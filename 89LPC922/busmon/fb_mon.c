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

// Versionen:	1.00	erste Version Busmonitor

	

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_rs232.h"
#include "fb_app_mon.h"




void main(void)
{ 




  
  restart_hw();				// Hardware zurücksetzen
   restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
  
  rs_init();				// serielle Schnittstelle initialisieren
  while(1);
}


