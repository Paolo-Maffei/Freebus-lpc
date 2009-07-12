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

#ifndef FB_APP_OUT
#define FB_APP_OUT

#define GS2					// GS1 für alte Relais-Schaltung, GS2 für neue
#define HAND				// Handsteuerung aktiv (auskommentieren wenn nicht gewünscht)
#define MAX_PORTS_8			// Anzahl Ausgänge (nur 4 oder 8 erlaubt)


#define FUNCASS		0xD8	// Startadresse der Zuordnung der Zusatzfunktionen (2 Byte)
#define OFFDISABLE	0xEB	// Aus-Telegramm ignorieren
#define FUNCTYP		0xED	// Typ der Zusatzfunktion
#define LOGICTYP	0xEE	// Verknüpfungs Typ 0=keine 1=ODER 2=UND 3=UND mir Rückführung
#define BLOCKACT	0xEF	// Verhalten beim Sperren
#define BLOCKPOL	0xF1	// Polarität der Sperrobjekte
#define RELMODE		0xF2	// Relaisbetrieb
#define	DELAYTAB	0xF9	// Start der Tabelle für Verzögerungswerte (Basis)

#ifdef GS1
	#define DUTY	0xC0	// 0xFF=immer low 0x00=immer high
#endif
#ifdef GS2
	#define DUTY	0x50	// 0xFF=immer low 0x00=immer high
#endif

#define REFRESH \
		P0= userram[0x29];	// refresh des Portzustandes in der hal


void write_value_req(void);		// Hauptroutine für Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
void read_value_req(void);
void send_value(unsigned char type, unsigned char objno, unsigned int sval);
void delay_timer(void);		// zählt alle 130ms die Variable Timer hoch und prüft Queue
void respond(unsigned char objno, unsigned char rval);
void port_schalten(unsigned char ports);	// Ausgänge schalten
void object_schalten(unsigned char objno, bit objstate);	// Objekt schalten


#endif
