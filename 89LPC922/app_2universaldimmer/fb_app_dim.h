/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2008 Andreas Krebs <kubi@krebsworld.de>
 *                      Richard Weissteiner richard@seelaus.at
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
/**
* @file   fb_app_dim.h
* @author Rainer Petzoldt <r.petzoldt@web.de>
* @date   17.10.2009
*
* @brief  Hier sind ausschliesslich die Universaldimmer Routinen fuer den 89LPC922
*
*/

#ifndef FB_APP_DIM
#define FB_APP_DIM

#include "AllgDefs.h"

extern __idata volatile byte IstKurzschluss[2];			//
extern __idata volatile byte IstSpannungsausfall[2];		//


ulong read_obj_value(byte objno);

void restart_app(void);		// Alle Applikations-Parameter zurücksetzen

// Bestimmt aus der Helligkeitsstufe die Helligkeit
byte HelligkeitFromStufe(byte stufe, byte kanal);

// Rückmeldeobjekte senden
void SendRueckmeldung(byte c, byte OldVal);

void read_value_req(void);

void write_value_req(void);	// Hauptroutine für Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)

void delay_timer(void);		// zählt alle 130ms die Variable Timer hoch und prüft Queue

void respond(byte objno, byte rval);

void port_schalten(byte ports);     // Ausgänge schalten

// Pruefen ob Kurzschluss und Telegramm senden
void CheckKurzschlussSpannungsausfall(byte kanal);

#endif
