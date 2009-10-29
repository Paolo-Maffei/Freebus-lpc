/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2009 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */


#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "app_finger.h"
//#include "../com/fb_rs232.h"


unsigned char portbuffer,p0h;
unsigned long wiegand;
unsigned int objstate;		// Zwischenspeicher der Objektzustände x.1 (Bit 0-7) und x.2 (Bit 8-15)
long timer;					// Timer für Schaltverzögerungen, wird alle 130ms hochgezählt
		

void key(void) interrupt 7
{

	unsigned char porth;
	
	EKBI=0;
	porth=P0&0x03;
	if (porth==1) wiegand=wiegand<<1;
	if (porth==2) wiegand=(wiegand<<1)+1;

	while((P0&0x03)!=0);
	//set_timer0(1000);
	//while (!TF0);
	//TF0=0;

	set_timer0(10000);
	KBCON=0;
	EKBI=1;
}



/*
void pin_changed(unsigned char pinno)
{
  EX1=0;		// externen Interrupt 1 sperren

  if (debounce(pinno))			// Entprellzeit abwarten und prüfen
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
          case 0x00:					// Einflächenbedienung heller/dunkler (UM)
            if (switch_dim(pinno)==0)			// prüfen, ob Taster länger gedrückt als Schalten/Dimmen-Zeit
            {						// umschalten
            }
            else					// dimmen
            {
            }
          case 0x01:					// Zweiflächenbedienung heller (EIN)
          case 0x02:					// Zweiflächenbedienung dunkler (AUS)
          case 0x03:					// Zweiflächenbedienung heller (UM)
          case 0x04:					// Zweiflächenbedienung dunkler (UM)
        }
    }
  }
  IE1=0;	// IRQ 1 Flag zurücksetzen
  EX1=1;	// externen Interrupt 1 wieder freigeben
}
*/             


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
  
  if (pinno<=7) {
	  if (risefall==1) func=(func>>2)&0x03;		// Funktion bei steigender Flanke
	  else func=func&0x03;						// Funktion bei fallender Flanke
  }
  else {
	  if (risefall==1) func=(func>>6)&0x03;		// Funktion bei steigender Flanke
	  else func=(func>>4)&0x03;					// Funktion bei fallender Flanke
  }

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
    	if (objstate&(0x0001<<pinno)) {						// AUS
    		telegramm[7]=0x80;
    		objstate=objstate&(0xFFFF-(0x0001<<pinno));
    	}
        else {
        	telegramm[7]=0x81;								// EIN
        	objstate=objstate|(0x0001<<pinno);
        }
      }
      EX1=0;
      send_telegramm();
      write_obj_value(pinno,telegramm[7]&0x01);		// Objektwert ins USERRAM schreiben
      EX1=1;
    }
  }
}




unsigned char pin_function(unsigned char pinno)		// Funktion des Eingangs ermitteln
{
  pinno;
  return (0);
}

/*
unsigned char debounce(unsigned char pinno)	// Entprellzeit abwarten und prüfen !!
{
  unsigned char debtime,n,ret;
  
  debtime=eeprom[DEBTIME];			// Entprellzeit in 0,5ms Schritten
  if (debtime>0) for(n=0;n<debtime;n++) delay(110);  
  if (((P0>>pinno)&0x01) == ((p0h>>pinno)&0x01)) ret=1;
  else ret=0; 
  return(ret);
}
*/


void write_value_req(void)		// Objekt-Wert setzen gemäß empfangenem EIS 1 Telegramms (an/aus)
{
	unsigned char objno,objflags,gapos,atp,assno,n,gaposh;

    gapos=gapos_in_gat(telegramm[3],telegramm[4]);
    if (gapos!=0xFF)	
    {
    	send_ack();
    	atp=eeprom[ASSOCTABPTR];		// Association Table Pointer
    	assno=eeprom[atp];				// Erster Eintrag = Anzahl Einträge
 
    	for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
    		gaposh=eeprom[atp+1+(n*2)];
    		if(gapos==gaposh) {					// Wenn Positionsnummer übereinstimmt
    			objno=eeprom[atp+2+(n*2)];			// Objektnummer
    			objflags=read_objflags(objno);		// Objekt Flags lesen
    			if((objflags&0x14)==0x14) {			// Kommunikation zulässig (Bit 2 = communication enable) + Schreiben zulässig (Bit 4 = write enable)
    				if (objno<16) {					// Status der Eingangsobjekte 0-15
    					if (telegramm[7]==0x80) objstate&=(0xFFFF-(0x0001<<objno));
    					if (telegramm[7]==0x81) objstate|=(0x0001<<objno);
    				}
    			}
    		}
    	}
    }
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
	unsigned char objno, objflags;
	int objvalue;
	
	objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
	if(objno!=0xFF) {	// falls Gruppenadresse nicht gefunden
		send_ack(); 
		
		objvalue=read_obj_value(objno);		// Objektwert aus USER-RAM lesen (Standard Einstellung)


		
		objflags=read_objflags(objno);		// Objekt Flags lesen
		// Objekt lesen, nur wenn read enable gesetzt (Bit3) und Kommunikation zulaessig (Bit2)
		if((objflags&0x0C)==0x0C) send_value(0,objno,objvalue);
    }
}


void send_value(unsigned char type, unsigned char objno, int sval)	// sucht Gruppenadresse für das Objekt objno uns sendet ein EIS Telegramm
{																	// mit dem Wert sval
  int ga;
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
    
    if(objtype<6) {					// Objekttyp, 1-6 Bit
    	telegramm[5]=0xE1;
    	telegramm[7]+=sval;
    }
    
    if(objtype>=6 && objtype<=7) {	// Objekttyp, 7-8 Bit
    	telegramm[5]=0xE2;
    	telegramm[8]=sval;
    }
    
     if(objtype==8) {				// Objekttyp, 16 Bit
    	telegramm[5]=0xE3;  	
    	telegramm[8]=sval>>8;
    	telegramm[9]=sval;
    }   
    
    EX1=0;
    send_telegramm();
    IE1=0;
    EX1=1;
  }

}  




void delay(int w)	// delay ca. 4,5µs * w
{
	int n;
	for(n=w;n>0;n--) {}
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{

	SET_PORT_MODE_INPUT(0);
	SET_PORT_MODE_INPUT(1);
	SET_PORT_MODE_BIDIRECTIONAL(2);
	SET_PORT_MODE_BIDIRECTIONAL(3);
	SET_PORT_MODE_BIDIRECTIONAL(4);
	SET_PORT_MODE_BIDIRECTIONAL(5);
	SET_PORT_MODE_BIDIRECTIONAL(6);
	SET_PORT_MODE_BIDIRECTIONAL(7);
  ;P0M1=0xFF;	//P0 auf input only (high impedance!)
  ;P0M2=0x00;
  P0=0x03;
  
	KBMASK=0x03;		// P0.0 & P0.1 enabled for KB-Interrupt
	KBPATN=0x00;		// Pattern
	KBCON=0;			// Interrupt when port not equal to pattern
	EKBI=1;				// keyboard interrupt enabled

  transparency=0;
  
  timer=0;		// Timer-Variable, wird alle 65ms inkrementiert
  
  START_WRITECYCLE;
  WRITE_BYTE(0x01,0x03,0x00);	// Herstellercode 0x0004 = Jung
  WRITE_BYTE(0x01,0x04,0x04);
  WRITE_BYTE(0x01,0x05,0x70);	// Geräte Typ (2118) 7054h
  WRITE_BYTE(0x01,0x06,0x54);	// 	"	"	"
  WRITE_BYTE(0x01,0x07,0x02);	// Versionsnummer
  WRITE_BYTE(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
  WRITE_BYTE(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
  WRITE_BYTE(0x01,0x12,0x84);	// COMMSTAB Pointer
  STOP_WRITECYCLE;
  START_WRITECYCLE;
  WRITE_BYTE(0x00,0x60,0x2E);	// system state: all layers active, not in prog mode
  STOP_WRITECYCLE;
}
