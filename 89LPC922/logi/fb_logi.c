/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2010 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *	1.00	erste Version 8 Logikgatter
 */


#include <P89LPC922.h>
#include "../lib_lpc922/fb_lpc922.h"
#include "fb_app_logi.h"




/** 
* Logische Verknüpfung
* 
*/

void main(void)
{ 
	unsigned char n, gateno;
	bit q=0, a=0, b=0;

	restart_hw();				// Hardware zuruecksetzen
	for (n=0;n<50;n++) {
		set_timer0(0xFFFF);		// Warten bis Bus stabil, nach Busspannungswiederkehr
		while(!TF0);
	}
	restart_app();				// Anwendungsspezifische Einstellungen zuruecksetzen

	do {
		if(eeprom[RUNSTATE]==0xFF) {	// nur wenn run-mode gesetzt

			P0=gate_q;					// Ausgänge der Gatter auf LEDs ausgeben

			for(gateno=0; gateno<8; gateno++) {		// Schleife über 8 Gatter
				a=(gate_a>>gateno) & 0x01;			// Eingang A
				b=(gate_b>>gateno) & 0x01;			// Eingang B
				switch(eeprom[0xF4+gateno]) {		// Gattertyp aus eeprom lesen
				case 0:		// AND
					q = a & b;
					break;
				case 1:		// OR
					q = a | b;
					break;
				case 2:		// NAND
					q = ! (a & b);
					break;
				case 3:		// NOR
					q = ! (a | b);
					break;
				case 4:		// EXOR
					q = a ^ b;
					break;
				case 5:		// NEXOR
					q = ! (a ^ b);
				}


				if(q!=((gate_q >> gateno)&0x01)) {	// Telegramm senden nur wenn sich Zustand geändert hat
					if(q) gate_q|=1<<gateno;		// neuen Zustand von Gatterausgang speichern
					else gate_q&=0xFF-(1<<gateno);
					send_obj_value(gateno*3+2);		// Telegramm senden
				}
			}

		}

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


