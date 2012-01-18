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
* @file   fb_uni_dim.h
* @author Rainer Petzoldt <r.petzoldt@web.de>
* @date   17.10.2009
*
* @brief  Hier sind ausschliesslich die Universaldimmer Routinen fuer den 89LPC922
*
*
*/

#include "AllgDefs.h"

#ifndef FB_UNIV_DIM
#define FB_UNIV_DIM

// Portdefinitionen Port 0
#define S_C1      6		// Bit  fuer Ansteuerung Kanal1
#define P_S_C1 P0_6		// Port fuer Ansteuerung Kanal1
#define U_C1      4		// Bit  fuer Spannungssignal Kanal1
#define P_U_C1 P0_4		// Port fuer Spannungssignal Kanal1
#define I_C1      3		// Bit  fuer Stromsignal Kanal1
#define P_I_C1 P0_3		// Port fuer Stromsignal Kanal1
#define K_C1      5		// Bit  fuer Ueberlastsignal Kanal1
#define P_K_C1 P0_5		// Port fuer Ueberlastsignal Kanal1
#define S_C2      0		// Bit  fuer Ansteuerung Kanal2
#define P_S_C2 P0_0		// Port fuer Ansteuerung Kanal2
#define U_C2      2		// Bit  fuer Spannungssignal Kanal2
#define P_U_C2 P0_2		// Port fuer Spannungssignal Kanal2
#define I_C2      1		// Bit  fuer Stromsignal Kanal2
#define P_I_C2 P0_1		// Port fuer Stromsignal Kanal2
#define K_C2      7		// Bit  fuer Ueberlastsignal Kanal2
#define P_K_C2 P0_7		// Port fuer Ueberlastsignal Kanal2

extern unsigned int I1_Zeit;
extern unsigned int I2_Zeit;
extern unsigned int debugIRQ;

// @todo nur für Debugausgaben im MAIN
extern __idata volatile uint ZeitFuerDimmschritt[2];  	// Zeit in Ticks für eine Dimmstufe
extern __idata volatile uint Grundhelligkeit[2];		// Grundhelligkeitin Ticks
extern __idata volatile uint Dauer[AnzahlKanaele] ;		// Dauer in Ticks bis zum Toggeln des Ausgangs
extern __idata volatile uint TimeSinceUIRQ[2];			// Zeit seit letztem U-IRQ in 0.5ms
extern __idata volatile uint TimeSinceShort[2];			// Zeit seit Kurzschluß in 0.5ms

extern __idata volatile byte dim_val_soll[2];				// gewünschte Helligkeit [0..255]   0=aus   255=ein
extern __idata volatile byte dim_val_ist[2];				// aktuelle Helligkeit [0..255]     0=aus   255=ein
//extern __idata volatile uint Dauer[AnzahlKanaele] ;		// Dauer in Ticks bis zum Toggeln des Ausgangs
//extern __idata volatile ulong dimmschritt[AnzahlKanaele] ;	// Dauer in RTC-Ticks bis zum nächsten Helligkeitswert
//extern __idata volatile byte IstABSchnitt[2];	         	// Abschnittsdimmer(!=0) oder Anschnittsdimmer (=0)
//extern __idata volatile ulong RTC_time[AnzahlKanaele];	// Rückwärtszaehler der 0.5 ms Intervalle pro Kanal füer andimmen, ...
//extern __idata volatile uint ZeitFuerDimmschritt[2];  	// Zeit in Ticks für eine Dimmstufe
//extern __idata volatile uint Grundhelligkeit[2];		// Grundhelligkeitin Ticks

//volatile uint HalbePeriode;						// Haelfte der Periodendauer in Ticks
extern volatile uint Nullkorrektur;
//extern volatile byte bef, nextBef;
//extern volatile byte kanal, nextKanal;
//extern volatile uint nextTimerWert;

/*
 * Initialisierung des Universaldimmers (nach HAL)
 */
void ud_init(void);


/**
 *  Schalten Dimmer Kanal c auf Helligkeitswert val beruecksichtigt auch andimmen
 */
void SwitchDimmer(byte c,byte val, byte anspringen, unsigned long schrittweite);


/**
 * Beendet den Dimmvorgang und behält die aktuelle Helligkeit
 */
void StopDimming(byte c);


/**
 *  Setzt Grundhelligkeit und ZeitFuerDimmschritt
 *	c = Kanal
 *	val = Grundhelligkeit 0..255  dunkel..hell
 */
void SetGrundhelligkeit(byte c, byte val);


/**
 * RTC Interrupt (simuliert durch polling)
 */
void RTC_IRQ(void) ;//__interrupt 10;   // = RTC Interrupt


void I1_IRQ(void) __interrupt 0;   //  0 = externer Interrupt 0

void I2_IRQ(void) __interrupt 7;   //  7 = Keyboard Interrupt


// Comparator Interrupt // muss in .h stehen wegen IRQ
void U_IRQ(void) __interrupt 8  ;


// Behandlung CMP-IRQ auf Kanal c
// void Handle_CMP_IRQ(byte c);

// Timer setzen mit Warteschlange
//void SetTimer(uint _dauer, byte _kanal, byte _befehl );


// Timer0 Interrupt // muss in .h stehen wegen IRQ
void Timer_IRQ(void) __interrupt 1 ;

/**
 * Einmessen der Phsaenlagen von Strom unf Spannung
 */
//void Bestimme_Dimmverfahren(void);

/**
 * Setzt kanal auf Dimmverfahren
 */
void SetDimmverfahren(byte kanal, byte Abschnittsdimmer);

/**
 *  Setzt den CMP-IRQ auf Strom oder Spannungseingang
 */
void SetCmpIrq(byte kanal,byte CMPState);


/**
 * Liefert true wenn der Kanal auf Spannungssignal steht
 */
byte IsCmpIrqU(byte kanal);

// Debugausgaben
void ShowTQ(void);


#endif
