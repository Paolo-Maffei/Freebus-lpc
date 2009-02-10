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
#include "fb_app_mon.h"
#include "../com/fb_rs232.h"

unsigned char telegramm[23];
unsigned char telpos;		// Zeiger auf nächste Position im Array Telegramm
unsigned char cs;			// checksum


void timer1(void) interrupt 3	// Interrupt von Timer 1, 370us keine Busaktivität seit letztem Byte, d.h. Telegramm wurde komplett übertragen
{
  unsigned char data_laenge,n,ack;
  int m;
  bit ackok;

  EX1=0;					// ext. Interrupt stoppen 
  ET1=0;					// Interrupt von Timer 1 sperren
  m=0;
  ack=0;
  ackok=0;
  	do {
      if(FBINC==1) m++;
      else
      {
        ack=get_byte();
        ackok=1;
        m=1000;
      }
    } while (m<1000);

    data_laenge=(telegramm[5]&0x0F);		// Telegramm-Länge = Bit 0 bis 3
    
    for (n=0;n<(data_laenge+8);n++) {
    	rs_send_hex(telegramm[n]);
    	SBUF=' ';
    	while(!TI);
    	TI=0;
    }
    if (ackok) rs_send_hex(ack);
    SBUF=0x0D;
    while(!TI);
    TI=0;
    SBUF=0x0A;
    while(!TI);
    TI=0;
    
  telpos=0;  
  IE1=0;		// IRQ zurücksetzen
  EX1=1;		// externen Interrupt 0 wieder freigeben
  TR1=0;
}


void restart_app(void)		// Protokoll-relevante Parameter zurücksetzen
{
	P0M1=0x00;
	P0M2=0x00;

	
  
  

  

  
  telpos=0;			// empfangene Bytes an dieser Position im Array telegramm[] ablegen
}
