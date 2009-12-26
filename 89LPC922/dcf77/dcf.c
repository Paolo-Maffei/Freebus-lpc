/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008, 2009 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *	Zeitgeber, Anschluss des DCF Signals an IO1 (=P0.0)
 *
 *	Ver.	1.00	erste Version
 *			1.10	umgestellt auf library / statemachine
 *
 *
 */


#include <P89LPC922.h>
#include "../lib_lpc922/fb_lpc922.h"
#include "app_dcf.h"





void main(void)
{ 
	unsigned char n, count=0, dcf_minute=0, dcf_hour=0;
	unsigned char dcf_day=0, dcf_dow=0;
	unsigned char dcf_month=0, dcf_year=0;
	bit dcf_bit, old_P0_0=0, bitok=0, min_par=0, min_par_rx=0;
	bit hr_par=0, hr_par_rx=0, dat_par=0, dat_par_rx=0;
	bit time_sent=0, start_bit=0;

	
	restart_hw();							// Hardware zuruecksetzen

	for (n=0;n<50;n++) {
		set_timer0(0xFFFF);					// Warten bis Bus stabil
		while(!TF0);
	}
	
	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen


	do  {

		if (eeprom[0x0D] == 0xFF) {		// wenn im run-mode

			if(P0_0 && !old_P0_0) {	// steigende flanke
				T0_count=0;
				TR0=1;
				bitok=0;
				old_P0_0=1;
				P0_2=0;
			}

			if (T0_count>10) P0_2=1;

			if (T0_count>14 && old_P0_0 && !bitok) {
				dcf_bit=P0_0;
				bitok=1;
				P0_2=1;

				switch (count) {
				case 20: start_bit=dcf_bit; break;
				case 21: min_par=dcf_bit;	dcf_minute=dcf_bit;		break;
				case 22: min_par^=dcf_bit;	dcf_minute+=dcf_bit*2;	break;
				case 23: min_par^=dcf_bit;	dcf_minute+=dcf_bit*4;	break;
				case 24: min_par^=dcf_bit;	dcf_minute+=dcf_bit*8;	break;
				case 25: min_par^=dcf_bit;	dcf_minute+=dcf_bit*10;	break;
				case 26: min_par^=dcf_bit;	dcf_minute+=dcf_bit*20;	break;
				case 27: min_par^=dcf_bit;	dcf_minute+=dcf_bit*40;	break;
				case 28: min_par_rx=dcf_bit; break;

				case 29: dcf_hour=dcf_bit;		hr_par=dcf_bit;		break;
				case 30: dcf_hour+=dcf_bit*2;	hr_par^=dcf_bit;	break;
				case 31: dcf_hour+=dcf_bit*4;	hr_par^=dcf_bit;	break;
				case 32: dcf_hour+=dcf_bit*8;	hr_par^=dcf_bit;	break;
				case 33: dcf_hour+=dcf_bit*10;	hr_par^=dcf_bit;	break;
				case 34: dcf_hour+=dcf_bit*20;	hr_par^=dcf_bit;	break;
				case 35: hr_par_rx=dcf_bit; break;

				case 36: dcf_day=dcf_bit;		dat_par=dcf_bit;	break;
				case 37: dcf_day+=dcf_bit*2;	dat_par^=dcf_bit;	break;
				case 38: dcf_day+=dcf_bit*4;	dat_par^=dcf_bit;	break;
				case 39: dcf_day+=dcf_bit*8;	dat_par^=dcf_bit;	break;
				case 40: dcf_day+=dcf_bit*10;	dat_par^=dcf_bit;	break;
				case 41: dcf_day+=dcf_bit*20;	dat_par^=dcf_bit;	break;
				case 42: dcf_dow=dcf_bit; 		dat_par^=dcf_bit;	break;
				case 43: dcf_dow+=dcf_bit*2;	dat_par^=dcf_bit;	break;
				case 44: dcf_dow+=dcf_bit*4;	dat_par^=dcf_bit;	break;
				case 45: dcf_month=dcf_bit;		dat_par^=dcf_bit;	break;
				case 46: dcf_month+=dcf_bit*2;  dat_par^=dcf_bit;	break;
				case 47: dcf_month+=dcf_bit*4;  dat_par^=dcf_bit;	break;
				case 48: dcf_month+=dcf_bit*8;  dat_par^=dcf_bit;	break;
				case 49: dcf_month+=dcf_bit*10; dat_par^=dcf_bit;	break;
				case 50: dcf_year=dcf_bit;		dat_par^=dcf_bit;	break;
				case 51: dcf_year+=dcf_bit*2;	dat_par^=dcf_bit;	break;
				case 52: dcf_year+=dcf_bit*4;	dat_par^=dcf_bit;	break;
				case 53: dcf_year+=dcf_bit*8;	dat_par^=dcf_bit;	break;
				case 54: dcf_year+=dcf_bit*10;	dat_par^=dcf_bit;	break;
				case 55: dcf_year+=dcf_bit*20;	dat_par^=dcf_bit;	break;
				case 56: dcf_year+=dcf_bit*40;	dat_par^=dcf_bit;	break;
				case 57: dcf_year+=dcf_bit*80;	dat_par^=dcf_bit;	break;
				case 58: dat_par_rx=dcf_bit; break;
				}
				count++;
			}

			if(!P0_0 && bitok) {		// Pin ist 0 und bit ausgewertet
				old_P0_0=0;
			}

			if(!P0_0 && !old_P0_0 && T0_count>104) {	// lücke = sekunde 0
				T0_count=0;
				TR0=0;

				count=0;

				if (min_par==min_par_rx && hr_par==hr_par_rx && dat_par==dat_par_rx && start_bit==1) {
					second=0;
					minute=dcf_minute;
					hour=dcf_hour;
					dow=dcf_dow;
					day=dcf_day;
					month=dcf_month;
					year=dcf_year;
				}
				// alles kaputt machen, damit beim nächsten mal nur korrekt
				// empfangenen Zeit-Telegramme verarbeitet werden
				start_bit=0;
				min_par=!min_par_rx;
				hr_par=!hr_par_rx;
				dat_par=!dat_par_rx;
			}


			if (RTCCON&0x80) {		// eine sekunde der rtc ist abgelaufen
				RTCCON&=0x7F;
				second++;
				if (second==60) {
					second=0;
					minute++;
				}
				if (minute==60) {
					minute=0;
					hour++;
				}
				if (hour==24) {
					hour=0;
					dow++;
					day++;
				}
				time_sent=0;
			}


			if (second==0 && eeprom[0xFE]==1) {	// jede Minute senden
				if (!time_sent) {
					//send_dt(1,0);
					//send_dt(1,1);
					send_obj_value(0);
					send_obj_value(1);
					time_sent=1;
				}
			}

			if (second==0 && minute==0 && eeprom[0xFE]==2) {	// jede Stunde senden
				if (!time_sent) {
					//send_dt(1,0);
					//send_dt(1,1);
					send_obj_value(0);
					send_obj_value(1);
					time_sent=1;
				}
			}

			if (second==0 && minute==0 && hour==0 && eeprom[0xFE]==3) {	// um 00:00 senden
				if (!time_sent) {
					//send_dt(1,0);
					//send_dt(1,1);
					send_obj_value(0);
					send_obj_value(1);
					time_sent=1;
				}
			}

			if (second==0 && minute==0 && hour==2 && eeprom[0xFE]==4) {	// um 02:00 senden
				if (!time_sent) {
					//send_dt(1,0);
					//send_dt(1,1);
					send_obj_value(0);
					send_obj_value(1);
					time_sent=1;
				}
			}


		}

		if (tel_arrived) {
			tel_arrived=0;
			process_tel();
		}


		

		TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER) {				// Taster gedrückt
			for(n=0;n<100;n++) {}	// Entprell-Zeit
			while(!TASTER);			// warten bis Taster losgelassen
			status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
		}
		TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
		for(n=0;n<100;n++) {}	// falls Hauptroutine keine Zeit verbraucht, der LED etwas Zeit geben, damit sie auch leuchten kann

  } while(1);
}


