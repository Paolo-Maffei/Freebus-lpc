/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008-2011 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

#ifndef FB_APP_OUT
#define FB_APP_OUT

#define GS2					// GS1 f�r alte Relais-Schaltung, GS2 f�r neue
#define HAND				// Handsteuerung aktiv (auskommentieren wenn nicht gew�nscht)
#define MAX_PORTS_8			// Anzahl Ausg�nge (nur 4 oder 8 erlaubt)
//#define SPIBISTAB			// Serielle Ausgabe f�r bistabile relaise aktivieren
// Parameter-Adressen im EEPROM
#define FUNCASS		0xD8	// Startadresse der Zuordnung der Zusatzfunktionen (2 Byte)
#define OFFDISABLE	0xEB	// Aus-Telegramm ignorieren
#define FUNCTYP		0xED	// Typ der Zusatzfunktion
#define LOGICTYP	0xEE	// Verkn�pfungs Typ 0=keine 1=ODER 2=UND 3=UND mir R�ckf�hrung
#define BLOCKACT	0xEF	// Verhalten beim Sperren
#define BLOCKPOL	0xF1	// Polarit�t der Sperrobjekte
#define RELMODE		0xF2	// Relaisbetrieb (�ffner/Schlie�er)
#define RMINV		0xF3	// R�ckmeldung invertiert oder normal
#define	DELAYTAB	0xF9	// Start der Tabelle f�r Verz�gerungswerte (Basis)

// Adressen zum speichern von Applikations Daten
#define PORTSAVE	0x99	// Portzust�nde
#define TIMERANZ	0x08	// timeranzahl


#ifdef GS1
	#define DUTY	0xC0	// 0xFF=immer low 0x00=immer high
#endif
#ifdef GS2
	#define DUTY	0x50	// 0xFF=immer low 0x00=immer high
#endif

#define REFRESH \
		P0= oldportbuffer;	// refresh des Portzustandes in der hal
							// f�r astabile Relaise 
// SPI Konfiguration
#define CLK			P0_3
#define BOT_OUT		P0_0
#define MID_OUT		P0_1
#define WRITE		P0_2

extern 	bit portchanged;// globale variable, sie ist 1 wenn sich portbuffer ge�ndert hat
extern unsigned char portbuffer;


void write_delay_record(unsigned char objno, unsigned char delay_status, long delay_target);	// Schreibt die Schalt-Verzoegerungswerte ins Flash
void clear_delay_record(unsigned char objno); // Loescht den Delay Eintrag
void write_value_req(void);		// Hauptroutine f�r Ausg�nge schalten gem�� EIS 1 Protokoll (an/aus)
void read_value_req(void);
void delay_timer(void);		// z�hlt alle 130ms die Variable Timer hoch und pr�ft Queue
void port_schalten(void);	// Ausg�nge schalten
void object_schalten(unsigned char objno, bit objstate);	// Objekt schalten
void spi_2_out(unsigned int daten);
unsigned int sort_output(unsigned char portbuffer);
void bus_return(void);		// Aktionen bei Busspannungswiederkehr
void restart_app(void);		// Alle Applikations-Parameter zur�cksetzen

unsigned long read_obj_value(unsigned char objno);	// gibt den Wert eines Objektes zurueck
void write_obj_value(unsigned char objno,unsigned int objvalue);	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'



#endif
