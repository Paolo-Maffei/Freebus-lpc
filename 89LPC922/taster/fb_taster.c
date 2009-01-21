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


/* Versionen:	1.00	erstes Programm

*/
	

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_delay.h"
#include "fb_app_taster.h"


#define NOPROGBUTTON	// es ist kein prog Taster vorhanden sondern progmode wird durch drücken von taste 1&3 oder 2&4 aktiviert


void main(void)
{ 
	unsigned char n;
	bit blink;
	
	restart_hw();							// Hardware zurücksetzen
	restart_prot();							// Protokoll-relevante Parameter zurücksetzen
	restart_app();							// Anwendungsspezifische Einstellungen zurücksetzen
	for (n=0;n<50;n++) sysdelay(0xFFFF);	// Warten bis Bus stabil

	do  {
		if ((PORT & 0x0F) != button_buffer) port_changed(PORT & 0x0F);	// ein Taster wurde gedrückt
		if (RTCCON>=0x80) delay_timer();	// Realtime clock Überlauf
			
		n=timer;
		blink=((n>>4) & 0x01);
		
#ifndef NOPROGBUTTON
		TASTER=1;				        	// Pin als Eingang schalten um Programmiertaster abzufragen
		if (!TASTER) {						// Programmiertaster gedrückt
			for(n=0;n<100;n++) {}
			while(!TASTER);					// warten bis Programmiertaster losgelassen
			progmode=!progmode;
		}
#else
		// progmode wird durch Taste 1&3 bzw. 2&4 getoggelt
		if (((PORT & 0x0F)== 0x05) || ((PORT & 0x0F)== 0x0A)) progmode=!progmode;
#endif
		if (progmode) TASTER = blink;		// LED blinkt im Prog-Mode
		else TASTER = !((eeprom[0xCD] & 0x10) >> 4);	// LED ist an oder aus gemäß Parameter für Betriebs-LED
		for(n=0;n<100;n++) {}
  } while(1);
}


