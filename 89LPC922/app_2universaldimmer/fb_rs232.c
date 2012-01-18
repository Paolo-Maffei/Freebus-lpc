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
/**
* @file   fb_rs232.c
* @author Andreas Krebs <kubi@krebsworld.de>
* @date    2008
*
* @brief  Hier sind ausschliesslich die RS232 Routinen fuer den 89LPC922
*
* 	serielle auf 115200,n,8,1
*/

#include "AllgDefs.h"
#include <P89LPC922.h>
#include "fb_rs232.h"
#include "DEBUG.h"
#include "fb_lpc9xx.h"


#ifdef IncludeRS232


/**
* serielle auf 115200,n,8,1 initialisieren
*
*
*
*/
void rs_init(void)
{
	P1M1&=0xFC;		// RX und TX auf bidirectional setzen
	P1M2&=0xFC;
	SCON=0x50;		// Mode 1, receive enable
	SSTAT|=0x40;	// TI wird am Ende des Stopbits gesetzt
	BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
	BRGR1=0x00;		// Baudrate = cclk/((BRGR1,BRGR0)+16)=(115200baud) = 00 30 (02 F0 für 9600 Baud)
	BRGR0=0x30;
	BRGCON|=0x01;	// Baudrate Generator starten
}






/**
*
*
*
*
*/
void rs_send_dec(unsigned int wert)
{
//	rs_send_hex_i(wert);
	unsigned int n;
	__bit zero;

	zero=1;

	n=0;
	while(wert>=10000){
		n++;
		wert-=10000;
	}
  	if(n>0)
  	{
  		SBUF=n+48;
  		while(!TI);
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
  		SBUF=n+48;
  		while(!TI);
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
  		SBUF=n+48;
  		while(!TI);
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
  		SBUF=n+48;
  		while(!TI);
  		TI=0;
  		zero=0;
  	}


  	SBUF=wert+48;
  	while(!TI);
  	TI=0;
}




/**
*
*
*
*
*/
void rs_send_s(unsigned char *s)
{
	unsigned char n=0;
	while (s[n]!=0)
	{
		if(s[n]==(unsigned char)'\n')
		{
			SBUF=0x0d;
			while(!TI);
			TI=0;
		}
		SBUF=s[n];
		while(!TI);
		TI=0;
		n++;
		if(n>254)
			return;
	}
	return;
}




/**
*
*
*
*
*/
void rs_send_hex(unsigned char wert)
{
	const unsigned char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	rs_send(hex[wert>>4]);
	rs_send(hex[wert&0x0F]);
}




/**
*
*
*
*
*/

void rs_send_hex_l(unsigned long wert)
{
	rs_send_hex(wert>>24);
	rs_send_hex(wert>>16);
	rs_send_hex(wert>>8);
	rs_send_hex(wert);
}




/**
*
*
*
*
*/
void rs_send_hex_i(unsigned int wert)
{
	rs_send_hex(wert>>8);
	rs_send_hex(wert);
}





/**
*
*
*
*
*/
void rs_send(unsigned char z)
{
	SBUF=z;
 	while(!TI);
 	TI=0;
}

void rs_show(unsigned char *s,unsigned int c1,unsigned int c2)
{
	rs_send_s("\n");
	rs_send_s(s);
	rs_send_s(": ");

	rs_send_hex_i(c1);
	rs_send_s(" ");
	rs_send_hex_i(c2);

}

#endif
