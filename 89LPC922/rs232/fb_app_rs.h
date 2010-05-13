/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2008-2010 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */


#ifndef FB_APP_RS
#define FB_APP_RS

#define ASSOCTABPTR 	0x11	// Adresse des Pointers auf die Assoziations-Tabelle
#define COMMSTABPTR 	0x12	// Adresse des Pointers auf die Kommunikationsobjekt-Tabelle
#define ADDRTAB		0x16	// Startadresse der Adresstabelle
#define FUNCASS		0xD8	// Startadresse der Zuordnung der Zusatzfunktionen (2 Byte)
#define FUNCTYP		0xED	// Typ der Zusatzfunktion
#define LOGICTYP	0xEE	// Verknüpfungs Typ 0=keine 1=ODER 2=UND 3=UND mir Rückführung
#define BLOCKACT	0xEF	// Verhalten beim Sperren
#define RELMODE		0xF2	// Relaisbetrieb
#define	DELAYTAB	0xF9	// Start der Tabelle für Verzögerungswerte (Basis)

#define RXLED	P0_6
#define EIBLED	P0_7

struct ga_record {
	unsigned int ga;
	unsigned int val;
};


extern unsigned char rsin[30];		// seriell empfangener string
extern unsigned char rsinpos;

extern __code struct ga_record __at 0x1A00 ga_db[256];
extern __code unsigned char __at 0x1DFB echo;
extern __code unsigned int __at 0x1DFE baud;

void restart_app(void);		// Alle Applikations-Parameter zurücksetzen
void save_ga(unsigned int ga, unsigned int val);
void tel_header(unsigned int ga, unsigned char length);
unsigned int convert_adr(unsigned char pos);
unsigned char equal_pos(void);
void write_value_req(void);
void serial_int(void) interrupt 4 using 1;
#endif
