/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2009 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

// Versionen:	1.00	erste Version

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "app_finger.h"


void main(void)
{ 

	unsigned char n, user;

	restart_hw();				// Hardware zurücksetzen
	restart_prot();			// Protokoll-relevante Parameter zurücksetzen
	restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
	wiegand=0;
 
	do  {
  
		if (TF0) {		// timeout bei Wiegand-Protokoll empfangen
			TR0=0;
			TF0=0;
			EKBI=0;		// keyboard interrupt sperren
			user=((wiegand>>1)&0xFF)-1;	// user-no ab 2. Bit im Wiegand Telegramm
			wiegand=0;
			if (user<16) schalten(1,user);	// user 1-16 den objekten 0-15 zuordnen, nur Schalten!
			EKBI=1;		// keyboard interrupt freigeben
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
