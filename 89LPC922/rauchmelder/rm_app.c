/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2011 - 2012 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is not free software; you can use it and/or modify
 *  it for private use only.
 *
 *
 */



#include <P89LPC922.h>
#include "../lib_lpc922/fb_lpc922.h"
#include "rm_app.h"


__bit event, alarm, stoerung, alarm_obj, stoerung_obj;
unsigned int timer, timer_alarm, timer_stoerung;


void write_value_req(void)	// Empfangenes write_value_request Telegramm verarbeiten
{
	/* Hier holt man sich die Bytes aus dem array telegramm[] und führt
	 * die entsprechenden Aktionen aus, die das Gerät haben soll
	 */
}



void read_value_req(void)	// Empfangenes read_value_request Telegramm verarbeiten
{
	/* Hier sicherstellen, dass der Objektwert, der durch read_obj_value() gelesen wird,
	 * aktuell ist. Danach das Senden des Objektes anstossen.
	 */
}


unsigned long read_obj_value(unsigned char objno)
{
	unsigned char return_value=0;

	if(objno==0) return_value=alarm_obj;
	if(objno==1) return_value=stoerung_obj;

	return(return_value);
}


void key(void) __interrupt (7)
{
	unsigned char port;

	EKBI=0;				// keyboard Interrupt sperren

	port=P0&0x03;
	if(port==2) alarm=1;
	if(port==1) stoerung=1;
	if(port==0) {
		alarm=0;
		stoerung=0;
	}
	event=1;				// zeigt an, dass der Rauchmelder etwas gesendet hat
	interrupted=1;			// Flag setzen, dass unterbrochen wurde
	//while((P0 & 0x03)!= 0x03);
	KBCON=0;				// Interrupt-Flag löschen
	KBPATN=port;
	EKBI=1;					// Keyboard Interrupt wieder frei geben
}


void delay_timer(void)	// zählt alle 65ms die Variable Timer hoch und prüft Queue
{


	RTCCON=0x60;		// RTC anhalten und Flag löschen
	RTCH=0xE1;			// reload Real Time Clock
	RTCL=0x00;

	timer++;

	if (timer_alarm==timer && eeprom[A_ZYKLISCH]) {
		send_obj_value(0);
		if (eeprom[A_BASIS]) timer_alarm=timer+eeprom[A_FAKTOR]*60;
		else timer_alarm=timer+eeprom[A_FAKTOR];
	}
	if (timer_stoerung==timer && eeprom[S_ZYKLISCH]) {
		send_obj_value(1);
		if (eeprom[S_BASIS]) timer_stoerung=timer+eeprom[S_FAKTOR]*60;
		else timer_stoerung=timer+eeprom[S_FAKTOR];
	}

	RTCCON=0x61;		// RTC starten
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{


	P0M1= 0x00;			// all bidirectional,
	P0M2= 0x00;
	P0= 0xFF;

	alarm=0;
	stoerung=0;
	alarm_obj=0;
	stoerung_obj=0;

	// Init Keyboard Interrupt
	KBMASK=0x03;		// P0.0 & P0.1 enabled for KB-Interrupt
	KBPATN=0x03;		// Pattern
	KBCON=0;			// Interrupt when port not equal to pattern
	EKBI=1;

	RTCH=0xE1;		// Real Time Clock auf 1s laden
	RTCL=0x00;		// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
	RTCCON=0x61;	// ... und starten

	timer=0;
	if (eeprom[A_ZYKLISCH]) timer_alarm=timer+2;
	if (eeprom[S_ZYKLISCH]) timer_stoerung=timer+4;

	// Beispiel für die Applikations-spezifischen Einträge im eeprom
	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	START_WRITECYCLE;
	WRITE_BYTE(0x01,0x03,0x00);	// Herstellercode 0x0000 = Freebus
	WRITE_BYTE(0x01,0x04,0x00);
	WRITE_BYTE(0x01,0x05,0x10);	// Devicetype 0x1003
	WRITE_BYTE(0x01,0x06,0x03);
	WRITE_BYTE(0x01,0x07,0x01);	// Versionnumber of application programm
	WRITE_BYTE(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0xA0);	// COMMSTAB Pointer
	STOP_WRITECYCLE;
	EA=1;						// Interrupts freigeben
}
