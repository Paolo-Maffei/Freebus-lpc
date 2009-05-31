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
 *http://de.wikibooks.org/wiki/C%2B%2B-Programmierung:_Dokumentation_mit_Doxygen
 * http://studiwiki.informatik.uni-stuttgart.de/Softwaretechnik/Studienprojekte/Beispiel_Styleguide
 *http://www.stack.nl/~dimitri/doxygen/commands.html
 */
/**
* @file   fb_app_taster.c
* @author Andreas Krebs <kubi@krebsworld.de>
* @date    2008
* 
* @brief Applikation Taster, siehe fb_tester.c 
* 
* 
*/

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_delay.h"
//#include "../com/fb_rs232.h"
#include "fb_app_taster.h"


long timer; /// Timer fuer Schaltverzoegerungen, wird alle 130us hochgezaehlt
bit delay_toggle; /// um nur jedes 2. Mal die delay routine auszufuehren
long buttontimer[4];
unsigned char button_buffer; /// Puffer fuer Taster Werte



/** 
*  Ein oder mehrere Taster wurden gedrueckt oder losgelassen
*
* \param  portval <Beschreibung>
* @return void
*/
void port_changed(unsigned char portval)
{
	unsigned char n, buttonpattern;
	
	set_timer0(50000);			// Entprellzeit
	WAIT_FOR_TIMER0				// warten auf Timer 0
	if ((PORT & 0x0F) == portval) {
		for (n=0; n<4; n++) {	// alle 4 Taster einzeln pruefen (koennten ja mehrere gleichzeitig gedrueckt worden sein)
			buttonpattern=1<<n;
			if ((portval & buttonpattern) && !(button_buffer & buttonpattern)) button_changed(n,0);	// Taster losgelassen
			if (!(portval & buttonpattern) && (button_buffer & buttonpattern)) button_changed(n,1);	// Taster gedrueckt
		}
		button_buffer=portval;	// aktuellen port wert in buffer fuer naechsten Vergleich uebernehmen
	}
}



/** 
* Taster geaendert
*
* \param  buttonno <Beschreibung>
* \param  buttonval <Beschreibung>
*
* @return void
*/
void button_changed(unsigned char buttonno, bit buttonval)
{
	unsigned char command;
	bit objval=0;
	long duration=1;		// falls seitens ETS falsch programmiert 8ms default
	
	switch ((eeprom[FUNCTION+(buttonno>>1)] >> ((buttonno & 0x01)*4)) & 0x0F) {		// Funktion des Tasters
	
	
	/*********************
	 * Funktion Schalten
	 *********************/
	case 1:
		if (buttonval) command = (((eeprom[COMMAND+(buttonno*4)]) >> 6) & 0x03);	// Befehl beim druecken
		else command = (((eeprom[COMMAND+(buttonno*4)]) >> 4) & 0x03);				// Befehl beim loslassen

		switch (command) {	// Befehl des Tasters
		case 1:		// EIN
			objval=1;
			break;
		case 2:		// UM
			objval = read_obj_value(buttonno);
			objval = !objval;
			break;
		case 3:		// AUS
			objval=0;
		}

		if (command) {	// nur wenn EIN, UM oder AUS (0=keine Funktion)
			send_eis(1,buttonno,objval);		// EIS 1 Telegramm senden
			switch_led(buttonno, objval);		// LED schalten
		}
		break;
		
		
	/***********************
	 * Funktion Dimmen
	 ***********************/
	case 2:
		if (buttonval) {	// Taster gedrueckt -> schauen wie lange gehalten
			if ((eeprom[COMMAND+(buttonno*4)]) & 0x04) switch_led(buttonno,0);	// wenn Betuetigungsanzeige, dann gleich beim druecken einschalten
			duration=eeprom[0xD6+(buttonno*4)];	// Faktor Dauer			
			switch (eeprom[0xD5+(buttonno*4)]&0x30) { // Basis Dauer zwischen kurz und langzeit
			case 0:		// 130ms
				duration=duration<<4;
				break;			
			case 0x10:	// 260ms
				duration=duration<<5;
				break;
			case 0x20:	// 520ms
				duration=duration<<6;
				break;
			case 0x30:	// 1s
				duration=duration<<7;
			}
			duration+=timer;
			switch (eeprom[COMMAND+(buttonno*4)]&0x30) {
			case 0x10:	// zweiflï¿½chen heller
				write_delay_record(buttonno+4, ((eeprom[0xD4+(buttonno*4)]&0xF0)>>4)+0x40, duration);	// dimmen
				break;
			case 0x30:	// zweiflï¿½chen dunkler
				write_delay_record(buttonno+4, ((eeprom[0xD4+(buttonno*4)]&0x0F))+0x40, duration);	// dimmen
			}
		}
		else {		// Taster losgelassen
			if (delrec[(buttonno+4)*4]) {		// wenn delaytimer noch lauft, dann Schalten, also EIS1 telegramm senden
				switch (eeprom[COMMAND+(buttonno*4)]&0x30) {
				case 0x10:	// zweiflï¿½chen ein
					send_eis(1, buttonno, 1);
					switch_led(buttonno,1);
					break;
				case 0x30:	// zweiflï¿½chen aus
					send_eis(1, buttonno, 0);
					switch_led(buttonno,0);
				}
				clear_delay_record(buttonno+4);
			}
			else {	// Timer schon abgelaufen (also dimmen), dann beim loslassen stop-telegramm senden
				if ((eeprom[COMMAND+(buttonno*4)] & 0x40) == 0) {	// ... natuerlich nur wenn parameter dementsprechend (0=senden!!!)
					send_eis(2, buttonno+8, 0);		// Stop Telegramm
				}
				else write_obj_value(buttonno+8,0);	// auch wenn Stopp Telegramm nicht gesendet wird, Objektwert auf 0 setzen
			}
			
		}
		break;
		
		
	/****************************
	 * Funktion Jalousie
	 ****************************/
	case 3:
		if (buttonval) {	// Taster gedrueckt -> schauen wie lange gehalten
			send_eis(1, buttonno, ((eeprom[0xD3+(buttonno*4)]&0x10)>>4));	// Kurzzeit telegramm immer bei Drücken senden
			switch_led(buttonno,1);	// Status-LED schalten
			duration=eeprom[0xD5+(buttonno*4)];	// Faktor Dauer			
			switch (eeprom[0xD4+(buttonno*4)]&0x06) { // Basis Dauer zwischen kurz und langzeit
			case 2:	// 130ms
				duration=duration<<4;
				break;
			case 4:	// 2,2s
				duration=duration<<8;
				break;
			case 6:	// 33s
				duration=duration<<12;
			}
			duration+=timer;
			write_delay_record(buttonno+4, ((eeprom[0xD3+(buttonno*4)]&0x10)>>4)+0x80, duration);
		}
		else {	// Taster losgelassen
			if (delrec[(buttonno+4)*4] & 0x10) send_eis(1, buttonno, ((eeprom[0xD3+(buttonno*4)]&0x10)>>4));	// wenn delaytimer noch laueft und in T2 ist, dann kurzzeit telegramm senden
			else clear_delay_record(buttonno+4);	// T2 bereits abgelaufen
		}
	}
}



/** 
* Ausgaenge schalten gemaess EIS 1 Protokoll (an/aus)
*
* \param void
* @return void
*/
void write_value_req(void)
{
	unsigned char objno,objflags,gapos,atp,assno,n,gaposh;

	gapos=gapos_in_gat(telegramm[3],telegramm[4]);
	if (gapos!=0xFF)	
	{
		if ((telegramm[1] != eeprom[ADDRTAB+1]) || (telegramm[2] != eeprom[ADDRTAB+2])) send_ack();
	    atp=eeprom[ASSOCTABPTR];			// Association Table Pointer
	    assno=eeprom[atp];					// Erster Eintrag = Anzahl Eintraege
	 
	    for(n=0;n<assno;n++) {				// Schleife über alle Eintraege in der Ass-Table, denn es koennten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
	    	gaposh=eeprom[atp+1+(n*2)];
	    	if(gapos==gaposh) {					// Wenn Positionsnummer uebereinstimmt
	    		objno=eeprom[atp+2+(n*2)];			// Objektnummer
	    		objflags=read_objflags(objno);		// Objekt Flags lesen
	    		if((objflags&0x14)==0x14) {			// Kommunikation zulaessig (Bit 2 = communication enable) + Schreiben zulaessig (Bit 4 = write enable)
	    			if (objno<12) {					// max 12 objekte
	    				write_obj_value(objno,telegramm[7]);
	    				if ((objno<4) && ((eeprom[COMMAND+(objno*4)]) & 0x07) <4) switch_led(objno,telegramm[7]&0x01);	// LED nur schalten, wenn nicht auf Betï¿½tigungsanzeige parametriert
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



/** 
* LEDs schalten entsprechend der parametrierung
*
* \param  ledno <Beschreibung>
* \param  onoff <Beschreibung>
*
* @return void
*/
void switch_led(unsigned char ledno, bit onoff)
{
	unsigned char command;
	
	if (ledno<4) {
		command = ((eeprom[COMMAND+(ledno*4)]) & 0x07);	// Befehl der Status LED
		switch (command) {
		case 0:		// immer AUS
			onoff=0;
			break;
		case 1:		// immer an
			onoff=1;
			break;
		// case 2 ist Statusanzeige, onoff bleibt also unveraendert
		case 3:		// LED = invertierte Statusanzeige
			onoff=!onoff;
			break;
		case 4:		// LED = Betaetigungsanzeige
			onoff=1;	// erstmal an beim druecken der Taste
			switch (eeprom[LED_DURATION]) {		// dann ueber delay-timer aus
			case 38:	// 0,75 sec
				write_delay_record(ledno, 0x80, timer+94);
				break;
			case 118:	// 2,25 sec
				write_delay_record(ledno, 0x80, timer+281);
				break;
			case 150:	// 3 sec
				write_delay_record(ledno, 0x80, timer+375);
			}
		}
		PORT &= ~(1<<(ledno+4));	// LEDs sind an Pin 4-7
		PORT |= ((onoff<<(ledno+4)) | 0x0F);	// unteren 4 bits immer auf 1 lassen !!!
	}
}





/** 
* sucht Gruppenadresse fuer das Objekt objno und sendet ein EIS Telegramm
* mit dem Wert sval+0x80
*
* \param  eistyp <Beschreibung>
* \param  objno <Beschreibung>
* \param  sval <Beschreibung>
*
* @return void
*/
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
	write_value_req();				// eigenes Telegramm nochmal verarbeiten
  }
  else write_obj_value(objno, sval);	// Objektwert trotzdem im USERRAM speichern
}  


/** 
* zaehlt alle 8ms die Variable Timer hoch und prueft records
*
* \param void
* @return void
*/
void delay_timer(void)
{
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
				if (objno<4) {	// LED bei Betaetigungsanzeige nach eingestellter Zeit ausschalten
					PORT &= ~(1<<(objno+4));	// LEDs sind an Pin 4-7
					PORT |= 0x0F;				// unbedingt taster pins wieder auf 1 
				}
				else {	// delrec-Eintraege 4-7 sind die Abfragen wie lange Taster gedrueckt, bzw. wann er losgelassen wurde
					if (delay_state & 0x80) { // 0x80, 0x81 für langzeit telegramm senden
						send_eis(1, objno+4, delay_state & 0x01);	// Langzeit Telegramm senden
						// *** delay record neu laden für Dauer Lamellenverstellung ***
						duration=eeprom[DEL_FACTOR2+((objno-4)*4)];	// Faktor Dauer	T2		
						switch (eeprom[DEL_BASE+((objno-4)*4)]&0x60) { // Basis Dauer T2
						case 0x20:	// 130ms
							duration=duration<<4;
							break;
						case 0x40:	// 2,2s
							duration=duration<<8;
							break;
						case 0x60:	// 33s
							duration=duration<<12;
						}
						if (duration) {	// wenn keine lamellenverstellzeit dann nix tun
							duration+=timer;
							write_delay_record(objno, ((eeprom[COMMAND+((objno-4)*4)]&0x10)>>4)+0x10, duration); // 0x10,0x11 fuer ende T2 (lamellenvestellzeit)
						}
						else clear_delay_record(objno);
					}
					
					if (delay_state & 0x10) clear_delay_record(objno); // wenn T2 abgelaufen dann nichts mehr machen
					
					if (delay_state & 0x40) { // 0x4? fuer Dimmer Funktion
						send_eis(2, objno+4, delay_state);	// Langzeit Telegramm senden
						clear_delay_record(objno);
					}
				}
			}
		}
	}
	start_rtc(8);		// RTC neu starten mit 8ms
}


/** 
* Alle Applikations-Parameter zuruecksetzen und Empfang starten
* 
*
* \param void
* @return void
*/
void restart_app(void)
{
	unsigned char n;
	bit write_ok=0;
	
	// Pin 0-3 fuer Taster
	for (n=0;n<4;n++) {
		SET_PORT_MODE_BIDIRECTIONAL(n)
	}
	
	// Pin 4-7 fuer LEDs
	for (n=4;n<8;n++) {
		SET_PORT_MODE_PUSHPULL(n)
	}
	
	PORT=0x0F;							// Taster auf high, LEDs zunï¿½chst aus

	button_buffer=0x0F;	// Variable fï¿½r letzten abgearbeiteten Taster Status
	
	stop_rtc();
	start_rtc(8);		// RTC neu mit 8ms starten
	timer=0;			// Timer-Variable, wird alle 8ms inkrementiert

	// Applikations-spezifische eeprom Eintraege schreiben
	START_WRITECYCLE			
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
	WRITE_BYTE(0x01,0x04,0x04)
	WRITE_BYTE(0x01,0x05,0x10)	// Devicetype 0x1052 = Jung Tastsensor 2092
	WRITE_BYTE(0x01,0x06,0x52)	
	WRITE_BYTE(0x01,0x07,0x01)	// Versionsnummer
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0x9A)	// COMMSTAB Pointer
	STOP_WRITECYCLE

	for (n=0;n<12;n++) write_obj_value(n,0);		// Objektwerte alle auf 0 setzen

	for (n=0;n<8;n++) clear_delay_record(n);		// delay records loeschen
	
	for (n=0;n<4;n++) switch_led(n,0);	// Alle LEDs gemaess ihren Parametern setzen
	
	RECEIVE_INT_ENABLE=1;		// Empfangs-Interrupt freigeben	
	
	//rs_init();
}
