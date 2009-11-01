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
#include "../com/fb_delay.h"
#include "../com/fb_prot.h"
#include "fb_app_in8.h"
#include "../com/fb_rs232.h"


unsigned char portbuffer,p0h;
unsigned int objstate;		// Zwischenspeicher der Objektzustände x.1 (Bit 0-7) und x.2 (Bit 8-15)
long timer;			// Timer für Schaltverzögerungen, wird alle 130ms hochgezählt
		


void pin_changed(unsigned char pinno)
{
	long duration=1;		// falls seitens ETS falsch programmiert 8ms default
unsigned char para_adr=0;
unsigned char para_value=0;
	EX1=0;		// externen Interrupt 1 sperren

  if (debounce(pinno))			// Entprellzeit abwarten und prüfen
  {
	  switch ((eeprom[0xCE+(pinno>>1)] >> ((pinno & 0x01)*4)) & 0x0F)	// Funktion des Eingangs
    {
     case 0x01:				// Funktion Schalten
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
      break;  
      case 0x02:				// Funktion Dimmen
    		/***********************
    		 * Funktion Dimmen
    		 ***********************/
         // rs_send_dec (2);

  		// Taster gedrueckt -> schauen wie lange gehalten
            if ((((portbuffer>>pinno)&0x01)==0) && (((p0h>>pinno)&0x01)==1)){// Taster gedrueckt -> schauen wie lange gehalten
  			duration=(eeprom[0xD7+(pinno*4)]&0x7F);	// Faktor Dauer			
			switch(pinno){
			case 0:
				para_adr=0xF6;
			break;
			case 1:
			case 2:
				para_adr=0xF7;
			break;
			case 3:
			case 4:
				para_adr=0xF8;
			break;	
			case 5:
			case 6:
				para_adr=0xF9;
			break;
			case 7:
				para_adr=0xFA;
			}// im Nachfolgenden wird die Zeitbasis geholt und schiebt duration nach links
			duration=duration << ((eeprom[para_adr]>>(4*(1-(pinno&0x01))))&0x03);// Basis Dauer zwischen kurz und langzeit)	
  			duration+=timer;
  			switch (eeprom[0xD5+(pinno*4)]&0x30) {
  			case 0x10:	// zweiflaechen heller
  				write_delay_record(pinno, ((eeprom[0xD6+(pinno*4)]&0x38)>>3)+0x44, duration);	// dimmen
  				break;
  			case 0x20:	// zweiflaechen dunkler
  				write_delay_record(pinno, ((eeprom[0xD6+(pinno*4)]&0x03))+0x40, duration);	// dimmen
  			}
  		}
  		else {		// Taster losgelassen
  			if (delrec[pinno*4]) {		// wenn delaytimer noch lauft, dann Schalten, also EIS1 telegramm senden
  				switch (eeprom[0xD5+(pinno*4)]&0x30) {
  				case 0x10:	// zweiflaechen ein
  					send_eis(1, pinno, 1);
  					break;
  				case 0x20:	// zweiflaechen aus
  					send_eis(1, pinno, 0);
  				}
  				clear_delay_record(pinno);
  			}
  			else {	// Timer schon abgelaufen (also dimmen), dann beim loslassen stop-telegramm senden
  				if (eeprom[0xD5+(pinno*4)] & 0x08) {	// ... natuerlich nur wenn parameter dementsprechend (0=senden!!!)
  					send_eis(2, pinno+8, 0);		// Stop Telegramm
  				}
  				else write_obj_value(pinno+8,0);	// auch wenn Stopp Telegramm nicht gesendet wird, Objektwert auf 0 setzen
  			}
  			
  		}
        break;
       
        case 0x03:				//Funktion Jalousie
        	/****************************
        	 * Funktion Jalousie
        	 ****************************/
            if ((((portbuffer>>pinno)&0x01)==0) && (((p0h>>pinno)&0x01)==1)){// Taster gedrueckt -> schauen wie lange gehalten

    			send_eis(1, pinno, (1-(eeprom[0xD8+(pinno*4)]&0x10)>>4));	// Kurzzeit telegramm immer bei Drücken senden
    			duration=eeprom[0xD6+(pinno*4)];	// Faktor Dauer			
    			switch(pinno){
    			case 0:
    				para_adr=0xF6;
    			break;
    			case 1:
    			case 2:
    				para_adr=0xF7;
    			break;
    			case 3:
    			case 4:
    				para_adr=0xF8;
    			break;	
    			case 5:
    			case 6:
    				para_adr=0xF9;
    			break;
    			case 7:
    				para_adr=0xFA;
    			}// im Nachfolgenden wird die Zeitbasis geholt und schiebt duration nach links
    			duration=duration << (eeprom[para_adr]>>(4*(1-(pinno&0x01))));// Basis Dauer zwischen kurz und langzeit)	
     			duration+=timer;
    			write_delay_record(pinno, ((eeprom[0xD8+(pinno*4)]&0x30)>>4)+0x80, duration);
    		}
    		else {	// Taster losgelassen
    			if (delrec[pinno*4] & 0x10) send_eis(1, pinno, (1-(eeprom[0xD8+(pinno*4)]&0x10)>>4));	// wenn delaytimer noch laueft und in T2 ist, dann kurzzeit telegramm senden
    			else clear_delay_record(pinno);	// T2 bereits abgelaufen
    		}
        break;
 
        
        
        case 0x04:				// Wertgeber
 //           rs_send_dec (4);
        break;
        case 0x09:				// Impulszähler
 //           rs_send_dec (9);
      	break;
        case 0x0A:				// Schaltzähler	
 //           rs_send_dec (10);
        break;    
    }
  }
  IE1=0;	// IRQ 1 Flag zurücksetzen
  EX1=1;	// externen Interrupt 1 wieder freigeben
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
/** 
* zaehlt alle 130ms die Variable Timer hoch und prueft records
*
* \param void
* @return void
*/
void delay_timer(void)
{
unsigned char para_adr=0;
unsigned char para_value=0;

	unsigned char objno, delay_state;
	long delval;
	long duration=1;

	stop_rtc();
	timer++;
	if (timer==0x01000000) timer=0;	// nur 3 Byte aktiv
	for(objno=0;objno<8;objno++) {
		delay_state=delrec[objno*4];
		if(delay_state!=0x00) {			// 0x00 = delay Eintrag ist leer   
			delval=delrec[objno*4+1];
			delval=(delval<<8)+delrec[objno*4+2];
			delval=(delval<<8)+delrec[objno*4+3];	// delval enthaelt den im delay record gespeicherten timer-wert
			if(delval==timer) {	// ... es ist also soweit

				if (delay_state & 0x80) { // 0x80, 0x81 für langzeit telegramm senden
						send_eis(1, objno+8, delay_state & 0x01);	// Langzeit Telegramm senden
						// *** delay record neu laden für Dauer Lamellenverstellung ***
//						duration=eeprom[((objno)*4)];	//[DEL_FACTOR2+ Faktor Dauer	T2		

		    			duration=eeprom[0xD7+(objno*4)];	// Faktor Dauer	Lamelle	T2	
		    			switch(objno){
		    			case 0:
		    				para_adr=0xFA;
		    			break;
		    			case 1:
		    			case 2:
		    				para_adr=0xFB;
		    			break;
		    			case 3:
		    			case 4:
		    				para_adr=0xFC;
		    			break;	
		    			case 5:
		    			case 6:
		    				para_adr=0xFD;
		    			break;
		    			case 7:
		    				para_adr=0xFE;
		    			}
		    			if (duration){// wenn lamellenverstellzeit dann zeit sichern und kurztele zwecks stop
		    				duration=duration << (eeprom[para_adr]>>(4*(1-(objno&0x01))));
		    				duration += timer;
						write_delay_record(objno, ((eeprom[0xD8+((objno)*4)]&0x30)>>3)+0x10, duration); // 0x10,0x11 fuer ende T2 (lamellenvestellzeit)
						}
						else clear_delay_record(objno);
					}
					
					if (delay_state & 0x10) clear_delay_record(objno); // wenn T2 abgelaufen dann nichts mehr machen
					
					if (delay_state & 0x40) { // 0x4? fuer Dimmer Funktion
						send_eis(2, objno+8, delay_state);	// Langzeit Telegramm senden
						clear_delay_record(objno);
					}
				//}
			}
		}
	}
	start_rtc(130);		// RTC neu starten mit 8ms
}



void schalten(unsigned char risefall, unsigned char pinno)	// Schaltbefehl senden
{
  unsigned char func;
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
      if (func==0x01) send_eis(1,pinno,0x01);	// EIN
      if (func==0x02) send_eis(1,pinno,0x00);	// AUS
      if (func==0x03)						// UM
      {
    	if (objstate&(0x0001<<pinno)) {						// AUS
    		send_eis(1,pinno,0x00);
    		objstate=objstate&(0xFFFF-(0x0001<<pinno));
    	}
        else {
        	send_eis(1,pinno,0x01);//telegramm[7]=0x81;								// EIN
        	objstate=objstate|(0x0001<<pinno);
        }
      }
  }
}




unsigned char pin_function(unsigned char pinno)		// Funktion des Eingangs ermitteln
{
pinno;
return(1);
}

unsigned char debounce(unsigned char pinno)	// Entprellzeit abwarten und prüfen !!
{
  unsigned char debtime,n,ret;
  
  debtime=eeprom[DEBTIME];			// Entprellzeit in 0,5ms Schritten
  if (debtime>0) for(n=0;n<debtime;n++) delay(110);  
  if (((P0>>pinno)&0x01) == ((p0h>>pinno)&0x01)) ret=1;
  else ret=0; 
  return(ret);
}



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
		if((objflags&0x0C)==0x0C) send_eis(0,objno,objvalue);
    }
}

void send_eis(unsigned char eistyp, unsigned char objno, int sval)
{
  int ga;
  
  ga=find_ga(objno);					// wenn keine Gruppenadresse hinterlegt nix tun
  if (ga!=0)
  {
    telegramm[0]=0xBC;
	telegramm[1]=eeprom[ADDRTAB+1];		// phys. Adresse
	telegramm[2]=eeprom[ADDRTAB+2];
    telegramm[3]=ga>>8;
    telegramm[4]=ga;
    switch (eistyp) {
    case 1:
    	telegramm[5]=0xD1;
    	telegramm[6]=0x00;
    	sval=(sval & 0x01);	// nur 1 Bit
    	telegramm[7]=sval + 0x80;
    	break;
    case 2:
    	telegramm[5]=0xD1;
    	telegramm[6]=0x00;
    	sval=(sval & 0x0F);	// nur 4 Bit
    	telegramm[7]=sval + 0x80;
    	break;    	
    case 5:
    	telegramm[5]=0xE3;
    	telegramm[6]=0x00;
    	telegramm[7]=0x80;
    	telegramm[8]=sval>>8;
    	telegramm[9]=sval;
    	break;
    case 6:
    	telegramm[5]=0xE2;
    	telegramm[6]=0x00;
    	telegramm[7]=0x80;
    	telegramm[8]=sval;
    	break;
    }
    
    EX1=0;
    send_telegramm();
    EX1=1;
	write_obj_value(objno, sval);	// Objektwert im USERRAM speichern
//	write_value_req();				// eigenes Telegramm nochmal verarbeiten
  }
  else write_obj_value(objno, sval);	// Objektwert trotzdem im USERRAM speichern
}  
/*
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
*/



void delay(int w)	// delay ca. 4,5µs * w
{
	int n;
	for(n=w;n>0;n--) {}
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{

  P0M1=0xFF;	//P0 auf input only (high impedance!)
  P0M2=0x00;
  P0=0xFF;

  transparency=0;
	stop_rtc();
	start_rtc(130);		// RTC neu mit 8ms starten
	timer=0;			// Timer-Variable, wird alle 8ms inkrementiert

  
  START_WRITECYCLE
  WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
  WRITE_BYTE(0x01,0x04,0x04);
  WRITE_BYTE(0x01,0x05,0x70);	// Geräte Typ (2118) 7054h
  WRITE_BYTE(0x01,0x06,0x54);  // 	"	"	"
  WRITE_BYTE(0x01,0x07,0x02);	// Versionsnummer
  WRITE_BYTE(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
  WRITE_BYTE(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
  WRITE_BYTE(0x01,0x12,0x84);	// COMMSTAB Pointer
  STOP_WRITECYCLE
}
