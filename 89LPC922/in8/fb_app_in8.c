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
#include "fb_app_in8.h"
//#include "../com/fb_rs232.h"


unsigned char portbuffer,p0h;

int objstate;		// Zwischenspeicer der Objektzust‰nde x.1 (Bit 0-7) und x.2 (Bit 8-15)
long timer;			// Timer f¸r Schaltverzˆgerungen, wird alle 130us hochgez‰hlt
		


void pin_changed(unsigned char pinno)
{
  EX1=0;

  if (debounce(pinno))			// Entprellzeit abwarten und pr¸fen
  {
    switch (pin_function(pinno))	// Funktion des Eingangs
    {
      case 0x00:				// Funktion Schalten
        if((((portbuffer>>pinno)&0x01)==0) && (((p0h>>pinno)&0x01)==1))	
        {
          schalten(1,pinno);			// steigende Flanke Eingang x.1
          schalten(1,pinno+8);			// steigende Flanke Eingang x.2
        }
        else
        {
          schalten(0,pinno);			// fallende Flanke Eingang x.1
          schalten(0,pinno+8);			// fallende Flanke Eingang x.2
        }
        send_cyclic(pinno);
      case 0x01:				// Funktion Dimmen
        switch (operation(pinno))			// Bedienung
        {
          case 0x00:					// Einfl‰chenbedienung heller/dunkler (UM)
            if (switch_dim(pinno)==0)			// pr¸fen, ob Taster l‰nger gedr¸ckt als Schalten/Dimmen-Zeit
            {						// umschalten
            }
            else					// dimmen
            {
            }
          case 0x01:					// Zweifl‰chenbedienung heller (EIN)
          case 0x02:					// Zweifl‰chenbedienung dunkler (AUS)
          case 0x03:					// Zweifl‰chenbedienung heller (UM)
          case 0x04:					// Zweifl‰chenbedienung dunkler (UM)
        }
    }
  }
  IE1=0;
  EX1=1;
}
             


void send_cyclic(unsigned char pinno)
{
pinno;
}


unsigned char operation(unsigned char pinno)
{
pinno;
  return(1);
}


unsigned char switch_dim(unsigned char pinno)
{
pinno;
  return(1);
}


void schalten(unsigned char risefall, unsigned char pinno)	// Schaltbefehl senden
{
  unsigned char func;
  int ga;

  func=eeprom[0xD7+((pinno&0x07)*4)];
  if (risefall==1) func=(func>>2)&0x03;		// Funktion bei steigender Flanke
  else func=func&0x03;						// Funktion bei fallender Flanke

  if (func!=0)
  {
    ga=find_ga(pinno);
    if (ga!=0)
    {
      telegramm[0]=0xBC;
      telegramm[1]=eeprom[ADDRTAB+1];		// phys. Adresse
      telegramm[2]=eeprom[ADDRTAB+2];
      telegramm[3]=ga>>8;
      telegramm[4]=ga;
      telegramm[5]=0xD1;
      telegramm[6]=0x00;
      if (func==0x01) telegramm[7]=0x81;	// EIN
      if (func==0x02) telegramm[7]=0x80;	// AUS
      if (func==0x03)						// UM
      {
        if (read_obj_value(pinno)==1) telegramm[7]=0x80;	// AUS
        else telegramm[7]=0x81;								// EIN
      }
      send_telegramm();
      if (telegramm[7]==0x80) {
    	  // objstate=objstate&(0xFFFF-(0x0001<<pinno));
    	  write_obj_value(pinno,0);
      }
      else {
    	  // objstate=objstate|(0x0001<<pinno);
    	  write_obj_value(pinno,1);
      }
      
    }
  }
}




unsigned char pin_function(unsigned char pinno)		// Funktion des Eingangs ermitteln
{
  pinno;
  return (0);
}


unsigned char debounce(unsigned char pinno)	// Entprellzeit abwarten und pr¸fen !!
{
  unsigned char debtime,n,ret;
  
  debtime=eeprom[DEBTIME];			// Entprellzeit in 0,5ms Schritten
  if (debtime>0)
  {
    for(n=0;n<debtime;n++)
    {
      delay(2000);
    }
  }  
  pinno;
  if (((P0>>pinno)&0x01) == ((p0h>>pinno)&0x01)) ret=1;
  else ret=0; 
  return(ret);
}



void write_value_req(void)		// Objekt-Wert setzen gem‰ﬂ empfangenem EIS 1 Telegramms (an/aus)
{
	unsigned char objno,port_pattern,objflags,gapos,atp,assno,n,gaposh;

    gapos=gapos_in_gat(telegramm[3],telegramm[4]);
    if (gapos!=0xFF)	
    {
    	send_ack();
    	atp=eeprom[ASSOCTABPTR];			// Association Table Pointer
    	assno=eeprom[atp];		// Erster Eintrag = Anzahl Eintr‰ge
 
    	for(n=0;n<assno;n++) {				// Schleife ¸ber alle Eintr‰ge in der Ass-Table, denn es kˆnnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
    		gaposh=eeprom[atp+1+(n*2)];
    		if(gapos==gaposh) {					// Wenn Positionsnummer ¸bereinstimmt
    			objno=eeprom[atp+2+(n*2)];			// Objektnummer
    			objflags=read_objflags(objno);			// Objekt Flags lesen
    			if((objflags&0x04)==0x04) {				// Kommunikation zul‰ssig (Bit 2 = communication enable) 
    				port_pattern=0x01<<objno;

    				if((objflags&0x10)==0x10) {				// Schreiben zul‰ssig (Bit 4 = write enable)
    					write_obj_value(objno,telegramm[7]&0x3F);	// Objektwert in USERRAM schreiben
    				}
    			}
    		}
    	}
    }
}
    

void restart_app(void)		// Alle Applikations-Parameter zur¸cksetzen
{

  
  
  P0M1=0xFF;
  P0M2=0x00;
  //P0=0xFF;

  
  
  timer=0;		// Timer-Variable, wird alle 135us inkrementiert
  
  start_writecycle();
  write_byte(0x01,0x03,0x00);	// Herstellercode 0x0004 = Jung
  write_byte(0x01,0x04,0x04);
  write_byte(0x01,0x05,0x70);	// Ger‰te Typ (2118) 7054h
  write_byte(0x01,0x06,0x54);  // 	"	"	"
  write_byte(0x01,0x07,0x02);	// Versionsnummer
  write_byte(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
  write_byte(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
  write_byte(0x01,0x12,0x84);	// COMMSTAB Pointer
  stop_writecycle();
}
