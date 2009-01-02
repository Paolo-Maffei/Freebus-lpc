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

#define GS1					// GS1 f�r alte Relais-Schaltung, GS2 f�r neue
//#define HAND				// Handsteuerung aktiv (auskommentieren wenn nicht gew�nscht)
#define MAX_PORTS_4			// Anzahl Ausg�nge (nur 4 oder 8 erlaubt)


#define FUNCASS		0xD8	// Startadresse der Zuordnung der Zusatzfunktionen (2 Byte)
#define OFFDISABLE	0xEB	// Aus-Telegramm ignorieren
#define FUNCTYP		0xED	// Typ der Zusatzfunktion
#define LOGICTYP	0xEE	// Verkn�pfungs Typ 0=keine 1=ODER 2=UND 3=UND mir R�ckf�hrung
#define BLOCKACT	0xEF	// Verhalten beim Sperren
#define RELMODE		0xF2	// Relaisbetrieb
#define	DELAYTAB	0xF9	// Start der Tabelle f�r Verz�gerungswerte (Basis)

#ifdef GS1
	#define DUTY	0xC0	// 0xFF=immer low 0x00=immer high
#endif
#ifdef GS2
	#define DUTY	0x50	// 0xFF=immer low 0x00=immer high
#endif

extern unsigned char portbuffer;	// Zwischenspeicherung der Portzust�nde
extern unsigned char zfstate;		// Zustand der Objekte 8-11 = Zusatzfunktionen 1-4
extern unsigned char blocked;		// Sperrung der 8 Ausg�nge (1=gesperrt)
extern unsigned char logicstate;	// Zustand der Verkn�pfungen pro Ausgang
extern long timer;					// Timer f�r Schaltverz�gerungen, wird alle 130us hochgez�hlt
extern bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszuf�hren


void write_value_req(void);		// Hauptroutine f�r Ausg�nge schalten gem�� EIS 1 Protokoll (an/aus)
void delay_timer(void);		// z�hlt alle 130ms die Variable Timer hoch und pr�ft Queue
void respond(unsigned char objno, unsigned char rval);
void port_schalten(unsigned char ports);	// Ausg�nge schalten
void object_schalten(unsigned char objno, bit objstate);	// Objekt schalten


#endif
