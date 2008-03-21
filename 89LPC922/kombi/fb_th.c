// Versionen:	1.00	erste Version
// 				1.01	Temperaturschwellen eingebaut
//				1.02	Temperaturwert senden komplett

	

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_th.h"


long timer;
int temp,lasttemp;
bit templevel1, templevel2;		// ist 0 wenn schwelle unterschritten, 1 wenn sdchwelle überschritten




void main(void)
{ 
  unsigned char n,sequence;

  int th,eis5temp;

  templevel1=0;
  templevel2=0;
  
  restart_hw();				// Hardware zurücksetzen
  restart_prot();			// Protokoll-relevante Parameter zurücksetzen
  restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
  
  timer=0;
  sequence=1;
  
  do {
	  if (TR1==0) {
	  switch (sequence) {
	  case 1:	interrupted=0;
	  			start_tempconversion();			// Konvertierung starten
	  			if (!interrupted) sequence=2;
	  			break;
	  case 2:	if (ow_read_bit()) sequence=3;	// Konvertierung abgeschlossen
	  			break;
	  case 3:	interrupted=0;
	  	  		th=read_temp();					// Temperatur einlesen
	  			if (!interrupted) {
	  				temp=th;
	  				sequence=1;
	  			}
	  			break;
	  }
	  }
	  
	  
	  temp_schwelle(0);			// Temperaturschwelle 1 prüfen und ggf. reagieren
	  temp_schwelle(1);
	  
	  if ((eeprom[TEMPPARAM] & 0xF0) !=0) {
		  if (temp > lasttemp) {
			  if ((temp - lasttemp)>= (((eeprom[TEMPPARAM]&0xF0)>>4)*100)) {
				  eis5temp=temp>>3;					// durch 8 teilen, da später Exponent 3 dazukommt
				  //eis5temp=eis5temp+((msb & 0x8000)<<8);	// Vorzeichen
				  eis5temp=eis5temp+(0x18 << 8);			// Exponent 3       	      
				  send_eis(5,1,eis5temp);
				  lasttemp=temp;
			  }
		  }
		  else {
			  if ((lasttemp - temp)>= (((eeprom[TEMPPARAM]&0xF0)>>4)*100)) {
				  eis5temp=temp>>3;					// durch 8 teilen, da später Exponent 3 dazukommt
				  //eis5temp=eis5temp+((msb & 0x8000)<<8);	// Vorzeichen
				  eis5temp=eis5temp+(0x18 << 8);			// Exponent 3       	      
				  send_eis(5,1,eis5temp);
				  lasttemp=temp;
			  }
		  }
	  }
	  
	  if(RTCCON>=0x80) delay_timer();	// Realtime clock Überlauf
	  
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


