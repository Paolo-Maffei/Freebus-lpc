/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008-2011 Andreas Krebs <kubi@krebsworld.de>
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
*	2.00	erstes Programm in C für Hardware Ver. 2 \n
*	2.01	Schaltverzögerung hinzugefügt \n
*	2.02	Restart Fehler behoben \n
*	2.03	Arrays korrigiert \n
*	2.04	Bugs in bin_out behoben		\n
*	3.01	auf 89LPC922 portiert und Bugs behoben		\n
*	3.02	Verzögerung über RTC		behobene Bugs: Verzoegerung geht nach einiger Zeit sehr langsam \n
*	3.03	Timer 0 für PWM		\n
*	3.04	RX & TX Timing nochmals optimiert 	behobene Bugs: get_ack funktionierte nicht \n
*	3.05	Zeitschaltfunktion hinzugefuegt \n
*	3.06	Öffner-/Schliesserbetrieb und Verhalten nach Busspannungswiederkehr hinzugefügt \n
*	3.07	Rückmeldeobjekte eingefuegt \n
*	3.08	gat Array entfernt und durch gapos_in_gat funktion ersetzt \n
*	3.09	Sperrobjekte hinzugefügt \n
*	3.10	Fehler in main() behoben (kein delay!)
*	3.11	Fehler bei Zusatzfunktionstyp behoben,  \n
*			Fehler bei Sperrobjekten behoben, \n
*			Relais ziehen jetzt vollen Strom auch bei Busspannungswiederkehr \n
*	3.12	Fehler bei Sperrobjekten und Rueckmeldung im out8 behoben,  \n
*			ausserdem ziehen Relais jetzt auch bei Busspannungswiederkehr mit vollem Strom. \n
*	3.13	Parametrierung für alte/neue Relaisschaltung eingefügt \n
*			Parametrierung für 4-port / 8-port hinzugefügt, damit eine Soft fï¿½r out4 und out8 \n
*			Parametrierung für Handbetrieb zunaechst eingefügt \n
*			read_value_request lief nicht korrekt, behoben \n
*			Rückmeldung bei Busspannungswiederkehr funktioniert jetzt \n
*			Warteschleife bei Busspannungswiederkehr eingefügt, wg. stabilitaet
*	3.14	Rückmelde-Telegramm löst intern jetzt max. zwei weitere Rückmeldungen aus
* 	3.15	Fehler mit PWM für alte Relais-Schaltung behoben
* 	3.16	Polarität der Sperrobjegte eingebaut
* 	3.17	Bug bei Polarität der Sperrobjekte behoben
* 	3.18	Progmode lässt sich jetzt per ets setzen
* 			Interrupts beim retart aus, da sonst ggf. flashen unterbrochen wird wenn int
* 			Ausführungszustand wird in Geräteinfo angezeigt
* 			NACK wird bei fehlerhaft empfangenem Telegramm gesendet
* 			Handsteuerung läuft
* 	3.19	Relais bekamen manchmal keinen Vollstrom -> behoben
* 			Interrupts bei progmode flashen in der main() aus
*   3.20	port_schalten() wird jetzt zentral von der main aufgerufen
*   3.30	umgestellt auf statemachine library
*   3.31	ein paar lokale Variablen enfernt um stack zu entlasten
*   3.32	Funktion bei Beginn/Ende der Sperre nur wenn Sperre vorher inaktiv/aktiv war
*   3.33	Auf lib Version 1.22 f.f. angepasst (tel_sent, rtc- und timer-funktion)
 


* @todo:
	- Prio beim Senden implementieren \n
	- Zwangsstellungsobjekte implementieren \n
*/


#include <P89LPC922.h>
#include "../lib_lpc922/fb_lpc922.h"
#include "fb_app_out.h"

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
	signed char cal;
	static __code signed char __at 0x1BFF trimsave;
	
	restart_hw();							// Hardware zuruecksetzen

	cal=trimsave;
	TRIM = TRIM+trimsave;

	for (n=0;n<50;n++) {		// Warten bis Bus stabil
		TR0=0;					// Timer 0 anhalten
		TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
		TL0=eeprom[ADDRTAB+2];
		TF0=0;					// Überlauf-Flag zurücksetzen
		TR0=1;					// Timer 0 starten
		while(!TF0);
	}

	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen
	bus_return();							// Aktionen bei Busspannungswiederkehr

	do  {
		if(eeprom[RUNSTATE]==0xFF) {	// nur wenn run-mode gesetzt

			if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf
			if(TF0 && (TMOD & 0x0F)==0x01) {	// Vollstrom für Relais ausschalten und wieder PWM ein
#ifndef SPIBISTAB
				TMOD=(TMOD & 0xF0) + 2;			// Timer 0 als PWM
				TAMOD=0x01;
				TH0=DUTY;
#endif				
				TF0=0;
#ifndef SPIBISTAB
				AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben
#endif
				PWM=1;			// PWM Pin muss auf 1 gesetzt werden, damit PWM geht !!!
#ifndef SPIBISTAB
				TR0=1;
#else
				P0=portbuffer;
#endif				
			}

			if (portchanged)port_schalten();	// Ausgänge schalten

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
		if (tel_arrived || tel_sent) {
			tel_arrived=0;
			tel_sent=0;
			process_tel();
		}

		
		
		TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER) {				// Taster gedrückt
			for(n=0;n<100;n++) {}	// Entprell-Zeit
			n=0;
			while(!TASTER)			// warten bis Taster losgelassen
			 {
				while (RTCCON<0x80);
				if (n<=254)	n++;
				RTCCON=0x60;	// Real Time Clock stoppen
				RTCH=0x01;		// Real Time Clock auf 8ms laden (0,008s x 7372800 / 128)
				RTCL=0xCD;		// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
				RTCCON=0x61;	// ... und starten
			 }
				if(n<125){
					status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
				}
				else
				{					//länger als 1 Sekunde
					if (n<250){
						cal++;//kürzer als 2 sekunden
						TRIM+=1;
					}
					else{
						cal--;
						TRIM-=1;
					}
					EA=0;
					START_WRITECYCLE;	//cal an 0x1bff schreiben
					FMADRH= 0x1B;		
					FMADRL= 0xFF; 
					FMDATA=	cal; 
					STOP_WRITECYCLE;
					EA=1;				//int wieder freigeben
				}
				RTCCON=0x60;	// Real Time Clock stoppen
				RTCH=0x0E;		// Real Time Clock auf 65ms laden (0,065 x 7372800 / 128)
				RTCL=0xA0;		// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
				RTCCON=0x61;	// ... und starten


		}
		TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
		for(n=0;n<100;n++) {}	// falls Hauptroutine keine Zeit verbraucht, der LED etwas Zeit geben, damit sie auch leuchten kann
  } while(1);
}


