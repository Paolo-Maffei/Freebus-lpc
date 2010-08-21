/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2010 Jan Wegner
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */


#include <P89LPC922.h>
#include "4temp_onewire.h"

#define OWDATA 	P0_2	// Data-Pin f�r one-wire Sensor


bit ow_init(void)		// one-wire Ger�t initialisieren
{
  bit presence;
  unsigned char n;

  presence=1;

  OWDATA=0;

  owdelay(2500);

  OWDATA=1;

  for (n=0;n<255;n++) presence=presence & OWDATA;

  presence=!presence;
  return (presence);
}



void ow_write(unsigned char owbyte)	// Byte an one-wire Ger�t senden
{
  unsigned char n,m;

  for (n=1;n!=0;n=n<<1)		// LSB first
  {
	if (owbyte & n)
    {
      for (m=0;m<2;m++) OWDATA=0;	// 1-Bit: 5�s auf low dann auf high und 85�s warten

      OWDATA=1;

      owdelay(260);
    }
    else
    {
      OWDATA=0;			// 0-Bit: 90�s auf low dann auf high

      owdelay(275);

      OWDATA=1;

    }
  }
}



unsigned char ow_read(void)			// Byte von one-wire Ger�t lesen
{
  unsigned char n,m,d;

  d=0;
  for (n=1;n!=0;n=n<<1)
  {
    for (m=0;m<2;m++) OWDATA=0;

	OWDATA=1;

	owdelay(1);
    if (OWDATA) d|=n;

	owdelay(140);
  }
  return(d);
}



bit ow_read_bit(void)				// Bit von one-wire Datenleitung einlesen
{
	unsigned char m;
	bit b;

	for (m=0;m<2;m++) OWDATA=0;

	OWDATA=1;

	owdelay(1);

	b=OWDATA;

	owdelay (140);
	return (b);
}



void start_tempconversion(void)		// Temperaturmessung starten
{
	if (ow_init()) {
		ow_write(0xCC);			// Skip-ROM command: alle parallel angeschlossenen Ger�te werden angesprochen
		ow_write(0x44);			// start single temperature conversion command
	}
}



signed int read_temp(unsigned char sensortyp)					// Temperatur einlesen
{
	unsigned char lsb,msb;
	signed int t;
	unsigned int t2;
	unsigned char sign;
	unsigned char counts;


  	if (ow_init()) {
  		ow_write(0xCC);				// Skip-ROM command: alle parallel angeschlossenen Ger�te werden angesprochen
  		ow_write(0xBE);				// read scratchpad command: Speicher einlesen
  		lsb=ow_read();				// LSB von Temperaturwert
  		msb=ow_read();				// MSB von Temperaturwert


		if(sensortyp==2){			// DS18S20
			counts=ow_read();
			counts=ow_read();
			counts=ow_read();
			counts=ow_read();
			counts=ow_read();		// counts remaining

			msb&=0xF8;				// oberen 3 Bits von LSB in untere 3 von MSB
			msb+=(lsb>>5)&0x07;

			lsb=lsb<<3;				// LSB um 3 Bit nach oben verschieben
			lsb&=0xF0;				// alles unterhalb 2^0 abschneiden
			lsb+=(16-counts);
		}


		sign=msb&0x80;
  		t2=msb*256+lsb;
  		if (sign) t2=(0xFFFF-t2)+1;



  		t=t2*6;
  		t2=t2>>2;
  		t=t+t2;						// hier ist t die Teperatur in 0,01�C


		if(sensortyp==2){			// DS18S20
			t-=25;
		}


  		if (sign) t=-t;				// Vorzeichen

  	}
  	else t=0xFFFF;					// im Fehlerfall 0xFFFF zur�ckmelden
  	return (t);
}



void owdelay(int deltime)			// Warten, deltime = Anzahl Takte / 2 (Timer wird mit CCLK/2 betrieben) 
{									// Der Aufruf allein dauert schon ca. 12�s !!!
									// NICHT IN APP VERWENDEN !!!
  TR0=0;							// Timer 0 anhalten
  deltime=0xFFFF-deltime;
  TH0=deltime>>8;					// Timer 0 setzen
  TL0=deltime;	
  TF0=0;
  TR0=1;
  while(!TF0);						// warten auf Timer 0
  TR0=0;		
}

