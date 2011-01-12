/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2010 Jan Wegner
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

#ifndef FB_APP
#define FB_APP

//#define MODUL_8_IN
//#define TASTER_8
#define TASTER_4
//#define RADIO

#ifdef MODUL_8_IN
#define PROGRAMM 1
#endif
#ifdef TASTER_8
#define PROGRAMM 2
#endif
#ifdef TASTER_4
#define PROGRAMM 3
#endif
#ifdef RADIO
#define PROGRAMM 4
#endif

#define POWERLED		0xCD
#define LED_DURATION	0xCE
#define FUNCTION		0xCF	// Funktion der Taster
#define COMMAND			0xD3	// Funktion der LEDs und Befehle der Taster
#define DEL_BASE		0xD4
#define DEL_FACTOR1		0xD5
#define DEL_FACTOR2		0xD6


extern long timer;				// Timer fuer Schaltverzoegerungen, wird alle 130us hochgezaehlt
extern unsigned char button_buffer;	// puffer fuer taster werte


void port_changed(unsigned char portval);		// ein Taster wurde gedrueckt oder losgelassen
void button_changed(unsigned char buttonno, bit buttonval);	// Taster Aktion abarbeiten
void write_value_req(void);		// Hauptroutine fuer Ausgaenge schalten gemaess EIS 1 Protokoll (an/aus)
void delay_timer(void);			// zaehlt alle 130ms die Variable Timer hoch und prueft Queue
void send_value(unsigned char type, unsigned char objno, unsigned int sval);	// sendet ein EIS Telegramm


#if (PROGRAMM == 4)
extern unsigned char led_port;
#endif


#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
void switch_led(unsigned char ledno, bit onoff);
void w_switch_led(unsigned char ledno, bit onoff);
#endif


#endif /* FB_APP */
