// Versionen:	1.00	erste Version

	

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_rs232.h"
#include "fb_app_th.h"







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
  if (temp != 0xFFFF){
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
  }
  
  
  do  {
    TASTER=1;					// Pin als Eingang schalten um Taster abzufragen
    if(!TASTER) {				// Taster wurde gedrückt
      for(n=0;n<100;n++) {}
      while(!TASTER);			// warten bis Taster losgelassen
      progmode=!progmode;
    }
    TASTER=!progmode;			// LED entsprechend schalten (low=LED an)
    for(n=0;n<100;n++) {}
  } while(1);
}


