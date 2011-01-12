/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2010 Jan Wegner
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

#include <P89LPC922.h>
#include "fb_hal_lpc.h"
#include "fb_prot.h"
#include "spi.h"


unsigned char spi_in_out(unsigned char led)
{
	unsigned char daten=0, n, out=0, daten_help=0;

	out=(led&0x03)<<3;
	out|=(led&0x0C)>>1;
	out|=(led&0x30)<<1;

	RW=1;

	do
	{

		if(interrupted){
			RW=0;
			RW=1;
			interrupted=0;
		}

		for(n=0;n<=7;n++)
		{
			CLK=0;
			daten<<=1;
			if (SER_IN) daten++;
			SER_OUT=(out&0x80)>>7;
			out<<=1;
			CLK=1;
		}

	}while (interrupted);

	RW=0;

	daten_help=(daten&0x15)<<1;
	daten_help|=(daten&0x2A)>>1;

 	return daten_help;

}
