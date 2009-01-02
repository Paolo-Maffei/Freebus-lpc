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


/* Versionen:	2.00	erstes Programm in C f�r Hardware Ver. 2
	2.01	Schaltverz�gerung hinzugef�gt
	2.02	Restart Fehler behoben
	2.03	Arrays korrigiert
	2.04	Bugs in bin_out behoben		
	3.01	auf 89LPC922 portiert und Bugs behoben		
	3.02	Verz�gerung �ber RTC		behobene Bugs: Verz�gerung geht nach einiger Zeit sehr langsam
	3.03	Timer 0 f�r PWM		
	3.04	RX & TX Timing nochmals optimiert 	behobene Bugs: get_ack funktionierte nicht
	3.05	Zeitschaltfunktion hinzugef�gt
	3.06	�ffner-/Schliesserbetrieb und Verhalten nach Busspannungswiederkehr hinzugef�gt
	3.07	R�ckmeldeobjekte eingef�gt
	3.08	gat Array entfernt und durch gapos_in_gat funktion ersetzt
	3.09	Sperrobjekte hinzugef�gt
	3.10	Fehler in main() behoben (kein delay!)
	3.11	Fehler bei Zusatzfunktionstyp behoben, 
			Fehler bei Sperrobjekten behoben,
			Relais ziehen jetzt vollen Strom auch bei Busspannungswiederkehr
	3.12	Fehler bei Sperrobjekten und R�ckmeldung im out8 behoben, 
			ausserdem ziehen Relais jetzt auch bei Busspannungswiederkehr mit vollem Strom.
	3.13	Parametrierung f�r alte/neue Relaisschaltung eingef�gt
			Parametrierung f�r 4-port / 8-port hinzugef�gt, damit eine Soft f�r out4 und out8
			Parametrierung f�r Handbetrieb zun�chst eingef�gt
			read_value_request lief nicht korrekt, behoben
			R�ckmeldung bei Busspannungswiederkehr funktioniert jetzt
			Warteschleife bei Busspannungswiederkehr eingef�gt, wg. stabilit�t

	todo:	- Objekt lesen muss bei allen Objekten funktionieren
			- Prio beim Senden implementieren
			- Zwangsstellungsobjekte implementieren
*/
	

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_out.h"


void main(void)
{ 
	unsigned char n;
	restart_hw();							// Hardware zur�cksetzen
	for (n=0;n<50;n++) sysdelay(0xFFFF);	// Warten bis Bus stabil
	restart_prot();							// Protokoll-relevante Parameter zur�cksetzen
	restart_app();							// Anwendungsspezifische Einstellungen zur�cksetzen

	do  {
		if(RTCCON>=0x80) delay_timer();	// Realtime clock �berlauf

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
		if(!TASTER) {					// Taster gedr�ckt
			for(n=0;n<100;n++) {}
			while(!TASTER);				// warten bis Taster losgelassen
			progmode=!progmode;
		}
		TASTER=!progmode;				// LED entsprechend schalten (low=LED an)
		for(n=0;n<100;n++) {}
  } while(1);
}


