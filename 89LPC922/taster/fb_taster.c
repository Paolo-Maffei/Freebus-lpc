/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008,2009,2010 Andreas Krebs <kubi@krebsworld.de>
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
//#define LPC936

#ifndef LPC936
	#include <P89LPC922.h>
#else
	#include <P89LPC935_6.h>
#endif	

#include "../lib_lpc922/fb_lpc922.h"
#include "../com/fb_delay.h"
#include "fb_app_taster.h"
#include "../com/fb_rs232.h"
//#include "fb_lpc922.c"
//#include "fb_lpc922.h"
#include"../com/watchdog.h"
//#define NOPROGBUTTON	// es ist kein prog Taster vorhanden sondern progmode wird durch druecken von taste 1&3 oder 2&4 aktiviert
#define NOPROGLED // Die Progled blinkt im Progmodus da sie auch Betriebs LED ist


unsigned char object_value[12];	// wird hier deklariert um den Speicher besser auszunutzen!!!


/** 
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
* 
* @return 
*/
void main(void)
{ 
	unsigned char n,LED;
	bit blink, verstell, verstellt;
	static __code unsigned char __at 0x1BFE LED_hell;	

	restart_hw();							// Hardware zuruecksetzen	
	watchdog_init();
	watchdog_start();
	for (n=0;n<50;n++) {
		TR0=0;					// Timer 0 anhalten
		TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Ger�te unterschiedlich beginnen zu senden
		TL0=eeprom[ADDRTAB+2];
		TF0=0;					// �berlauf-Flag zur�cksetzen
		TR0=1;					// Timer 0 starten
		while(!TF0);
	}
	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	rs_init(192);
	for (n=0;n<4;n++) switch_led(n,0);	// Alle LEDs gemaess ihren Parametern setzen

	LED=0;
	verstellt=0;
	dimmwert = LED_hell;

	do  {
		watchdog_feed();
		if (RTCCON>=0x80) delay_timer();	// Realtime clock ueberlauf

		n=timer;
		blink=((n>>5) & 0x01);
		verstell=((n>>2) & 0x01);
		
		if (verstell==0)verstellt=0;
		

		
		if (status60 & 0x01){			//wenn progmode aktiv ist...
			//n=dimmwert;//LED_hell;
			if ((PORT & 0x0F)==0x0E){	// Taste 1 gedr�ck
				if ((dimmwert<254) && (verstell==1)&& verstellt==0){
					dimmwert++;
					verstellt=1;
				}
			}
			if ((PORT & 0x0F)==0x0D){ // Taste 2 gedr�ckt
				if ((dimmwert>1) && (verstell==1)&& verstellt==0){
					dimmwert--;
					verstellt=1;
					}
			}
		}	
		else{	//Wenn also Modul nicht im Progmode ist..
		if ((PORT & 0x0F) != button_buffer) port_changed(PORT & 0x0F);	// ein Taster wurde gedrueckt
		}

//		if (tel_arrived) process_tel();		
		if (tel_arrived || tel_sent) {//
			tel_sent=0;
			process_tel();
		}
		
		
#ifndef NOPROGBUTTON
		TASTER=1;				        	// Pin als Eingang schalten um Programmiertaster abzufragen
		if (!TASTER) {						// Programmiertaster gedrueckt
				for(n=0;n<100;n++) {}
				while(!TASTER);					// warten bis Programmiertaster losgelassen
				status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
				if((status60 & 0x01)==0){	//wenn ausgemacht Dimmwert speichern
					EA=0;
					START_WRITECYCLE;
					FMADRH= 0x1B;		
					FMADRL= 0xFE; 
					FMDATA=	dimmwert; 
					STOP_WRITECYCLE;
					EA=1;
				}
				
		}
#else
		// progmode wird durch Taste 1&2 bzw. 3&4 getoggelt
		if (((PORT & 0x0F)== 0x03) || ((PORT & 0x0F)== 0x0C)) {
			while ((PORT & 0x0F)< 0x0F) ;	// Warten bis alle Taster losgelassen
			status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
		}
#endif

#ifdef NOPROGLED
		if (status60 & 0x01) TASTER = blink;		// LED blinkt im Prog-Mode
		else TASTER = !((eeprom[0xCD] & 0x10) >> 4);	// LED ist an oder aus gemaess Parameter fuer Betriebs-LED
#else
		if (status60 & 0x01) TASTER = 0;		// LED leuchtet im Prog-Mode
		else TASTER = 1;						// LED aus
#endif
/*     +++ folgendes wurde in die timer0 ISR verschoben. +++
		if((dimmcompare+2 ) <= dimmwert) LED = LEDSTATE;
		else LED = 0;
		//dimmcompare ++;
		PORT = LED | 0x0F;	// unteren 4 bits immer auf 1 lassen !!!
*/
		for(n=0;n<100;n++) {}

	}  while(1);
}



/*

#ifndef NOPROGBUTTON
		TASTER=1;				        	// Pin als Eingang schalten um Programmiertaster abzufragen
		if (!TASTER) {						// Programmiertaster gedrueckt
			for(n=0;n<100;n++) {}
			while(!TASTER);					// warten bis Programmiertaster losgelassen
			status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
		}
#else
		// progmode wird durch Taste 1&2 bzw. 3&4 getoggelt
		if (((PORT & 0x0F)== 0x03) || ((PORT & 0x0F)== 0x0C)) {
			while ((PORT & 0x0F)< 0x0F) ;	// Warten bis alle Taster losgelassen
			status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
		}
#endif
#ifdef NOPROGBUTTON
		if (status60&0x01) TASTER = blink;		// LED blinkt im Prog-Mode
		else TASTER = !((eeprom[0xCD] & 0x10) >> 4);	// LED ist an oder aus gemaess Parameter fuer Betriebs-LED
#else
		if (status60&0x01) TASTER = 0;		// LED leuchtet im Prog-Mode
		else TASTER = 1;						// LED aus
#endif

		for(n=0;n<100;n++) {}
  } while(1);
}
*/

