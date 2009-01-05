/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2008 Andreas Krebs <kubi@krebsworld.de>
 *                   Richard Weissteiner richard@seelaus.at
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */


//              umbau anfang zum dimmer (Gira 1032) 30.12.2008
//dimmer kann:
//      Dimmen
//      grundhellikeit
//      wertobjekt
//      einschalthellikeit
//      verhalten bei busspannungswiederkehr auch letzter wert
//      verhalten beim emfang eines wertes andimmen oder anspringen
//      dimmgeschwindikeit
//      lesen der objekte
//      rückmeldeobjekte 1bit + 1 byte
//      Lichtzenenfunktionen
//      Sperrfunktion

//dimmer kann nicht: @TODO noch viele kleinikeiten zb

//      zeitfunktionen
//      ausschalfunktion


#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_dim.h"
#include "../com/fb_rs232.h"
#include "fb_i2c.h"

extern unsigned char Tval;
#define MAXDIMMWERT 250


unsigned char anspringen[DIMKREISE];          //andimmen (0) oder anspringen (1) [0]=K1
unsigned char dimm_helldunkel[DIMKREISE];          //9=heller 0=stop 1=dunkler
unsigned char dimm_I2C[DIMKREISE];
unsigned char dimmwert[DIMKREISE];
unsigned char mindimmwert[DIMKREISE];             //minimaldimmwert von der applikation
unsigned char einschathellikeit[DIMKREISE];
unsigned char mk[DIMKREISE]; //merker Kanal zum übertragen uber i2c
unsigned char sperren[DIMKREISE];             //Sperren oder nicht 1=sperren
unsigned int ie=0;              // dimmer immer wieder aktualisieren
unsigned char dimmgeschwindikeit=0;
unsigned char code hellikeit[]={0,25,40,53,67,80,95,120,140,160,180,200,0};



unsigned char helligkeittsstufe(unsigned char stufe,unsigned char kanal)
{
  if(stufe == 1)
    return mindimmwert[kanal];
  if(stufe == 0x0b)
    return MAXDIMMWERT;
  if(stufe == 0x0c)
    return read_obj_value(kanal+4);
  return hellikeit[stufe];
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{
    //Timer0 einstellen
    TMOD&=0xf0;   //register löschen
    TMOD|=0x01;   // Timer 0 als reload, Timer 1 nicht ändern
    TAMOD&=0xf0;
    TH0 = 0;
    AUXR1&=~0x10;             // toggled whenever Timer0 overflows ausschalten
    ET0=1;                        // Interrupt für Timer 0 freigeben
    TR0=1;                        // Timer 0 starten
    EA=1;

    Tval=0x00;

  P0M1=0x00;				// Port 0 Modus push-pull für Ausgang
  P0M2=0xFF;

  anspringen[0]=(eeprom[0xC6]&(1<<3))>>3;
  anspringen[1]=(eeprom[0xC6]&(1<<7))>>7;
  einschathellikeit[0]=eeprom[0xC4]&0x0f;       //wert 0 - 0x0c
  einschathellikeit[1]=eeprom[0xC4]>>4;         //wert 0 - 0x0c
  dimmwert[0]=helligkeittsstufe(eeprom[0xe2]&0x0f,0);     //Verhalten bei Busspannungswiederkehr
  dimmwert[1]=helligkeittsstufe((eeprom[0xe2]>>4)&0x0f,1);//Verhalten bei Busspannungswiederkehr
  mindimmwert[0]=(eeprom[0xc2]&0x0f)*10+10;
  mindimmwert[1]=(eeprom[0xc2]>>4)*10+10;

  start_writecycle();
  write_byte(0x01,0x03,0x00);	// Herstellercode 0x0004 = Jung 0x0008 = Gira
  write_byte(0x01,0x04,0x08);
  write_byte(0x01,0x05,0x30);	// Device Type (2038.10) 2060h (0x3015 gira 1032)
  write_byte(0x01,0x06,0x15);	// 	"	"	"
  write_byte(0x01,0x07,0x01);	// Versionsnummer
  write_byte(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
  write_byte(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
  write_byte(0x01,COMMSTABPTR,0x8a);	// COMMSTAB Pointer
  stop_writecycle();
}


void tr0_int(void) interrupt 1          //n=nummer 0x03+8*n
{
  TH0=0x10;
  P0_0 =! P0_0;         //@TODO: testled raus

  if(ie<4000)
    {
    ++ie;
    }
   else
    {
    i2c_send_daten(dimm_I2C[0],dimm_I2C[1]);
    ie=0;
    }

   if(anspringen[0])
           dimm_I2C[0]=dimmwert[0];  //anspringen vom wert
   else
   {
           if(dimm_I2C[0] > dimmwert[0])
                   dimm_I2C[0]-=1;
           if(dimm_I2C[0] < dimmwert[0])
                   dimm_I2C[0]+=1;
   }

   if(anspringen[1])
           dimm_I2C[1]=dimmwert[1];  //anspringen vom wert
   else
   {
           if(dimm_I2C[1] > dimmwert[1])
                   dimm_I2C[1]-=1;
           if(dimm_I2C[1] < dimmwert[1])
                   dimm_I2C[1]+=1;
   }
   if(dimm_I2C[0]!=mk[0]||dimm_I2C[1]!=mk[1])
     {
    /*  rs_send_s("Dimmwert=");
       rs_send_hex(dimm_I2C[0]);
       rs_send(' ');
       rs_send_hex(dimm_I2C[1]);
       rs_send_s("\n");
*/
       ie=0;
       mk[0]=dimm_I2C[0];
       mk[1]=dimm_I2C[1];
       i2c_send_daten(dimm_I2C[0],dimm_I2C[1]);
     }





 //Dimmgeschwindikeit
  dimmgeschwindikeit=dimm_helldunkel[0]&0x07;
  if(dimmwert[0] <= (MAXDIMMWERT-dimmgeschwindikeit)&&(dimm_helldunkel[0]&8)!=0)   //heller 9( bit 3 heller dunkler ,bit 0-2 geschwindikeit)
        {
        if(dimmwert[0]<mindimmwert[0])
                dimmwert[0]=mindimmwert[0];
        else
                dimmwert[0]+=dimmgeschwindikeit;
        }
  if(dimmwert[0] >= (mindimmwert[0]+dimmgeschwindikeit) && (dimm_helldunkel[0]&8)==0)      //dunkler
        {
        dimmwert[0]-=dimmgeschwindikeit;
        }

  dimmgeschwindikeit=dimm_helldunkel[1]&0x07;
  if(dimmwert[1] <= (MAXDIMMWERT-dimmgeschwindikeit)&&(dimm_helldunkel[1]&8)!=0)   //heller 9( bit 3 heller dunkler ,bit 0-2 geschwindikeit)
        {
        if(dimmwert[1]<mindimmwert[1])
                dimmwert[1]=mindimmwert[1];
        else
                dimmwert[1]+=dimmgeschwindikeit;
        }
  if(dimmwert[1] >= (mindimmwert[1]+dimmgeschwindikeit) && (dimm_helldunkel[1]&8)==0)      //dunkler
        dimmwert[1]-=dimmgeschwindikeit;
}




void main(void)
{
unsigned int i=0;
  unsigned char n;
  restart_hw();				// Hardware zurücksetzen
  restart_prot();			// Protokoll-relevante Parameter zurücksetzen
  rs_init();
  i2c_init();
  restart_app();                        // Anwendungsspezifische Einstellungen zurücksetzen
  rs_send_s("Programmstart\n");
  do
      {
     //if(RTCCON>=0x80) delay_timer();	// Realtime clock Überlauf
      //
      // +++++ Handhabung des Programmiertasters und der ProgrammierLED +++++
      //
      TASTER=1;				        // Pin als Eingang schalten um Taster abzufragen
      if(!TASTER)
        {					// Taster gedrückt
        for(n=0;n<100;n++) {}
        while(!TASTER);				// warten bis Taster losgelassen
        progmode=!progmode;
        }
      TASTER=!progmode;				// LED entsprechend schalten (low=LED an)
      for(n=0;n<100;n++) {}
      }
  while(1)

    ;
}


