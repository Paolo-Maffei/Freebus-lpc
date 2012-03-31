/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2008 Andreas Krebs <kubi@krebsworld.de>
 *                      Richard Weissteiner richard@seelaus.at
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *
 *
 * 30 12. 2008 umbau auf dimmer begonnen org file fb_app_out.c
 *
 *
 */

#include "fb_app_dim.h"
#include "DEBUG.h"
#include <P89LPC922.h>
#include "fb_lpc9xx.h"
#include "fb_app_dim.h"
#include "fb_uni_dim.h"


//#ifdef IncludeRS232
#include "fb_rs232.h"
//#endif


/******************************************/
extern byte Tval;
#define MAXDIMMWERT 255

// Stufe                        0 1  2  3  4   5   6   7   8   9 10   11  12  13  14
byte __code helligkeitsstufe[]={0,1,25,51,76,102,127,153,178,204,230,255,255,255,255};
uint __code basis[]={0,1,0x10,0x100,0x1000,0xFFFF};

__idata byte einschalthelligkeit[AnzahlKanaele];	// parametr. Einschalthelligkeit
__idata byte anspringen[AnzahlKanaele];          	// parametriert: andimmen (0) oder anspringen (1)
__idata byte sperren[AnzahlKanaele];             	// parametrierte Sperren    1=sperren
__idata uint dimmgeschwindikeit[AnzahlKanaele];		// parametrierte Dimmgeschwindigkeit
__idata uint softEinGeschwindikeit[AnzahlKanaele];	// parametrierte Dimmgeschwindigkeit Soft-Ein
__idata uint softAusGeschwindikeit[AnzahlKanaele];	// parametrierte Dimmgeschwindigkeit Soft-Aus
__idata uint softEin[AnzahlKanaele];				// Soft-Ein aktiv
__idata uint softAus[AnzahlKanaele];				// Soft-Aus aktiv
__idata volatile byte IstKurzschluss[2];			//
__idata volatile byte IstSpannungsausfall[2];		//

byte RueckmeldungPending[AnzahlKanaele];			// Rückmeldung muss noch gesendet werden


/**
 *  Initialisierung der Applikationsparameter
 */
void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{
#ifdef debug_restart_app
	rs_send_s("\nrestart_app");
#endif
	//@todo Bug in der LIB, Prio für PT1 von 0 auf 2 gesetzt,  ist das in der neuenLIB noch nötig?
	SET_BIT(IP0H,3);

	ud_init();	// Dimmer initialisieren
	// Einschaltwerte
	einschalthelligkeit[0]=eeprom[0xC4]&0x0f;       //wert 0 - 0x0c
	einschalthelligkeit[1]=eeprom[0xC4]>>4;         //wert 0 - 0x0c
	// Dimmmodus
	anspringen[0]=(eeprom[0xC6]&(1<<3))>>3;
	anspringen[1]=(eeprom[0xC6]&(1<<7))>>7;
	dimmgeschwindikeit[0]=basis[(eeprom[0xC6]&0x07)]*eeprom[0xC8];
	dimmgeschwindikeit[1]=basis[(eeprom[0xC6]>>4)&0x07]*eeprom[0xC9];
	// Soft-Ein
	softEin[0]=(eeprom[0xD3]!=0);
	softEin[1]=(eeprom[0xD4]!=0);
	softEinGeschwindikeit[0]=basis[(eeprom[0xD2]&0x07)]*eeprom[0xD3];
	softEinGeschwindikeit[1]=basis[(eeprom[0xD2]>>4)&0x07]*eeprom[0xD4];
	// Soft-Aus
	softAus[0]=(eeprom[0xD7]!=0);
	softAus[1]=(eeprom[0xD8]!=0);
	softAusGeschwindikeit[0]=basis[(eeprom[0xD6]&0x07)]*eeprom[0xD7];
	softAusGeschwindikeit[1]=basis[(eeprom[0xD6]>>4)&0x07]*eeprom[0xD8];

	sperren[KANAL1]=false;
	sperren[KANAL2]=false;
	RueckmeldungPending[KANAL1]=0;
	RueckmeldungPending[KANAL2]=0;
	IstKurzschluss[KANAL1] = false;
	IstKurzschluss[KANAL2] = false;

	// Grundhelligkeit setzen
	SetGrundhelligkeit(KANAL1,(eeprom[0xc2]&0x0f)*15+30);  //@todo mit Gira vergleichen
	SetGrundhelligkeit(KANAL2,(eeprom[0xc2]>>4)*15+30);

	// Anfangshelligkeit //Verhalten bei Busspannungswiederkehr
	SwitchDimmer(KANAL1,HelligkeitFromStufe(eeprom[0xe2]&0x0f,0),true,1);
	SwitchDimmer(KANAL2,HelligkeitFromStufe((eeprom[0xe2]>>4)&0x0f,1),true,1);
// @toto test
	//SwitchDimmer(KANAL1,0,true,1);
	//SwitchDimmer(KANAL2,0,true,1);

	// EEprom initialisieren
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
	EA=1;

	//Bestimme_Dimmverfahren();				// Bestimmt ob Pasenan- oder -abschnittsverfahren
#ifdef debug_restart_app
	rs_send_s("\nEnde restart_app");
#endif

}



/**
 *  Bestimmt aus der Helligkeitsstufe die Helligkeit
 */
byte HelligkeitFromStufe(byte stufe,byte kanal)//Stufe 0-c
{
  if (stufe>14) return 128;
//  if(stufe == 0x0c)  return ausschalthellikeit[kanal];  //@todo
  kanal;  // @todo entfernen, nur damit keine warnung kommt
  return helligkeitsstufe[stufe];
}



/**
 * Liefert den Wert eines Objektes
 */
unsigned long read_obj_value(byte objno)
{

	//@todo  Rückmeldung nur senden wenn parametriert
	if (objno<2) return  dim_val_ist[objno]==0;		// Schalten
	//if (objno<4) return  0x22 ; 					//@todo test Dimmen
	if (objno<6) return  dim_val_ist[objno-4];		// Helligkeit
	if (objno<8) return  dim_val_ist[objno-6]!=0;  	// Rückmeldung Schaltzustand
	if (objno<10) return  dim_val_ist[objno-8];		// Rückmeldung Helligkeit
	//if (objno<12) return  111 ; 					//@todo test Rückmeldung Sperre
	if (objno<13) return userram[0xFF] ; 			//@todo Lichtszene1 Momentan rebootzähler
	//if (objno<14) return  113 ; 					//@todo Lichtszene2
	if (objno<16) return  IstKurzschluss[objno-14];	//@todo test Kurzschluss
	if (objno<18) return  IstSpannungsausfall[objno-16];	//@todo test Spannungsausfall
	return 0x99;
}


/**
 * Rückmeldung senden
 * c = Kanal
 */
void SendRueckmeldung(byte c, byte OldVal)
{
	if (RueckmeldungPending[c])
	{
#ifdef debug_SendRueckmeldung
	rs_send_s("\nRueck:");
	rs_send_hex(c);
#endif
		// @-todo Rückmeldung nur senden wenn Änderung ???
		OldVal;  //zur vermeidung von Warnmeldung solange noch nicht verwendet
		//@todo auchbei Ü-Flag
		if(eeprom[0xc3] & (1 << (6 + c)) != 0)
		{
//			if (((dim_val_ist[c]==0)+(OldVal==0))==1) send_obj_value(c + 6);
		    send_obj_value(c + 6);
		}

//		if (dim_val_ist[c]!=OldVal) send_obj_value(c + 8);
		send_obj_value(c + 8);

		RueckmeldungPending[c]=false;
	}

}



/*
 * Bearbeitung eines Telegrammes
 */
void write_value_req(void)
{
  byte c,objno,gapos,atp,assno,n,gaposh,datal;
  byte dataw=0;
  byte sperr=0;
  byte commObjectNumber=0;
  int len = 0;

#ifdef debugWriteValueReq
  int i;

  rs_send_s("\nwvr[");
  rs_send_dec(telegramm[3]>>3);
  rs_send_s("/");
  rs_send_dec(telegramm[3]&0x07);
  rs_send_s("/");
  rs_send_dec(telegramm[4]);
  rs_send_s("]:");
  len = (telegramm[5]&0x0F) + 8;
  for (i=0;i<len;i++) rs_send_hex(telegramm[i]);
#endif

    gaposh=0;
    gapos=gapos_in_gat(telegramm[3],telegramm[4]);	// Position der Gruppenadresse in der Adresstabelle

    if (gapos!=0xFF)					// =0xFF falls nicht vorhanden
    {
      atp=eeprom[ASSOCTABPTR];			// Start Association Table
      assno=eeprom[atp];			// Erster Eintrag = Anzahl Einträge
      datal=telegramm[8];                       //wert sichern nach respond ist er anders

      for(n=0;n<assno;n++)			// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
      {
        gaposh=eeprom[atp+1+(n*2)];
        if(gapos==gaposh)			// Wenn Positionsnummer übereinstimmt
        {
          objno=eeprom[atp+2+(n*2)];		// Objektnummer
          commObjectNumber=objno;
          dataw=telegramm[7]&0x3f;
          for(c=0;c<2;c++)
            {
        	  //Kanal 1+2
              if(dataw==0&&commObjectNumber==c && sperren[c]==0) //schaltobjekt  aus,
                {
            	  // @todo Softausfunktion testen
            	  SwitchDimmer(c,0,!softAus[c],softAusGeschwindikeit[c]);
            	  RueckmeldungPending[c]=true;
                }
              if(dataw==1&&commObjectNumber==c && sperren[c]==0) //schaltobjekt  EIN
                {
            	  // @todo Softeinfunktiion testen
            	  SwitchDimmer(c,HelligkeitFromStufe(einschalthelligkeit[c],c),!softEin[c],softEinGeschwindikeit[c]);
            	  RueckmeldungPending[c]=true;
                }
              if(commObjectNumber==c+2 && sperren[c]==0)         //Dimmobjekt
                {
            	  if(dataw==9) //heller
            	  {
                	  SwitchDimmer(c,255,false,dimmgeschwindikeit[c]);
            	  }
               	  if(dataw==1) //dunkler
               	  {
                	  SwitchDimmer(c,1,false,dimmgeschwindikeit[c]);
               	  }
               	  if((dataw==0)||(dataw==8)) //stopp
               	  {
             		  StopDimming(c);
               		  RueckmeldungPending[c]=true;
               	  }
               }
              if(commObjectNumber==c+4 && sperren[c]==0)         //Wertobjekt
                {
               	SwitchDimmer(c,datal,anspringen[c],dimmgeschwindikeit[c]);
                RueckmeldungPending[c]=true;
                }

              if(commObjectNumber==c+0x0c && sperren[c]==0)      //Lichtzene
                {
            	  // @todo debug:
            		EA=0;
            		START_WRITECYCLE
            		WRITE_BYTE(0x00,0xFF,datal);	// setzen
            		STOP_WRITECYCLE
            		EA=1;


 /*
            	  if((datal&0x80)==0x80)        //Lichtzenen Speichern mit 0x8n n=szenennummer
                    {
                    if(eeprom[0xe3]&(1<<(4+c))!=0)// speichern nur wenn erlaubt
                          write_obj_lz(0xe7+(datal&~0x80)+(c*8),dimmwert[c]);
                    }
                  else                          //Lichtzenen aufrufen
                    b_send=1;
                  dimmwert[c]=eeprom[0xe7+(datal&~0x80)+(c*8)]; //Nummer der LZ
*/
                }

 /*
              if(commObjectNumber==c+0x0a)      // Sperren
                {
                 if(eeprom[0xc3]&(1<<(3+c))!=0)//invertiert
                   {
                   if(dataw==1) sperr=0;
                   else sperr=1;
                   }
                 else sperr=dataw;
                 if (sperr==1)
                   {                          //beginn der sperrung
                   dimmwert[c]=helligkeittsstufe(eeprom[0xdf+c]&0x0f,c);
                   sperren[c]=1;
                   }
                 else
                   {                          //ende der sperrung
                   dimmwert[c]=helligkeittsstufe(eeprom[0xdf+c]>>4,c);
                   sperren[c]=0;
                   }
                 b_send=1;
                }
*/
              }

           }
        }
    }
}




/**
* Objektwert lesen wurde angefordert, read_value_response Telegramm zurücksenden
*
* @return
*
*/
void read_value_req(void)
{
        byte objno, objflags;

        objno=find_first_objno(telegramm[3],telegramm[4]);      // erste Objektnummer zu empfangener GA finden
        if(objno!=0xFF)
			{       								// falls Gruppenadresse gefunden
            objflags=read_objflags(objno);          // Objekt Flags lesen

            // Objekt lesen, nur wenn read enable gesetzt (Bit3) und Kommunikation zulaessig (Bit2)
#ifdef debug_app
        	rs_send_s("o:");
        	rs_send_hex(objno);
        	rs_send_hex(objflags&0x0C);
        	rs_send_hex(find_ga(objno));
        	rs_send_s("\n");
#endif
            if((objflags&0x0C)==0x0C)
            	{
#ifdef debug_app2
            	rs_send_hex(0x55);
#endif
            	send_obj_value(objno+0x40);
            	}
#ifdef debug_app2
        	rs_send_s("\n");
#endif
    }
}


// Pruefen ob Kurzschluss oder Spannungsausfall und Telegramm senden
void CheckKurzschlussSpannungsausfall(byte kanal)
{
	byte state;

	// Check Kurzschluss
	state = (TimeSinceShort[kanal]> 2000);		// erst nach 1 s akzeptieren
	if (TimeSinceUIRQ[kanal]<1000)				// nur wenn letztes U-Signal vor weniger als 0.5 s auftrat
												// da sonst Spannungsausfall vorliegt
	{
		if (state != IstKurzschluss[kanal])    		// Status hat sich geändert
		{
			IstKurzschluss[kanal] = state;			// Merken
			send_obj_value(kanal + 14);				// Melden
			if (state)
			{	// Kurzschluß neu aufgetreten, dann abschalten
				SwitchDimmer(kanal,0,true,0);
				RueckmeldungPending[kanal] = true;
			}

			#ifdef debug_CheckKurzschluss
				rs_send_s("\nKurzer:");
				rs_send_hex(kanal);
				rs_send_hex(state);
				rs_send_s(" ");
				rs_send_hex_i(TimeSinceUIRQ[kanal]);
				rs_send_hex_i(IstSpannungsausfall[kanal]);
			#endif
		}
	}

	// Check Spannungsausfall
	state = (TimeSinceUIRQ[kanal]> 4000);		// erst nach 2 s akzeptieren
	if (state != IstSpannungsausfall[kanal])    // Status hat sich geändert
	{	// keine Spannung da
		IstSpannungsausfall[kanal] = state;		// Merken
		send_obj_value(kanal + 16);				// Melden

		#ifdef	debug_CheckSpannungsausfall
			rs_send_s("\nSpannungsausfall:");
			rs_send_hex(kanal);
			rs_send_hex(state);
		#endif
	}
}

