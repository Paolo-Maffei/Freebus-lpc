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
#include "fb_lpc9xx.h"
#include <P89LPC922.h>
#include "fb_uni_dim.h"

#define TQ_INC(ptr) {if (ptr == TimeQueueLen-1) ptr = 0 ;              else ptr++;	}
#define TQ_DEC(ptr) {if (ptr ==0 )              ptr = TimeQueueLen-1 ; else ptr--;	}


//#ifdef IncludeRS232
#include "fb_rs232.h"
//#endif



#define SET_KANAL(c,state) if (c) {P_S_C2=state;} else {P_S_C1=state;}

#define CMP_U 0x28			// 0x28 = enabled, Neg. Eingang = Uref; Quelle = U-Signal
#define CMP_I 0x38			// 0x38 = enabled, Neg. Eingang = Uref; Quelle = I-Signal

unsigned int I1_Zeit;
unsigned int I2_Zeit;
unsigned int debugIRQ;
#define MinAusZeit 7373							// muss immer 2ms = 7373 Ticks aus sein (damit das Netzteil genug Spannung bekommt)


__idata volatile byte dim_val_soll[2];				// gewünschte Helligkeit [0..255]   0=aus   255=ein
__idata volatile byte dim_val_ist[2];				// aktuelle Helligkeit [0..255]     0=aus   255=ein
__idata volatile uint Dauer[AnzahlKanaele] ;		// Dauer in Ticks bis zum Toggeln des Ausgangs
__idata volatile ulong dimmschritt[AnzahlKanaele] ;	// Dauer in RTC-Ticks bis zum nächsten Helligkeitswert
__idata volatile byte IstABSchnitt[2];	         	// Abschnittsdimmer(!=0) oder Anschnittsdimmer (=0)
__idata volatile ulong NextDimmschritTime[AnzahlKanaele];	// Rückwärtszaehler der 0.5 ms Intervalle pro Kanal füer andimmen, ...
__idata volatile uint ZeitFuerDimmschritt[2];  		// Zeit in Ticks für eine Dimmstufe
__idata volatile uint Grundhelligkeit[2];			// Grundhelligkeitin Ticks
__idata volatile uint TimeSinceUIRQ[2];				// Zeit seit letztem U-IRQ in 0.5ms
__idata volatile uint TimeSinceShort[2];			// Zeit seit Kurzschluß in 0.5ms


volatile uint HalbePeriode;						// Haelfte der Periodendauer in Ticks
volatile uint Nullkorrektur;					// Zeitkorrektur fuerNulldurchgang in Ticks

#define TimeQueueLen 4							// Anzahle der Elemente in der Timerqueue  0..TimeQueueLen-1
//volatile byte TQbef[TimeQueueLen];				// Beim nächsten IRQ auszuführender Befehl
//volatile uint TQdauer[TimeQueueLen];			// Beim nächsten IRQ zu setzenden Timerwert (bis zum übernächsten Befehl)

struct TQItem {
	byte bef;			// Befehl bei nächsten Timerinterrupr
	uint TimerValue;	// Beim nächsten IRQ zu setzenden Timerwert (bis zum übernächsten Befehl)
	};
volatile struct TQItem TQ[TimeQueueLen];
volatile byte TQReadPointer = 0;
volatile byte TQAnzahlItems = 0;


/**
 * Initialisierung des Universaldimmers
 *
 */
void ud_init(void)
{
	P0M1 = 0x00; 			// Port 0: 1..5,7 = quasi-bidirectional 0,6 = push-pull
	P0M2 = 0x41;

	//@todo prüfen ob das noch so ist
	//	PT0AD = 0x1E;  			// Analogports für Digital Input nicht sperren, sonst tut einmessen nicht

	// Prioritaet CMP-IRQ auf 1
	SET_BIT(IP1 ,2);
	CLR_BIT(IP1H,2);

	// Dimmart setzen  (Defaultswert)
	SetDimmverfahren(KANAL1,ABSCHNITT);  // Abschnitt
	SetDimmverfahren(KANAL2,ABSCHNITT);  // Abschnitt
	CMP1# = CMP_U;
	CMP2# = CMP_U;
	EC = 1;  				// Comparator IRQ freigeben
//	EX0 = 1;                // X0 IRQ freigeben für I1
//	KBMASK = 0x02;			// nur Bit 1 beachten
//	KBPATN = 0x00;			// IRQ wenn 0
//	KBCON = 0x02;			// IRQ wenn = Pattern
//xxx	EKBI = 1;				// KBD IRQ freigeben für I2

//	HalbePeriode = 36864;	// Default = 50Hz
	HalbePeriode = 36000;	// @todo sonst Flackern bei voller Helligkeit, da beide Halbwellen unterschiedlich lang sind
	Nullkorrektur = 1400;

	// Timer setzen
	TR0 = 0;				// Timer aus
	TMOD =(TMOD&0xF0)|0x01;	// Timer0 Mode1 = 16bit ohne prescaler , d.h. 0.2713us
	TAMOD &= 0xF0;
	ET0 = 1;				// Timerinterrupt freigeben

	// Timerqueue initialisieren
	TQReadPointer = 0;
	TQAnzahlItems = 0;

	RTCH = 0x00;		// RTC auf 0,503 ms  [0x001D]
	RTCL = 0x1D;
	//EWDRT = 1;			// Enable RTC-IRQ tut nicht !!!
	RTCCON = 0x61;
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
	byte c;
	byte state;
	//
	for (c=0;c<2;c++)
	{
		NextDimmschritTime[c]--;
		if (NextDimmschritTime[c] == 0)
		{	// Zeit für Dimmschritt
			if (dim_val_soll[c]>dim_val_ist[c]) dim_val_ist[c]++;
			else if (dim_val_soll[c]<dim_val_ist[c]) dim_val_ist[c]--;
			else SendRueckmeldung(c,dim_val_ist[c]);
			BerechneDauer(c);
			NextDimmschritTime[c] = dimmschritt[c];
#ifdef debugRTC
			rs_send_s("\nIst:");
			rs_send_dec(dim_val_ist[0]);
			rs_send_s(",");
			rs_send_dec(dim_val_ist[1]);
#endif
		}
		// Zeit seit letztem U-IRQ hochzählen
		if (TimeSinceUIRQ[c]<0xFFFF)TimeSinceUIRQ[c]++;
		// Kurzschlußdauer hochzählen
		if (c==KANAL1) state = P_K_C1;
		else  state = P_K_C2;
		if(state & !IstSpannungsausfall[c])
		{	// Wenn Kurzschlußsignal und nicht Spannungsausfall
			if (TimeSinceShort[c]<0xFFFF) TimeSinceShort[c]++;		// Kurzschlußzeit hochzählen
		}
		else
		{
			TimeSinceShort[c] = 0;
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
/*
	if (!IstABSchnitt[c])
		if (dim_val_ist[c] == 0)
			if (val!=0) SET_KANAL(c,LAST_AN)
*/

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
 *	val = Grundhelligkeit 0..255  dunkel(Grundhelligkeit)..hell(MaxHelligkeit)
 */
void SetGrundhelligkeit(byte c, byte val)
{
	Grundhelligkeit[c] = val * (HalbePeriode>>8);
	ZeitFuerDimmschritt[c]= (HalbePeriode - MinAusZeit - Grundhelligkeit[c])>>8;
}



/**
 * neuen Befehl in Timerqueue eintragen  (für Timer0)
 * dabei müssen beide Kanäle gleichzeitig berücksichtigt werden
 *
 * *Dauer ist die Zeitdauer in ..
 * *Value ist der entsprechende Timerwert, es gilt *Value = - *Dauer
 */
void SetTimer(uint SollDauer, byte SollBefehl )
{
	//@todo wenn die dauern fast gleich sind, dann ein Befehl daraus machen !!!

	uint istDauer;
	uint SollValue;
	byte TQWritePointer;
	byte TQMovePointer;
	byte TQMoveToPointer;
	byte i;

	SollValue = - SollDauer;  // @todo kann später ersetzt werden

	if (TQAnzahlItems == 0)
	{	// Kein Befehl geplant, dann diesen einplanen
		TQ[TQReadPointer].bef = SollBefehl;		// Befehl eintragen
		TQ[TQReadPointer].TimerValue = -1;		// dadach kein weiterer Befehl vorhanden
		TQAnzahlItems++;						// Nun 1 Eintrag vorhanden
		TR0 = 0;								// Timer anhalten
		// Timerdauer setzen
		TH0 = MSB(SollValue);
		TL0 = LSB(SollValue);
		TR0 = 1;								// Timer starten
	}
	else if (TQAnzahlItems >= TimeQueueLen )
	{	// Kein Platz für weiteren Eintrag vorhanden
	}
	else
	{	// Befehle sind bereits geplant, dann prüfen wo dieser richtig einsortiert werden muss
		TR0 = 0;									// Timer anhalten
		istDauer = -((((uint)TH0)<<8) + TL0);		// dauer bis zum ersten Befehl bestimmen
		if (istDauer>SollDauer)
		{	// neuen Befehl vor allen anderen eintragen
			TQ_DEC(TQReadPointer);					// Lesepointer um 1 verkleinern
			TQAnzahlItems++;						// Anzahl der Einträge um 1 vergrößern
			TQ[TQReadPointer].bef = SollBefehl;		// Befehl eintragen
			TQ[TQReadPointer].TimerValue =  SollDauer - istDauer ;   // dann nur noch die Differenz warten  = - (istDauer - Solldauer)
			// Timer auf den neuen Befehl setzen
			TH0 = MSB(SollValue);
			TL0 = LSB(SollValue);
			TR0 = 1;								// Timer starten
		}
		else
		{	// neuen Befehl in Warteschlange einreihen, denn er ist nicht der erste
			TQWritePointer = TQReadPointer;
			SollDauer -= istDauer;					// Solldauer um Dauer bis ersten Befehl verkleinern
			// Schleife über alle vorhandenen Einträge
			i = 0;
			do
			{
				if (TQ[TQWritePointer].TimerValue == -1)
				{	// das war der letzte Befehl, dann einfach anhängen
					TQ[TQWritePointer].TimerValue = - SollDauer;	// Dauer bis zum nächsten Befehl eintragen (negativ da Value)
					TQ_INC(TQWritePointer);							// Zeiger auf neuen Befehl
					TQ[TQWritePointer].bef = SollBefehl;			// Befehl eintragen
					TQ[TQWritePointer].TimerValue = - 1;			// dieser ist dann der letzte
					TQAnzahlItems++;								// jetzt ein Eintrag mehr
					break;											// Schleife kann beendet werden
				}
				else if (SollDauer<-TQ[TQWritePointer].TimerValue)
				{	// nach diesem einfügen
					// es kommen weitere Befehle, dann diese nach hinten verschieben

					// zuerst den letzten suchen
					TQMovePointer = TQWritePointer;
					do
					{
						TQ_INC(TQMovePointer);
					} while (TQ[TQMovePointer].TimerValue!=-1);

					//	dann alle um eins nach hinten verschieben
					TQMoveToPointer = TQMovePointer;
					TQ_INC(TQMoveToPointer);
					do
					{
						TQ[TQMoveToPointer].TimerValue = TQ[TQMovePointer].TimerValue;
						TQ[TQMoveToPointer].bef = TQ[TQMovePointer].bef;
						if (TQMovePointer!=TQWritePointer) break;
						TQ_DEC(TQMoveToPointer);
						TQ_DEC(TQMovePointer);
					} while (1);

					// nun den neuen Befehl einfügen
					TQ[TQWritePointer].TimerValue = - SollDauer;	// Dauer bis zum nächsten Befehl eintragen (negativ da Value)
					TQ_INC(TQWritePointer);							// Zeiger auf neuen Befehl
					TQ[TQWritePointer].bef = SollBefehl;			// Befehl eintragen
					TQ[TQWritePointer].TimerValue += SollDauer ;	// um SollDauer kürzen
					TQAnzahlItems++;								// jetzt ein Eintrag mehr
					break;											// fertig eingefügt
				}
				else
				{	// erst kommt noch ein Befehl, deshalb nach diesem weitersuchen
					SollDauer += TQ[TQWritePointer].TimerValue;	// Solldauer entsprechend verringern
					TQ_INC(TQWritePointer);						// nächsten Eintrag
					i++;										// Zähler erhöhen
				}
			} while (i<TQAnzahlItems);
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
	TimeSinceUIRQ[c] = 0;				// Zeit seit U-IRQ zurücksetzen
	debugIRQ++;
	if (IstABSchnitt[c])
	{	// Abschnittsdimmer
		if (dim_val_ist[c]!=0)
		{
			SET_KANAL(c,LAST_AN);		// einschalten bei U=0 wenn ABschnitt
			// NEU: und Timer für nächstes einschalten setzen
			//xxx SetTimer(HalbePeriode-Nullkorrektur,BEF_EIN<<((c-KANAL1)*4));
			// jetzt den Timer für das Ausschalten setzen
			SetTimer(Dauer[c],BEF_AUS<<((c-KANAL1)*4));
		}
		else
		{
			SET_KANAL(c,LAST_AUS);		// ausschalten
		}
	}
	else
	{	// ANschnittsdimmer
		//if (IsCmpIrqU(c))
		{	// U = 0
			//if (dim_val_ist[c]!=255)
			{
				SET_KANAL(c,LAST_AUS)	// ausschalten bei I=0 wenn ANschnitt
				// NEU: und Timer für nächstes ausschalten setzen
				//xxx SetTimer(HalbePeriode-Nullkorrektur,BEF_AUS<<((c-KANAL1)*4));
			}
			// jetzt den Timer für das Einschalten setzen bei U=0
			if (dim_val_ist[c]!=0) 	SetTimer(Dauer[c],BEF_EIN<<((c-KANAL1)*4));
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
 * steht immer auf Spannung von Kanal1 oder Kanal2 gegen Uref
 * damit ist immer ein fester Bezugspunkt zum Anfang einer Periode gegeben
 *
 */
void U_IRQ(void) __interrupt 8   //  8 = Comparator Interrupt
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
	byte befehl;


	if (TQAnzahlItems !=0)
	{
		// Kanal1
		befehl = LSN(TQ[TQReadPointer].bef);
		if (befehl  == BEF_EIN)
		{
			if (dim_val_ist[KANAL1] !=0)
			{
				SET_KANAL(KANAL1,LAST_AN); 	//@todo evtl Bedingung unnötig
			}
		}
		else if (befehl == BEF_AUS)
		{
			SET_KANAL(KANAL1,LAST_AUS);
		}
		// Kanal2
		befehl = MSN(TQ[TQReadPointer].bef);
		if (befehl == BEF_EIN)
		{
			if (dim_val_ist[KANAL2]!=0)
				{
				SET_KANAL(KANAL2,LAST_AN); 	//@todo evtl Bedingung unnötig
				}
		}
		else if (befehl == BEF_AUS)
		{
			SET_KANAL(KANAL2,LAST_AUS);
		}

		TQAnzahlItems--;
		if (TQAnzahlItems>0)
		{
			TH0 = MSB(TQ[TQReadPointer].TimerValue);
			TL0 = LSB(TQ[TQReadPointer].TimerValue);
			TR0 = 1;					// Timer starten
		}

		TQ_INC(TQReadPointer);
	}
}


void I1_IRQ(void) __interrupt 0   //  0 = externer Interrupt 0
{
//	TR0 = 0;					// Timer anhalten
	I1_Zeit = -((((uint)TH0)<<8) + TL0);
//	TR0 = 1;
}

void I2_IRQ(void) __interrupt 7   //  7 = Keyboard Interrupt
{
//	TR0 = 0;					// Timer anhalten
	I2_Zeit = -((((uint)TH0)<<8) + TL0);
//	TR0 = 1;
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
	byte timeout = false;

	AnfangsPattern = 1<<Pattern1;
	EndStatus = State1 << Pattern1;
	EndPattern = 1<<Pattern2;
	s2 = State2 << Pattern2;

	EA=0;
	TR0 = 0;						// Timer aus

//	P_S_C1 = LAST_AN;				// Last Kanal1 einschalten
//	P_S_C2 = LAST_AN;				// Last Kanal2 einschalten
	for (i=0;i<0xff;i++);			//warten vor Messung bis Last stabil
	for (i=0;i<20;i++)
	{
		TL0 = 0;					// Timer zurücksetzen
		TH0 = 0;
		TR0 = 1;					// Timer Start
		//xxx hier müssen Timeouts eingebaut werden !!!
		while ((P0&AnfangsPattern)==EndStatus)
		{	// Warte auf !Anfangsstatus
			if (TH0==0xFF)
				{
				timeout = true;
				rs_send_s("TO1");
				return -1;
				}
		}
		TR0 = 0;					// Timer Stop
		TL0 = 0;					// Timer zurücksetzen
		TH0 = 0;
		TR0 = 1;					// Timer Start
		while ((P0&AnfangsPattern)!=EndStatus) // Warte auf Anfangsstatus
		{	// Warte auf Anfangsstatus
			if (TH0==0xFF)
				{
				timeout = true;
				rs_send_s(" TO2");
				return -1;
				}
		}
		TR0 = 0;					// Timer Stop
		TL0 = 0;					// Timer zurücksetzen
		TH0 = 0;
		TR0 = 1;					// Timer Start
		while ((P0&EndPattern)!=s2)
		{	// Warte auf Endestatus

			if (TH0==0xFF)
				{
				timeout = true;
				rs_send_s(" TO3");
				return -1;
				}

		}
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
/*
void Bestimme_Dimmverfahren(void)
{
	uint t,t1,t2;

	// zuerst Periodenlänge messen @todo
	P_S_C1 = LAST_AN;				// Last Kanal1 einschalten

	rs_send_s("\nU1h->U1l:");
	t1 = ZeitZwischen(U_C1,0,U_C1,1);

	rs_send_s("\nU1l->U1h:");
	t2 = ZeitZwischen(U_C1,1,U_C1,0);
    if (t1<t2) t=t1;
    else t = t2;
	rs_send_s("\nU-Periode/2: ");
    rs_send_hex_i(t);

	P_S_C1 = LAST_AUS;				// Last Kanal1 ausschalten

	rs_send_s("\nU1h->U1l:");
	t1 = ZeitZwischen(U_C1,0,U_C1,1);

	rs_send_s("\nU1l->U1h:");
	t2 = ZeitZwischen(U_C1,1,U_C1,0);
    if (t1<t2) t=t1;
    else t = t2;
	rs_send_s("\nU-Periode/2: ");
    rs_send_hex_i(t);


	P_S_C1 = LAST_AN;				// Last Kanal1 einschalten


	rs_send_s("\nI1l->I1h:");
	t1 = ZeitZwischen(I_C1,0,I_C1,1);

	rs_send_s("\nI1h->I1l:");
	t2 = ZeitZwischen(I_C1,1,I_C1,0);
    if (t1<t2) t=t1;
    else t = t2;
	rs_send_s("\nI-Periode/2: ");
    rs_send_hex_i(t);


	// Dann
	rs_send_s("\nU1h->I1h:");
	t2 = ZeitZwischen(U_C1,1,I_C1,1);

	rs_send_s("\nU1h->I1l:");
	t2 = ZeitZwischen(U_C1,1,I_C1,0);

	rs_send_s("\nU1l->I1h:");
	t2 = ZeitZwischen(U_C1,0,I_C1,1);

	rs_send_s("\nU1l->I1l:");
	t2 = ZeitZwischen(U_C1,0,I_C1,0);



	// Dimmverfahren bestimmen
	//@todo bisher nur test
	SetDimmverfahren(KANAL1,ABSCHNITT); // ABschnitt
	SetDimmverfahren(KANAL2,ABSCHNITT); // ABschnitt

	//SetDimmverfahren(KANAL1,ANSCHNITT); // ANschnitt
	//SetDimmverfahren(KANAL2,ANSCHNITT); // ANschnitt
}
*/


/**
 * Setzt kanal auf Dimmverfahren
 */
void SetDimmverfahren(byte kanal,byte Abschnittsdimmer)
{
	IstABSchnitt[kanal] = Abschnittsdimmer;

#ifdef debug_SetDimmverfahren
	rs_send_s("\nSetDimmverfahren Kanal");
	rs_send_hex(kanal);
	if (Abschnittsdimmer)
	{
		rs_send_s(" ABschnitt");
	}
	else
	{
		rs_send_s(" ANschnitt");
	}
#endif
}

#define debug_SetCmpIrq
/**
 *  Setzt den CMP-IRQ auf Strom oder Spannungseingang
 */
/*
void SetCmpIrq(byte kanal,byte CMPState)
{
#ifdef debug_SetCmpIrq
	rs_send_s("\nSetCmpIrq");
	rs_send_hex(kanal);
	rs_send_s(" CMPState");
	rs_send_hex(CMPState);
#endif

	if (kanal==KANAL1)
	{
		CMP1# = CMPState;
	}
	else
	{
		CMP2# = CMPState;
	}
}
*/
/**
 * Liefert true wenn der Kanal auf Spannungssignal steht
 */
/*
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
*/


void ShowTQ(void)
{
#ifdef DebugTQ
	byte i;
		rs_send_s("\nTimerqueue:");
		rs_send_s("\n  TQAnzahlItems=");
		rs_send_hex(TQAnzahlItems);
		rs_send_s("\n  TQReadPointer=");
		rs_send_hex(TQReadPointer);
		for(i=0;i<TimeQueueLen;i++)
		{
			rs_send_s("\n  [");
			rs_send_hex(i);
			rs_send_s("] ");
			rs_send_hex(TQ[i].bef);
			rs_send_s("  ");
			rs_send_hex_i(TQ[i].TimerValue);
			//rs_send_s(" ");
		}


#endif

}
