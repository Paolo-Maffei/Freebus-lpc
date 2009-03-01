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
/**
* @file   fb_rollo.c
* @author Andreas Krebs <kubi@krebsworld.de>
* @date   Tue Jan 01 17:44:47 2009
* 
* @brief  The Freebus relais application to switch  up to 8 relais \n
* Manufactorer code is 0x04 = Jung \n
* Device type    8 out (2038.10) 0x2060 Ordernumber: 2138.10REG    or \n
* 		4 out Devicetype 0x2062 = Jung Aktor 2134.16 
*
* \par Changes:
* 	3.15	Fehler mit PWM für alte Relais-Schaltung behoben
* 
* 
* @todo:
	- Prio beim Senden implementieren \n
	- Zwangsstellungsobjekte implementieren \n
	- run-mode abfragen \n
*/


#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_delay.h"
#include "fb_app_rollo.h"
#include "../com/fb_rs232.h"


/** 
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
* 
*
*/
void main(void)
{ 
	unsigned char n;
	restart_hw();							// Hardware zuruecksetzen
	for (n=0;n<50;n++) sysdelay(0xFFFF);	// Warten bis Bus stabil
	restart_prot();							// Protokoll-relevante Parameter zuruecksetzen
	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	  rs_init();				// serielle Schnittstelle initialisieren

	do  {
		if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf

		if(TF0) {			// Vollstrom für Relais ausschalten und wieder PWM ein
			TMOD=0x12;		// Timer 0 als PWM, Timer 1 als 16-Bit Timer
			TAMOD=0x01;
			TH0=DUTY;
			TF0=0;
			AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben
			PWM=1;			// PWM Pin muss auf 1 gesetzt werden, damit PWM geht !!!
			TR0=1;
		}
  
		TASTER=1;				        // Pin als Eingang schalten um Taster abzufragen
		if(!TASTER) {					// Taster gedrueckt
			for(n=0;n<100;n++) {}
			while(!TASTER);				// warten bis Taster losgelassen
			progmode=!progmode;
		}
		TASTER=!progmode;				// LED entsprechend schalten (low=LED an)
		for(n=0;n<100;n++) {}
  } while(1);
}


