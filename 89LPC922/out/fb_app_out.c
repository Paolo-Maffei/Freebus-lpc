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
 * 
 * 09.11.08	- delay_timer geht nicht mehr �ber flash sondern �ber globale variable delrec
 * 			- delay_timer auf 24bit reduziert statt 32bit
 * 			- port_schalten nur noch eimal pro telegramm f�r alle pins
 * 			- interrupt-steuerung bei respond() rausgenommen
 * 			- globale variablen pah, pal, rmstate entfernt
 * 			- write_obj_value aufrufe rausgenommen
 * 
 * 23.11.08 - Soft PWM w�hrend der Vollstromphase
 * 			- Handbet�tigung in delay_timer eingef�gt (hierzu P1.3 n�tig !)
 *  
 * 01.01.09	- Soft PWM rausgenommen
 * 			- write_obj_value wieder reingenommen mit �berpr�fung ob INT unterbrochen hat
 * 			- R�ckmeldung bei Busspannungswiederkehr funktioniert jetzt
 * 
 * 13.02.09	- owntele ist ein z�hler, wie oft ein gesendetes telegramm intern erneut verarbeitet wurde
 *
 * 12.11.09 - umgestellt auf statemachine-library
 *
 * 18.12.09 - read_obj_value und write_obj_value aus der lib entfernt und in app implementiert
 * 			  kompletter Verzicht auf userram -> alle Stati in globalen Variablen
 *
 * 15.04.10 - Fehler mit den Logigverkn�pfungen behoben
 * 
 * 02.01.11 - Ausgabe auf serielle Schieberegister f�r bistabile Relaise via Compilerschalter
 * 
 */



#include <P89LPC922.h>
#include "../lib_lpc922/fb_lpc922.h"
#include  "fb_app_out.h"

//#include "../com/fb_rs232.h"

unsigned char timerbase[TIMERANZ];// Speicherplatz f�r die Zeitbasis und 4 status bits
unsigned char timercnt[TIMERANZ];// speicherplatz f�r den timercounter und 1 status bit
unsigned int timer;		// Timer f�r Schaltverz�gerungen, wird alle 130us hochgez�hlt


unsigned char Tval;
unsigned char out_state;	// Werte der Objekte 0-7 (Ausg�ngsobjekte)
unsigned char rm_state;		// Werte der Objekte 12-19 (R�ckmeldeobjekte)
unsigned char zf_state;		// Werte der Objekte 8-11 (Zusatzfunktionen 1-4)
unsigned char portbuffer;	// Zwischenspeicherung der Portzust�nde
unsigned char oldportbuffer;// Wert von portbuffer vor �nderung (war fr�her ...0x29)
unsigned char blocked;		// Sperrung der 8 Ausg�nge (1=gesperrt)
unsigned char logicstate;	// Zustand der Verkn�pfungen pro Ausgang
bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszuf�hren
bit portchanged;
unsigned char rm_send;		// die von der main zu sendenden R�ckmeldungen




void write_value_req(void) 				// Ausg�nge schalten gem�� EIS 1 Protokoll (an/aus)
{
  unsigned char objno,objflags,assno,n,gaposh,zfout,zftyp, gapos;
  unsigned char blockstart, blockend, block_polarity;
  unsigned char obj_bitpattern, zf_bitpattern;
 
    gaposh=0;

    gapos=gapos_in_gat(telegramm[3],telegramm[4]);	// Position der Gruppenadresse in der Adresstabelle
    if (gapos!=0xFF)					// =0xFF falls nicht vorhanden
    {
	  //atp=eeprom[ASSOCTABPTR];			// Start Association Table
      assno=eeprom[eeprom[ASSOCTABPTR]];				// Erster Eintrag = Anzahl Eintr�ge
 
      for(n=0;n<assno;n++)				// Schleife �ber alle Eintr�ge in der Ass-Table, denn es k�nnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
      {
        gaposh=eeprom[eeprom[ASSOCTABPTR]+1+(n*2)];
        if(gapos==gaposh)					// Wenn Positionsnummer �bereinstimmt
        {
          objno=eeprom[eeprom[ASSOCTABPTR]+2+(n*2)];				// Objektnummer
          objflags=read_objflags(objno);			// Objekt Flags lesen
//obj_bitpattern pr�fen !!!
          obj_bitpattern=0x01<<(objno-8);
          
          if (objno<8) object_schalten(objno,telegramm[7]&0x01);	// Objektnummer 0-7 entspricht den Ausg�ngen 1-8

          if (objno>7 && objno<12)	// Objektnummer 8-11 entspricht den Zusatzfunktionen 1-4
          {
            write_obj_value(objno, telegramm[7]&0x01);
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
            zf_bitpattern=0x01<<(zfout-1);
           
            switch (zftyp)
            {
              case 0x00:			// Verkn�pfung
                switch (telegramm[7])
                {
                  case 0x80:
                    logicstate=logicstate&(0xFF-zf_bitpattern);
                  break;
                  case 0x81:
                    logicstate=logicstate|zf_bitpattern;
                }
                object_schalten(zfout-1, read_obj_value(zfout-1));	//telegramm[7]&0x01);
              break;
              case 0x01:			// Sperren
            	block_polarity=eeprom[BLOCKPOL] & obj_bitpattern;
                if (((telegramm[7]==0x80) && (block_polarity==0)) ||
                	((telegramm[7]==0x81) && (block_polarity!=0)))
                {	// Ende der Sperrung
                	if((blocked & zf_bitpattern)!=0) {	// nur wenn Sperre aktiv war
						blocked=blocked&(0xFF-zf_bitpattern);
						if (blockend==0x01) portbuffer=portbuffer&(0xFF-zf_bitpattern);	// Bei Ende der Sperrung ausschalten
						if (blockend==0x02) portbuffer=portbuffer|zf_bitpattern;		// Bei Ende der Sperrung einschalten
                	}
                }
                  
                if (((telegramm[7]==0x81) && (block_polarity==0)) ||
                	((telegramm[7]==0x80) && (block_polarity!=0)))
                {	// Beginn der Sperrung
                	if((blocked & zf_bitpattern)==0) {	// nur wenn Sperre inaktiv war
						blocked=blocked|zf_bitpattern;
						if (blockstart==0x01) portbuffer=portbuffer&(0xFF-zf_bitpattern);	// Bei Beginn der Sperrung ausschalten
						if (blockstart==0x02) portbuffer=portbuffer|zf_bitpattern;		// Bei Beginn der Sperrung einschalten
						timercnt[zfout-1]=0;//delrec[(zfout-1)*4]=0;	// ggf. Eintrag f�r Schaltverz�gerung l�schen
                	}
                }
              //port_schalten(portbuffer);
              break;
              //case 0x02:			// Zwangsstellung
            }
          }
        }
      }
      if (portbuffer != oldportbuffer) portchanged=1;//post f�r port_schalten hinterlegen
      //port_schalten(portbuffer);	//Port schalten wenn sich ein Pin ge�ndert hat
    }
    //owntele=0;
    //respondpattern=0;
}


/** 
* Objektwert lesen wurde angefordert, read_value_response Telegramm zur�cksenden
*
* 
* @return
* 
*/
void read_value_req(void)
{
	unsigned char objno, objflags;
	unsigned int objvalue;
	
	objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
	if(objno!=0xFF) {	// falls Gruppenadresse nicht gefunden
		
		objvalue=read_obj_value(objno);		// Objektwert aus USER-RAM lesen (Standard Einstellung)

		objflags=read_objflags(objno);		// Objekt Flags lesen
		// Objekt lesen, nur wenn read enable gesetzt (Bit3) und Kommunikation zulaessig (Bit2)
		if((objflags&0x0C)==0x0C) send_obj_value(objno+64); //send_value(0,objno,objvalue);
    }
}


unsigned long read_obj_value(unsigned char objno) 	// gibt den Wert eines Objektes zurueck
{
	unsigned char ret_val=0;

	if(objno<8) {
		if(out_state&(1<<objno)) ret_val=1;
	}
	if(objno>=8 && objno<12) {
		if(zf_state&(1<<(objno-8))) ret_val=1;
	}
	if(objno>=12) {
		if(rm_state&(1<<(objno-12))) ret_val=1;
	}
	return(ret_val);
}


void write_obj_value(unsigned char objno,unsigned int objvalue)	// schreibt den aktuellen Wert eines Objektes ins 'USERRAM'
{
	if(objno<8) {
		if(objvalue==0) out_state&=0xFF-(1<<objno);
		else out_state|=1<<objno;
	}
	if(objno>=8 && objno<12) {
		if(objvalue==0) zf_state&=0x0F-(1<<(objno-8));
		else zf_state|=1<<(objno-8);
	}
	if(objno>=12) {
		if(objvalue==0) rm_state&=0xFF-(1<<(objno-12));
		else rm_state|=1<<(objno-12);
	}
}






void object_schalten(unsigned char objno, bit objstate)	// Schaltet einen Ausgang gem�� objstate und den zug�rigen Parametern
{
	
	unsigned char delay_base,delay_state,logicfunc,zfno;
	unsigned char delay_onoff;
	bit off_disable;
    

	
	off_disable=((eeprom[OFFDISABLE]>>objno)&0x01);	// nur ausschalten wenn AUS-Tete nicht ignoriert werden soll
	if ((!objstate && !off_disable) || objstate) {
		write_obj_value(objno,objstate);		// Objektwert speichern
		//objflags=read_objflags(objno);			// Objekt Flags lesen

		zfno=0;
		logicfunc=0;
		if((eeprom[FUNCASS]&0x0F)==(objno+1)) zfno=1;
		if(((eeprom[FUNCASS]&0xF0)>>4)==(objno+1)) zfno=2;
		if((eeprom[FUNCASS+1]&0x0F)==(objno+1)) zfno=3;
		if(((eeprom[FUNCASS+1]&0xF0)>>4)==(objno+1)) zfno=4;
		if(zfno) {
			if(((eeprom[FUNCTYP]>>((zfno-1)*2))&0x03)==0x00) logicfunc=((eeprom[LOGICTYP]>>((zfno-1)*2))&0x03);
		}

		if(((0x01<<objno) & blocked)==0 && (read_objflags(objno)&0x14)==0x14) {	// Objekt ist nicht gesperrt und Kommunikation zul�ssig (Bit 2 = communication enable) und Schreiben zul�ssig (Bit 4 = write enable)
			delay_base=eeprom[(((objno+1)>>1)+DELAYTAB)];   
			if((objno&0x01)==0x01) delay_base&=0x0F;
			else delay_base=(delay_base&0xF0)>>4;
			//delay_target=0;
			delay_onoff=0;
			delay_state=0;
			//delay_zeit=eeprom[0xEA];
			//delay_zeit=((eeprom[0xEA]>>objno)&0x01);
					// Ausschalten
			if ( (objstate==0 && (logicfunc==0 || (logicfunc==1 && ((logicstate>>objno)&0x01)==0x00) || logicfunc>=2))
					|| (objstate==1 && (logicfunc>=2 && ((logicstate>>objno)&0x01)==0x00)) )
			{
				delay_onoff=eeprom[objno+0xE2];
				if(delay_onoff==0x00 || ((eeprom[0xEA]>>objno)&0x01)==0x01) {		// sofort ausschalten
					if (((eeprom[RELMODE]>>objno)&0x01)==0x00) portbuffer=portbuffer&~(0x01<<objno);	// Schliesserbetrieb
					else portbuffer=portbuffer|(0x01<<objno);						// �ffnerbetrieb
				}
				else delay_state=0x01;				// verz�gert ausschalten
			}
                    
          			// Einschalten
			if ( (objstate==1 && (logicfunc==0 || logicfunc==1 || (logicfunc>=2 && ((logicstate>>objno)&0x01)==0x01))) 
					|| (objstate==0 && (logicfunc==1 && ((logicstate>>objno)&0x01)==0x01)) )
			{
				delay_onoff=eeprom[objno+0xDA];
				if(delay_onoff==0x00) {


					if(((eeprom[0xEA]>>objno)&0x01)==0x01) { 			// Zeitschaltfunktion
						delay_state=0x80;
						delay_onoff=eeprom[objno+0xE2];
					} 
					if (((eeprom[RELMODE]>>objno)&0x01)==0x00) portbuffer=portbuffer|(0x01<<objno);	// sofort einschalten (Schliesserbetrieb)
					else portbuffer=portbuffer&~(0x01<<objno);					// sofort einschalten (�ffnerbetrieb)
				}
				else delay_state=0x11;				// verz�gert einschalten
			}

			if(delay_state!=0) {				// wenn Verz�gerung, dann timer-Wert ins Flash schreiben  
				timercnt[objno]=delay_onoff|0x80;//delay_target=(delay_onoff<<delay_base)+timer;
				timerbase[objno]=delay_base|(delay_state & 0xF0);//write_delay_record(objno,delay_state,delay_target);
			}
			else timercnt[objno]= 0;//clear_delay_record(objno);    
		}
	}
}



void delay_timer(void)	// z�hlt alle 65ms die Variable Timer hoch und pr�ft Queue
{
	unsigned char objno,port_pattern,delay_zeit,delay_onoff,delay_base,n,m;
	unsigned int timerflags;
	
#ifdef HAND		// f�r Handbet�tigung
//	unsigned char n;
	unsigned char ledport;
	unsigned char Tasten=0;
#endif
	
	RTCCON=0x60;		// RTC anhalten und Flag l�schen
	RTCH=0x0E;			// reload Real Time Clock
	RTCL=0xA0;
	objno=0;

		timer++;
		timerflags = timer&(~(timer-1));
		for(n=0;n<16;n++){
			if(timerflags & 0x0001){// positive flags erzeugen und schieben
				for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
					if ((timerbase[m]& 0x0F)==n){// wenn die base mit der gespeicherten base �bereinstimmt
						if (timercnt[m]>0x80){// wenn der counter l�uft...
							timercnt[m]=timercnt[m]-1;// den timer [m]decrementieren
						}// end if (timercnt...
					}//end if(timerbase...
				}// end  for(m..
			}// end if timer...
			timerflags = timerflags>>1;
		}//end for (n=...
		
		// ab Hier die aktion...
		
		for(objno=0;objno<=7;objno++) {
//			delay_state=delrec[objno*4];
//			if(delay_state!=0x00) {			// 0x00 = delay Eintrag ist leer   
//				delval=delrec[objno*4+1];
//				delval=(delval<<8)+delrec[objno*4+2];
//				delval=(delval<<8)+delrec[objno*4+3];
				if(timercnt[objno]==0x80) {			// 0x00 = delay Eintrag ist leer   
//				if(delval==timer) { 
					portchanged=1;
					port_pattern=0x01<<objno;
					if(timerbase[objno]&0x10) { //if(delay_state==0x81) {	// einschalten
						if (((eeprom[RELMODE]>>objno)&0x01)==0x00) {				
							portbuffer=portbuffer|port_pattern;		// Einschalten (Schliesserbetrieb)
						}
						else {
							portbuffer=portbuffer&~port_pattern;	// Einschalten (�ffnerbetrieb)
						}
					timercnt[objno]=0;//delrec[objno*4]=0;
//						delrec[objno*4]=0;
						delay_zeit=eeprom[0xEA];
						delay_zeit=((delay_zeit>>objno)&0x01);
						if(delay_zeit==0x01) {
							delay_base=eeprom[(((objno+1)>>1)+0xF9)];   
							if((objno&0x01)==0x01) delay_base&=0x0F;
							else delay_base=(delay_base&0xF0)>>4;
							delay_onoff=eeprom[objno+0xE2];
							if (delay_onoff!=0x00 && delay_zeit!=0x00) {  
								timercnt[objno]=delay_onoff|0x80;//delay_target=(delay_onoff<<delay_base)+timer;
								timerbase[objno]=delay_base;//write_delay_record(objno,0x80,delay_target);		// Schaltverz�gerung in Flash schreiben
//								delay_target=(delay_onoff<<delay_base)+timer;
//								write_delay_record(objno,0x80,delay_target);		// Schaltverz�gerung in Flash schreiben
							}
						}
					}
					else {	// ausschalten
						if (((eeprom[RELMODE]>>objno)&0x01)==0x00) {
							portbuffer=portbuffer&~port_pattern;		// Ausschalten (Schliesserbetrieb)
						}
						else {
							portbuffer=portbuffer|port_pattern;			// Ausschalten (�ffnerbetrieb)
						}
						timercnt[objno]=0;//delrec[objno*4]=0;
					}
				//}
			}   
		}
	//}
		
#ifdef HAND		//+++++++   Handbet�tigung  ++++++++++

	if((TMOD&0x0F)==0x02 && fb_state==0) {
		ET1=0;
	#ifdef GS1
		while( TMOD&0x0F==0x02 && (PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen
	#endif
	#ifdef GS2
		#ifdef MAX_PORTS_8

		while(  (!PWM || (TL0>0x72)));// PWM scannen um "Hand"-Tasten abzufragen

		#endif
		#ifdef MAX_PORTS_4
		while( (TMOD&0x0F)==0x02 && ( TL0>0x72));// PWM scannen um "Hand"-Tasten abzufragen
		#endif
	#endif
		interrupted=0;	  
		Tasten=0;				

	#ifdef MAX_PORTS_8
		P1_3= 1;			    //int0 auf 1, wird �ber Dioden und taster auf low IO gezogen.
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
	#endif	
		
	#ifdef MAX_PORTS_4
		ledport=0x01;
		for (n=0;n<4;n++) {  						
			P0=~ledport;
			P0_5=1;			//P0.5 auf 1, wird �ber Dioden und taster auf low IO gezogen.
			if (!P0_5){
		  		Tasten=Tasten|ledport;
		  		objno=n;
		  		n=3;
		  	}
		  	ledport=ledport<<1;
		} 
	#endif
		
		//if (interrupted==1) Tasten=Tval;  // wenn unterbrochen wurde verwerfen wir die Taste
		REFRESH;
		//	Tasten = Tval; // ##############  <----- Hier wird Handbet�tigung quasi mit ausgeschaltet !! #########################
		if (Tasten != Tval)  {
			portbuffer=oldportbuffer;
		  	ledport=Tasten&~Tval; // ledport ist hier die Hilfsvariable f�r steigende Flanke
		  	if (ledport){
		  		portbuffer^=ledport; // bei gedr�ckter Taste toggeln
		  		portchanged=1;
		  	}
		  	Tval=Tasten;			//neue Tasten sichern
		}
		ET1=1;
	}
#endif
//	if (portchanged) port_schalten(portbuffer);				// Ausg�nge schalten
	RTCCON=0x61;		// RTC starten
//	delay_toggle=!delay_toggle;
}






void port_schalten(void)		// Schaltet die Ports mit PWM, DUTY ist Pulsverh�ltnis
{
	unsigned char n, pattern;

#ifdef SPIBISTAB	//serielle schiebeausgang f�r bistabile Relaise
		spi_2_out(sort_output(portbuffer));		// Ports schalten
		PWM=0;
		TF0=0;			// Timer 0 f�r Haltezeit Vollstrom verwenden
		TH0=0x6f;		// 16ms (10ms=6fff)
		TL0=0xff;
		TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;

	rm_state=portbuffer ^ eeprom[RMINV];	// R�ckmeldeobjekte setzen
	for (n=0;n<8;n++) {	// R�ckmeldung wenn ein Ausgag sich ge�ndert hat
		pattern=1<<n;
		if((portbuffer&pattern)!=(oldportbuffer&pattern)) send_obj_value(n+12);
	}

	oldportbuffer=portbuffer;
	portchanged=0;

#else	// also normaler out8 oder out4

	if(portbuffer & ~oldportbuffer) {	// Vollstrom nur wenn ein relais eingeschaltet wird
		TR0=0;
		AUXR1&=0xE9;	// PWM von Timer 0 nicht mehr auf Pin ausgeben
#ifdef GS1
		PWM=1;
#endif
#ifdef GS2
		PWM=0;			// Vollstrom an
#endif
		P0=portbuffer;		// Ports schalten
		TF0=0;			// Timer 0 f�r Haltezeit Vollstrom verwenden
		TH0=0x00;		// 16ms (10ms=6fff)
		TL0=0x00;
		TMOD=(TMOD & 0xF0) +1;		// Timer 0 als 16-Bit Timer
		TAMOD=0x00;
		TR0=1;
	}
	else P0=portbuffer;

	rm_state=portbuffer ^ eeprom[RMINV];	// R�ckmeldeobjekte setzen
	for (n=0;n<8;n++) {	// R�ckmeldung wenn ein Ausgag sich ge�ndert hat
		pattern=1<<n;
		if((portbuffer&pattern)!=(oldportbuffer&pattern)) rm_send|=pattern;		//send_obj_value(n+12);
	}

	oldportbuffer=portbuffer;
	portchanged=0;
	
#endif

}

unsigned int sort_output(unsigned char portbuffer){
   unsigned char diff;
   unsigned int result;
   diff=portbuffer ^ oldportbuffer;
   result=0;
   // A1 
   if (diff & 0x01){
	   if(portbuffer & 0x01){
		   result|=0x1000;
	   }
	   else{
		   result|=0x2000;
	   }
   }

   // A2
   if (diff & 0x02){
	   if(portbuffer & 0x02){
	      result|=0x0004;
	   }
	   else{
	      result|=0x0008;
	   }
   }
   // A3
   if (diff & 0x04){
	   if(portbuffer & 0x04){
	      result|=0x4000;
	   }
	   else{
	      result|=0x8000;
	   }
   }
   // A4
   if (diff & 0x08){
	   if(portbuffer & 0x08){
	      result|=0x0001;
	   }
	   else{
	      result|=0x0002;
	   }
   }
   
   // A5
   if (diff & 0x10){
	   if(portbuffer & 0x10){
	      result|=0x0040;
	   }
	   else{
	      result|=0x0080;
	   }
   }
   // A6
   if (diff & 0x20){
   	   if(portbuffer & 0x20){
	      result|=0x0100;
	   }
	   else{
	      result|=0x0200;
	   }
   }
   
   // A7
   if (diff & 0x40){
	   if(portbuffer & 0x40){
	      result|=0x0010;
	   }
	   else{
	      result|=0x0020;
	   }
   }
   // A8
   if (diff & 0x80){
	   if(portbuffer & 0x80){
	      result|=0x0400;
	   }
	   else{
	      result|=0x0800;
	   }
   }
   return result;

}


void spi_2_out(unsigned int daten){

   unsigned char n, unten, mitte;

   unten=daten & 0xFF;
   mitte=daten>>8;

   WRITE=0;
   CLK=0;
   for(n=0;n<=7;n++){
      

      BOT_OUT=(unten & 0x080)>>7;
      unten<<=1;
      
      MID_OUT=(mitte & 0x080)>>7;
      mitte<<=1;

      CLK=1;
      CLK=0;

   }

   WRITE=1;

   WRITE=0;

}






void bus_return(void)		// Aktionen bei Busspannungswiederkehr
{
	unsigned char n, bw, bwh, pattern;

	portbuffer=eeprom[PORTSAVE];	// Verhalten nach Busspannungs-Wiederkehr

	bw=eeprom[0xF6];
	for(n=0;n<=3;n++) {			// Ausg�nge 1-4
		bwh=(bw>>(2*n))&0x03;
		if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<n));
		if(bwh==0x02)  portbuffer=portbuffer | (0x01<<n);
	}

#ifdef MAX_PORTS_8
	bw=eeprom[0xF7];
	for(n=0;n<=3;n++) {			// Ausg�nge 5-8
		bwh=(bw>>(2*n))&0x03;
		if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<(n+4)));
		if(bwh==0x02)  portbuffer=portbuffer | (0x01<<(n+4));
	}
#endif

	oldportbuffer=0; 	// auf 0 setzen, da sonst kein Vollstrom aktiviert wird
	portchanged=1;		// Post hinterlegen damit in delaytimer nach portschalten springt


	rm_state=portbuffer ^ eeprom[RMINV];	// R�ckmeldeobjekte setzen


	// R�ckmeldung bei Busspannungswiederkehr

	for (n=0;n<8;n++) {	// R�ckmeldung nur f�r Objekte mit Wert 0, da Wert 1 in normelem schalten eh gesendet wird
		pattern=1<<n;
		if((~portbuffer)&pattern) send_obj_value(n+12);
	}
}


void restart_app(void) 		// Alle Applikations-Parameter zur�cksetzen
{
#ifdef HAND
	Tval=0x00;
#endif
	P0=0;
	P0M1=0x00;		// Port 0 Modus push-pull f�r Ausgang
#ifdef MAX_PORTS_8
	P0M2=0xFF;
#endif
#ifdef MAX_PORTS_4
	P0M2= 0x0F;
#endif	
 

#ifdef SPIBISTAB
	PWM=1;
#else 
	TMOD=(TMOD & 0xF0) + 2;		// Timer 0 als PWM
	TAMOD=0x01;
	TH0=DUTY;		// Pulsverh�ltnis PWM
	AUXR1|=0x10;	// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
	TR0=1;			// Timer 0 starten (PWM)
#endif
	ET0=0;			// Interrupt f�r Timer 0 sperren

	zf_state=0x00;		// Zustand der Zusatzfunktionen 1-4
	blocked=0x00;		// Ausg�nge nicht gesperrt
	timer=0;			// Timer-Variable, wird alle 130ms inkrementiert
  
	logicstate=0;
	delay_toggle=0;
	
	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
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
	WRITE_BYTE(0x01,0x07,0x01)	// Versionnumber of application programm
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0x9A)	// COMMSTAB Pointer
	STOP_WRITECYCLE
	EA=1;						// Interrupts freigeben
}
