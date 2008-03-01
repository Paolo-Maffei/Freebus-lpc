// Versionen:	1.00	erste Version

	

#include <P89LPC922.h>
#include "d:/freebus/trunk/software/c51/89LPC922/com/fb_hal_lpc.h"
#include "d:/freebus/trunk/software/c51/89LPC922/com/fb_prot.h"
#include "d:/freebus/trunk/software/c51/89LPC922/com/fb_rs232.h"
#include "d:/freebus/trunk/software/c51/89LPC922/kombi/fb_app_th.h"




#define OWDATA P3_1

bit ow_init(void)
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

void ow_write(unsigned char owbyte)	// Byte an one-wire port senden
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


unsigned char ow_read(void)
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

int read_temp(void)
{
  unsigned char lsb,msb;
  int t,t2;
  
  ow_init();
  ow_write(0xCC);
  ow_write(0x44);
  while(ow_read()!=0xFF);
  ow_init();
  ow_write(0xCC);
  ow_write(0xBE);
  lsb=ow_read();
  msb=ow_read();
  t2=((msb&0x07)<<8)+lsb;	// Umrechnen von Basis 1/16 auf Basis 1/100
  t=t2*6;
  t2=t2>>2;
  t=t+t2;
  t=t>>3;
  t=t+((msb & 0x80)<<8);	// Vorzeichen
  t=t+(0x18 << 8);		// Exponent 3
  return (t);
}


void main(void)
{ 
  unsigned char n,rsinpos;
  bit cr_received, crlf_received;
  int temp;

  
  restart_hw();				// Hardware zurücksetzen
  restart_prot();			// Protokoll-relevante Parameter zurücksetzen
  restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
  
  rs_init();				// serielle Schnittstelle initialisieren
  rsinpos=0;
  cr_received=0;
  crlf_received=0;

  
  temp=read_temp();
  rs_send_dec(temp>>8);
  rs_send(' ');
  rs_send_dec(temp);
  
  EX1=0;
  telegramm[0]=0xBC;
  telegramm[1]=0x11;
  telegramm[2]=0x47;
  telegramm[3]=0x0D;
  telegramm[4]=0x13;
  telegramm[5]=0xE3;
  telegramm[6]=0x00;
  telegramm[7]=0x80;
  telegramm[8]=temp>>8;
  telegramm[9]=temp;
  send_telegramm();
  EX1=1;
  
  
  do  {
    TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
    if(!TASTER) {			// Taster gedrückt
      for(n=0;n<100;n++) {}
      while(!TASTER);			// warten bis Taster losgelassen
      progmode=!progmode;
    }
    TASTER=!progmode;			// LED entsprechend schalten (low=LED an)
    for(n=0;n<100;n++) {}
  } while(1);
}


