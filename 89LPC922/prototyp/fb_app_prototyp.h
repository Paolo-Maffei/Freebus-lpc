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
 */

#ifndef FB_APP_PROTOTYP
#define FB_APP_PROTOTYP



// Das REFRESH Makro wird unmittelbar nach Ausl�sen des Empfangs-Interrupts ausgef�hrt, falls
// man z.B. Portzust�nde vor der weiteren Verarbeitung restaurieren muss
#define REFRESH \
		P0= userram[0x29];	// BEISPIEL: refresh des Portzustandes in der hal


void write_value_req(void);		// Hauptroutine f�r Ausg�nge schalten gem�� EIS 1 Protokoll (an/aus)
void read_value_req(void);
void send_value(unsigned char type, unsigned char objno, unsigned int sval);
void delay_timer(void);			// z�hlt alle 130ms die Variable Timer hoch und pr�ft Queue
void respond(unsigned char objno, unsigned char rval);
void port_schalten(unsigned char ports);	// Ausg�nge schalten
void object_schalten(unsigned char objno, bit objstate);	// Objekt schalten


#endif
