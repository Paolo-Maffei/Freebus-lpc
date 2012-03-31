/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2009-2012 Andreas Krebs <kubi@krebsworld.de>
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
	unsigned char n, tasterpegel=0;
	__bit tastergetoggelt=0;

	restart_hw();				// Hardware zuruecksetzen
	for (n=0;n<50;n++) {		// Warten bis Bus stabil, nach Busspannungswiederkehr
		TR0=0;					// Timer 0 anhalten
		TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
		TL0=eeprom[ADDRTAB+2];
		TF0=0;					// Überlauf-Flag zurücksetzen
		TR0=1;					// Timer 0 starten
	while(!TF0);
	}
	restart_app();				// Anwendungsspezifische Einstellungen zuruecksetzen

	do  {
		if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt und nicht in verbindungsorientierter Kommunikation

		// ***************************************************************************
		// Hier ist der Platz für wiederkehrende Abfragen, die nicht zeitkritisch sind
		// ***************************************************************************

		}

		if(tel_arrived) {		// empfangenes Telegramm abarbeiten
								// wenn eigene gesendete Telegramme auch verarbeitet werden sollen: if(tel_arrived || tel_sent) {
			process_tel();
		}


		// Abfrage Programmier-Taster
		TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER){ // Taster gedrückt
			if(tasterpegel<255)	tasterpegel++;
			else{
				if(!tastergetoggelt)status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
				tastergetoggelt=1;
			}
		}
		else {
			if(tasterpegel>0) tasterpegel--;
			else tastergetoggelt=0;
		}
		TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
		for(n=0;n<100;n++) {}		// falls Hauptroutine keine Zeit verbraucht, der LED etwas Zeit geben, damit sie auch leuchten kann
  } while(1);
}


