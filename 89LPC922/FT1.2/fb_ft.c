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
 *
 *	Versionen:	1.00	erste Version
 * 				1.01	int freigabe bei empfangenen telegrammen war zu früh
 * 				1.02	Makros in Schleifen korrigiert
 * 				1.10	umgestellt auf Library
 *
 */


	

#include <P89LPC922.h>
#include "../lib_lpc922/fb_lpc922.h"
#include "fb_app_ft.h"




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
  		if (rsinpos>0) {
	  
  			if (rsin[rsinpos-1]==0x16 && rsinpos==(rsin[1]+6)) ft_process_var_frame();
  			if (rsin[0]==0x10 && rsinpos==4) ft_process_fix_frame();
  			if (TF0) {		// timeout, frame verwerfen
  				rsinpos=0;
  				TR0=0;
  				TF0=0;
  			}
  		}
  		if (tel_arrived) {
  			tel_arrived=0;
  			process_telegram();
  		}
  		

  	} while(1);
}


