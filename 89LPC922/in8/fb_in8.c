// Versionen:	3.00	erste Version Binäreingang auf HW Basis 3

	

#include <P89LPC922.h>
#include "d:/freebus/trunk/software/c51/89LPC922/com/fb_hal_lpc.h"
#include "d:/freebus/trunk/software/c51/89LPC922/com/fb_prot.h"
#include "d:/freebus/trunk/software/c51/89LPC922/in8/fb_app_in8.h"



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


