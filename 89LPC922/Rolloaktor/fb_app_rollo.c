/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008 Andreas Krebs <kubi@krebsworld.de>
 *  Copyright (c) 2009 Andreas Krieger <service at krieger minus elektro.de>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 * 
 
 * 			- write_obj_value aufrufe rausgenommen
 * 
 * 23.11.08 - Soft PWM während der Vollstromphase
 * 			- Handbetätigung in delay_timer eingefügt (hierzu P1.3 nötig !)
 *  
 * 01.01.09	- Soft PWM rausgenommen
 * 			- write_obj_value wieder reingenommen mit Überprüfung ob INT unterbrochen hat
 * 			- Rückmeldung bei Busspannungswiederkehr funktioniert jetzt
 * 12.12.09 - Überprüfung auf Zuordnung der Sicherheitsfunktion in Applistart
 * 			- Appli Start: Empfang beim flashen gesperrt.
 */



#include <P89LPC922.h>
#include "../com/rollo_hal_lpc.h"
#include "../com/rollo_prot.h"
#include "../com/fb_delay.h"
#include "fb_app_rollo.h"
#include "../com/fb_rs232.h"

unsigned char Tval,serbuf;			// Zwischenspeicher des Zustandes der Tasten (Handbetaetigung)
//unsigned char por;	// Zwischenspeicherung der Portzustände
unsigned char oldportvalue; // alter portzustand
unsigned char zfstate;		// Zustand der Objekte 8-11 = Zusatzfunktionen 1-4
unsigned char blocked;		// Sperrung der 4 Kanäle (1=gesperrt)
unsigned char oldblockvalue;//,zfout,zftyp;
unsigned char logicstate;	// Zustand der Verknüpfungen pro Ausgang
long timer;					// Timer für Schaltverzögerungen, wird alle 8 us hochgezählt
unsigned char delay_toggle;			// um nur jedes 8. Mal die delay routine auszuführen
//unsigned char owntele;		// Anzahl der internen Verarbeitungen eines gesendeten Telegrammes (Rückmeldung)
//unsigned char respondpattern;// bit wird auf 1 gesetzt wenn objekt eine rückmeldung ausgelöst hat
unsigned char kanal[4];		// Wert des Kanalobjekts
unsigned char knr,n;

bit portchanged,state;
bit handmode;
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


void write_value_req(void)				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
{
  unsigned char objno,objflags,gapos,atp,assno,n,gaposh;
 
    gaposh=0;

    gapos=gapos_in_gat(telegramm[3],telegramm[4]);	// Position der Gruppenadresse in der Adresstabelle
    if (gapos!=0xFF)					// =0xFF falls nicht vorhanden
    {
	  if ((telegramm[1] != eeprom[ADDRTAB+1]) || (telegramm[2] != eeprom[ADDRTAB+2])) {
		  send_ack();
	  }
	  atp=eeprom[ASSOCTABPTR];			// Start Association Table
      assno=eeprom[atp];			// Erster Eintrag = Anzahl Einträge
      for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
      {
        gaposh=eeprom[atp+1+(n*2)];
        if(gapos==gaposh)					// Wenn Positionsnummer übereinstimmt
        {
          objno=eeprom[atp+2+(n*2)];				// Objektnummer
          objflags=read_objflags(objno);			// Objekt Flags lesen

         if (objno<8 && !handmode) object_schalten(objno,telegramm[7]&0x01);	// Objektnummer 0-4 entspricht den Kanälen 1-4
 
         if (objno>=16 && objno<=17)Sobject_schalten(objno);	// Objektnummer 16+17 entspricht den Sicherheitsfahrten 1 + 2

        	}// ende if(gapos...
        }// ende for(n=0;n...
      //rollo if (portbuffer != userram[0x29])port_schalten(portbuffer);	//Port schalten wenn sich ein Pin geändert hat
    }//ende if(gapos!=...
 //   owntele=0;
 //   respondpattern=0;
    //rs_send(blocked);
}//ende void write_value_request(....

void Sobject_schalten(unsigned char objno)
{
unsigned char k,zuordnung,sobj,blockstart,blockend;
	
	if (objno >18){				// wenn bypass aus delay timer...
		sobj=objno&0x01;	// dann sobj ausfiltern
		state=0;				//state so setzen damit sperre aktiv wird
		telegramm[7]=0x81;		// dto für objektvalue
	}
	else{
		sobj=objno-16;				//sobj ("Sicherheitsobjektnummer")ist also 0 für Sicherheit1, 1 für Si 2
		state=!((eeprom[0xE2])& (0x40<<sobj));//Polarität

	}
		if (telegramm[7]) write_obj_value(objno & 0x1F ,1);		// Objektwert im userram speichern
			else write_obj_value(objno & 0x1F,0);
			if (telegramm[7]& 0x80){
				if (state^(telegramm[7]==0x81)) zfstate=zfstate |(0x0F<<(sobj<<2));// setzen der sicherhfahrt 1 in zfstate, xor verknüpft die polarität
				else {
					zfstate=zfstate & (0xFF-(0x0F<<(sobj<<2)));//in zfstate sind für sich1 0F und sich2 F0
					set_entriegeln(sobj + 9);// Update objekt macht refresh auf Zeit 9/10  Zyklusüberwachung
					}
				zuordnung=eeprom[0xF1] & zfstate;//in zuordnung jetzt eine 1 für jede sicherheit 
				blocked =zuordnung |((zuordnung >>4) | (zuordnung<<4)); //beide Sicherheitsergebnisse verodern..
			}
			blockstart= blocked & ~oldblockvalue;//steigende Flanke der Blockade(sicherheit)
			blockend= ~blocked & oldblockvalue;	//fallende Flanke der Blockade(sicherheit)
			START_WRITECYCLE
			WRITE_BYTE(0x00,0x2A,blocked)		// 0xCA  blocked im userram sichern
			STOP_WRITECYCLE
			if (!handmode){
			oldblockvalue=blocked;

			for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
				if(blockstart & 0x01){
					switch((eeprom[0xF0]>>(k<<1))&0x03){  //EF ende, F0 anfang...
					case 1:
						object_schalten(k+12,0);
					break;
					case 2:
						object_schalten(k+12,1);
					break;
					default:
					break;
					}// ende switch */
				}// ende if(blockstart
				if(blockend & 0x01){
					switch((eeprom[0xEF]>>(k<<1))&0x03){
					case 1:
						object_schalten(k+12,0);
					break;
					case 2:
						object_schalten(k+12,1);
					break;
					default:
					break;
					}// ende switch
					
				}// ende if(blockend...
				blockend=blockend>>1;
				blockstart=blockstart>>1;
			}// ende for(k=0;k...
		}//ende if !handmode
}//ende Sobject_schalten

void set_pause(unsigned char objnr,unsigned char Pstate)// setzt die Pausezeit und traegt Pstate in delreg[] ein
{
long pause;
	pause=125;//werkseinstellung
	switch ((eeprom[0xEE]>>((objnr&0x03)<<1))&0x03) { // Dauer zwischen auf und ab
	case 0:	// 0,5s
		pause=62;
	break;
	case 1:	// 1s
		pause=125;
	break;
	case 2:	// 2s
		pause=250;
	break;
	case 3:	// 5s
		pause=625;
	break;
}
	write_delay_record((objnr & 0x03)+ 11,Pstate,pause + timer);
}// ende Pausezeit


void set_entriegeln(unsigned char zeitnr){// Setzt die zyklische überwachungszeit
	long svzeit;
	unsigned char svbase,svfaktor=0;

	svbase=eeprom[0xD9]&0x0F;

	if (svbase>0){
		switch(svbase){
			case 1:
				svfaktor=2;
				break;
			case 2: 
				svfaktor=4;
				break;
			case 3: 
				svfaktor=6;
				break;
			case 4: 
				svfaktor=7;
				break;
			case 5: 
				svfaktor=9;
				break;
			case 6: 
				svfaktor=11;
				break;
			case 7: 
				svfaktor=13;
				break;
			case 8: 
				svfaktor=15;
				break;
			case 9: 
				svfaktor=18;
				break;
			case 10: 
				svfaktor=20;
				break;
			case 11: 
				svfaktor=22;
				break;
			case 12: 
				svfaktor=37;
				break;
			case 13: 
				svfaktor=73;
				break;
			case 14: 
				svfaktor=110;
				break;
			case 15: 
				svfaktor=220;
				break;
		}
		//rs_send(svfaktor);
		svzeit=svfaktor<<12 ;//12  entspricht ein svfaktor*4096
		write_delay_record(zeitnr,0x01,timer+svzeit);
	}
	else{
		delrec[zeitnr*4]=0;
	}
}

void object_schalten(unsigned char objno, bit objstate)	// Schaltet einen Kanal gemäß objstate und den zugörigen Parametern
{
	//unsigned char delay_base,delay_zeit,logicfunc,delay_state,zfno;
	unsigned char port_pattern,objflags,kwin,kwout,faktor,lz_ue,tmp;
	long delay_target,pluszeit;//,delay_onoff,
	bit off_disable;
    off_disable;
		kwin = kanal[objno & 0x03]& 0x0f;// kwin heisst KanalWertIN. Bit 0+1 Relaise status, Bit 4+5 gewünschter Relaise status
		kwout=kwin;
		if (objstate) write_obj_value(objno & 0x07,1);		// Objektwert im userram speichern
		else write_obj_value(objno & 0x07,0);
		objflags=read_objflags(objno&0x07);			// Objekt Flags lesen
		port_pattern=0x01<<(objno&0x07);//port_pattern=0x01<<(objno&0x0F)
//		zfno=0;
//		logicfunc=0;
		if((port_pattern & blocked)==0 && (objflags&0x14)==0x14 ||(objno >=8)) {	// Objekt ist nicht gesperrt und Kommunikation zulässig (Bit 2 = communication enable) und Schreiben zulässig (Bit 4 = write enable)
		objno=objno&0x07;	// damit die bypassobjekte 8-15 wieder 0-7 sind!

// Pausezeit berechnen..
			
			if (objno<0x04){			//+++++ kurzzeitobjekt +++++
				delay_target=zeit(0xE8,0xE9,0xEA,objno);// zeit aus eeprom holen
				pluszeit=delay_target + (delay_target>>5);// 3% zeit bei "auf" 
				faktor=eeprom[0xEA+objno];// faktor holen um dann auf 0 zu prüfen
			
				if (objstate==0){	//----- auf -----

					if (kwin&0x33){					// wenn faehrt,dann stop
						  set_pause(objno,kwin&0x03);
						  //						  write_delay_record((objno&0x03)+11, 0x02, timer + pause);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
						  kwout=kwin&0xCC;	//war EE, Fahrt in beide Richtungen stoppen
						  clear_delay_record(objno);	// kurzzeit löschen
						  clear_delay_record(objno+4);  // lanzeit löschen
					  }
					  if ((!(kwin&0x33))&&(faktor)){	//wenn stillstand und faktor>0  dann step
						  
						  kwout=kwin|0x10;
						  kwout=kwout&0xDF;
						  write_delay_record(objno, 0x01, timer  + pluszeit);
					  }
					  /*if ((kwin&0x22)&&(faktor)){					// wenn fahrt in andere richtung
						  set_pause(objno, 0x01);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
						  kwout=kwin|0x10;
						  kwout=kwout&0xDF;
						  write_delay_record(objno, 0x01, timer + pluszeit );
					  }*/
				}
				else{				//----- ab -----
					  if (kwin&0x33){					// wenn faehrt, dann stop
						  set_pause(objno,kwin&0x03);
						  //write_delay_record((objno&0x03)+11, 0x01, timer + pause);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
						  kwout=kwin&0xCC;//war DD
						  clear_delay_record(objno);	// kurzzeit löschen
						  clear_delay_record(objno+4);	//langzeit löschen
					  }
					  if ((!(kwin&0x33))&&(faktor)){		// wenn stillstand dann step
						  kwout=kwin|0x20;
						  kwout=kwout&0xEF;
						  write_delay_record(objno, 0x02, timer + delay_target);
					  }
					/*  if (kwin&0x11){					// wenn fahrt in andere richtung
						  set_pause(objno, 0x02);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
						  kwout=kwin|0x20;
						  kwout=kwout&0xEF;
						  write_delay_record(objno, 0x01, timer + delay_target );
					  }*/
				}//ende ab
			}// ende kurzzeitobjekte
			
				else{				//++++++ Langzeitobjekt +++++++
					delay_target=zeit(0xFB,0xFC,0xDA,objno&0x03);// zeit aus eeprom holen
					delay_target=delay_target + (delay_target>>2);// +25% zeit bei langzeit 
					pluszeit=delay_target + (delay_target>>5);// 3% zeit bei "auf" 
					lz_ue=((eeprom[0xF2]>>objno)&0x01);		//lz_ue bedeutet: langzeit unendlich
					if (objstate==0){// --- auf ----
						//rs_send(objno);
						if (kwin&0x11){		//läuft bereits, also nachtriggern
							kwout=kwin|0x10;// auch hier neu setzen da in delay nach rechts kommt
							  clear_delay_record(objno-4);//kurzzeit löschen
							if (!lz_ue)write_delay_record(objno, 0x01, timer + pluszeit);
						 }
						if (!(kwin&0x33)){	//wenn stillstand, dann move
							kwout=kwin|0x10;
							 // kwout=kwout&0xDF;
							  
							if (!lz_ue)write_delay_record(objno, 0x01, timer + pluszeit);
						  }
						   if (kwin&0x22){		// wenn fahrt in andere richtung
							  set_pause(objno,0x05);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
							  kwout=kwin|0x10;
							  kwout=kwout&0xDF;
							  if (!lz_ue)write_delay_record(objno, 0x01, timer  + pluszeit);
						  }
					}//ende auf

					else{			//  --- ab ----
						 if (kwin&0x22){		//läuft bereits, also nachtriggern
							 kwout=kwin|0x20;// auch hier neu setzen da in delay nach rechts kommt
							  clear_delay_record(objno-4);//kurzzeit löschen
							 if (!lz_ue)write_delay_record(objno, 0x02, timer + delay_target);
						 }
						if (!(kwin&0x33)){	//wenn stillstand, dann move
							  kwout=kwin|0x20;// kanal setzen
							 // kwout=kwout&0xEF;
							  clear_delay_record(objno-4);//kurzzeit löschen
							  if (!lz_ue) write_delay_record(objno, 0x02, timer + delay_target );
						  }
						if (kwin&0x11){					// wenn fahrt in andere richtung
							  set_pause(objno, 0x06);// einsch. verz "pause" für eventuelle Faht in gegenrichtung
							  kwout=kwin|0x20;
							  kwout=kwout&0xEF;
							  clear_delay_record(objno-4);
							  if (!lz_ue) write_delay_record(objno, 0x02, timer  + delay_target );
						  }

					
					}//ende ab
					
			}// ende langzeitobjekte +++++++
			
			kwin=kwout;
			if (objno<=7){
				tmp=delrec[((objno & 0x03)+11)*4]& 0x07;
				//rs_send(tmp);
				if ((tmp<4)&& (tmp & (kwout>>4) & 0x03)){
				//	rs_send('L');
					clear_delay_record((objno&0x03)+11);//gleiche Richtung: Pause löschen
					tmp=0;
				}
				
				if(tmp & 0x04){//wenn Pause wegen umschalten läuft,Kanal "ist" löschen.
				//	rs_send('P');
					kwout=kwout&0xF0;
				}
				else {
					if(!(tmp)){
					kwout=kwin>>4;//wenn keiene Pause Läuft, dann kanal "soll" in "ist" kopieren
				//	rs_send ('S');
					}
				}
			}

			/*		if((kwin>>4)& bit_swap(kwin&0x0f)){//wenn richtung umgeschaltet werden soll
//				rs_send(0xFF);
				write_delay_record((objno&0x03)+11, 0x01, timer + pause);
			}
			else{
				if(kwin&0xf0){
					kwout=kwin>>4;
					//rs_send(kwout);
				}
			}*/
			kanal[objno&0x03]=kwout;
			portchanged=1;
	
		} 
}



void delay_timer(void)	// zählt alle 8ms die Variable Timer hoch und prüft Queue
{
	unsigned char objno,delay_state;//,delay_base;
// unsigned char port_pattern,delay_zeit,delay_onoff;
	long delval;//,delay_target;
//	bit hand;
	stop_rtc();
	start_rtc(8);		// RTC neu mit 8ms starten
	delay_toggle++;
	objno=0;
		timer++;		//###  Hier wird der timer hochgezaelt ####
		if (timer==0x01000000) timer=0;					// nur 3 Byte aktiv
		for(objno=0;objno<=15;objno++) {
			delay_state=delrec[(objno)*4];			//status des timer-records
			if(delay_state!=0x00) {					// 0x00 = delay Eintrag ist leer   
				delval=delrec[(objno)*4+1];			//3 timer-wert-bytes
				delval=(delval<<8)+delrec[(objno)*4+2];
				delval=(delval<<8)+delrec[(objno)*4+3];
				if(delval==timer) { 					// wenn der record dem timer entspricht, also zeit ist abgelaufen...
					if (objno<=7){					// wenns ein kurz oder langzeit objekt ist...
						clear_delay_record(objno);
						kanal[objno&0x03]=0x00;
					    set_pause(objno,(delay_state));// einsch. verz "pause" für eventuelle Fahrt in gegenrichtung
					    								//in Pause-state sichern
					}
					if (objno==9 ){	//Sicherheit 1
						if (delay_state == 0x01){
							delrec[9*4]=0x02;// wenn ziel erreicht in delrec sichern
							Sobject_schalten(48);// und Sicherheitsobjekt über bypass schalten
						}
						//rs_send('1');
					}
					if (objno==10 ){	//Sicherheit 2
						if (delay_state == 0x01){
							delrec[10*4]=0x02;// wenn ziel erreicht in delrec sichern
							Sobject_schalten(49);// und Sicherheitsobjekt über bypass schalten
						}
						//rs_send('2');
					}
					if ((objno>=11) && (objno<=14)){// die Pausezeit der Kanaele
					kanal[objno-11]=kanal[objno-11]>>4;			// die oberen 4 bit des kanals sind die neue value.
					clear_delay_record(objno);			//timer loeschen
					}
					if (objno>=15){// handmode kurz/langtele + einschaltverz + ausschaltverz
						//hand
						if (delay_state == 0x12) delrec[15*4]=0x22; // wenn ziel 2 erreicht in delrec sichern
						if (delay_state == 0x01) write_delay_record(15,0x12,timer+200);// wenn ziel 1 erreicht in delrec sichern und restzeit fuer ziel 2 schreiben
							 //2sek.langer Tastendruck setzen
						if (delay_state == 0x04) delrec[15*4]= 0x08;// wenn ziel erreicht in delrec sichern
					}
				 portchanged=1;
				}//ende if(deval==..
				else{// also die zeit nicht abgelaufen...
					if ( objno<=0x07 && ((delrec[((objno & 0x03)+11)*4])>0)){//wenn zeit der pause läuft.. 
						write_delay_record(objno,delay_state,delval+1);//trick : wegen der pause werden die zeiten geschoben
					}
				}//ende else zeit abgelaufen
			}//ende if(delay_state...
		}//ende for (objno=0;...
//#ifdef HAND		//+++++++   Handbetätigung  ++++++++++


}


bit handsteuerung()
{
	//#ifdef HAND		// für Handbetätigung
		unsigned char n;
		unsigned char ledport;
		unsigned char Tasten=0;
		unsigned char tmph;
		tmph;
	//#endif
/*
	if (RI){//simulation..
		RI=0;
	serbuf=SBUF;
	//	rs_send(eeprom[SBUF]);// für sniffer
	}//ende simulation
*/
#ifdef GS1
		while( TMOD==0x12 && (PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen
#endif
#ifdef GS2
		while( TMOD==0x12 && (!PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen
#endif
	interrupted=0;	  
	Tasten=8;				// 
	P1_3= 1;			    //int0 auf 1; wird über taster, diode, IO auf gnd gezogen.
	ledport=0x01;
	for (n=0;n<=7;n++){  						
		P0=~ledport;
	  	if (!P1_3){
	  		Tasten=n;
	  		n=7;
	  	}
	  	ledport=ledport<<1;
	} 
	
//	Tasten=serbuf;

//		if (!interrupted);//
//		else Tasten=8;  // wenn unterbrochen wurde verwerfen wir die Taste
	_asm;
	jnb _interrupted,00001$;
	mov r2,#8; //_Tval;
	00001$:
	_endasm; 
	// in ASM weils der doofe Optimizer wegoptimiert!!??!!
	P0=~oldportvalue; 
	
	//	Tasten = Tval; // ##############  <----- Hier wird Handbetätigung quasi mit ausgeschaltet !! #########################
	if (Tasten <= 0x07){
		if (Tval >= 0x08){// steigende Flanke des Tasters 
			tmph=delrec[15*4];
			write_delay_record(15,0x01,timer+50);//50 kurz-lang 0,4 sek
		}
	}	
	else{
		if (Tval<=0x07){// wenn tasten >7 und Tval <=7 also taste losgelassen...
			if (delrec[15*4]&0x20){
				handmode = !handmode;
				clear_delay_record(15);
				if (handmode){
					for(n=0;n<=4;n++) kanal[n]=0x00;
					portchanged=1;
				}
				else{//wenn nach dem toggeln nicht handmode also ausgeschaltet
					sobj_update();
				}
			}
			if (handmode){// wenn handmode aktiv...
				if (delrec[15*4]&0x02){// status der zeit=2 also abgelaufen..
					object_schalten((Tval>>1)+12,(Tval&0x01==0x01));
					}
				else{
					object_schalten((Tval>>1)+8,(Tval&0x01==0x01));
				}	
			}//ende if(handmode...		
			write_delay_record(15,0x04,timer+1875);//handbetätigung aus starten
		}// ende if Tval
	}// ende if (Taster<=7)
	Tval=Tasten;
	if(delrec[15*4]&0x08){
		handmode=0;//handmode automatisch ausschalten
		clear_delay_record(15);
		sobj_update();
	}
	return handmode;
}//ende handsteuerung...
	
void sobj_update(void)
{
	telegramm[7]=read_obj_value(16)&0x01;
	Sobject_schalten(16);
	telegramm[7]=read_obj_value(17)&0x01;
	Sobject_schalten(17);
}
unsigned long zeit(unsigned char base_low,unsigned char base_high,unsigned char faktor_adr,unsigned char obj)
{
	unsigned char blow,bhigh,base,faktor;
	blow=eeprom[base_low];
	bhigh=eeprom[base_high];
	switch(obj){					// Basis maskieren
	case 0://  kanal 1
		base=blow&0x7;
	break;
	case 1://  kanal 2
		base=(blow>>3)&0x7;
	break;
	case 2://  kanal 3
		base=bhigh&0x7;
	break;
	default://  kanal 4
		base=(bhigh>>3)&0x7;
	}
	faktor=eeprom[faktor_adr + obj];// Zeit berechnen
	switch (base) { // Basis 
	case 3:				// 128ms
		return(faktor<<4);
		break;
	case 4:				// 2,05s
		return(faktor<<8);
		break;
	case 5:				// 33s
		return(faktor<<12);
		break;
	default:			//8ms
		return(faktor);
	}// end switch
}// end zeit

unsigned char bit_swap(unsigned char swp)// vertauscht bit 0-1, 2-3, 4-5, 6-7
{
	return ((swp&0x55)<<1)|((swp&0xAA)>>1);
}

/*
void Kanaltreiber(unsigned char ports, unsigned char kanal,unsigned char value,unsigned char work)//Kanal handling
// kanal= Kanalnummer 0-3, value= 0 fuer auf, 1 fuer ab. work= 0 fuer stop, 1 fuer auf/ab fahren)
{
	unsigned char kanalpattern;
	
	kanalpattern =((0x01&work)<<value)<<(kanal<<2);
	ports&=(~kanalpattern);
	ports|=kanalpattern;
	
}
*/

void port_schalten(unsigned char ports)		// Schaltet die Ports mit PWM, DUTY ist Pulsverhältnis

{
	unsigned char kmod;
	if (eeprom[0xE4]& 0x80) kmod=0x01;		// bit 7 ist Kanal-mode
	else kmod=0x03;
	for (knr=0;knr<=0x03;knr++){
		ports=ports|((kanal[knr & kmod]& 0x03)<<(knr<<1));
		}
	if(ports & oldportvalue) {	// Vollstrom nur wenn ein relais eingeschaltet wird
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
		TH0=0x70;		// 00   16ms (10ms=6fff)
		TL0=0x00;
		TMOD=0x11;		// Timer 0 als 16-Bit Timer, Timer 1 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;
	}
	else P0=ports;
	oldportvalue=~ports;
  portchanged=0;
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{
	unsigned char bw,bwh,n;
	bw;
	bwh;
	n;
//#ifdef HAND
	Tval=0x08;
	serbuf=8;
	handmode=0;
// #endif
	P0=0;
	P0M1=0x00;		// Port 0 Modus push-pull für Ausgang
	P0M2=0xFF;
  
	TMOD=0x12;		// Timer 0 als PWM, Timer 1 als 16-Bit Timer
	TAMOD=0x01;
	TH0=DUTY;		// Pulsverhältnis PWM
	AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
	ET0=0;			// Interrupt für Timer 0 sperren 
	TR0=1;			// Timer 0 starten (PWM)
	stop_rtc();
	start_rtc(8);		// RTC neu mit 8ms starten
	timer=0;			// Timer-Variable, wird alle 8ms inkrementiert

	for(n=0;n<=15;n++){
		delrec[n*4]=0;
	}

	/*	EX1=0;							// Rückmeldung bei Busspannungswiederkehr
	for (n=0;n<8;n++) {
		owntele=1;
		//rollo respond(n+12,((portbuffer>>n) & 0x01)+0x80);
	}
	EX1=1;
	owntele=0;
	respondpattern=0;
 */ 
	
	oldportvalue=0xFF;	//alter portwert, damit vollstrom möglich wird
	blocked=userram[0x2A];		// Ausgänge gesperrt?
	timer=0;			// Timer-Variable, wird alle 8 ms inkrementiert
	for (n=0;n<=3;n++){
		if(((eeprom[0xF1]>>n)&0x11)==0 ){// wenn keine Sperrfunktion zugewiesen
			blocked &= ~(0x11<<n);  // dann blocked löschen, damit nach umpara
		}							// nicht stehen bleibt.
		switch(eeprom[0xD9]& 0xC0){
		case 0x40:
			object_schalten(n+12,0);
		break;
		case 0x80:
			object_schalten(n+12,1);
		break;
		default:
		}
	}
//	logicstate=0;
//	delay_toggle=0;
  
	EA=0;
  
	START_WRITECYCLE
	WRITE_BYTE(0x01,0x03,0x00);	// Herstellercode 0x0004 = Jung
	WRITE_BYTE(0x01,0x04,0x04);
	WRITE_BYTE(0x01,0x05,0x20);	// Devicetype 0x2070 = Jung Aktor 
	WRITE_BYTE(0x01,0x06,0x70);	
	WRITE_BYTE(0x01,0x07,0x01);	// Versionsnummer
	
	WRITE_BYTE(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0x9A);	// COMMSTAB Pointer
	STOP_WRITECYCLE
	EA=1;
	set_entriegeln(9);
	set_entriegeln(10);

}
