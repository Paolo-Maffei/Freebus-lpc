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
#include "fb_app_rollo.h"
#include "../com/fb_rs232.h"

unsigned char Tval;			// Zwischenspeicher des Zustandes der Tasten (Handbetaetigung)
unsigned char portbuffer;	// Zwischenspeicherung der Portzustände
unsigned char oldportvalue; // alter portzustand
unsigned char zfstate;		// Zustand der Objekte 8-11 = Zusatzfunktionen 1-4
unsigned char blocked;		// Sperrung der 4 Kanäle (1=gesperrt)
unsigned char oldblockvalue;//,zfout,zftyp;
unsigned char logicstate;	// Zustand der Verknüpfungen pro Ausgang
long timer;					// Timer für Schaltverzögerungen, wird alle 8 us hochgezählt
unsigned char delay_toggle;			// um nur jedes 8. Mal die delay routine auszuführen
unsigned char owntele;		// Anzahl der internen Verarbeitungen eines gesendeten Telegrammes (Rückmeldung)
unsigned char respondpattern;// bit wird auf 1 gesetzt wenn objekt eine rückmeldung ausgelöst hat
//unsigned char Kanalfreigabe; // ist 1 für den jeweiligen Kanal nach umschaltpause
unsigned char kanal[4];		// Wert des Kanalobjekts
unsigned char knr,n;
bit portchanged,state;

void write_value_req(void)				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
{
  unsigned char objno,objflags,gapos,atp,assno,n,gaposh;
 unsigned char k,zuordnung,sobj,blockstart,blockend;
 
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

          if (objno<8) object_schalten(objno,telegramm[7]&0x01);	// Objektnummer 0-4 entspricht den Kanälen 1-4
 
         if (objno>=16 && objno<=17)	// Objektnummer 16+17 entspricht den Sicherheitsfahrten 1 + 2
            {
        	 sobj=objno-16;				//sobj ("Sicherheitsobjektnummer")ist also 0 für Sicherheit1, 1 für Si 2
     		if (telegramm[7]) write_obj_value(objno,1);		// Objektwert im userram speichern
     		else write_obj_value(objno,0);
     		if (telegramm[7]& 0x80){
     			state=(eeprom[0xE2]& (0x40<<sobj));
     			if (state^(telegramm[7]==0x81)) zfstate=zfstate |(0x0F<<(sobj<<2));// setzen der sicherhfahrt 1 in zfstate, xor verknüpft die polarität
     			else zfstate=zfstate & (0xFF-(0x0F<<(sobj<<2)));//in zfstate sind für sich1 0F und sich2 F0
     			zuordnung=eeprom[0xF1] & zfstate;//in zuordnung jetzt eine 1 für jede sicherheit 
     			blocked =zuordnung |((zuordnung >>4) | (zuordnung<<4)); //beide Sicherheitsergebnisse verodern..
     			}
 			blockstart= blocked & ~oldblockvalue;//steigende Flanke der Blockade(sicherheit)
 			blockend= ~blocked & oldblockvalue;	//fallende Flanke der Blockade(sicherheit)
     		oldblockvalue=blocked;
     		start_writecycle();
     		write_byte(0x00,0xCA,blocked);		// 0xCA  blocked im userram sichern
     		stop_writecycle();
     		for (k=0;k<=3;k++){		//für die 4 Kanäle die Sicherheitsfuntionen schalten
     			if(blockstart & 0x01){
     				switch((eeprom[0xF0]<<(k<<1))&0x03){  //EF ende, F0 anfang...
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
     				switch(eeprom[0xEF]<<(k<<1)&0x03){
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
            
        	}// ende if(objno>=16...
          }// ende if(gapos...
        }// ende for(n=0;n...
      
      //rollo if (portbuffer != userram[0x29])port_schalten(portbuffer);	//Port schalten wenn sich ein Pin geändert hat
    }//ende if(gapos!=...
    owntele=0;
    respondpattern=0;
    //rs_send(blocked);
}//ende void write_value_request(....




void object_schalten(unsigned char objno, bit objstate)	// Schaltet einen Kanal gemäß objstate und den zugörigen Parametern
{
	//unsigned char delay_base,delay_zeit,logicfunc,delay_state,zfno;
	unsigned char port_pattern,objflags,kwin,kwout,faktor,lz_ue;
	long delay_target,pause,pluszeit;//,delay_onoff,
	bit off_disable;
    off_disable;

		kwin = kanal[objno & 0x03]& 0x0f;// kwin heisst KanalWertIN. Bit 0+1 Relaise status, Bit 4+5 gewünschter Relaise status
		kwout=kwin;
		if (objstate) write_obj_value(objno,1);		// Objektwert im userram speichern
		else write_obj_value(objno,0);
		objflags=read_objflags(objno);			// Objekt Flags lesen
		port_pattern=0x01<<(objno&0x07);// 0x0F ist Absicht, die oberen 8 objekte nicht blockieren, da sie ein bypass über blocked sind
//		zfno=0;
//		logicfunc=0;
		if((port_pattern & blocked)==0 && (objflags&0x14)==0x14 ||(objno >=8)) {	// Objekt ist nicht gesperrt und Kommunikation zulässig (Bit 2 = communication enable) und Schreiben zulässig (Bit 4 = write enable)
		objno=objno&0x07;	// damit die bypassobjekte 8-15 wieder 0-7 sind!

// Pausezeit berechnen..
			pause=125;//werkseinstellung
			switch ((eeprom[0xEE]>>((objno&0x03)<<1))&0x03) { // Dauer zwischen auf und ab
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
// ende Pausezeit
			
			if (objno<0x04){			//+++++ kurzzeitobjekt +++++
				delay_target=zeit(0xE8,0xE9,0xEA,objno);// zeit aus eeprom holen
				pluszeit=delay_target + (delay_target>>5);// 3% zeit bei "auf" 
				faktor=eeprom[0xEA+objno];// faktor holen um dann auf 0 zu prüfen
			
				if (objstate==0){	//----- auf -----
					  if (kwin&0x11){					// wenn fahrt,dann stop
						  kwout=kwin&0xEE;
						  clear_delay_record(objno);	// kurzzeit löschen
						  clear_delay_record(objno+4);  // lanzeit löschen
					  }
					  if (!(kwin&0x33)&&(faktor)){	//wenn stillstand, dann step
						  kwout=kwin|0x10;
						  kwout=kwout&0xDF;
							write_delay_record(objno, 0x01, timer  + pluszeit);
					  }
					  if (kwin&0x22){					// wenn fahrt in andere richtung
						  kwout=kwin|0x10;
						  kwout=kwout&0xDF;
							write_delay_record(objno, 0x01, timer + pluszeit + pause );
					  }
				}
				else{				//----- ab -----
					  if (kwin&0x22){					// wenn fahrt, dann stop
						  kwout=kwin&0xDD;
						  clear_delay_record(objno);	// kurzzeit löschen
						  clear_delay_record(objno+4);	//langzeit löschen
					  }
					  if (!(kwin&0x33)&&(faktor)){		// wenn stillstand dann step
						  kwout=kwin|0x20;
						  kwout=kwout&0xEF;
							write_delay_record(objno, 0x01, timer + delay_target);
					  }
					  if (kwin&0x11){					// wenn fahrt in andere richtung
						  kwout=kwin|0x20;
						  kwout=kwout&0xEF;
							write_delay_record(objno, 0x01, timer + delay_target + pause);
					  }
				}//ende ab
			}// ende kurzzeitobjekte
			
				else{				//++++++ Langzeitobjekt +++++++
					rs_send(objno);
					delay_target=zeit(0xFB,0xFC,0xDA,objno&0x03);// zeit aus eeprom holen
					delay_target=delay_target + (delay_target>>2);// +25% zeit bei langzeit 
					pluszeit=delay_target + (delay_target>>5);// 3% zeit bei "auf" 
					lz_ue=((eeprom[0xF2]>>objno)&0x01);		//lz_ue bedeutet: langzeit unendlich
					if (objstate==0){// --- auf ----
						
						if (kwin&0x11){		//läuft bereits, also nachtriggern
							  if (!lz_ue)write_delay_record(objno, 0x01, timer + pluszeit);
						 }
						 if (!(kwin&0x33)){	//wenn stillstand, dann move
							  kwout=kwin|0x10;
							  kwout=kwout&0xDF;
							  if (!lz_ue)write_delay_record(objno, 0x01, timer + pluszeit);
						  }
						  if (kwin&0x22){		// wenn fahrt in andere richtung
							  kwout=kwin|0x10;
							  kwout=kwout&0xDF;
							  if (!lz_ue)write_delay_record(objno, 0x01, timer +  pause + pluszeit);
						  }
					}//ende auf

					else{			//  --- ab ----
						 if (kwin&0x22){		//läuft bereits, also nachtriggern
							  if (!lz_ue)write_delay_record(objno, 0x01, timer + pluszeit);
						 }
						if (!(kwin&0x33)){	//wenn stillstand, dann move
							  kwout=kwin|0x20;
							  kwout=kwout&0xEF;
							  clear_delay_record(objno-4);
							  if (!lz_ue) write_delay_record(objno, 0x01, timer + delay_target );
						  }
						  if (kwin&0x11){					// wenn fahrt in andere richtung
							  kwout=kwin|0x20;
							  kwout=kwout&0xEF;
							  clear_delay_record(objno-4);
							  if (!lz_ue) write_delay_record(objno, 0x01, timer + delay_target + pause );
						  }

					
					}//ende ab
					
			}// ende langzeitobjekte +++++++
//			rs_send(kwout);
//			kwin=kanal[objnr];
			kwin=kwout;
			if((kwin>>4)& bit_swap(kwin&0x0f)){//wenn richtung umgeschaltet werden soll
//				rs_send(0xFF);
				write_delay_record((objno&0x03)+11, 0x01, timer + pause);
				kwout=kwout&0xF0;
				//rs_send(00);
			}
			else{
				if(kwin&0xf0){
					kwout=kwin>>4;
					//rs_send(kwout);
				}
			}
			kanal[objno&0x03]=kwout;
			portchanged=1;
				
		} 
}



void delay_timer(void)	// zählt alle 8ms die Variable Timer hoch und prüft Queue
{
	unsigned char objno,delay_state;//,delay_base;
// unsigned char port_pattern,delay_zeit,delay_onoff;
	long delval;//,delay_target;
	bit hand;
//#ifdef HAND		// für Handbetätigung
	unsigned char n;
	unsigned char ledport;
	unsigned char Tasten=0;
//#endif
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
					}
			//		if ((objno>=8) && (objno <=10)){	//zyklische überwachung von sicherheitsobj 1 bzw 2
						
			//		}
					if ((objno>=11) && (objno<=14)){
					clear_delay_record(objno);			//timer loeschen
					kanal[objno-11]=kanal[objno-11]>>4;			// die oberen 4 bit des kanals sind die neue value.
					}
					if (objno>=15){
						//hand
						if (delay_state == 0x01) delrec[15*4]=0x02;// wenn ziel erreicht in delrec sichern
					}
				 //portbuffer=portbuffer|(kanal[tinr]<<tinr);
				 portchanged=1;
				}//ende if(deval==..
			}//ende if(delay_state...
		}//ende for (objno=0;...
//#ifdef HAND		//+++++++   Handbetätigung  ++++++++++
	hand=((eeprom[0xE5]& 0xC0)>0);
	if (((delay_toggle & 0x07)==0x07)){   // Handbetätigung nur jedes 8.mal ausführen
	while(TL0>256-DUTY+0x10);	// PWM scannen um "Hand"-Tasten abzufragen
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
	if (RI){//simulation..
		
		RI=0;
		Tasten=SBUF;
 	}//ende simulation

	
//	if (interrupted==1) Tasten=8;  // wenn unterbrochen wurde verwerfen wir die Taste
	_asm;
	jb _interrupted,00001$;
	mov r2,#8;
	00001$:
	_endasm;
	// in ASM weils der doofe Optimizer wegoptimiert!!??!!
	P0=~oldportvalue; 
	//	Tasten = Tval; // ##############  <----- Hier wird Handbetätigung quasi mit ausgeschaltet !! #########################
	if (Tasten <= 0x07){
		if (Tval > 0x07){
			rs_send(eeprom[0xE5]);

			write_delay_record(0x0F,0x01,timer+150);

		}	
	else{
		if (Tval<=0x07){// wenn tasten >7 und Taval <=7 also taste losgelassen...
			if (delrec[15*4]>=0x02){// status der zeit=2 also abgelaufen..
				clear_delay_record(15);	//zeit löschen
				object_schalten((Tasten>1)+12,(Tasten&0x01==0x01));
			}
			else{
				clear_delay_record(15);	
				object_schalten((Tasten>1)+8,(Tasten&0x01==0x01));
				
			}	
				
		}
	}
	}// ende if (Taster<=7)
	Tval=Tasten;
	}//ende if delay_toggle...
	//#endif
//ende void delay_timer(void)






if (portchanged) port_schalten(0);	//(portbuffer)			// Ausgänge schalten
//rollo	RTCCON=0x61;		// RTC starten
//rollo	delay_toggle=!delay_toggle;
} //end of delay_timer()-------------------------------------------------------

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
		TH0=0x00;		// 16ms (10ms=6fff)
		TL0=0x00;
		TMOD=0x11;		// Timer 0 als 16-Bit Timer, Timer 1 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;
	}
	else P0=ports;
	oldportvalue=~ports;
  portchanged=0;
}


/*
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
*/

void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{
	unsigned char bw,bwh,n;
	bw;
	bwh;
	n;
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
	stop_rtc();
	start_rtc(8);		// RTC neu mit 8ms starten
	timer=0;			// Timer-Variable, wird alle 8ms inkrementiert

for(n=0;n<=13;n++){
	delrec[n*4]=0;
}
/*	EX1=0;							// Rückmeldung bei Busspannungswiederkehr
	for (n=0;n<8;n++) {
		owntele=1;
		//rollo respond(n+12,((portbuffer>>n) & 0x01)+0x80);
	}
	EX1=1;
*/	owntele=0;
	respondpattern=0;
  
	oldportvalue=0xFF;	//alter portwert, damit vollstrom möglich wird
	blocked=userram[0xCA];		// Ausgänge gesperrt?
	timer=0;			// Timer-Variable, wird alle 8 ms inkrementiert
	for (n=0;n<=3;n++){
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
  
	start_writecycle();
	write_byte(0x01,0x03,0x00);	// Herstellercode 0x0004 = Jung
	write_byte(0x01,0x04,0x04);
	write_byte(0x01,0x05,0x20);	// Devicetype 0x2070 = Jung Aktor 
	write_byte(0x01,0x06,0x70);	
	write_byte(0x01,0x07,0x01);	// Versionsnummer
	
	write_byte(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
	write_byte(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
	write_byte(0x01,0x12,0x9A);	// COMMSTAB Pointer
	stop_writecycle();
}
