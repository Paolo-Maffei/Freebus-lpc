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
 * 	Routinen und Array für Zeitschaltfunktionen
 */

unsigned char delrec[40];

void write_delay_record(unsigned char objno, unsigned char delay_state, long delay_target)		// Schreibt die Schalt-Verzögerungswerte ins Flash
{
	delrec[objno*4]=delay_state;
	delrec[objno*4+1]=delay_target>>16;
	delrec[objno*4+2]=delay_target>>8;
	delrec[objno*4+3]=delay_target;
}

void clear_delay_record(unsigned char objno)		// Schreibt die Schalt-Verzögerungswerte ins Flash
{
	delrec[objno*4]=0;
	delrec[objno*4+1]=0;
	delrec[objno*4+2]=0;
	delrec[objno*4+3]=0;
}