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
 * 
 * 09.11.08	- delay_timer geht nicht mehr �ber flash sondern �ber globale variable delrec
 * 			- delay_timer auf 24bit reduziert statt 32bit
 * 			- port_schalten nur noch eimal pro telegramm f�r alle pins
 * 			- interrupt-steuerung bei respond() rausgenommen
 * 			- globale variablen pah, pal, rmstate entfernt
 * 			- write_obj_value aufrufe rausgenommen
 * 
 * 
 */

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_app_out.h"

unsigned char portbuffer;	// Zwischenspeicherung der Portzust�nde
unsigned char zfstate;		// Zustand der Objekte 8-11 = Zusatzfunktionen 1-4
unsigned char blocked;		// Sperrung der 8 Ausg�nge (1=gesperrt)
unsigned char logicstate;	// Zustand der Verkn�pfungen pro Ausgang
long timer;			// Timer f�r Schaltverz�gerungen, wird alle 130us hochgez�hlt



void write_value_req(void)				// Ausg�nge schalten gem�� EIS 1 Protokoll (an/aus)
{
  unsigned char objno,objflags,gapos,atp,assno,n,gaposh,zfout,zftyp;
  unsigned char blockstart,blockend;
 
    gaposh=0;

    gapos=gapos_in_gat(telegramm[3],telegramm[4]);	// Position der Gruppenadresse in der Adresstabelle
    if (gapos!=0xFF)					// =0xFF falls nicht vorhanden
    {
      send_ack();
      atp=eeprom[ASSOCTABPTR];			// Start Association Table
      assno=eeprom[atp];			// Erster Eintrag = Anzahl Eintr�ge
 
      for(n=0;n<assno;n++)				// Schleife �ber alle Eintr�ge in der Ass-Table, denn es k�nnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
      {
        gaposh=eeprom[atp+1+(n*2)];
        if(gapos==gaposh)					// Wenn Positionsnummer �bereinstimmt
        {
          objno=eeprom[atp+2+(n*2)];				// Objektnummer
          objflags=read_objflags(objno);			// Objekt Flags lesen
          
          if (objno<8) object_schalten(objno,telegramm[7]&0x01);	// Objektnummer 0-7 entspricht den Ausg�ngen 1-8

          if (objno>7 && objno<12)	// Objektnummer 8-11 entspricht den Zusatzfunktionen 1-4
          {
            if (telegramm[7]==0x80) zfstate=zfstate & (0x0F-(0x01<<(objno-8)));
            if (telegramm[7]==0x81) zfstate=zfstate | (0x01<<(objno-8));
            zfout=0;
            blockstart=0;
            blockend=0;
            switch (objno-8)			// Zugeordneten Ausgang zu Zusatzfunktionsnr. in zfout speichern (1-8)
            {
              case 0x00:		
                zfout=eeprom[FUNCASS]&0x0F;		
                blockstart=eeprom[BLOCKACT]&0x03;	// Verhalten bei Beginn der Sperrung
                blockend=(eeprom[BLOCKACT]>>2)&0x03;	// Verhalten bei Ende der Sperrung
              break;
              case 0x01:
                zfout=(eeprom[FUNCASS]&0xF0)>>4;
                blockstart=(eeprom[BLOCKACT]>>4)&0x03;	// Verhalten bei Beginn der Sperrung
                blockend=(eeprom[BLOCKACT]>>6)&0x03;	// Verhalten bei Ende der Sperrung
              break;
              case 0x02:
                zfout=eeprom[FUNCASS+1]&0x0F;
                blockstart=eeprom[BLOCKACT+1]&0x03;	// Verhalten bei Beginn der Sperrung
                blockend=(eeprom[BLOCKACT+1]>>2)&0x03;	// Verhalten bei Ende der Sperrung
              break;
              case 0x03:
                zfout=(eeprom[FUNCASS+1]&0xF0)>>4;
                blockstart=(eeprom[BLOCKACT+1]>>4)&0x03;	// Verhalten bei Beginn der Sperrung
                blockend=(eeprom[BLOCKACT+1]>>6)&0x03;	// Verhalten bei Ende der Sperrung
            }
            zftyp=((eeprom[FUNCTYP])>>((objno-8)*2)) & 0x03;	// Typ der Zusatzfunktion
            switch (zftyp)
            {
              case 0x00:			// Verkn�pfung
                switch (telegramm[7])
                {
                  case 0x80:
                    logicstate=logicstate&(0xFF-(0x01<<(zfout-1)));
                  break;
                  case 0x81:
                    logicstate=logicstate|(0x01<<(zfout-1));
                }
                object_schalten(zfout-1, telegramm[7]&0x01);
              break;
              case 0x01:			// Sperren
                switch (telegramm[7])
                {
                  case 0x80:					// Ende der Sperrung
                    blocked=blocked&(0xFF-(0x01<<(zfout-1)));
                    if (blockend==0x01) portbuffer=portbuffer&(0xFF-(0x01<<(zfout-1)));	// Bei Ende der Sperrung ausschalten
                    if (blockend==0x02) portbuffer=portbuffer|(0x01<<(zfout-1));		// Bei Ende der Sperrung einschalten
                  break;
                  case 0x81:					// Beginn der Sperrung
                    blocked=blocked|(0x01<<(zfout-1));
                    if (blockstart==0x01) portbuffer=portbuffer&(0xFF-(0x01<<(zfout-1)));	// Bei Beginn der Sperrung ausschalten
                    if (blockstart==0x02) portbuffer=portbuffer|(0x01<<(zfout-1));		// Bei Beginn der Sperrung einschalten
                    //start_writecycle();							
                    //write_byte(0x00,(zfout-1)*5,0x00);					// ggf. Eintrag f�r Schaltverz�gerung l�schen
                    //stop_writecycle();
                    delrec[(zfout-1)*4]=0;
                }
              //port_schalten(portbuffer);
              break;
              //case 0x02:			// Zwangsstellung
            }
          }
        }
      }
      port_schalten(portbuffer);	//test
      
    }
}




void object_schalten(unsigned char objno, bit objstate)	// Schaltet einen Ausgang gem�� objstate und den zug�rigen Parametern
{
	
  unsigned char port_pattern,objflags,delay_base,delay_state,delay_zeit,logicfunc,zfno;
  long delay_target,delay_onoff;

  objflags=read_objflags(objno);			// Objekt Flags lesen
  port_pattern=0x01<<objno;
  
  zfno=0;
  logicfunc=0;
  if((eeprom[FUNCASS]&0x0F)==(objno+1)) zfno=1;
  if(((eeprom[FUNCASS]&0xF0)>>4)==(objno+1)) zfno=2;
  if((eeprom[FUNCASS+1]&0x0F)==(objno+1)) zfno=3;
  if(((eeprom[FUNCASS+1]&0xF0)>>4)==(objno+1)) zfno=4;
  if(zfno)
  {
    if(((eeprom[FUNCTYP]>>((zfno-1)*2))&0x03)==0x00) logicfunc=((eeprom[LOGICTYP]>>((zfno-1)*2))&0x03);
  }
  
  if((port_pattern & blocked)==0 && (objflags&0x14)==0x14)	// Objekt ist nicht gesperrt und Kommunikation zul�ssig (Bit 2 = communication enable) und Schreiben zul�ssig (Bit 4 = write enable)
  {

      delay_base=eeprom[(((objno+1)>>1)+DELAYTAB)];   
      if((objno&0x01)==0x01) delay_base&=0x0F;
      else delay_base=(delay_base&0xF0)>>4;
      delay_target=0;
      delay_onoff=0;
      delay_state=0;
      delay_zeit=eeprom[0xEA];
      delay_zeit=((delay_zeit>>objno)&0x01);

					// Ausschalten
          if ( (objstate==0 && (logicfunc==0 || (logicfunc==1 && ((logicstate>>objno)&0x01)==0x00) || logicfunc>=2))
            || (objstate==1 && (logicfunc>=2 && ((logicstate>>objno)&0x01)==0x00)) )
          {
            delay_onoff=eeprom[objno+0xE2];
            if(delay_onoff==0x00 || delay_zeit==0x01)		// sofort ausschalten
            { 
              if (((eeprom[RELMODE]>>objno)&0x01)==0x00) portbuffer=portbuffer&~port_pattern;	// Schliesserbetrieb
              else portbuffer=portbuffer|port_pattern;						// �ffnerbetrieb
              respond(objno+12,0x80);
            }
            else delay_state=0x80;				// verz�gert ausschalten
          }

                    
          			// Einschalten
          if ( (objstate==1 && (logicfunc==0 || logicfunc==1 || (logicfunc>=2 && ((logicstate>>objno)&0x01)==0x01))) 
            || (objstate==0 && (logicfunc==1 && ((logicstate>>objno)&0x01)==0x01)) )
          {
            delay_onoff=eeprom[objno+0xDA];
            if(delay_onoff==0x00)
            {
              if(delay_zeit==0x01) 			// Zeitschaltfunktion 
              {
                delay_state=0x80;
                delay_onoff=eeprom[objno+0xE2];
              } 
              if (((eeprom[RELMODE]>>objno)&0x01)==0x00) portbuffer=portbuffer|port_pattern;	// sofort einschalten (Schliesserbetrieb)
              else portbuffer=portbuffer&~port_pattern;					// sofort einschalten (�ffnerbetrieb)
              respond(objno+12,0x81);
            }
            else delay_state=0x81;				// verz�gert einschalten
          }

      if(delay_state!=0)					// wenn Verz�gerung, dann timer-Wert ins Flash schreiben
      {  
        delay_target=(delay_onoff<<delay_base)+timer;				
        write_delay_record(objno,delay_state,delay_target);
      }
      else clear_delay_record(objno);    
  }
}



void delay_timer(void)	// z�hlt alle 130ms die Variable Timer hoch und pr�ft Queue
{
  unsigned char objno,delay_state,port_pattern,delay_zeit,delay_onoff,delay_base;
  long delval,delay_target;
  bit portchanged;
  
  portchanged=0;
  RTCCON=0x60;		// RTC anhalten und Flag l�schen
  RTCH=0x1D;		// Real Time Clock
  RTCL=0x40;

  timer++;
  if (timer==0x01000000) timer=0;	// nur 3 Byte aktiv
  for(objno=0;objno<=7;objno++)
  {
    delay_state=delrec[objno*4];
    if(delay_state!=0x00)			// 0x00 = delay Eintrag ist leer
    {   
// userram statt delrec
      delval=delrec[objno*4+1];
      delval=(delval<<8)+delrec[objno*4+2];
      delval=(delval<<8)+delrec[objno*4+3];
      if(delval==timer)
      {       
    	portchanged=1;
        port_pattern=0x01<<objno;
        if(delay_state==0x81)	// einschalten
        {
          if (((eeprom[RELMODE]>>objno)&0x01)==0x00)
          {				
            portbuffer=portbuffer|port_pattern;		// Einschalten (Schliesserbetrieb)
          }
          else
          {
            portbuffer=portbuffer&~port_pattern;	// Einschalten (�ffnerbetrieb)
          }
          EX1=0;
          respond(objno+12,0x81);			// R�ckmeldung
          EX1=1;
          //start_writecycle();
          //write_byte(0x00,objno*5,0x00);			
          //stop_writecycle();
          delrec[objno*4]=0;
          delay_zeit=eeprom[0xEA];
          delay_zeit=((delay_zeit>>objno)&0x01);
          if(delay_zeit==0x01)
          {
            delay_base=eeprom[(((objno+1)>>1)+0xF9)];   
            if((objno&0x01)==0x01) delay_base&=0x0F;
            else delay_base=(delay_base&0xF0)>>4;
            delay_onoff=eeprom[objno+0xE2];
            if (delay_onoff!=0x00 && delay_zeit!=0x00)
            {  
              delay_target=(delay_onoff<<delay_base)+timer;
              write_delay_record(objno,0x80,delay_target);		// Schaltverz�gerung in Flash schreiben
            }
          }
        }
        else	// ausschalten
        {
          if (((eeprom[RELMODE]>>objno)&0x01)==0x00)
          {
            portbuffer=portbuffer&~port_pattern;		// Ausschalten (Schliesserbetrieb)
          }
          else
          {
            portbuffer=portbuffer|port_pattern;			// Ausschalten (�ffnerbetrieb)
          }
          EX1=0;
          respond(objno+12,0x80);				// R�ckmeldung
          EX1=1;
          //start_writecycle();
          //write_byte(0x00,objno*5,0x00);
          //stop_writecycle();
          delrec[objno*4]=0;
        }

        //write_obj_value(objno,delay_state&0x3F);		// Objektwert f�r Schaltobjekt schreiben
        //write_obj_value(objno+12,delay_state&0x3F);		// Objektwert f�r R�ckmeldeobjekt
        
      }
    }   
  }
  if (portchanged) port_schalten(portbuffer);				// Ausg�nge schalten
  RTCCON=0x61;		// RTC starten
}


void port_schalten(unsigned char ports)		// Schaltet die Ports mit PWM, DUTY ist Pulsverh�ltnis
{
  TH0=0;					// Port-Ausgabe
  P1_2=1;
  P0=ports;
  TR1=0;					
  TF1=0;
  TH1=0xA0;				// Relais zun�chst mit vollem Strom einschalten...
  TL1=0x00;				
  TR1=1;
  while (!TF1);
  TR1=0;
  TH0=DUTY;				// ...danach mit PWM halten (min5% von I nominal)
  start_writecycle();	
  write_byte(0x00,0x29,portbuffer);
  stop_writecycle();
}



void respond(unsigned char objno, unsigned char rval)	// sucht Gruppenadresse f�r das Objekt objno uns sendet ein EIS 1 Telegramm
{							// mit dem Wert rval (0x80 oder 0x81) f�r R�ckmeldeobjekte
	
  int ga;
  unsigned char inv;
  
  ga=find_ga(objno);					// wenn keine Gruppenadresse hintrlegt nix tun
  if (ga!=0)
  {
	//EX1=0;
    telegramm[0]=0xBC;
    telegramm[1]=eeprom[ADDRTAB+1];
    telegramm[2]=eeprom[ADDRTAB+2];
    telegramm[3]=ga>>8;
    telegramm[4]=ga;
    telegramm[5]=0xD1;
    telegramm[6]=0x00;
    objno=objno-12;
    inv=eeprom[0xF3];
    inv=(inv>>objno)&0x01;
    if (inv==0) telegramm[7]=rval;
    if (inv==1)
    {
      if (rval==0x80) telegramm[7]=0x81;
      else telegramm[7]=0x80;
    }  
    send_telegramm();
    //EX1=1;
  }
 
}  


