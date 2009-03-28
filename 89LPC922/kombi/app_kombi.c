/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008, 2009 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/onewire.h"
#include "app_kombi.h"

//292
const int cycleval[] = {17490, 20, 875, 1458, 2915, 5830, 8745, 13117, 17490}; // Zykluszeit in 130ms
const unsigned int luxtable[] = {2,2,2,3,3,4,4,5,5,6,7,8,9,10,11,12,14,16,18,20,23,26,30,35,40,45,50,55,60,70,80,90,100,110,125,140,160,180,200,230,260,300,350,400,450,500,550,600,700,800,900,1000,1100,1250,1400,1600,1800,2000,2300,2600,3000,3500,4000,4500,5000,5500,6000,7000,8000,9000,10000,11000,12500,14000,16000,18000,20000,23000,26000,30000,35000,40000,45000,50000,55000,60000,65535,65535,65535,65535};
const unsigned char hystable[] = {1,2,10,5,3};	// divisor für Lux Hysterese (50%,10%,20%,30%)
const unsigned int luxdelay[] = {0,10,25,49,73,97,146,219,292,438,583,875,1458,2915,4380,8745};

int temp, eis5temp,lasttemp,lux,lastlux, eis5lux;
unsigned char overrun, dimmwert, underrun, sequence;

struct delayrecord {
	unsigned char delaystate;
	long delayvalue;
};
struct delayrecord delreco[9];


#define WRITE_DELAY_RECORD(wdro,wdrs,wdrt) \
	delreco[wdro].delaystate=wdrs; \
	delreco[wdro].delayvalue=wdrt; 




void schwelle(unsigned char objno)		// Luxschwelle prüfen und reagieren
{
	
	unsigned char ctrl, cycle, bitmask, temp_compare, lux_compare;
	unsigned char lastdimm, step, wertl, werth, offset;
	bit sendval=0, lock, over=0, under=0;
	bit luxlevel=0;
	unsigned char sendcyclicl, sendcyclich;

	unsigned int schwellwert=0;
	unsigned int hysterese=0, delayover=0, delayunder=0;
	long timerneu;
	

	offset=(objno-3)*5;
	if (objno==9) offset++;	// da Verssatz in der Reihenfolge der Parameter

	ctrl=eeprom[LUXCTRL-offset];
	cycle = eeprom[LUXCYCLE1-offset] & 0x07;
	timerneu = timer+cycleval[cycle];
	lock=read_obj_value(10);

	if ((eeprom[LUXPARAM]&0x80) && objno==3) {	// Helligkeitsregelung (nur Objekt1)
		
		lastdimm=dimmwert;
		schwellwert=eeprom[LUXSCHWELLWERT]*10;		// schwellwert ist hier der Sollwert
		hysterese=_divuint(schwellwert,hystable[ctrl&0x07]);
		if (hysterese==0) hysterese=1;	// mindestens jedoch 1 Lux
		step=(((ctrl & 0xF0) >> 4) + 1) * 16;
		
		if (((ctrl & 0x08)==0) || lock==0) {	// Sperre ignorieren oder Sperre=0
			if (lux>schwellwert) {	// wenn überschritten
				if ((lux > (schwellwert*2)) && (dimmwert >= step)) dimmwert-=step;
				else {
					if (dimmwert>3) dimmwert-=4;
					else dimmwert=0;
				}
			}
			if (lux<(schwellwert-hysterese)) {		// wenn unterschritten
				if (((lux*2) < (schwellwert-hysterese)) && (dimmwert <= (255 - step))) dimmwert+=step;	// grosse Schritte wenn weit weg von Sollwert
				else {
					if (dimmwert<252) dimmwert+=4;
					else dimmwert=255;
				}
			}
			if (lastdimm != dimmwert) {
				send_value(1,3,dimmwert);	//6
				WRITE_DELAY_RECORD(2,1,timerneu)
			}
		}
	}

	else {	// Schwellen

		if (objno<6) {	// Helligkeitsschwellen
			schwellwert=luxtable[eeprom[LUXSCHWELLWERT-offset]-7];
			hysterese=_divuint(schwellwert,hystable[ctrl&0x07]);
			if (hysterese==0) hysterese=1;	// mindestens jedoch 1 Lux
			if (lux>schwellwert) over=1; 
			if (lux<(schwellwert-hysterese)) under=1; 
			delayover=luxdelay[(eeprom[LUXCYCLE1-offset] & 0xF0) >> 4];	// Verzögerung bei überschreiten
			switch (objno) {
			case 3:
				if ((eeprom[LUXPARAM]&0x80) == 0) delayunder=luxdelay[(eeprom[0xCD] & 0xF0) >> 4];
				else delayover=0;	// bei Helligkeitsregelung keine Verzögerung
				break;
			case 4:
				delayunder=luxdelay[eeprom[0xCD] & 0x0F];
				break;
			case 5:
				delayunder=luxdelay[(eeprom[0xCC] & 0xF0) >> 4];
				break;
			}
			
		}
		else {			
			if (objno<8) {	// Temperaturschwellen
				schwellwert=eeprom[LUXSCHWELLWERT-offset];		
				hysterese = ctrl & 0x07;
				if ((temp > (schwellwert*100)) && schwellwert<51) over=1;
				if ((temp < ((schwellwert - hysterese)*100)) && schwellwert<51) under=1;
			}
			else {			// Verknüpfungsobjekte
				if (objno==8) {
					temp_compare = eeprom[VERKCYCLE_TEMP1] & 0x70;
					lux_compare = eeprom[VERKLUX1] & 0xF0;
				}
				else {
					temp_compare = eeprom[VERKCYCLE_TEMP2] & 0x70;
					lux_compare = eeprom[VERKLUX2] & 0xF0;
				}
				

				// hier bedeutet over=Bedingung erfüllt, under=bedingung nicht erfüllt
				over=0;
				under=0;
				switch (temp_compare) {
				case 0:
					over=1;
					break;
				case 0x10:		// 1 = größer als Temperaturschwelle 1
					over = (overrun & 0x08);
					break;
				case 0x20:		// 2 = größer als Temperaturschwelle 2
					over = (overrun & 0x10);
					break;
				case 0x30:		// 3 = kleiner als Temperaturschwelle 1
					over = (underrun & 0x08);
					break;
				case 0x40:		// 4 = kleiner als Temperaturschwelle 2
					over = (underrun & 0x10);
					break;
				}
				switch (lux_compare) {
				case 0x10:		// 1 = größer als Helligkeitsschwelle 1
					over &= (overrun & 0x01);
					break;
				case 0x20:		// 2 = größer als Helligkeitsschwelle 2
					over &= (overrun & 0x02);
					break;
				case 0x30:		// 3 = größer als Helligkeitsschwelle 3
					over &= (overrun & 0x04);
					break;
				case 0x40:		// 4 = kleiner als Helligkeitsschwelle 1
					over &= (underrun & 0x01);
					break;
				case 0x50:		// 5 = kleiner als Helligkeitsschwelle 2
					over &= (underrun & 0x02);
					break;
				case 0x60:		// 6 = kleiner als Helligkeitsschwelle 3
					over &= (underrun & 0x04);
					break;
				}

				under = !over;
			}
		}
		
		if (objno>=8) offset++;				// da Verssatz in der Reihenfolge der Parameter
		werth=eeprom[LUX_OVER-offset];		// zu sendender Wert bei überschreiten
		wertl=eeprom[LUX_UNDER-offset];		// zu sendender Wert bei unterschreiten
		bitmask=1<<(objno-3);				// Bitmaske für underrun und overrun
		sendcyclich = (ctrl & 0x20) >> 5;	// zyklisches senden bei überschreiten
		sendcyclicl = (ctrl & 0x80) >> 7;	// zyklisches senden bei unterschreiten
		
		
		if (((ctrl & 0x08)==0) || lock==0) {	// Sperre ignorieren oder Sperre=0
			if (over) {					// wenn überschritten
				if ((ctrl & 0x30) && !(overrun&bitmask)) { 	// wenn einmal oder zyklisch gesendet werden soll
					if (delayover) {
						sendcyclich+=2;	// Bit0: zyklisch, Bit1: verzögert, alle 0 = inaktiv
						timerneu=timer+delayover;
					}
					WRITE_DELAY_RECORD(objno-1,sendcyclich,timerneu)	//objno-1 weil objekt 2 nicht existiert
					if (delayover==0) send_value(1,objno,werth);	//eistype
					if (read_obj_value(objno) != werth) write_obj_value(objno,werth);	// nur flashen wenn nötig
					overrun|=bitmask;		// überschreiten wurde schon gesendet
				}
				underrun&=0xFF-bitmask;	// unterschreiten schon gesendet löschen
			}
			if (under) {		// wenn unterschritten
				if ((ctrl & 0xC0) && !(underrun&bitmask)) { 	// wenn einmal oder zyklisch gesendet werden soll
					if (delayunder) {
						sendcyclicl+=2;	// Bit0: zyklisch, Bit1: verzögert, alle 0 = inaktiv
						timerneu=timer+delayunder;
					}
					WRITE_DELAY_RECORD(objno-1,sendcyclicl,timerneu)
					if (delayunder==0) send_value(1,objno,wertl);	//eistype
					if (read_obj_value(objno) != wertl) write_obj_value(objno,wertl);	// nur flashen wenn nötig
					underrun|=bitmask;
				}
				overrun&=0xFF-bitmask;
			}
		}
		else {	// Sperre gesetzt und muss beachtet werden
			WRITE_DELAY_RECORD(objno-1,0,0)	// zyklisches Senden anhalten
			overrun&=0xFF-bitmask;			// über-/unterschritten bits löschen, damit es bei aufgehobener sperre sofort weiterläuft
			underrun&=0xFF-bitmask;
		}
	}
}



void send_value(unsigned char type, unsigned char objno, int sval)	// sucht Gruppenadresse für das Objekt objno uns sendet ein EIS Telegramm
{												// mit dem Wert sval
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
		
		// Applikationsspezifische Zuweisung der Objektwerte
		switch (objno) {
		case 0:
			objvalue = eis5lux;
			break;
		case 1:
			objvalue = eis5temp;
			break;
		case 3:
			if (eeprom[LUXPARAM]&0x80) objvalue=dimmwert;
			else objvalue=read_obj_value(objno);
		default:
			objvalue=read_obj_value(objno);		// Objektwert aus USER-RAM lesen (Standard Einstellung)
		}
		

		objflags=read_objflags(objno);		// Objekt Flags lesen
		// Objekt lesen, nur wenn read enable gesetzt (Bit3) und Kommunikation zulaessig (Bit2)
		if((objflags&0x0C)==0x0C) send_value(0,objno,objvalue);
    }
}



void write_value_req(void)
{
	unsigned char objno, wert;
	
	objno=find_first_objno(telegramm[3],telegramm[4]); 
	
	if (objno>2) {	// Sperrobjekt und Schaltobjekte
		send_ack();
		if (objno==3 && (eeprom[LUXPARAM]&0x80)) wert=telegramm[8];	// bei Helligkeitsregelung EIS 6
		else wert=telegramm[7]&0x01;								// sonst EIS 1
		write_obj_value(objno,wert);
	}
}



void delay_timer(void)	// zählt alle 130ms die Variable Timer hoch und prüft Einträge
{
	unsigned char objno, delay_state, eistype, cycle_param=0, offset;
	unsigned int objvalue;

	stop_rtc();
	timer++;
	start_rtc(130);	// RTC mit 130ms neu starten
	
	for(objno=0;objno<=7;objno++) {
		eistype=0;
		delay_state=delreco[objno].delaystate;	  
		if (delreco[objno].delayvalue==timer && delay_state) {
		  
			switch (objno) {
		  
			case 0:		// Helligkeitswert zyklisch senden
				cycle_param=eeprom[LUXPARAM]&0x0F;
				objvalue = eis5lux;
				break;		  
		  
			case 1:		// Temperaturwert zyklisch senden
				cycle_param=eeprom[TEMPPARAM]&0x0F;
				objvalue = eis5temp;
				break;

			case 2: 	// Helligkeitsschwelle1, objektnummer 3 !!!
				cycle_param=eeprom[LUXCYCLE1]&0x07;
				if (overrun & 0x01) objvalue = eeprom[LUX_OVER]; else objvalue = eeprom[LUX_UNDER];
				if (eeprom[LUXPARAM]&0x80) objvalue = dimmwert; 
				break;
				
			default:
				cycle_param=eeprom[LUXCYCLE1-((objno-3)*5)]&0x07;
				objvalue = read_obj_value(objno+1);
				break;
			}
			if (objno>1) offset=1; else offset=0;	// da objno 2 im delay nicht benutzt wird
			
			send_value(1,objno+offset,objvalue);	
			if (delay_state&0x01) {	// zyklisch
				WRITE_DELAY_RECORD(objno,1,timer+cycleval[cycle_param])
			}
			else {
				WRITE_DELAY_RECORD(objno,0xFF,0);	// inaktiv
			}
		}
	}
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{
	
	unsigned char objno;
  
	PT0AD=0xF0; 		// disable digital inputs P0.1 ... P0.5
	P0= 0xBF;			// P0.0 push-pull for charging the capacitor, P0.6 push-pull status-LED
	P0M1= 0x22;			// others bidirectional,
	P0M2= 0x41;			// P0_5 & P0_1 high impedance for adc inputs
	
	lux=0;
	lastlux=0;
	temp=0;
	lasttemp=0;

	overrun=0;			// obere Bits für überschritten gesendet, untere für Unterschritten gesendet
	underrun=0;
	
	timer=0;
	sequence=1;
  
  	for (objno=0;objno<9;objno++) WRITE_DELAY_RECORD(objno,0,0)			// erstmal alle delay-records auf inaktiv setzen
	if ((eeprom[TEMPPARAM] & 0x0F)!=0x00) WRITE_DELAY_RECORD(1,1,30)	// falls Temperaturwert zyklisch gesendet werden soll
	if ((eeprom[LUXPARAM] & 0x0F)!=0x00)  WRITE_DELAY_RECORD(0,1,35)	// falls Helligkeitswert zyklisch gesendet werden soll

	START_WRITECYCLE			// Applikations-spezifische eeprom Eintraege schreiben
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode: 0x0001 Siemens
  	WRITE_BYTE(0x01,0x04,0x01)
  	WRITE_BYTE(0x01,0x05,0x22)	// Gerätetyp: 0x221C AP254
  	WRITE_BYTE(0x01,0x06,0x1C)	
  	WRITE_BYTE(0x01,0x07,0x01)	// Software-Versionsnummer
  	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
  	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
  	WRITE_BYTE(0x01,0x12,0x56)	// COMMSTAB Pointer
	STOP_WRITECYCLE


}
