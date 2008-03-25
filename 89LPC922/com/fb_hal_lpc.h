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


#ifndef FB_HAL
#define FB_HAL

#define FBOUTC	P1_6	// Sendepin
#define TASTER	P1_7	// Pin für Programmiertaster
#define FBINC	P1_4	// Empfangspin
#define DUTY	0xC0	// war C0  0xFF=immer low 0x00=immer high


extern __code unsigned char __at 0x1C00 userram[255];	// Bereich im Flash für User-RAM
extern __code unsigned char __at 0x1D00 eeprom[255];	// Bereich im Flash für EEPROM

extern bit parity_ok;		// Parity Bit des letzten empfangenen Bytes OK
extern bit interrupted;		// wird durch interrupt-routine gesetzt. so kann eine andere routine prüfen, ob sie unterbrochen wurde

unsigned char get_byte(void);
void ext_int0(void) interrupt 2;
bit sendbyte(unsigned char fbsb);
void start_writecycle(void);
void stop_writecycle(void);
void write_byte(unsigned char addrh, unsigned char addrl, unsigned char zdata);
unsigned char read_byte(unsigned char addrh, unsigned char addrl);
void delay(int deltime);
void set_timer1(int deltime);
void restart_hw(void);

#endif
