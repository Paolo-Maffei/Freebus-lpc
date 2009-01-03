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
#include "../com/fb_rs232.h"



void rs_init(void)
{
  SCON=0x50;	//Mode 1, receive enable
  SSTAT|=0x40;	// TI wird am Ende des Stopbits gesetzt
  BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
  BRGR1=0x00;	// Baudrate = cclk/((BRGR1,BRGR0)+16)=(115200baud)
  BRGR0=0x30;   //
  BRGCON|=0x01;	// Baudrate Generator starten
}

void rs_send_dec(unsigned char wert)
{
  unsigned char n;
  bit zero;

  zero=1;
  n=wert/100;
  if(n>0)
  {
    SBUF=n+48;
    while(!TI);
    TI=0;
    zero=0;
  }
  wert=wert-(n*100);
  n=wert/10;
  if((n>0) || !zero)
  {
    SBUF=n+48;
    while(!TI);
    TI=0;
  }
  wert=wert-(n*10);
  SBUF=wert+48;
  while(!TI);
  TI=0;
}

void rs_send_s(unsigned char *s)
{
  unsigned char n=0;
  while (s[n]!=0)
  {
    if(s[n]=='\n')
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


void rs_send_hex(unsigned char wert)
{
	const unsigned char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	rs_send(hex[wert>>4]);
	rs_send(hex[wert&0x0F]);
}



void rs_send_ok(void)
{
  SBUF='O';
  while(!TI);
  TI=0;
  SBUF='K';
  while(!TI);
  TI=0;
  SBUF=0x0D;
  while(!TI);
  TI=0;
  SBUF=0x0A;
  while(!TI);
  TI=0;
}

void rs_send(unsigned char z)
{
  SBUF=z;
  while(!TI);
  TI=0;
}
