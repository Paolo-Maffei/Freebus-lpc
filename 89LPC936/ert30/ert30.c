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
* 
*
*
*		1.00	erste Version
*		1.10	auf lib portiert, Bugs bei Verkn�pfung raus
*		1.11	Wartezeit nach reset verl�ngert (Probleme mit solltemp einstellung)
*		1.12	Solltemperaturobjekt eingef�gt, Sollwert wird im EEPROM gespeichert
*/

#define LPC936




#include <P89LPC935_6.h>

#include "../lib_lpc936/fb_lpc936.h"
#include "app_ert30.h"
#include "_divuint.c"
#include "../../89LPC922/com/onewire.h"
#include "../../89LPC922/com/adc_922.h"




unsigned int timer;

const unsigned char logtable[] = {0,9,17,27,40,53,66,79,88,96,101,106,109,112,255};
const unsigned char luxchange[] = {100,20,10,5,3};

// DAC Werte in 0,5� Schritten von 9,0� bis 40,0�
const unsigned char dactemp[] = {0,4, 	  8, 12, 15, 19, 22, 25, 28, 32, 36, 39,
										 43, 47, 51, 55, 59, 63, 67, 71, 77, 81,
										 85, 90, 94, 99,103,108,113,118,122,127,
										131,136,141,145,149,154,159,164,169,174,
										179,183,188,193,197,201,205,209,213,217,
										220,224,227,231,234,237,240,243,246,250,  253};


void main(void)
{ 
	unsigned char n,m,delta, tempx2;
	int th, change=0, eis5temp, lasttemp;
	unsigned int exponent, eis5lux, lastlux,rest;


	restart_hw();				// Hardware zur�cksetzen
	restart_app();			// Anwendungsspezifische Einstellungen zur�cksetzen
	P1_2=1;	// debug-led aus

	lasttemp=temp;
	lastlux=lux;


	do {
		if (eeprom[0x0D]==0xFF && fb_state==0) {	// Nur wenn nicht gerade TR1 l�uft, also Senden/Empfangen noch nicht abgeschlossen
			ET1=0;									// statemachine stoppen
			switch (sequence) {						// Temperatur messen
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
				if (!interrupted) {
					temp=th;

					// Anzeige der Temperatur auf dem ERT30 Display
					tempx2=_divuint((temp-25),50);
userram[1]=dactemp[tempx2-18];
					if (tempx2<18) tempx2=18;
					if (tempx2>80) tempx2=80;

					AD0DAT3=dactemp[tempx2-18]+eeprom[TEMPCORR];	// + Abgleichwert
					
					if (temp != lasttemp) {
						eis5temp=(temp>>3)&0x07FF;		// durch 8 teilen, da sp�ter Exponent 3 dazukommt
						eis5temp=eis5temp+(0x18 << 8);	
						if (temp<0) eis5temp+=0x8000;	// Vorzeichen
						write_obj_value(1,eis5temp);
						//schwelle(6);					// Temperaturschwellen pr�fen und ggf. reagieren
						schwelle(7);	  				// (nur Temp.Schwelle 2 pr�fen)	
					}
					
					sequence=4;
				}
				break;
			case 4:		// Helligkeitswert konvertieren
				interrupted=0;
				Get_ADC(2);		// ADC-Wert holen
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

			if (RLY && !lastrly) {	// Schaltausgang ein
				lastrly=1;
				write_obj_value(6,1);
				send_obj_value(6);
			}
			if (!RLY && lastrly) {	// Schaltausgang aus
				lastrly=0;
				write_obj_value(6,0);
				send_obj_value(6);
			}

			if (!editmode && solltemplcd != solltemplpc) sync();

			if (!RESET) restart_app();		// wenn Reset-Taste am ERT30 gedr�ckt wurde

			if(RTCCON>=0x80) delay_timer();	// Realtime clock �berlauf

		}	// Ende des Bereiches, der nur im run-state laufen darf

		
		if(tel_arrived) process_tel();			// empfangenes Telegramm abarbeiten

		// Programmiertaster abfragen
		TASTER=1;					// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER) {				// Taster gedr�ckt
			for(n=0;n<100;n++) {}	// Entprell-Zeit
			while(!TASTER);			// warten bis Taster losgelassen
			userram[0x60]^=0x81;			// Prog-Bit und Parity-Bit im system_state toggeln
		}
		TASTER=!(userram[0x60] & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
	} while(1);
}

