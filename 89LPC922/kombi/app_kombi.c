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
#include "../com/onewire.h"
#include "app_kombi.h"

/*
const __code unsigned char __at 0x1D04 MANUFACTURER = 1;	// Siemens
const __code unsigned char __at 0x1D05 TYPEH = 0x22;		// Geräte Typ (AP254) 221Ch
const __code unsigned char __at 0x1D06 TYPEL = 0x00;
const __code unsigned char __at 0x1D07 VERSIONNO = 1;		// Versionsnummer
const __code unsigned char __at 0x1D0C PORTADIR = 0;		// PORT A Direction Bit Setting
const __code unsigned char __at 0x1D0D RUNSTATE = 0xFF;		// Run-Status (00=stop FF=run)
const __code unsigned char __at 0x1D12 CTPTR = 0x56;		// COMMSTAB Pointer
*/

const int cycleval[] = {27692, 462, 1385, 2308, 4615, 9231, 13846, 20769, 27692}; // Zykluszeit in 130ms
const unsigned char luxtable[] = {10,11,12,14,16,18,20,23,26,30,35,40,45,50,55,60,70,80,90};
const unsigned char hystable[] = {1,2,10,5,3};	// divisor für Lux Hysterese (50%,10%,20%,30%)

int temp, eis5temp,lasttemp,lux,lastlux, eis5lux;
unsigned char luxsent, dimmwert;

struct delayrecord {
	unsigned char delaystate;
	long delayvalue;
};
struct delayrecord delreco[8];


#define WRITE_DELAY_RECORD(wdro,wdrs,wdrt) \
	delreco[wdro].delaystate=wdrs; \
	delreco[wdro].delayvalue=wdrt; 







void temp_schwelle(bit schwelle)		// Temperaturschwelle prüfen und reagieren
{
	char schwellwert;
	unsigned char tempctrl, hysterese, tempwerth, tempwertl, objno, cycle, eistype;
	bit sendval, ignorelock, sendonceh, sendcyclich, sendoncel, sendcyclicl;
	bit templevel;
	long timerneu;

	
	if (!schwelle) { // Temperaturschwelle 1
		schwellwert=eeprom[TEMPSCHWELLWERT1];
		tempctrl=eeprom[TEMPCTRL1];
		sendval = (eeprom[FUNKTION]&0x04) >> 2;
		templevel = templevel1;
		tempwerth = eeprom[TEMPWERT1H];
		tempwertl = eeprom[TEMPWERT1L];
		objno = 6;
		cycle = eeprom[TEMPCYCLE1] & 0x07;
	}
	else { // Temperaturschwelle 2
		schwellwert=eeprom[TEMPSCHWELLWERT2];
		tempctrl=eeprom[TEMPCTRL2];
		sendval = (eeprom[FUNKTION] & 0x08) >> 3;
		templevel = templevel2;
		tempwerth = eeprom[TEMPWERT2H];
		tempwertl = eeprom[TEMPWERT2L];
		cycle = eeprom[TEMPCYCLE2] & 0x07;
		objno = 7;
	}
	if (sendval) eistype=6; else eistype=1;
	ignorelock = (tempctrl & 0x08) >> 3;	// 0=Sperre ignorieren
	hysterese = tempctrl & 0x07;
	sendonceh = (tempctrl & 0x10) >> 4;
	sendcyclich = (tempctrl & 0x20) >> 5;
	sendoncel = (tempctrl & 0x40) >> 6;
	sendcyclicl = (tempctrl & 0x80) >> 7;
	timerneu = timer+cycleval[cycle];
	
	
	if (schwellwert<51) {			// wenn > 50 dann ist die Temp.-Schwelle inaktiv
		if (!((read_obj_value(10)==1) && (ignorelock==1))) {	// wenn Sperrobjekt nicht gesetzt oder Sperre ignorieren
			if (temp > (schwellwert*100)) {	//überschritten
				if ((sendonceh || sendcyclich) && !templevel) {	//wenn nur einmal odr zyklisch senden und erstes mal überschritten
					if (sendcyclich) WRITE_DELAY_RECORD(objno,1,timerneu)
					send_eis(eistype,objno,tempwerth);	// Wert senden oder schalten

				}
				templevel=1;	// wurde überschritten
			}
			if (temp < ((schwellwert - hysterese)*100)) {	// unterschritten
				if ((sendoncel  || sendcyclicl) && templevel) {	//wenn nur einmal senden und erstes mal unterschritten
					if (sendcyclicl) WRITE_DELAY_RECORD(objno,1,timerneu)
					send_eis(eistype,objno,tempwertl);

				}
				templevel=0;	// wurde unterschritten
			}
		}
	}
	if (schwelle) templevel2=templevel;
	else templevel1=templevel;
}


void lux_schwelle(unsigned char schwelle)		// Luxschwelle prüfen und reagieren
{
	
	unsigned char ctrl=0, luxwerth=0, luxwertl=0, objno=0, cycle=0, potenz, rest, bitmaskh, bitmaskl;
	unsigned char lastdimm;
	bit sendval=0;
	bit luxlevel=0;

	unsigned int schwellwert=0;
	unsigned int hysterese=0;


	potenz=(eeprom[LUXSCHWELLWERT-(schwelle*5)]+1) / 19;
	rest=eeprom[LUXSCHWELLWERT-(schwelle*5)] - (19*potenz) +1;
	schwellwert=luxtable[rest];
	switch (potenz) {
	case 0:
		schwellwert=schwellwert/10;
		break;
	case 2:
		schwellwert=schwellwert*10;
		break;
	case 3:
		schwellwert=schwellwert*100;
		break;
	case 4:
		if (schwellwert<=60) schwellwert=schwellwert*1000;
		else schwellwert=0xFFFF;
		break;
	case 5:
		schwellwert=0xFFFF;
		break;
	}
	
	ctrl=eeprom[LUXCTRL-(schwelle*5)];
	
	
	
	if ((eeprom[LUXPARAM]&0x80) && schwelle==0) {	// Helligkeitsregelung (nur Objekt1)
		lastdimm=dimmwert;
		schwellwert=eeprom[LUXSCHWELLWERT]*10;		// schwellwert ist hier der Sollwert
		hysterese=_divuint(schwellwert,hystable[ctrl&0x07]);
		if (hysterese==0) hysterese=1;	// mindestens jedoch 1 Lux
		if (((ctrl & 0x08)==0) || read_obj_value(10)==0) {	// Sperre ignorieren oder Sperre=0
			if (lux>schwellwert) {	// wenn überschritten
				if ((lux > (schwellwert*2)) && (dimmwert > 15)) dimmwert-=16;
				else if (dimmwert>3) dimmwert-=4;
			}
			if (lux<(schwellwert-hysterese)) {		// wenn unterschritten
				if (((lux*2) < (schwellwert-hysterese)) && (dimmwert < 240)) dimmwert+=16;	// grosse Schritte wenn weit weg von Sollwert
				else if (dimmwert<252) dimmwert+=4;
			}
			if (lastdimm != dimmwert) send_eis(6,3,dimmwert);
		}
	}
	else {	// Helligkeitsschwelle
		hysterese=_divuint(schwellwert,hystable[ctrl&0x07]);
		if (hysterese==0) hysterese=1;	// mindestens jedoch 1 Lux
		bitmaskh=1<<(4+schwelle);		// Bitmaske für oberes nibble
		bitmaskl=1<<schwelle;			// Bitmaske für unteres Nibble
		
		if (((ctrl & 0x08)==0) || read_obj_value(10)==0) {	// Sperre ignorieren oder Sperre=0
			if (lux>schwellwert) {					// wenn überschritten
				if (ctrl & 0x30) { 	// wenn einmal oder zyklisch gesendet werden soll
					if(!(luxsent&bitmaskh)) {	// Nur senden wenn vorher noch nicht gesendet
						send_eis(1,3+schwelle,eeprom[LUX_OVER-(schwelle*5)]);
						luxsent|=bitmaskh;		// luxsent: obere 4 bits=1 -> überschreiten wurde schon gesendet
					}
					luxsent&=0xFF-bitmaskl;	// luxsent: untere 4 bits=1 -> unterschreiten wurde schon gesendet
				}
			}
			if (lux<(schwellwert-hysterese)) {		// wenn unterschritten
				if (ctrl & 0xC0) { 	// wenn einmal oder zyklisch gesendet werden soll			
					if (!(luxsent&bitmaskl)) {		// Nur senden wenn vorher noch nicht gesendet
						send_eis(1,3+schwelle,eeprom[LUX_UNDER-(schwelle*5)]);
						luxsent|=bitmaskl;
					}
					luxsent&=0xFF-bitmaskh;
				}
			}
		}
	}
}



void send_eis(unsigned char eistyp, unsigned char objno, int sval)	// sucht Gruppenadresse für das Objekt objno uns sendet ein EIS 1 Telegramm
{														// mit dem Wert sval+0x80
  int ga;

  ga=find_ga(objno);					// wenn keine Gruppenadresse hintrlegt nix tun
  if (ga!=0)
  {
    telegramm[0]=0xBC;
    telegramm[1]=eeprom[ADDRTAB+1];
    telegramm[2]=eeprom[ADDRTAB+2];
    telegramm[3]=ga>>8;
    telegramm[4]=ga;
    telegramm[6]=0x00;
    telegramm[7]=0x80;
    switch (eistyp) {
    case 1:
    	telegramm[5]=0xD1;
    	telegramm[7]+=sval;
    	break;
    case 5:
    	telegramm[5]=0xE3;  	
    	telegramm[8]=sval>>8;
    	telegramm[9]=sval;
    	break;
    case 6:
    	telegramm[5]=0xE2;
    	telegramm[8]=sval;
    	break;
    }
    
    EX1=0;
    send_telegramm();
    IE1=0;
    EX1=1;
  }
}  





void write_value_req(void)
{
	unsigned char objno;
	
	objno=find_first_objno(telegramm[3],telegramm[4]);
	if (objno!=0xFF) send_ack();
	
	if (objno==10) {	// Sperrobjekt
		write_obj_value(10,telegramm[7]&0x01);
	}
}



void delay_timer(void)	// zählt alle 130ms die Variable Timer hoch und prüft Queue
{
  unsigned char objno,delay_state;

  
  
  stop_rtc();
  
  timer++;

  for(objno=0;objno<=7;objno++) {
	  delay_state=delreco[objno].delaystate;	  
	  if (delreco[objno].delayvalue==timer) {
		  if (objno==6) {	// Temperaturschwelle 1
			  if (!(eeprom[FUNKTION] & 0x04)) {	// schalten
				  if (((eeprom[TEMPCTRL1] & 0x30)==0x20) && templevel1) { // zykl. und überschr.
					  WRITE_DELAY_RECORD(6,1,timer+cycleval[eeprom[TEMPCYCLE1]&0x07])
					  send_eis(1,6,eeprom[TEMPWERT1H]);
				  }
				  if (((eeprom[TEMPCTRL1] & 0xC0)==0x80) && !templevel1) { // zykl. und unterschr.
					  WRITE_DELAY_RECORD(6,1,timer+cycleval[eeprom[TEMPCYCLE1]&0x07])
					  send_eis(1,6,eeprom[TEMPWERT1L]);    
				  }
			  }
		  }
    
		  if (objno==7) {	// Temperaturschwelle 2
			  if (!(eeprom[FUNKTION] & 0x08)) {	// schalten
				  if (((eeprom[TEMPCTRL2] & 0x30)==0x20) && templevel2) { // zykl. und überschr.
					  WRITE_DELAY_RECORD(7,1,timer+cycleval[eeprom[TEMPCYCLE2]&0x07])
					  send_eis(1,7,eeprom[TEMPWERT2H]);
        				
				  }
				  if (((eeprom[TEMPCTRL2] & 0xC0)==0x80) && !templevel2) { // zykl. und unterschr.
					  WRITE_DELAY_RECORD(7,1,timer+cycleval[eeprom[TEMPCYCLE2]&0x07])
					  send_eis(1,7,eeprom[TEMPWERT2L]);
				  }
			  }
		  }
    

		  if(objno==1) {		// Temperaturwert zyklisch senden
			  if ((eeprom[TEMPPARAM]&0x0F)!=0) {
				  WRITE_DELAY_RECORD(1,1,timer+cycleval[eeprom[TEMPPARAM]&0x0F])
				  send_eis(5,1,eis5temp);
			  }	  
		  } 
		  if(objno==0) {		// Helligkeitswert zyklisch senden
        	  if ((eeprom[LUXPARAM]&0x0F)!=0) {
        	      WRITE_DELAY_RECORD(0,1,timer+cycleval[eeprom[LUXPARAM]&0x0F])
        	      send_eis(5,0,eis5lux);
        	  }	  
          }
	  }
  }
  start_rtc(130);	// RTC mit 130ms starten

}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{
	
	unsigned char objno;
  
	PT0AD=0xF0; 		// disable digital inputs P0.1 ... P0.5
	P0= 0xFF;			// P0.0 push-pull for charging the capacitor,
	P0M1= 0x22;			// others bidirectional,
	P0M2= 0x01;			// P0_5 & P0_1 high impedance for adc inputs
	
	//Temp Test LED
	SET_PORT_MODE_PUSHPULL(6)

	luxsent=0;			// obere Bits für überschritten gesendet, untere für Unterschritten gesendet

  
  	for (objno=0;objno<8;objno++) WRITE_DELAY_RECORD(objno,0,0)
	if ((eeprom[TEMPCTRL1] & 0x30)==0x20) WRITE_DELAY_RECORD(6,1,10)	// falls Temperaturschwelle1 zyklisch gesendet werden soll 
	if ((eeprom[TEMPCTRL1] & 0xC0)==0x80) WRITE_DELAY_RECORD(6,1,15)
	if ((eeprom[TEMPCTRL2] & 0x30)==0x20) WRITE_DELAY_RECORD(7,1,20)	// falls Temperaturschwelle2 zyklisch gesendet werden soll
	if ((eeprom[TEMPCTRL2] & 0xC0)==0x80) WRITE_DELAY_RECORD(7,1,25)
	if ((eeprom[TEMPPARAM] & 0x0F)!=0x00) WRITE_DELAY_RECORD(1,1,30)	// falls Temperaturwert zyklisch gesendet werden soll
	if ((eeprom[LUXPARAM] & 0x0F)!=0x00)  WRITE_DELAY_RECORD(0,1,35)	// falls Helligkeitswert zyklisch gesendet werden soll

	start_writecycle();			// Applikations-spezifische eeprom Eintraege schreiben
	write_byte(0x01,0x03,0x00);	// Herstellercode 
	write_byte(0x01,0x04,0x01);
	write_byte(0x01,0x05,0x22);	// Devicetype 
	write_byte(0x01,0x06,0x00);	
	write_byte(0x01,0x07,0x01);	// Versionsnummer
	write_byte(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
	write_byte(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
	write_byte(0x01,0x12,0x56);	// COMMSTAB Pointer
	stop_writecycle();


}
