/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2008 Andreas Krebs <kubi@krebsworld.de>  Richard Weissteiner richard@seelaus.at
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
 * 30 12. 2008 umbau auf dimmer begonnen org file fb_app_out.c
 *
 *
 */

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_app_dim.h"
#include "../com/fb_rs232.h"
unsigned char Tval;
unsigned char portbuffer;	// Zwischenspeicherung der Portzustände
unsigned char zfstate;		// Zustand der Objekte 8-11 = Zusatzfunktionen 1-4
unsigned char blocked;		// Sperrung der 8 Ausgänge (1=gesperrt)
unsigned char logicstate;	// Zustand der Verknüpfungen pro Ausgang
long timer;					// Timer für Schaltverzögerungen, wird alle 130us hochgezählt
bit delay_toggle;			// um nur jedes 2. Mal die delay routine auszuführen


void write_value_req(void)				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
{
  unsigned char c,objno,gapos,atp,assno,n,gaposh;
  unsigned char dataw=0;
  unsigned char commObjectNumber=0;
    gaposh=0;
    gapos=gapos_in_gat(telegramm[3],telegramm[4]);	// Position der Gruppenadresse in der Adresstabelle

    if (gapos!=0xFF)					// =0xFF falls nicht vorhanden
    {
      send_ack();
      rs_send_s("\nwr_val_rq ");
      atp=eeprom[ASSOCTABPTR];			// Start Association Table
      assno=eeprom[atp];			// Erster Eintrag = Anzahl Einträge

      for(n=0;n<assno;n++)			// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
      {

        gaposh=eeprom[atp+1+(n*2)];
        if(gapos==gaposh)			// Wenn Positionsnummer übereinstimmt
        {
          objno=eeprom[atp+2+(n*2)];		// Objektnummer
          //objflags=read_objflags(objno);//ToDo: Objekt Flags read funkt nicht

          dataw=telegramm[7]&0x3f;
          rs_send_hex(objno);
          rs_send_s(" ");
          rs_send_hex(dataw);
          rs_send_s(" ");
          rs_send_hex(telegramm[8]);

          //respond(objno,0x40+dataw);
          commObjectNumber=objno;
          for(c=0;c<2;c++)
            {
          //KAnal 1+2
              if(dataw==0&&commObjectNumber==c)            //schaltobjekt  aus
                dimmwert[c]=0;
             if(dataw==1&&commObjectNumber==c)             //schaltobjekt  EIN
                dimmwert[c]=helligkeittsstufe(einschathellikeit[c],c);
              if(commObjectNumber==c+2)                    //Dimmobjekt
                dimm_helldunkel[c]=dataw;
              if(commObjectNumber==c+4)                    //Wertobjekt
                dimmwert[c]=telegramm[8];
            }
           }
        }
    }
}


void respond(unsigned char objno, unsigned char rval)	// sucht Gruppenadresse für das Objekt objno uns sendet ein EIS 1 Telegramm
{							// mit dem Wert rval (0x80 oder 0x81) für Rückmeldeobjekte

  int ga;
  rs_send_s("\nrespond ");

  ga=find_ga(objno);					// wenn keine Gruppenadresse hintrlegt nix tun
  if (ga!=0)
  {
    //EX1=0;
    telegramm[0]=0xBC;
    telegramm[1]=eeprom[ADDRTAB+1];
    telegramm[2]=eeprom[ADDRTAB+2];
    telegramm[3]=ga>>8;
    telegramm[4]=ga;
    telegramm[5]=0xD1;
    telegramm[6]=0x00;
    objno=objno-12;
    telegramm[7]=rval;
    send_telegramm();
    //EX1=1;
  }

}


