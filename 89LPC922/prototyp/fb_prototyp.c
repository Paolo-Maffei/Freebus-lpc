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


#include <P89LPC922.h>
#include "../lib_lpc922/fb_lpc922.h"
#include "fb_app_prototyp.h"




/** 
* Dies ist ein leeres Beispielprogramm zur Veranschaulichung was mindestens erfordelich ist,
* damit das Programm mit der Library läuft.
* 
*/

void main(void)
{ 
	unsigned char n;

	restart_hw();				// Hardware zuruecksetzen
	for (n=0;n<50;n++) {
		set_timer0(0xFFFF);		// Warten bis Bus stabil, nach Busspannungswiederkehr
		while(!TF0);
	}
	restart_app();				// Anwendungsspezifische Einstellungen zuruecksetzen

	do  {
		
		// ***************************************************************************
		// Hier ist der Platz für wiederkehrende Abfragen, die nicht zeitkritisch sind
		// ***************************************************************************
  

		if(tel_arrived) {		// empfangenes Telegramm abarbeiten
			tel_arrived=0;
			process_tel();
		}


		// Abfrage Programmier-Taster
		TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER) {				// Taster gedrückt
			for(n=0;n<100;n++) {}	// Entprell-Zeit
			while(!TASTER);			// warten bis Taster losgelassen
			status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
		}
		TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
		for(n=0;n<100;n++) {}	// falls Hauptroutine keine Zeit verbraucht, der LED etwas Zeit geben, damit sie auch leuchten kann
  } while(1);
}


