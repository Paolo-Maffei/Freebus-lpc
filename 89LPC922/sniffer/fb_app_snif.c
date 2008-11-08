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

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_snif.h"
#include "../com/fb_rs232.h"

void write_value_req(void)
{
  rs_send_dec(telegramm[3]>>3);
  SBUF='.';
  while(!TI);
  TI=0;
  rs_send_dec(telegramm[3] & 0x07);
  SBUF='.';
  while(!TI);
  TI=0;
  rs_send_dec(telegramm[4]);
  SBUF='=';
  while(!TI);
  TI=0;
  rs_send_dec(telegramm[7] & 0x01);
  SBUF=0x0D;
  while(!TI);
  TI=0;
  SBUF=0x0A;
  while(!TI);
  TI=0;
}






void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{

	start_writecycle();
	write_byte(0x01,0x04,0x01);	// Herstellercode 0x01 = Siemens
	write_byte(0x01,0x05,0x22);	// Geräte Typ (AP254) 221Ch
	write_byte(0x01,0x06,0x1C);	// 	"	"	"
	write_byte(0x01,0x07,0x01);	// Versionsnummer
	write_byte(0x01,0x0C,0x00);
	write_byte(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
	write_byte(0x01,0x12,0x56);	// COMMSTAB Pointer
	stop_writecycle();
  
}
