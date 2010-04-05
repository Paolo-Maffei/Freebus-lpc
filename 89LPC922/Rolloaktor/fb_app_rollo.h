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

#define GS2// GS1 für alte Relais-Schaltung, GS2 für neue
#define HAND				// Handsteuerung aktiv (auskommentieren wenn nicht gewünscht)
#define MAX_PORTS_8			// Anzahl Ausgänge (nur 4 oder 8 erlaubt)


#define FUNCASS		0xD8	// Startadresse der Zuordnung der Zusatzfunktionen (2 Byte)
#define OFFDISABLE	0xEB	// Aus-Telegramm ignorieren
#define FUNCTYP		0xED	// Typ der Zusatzfunktion
#define LOGICTYP	0xEE	// Verknüpfungs Typ 0=keine 1=ODER 2=UND 3=UND mir Rückführung
#define BLOCKACT	0xEF	// Verhalten beim Sperren
#define RELMODE		0xF2	// Relaisbetrieb
#define	DELAYTAB	0xF9	// Start der Tabelle für Verzögerungswerte (Basis)

#ifdef GS1
	#define DUTY	0xE7	// 0xFF=immer low 0x00=immer high
#endif
#ifdef GS2
	#define DUTY	0x50	//42 50 0xFF=immer low 0x00=immer high
#endif

//extern unsigned char portbuffer;	// Zwischenspeicherung der Portzustände
extern unsigned char zfstate;		// Zustand der Objekte 8-11 = Zusatzfunktionen 1-4
extern unsigned char blocked;		// Sperrung der 8 Ausgänge (1=gesperrt)
extern unsigned char logicstate;	// Zustand der Verknüpfungen pro Ausgang
extern long timer;					// Timer für Schaltverzögerungen, wird alle 130us hochgezählt
extern unsigned char delay_toggle;			// um nur jedes 2. Mal die delay routine auszuführen
//extern unsigned char owntele;		// ist 0 wenn telegramm vom bus gekommen, 1 wenn eigenes tele (rückmeldung) verarbeitet wird
//extern unsigned char respondpattern;
extern unsigned char kanal[4];		// Wert des Kanalobjekts
//extern unsigned char delrec[32];
extern unsigned char oldportvalue;
//void write_delay_record(unsigned char objno, unsigned char delay_status, long delay_target);	// Schreibt die Schalt-Verzoegerungswerte ins Flash
//void clear_delay_record(unsigned char objno); // Loescht den Delay Eintrag
extern bit handmode;
extern bit portchanged;


void write_value_req(void);		// Hauptroutine für Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
void send_value(unsigned char type, unsigned char objno, int sval);
void delay_timer(void);		// zählt alle 130ms die Variable Timer hoch und prüft Queue
bit handsteuerung();// Hauptroutine zur Handsteuerung
void sobj_update(void);
//void respond(unsigned char objno, unsigned char rval);
void port_schalten(unsigned char ports);	// Ausgänge gemäss Kanal[] schalten
void object_schalten(unsigned char objno, bit objstate);	// Objekt schalten
void Sobject_schalten(unsigned char objno);// sicherheitsobjekte schalten
void set_pause(unsigned char objnr,unsigned char Pstate);// setzt den jeweiligen Pausetimer
void set_entriegeln(unsigned char zeitnr);
unsigned char bit_swap(unsigned char swp); //vertauscht bit 0+1, 2+3,4+5,6+7
unsigned long zeit(unsigned char base_low,unsigned char base_high,unsigned char faktor_adr,unsigned char objno);
// rechnet die zeit aus
#endif
