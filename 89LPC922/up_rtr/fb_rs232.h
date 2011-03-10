/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2008-2010 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
/**
* @file   fb_rs232.h
* @author Andreas Krebs <kubi@krebsworld.de>
* @date    2008
* 
* @brief  Hier sind ausschliesslich die RS232 Routinen fuer den 89LPC922
* 
*
*/


#ifndef FB_RS232
#define FB_RS232

#ifdef DEBUG
#define ENABLE_RS_INIT          1
#define ENABLE_RS_SEND_DEC      1
//#define ENABLE_RS_SEND_HEX      1
//#define ENABLE_RS_SEND_HEXL     1
//#define ENABLE_RS_SEND_HEXI     1
#define ENABLE_RS_SEND_S        1
#endif

// funktion rs_send() wird für die Hex-Funktionen benötigt
#define ENABLE_RS_SEND          (defined(ENABLE_RS_SEND_HEX) || defined(ENABLE_RS_SEND_HEXL) || defined(ENABLE_RS_SEND_HEXI))


#ifdef ENABLE_RS_INIT
void rs_init(unsigned int baudrate);
#endif

#ifdef ENABLE_RS_SEND_DEC
void rs_send_dec(unsigned int wert);
#endif

#ifdef ENABLE_RS_SEND_HEX
void rs_send_hex(unsigned char wert);
#endif

#ifdef ENABLE_RS_SEND_HEXL
void rs_send_hex_l(unsigned long wert);
#endif

#ifdef ENABLE_RS_SEND_HEXI
void rs_send_hex_i(unsigned int wert);
#endif

#if defined(ENABLE_RS_SEND) && ENABLE_RS_SEND
void rs_send(unsigned char z);
#endif

#ifdef ENABLE_RS_SEND_S
void rs_send_s(unsigned char *s);
#endif

#endif
