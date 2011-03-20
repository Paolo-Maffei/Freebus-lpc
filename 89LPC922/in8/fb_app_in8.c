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
#ifdef IN8_2TE
#include "spi.h"
#endif

//unsigned char prot_timer;
unsigned char portbuffer,p0h;
unsigned int objstate;		// Zwischenspeicher der Objektzustände x.1 (Bit 0-7) und x.2 (Bit 8-15)
unsigned char blocked;			//zwischenspeicherung der Sperren
unsigned char timer_base,timer_state;			// Timer für Schaltverzögerungen, wird alle 130ms hochgezählt
unsigned int timer;
unsigned char timerbase[TIMERANZ];// Speicherplatz für die Zeitbasis 
unsigned char timercnt[TIMERANZ];// speicherplatz für den timercounter und 1 status bit
unsigned char timerstate[TIMERANZ];//
unsigned char pinnoX4,para_adr,pinno;
unsigned char para_value;
unsigned int zaehlervalue[2];
unsigned char schrittzaehler[2];

bit objval=0,jobj=0;
bit st_Flanke=0;

//unsigned char value[16];		
//__code unsigned char __at 0x1C00 userram[]={......

void pin_changed(unsigned char pin_no)
{
//	long duration=1;		// falls seitens ETS falsch programmiert 8ms default
#ifdef zaehler
	int maxzaehler;
#endif
	unsigned char tmp;
	unsigned char objoffset=8;
	unsigned char typ=0;
	unsigned char n;
	timer_base=0;
	para_value=0;

	while(!TF1&&TR1);//ist was am Laufen warten wir besser mal ab....
	EX1=0;		// externen Interrupt 1 sperren
	pinno=pin_no;
	pinnoX4=pinno*4;
	para_adr=0xD5+(pinnoX4);
	n;
  if (debounce(pinno))			// Entprellzeit abwarten und prüfen
  {
	timer_base=(eeprom[0xF6+((pinno+1)>>1)]>>(4*((pinno&0x01)^0x01)))&0x07  ;
	st_Flanke=(((portbuffer>>pinno)&0x01)==0) && (((p0h>>pinno)&0x01)==1);
	timer_state=timerstate[pinno];
	//	 for (n=0;n<8;n++){
//	}
	switch ((eeprom[0xCE+(pinno>>1)] >> ((pinno & 0x01)*4)) & 0x0F)	// Funktion des Eingangs
    {
    case 0x01:				// Funktion Schalten
    	schalten(st_Flanke,pinno);			// Flanke Eingang x.1

#ifdef zykls	// mit zyklisch senden Eingang normal behandeln
		schalten(st_Flanke,pinno+8);		// Flanke Eingang x.2

#else			// ohne zyklisch senden dafür 2. schaltebene
        tmp=(eeprom[para_adr]&0x0C);//0xD5/ bit 2-3 zykl senden aktiv 2. Schaltebene
		if ((tmp==0x04 && st_Flanke==1)||(tmp==0x08 && st_Flanke==0)){
        	 timercnt[pinno]= eeprom[para_adr+1]+ 0x80;//0xD6 Faktor Dauer )
         	 timerbase[pinno]=0;
         	 timer_state = 0x20|st_Flanke;//speichern des portzustandes
         }
         else {// kein zyklsenden, bzw loslassen
         			timercnt[pinno]=0;
         			schalten(st_Flanke,pinno+8);		// Flanke Eingang x.2
         }
#endif
     break;  
      case 0x02:				// Funktion Dimmen
    		/***********************
    		 * Funktion Dimmen
    		 ***********************/
    		// Taster gedrueckt -> schauen wie lange gehalten
            if (st_Flanke){// Taster gedrueckt -> schauen wie lange gehalten
  			timercnt[pinno]=0x80+(eeprom[0xD7+(pinnoX4)]&0x7F);	// Faktor/Dauer			
			timerbase[pinno]=timer_base;

   			objval=(read_obj_value(pinno+8)>>3)&0x01;
  			switch (eeprom[para_adr]&0x70) {
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
  				timer_state = ((eeprom[para_adr+0x01]&0x38)>>3)+ 0x48;	// dimmen
  				}
  			else{		// wenn dunkler dimmen soll
  				timer_state = (eeprom[para_adr+0x01]&0x07)+ 0x40;	// dimmen
  				}
          }
  		else {		// Taster losgelassen
  			if (timercnt[pinno]>0x80) {		// wenn delaytimer noch laeuft, dann Schalten, also EIS1 telegramm senden
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
  				timercnt[pinno]=0;
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
            		//timerbase[pinno]=0;
            		timer_state = jobj+0x80;
            		timercnt[pinno]=0x80;//langzeit in delay_timer SOFORT ausführen
            	}
            	else{								//wenn Bedienkonzept kurz-lang-kurz
	            	send_value(1, pinno, jobj);	// Kurzzeit telegramm immer bei Drücken senden
	    			timercnt[pinno]=0x80+eeprom[0xD6+(pinno*4)];//Faktor Dauer )
	    			timerbase[pinno]=timer_base;
	    			// Zeit zwischen kurz und langzeit)	
	     			//
	    			timer_state = jobj+0x80;
	            }// ende Bedienkonzept lang-kurz-lang
            }//ende steigende Flanke
    		else {	// Taster losgelassen
  			if (timer_state & 0x10) send_value(1, pinno, jobj);	// wenn delaytimer noch laueft und in T2 ist, dann kurzzeit telegramm senden
    			else timercnt[pinno]=0;	// T2 bereits abgelaufen
    		}
        break;

#ifdef wertgeber 
    	/**********************************************************
    	 * Funktion Wertgeber Dimmen,Temparatur,Helligkeit
    	 **********************************************************/
       
        case 0x04:// Dimmwertgeber
        	para_value=0xFF;
        	typ=0x01;
        	objoffset=0;//läuft absichtlich in den nächsten case
        case 0x07:// Temperaturwertgeber
         	//para_value=para_value |0x1F; <--wird in Helligkeitswertgeber eh nochmal erledigt!
         	typ=typ|0x02;//kein objoffset zugewiesen,d.h. 8,da mit 8 initialisiert
        case 0x08:// Helligkeitswertgeber,
        	para_value=para_value |0x1F;
        	typ=typ|0x04;//kein objoffset zugewiesen,d.h. 8,da mit 8 initialisiert
        	n=0xD5+(pinno*4);
        	tmp=(((eeprom[n]&0x04)>>2)|(eeprom[n+1]&0x80)>>6);//in tmp steigend fallend reaktion
			if (st_Flanke){// Taster gedrueckt       in tmp bit0 steigend, bit1 fallend
				if(tmp&0x01) send_value(49, pinno+objoffset, eis5conversion((eeprom[n+2]& para_value),typ));	//wert senden
            }//ende steigende Flanke
    		else {	// Taster losgelassen dimmwert senden
  			if (tmp>=0x02) send_value(49, pinno+objoffset, eis5conversion(eeprom[n+tmp]& para_value,typ));
    		}
         break;
 
         case 0x05:
    	/*******************************************
    	 * Funktion Wertgeber Lichtszenen
    	 *******************************************/
        	 n=0xD5+(pinno*4);
        	 para_value=eeprom[n] & 0x0C;
        	 
		if (st_Flanke){// Taster gedrueckt -> schauen wie lange gehalten
			if(para_value!=0x04) send_value(49, pinno,eeprom[n+2]&0x7F );	// Lichtszenennummer senden
		}
		else{
			if(para_value>=0x04) send_value(49, pinno,eeprom[n+3]&0x7F );	// Lichtszenennummer senden
		}
 	
        break;
#endif        

        
#ifdef zaehler         
         case 0x09:
        	/*******************************************
        	 * Funktion Impulszaehler
        	 *******************************************/
        	n=eeprom[0xD5+(pinno*4)];// Parameter Flanke für Zählimpuls
        	if (pinno<=1){// pinno 0-1 Zähleingnag
        		if ((n&0x01 && st_Flanke)||(n&0x02 &! st_Flanke)){
        			if (zaehlervalue[pinno]< 0xFFFF)zaehlervalue[pinno]++;
        		}
        	}
        	else{ //pinno also grösser 1, bei Impulszähler hier die Syncron eingänge
        		n=eeprom[0xD5+((pinno-2)*4)];// Parameter Flanke für Zählimpuls
        		if ((n&0x04 && st_Flanke)||(n&0x08 &! st_Flanke)){
        			if (pinno==2){
        				zaehlervalue[0]=0;//pinno-2 , da die parameter den zählereingangen zugeordnet sind
        				timercnt[0]=eeprom[0xD6]|0x80;//Torzeit setzen
        				timerbase[0]=((eeprom[0xF6]&0xF0)>>4)|0x80;
        			}
        			else{
        				zaehlervalue[1]=0;//pinno-2 , da die parameter den zählereingangen zugeordnet sind
        				timercnt[1]=eeprom[0xD6]|0x80;//Torzeit setzen
        				timerbase[1]=((eeprom[0xF7]&0x0F))|0x80;
        				
        			}
        		}
        		n = n & 0xF0;
        		tmp=0;
        		if (st_Flanke){// telegramme bei synceingang
        			if(n==0x40||n==0x60)tmp=0x11;
        			if(n==0x80||n==0x90)tmp=0x10;
        			if(n==0xC0||n==0xF0)tmp=0x12;
        		}
        		else {			// fallende flanke
        			if(n==0x10||n==0x90)tmp=0x11;
        			if(n==0x20||n==0x60)tmp=0x10;
        			if(n==0x30||n==0xF0)tmp=0x12;
        		}
        		if (tmp==0x12)tmp= (read_obj_value(pinno)^0x01)|0x10;
        		if(tmp){	send_value(1,pinno,tmp&0x01);
        		}
       		}
        	
        	break;
        case 10:
        	
        	n=eeprom[0xD5+(pinno*4)];// Parameter Flanke für Zählimpuls
            	if ((n&0x01 && st_Flanke)||(n&0x02 &! st_Flanke)){
            		zaehlervalue[pinno]++; // zählwert erhöhen
            		schrittzaehler[pinno]++;// schrittzähler erhöhen
            		maxzaehler=(eeprom[para_adr +2]<<8) +eeprom[para_adr+3];
            		tmp=0;                                 
            		if (zaehlervalue[pinno]>=maxzaehler){// wenn zählwert erreicht
            			tmp=(n>>6);// parameter für ausgange 1Bit
            			if (tmp==0x03)tmp= (read_obj_value(pinno)^0x01);//UM
                		if (tmp==0x02)tmp=0;// AUS
            			send_value(1,pinno,tmp);// 1Bit objekt senden
            			send_value(40,pinno+8,zaehlervalue[pinno]);//16Bit objekt senden
                		schrittzaehler[pinno]=0;// reset schritt
                		zaehlervalue[pinno]=0;// reset Zähler
                	}
                	if(schrittzaehler[pinno]>=eeprom[para_adr+1]){// wenn schrittzählerwert erreicht
            			send_value(40,pinno+8,zaehlervalue[pinno]);// 16Bit objekt senden
                		schrittzaehler[pinno]=0;			// reset schrittzähler
                	}
            	}
        
        	break;
#endif        	
    }
	timerstate[pinno]=timer_state;
  }
  IE1=0;	// IRQ 1 Flag zurücksetzen
  EX1=1;	// externen Interrupt 1 wieder freigeben
}

#ifdef wertgeber
int eis5conversion(int zahl,unsigned char Typ)
{
	unsigned char exp=0;
	unsigned int wert=0;
	if (Typ==4){// Helligkeitwert
		exp=3;// Da kleinster wert 50 lux*100=5000 ==> 5000/8 (exp=3) 
	 	wert=zahl*625;//= 625
	}
	if (Typ==6){// Temperaturwert kleinster wert =1 größter 31
		
		wert=zahl*100;// Hier reicht uns eine 16bit int var
	}
	if (Typ==7){// wenn Dimmwert ( EIS2, also keine Fließkomma)
		wert=zahl;
	}
	else{// fließkomma EIS5 berechnen
	 		while (wert > 2047){//solange Mantisse größer 11 Bit
	 			wert=wert>>1;// Mantisse /2
	 			exp++;// und exponent um 1 erhöhen (ist ein 2^exp)
	 		}
	}
 	return (wert+(exp<<11));// exponent dazu, geht auch bei EIS2 da EXP hier 0 ist.
}
#endif

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
	unsigned char  objno,m,n;
	unsigned int timerflags;
	bit jobj=0;

	
	SET_RTC(65)// timer auf die hälfte der kleinsten basis setzen


	timer++;
	timerflags = timer&(~(timer-1));// flanke generieren
	for(n=0;n<16;n++){
		if(timerflags & 0x0001){// positive flags erzeugen und schieben
			for(m=0;m<TIMERANZ;m++){// die timer der reihe nach checken und dec wenn laufen
				if ((timerbase[m]& 0x0F)==n){// wenn die base mit der gespeicherten base übereinstimmt
					if (timercnt[m]>0x80){// wenn der counter läuft...
						timercnt[m]=timercnt[m]-1;// den timer[m]decrementieren
					}// end if (timercnt...
				}//end if(timerbase...
			}// end  for(m..
		}// end if timer...
		timerflags = timerflags>>1;
	}//end for (n=...
//	if (connected ){		//timer für timer-overflow connect 
//		if(con_timer_refresh){
//			timercnt[PROTTIMER]=0xAE;// wenn connected und refresh timeout timer neu setzen
//			con_timer_refresh=0;
//		}
		//else timercnt[PROTTIMER]--;
//	}
//	else timercnt[PROTTIMER]=0x00;// wenn nicht connected timeout timer ausschalten
	
//	if (timercnt[PROTTIMER]==0x80)T_Disconnect();//Verbindungsabbau wegen timeout
	
// Im folgenden die Aktionen bei abgelaufenen Timern
	for(objno=0;objno<8;objno++) {
		timer_state=timerstate[objno];
		if(timercnt[objno]==0x80) {
#ifndef zykls
		if (timer_state & 0x20){
#ifdef test //zykls
					schalten(timer_state & 0x01,objno);
					jobj=read_obj_value((objno&0x07)+8);
					if(timerbase[objno]<15){
						schalten(jobj,objno+8);
					}
					timercnt[objno]=(eeprom[0xD6+(objno*4)]&0x7F)+0x80;
#endif
 
					schalten(timer_state & 0x01,objno+8);
					//timerbase[objno]=0;
					timercnt[objno]=0;
					//timerstate=0;
				}
#endif
			if (timer_state & 0x80) { // 0x80, 0x81 für langzeit telegramm senden
						send_value(1, objno+8, timer_state & 0x01);	// Langzeit Telegramm senden
						// *** delay record neu laden für Dauer Lamellenverstellung ***

		    			m = eeprom[0xD7+(objno*4)];	// Faktor Dauer	Lamelle	T2	
		    			if (m > 3){// wenn lamellenverstellzeit >3 dann zeit sichern und kurztele zwecks stop
		    				//d.h. bei minimum nach ETS Faktor=3 T2 ist abgeschaltet->kein stop
		    				//damit kann Jalousie als schalter mit 2 schaltebenen verwendung finden
		    				timerbase[objno]= ((eeprom[0xFA+((objno+1)>>1)]>>(4*((objno&0x01)^0x01)))&0x07);
		    				jobj=read_obj_value((objno&0x07)+8);
		    				timerstate[objno]= jobj|0x10; // 0x10,0x11 fuer ende T2 (lamellenvestellzeit)
		    				timercnt[objno]= m + 0x80;
		    			}
						else timercnt[objno]=0;
		    			//timerbase[objno]=0;
				}
					
				if (timer_state & 0x10) timercnt[objno]=0; // wenn T2 abgelaufen dann nichts mehr machen
					
				if (timer_state & 0x40) { // 0x4? fuer Dimmer Funktion
						send_value(2, objno+8, timer_state );	// Langzeit Telegramm senden
						timercnt[objno]=0;
				}
				if(timer_state==0 && (timerbase[objno]& 0x80)==0x80){//Impulszähler
        			timercnt[objno]=eeprom[0xD6+(objno)*4]|0x80;//Torzeit setzen
        			timerbase[objno]=(eeprom[0xF6+((objno+1)>>1)]>>(4*((objno&0x01)^0x01)))|0x80;
        			send_value(40,objno+8,zaehlervalue[objno]);
        			zaehlervalue[objno]=0;
				}
			}
		}
	//}
	START_RTC	// RTC starten
}


void schalten(bit risefall, unsigned char pinno)	// Schaltbefehl senden
{
	unsigned char func,sendval=0;

		func=eeprom[0xD7+(pinno & 0x07)*4]; //0xD7
		if (pinno>=8)func=func>>4;			// wenn 2. Schaltobjekt dann obere 4 bit
		if (risefall) func=(func>>2);		// Funktion bei steigender Flanke obere 2 bit
		func=func&0x03;					// Funktion maskieren
		if (func!=0)
		{
			if (func==0x03) sendval=read_obj_value(pinno) ^0x01;  //UM
			else sendval = func & 0x01;	// EIN   AUS
			send_value(1,pinno,sendval);
		}
	
}





unsigned char debounce(unsigned char pinno)	// Entprellzeit abwarten und prüfen !!
{
  unsigned char debtime,n,w,ret;//,port_help;
  debtime=eeprom[DEBTIME];			// Entprellzeit in 0,5ms Schritten
  if (debtime>0) for(n=0;n<debtime;n++){
	  	for(w=112;w>0;w--) {}// delay ca. 4,5µs
  }

#ifndef IN8_2TE
  if (((P0>>pinno)&0x01) == ((p0h>>pinno)&0x01)) ret=1;
  else ret=0;
#else
  if (((spi_in_out()>>pinno)&0x01) == ((p0h>>pinno)&0x01)) ret=1;
  else ret=0;
#endif

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
    if (safe)  while(!write_obj_value(objno, sval));	// Objektwert im USERRAM speichern
    while(!TF1&&TR1);//ist was am Laufen warten wir besser mal ab....
    EX1=0;
 //   do{
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
  
    	if (selftele)write_value_req();				// eigenes Telegramm nochmal verarbeiten

    	send_telegramm();
//    }
    IE1=0;
    EX1=1;
  }

}  





void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{
	unsigned char n;
	bit objval=0,senden;

#ifndef IN8_2TE
	P0M1=0xFF;	//P0 auf input only (high impedance!)
	P0M2=0x00;
	P0=0xFF;
#else
	P0M1=0x00;	// P0_1 Biderektional Rest PushPull
	P0M2=0xFD;
	P0=0x22;	// WRITE=1 SER_IN=1
#endif

  transparency=0;
//	stop_rtc();
//	start_rtc(130);		// RTC neu mit 8ms starten
	timer=0;			// Timer-Variable, wird alle 65ms inkrementiert

  EA=0; 
  START_WRITECYCLE
  WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
  WRITE_BYTE(0x01,0x04,0x04)
  WRITE_BYTE(0x01,0x05,0x70)	// Geräte Typ (2118) 7054h
  WRITE_BYTE(0x01,0x06,0x54)  // 	"	"	"
  WRITE_BYTE(0x01,0x07,0x02)	// Versionsnummer
  WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
  WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
  WRITE_BYTE(0x01,0x12,0x84)	// COMMSTAB Pointer
  STOP_WRITECYCLE

  START_WRITECYCLE;
  WRITE_BYTE(0x00,0x60,0x2E);	// system state: all layers active (run), not in prog mode
  STOP_WRITECYCLE;

  EA=1;
  //  ++++++++++++    Startverhalten bei Buswiederkehr ++++++++++
  for (n=0;n<8;n++){
	  senden=0;
	  timercnt[n]=0;// alle timer ausschalten
	  switch ((eeprom[0xCE+(n>>1)] >> ((n & 0x01)*4)) & 0x0F)	// Funktion des objektes
		{
		case 0x01:// schalten
		timerstate[n]=0;
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
		break;
		case 0x09:	// timer für impulszähler starten falls kein sync angeschlossen 
			if (n<=1){
				timercnt[n]=0x80;
				timerbase[n]=0x80;
			}
		//breake;
  		}
	if (senden)send_value(17,n,objval);// eis1, kein selftele, speichern ja
	if(eeprom[0xD5+(n*4)]& 0x03) blocked=blocked | ((read_obj_value(n+16)& 0x01)<<n);
  }
  
  
  
}
