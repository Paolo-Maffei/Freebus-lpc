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
 * 09.11.08	- array delrec[] statt flash f�r zeitverz�gerung, auf 24bit gek�rzt
 * 			- funktionen write_delay_record() und clear_delay_record() angepasst
 * 			- globale variablen pah und pal durch direktes eeprom[] lesen ersetzt
 * 14.11.08	- in find_ga() default value von ga auf 0xFE gesetzt
 * 
 * 
 */
/**
* @file   fb_prot.c
* @author Andreas Krebs <kubi@krebsworld.de>
* @date    2008
* 
* @brief  Hier sind ausschliesslich die Protokoll-Handling Routinen fuer den 89LPC922
* 
* 
*/





#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"


unsigned char telegramm[23];
unsigned char telpos;		/// Zeiger auf naechste Position im Array Telegramm
unsigned char cs;			/// checksum

bit progmode, connected;	/// Programmiermodus, Verbindung steht
unsigned char conh, conl;	/// bei bestehender Verbindung phys. Adresse des Kommunikationspartners
unsigned char pcount;		/// Paketzaehler, Gruppenadresszaehler
unsigned char last_tel;
bit transparency;




/** 
* Interrupt von Timer 1, 370us keine Busaktivit�t seit letztem Byte,
* d.h. Telegramm wurde komplett uebertragen
*
* 
* @return 
*/
void timer1(void) interrupt 3
{
	unsigned char data_laenge,daf;

	EX1=0;					// ext. Interrupt stoppen 
	ET1=0;					// Interrupt von Timer 1 sperren
	set_timer1(4830);				// 4720 und neu starten fuer korrekte Positionierung des ACK Bytes
  
	if(cs==0xff) {					// Checksum des Telegramms ist OK
		if (transparency) {
			last_tel=telpos;
		}
		else {
			data_laenge=(telegramm[5]&0x0F);		// Telegramm-Laenge = Bit 0 bis 3 
			daf=(telegramm[5]&0x80);			// Destination Adress Flag = Bit 7, 0=phys. Adr., 1=Gruppenadr.

			if(telegramm[3]==0 && telegramm[4]==0) {		// Broadcast, wenn Zieladresse = 0

			}
			else {
				if(daf==0x00) {					// Unicast, wenn Zieladresse physikalische Adresse ist

				}
				else {		// Multicast, wenn Zieladresse Gruppenadresse ist
					if(data_laenge>=1 && telegramm[6]==0x00 && (telegramm[7]&0xC0)==0x80) write_value_req();	// Objektwerte schreiben (zB. EISx)

				}
			}
		} 
	}
	telpos=0;  
	IE1=0;					// IRQ Flag zuruecksetzen
	EX1=1;					// externen Interrupt 0 wieder freigeben
	if (!transparency) {	// Telegramm abgearbeitet
		TR1=0;				// Timer 1 stoppen
		cs=0;				// cheksum zur�cksetzen
	}
}




/** 
* Byte empfangen und pruefen ob es ein ACK war
*
* 
*
*/
bit get_ack(void)
{
  bit ret;
  int n;

  n=0;
  ret=0;
  do {
    if(FBINC==1) n++;
    else {
      if (get_byte()==0xCC && parity_ok) {
    	  ret=1;
    	  n=3000;
      }
    }
  } while (n<3000);
  return(ret);
}



/** 
* sendet das Telegramm, das in telegramm[] vorher abgelegt wurde und berechnet die checksum
*
*
*
*/
void send_telegramm(void)
{
  unsigned char data_laenge,l,checksum,r;

  r=0;
  do
  {
    checksum=0;
    data_laenge=telegramm[5]&0x0F;	// Telegramm-Laenge = Bit 0 bis 3

    set_timer1(18780);			// Warten bis Bus frei ist
    while(!TF1) {
      if(!FBINC) set_timer1(18780);
    }
    TR1=0;
  
    for(l=0;l<=data_laenge+6;l++)
    {
      sendbyte(telegramm[l]);
      checksum^=telegramm[l];
      sysdelay(1230);			// Interbyte-Abstand
    }
    checksum=~checksum;
    sendbyte(checksum);
    if(get_ack()) r=3;		// wenn ACK empfangen, dann nicht nochmal senden
    r++;
    telegramm[0]&=0xDF;			// Bit 5 loeschen = Wiederholung
  }
  while(r<=3); 				// falls kein ACK max. 3 Mal wiederholen
}




/** 
* wartet auf Timer 1 wegen korrekter Positionierung und sendet ACK (0xCC)
*
*
*
*/
void send_ack(void)
{
  while(!TF1&&TR1) {}
  sendbyte(0xCC);
}




















/** 
* neue phys. Adresse programmieren
*
*
*
*/
void set_pa(void)
{
  START_WRITECYCLE
  WRITE_BYTE(0x01,ADDRTAB+1,telegramm[8])
  WRITE_BYTE(0x01,ADDRTAB+2,telegramm[9]);
  STOP_WRITECYCLE
}





/** 
* Protokoll-relevante Parameter zuruecksetzen
*
*
*
*/
void restart_prot(void)
{
  
  progmode=0;			// kein Programmiermodus
  pcount=1;				// Paketzaehler initialisieren
  connected=0;			// keine Verbindung
  
  telpos=0;				// empfangene Bytes an dieser Position im Array telegramm[] ablegen
  last_tel=0;
  transparency=0;
}
