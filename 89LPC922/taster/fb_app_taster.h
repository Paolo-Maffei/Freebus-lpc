/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
/**
* @file   fb_app_taster.h
* @author Andreas Krebs <kubi@krebsworld.de>
* @date    2008
* 
* @brief The Freebus Taster Application, Firmware f�r einen 4-fach Taster mit 4 LEDs
* 
* 
*/

#ifndef FB_APP
#define FB_APP


#define POWERLED		0xCD
#define LED_DURATION	0xCE
#define FUNCTION		0xCF	// Funktion der Tester
#define COMMAND			0xD3	// Funktion der LEDs und Befehle der Taster
#define DEL_BASE		0xD4
#define DEL_FACTOR1		0xD5
#define DEL_FACTOR2		0xD6



#define WAIT_FOR_TIMER0 while (!TF0);


extern long timer;				// Timer fuer Schaltverzoegerungen, wird alle 130us hochgezaehlt
extern bit delay_toggle;		// um nur jedes 2. Mal die delay routine auszufuehren
extern long buttontimer[4];

extern unsigned char button_buffer;	// puffer fuer taster werte


void port_changed(unsigned char portval);		// ein Taster wurde gedrueckt oder losgelassen
void button_changed(unsigned char buttonno, bit buttonval);	// Taster Aktion abarbeiten
void switch_led(unsigned char ledno, bit onoff);	// LED schalten
void write_value_req(void);		// Hauptroutine fuer Ausgaenge schalten gemaess EIS 1 Protokoll (an/aus)
void delay_timer(void);			// zaehlt alle 130ms die Variable Timer hoch und prueft Queue
void send_eis(unsigned char eistyp, unsigned char objno, int sval);	// sendet ein EIS Telegramm


#endif
