
#ifndef FB_APP_KOMBI
#define FB_APP_KOMBI

#define	TEMPCORR			0xCA	// Abgleichwert f�r Temperaturanzeige (-127 bis 128)
#define FUNKTION			0xCB	// schalten oder wert senden

#define LUXDELAY3			0xCC
#define LUXDELAY12			0xCD

#define TEMPPARAM			0xD2
#define LUXPARAM			0xD3



#define VERKWERT2L			0xD7
#define VERKWERT2H			0xD8
#define VERKLUX2			0xD9
#define	VERKCTRL2			0xDA
#define VERKCYCLE_TEMP2		0xDB

#define WINDEXIST			0xDC

#define VERKWERT1L			0xDD
#define VERKWERT1H			0xDE
#define VERKLUX1			0xDF
#define	VERKCTRL1			0xE0
#define VERKCYCLE_TEMP1		0xE1

#define WINDCTRL			0xE2

#define TEMPWERT2L			0xE3
#define TEMPWERT2H			0xE4
#define	TEMPCTRL2			0xE5
#define TEMPCYCLE2			0xE6
#define TEMPSCHWELLWERT2	0xE7

#define TEMPWERT1L			0xE8
#define TEMPWERT1H			0xE9
#define	TEMPCTRL1			0xEA
#define TEMPCYCLE1			0xEB
#define TEMPSCHWELLWERT1	0xEC

#define LUX_UNDER3			0xED
#define LUX_OVER3			0xEE
#define LUXCTRL3			0xEF
#define LUXCYCLE3			0xF0
#define LUXSCHWELLWERT3		0xF1

#define LUX_UNDER2			0xF2
#define LUX_OVER2			0xF3
#define LUXCTRL2			0xF4
#define LUXCYCLE2			0xF5
#define LUXSCHWELLWERT2		0xF6

#define LUX_UNDER			0xF7
#define LUX_OVER			0xF8
#define LUXCTRL				0xF9
#define LUXCYCLE1			0xFA
#define LUXSCHWELLWERT		0xFB

#define NIGHT		P0_0
#define RLY			P0_1
#define UP 			P0_4
#define DOWN		P0_6
#define BL			P0_7
#define POLARITY	P2_4
#define RESET		P2_5





#define EDITTIMEOUT	22


extern unsigned int timer;			// Timer f�r Schaltverz�gerungen, wird alle 130us hochgez�hlt
__xdata extern int temp;
__xdata extern unsigned int lux;
__xdata extern unsigned char overrun, dimmwert, underrun, sequence, lockatt, resend;
extern volatile __xdata unsigned char solltemplcd, solltemplpc;
extern bit lastrly;
extern volatile bit editmode;


extern struct delayrecord {
	unsigned char delayactive;
	unsigned char delaystate;
	unsigned int delayvalue;
};
extern struct delayrecord delrec[10];

#define WRITE_DELAY_RECORD(wdro,wdra,wdrs,wdrt) \
	delrec[wdro].delayactive=wdra; \
	delrec[wdro].delaystate=wdrs; \
	delrec[wdro].delayvalue=wdrt; 


void write_delay_record(unsigned char objno, unsigned char state, long deltime);

void restart_app(void);					// Alle Applikations-Parameter zur�cksetzen
void schwelle(unsigned char objno);
void delay_timer(void);					// z�hlt alle 130ms die Variable Timer hoch und pr�ft Queue
void write_value_req(void);
void read_value_req(void);
unsigned long read_obj_value(unsigned char objno);
void write_obj_value(unsigned char objno,int objvalue);
int eis5_to_int100(int eis5);
char eis5_to_char2(int eis5);
unsigned int int100_to_eis5(int int100);
void sync(void);
void key(void) interrupt 7;
#endif
