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
#include "../com/fb_delay.h"
#include "../com/fb_prot.h"
#include "fb_app_in8.h"
#include "../com/fb_rs232.h"


unsigned char portbuffer,p0h;
unsigned int objstate;		// Zwischenspeicher der Objektzustände x.1 (Bit 0-7) und x.2 (Bit 8-15)
unsigned char blocked;			//zwischenspeicherung der Sperren
long timer;			// Timer für Schaltverzögerungen, wird alle 130ms hochgezählt
//unsigned char value[16];		


void pin_changed(unsigned char pinno)
{
	long duration=1;		// falls seitens ETS falsch programmiert 8ms default
	unsigned char timebase=0;
	unsigned char para_value=0;
	unsigned char tmp;
	unsigned char n;
	bit objval=0,jobj=0;
	bit st_Flanke=0;
	unsigned char pinnoX4,para_adr;
	//const unsigned char para_adr_feld[]={0xF6,0xF7,0xF7,0xF8,0xF8,0xF9,0xF9,0xFA};
	EX1=0;		// externen Interrupt 1 sperren
	pinnoX4=pinno*4;
	para_adr=0xD5+(pinnoX4);
	n;
  if (debounce(pinno))			// Entprellzeit abwarten und prüfen
  {
	timebase=(eeprom[0xF6+((pinno+1)>>1)]>>(4*((pinno&0x01)^0x01)))&0x07  ;
	st_Flanke=(((portbuffer>>pinno)&0x01)==0) && (((p0h>>pinno)&0x01)==1);
//	 for (n=0;n<8;n++){
//	}
	switch ((eeprom[0xCE+(pinno>>1)] >> ((pinno & 0x01)*4)) & 0x0F)	// Funktion des Eingangs
    {
     case 0x01:				// Funktion Schalten
        if(st_Flanke)	
        {
          schalten(1,pinno);			// steigende Flanke Eingang x.1
          schalten(1,pinno+8);			// steigende Flanke Eingang x.2
        }
        else
        {
          schalten(0,pinno);			// fallende Flanke Eingang x.1
          schalten(0,pinno+8);			// fallende Flanke Eingang x.2
        }
        send_cyclic(pinno);
      break;  
      case 0x02:				// Funktion Dimmen
    		/***********************
    		 * Funktion Dimmen
    		 ***********************/
    		// Taster gedrueckt -> schauen wie lange gehalten
            if (st_Flanke){// Taster gedrueckt -> schauen wie lange gehalten
  			duration=(eeprom[0xD7+(pinnoX4)]&0x7F);	// Faktor Dauer			
            // im Nachfolgenden wird die Zeitbasis geholt und schiebt duration nach links
			duration=duration << timebase;// Basis Dauer zwischen kurz und langzeit)	
  			duration+=timer;
  			objval=(read_obj_value(pinno+8)>>3)&0x01;
  			switch (eeprom[para_adr + 0x02]&0x70) {
  			case 0x00:	// UM Dimmen
  				objval = !objval;	// Dimmrichtung ändern
  				break;
  			case 0x10:				// zweiflaechen heller parametriert
  			case 0x30:
  				objval=1;
  				break;
  			default:	
  			//case 0x20:			// zweiflaechen dunkler parametriert
  			//case 0x40:
  				objval=0;
  			}
  			if(objval){	// wenn heller dimmen soll
  				write_delay_record(pinno, ((eeprom[para_adr+0x01]&0x38)>>3)+ 0x48, duration);	// dimmen
  				}
  			else{		// wenn dunkler dimmen soll
  				write_delay_record(pinno, (eeprom[para_adr+0x01]&0x07)+ 0x40, duration);	// dimmen
  				}
          }
  		else {		// Taster losgelassen
  			if (delrec[pinnoX4]) {		// wenn delaytimer noch laeuft, dann Schalten, also EIS1 telegramm senden
  				objval = read_obj_value(pinno);
  				switch (eeprom[para_adr]&0x70) {//Bedienkonzept angucken
  				case 0x10:	// zweiflaechen ein
  					objval=1;
  					break;
  				case 0x20:	// zweiflaechen aus
  					objval=0;
  					break;
  				default:	
  			//	case 0x00:	// UM Einflaeche
  			//	case 0x30:	// UM-heller
  			//	case 0x40:	// UM-dunkler
  					objval = !objval;
  				}
  				send_value(1,pinno,objval);
  				clear_delay_record(pinno);
  			}
  			else {	// Timer schon abgelaufen (also dimmen), dann beim loslassen stop-telegramm senden
  				tmp=read_obj_value(pinno+8);
  				if (eeprom[0xD5+(pinnoX4)] & 0x08) {	// ... natuerlich nur wenn parameter dementsprechend 
  					send_value(2, pinno+8, tmp & 0x08);		// Stop Telegramm
  				}
  				else while(!write_obj_value(pinno+8,tmp & 0x08));	// auch wenn Stopp Telegramm nicht gesendet wird, Objektwert auf 0 setzen
  			}
  			
  		}
        break;
       
        case 0x03:				//Funktion Jalousie
        	/****************************
        	 * Funktion Jalousie
        	 ****************************/
        	n=0xD8+(pinno*4);
			para_value=(eeprom[n]&0x30)>>4;//Jalofunktion holen
			switch (para_value){
				case 1:		//auf
					jobj=0;
				break;
				case 2:		//ab
					jobj=1;
				break;
				case 3:		//UM
	    			jobj=read_obj_value(pinno+8)^0x01;//neues Jaloobj invers zum langzeit
	    		break;
			}
			if (st_Flanke){// Taster gedrueckt -> schauen wie lange gehalten
            	if(eeprom[n]& 0x08){	//wenn Bedienkonzept lang-kurz ()
            		write_delay_record(pinno, jobj+0x80, timer+1);
            	}
            	else{								//wenn Bedienkonzept kurz-lang-kurz
	            	send_value(1, pinno, jobj);	// Kurzzeit telegramm immer bei Drücken senden
	    			duration=eeprom[0xD6+(pinno*4)];//Faktor Dauer )
	   			// im Nachfolgenden wird die Zeitbasis geholt und schiebt duration nach links
	    			duration=duration << timebase;// Basis Dauer zwischen kurz und langzeit)	
	     			duration+=timer;
	    			write_delay_record(pinno, jobj+0x80, duration);
	            }// ende Bedienkonzept lang-kurz-lang
            }//ende steigende Flanke
    		else {	// Taster losgelassen
  			if (delrec[pinno*4] & 0x10) send_value(1, pinno, jobj);	// wenn delaytimer noch laueft und in T2 ist, dann kurzzeit telegramm senden
    			else clear_delay_record(pinno);	// T2 bereits abgelaufen
    		}
        break;
 
    	/**********************************************************
    	 * Funktion Wertgeber Dimmen,Temparatur,Helligkeit
    	 **********************************************************/
        
        case 0x04:// Dimmwertgeber
        	para_value=0xFF;
        case 0x07:// Temperaturwertgeber
        case 0x08:// Helligkeitswertgeber,
        	para_value=para_value |0x1F;
        	//rs_send_hex(para_value);
        	n=0xD5+(pinno*4);
        	tmp=(((eeprom[n]&0x04)>>2)|(eeprom[n+1]&0x80)>>6);
			if (st_Flanke){// Taster gedrueckt
				if(tmp&0x01) send_value(54, pinno, eeprom[n+2]& para_value);	//Dimmwert senden
            }//ende steigende Flanke
    		else {	// Taster losgelassen dimmwert senden
  			if (tmp>=0x02) send_value(54, pinno, eeprom[n+tmp]& para_value);
    		}
         break;
 
         case 0x05:
    	/*******************************************
    	 * Funktion Wertgeber Lichtszenen
    	 *******************************************/
        	 n=0xD5+(pinno*4);
        	 para_value=eeprom[n] & 0x0C;
        	 
		if (st_Flanke){// Taster gedrueckt -> schauen wie lange gehalten
			if(para_value!=0x04) send_value(54, pinno,eeprom[n+2]&0x7F );	// Lichtszenennummer sanden
		}
		else{
			if(para_value>=0x04) send_value(54, pinno,eeprom[n+3]&0x7F );	// Lichtszenennummer sanden
		}
 	
        break;    
    }
  }
  IE1=0;	// IRQ 1 Flag zurücksetzen
  EX1=1;	// externen Interrupt 1 wieder freigeben
}
             


void send_cyclic(unsigned char pinno)
{
	pinno;
}


unsigned char operation(unsigned char pinno)
{
pinno;
return(1);
}


unsigned char switch_dim(unsigned char pinno)
{
pinno;
return(1);
}
/** 
* zaehlt alle 130ms die Variable Timer hoch und prueft records
*
* \param void
* @return void
*/
void delay_timer(void)
{
//unsigned char para_adr=0;
//unsigned char para_value=0;
	unsigned char objno, delay_state;
	long delval;
	long duration=1;
	bit jobj=0;
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

				if (delay_state & 0x80) { // 0x80, 0x81 für langzeit telegramm senden
						send_value(1, objno+8, delay_state & 0x01);	// Langzeit Telegramm senden
						// *** delay record neu laden für Dauer Lamellenverstellung ***

		    			duration=eeprom[0xD7+(objno*4)];	// Faktor Dauer	Lamelle	T2	
		    			if (duration>3){// wenn lamellenverstellzeit >3 dann zeit sichern und kurztele zwecks stop
		    				//d.h. bei minimum nach ETS Faktor=3 T2 ist abgeschaltet->kein stop
		    				//damit kann Jalousie als schalter mit 2 schaltebenen verwendung finden
		    				duration=duration << (eeprom[0xFA+((objno+1)>>1)]>>(4*((objno&0x01)^0x01)));
		    				duration += timer;
		    				jobj=read_obj_value((objno&0x07)+8);
		    				write_delay_record(objno, jobj|0x10, duration); // 0x10,0x11 fuer ende T2 (lamellenvestellzeit)
						}
						else clear_delay_record(objno);
					}
					
					if (delay_state & 0x10) clear_delay_record(objno); // wenn T2 abgelaufen dann nichts mehr machen
					
					if (delay_state & 0x40) { // 0x4? fuer Dimmer Funktion
						send_value(2, objno+8, delay_state );	// Langzeit Telegramm senden
						clear_delay_record(objno);
					}
				//}
			}
		}
	}
	start_rtc(130);		// RTC neu starten mit 8ms
}



void schalten(unsigned char risefall, unsigned char pinno)	// Schaltbefehl senden
{
  unsigned char func,sendval=0;
  func=eeprom[0xD7+((pinno&0x07)*4)];
  
  if (pinno<=7) {
	  if (risefall==1) func=(func>>2)&0x03;		// Funktion bei steigender Flanke
	  else func=func&0x03;						// Funktion bei fallender Flanke
  }
  else {
	  if (risefall==1) func=(func>>6)&0x03;		// Funktion bei steigender Flanke
	  else func=(func>>4)&0x03;					// Funktion bei fallender Flanke
  }

  if (func!=0)
  {
      if (func==0x03) sendval=(read_obj_value(pinno)^0x01);  //UM
      else sendval = func & 0x01;	// EIN   AUS
   	  send_value(1,pinno,sendval);
  }
}



/*
unsigned char pin_function(unsigned char pinno)		// Funktion des Eingangs ermitteln
{
pinno;
return(1);
}
*/
unsigned char debounce(unsigned char pinno)	// Entprellzeit abwarten und prüfen !!
{
  unsigned char debtime,n,ret;
  
  debtime=eeprom[DEBTIME];			// Entprellzeit in 0,5ms Schritten
  if (debtime>0) for(n=0;n<debtime;n++) delay(110);  
  if (((P0>>pinno)&0x01) == ((p0h>>pinno)&0x01)) ret=1;
  else ret=0; 
  return(ret);
}



void write_value_req(void)		// Objekt-Wert setzen gemäß empfangenem EIS  Telegramms
{
	unsigned char objno,objflags,gapos,atp,assno,n,gaposh,para_value,tmp;

    gapos=gapos_in_gat(telegramm[3],telegramm[4]);
    if (gapos!=0xFF)	
    {
    	send_ack();
    	atp=eeprom[ASSOCTABPTR];		// Association Table Pointer
    	assno=eeprom[atp];				// Erster Eintrag = Anzahl Einträge
 
    	for(n=0;n<assno;n++) {				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
    		gaposh=eeprom[atp+1+(n*2)];
    		if(gapos==gaposh) {					// Wenn Positionsnummer übereinstimmt
    			objno=eeprom[atp+2+(n*2)];			// Objektnummer
    			objflags=read_objflags(objno);		// Objekt Flags lesen
    			if((objflags&0x14)==0x14) {			// Kommunikation zulässig (Bit 2 = communication enable) + Schreiben zulässig (Bit 4 = write enable)
    				if (objno<16) {					// Status der Eingangsobjekte 0-15
    					//if (telegramm[7]==0x80) objstate&=(0xFFFF-(0x0001<<objno));
    					//if (telegramm[7]==0x81) objstate|=(0x0001<<objno);
    					while(!write_obj_value(objno,telegramm[7]&0x0F));
    				}
 //   				if (objno>7&&objno<16){ // zum Bsp Langzeitobjekte		
 //   					write_obj_value(objno,telegramm[7]&0x0F);
 //   				}
    				else{		//16-23 Sperrobjekte
    					tmp=telegramm[7]& 0x01;
    					if (read_obj_value(objno)^tmp) {
	    					while(!write_obj_value(objno,tmp));
	    					para_value= (eeprom[0xD5+((objno & 0x07)*4)]&0x03);
	    					tmp = tmp ^ ((para_value) & 0x01);
	    					if (para_value){			// wenn eine sperre aktiviert parametriert ist
	    						if(tmp){		//nicht gesperrt
	    							blocked=blocked & (~(0x01<<(objno&0x07)));
	    							sperren(objno,tmp);
	    						}
	    						else {			//gesperrt
	    							blocked=blocked |((tmp^0x01)<<(objno&0x07));
	    							sperren(objno,tmp);
	    						}
	    					}//ende if para_value
    					}//ende if read...
    				}//ende if objno>15
    			}//ende if objflags...
    		}//ende if gapos...
    	}// ende for n=....
    }// ende if gapos !=0
}// end function
    

void sperren (unsigned char obj,unsigned char freigabe)
{	
	bit objval=0;
	bit sending ;
	sending=1;
	obj=obj & 0x07;
	switch ((eeprom[0xCE+(obj>>1)] >> ((obj & 0x01)*4)) & 0x0F){// Funtion des zugehörigen Eingangs
	case 0x01:// funktion Schalten sperren
		switch ((eeprom[0xD5+(obj*4)]>>((freigabe^0x01)*2))&0x0C){

			case 0x04:		//EIN
				objval=1;
			break;
			case 0x08:		//AUS
				objval=0;
			break;
			case 0x0C:	//UM
				if (freigabe){ //ende sperre-> aktueller Zustand
				objval= (portbuffer>>obj)& 0x01;
				}
				else{	
    			objval=read_obj_value(obj)^0x01;//Tele invers senden
				}
			break;
			default:
			sending=0;
		}
		if (sending) send_value(1,obj,objval);
	break;	
	case 0x02:// funktion Dimmer-sperren
		objval = read_obj_value(obj);
		if (freigabe){		// Ende Sperre  
			if (eeprom[0xD5+(obj*4)]&0x80) objval=0;
			else sending=0;
		}
		else{				// Beginn Sperre
			switch (eeprom[0xD5+(obj*4)+1]& 0xC0) {//Bedienkonzept angucken
			case 0x40:	// zweiflaechen ein
				objval=1;
				break;
			case 0x80:	// zweiflaechen aus
				objval=0;
				break;
			case 0xC0:	// UM-heller
				objval = !objval;
				break;
			default:
			sending=0;
			}
		}
		if (sending) send_value(1,obj,objval);	// value senden
		
	break;
	case 0x03:// Funktion Jalousie - Sperren
		switch ((eeprom[0xD5+(obj*4)]>>((freigabe^0x01)*2))&0x0C){
			case 0x04:		//ab
				objval=0;
			break;
			case 0x08:		//auf
				objval=1;
			break;
			case 0x0c:	//UM
    			objval=read_obj_value(obj+8)^0x01;//neues Jaloobj invers zum langzeit
    		break;
			default:
			sending=0;	
		}
		if (sending) send_value(1,obj+8,objval);
	break;
	}// Ende switch funktion
	
	
}// End function



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
		if((objflags&0x0C)==0x0C) send_value(48,objno,objvalue);//eistype 1, nosafe, nosleftele
    }
}




void send_value(unsigned char type, unsigned char objno, int sval)	// sucht Gruppenadresse für das Objekt objno uns sendet ein EIS Telegramm
{				//|0x10->nosafe, |0x020 no selftele													// mit dem Wert sval
  int ga;
  unsigned char objtype;
  bit safe;
  bit selftele;

  if (type & 0x10){		// bei EIS Type +16 wird es nicht in obj_value gesichert
	  safe=0;
  	}
  else safe=1;
  if(type & 0x20){		// bei EIS Type +32 wird es nich nochmal selber aufgerufen
	  selftele=0;
  	}
  else selftele=1;
  type= type & 0x0F;
  
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
    	telegramm[7]+=sval & (0x03F);// auf 6 bit beschränken
    }//beschraänkung ändern im Aufruf!!s. oben!!
    
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
    if (safe)  while(!write_obj_value(objno, sval));	// Objektwert im USERRAM speichern
	if (selftele)write_value_req();				// eigenes Telegramm nochmal verarbeiten

    send_telegramm();

    IE1=0;
    EX1=1;
  }

}  




void delay(int w)	// delay ca. 4,5µs * w
{
	int n;
	for(n=w;n>0;n--) {}
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{
	unsigned char n;
	bit objval=0,senden;
	
  P0M1=0xFF;	//P0 auf input only (high impedance!)
  P0M2=0x00;
  P0=0xFF;

  transparency=0;
	stop_rtc();
	start_rtc(130);		// RTC neu mit 8ms starten
	timer=0;			// Timer-Variable, wird alle 8ms inkrementiert

  EA=0; 
  START_WRITECYCLE
  WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
  WRITE_BYTE(0x01,0x04,0x04);
  WRITE_BYTE(0x01,0x05,0x70);	// Geräte Typ (2118) 7054h
  WRITE_BYTE(0x01,0x06,0x54);  // 	"	"	"
  WRITE_BYTE(0x01,0x07,0x02);	// Versionsnummer
  WRITE_BYTE(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
  WRITE_BYTE(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
  WRITE_BYTE(0x01,0x12,0x84);	// COMMSTAB Pointer
  STOP_WRITECYCLE
  EA=1;
  
  //  ++++++++++++    Startverhalten bei Buswiederkehr ++++++++++
  for (n=0;n<8;n++){
	  senden=0;
	  switch ((eeprom[0xCE+(n>>1)] >> ((n & 0x01)*4)) & 0x0F)	// Funktion des objektes
		{
		case 0x01:// schalten
		case 0x03:// Jalousie
	//  case 0x04:// Wertgeber(lichtszene)		
			switch(eeprom[0xD5+(n*4)]&0xC0){
			case 0x40:
				objval=1;
				senden=1;
			break;	
			case 0x80:
				objval=0;
				senden=1;
			break;
			case 0xC0:
				objval=(p0h>>n);
				senden=1;
			// ansonsten nichst tun !	
			}
		break;
		case 0x02://dimmen austele
			if(eeprom[0xD7+(n*4)]&0x80){
				objval=0;
				senden=1;
				}
			if(eeprom[0xD8+(n*4)]&0x80){
				objval=1;
				senden=1;
			//ansonsten nichts tun !	
			}
  		}
	if (senden)send_value(17,n,objval);// eis1, kein selftele, speichern ja
	if(eeprom[0xD5+(n*4)]& 0x03) blocked=blocked | ((read_obj_value(n+16)& 0x01)<<n);
  }
  
  
  
}
