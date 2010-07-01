/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2008-2010 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */


#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "miniprot.h"
#include "fb_app_rs.h"
#include "../com/fb_rs232.h"


unsigned char rsin[30];		// seriell empfangener string
unsigned char rsinpos;

__code struct ga_record __at 0x1A00 ga_db[256];
__code unsigned char __at 0x1DFB echo;
__code unsigned int __at 0x1DFE baud;

/* Flash Belegung:
 * 1A00 bis 1DE7	250 mal GA und 2-Byte Wert
 *
 * 1DFB				lokales Echo an/aus
 * 1DFC bis 1DFD	eigene PA
 * 1DFE bis 1DFF	Baudrate
 */






// Empfangenes Telegramm verarbeiten
void write_value_req(void)
{
	unsigned char length;
	unsigned int ga;
	unsigned int val=0;

	eibledcount=0xff;// EIBLED lang einschalten

	length=telegramm[5]&0x0F;

	if (length<=3)	{
		rs_send_dec(telegramm[3]>>3);			// GA senden
		rs_send('/');
		rs_send_dec(telegramm[3] & 0x07);
		rs_send('/');
		rs_send_dec(telegramm[4]);
		rs_send('=');
		if (length==1) {						// bis max. 6 Bit Nutzdaten
			rs_send_dec(telegramm[7] & 0x3F);
			val=telegramm[7] & 0x3F;
		}
		if (length==2) {						// 8 Bit
			rs_send_dec(telegramm[8]);
			val=telegramm[8];
		}
		if (length==3) {						// 16 Bit
			rs_send_dec(256*telegramm[8]+telegramm[9]);
			val=256*telegramm[8]+telegramm[9];
		}		
		rs_send(13);							// CR LF
		rs_send(10);
		ga=256*telegramm[3]+telegramm[4];
		save_ga(ga,val);						// GA mit Wert speichern
	}
}


/**
* Gruppenadresse und deren Wert im Flash speichern
*
*
* @return
*/
void save_ga(unsigned int ga, unsigned int val)
{
	unsigned char n;
	bit write_ok;

	n=0;
	do {								// Wert der GA in Flash schreiben
		if(ga_db[n].ga==ga || ga_db[n].ga==0xFFFF) {
			write_ok=0;
			while (!write_ok) {
				START_WRITECYCLE
				if(ga_db[n].ga==0xFFFF) {			// GA noch nicht gespeichert
					FMADRH = (n >> 6) + 0x1A;		// Low Byte schreiben
					FMADRL = ((n & 0x3F) * 4);		// (int wird LSB first abgelegt)
					FMDATA=ga;
					FMDATA=ga>>8;
				}
				FMADRH = (n >> 6) + 0x1A;		// Low Byte schreiben
				FMADRL = ((n & 0x3F) * 4) + 2;
				FMDATA=val;
				FMDATA=val>>8;					// High Byte schreiben
				STOP_WRITECYCLE
				if(!(FMCON & 0x01)) write_ok=1;	// pruefen, ob erfolgreich geflasht
			}				
			n=250;	// Schleife abbrechen
		}
		n++;
	}while (n<250);
}


// erstellt den Anfang des Telegramms, length ist die Länge der Nutzdaten
void tel_header(unsigned int ga, unsigned char length)
{
    telegramm[0]=0xBC;
    telegramm[1]=eeprom[0xFC];
    telegramm[2]=eeprom[0xFD];
    telegramm[3]=ga>>8;
    telegramm[4]=ga;
    telegramm[5]=0xE0 + length;
    telegramm[6]=0x00;
}


// konvertiert die GA oder PA, die ab Position pos in rsin[] steht in eine int
unsigned int convert_adr(unsigned char pos)
{
	unsigned int adr;
	unsigned char sepcount, n, adr_tmp;
	bit firstrun;

	firstrun=1;
	sepcount=0;
	n=pos;
	adr=0;
	adr_tmp=0;
	while(rsin[n]!='=' && n<(rsinpos-1)) {
		if(rsin[n]!='/' && rsin[n]!='.') {
			if(!firstrun) adr_tmp*=10;
			adr_tmp+=rsin[n]-48;
			firstrun=0;
		}
		else {
			sepcount++;
			firstrun=1;
			adr+=adr_tmp;
			if (rsin[n]=='/') {		// für GA
				if (sepcount==1) adr=adr<<3; else adr=adr<<8;
			}
			else {					// für PA
				if (sepcount==1) adr=adr<<4; else adr=adr<<8;
			}
			adr_tmp=0;
		}
		n++;
	}
	adr+=adr_tmp;
    return(adr);
}



// gibt die Position des = Zeichens im empfangenen string zurück
unsigned char equal_pos(void)
{
	unsigned char n, pos;

	n=0;
	pos=0xFF;
	while(n<(rsinpos-1)) {
		if(rsin[n]=='=') pos=n;
		n++;
	}
	return(pos);
}


void serial_int(void) interrupt 4 using 1	// Interrupt on received char from serial port
{
	ES=0;
	if (rsinpos<30) {
		rxledcount=0x40;// * RXLED kurz eischalten
		if(SBUF!=0x0A) {
			rsin[rsinpos]=SBUF;		// store byte in rsin
			rsinpos++;
			if (echo) {
				while(!TI);
				SBUF=SBUF;
				TI=0;
			}
		}
	}
	else rsinpos=0;
	RI=0;
	ES=1;
}



void restart_app(void)
{
	unsigned char n;
	bit write_ok;
	
	P0M1=0x00;
	P0M2=0x00;

	for (n=0;n<50;n++) sysdelay(0xFFFF);	// Warten bis Bus stabil
	
	n=0;
	do {								// GA Tabelle löschen
		write_ok=0;
		while (!write_ok) {
			START_WRITECYCLE
			FMADRH = (n >> 6) + 0x1A;
			FMADRL = ((n & 0x3F) * 4);
			FMDATA=0xFF;					// High Byte GA schreiben
			FMDATA=0xFF;					// Low Byte GA schreiben
			FMDATA=0xFF;					// Wert
			FMDATA=0xFF;
			STOP_WRITECYCLE
			if(!(FMCON & 0x01)) write_ok=1;	// pruefen, ob erfolgreich geflasht
		}
		n++;
	}while(n<250);

	RI=0;
	TI=1;
	ES=1;
}
