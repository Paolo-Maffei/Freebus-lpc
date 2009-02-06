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
* @file   fb_out.c
* @author Andreas Krebs <kubi@krebsworld.de>
* @date   Tue Jan 01 17:44:47 2009
* 
* @brief  The Freebus relais application to switch  up to 8 relais \n
* Manufactorer code is 0x04 = Jung \n
* Device type    8 out (2038.10) 0x2060 Ordernumber: 2138.10REG    or \n
* 		4 out Devicetype 0x2062 = Jung Aktor 2134.16 
*
* \par Changes:
*	2.00	erstes Programm in C f�r Hardware Ver. 2 \n
*	2.01	Schaltverzoegerung hinzugefuegt \n
*	2.02	Restart Fehler behoben \n
*	2.03	Arrays korrigiert \n
*	2.04	Bugs in bin_out behoben		\n
*	3.01	auf 89LPC922 portiert und Bugs behoben		\n
*	3.02	Verzoegerung �ber RTC		behobene Bugs: Verzoegerung geht nach einiger Zeit sehr langsam \n
*	3.03	Timer 0 f�r PWM		\n
*	3.04	RX & TX Timing nochmals optimiert 	behobene Bugs: get_ack funktionierte nicht \n
*	3.05	Zeitschaltfunktion hinzugefuegt \n
*	3.06	�ffner-/Schliesserbetrieb und Verhalten nach Busspannungswiederkehr hinzugefuegt \n
*	3.07	Rueckmeldeobjekte eingefuegt \n
*	3.08	gat Array entfernt und durch gapos_in_gat funktion ersetzt \n
*	3.09	Sperrobjekte hinzugefuegt \n
*	3.10	Fehler in main() behoben (kein delay!)
*	3.11	Fehler bei Zusatzfunktionstyp behoben,  \n
*			Fehler bei Sperrobjekten behoben, \n
*			Relais ziehen jetzt vollen Strom auch bei Busspannungswiederkehr \n
*	3.12	Fehler bei Sperrobjekten und Rueckmeldung im out8 behoben,  \n
*			ausserdem ziehen Relais jetzt auch bei Busspannungswiederkehr mit vollem Strom. \n
*	3.13	Parametrierung f�r alte/neue Relaisschaltung eingefuegt \n
*			Parametrierung f�r 4-port / 8-port hinzugefuegt, damit eine Soft f�r out4 und out8 \n
*			Parametrierung f�r Handbetrieb zunaechst eingefuegt \n
*			read_value_request lief nicht korrekt, behoben \n
*			Rueckmeldung bei Busspannungswiederkehr funktioniert jetzt \n
*			Warteschleife bei Busspannungswiederkehr eingefuegt, wg. stabilitaet
*
* @todo:
	- Objekt lesen muss bei allen Objekten funktionieren \n
	- Prio beim Senden implementieren \n
	- Zwangsstellungsobjekte implementieren \n
*/


#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_delay.h"
#include "fb_app_out.h"


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

	do  {
		if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf

		if(TF0) {						// Vollstrom f�r Relais ausschalten
#ifdef GS1		// alte Relais-Schaltung mit Transistoren
			PWM=0;
#endif
#ifdef GS2		// neue Relais-Schaltung mit 74HC573
			PWM=1;	
#endif
			TMOD=0x12;		// Timer 0 als PWM, Timer 1 als 16-Bit Timer
			TAMOD=0x01;
			TH0=DUTY;
			TF0=0;
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


