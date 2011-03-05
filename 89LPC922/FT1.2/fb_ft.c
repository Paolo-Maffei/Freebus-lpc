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
 *
 *	Versionen:	1.00	erste Version
 * 				1.01	int freigabe bei empfangenen telegrammen war zu früh
 * 				1.02	Makros in Schleifen korrigiert
 * 				1.10	umgestellt auf Library, thx to tuxbow :-)
 *
 */


	

#include <P89LPC922.h>
#include "../lib_LPC922/fb_lpc922.h"
#include "fb_app_ft.h"

/** 
* Timer 0 stoppen, setzen und starten (Timer wird mit CCLK/2 betrieben)
*
*
* \param deltime
*/
void set_timer0(unsigned int deltime)
{
  TR0=0;                    // Timer 0 anhalten
  deltime=0xFFFF-deltime;
  TH0=deltime>>8;           // Timer 0 setzen 
  TL0=deltime;  
  TF0=0;                    // Überlauf-Flag zuruecksetzen
  TR0=1;                    // Timer 0 starten
}




void main(void)
{ 
  unsigned char n;

  
  
	restart_hw();				// Hardware zurücksetzen
	for (n=0;n<50;n++) {
		set_timer0(0xFFFF);					// Warten bis Bus stabil
		while(!TF0);
	}
	restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
  
  
  	do  {
            n = rsin_stat;
            rsin_stat = RSIN_NONE;
            if ( n == RSIN_VARFRAME ) ft_process_var_frame();
            if ( n == RSIN_FIXFRAME ) ft_process_fix_frame();
/*
    		if (rsinpos>0) {
	  
  			if (rsin[rsinpos-1]==0x16 && rsinpos==(rsin[1]+6)) ft_process_var_frame();
  			if (rsin[0]==0x10 && rsinpos==4) ft_process_fix_frame();

  			if (TF0) {		// timeout, frame verwerfen
  				rsinpos=0;
  				TR0=0;
  				TF0=0;
  			}
*/
            if (tel_arrived) {
                tel_arrived=0;
                //if ( (telegramm[1]!=eeprom[ADDRTAB+1]) ||
                //     (telegramm[2]!=eeprom[ADDRTAB+2]) )
                   process_telegram();      // don't process self sent telegrams
            }
  		

  	} while(1);
}


