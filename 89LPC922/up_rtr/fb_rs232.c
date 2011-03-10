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
#include "fb_rs232.h"


#ifdef ENABLE_RS_INIT
void rs_init(unsigned int baudrate)
{
	unsigned int brg;

	switch (baudrate) {
	case 96:		// 9600 Baud
		brg=0x02F0;
		break;
	case 192:		// 19200 Baud
		brg=0x0170;
		break;
	case 384:		// 38400 Baud
		brg=0x00B0;
		break;
	case 576:		// 57600 Baud
		brg=0x0070;
		break;
	default:		// in allen anderen Fällen 115200 Baud als default
		brg=0x0030;
	}
	BRGCON&=0xFE;	// Baudrate Generator stoppen
	P1M1&=0xFC;		// RX und TX auf bidirectional setzen
	P1M2&=0xFC;
	SCON=0x50;		// Mode 1, receive enable
	SSTAT|=0xE0;	// TI wird am Ende des Stopbits gesetzt und Interrupt nur bei RX und double TX buffer an
	BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
	BRGR1=brg>>8;	// Baudrate = cclk/((BRGR1,BRGR0)+16)
	BRGR0=brg;
	BRGCON|=0x01;	// Baudrate Generator starten
	TI=1;
}
#endif

#ifdef ENABLE_RS_SEND_DEC
void rs_send_dec(unsigned int wert)
{
	unsigned int n;
	bit zero;

	zero=1;
	
	n=0;
	while(wert>=10000){
		n++;
		wert-=10000;
	}
  	if(n>0)
  	{
  		while(!TI);
  		SBUF=n+48;

  		TI=0;
  		zero=0;
  	}
	
	n=0;
	while(wert>=1000){
		n++;
		wert-=1000;
	}
  	if(n>0 || !zero)
  	{
  		while(!TI);
  		SBUF=n+48;

  		TI=0;
  		zero=0;
  	}  	

	n=0;
	while(wert>=100){
		n++;
		wert-=100;
	}
  	if(n>0 || !zero)
  	{
  		while(!TI);
  		SBUF=n+48;

  		TI=0;
  		zero=0;
  	}

	n=0;
	while(wert>=10){
		n++;
		wert-=10;
	}
  	if(n>0 || !zero)
  	{
  		while(!TI);
  		SBUF=n+48;

  		TI=0;
  		zero=0;
  	}
  	
  	while(!TI);
  	SBUF=wert+48;

  	TI=0;
}
#endif


#ifdef ENABLE_RS_SEND_S
void rs_send_s(unsigned char *s)
{
	unsigned char n=0;
	while (s[n]!=0)
	{
		if((signed)s[n]=='\n')
		{
			while(!TI);
			SBUF=0x0d;

			TI=0;
		}
		while(!TI);
		SBUF=s[n];

		TI=0;
		n++;
		if(n>254)
			return;
	}
	return;
}
#endif


#ifdef ENABLE_RS_SEND_HEX
void rs_send_hex(unsigned char wert)
{
        const unsigned char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

        rs_send(hex[wert>>4]);
        rs_send(hex[wert&0x0F]);
}
#endif


#ifdef ENABLE_RS_SEND_HEXL
void rs_send_hex_l(unsigned long wert)
{
        const unsigned char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

        rs_send(hex[wert>>28&0x0F]);
        rs_send(hex[wert>>24&0x0F]);
        rs_send(hex[wert>>20&0x0F]);
        rs_send(hex[wert>>16&0x0F]);
        rs_send(hex[wert>>12&0x0F]);
        rs_send(hex[wert>>8&0x0F]);
        rs_send(hex[wert>>4&0x0F]);
        rs_send(hex[wert&0x0F]);
}
#endif


#ifdef ENABLE_RS_SEND_HEXI
void rs_send_hex_i(unsigned int wert)
{
        const unsigned char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        rs_send(hex[(wert>>12)&0x0F]);
        rs_send(hex[(wert>>8)&0x0F]);
        rs_send(hex[(wert>>4)&0x0F]);
        rs_send(hex[wert&0x0F]);
}
#endif


#if defined(ENABLE_RS_SEND) && ENABLE_RS_SEND
void rs_send(unsigned char z)
{
	while(!TI);
	SBUF=z;

 	TI=0;
}
#endif
