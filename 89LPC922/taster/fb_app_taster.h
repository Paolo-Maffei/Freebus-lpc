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

#ifndef FB_APP
#define FB_APP

#define POWERLED	0xCD
#define DURATION	0xCE
#define FUNCTION	0xCF	// Funktion der Tester
#define COMMAND		0xD3	// Funktion der LEDs und Befehle der Taster



#define WAIT_FOR_TIMER0 while (!TF0);


extern long timer;				// Timer f�r Schaltverz�gerungen, wird alle 130us hochgez�hlt
extern bit delay_toggle;		// um nur jedes 2. Mal die delay routine auszuf�hren

extern unsigned char button_buffer;	// puffer f�r taster werte


void port_changed(unsigned char portval);		// ein Taster wurde gedr�ckt oder losgelassen
void button_changed(unsigned char buttonno, bit buttonval);	// Taster Aktion abarbeiten
void switch_led(unsigned char ledno, bit onoff);	// LED schalten
void write_value_req(void);		// Hauptroutine f�r Ausg�nge schalten gem�� EIS 1 Protokoll (an/aus)
void delay_timer(void);			// z�hlt alle 130ms die Variable Timer hoch und pr�ft Queue



#endif
