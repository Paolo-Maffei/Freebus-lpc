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
	

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_in8T.h"
//#include "../com/fb_rs232.h"



void main(void)
{ 

  unsigned char n;
  unsigned char wait1 = 0;
  unsigned char wait2 = 0;
  restart_hw();				// Hardware zurücksetzen
  restart_prot();			// Protokoll-relevante Parameter zurücksetzen
  restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
  portbuffer=0x0F;
  
//  rs_init();
 
  do  {
  
    if(RTCCON>=0x80) {delay_timer();}		// Verzögerungs-Timer alle 130ms hochzählen
    p0h=(~P0)|0XF0;				// prüfen ob ein Eingang sich geändert hat(Taster low activ)
    if (p0h!=portbuffer) 
    {
      for(n=0;n<8;n++)					// jeden Eingangspin einzel prüfen
      {
        if (((p0h>>n)&0x01) != ((portbuffer>>n)&0x01))
        {
          pin_changed(n);				// Änderung verarbeiten
        }
      }
      portbuffer=p0h;					// neuen Portzustand in buffer speichern
    }
    wait2++;					//Zeitschleifenvariable für Progled
    if (wait2==0x20){
    	wait1++;
    	wait2=0x00;
    }
    TASTER= progmode&((wait1>>7)==1);
    if(((p0h & 0x0f)==0x03)|((p0h & 0x0f)== 0x0c)) {	// Taster 0&1 oder 2&3 gedrückt
      for(n=0;n<100;n++) {}
      while((P0|0xF0)<0xFF);
      progmode=!progmode;
    }
    //				// LED entsprechend schalten (low=LED an)
    for(n=0;n<100;n++) {}
  } while(1);
}


