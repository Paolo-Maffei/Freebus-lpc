/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008,2009 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
/**
* @file   fb_taster.c
* @author Andreas Krebs <kubi@krebsworld.de>
* @date   2008
* 
* @brief The Freebus Taster Application, Firmware fuer einen 4-fach Taster mit 4 LEDs
*		Herstellercode 0x0004 = Jung
*		Devicetype 0x1052 = Jung Tastsensor 2092
*		in ETS das Applikationsprogramm "Universal/Schalten 105201" auswaehlen
*
* \par Changes:
*		1.00	erste Version;
*		1.01	eigenes Telegramm wird ausgewertet, "Affengriff" entprellt
* 
*/
	

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_delay.h"
#include "fb_app_taster.h"


//#define NOPROGBUTTON	// es ist kein prog Taster vorhanden sondern progmode wird durch druecken von taste 1&3 oder 2&4 aktiviert

/** 
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
* 
* @return 
*/
void main(void)
{ 
	unsigned char n;
	bit blink;
	
	restart_hw();							// Hardware zuruecksetzen
	restart_prot();							// Protokoll-relevante Parameter zuruecksetzen
	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	for (n=0;n<50;n++) sysdelay(0xFFFF);	// Warten bis Bus stabil

	do  {
		if ((PORT & 0x0F) != button_buffer) port_changed(PORT & 0x0F);	// ein Taster wurde gedrueckt
		if (RTCCON>=0x80) delay_timer();	// Realtime clock ueberlauf
			
		n=timer;
		blink=((n>>4) & 0x01);
		
#ifndef NOPROGBUTTON
		TASTER=1;				        	// Pin als Eingang schalten um Programmiertaster abzufragen
		if (!TASTER) {						// Programmiertaster gedrueckt
			for(n=0;n<100;n++) {}
			while(!TASTER);					// warten bis Programmiertaster losgelassen
			progmode=!progmode;
		}
#else
		// progmode wird durch Taste 1&2 bzw. 3&4 getoggelt
		if (((PORT & 0x0F)== 0x03) || ((PORT & 0x0F)== 0x0C)) {
			while (PORT & 0x0F);	// Warten bis alle Taster losgelassen
			progmode=!progmode;
		}
#endif
		if (progmode) TASTER = blink;		// LED blinkt im Prog-Mode
		else TASTER = !((eeprom[0xCD] & 0x10) >> 4);	// LED ist an oder aus gemaess Parameter fuer Betriebs-LED
		for(n=0;n<100;n++) {}
  } while(1);
}


