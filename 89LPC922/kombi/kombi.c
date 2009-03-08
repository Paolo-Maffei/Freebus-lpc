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
//#include "../com/fb_rs232.h"

long timer;

bit templevel1, templevel2;		// ist 0 wenn schwelle unterschritten, 1 wenn sdchwelle überschritten


const unsigned char logtable[] = {0,1,12,24,35,47,59,71,82,94,106,118,129,141,153};
const unsigned char luxchange[] = {100,20,10,5,3};


void main(void)
{ 
	unsigned char n,sequence,luxcount,delta, rest;

	int th, change=0;
	long luxtest;

	lux=0;
  
  
  	lastlux=0;
  	lasttemp=0;
	luxtest=0; 
	luxcount=0;



	templevel1=0;
	templevel2=0;
  
	restart_hw();				// Hardware zurücksetzen
	restart_prot();			// Protokoll-relevante Parameter zurücksetzen
	restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
  


  
	timer=0;
	sequence=1;
  
	do {
		P0_6=TR1;
		if (!TR1 && (eeprom[0x0D]==0xFF)) {	// Nur wenn nicht gerade TR1 läuft, also Senden/Empfangen noch nicht abgeschlossen
			switch (sequence) {						// Temperatur messen
			case 1:	
				interrupted=0;
				start_tempconversion();				// Konvertierung starten
				if (!interrupted) sequence=2;
				break;
			case 2:	
				if (ow_read_bit()) sequence=3;	// Konvertierung abgeschlossen
				break;
			case 3:	
				interrupted=0;
				th=read_temp();						// Temperatur einlesen
				if (!interrupted) {
					temp=th;
					if (temp != lasttemp) {
						eis5temp=temp>>3;					// durch 8 teilen, da später Exponent 3 dazukommt
						//eis5temp=eis5temp+((msb & 0x8000)<<8);	// Vorzeichen
						eis5temp=eis5temp+(0x18 << 8);	
						write_obj_value(1,eis5temp);
						temp_schwelle(0);			// Temperaturschwelle 1 prüfen und ggf. reagieren
						temp_schwelle(1);	  					
					}
					sequence=4;
				}
				//P0_6=!P0_6;							// Temperatur Sensor LED
				break;
			case 4:		// Helligkeitswert konvertieren
				Get_ADC(3);		// Lux-Wert holen
				n=0;
				while (HighByte >= logtable[n]) n++;
				if (n>1) {
					lux=8;
					lux=lux<<(n-1);	// unterer Wert
			  	}
					  
			  	else lux=0;
			  	rest=HighByte-logtable[n-1];
			  	delta=logtable[n]-logtable[n-1];
			  
			  	if (n<11) lux=lux+_divuint(rest<<(n+2),delta);
				
				//lux=lux+_divuint(_divuint(LowByte<<(n+2),delta),256);
				if (n<7) lux=lux+(_divuint(LowByte<<(n+2),delta)>>8);
				
				if (lux!=lastlux) {
					  eis5lux=lux;
					  eis5lux+=lux>>1;
					  eis5lux+=lux>>4;
					  eis5lux=eis5lux+(0x3000);			// Exponent 6
					  write_obj_value(0,eis5lux);
				  	  		
				  	  lux_schwelle(1);		// Helligkeitsschwellen
				  	  lux_schwelle(2);
				}
				lux_schwelle(0);	// Schwelle 0 trotzdem jedes mal weil es auch nachregelung sein könnte
				sequence=1;
				break;
				
			}
		}


	  
		if ((eeprom[TEMPPARAM] & 0x70)) {	// wenn Temp senden bei Änderung aktiv
			change=((eeprom[TEMPPARAM]&0x70)>>4)*100;
			if (((temp + change)<= lasttemp) || ((lasttemp + change)<= temp)) {	// bei Änderung um 1-3K
				send_eis(5,1,eis5temp);
				lasttemp=temp;
			}
		}

		if (eeprom[LUXPARAM] & 0x70) {	// wenn Lux senden bei Änderung aktiv		  
			change=_divuint(lastlux,luxchange[(eeprom[LUXPARAM]&0x70)>>4]);
			if (change==0) change=1;		// mindestens 1 Lux Änderung
			if (((lux + change)<= lastlux) || ((lastlux + change)<= lux)) {	// bei Änderung um 5-30%		  
				send_eis(5,0,eis5lux);
				lastlux=lux;
			}
		}

	  
		if(RTCCON>=0x80) delay_timer();	// Realtime clock Überlauf
	  
		TASTER=1;					// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER) {				// Taster wurde gedrückt
			for(n=0;n<100;n++) {}
			while(!TASTER);			// warten bis Taster losgelassen
			progmode=!progmode;
		}
		TASTER=!progmode;			// LED entsprechend schalten (low=LED an)
		for(n=0;n<100;n++) {}
	} while(1);
}

