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

#ifndef FB_APP_IN8T
#define FB_APP_IN8T

#define DEBTIME			0xD2	// Entprellzeit in 0,5ms
#define RELMODE			0xF2	// Relaisbetrieb
#define	DELAYTAB		0xF9	// Start der Tabelle für Verzögerungswerte (Basis)
#define PDIR			0xF0	// Port-Richtung, wenn Bit gesetzt dann ist der entsprechende Pin ein Ausgang (für kombinierte Ein-/Ausgänge)

extern unsigned char portbuffer,p0h;	// Zwischenspeicherung der Portzustände

void pin_changed(unsigned char pinno);
void read_value_req(void);				// Objektwerte lesen angefordert
void schalten(unsigned char risefall, unsigned char pinno);	// Schaltbefehl senden
unsigned char pin_function(unsigned char pinno);	// Funktion des Eingangs ermitteln
unsigned char debounce(unsigned char pinno);		// Entprellzeit abwarten und prüfen
void send_cyclic(unsigned char pinno);
unsigned char operation(unsigned char pinno);
unsigned char switch_dim(unsigned char pinno);

void eis1(void);			// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
void delay_timer(void);		// zählt alle 130ms die Variable Timer hoch und prüft Queue
void restart_app(void);		// Alle Applikations-Parameter zurücksetzen

#endif
