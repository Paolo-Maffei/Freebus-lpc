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

// Versionen:	3.00	erste Version Binäreingang auf HW Basis 3
//				3.01	Lesen von Objekten zugefügt
//				3.02	Fehler behoben: gelegentliches Dauersenden von Telegrammen
//				3.03	Fehler behoben: 2. Objekt eines Eingangs reagierte auf Flanken wie das erste
//				3.04	Bug beim Lesen eines GA-Wertes behoben
//				3.05	Bug: Empfing nach Senden eines Schaltbefehls keine Telegramme mehr 

	

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_in8.h"
#include "../com/fb_rs232.h"
//#include "../com/fb_rs232.c"

//#include "watchdog.h"

#ifdef IN8_2TE
#include "spi.h"
#endif

void main(void)
{ 
  unsigned int base;
  unsigned char n,tmp,objno,objstate;
  tmp;objno;objstate;
  restart_hw();				// Hardware zurücksetzen
TRIM+=2;
  //  rs_init(192);				// serielle Schnittstelle initialisieren
//  watchdog_init();
  SET_RTC (65)			//realtimerclock mit 65ms Ablaufzeit setzen 
  START_RTC					//...und starten

  restart_prot();			// Protokoll-relevante Parameter zurücksetzen
  restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen

#ifndef IN8_2TE
  portbuffer=P0;			// zunächst keine Änderungen bei Busspannungswiederkehr
#else
  portbuffer=spi_in_out();
#endif

  // Verzögerung Busspannungswiederkehr	
  for(base=0;base<=(eeprom[0xD4]<<(eeprom[0xFE]>>4)) ;base++){//faktor startverz hohlen und um basis nach links schieben
//	  start_rtc(130);		// rtc auf 130ms
		RTCCON=0x60;		// RTC anhalten und Flag löschen
		RTCH=0x1D;			// reload Real Time Clock für 65ms
		RTCL=0x40;
		RTCCON=0x61;		// RTC starten
	    while (RTCCON<=0x7F) ;	// Realtime clock ueberlauf abwarten
//	  stop_rtc;
  }
  TASTER=1;
  do  {
/*	    if (RI)
	    {
	    	RI=0;
	    	if (SBUF>47) rs_send_hex(read_obj_value(SBUF-48));
	    }
*/
#ifndef IN8_2TE
	  p0h=P0;				// prüfen ob ein Eingang sich geändert hat
#else
	  p0h=spi_in_out();
#endif
    if (p0h!=portbuffer) 
    {
      for(n=0;n<8;n++)					// jeden Eingangspin einzel prüfen
      {
        if ((((p0h>>n)&0x01) != ((portbuffer>>n)&0x01))&& !(blocked>>n)&0x01)
        {
          pin_changed(n);				// Änderung verarbeiten
        }
      }
      portbuffer=p0h;					// neuen Portzustand in buffer speichern
    }
	if (RTCCON>=0x80)delay_timer();	// Realtime clock ueberlauf

        	 
#ifdef zykls
	for(objno=0;objno<=7;objno++){	
    	tmp=(eeprom[0xD5+(objno*4)]&0x0C);//0xD5/ bit 2-3 zykl senden aktiv 
    	objstate=read_obj_value(objno);
    	if (((eeprom[0xCE+(objno>>1)] >> ((objno & 0x01)*4)) & 0x0F)==1){// bei Funktion=Schalten
			if ((tmp==0x04 && objstate==1)||(tmp==0x08 && objstate==0)|| tmp==0x0C){//bei zykl senden aktiviert
				n=timercnt[objno];
				if ((n & 0x7F) ==0){ 		//    wenn aus oder abgelaufen
					timercnt[objno] = (eeprom[0xD6+(objno*4)]& 0x3F)+ 0x80 ;//0xD6 Faktor Zyklisch senden x.1 + x.2 )+ einschalten
					timerbase[objno]=(eeprom[0xF6+((objno+1)>>1)]>>(4*((objno&0x01)^0x01)))&0x07;	//Basis zyklisch senden
					if (n & 0x80){// wenn timer ein war
						send_value(0x30 +1,objno,objstate);		// Eingang x.1 zyklisch senden
					}
				}
			}
			else timercnt[objno]=0;
  		}
	}

#endif

    TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
    if(!TASTER) {				// Taster gedrückt
      for(n=0;n<100;n++) {}
      while(!TASTER);
		EA=0;
		START_WRITECYCLE;
		WRITE_BYTE(0x00,0x60,userram[0x60] ^ 0x81);	// Prog-Bit und Parity-Bit im system_state toggeln
		STOP_WRITECYCLE;
		EA=1;
    }
	TASTER=!(userram[0x060] & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
    for(n=0;n<100;n++) {}
  } while(1);
}


