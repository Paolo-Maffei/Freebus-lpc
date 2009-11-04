/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2009
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 * 
 *
 *
 *
 */



#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_delay.h"
#include "fb_app_2te_kombi.h"
#include "../com/fb_rs232.h"

/******
 * Ein
 *****/

unsigned char button_buffer; 	// Puffer fuer Taster Werte



/*****
 * Aus
 *****/

unsigned char portbuffer;		// Zwischenspeicherung der Portzustände
unsigned char zfstate;			// Zustand der Objekte 8-11 = Zusatzfunktionen 1-4
unsigned char blocked;			// Sperrung der 8 Ausgänge (1=gesperrt)
unsigned char logicstate;		// Zustand der Verknüpfungen pro Ausgang
long timer;						// Timer für Schaltverzögerungen, wird alle 130us hochgezählt
bit delay_toggle;				// um nur jedes 2. Mal die delay routine auszuführen
unsigned char owntele;			// Anzahl der internen Verarbeitungen eines gesendeten Telegrammes (Rückmeldung)
unsigned char respondpattern;	// bit wird auf 1 gesetzt wenn objekt eine rückmeldung ausgelöst hat
bit portchanged;


/*****************
 * Eingänge
 *****************/

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
	while (!TF0);				// warten auf Timer 0
	if ((PORT & 0x03) == portval) {
		for (n=0; n<2; n++) {	// alle 2 Eingänge einzeln pruefen (koennten ja mehrere gleichzeitig gedrueckt worden sein)
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

	switch ((eeprom[FUNCTION] >> ((buttonno & 0x01)*4)) & 0x03) {		// Funktion des Tasters


	/*********************
	 * Funktion Schalten
	 *********************/
	case 1:

		if (eeprom[0xF4] & 0x01)  // direkt Schaltem E1->A1  E2->A2
		{
			if (buttonval) command = (((eeprom[COMMAND+(buttonno*4)]) >> 2) & 0x03);	// Befehl beim druecken
			else command = ((eeprom[COMMAND+(buttonno*4)]) & 0x03);				// Befehl beim loslassen

			switch (command) {	// Befehl des Tasters
			case 1:		// EIN
				objval=1;
//				PORT |= (1<<(buttonno + 2));
				break;
			case 2:		// AUS
				objval=0;
//				PORT &= ~(1<<(buttonno + 2));
				break;
			case 3:		// UM
				objval = read_obj_value(buttonno);
				objval = !objval;
//				PORT ^= (1<<(buttonno + 2));
				break;
			}

			if (command) {	// nur wenn EIN, UM oder AUS (0=keine Funktion)
				object_schalten(buttonno,objval);
			}
		}

		else {  //Schalten auf Bus Telegramm senden

			/****************
			 * erstes Objekt
			 ***************/
			if (buttonval) command = (((eeprom[COMMAND+(buttonno*4)]) >> 2) & 0x03);	// Befehl beim druecken
			else command = ((eeprom[COMMAND+(buttonno*4)]) & 0x03);				// Befehl beim loslassen

			switch (command) {	// Befehl des Tasters
			case 1:		// EIN
				objval=1;
				break;
			case 2:		// AUS
				objval=0;
				break;
			case 3:		// UM
				objval = read_obj_value(buttonno+2);
				objval = !objval;
				break;
			}

			if (command) {	// nur wenn EIN, UM oder AUS (0=keine Funktion)
				send_eis(1,(buttonno + 2),objval);		// EIS 1 Telegramm senden
			}

			/******************
			 *  zweites Objekt
			 ******************/
			if (buttonval) command = (((eeprom[COMMAND+(buttonno*4)]) >> 6) & 0x03);	// Befehl beim druecken
			else command = (((eeprom[COMMAND+(buttonno*4)]) >> 4) & 0x03);				// Befehl beim loslassen

			switch (command) {	// Befehl des Tasters
			case 1:		// EIN
				objval=1;
//				PORT |= (1<<(buttonno + 2));
				break;
			case 2:		// AUS
				objval=0;
//				PORT &= ~(1<<(buttonno + 2));
				break;
			case 3:		// UM
				objval = read_obj_value(buttonno + 10);
				objval = !objval;
//				PORT ^= (1<<(buttonno + 2));
				break;
			}

			if (command) {	// nur wenn EIN, UM oder AUS (0=keine Funktion)
				send_eis(1,(buttonno + 10),objval);		// EIS 1 Telegramm senden
			}

		}

		break;  //Schalten Ende

		/****************************
		 * Funktion Jalousie
		 ****************************/
/*		case 3:
			if (buttonval) {	// Taster gedrueckt -> schauen wie lange gehalten
				send_eis(1, buttonno, ((eeprom[0xD3+(buttonno*4)]&0x10)>>4));	// Kurzzeit telegramm immer bei Drücken senden
				duration=eeprom[0xD5+(buttonno*4)];	// Faktor Dauer
				switch (eeprom[0xDF+(buttonno*4)]&0x06) { // Basis Dauer zwischen kurz und langzeit Lamellenverstellzeit angepasst
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
			// Jalousie Ende
*/
	}  // switch Ende

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



/******************
 * Ausgänge
 ******************/


void object_schalten(unsigned char objno, bit objstate)	// Schaltet einen Ausgang gemäß objstate und den zugörigen Parametern
{

	unsigned char port_pattern,objflags,delay_base,delay_state,delay_zeit,logicfunc,zfno;
	unsigned long delay_target,delay_onoff;
	bit off_disable;



	off_disable=((eeprom[OFFDISABLE]>>objno)&0x01);	// nur ausschalten wenn AUS-Tete nicht ignoriert werden soll
	if ((!objstate && !off_disable) || objstate) {
		if (objstate)
		{
//			rs_send(objno);
//			rs_send(read_obj_value(objno));
			write_obj_value(objno,1);		// Objektwert im userram speichern
//			rs_send(read_obj_value(objno));
		}
		else {
//			rs_send(objno);
//			rs_send(read_obj_value(objno));
			write_obj_value(objno,0);
//			rs_send(read_obj_value(objno));
		}

		objflags=read_objflags(objno);			// Objekt Flags lesen
		port_pattern=0x01<<objno;
		zfno=0;
		logicfunc=0;
//		if((eeprom[FUNCASS]&0x0F)==(objno+1)) zfno=1;
//		if(((eeprom[FUNCASS]&0xF0)>>4)==(objno+1)) zfno=2;
//		if((eeprom[FUNCASS+1]&0x0F)==(objno+1)) zfno=3;
//		if(((eeprom[FUNCASS+1]&0xF0)>>4)==(objno+1)) zfno=4;
//		if(zfno) {
//			if(((eeprom[FUNCTYP]>>((zfno-1)*2))&0x03)==0x00) logicfunc=((eeprom[LOGICTYP]>>((zfno-1)*2))&0x03);
//		}

		if((port_pattern & blocked)==0 && (objflags&0x14)==0x14) {	// Objekt ist nicht gesperrt und Kommunikation zulässig (Bit 2 = communication enable) und Schreiben zulässig (Bit 4 = write enable)
			delay_base=eeprom[(((objno+1)>>1)+DELAYTAB)];  //DELAYTAB angepasst
			if((objno&0x01)==0x01) delay_base&=0x0F;
			else delay_base=(delay_base&0xF0)>>4;
			delay_target=0;
			delay_onoff=0;
			delay_state=0;

			delay_zeit=eeprom[0xE9];  //ZeitSCHALTfunktion angepasst
			delay_zeit=((delay_zeit>>objno)&0x01);

			// Ausschalten
//			if ( (objstate==0 && (logicfunc==0 || (logicfunc==1 && ((logicstate>>objno)&0x01)==0x00) || logicfunc>=2))
//					|| (objstate==1 && (logicfunc>=2 && ((logicstate>>objno)&0x01)==0x00)) )

			if (objstate==0)
			{
			delay_onoff=((eeprom[objno+0xE7]) & 0x7F);  //Zeitfaktor Auschaltverzögerung angepasst (bit 0-6)

				if(delay_onoff==0x00 || delay_zeit==0x01) {		// sofort ausschalten
					if (((eeprom[RELMODE]>>objno)&0x01)==0x00) portbuffer=portbuffer&~port_pattern;	// Schliesserbetrieb RELMODE angepasst
					else portbuffer=portbuffer|port_pattern;						// Öffnerbetrieb

					respond(objno+16,0x80);  //Rückmeldeobjekt angepasst
				}
				else delay_state=0x80;				// verzögert ausschalten
			}


			// Einschalten
//			if ( (objstate==1 && (logicfunc==0 || logicfunc==1 || (logicfunc>=2 && ((logicstate>>objno)&0x01)==0x01)))
//					|| (objstate==0 && (logicfunc==1 && ((logicstate>>objno)&0x01)==0x01)) )


			if (objstate==1)
			{
				delay_onoff=((eeprom[objno+0xE5]) & 0x7F);  //Zeitfaktor Einschaltverzögerung angepasst (bit 0-6)
				if(delay_onoff==0x00) {
					if(delay_zeit==0x01) { 			// Zeitschaltfunktion
						delay_state=0x80;
						delay_onoff=((eeprom[objno+0xE7]) & 0x7F);  //Zeitfaktor Auschaltverzögerung angepasst (bit 0-6)
					}
					if (((eeprom[RELMODE]>>objno)&0x01)==0x00) portbuffer=portbuffer|port_pattern;	// sofort einschalten (Schliesserbetrieb) RELMODE angepasst
					else portbuffer=portbuffer&~port_pattern;					// sofort einschalten (Öffnerbetrieb)

					respond(objno+16,0x81);  //Rückmeldeobjekt angepasst
				}
				else delay_state=0x81;				// verzögert einschalten
			}

			if(delay_state!=0) {				// wenn Verzögerung, dann timer-Wert ins Flash schreiben
				delay_target=(delay_onoff<<delay_base)+timer;
				write_delay_record(objno,delay_state,delay_target);
			}
			else clear_delay_record(objno);
		}
	}
}


void delay_timer(void)	// zählt alle 130ms die Variable Timer hoch und prüft Queue
{
	unsigned char objno,delay_state,port_pattern,delay_zeit,delay_onoff,delay_base;
	unsigned long delval,delay_target;
//	bit portchanged; (nicht mehr lokal...)

	RTCCON=0x60;		// RTC anhalten und Flag löschen
	RTCH=0x0E;			// reload Real Time Clock
	RTCL=0xA0;
	objno=0;

	if (delay_toggle) {	// RTC läuft auf 65ms, daher nur jedes 2. mal timer erhöhen
		timer++;
		if (timer==0x01000000) timer=0;	// nur 3 Byte aktiv
		for(objno=0;objno<=1;objno++) {  //nur zwei Objekte Relais angepasst
			delay_state=delrec[objno*4];
			if(delay_state!=0x00) {			// 0x00 = delay Eintrag ist leer
				delval=delrec[objno*4+1];
				delval=(delval<<8)+delrec[objno*4+2];
				delval=(delval<<8)+delrec[objno*4+3];
				if(delval==timer) {
					portchanged=1;
					port_pattern=0x01<<objno;
					if(delay_state==0x81) {	// einschalten
						if (((eeprom[RELMODE]>>objno)&0x01)==0x00) { //RELMODE angepasst
							portbuffer=portbuffer|port_pattern;		// Einschalten (Schliesserbetrieb)
						}
						else {
							portbuffer=portbuffer&~port_pattern;	// Einschalten (Öffnerbetrieb)
						}
						EX1=0;
						respond(objno+16,0x81);			// ggf. Rückmeldung angepasst
						EX1=1;
						delrec[objno*4]=0;
						delay_zeit=eeprom[0xE9];  //Zeitschaltfunktion angepasst
						delay_zeit=((delay_zeit>>objno)&0x01);
						if(delay_zeit==0x01) {
							delay_base=eeprom[(((objno+1)>>1)+0xF6)];  //Zeitbasis angepasst
							if((objno&0x01)==0x01) delay_base&=0x0F;
							else delay_base=(delay_base&0xF0)>>4;
							delay_onoff=eeprom[objno+0xE7];  //Ausschaltverzögerung angepasst
							if (delay_onoff!=0x00 && delay_zeit!=0x00) {
								delay_target=(delay_onoff<<delay_base)+timer;
								write_delay_record(objno,0x80,delay_target);		// Schaltverzögerung in Flash schreiben
							}
						}
					}
					else {	// ausschalten
						if (((eeprom[RELMODE]>>objno)&0x01)==0x00) {  //RELMODE angepasst
							portbuffer=portbuffer&~port_pattern;		// Ausschalten (Schliesserbetrieb)
						}
						else {
							portbuffer=portbuffer|port_pattern;			// Ausschalten (Öffnerbetrieb)
						}
						EX1=0;
						respond(objno+16,0x80);				// ggf. Rückmeldung angepasst
						EX1=1;
						delrec[objno*4]=0;
					}
				}
			}
		}
	}

//	if (portchanged) port_schalten(portbuffer);				// Ausgänge schalten
	RTCCON=0x61;		// RTC starten
	delay_toggle=!delay_toggle;
}



void port_schalten(unsigned char ports)		// Schaltet die Ports mit PWM, DUTY ist Pulsverhältnis
{
/*	if(ports & ~((userram[0x29]>>2) & 0x03)) {}	// Vollstrom nur wenn ein relais eingeschaltet wird
		TR0=0;
		AUXR1&=0xE9;	// PWM von Timer 0 nicht mehr auf Pin ausgeben
		PWM=1;			// Vollstrom an
		P0=ports;		// Ports schalten
		TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
		TH0=0x00;		// 16ms (10ms=6fff)
		TL0=0x00;
		TMOD=0x11;		// Timer 0 als 16-Bit Timer, Timer 1 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;

	}
	else P0=ports;

*/
	P0_2=(ports & 0x01);
	P0_3=((ports >> 1) & 0x01);


	START_WRITECYCLE
	WRITE_BYTE(0x00,0x29,P0)
	STOP_WRITECYCLE
	portchanged=0;


}




void respond(unsigned char objno, unsigned char rval)	// sucht Gruppenadresse für das Objekt objno uns sendet ein EIS 1 Telegramm
{							// mit dem Wert rval (0x80 oder 0x81) für Rückmeldeobjekte
	unsigned int ga;
	unsigned char inv;

	if ((owntele < 3) && ((respondpattern & (1<<(objno-16))) == 0)) {  //Objektnummer angepasst
		respondpattern |= (1<<(objno-16)); //Objektnummern angepasst
		owntele++;
		ga=find_ga(objno);					// wenn keine Gruppenadresse hinterlegt nix tun
		if (ga!=0) {
			//EX1=0;
			telegramm[0]=0xBC;
			telegramm[1]=eeprom[ADDRTAB+1];
			telegramm[2]=eeprom[ADDRTAB+2];
			telegramm[3]=ga>>8;
			telegramm[4]=ga;
			telegramm[5]=0xD1;
			telegramm[6]=0x00;
			objno=objno-16;  //Objektnummer angepasst
			inv=eeprom[0xF1];  //Verhalten Rückmeldung angepasst
			inv=(inv>>objno)&0x01;
			if (inv==0) telegramm[7]=rval;
			if (inv==1) {
				if (rval==0x80) telegramm[7]=0x81;
				else telegramm[7]=0x80;
			}
			send_telegramm();
			//EX1=1;
			write_value_req();
		}
	}

}



void write_value_req(void)	// Empfangenes write_value_request Telegramm verarbeiten
{
	  unsigned char objno,objflags,gapos,atp,assno,n,gaposh,zfout,zftyp;
	  unsigned char blockstart,blockend;

	    gaposh=0;

	    gapos=gapos_in_gat(telegramm[3],telegramm[4]);	// Position der Gruppenadresse in der Adresstabelle
	    if (gapos!=0xFF)					// =0xFF falls nicht vorhanden
	    {
		  if ((telegramm[1] != eeprom[ADDRTAB+1]) || (telegramm[2] != eeprom[ADDRTAB+2])) {
			  send_ack();
		  }
		  atp=eeprom[ASSOCTABPTR];			// Start Association Table
	      assno=eeprom[atp];				// Erster Eintrag = Anzahl Einträge

	      for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
	      {
	        gaposh=eeprom[atp+1+(n*2)];
	        if(gapos==gaposh)					// Wenn Positionsnummer übereinstimmt
	        {
	          objno=eeprom[atp+2+(n*2)];				// Objektnummer
	          objflags=read_objflags(objno);			// Objekt Flags lesen

	          if (objno<2) object_schalten(objno,telegramm[7]&0x01);	// Objektnummer 0-1 entspricht den Ausgängen 1-2 angepasst



/*	          if (objno>7 && objno<12)	// Objektnummer 8-11 entspricht den Zusatzfunktionen 1-4
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
	                blockstart=eeprom[BLOCKACT]&0x03;		// Verhalten bei Beginn der Sperrung
	                blockend=(eeprom[BLOCKACT]>>2)&0x03;	// Verhalten bei Ende der Sperrung
	              break;
	              case 0x01:
	                zfout=(eeprom[FUNCASS]&0xF0)>>4;
	                blockstart=(eeprom[BLOCKACT]>>4)&0x03;	// Verhalten bei Beginn der Sperrung
	                blockend=(eeprom[BLOCKACT]>>6)&0x03;	// Verhalten bei Ende der Sperrung
	              break;
	              case 0x02:
	                zfout=eeprom[FUNCASS+1]&0x0F;
	                blockstart=eeprom[BLOCKACT+1]&0x03;		// Verhalten bei Beginn der Sperrung
	                blockend=(eeprom[BLOCKACT+1]>>2)&0x03;	// Verhalten bei Ende der Sperrung
	              break;
	              case 0x03:
	                zfout=(eeprom[FUNCASS+1]&0xF0)>>4;
	                blockstart=(eeprom[BLOCKACT+1]>>4)&0x03;	// Verhalten bei Beginn der Sperrung
	                blockend=(eeprom[BLOCKACT+1]>>6)&0x03;		// Verhalten bei Ende der Sperrung
	            }
	            zftyp=((eeprom[FUNCTYP])>>((objno-8)*2)) & 0x03;	// Typ der Zusatzfunktion

	            switch (zftyp)
	            {
	              case 0x00:			// Verknüpfung
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
	                if (((telegramm[7]==0x80) && ((eeprom[BLOCKPOL]&(1<<(objno-8)))==0)) ||
	                	((telegramm[7]==0x81) && ((eeprom[BLOCKPOL]&(1<<(objno-8)))!=0)))
	                {	// Ende der Sperrung
	                    blocked=blocked&(0xFF-(0x01<<(zfout-1)));
	                    if (blockend==0x01) portbuffer=portbuffer&(0xFF-(0x01<<(zfout-1)));	// Bei Ende der Sperrung ausschalten
	                    if (blockend==0x02) portbuffer=portbuffer|(0x01<<(zfout-1));		// Bei Ende der Sperrung einschalten
	                }

	                if (((telegramm[7]==0x81) && ((eeprom[BLOCKPOL]&(1<<(objno-8)))==0)) ||
	                	((telegramm[7]==0x80) && ((eeprom[BLOCKPOL]&(1<<(objno-8)))!=0)))
	                {	// Beginn der Sperrung

	                    blocked=blocked|(0x01<<(zfout-1));
	                    if (blockstart==0x01) portbuffer=portbuffer&(0xFF-(0x01<<(zfout-1)));	// Bei Beginn der Sperrung ausschalten
	                    if (blockstart==0x02) portbuffer=portbuffer|(0x01<<(zfout-1));		// Bei Beginn der Sperrung einschalten
	                    delrec[(zfout-1)*4]=0;	// ggf. Eintrag für Schaltverzögerung löschen
	                }
	              //port_schalten(portbuffer);
	              break;
	              //case 0x02:			// Zwangsstellung
	            }
	          }

*/

	        }
	      }
	      if (portbuffer != ((userram[0x29] >> 2) & 0x03)) portchanged=1;//post für port_schalten hinterlegen
	      //port_schalten(portbuffer);	//Port schalten wenn sich ein Pin geändert hat
	    }
	    owntele=0;
	    respondpattern=0;

}



void read_value_req(void)	// Empfangenes read_value_request Telegramm verarbeiten
{
	unsigned char objno, objflags;
	unsigned int objvalue;

	objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
	if(objno!=0xFF) {	// falls Gruppenadresse nicht gefunden
		send_ack();

		objvalue=read_obj_value(objno);		// Objektwert aus USER-RAM lesen (Standard Einstellung)

		objflags=read_objflags(objno);		// Objekt Flags lesen
		// Objekt lesen, nur wenn read enable gesetzt (Bit3) und Kommunikation zulaessig (Bit2)
		if((objflags&0x0C)==0x0C) send_value(0,objno,objvalue);
    }

}

void send_value(unsigned char type, unsigned char objno, unsigned int sval)	// sucht Gruppenadresse für das Objekt objno uns sendet ein EIS Telegramm
{																	// mit dem Wert sval
  unsigned int ga;
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


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{

	
	// ***************************************
	//  hier Port und Sonstiges konfigurieren
	// ***************************************	
	unsigned char n;
	bit write_ok=0;

	// Pin 0-1 fuer Taster
	for (n=0;n<2;n++) {
		SET_PORT_MODE_BIDIRECTIONAL(n)
	}

	// Pin 2-3 fuer Ausgänge
	for (n=2;n<4;n++) {
		SET_PORT_MODE_PUSHPULL(n)
	}

	PORT=0x03;							// Taster auf high, Ausgänge zunächst aus

	button_buffer=0x03;	// Variable für letzten abgearbeiteten Taster Status

	stop_rtc();
	start_rtc(8);		// RTC neu mit 8ms starten
	timer=0;			// Timer-Variable, wird alle 8ms inkrementiert
	
	
	// mögliche Bit-Variablen:
	// transparency=1;	// Telegramme werden nicht vom Protokoll-Layer abgearbeitet, default 0

	
	// Beispiel für die Applikations-spezifischen Einträge im eeprom
	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	START_WRITECYCLE
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
	WRITE_BYTE(0x01,0x04,0x04)
	WRITE_BYTE(0x01,0x05,0x20)	// Devicetype 0x2071 = Jung Schaltaktor 2fach 6A UP
	WRITE_BYTE(0x01,0x06,0x71)
	WRITE_BYTE(0x01,0x07,0x01)	// Versionnumber of application programm
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0x84)	// COMMSTAB Pointer
	STOP_WRITECYCLE
	START_WRITECYCLE;
	WRITE_BYTE(0x00,0x60,0x2E);	// system state: all layers active (run), not in prog mode
	STOP_WRITECYCLE;
	EA=1;						// Interrupts freigeben

	for (n=0;n<12;n++) write_obj_value(n,0);		// Objektwerte alle auf 0 setzen


}
