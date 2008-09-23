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
#include "fb_app_in8T.h"
//#include "../com/fb_rs232.h"


unsigned char portbuffer,p0h;

int objstate;		// Zwischenspeicer der Objektzustände x.1 (Bit 0-7) und x.2 (Bit 8-15)
long timer;			// Timer für Schaltverzögerungen, wird alle 130us hochgezählt
		


void pin_changed(unsigned char pinno)
{
  EX1=0;

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
  EX1=1;
}
             
void read_value_req(void)				// Objektwerte lesen angefordert
{
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
  if (risefall==1) func=(func>>2)&0x03;		// steigende Flanke
  else func=func&0x03;				// fallende Flanke

  if (func!=0)
  {
    ga=find_ga(pinno);
    if (ga!=0)
    {
      telegramm[0]=0xBC;
      telegramm[1]=pah;
      telegramm[2]=pal;
      telegramm[3]=ga>>8;
      telegramm[4]=ga;
      telegramm[5]=0xD1;
      telegramm[6]=0x00;
      if (func==0x01){
    	  telegramm[7]=0x81;	// EIN
    	  if ((pinno&0x01)==0x00)  objstate=objstate|(0x01<<(pinno+1));//bei EIN nächsthöheren Eingang setzen
    	  else objstate=objstate|(0x01<<(pinno-1));//bei EIN nächst niedrigeren Eingang setzen
      }
      if (func==0x02){
    	  telegramm[7]=0x80;	// AUS
    	  if ((pinno&0x01)==0x00)  objstate=objstate&(~(0x01<<(pinno+1)));// bei AUs nächsthöheren Eingang löschen
    	  else objstate=objstate&(~(0x01<<(pinno-1)));// bei AUS nächst niedrigeren Eingan löschen
      }
      if (func==0x03)				// UM
      {
        if (((objstate>>pinno)&0x01)==0x01) telegramm[7]=0x80;	// AUS
        else telegramm[7]=0x81;					// EIN
      }
      if (telegramm[7]==0x80) objstate=objstate&(0xFFFF-(0x0001<<pinno));
      else objstate=objstate|(0x0001<<pinno);
      send_telegramm();
      P0=(objstate<<4)|0x0f;	//LEDS ansteuern
    }
  }
}




unsigned char pin_function(unsigned char pinno)		// Funktion des Eingangs ermitteln
{
  pinno;
  return (0);
}


unsigned char debounce(unsigned char pinno)	// Entprellzeit abwarten und prüfen !! Prüfung fehlt noch !!
{
  unsigned char debtime,n;
  
  debtime=eeprom[DEBTIME];			// Entprellzeit in 0,5ms Schritten
  if (debtime>0)
  {
    for(n=0;n<debtime;n++)
    {
      delay(500);
    }
  }  
  pinno;
  return(1);
}



void eis1(void)				// Objekte schalten gemäß EIS 1 Protokoll (an/aus)
{
  unsigned char objno,port_pattern,objflags,gapos,atp,assno,n,gaposh;
  int ga;
 
    gaposh=0;
    ga=telegramm[3];
    ga=ga<<8;
    ga=ga+telegramm[4];
    gapos=0xFF;
    
    
    gapos=gapos_in_gat(telegramm[3],telegramm[4]);
    if (gapos!=0xFF)	
    {
      send_ack();
      atp=eeprom[0x11];			// Association Table Pointer
      assno=eeprom[atp];		// Erster Eintrag = Anzahl Einträge
 
      for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
      {
        gaposh=eeprom[atp+1+(n*2)];
        if(gapos==gaposh)					// Wenn Positionsnummer übereinstimmt
        {
          objno=eeprom[atp+2+(n*2)];			// Objektnummer
          objflags=read_objflags(objno);			// Objekt Flags lesen
          if((objflags&0x04)==0x04)				// Kommunikation zulässig (Bit 2 = communication enable) 
          {
            port_pattern=0x01<<objno;

              if((objflags&0x10)==0x10)				// Schreiben zulässig (Bit 4 = write enable)
              {
                        
                
                if (telegramm[7]==0x80) objstate=objstate&(0xFFFF-(0x0001<<objno));
                else objstate=objstate|(0x0001<<objno);
                

              }

            if(telegramm[7]==0x00 && (objflags&0x08)==0x08)	// Wert lesen, nur wenn read enable gesetzt (Bit3)
            {
              telegramm[0]=0xBC;
              telegramm[1]=pah;			// Source Adresse
              telegramm[2]=pal;
              telegramm[5]=0xE1;		// DRL
              telegramm[6]=0x00;
              if((port_pattern&portbuffer)>0) telegramm[7]=0x41;	// An
              else telegramm[7]=0x40;					// Aus
              send_telegramm();
            }
          }
        }
      }
      
    }
}
    


void delay_timer(void)	// zählt alle 130ms die Variable Timer hoch und prüft Queue
{
  unsigned char n,b,port_pattern,delay_zeit,delay_onoff,delay_base;
  long delval,delay_target;
  
  RTCCON=0x60;		// RTC anhalten und Flag löschen
  RTCH=0x1D;		// Real Time Clock
  RTCL=0x40;

  timer++;
  for(n=0;n<=7;n++)
  {
    b=userram[n*5];
    if(b!=0x00)							// 0x00 = queue Eintrag ist leer
    {   
      delval=userram[n*5+1];
      delval=(delval<<8)+userram[n*5+2];
      delval=(delval<<8)+userram[n*5+3];
      delval=(delval<<8)+userram[n*5+4];
      if(delval==timer)
      {       
        port_pattern=0x01<<((b&0x0F));
        if((b&0xF0)==0x90)
        {
          if (((eeprom[RELMODE]>>(b&0x0F))&0x01)==0x00)
          {				
            portbuffer=portbuffer|port_pattern;		// Einschalten (Schliesserbetrieb)
          }
          else
          {
            portbuffer=portbuffer&~port_pattern;	// Einschalten (Öffnerbetrieb)
          }
          start_writecycle();
          write_byte(0x00,n*5,0x00);
          stop_writecycle();
          delay_zeit=eeprom[0xEA];
          delay_zeit=((delay_zeit>>n)&0x01);
          if(delay_zeit==0x01)
          {
            delay_base=eeprom[((n+1)>>1)+0xF9];   
            if((n&0x01)==0x01) delay_base&=0x0F;
            else delay_base=(delay_base&0xF0)>>4;
            delay_onoff=eeprom[n+0xE2];
            if (delay_onoff!=0x00 && delay_zeit!=0x00)
            {
              delay_target=delay_onoff;
              delay_target=delay_target<<delay_base;
              delay_target+=timer;  
              start_writecycle();   
              write_byte(0x00,n*5,n+0x80);
              write_byte(0x00,1+n*5,delay_target>>24);
              write_byte(0x00,2+n*5,delay_target>>16);
              write_byte(0x00,3+n*5,delay_target>>8);
              write_byte(0x00,4+n*5,delay_target);
              stop_writecycle();
            }
          }
        }
        else
        {
          if (((eeprom[RELMODE]>>(b&0x0F))&0x01)==0x00)
          {
            portbuffer=portbuffer&~port_pattern;		// Ausschalten (Schliesserbetrieb)
          }
          else
          {
            portbuffer=portbuffer|port_pattern;			// Ausschalten (Öffnerbetrieb)
          }
          start_writecycle();
          write_byte(0x00,n*5,0x00);
          stop_writecycle();
        }
        TH0=0;					// Port-Ausgabe
        P1_2=1;
      	P0=portbuffer;	
      	start_writecycle();
      	write_byte(0x00,0x29,portbuffer);
      	stop_writecycle();
      	TR1=0;					
      	TF1=0;
      	TH1=0xA0;				// Relais zunächst mit vollem Strom einschalten...
      	TL1=0x00;				
      	TR1=1;
      	while (!TF1);
      	TR1=0;
      	TH0=DUTY;				// ...danach mit PWM halten (min5% von I nominal)    
      	

      }
    }   
  }
  RTCCON=0x61;		// RTC starten
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{

  
  
  P0M1=0x00;
  P0M2=0xF0;	// untere 4 Bit pullup, obere 4 bit push pull
  //P0=0xFF;
  P0=(objstate<<4)|0x0f;	// LEDs nach Objstate schalten.
  
  
  timer=0;		// Timer-Variable, wird alle 135us inkrementiert
  
  start_writecycle();
  write_byte(0x01,0x04,0x04);	// Herstellercode 0x04 = Jung
  write_byte(0x01,0x05,0x70);	// Geräte Typ (2118) 7054h
  write_byte(0x01,0x06,0x54);  // 	"	"	"
  write_byte(0x01,0x07,0x02);	// Versionsnummer
  write_byte(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
  write_byte(0x01,0x12,0x84);	// COMMSTAB Pointer
 
   stop_writecycle();
  
}
