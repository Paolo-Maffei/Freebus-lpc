
#include <P89LPC922.h>
#include "d:/freebus/trunk/software/c51/89LPC922/com/fb_hal_lpc.h"
#include "d:/freebus/trunk/software/c51/89LPC922/com/fb_prot.h"
#include "d:/freebus/trunk/software/c51/89LPC922/com/fb_rs232.h"
#include "d:/freebus/trunk/software/c51/89LPC922/kombi/fb_app_th.h"

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
