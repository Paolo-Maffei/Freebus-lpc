
#include <P89LPC922.h>
#include "d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.h"
#include "d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.h"
#include <fb_app_rs.h>

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


  
  P0M1=0x00;				// Port 0 Modus push-pull für Ausgang
  P0M2=0xFF;
  P0=0;

}
