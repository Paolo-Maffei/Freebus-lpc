/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008,2009 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 * 
 */



#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "app_dcf.h"


unsigned char minute=0, hour=0, day=0, dow=0, month=0, year=0;

long timer;					// Timer für Schaltverzögerungen, wird alle 130us hochgezählt
bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszuführen



void write_value_req(void)				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
{
}


/** 
* Objektwert lesen wurde angefordert, read_value_response Telegramm zurücksenden
*
* 
* @return
* 
*/
void read_value_req(void)
{
}


void send_dt(unsigned char type, unsigned char objno)	// sucht Gruppenadresse für das Objekt objno uns sendet ein EIS Telegramm
{																	// mit dem Wert sval
  unsigned int ga;
  unsigned char objtype;

  ga=find_ga(objno);					// wenn keine Gruppenadresse hintrlegt nix tun
  if (ga!=0)
  {
    telegramm[0]=0xBC;
    telegramm[1]=eeprom[ADDRTAB+1];
    telegramm[2]=eeprom[ADDRTAB+2];
    telegramm[3]=ga>>8;
    telegramm[4]=ga;
    telegramm[6]=0x00;
    if (type==0) telegramm[7]=0x40;		// read_value_response Telegramm (angefordert)
    else telegramm[7]=0x80;				// write_value_request Telegramm (nicht angefordert)
    
    objtype=read_obj_type(objno);

    if(objno==0) {				// time
    	telegramm[5]=0xE4;
    	telegramm[8]=(dow<<5) + hour;
    	telegramm[9]=minute;
    	telegramm[10]=0;
    }
    if(objno==1) {				// date
    	telegramm[5]=0xE4;
    	telegramm[8]=day;
    	telegramm[9]=month;
    	telegramm[10]=year;
    }   

    EX1=0;
    send_telegramm();
    IE1=0;
    EX1=1;
  }

}  





void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{
	P0=0xFF;
	P0M1=0x00;		// Port 0 bidirectional
	P0M2=0x00;

 
	
	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	START_WRITECYCLE
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x000C = Merten
	WRITE_BYTE(0x01,0x04,0x0C)
	WRITE_BYTE(0x01,0x05,0x24)	// Devicetype 0x2422 Merten Zeitgeber
	WRITE_BYTE(0x01,0x06,0x22)
	WRITE_BYTE(0x01,0x07,0x01)	// Versionnumber of application programm
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0x9A)	// COMMSTAB Pointer
	STOP_WRITECYCLE
	START_WRITECYCLE;
	WRITE_BYTE(0x00,0x60,0x2E);	// system state: all layers active (run), not in prog mode
	STOP_WRITECYCLE;
	EA=1;						// Interrupts freigeben
}
