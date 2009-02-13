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

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_ft.h"


unsigned char rsin[32];					// serieller Empfangspuffer
unsigned char rsinpos, switch_mode;
bit fcb;
unsigned char property_5;
bit ft_ack;


#define FT_SEND_T_DATACONNECTED_CONF \
	FT_SET_HEADER(rsin[1],0x8E) \
	ft_send_frame();

#define FT_SEND_L_DATA_CONF \
	FT_SET_HEADER(rsin[1],0x2E) \
	rsin[6]=0xB0 + (rsin[6] & 0x0F); \
	rsin[7]=eeprom[ADDRTAB+1]; \
	rsin[8]=eeprom[ADDRTAB+2]; \
	ft_send_frame();

#define FT_SET_HEADER(length, control) \
	rsin[0]=0x68; \
	rsin[1]=length; \
	rsin[2]=length; \
	rsin[3]=0x68; \
	fcb=!fcb; \
	rsin[4]=0xD3+(fcb<<5); \
	rsin[5]=control; 

#define FT_SEND_CHAR(sc) \
	TB8=0; \
	for (n=0;n<8;n++) { \
		if (sc & (1<<n)) TB8=!TB8; \
	} \
	SBUF=sc; \
	while(!TI); \
	TI=0; \
	for(n=0;n<10;n++) TI=0;



void ft_process_var_frame(void)
{
	unsigned char n;
	bit write_ok=0;
	
	if (rsin[0]==0x68 && rsin[3]==0x68 && rsin[1]==rsin[2]) {	// Multi Byte
		if ((rsin[4]&0xDF)==0x53) {		// send_Udat
			switch (rsin[5])		// PEI10 message code
			{
			case 0x11:		// send a telegram on the bus
				FT_SEND_CHAR(0xE5)				
				EX1=0;
				for (n=3;n<(rsin[1]-2);n++) telegramm[n]=rsin[n+6];
				telegramm[0]=0xB0 + (rsin[6] & 0x0F);
				telegramm[1]=eeprom[ADDRTAB+1];	// PA high
				telegramm[2]=eeprom[ADDRTAB+2];	// PA low	
				FT_SEND_L_DATA_CONF				// send confirmation frame				
				send_telegramm();

				IE1=0;
				EX1=1;				
				break;
				
			case 0xA9:		// PEI_switch_request	
				FT_SEND_CHAR(0xE5)
				if (rsin[6]==0x00 && rsin[8]==0x34) {
					if  (rsin[7]==0x12) {
						if (rsin[9]==0x56 && rsin[10]==0x78 && rsin[11]==0x9A) switch_mode=0x00; // normal mode
						if (rsin[9]==0x56 && rsin[10]==0x78 && rsin[11]==0x8A) switch_mode=0x01; // application layer
						if (rsin[9]==0x48 && rsin[10]==0x88 && rsin[11]==0x0A) switch_mode=0x02; // transport layer remote
						if (rsin[9]==0x56 && rsin[10]==0x78 && rsin[11]==0x0A) switch_mode=0x03; // transport layer local
					}
					if (rsin[7]==0x18) {
						if (rsin[9]==0x56 && rsin[10]==0x78 && rsin[11]==0x0A) switch_mode=0x04; // link layer
					}
				}
				if (rsin[6]==0x90 && rsin[7]==0x18 && rsin[8]==0x34 && rsin[9]==0x56 && rsin[10]==0x78 && rsin[11]==0x0A) switch_mode=0x05; // busmonitor
				break;
				
			case 0x43:		// T_connect_request
				FT_SEND_CHAR(0xE5)
				if (switch_mode==0x03) {
					FT_SET_HEADER(0x07,0x86)
					rsin[6]=(0x00);
					rsin[7]=(0x00);
					rsin[8]=(0x00);
					rsin[9]=(0x00);
					rsin[10]=(0x00);
					ft_send_frame();
				}
				break;
				
			case 0x44:	// T_Disconcect.req
				FT_SEND_CHAR(0xE5)
				if (switch_mode==0x03) {
					FT_SET_HEADER(rsin[1],0x88)
					ft_send_frame();
				}
				break;				
				
			case 0x41:		// T_dataConnected.request
				FT_SEND_CHAR(0xE5)
				if (switch_mode==TLlocal) { 	// Transport Layer local															
					switch (rsin[12]) {
					case 0x03:
						switch (rsin[13]) {
						case 0x00:		// Read_Mask_Version_Req	  
							FT_SEND_T_DATACONNECTED_CONF		
							FT_SET_HEADER(0x0C,0x89)
							rsin[6]=(0x00);
							rsin[7]=(0x00);
							rsin[8]=(0x00);
							rsin[9]=(0x00);
							rsin[10]=(0x00);
							rsin[11]=(0x63);	// DRL L�nge 3 Bytes
							rsin[12]=(0x03);	// 03 40 = Read_Mask_Version_res
							rsin[13]=(0x40);	//
							rsin[14]=(0x00);	// Maskenversion 00 21
							rsin[15]=(0x21);
							ft_send_frame();
							break;
						case 0xD5:
							if (rsin[14]==0x01 && rsin[15]==0x05 && rsin[16]==0x10 && rsin[17]==0x01)	// Read_Property_Value_Req
							{
								FT_SEND_T_DATACONNECTED_CONF
								FT_SET_HEADER(0x0F,0x89)
								rsin[11]=0x66;
								rsin[13]=0xD6;
								rsin[18]=property_5;
								ft_send_frame();
							}
							break;
						case 0xD7:
							if (rsin[14]==0x01 && rsin[15]==0x05 && rsin[16]==0x10 && rsin[17]==0x01)	// Write_Property_Value_Req
							{
								FT_SEND_T_DATACONNECTED_CONF
								if (rsin[18]==0x01) property_5=0x02; else property_5=0x01;
								FT_SET_HEADER(0x0F,0x89)
								rsin[11]=0x66;
								rsin[13]=0xD6;
								rsin[18]=property_5;
								ft_send_frame();
							}	
							break;
							
						case  0xD1:		// Authorize_Req
							FT_SEND_T_DATACONNECTED_CONF
							rsin[4]|=0x80;		// DIR=1 BAU to external device
							//rsin[4]^=0x20;		// toggle FCB

							FT_SET_HEADER(0x0B,0x89)
							rsin[11]=0x62;// 66
							rsin[13]=0xD2;	
							ft_send_frame();
							break;
						}
						break;
						
					case 0x02:
						switch (rsin[13]&0xF0) {
						case 0x00:	// Read_Memory_Req
							FT_SEND_T_DATACONNECTED_CONF
							ft_send_Read_Memory_Res((rsin[13]&0x0F),rsin[14],rsin[15]);
							break;
							
						case 0x80:	// Write_Memory_Req
							
							EA=0;
							//EX1=0;
							write_ok=0;
							while (!write_ok) {
								start_writecycle();
								for (n=0;n<(rsin[13]&0x0F);n++) write_byte(rsin[14],rsin[15]+n,rsin[16+n]);
								stop_writecycle();
								if(!(FMCON & 0x0F)) write_ok=1;	// pr�fen, ob erfolgreich geflasht
							}
							EA=1;
							
			
							FT_SEND_T_DATACONNECTED_CONF
							
							//EX1=1;
							break;
						}
					}
					break;
				}
				break;
				
			case 0xA7:		// PEI_identify_request
				PEI_identify_req();
				break;
			}
		}
	}
	rsinpos=0;
}


void ft_process_fix_frame(void)		// frame with fixed length received
{
	unsigned char n;
	
	if (rsin[0]==0x10 && rsin[3]==0x16 && rsin[1]==rsin[2]) {	// Single Byte
		if ((rsin[1]&0x0F)==0x00) {	//send_reset received
			FT_SEND_CHAR(0xE5)		// send an ack
			restart_app();
		}
		if (rsin[1]==0x49) {		// N_DataConnected.ind received
			FT_SEND_CHAR(0x10)
			FT_SEND_CHAR(0x8B)
			FT_SEND_CHAR(0x8B)
			FT_SEND_CHAR(0x16)
		}
	}
	rsinpos=0;
}


void ft_send_Read_Memory_Res(unsigned char bytecount, unsigned char adrh, unsigned char adrl)
{
	unsigned char n;

	FT_SET_HEADER(bytecount+12,0x89)

	rsin[6]=0x0C;
	rsin[7]=0x00;
	rsin[8]=0x00;
	rsin[9]=0x00;
	rsin[10]=0x00;
	rsin[11]=bytecount+3;
	rsin[12]=0x02;
	rsin[13]=0x40+bytecount;
	rsin[14]=adrh;
	rsin[15]=adrl;
	if (switch_mode==0x03) for (n=0;n<bytecount;n++) rsin[n+16]=eeprom[adrl+n];
	ft_send_frame();
}




void process_telegram(void)		// EIB telegram received
{
	unsigned char n;	
	bit ack;

	if (switch_mode==0x05)		// busmonitor
	{
		ack=get_ack();
		FT_SET_HEADER((telegramm[5]&0x0F)+13,0x2B)
		rsin[6]=0x01;	// status
		rsin[7]=0x22;	// timestamp
		rsin[8]=0x33;	// timestamp
		for (n=0;n<(rsin[1]-4);n++) rsin[n+9]=telegramm[n];	// -1
		ft_send_frame();
		last_tel=0;
		
		if (ack) {
			FT_SET_HEADER(0x06,0x2B)
			rsin[6]=0x01;
			rsin[7]=0x33;	// timestamp
			rsin[8]=0x44;	// timestamp
			rsin[9]=0xCC;
			ft_send_frame();
		}
		ET1=1;					// Interrupt f�r Timer 1 freigeben
		IE1=0;					// Interrupt 0 request zur�cksetzen
		EX1=1;					// Interrupt 0 wieder freigeben
	}
	else {
		EX1=0;
		send_ack();
		IE1=0;
		EX1=1;
		FT_SET_HEADER((telegramm[5]&0x0F)+9,0x29)	// +9
		for (n=0;n<(rsin[1]-1);n++) rsin[n+6]=telegramm[n];	// -1
		ft_send_frame();
		last_tel=0;
	}
}


void ft_send_frame(void)	// send a frame with variable length that is stored in rsin
{
	unsigned char b,n,repeat;
	unsigned int timeout;
	
rsinpos=0;
	repeat=0;
	while (repeat<4) {		// repeat sending frame up to 3 times if not achnowleged
		rsin[rsin[1]+4]=0;
		for (n=4;n<(rsin[1]+4);n++) rsin[rsin[1]+4]+=rsin[n];	// checksum berechnen
		rsin[rsin[1]+5]=0x16;
	ES=0;
		for (b=0;b<(rsin[1]+6);b++) {
			FT_SEND_CHAR(rsin[b])
			
		}
	ES=1;
		rsinpos=0;
		timeout=0;
		while (timeout<10000) {		// give enough time to receive an ack
			if (ft_ack) {			
				repeat=4;
				timeout=10000;
				ft_ack=0;
			}
			timeout++;
		}
		repeat++;
	}
}


void ft_send_fixed_frame(unsigned char controlfield)	// send a frame with fixed length (single byte)
														// that is passed as parameter
{
	unsigned char n,r;
	
	r=0;
	while (r<4) {
		rsin[0]=0x10;
		rsin[1]=controlfield;
		rsin[2]=controlfield;
		rsin[3]=0x16;
		ES=0;
		for (n=0;n<4;n++) {
			FT_SEND_CHAR(rsin[n])
		}
		ES=1;
		//if (ft_get_ack()) r=4;
		r++;
	}
}



void PEI_identify_req(void)
{
	unsigned char n;
	
	FT_SEND_CHAR(0xE5)
	
	FT_SET_HEADER(0x0A,0xA8)

	rsin[6]=eeprom[ADDRTAB+1];
	rsin[7]=eeprom[ADDRTAB+2];
	rsin[8]=0x00;
	rsin[9]=0x01;	
	rsin[10]=0x00;	
	rsin[11]=0x00;	
	rsin[12]=0xE4;
	rsin[13]=0x5A;
	rsin[14]=0;
	ft_send_frame();

}



void ft_rs_init(void)
{  

  SCON=0xD0;	// Mode 3, receive enable
  SSTAT|=0x40;	// TI wird am Ende des Stopbits gesetzt
  BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
  BRGR1=0x01;	// Baudrate = cclk/((BRGR1,BRGR0)+16) = 19200
  BRGR0=0x80;
  BRGCON|=0x01;	// Baudrate Generator starten
}


void serial_int(void) interrupt 4 using 2	// Interrupt on received char from serial port
{

	
	ES=0;
	if (RI) {
		if (rsinpos<32) {
			rsin[rsinpos]=SBUF;		// store byte in rsin
			rsinpos++;
			RI=0;
			TI=0;
			if (rsinpos==1 && rsin[0]==0xE5) {	// in case of ack, set the ft_ack bit
				ft_ack=1;
				rsinpos=0;
			}
			TR0=0;
			TH0=0xCC;	// set timer to max idle time between 2 bytes = 33 bit
			TL0=0xFF;
			TF0=0;
			TR0=1;
		}

		else {
			rsinpos=0;
			TF0=0;
			TR0=0;
		}
	}
	
	ES=1;
}







void write_value_req(void)
{

}







void restart_app(void)		// Alle Applikations-Parameter zur�cksetzen
{
	P0M1=0;
	P0M2=0;
	
	
	  ft_rs_init();			// serielle Schnittstelle initialisieren f�r FT1.2
	  rsinpos=0;
	  ES=1;					// enable serial interrupt

//	  telegramm[8]=0x11;	// TODO PA wird hier fix auf 1.1.255 gesetzt
//	  telegramm[9]=0xFF;
//	  set_pa();
	  
	  switch_mode=0x00;		// normal mode
	  fcb=0;
	  property_5=0x01;
	  
	  transparency=1;		// telegramme nicht in prot.c auswerten
	  
	  
}
