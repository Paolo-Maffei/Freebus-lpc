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
* 
* @todo:
* 
*/


#include <P89LPC922.h>

#include "_divuint.c"
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/onewire.h"
#include "../com/adc_922.h"
#include "app_kombi.h"


unsigned int timer;

//const unsigned char logtable[] = {0,1,12,24,35,47,59,71,82,94,106,118,129,141,153,255};
const unsigned char logtable[] = {0,9,17,27,40,53,66,79,88,96,101,106,109,112,255};
const unsigned char luxchange[] = {100,20,10,5,3};


void main(void)
{ 
	unsigned char n,delta, rest;
	int th, change=0;
	unsigned int exponent;

	restart_hw();			// Hardware zur�cksetzen
	restart_prot();			// Protokoll-relevante Parameter zur�cksetzen
	restart_app();			// Anwendungsspezifische Einstellungen zur�cksetzen
  
	do {
		if (!TR1 && (eeprom[0x0D]==0xFF)) {	// Nur wenn nicht gerade TR1 l�uft, also Senden/Empfangen noch nicht abgeschlossen
			switch (sequence) {						// Temperatur messen
			case 1:	
				interrupted=0;
				start_tempconversion();				// Konvertierung starten
				if (!interrupted) sequence=2;
				break;
			case 2:	
				if (ow_read_bit()) sequence=3;		// Konvertierung abgeschlossen
				break;
			case 3:	
				interrupted=0;
				th=read_temp();						// Temperatur einlesen
			
		  		
				if (!interrupted) {
					temp=th;
					
					if (temp != lasttemp) {
						eis5temp=(temp>>3)&0x07FF;			// durch 8 teilen, da sp�ter Exponent 3 dazukommt
						eis5temp=eis5temp+(0x18 << 8);	
						if (temp<0) eis5temp+=0x8000;		// Vorzeichen
						schwelle(6);					// Temperaturschwellen pr�fen und ggf. reagieren
						schwelle(7);	  					
					}
					
					sequence=4;
				}
				break;
			case 4:		// Helligkeitswert konvertieren
				Get_ADC(3);		// ADC-Wert holen
				n=0;
				if (HighByte>=112) {
					lux=65535;
				}
				else {
					while (HighByte >= logtable[n]) n++;
				
					if (n>1) {
						lux=8;
						lux=lux<<(n-1);	// unterer Wert
					}
					  
					else lux=0;
				
					rest=HighByte-logtable[n-1];
					delta=logtable[n]-logtable[n-1];
			  
					if (n<11) lux+=_divuint(rest<<(n+2),delta);
					else lux+=_divuint(rest<<(n-2),delta)<<4;
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
		//eis5lux=256*HighByte+LowByte;
				  	schwelle(4);					// Helligkeitsschwellen 2 und 3
				  	schwelle(5);
				}
				schwelle(3);	// Helligkeitsschwelle 1 trotzdem jedes mal weil es auch Nachregelung sein k�nnte
				sequence=1;
				break;
				
			}
		}


		// Senden von Temp und Lux bei �nderung
		if ((eeprom[TEMPPARAM] & 0x70)) {	// wenn Temp senden bei �nderung aktiv
			change=((eeprom[TEMPPARAM]&0x70)>>4)*100;
			if (((temp + change)<= lasttemp) || ((lasttemp + change)<= temp)) {	// bei �nderung um 1-3K
				//send_value(1,1,eis5temp);	
				WRITE_DELAY_RECORD(1,1,1,timer+1)
				lasttemp=temp;
			}
		}
		if (eeprom[LUXPARAM] & 0x70) {	// wenn Lux senden bei �nderung aktiv		  
			change=_divuint(lastlux,luxchange[(eeprom[LUXPARAM]&0x70)>>4]);
			if (change==0) change=1;		// mindestens 1 Lux �nderung
			//if (((lux + change)<= lastlux) || ((lastlux + change)<= lux)) {	// bei �nderung um 5-30%
			if ((lux>lastlux && (lux-lastlux)>=change) || (lux<lastlux && (lastlux-lux)>=change)) {
				//send_value(1,0,eis5lux);
				WRITE_DELAY_RECORD(0,1,1,timer+1)
				lastlux=lux;
			}
		}
		
		schwelle(8);	// Verkn�pfungsobjekte
		schwelle(9);

	  
		if(RTCCON>=0x80) delay_timer();	// Realtime clock �berlauf
	  
		TASTER=1;					// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER) {				// Taster wurde gedr�ckt
			for(n=0;n<100;n++) {}
			while(!TASTER);			// warten bis Taster losgelassen
			  EA=0;
		      START_WRITECYCLE;
		      WRITE_BYTE(0x00,0x60,userram[0x60] ^ 0x81);	// Prog-Bit und Parity-Bit im system_state toggeln
		      STOP_WRITECYCLE;
		      EA=1;
		}
	    TASTER=!(userram[0x060] & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
	} while(1);
}

