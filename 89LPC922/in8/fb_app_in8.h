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

#ifndef FB_APP_IN8
#define FB_APP_IN8

#define DEBTIME			0xD2	// Entprellzeit in 0,5ms
#define RELMODE			0xF2	// Relaisbetrieb
#define	DELAYTAB		0xF9	// Start der Tabelle für Verzögerungswerte (Basis)
#define PDIR			0xFF	// Port-Richtung, wenn Bit gesetzt dann ist der entsprechende Pin ein Ausgang (für kombinierte Ein-/Ausgänge)

//#define PROTTIMER 		TIMERANZ+1
#define TIMERANZ		0x09	// timeranzahl (17)
#define PROTTIMER		TIMERANZ-1// PROTTIMER ist stets der letzte timer(0-7user,8prot,Gesmatzahl=9)





//extern unsigned char prot_timer;
extern unsigned char portbuffer,p0h;	// Zwischenspeicherung der Portzustände
extern unsigned char blocked;	// Sperrobjekte
void pin_changed(unsigned char pinno);
void schalten(bit risefall, unsigned char pinno);	// Schaltbefehl senden
unsigned char pin_function(unsigned char pinno);	// Funktion des Eingangs ermitteln
unsigned char debounce(unsigned char pinno);		// Entprellzeit abwarten und prüfen
void send_cyclic(unsigned char pinno);
unsigned char operation(unsigned char pinno);
unsigned char switch_dim(unsigned char pinno);
int eis5conversion(int zahl,unsigned char typ);
void delay(int w);
void delay_timer(void);
void write_value_req(void);	
void sperren(unsigned char objno,unsigned char freigabe);
void read_value_req(void);
void send_value(unsigned char type, unsigned char objno, int sval);
void restart_app(void);		// Alle Applikations-Parameter zurücksetzen
//void send_eis(unsigned char eistyp, unsigned char objno, int sval);	// sendet ein EIS Telegramm

#endif
