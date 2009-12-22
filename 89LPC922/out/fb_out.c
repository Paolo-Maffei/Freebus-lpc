/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008, 2009 Andreas Krebs <kubi@krebsworld.de>
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
*	2.00	erstes Programm in C fï¿½r Hardware Ver. 2 \n
*	2.01	Schaltverzoegerung hinzugefuegt \n
*	2.02	Restart Fehler behoben \n
*	2.03	Arrays korrigiert \n
*	2.04	Bugs in bin_out behoben		\n
*	3.01	auf 89LPC922 portiert und Bugs behoben		\n
*	3.02	Verzoegerung ï¿½ber RTC		behobene Bugs: Verzoegerung geht nach einiger Zeit sehr langsam \n
*	3.03	Timer 0 fï¿½r PWM		\n
*	3.04	RX & TX Timing nochmals optimiert 	behobene Bugs: get_ack funktionierte nicht \n
*	3.05	Zeitschaltfunktion hinzugefuegt \n
*	3.06	ï¿½ffner-/Schliesserbetrieb und Verhalten nach Busspannungswiederkehr hinzugefuegt \n
*	3.07	Rueckmeldeobjekte eingefuegt \n
*	3.08	gat Array entfernt und durch gapos_in_gat funktion ersetzt \n
*	3.09	Sperrobjekte hinzugefuegt \n
*	3.10	Fehler in main() behoben (kein delay!)
*	3.11	Fehler bei Zusatzfunktionstyp behoben,  \n
*			Fehler bei Sperrobjekten behoben, \n
*			Relais ziehen jetzt vollen Strom auch bei Busspannungswiederkehr \n
*	3.12	Fehler bei Sperrobjekten und Rueckmeldung im out8 behoben,  \n
*			ausserdem ziehen Relais jetzt auch bei Busspannungswiederkehr mit vollem Strom. \n
*	3.13	Parametrierung fï¿½r alte/neue Relaisschaltung eingefuegt \n
*			Parametrierung fï¿½r 4-port / 8-port hinzugefuegt, damit eine Soft fï¿½r out4 und out8 \n
*			Parametrierung fï¿½r Handbetrieb zunaechst eingefuegt \n
*			read_value_request lief nicht korrekt, behoben \n
*			Rueckmeldung bei Busspannungswiederkehr funktioniert jetzt \n
*			Warteschleife bei Busspannungswiederkehr eingefuegt, wg. stabilitaet
*	3.14	Rückmelde-Telegramm löst intern jetzt max. zwei weitere Rückmeldungen aus
* 	3.15	Fehler mit PWM für alte Relais-Schaltung behoben
* 	3.16	Polarität der Sperrobjegte eingebaut
* 	3.17	Bug bei Polarität der Sperrobjekte behoben
* 	3.18	Progmode lässt sich per ets setzen
* 			Interrupts beim retart aus, da sonst ggf. flashen unterbrochen wird wenn int
* 			Ausführungszustand wird in Geräteinfo angezeigt
* 			NACK wird bei fehlerhaft empfangenem Telegramm gesendet
* 			Handsteuerung läuft
* 	3.19	Relais bekamen manchmal keinen Vollstrom -> behoben
* 			Interrupts bei progmode flashen in der main() aus
*   3.20	port_schalten() wird jetzt zentral von der main aufgerufen
*   3.30	umgestellt auf statemachine library
* 
* @todo:
	- Prio beim Senden implementieren \n
	- Zwangsstellungsobjekte implementieren \n
	- run-mode abfragen \n
*/


#include <P89LPC922.h>
#include "../lib_lpc922/fb_lpc922.h"
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

	for (n=0;n<50;n++) {
		set_timer0(0xFFFF);					// Warten bis Bus stabil
		while(!TF0);
	}
	
	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	bus_return();							// Aktionen bei Busspannungswiederkehr


	do  {
		if(eeprom[RUNSTATE]==0xFF) {	// nur wenn run-mode gesetzt

			if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf

			if(TF0 && (TMOD & 0x0F)==0x01) {			// Vollstrom für Relais ausschalten und wieder PWM ein
				TMOD=(TMOD & 0xF0) + 2;		// Timer 0 als PWM
				TAMOD=0x01;
				TH0=DUTY;
				TF0=0;
				AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben
				PWM=1;			// PWM Pin muss auf 1 gesetzt werden, damit PWM geht !!!
				TR0=1;
			}

			if (portchanged) port_schalten();				// Ausgänge schalten

			// portbuffer flashen, Abbruch durch ext-int wird akzeptiert und später neu probiert
			// T1-int wird solange abgeschaltet, timeout_count wird ggf. um 4ms (flashzeit) reduziert
			if (fb_state==0 && portbuffer!=eeprom[PORTSAVE]) {
				ET1=0;
				START_WRITECYCLE;
				WRITE_BYTE(0x01,PORTSAVE,portbuffer);
				STOP_WRITECYCLE;
				if (timeout_count>120) timeout_count-=120; else timeout_count=0;
				ET1=1;
			}

		}
		if (tel_arrived) {
			tel_arrived=0;
			process_tel();
		}

		
		
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


