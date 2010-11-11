/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008-2010 Andreas Krebs <kubi@krebsworld.de>
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
*/

#define LPC936




#include <P89LPC935_6.h>

#include "app_ert30.h"
#include "_divuint.c"
#include "../com/fb_hal_lpc936.h"
#include "../com/fb_prot.h"
#include "../com/onewire.h"
#include "../com/adc_922.h"
//#include "../com/fb_rs232.h"



unsigned int timer;

const unsigned char logtable[] = {0,1,12,24,35,47,59,71,82,94,106,118,129,141,153};
const unsigned char luxchange[] = {100,20,10,5,3};

// DAC Werte in 0,5° Schritten von 9,0° bis 40,0°
const unsigned char dactemp[] = {0,4, 	  8, 12, 15, 19, 22, 25, 28, 32, 36, 39,
										 43, 47, 51, 55, 59, 63, 67, 71, 77, 81,
										 85, 90, 94, 99,103,108,113,118,122,127,
										131,136,141,145,149,154,159,164,169,174,
										179,183,188,193,197,201,205,209,213,217,
										220,224,227,231,234,237,240,243,246,250,  253};


void main(void)
{ 
	unsigned char n,delta, rest, tempx2;
	int th, change=0;

	restart_hw();				// Hardware zurücksetzen
	restart_prot();			// Protokoll-relevante Parameter zurücksetzen
	restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
P1_2=1;	// debug-led

	//rs_init();

	do {
		if (!TR1 && (eeprom[0x0D]==0xFF)) {	// Nur wenn nicht gerade TR1 läuft, also Senden/Empfangen noch nicht abgeschlossen
			switch (sequence) {						// Temperatur messen
			case 1:	
				//P1_2=!P1_2;
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
				
			//rs_send(th>>8);
			//rs_send(th);
		  		
				if (!interrupted) {
					temp=th;

					// Anzeige der Temperatur auf dem ERT30 Display
					tempx2=_divuint((temp-25),50);
					if (tempx2<18) tempx2=18;
					if (tempx2>80) tempx2=80;
					AD0DAT3=dactemp[tempx2-18]+eeprom[TEMPCORR];	// + Abgleichwert
					
					if (temp != lasttemp) {
						eis5temp=(temp>>3)&0x07FF;			// durch 8 teilen, da später Exponent 3 dazukommt
						eis5temp=eis5temp+(0x18 << 8);	
						if (temp<0) eis5temp+=0x8000;		// Vorzeichen
						//schwelle(6);					// Temperaturschwellen prüfen und ggf. reagieren
						schwelle(7);	  				// (nur Temp.Schwelle 2 prüfen)	
					}
					
					sequence=4;
				}
				break;
			case 4:		// Helligkeitswert konvertieren
				Get_ADC(2);		// ADC-Wert holen
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
				if (n<7) lux=lux+(_divuint(LowByte<<(n+2),delta)>>8);
				
				if (lux!=lastlux) {
					  eis5lux=lux;
					  eis5lux+=lux>>1;
					  eis5lux+=lux>>4;
					  eis5lux=eis5lux+(0x3000);			// Exponent 6
				  	  schwelle(4);					// Helligkeitsschwellen 2 und 3
				  	  schwelle(5);
				}
				schwelle(3);	// Helligkeitsschwelle 1 trotzdem jedes mal weil es auch Nachregelung sein könnte
				sequence=1;
				break;
				
			}
		}


		// Senden von Temp und Lux bei Änderung
		if ((eeprom[TEMPPARAM] & 0x70)) {	// wenn Temp senden bei Änderung aktiv
			change=((eeprom[TEMPPARAM]&0x70)>>4)*100;
			if (((temp + change)<= lasttemp) || ((lasttemp + change)<= temp)) {	// bei Änderung um 1-3K
				//send_value(1,1,eis5temp);	
				WRITE_DELAY_RECORD(1,1,1,timer+1)
				lasttemp=temp;
			}
		}
		if (eeprom[LUXPARAM] & 0x70) {	// wenn Lux senden bei Änderung aktiv		  
			change=_divuint(lastlux,luxchange[(eeprom[LUXPARAM]&0x70)>>4]);
			if (change==0) change=1;		// mindestens 1 Lux Änderung
			if (((lux + change)<= lastlux) || ((lastlux + change)<= lux)) {	// bei Änderung um 5-30%		  
				//send_value(1,0,eis5lux);
				WRITE_DELAY_RECORD(0,1,1,timer+1)
				lastlux=lux;
			}
		}
		
		schwelle(8);	// Verknüpfungsobjekte
		schwelle(9);
		
		if (RLY && !lastrly) {	// Schaltausgang ein
			lastrly=1;
			send_value(1,6,1);
			write_obj_value(6,1);
		}
		if (!RLY && lastrly) {	// Schaltausgang aus
			lastrly=0;
			send_value(1,6,0);
			write_obj_value(6,0);
		}

		if (!RESET) restart_app();		// wenn Reset-Taste am ERT30 gedrückt wurde
	  
		if(RTCCON>=0x80) delay_timer();	// Realtime clock Überlauf
	  
		TASTER=1;					// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER) {				// Taster wurde gedrückt
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

