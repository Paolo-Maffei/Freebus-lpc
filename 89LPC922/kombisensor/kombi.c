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
* @file   kombi.c
* @author Andreas Krebs <kubi@krebsworld.de>
* @date   Tue Jan 01 17:44:47 2009
* 
* @brief  Kombisensor for temperature and lux
*
* \par Changes:
*		1.00	erste Version
* 		1.01	Temperaturschwellen eingebaut
*		1.02	Temperaturwert senden komplett
* 		1.03	Helligkeitsschwellen und Nachregelung eingebaut
* 		1.04	zyklisches Senden f�r Werte, Schwellen und Nachregelung geht, Lux-Berechnung korrigiert
* 		1.05	Wert senden f�r Helligkeitsschwellen zugef�gt, auch zyklisch
* 		1.06	Verkn�pfungsobjekte zugef�gt, read_value_req() von hal in app verlegt
* 				neue Struktur f�r schwelle()
* 		1.07	Verz�gertes Senden bei Helligkeitsschwellen neu
* 		1.08	zuvor gesperrte Objekte senden bei Aufheben der Sperre sofort
* 				Objektwerte werden nur beim Senden aktualisiert
* 		1.09	Bug bei sehr hohen Lux-Werten behoben
* 		1.10	Bug bei Schwellen Senden, wenn nur Unter- oder �berschreiten gesendet werden soll
* 				Bug bei Timer�berlauf behoben
* 		2.00	auf lib portiert
* 		2.01	Korrekturwert Temperatur eingebaut
* 		2.02	Debug: zyklisches Senden nach restart ging nicht: Initialwerte ge�ndert
* 		2.03	Parameter zyklisches Senden in der restart abgefragt
* 		2.04	Klammerfehler bei zykl. senden behoben (ging bei 3min,10min, etc. nicht)
* 				ADC Routine wird bei interrupted unterbrochen um Programmieren zu erleichtern
* 		2.05	mit lib Version 1.24 compiliert
*/


#include <P89LPC922.h>

#include "../lib_lpc922/fb_lpc922.h"
#include "../com/onewire.h"
#include "../com/adc_922.h"
#include "app_kombi.h"


unsigned int timer;
unsigned int lastlux;
int lasttemp;

const unsigned char logtable[] = {0,9,17,27,40,53,66,79,88,96,101,106,109,112,255};
const unsigned char luxchange[] = {100,20,10,5,3};


void main(void)
{ 
	unsigned char n,m,delta;
	int th, change=0, eis5temp;
	signed char korrektur;
	unsigned int exponent, eis5lux, rest;

	restart_hw();				// Hardware zuruecksetzen

	for (n=0;n<50;n++) {		// Warten bis Bus stabil, nach Busspannungswiederkehr
		TR0=0;					// Timer 0 anhalten
		TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Ger�te unterschiedlich beginnen zu senden
		TL0=eeprom[ADDRTAB+2];
		TF0=0;					// �berlauf-Flag zur�cksetzen
		TR0=1;					// Timer 0 starten
		while(!TF0);
	}

	restart_app();				// Anwendungsspezifische Einstellungen zuruecksetzen


	do {
		if (eeprom[0x0D]==0xFF && fb_state==0 && !connected) {	// Nur wenn im run-mode und statemachine idle
			ET1=0;									// statemachine stoppen
			switch (sequence) {
			case 1:	
				interrupted=0;
				start_tempconversion();				// Konvertierung starten
				if (!interrupted) sequence=2;
				ET1=1;								// statemachine starten
				break;
			case 2:	
				interrupted=0;
				if (ow_read_bit() && !interrupted) sequence=3;		// Konvertierung abgeschlossen
				ET1=1;												// statemachine starten
				break;
			case 3:	
				interrupted=0;
				th=read_temp();							// Temperatur einlesen
				ET1=1;									// statemachine starten
				korrektur = eeprom[TEMPCORR];			// Parameter Korrekturwert Temperatur
				for (n=0;n<10;n++) th+=korrektur;
				if (!interrupted) {

					temp=th;
					
					if (temp != lasttemp) {
						eis5temp=(temp>>3)&0x07FF;		// durch 8 teilen, da sp�ter Exponent 3 dazukommt
						eis5temp=eis5temp+(0x18 << 8);	
						if (temp<0) eis5temp+=0x8000;	// Vorzeichen
						write_obj_value(1,eis5temp);
						schwelle(6);					// Temperaturschwellen pr�fen und ggf. reagieren
						schwelle(7);	  					
					}
					
					sequence=4;
				}
				break;
			case 4:				// Helligkeitswert konvertieren
				interrupted=0;
				Get_ADC(3);		// ADC-Wert holen
				ET1=1;			// statemachine starten
				if (!interrupted) {
					n=0;
					if (HighByte>=112) {
						lux=65535;
					}
					else {
						/*
						while (HighByte >= logtable[n]) n++;

						if (n>1) {
							lux=8;
							lux=lux<<(n-1);	// unterer Wert
						}

						else lux=0;
						*/
						lux=2;
						while (HighByte >= logtable[n]) {
							n++;
							lux=lux*2;
						}
						if (n<=1) lux=0;


						rest=HighByte-logtable[n-1];
						delta=logtable[n]-logtable[n-1];

						/*
						if (n<11) lux+=_divuint(rest<<(n+2),delta);
						else lux+=_divuint(rest<<(n-2),delta)<<4;
						*/
						if (n<11) m=n+2; else m=n-2;
						rest=rest<<m;
						rest=_divuint(rest,delta);
						if (n<11) lux+=rest; else lux+=rest<<4;


						if (n<7) lux+=(_divuint(LowByte<<(n+2),delta)>>8);

					}
					if (lux!=lastlux) {
						exponent=0x3800;	// Exponent 7

						eis5lux=lux>>1;
						eis5lux+=lux>>2;
						eis5lux+=lux>>5;


						while (eis5lux > 0x07FF) {	// Exponent erh�hen falls Mantisse zu gro�
							eis5lux=eis5lux>>1;
							exponent+=0x0800;
						}
						eis5lux+=exponent;

						write_obj_value(0,eis5lux);		// Lux Wert im userram speichern
						schwelle(4);					// Helligkeitsschwellen 2 und 3
						schwelle(5);
					}
					schwelle(3);	// Helligkeitsschwelle 1 trotzdem jedes mal weil es auch Nachregelung sein k�nnte
					sequence=1;
				}
				break;
				
			}



			// Senden von Temp bei �nderung
			change=((eeprom[TEMPPARAM]&0x70)>>4)*100;	// wenn change=0 wird nicht gesendet
			if(change) {
				if (((temp + change)<= lasttemp) || ((lasttemp + change)<= temp)) {	// bei �nderung um 1-3K
					WRITE_DELAY_RECORD(1,1,1,timer+1)
					lasttemp=temp;
				}
			}

			// Senden von Lux bei �nderung
			if (eeprom[LUXPARAM] & 0x70) {	// wenn Lux senden bei �nderung aktiv
				change=_divuint(lastlux,luxchange[(eeprom[LUXPARAM]&0x70)>>4]);
				if (change==0) change=1;		// mindestens 1 Lux �nderung
				if ((lux>lastlux && (lux-lastlux)>=change) || (lux<lastlux && (lastlux-lux)>=change)) {
					WRITE_DELAY_RECORD(0,1,1,timer+1)
					lastlux=lux;
				}
			}

			schwelle(8);	// Verkn�pfungsobjekte
			schwelle(9);

			if(RTCCON>=0x80) delay_timer();	// Realtime clock �berlauf

		}	// Ende des Bereiches, der nur im run-state laufen darf
		

		if(tel_arrived) process_tel();			// empfangenes Telegramm abarbeiten


		// Programmiertaster abfragen
		TASTER=1;					// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER) {				// Taster gedr�ckt
			for(n=0;n<100;n++) {}	// Entprell-Zeit
			while(!TASTER);			// warten bis Taster losgelassen
			status60^=0x81;			// Prog-Bit und Parity-Bit im system_state toggeln
		}
		TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
		if (fb_state==0) for(n=0;n<100;n++) {}	// etwas zeit zum leuchten, wenn Hauptschleife nicht aktiv
	} while(1);
}

