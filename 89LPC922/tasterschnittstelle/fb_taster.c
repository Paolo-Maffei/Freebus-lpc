/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2010 Jan Wegner
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
*/
	

#include <P89LPC922.h>
#include "fb_hal_lpc.h"
#include "fb_prot.h"
#include "fb_delay.h"
#include "fb_app_taster.h"
#include "watchdog.h"

#if (PROGRAMM == 4) // RADIO
#include "spi.h"
#endif

/** 
* The start point of the program, init all libraries, start the bus interface, the application
* and check the status of the program button.
* 
* @return 
*/
void main(void)
{ 
	unsigned char n;
	bit blink;

#if (PROGRAMM == 4) // RADIO
	unsigned char spi_port;
#endif
	
	restart_hw();							// Hardware zuruecksetzen	

	watchdog_count();

	watchdog_init();

	for (n=0;n<50;n++) {
		set_timer0(0xFFFF);					// Warten bis Bus stabil
		while(!TF0);
	}
	restart_prot();							// Protokoll-relevante Parameter zuruecksetzen
	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen

	do  {

		if(EX1){
			watchdog_feed();
		}

#if (PROGRAMM == 1 | PROGRAMM == 2) // MODUL_8_IN oder TASTER_8
		if (PORT != button_buffer) port_changed(PORT);	// ein Taster wurde gedrueckt

#elif (PROGRAMM == 3) // TASTER_4
		if ((PORT & 0x0F) != button_buffer) port_changed(PORT & 0x0F);	// ein Taster wurde gedrueckt

#elif (PROGRAMM == 4) // RADIO
		spi_port=spi_in_out(led_port);
		if (spi_port != button_buffer) port_changed(spi_port);	// ein Taster wurde gedrueckt

#endif

		if (RTCCON>=0x80) delay_timer();	// Realtime clock ueberlauf
			
		n=timer;
		blink=((n>>4) & 0x01);
		
		TASTER=1;				        	// Pin als Eingang schalten um Programmiertaster abzufragen
		if (!TASTER)
		{						// Programmiertaster gedrueckt
			for(n=0;n<100;n++) {}
			while(!TASTER);					// warten bis Programmiertaster losgelassen
			START_WRITECYCLE;
			WRITE_BYTE(0x00,0x60,userram[0x60] ^ 0x81);	// Prog-Bit und Parity-Bit im system_state toggeln
			STOP_WRITECYCLE;
		}

		if (userram[0x60]&0x01)
		{
			TASTER = blink;		// LED blinkt im Prog-Mode
		}
		else
		{
			TASTER = !((eeprom[0xCD] & 0x10) >> 4);	// LED ist an oder aus gemaess Parameter fuer Betriebs-LED
		}


		for(n=0;n<100;n++) {}
  } while(1);
}


