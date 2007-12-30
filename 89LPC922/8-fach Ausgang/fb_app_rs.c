
#include <P89LPC922.h>
#include "s:/elektronik/eib/c/fb_common/fb_hal_lpc.h"
#include "s:/elektronik/eib/c/fb_common/fb_prot.h"
#include <fb_app_rs.h>

void eis1(void)
{
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
