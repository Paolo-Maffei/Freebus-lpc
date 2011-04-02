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
#include "../lib_lpc922/fb_lpc922.h"
#include "fb_app_prototyp.h"



void write_value_req(void)	// Empfangenes write_value_request Telegramm verarbeiten
{
	/* Hier holt man sich die Bytes aus dem array telegramm[] und führt
	 * die entsprechenden Aktionen aus, die das Gerät haben soll
	 */
}



void read_value_req(void)	// Empfangenes read_value_request Telegramm verarbeiten
{
	/* Hier sicherstellen, dass der Objektwert, der durch read_obj_value() gelesen wird,
	 * aktuell ist. Danach das Senden des Objektes anstossen.
	 */
}


unsigned long read_obj_value(unsigned char objno)
{
	/* Hier muss der Wert eines Objektes zurückgegeben werden.
	 * (und zwar so wie er gesendet werden soll !!! z.B. bereits als EIS5 codiert)
	 */

	// Dummy Code: (damit der compiler nicht meckert, weil es leer ist...)
	objno++;
	return(objno);	// Beispiel return-Wert
}


void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{

	
	// ***************************************
	//  hier Port und Sonstiges konfigurieren
	// ***************************************	
	
	

	
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
	EA=1;						// Interrupts freigeben
}
