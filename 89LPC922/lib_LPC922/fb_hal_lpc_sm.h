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
 */
/**
* @file   fb_hal_lpc.h
* @author Andreas Krebs <kubi@krebsworld.de>
* @date    2008
* 
* @brief  Hier sind ausschliesslich die Hardware-spezifischen aber Applikations-unabhaengigen Routinen fuer den 89LPC922
* 
* 
*/


#ifndef FB_HAL
#define FB_HAL

#define FBOUTC		P1_6	/// Sendepin
#define TASTER		P1_7	/// Pin fuer Programmiertaster
#define FBINC		P1_4	/// Empfangspin
#define PWM		P1_2	/// PWM-Pin

#define PORT	P0		/// Port fuer 8-bit I/O

#define RECEIVE_INT_ENABLE	EX1		// Interrupt enable Flag fuer Empfang


#define ASSOCTABPTR 	0x11	// Adresse des Pointers auf die Assoziations-Tabelle
#define COMMSTABPTR 	0x12	// Adresse des Pointers auf die Kommunikationsobjekt-Tabelle
#define ADDRTAB			0x16	// Startadresse der Adresstabelle



// Konfiguriert den entsprechenden pin als bidirectional mit internem pull-up R
#define SET_PORT_MODE_BIDIRECTIONAL(pin) \
	if (pin<8) { \
		P0M1&=(0xFF-(1<<pin)); \
		P0M2&=(0xFF-(1<<pin)); \
	}



// Konfiguriert den entsprechenden pin als pushpull
#define  SET_PORT_MODE_PUSHPULL(pin) \
	if (pin<8) { \
		P0M1&=(0xFF-(1<<pin)); \
		P0M2|=(1<<pin); \
	}


// Konfiguriert den entsprechenden pin als input-only (high impedance, ohne pull-up R) 
#define  SET_PORT_MODE_INPUT(pin) \
	if (pin<8) { \
		P0M1|=(1<<pin); \
		P0M2&=(0xFF-(1<<pin)); \
	}

// Konfiguriert den entsprechenden pin als ausgang mit open drain
#define  SET_PORT_MODE_OPENDRAIN(pin) \
	if (pin<8) { \
		P0M1|=(1<<pin); \
		P0M2|=(1<<pin); \
	}

#define START_WRITECYCLE \
	FMCON=0x00;

#define STOP_WRITECYCLE \
	FMCON=0x68;

#define WRITE_BYTE(addrh, addrl, zdata) \
		FMADRH=(addrh&0x01)+0x1C; \
		FMADRL=addrl; \
		FMDATA=zdata; 


// Globale Variablen
extern unsigned char telegramm[23];
extern unsigned char telpos;		// Zeiger auf naechste Position im Array Telegramm
extern __code unsigned char __at 0x1C00 userram[255];	// Bereich im Flash fuer User-RAM
extern __code unsigned char __at 0x1D00 eeprom[255];	// Bereich im Flash fuer EEPROM
extern volatile bit interrupted;		// wird durch interrupt-routine gesetzt. so kann eine andere routine pruefen, ob sie unterbrochen wurde
extern volatile unsigned char fb_state;
extern bit ack, nack, tel_arrived, auto_ack;


// Funktionen
void X1_int(void) interrupt 2;
void T1_int(void) interrupt 3;
void init_rx(void);
void init_tx(void);
void init_repeat_tx(void);
void send_tel(void);
unsigned char gapos_in_gat(unsigned char gah, unsigned char gal);
void set_timer0(unsigned int deltime);
void start_rtc(unsigned char base);	// RTC starten, base in ms
void stop_rtc(void);
void restart_hw(void);
void send_tel(void);

// Funktionen in prot
extern void process_tel(void);

#endif
