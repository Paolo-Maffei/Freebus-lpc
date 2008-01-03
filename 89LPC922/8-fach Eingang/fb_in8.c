// Versionen:	3.00	erste Version Binäreingang auf HW Basis 3

	

#include <P89LPC922.h>
#include "s:/elektronik/eib/c/fb_common/fb_hal_lpc.h"
#include "s:/elektronik/eib/c/fb_common/fb_prot.h"
#include <fb_app_in8.h>

#include "s:/elektronik/eib/c/fb_common/fb_hal_lpc.c"
#include "s:/elektronik/eib/c/fb_common/fb_prot.c"
#include <fb_app_in8.c>



void main(void)
{ 

  unsigned char n;

  restart_hw();				// Hardware zurücksetzen
  restart_prot();			// Protokoll-relevante Parameter zurücksetzen
  restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
  portbuffer=0xFF;
  
  do  {
  
    if(RTCCON>=0x80) delay_timer();	// Verzögerungs-Timer alle 130ms hochzählen
    
    p0h=P0;				// prüfen ob ein Eingang sich geändert hat
    if (p0h!=portbuffer) 
    {
      for(n=0;n<8;n++)					// jeden Eingangspin einzel prüfen
      {
        if (((p0h>>n)&0x01) != ((portbuffer>>n)&0x01))
        {
          pin_changed(n);				// Änderung verarbeiten
        }
      }
      portbuffer=p0h;					// neuen Portzustand in buffer speichern
    }
    
    TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
    if(!TASTER) {				// Taster gedrückt
      for(n=0;n<100;n++) {}
      while(!TASTER);
      progmode=!progmode;
    }
    TASTER=!progmode;				// LED entsprechend schalten (low=LED an)
    for(n=0;n<100;n++) {}
  } while(1);
}


