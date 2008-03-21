
#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_th.h"


const int cycleval[] = {27692, 462, 1385, 2308, 4615, 9231, 13846, 20769, 27692}; // Zykluszeit in 130ms

bit ow_init(void)		// one-wire Gerät initialisieren
{
  bit presence;
  unsigned char n;
  
  presence=1;
  OWDATA=0;
  delay(2000);
  OWDATA=1;
  for (n=0;n<200;n++) presence=presence && OWDATA;
  presence=!presence;
  return (presence);
}

void ow_write(unsigned char owbyte)	// Byte an one-wire Gerät senden
{
  unsigned char n,m;

  for (n=0;n<8;n++)		// LSB zuerst
  {
    if ((owbyte & (0x01<<n)) != 0)
    {
      for (m=0;m<2;m++) OWDATA=0;	// 1-Bit: 5µs auf low dann auf high und 85µs warten
      OWDATA=1;
      delay(260);
    }
    else
    {
      OWDATA=0;			// 0-Bit: 90µs auf low dann auf high
      delay(275);
      OWDATA=1;
    }
  }
}


unsigned char ow_read(void)			// Byte von one-wire Gerät lesen
{
  unsigned char n,m,b,d;
  
  d=0;
  for (n=0;n<8;n++)
  {
    for (m=0;m<2;m++) OWDATA=0;
    OWDATA=1;
    delay(1);
    b=OWDATA<<n;
    delay(140);
    d=d|b;
  }
  return(d);
}



bit ow_read_bit(void)				// Bit von one-wire Datenleitung einlesen
{
	unsigned char m;
	bit b;
	
	for (m=0;m<2;m++) OWDATA=0;
	OWDATA=1;
	delay(1);
	b=OWDATA;
	delay (140);
	return (b);
}


void start_tempconversion(void)		// Temperaturmessung starten
{
	if (ow_init()) {
		ow_write(0xCC);			// Skip-ROM command: alle parallel angeschlossenen Geräte werden angesprochen
		ow_write(0x44);			// start single temperature conversion command
	}
}

int read_temp(void)					// Temperatur einlesen und gem EIS5 umrechnen
{
	unsigned char lsb,msb;
	int t,t2;
	signed char corr;
  
  	if (ow_init()) {
  		ow_write(0xCC);			// Skip-ROM command: alle parallel angeschlossenen Geräte werden angesprochen
  		ow_write(0xBE);			// read scratchpad command: Speicher einlesen
  		lsb=ow_read();			// LSB von Temperaturwert
  		msb=ow_read();			// MSB von Temperaturwert
  		t2=((msb&0x07)<<8)+lsb;	// Umrechnen von Basis 1/16 auf Basis 1/100
  		t=t2*6;
  		t2=t2>>2;
  		t=t+t2;					// hier ist t die Teperatur in 0,01°C
  		corr=eeprom[TEMPCORR];	// Abgleichwert für Temperatur
  		t=t+(corr*10);
  		//t=t>>3;					// durch 8 teilen, da später Exponent 3 dazukommt
  		//t=t+((msb & 0x80)<<8);	// Vorzeichen
  		//t=t+(0x18 << 8);			// Exponent 3
  	}
  	else t=0xFFFF;				// im Fehlerfall 0xFFFF zurückmelden
  	return (t);
}


void temp_schwelle(bit schwelle)		// Temperaturschwelle prüfen und reagieren
{
	char schwellwert;
	unsigned char tempctrl, hysterese, tempwerth, tempwertl, objno, cycle;
	bit sendval, ignorelock, sendonceh, sendcyclich, sendoncel, sendcyclicl;
	bit templevel;
	long timerneu;

	
	if (!schwelle) { // Temperaturschwelle 1
		schwellwert=eeprom[TEMPSCHWELLWERT1];
		tempctrl=eeprom[TEMPCTRL1];
		sendval = (eeprom[FUNKTION]&0x04) >> 2;
		templevel = templevel1;
		tempwerth = eeprom[TEMPWERT1H];
		tempwertl = eeprom[TEMPWERT1L];
		objno = 6;
		cycle = eeprom[TEMPCYCLE1] & 0x07;
	}
	else { // Temperaturschwelle 2
		schwellwert=eeprom[TEMPSCHWELLWERT2];
		tempctrl=eeprom[TEMPCTRL2];
		sendval = (eeprom[FUNKTION] & 0x08) >> 3;
		templevel = templevel2;
		tempwerth = eeprom[TEMPWERT2H];
		tempwertl = eeprom[TEMPWERT2L];
		cycle = eeprom[TEMPCYCLE2] & 0x07;
		objno = 7;
	}
	ignorelock = (tempctrl & 0x08) >> 3;	// 0=Sperre ignorieren
	hysterese = tempctrl & 0x07;
	sendonceh = (tempctrl & 0x10) >> 4;
	sendcyclich = (tempctrl & 0x20) >> 5;
	sendoncel = (tempctrl & 0x40) >> 6;
	sendcyclicl = (tempctrl & 0x80) >> 7;
	timerneu = timer+cycleval[cycle];
	
	
	if (schwellwert<51) {			// wenn > 50 dann ist die Temp.-Schwelle inaktiv
		if (!((read_obj_value(10)==1) && (ignorelock==1))) {	// wenn Sperrobjekt nicht gesetzt oder Sperre ignorieren
			if (temp > (schwellwert*100)) {	//überschritten
				if ((sendonceh || sendcyclich) && !templevel) {	//wenn nur einmal odr zyklisch senden und erstes mal überschritten
					if (sendcyclich) write_delay_record(objno,1,timerneu);
					if (sendval) send_eis(6,objno,tempwerth);	// Wert senden
					else send_eis(1,objno,tempwerth);			// schalten
				}
				templevel=1;	// wurde überschritten
			}
			if (temp < ((schwellwert - hysterese)*100)) {	// unterschritten
				if ((sendoncel  || sendcyclicl) && templevel) {	//wenn nur einmal senden und erstes mal unterschritten
					if (sendcyclicl) write_delay_record(objno,1,timerneu);
					if (sendval) send_eis(6,objno,tempwertl);
					else send_eis(1,objno,tempwertl);
				}
				templevel=0;	// wurde unterschritten
			}
		}
	}
	if (schwelle) templevel2=templevel;
	else templevel1=templevel;
}






void send_eis(unsigned char eistyp, unsigned char objno, int sval)	// sucht Gruppenadresse für das Objekt objno uns sendet ein EIS 1 Telegramm
{														// mit dem Wert sval+0x80
  int ga;
  
  ga=find_ga(objno);					// wenn keine Gruppenadresse hintrlegt nix tun
  if (ga!=0)
  {
    telegramm[0]=0xBC;
    telegramm[1]=pah;
    telegramm[2]=pal;
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





void eis1(void)
{
	unsigned char objno;
	
	objno=find_objno(telegramm[3],telegramm[4]);
	if (objno!=0xFF) send_ack();
	
	if (objno==10) {
		if (telegramm[7]==0x81) write_obj_value(10,1);
		if (telegramm[7]==0x80) write_obj_value(10,0);
	}
}

void read_value_req(void)
{
}


void delay_timer(void)	// zählt alle 130ms die Variable Timer hoch und prüft Queue
{
  unsigned char objno,delay_state;
  long delval;
  int eis5temp;
  
  
  
  
  RTCCON=0x60;		// RTC anhalten und Flag löschen
  RTCH=0x1D;		// Real Time Clock
  RTCL=0x40;

  timer++;
  for(objno=0;objno<=7;objno++)
  {
    delay_state=userram[objno*5];
    
    delval=userram[objno*5+1];
    delval=(delval<<8)+userram[objno*5+2];
    delval=(delval<<8)+userram[objno*5+3];
    delval=(delval<<8)+userram[objno*5+4];
    
    if (objno==6) {	// Temperaturschwelle 1
    	if (delval==timer) {
    		if (!(eeprom[FUNKTION] & 0x04)) {	// schalten
    			if (((eeprom[TEMPCTRL1] & 0x30)==0x20) && templevel1) { // zykl. und überschr.
    				write_delay_record(6,1,timer+cycleval[eeprom[TEMPCYCLE1]&0x07]);
    				send_eis(1,6,eeprom[TEMPWERT1H]);
    				
    			}
    			if (((eeprom[TEMPCTRL1] & 0xC0)==0x80) && !templevel1) { // zykl. und unterschr.
    				write_delay_record(6,1,timer+cycleval[eeprom[TEMPCYCLE1]&0x07]);
    			    send_eis(1,6,eeprom[TEMPWERT1L]);    
    			}
    		}
    	}
    }
    if (objno==7) {	// Temperaturschwelle 2
        if (delval==timer) {
        	if (!(eeprom[FUNKTION] & 0x08)) {	// schalten
        		if (((eeprom[TEMPCTRL2] & 0x30)==0x20) && templevel2) { // zykl. und überschr.
        			write_delay_record(7,1,timer+cycleval[eeprom[TEMPCYCLE2]&0x07]);
        			send_eis(1,7,eeprom[TEMPWERT2H]);
        				
        		}
        		if (((eeprom[TEMPCTRL2] & 0xC0)==0x80) && !templevel2) { // zykl. und unterschr.
        			write_delay_record(7,1,timer+cycleval[eeprom[TEMPCYCLE2]&0x07]);
        		    send_eis(1,7,eeprom[TEMPWERT2L]);
        		}
        	}
        }
    }
    
    
    if(objno==1)							// 0x00 = queue Eintrag ist leer
    {   
      if(delval==timer)							// Ereignis ist eingetroffen
      {   
    	  if ((eeprom[TEMPPARAM]&0x0F)!=0) {
    	      write_delay_record(1,1,timer+cycleval[eeprom[TEMPPARAM]&0x0F]);
    	      
    	      eis5temp=temp>>3;					// durch 8 teilen, da später Exponent 3 dazukommt
    	      //eis5temp=eis5temp+((msb & 0x8000)<<8);	// Vorzeichen
    	      eis5temp=eis5temp+(0x18 << 8);			// Exponent 3   
    	      
    	      send_eis(5,1,eis5temp);
    	      lasttemp=temp;
    	  }	  
      }
    }   
  }
  RTCCON=0x61;		// RTC starten
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{
	
	unsigned char objno;

	P0M1=0x00;				// Port 0 Modus push-pull für Ausgang
	P0M2=0xFF;
  
	P3M1=0x00;				// Port 3_1 bidirektional
	P3M2=0x00;
	P3_1=1;
	

	
	start_writecycle();
	write_byte(0x01,0x04,0x01);	// Herstellercode 0x01 = Siemens
	write_byte(0x01,0x05,0x22);	// Geräte Typ (AP254) 221Ch
	write_byte(0x01,0x06,0x1C);	// 	"	"	"
	write_byte(0x01,0x07,0x01);	// Versionsnummer
	write_byte(0x01,0x0C,0x00);
	write_byte(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
	write_byte(0x01,0x12,0x56);	// COMMSTAB Pointer
	stop_writecycle();
  
  	for (objno=0;objno<8;objno++) write_delay_record(objno,0,0);
	if ((eeprom[TEMPCTRL1] & 0x30)==0x20) write_delay_record(6,1,10);	// falls Temperaturschwelle1 zyklisch gesendet werden soll 
	if ((eeprom[TEMPCTRL1] & 0xC0)==0x80) write_delay_record(6,1,15);
	if ((eeprom[TEMPCTRL2] & 0x30)==0x20) write_delay_record(7,1,20);	// falls Temperaturschwelle2 zyklisch gesendet werden soll
	if ((eeprom[TEMPCTRL2] & 0xC0)==0x80) write_delay_record(7,1,25);
	if ((eeprom[TEMPPARAM] & 0x0F)!=0x00) write_delay_record(1,1,30);	// falls Temperaturwert zyklisch gesendet werden soll
	
	start_tempconversion();
	while (!ow_read_bit());
	temp=read_temp();
	
	lasttemp=0;
}
