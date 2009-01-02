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

#ifndef FB_PROT
#define FB_PROT

#define ASSOCTABPTR 	0x11	// Adresse des Pointers auf die Assoziations-Tabelle
#define COMMSTABPTR 	0x12	// Adresse des Pointers auf die Kommunikationsobjekt-Tabelle
#define ADDRTAB			0x16	// Startadresse der Adresstabelle

extern unsigned char telegramm[23];
extern unsigned char telpos;		// Zeiger auf nächste Position im Array Telegramm
extern unsigned char cs;			// checksum
extern bit progmode, connected;		// Programmiermodus, Verbindung steht
extern unsigned char conh, conl;	// bei bestehender Verbindung phys. Adresse des Kommunikationspartners
extern unsigned char pcount;		// Paketzähler, Gruppenadresszähler
extern bit parity_ok;				// Parity Bit des letzten empfangenen Bytes OK
extern unsigned char last_tel;
extern bit transparency;			// wenn 1 dann wird telegramm lokal nicht verarbeitet
extern unsigned char delrec[40];

void timer1(void) interrupt 3;	// Interrupt von Timer 1, 370us keine Busaktivität seit letztem Byte, d.h. Telegramm wurde komplett übertragen
bit get_ack(void);				// wartet bis Byte empfangen wurde und prüft ob es ein ACK war  <- suboptimal, besser mit timeout !!!
void send_telegramm(void);		// sendet das Telegramm, das in telegramm[] vorher abgelegt wurde und berechnet die checksum
void send_ack(void);			// wartet auf Timer 1 wegen korrekter Positionierung und sendet ACK (0xCC)
void ucd_opr(void);				// UCD Verbindungsaufbau
void ucd_clr(void);				// UCD Verbindungsabbau
void get_gat(void);				// group address table aus EEPROM lesen und in array gat[] schreiben
unsigned char gapos_in_gat(unsigned char gah, unsigned char gal);	// Gruppenadresse in Adresstabelle finden, Rückgabe Positionsnr.
void ncd_quit(void);			// NCD Quittierung zurück senden. Setzt telegramm Bytes 0 bis 6 !!!
void read_masq(void);			// Maskenversion senden
void read_memory(void);			// read_memory_request - Speicher auslesen und senden
void write_memory(void);		// write_memory_request - empfangene Daten in Speicher schreiben
void set_pa(void);				// neue phys. Adresse programmieren
void read_pa(void);				// phys. Adresse senden
void read_value_req(void);		// Objektwert lesen angefordert

unsigned char read_objflags(unsigned char objno);	// Objektflags lesen

int find_ga(unsigned char objno);	// Gruppenadresse über Assoziationstabelle finden (erster Eintrag, falls mehrere)
unsigned char find_first_objno(unsigned char gah, unsigned char gal);

void write_delay_record(unsigned char objno, unsigned char delay_status, long delay_target);	// Schreibt die Schalt-Verzögerungswerte ins Flash
void clear_delay_record(unsigned char objno); // Löscht den Delay Eintrag
void restart_prot(void);		// Protokoll-relevante Parameter zurücksetzen

int read_obj_value(unsigned char objno);	// gibt den Wert eines Objektes zurück
unsigned char read_obj_type(unsigned char objno);		// gibt den Typ eines Objektes zurück
bit write_obj_value(unsigned char objno,int objvalue);	// schreibt den aktuellen Wert eines Objektes ins 'RAM'

void write_value_req(void);				// Hauptroutine für Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
void read_value_req(void);		// Objektwerte lesen angefordert
void restart_app(void);			// Alle Applikations-Parameter zurücksetzen

#endif
