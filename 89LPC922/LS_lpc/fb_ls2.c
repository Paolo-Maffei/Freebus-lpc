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
//Audioaktor kann:
//      Dimmen
//      grundhellikeit
//      wertobjekt
//      einschalthellikeit
//      verhalten bei busspannungswiederkehr auch letzter wert
//      verhalten beim emfang eines wertes andimmen oder anspringen
//      dimmgeschwindikeit @TODO nicht fertig
//      lesen der objekte
//      rückmeldeobjekte 1bit + 1 byte
//      Lichtzenenfunktionen
//      Sperrfunktion für eingangsauswahl


//                eingangsauswahl über sperrobjekt
//      10.7.2009 Bass und höhen über lastausfall und kurzschlussobjekt
//       3.18    Progmode lässt sich per ets setzen
//               Interrupts beim retart aus, da sonst ggf. flashen unterbrochen wird wenn int
//               Ausführungszustand wird in Geräteinfo angezeigt
//               NACK wird bei fehlerhaft empfangenem Telegramm gesendet
//               Handsteuerung läuft



#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_ls.h"
#include "../com/fb_rs232.h"
#include "fb_i2c.h"


extern unsigned char Tval;
#define MAXDIMMWERT 255


unsigned char anspringen[DIMKREISE];          //andimmen (0) oder anspringen (1) [0]=K1
unsigned char dimm_helldunkel[DIMKREISE];          //9=heller 0=stop 1=dunkler
unsigned char dimm_I2C[DIMKREISE];
unsigned char dimmwert[DIMKREISE];
unsigned char mindimmwert[DIMKREISE];             //minimaldimmwert von der applikation
unsigned char einschathellikeit[DIMKREISE];
unsigned char mk[DIMKREISE]; //merker Kanal zum übertragen uber i2c
unsigned char sperren[DIMKREISE];             //Sperren oder nicht 1=sperren
unsigned char sel_audioinput[DIMKREISE];
unsigned char send_bass(unsigned char kanal,unsigned char wert);
unsigned char send_hoehen(unsigned char kanal,unsigned char wert);

unsigned int ie=0;              // dimmer immer wieder aktualisieren
//unsigned char faktor_dimmgeschwindikeit[DIMKREISE];
unsigned int basis_dimmgeschwindikeit[DIMKREISE];
unsigned char code hellikeit[]={0,25,40,53,67,80,95,120,140,160,180,200,0};
unsigned int code basis[]={0,1,16,260,4200,65000};
unsigned char faktor_zl[DIMKREISE];
unsigned int basis_zl[DIMKREISE];
unsigned char kanal_zl=0;
unsigned char andimm_zl=0;
unsigned char hoehen[DIMKREISE];
unsigned char bass[DIMKREISE];

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
    TMOD&=0xf0;   //register für Timer 0 löschen
    TMOD|=0x01;   // Timer 0 als reload, Timer 1 nicht ändern !
    TAMOD&=0xf0;
    TH0 = 0xff;
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
  mindimmwert[0]=(eeprom[0xc2]&0x0f)*80+10;
  mindimmwert[1]=(eeprom[0xc2]>>4)*80+10;

  basis_dimmgeschwindikeit[0]=basis[(eeprom[0xC6]&0x07)];
  basis_dimmgeschwindikeit[1]=basis[(eeprom[0xC6]>>4)&0x07];
  rs_send_s("M=");
  hoehen[0]=6; // 0db ==6
  hoehen[1]=6;
  bass[0]=6;
  bass[1]=6;

  rs_send(i2c_send_einstellungen()+0x30);
  rs_send_s(" ");


  rs_send_hex(mindimmwert[0]);
  rs_send_s(" ");
  rs_send_hex(mindimmwert[1]);
  rs_send_s(" ");
  EA=0;
  START_WRITECYCLE
  WRITE_BYTE(0x01,0x03,0x00);	// Herstellercode 0x0004 = Jung 0x0008 = Gira
  WRITE_BYTE(0x01,0x04,0x08);
  WRITE_BYTE(0x01,0x05,0x30);	// Device Type (2038.10) 2060h (0x3015 gira 1032)
  WRITE_BYTE(0x01,0x06,0x15);	// 	"	"	"
  WRITE_BYTE(0x01,0x07,0x01);	// Versionsnummer
  WRITE_BYTE(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
  WRITE_BYTE(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
  WRITE_BYTE(0x01,COMMSTABPTR,0x8a);	// COMMSTAB Pointer
  STOP_WRITECYCLE
  START_WRITECYCLE;
  WRITE_BYTE(0x00,0x60,0x2E);     // system state: all layers active (run), not in prog mode
  STOP_WRITECYCLE;
  EA=1;
}

void tr0_int(void) interrupt 1         //n=nummer 0x03+8*n
{
//  TH0=0x10;
  TL0=0x09;     // timer mit H=0xf9 L=0x09 2KHz = 0,5ms
  TH0=0xf9;     // timer mit 0xb7 200HZ = 5ms
  //P0_0 =! P0_0;

  if(ie<40000)                   //interwallmäsiges senden kann evetuel raus
    ++ie;
   else
    {
    i2c_send_einstellungen();
    i2c_send_daten(dimm_I2C[0]/4,dimm_I2C[1]/4);
    ie=0;
    }

  if(dimm_I2C[0]/4!=mk[0]||dimm_I2C[1]/4!=mk[1])   //i2c übertragen
     {
    /*  rs_send_s("Dimmwert=");
       rs_send_hex(dimm_I2C[0]);
       rs_send(' ');
       rs_send_hex(dimm_I2C[1]);
       rs_send_s("\n");
*/
       ie=0;
       mk[0]=dimm_I2C[0]/4;
       mk[1]=dimm_I2C[1]/4;
       if(mk[0]==0)             //verstärker 1 ausschalten
         P0_0=0;
       else P0_0=1;

       if(mk[1]==0)             //verstärker 2 ausschalten
         P0_1=0;
       else P0_1=1;
       i2c_send_daten(mk[0],mk[1]);
     }

   if(anspringen[0])
           dimm_I2C[0]=dimmwert[0];  //anspringen vom wert K1
   if(anspringen[1])
           dimm_I2C[1]=dimmwert[1];  //anspringen vom wert K2

    if(andimm_zl>8)                    //andimmern vom wert
     {
       andimm_zl=0;
       for(kanal_zl=0;kanal_zl<DIMKREISE;++kanal_zl)
         {
       if(dimmwert[kanal_zl]!=dimm_I2C[kanal_zl])        //andimmern von wert
          {
          if(dimm_I2C[kanal_zl] > dimmwert[kanal_zl])    //dunkler andimmen
                   dimm_I2C[kanal_zl]--;
          if(dimm_I2C[kanal_zl] < dimmwert[kanal_zl])    //heller andimmen
            {
            if(dimmwert[kanal_zl]<mindimmwert[kanal_zl])   // mit minimalwert Starten
               {
               dimm_I2C[kanal_zl]=mindimmwert[kanal_zl];
               dimmwert[kanal_zl]=dimm_I2C[kanal_zl];
               }
            else dimm_I2C[kanal_zl]++;
            }
          }
        }
      }
     else andimm_zl++;


   for(kanal_zl=0;kanal_zl<DIMKREISE;++kanal_zl)//basis und faktor für dimmstufen
     {
       basis_zl[kanal_zl]++;
       if(basis_zl[kanal_zl] > basis_dimmgeschwindikeit[kanal_zl])//1-65000
          {
          basis_zl[kanal_zl]=0;
          faktor_zl[kanal_zl]++;
          if(faktor_zl[kanal_zl] > eeprom[0xc8+(kanal_zl)])
             {
             faktor_zl[kanal_zl]=0;
             if(dimm_helldunkel[kanal_zl]>=9 && dimm_helldunkel[kanal_zl]<=0xf)        //heller=9
               {
               if(dimmwert[kanal_zl]<MAXDIMMWERT-1)
                 dimmwert[kanal_zl]+=2;
               }
             if(dimm_helldunkel[kanal_zl]>=1 && dimm_helldunkel[kanal_zl]<=7)        //dunkler=1
               {
                 if(dimmwert[kanal_zl]>mindimmwert[kanal_zl]+1)
                   dimmwert[kanal_zl]-=2;
               }
            }
         }
     }
  }







void main(void)
{
unsigned int i=0;
  unsigned char n;
  bit flag50hz=0;

  restart_hw();                           // Hardware zuruecksetzen
  for (n=0;n<50;n++) {
          set_timer0(0xFFFF);             // Warten bis Bus stabil
          while(!TF0);
  }
  restart_prot();			// Protokoll-relevante Parameter zurücksetzen
  rs_init();
  i2c_ma_init();
  restart_app();                        // Anwendungsspezifische Einstellungen zurücksetzen
  rs_send_s("Programmstart\n");
  do
      {
     //if(RTCCON>=0x80) delay_timer();	// Realtime clock Überlauf
      //
      // +++++ Handhabung des Programmiertasters und der ProgrammierLED +++++
      //
        TASTER=1;                                       // Pin als Eingang schalten um Taster abzufragen
        if(!TASTER) {                           // Taster gedrückt
            for(n=0;n<200;n++) {}   // Entprell-Zeit
            while(!TASTER);                 // warten bis Taster losgelassen

            //n=userram[0x60];
            //rs_send_hex(n);
            //n=n^0x81;
            //rs_send_hex(n);
            EA=0;
            START_WRITECYCLE;
            WRITE_BYTE(0x00,0x60,userram[0x60]^0x81);     // Prog-Bit und Parity-Bit im system_state toggeln
            STOP_WRITECYCLE;
            EA=1;

            //n=userram[0x60];
            //rs_send_hex(n);
            //rs_send_s("\n");
        }
        TASTER=!(userram[0x60] & 0x01);        // LED entsprechend Prog-Bit schalten (low=LED an)
        for(n=0;n<200;n++) {}           // falls Hauptroutine keine Zeit verbraucht, der LED etwas Zeit geben, damit sie auch leuchten kann
      }
  while(1)

    ;
}


