
#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_rs232.h"
#include "fb_app_th.h"




bit ow_init(void)		// one-wire Gerät initialisieren
{
  bit presence;
  unsigned char n;
  
  presence=1;
  OWDATA=0;
  delay(2000);
  OWDATA=1;
  for (n=0;n<200;n++) presence=presence && OWDATA;
  presence=!presence;
  return (presence);
}

void ow_write(unsigned char owbyte)	// Byte an one-wire Gerät senden
{
  unsigned char n,m;

  for (n=0;n<8;n++)		// LSB zuerst
  {
   
    if ((owbyte & (0x01<<n)) != 0)
    {
      for (m=0;m<2;m++) OWDATA=0;	// 1-Bit: 5µs auf low dann auf high und 85µs warten
      OWDATA=1;
      delay(260);
    }
    else
    {
      OWDATA=0;			// 0-Bit: 90µs auf low dann auf high
      delay(275);
      OWDATA=1;
    }
  }
}


unsigned char ow_read(void)			// Byte von one-wire Gerät lesen
{
  unsigned char n,m,b,d;
  
  d=0;
  for (n=0;n<8;n++)
  {
    for (m=0;m<2;m++) OWDATA=0;
    OWDATA=1;
    delay(1);
    b=OWDATA<<n;
    delay(120);
    d=d|b;
  }
  return(d);
}



bit ow_read_bit(void)				// Bit von one-wire Datenleitung einlesen
{
	unsigned char m;
	bit b;
	
	for (m=0;m<2;m++) OWDATA=0;
	OWDATA=1;
	delay(1);
	b=OWDATA;
	delay (120);
	return (b);
}



int read_temp(void)					// Temperatur einlesen und gem EIS6 umrechnen
{
  unsigned char lsb,msb;
  int t,t2;
  
  do {
	  interrupted=0;
	  if (ow_init()) {
		  ow_write(0xCC);			// Skip-ROM command: alle parallel angeschlossenen Geräte werden angesprochen
		  ow_write(0x44);			// start single temperature conversion command
		  while(!ow_read_bit());	// warten bis Messung fertig, d.h. Bit = 1 ist
	  }
  } while(interrupted);
   
  do {
  	  interrupted=0;
  	  if (ow_init()) {
  		  ow_write(0xCC);			// Skip-ROM command: alle parallel angeschlossenen Geräte werden angesprochen
  		  ow_write(0xBE);			// read scratchpad command: Speicher einlesen
  		  lsb=ow_read();			// LSB von Temperaturwert
  		  msb=ow_read();			// MSB von Temperaturwert
  		  t2=((msb&0x07)<<8)+lsb;	// Umrechnen von Basis 1/16 auf Basis 1/100
  		  t=t2*6;
  		  t2=t2>>2;
  		  t=t+t2;
  		  t=t>>3;
  		  t=t+((msb & 0x80)<<8);	// Vorzeichen
  		  t=t+(0x18 << 8);			// Exponent 3
  	  }
  	  else t=0xFFFF;				// im Fehlerfall 0xFFFF zurückmelden
  } while (interrupted);
  
  return (t);
}







void eis1(void)
{
  rs_send_dec(telegramm[3]>>3);
  SBUF='.';
  while(!TI);
  TI=0;
  rs_send_dec(telegramm[3] & 0x07);
  SBUF='.';
  while(!TI);
  TI=0;
  rs_send_dec(telegramm[4]);
  SBUF='=';
  while(!TI);
  TI=0;
  rs_send_dec(telegramm[7] & 0x01);
  SBUF=0x0D;
  while(!TI);
  TI=0;
  SBUF=0x0A;
  while(!TI);
  TI=0;
}

void read_value_req(void)
{
}




void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{


  
  P3M1=0x00;				// Port 3_1 bidirektional
  P3M2=0x00;
  P3_1=1;

  start_writecycle();
  write_byte(0x01,0x04,0x01);	// Herstellercode 0x01 = Siemens
  write_byte(0x01,0x05,0x22);	// Geräte Typ (AP254) 221Ch
  write_byte(0x01,0x06,0x1C);	// 	"	"	"
  write_byte(0x01,0x07,0x01);	// Versionsnummer
  write_byte(0x01,0x0C,0x00);
  write_byte(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
  write_byte(0x01,0x12,0x56);	// COMMSTAB Pointer
  stop_writecycle();
}
