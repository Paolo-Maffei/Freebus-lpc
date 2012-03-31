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


#ifdef IsDebug
	void rs_init(void);
	void rs_send_dec(unsigned int wert);
	void rs_send_hex(unsigned char wert);
	void rs_send_hex_l(unsigned long wert);
	void rs_send_hex_i(unsigned int wert);
	void rs_send_ok(void);
	void rs_send(unsigned char z);
	void rs_send_s(unsigned char *s);
	void rs_show(unsigned char *s,unsigned int c1,unsigned int c2);
#else
	#define rs_init()
	#define rs_send_dec(x)
	#define rs_send_hex(x)
	#define rs_send_hex_l(x)
	#define rs_send_hex_i(x)
	#define rs_send_ok()
	#define rs_send(x)
	#define rs_send_s(x)
    #define rs_show(a,c1,c2)
#endif
#endif
