
// Hier sind ausschliesslich die Protokoll-Handling Routinen

#include <P89LPC922.h>
#include "d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.h"
//#include <fb_app_in8.h>
#include "d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.h"




void timer1(void) interrupt 3	// Interrupt von Timer 1, 370us keine Busaktivit�t seit letztem Byte, d.h. Telegramm wurde komplett �bertragen
{
  unsigned char data_laenge,daf;

  EX1=0;					// ext. Interrupt stoppen 
  ET1=0;					// Interrupt von Timer 1 sperren
  set_timer1(4720);				// und neu starten f�r korrekte Positionierung des ACK Bytes
  
  if(cs==0xff)					// Checksum des Telegramms ist OK 
  {
    data_laenge=(telegramm[5]&0x0F);		// Telegramm-L�nge = Bit 0 bis 3 
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
            if((telegramm[6]&0x03)==0x03 && telegramm[7]==0x80)		// restart request
            {
              restart_hw();	// Hardware zur�cksetzen
              restart_prot();	// Protokoll-relevante Parameter zur�cksetzen
              restart_app();	// Anwendungsspezifische Einstellungen zur�cksetzen
            }
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
        if(data_laenge==1 && telegramm[6]==0x00)
        {
          if ((telegramm[7]&0xFE)==0x80) eis1();		// Ausg�nge schalten (EIS 1)
          if (telegramm[7]==0x00) read_value_req();		// Objektwert lesen und als read_value_res auf Bus senden
        }
      }
    }
  }
  telpos=0;  
  IE1=0;		// IRQ zur�cksetzen
  EX1=1;		// externen Interrupt 0 wieder freigeben
}





unsigned char get_ack(void)		// Byte empfangen und pr�fen ob es ein ACK war
{
  unsigned char ret;
  int n;

  n=0;
  ret=0;
  do 
  {
    if(FBINC==1) n++;
    else
    {
      if (get_byte()==0xCC && parity_ok) ret=1;
    }
  } while (n<3000);
  return(ret);
}



void send_telegramm(void)		// sendet das Telegramm, das in telegramm[] vorher abgelegt wurde und berechnet die checksum
{
  unsigned char data_laenge,l,checksum,r;

  r=0;
  do
  {
    checksum=0;
    data_laenge=telegramm[5]&0x0F;	// Telegramm-L�nge = Bit 0 bis 3

    set_timer1(18780);			// Warten bis Bus frei ist
    while(!TF1)
    {
      if(!FBINC) set_timer1(18780);
    }
    TR1=0;
  
    for(l=0;l<=data_laenge+6;l++)
    {
      sendbyte(telegramm[l]);
      checksum^=telegramm[l];
      delay(1230);			// Interbyte-Abstand
    }
    checksum=~checksum;
    sendbyte(checksum);
    if(get_ack()==1) r=3;		// wenn ACK empfangen, dann nicht nochmal senden
    r++;
    telegramm[0]&=0xDF;			// Bit 5 l�schen = Wiederholung
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
    pcount=1;			// Paketz�hler zur�cksetzen
  }
}
    

void ucd_clr(void)		// UCD Verbindungsabbau
{
  if(conh==telegramm[1] && conl==telegramm[2] && connected)	// nur abbauen, wenn verbunden und Anforderung vom Verbindungspartner, kein ACK senden
  {
    connected=0;
    pcount=1;			// Paketz�hler zur�cksetzen
  }
}


void ncd_quit(void)			// NCD Quittierung zur�ck senden. Setzt telegramm Bytes 0 bis 6 !!!
{
  telegramm[0]=0xB0;			// Control Byte			
  telegramm[3]=telegramm[1];		// Zieladresse wird Quelladresse
  telegramm[4]=telegramm[2];
  telegramm[1]=pah;			// Quelladresse ist phys. Adresse
  telegramm[2]=pal;
  telegramm[5]=0x60;			// DRL
  telegramm[6]|=0xC0;			// Bit 6 und 7 setzen (TCPI = 11 NCD Quittierung)
  telegramm[6]&=0xFE;			// Bit 0 l�schen 
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
    telegramm[6]=(pcount<<2)|0x42;	// Paketz�hler, TCPI und ersten beiden Befehlsbits
    telegramm[7]=ab|0x40;		// letzten 2 Befehlsbits
    send_telegramm();

  pcount++;				// Paketz�hler erh�hen
  pcount&=0x0F;				// max. 15
}


void write_memory(void)			// write_memory_request - empfangene Daten in Speicher schreiben
{
  unsigned char ab,n;
 
  send_ack();
  ab=telegramm[7]&0x0F;			// Anzahl Bytes
  ncd_quit();
  
  start_writecycle();
  for(n=0;n<ab;n++) 
  {
    write_byte(telegramm[8],telegramm[9]+n,telegramm[n+10]);
    if ((((telegramm[9]+n)&0x3F)==0x3F) && n!=(ab-1))		// Ende des 64-Byte Pageregisters, also zwischendurch flashen
    {
      stop_writecycle();
      start_writecycle();
    }
  }
  stop_writecycle(); 
}
  

void set_pa(void)			// neue phys. Adresse programmieren
{
  pah=telegramm[8];
  pal=telegramm[9];
  start_writecycle();
  write_byte(0x01,ADDRTAB+1,pah);		// in Flash schreiben
  write_byte(0x01,ADDRTAB+2,pal);
  stop_writecycle();
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
  
  ctp=read_byte(0x01,COMMSTABPTR);		// COMMSTAB Pointer
  addr=ctp+3+3*objno;
  flags=read_byte(0x01,addr);	// Objektflags
  return(flags);
}


int find_ga(unsigned char objno)		// Gruppenadresse �ber Assoziationstabelle finden (letzter Eintrag, falls mehrere)
{						// dient zum Senden eines Telegrammes nach einem Ereignis (Eingang, R�ckmeldeobjekt, etc.)
  unsigned char n,assno,asstab,gapos,gal,gah;
  int ga;
  
  gapos=0;
  asstab=read_byte(0x01,ASSOCTABPTR);
  assno=read_byte(0x01,asstab);
  for(n=0;n<assno;n++)
  {
    if(read_byte(0x01,asstab+2+2*n)==objno)
    {
      gapos=read_byte(0x01,asstab+1+2*n);
    }
  }
  if(gapos!=0)
  {
    gah=read_byte(0x01,ADDRTAB+1+gapos*2);
    gal=read_byte(0x01,ADDRTAB+2+gapos*2);
    ga=gal+256*gah;
  }
  else
  {
    ga=0;
  }
  return(ga);
} 


unsigned char gapos_in_gat(unsigned char gah, unsigned char gal)
{
  unsigned char ga_position,ga_count,n;
  
  ga_count=read_byte(0x01,ADDRTAB);
  ga_position=0xFF; 
  if (ga_count>0)
  {
    for (n=1;n<=ga_count;n++)
    {
      if (gah==read_byte(0x01,ADDRTAB+n*2+1) && gal==read_byte(0x01,ADDRTAB+n*2+2)) ga_position=n;
    }
  }
  return (ga_position);
}


void write_delay_record(unsigned char objno, unsigned char delay_status, long delay_target)		// Schreibt die Schalt-Verz�gerungswerte ins Flash
{
  start_writecycle();
  write_byte(0x00,objno*5,objno+delay_status);
  write_byte(0x00,1+objno*5,delay_target>>24);
  write_byte(0x00,2+objno*5,delay_target>>16);
  write_byte(0x00,3+objno*5,delay_target>>8);
  write_byte(0x00,4+objno*5,delay_target);
  stop_writecycle();
}


void restart_prot(void)		// Protokoll-relevante Parameter zur�cksetzen
{
  pah=read_byte(0x01,ADDRTAB+1);	// phys. Adresse einlesen
  pal=read_byte(0x01,ADDRTAB+2);
  
  progmode=0;			// kein Programmiermodus
  pcount=1;			// Paketz�hler initialisieren
  connected=0;			// keine Verbindung
  
  telpos=0;			// empfangene Bytes an dieser Position im Array telegramm[] ablegen
}