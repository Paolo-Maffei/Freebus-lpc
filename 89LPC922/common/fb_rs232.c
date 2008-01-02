  
void rs_init(void)
{  
  SCON=0x50;	//Mode 1, receive enable
  SSTAT|=0x40;	// TI wird am Ende des Stopbits gesetzt
  BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
  BRGR1=0x00;	// Baudrate = cclk/((BRGR1,BRGR0)+16)
  BRGR0=0x30;
  BRGCON|=0x01;	// Baudrate Generator starten
}

void rs_send_dec(unsigned char wert)
{
  unsigned char n;
  
  n=wert/100;
  if(n>0)
  {
    SBUF=n+48;
    while(!TI);
    TI=0;
  }
  wert=wert-(n*100);
  n=wert/10;
  if(n>0)
  {
    SBUF=n+48;
    while(!TI);
    TI=0;
  }
  wert=wert-(n*10);
  SBUF=wert+48;
  while(!TI);
  TI=0;
}

void rs_send_ok(void)
{
  SBUF='O';
  while(!TI);
  TI=0;
  SBUF='K';
  while(!TI);
  TI=0;
  SBUF=0x0D;
  while(!TI);
  TI=0;
  SBUF=0x0A;
  while(!TI);
  TI=0;
}
