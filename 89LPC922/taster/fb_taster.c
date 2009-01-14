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



void main(void)
{ 
	unsigned char n;
	bit blink;
	
	restart_hw();							// Hardware zur�cksetzen
	for (n=0;n<50;n++) sysdelay(0xFFFF);	// Warten bis Bus stabil
	restart_prot();							// Protokoll-relevante Parameter zur�cksetzen
	restart_app();							// Anwendungsspezifische Einstellungen zur�cksetzen

	do  {
		if ((PORT & 0x0F) != button_buffer) port_changed(PORT & 0x0F);	// ein Taster wurde gedr�ckt
		if (RTCCON>=0x80) delay_timer();				// Realtime clock �berlauf
			
		n=timer;
		blink=((n>>1) & 0x01);
		TASTER=1;				        // Pin als Eingang schalten um Programmiertaster abzufragen
		if (!TASTER) {					// Programmiertaster gedr�ckt
			for(n=0;n<255;n++) {}
			while(!TASTER);				// warten bis Programmiertaster losgelassen
			progmode=!progmode;
		}
		if (progmode) TASTER = blink;	// LED blinkt im Prog-Mode
		else TASTER = !((eeprom[0xCD] & 0x10) >> 4);	// LED ist an oder aus gem�� Parameter f�r Betriebs-LED
  } while(1);
}

