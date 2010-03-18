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
* @date   2009
* 
* @brief The Freebus Taster Application, Firmware fuer einen 4-fach Taster mit 4 LEDs
*		Herstellercode 0x0004 = Jung
*		Devicetype 0x1052 = Jung Tastsensor 2092
*		in ETS das Applikationsprogramm "Universal/Schalten 105201" auswaehlen
*
* \par Changes:
*		1.00	erste Version;
*		1.01	eigenes Telegramm wird ausgewertet, "Affengriff" entprellt
* 		1.02	div. bugs behoben
* 		1.03	Fehler bei Lamellenverstellzeit (T2) behoben
* 
*/
	

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_delay.h"
#include "fb_app_taster.h"



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
	for (n=0;n<50;n++) {
		set_timer0(0xFFFF);					// Warten bis Bus stabil
		while(!TF0);
	}
	restart_prot();							// Protokoll-relevante Parameter zuruecksetzen
	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen

	do  {

#ifdef TASTER_4
		if ((PORT & 0x0F) != button_buffer) port_changed(PORT & 0x0F);	// ein Taster wurde gedrueckt
#else
		if (PORT != button_buffer) port_changed(PORT);	// ein Taster wurde gedrueckt
#endif


		if (RTCCON>=0x80) delay_timer();	// Realtime clock ueberlauf
			
		n=timer;
		blink=((n>>4) & 0x01);
		
		TASTER=1;				        	// Pin als Eingang schalten um Programmiertaster abzufragen
		if (!TASTER)
		{						// Programmiertaster gedrueckt
			for(n=0;n<100;n++) {}
			while(!TASTER);					// warten bis Programmiertaster losgelassen
			START_WRITECYCLE;
			WRITE_BYTE(0x00,0x60,userram[0x60] ^ 0x81);	// Prog-Bit und Parity-Bit im system_state toggeln
			STOP_WRITECYCLE;
		}

		if (userram[0x60]&0x01)
		{
			TASTER = blink;		// LED blinkt im Prog-Mode
		}
		else
		{
			TASTER = !((eeprom[0xCD] & 0x10) >> 4);	// LED ist an oder aus gemaess Parameter fuer Betriebs-LED
		}


		for(n=0;n<100;n++) {}
  } while(1);
}


