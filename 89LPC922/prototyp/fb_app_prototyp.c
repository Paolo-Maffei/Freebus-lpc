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
 * 
 */



#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_prototyp.h"



void write_value_req(void)	// Empfangenes write_value_request Telegramm verarbeiten
{

}



void read_value_req(void)	// Empfangenes read_value_request Telegramm verarbeiten
{

}



void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{

	
	// ***************************************
	//  hier Port und Sonstiges konfigurieren
	// ***************************************	
	
	
	// mögliche Bit-Variablen:
	// transparency=1;	// Telegramme werden nicht vom Protokoll-Layer abgearbeitet, default 0

	
	// Beispiel für die Applikations-spezifischen Einträge im eeprom
	EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
	START_WRITECYCLE
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
	WRITE_BYTE(0x01,0x04,0x04)
	WRITE_BYTE(0x01,0x05,0x20)	// Devicetype 0x2060 = Jung Aktor 2138.10
	WRITE_BYTE(0x01,0x06,0x60)	
	WRITE_BYTE(0x01,0x07,0x01)	// Versionnumber of application programm
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0x9A)	// COMMSTAB Pointer
	STOP_WRITECYCLE
	START_WRITECYCLE;
	WRITE_BYTE(0x00,0x60,0x2E);	// system state: all layers active (run), not in prog mode
	STOP_WRITECYCLE;
	EA=1;						// Interrupts freigeben
}
