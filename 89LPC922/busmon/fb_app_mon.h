/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2009 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

#ifndef FB_APP_BM
#define FB_APP_BM

void restart_app(void);		// Alle Applikations-Parameter zur�cksetzen
void write_value_req(void);	// entf�llt
void read_value_req(void);	// entf�llt
unsigned int read_obj_value(unsigned char objno);	// entf�llt
void write_obj_value(unsigned char objno, unsigned int val);			// entf�llt

#endif
