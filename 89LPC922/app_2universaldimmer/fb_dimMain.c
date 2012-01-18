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
 *  21.11.2009  Initialversion
 *  13.02.2011  Für HW-Version 2.0 angepasst
 *
 *
 */

#include "AllgDefs.h"
#include "DEBUG.h"
#include <P89LPC922.h>
#include "fb_uni_dim.h"
#include "fb_app_dim.h"
#include "fb_lpc9xx.h"
#include "fb_rs232.h"

void main(void) {
	unsigned char n;				// Schleifenzähler
//	uint TastDauer=0;				// debugging
	char bef;						// debugging
	char debugChan = 1;				// debugging


#ifdef debugMain  // Debugmeldungen bei Programmstart
	rs_init();
#ifdef LPC936
	rs_send_s("\n\nProgrammstart LPC936 ");
#else
	rs_send_s("\n\nProgrammstart LPC922 ");
#endif
	rs_send_s("V2.1.1  7.1.12 21:06  PA=");
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

#ifdef debugMain  // Debugmeldungen bei Programmstart
	rs_send_s("\nStart Do-loop\n");
#endif

	do {
#ifdef IsDebug
		// Debugbefehle über RS232
		if (RI)	{
			RI = 0;
			bef = SBUF;
			rs_send_s("\nRS232-Befehl:");
			rs_send(bef);
			rs_send_s("\n");

			if (bef == 'n')		SetDimmverfahren(KANAL1,ANSCHNITT); // ANschnitt
			if (bef == 'N')		SetDimmverfahren(KANAL2,ANSCHNITT); // ANschnitt
			if (bef == 'b')		SetDimmverfahren(KANAL1,ABSCHNITT); // ABschnitt
			if (bef == 'B')		SetDimmverfahren(KANAL2,ABSCHNITT); // ABschnitt
			//if (bef == 'd')	Bestimme_Dimmverfahren();
			if (bef == 'e')	    P_S_C1 = LAST_AN;
			if (bef == 'a')	    P_S_C1 = LAST_AUS;
			if (bef == 'E')	    P_S_C2 = LAST_AN;
			if (bef == 'A')	    P_S_C2 = LAST_AUS;
			if (bef == 'x')
			{
				EA = 0;
				rs_send_s("\nEA = 0");
			}
			if (bef == 'y')
			{
				EA = 1;
				rs_send_s("\nEA = 1");
			}
			if (bef == 'k')
			{
				if (debugChan==1) debugChan = 0;
				else debugChan = 1;
				rs_send_s("\ndebugChan=");
				rs_send_dec(debugChan);
			}
			if ((bef>='0') & (bef < '9'))
			{
				SwitchDimmer(debugChan,(bef-'0')*28,true,1);
				rs_send_s("\nSwitchDimmer=");
				rs_send_dec((bef-'0')*28);
			}
			if (bef == '9')
			{
				SwitchDimmer(debugChan,255,true,1);
				rs_send_s("\nSwitchDimmer=");
				rs_send_dec(255);

			}
			if (bef == 'p')
				{
				Nullkorrektur += 100;
				rs_send_s("\nNullkorrektur=");
				rs_send_dec(Nullkorrektur);
				}
			if (bef == 'm')
				{
				Nullkorrektur -= 100;
				rs_send_s("\nNullkorrektur=");
				rs_send_dec(Nullkorrektur);
				}
			if (bef == 'z')
			{
				rs_send_s("\nI-Zeiten: ");
				rs_send_hex(I1_Zeit);
				rs_send_s("  ");
				rs_send_hex(I2_Zeit);
				rs_send_s("\n");

			}
			if (bef == 't')
			{
				ShowTQ();
			}
			if (bef == 'r')
			{
				rs_send_hex(debugIRQ);
			}
			if (bef == 'i')
			{
				rs_show("Grundhelligkeit",Grundhelligkeit[0],Grundhelligkeit[1]);
				rs_show("ZeitFuerDimmschritt",ZeitFuerDimmschritt[0],ZeitFuerDimmschritt[1]);
				rs_show("Dauer",Dauer[0],Dauer[1]);
				rs_show("dim_val_ist",dim_val_ist[0],dim_val_ist[1]);
				rs_show("dim_val_soll",dim_val_soll[0],dim_val_soll[1]);
				rs_show("IstKurzschluss",IstKurzschluss[0],IstKurzschluss[1]);
				rs_show("IstSpannungsausfall",IstSpannungsausfall[0],IstSpannungsausfall[1]);
				rs_show("TimeSinceUIRQ",TimeSinceUIRQ[0],TimeSinceUIRQ[1]);

			}
		}
#endif

		// RTC pollen, da der RTC-IRQ nicht funktioniert !!!
		if ((RTCCON & 0x80) != 0)
		{
			char oldEA;			// (1) für Debuggingfunktion imer ein
			RTCCON &= ~0x80;	// Flag zurücksetzen
			RTC_IRQ();			// Behandlungsroutine aufrufen
			// Watchdog triggern
			oldEA = EA;			// (1) für Debuggingfunktion imer ein
			EA = 0;
			WFEED1 = 0xA5;
			WFEED2 = 0x5A;
			//EA = 1;
			EA = oldEA;			// (1) für Debuggingfunktion imer ein
		}

		// Telegramme bearbeiten
		if (tel_arrived) {
			//tel_arrived=0; wird schon in process_tel  gesetzt
			rs_send('.');
			process_tel();
		}

		// Kurzschluß abfragen
		CheckKurzschlussSpannungsausfall(KANAL1);
		CheckKurzschlussSpannungsausfall(KANAL2);

		// Taster abfragen
		TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
		if(!TASTER) {				// Taster gedrückt
			for(n=0;n<100;n++) {}	// Entprell-Zeit

// todo Debug für ANschnitt wenn aus dann Einschalten
//			P0_0 = 0;
//			P0_6 = 0;

			while(!TASTER)			// warten bis Taster losgelassen
			{
				if ((RTCCON & 0x80) != 0)
				{
					RTCCON &= ~0x80;	// Flag zurücksetzen
					RTC_IRQ();			// Behandlungsroutine aufrufen
					// Watchdog triggern
					EA = 0;
					WFEED1 = 0xA5;
					WFEED2 = 0x5A;
					EA = 1;
				}
			}
			status60 = status60^ 0x81;
			rs_send_hex(status60);
		}
		// LED entsprechend Prog-Bit schalten (low=LED an)
		TASTER = !(status60 & 0x01);
		for(n=0;n<100;n++) {}	// falls Hauptroutine keine Zeit verbraucht, der LED etwas Zeit geben, damit sie auch leuchten kann

	} while (1);
}

