/*
 * fb_i2c.c
 *
 *  Created on: 02.01.2009
 *      Author: Richard
 */
#include <P89LPC922.h>
#include "fb_i2c.h"
#include "fb_app_ls.h"
//#include "fb_rs232.h"
#define I2CSPEEDH 25    //min 40bei 5v
#define I2CSPEEDL 25    //min 20


void delay(unsigned int e)
        {
        unsigned int   i;
        for(i=0;i<e;++i)i=i;
        return;
        }


void starti2c(void)
        {
        SDA=1;
        delay(15);
        SCL=1;
        //while(SCL==0);
        delay(30);
        SDA=0;
        delay(50);
        //SCL=0;
        return;
        }

void stopi2c(void)
        {
        SCL=0;
        delay(10);
        SDA=0;
        delay(20);
        SCL=1;
        //while(SCL==0);
        delay(20);
        SDA=1;
        delay(100);

        return;
        }



/*uebergabe wert oder adresse zum verschicken*/
/*rueckgabe 1= ACK       empfangen*/
/*rueckgabe 0= ACK nicht empfangen*/
bit sendi2c(unsigned char a)
        {
        unsigned char   i=8;
        for(;i>0;i--)
                {
                SCL=0;
                delay(40);
                SDA=((a>>(i-1))&1);
                delay(20);
                SCL=1;
                //while(SCL==0);
                delay(20);
                }
        SCL=0;
        delay(50);
        SDA=1;
        delay(20);
        SCL=1;//für ack rückmeldung
        //while(SCL==0);
        if(SDA==0)  /*ACK*/
                {
                i=1;
                }
        else
                i=0;
        delay(40);
        SCL=0;
        delay(10);
        return(i);
        }



void i2c_sla_init(void)
{
  P1M1 |= 0x0c;//(1<<2)+(1<<3);
  P1M2 &= ~0x0c;
  I2ADR = 0xa0; // default slave address
  I2CON = 0x44;
  I2SCLH=I2CSPEEDH; //I2C takt
  I2SCLL=I2CSPEEDL; //I2C takt
  SDA=1;
  SCL=1;
  EI2C=1;
  EA=1;
  return;
}

void i2c_ma_init(void)
{
  P1M1 |= 0x0c;//(1<<2)+(1<<3);
  P1M2 |= 0x0c;//((1<<2)+(1<<3));
  /*I2ADR = 0xa0; // default slave address
  I2CON = 0x44;
  I2SCLH=I2CSPEEDH; //I2C takt
  I2SCLL=I2CSPEEDL; //I2C takt
  */SDA=1;
  SCL=1;
  return;
}
/*
unsigned char i2c_wait(void)
        {
        unsigned int timeueberlauf=0;

        while (SI==0)
                {
                //rs_send_s("I2C warten auf Gesendet\n");
                timeueberlauf++;
                if(timeueberlauf>MAX_I2C_ZEIT)
                  {
                    //rs_send_s("TimeOutI2C\n");
                    SI=0;
                    return 0xFF;

                  }
                }
        //rs_send_s("I2C Send OK\n");
        SI=0;
        return 0;
        }

unsigned char send_lautstaerke(unsigned char kanal)
{
  CRSEL=0;        //CRSEL=0
  I2SCLH=I2CSPEEDH;
  I2SCLL=I2CSPEEDL;
  I2CON=0;
  I2EN=1;         //Master Transmit mode

  STA=1;           //send Start MASTER
    if(i2c_wait()!=0)
           return 0xff;
   STA=0;
   I2DAT = 0x82+0;//a0= adresse i2c eeprom 0=schreiben SLA_W;       //Adresse senden MASTER
   if(i2c_wait()!=0)
           return 0xff;
   I2DAT = 0x00;       //00                    //Daten Senden MASTER
   if(i2c_wait()!=0)
           return 0xff;
   I2DAT = (kanal)+0xc0;                             //Daten Senden MASTER
   if(i2c_wait()!=0)
           return 0xff;

   STA=1;           //send Start MASTER
   if(i2c_wait()!=0)
           return 0xff;
   STA=0;
   I2DAT = 0x82+0;//a0= adresse i2c eeprom 0=schreiben SLA_W;       //Adresse senden MASTER
   if(i2c_wait()!=0)
           return 0xff;
   I2DAT = 0x01;                           //Daten Senden MASTER
   if(i2c_wait()!=0)
           return 0xff;
   I2DAT = (kanal)+0xc0;
   //I2DAT = (K2/4)+0xc0;                             //Daten Senden MASTER
   if(i2c_wait()!=0)
           return 0xff;
    STO=1;            //send Stop MASTER
    if(i2c_wait()!=0)
            return 0xff;
    return 0;
}
*/


unsigned char send_lautstaerke(unsigned char kanal)
{
  starti2c();
  sendi2c(0x82);
  sendi2c(0x0);
  sendi2c(kanal+0xc0);
  starti2c();
  sendi2c(0x82);
  sendi2c(0x01);
  sendi2c(kanal+0xc0);
  stopi2c();
  return 0;
}
unsigned char i2c_send_daten(unsigned char K1,unsigned char K2)
{
  P0_2=1;
  send_lautstaerke(K1);
  P0_2=0;
  P0_3=1;
  send_lautstaerke(K2);
  P0_3=0;
  return 0;
}
unsigned char i2c_send_einstellungen(void)
{
  send_audioinput();
/*  P0_2=1;
  P0_3=1;
  starti2c();
  sendi2c(0x82);
  sendi2c(0x02); //bass==0 =0xf6
  sendi2c(0xf6);
  stopi2c();
  P0_2=0;
  P0_3=0;
  */return 0;

}

unsigned char send_bass(unsigned char kanal,unsigned char wert)
{
  if(kanal==0)
    P0_2=1;
  else
    P0_3=1;
  starti2c();
  sendi2c(0x82);
  sendi2c(0x02); //bass==0 =0xf6
  if (wert>=13)
    wert=13;
  if(wert<=1)
    wert=1;
  sendi2c(wert+0xf0);
  stopi2c();
  P0_2=0;
  P0_3=0;
  return(wert);
}

unsigned char send_hoehen(unsigned char kanal,unsigned char wert)
{
  if(kanal==0)
    P0_2=1;
  else
    P0_3=1;
  starti2c();
  sendi2c(0x82);
  sendi2c(0x03); //Höhen==0 =0xf6
  if (wert>=13)
    wert=13;
  if(wert<=1)
    wert=1;
  sendi2c(wert+0xf0);
  stopi2c();
  P0_2=0;
  P0_3=0;
  return(wert);
}


void send_audioinput(void)
{
  P0_2=1;               //kanal1
  starti2c();
  sendi2c(0x82);
  sendi2c(0x08);
  if(sel_audioinput[0]==0) sendi2c(0xde);
  else sendi2c(0xdf);
  stopi2c();
  P0_2=0;
  P0_3=1;               //kanal2
  starti2c();
  sendi2c(0x82);
  sendi2c(0x08);
  if(sel_audioinput[1]==0) sendi2c(0xde);
  else sendi2c(0xdf);
  stopi2c();
  P0_3=0;

  return;
}


/*unsigned char i2c_send_einstellungen(void)
        {
        I2SCLH=I2CSPEEDH;
        I2SCLL=I2CSPEEDL;
        I2CON=0;
        I2EN=1;         //Master Transmit mode
        CRSEL=0;        //CRSEL=0
        STA=1;           //send Start MASTER
        if(i2c_wait()!=0)
                return 0xff;
        STA=0;
        I2DAT = 0x82+0;//a0= adresse i2c eeprom 0=schreiben SLA_W;       //Adresse senden MASTER
        if(i2c_wait()!=0)
                return 0xff;
        I2DAT = 0x08;                           //Daten Senden MASTER
        if(i2c_wait()!=0)
                return 0xff;
        I2DAT = 0xde;                             //Daten Senden MASTER
        if(i2c_wait()!=0)
                 return 0xff;

        STA=1;           //send Start MASTER
        if(i2c_wait()!=0)
                return 0xff;
        I2DAT = 0x82+0;//a0= adresse i2c eeprom 0=schreiben SLA_W;       //Adresse senden MASTER
        if(i2c_wait()!=0)
                return 0xff;
        I2DAT = 0x02;                           //Daten Senden MASTER
        if(i2c_wait()!=0)
                return 0xff;
        I2DAT = 0xff;                             //Daten Senden MASTER
        if(i2c_wait()!=0)
                 return 0xff;
        STO=1;            //send Stop MASTER
        if(i2c_wait()!=0)
                 return 0xff;

        return 0;
        }

*/

