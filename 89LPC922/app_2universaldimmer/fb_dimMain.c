/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2009  Rainer Petzoldt <r.petzoldt@web.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  21 11. 2009 Initialversion
 *
 *
 */

#include "AllgDefs.h"
#include "DEBUG.h"
#include <P89LPC922.h>
#include "fb_uni_dim.h"
#include "fb_app_dim.h"
#include "fb_lpc922.h"

#ifdef IncludeRS232
#include "fb_rs232.h"
#endif


void main(void) {
	unsigned char n;
	unsigned int i = 0;
	uint TastDauer=0;

#ifdef debugMain  // Debugmeldungen bei Programmstart
	rs_init();
	rs_send_s("\n\nProgrammstart V1.6.3  PA=");
	rs_send_hex(eeprom[0x17]);
	rs_send_hex(eeprom[0x18]);
	rs_send_s("  FF=");
	rs_send_hex(userram[0xFF]);
#endif
	// Zähler für Programmstarts erhöhen
	EA=0;
	START_WRITECYCLE
	WRITE_BYTE(0x00,0xFF,userram[0xFF]+1);	// um 1 erhöhen
	STOP_WRITECYCLE
	EA=1;
#ifdef debugMain   // und anzeigen
	rs_send_hex(userram[0xFF]);
#endif


	restart_hw();							// Hardware zuruecksetzen

	for (n=0;n<50;n++) {
		set_timer0(0xFFFF);					// Warten bis Bus stabil
		while(!TF0);
	}


	restart_app();							// Anwendungsspezifische Einstellungen zuruecksetzen

	send_obj_value(12);		// @todo nur für debugging, Restartzaehler an Lichtszenenobjekt senden


	do {
		// RTC pollen, da der RTC-IRQ nicht funktioniert !!!
		if ((RTCCON & 0x80) != 0)
		{
			RTCCON &= ~0x80;	// Flag zurücksetzen
			RTC_IRQ();			// Behandlungsroutine aufrufen
			TastDauer++;
			// Watchdog triggern
			EA = 0;
			WFEED1 = 0xA5;
			WFEED2 = 0x5A;
			EA = 1;
		}

		// Telegramme bearbeiten
		if (tel_arrived) {
			tel_arrived=0;
			process_tel();
		}

		// Kurzschluß abfragen
		CheckKurzschlussSpannungsausfall(KANAL1);
		CheckKurzschlussSpannungsausfall(KANAL2);

		// Taster abfragen
		TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER) {				// Taster gedrückt
			for(n=0;n<100;n++) {}	// Entprell-Zeit
			TastDauer = 0;			// Zeit merken wann Taste gedrückt wurde

// todo Debug für ANschnitt wenn aus dann Einschalten
			P0_0 = 0;
			P0_6 = 0;

#ifdef debugOutputMode
rs_send_s("\nOutmode=");
rs_send_hex(P0M1);
rs_send_hex(P0M2);
#endif

			while(!TASTER)			// warten bis Taster losgelassen
			{
				if ((RTCCON & 0x80) != 0)
				{
					RTCCON &= ~0x80;	// Flag zurücksetzen
					RTC_IRQ();			// Behandlungsroutine aufrufen
					TastDauer++;
					// Watchdog triggern
					EA = 0;
					WFEED1 = 0xA5;
					WFEED2 = 0x5A;
					EA = 1;
					if (TastDauer==1000) rs_send_s(" AN ");
					if (TastDauer==4000) rs_send_s(" AB ");
				}
			}
/*
			if (TastDauer>4000)
			{	// Taste über 2s lang gedrückt
				//Bestimme_Dimmverfahren();				// Bestimmt ob Pasenan- oder abschnittsverfahren
				rs_send_s("\nAB");
				SetDimmverfahren(KANAL1,true);  // Abschnitt
				SetDimmverfahren(KANAL2,true);  // Abschnitt
			}
			else
*/
			if (TastDauer>1000)
			{	// Taste über 0.5s lang gedrückt

				//Bestimme_Dimmverfahren();				// Bestimmt ob Pasenan- oder abschnittsverfahren
				rs_send_s("\nAN");
				SetDimmverfahren(KANAL1,false);  // Anschnitt
				SetDimmverfahren(KANAL2,false);  // Anschnitt
			}
			else
			{	// Taste kurz gedrückt
				status60 = status60^ 0x81;
				rs_send_hex(status60);
			}
		}
		// LED entsprechend Prog-Bit schalten (low=LED an)
		TASTER = !(status60 & 0x01);
		for(n=0;n<100;n++) {}	// falls Hauptroutine keine Zeit verbraucht, der LED etwas Zeit geben, damit sie auch leuchten kann

	} while (1);
}

