/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2009 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 * 
 */



#include <P89LPC922.h>
#include "../lib_lpc922/fb_lpc922.h"
#include "fb_app_logi.h"


unsigned char gate_a, gate_b, gate_q;


void write_value_req(void)	// Empfangenes write_value_request Telegramm verarbeiten
{
	unsigned char gapos, gaposh, objno, atp, assno, n;

    gaposh=0;

    gapos=gapos_in_gat(telegramm[3],telegramm[4]);	// Position der Gruppenadresse in der Adresstabelle
    if (gapos!=0xFF) {					// =0xFF falls nicht vorhanden
		atp=eeprom[ASSOCTABPTR];			// Start Association Table
		assno=eeprom[atp];				// Erster Eintrag = Anzahl Einträge

		for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
			gaposh=eeprom[atp+1+(n*2)];
			if(gapos==gaposh) {					// Wenn Positionsnummer übereinstimmt
				objno=eeprom[atp+2+(n*2)];				// Objektnummer
				write_obj_value(objno, telegramm[7]&0x01);
			}
		}
    }

}


// speichert den aktuellen Wert eines Objektes
// die gate ausgänge werden nicht verarbeitet!!!
void write_obj_value(unsigned char objno,unsigned int objvalue)
{
	unsigned char gateno, rest;

	gateno=objno/3;
	rest=objno-(gateno*3);

	if(rest==0) {
		if(objvalue==0) gate_a&=0xFF-(1<<gateno);
		else gate_a|=1<<gateno;
	}
	if(rest==1) {
		if(objvalue==0) gate_b&=0xFF-(1<<gateno);
		else gate_b|=1<<gateno;
	}
}



void read_value_req(void)	// Empfangenes read_value_request Telegramm verarbeiten
{
	/* Hier sicherstellen, dass der Objektwert, der durch read_obj_value() gelesen wird,
	 * aktuell ist. Danach das Senden des Objektes anstossen.
	 */
}


unsigned long read_obj_value(unsigned char objno)
{
	unsigned char gateno, rest, value=0;

	gateno=objno/3;
	rest=objno-(gateno*3);

	if(rest==0) {
		value=(gate_a>>gateno)&0x01;
	}
	if(rest==1) {
		value=(gate_b>>gateno)&0x01;
	}
	if(rest==2) {
		value=(gate_q>>gateno)&0x01;
	}


	return(value);	// Beispiel return-Wert
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{

	P0=0;
	P0M1=0x00;		// Port 0 Modus push-pull für Ausgang
	P0M2=0xFF;

	gate_a=0;
	gate_b=0;
	gate_q=0;
	

	
	// Beispiel für die Applikations-spezifischen Einträge im eeprom
	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	START_WRITECYCLE
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
	WRITE_BYTE(0x01,0x04,0x00)
	WRITE_BYTE(0x01,0x05,0x10)	// Devicetype 0x2060 = Jung Aktor 2138.10
	WRITE_BYTE(0x01,0x06,0x01)
	WRITE_BYTE(0x01,0x07,0x01)	// Versionnumber of application programm
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0xA0)	// COMMSTAB Pointer
	STOP_WRITECYCLE
	EA=1;						// Interrupts freigeben
}
