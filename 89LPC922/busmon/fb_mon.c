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
 *
 *  Versionen:	1.00	erste Version Busmonitor
 *  			2.00	umgestellt auf statemachine library
 *  			2.01	auf neue lib portiert
 *
 */


	

#include <P89LPC922.h>						// Controller-Typ
#include "../lib_lpc922/fb_lpc922.h"		// Freebus Library
#include "../com/fb_rs232.h"				// RS232 Funktionen
#include "fb_app_mon.h"




void main(void)
{ 
	unsigned char sendpos=0;

	restart_hw();				// Hardware zur�cksetzen
	restart_app();				// Anwendungsspezifische Einstellungen zur�cksetzen

	rs_init();					// serielle Schnittstelle initialisieren
  
	auto_ack=0;					// kein automatisches ACK senden


	do {

		if (sendpos>0 && fb_state==0) {			// Telegramm komplett empfangen
			sendpos=0;								// Sendezeiger zur�cksetzen
			telpos=0;								// Telegrammzeiger zur�cksetzen
			rs_send(0x0D);							// CR
			rs_send(0x0A);							// LF
		}

		if (telpos>sendpos) {					// neues Byte im Buffer
			rs_send_hex(telegramm[sendpos]);		// Hexadezimal ausgeben
			rs_send(' ');							// Leerzeichen senden
			sendpos++;								// Sendezeiger erh�hen
		}

		if (ack) {								// ACK empfangen
			rs_send_s("ACK");						// Text ausgeben
			rs_send(0x0D);							// CR
			rs_send(0x0A);							// LF
			ack=0;									// Flag zur�cksetzen
		}

		if (nack) {								// NACK empfangen
			rs_send_s("NACK");						// Text ausgeben
			rs_send(0x0D);							// CR
			rs_send(0x0A);							// LF
			nack=0;									// Flag zur�cksetzen
		}
	} while(1);								// Endlos-Schleife
}
