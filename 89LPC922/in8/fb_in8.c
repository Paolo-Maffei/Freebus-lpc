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



void main(void)
{ 
  unsigned int base;
  unsigned char n;
  restart_hw();				// Hardware zurücksetzen
 // rs_init();				// serielle Schnittstelle initialisieren

  restart_prot();			// Protokoll-relevante Parameter zurücksetzen
  restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
  portbuffer=P0;			// zunächst keine Änderungen bei Busspannungswiederkehr
  // Verzögerung Busspannungswiederkehr	
  for(base=0;base<=(eeprom[0xD4]<<(eeprom[0xFE]>>4)) ;base++){//faktor startverz hohlen und um basis nach links schieben
	  start_rtc(130);		// rtc auf 130ms
	  while (RTCCON<=0x7F) ;	// Realtime clock ueberlauf abwarten
	  stop_rtc;
  }
  do  {
  
/*	    if (RI)
	    {
	    	RI=0;
	    	if (SBUF>47) rs_send_hex(read_obj_value(SBUF-48));
	    }
*/
	  
    p0h=P0;				// prüfen ob ein Eingang sich geändert hat
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
	if (RTCCON>=0x80) delay_timer();	// Realtime clock ueberlauf

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


