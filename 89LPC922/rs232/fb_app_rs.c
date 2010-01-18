/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2008, 2009 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
/**
* @file   fb_app_rs.c
* @author Andreas Krebs <kubi@krebsworld.de>
* @date   2008
*
* @brief
*
*/

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "miniprot.h"
#include "fb_app_rs.h"
#include "../com/fb_rs232.h"


unsigned char rsin[30];		// seriell empfangener string

__code struct ga_record __at 0x1A00 ga_db[256];

/**
* Empfangenes Telegramm verarbeiten
*
*
* @return
*/
void write_value_req(void)
{
	unsigned char length;
	unsigned int ga;
	unsigned int val=0;

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
					FMADRH = (n >> 6) + 0x1A;		// High Byte schreiben
					FMADRL = ((n & 0x3F) * 4) + 1;
					FMDATA=ga>>8;
				}
				FMADRH = (n >> 6) + 0x1A;		// Low Byte schreiben
				FMADRL = ((n & 0x3F) * 4) + 2;
				FMDATA=val;
				FMADRH = (n >> 6) + 0x1A;		// High Byte schreiben
				FMADRL = ((n & 0x3F) * 4) + 3;
				FMDATA=val>>8;
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


// konvertiert die GA, die ab Position pos in rsin[] steht in eine int
unsigned int convert_ga(unsigned char pos)
{
	unsigned int ga;
	unsigned char gah, gal;

    gah=((rsin[pos]-48)*10) + (rsin[pos+1]-48);
    gah=gah*8;
    gah=gah + (rsin[pos+3]-48);
    gal=((rsin[pos+5]-48)*100) + ((rsin[pos+6]-48)*10) + (rsin[pos+7]-48);
    ga=256*gah+gal;
    return(ga);
}



void restart_app(void)
{
	unsigned char n;
	
	//for (n=0;n<50;n++) sysdelay(0xFFFF);	// Warten bis Bus stabil
	
	n=0;
	do {								// GA Tabelle löschen
		START_WRITECYCLE
		FMADRH = (n >> 6) + 0x1A;
		FMADRL = ((n & 0x3F) * 4);
		FMDATA=0xFF;					// High Byte GA schreiben
		FMDATA=0xFF;					// Low Byte GA schreiben
		FMDATA=0xFF;					// Wert
		FMDATA=0xFF;
		STOP_WRITECYCLE
		n++;
	}while(n<250);
}
