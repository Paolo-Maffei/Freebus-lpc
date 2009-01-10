/*
 * main.c
 *
 *  Created on: 08.01.2009
 *      Author: Richard
 */
#include <P89LPC922.h>
#include "..\com\fb_rs232.h"
#include "..\dim2\fb_i2c.h"
unsigned char dimm_I2C[2];
unsigned char mk[2];
unsigned char bytenummer;
#define K1OUT P0_7
#define K2OUT P0_6
unsigned int zl_50hz=0;
unsigned int sp=0;
unsigned int m=0;
unsigned char dimmzl=0;


void i2c_int(void)interrupt 6
{
  if(I2STAT==0x60)      //Slaveadresse
    bytenummer=0;
  if(I2STAT==0x80)      //Datenbyte emfangen
    bytenummer++;
  if(I2STAT==0xA0)      //Stop emfangen
    bytenummer=0;
  if(bytenummer>1&&bytenummer<4)  //erstes byte verwerfen
    dimm_I2C[bytenummer-2]=I2DAT; //zweites und drittes byte sind K1 + K2
  SI=0;
  return;
}

void nulldurchgang(void)
        {
         dimmzl=0;
        if(dimm_I2C[0])  //dimmwert gr�sser 0 Dimmer  ein
              K1OUT=1;       //EIN
        if(dimm_I2C[1])  //dimmwert gr�sser 0 Dimmer  ein
               K2OUT=1;       //EIN
        return;
        }

void ex1_int(void) interrupt 2
{
//sp=zl_50hz;
zl_50hz=0;
//P0_1 =! P0_1;
return;
}

void tim0_int(void) interrupt 1
{
  TL0=0x95;
  TH0=255;
  if(zl_50hz<5000)
    zl_50hz++;
  if(zl_50hz==460||zl_50hz==205)
    nulldurchgang();
  if(dimmzl!=255)
    dimmzl++;
  if(dimmzl>=dimm_I2C[0])
    K1OUT=0;
  if(dimmzl>=dimm_I2C[1])
    K2OUT=0;

  //P0_1 =! P0_1;
   return;
}
void in50hz_init(void)
{
  P1M1 |= (1<<4); //Pin P1.4 input
  P1M2 &= ~(1<<4);
  EX1=1; //Externer intrrupt ein
  IT1=1; //fallende flanke
  EA=1;  //globale interruptfreigabe
  return;

}


void main(void)
{
  int i;
  rs_init();
  i2c_sla_init();
  in50hz_init();
  P1M1 |= 0x03; //rs232 open drain
  P1M2 |= 0x03; //rs232 open drain

  rs_send_s("Programmstart\n");

  P0M1 &= ~0xc0; //pin 0.6 und 0.7 Ausgang
  P0M2 |= 0xc0;
  K1OUT=0;
  K2OUT=0;

  TMOD=0x01;   // Timer 0 als reload
  TH0 = 0;
  //AUXR1&=~0x10;             // toggled whenever Timer0 overflows ausschalten
  ET0=1;                        // Interrupt f�r Timer 0 freigeben
  TR0=1;                        // Timer 0 starten
  EA=1;


  P0M1 &= ~(1<<1); // P0_1 = Ausgang zum test
  P0M2 |= (1<<1);

  while(1)
    {
      /*if(m<sp-1||m>sp+1)
        {
          rs_send_hex(sp>>8);
          rs_send_hex(sp&0xff);
          rs_send(' ');
          m=sp;
        }*/


      if(dimm_I2C[0]!=mk[0]||dimm_I2C[1]!=mk[1])
         {
          rs_send_s("D");
          rs_send_hex(dimm_I2C[0]);
          rs_send(' ');
          rs_send_hex(dimm_I2C[1]);
          rs_send_s("\n");
          mk[0]=dimm_I2C[0];
          mk[1]=dimm_I2C[1];
         }
      else
        for (i=0;i<5000;++i);

    }

}


