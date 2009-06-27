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
 * 09.11.08	- delay_timer geht nicht mehr über flash sondern über globale variable delrec
 * 			- delay_timer auf 24bit reduziert statt 32bit
 * 			- port_schalten nur noch eimal pro telegramm für alle pins
 * 			- interrupt-steuerung bei respond() rausgenommen
 * 			- globale variablen pah, pal, rmstate entfernt
 * 			- write_obj_value aufrufe rausgenommen
 * 
 * 23.11.08 - Soft PWM während der Vollstromphase
 * 			- Handbetätigung in delay_timer eingefügt (hierzu P1.3 nötig !)
 *  
 * 01.01.09	- Soft PWM rausgenommen
 * 			- write_obj_value wieder reingenommen mit Überprüfung ob INT unterbrochen hat
 * 			- Rückmeldung bei Busspannungswiederkehr funktioniert jetzt
 * 
 * 13.02.09	- owntele ist ein zähler, wie oft ein gesendetes telegramm intern erneut verarbeitet wurde
 */



#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_delay.h"
#include "fb_app_out.h"



unsigned char Tval;
unsigned char portbuffer;	// Zwischenspeicherung der Portzustände
unsigned char zfstate;		// Zustand der Objekte 8-11 = Zusatzfunktionen 1-4
unsigned char blocked;		// Sperrung der 8 Ausgänge (1=gesperrt)
unsigned char logicstate;	// Zustand der Verknüpfungen pro Ausgang
long timer;					// Timer für Schaltverzögerungen, wird alle 130us hochgezählt
bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszuführen
unsigned char owntele;		// Anzahl der internen Verarbeitungen eines gesendeten Telegrammes (Rückmeldung)
unsigned char respondpattern;	// bit wird auf 1 gesetzt wenn objekt eine rückmeldung ausgelöst hat




void write_value_req(void)				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
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
          
          if (objno<8) object_schalten(objno,telegramm[7]&0x01);	// Objektnummer 0-7 entspricht den Ausgängen 1-8

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
        }
      }
      if (portbuffer != userram[0x29])port_schalten(portbuffer);	//Port schalten wenn sich ein Pin geändert hat
    }
    owntele=0;
    respondpattern=0;
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
		if((objflags&0x0C)==0x0C) send_value(0,objno,objvalue);
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


void object_schalten(unsigned char objno, bit objstate)	// Schaltet einen Ausgang gemäß objstate und den zugörigen Parametern
{
	
	unsigned char port_pattern,objflags,delay_base,delay_state,delay_zeit,logicfunc,zfno;
	long delay_target,delay_onoff;
	bit off_disable;
    

	
	off_disable=((eeprom[OFFDISABLE]>>objno)&0x01);	// nur ausschalten wenn AUS-Tete nicht ignoriert werden soll
	if ((!objstate && !off_disable) || objstate) {
		if (objstate) write_obj_value(objno,1);		// Objektwert im userram speichern
		else write_obj_value(objno,0);
		objflags=read_objflags(objno);			// Objekt Flags lesen
		port_pattern=0x01<<objno;
		zfno=0;
		logicfunc=0;
		if((eeprom[FUNCASS]&0x0F)==(objno+1)) zfno=1;
		if(((eeprom[FUNCASS]&0xF0)>>4)==(objno+1)) zfno=2;
		if((eeprom[FUNCASS+1]&0x0F)==(objno+1)) zfno=3;
		if(((eeprom[FUNCASS+1]&0xF0)>>4)==(objno+1)) zfno=4;
		if(zfno) {
			if(((eeprom[FUNCTYP]>>((zfno-1)*2))&0x03)==0x00) logicfunc=((eeprom[LOGICTYP]>>((zfno-1)*2))&0x03);
		}
  
		if((port_pattern & blocked)==0 && (objflags&0x14)==0x14) {	// Objekt ist nicht gesperrt und Kommunikation zulässig (Bit 2 = communication enable) und Schreiben zulässig (Bit 4 = write enable)
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
				if(delay_onoff==0x00 || delay_zeit==0x01) {		// sofort ausschalten
					if (((eeprom[RELMODE]>>objno)&0x01)==0x00) portbuffer=portbuffer&~port_pattern;	// Schliesserbetrieb
					else portbuffer=portbuffer|port_pattern;						// Öffnerbetrieb
					respond(objno+12,0x80);
				}
				else delay_state=0x80;				// verzögert ausschalten
			}
                    
          			// Einschalten
			if ( (objstate==1 && (logicfunc==0 || logicfunc==1 || (logicfunc>=2 && ((logicstate>>objno)&0x01)==0x01))) 
					|| (objstate==0 && (logicfunc==1 && ((logicstate>>objno)&0x01)==0x01)) )
			{
				delay_onoff=eeprom[objno+0xDA];
				if(delay_onoff==0x00) {
					if(delay_zeit==0x01) { 			// Zeitschaltfunktion 
						delay_state=0x80;
						delay_onoff=eeprom[objno+0xE2];
					} 
					if (((eeprom[RELMODE]>>objno)&0x01)==0x00) portbuffer=portbuffer|port_pattern;	// sofort einschalten (Schliesserbetrieb)
					else portbuffer=portbuffer&~port_pattern;					// sofort einschalten (Öffnerbetrieb)
					respond(objno+12,0x81);
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
	long delval,delay_target;
	bit portchanged;
	
#ifdef HAND		// für Handbetätigung
	unsigned char n;
	unsigned char ledport;
	unsigned char Tasten=0;
#endif
	
	portchanged=0;
	RTCCON=0x60;		// RTC anhalten und Flag löschen
	RTCH=0x0E;			// reload Real Time Clock
	RTCL=0xA0;
	objno=0;

	if (delay_toggle) {	// RTC läuft auf 65ms, daher nur jedes 2. mal timer erhöhen
		timer++;
		if (timer==0x01000000) timer=0;	// nur 3 Byte aktiv
		for(objno=0;objno<=7;objno++) {
			delay_state=delrec[objno*4];
			if(delay_state!=0x00) {			// 0x00 = delay Eintrag ist leer   
				delval=delrec[objno*4+1];
				delval=(delval<<8)+delrec[objno*4+2];
				delval=(delval<<8)+delrec[objno*4+3];
				if(delval==timer) { 
					portchanged=1;
					port_pattern=0x01<<objno;
					if(delay_state==0x81) {	// einschalten
						if (((eeprom[RELMODE]>>objno)&0x01)==0x00) {				
							portbuffer=portbuffer|port_pattern;		// Einschalten (Schliesserbetrieb)
						}
						else {
							portbuffer=portbuffer&~port_pattern;	// Einschalten (Öffnerbetrieb)
						}
						EX1=0;
						respond(objno+12,0x81);			// ggf. Rückmeldung
						EX1=1;
						delrec[objno*4]=0;
						delay_zeit=eeprom[0xEA];
						delay_zeit=((delay_zeit>>objno)&0x01);
						if(delay_zeit==0x01) {
							delay_base=eeprom[(((objno+1)>>1)+0xF9)];   
							if((objno&0x01)==0x01) delay_base&=0x0F;
							else delay_base=(delay_base&0xF0)>>4;
							delay_onoff=eeprom[objno+0xE2];
							if (delay_onoff!=0x00 && delay_zeit!=0x00) {  
								delay_target=(delay_onoff<<delay_base)+timer;
								write_delay_record(objno,0x80,delay_target);		// Schaltverzögerung in Flash schreiben
							}
						}
					}
					else {	// ausschalten
						if (((eeprom[RELMODE]>>objno)&0x01)==0x00) {
							portbuffer=portbuffer&~port_pattern;		// Ausschalten (Schliesserbetrieb)
						}
						else {
							portbuffer=portbuffer|port_pattern;			// Ausschalten (Öffnerbetrieb)
						}
						EX1=0;
						respond(objno+12,0x80);				// ggf. Rückmeldung
						EX1=1;
						delrec[objno*4]=0;
					}
				}
			}   
		}
	}
#ifdef HAND		//+++++++   Handbetätigung  ++++++++++

	if(TMOD==0x12){
#ifdef GS1
		while( TMOD==0x12 && (PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen
	#endif
	#ifdef GS2
		while( TMOD==0x12 && (!PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen
	#endif
		interrupted=0;	  
		Tasten=0;				// 60 ist die Hälfte von C0(duty von kubi)
		P1_3= 1;			    //int0 auf 1 wird über Dioden und taster auf low IO gezogen.
		ledport=0x01;
		for (n=0;n<8;n++) {  						
			P0=~ledport;
		  	if (!P1_3){
		  		Tasten=Tasten|ledport;
		  		objno=n;
		  		n=7;
		  	}
		  	ledport=ledport<<1;
		} 
		if (interrupted==1) Tasten=Tval;  // wenn unterbrochen wurde verwerfen wir die Taste
		P0=userram[0x29]; 
		//	Tasten = Tval; // ##############  <----- Hier wird Handbetätigung quasi mit ausgeschaltet !! #########################
		if (Tasten != Tval)  {
			portbuffer=userram[0x29];
		  	ledport=Tasten&~Tval; // ledport ist hier die Hilfsvariable für steigende Flanke
		  	if (ledport){
		  		portbuffer^=ledport; // bei gedrückter Taste toggeln
		  		portchanged=1;
		  		EX1=0;
		  		if (((eeprom[RELMODE]>>objno)&0x01)==0x00) respond(objno+12,((portbuffer&ledport)>>objno)+0x80);		//  (Schliesserbetrieb)
		  		else respond(objno+12,0x81-((portbuffer&ledport)>>objno));	// (Öffnerbetrieb)
		  		EX1=1;
		  	}
		  	Tval=Tasten;			//neue Tasten sichern
		}
	}	
#endif

	
	if (portchanged) port_schalten(portbuffer);				// Ausgänge schalten
	RTCCON=0x61;		// RTC starten
	delay_toggle=!delay_toggle;
}


void port_schalten(unsigned char ports)		// Schaltet die Ports mit PWM, DUTY ist Pulsverhältnis
{
	if(ports & ~userram[0x29]) {	// Vollstrom nur wenn ein relais eingeschaltet wird
		TR0=0;
		AUXR1&=0xE9;	// PWM von Timer 0 nicht mehr auf Pin ausgeben
#ifdef GS1
		PWM=1;
#endif
#ifdef GS2
		PWM=0;			// Vollstrom an
#endif
		P0=ports;		// Ports schalten
		TF0=0;			// Timer 0 für Haltezeit Vollstrom verwenden
		TH0=0x00;		// 16ms (10ms=6fff)
		TL0=0x00;
		TMOD=0x11;		// Timer 0 als 16-Bit Timer, Timer 1 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;
	}
	else P0=ports;
	
  START_WRITECYCLE	
  WRITE_BYTE(0x00,0x29,ports)
  STOP_WRITECYCLE
}



void respond(unsigned char objno, unsigned char rval)	// sucht Gruppenadresse für das Objekt objno uns sendet ein EIS 1 Telegramm
{							// mit dem Wert rval (0x80 oder 0x81) für Rückmeldeobjekte	
	int ga;
	unsigned char inv;

	if ((owntele < 3) && ((respondpattern & (1<<(objno-12))) == 0)) {
		respondpattern |= (1<<(objno-12));
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
			objno=objno-12;
			inv=eeprom[0xF3];
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


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{
	unsigned char bw,bwh,n;
#ifdef HAND
	Tval=0x00;
#endif
	P0=0;
	P0M1=0x00;		// Port 0 Modus push-pull für Ausgang
	P0M2=0xFF;
  
	TMOD=0x12;		// Timer 0 als PWM, Timer 1 als 16-Bit Timer
	TAMOD=0x01;
	TH0=DUTY;		// Pulsverhältnis PWM
	AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
	ET0=0;			// Interrupt für Timer 0 sperren 
	TR0=1;			// Timer 0 starten (PWM)
 
	portbuffer=userram[0x29];	// Verhalten nach Busspannungs-Wiederkehr
	bw=eeprom[0xF6];
	for(n=0;n<=3;n++) {			// Ausgänge 1-4
		bwh=(bw>>(2*n))&0x03; 
		if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<n));
		if(bwh==0x02)  portbuffer=portbuffer | (0x01<<n);
	}
	
#ifdef MAX_PORTS_8
	bw=eeprom[0xF7];
	for(n=0;n<=3;n++) {			// Ausgänge 5-8
		bwh=(bw>>(2*n))&0x03; 
		if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<(n+4)));
		if(bwh==0x02)  portbuffer=portbuffer | (0x01<<(n+4));
	}
#endif
	START_WRITECYCLE
	// 0x29 auf 0 setzen, da sonst kein Vollstrom aktiviert wird
	WRITE_BYTE(0x00,0x29,0x00)		
	STOP_WRITECYCLE
	port_schalten(portbuffer);  
	
	EX1=0;							// Rückmeldung bei Busspannungswiederkehr
	for (n=0;n<8;n++) {
		owntele=1;
		respond(n+12,((portbuffer>>n) & 0x01)+0x80);
	}
	EX1=1;
	owntele=0;
	respondpattern=0;
  
	zfstate=0x00;		// Zustand der Zusatzfunktionen 1-4
	blocked=0x00;		// Ausgänge nicht gesperrt
	timer=0;			// Timer-Variable, wird alle 130ms inkrementiert
  
	logicstate=0;
	delay_toggle=0;
  
	START_WRITECYCLE
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
	WRITE_BYTE(0x01,0x04,0x04)
#ifdef MAX_PORTS_8				// 8-fach Aktor
	WRITE_BYTE(0x01,0x05,0x20)	// Devicetype 0x2060 = Jung Aktor 2138.10
	WRITE_BYTE(0x01,0x06,0x60)	
#endif
#ifdef MAX_PORTS_4				// 4-fach Aktor
	WRITE_BYTE(0x01,0x05,0x20)	// Devicetype 0x2062 = Jung Aktor 2134.16
	WRITE_BYTE(0x01,0x06,0x62)
#endif
	WRITE_BYTE(0x01,0x07,0x01)	// Versionsnummer
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0x9A)	// COMMSTAB Pointer
	STOP_WRITECYCLE
}
