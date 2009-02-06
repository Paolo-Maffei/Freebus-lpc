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
* @file   fb_app_out.h
* @author Andreas Krebs <kubi@krebsworld.de>
* @date   Tue Jan 01 17:44:47 2009
* 
* @brief  The Freebus relais application (header)
* 
* 
*/

#ifndef FB_APP_OUT
#define FB_APP_OUT

#define GS2					/// GS1 fuer alte Relais-Schaltung, GS2 fuer neue
//#define HAND				/// Handsteuerung aktiv (auskommentieren wenn nicht gewuenscht)
#define MAX_PORTS_8			/// Anzahl Ausgaenge (nur 4 oder 8 erlaubt)


#define FUNCASS		0xD8	// Startadresse der Zuordnung der Zusatzfunktionen (2 Byte)
#define OFFDISABLE	0xEB	// Aus-Telegramm ignorieren
#define FUNCTYP		0xED	// Typ der Zusatzfunktion
#define LOGICTYP	0xEE	// Verknuepfungs Typ 0=keine 1=ODER 2=UND 3=UND mir Rueckfuehrung
#define BLOCKACT	0xEF	// Verhalten beim Sperren
#define RELMODE		0xF2	// Relaisbetrieb
#define	DELAYTAB	0xF9	// Start der Tabelle fuer Verzoegerungswerte (Basis)

#ifdef GS1
	#define DUTY	0xC0	// 0xFF=immer low 0x00=immer high
#endif
#ifdef GS2
	#define DUTY	0x50	// 0xFF=immer low 0x00=immer high
#endif

extern unsigned char portbuffer;	// Zwischenspeicherung der Portzustaende
extern unsigned char zfstate;		// Zustand der Objekte 8-11 = Zusatzfunktionen 1-4
extern unsigned char blocked;		// Sperrung der 8 Ausgaenge (1=gesperrt)
extern unsigned char logicstate;	// Zustand der Verknuepfungen pro Ausgang
extern long timer;					// Timer fuer Schaltverzoegerungen, wird alle 130us hochgezaehlt
extern bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszufuehren


void write_value_req(void);		// Hauptroutine fuer Ausgaenge schalten gemaess EIS 1 Protokoll (an/aus)
void delay_timer(void);		// zaehlt alle 130ms die Variable Timer hoch und prueft Queue
void respond(unsigned char objno, unsigned char rval);
void port_schalten(unsigned char ports);	// Ausgaenge schalten
void object_schalten(unsigned char objno, bit objstate);	// Objekt schalten


#endif
