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
* @file   fb_prot.h
* @author Andreas Krebs <kubi@krebsworld.de>
* @date    2008
* 
* @brief  Hier sind ausschliesslich die Protokoll-Handling Routinen fuer den 89LPC922
* 
* 
*/

#ifndef FB_PROT
#define FB_PROT

#define ASSOCTABPTR 	0x11	// Adresse des Pointers auf die Assoziations-Tabelle
#define COMMSTABPTR 	0x12	// Adresse des Pointers auf die Kommunikationsobjekt-Tabelle
#define ADDRTAB			0x16	// Startadresse der Adresstabelle

extern unsigned char telegramm[23];
extern unsigned char telpos;		// Zeiger auf naechste Position im Array Telegramm
extern unsigned char cs;			// checksum
extern bit progmode, connected;		// Programmiermodus, Verbindung steht
extern unsigned char conh, conl;	// bei bestehender Verbindung phys. Adresse des Kommunikationspartners
extern unsigned char pcount;		// Paketzaehler, Gruppenadresszï¿½hler
extern bit parity_ok;				// Parity Bit des letzten empfangenen Bytes OK
extern unsigned char last_tel;
extern bit transparency;			// wenn 1 dann wird telegramm lokal nicht verarbeitet

extern unsigned char ledcount;
extern unsigned char eibledcount;
extern unsigned char rxledcount;


void timer1(void) interrupt 3;	// Interrupt von Timer 1, 370us keine Busaktivitaet seit letztem Byte,
bit get_ack(void);				// wartet bis Byte empfangen wurde und prueft ob es ein ACK war  <- suboptimal, besser mit timeout !!!
void send_telegramm(void);		// sendet das Telegramm, das in telegramm[] vorher abgelegt wurde und berechnet die checksum
void send_ack(void);			// wartet auf Timer 1 wegen korrekter Positionierung und sendet ACK (0xCC)
void restart_prot(void);		// Protokoll-relevante Parameter zuruecksetzen

// Funktionen die sich in der app befinden müssen
extern void write_value_req(void);		// Routine zur Verarbeitung eingegegangener Telegramme zum Schreiben eines Objektwertes
extern void read_value_req(void);		// Objektwerte lesen angefordert




#endif
