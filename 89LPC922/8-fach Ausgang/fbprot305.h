unsigned char get_byte(void)
{
bit rbit,parity,ph;			// dann ist das Telegramm komplett übertragen worden
  unsigned char m,fbbh;
  						
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
      
  if(parity==ph) return fbbh;
  else return 0xFF;
}




void ext_int0(void) interrupt 2		// Byte vom Bus empfangen, wird durch negative Flanke am INT1 Eingang getriggert
					// liest ein Byte und prüft das parity-bit
					// wenn OK wird das Byte in das array telegramm an die Position telpos abgelegt
{					// anschließend wird der time-out Zähler gestartet, wenn während 370us nichts empfangen wird
  bit rbit,parity,ph;			// dann ist das Telegramm komplett übertragen worden
  unsigned char m,fbbh;
  						
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
  



bit get_ack(void)		// wartet bis Byte empfangen wurde und prüft ob es ein ACK war  <- suboptimal, besser mit timeout !!!
{
  do {} while(FBINC);
  //get_byte();
  if (get_byte()==0xCC) return(1);
  else return(0);
}



void send_telegramm(void)		// sendet das Telegramm, das in telegramm[] vorher abgelegt wurde und berechnet die checksum
{

  unsigned char data_laenge,l,checksum,r;

  
  r=0;
  do
  {
  eibcol=0;
  checksum=0;
  data_laenge=telegramm[5]&0x0F;	// Telegramm-Länge = Bit 0 bis 3

  TR1=0;
  TH1=0xB6;
  TL1=0x8F;
  TF1=0;
  TR1=1;
  while(!TF1)
  {
    if(!FBINC)
    {
      TR1=0;
      TH1=0xB0;
      TL1=0x4F;
      TF1=0;
      TR1=1;
    }
  }
  TR1=0;
  
  for(l=0;l<=data_laenge+6;l++)
  {
    sendbyte(telegramm[l]);
    checksum^=telegramm[l];

    TR1=0;
    TH1=0xFB;
    TL1=0x1F;
    TF1=0;
    TR1=1;
    while(!TF1);
    TR1=0;
  }
  checksum=~checksum;
  sendbyte(checksum);
  if(get_ack()) r=3;
  r++;
  telegramm[0]&=0xDF;			// Bit 5 löschen = Wiederholung
  }
  while(r<=3); 				// falls kein ACK max. 3 Mal wiederholen
}


void send_ack(void)			// wartet auf Timer 1 wegen korrekter Positionierung und sendet ACK (0xCC)
{
  while(!TF1) {}
  sendbyte(0xCC);
}



  

void ucd_opr(void)		// UCD Verbindungsaufbau
{
  if(!connected)		// wenn bereits verbunden: ignorieren
  {
    connected=1;
    conh=telegramm[1];		// phys. Adresse des Verbindungspartners
    conl=telegramm[2];
    send_ack();			// quittieren
    pcount=1;			// Paketzähler zurücksetzen
  }
}
    

void ucd_clr(void)		// UCD Verbindungsabbau
{
  if(conh==telegramm[1] && conl==telegramm[2] && connected)	// nur abbauen, wenn verbunden und Anforderung vom Verbindungspartner, kein ACK senden
  {
    connected=0;
    pcount=1;			// Paketzähler zurücksetzen
  }
}


void get_gat(void)					// group address table aus EEPROM lesen und in array gat[] schreiben
{
  unsigned char n,x;
  
  gacount=read_byte(0x01,0x16);		// Anzahl Einträge in der group address table
  gacount--;						// erster Eintrag ist phys. Adresse
  if(gacount>0)
  {
    if(gacount>8) gacount=8;				// Maximal 19 Einträge erlaubt
    for(n=0;n<gacount;n++)
    {
      x=read_byte(0x01,2*n+0x19);	// MSB
      gat[n]=x; // *256
      x=read_byte(0x01,2*n+0x1A);	// LSB
      gat[n]=(gat[n]<<8)+x;
    }
  }
}
    





void ncd_quit(void)			// NCD Quittierung zurück senden. Setzt telegramm Bytes 0 bis 6 !!!
{

  

  telegramm[0]=0xB0;			// Control Byte
			
    telegramm[3]=telegramm[1];		// Zieladresse wird Quelladresse
    telegramm[4]=telegramm[2];
    telegramm[1]=pah;			// Quelladresse ist phys. Adresse
    telegramm[2]=pal;
    telegramm[5]=0x60;			// DRL
    telegramm[6]|=0xC0;			// Bit 6 und 7 setzen (TCPI = 11 NCD Quittierung)
    telegramm[6]&=0xFE;			// Bit 0 löschen 
    send_telegramm();
}




void read_masq(void)			// Maskenversion senden
{

  
  send_ack();
  ncd_quit();				// NCD Quittierung senden

  telegramm[0]=0xB0;			// Control Byte
		
    telegramm[5]=0x63;			// DRL
    telegramm[6]=0x43;
    telegramm[7]=0x40;
    telegramm[8]=0x00;
    telegramm[9]=0x12;			// Maskenversion 1 = BCU1
    send_telegramm();

}  
    

void read_memory(void)			// read_memory_request - Speicher auslesen und senden
{
  unsigned char ab,n;

  send_ack();				// erstmal quittieren
  ab=telegramm[7];			// Anzahl Bytes
  ncd_quit();
  
  for(n=0;n<ab;n++)
  {
    telegramm[n+10]=read_byte(telegramm[8],(telegramm[9]+n));    
  }

  telegramm[0]=0xB0;			// read_memory_res senden
			
    telegramm[5]=ab+0x63;		// DRL (Anzahl Bytes + 3)
    telegramm[6]=(pcount<<2)|0x42;	// Paketzähler, TCPI und ersten beiden Befehlsbits
    telegramm[7]=ab|0x40;		// letzten 2 Befehlsbits
    send_telegramm();

  pcount++;				// Paketzähler erhöhen
  pcount&=0x0F;				// max. 15
}


void write_memory(void)			// write_memory_request - empfangene Daten in Speicher schreiben
{
  unsigned char ab,n;
 
  send_ack();
  ab=telegramm[7]&0x0F;			// Anzahl Bytes
  ncd_quit();
  

  
  for(n=0;n<ab;n++)
  {
    write_byte(telegramm[8],telegramm[9]+n,telegramm[n+10]);
    
  }
}
  

void set_pa(void)			// neue phys. Adresse programmieren
{
  pah=telegramm[8];
  pal=telegramm[9];
  write_byte(0x01,0x17,pah);		// in Flash schreiben
  write_byte(0x01,0x18,pal);
}


void read_pa(void)			// phys. Adresse senden
{

  
  send_ack();

  telegramm[0]=0xB0;			// read_memory_res senden

    telegramm[1]=pah;
    telegramm[2]=pal;
    telegramm[3]=0x00;
    telegramm[4]=0x00;			
    telegramm[5]=0xE1;			// DRL
    telegramm[6]=0x01;		
    telegramm[7]=0x40;
    send_telegramm();

}


unsigned char read_objflags(unsigned char objno)	// Objektflags lesen
{
  unsigned char ctp,addr,flags;
  
  ctp=read_byte(0x01,0x12);		// COMMSTAB Pointer
  addr=ctp+3+3*objno;
  flags=read_byte(0x01,addr);	// Objektflags
  return(flags);
}
