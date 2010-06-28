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
#include "../lib_lpc922/fb_lpc922.h"
#include "app_dcf.h"


unsigned char second=0, minute=0, hour=0, day=1, dow=0, month=1, year=0;
volatile unsigned char T0_count;

long timer;					// Timer für Schaltverzögerungen, wird alle 130us hochgezählt
bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszuführen



void write_value_req(void)
{
	unsigned char objno;

	objno=find_first_objno(telegramm[3],telegramm[4]);

	if (objno==2) {	// nur Zeit/Datum senden Objekt
		if (telegramm[7]==0x81) {
			//send_dt(1,0);
			//send_dt(1,1);
			send_obj_value(0);
			send_obj_value(1);
		}
	}
}


void read_value_req(void)
{
	unsigned char objno, objflags;

	objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
	if(objno!=0xFF) {	// wenn Gruppenadresse gefunden
		objflags=read_objflags(objno);		// Objekt Flags lesen

		// Objekt lesen, nur wenn read enable gesetzt (Bit3) und Kommunikation zulaessig (Bit2)
		if((objflags&0x0C)==0x0C) {
			if (objno==0) send_obj_value(0x40);
			if (objno==1) send_obj_value(0x41);
		}
	}
}


unsigned long read_obj_value(unsigned char objno)
{
	unsigned long ret_val=0;

	switch (objno)
	{
	case 0:
		ret_val=(dow<<5) + hour;
		ret_val=ret_val<<8;
		ret_val+=minute;
		ret_val=ret_val<<8;
		ret_val+=second;
		break;
	case 1:
		ret_val=day;
		ret_val=ret_val<<8;
		ret_val+=month;
		ret_val=ret_val<<8;
		ret_val+=year;
		break;
	}
	return (ret_val);
}

/*
void send_dt(unsigned char type, unsigned char objno)	// sucht Gruppenadresse für das Objekt objno uns sendet ein EIS Telegramm
{																	// mit dem Wert sval
	unsigned int ga;

	ga=find_ga(objno);	// wenn keine Gruppenadresse hintrlegt nix tun
	if (ga!=0)
	{
		while (fb_state!=0);
		telegramm[0]=0xBC;
		telegramm[1]=eeprom[ADDRTAB+1];
		telegramm[2]=eeprom[ADDRTAB+2];
		telegramm[3]=ga>>8;
		telegramm[4]=ga;
		telegramm[6]=0x00;
		if (type==0) telegramm[7]=0x40;		// read_value_response Telegramm (angefordert)
		else telegramm[7]=0x80;				// write_value_request Telegramm (nicht angefordert)

		if(objno==0) {				// time
			telegramm[5]=0xE4;
			telegramm[8]=(dow<<5) + hour;
			telegramm[9]=minute;
			telegramm[10]=second;
		}
		if(objno==1) {				// date
			telegramm[5]=0xE4;
			telegramm[8]=day;
			telegramm[9]=month;
			telegramm[10]=year;
		}
		send_tel();
	}
}  
*/

void T0_int(void) interrupt 1
{
	unsigned int tval;
	signed char corr;

	TR0=0;
	corr=eeprom[0xFD];
	tval=0x6FFF+TH0*256+TL0+corr;
	TH0=tval>>8;
	TL0=tval;
	TR0=1;
	T0_count++;
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
	WRITE_BYTE(0x01,0x07,0x10)	// Versionnumber of application programm
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0x3A)	// COMMSTAB Pointer
	STOP_WRITECYCLE
	START_WRITECYCLE;
	WRITE_BYTE(0x00,0x60,0x2E);	// system state: all layers active (run), not in prog mode
	STOP_WRITECYCLE;
	EA=1;						// Interrupts freigeben

	RTCH=0xE1;		// rtc auf 1000ms
	RTCL=0x00;
	RTCCON=0x61;	// rtc starten

	T0_count=0;
	TH0=0x6F;
	TL0=0xFF;
	TR0=1;
	TF0=0;
	ET0=1;
}
