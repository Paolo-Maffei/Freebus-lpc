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
 */

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_delay.h"
#include "fb_app_taster.h"


long timer;					// Timer f�r Schaltverz�gerungen, wird alle 130us hochgez�hlt
bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszuf�hren

unsigned char button_buffer;	// puffer f�r taster werte


void port_changed(unsigned char portval)		// ein oder mehrere Taster wurden gedr�ckt oder losgelassen
{
	unsigned char n, buttonpattern;
	
	set_timer0(50000);			// Entprellzeit
	WAIT_FOR_TIMER0				// warten auf Timer 0
	if ((PORT & 0x0F) == portval) {
		for (n=0; n<4; n++) {	// alle 4 Taster einzeln pr�fen (k�nnten ja mehrere gleichzeitig gedr�ckt worden sein)
			buttonpattern=1<<n;
			if ((portval & buttonpattern) && !(button_buffer & buttonpattern)) button_changed(n,0);	// Taster losgelassen
			if (!(portval & buttonpattern) && (button_buffer & buttonpattern)) button_changed(n,1);	// Taster gedr�ckt
		}
		button_buffer=portval;	// aktuellen port wert in buffer f�r n�chsten Vergleich �bernehmen
	}
}



void button_changed(unsigned char buttonno, bit buttonval)	// Taster ge�ndert
{
	unsigned char command;
	bit objval=0;
	
	switch ((eeprom[FUNCTION+(buttonno>>1)] >> ((buttonno & 0x01)*4)) & 0x0F) {		// Funktion des Tasters
	case 1:		// Schalten
		if (buttonval) command = (((eeprom[COMMAND+(buttonno*4)]) >> 6) & 0x03);	// Befehl beim dr�cken
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
			write_obj_value(buttonno, objval);	// Objektwert im USERRAM speichern
			switch_led(buttonno, objval);		// LED schalten
		}		
	}
}




void write_value_req(void)				// Ausg�nge schalten gem�� EIS 1 Protokoll (an/aus)
{
	unsigned char objno,objflags,gapos,atp,assno,n,gaposh;

	gapos=gapos_in_gat(telegramm[3],telegramm[4]);
	if (gapos!=0xFF)	
	{
		send_ack();
	    atp=eeprom[ASSOCTABPTR];		// Association Table Pointer
	    assno=eeprom[atp];				// Erster Eintrag = Anzahl Eintr�ge
	 
	    for(n=0;n<assno;n++) {				// Schleife �ber alle Eintr�ge in der Ass-Table, denn es k�nnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
	    	gaposh=eeprom[atp+1+(n*2)];
	    	if(gapos==gaposh) {					// Wenn Positionsnummer �bereinstimmt
	    		objno=eeprom[atp+2+(n*2)];			// Objektnummer
	    		objflags=read_objflags(objno);		// Objekt Flags lesen
	    		if((objflags&0x14)==0x14) {			// Kommunikation zul�ssig (Bit 2 = communication enable) + Schreiben zul�ssig (Bit 4 = write enable)
	    			if (objno<4) {					// Status der Eingangsobjekte 0-3
	    				write_obj_value(objno,telegramm[7]&0x01);
	    				switch_led(objno,telegramm[7]&0x01);
	    			}
	    		}
	    	}
	    }
	}
}


void switch_led(unsigned char ledno, bit onoff)	// LEDs schalten
{
	unsigned char command;
	
	if (ledno<4) {
		command = ((eeprom[COMMAND+(ledno*4)]) & 0x07);	// Befehl der Status LED
		switch (command) {
		case 3:		// LED = invertierte Statusanzeige
			onoff=!onoff;
			break;
		case 4:		// LED = Bet�tigungsanzeige
			onoff=1;
			switch (eeprom[DURATION]) {
			case 38:	// 0,75 sec
				write_delay_record(ledno, 0x80, timer+6);
				break;
			case 118:	// 2,25 sec
				write_delay_record(ledno, 0x80, timer+17);
				break;
			case 150:	// 3 sec
				write_delay_record(ledno, 0x80, timer+23);
			}
		}
		PORT &= ~(1<<(ledno+4));	// LEDs sind an Pin 4-7
		PORT |= onoff<<(ledno+4);
	}
}


void send_eis(unsigned char eistyp, unsigned char objno, int sval)	// sucht Gruppenadresse f�r das Objekt objno und sendet ein EIS Telegramm
{														// mit dem Wert sval+0x80
  int ga;
  
  ga=find_ga(objno);					// wenn keine Gruppenadresse hintrlegt nix tun
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
    	telegramm[7]=sval+0x80;
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
  }
}  


void delay_timer(void)	// z�hlt alle 130ms die Variable Timer hoch und pr�ft Queue
{
	unsigned char objno, delay_state;
	long delval;

	delay_toggle=!delay_toggle;
	RTCCON=0x60;		// RTC anhalten und Flag l�schen
	RTCH=0x0E;			// reload Real Time Clock
	RTCL=0xA0;
	if (delay_toggle) {
		timer++;
		if (timer==0x01000000) timer=0;	// nur 3 Byte aktiv
		for(objno=0;objno<=4;objno++) {
			delay_state=delrec[objno*4];
			if(delay_state!=0x00) {			// 0x00 = delay Eintrag ist leer   
				delval=delrec[objno*4+1];
				delval=(delval<<8)+delrec[objno*4+2];
				delval=(delval<<8)+delrec[objno*4+3];
				if(delval==timer) {
					switch_led(objno,(delay_state & 0x01));	// LED aus bei Bet�tigungsanzeige
				}
			}
		}
	}
	RTCCON=0x61;		// RTC starten
}








void restart_app(void)		// Alle Applikations-Parameter zur�cksetzen und Empfang sterten
{

	set_port_mode_bidirectional(0);		// Pin 0-3 f�r Taster
	set_port_mode_bidirectional(1);
	set_port_mode_bidirectional(2);
	set_port_mode_bidirectional(3);
	set_port_mode_pushpull(4);			// Pin 4-7 f�r LEDs
	set_port_mode_pushpull(5);
	set_port_mode_pushpull(6);
	set_port_mode_pushpull(7);
	PORT=0x0F;							// Taster auf high, LEDs aus
	
	button_buffer=0x0F;	// Variable f�r letzten abgearbeiteten Taster Status
	
	timer=0;			// Timer-Variable, wird alle 130ms inkrementiert
	delay_toggle=0;		// timer_toggle sorgt daf�r, da� der 65ms rtc nur jedes 2.mal timer inkrementiert
  
	start_writecycle();
	write_byte(0x01,0x03,0x00);	// Herstellercode 0x0004 = Jung
	write_byte(0x01,0x04,0x04);
	write_byte(0x01,0x05,0x10);	// Devicetype 0x1052 = Jung Tastsensor 2092
	write_byte(0x01,0x06,0x52);	
	write_byte(0x01,0x07,0x01);	// Versionsnummer
	write_byte(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
	write_byte(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
	write_byte(0x01,0x12,0x9A);	// COMMSTAB Pointer
	stop_writecycle();
	
	RECEIVE_INT_ENABLE=1;		// Empfangs-Interrupt freigeben
	
	write_obj_value(0,0);		// Taster Objektwerte alle auf 0 setzen
	write_obj_value(1,0);
	write_obj_value(2,0);
	write_obj_value(3,0);
}