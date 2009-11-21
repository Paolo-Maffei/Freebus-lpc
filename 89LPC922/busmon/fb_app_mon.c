/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2009 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

#include <P89LPC922.h>
#include "../lib_lpc922/fb_hal_lpc_sm.h"
#include "fb_app_mon.h"



void process_tel(void)		// Telegramm abarbeiten (entfällt hier)
{
}


void restart_app(void)		// Applikations-Parameter zurücksetzen
{
	P0M1=0x00;
	P0M2=0x00;
}
