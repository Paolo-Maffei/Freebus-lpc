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


// Versionen:	2.00	erstes Programm in C f�r Hardware Ver. 2
//		2.01	Schaltverz�gerung hinzugef�gt
//		2.02	Restart Fehler behoben
//		2.03	Arrays korrigiert
//		2.04	Bugs in bin_out behoben		
//		3.01	auf 89LPC922 portiert und Bugs behoben		
//		3.02	Verz�gerung �ber RTC		behobene Bugs: Verz�gerung geht nach einiger Zeit sehr langsam
//		3.03	Timer 0 f�r PWM		
//		3.04	RX & TX Timing nochmals optimiert 	behobene Bugs: get_ack funktionierte nicht
//		3.05	Zeitschaltfunktion hinzugef�gt
//		3.06	�ffner-/Schliesserbetrieb und Verhalten nach Busspannungswiederkehr hinzugef�gt
//		3.07	R�ckmeldeobjekte eingef�gt
//		3.08	gat Array entfernt und durch gapos_in_gat funktion ersetzt
//		3.09	Sperrobjekte hinzugef�gt
//		3.10	Fehler in main() behoben (kein delay!)
//		3.11	Fehler bei Zusatzfunktionstyp behoben, 
//				Fehler bei Sperrobjekten behoben,
//				Relais ziehen jetzt vollen Strom auch bei Busspannungswiederkehr


//	todo:	- R�ckmeldeobjekte m�ssen bei Busspannungswiederkehr senden
//		- Objekt lesen muss bei allen Objekten funktionieren
//		- Prio beim Senden implementieren
//		- Zwangsstellungsobjekte implementieren

	

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_out4.h"





void main(void)
{ 
  unsigned char n;

  restart_hw();				// Hardware zur�cksetzen
  restart_prot();			// Protokoll-relevante Parameter zur�cksetzen
  restart_app();			// Anwendungsspezifische Einstellungen zur�cksetzen
  
  do  {
    if(RTCCON>=0x80) delay_timer();	// Realtime clock �berlauf
    TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
    if(!TASTER) {			// Taster gedr�ckt
      for(n=0;n<100;n++) {}
      while(!TASTER);			// warten bis Taster losgelassen
      progmode=!progmode;
    }
    TASTER=!progmode;			// LED entsprechend schalten (low=LED an)
    for(n=0;n<100;n++) {}
  } while(1);
}


