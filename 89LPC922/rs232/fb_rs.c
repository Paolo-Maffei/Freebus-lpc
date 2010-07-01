/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2008-2010 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *
 *  Dies ist ein EIB-RS232 Interface auf Basis des LPC-Controllerboards.
 *
 *	Die Schnittstelle ist default auf 115.200 Baud,n,8,1 eingestellt.
 *
 *  Versionen:	1.00	erste Version
 * 				1.01	erweitert um 1-Byte Empfang (zB. EIS6)
 * 				1.02	empfangege Telegramme werdwen gespeichert,
 * 						gespeicherte Werte einer GA können mit fbrgaxx/x/xxx ausgelesen werden
 *						mit fbdump wird die interne Tabelle ausgegeben
 *				1.03	EIS5 und EIS15 eingebaut (thx daywalker)
 *						echo eingebaut
 *				1.04	Baudrate einstellbar mit fbsbrXXXXX (XXXXX=9600, 19200, 38400, 57600, 115200)
 *						echo status wird gespeichert
 *						kein Auffüllen mit Nullen mehr bei GA und PA
 *						Status-LEDs für RX und EIB
 *						serilles Empfangen auf Int umgestellt
 *						fbrva für lesen eines GA-Wertes über bus
 */


#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "miniprot.h"
#include "../com/fb_rs232.h"
#include "fb_app_rs.h"

// kubi-----

void main(void)
{
	unsigned char n, value_pos;
	bit write_ok;
	unsigned int groupadr, pa;
	unsigned int value;
	unsigned int baud_tmp;


	restart_hw();			// Hardware zurücksetzen
	rs_init(baud);			// serielle Schnittstelle initialisieren, muss hier sein
							// weil etwas Zeit vergehen muss bis erstmals gesendet werden kann
	restart_prot();			// Protokoll-relevante Parameter zurücksetzen
	restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen

	RXLED=1;
	EIBLED=1;
	ledcount=0xff;
	eibledcount=0;
	rxledcount=0;
	rsinpos=0;

	rs_send_s("kubi's RS-interface V1.04 ready @ ");
	if (baud==96 || baud==192 || baud==384 || baud==576) rs_send_dec(baud);
	else rs_send_s("1152");
	rs_send_s("00 Baud.\n");

	do  {
		ledcount--;
		if(!ledcount){
			if(!eibledcount)EIBLED=1;
			else {
				eibledcount--;
				EIBLED=0;
			}
			if(!rxledcount)RXLED=1;
			else {
				rxledcount--;
				RXLED=0;
			}
		}
		if(rsin[rsinpos-1]==0x0A) rsinpos--;	// ggf. LF entfernen
		if(rsinpos>0 && rsin[rsinpos-1]==0x0D)	// CR empfangen
		{
			rxledcount=0xff;// * RXLED lang einschalten
			if(echo) rs_send(0x0A);
			if (rsin[0]=='f' && rsin[1]=='b') {	// Magic-word 'fb' empfangen

				if(rsin[2]=='s') {		// s=senden oder setzen

					// EIS 1
					if(rsin[3]=='0' && rsin[4]=='1' && rsin[rsinpos-3]=='=' && (rsin[rsinpos-2]=='0' || rsin[rsinpos-2]=='1')) {
						groupadr=convert_adr(6);
						tel_header(groupadr, 1);
						if (rsin[rsinpos-2]=='1') value=1;
						else value=0;
						telegramm[7]=0x80+value;
						EX1=0;
						send_telegramm();
						EX1=1;
						rs_send_s("OK\n");
						save_ga(groupadr,value);
					}

					// EIS 5 senden Wert
					if(rsin[3]=='0' && rsin[4]=='5') {
						int eis5temp, d, exp;
						unsigned long temp;

						value_pos=equal_pos()+1;
						groupadr=convert_adr(6);
						tel_header(groupadr, 3);
						telegramm[7]=0x80;

						if(rsin[value_pos]<48 || rsin[value_pos]>57) d=value_pos+1; else d=value_pos;	// falls Vorzeichen
									//ascii Zeichen in Int wandeln, Anfang:

						temp=0;
						while (d<(rsinpos-1) && rsin[d]!=0x2E && rsin[d]!=0x2C) {
							temp=temp*10;
							temp=temp+(rsin[d]-48);
							d++;
						}
						d++;
						temp=temp*10;
						if(d<(rsinpos-1))temp=temp+(rsin[d]-48);//erste Stelle nach dem Komma
						d++;
						temp=temp*10;
						if(d<(rsinpos-1))temp=temp+(rsin[d]-48);//zweite Stelle nach dem Komma gen
						//ascii Zeichen in Int wandeln, Ende
						exp=(0x0000);
						while(temp > 0x07FF) {
							temp=temp>>1;
							exp=exp + (0x800);
						}
						if (rsin[value_pos]=='-') {
							temp=(0x7FF-temp)+1;
							eis5temp=temp+exp;
							eis5temp+=0x8000;
						}
						else eis5temp=temp+exp;
						telegramm[8]=eis5temp>>8;
						telegramm[9]=eis5temp;
						EX1=0;
						send_telegramm();
						EX1=1;
						rs_send_s("OK\n");
					}

					// EIS 6 senden
					if(rsin[3]=='0' && rsin[4]=='6') {
						groupadr=convert_adr(6);
						value_pos=equal_pos()+1;
						tel_header(groupadr, 2);
						telegramm[7]=0x80;

						value=0;
						n=value_pos;
						while(n<(rsinpos-1)) {
							value*=10;
							value+=rsin[n]-48;
							n++;
						}
						//telegramm[8]=((rsin[15]-48)*100) + ((rsin[16]-48)*10) + (rsin[17]-48);
						telegramm[8]=value;
						EX1=0;
						send_telegramm();
						EX1=1;
						rs_send_s("OK\n");
						save_ga(groupadr,value);
					}

					// EIS 15 senden, wird nicht im Speicher abgelegt
					if(rsin[3]=='1' && rsin[4]=='5') {
						int d;

						groupadr=convert_adr(6);
						value_pos=equal_pos()+1;
						tel_header(groupadr, 15);

						telegramm[7]=0x80;

						for(d=8;d<22;d++){
							if((value_pos+d-8)>=(rsinpos-1)) telegramm[d]=0x00;
							else telegramm[d]=rsin[(value_pos+d-8)];
						}
						EX1=0;
						send_telegramm();
						EX1=1;
						rs_send_s("OK\n");
					}

					// phys. Adresse des Adapters setzen (fbspaX.X.X)
					if(rsin[3]=='p' && rsin[4]=='a')
					{
						pa=convert_adr(5);
						write_ok=0;
						while (!write_ok) {
							START_WRITECYCLE
							FMADRH = 0x1D;
							FMADRL = 0xFC;
							FMDATA = pa>>8;
							FMDATA = pa;
							STOP_WRITECYCLE
							if(!(FMCON & 0x01)) write_ok=1;	// pruefen, ob erfolgreich geflasht
						}
						rs_send_s("OK\n");
					}

					// Baudrate setzen mit fbsbrXXXXX
					if(rsin[3]=='b' && rsin[4]=='r') {
						baud_tmp=0;
						if(rsinpos>9 && rsin[rsinpos-3]=='0' && rsin[rsinpos-2]=='0') {
							for(n=5;n<rsinpos-3;n++) {
								baud_tmp*=10;
								baud_tmp+=rsin[n]-48;
							}
						}
						if (baud_tmp==96 || baud_tmp==192 || baud_tmp==384 || baud_tmp==576 || baud_tmp==1152) {
							write_ok=0;
							while (!write_ok) {
								START_WRITECYCLE
								FMADRH = 0x1D;
								FMADRL = 0xFE;
								FMDATA = baud_tmp;		// LSB
								FMDATA = baud_tmp>>8;	// MSB
								STOP_WRITECYCLE
								if(!(FMCON & 0x01)) write_ok=1;	// pruefen, ob erfolgreich geflasht
							}
							rs_send_s("OK\n");
							rs_init(baud_tmp);
						}
						else {
							rs_send_s("error: unknown baudrate!\n");
						}
					}


				}	// Ende senden/setzen


				if(rsin[2]=='r') {	// r=read

					// physikalische Adresse des Adaptrs lesen (fbrpa)
					if(rsin[3]=='p' && rsin[4]=='a')
					{
						rs_send_dec(eeprom[0xFC]>>4);
						rs_send('.');
						rs_send_dec(eeprom[0xFC]&0x0F);
						rs_send('.');
						rs_send_dec(eeprom[0xFD]);
						rs_send(0x0D);
						rs_send(0x0A);
					}

					// gespeicherten Wert einer Gruppen-Adresse lesen (fbrgax/x/x)
					if(rsin[3]=='g' && rsin[4]=='a') {
						groupadr=convert_adr(5);
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

					// Wert einer Gruppen-Adresse über Bus lesen (fbrvax/x/x)
					if(rsin[3]=='v' && rsin[4]=='a') {
						groupadr=convert_adr(5);
						tel_header(groupadr, 1);
						telegramm[7]=0x00;
						EX1=0;
						send_telegramm();
						EX1=1;

					}
				}	// ende read


				// GA-Tabelle ausgeben
				if(rsin[2]=='d' && rsin[3]=='u' && rsin[4]=='m' && rsin[5]=='p' && rsinpos==7) {
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
					}while(n<250);
				}

				// echo an-/ausschalten
				if(rsin[2]=='e' && rsin[3]=='c' && rsin[4]=='h' && rsin[5]=='o' && rsin[6]=='=' && rsinpos==9) {
					write_ok=0;
					while (!write_ok) {
						START_WRITECYCLE
						FMADRH = 0x1D;
						FMADRL = 0xFB;
						if(rsin[7]=='0') FMDATA=0; else FMDATA=1;
						STOP_WRITECYCLE
						if(!(FMCON & 0x01)) write_ok=1;	// pruefen, ob erfolgreich geflasht
					}
					rs_send_s("OK\n");
				}


			} // von if(fb...)
			for(n=0;n<30;n++) rsin[n]=0x00;
			rsinpos=0;
		} // von if(crlf_received)
	} while(1);
}


