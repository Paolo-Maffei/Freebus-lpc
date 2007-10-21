/* $ID$ */

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


	

#include <P89LPC922.h>	

#define FBOUTC	P1_6
#define TASTER	P1_7
#define FBINC	P1_4

#define DUTY	0xC0			// war C0  0xFF=immer low 0x00=immer high


unsigned char fbb;			// globale Variablen für Empfangsroutine
unsigned char telegramm[23];
unsigned char telpos;

volatile bit eibcol,parity;		// globale Variablen für Senderoutine

long timer;				// Timer für Schaltverzögerungen, wird alle 65us hochgezählt
unsigned char pal, pah;			// phys. Adresse
unsigned char pcount, gacount;		// Paketzähler, Gruppenadresszähler
unsigned char conh, conl;		// bei bestehender Verbindung phys. Adresse des Kommunikationspartners
unsigned char portbuffer;		// Zwischenspeicherung der Portzustände
unsigned char pdir;			// Port-Richtung, wenn Bit gesetzt dann ist der entsprechende Pin ein Ausgang (für kombinierte Ein-/Ausgänge)
unsigned char cs;			// checksum
bit progmode, connected;		// Programmiermodus, Verbindung steht
int gat[20];				// group address table

unsigned char n;
__code unsigned char __at 0x1A00 dataflash[512]=0x00;


#include <flash.h>
#include <fbprot.h>




void restart(void)

{
  DIVM=0;		// Taktferquenz nicht teilen -> volles Tempo
  //WDCON=0x01;		// Watchdog aus
  
  P0M1=0x00;		// Port 0 Modus push-pull
  P0M2=0xFF;
  P1M1=0x14;		// P1 auf quasi-bidirektional, außer P1.2(T0)=open-drain, P1.4(INT1)=Input only, P1.6 qb
  P1M2=0x04;
  
  P0=0x00;		
  portbuffer=0x00;
  
  FBOUTC=0;		// Ausgang auf low, damit der 68R nicht verglüht...	
			
  progmode=0;		// kein Programmiermodus
  pcount=1;		// Paketzähler initialisieren
  connected=0;		// keine Verbindung
  pdir=0xFF;		// Port-Direction - wenn Bit=1 darf entsprechender Portpin beschrieben werden (Ausgang), sonst nicht (Eingang)
  telpos=0;		// empfangene Bytes an dieser Position im Array telegramm[] ablege
  
  TMOD=0x12;		// Timer 0 als PWM, Timer 1 als 16-Bit Timer
  TAMOD=0x01;
  TH0=DUTY;		// Pulsverhältnis PWM
  AUXR1|=0x10;		// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
  ET0=0;		// Interrupt für Timer 0 sperren 
  TR0=1;		// Timer 0 starten
  TR1=0;		// Timer 1 (Empfangs-Timeout) zunächst stoppen

  
  RTCH=0x1D;		// Real Time Clock
  RTCL=0x40;
  RTCCON=0x61;
  timer=0;		// Timer-Variable, wird alle 135us inkrementiert
  
//lcd_init();
 
  get_gat();		// Gruppenadressen-Tabelle einlesen
 
  pah=read_byte(0x01,0x17);	// phys. Adresse einlesen
  pal=read_byte(0x01,0x18);
  		
//lcd_hex(pah);
//lcd_hex(pal);

  write_byte(0x01,0x04,0x04);	// Herstellercode 0x04 = Jung
  write_byte(0x01,0x05,0x20);	// Geräte Typ (2038.10) 2060h
  write_byte(0x01,0x06,0x60);  // 	"	"	"
  write_byte(0x01,0x07,0x01);	// Versionsnummer
  write_byte(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
  write_byte(0x01,0x12,0x9A);	// COMMSTAB Pointer
  
  IEN0=0x00;
  IEN1=0x00;
  EA=1;					// Interrupts prinzipiell freigeben
  EX0=0;				// Externen Interrupt 0 sperren
  EX1=1;				// Externen Interrupt 1 freigeben	

  IP0=0x0C;				// höchste Priorität für ext. Int. 1 und Timer 1 (Bit 0 und 3)
  IP0H=0x0C;
  IP1=0x00;
  IP1H=0x00;
  IT1=1;				// Int1 flankengetriggert=1 pegelgetriggert=0
  
}





void bin_out(void)				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
{
  unsigned char objno,port_pattern,objflags,gapos,atp,assno,delay_base,n,delay_onoff,delay_status,gaposh,delay_zeit;
  long delay_target;
  int ga;
 
    gaposh=0;
    ga=telegramm[3];
    ga=ga<<8;
    ga=ga+telegramm[4];
    gapos=0xFF;
    
    
    for(n=0;n<gacount;n++)			// Schleife über alle Gruppenadressen in der group-address-table (Wichtig! denn 2 Ausgänge könnten die selbe Gruppenadresse haben.)
    {
      if(gat[n]==ga) gapos=n+1;
    }
    if (gapos!=0xFF)	
    {
      send_ack();
      atp=read_byte(0x01,0x11);			// Association Table Pointer
      assno=read_byte(0x01,atp);		// Erster Eintrag = Anzahl Einträge
 
      for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
      {
        gaposh=read_byte(0x01,atp+1+(n*2));
        if(gapos==gaposh)					// Wenn Positionsnummer übereinstimmt
        {
          objno=read_byte(0x01,atp+2+(n*2));			// Objektnummer
          objflags=read_objflags(objno);			// Objekt Flags lesen
          if((objflags&0x04)==0x04)				// Kommunikation zulässig (Bit 2 = communication enable) 
          {
            port_pattern=0x01<<objno;
            if((port_pattern&pdir)==port_pattern)		// Portpin darf beschrieben werden
            {
              if((objflags&0x10)==0x10)				// Schreiben zulässig (Bit 4 = write enable)
              {
                delay_base=read_byte(0x01,(((objno+1)>>1)+0xF9));   
                if((objno&0x01)==0x01) delay_base&=0x0F;
                else delay_base=(delay_base&0xF0)>>4;
                delay_target=0;
                delay_onoff=0;
                delay_status=0;
                delay_zeit=read_byte(0x01,0xEA);
                delay_zeit=((delay_zeit>>objno)&0x01);
                
                switch (telegramm[7])
                {
                  case 0x80:					// Ausschalten
                    delay_onoff=read_byte(0x01,(objno+0xE2));
                    if(delay_onoff==0x00 || delay_zeit==0x01)
                    { 

                      portbuffer=portbuffer&~port_pattern;		// sofort
                    }
                    else
                    {
                      delay_status=0x80;				// verzögert
                    }
                    break;
                  case 0x81:					// Einschalten
                    delay_onoff=read_byte(0x01,(objno+0xDA));
                    if(delay_onoff==0x00)
                    {
                      if(delay_zeit==0x01) 			// Zeitschaltfunktion 
                      {
                        delay_status=0x80;
                        delay_onoff=read_byte(0x01,(objno+0xE2));
                      }
                      portbuffer=portbuffer|port_pattern;		// sofort
                    }
                    else
                    {
                      delay_status=0x90;				// verzögert

                    }
                    break;
                }
                if(delay_status!=0)								// wenn Verzögerung, dann timer-Wert schreiben
                {  
                  //delay_target=(delay_onoff<<delay_base)+timer;				
                  delay_target=delay_onoff;
                  delay_target=delay_target<<delay_base;
                  delay_target+=timer;
                  
                  write_byte(0x00,objno*5,objno+delay_status);
                  write_byte(0x00,1+objno*5,delay_target>>24);
                  write_byte(0x00,2+objno*5,delay_target>>16);
                  write_byte(0x00,3+objno*5,delay_target>>8);
                  write_byte(0x00,4+objno*5,delay_target);
                } //ansonsten mit else hier sofort schalten
                //else
                //{
                TH0=0;					// Port-Ausgabe
      		P1_2=1;
      		P0=portbuffer;								
      		TR1=0;					
      		TF1=0;
      		TH1=0xA0;				// Relais zunächst mit vollem Strom einschalten...
      		TL1=0x00;				
      		TR1=1;
      		while (!TF1);
      		TR1=0;
      		TH0=DUTY;				// ...danach mit PWM halten (min5% von I nominal)     
                //}
              }
            }
            if(telegramm[7]==0x00 && (objflags&0x08)==0x08)	// Wert lesen, nur wenn read enable gesetzt (Bit3)
            {
              telegramm[0]=0xBC;
              telegramm[1]=pah;			// Source Adresse
              telegramm[2]=pal;
              telegramm[5]=0xE1;		// DRL
              telegramm[6]=0x00;
              if((port_pattern&portbuffer)>0) telegramm[7]=0x41;	// An
              else telegramm[7]=0x40;					// Aus
              send_telegramm();
            }
          }
        }
      }
      
    }
}
    


void timer1(void) interrupt 3	// Interrupt von Timer 1, 370us keine Busaktivität seit letztem Byte, d.h. Telegramm wurde komplett übertragen
{
  unsigned char data_laenge,daf;

  EX1=0;					// ext. Interrupt stoppen 
  ET1=0;					// Interrupt von Timer 1 sperren
  TR1=0;					// Timer 1 anhalten
  TF1=0;
  TH1=0xED;					// und neu starten für korrekte Positionierung des ACK Bytes
  TL1=0x80;				
  TR1=1;

  if(cs==0xff)					// Checksum des Telegramms ist OK 
  {
    data_laenge=(telegramm[5]&0x0F);		// Telegramm-Länge = Bit 0 bis 3 
    daf=(telegramm[5]&0x80);			// Destination Adress Flag = Bit 7, 0=phys. Adr., 1=Gruppenadr.

    if(telegramm[3]==0 && telegramm[4]==0)		// Broadcast, wenn Zieladresse = 0
    {
      if(progmode)
      {
        if(data_laenge==3 && telegramm[6]==0x00 && telegramm[7]==0xC0) set_pa();	// set_pa_req
        if(telegramm[6]==0x01 && telegramm[7]==0x00) read_pa();				// read_pa_req
      }
    }
    else
    {
      if(daf==0x00)					// Unicast, wenn Zieladresse physikalische Adresse ist
      {
        if(telegramm[3]==pah && telegramm[4]==pal)	// nur wenn es die eigene phys. Adr. ist
        {
          if((telegramm[6]&0xC3)==0x42 && (telegramm[7]&0xC0)==0x80) write_memory();	// write_memory_request beantworten
          if(data_laenge==0)
          {    
            if((telegramm[6]&0xC0)==0xC0) send_ack();				// auf NCD_Quittierung mit ACK antworten
            if(telegramm[6]==0x80) ucd_opr();					// UCD Verbindungsaufbau
            if(telegramm[6]==0x81) ucd_clr();					// UCD Verbindungsabbau
          }
          if(data_laenge==1)
          {
            if((telegramm[6]&0x03)==0x03 && telegramm[7]==0x80) restart();	// restart request
            if(telegramm[6]==0x43 && telegramm[7]==0x00) read_masq();		// Maskenversion angefordert
          }
          if(data_laenge==3)
          {
            if((telegramm[6]&0xC3)==0x42 && (telegramm[7]&0xC0)==0x00) read_memory();	// read_memory_request beantworten
          }
          
        }
      }
      else						// Multicast, wenn Zieladresse Gruppenadresse ist
      {
        if(data_laenge==1 && telegramm[6]==0x00 && ((telegramm[7]&0xFE)==0x80 || telegramm[7]==0x00)) bin_out();	// Ausgänge schalten (EIS 1) oder lesen
      }
    }
  }
  telpos=0;  
  IE1=0;		// IRQ zurücksetzen
  EX1=1;		// externen Interrupt 0 wieder freigeben
}




void delay_timer(void)	// zählt alle 130ms die Variable Timer hoch und prüft Queue
{
  unsigned char n,b,port_pattern,delay_zeit,delay_onoff,delay_base;
  long delval,delay_target;
  
  RTCCON=0x60;		// RTC anhalten und Flag löschen
  RTCH=0x1D;		// Real Time Clock
  RTCL=0x40;

  timer++;
  for(n=0;n<=7;n++)
  {
    b=read_byte(0x00,n*5);
    if(b!=0x00)							// 0x00 = queue Eintrag ist leer
    {   
      delval=read_byte(0x00,n*5+1);
      delval=(delval<<8)+read_byte(0x00,n*5+2);
      delval=(delval<<8)+read_byte(0x00,n*5+3);
      delval=(delval<<8)+read_byte(0x00,n*5+4);
      if(delval==timer)
      {       
        port_pattern=0x01<<((b&0x0F));
        if((b&0xF0)==0x90)
        {				
          portbuffer=portbuffer|port_pattern;		// Einschalten
          write_byte(0x00,n*5,0x00);
          delay_zeit=read_byte(0x01,0xEA);
          delay_zeit=((delay_zeit>>n)&0x01);
          if(delay_zeit==0x01)
          {
            delay_base=read_byte(0x01,(((n+1)>>1)+0xF9));   
            if((n&0x01)==0x01) delay_base&=0x0F;
            else delay_base=(delay_base&0xF0)>>4;
            delay_onoff=read_byte(0x01,(n+0xE2));
            if (delay_onoff!=0x00 && delay_zeit!=0x00)
            {
              delay_target=delay_onoff;
              delay_target=delay_target<<delay_base;
              delay_target+=timer;     
              write_byte(0x00,n*5,n+0x80);
              write_byte(0x00,1+n*5,delay_target>>24);
              write_byte(0x00,2+n*5,delay_target>>16);
              write_byte(0x00,3+n*5,delay_target>>8);
              write_byte(0x00,4+n*5,delay_target);
            }
          }
        }
        else
        {			
          portbuffer=portbuffer&~port_pattern;		// Ausschalten
          write_byte(0x00,n*5,0x00);
        }
        TH0=0;					// Port-Ausgabe
        P1_2=1;
      	P0=portbuffer;								
      	TR1=0;					
      	TF1=0;
      	TH1=0xA0;				// Relais zunächst mit vollem Strom einschalten...
      	TL1=0x00;				
      	TR1=1;
      	while (!TF1);
      	TR1=0;
      	TH0=DUTY;				// ...danach mit PWM halten (min5% von I nominal)    
      	

      }
    }   
  }
  RTCCON=0x61;		// RTC starten
}






void main(void)
{ 
  restart();
  
  do  {
    if(RTCCON>=0x80) delay_timer();
    TASTER=1;			// Pin als Eingang schalten um Taster abzufragen
    if(!TASTER) {		// Taster gedrückt
      for(n=0;n<100;n++) {}
      while(!TASTER);
      progmode=!progmode;
    }
    TASTER=!progmode;		// LED entsprechend schalten (low=LED an)
    for(n=0;n<100;n++) {}
  } while(1);
}


