// Versionen:	1.00	erste Version

	

#include <P89LPC922.h>
#include "d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.h"
#include "d:/freebus/trunk/c51/89LPC922/common/fb_prot.h"
#include "d:/freebus/trunk/c51/89LPC922/common/fb_rs232.h"
#include <fb_app_rs.h>

#include "d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c"
#include "d:/freebus/trunk/c51/89LPC922/common/fb_prot.c"
#include "d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c"
#include <fb_app_rs.c>



void main(void)
{ 
  unsigned char n,rsinpos;
  unsigned char rsin[20];		// seriell empfangener string
  bit cr_received, crlf_received;
  int groupadr;
  
  restart_hw();				// Hardware zurücksetzen
  restart_prot();			// Protokoll-relevante Parameter zurücksetzen
  restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
  
  rs_init();				// serielle Schnittstelle initialisieren
  rsinpos=0;
  cr_received=0;
  crlf_received=0;
  
  
  do  {
    if (RI)
    {
      switch (SBUF)
      {
        case 0x0D:
          cr_received=1;
          break;
        case 0x0A:
          if (cr_received) crlf_received=1;
          break;
        default:
          rsin[rsinpos]=SBUF;
          rsinpos++;
          cr_received=0;
          crlf_received=0;
      }
      RI=0;
    }
    
    if (crlf_received)			// Zeile vollständig empfangen
    {
      if (rsin[0]=='f' && rsin[1]=='b')	// Magic-word 'fb' empfangen
      { 
        if(rsin[2]=='s' && rsin[3]=='0' && rsin[4]=='1' && rsin[5]=='/' && rsin[8]=='/' && rsin[10]=='/' && rsin[14]=='=' && (rsin[15]=='0' || rsin[15]=='1'))	// EIS 1 senden
        {
          groupadr=((rsin[6]-48)*10) + (rsin[7]-48);
          groupadr=groupadr*8;
          groupadr=groupadr + (rsin[9]-48);
          groupadr=groupadr*256;
          groupadr=groupadr+((rsin[11]-48)*100) + ((rsin[12]-48)*10) + (rsin[13]-48);
          telegramm[0]=0xBC;
          telegramm[1]=0x11;
          telegramm[2]=0x49;
          telegramm[3]=groupadr>>8;
          telegramm[4]=groupadr;
          telegramm[5]=0xE1;
          telegramm[6]=0x00;
          if (rsin[15]=='1') telegramm[7]=0x81;
          if (rsin[15]=='0') telegramm[7]=0x80;
          EX1=0;
          send_telegramm();
          EX1=1;
        }
      }
      for(n=0;n<20;n++) rsin[n]=0x00;
      rsinpos=0;
      cr_received=0;
      crlf_received=0;
    }
    
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


