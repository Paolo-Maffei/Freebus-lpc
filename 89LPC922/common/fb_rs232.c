  
void rs_init(void)
{  
  SCON=0x50;	//Mode 1, receive enable
  SSTAT|=0x40;	// TI wird am Ende des Stopbits gesetzt
  BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
  BRGR1=0x00;	// Baudrate = cclk/((BRGR1,BRGR0)+16)
  BRGR0=0x30;
  BRGCON|=0x01;	// Baudrate Generator starten
}
