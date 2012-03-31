/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2008-2012 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
#define uint8_t unsigned char

#include <P89LPC922.h>
#include "../lib_lpc922/fb_lpc922.h"
#include "app_kombi.h"



#define uint16_t unsigned int
#define uint8_t unsigned char

const int cycleval[] = {17490, 292, 875, 1458, 2915, 5830, 8745, 13117, 17490}; // Zykluszeit in 130ms abzüglich der Verzögerung durch ADC und temp in main
const unsigned int luxtable[] = {2,2,2,3,3,4,4,5,5,6,7,8,9,10,11,12,14,16,18,20,23,26,30,35,40,45,50,55,60,70,80,90,100,110,125,140,160,180,200,230,260,300,350,400,450,500,550,600,700,800,900,1000,1100,1250,1400,1600,1800,2000,2300,2600,3000,3500,4000,4500,5000,5500,6000,7000,8000,9000,10000,11000,12500,14000,16000,18000,20000,23000,26000,30000,35000,40000,45000,50000,55000,60000,65535,65535,65535,65535};
const unsigned char hystable[] = {1,2,10,5,3};	// divisor für Lux Hysterese (50%,10%,20%,30%)
const unsigned int luxdelay[] = {0,10,25,49,73,97,146,219,292,438,583,875,1458,2915,4380,8745};
const unsigned char ctrl_adr[]  = {0xD2,0xD1,0,0xF9,0xF4,0xEF,0xEA,0xE5,0xE0,0xDA};


__idata unsigned char overrun, dimmwert, underrun, sequence, lockatt, resend;
int global_object_value_0_to_1 [2];
__bit global_object_value_3_to_10;



#define DELREC_CNT 9

struct delayrecord {
	unsigned char delayactive;
	unsigned char delaystate;
	unsigned int delayvalue;
};

struct delayrecord delrec[DELREC_CNT];



void schwelle(unsigned char objno)		// Luxschwelle prüfen und reagieren
{

	unsigned char ctrl, cycle, bitmask, temp_compare, lux_compare;
	unsigned char lastdimm, step, wertl, werth, offset;
	__bit sendval=0, over=0, under=0;
	__bit luxlevel=0;
	unsigned char sendcyclicl=0, sendcyclich=0, active;
	unsigned int schwellwert=0;
	signed int schwellwert_temp =0;
	unsigned int hysterese=0, delayover=0, delayunder=0;
	unsigned int timerneu;


	offset=(objno-3)*5;
       // if (objno==8) offset++;        // da Verssatz in der Reihenfolge der Parameter
        if (objno==9) offset++;        // da Verssatz in der Reihenfolge der Parameter

	ctrl=eeprom[LUXCTRL-offset];
	cycle = eeprom[LUXCYCLE1-offset] & 0x07;
	timerneu = timer+cycleval[cycle];

	if ((eeprom[LUXPARAM]&0x80) && objno==3) {	// Helligkeitsregelung (nur Objekt1)

		lastdimm=dimmwert;		// beim letzten Durchlauf errechneter Wert
		schwellwert=eeprom[LUXSCHWELLWERT]*10;		// schwellwert ist hier der Sollwert

		hysterese=_divuint(schwellwert,hystable[ctrl&0x07]);
		if (hysterese==0) hysterese=1;	// mindestens jedoch 1 Lux
		step=(((ctrl & 0xF0) >> 4) + 1) * 16;

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
			WRITE_DELAY_RECORD(2,1,dimmwert,timer+1)
		}
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
				schwellwert_temp=(signed char)eeprom[LUXSCHWELLWERT-offset];
                                hysterese = ctrl & 0x07;

				if (schwellwert_temp<51) {	//>51 : Temperaturschwelle inaktiv
					if (temp > (schwellwert_temp* (signed int)100)) over=1;
					if (temp < ((schwellwert_temp - (signed int)hysterese)*(signed int)100)) under=1;
				}
			}
			else {			// Verknüpfungsobjekte

				if (objno==8) {
					lux_compare = eeprom[VERKLUX1];
				}
				else {
					lux_compare = eeprom[VERKLUX2];
				}

 			lux_compare&=0xF0;
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
					active=3;	// Bit0=1=aktiv und Bit1=1=überschritten
				}
				else {	// verzögert senden
					if(delrec[objno-1].delayactive==5) {	// wenn bereits verzögertes unterschreiten läuft ...
						active=0;							// ... timer inaktiv setzen
					}
					else {
						active=7;	// Bit0=1=aktiv und Bit1=1=überschritten und Bit2=1=verzögert senden
						timerneu=timer+delayover;
					}
				}
				WRITE_DELAY_RECORD(objno-1,active,werth,timerneu)	//objno-1 weil objekt 2 nicht existiert


			}
			overrun|=bitmask;		// Überschritten Bit setzen
			underrun&=~bitmask;		// Unterschritten Bit löschen
		}

		if (under) {										// wenn Wert unter Schwellwert
			if (!(underrun&bitmask)) { 						// wenn neu unterschritten

				if (delayunder==0 || (resend&bitmask)) {	// sofort senden
					timerneu=timer+1;
					resend&=~bitmask;
					active=1;						// Bit0=1=aktiv und Bit1=0=unterschritten
				}
				else {										// verzögert senden
					if(delrec[objno-1].delayactive==7) {	// falls verzögertes überschritten Senden noch läuft...
						active=0;							// ... stoppen
						}
					else {
						active=5;	// Bit0=1=aktiv und Bit1=0=unterschritten und Bit2=1=verzögert
						timerneu=timer+delayunder;
					}
				}
				WRITE_DELAY_RECORD(objno-1,active,wertl,timerneu)


			}
			underrun|=bitmask;	// Unterschritten Bit setzen
			overrun&=~bitmask;	// Überschritten Bit löschen
		}
	}
}



/*
// aktuellen Objektwert aus userram auslesen
unsigned long read_obj_value(unsigned char objno)
{
	unsigned char objtype, valuepointer, offset, commstab;
	unsigned long objvalue=0;

	offset=objno*3;
	commstab=eeprom[COMMSTABPTR];
	objtype=eeprom[commstab+offset+4];

	if (objno <= commstab) {	// wenn objno <= anzahl objekte
		valuepointer=eeprom[commstab+offset+2];	// Zeiger auf USERRAM, wo der Objekt-Wert gespeichert ist
                //map ram adress  and 0x0 till 0x0f to user_ram[0] till user_ram[15], 0x50 to 0x5f to user_ram[16] to user_ram[31]
		// 0xce-0xdf to array of user_ram[31] till user_ram[49]
#ifdef USE_RAM
		if (valuepointer < 0xce)
                  {if (valuepointer > 0x0f) valuepointer += 0x10 - 0x50; //
                  //else valuepointer = 0xce -0x20 -valuepointer - 0x50;
                  }else valuepointer -= 0xce + 0x20;

                //if (objtype < 8) {
                        objvalue=user_ram[valuepointer]; // Typ zwischen 1 und 8 Bit gross
                //}
                if (objtype == 8) {     // 2-Byte Wert
                        objvalue=256*objvalue+user_ram[valuepointer+1];
                }

#else
                if (valuepointer < 0xce)
                  if (valuepointer < 0x20) valuepointer = 0xce -valuepointer;
                  else valuepointer = 0xce -0x20 -valuepointer - 0x50;

		//if (objtype < 8) {
			objvalue=userram[valuepointer];	// Typ zwischen 1 und 8 Bit gross
		//}
		if (objtype == 8) {	// 2-Byte Wert
			objvalue=256*objvalue+userram[valuepointer+1];
		}
#endif
	}
	return(objvalue);

}
*/

unsigned long read_obj_value(unsigned char objno)
{
	int objvalue=0;

	if (objno <= 1) {
		objvalue = global_object_value_0_to_1[objno];
	}
	if (objno >=3 && objno <= 10) {
		if (global_object_value_3_to_10 & (1<<(objno-3))) objvalue=1; else objvalue=0;
	}
	return(objvalue);
}


void write_obj_value(unsigned char objno,int objvalue)
{
	unsigned char bitpattern;

	bitpattern = 1<<(objno-3);
	if (objno <= 1) {
		global_object_value_0_to_1[objno]=objvalue;
	}
	if (objno >=3 && objno <= 10) {
		if (objvalue) global_object_value_3_to_10 |= bitpattern;
		else global_object_value_3_to_10 &= (0xFF - bitpattern);
	}

}


/*
void write_obj_value(unsigned char objno,int objvalue)
{
	unsigned char objtype, valuepointer, offset, commstab;
	__bit write_ok=0;

	offset=objno*3;
	commstab=eeprom[COMMSTABPTR];
	objtype=eeprom[commstab+offset+4];

	if (objno <= commstab) {	// wenn objno <= anzahl objekte
		valuepointer=eeprom[commstab+offset+2];	// Zeiger auf USERRAM, wo der Objekt-Wert gespeichert ist
#ifdef USE_RAM
                if (valuepointer < 0xce)
                  {if (valuepointer > 0x0f) valuepointer += 0x10 - 0x50; //
                   }
                else valuepointer -= 0xce + 0x20;

                if (objtype < 8) user_ram[valuepointer] = objvalue & (0xFF>>(7-objtype));
                else {  // da hier nur max. mit 2-Byte Werten gearbeitet wird, reicht das "else"
                    user_ram[valuepointer] = objvalue>>8;         // HighByte
                    user_ram[valuepointer+1] = objvalue & 0xff;            // Autoinkrement, LowByte
                }

#else
		if (valuepointer < 0xce)
		  if (valuepointer < 0x20) valuepointer = 0xce -valuepointer;
		  else valuepointer = 0xce -0x20 -valuepointer - 0x50;

		EA=0;
		while (!write_ok) {
			FMCON=0x00;					// load command, leert das pageregister
			FMADRH=USERRAMADDRH;
			FMADRL=valuepointer;
			if (objtype < 8) FMDATA=objvalue & (0xFF>>(7-objtype));
			else {	// da hier nur max. mit 2-Byte Werten gearbeitet wird, reicht das "else"
			    FMDATA=objvalue>>8;		// HighByte
			    FMDATA=objvalue;		// Autoinkrement, LowByte
			}
			FMCON=0x68;					// write command, schreibt pageregister ins flash und versetzt CPU in idle fuer 4ms
			if(!(FMCON & 0x01)) write_ok=1;	// pruefen, ob erfolgreich geflasht
		}
		EA=1;
#endif
	}
}
*/



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

	objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
	if(objno!=0xFF) {									// falls Gruppenadresse nicht gefunden
		objflags=read_objflags(objno);					// Objekt Flags lesen
		// Objekt lesen, nur wenn read enable gesetzt (Bit3) und Kommunikation zulaessig (Bit2)
		if((objflags&0x0C)==0x0C) send_obj_value(objno+0x40);
	}
}



void write_value_req(void)
{
	unsigned char objno;

	objno=find_first_objno(telegramm[3],telegramm[4]);

	if (objno==10) {	// nur Sperrobjekt darf beschrieben werden
		//write_obj_value(objno,telegramm[7]&0x01);
		if(telegramm[7]&0x01) global_object_value_3_to_10 |= 0x80;
		else global_object_value_3_to_10 &= 0x7F;

		// Bei Aufheben der Sperre sollen alle zuvor gesperrten Objekte ihren Wert senden
		if((telegramm[7]&0x01)==0) {
			overrun&=~lockatt;
			underrun&=~lockatt;
			resend=lockatt;
		}
	}
}



void delay_timer(void)	// zählt alle 130ms die Variable Timer hoch und prüft Einträge
{
	unsigned char delrecno, objno, delay_state, cycle_param=0, ctrl, sperre;
	__bit send, cyclic, over;

	RTCCON=0x60;	// Real Time Clock stoppen

	timer++;

	RTCH=0x1D;		// Real Time Clock auf 130ms laden (0,13s x 7372800 / 128)
	RTCL=0x40;		// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
	RTCCON=0x61;	// ... und starten

	for(delrecno=0;delrecno<DELREC_CNT;delrecno++) {
		objno=delrecno;
		if (delrecno>1) objno++;	// da objno 2 im delay nicht benutzt wird

		delay_state=delrec[delrecno].delaystate;
		if (delrec[delrecno].delayvalue==timer && delrec[delrecno].delayactive) {

			send=0;
			cyclic=0;
			ctrl=eeprom[ctrl_adr[objno]];		// Control Parameter
			sperre=read_obj_value(10);

			if (delrecno<2) {	//Helligkeits- und Temperaturwert

				if ((eeprom[0xD3-delrecno])!=0)send=1;		// ohne Prüfung auf Sperre etc. immer senden wenn mindset hysterese<>0 oder zykl.

				if ((eeprom[0xD3-delrecno]&0x0F)!=0) cyclic=1;	// falls zyklisches Senden

			}
			else{	// Schwellen und Verknüpfungen
				over=delrec[delrecno].delayactive & 0x02;	// überschritten
				if (over) {	// wenn überschritten
					if(ctrl & 0x20) cyclic=1;	// wenn überschritten und es soll zyklisch gesendet werden...
				}
				else {
					if(ctrl & 0x80) cyclic=1;	// ...oder wenn unterschritten und es soll zyklisch gesendet werden...
				}

				if ((over && (ctrl&0x30)) || (!over && (ctrl&0xC0))) {	// Senden bei über- oder unterschreiten...
					if ((ctrl & 0x08)==0 || sperre==0) {	// ... nur wenn Sperre ignorieren oder Sperre=0
						send=1;
					}
				}

				if ((eeprom[LUXPARAM]&0x80) && (objno==3)) {	// bei Helligkeitsregelung immer zyklisch und immer senden
					if ((ctrl & 0x08)==0 || sperre==0) {	// ... nur wenn Sperre ignorieren oder Sperre=0
						send=1;
						cyclic=1;
					}
				}
			}

			if (send) {
				if (objno>1) write_obj_value(objno,delay_state);		// Wert ins userram schreiben
				send_obj_value(objno);			// Telegramm senden

			}

			// wenn delay zur Verzögerung aktiv war, dann Verzögerungs-Bit löschen
			if(delrec[delrecno].delayactive & 0x04) delrec[delrecno].delayactive-=4;

			if (cyclic) {
				cycle_param=eeprom[ctrl_adr[objno]+1]&0x0F;	// Zyklus-Adresse jeweils ein Byte über ctrl_adr
				delrec[delrecno].delayvalue=timer+cycleval[cycle_param];
			}
			// wenn nicht zyklisch gesendet werden soll den timer inaktiv setzen
			else delrec[delrecno].delayactive=0;

		}
	}
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{

	unsigned char objno, bitmask, ctrl;

	PT0AD=0xF0; 		// disable digital inputs P0.1 ... P0.5
	P0= 0xBF;			// P0.0 push-pull for charging the capacitor, P0.6 push-pull status-LED
	P0M1= 0x22;			// others bidirectional,
	P0M2= 0x41;			// P0_5 & P0_1 high impedance for adc inputs

	lux=65535;
	temp=-1000;
	lastlux=lux;
	lasttemp=temp;

	overrun=0;
	underrun=0;

	timer=0;
	sequence=1;

	// in lockatt bit setzen für jedes Objekt, das Sperre beachten muss
	lockatt=0;
	bitmask=1;
	for (objno=3; objno<=9; objno++) {
		ctrl=eeprom[ctrl_adr[objno]];
		if (ctrl & 0x08) lockatt|=bitmask;
		bitmask=bitmask<<1;
	}

	//write_obj_value(10,0);		// Sperre bei Neustart löschen
	global_object_value_3_to_10 &= 0x7F;

  	for (objno=2;objno<9;objno++) WRITE_DELAY_RECORD(objno,0,0,0)			// erstmal alle delay-records auf inaktiv setzen
  	if ((eeprom[0xD3]&0x0F)!=0) {
  		WRITE_DELAY_RECORD(0,1,1,timer+50)
  	}
  	if ((eeprom[0xD2]&0x0F)!=0) {
  		WRITE_DELAY_RECORD(1,1,1,timer+55)
  	}

  	EA=0;
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
	START_WRITECYCLE;
	WRITE_BYTE(0x00,0x60,0x2E);	// system state: all layers active (run), not in prog mode
	STOP_WRITECYCLE;
	EA=1;
}
