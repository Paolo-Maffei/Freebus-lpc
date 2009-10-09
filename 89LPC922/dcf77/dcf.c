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
 */
/**
* @file   dcf.c
* @author Andreas Krebs <kubi@krebsworld.de>
*/


#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_rs232.h"

#include "app_dcf.h"




/** 
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
* 
*
*/
void main(void)
{ 
	unsigned char n, count=0, old_minute=0, old_hour=0;
	unsigned char old_day=0, old_dow=0;
	unsigned char old_month=0, old_year=0;
	bit dcf_bit, old_P0_0=0, bitok=0, min_par=0, min_par_rx=0;
	bit hr_par=0, hr_par_rx=0, dat_par=0, dat_par_rx=0;

	
	restart_hw();							// Hardware zuruecksetzen

	for (n=0;n<50;n++) {
		set_timer0(0xFFFF);					// Warten bis Bus stabil
		while(!TF0);
	}
	
	restart_prot();							// Protokoll-relevante Parameter zuruecksetzen
	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen

	rs_init();

	do  {
		//if(RTCCON>=0x80) delay_timer();	// Realtime clock Ueberlauf

  
		//TASTER=!P0_0;
		if(P0_0 && !old_P0_0) {	// steigende flanke
			RTCCON=0x60;	// rtc stoppen
			RTCH=0x21;		// rtc auf 150ms
			RTCL=0xC0;
			RTCCON=0x61;	// rtc starten
			bitok=0;
			old_P0_0=1;
		}
		if(RTCCON>=0x80 && old_P0_0) {	// 150ms nach steigender flanke das bit lesen
			dcf_bit=P0_0;
			bitok=1;
			RTCCON=0x60;	// rtc stoppen
			RTCH=0xCA;		// rtc auf 900ms
			RTCL=0x7F;
			RTCCON=0x61;	// rtc starten
			switch (count) {
			case 21: old_minute=minute; minute=dcf_bit; min_par=dcf_bit; break;
			case 22: min_par^=dcf_bit; minute+=dcf_bit*2;  break;
			case 23: min_par^=dcf_bit; minute+=dcf_bit*4;  break;
			case 24: min_par^=dcf_bit; minute+=dcf_bit*8;  break;
			case 25: min_par^=dcf_bit; minute+=dcf_bit*10; break;
			case 26: min_par^=dcf_bit; minute+=dcf_bit*20; break;
			case 27: min_par^=dcf_bit; minute+=dcf_bit*40; break;
			case 28: min_par_rx=dcf_bit; break;
			case 29: old_hour=hour; hour=dcf_bit; hr_par=dcf_bit; break;
			case 30: hour+=dcf_bit*2;  hr_par^=dcf_bit; break;
			case 31: hour+=dcf_bit*4;  hr_par^=dcf_bit; break;
			case 32: hour+=dcf_bit*8;  hr_par^=dcf_bit; break;
			case 33: hour+=dcf_bit*10; hr_par^=dcf_bit;	break;
			case 34: hour+=dcf_bit*20; hr_par^=dcf_bit;	break;
			case 35: hr_par_rx=dcf_bit; break;
			case 36: old_day=day; day=dcf_bit; dat_par=dcf_bit; break;
			case 37: day+=dcf_bit*2;  dat_par^=dcf_bit; break;
			case 38: day+=dcf_bit*4;  dat_par^=dcf_bit; break;
			case 39: day+=dcf_bit*8;  dat_par^=dcf_bit; break;
			case 40: day+=dcf_bit*10; dat_par^=dcf_bit; break;
			case 41: day+=dcf_bit*20; dat_par^=dcf_bit; break;
			case 42: old_dow=dow; dow=dcf_bit; dat_par^=dcf_bit; break;
			case 43: dow+=dcf_bit*2;  dat_par^=dcf_bit; break;
			case 44: dow+=dcf_bit*4;  dat_par^=dcf_bit; break;
			case 45: old_month=month; month=dcf_bit; dat_par^=dcf_bit; break;
			case 46: month+=dcf_bit*2;  dat_par^=dcf_bit; break;
			case 47: month+=dcf_bit*4;  dat_par^=dcf_bit; break;
			case 48: month+=dcf_bit*8;  dat_par^=dcf_bit; break;
			case 49: month+=dcf_bit*10; dat_par^=dcf_bit; break;
			case 50: old_year=year; year=dcf_bit; dat_par^=dcf_bit; break;
			case 51: year+=dcf_bit*2;  dat_par^=dcf_bit; break;
			case 52: year+=dcf_bit*4;  dat_par^=dcf_bit; break;
			case 53: year+=dcf_bit*8;  dat_par^=dcf_bit; break;
			case 54: year+=dcf_bit*10;  dat_par^=dcf_bit; break;
			case 55: year+=dcf_bit*20;  dat_par^=dcf_bit; break;
			case 56: year+=dcf_bit*40;  dat_par^=dcf_bit; break;
			case 57: year+=dcf_bit*80;  dat_par^=dcf_bit; break;
			case 58: dat_par_rx=dcf_bit; break;



			}
			count++;
		}
		if(!P0_0 && bitok) {		// Pin ist 0 und bit ausgewertet
			old_P0_0=0;
		}
		if(!P0_0 && !old_P0_0 && RTCCON>=0x80) {	// lücke = sekunde 0
			RTCCON=0x60;	// rtc stoppen
			count=0;
			if(hour>23 || hr_par!=hr_par_rx) hour=0;
			rs_send(hour);
			if(minute>59 || min_par!=min_par_rx) minute=0;
			rs_send(minute);
			if(dow>7 || dow<1 || dat_par!=dat_par_rx) dow=old_dow;
			rs_send(dow);
			if(day>31 || day<1 || dat_par!=dat_par_rx) day=old_day;
			rs_send(day);
			if(month>12 || month<1 || dat_par!=dat_par_rx) month=old_month;
			rs_send(month);
			if(dat_par!=dat_par_rx) year=old_year;
			rs_send(year);

			send_dt(1,0);	// time
			send_dt(1,1);	// date

		}



		

		TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER) {				// Taster gedrückt
			for(n=0;n<100;n++) {}	// Entprell-Zeit
			while(!TASTER);			// warten bis Taster losgelassen
			EA=0;
			START_WRITECYCLE;
			WRITE_BYTE(0x00,0x60,userram[0x60] ^ 0x81);	// Prog-Bit und Parity-Bit im system_state toggeln
			STOP_WRITECYCLE;
			EA=1;
		}
		TASTER=!(userram[0x060] & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
		for(n=0;n<100;n++) {}	// falls Hauptroutine keine Zeit verbraucht, der LED etwas Zeit geben, damit sie auch leuchten kann

  } while(1);
}


