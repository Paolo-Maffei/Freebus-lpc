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

#include <P89LPC935_6.h>
#include "../com/fb_rs232.h"
#include "../com/fb_hal_lpc936.h"
#include "../com/fb_prot.h"
#include "../com/onewire.h"

#include "app_ert30.h"


#define UP 			P0_4
#define DOWN		P0_6
#define EDITTIMEOUT	21


const __code unsigned char __at 0x3600 SOLLMANU=40;

//292
const int cycleval[] = {17490, 292, 875, 1458, 2915, 5830, 8745, 13117, 17490}; // Zykluszeit in 130ms
const unsigned int luxtable[] = {2,2,2,3,3,4,4,5,5,6,7,8,9,10,11,12,14,16,18,20,23,26,30,35,40,45,50,55,60,70,80,90,100,110,125,140,160,180,200,230,260,300,350,400,450,500,550,600,700,800,900,1000,1100,1250,1400,1600,1800,2000,2300,2600,3000,3500,4000,4500,5000,5500,6000,7000,8000,9000,10000,11000,12500,14000,16000,18000,20000,23000,26000,30000,35000,40000,45000,50000,55000,60000,65535,65535,65535,65535};
const unsigned char hystable[] = {1,2,10,5,3};	// divisor für Lux Hysterese (50%,10%,20%,30%)
const unsigned int luxdelay[] = {0,10,25,49,73,97,146,219,292,438,583,875,1458,2915,4380,8745};
const unsigned char ctrl_adr[]  = {0xD2,0xD1,0,0xF9,0xF4,0xEF,0xEA,0xE5,0xE0,0xDA};
//const unsigned char cycle_adr[] = {0,0,0,0xFA,0xF5,0xF0,0xEB,0xE6,0xE1,0xDB};


int temp, eis5temp,lasttemp,lux,lastlux, eis5lux;
unsigned char overrun, dimmwert, underrun, sequence, lockatt, resend, solltempmanu;
bit editmode;


struct delayrecord {
	unsigned char delayactive;
	unsigned char delaystate;
	unsigned int delayvalue;
};
struct delayrecord delrec[10];







void schwelle(unsigned char objno)		// Luxschwelle prüfen und reagieren
{
	
	unsigned char ctrl, cycle, bitmask, temp_compare, lux_compare;
	unsigned char lastdimm, step, wertl, werth, offset;
	bit sendval=0, unlock, over=0, under=0;
	bit luxlevel=0;
	unsigned char sendcyclicl=0, sendcyclich=0, active;

	unsigned int schwellwert=0;
	unsigned int hysterese=0, delayover=0, delayunder=0;
	unsigned int timerneu;
	

	offset=(objno-3)*5;
	if (objno==9) offset++;	// da Verssatz in der Reihenfolge der Parameter

	ctrl=eeprom[LUXCTRL-offset];
	cycle = eeprom[LUXCYCLE1-offset] & 0x07;
	timerneu = timer+cycleval[cycle];
	unlock=!((ctrl & 0x08) & (read_obj_value(10)));

	if ((eeprom[LUXPARAM]&0x80) && objno==3) {	// Helligkeitsregelung (nur Objekt1)
		
		lastdimm=dimmwert;		// beim letzten Durchlauf errechneter Wert
		schwellwert=eeprom[LUXSCHWELLWERT]*10;		// schwellwert ist hier der Sollwert
		hysterese=_divuint(schwellwert,hystable[ctrl&0x07]);
		if (hysterese==0) hysterese=1;	// mindestens jedoch 1 Lux
		step=(((ctrl & 0xF0) >> 4) + 1) * 16;
		
		//if (unlock) {	// Sperre ignorieren oder Sperre=0
			if (lux>schwellwert) {	// wenn überschritten
				if ((lux > (schwellwert*2)) && (dimmwert >= step)) dimmwert-=step;	// grosse Schritte wenn weit weg von Sollwert
				else {
					if (dimmwert>3) dimmwert-=4;		// kleine Schritte
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
				//send_value(1,3,dimmwert);	//6
				//WRITE_DELAY_RECORD(2,1,timerneu)
				WRITE_DELAY_RECORD(2,1,dimmwert,timer+1)
			}
		//}
	}

	else {	// Schwellen

		if (objno<6) {	// Helligkeitsschwellen
			schwellwert=luxtable[eeprom[LUXSCHWELLWERT-offset]-7];	// -7, weil luxtable erst ab 7 beginnt
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
				if (schwellwert<51) {	//>51 : Temperaturschwelle inaktiv
					if (temp > (schwellwert*100)) over=1;
					if (temp < ((schwellwert - hysterese)*100)) under=1;
				}
			}
			else {			// Verknüpfungsobjekte
				
				if (objno==8) {
					//temp_compare = eeprom[VERKCYCLE_TEMP1] & 0x70;
					lux_compare = eeprom[VERKLUX1] & 0xF0;
				}
				else {
					//temp_compare = eeprom[VERKCYCLE_TEMP2] & 0x70;
					lux_compare = eeprom[VERKLUX2] & 0xF0;
				}
				
				temp_compare = eeprom[ctrl_adr[objno]+1] & 0x70;

				

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

		
		if (over) {					// wenn überschritten
			if (!(overrun&bitmask)) { 	// wenn neu überschritten
				
				if (delayover==0 || (resend&bitmask)) {		// sofort senden
					timerneu=timer+1;
					resend&=~bitmask;
					active=3;
				}
				else {	// verzögert senden
					if(delrec[objno-1].delayactive==5) {
						active=0;
					}
					else {
						active=7;
						timerneu=timer+delayover;
					}
				}
				WRITE_DELAY_RECORD(objno-1,active,werth,timerneu)	//objno-1 weil objekt 2 nicht existiert					
				

			}
			overrun|=bitmask;
			underrun&=~bitmask;
		}
		
		if (under) {		// wenn unterschritten
			if (!(underrun&bitmask)) { 	// wenn einmal oder zyklisch gesendet werden soll
				
				if (delayunder==0 || (resend&bitmask)) {	// sofort senden
					timerneu=timer+1;
					resend&=~bitmask;
					active=1;
				}
				else {											// verzögert senden
					if(delrec[objno-1].delayactive==7) {
						active=0;
						}
					else {
						active=5;
						timerneu=timer+delayunder;
					}
				}
				WRITE_DELAY_RECORD(objno-1,active,wertl,timerneu)
				

			}
			underrun|=bitmask;
			overrun&=~bitmask;
		}
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
	unsigned char objno, n, bitmask;
	
	objno=find_first_objno(telegramm[3],telegramm[4]); 
	
	if (objno==10) {	// nur Sperrobjekt
		send_ack();
		write_obj_value(objno,telegramm[7]&0x01);
		
		if((telegramm[7]&0x01)==0) {
			resend=0;
			for(n=0; n<=7; n++) {
				bitmask=1<<n;
				if(lockatt&bitmask) {
					overrun&=~bitmask;
					underrun&=~bitmask;
					resend|=bitmask;
				}
			}
		}
	}
}



void delay_timer(void)	// zählt alle 130ms die Variable Timer hoch und prüft Einträge
{
	unsigned char delrecno, objno, delay_state, cycle_param=0, bitmask, ctrl, werth;
	unsigned int objvalue=0;
	bit send, cyclic, sendcyclicl=0, sendcyclich=0;

	stop_rtc();
	timer++;
	start_rtc(130);	// RTC mit 130ms neu starten
	
	for(delrecno=0;delrecno<=7;delrecno++) {
		objno=delrecno;
		if (delrecno>1) objno++;	// da objno 2 im delay nicht benutzt wird
		bitmask=1<<(objno-3);
		
		delay_state=delrec[delrecno].delaystate;	  
		if (delrec[delrecno].delayvalue==timer && delrec[delrecno].delayactive) {
			
			send=0;
			cyclic=0;
			ctrl=eeprom[ctrl_adr[objno]];		// Control Parameter 
			werth=eeprom[ctrl_adr[objno]-1];	// Wert bei überschreiten ( 1 unter Control ) 			
			
			switch (delrecno) {
			case 0:		// Helligkeitswert
				objvalue = eis5lux;
				send=1;		// ohne Prüfung auf Sperre etc. senden
				cyclic=1; 
				break;		  
			case 1:		// Temperaturwert
				objvalue = eis5temp;
				send=1;					// ohne Prüfung auf Sperre etc. senden
				cyclic=1;
				break;
			default:
				objvalue = delay_state;
				
				if ((werth==delay_state && (ctrl & 0x20)!=0) || 			// wenn überschritten und es soll zyklisch gesendet werden...
					(werth!=delay_state && (ctrl & 0x80)!=0) )	cyclic=1;	// oder wenn unterschritten und es soll zyklisch gesendet werden...
				

				if ((werth==delay_state && (ctrl&0x30)) || (werth!=delay_state && (ctrl&0xC0))) {	// ... nur wenn einmal oder zyklisch
					if ((ctrl & 0x08)==0 || read_obj_value(10)==0) {	// ... nur wenn Sperre ignorieren oder Sperre=0							
						send=1;	
					}
				}
				if ((eeprom[LUXPARAM]&0x80) && (objno==3)) {	// bei Helligkeitsregelung immer zyklisch und immer senden
					if ((ctrl & 0x08)==0 || read_obj_value(10)==0) {	// ... nur wenn Sperre ignorieren oder Sperre=0													
						send=1;
						cyclic=1;
					}
				}
			}

			if (send) {
				send_value(1,objno,objvalue);			// Telegramm senden
				write_obj_value(objno,objvalue);		// Wert ins userram schreiben
			}
			
			// wenn delay zur Verzögerung aktiv war, dann Verzögerungs-Bit löschen
			if(delrec[delrecno].delayactive & 0x04) delrec[delrecno].delayactive-=4;
			
			if (cyclic) {	
				cycle_param=eeprom[ctrl_adr[objno]+1]&0x0F;	// Zyklus-Adresse jeweils ein Byte über ctrl_adr
				delrec[delrecno].delayvalue=timer+cycleval[cycle_param];
			}
			
		}
	}
	if (delrec[9].delayvalue==timer && delrec[9].delayactive) {	//editmode manuelle Sollwerteinstellung
		editmode=0;
		delrec[9].delayactive=0;
	}
}


void sync(void)
{
	unsigned char n,m;
	
	
	EKBI=0;
	if (solltempmanu<40) {
		for (n=0;n<(41-solltempmanu);n++) {
			DOWN=0;
			for (m=0;m<10;m++) {
				set_timer0(65000);
				while (!TF0);
				TF0=0;
				TR0=0;
			}
			DOWN=1;
			for (m=0;m<10;m++) {
				set_timer0(65000);
				while (!TF0);
				TF0=0;
				TR0=0;
			}
		}
		editmode=1;
		WRITE_DELAY_RECORD(9,1,0,timer+EDITTIMEOUT)
	}
	
	if (solltempmanu>40) {
		for (n=0;n<(solltempmanu-39);n++) {
			UP=0;
			for (m=0;m<10;m++) {
				set_timer0(65000);
				while (!TF0);
				TF0=0;
				TR0=0;
			}
			UP=1;
			for (m=0;m<10;m++) {
				set_timer0(65000);
				while (!TF0);
				TF0=0;
				TR0=0;
			}
		}
		editmode=1;
		WRITE_DELAY_RECORD(9,1,0,timer+EDITTIMEOUT)
	}
	KBCON=0;
	EKBI=1;
}


void key(void) interrupt 7
{
	EA=0;				// alle Interrupts sperren
	
	set_timer0(65000);	// Entprellung
	while (!TF0);
	TF0=0;
	TR0=0;
	
	if (editmode) {		// erster Tastendruck bewirkt nichts, geht nur in Editier-Modus
		if (!UP) {		// + Taste gedrückt
			if (solltempmanu<70) solltempmanu++;
			//while(!UP);		// warten bis losgelassen
		}
		else {		// - Taste gedrückt
			if (solltempmanu>10) solltempmanu--;
			//while(!DOWN);	// warten bis losgelassen
		}
		
		rs_send_dec(solltempmanu);
		
		// ins flash schreiben
		START_WRITECYCLE
		WRITE_BYTE(0x00,0x00,solltempmanu)
		STOP_WRITECYCLE
	}
	
	editmode=1;
	WRITE_DELAY_RECORD(9,1,0,timer+EDITTIMEOUT)
	while(!DOWN || !UP);
	
	
	KBCON=0;	// Interrupt-Flag löschen
	EA=1;		// alle Interrupts wieder frei geben
}

void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{
	
	unsigned char objno, bitmask, ctrl, n, m;
  
	//PT0AD=0xF0; 		// disable digital inputs P0.1 ... P0.5
	//P0= 0xBF;			// P0.0 push-pull for charging the capacitor, P0.6 push-pull status-LED
	//P0M1= 0x22;			// others bidirectional,
	//P0M2= 0x41;			// P0_5 & P0_1 high impedance for adc inputs
	
	SET_PORT_MODE_BIDIRECTIONAL(4)
	SET_PORT_MODE_BIDIRECTIONAL(6)
	SET_PORT_MODE_BIDIRECTIONAL(7)
	UP=1;
	DOWN=1;
	editmode=0;
	

	
	for (m=0;m<3;m++) {
		for (n=0;n<200;n++) sysdelay(0xFFFF);	// Warten bis Bus stabil
	}	

	
	// Init DAC 0
	P2M1|=0x01;		// P2.0 high impedance
	P2M2&=0xFE;
	ADMODB|=0x04; 	// enable DAC0
	ADCON0|=0x04;	// enable ADC0 (muss auch für DAC sein!)
	
	KBMASK=0x50;		// P0.4 & P0.6 enabled for KB-Interrupt
	KBPATN=0x50;		// Pattern
	KBCON=0;			// Interrupt when port not equal to pattern
	EKBI=1;
	EA=1;
	
	lux=0;
	lastlux=0;
	temp=-10000;
	lasttemp=-10000;
	
	solltempmanu=userram[0];
	
	sync();
	
	rs_init();
	
	overrun=0;
	underrun=0;

	timer=0;
	sequence=1;
	
	// in lockatt bit setzen für jedes Objekt, das Sperre beachten muss
	lockatt=0;
	for (objno=3; objno<=9; objno++) {	
		ctrl=eeprom[ctrl_adr[objno]];		
		bitmask=1<<(objno-3);
		if (ctrl & 0x08) lockatt|=bitmask;
	}
	
	write_obj_value(10,0);		// Sperre bei Neustart löschen
  
  	for (objno=0;objno<9;objno++) WRITE_DELAY_RECORD(objno,0,0,0)			// erstmal alle delay-records auf inaktiv setzen

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
