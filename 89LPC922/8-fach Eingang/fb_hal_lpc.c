

// Hier sind ausschliesslich die Hardware-spezifischen aber Applikations-unabhängigen Routinen für den 89LPC922

#include <P89LPC922.h>
#include <fb_prot.h>
#include <fb_hal_lpc.h>


unsigned char get_byte(void)
{
  bit rbit,parity,ph;			
  unsigned char n,m,fbb,fbbh;
  						
  EX1=0;				// Interrupt 1 sperren
  ET1=0;				// Interrupt von Timer 1 sperren
  TR1=0;				// Timer 1 anhalten
  
  TH1=0xFE;				// Timer 1 setzen um 1.Bit mittig zu treffen
  TL1=0x70;	//FEA0-FE40
  TF1=0;
  TR1=1;
  ph=0;					// Paritybit wird aus empfangenem Byte berechnet
  while(!TF1);				// warten auf Timer 1
  TR1=0;				
  TH1=0xFE;				// Timer 1 neu setzen für 2.Bit
  TL1=0x85;	
  TF1=0;
  TR1=1;
  rbit=FBINC;				// 1.Bit einlesen
  for(m=0;m<5;m++)
  {
    rbit&=FBINC;			// zur Steigerung der Fehlertoleranz mehrfach lesen
  }
  fbb=rbit;
  if(rbit) ph=!ph;			// Paritybit berechnen
  
  for(n=0;n<7;n++)			// 2. bis 8. Bit
  {
    
    fbb=fbb<<1;
    while(!TF1);
    TR1=0;
    TH1=0xFE;				// Timer 1 setzen für Position 2.-9.Bit
    TL1=0x8B;	//7A-9C
    TF1=0;
    TR1=1;
    rbit=FBINC;
    for(m=0;m<5;m++)
    {
      rbit&=FBINC;			// zur Steigerung der Fehlertoleranz mehrfach lesen
    }
    fbb=fbb+rbit;
    if(rbit) ph=!ph;			// Paritybit berechnen
  }  
  while(!TF1);				
  TR1=0;
  parity=FBINC;				// Paritybit lesen
  for(m=0;m<5;m++)
  {
    parity&=FBINC;
  }
  
  fbbh=(fbb&0x80)>>7;			// Byte bitweise vertauschen, da LSB zuerst übertragen wurde
  fbbh=fbbh+((fbb&0x40)>>5);
  fbbh=fbbh+((fbb&0x20)>>3);
  fbbh=fbbh+((fbb&0x10)>>1);
  fbbh=fbbh+((fbb&0x08)<<1);
  fbbh=fbbh+((fbb&0x04)<<3);
  fbbh=fbbh+((fbb&0x02)<<5);
  fbbh=fbbh+((fbb&0x01)<<7);
      
  if(parity==ph) return fbbh;
  else return 0xFF;
}




void ext_int0(void) interrupt 2		// Byte vom Bus empfangen, wird durch negative Flanke am INT1 Eingang getriggert
					// liest ein Byte und prüft das parity-bit
					// wenn OK wird das Byte in das array telegramm an die Position telpos abgelegt
{					// anschließend wird der time-out Zähler gestartet, wenn während 370us nichts empfangen wird
  bit rbit,parity,ph;			// dann ist das Telegramm komplett übertragen worden
  unsigned char n,m,fbb,fbbh;
  						
  EX1=0;				// Interrupt 0 sperren
  ET1=0;				// Interrupt von Timer 1 sperren
  TR1=0;				// Timer 1 anhalten
  
  TH1=0xFE;				// Timer 1 setzen um 1.Bit mittig zu treffen
  TL1=0x70;	//FEA0-FE40
  TF1=0;
  TR1=1;
  ph=0;					// Paritybit wird aus empfangenem Byte berechnet
  while(!TF1);				// warten auf Timer 1
  TR1=0;				
  TH1=0xFE;				// Timer 1 neu setzen für 2.Bit
  TL1=0x85;	
  TF1=0;
  TR1=1;
  rbit=FBINC;				// 1.Bit einlesen
  for(m=0;m<5;m++)
  {
    rbit&=FBINC;				// zur Steigerung der Fehlertoleranz mehrfach lesen
  }
  fbb=rbit;
  if(rbit) ph=!ph;			// Paritybit berechnen
  
  for(n=0;n<7;n++)			// 2. bis 8. Bit
  {
    
    fbb=fbb<<1;
    while(!TF1);
    TR1=0;
    TH1=0xFE;				// Timer 1 setzen für Position 2.-9.Bit
    TL1=0x8B;	//7A-9C
    TF1=0;
    TR1=1;
    rbit=FBINC;
    for(m=0;m<5;m++)
    {
      rbit&=FBINC;			// zur Steigerung der Fehlertoleranz mehrfach lesen
    }
    fbb=fbb+rbit;
    if(rbit) ph=!ph;			// Paritybit berechnen
  }  
  while(!TF1);				
  TR1=0;
  parity=FBINC;				// Paritybit lesen
  for(m=0;m<5;m++)
  {
    parity&=FBINC;
  }
  
  fbbh=(fbb&0x80)>>7;			// Byte bitweise vertauschen, da LSB zuerst übertragen wurde
  fbbh=fbbh+((fbb&0x40)>>5);
  fbbh=fbbh+((fbb&0x20)>>3);
  fbbh=fbbh+((fbb&0x10)>>1);
  fbbh=fbbh+((fbb&0x08)<<1);
  fbbh=fbbh+((fbb&0x04)<<3);
  fbbh=fbbh+((fbb&0x02)<<5);
  fbbh=fbbh+((fbb&0x01)<<7);
      
  if(parity==ph)			// wenn Parity OK
  {
    telegramm[telpos]=fbbh; 
    if(telpos==0) cs=0;
    cs^=fbb;				// Checksum durch EXOR der einzelnen Telegramm-Bytes bilden
    telpos++;
  }
  TH1=0xFA;				// Timer 1 starten für Timeout 370us -> signalisiert Telegrammende FA37
  TL1=0x37;
  TF1=0;
  TR1=1;
  ET1=1;				// Interrupt für Timer 1 freigeben
  IE1=0;				// Interrupt 0 request zurücksetzen
  EX1=1;				// Interrupt 0 wieder freigeben
} 


bit sendbyte(unsigned char fbsb)
{
  unsigned char n,m;
  bit sendbit,parity,error;
  
  
  TR1=0;
  TH1=0xFF;	//35us für Startbit (ff86)
  TL1=0x80;
  TF1=0;
  
  FBOUTC=1;	// Startbit senden
  TR1=1;
  parity=1;
  error=0;
  while(!TF1);
  FBOUTC=0;
  
  for(n=0;n<8;n++)		// 8 Datenbits senden
  {
    TR1=0;
    TH1=0xFF;			//69us Pause (ff16)
    TL1=0x12;
    TF1=0;
    TR1=1;
    if(((fbsb>>n)&0x01)==1) sendbit=0;
    else sendbit=1;
    while(!TF1);		// Warten bis 69us Pause fretig ist
    
    FBOUTC=sendbit;		// Bit senden
    
    TR1=0;			
    TH1=0xFF;			//35us Haltezeit für Bit (ff8A)
    TL1=0x8A;
    TF1=0;
    TR1=1;
    if(!sendbit) parity=!parity;
    
    if(!sendbit)		// wenn logische 1 gesendet wird, auf Kollision prüfen
    {
      for(m=0;m<5;m++)
      {
        if(!FBINC) error=1;
      }
    }
    if(error) break;  
    
    
    while(!TF1);		// Warten bis 35us abgelaufen
    FBOUTC=0;
  }
  if(!error)
  {
  TR1=0;
  TH1=0xFF;	//69us Pause (ff19)
  TL1=0x0F;
  TF1=0;
  TR1=1;
  while(!TF1);
  FBOUTC=parity;
  TR1=0;
  TH1=0xFF;	//35us für Bit (ff8A)
  TL1=0x8A;
  TF1=0;
  TR1=1;
  while(!TF1);
  FBOUTC=0;
  }
  TR1=0;
  
  return error;
}


void start_writecycle(void)
{
  FMCON=0x00;			// load command, leert das pageregister
}


void stop_writecycle(void)
{
  FMCON=0x68;			// write command, schreibt pageregister ins flash und versetzt CPU in idle für 4ms
}


void write_byte(unsigned char addrh, unsigned char addrl, unsigned char zdata)	// schreibt byte ins pageregister zum flashen
{
 
  if (addrh<=0x01)		// sicherstellen, dass nicht versehentlich bootloader überschrieben wird
  {	
    FMADRH=addrh+0x1C;
    FMADRL=addrl;
    FMDATA=zdata;
  }
}


void delay(int deltime)			// Warten, deltime = Anzahl µs
{
  TR1=0;				// Timer 1 anhalten
  deltime=0xFFFF-deltime;
  TH1=deltime>>8;			// Timer 1 setzen 
  TL1=deltime;	
  TF1=0;
  TR1=1;
  while(!TF1);				// warten auf Timer 1
  TR1=0;		
}


unsigned char read_byte(unsigned char addrh, unsigned char addrl)		// liest byte aus flash
{
  unsigned char zdata;
  
  
  zdata=dataflash[(addrh<<8)+addrl];
  return (zdata);
}


void restart_hw(void)	// Alle Hardware Einstellungen zurücksetzen

{

  DIVM=0;		// Taktferquenz nicht teilen -> volles Tempo
  
  P1M1=0x14;		// Port 1 auf quasi-bidirektional, außer P1.2(T0)=open-drain, P1.4(INT1)=Input only
  P1M2=0x04;
   
  FBOUTC=0;		// Bus-Ausgang auf low

  TMOD=0x12;		// Timer 0 als PWM, Timer 1 als 16-Bit Timer
  TAMOD=0x01;
  TH0=DUTY;		// Pulsverhältnis PWM
  AUXR1|=0x10;		// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
  
  ET0=0;		// Interrupt für Timer 0 sperren 
  TR0=1;		// Timer 0 starten (PWM)
  TR1=0;		// Timer 1 (Empfangs-Timeout) zunächst stoppen
 
  RTCH=0x1D;		// Real Time Clock
  RTCL=0x40;
  RTCCON=0x61;

  IEN0=0x00;
  IEN1=0x00;
  EA=1;			// Interrupts prinzipiell freigeben
  EX0=0;		// Externen Interrupt 0 sperren
  EX1=1;		// Externen Interrupt 1 freigeben	

  IP0=0x0C;		// höchste Priorität für ext. Int. 1 und Timer 1 (Bit 0 und 3)
  IP0H=0x0C;
  IP1=0x00;
  IP1H=0x00;
  IT1=1;		// Int1 flankengetriggert=1 pegelgetriggert=0
  
}
