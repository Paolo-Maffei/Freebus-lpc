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

	

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_in8.h"
//#include "../com/fb_rs232.h"



void main(void)
{ 

  unsigned char n;

  restart_hw();				// Hardware zurücksetzen
  restart_prot();			// Protokoll-relevante Parameter zurücksetzen
  restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
  portbuffer=0xFF;
  
  do  {
  
     
    p0h=P0;				// prüfen ob ein Eingang sich geändert hat
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
    
    TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
    if(!TASTER) {				// Taster gedrückt
      for(n=0;n<100;n++) {}
      while(!TASTER);
      progmode=!progmode;
    }
    TASTER=!progmode;				// LED entsprechend schalten (low=LED an)
    for(n=0;n<100;n++) {}
  } while(1);
}


