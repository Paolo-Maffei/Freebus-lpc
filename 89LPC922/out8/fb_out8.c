/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \ 
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ / 
 *  /_/   /_/ |_/_____/_____/_____/\____//____/  
 *                                      
 *  Copyright (c) 2008 Andreas Krebs <kubi@krebsworld.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */


// Versionen:	2.00	erstes Programm in C für Hardware Ver. 2
//		2.01	Schaltverzögerung hinzugefügt
//		2.02	Restart Fehler behoben
//		2.03	Arrays korrigiert
//		2.04	Bugs in bin_out behoben		
//		3.01	auf 89LPC922 portiert und Bugs behoben		
//		3.02	Verzögerung über RTC		behobene Bugs: Verzögerung geht nach einiger Zeit sehr langsam
//		3.03	Timer 0 für PWM		
//		3.04	RX & TX Timing nochmals optimiert 	behobene Bugs: get_ack funktionierte nicht
//		3.05	Zeitschaltfunktion hinzugefügt
//		3.06	Öffner-/Schliesserbetrieb und Verhalten nach Busspannungswiederkehr hinzugefügt
//		3.07	Rückmeldeobjekte eingefügt
//		3.08	gat Array entfernt und durch gapos_in_gat funktion ersetzt
//		3.09	Sperrobjekte hinzugefügt
//		3.10	Fehler in main() behoben (kein delay!)
//		3.11	Fehler bei Zusatzfunktionstyp behoben, 
//				Fehler bei Sperrobjekten behoben,
//				Relais ziehen jetzt vollen Strom auch bei Busspannungswiederkehr


//	todo:	- Rückmeldeobjekte müssen bei Busspannungswiederkehr senden
//		- Objekt lesen muss bei allen Objekten funktionieren
//		- Prio beim Senden implementieren
//		- Zwangsstellungsobjekte implementieren

	

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/fb_app_out.h"




void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
{

  unsigned char bw,bwh,n;
  
  P0M1=0x00;				// Port 0 Modus push-pull für Ausgang
  P0M2=0xFF;

  portbuffer=userram[0x29];	// Verhalten nach Busspannungs-Wiederkehr
  bw=eeprom[0xF6];
  for(n=0;n<=3;n++)			// Ausgänge 1-4
  {
    bwh=(bw>>(2*n))&0x03; 
    if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<n));
    if(bwh==0x02)  portbuffer=portbuffer | (0x01<<n);
  }
  bw=eeprom[0xF7];
  for(n=0;n<=3;n++)			// Ausgänge 5-8
  {
    bwh=(bw>>(2*n))&0x03; 
    if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<(n+4)));
    if(bwh==0x02)  portbuffer=portbuffer | (0x01<<(n+4));
  }
  port_schalten(portbuffer);  
  
  zfstate=0x00;		// Zustand der Zusatzfunktionen 1-4
  blocked=0x00;		// Ausgänge nicht gesperrt
  timer=0;			// Timer-Variable, wird alle 135us inkrementiert
  
  logicstate=0;
  //objstate=0;
  
  start_writecycle();
  write_byte(0x01,0x03,0x00);	// Herstellercode 0x0004 = Jung
  write_byte(0x01,0x04,0x04);
  write_byte(0x01,0x05,0x20);	// Device Type (2038.10) 2060h
  write_byte(0x01,0x06,0x60);	// 	"	"	"
  write_byte(0x01,0x07,0x01);	// Versionsnummer
  write_byte(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
  write_byte(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
  write_byte(0x01,0x12,0x9A);	// COMMSTAB Pointer
  stop_writecycle();
}







void main(void)
{ 
  unsigned char n;

  restart_hw();				// Hardware zurücksetzen
  restart_prot();			// Protokoll-relevante Parameter zurücksetzen
  restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen

  
  do  {
    if(RTCCON>=0x80) delay_timer();	// Realtime clock Überlauf
    TASTER=1;						// Pin als Eingang schalten um Taster abzufragen
    if(!TASTER) {					// Taster gedrückt
      for(n=0;n<100;n++) {}
      while(!TASTER);				// warten bis Taster losgelassen
      progmode=!progmode;
    }
    TASTER=!progmode;				// LED entsprechend schalten (low=LED an)
    for(n=0;n<100;n++) {}
  
    
  } while(1);
}


