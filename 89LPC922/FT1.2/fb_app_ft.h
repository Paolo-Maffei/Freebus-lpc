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

#ifndef FB_APP_FT
#define FB_APP_FT

#define ASSOCTABPTR 	0x11	// Adresse des Pointers auf die Assoziations-Tabelle
#define COMMSTABPTR 	0x12	// Adresse des Pointers auf die Kommunikationsobjekt-Tabelle
#define ADDRTAB		0x16	// Startadresse der Adresstabelle
#define FUNCASS		0xD8	// Startadresse der Zuordnung der Zusatzfunktionen (2 Byte)
#define FUNCTYP		0xED	// Typ der Zusatzfunktion
#define LOGICTYP	0xEE	// Verkn�pfungs Typ 0=keine 1=ODER 2=UND 3=UND mir R�ckf�hrung
#define BLOCKACT	0xEF	// Verhalten beim Sperren
#define RELMODE		0xF2	// Relaisbetrieb
#define	DELAYTAB	0xF9	// Start der Tabelle f�r Verz�gerungswerte (Basis)

#define TLlocal		0x03
#define LL			0x04

extern unsigned char rsin[32];
extern unsigned char rsinpos, switch_mode;
extern bit fcb;
extern unsigned char property_5;
extern bit ft_ack;


void ft_process_var_frame();
void ft_process_fix_frame();
void process_telegram(void);
void PEI_identify_req(void);
void ft_send_T_DataConnected_conf();
void ft_send_L_Data_conf();
void ft_send_Read_Memory_Res(unsigned char bytecount, unsigned char adrh, unsigned char adrl);
// void ft_set_header(unsigned char length, unsigned char control);
//bit ft_get_ack(void);
void ft_rs_init(void);
void ft_send_frame(void);
void ft_send_fixed_frame(unsigned char controlfield);
void serial_int(void) interrupt 4 using 2;
// void ft_send_char(unsigned char sc);
void restart_app(void);		// Alle Applikations-Parameter zur�cksetzen
void write_value_req(void);
void read_value_req(void);
unsigned long read_obj_value(unsigned char objno);
#endif
