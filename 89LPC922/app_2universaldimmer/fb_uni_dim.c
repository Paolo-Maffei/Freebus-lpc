/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2009 Rainer Petzoldt <r.petzoldt@web.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
/**
* @file   fb_uni_dim.c
* @author Rainer Petzoldt <r.petzoldt@web.de>
* @date   17.10.2009
* @brief  Hier sind ausschliesslich die Universaldimmer Routinen fuer den 89LPC922
*
* @version 0.1	26.10.2009	Timerinterrupt als Zaehlerueberlauf fuer Einmessen
* @version 1.5	13.02.2010	Interrupt nur bei Flanken und beim Schalten (keine Timeslots mehr)
*               25.02.2010  andimmen, Einschalthelligkeit
*
*/

#include "AllgDefs.h"
#include "DEBUG.h"
#include "fb_app_dim.h"
#include "fb_lpc922.h"
#include <P89LPC922.h>
#include "fb_uni_dim.h"

#ifdef IncludeRS232
#include "fb_rs232.h"
#endif



#define SET_KANAL(c,state) if (c) {P_S_C2=state;} else {P_S_C1=state;}

#define CMP_U 0x28			// 0x28 = enabled, Neg. Eingang = Uref; Quelle = U-Signal
#define CMP_I 0x38			// 0x38 = enabled, Neg. Eingang = Uref; Quelle = I-Signal


__idata volatile byte dim_val_soll[2];				// gewünschte Helligkeit [0..255]   0=aus   255=ein
__idata volatile byte dim_val_ist[2];				// aktuelle Helligkeit [0..255]     0=aus   255=ein
__idata volatile uint Dauer[AnzahlKanaele] ;		// Dauer in Ticks bis zum Toggeln des Ausgangs
__idata volatile ulong dimmschritt[AnzahlKanaele] ;	// Dauer in RTC-Ticks bis zum nächsten Helligkeitswert
__idata volatile byte IstABSchnitt[2];	         	// Abschnittsdimmer(!=0) oder Anschnittsdimmer (=0)
__idata volatile ulong NextDimmschritTime[AnzahlKanaele];	// Rückwärtszaehler der 0.5 ms Intervalle pro Kanal füer andimmen, ...
__idata volatile uint ZeitFuerDimmschritt[2];  	// Zeit in Ticks für eine Dimmstufe
__idata volatile uint Grundhelligkeit[2];		// Grundhelligkeitin Ticks


volatile uint HalbePeriode;						// Haelfte der Periodendauer in Ticks
volatile byte bef, nextBef;
volatile byte kanal, nextKanal;
volatile uint nextTimerWert;



/**
 * Initialisierung des Universaldimmers
 *
 */
void ud_init(void)
{
#ifdef debug_ud_init
	rs_send_s("\nud_init");
#endif

	P0M1 = 0x00; 			// Port 0: 1..5,7 = quasi-bidirectional 0,6 = push-pull
	P0M2 = 0x41;

	//@todo prüfen ob das noch so ist
	//	PT0AD = 0x1E;  			// Analogports für Digital Input nicht sperren, sonst tut einmessen nicht

	// Prioritaet CMP-IRQ auf 1
	SET_BIT(IP1 ,2);
	CLR_BIT(IP1H,2);

	// Dimmart setzen  (Defaultswert)
	SetDimmverfahren(KANAL1,true);  // Abschnitt
	SetDimmverfahren(KANAL2,true);  // Abschnitt
	EC = 1;  				// Comparator IRQ freigeben

//	HalbePeriode = 36864;	// Default = 50Hz
	HalbePeriode = 36000;	// @todo sonst Flackern bei voller Helligkeit, da beide Halbwellen unterschiedlich lang sind

	// Timer setzen
	TR0 = 0;				// Timer aus
	TMOD =(TMOD&0xF0)|0x01;	// Timer0 Mode1 = 16bit ohne prescaler , d.h. 0.2713us
	TAMOD &= 0xF0;
	ET0 = 1;				// Timerinterrupt freigeben

	// Timerqueue initialisieren
	bef = BEF_NOTHING;
	nextBef = BEF_NOTHING;
	nextTimerWert = 0;

	RTCH = 0x00;		// RTC auf 0,503 ms  [0x001D]
	RTCL = 0x1D;
	//EWDRT = 1;			// Enable RTC-IRQ tut nicht !!!
	RTCCON = 0x61;

#ifdef debugUDInit
	rs_send_s("\nud_init: IP1h 1l 0h 0l ");
	rs_send_hex(IP1H);
	rs_send_hex(IP1);
	rs_send_hex(IP0H);
	rs_send_hex(IP0);
#endif

}



/**
 * Berechnet aus der Helligkeit die Dauer
 */
void BerechneDauer(byte c)
{
	if (IstABSchnitt[c])
	{	// Abschnittsdimmer, Dauer bis zum Ausschalten
		Dauer[c] =  Grundhelligkeit[c] + dim_val_ist[c] * ZeitFuerDimmschritt[c];
	}
	else
	{	// Anschnittsdimmer, Dauer bis zum Einschalten
		Dauer[c] =  HalbePeriode - Grundhelligkeit[c] - dim_val_ist[c] * ZeitFuerDimmschritt[c];
	}
}



/**
 * RTC Interrupt (simuliert durch polling)
 */
void RTC_IRQ(void) //interrupt 10   // = RTC Interrupt
{	// wird alle 0.5 ms aufgerufen
	byte c,OldVal;
	for (c=0;c<2;c++)
	{
		NextDimmschritTime[c]--;
		if (NextDimmschritTime[c] == 0)
		{	// Zeit für Dimmschritt
			OldVal = dim_val_ist[c];
			if (dim_val_soll[c]>dim_val_ist[c]) dim_val_ist[c]++;
			else if (dim_val_soll[c]<dim_val_ist[c]) dim_val_ist[c]--;
			else SendRueckmeldung(c,OldVal);
			BerechneDauer(c);
			NextDimmschritTime[c] = dimmschritt[c];
#ifdef debugRTC
			rs_send_s("\nIst:");
			rs_send_dec(dim_val_ist[0]);
			rs_send_s(",");
			rs_send_dec(dim_val_ist[1]);
#endif
		}
	}
}




/*
 * Schaltet Dimmer Kanal c auf Helligkeitswert val
 * beruecksichtigt auch andimmen
 */
void SwitchDimmer(byte c,byte val, byte anspringen, ulong schrittweite)
{
	byte OldVal;
	dim_val_soll[c]=val;
	dimmschritt[c] = schrittweite;
	NextDimmschritTime[c]    = schrittweite;
	//@todo evtl. Rückmeldung EIN gleich senden Bedingungen
	if (anspringen)
	{	// wenn anspringen dann gleich den istwert setzen
		OldVal = dim_val_ist[c];
		dim_val_ist[c]=val;
		SendRueckmeldung(c,OldVal);
		BerechneDauer(c);
	}
	// Wenn ANschnitt und gerade eingeschaltet dann Starthilfe geben
	// es kommt sonst nie ein COM-I-IRQ
	if (!IstABSchnitt[c])
		if (dim_val_ist[c] == 0)
			if (val!=0) SET_KANAL(c,LAST_AN)

#ifdef debugSwitchDimmer

	rs_send_s("\nSwitchDimmer:");
	rs_send_s("\n  c=");
	rs_send_hex(c);
	rs_send_s("\n  val=");
	rs_send_hex(val);
	rs_send_s("\n  anspr=");
	rs_send_hex(anspringen);
	rs_send_s("\n  schritt=");
	rs_send_hex(schrittweite);
#endif

}

/**
 * Beendet den Dimmvorgang und behält die aktuelle Helligkeit
 */
void StopDimming(byte c)
{
	dim_val_soll[c] = dim_val_ist[c];
	BerechneDauer(c);
}


/**
 *	Setzt Grundhelligkeit und ZeitFuerDimmschritt
 *	c = Kanal
 *	val = Grundhelligkeit 0..255  dunkel..hell
 */
void SetGrundhelligkeit(byte c, byte val)
{
	Grundhelligkeit[c] = val * (HalbePeriode>>8);
	ZeitFuerDimmschritt[c]= (HalbePeriode - Grundhelligkeit[c])>>8;
}



/**
 * Timer0 für neue Zeit setzen
 * dabei muss der jeweils andere Kanal berücksichtigt werden
 */
void SetTimer(uint _dauer, byte _kanal, byte _befehl )
{
	uint istDauer;
	uint TimerWert;

	TimerWert = - _dauer;
	TR0 = 0;					// Timer anhalten
	istDauer = -((((uint)TH0)<<8) + TL0);
	if (bef == BEF_NOTHING)
	{	// Kein Befehl geplant
		bef = _befehl;
		kanal = _kanal;
		// Timerdauer setzen
		TH0 = MSB(TimerWert);
		TL0 = LSB(TimerWert);
		TR0 = 1;					// Timer starten
		//@todo istDauer zur Korrektur des Timings verwenden bzw. zur Frequenzbestimmung oder in BestimmeDimmverfahren
	}
	else
	{	// Befehl ist bereits geplant
		if (istDauer>_dauer)
		{	// neuen Befehl davor einfügen
			// alten Befehl in die Warteschlange
			nextBef = bef;
			nextKanal = kanal;
			nextTimerWert = _dauer - istDauer ;   // dann nur noch die Differenz warten
			// neuen Befehlsetzen
			bef = _befehl;
			kanal = _kanal;
			TH0 = MSB(TimerWert);
			TL0 = LSB(TimerWert);
			TR0 = 1;					// Timer starten
		}
		else
		{	// neuen Befehl in Warteschlange einreihen
			nextBef = _befehl;
			nextKanal = _kanal;
			nextTimerWert = istDauer - _dauer;   	// dann nur noch die Differenz warten
		}
	}
	TR0 = 1;					// Timer starten
}



/**
 * Behandlung CMP-IRQ auf Kanal c
 * d.h. Kanal schalten
 *
 */
void Handle_CMP_IRQ(byte c)
{
	if (IstABSchnitt[c])
	{	// Abschnittsdimmer
		if (dim_val_ist[c]!=0)
		{
			SET_KANAL(c,LAST_AN);		// einschalten bei U=0 wenn ABschnitt
			// jetzt den Timer für das Ausschalten setzen
			if (dim_val_ist[c]!=255) SetTimer(Dauer[c],c,BEF_AUS);
		}
		else
		{
			SET_KANAL(c,LAST_AUS);		// ausschalten
		}
	}
	else
	{	// ANschnittsdimmer
		if (IsCmpIrqU(c))
		{	// U = 0
			if (dim_val_ist[c]!=255)
			{
				SET_KANAL(c,LAST_AUS)	// ausschalten bei I=0 wenn ANschnitt
			}
			// jetzt den Timer für das Einschalten setzen bei U=0
			if (dim_val_ist[c]!=0) 	SetTimer(Dauer[c],c,BEF_EIN);
			// Warten auf I = 0
//			SetCmpIrq(c,CMP_I);
		}
/*
		else
		{	// I = 0
			// nun waretn auf U = 0
			SetCmpIrq(c,CMP_U);

			// bei I-Signal nur fallende Flanke berücksichtigen andere ignorieren
			if ((c==KANAL1) && (!P_I_C1)) return;
			if ((c==KANAL2) && (!P_I_C2)) return;

			if (dim_val_ist[c]!=255)
			{
				SET_KANAL(c,LAST_AUS)	// ausschalten bei I=0 wenn ANschnitt
			}
			else
			{
				SET_KANAL(c,LAST_AN);		// einschalten
			}
		}
*/
	}
}



/**
 * Comparator Interrupt
 * steht immer auf Spannung von Kanal1 gegen Uref
 * damit ist immer ein fester Bezugspunkt zum Anfang einer Periode gegeben
 *
 */
void C1_IRQ(void) __interrupt 8   //  8 = Comparator Interrupt
{
	if (CMP1#&0x01)
	{	// IRQ Kanal 1 wurde ausgelöst
		CMP1# &= 0xFE;				// Interruptflag löschen
		Handle_CMP_IRQ(KANAL1);
	}

	if (CMP2#&0x01)
	{	// IRQ Kanal 2 wurde ausgelöst
		CMP2# &= 0xFE;				// Interruptflag löschen
		Handle_CMP_IRQ(KANAL2);
	}
}




/**
 * Timer 0 Interrupt
 * wird ausgelöst wenn ein Kanal umgeschaltet werden muss
 * Was getan werden muss steht in bef, der Kanal in kanal
 * Bei Bedarf wird der Timer für den anderen Kanal neu gestartet (nextBef,nexKanal,nextTimerWert)
 */
void Timer_IRQ(void) __interrupt 1   					// = Timer0 Interrupt
{
	if (bef == BEF_EIN)
	{
		if (dim_val_ist[kanal]!=0) SET_KANAL(kanal,LAST_AN);
	}
	else if (bef == BEF_AUS)
	{
		if (dim_val_ist[kanal]!=255) SET_KANAL(kanal,LAST_AUS);
	}
	if (bef != BEF_NOTHING)
	{	// nächsten Befehl vorbereiten
		bef = nextBef;
		kanal = nextKanal;
		TH0 = MSB(nextTimerWert);
		TL0 = LSB(nextTimerWert);
		TR0 = 1;					// Timer starten
		nextBef = BEF_NOTHING;
		nextKanal = 9;
		nextTimerWert = 0;
	}
}



/**
 * Zeiten messen
 */

uint ZeitZwischen(byte Pattern1, byte State1, byte Pattern2, byte State2)
{
	uint p=0;
	uint pmin = 0xFFFF;
	uint pmax = 0;
	uint i;
	byte AnfangsPattern,EndStatus,EndPattern,s2;

	AnfangsPattern = 1<<Pattern1;
	EndStatus = State1 << Pattern1;
	EndPattern = 1<<Pattern2;
	s2 = State2 << Pattern2;

	EA=0;
	TR0 = 0;						// Timer aus

	P_S_C1 = LAST_AN;				// Last Kanal1 einschalten
	P_S_C2 = LAST_AN;				// Last Kanal2 einschalten
	for (i=0;i<0xff;i++);			//warten vor Messung bis Last stabil
	for (i=0;i<20;i++)
	{
		TL0 = 0;					// Timer zurücksetzen
		TH0 = 0;
		while ((P0&AnfangsPattern)==EndStatus) ;		// Warte auf !Anfangsstatus
		while ((P0&AnfangsPattern)!=EndStatus) ;		// Warte auf Anfangsstatus
		TR0 = 1;					// Timer Start
		while ((P0&EndPattern)!=s2);		// Warte auf Endstatus
		TR0 = 0;					// Timer Stop
		p = (((uint)TH0)<<8) + TL0; // Zeit bestimmen
		if (p>pmax) pmax = p;
		if (p<pmin) pmin = p;
	}
	EA=1;
	rs_send_s("  pmin=");
	rs_send_hex_i(pmin);
	rs_send_s("  pmax=");
	rs_send_hex_i(pmax);
	TR0 = 1;					// Timer Start
	return pmin;
}




/**
 * Bestimmen des Dimmverfahrens
 *
 * Ergebnisse;
 *   IstABSchnitt wird für jeden Kanal gesetzt
 *	 im CMP-Interrupt wird die entsprechende Interruptquelle ausgewählt
 */
void Bestimme_Dimmverfahren(void)
{
	//uint t,t1,t2;

	// zuerst Periodenlänge messen @todo
/*
	rs_send_s("\nU1h->U1l:");
	t1 = ZeitZwischen(U_C1,0,U_C1,1);

	rs_send_s("\nU1l->U1h:");
	t2 = ZeitZwischen(U_C1,1,U_C1,0);
    if (t1<t2) t=t1;
    else t = t2;
	rs_send_s("\nPeriode/2: ");
    rs_send_hex_i(t);
*/


/*
	// Dann
	rs_send_s("\nU1h->I1h:");
	t2 = ZeitZwischen(U_C1,1,I_C1,1);

	rs_send_s("\nI1l->I1h:");
	t2 = ZeitZwischen(I_C1,0,I_C1,1);

	rs_send_s("\nI1h->I1l:");
	t2 = ZeitZwischen(I_C1,1,I_C1,0);
*/


	// Dimmverfahren bestimmen
	//@todo bisher nur test
	SetDimmverfahren(0,true); // ABschnitt
	SetDimmverfahren(1,true); // ABschnitt

	//SetDimmverfahren(0,false); // ANschnitt
	//SetDimmverfahren(1,false); // ANschnitt

	SetCmpIrq(KANAL1,CMP_U);
	SetCmpIrq(KANAL2,CMP_U);
}



/**
 * Setzt kanal auf Dimmverfahren
 */
void SetDimmverfahren(byte kanal,byte Abschnittsdimmer)
{
	IstABSchnitt[kanal] = Abschnittsdimmer;

#ifdef debug_SetDimmverfahren
	rs_send_s("\nKanal");
	rs_send_hex(kanal);
	if (Abschnittsdimmer) rs_send_s("ABschnitt");
	else rs_send_s("ANschnitt");
#endif
}

/**
 *  Setzt den CMP-IRQ auf Strom oder Spannungseingang
 */
void SetCmpIrq(byte kanal,byte CMPState)
{
	if (kanal==KANAL1)
	{
		CMP1# = CMPState;
	}
	else
	{
		CMP2# = CMPState;
	}
}

/**
 * Liefert true wenn der Kanal auf Spannungssignal steht
 */
byte IsCmpIrqU(byte kanal)
{
	if (kanal==KANAL1)
	{
		return ((CMP1# & 0x10) == 0);
	}
	else
	{
		return ((CMP2# & 0x10) == 0);
	}

}
