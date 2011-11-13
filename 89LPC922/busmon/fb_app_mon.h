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

void ft_send_char(unsigned char sc);
void restart_app(void);		// Alle Applikations-Parameter zurücksetzen
void write_value_req(void);	// entfällt
void read_value_req(void);	// entfällt
unsigned long read_obj_value(unsigned char objno);	// entfällt
void write_obj_value(unsigned char objno, unsigned int val);			// entfällt

#endif
