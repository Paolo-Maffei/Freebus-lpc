/*
 *
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2010 Jan Wegner
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

#include <P89LPC922.h>
#include "fb_hal_lpc.h"
#include "fb_prot.h"
#include "fb_delay.h"
#include "fb_app_taster.h"

#if (PROGRAMM == 4)
#include "spi.h"
#endif

long timer; // Timer fuer Schaltverzoegerungen, wird alle 130us hochgezaehlt
unsigned char button_buffer; // Puffer fuer Taster Werte
bit dimmrichtung;

#if (PROGRAMM == 4)
unsigned char led_port;
#endif





/** 
*  Ein oder mehrere Taster wurden gedrueckt oder losgelassen
*
* \param  portval <Beschreibung>
* @return void
*/
void port_changed(unsigned char portval)
{
	unsigned char n, buttonpattern;
	
	set_timer0(50000);			// Entprellzeit
	while (!TF0);				// warten auf Timer 0


#if (PROGRAMM == 1 | PROGRAMM == 2) // MODUL_8_IN oder TASTER_8
	if (PORT == portval)
	{
		for (n=0; n<8; n++)		// alle 8 Taster einzeln pruefen (koennten ja mehrere gleichzeitig gedrueckt worden sein)

#elif (PROGRAMM == 3) // TASTER_4
	if ((PORT & 0x0F) == portval)
	{
		for (n=0; n<4; n++)		// alle 4 Taster einzeln pruefen (koennten ja mehrere gleichzeitig gedrueckt worden sein)

#elif (PROGRAMM == 4)  // RADIO
	if (spi_in_out(led_port) == portval)
	{
		for (n=0; n<8; n++)		// alle 8 Taster einzeln pruefen (koennten ja mehrere gleichzeitig gedrueckt worden sein)

#endif

		{
			buttonpattern=1<<n;

#if (PROGRAMM == 1) // MODUL_8_IN
			if ((portval & buttonpattern) && !(button_buffer & buttonpattern)) button_changed(n,1);	// Taster losgelassen
			if (!(portval & buttonpattern) && (button_buffer & buttonpattern)) button_changed(n,0);	// Taster gedrueckt
#else
			if ((portval & buttonpattern) && !(button_buffer & buttonpattern)) button_changed(n,0);	// Taster losgelassen
			if (!(portval & buttonpattern) && (button_buffer & buttonpattern)) button_changed(n,1);	// Taster gedrueckt
#endif

		}
		button_buffer=portval;	// aktuellen port wert in buffer fuer naechsten Vergleich uebernehmen
	}
}



/** 
* Taster geaendert
*
* \param  buttonno <Beschreibung>
* \param  buttonval <Beschreibung>
*
* @return void
*/
void button_changed(unsigned char buttonno, bit buttonval)
{
	unsigned char function, buttonno_help;

	// schalten
	unsigned char s_command, s_command_help;

	// dimmen
	unsigned char d_command, d_delay_state=0, d_delay_state_help;
	bit d_an_aus=1;

	// wertgeber
	int w_value;
	unsigned char w_command;

	bit objval=0;
	long duration=1;		// falls seitens ETS falsch programmiert 8ms default

	buttonno_help=buttonno*4; //wird selbstständig genutzt
	

	function=(eeprom[FUNCTION+(buttonno>>1)] >> ((buttonno & 0x01)*4)) & 0x0F;

	if (function==1)	//Schalten
	{
		s_command_help=eeprom[COMMAND+(buttonno*4)];

		s_command = ((s_command_help >> (2*buttonval+4)) & 0x03);
		objval=(s_command>>1)^0x01;

		if (s_command==2)
		{
			objval=!(read_obj_value(buttonno));
		}
		if (s_command)
		{
			send_value(1,(buttonno),objval);

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
			switch_led(buttonno, objval);		// LED schalten
#endif
		}
	}

	else if(function==2)	//Dimmen
	{
		if (buttonval)	// Taster gedrueckt -> schauen wie lange gehalten
		{

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
			if ((eeprom[COMMAND+(buttonno*4)]) & 0x04) switch_led(buttonno,0);	// wenn Betuetigungsanzeige, dann gleich beim druecken einschalten
#endif

			duration=eeprom[0xD6+(buttonno*4)];	// Faktor Dauer
			duration=duration<<4;
			duration=duration<<((eeprom[0xD5+(buttonno*4)]&0x30)>>4);
			duration+=timer;

			d_delay_state_help=eeprom[0xD4+(buttonno*4)];

			d_command=(eeprom[COMMAND+(buttonno*4)]&0x30);

			d_delay_state=d_delay_state_help>>(4*((~(d_command&0x20)>>5)&0x01));	// dimmen heller / dunkler

			if (d_command==0x20)
			{
				d_delay_state=d_delay_state_help>>(4*dimmrichtung);	// dimmen um
				dimmrichtung=!dimmrichtung;
			}

			d_delay_state&=0x0F;
			d_delay_state+=0x30;
			write_delay_record(buttonno,d_delay_state, duration);	// dimmen

		}
		else		// Taster losgelassen
		{
			if ((delrec[buttonno*4]&0xF0)==0x30) {		// wenn delaytimer noch lauft, dann Schalten, also EIS1 telegramm senden

				switch (eeprom[COMMAND+(buttonno*4)]&0x30)
				{
					case 0x10:	// zweiflächen ein
						d_an_aus=1;

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
						switch_led(buttonno,1);
#endif

						break;
					case 0x20:	// einflächen um
						d_an_aus=(((~read_obj_value(buttonno))&0x01));
						dimmrichtung=!d_an_aus;

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
						switch_led(buttonno,(!dimmrichtung));
#endif

						break;
					case 0x30:	// zweiflächen aus
						d_an_aus=0;

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
						switch_led(buttonno,0);
#endif

						break;
				}
				send_value(1, buttonno, d_an_aus);
				clear_delay_record(buttonno);

			}

			else {	// Timer schon abgelaufen (also dimmen), dann beim loslassen stop-telegramm senden
				if ((eeprom[COMMAND+(buttonno*4)] & 0x40) == 0) {	// ... natuerlich nur wenn parameter dementsprechend (0=senden!!!)
					send_value(1, buttonno+8, 0);		// Stop Telegramm
				}
				else write_obj_value(buttonno+8,0);	// auch wenn Stopp Telegramm nicht gesendet wird, Objektwert auf 0 setzen
			}

			if((delrec[buttonno*4]&0xF0)==0x40)
			{
				clear_delay_record(buttonno);
			}
		}
	}

	else if(function==3)	//Jalousie
	{
		if (buttonval)
		{	// Taster gedrueckt -> schauen wie lange gehalten

			objval=((eeprom[0xD3+(buttonno*4)]&0x10)>>4);
			send_value(1, buttonno, objval);	// Kurzzeit telegramm immer bei Drücken senden

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
			switch_led(buttonno,1);	// Status-LED schalten
#endif

			duration=eeprom[0xD5+(buttonno*4)];	// Faktor Dauer

			duration=duration<<2;
			duration=duration<<(eeprom[0xD4+(buttonno*4)]&0x06);

			duration+=timer;
			write_delay_record(buttonno, objval+0x10, duration);
		}
		else {	// Taster losgelassen
			if ((delrec[buttonno*4] & 0xF0)==0x20) send_value(1, buttonno, objval);	// wenn delaytimer noch laueft und in T2 ist, dann kurzzeit telegramm senden
			else clear_delay_record(buttonno);	// T2 bereits abgelaufen
		}

	}

	else if(function==4)	//Wertgeber
	{

		w_command=eeprom[0xD3+4*buttonno]&0x70;

		if (buttonval) // taster gedrückt
		{

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
			switch_led(buttonno,1);	// Status-LED schalten
#endif

			w_value=eeprom[0xD5+4*buttonno];
			if (w_command==0x20 || w_command==0x30)
			{
				w_value*=256;
				w_value+=eeprom[0xD6+4*buttonno];
			}


			if((eeprom[0xD3+4*buttonno]&0x70)==0x10)		// Lichtszene mit Speichrfunktion
			{
				write_delay_record(buttonno, 0x50, timer+125);		// 1s laden

			}
			else
			{
				write_delay_record(buttonno, 0x50, timer+625);		// 5s laden
				send_value(1, buttonno+8, w_value);					// Kurzwert senden
			}

		}
		else // taster losgelassen
		{
			if((eeprom[0xD3+4*buttonno]&0x70)==0x10)		// Lichtszene mit Speichrfunktion
			{
				if ((delrec[buttonno*4] & 0xF0)==0x50)	// noch 1.sekunde
				{
					send_value(1, buttonno+8, eeprom[0xD5+4*buttonno]);	// Lichtszene abrufen
				}
			}

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
			if ((delrec[buttonno*4] & 0xF0)==0x60)
			{
				w_switch_led(buttonno,0);
			}
#endif
			clear_delay_record(buttonno);
		}
	}

}



/** 
* Ausgaenge schalten gemaess EIS 1 Protokoll (an/aus)
*
* \param void
* @return void
*/
void write_value_req(void)
{
	unsigned char objno,objflags,gapos,atp,assno,n,gaposh;

	gapos=gapos_in_gat(telegramm[3],telegramm[4]);
	if (gapos!=0xFF)	
	{
		if ((telegramm[1] != eeprom[ADDRTAB+1]) || (telegramm[2] != eeprom[ADDRTAB+2])) send_ack();
	    atp=eeprom[ASSOCTABPTR];			// Association Table Pointer
	    assno=eeprom[atp];					// Erster Eintrag = Anzahl Eintraege
	 
	    for(n=0;n<assno;n++) {				// Schleife über alle Eintraege in der Ass-Table, denn es koennten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
	    	gaposh=eeprom[atp+1+(n*2)];
	    	if(gapos==gaposh) {					// Wenn Positionsnummer uebereinstimmt
	    		objno=eeprom[atp+2+(n*2)];			// Objektnummer
	    		objflags=read_objflags(objno);		// Objekt Flags lesen
	    		if((objflags&0x14)==0x14) {			// Kommunikation zulaessig (Bit 2 = communication enable) + Schreiben zulaessig (Bit 4 = write enable)
	    			if (objno<16) {					// max 12 objekte
	    				write_obj_value(objno,telegramm[7]);

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
	    				if ((objno<8) && ((eeprom[COMMAND+(objno*4)]) & 0x07) <4) switch_led(objno,telegramm[7]&0x01);	// LED nur schalten, wenn nicht auf Betï¿½tigungsanzeige parametriert
#endif

	    			}
	    		}
	    	}
	    }
	}
}


/** 
* Objektwert lesen wurde angefordert, read_value_response Telegramm zurücksenden
*
* 
* @return
* 
*/
void read_value_req(void)
{
	unsigned char objno, objflags;
	int objvalue;
	
	objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
	if(objno!=0xFF) {	// falls Gruppenadresse nicht gefunden
		send_ack(); 
		
		objvalue=read_obj_value(objno);		// Objektwert aus USER-RAM lesen (Standard Einstellung)

		objflags=read_objflags(objno);		// Objekt Flags lesen
		// Objekt lesen, nur wenn read enable gesetzt (Bit3) und Kommunikation zulaessig (Bit2)
		if((objflags&0x0C)==0x0C) send_value(0,objno,objvalue);
    }
}



/**
* sucht Gruppenadresse für das Objekt objno uns sendet ein EIS Telegramm
*
* \param  type
* \param  objno
* \param  sval
*
* @return void
*/
void send_value(unsigned char type, unsigned char objno, unsigned int sval)
{
  unsigned int ga;
  unsigned char objtype;

  ga=find_ga(objno);					// wenn keine Gruppenadresse hintrlegt nix tun
  if (ga!=0)
  {
    telegramm[0]=0xBC;
    telegramm[1]=eeprom[ADDRTAB+1];
    telegramm[2]=eeprom[ADDRTAB+2];
    telegramm[3]=ga>>8;
    telegramm[4]=ga;
    telegramm[6]=0x00;
//    if (type==0) telegramm[7]=0x40;		// read_value_response Telegramm (angefordert)
//    else telegramm[7]=0x80;				// write_value_request Telegramm (nicht angefordert)

    telegramm[7]=0x80;
    if (type==0) telegramm[7]=0x40;


    objtype=read_obj_type(objno);

    if(objtype<6) {					// Objekttyp, 1-6 Bit
    	telegramm[5]=0xE1;
    	telegramm[7]+=sval;
    }

   if(objtype>=6 && objtype<=7) {	// Objekttyp, 7-8 Bit
    	telegramm[5]=0xE2;
    	telegramm[8]=sval;
    }

     if(objtype==8) {				// Objekttyp, 16 Bit
    	telegramm[5]=0xE3;
    	telegramm[8]=sval>>8;
    	telegramm[9]=sval;
    }


    EX1=0;
    send_telegramm();
    IE1=0;
    EX1=1;

    if (type==1)
    {
    	if (objno<8)
    	{
			write_obj_value(objno,sval);
			write_value_req();
    	}
    }

  }
}



/** 
* zaehlt alle 8ms die Variable Timer hoch und prueft records
*
* \param void
* @return void
*/
void delay_timer(void)
{
	unsigned char objno, delay_state, d_telezeit, d_telezeit_help, w_telezeit;//, w_telezeit_help;
	long delval;
	long duration=1;

	int w_value;
	unsigned char w_diff;

	stop_rtc();
	timer++;

	timer&=0x00FFFFFF;	// nur 3 Byte aktiv

	for(objno=0;objno<16;objno++) {
		delay_state=delrec[objno*4];
		if(delay_state!=0x00) {			// 0x00 = delay Eintrag ist leer   
			delval=delrec[objno*4+1];
			delval=(delval<<8)+delrec[objno*4+2];
			delval=(delval<<8)+delrec[objno*4+3];	// delval enthaelt den im delay record gespeicherten timer-wert
			if(delval==timer) {	// ... es ist also soweit

#if (PROGRAMM == 3) // TASTER_4
				if (objno>7)	// LED bei Betaetigungsanzeige nach eingestellter Zeit ausschalten
				{
					PORT &= ~(1<<(objno-4));	// LEDs sind an Pin 4-7
					PORT |= 0x0F;				// unbedingt taster pins wieder auf 1
					clear_delay_record(objno);
				}
				else
				{
#endif

#if (PROGRAMM == 4) // RADIO
					if (objno>7)	// LED bei Betaetigungsanzeige nach eingestellter Zeit ausschalten
					{
						led_port &= ~(1<<(objno-8));	// LEDs sind an Pin 4-7
						clear_delay_record(objno);
					}
					else
					{
#endif

				if ((delay_state & 0xF0)==0x10) // 0x1? für langzeit telegramm senden
				{
					send_value(1, (objno+8), delay_state & 0x01);	// Langzeit Telegramm senden
					// *** delay record neu laden für Dauer Lamellenverstellung ***
					duration=eeprom[DEL_FACTOR2+(objno*4)];	// Faktor Dauer	T2
					duration=duration<<2;
					duration=duration<<((eeprom[DEL_BASE+(objno*4)]&0x60)>>4);

					if (duration) {	// wenn keine lamellenverstellzeit dann nix tun
						duration+=timer;
						write_delay_record(objno, ((eeprom[COMMAND+(objno*4)]&0x10)>>4)+0x20, duration); // 0x10,0x11 fuer ende T2 (lamellenvestellzeit)
					}
					else clear_delay_record(objno);
				}


				if ((delay_state & 0xF0)==0x20)
				{
					clear_delay_record(objno); // wenn T2 abgelaufen dann nichts mehr machen
				}


				if (((delay_state & 0xF0)==0x30) || ((delay_state & 0xF0)==0x40)) // 0x3? und 0x4? fuer Dimmer Funktion
				{
					send_value(1, objno+8, (delay_state&0x0F));	// Dimm Telegramm senden
					if ((eeprom[0xD5+(objno*4)]&0x08)==0x08)	// Telegrammwiederholung
					{
						clear_delay_record(objno);
					}
					else	// Wiederholzeit nachladen

					{
						d_telezeit=eeprom[0xD5+(objno*4)]&0x03;
						if (d_telezeit<1) d_telezeit_help=62;			// 500ms
						else if (d_telezeit<2) d_telezeit_help=125;		// 1s
						else if (d_telezeit<3) d_telezeit_help=187;		// 1,5s
						else if (d_telezeit<4) d_telezeit_help=250;		// 2s
						else if (d_telezeit<5) d_telezeit_help=25;		// 200ms
						else if (d_telezeit<6) d_telezeit_help=37;		// 300ms
						else if (d_telezeit<7) d_telezeit_help=50;		// 400ms
						else d_telezeit_help=93;						// 750ms
						write_delay_record(objno,((delay_state & 0x0F)+0x40),timer+d_telezeit_help);
					}
				}

				if (((delay_state & 0xF0)==0x50) || ((delay_state & 0xF0)==0x60)) // 0x5? und 0x6? für Wertgeber
				{
					if (eeprom[0xD3+4*objno]&0x80)	// nicht verstellen (Lichtszenenwertgeber)
					{
						if ((eeprom[0xD3+4*objno]&0x70)==0x10)	// Lichtszene mit Speichern
						{
							if ((delay_state & 0xF0)==0x50) // 1.sekunde rum
							{
								write_delay_record(objno,((delay_state & 0x0F)+0x60),timer+500);		// 4s nachladen
							}
							else	// 5.sekunde rum
							{

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
								w_switch_led(objno,1);
#endif

								send_value(1, objno+8, eeprom[0xD5+4*objno]+0x80);	// Lichtszene speichern
								clear_delay_record(objno);

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
								w_switch_led(objno,0);
#endif

							}
						}
					}
					else	// verstellen Dimmen Temperatur Helligkeit
					{
						// Verstellintervall nachladen
						w_telezeit=(eeprom[0xD4+(objno*4)]>>4)&0x03;
						w_telezeit*=62;
						w_telezeit+=62;
						write_delay_record(objno,((delay_state & 0x0F)+0x60),timer+w_telezeit);


						if ((eeprom[0xD3+4*objno]&0x70)==0x20)	//Helligkeit
						{
							w_value=eeprom[0xD5+4*objno];
							w_value*=256;
							w_value+=eeprom[0xD6+4*objno];

							w_diff=0x27;

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
							w_switch_led(objno,1);
#endif

							if (w_value==0x39FD || w_value==0x3828)	//Differenz ausgleichen
							{
								w_value--;
							}

							w_value-=w_diff;	// Wert verringern

							if (w_value==0x3800)	// bei 0lux LED aus
							{

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
								w_switch_led(objno,0);
#endif
							}
							if (!(w_value&0x0800)) w_value=0x3C94;	//von 0 nix mehr abziehen also wieder bei 1500lux starten


							send_value(1,objno+8,w_value);

							EA=0;
							START_WRITECYCLE
							WRITE_BYTE(0x01,(0xD5+4*objno),(w_value>>8)&0x00FF)
							WRITE_BYTE(0x01,(0xD6+4*objno),w_value&0x00FF)
							STOP_WRITECYCLE;
							EA=1;
						}

						if ((eeprom[0xD3+4*objno]&0x70)==0x30) //Temperatur
						{
							w_value=eeprom[0xD5+4*objno];
							w_value*=256;
							w_value+=eeprom[0xD6+4*objno];

							w_diff=0x32;

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
							w_switch_led(objno,1);
#endif

							w_value-=w_diff;	// Wert verringern


							if (w_value==0x0800)	// bei 0°C LED aus
							{

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
							w_switch_led(objno,0);
#endif
							}

							if (!(w_value&0x0800)) w_value=0x0FD0;	// von 0 nix mehr abziehen also wieder bei 40°C starten

							send_value(1,objno+8,w_value);

							EA=0;
							START_WRITECYCLE
							WRITE_BYTE(0x01,(0xD5+4*objno),(w_value>>8)&0x00FF)
							WRITE_BYTE(0x01,(0xD6+4*objno),w_value&0x00FF)
							STOP_WRITECYCLE;
							EA=1;
						}


						if ((eeprom[0xD3+4*objno]&0x70)==0x40)	//Dimmwert
						{
							w_value=eeprom[0xD5+4*objno];
							w_diff=(eeprom[0xD4+4*objno]&0x0F);
							if ((w_value)>w_diff || w_value==0x00)
							{
								w_value-=w_diff;

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
								w_switch_led(objno,1);
#endif
							}
							else
							{
								w_value=0x00;

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
								w_switch_led(objno,0);
#endif
							}
							send_value(1,objno+8,w_value);
							EA=0;
							START_WRITECYCLE
							WRITE_BYTE(0x01,(0xD5+4*objno),w_value&0x00FF)
							STOP_WRITECYCLE;
							EA=1;
						}
					}
				}

#if (PROGRAMM == 3 | PROGRAMM == 4) // TASTER_4 oder RADIO
				}
#endif

			}
		}
	}
	start_rtc(8);		// RTC neu starten mit 8ms
}

#if (PROGRAMM == 3) // TASTER_4
/**
* LEDs schalten entsprechend der parametrierung
*
* \param  ledno <Beschreibung>
* \param  onoff <Beschreibung>
*
* @return void
*/
void switch_led(unsigned char ledno, bit onoff)
{
	unsigned char command, led_zeit;

	if (ledno<4) {

		command = ((eeprom[COMMAND+(ledno*4)]) & 0x07);	// Befehl der Status LED

		if (command<1) {onoff=0;}				//immer aus
		else if (command<2) {onoff=1;}			//immer an
		else if (command<3) {}					//Statusanzeige
		else if (command<4) {onoff=!onoff;}		//invertierte Statusanzeige
		else									//Betätigungsanzeige
		{
			onoff=1;
			led_zeit=(eeprom[LED_DURATION]>>5);
			write_delay_record(ledno+8, 0x80, timer+(94*led_zeit));
		}

		PORT &= ~(1<<(ledno+4));				// LEDs sind an Pin 4-7
		PORT |= ((onoff<<(ledno+4)) | 0x0F);	// unteren 4 bits immer auf 1 lassen !!!
	}
}


/**
* LEDs schalten bei Wertverstellung Wertgeber
*
* \param  ledno <Beschreibung>
* \param  onoff <Beschreibung>
*
* @return void
*/
void w_switch_led(unsigned char ledno, bit onoff)
{
	PORT &= ~(1<<(ledno+4));				// LEDs sind an Pin 4-7
	PORT |= ((onoff<<(ledno+4)) | 0x0F);	// unteren 4 bits immer auf 1 lassen !!!
}
#endif




#if (PROGRAMM == 4) // RADIO
/**
* LEDs schalten entsprechend der parametrierung
*
* \param  ledno <Beschreibung>
* \param  onoff <Beschreibung>
*
* @return void
*/
void switch_led(unsigned char ledno, bit onoff)
{
	unsigned char command, led_zeit;

	if (ledno<8) {

		command = ((eeprom[COMMAND+(ledno*4)]) & 0x07);	// Befehl der Status LED

		if (command<1) {onoff=0;}				//immer aus
		else if (command<2) {onoff=1;}			//immer an
		else if (command<3) {}					//Statusanzeige
		else if (command<4) {onoff=!onoff;}		//invertierte Statusanzeige
		else									//Betätigungsanzeige
		{
			onoff=1;
			led_zeit=(eeprom[LED_DURATION]>>5);
			write_delay_record(ledno+8, 0x80, timer+(94*led_zeit));
		}

		led_port &= ~(1<<ledno);
		led_port |= (onoff<<ledno);
	}
}


/**
* LEDs schalten bei Wertverstellung Wertgeber
*
* \param  ledno <Beschreibung>
* \param  onoff <Beschreibung>
*
* @return void
*/
void w_switch_led(unsigned char ledno, bit onoff)
{
	led_port &= ~(1<<ledno);
	led_port |= (onoff<<ledno);
}

#endif




/** 
* Alle Applikations-Parameter zuruecksetzen und Empfang starten
* 
*
* \param void
* @return void
*/
void restart_app(void)
{
	unsigned char n;
	bit write_ok=0;


#if (PROGRAMM == 1) // MODUL_8_IN
	P0M1=0xFF;				//P0 auf input only (high impedance!)
	P0M2=0x00;
	P0=0x00;				// Taster auf low
	button_buffer=0x00;		// Variable für letzten abgearbeiteten Taster Status

#elif (PROGRAMM == 2) // TASTER_8
	P0M1=0x00;				//P0 auf bidirektional
	P0M2=0x00;
	P0=0xFF;				//Taster auf high
	button_buffer=0xFF;		// Variable für letzten abgearbeiteten Taster Status

#elif (PROGRAMM == 3) // TASTER_4
	P0M1=0x00;				//P0.0-P0.3 auf bidirektional P0.4-P0.7 auf Push-Pull
	P0M2=0xF0;
	PORT=0x0F;				// Taster auf high, LEDs zunächst aus
	button_buffer=0x0F;		// Variable für letzten abgearbeiteten Taster Status

#elif (PROGRAMM == 4) // RADIO
	P0M1=0x00;				// P0_1 Biderektional Rest PushPull
	P0M2=0xFB;
	P0=0x04;				// SER_IN=1
	button_buffer=0xFF;		// Variable für letzten abgearbeiteten Taster Status

#endif

	dimmrichtung=1;

	stop_rtc();
	start_rtc(8);		// RTC neu mit 8ms starten
	timer=0;			// Timer-Variable, wird alle 8ms inkrementiert

	EA=0;		// Interrupts sperren
	// Applikations-spezifische eeprom Eintraege schreiben
	START_WRITECYCLE			
	WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode 0x0004 = Jung
	WRITE_BYTE(0x01,0x04,0x04)
#if (PROGRAMM == 3) // TASTER_4
	WRITE_BYTE(0x01,0x05,0x10)	// Devicetype 0x1052 = Jung Tastsensor 2092
	WRITE_BYTE(0x01,0x06,0x52)
#else
	WRITE_BYTE(0x01,0x05,0x10)	// Devicetype 0x104E = Jung Tastsensor 2094
	WRITE_BYTE(0x01,0x06,0x4E)
#endif
	WRITE_BYTE(0x01,0x07,0x01)	// Versionsnummer
	WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	WRITE_BYTE(0x01,0x12,0x9A)	// COMMSTAB Pointer
	STOP_WRITECYCLE
	START_WRITECYCLE;
	WRITE_BYTE(0x00,0x60,0x2E);	// system state: all layers active (run), not in prog mode
	STOP_WRITECYCLE;

	for (n=0;n<16;n++) write_obj_value(n,0);		// Objektwerte alle auf 0 setzen
	for (n=0;n<16;n++) clear_delay_record(n);	// delay records loeschen


#if (PROGRAMM == 3) // TASTER_4
	for (n=0;n<4;n++) switch_led(n,0);	// Alle LEDs gemaess ihren Parametern setzen
#endif

#if (PROGRAMM == 4) // RADIO
	for (n=0;n<8;n++) switch_led(n,0);	// Alle LEDs gemaess ihren Parametern setzen
#endif

	EA=1;		// Interrupts freigeben	
	
}
