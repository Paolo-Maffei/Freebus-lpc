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
/**
* @file   fb_rs.c
* @author Andreas Krebs <kubi@krebsworld.de>
* @date   2008
*
* @brief  Dies ist ein EIB-RS232 Interface auf Basis des LPC-Controllerboards.
*
*	Die Schnittstelle ist auf 115.200 Baud,n,8,1 eingestellt.
*
* Versionen:	1.00	erste Version
* 				1.01	erweitert um 1-Byte Empfang (zB. EIS6)
* 				1.02	empfangege Telegramme werdwen gespeichert,
* 						gespeicherte Werte einer GA k�nnen mit fbrgaxx/x/xxx ausgelesen werden
*						mit fbdump wird die interne Tabelle ausgegeben
*/

#include "_divuint.c"
#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "miniprot.h"
#include "../com/fb_rs232.h"
#include "fb_app_rs.h"




/**
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
*
* @return
*/
void main(void)
{
  unsigned char n,rsinpos,pah,pal;
  unsigned char rsin[30];		// seriell empfangener string
  bit cr_received, crlf_received;
  unsigned int groupadr;
  unsigned int value;
  

  restart_hw();				// Hardware zur�cksetzen
  restart_prot();			// Protokoll-relevante Parameter zur�cksetzen
  restart_app();			// Anwendungsspezifische Einstellungen zur�cksetzen
  

  rs_init();				// serielle Schnittstelle initialisieren
  rsinpos=0;
  cr_received=0;
  crlf_received=0;


  rs_send_s("kubi's rs-interface ready.");
  rs_send(13);
  rs_send(10);

  do  {
    if (RI)
    {
      switch (SBUF)
      {
        case 0x0D:			// CR empfangen
          cr_received=1;
          break;
        case 0x0A:			// LF empfangen
          if (cr_received) crlf_received=1;
          break;
        default:
          rsin[rsinpos]=SBUF;			// empfangenes Byte ablegen
          rsinpos++;
          if(rsinpos>30) rsinpos=30;	// �berlauf des Puffers vermeiden
          cr_received=0;
          crlf_received=0;
      }
      RI=0;
    }

    if (crlf_received)			// Zeile vollst�ndig empfangen
    {
      if (rsin[0]=='f' && rsin[1]=='b')	// Magic-word 'fb' empfangen
      {
        if(rsin[2]=='s' && rsin[3]=='0' && rsin[4]=='1' && rsin[5]=='/' && rsin[8]=='/' && rsin[10]=='/' && rsin[14]=='=' && (rsin[15]=='0' || rsin[15]=='1'))	// EIS 1 senden
        {
          groupadr=((rsin[6]-48)*10) + (rsin[7]-48);
          groupadr=groupadr*8;
          groupadr=groupadr + (rsin[9]-48);
          groupadr=groupadr*256;
          groupadr=groupadr+((rsin[11]-48)*100) + ((rsin[12]-48)*10) + (rsin[13]-48);
          telegramm[0]=0xBC;
          telegramm[1]=eeprom[ADDRTAB+1];
          telegramm[2]=eeprom[ADDRTAB+2];
          telegramm[3]=groupadr>>8;
          telegramm[4]=groupadr;
          telegramm[5]=0xE1;
          telegramm[6]=0x00;
          if (rsin[15]=='1') telegramm[7]=0x81;
          if (rsin[15]=='0') telegramm[7]=0x80;
          value=telegramm[7] & 0x0F;
          EX1=0;
          send_telegramm();
          EX1=1;
          rs_send_ok();
          save_ga(groupadr,value);
        }


        if(rsin[2]=='s' && rsin[3]=='0' && rsin[4]=='5' && rsin[5]=='/' && rsin[8]=='/' && rsin[10]=='/' && rsin[14]=='=')	// EIS 5 senden Wert
              {
				int eis5temp, d, exp;
				unsigned long temp;
                groupadr=((rsin[6]-48)*10) + (rsin[7]-48);
                groupadr=groupadr*8;
                groupadr=groupadr + (rsin[9]-48);
                groupadr=groupadr*256;
                groupadr=groupadr+((rsin[11]-48)*100) + ((rsin[12]-48)*10) + (rsin[13]-48);
                telegramm[0]=0xBC;
                telegramm[1]=eeprom[ADDRTAB+1];
                telegramm[2]=eeprom[ADDRTAB+2];
                telegramm[3]=groupadr>>8;
                telegramm[4]=groupadr;
                telegramm[5]=0xE3;
                telegramm[6]=0x00;
                telegramm[7]=0x80;
                if(rsin[15]<48 || rsin[15]>57)d=16; else d=15;
         						//ascii Zeichen in Int wandeln, Anfang:

                temp=0;
                while (d<rsinpos && rsin[d]!=0x2E && rsin[d]!=0x2C)
                {
                	temp=temp*10;
                 	temp=temp+(rsin[d]-48);
                 	d++;
                }
                d++;
                temp=temp*10;
                if(d<rsinpos)temp=temp+(rsin[d]-48);//erste Stelle nach dem Komma
                d++;
                temp=temp*10;
                if(d<rsinpos)temp=temp+(rsin[d]-48);//zweite Stelle nach dem Komma gen
                	//ascii Zeichen in Int wandeln, Ende
			   exp=(0x0000);
               while(temp > 0x07FF)
               {
            	   temp=temp>>1;
            	   exp=exp + (0x800);
               }
               if (rsin[15]=='-')
                {
                temp=(0x7FF-temp)+1;
                eis5temp=temp+exp;
                eis5temp+=0x8000;
                }else
                {
                	eis5temp=temp+exp;
                }
                telegramm[8]=eis5temp>>8;
                telegramm[9]=eis5temp;
                EX1=0;
                send_telegramm();
                EX1=1;
                rs_send_ok();

              }
      if(rsin[2]=='s' && rsin[3]=='0' && rsin[4]=='6' && rsin[5]=='/' && rsin[8]=='/' && rsin[10]=='/' && rsin[14]=='=')	// EIS 6 senden
        {
          groupadr=((rsin[6]-48)*10) + (rsin[7]-48);
          groupadr=groupadr*8;
          groupadr=groupadr + (rsin[9]-48);
          groupadr=groupadr*256;
          groupadr=groupadr+((rsin[11]-48)*100) + ((rsin[12]-48)*10) + (rsin[13]-48);
          telegramm[0]=0xBC;
          telegramm[1]=eeprom[ADDRTAB+1];
          telegramm[2]=eeprom[ADDRTAB+2];
          telegramm[3]=groupadr>>8;
          telegramm[4]=groupadr;
          telegramm[5]=0xE2;
          telegramm[6]=0x00;
          telegramm[7]=0x80;
          telegramm[8]=((rsin[15]-48)*100) + ((rsin[16]-48)*10) + (rsin[17]-48);
          value=telegramm[8];
          EX1=0;
          send_telegramm();
          EX1=1;
          rs_send_ok();
          save_ga(groupadr,value);
        }

        if(rsin[2]=='s' && rsin[3]=='1' && rsin[4]=='5' && rsin[5]=='/' && rsin[8]=='/' && rsin[10]=='/' && rsin[14]=='=')	// EIS 15 senden, wird nicht im Speicher abgelegt
               {
				 unsigned char d;
                 groupadr=((rsin[6]-48)*10) + (rsin[7]-48);
                 groupadr=groupadr*8;
                 groupadr=groupadr + (rsin[9]-48);
                 groupadr=groupadr*256;
                 groupadr=groupadr+((rsin[11]-48)*100) + ((rsin[12]-48)*10) + (rsin[13]-48);
                 telegramm[0]=0x9C;
                 telegramm[1]=eeprom[ADDRTAB+1];
                 telegramm[2]=eeprom[ADDRTAB+2];
                 telegramm[3]=groupadr>>8;
                 telegramm[4]=groupadr;
                 telegramm[5]=0xEF;//L�nge der Nutzinformationen
                 telegramm[6]=0x00;
                 telegramm[7]=0x80;
                 d=8;
                 while(rsin[d+7]!=0x0D)
                 {
                	 telegramm[d]=rsin[d+7];
                	 d++;
                	 if(d==21)
                	 {
                		 break;
                	 }

                 }
                 while(d!=21)
                 {
                	 telegramm[d]=0x00;
                 }
                 EX1=0;
                 send_telegramm();
                 EX1=1;
                 rs_send_ok();
               }

        if(rsin[2]=='r' && rsin[3]=='p' && rsin[4]=='a')	// physikalische Adresse des Adaptrs lesen (fbrpa)
        {
          rs_send_dec(eeprom[ADDRTAB+1]>>4);
          SBUF='.';
          while(!TI);
          TI=0;
          rs_send_dec(eeprom[ADDRTAB+1]&0x0F);
          SBUF='.';
          while(!TI);
          TI=0;
          rs_send_dec(eeprom[ADDRTAB+2]);
          SBUF=0x0D;
          while(!TI);
          TI=0;
          SBUF=0x0A;
          while(!TI);
          TI=0;
        }
        if(rsin[2]=='s' && rsin[3]=='p' && rsin[4]=='a' && rsin[7]=='.' && rsin[10]=='.' && rsinpos==14)	// phys. Adresse des Adapters setzen (fbspaxx.xx.xxx)
        {
		  pah=(((rsin[5]-48)*10) + (rsin[6]-48))*16;
		  pah=pah + (((rsin[8]-48)*10) + (rsin[9]-48));
		  pal=(((rsin[11]-48)*100) + ((rsin[12]-48)*10) + (rsin[13]-48));
		  START_WRITECYCLE
		  WRITE_BYTE(0x01,ADDRTAB+1,pah)
		  WRITE_BYTE(0x01,ADDRTAB+2,pal)
		  STOP_WRITECYCLE
		  rs_send_ok();
		}
      }
      if(rsin[2]=='r' && rsin[3]=='g' && rsin[4]=='a' && rsin[7]=='/' && rsin[9]=='/' && rsinpos==13)	// gespeicherten Wert einer Gruppen-Adresse lesen (fbrgaxx/x/xxx)
      {
          groupadr=((rsin[5]-48)*10) + (rsin[6]-48);
          groupadr=groupadr*8;
          groupadr=groupadr + (rsin[8]-48);
          groupadr=groupadr*256;
          groupadr=groupadr+((rsin[10]-48)*100) + ((rsin[11]-48)*10) + (rsin[12]-48);
			n=0;
			value=0xFFFF;
			do {								// Wert der GA aus Flash lesen
				if(ga_db[n].ga==groupadr) {
					value=ga_db[n].val;
					n=255;
				}
				n++;
			}while (n>0);
			rs_send_dec(value);
			rs_send(13);
			rs_send(10);

      }
      
      if(rsin[2]=='d' && rsin[3]=='u' && rsin[4]=='m' && rsin[5]=='p' && rsinpos==6)
      {
    	  n=0;
    	  do {
    		  rs_send_hex(n);
    		  rs_send(':');
    		  rs_send(' ');
    		  rs_send_hex_i(ga_db[n].ga);
    		  rs_send(' ');
    		  rs_send_hex_i(ga_db[n].val);
    		  rs_send(13);
    		  rs_send(10);
    		  n++;
    	  }while(n>0);
      }

      for(n=0;n<20;n++) rsin[n]=0x00;
      rsinpos=0;
      cr_received=0;
      crlf_received=0;
    }

 
  } while(1);
}


