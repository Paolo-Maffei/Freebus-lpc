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


// Versionen:	2.00	erstes Programm in C für Hardware Ver. 2
//		2.01	Schaltverzögerung hinzugefügt
//		2.02	Restart Fehler behoben
//		2.03	Arrays korrigiert
//		2.04	Bugs in bin_out behoben		
//		3.01	auf 89LPC922 portiert und Bugs behoben		
//		3.02	Verzögerung über RTC		behobene Bugs: Verzögerung geht nach einiger Zeit sehr langsam
//		3.03	Timer 0 für PWM		
//		3.04	RX & TX Timing nochmals optimiert 	behobene Bugs: get_ack funktionierte nicht
//		3.05	Zeitschaltfunktion hinzugefügt
//		3.06	Öffner-/Schliesserbetrieb und Verhalten nach Busspannungswiederkehr hinzugefügt
//		3.07	Rückmeldeobjekte eingefügt
//		3.08	gat Array entfernt und durch gapos_in_gat funktion ersetzt
//		3.09	Sperrobjekte hinzugefügt
//		3.10	Fehler in main() behoben (kein delay!)
//		3.11	Fehler bei Zusatzfunktionstyp behoben, 
//				Fehler bei Sperrobjekten behoben,
//				Relais ziehen jetzt vollen Strom auch bei Busspannungswiederkehr


//	todo:	- Rückmeldeobjekte müssen bei Busspannungswiederkehr senden
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

  restart_hw();				// Hardware zurücksetzen
  restart_prot();			// Protokoll-relevante Parameter zurücksetzen
  restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
  
  do  {
    if(RTCCON>=0x80) delay_timer();	// Realtime clock Überlauf
    TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
    if(!TASTER) {			// Taster gedrückt
      for(n=0;n<100;n++) {}
      while(!TASTER);			// warten bis Taster losgelassen
      progmode=!progmode;
    }
    TASTER=!progmode;			// LED entsprechend schalten (low=LED an)
    for(n=0;n<100;n++) {}
  } while(1);
}


