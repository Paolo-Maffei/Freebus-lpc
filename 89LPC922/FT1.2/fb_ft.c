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



void main(void)
{ 
  unsigned char n;
  
	restart_hw();				// Hardware zurücksetzen
	for (n=0;n<50;n++) {		// Warten bis Bus stabil, nach Busspannungswiederkehr
		TR0=0;					// Timer 0 anhalten
		TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
		TL0=eeprom[ADDRTAB+2];
		TF0=0;					// Überlauf-Flag zurücksetzen
		TR0=1;					// Timer 0 starten
		while(!TF0);
	}
	restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen

  	do  {
		n = rsin_stat;
		rsin_stat = RSIN_NONE;
		if ( n == RSIN_VARFRAME ) ft_process_var_frame();
		if ( n == RSIN_FIXFRAME ) ft_process_fix_frame();
		if (tel_arrived) process_telegram();
  	} while(1);
}


