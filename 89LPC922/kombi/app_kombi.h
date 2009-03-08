
#ifndef FB_APP_KOMBI
#define FB_APP_KOMBI

#define	TEMPCORR			0xCA	// Abgleichwert für Temperatur in 0,1°C (-127 bis 128)
#define FUNKTION			0xCB	// schalten oder wert senden
#define TEMPPARAM			0xD2
#define LUXPARAM			0xD3

#define TEMPWERT1L			0xE8
#define TEMPWERT1H			0xE9
#define	TEMPCTRL1			0xEA
#define TEMPCYCLE1			0xEB
#define TEMPSCHWELLWERT1	0xEC

#define TEMPWERT2L			0xE3
#define TEMPWERT2H			0xE4
#define	TEMPCTRL2			0xE5
#define TEMPCYCLE2			0xE6
#define TEMPSCHWELLWERT2	0xE7


#define LUX_UNDER			0xF7
#define LUX_OVER			0xF8
#define LUXCTRL				0xF9
#define LUXSCHWELLWERT		0xFB




extern long timer;			// Timer für Schaltverzögerungen, wird alle 130us hochgezählt
extern int temp, eis5temp,lasttemp,lux,lastlux, eis5lux;

extern bit templevel1, templevel2;

extern unsigned char luxsent, dimmwert;

void write_delay_record(unsigned char objno, unsigned char state, long deltime);

void restart_app(void);					// Alle Applikations-Parameter zurücksetzen
void temp_schwelle(bit schwelle);		// Temperaturschwelle prüfen und reagieren
void lux_schwelle(unsigned char schwelle);
void delay_timer(void);					// zählt alle 130ms die Variable Timer hoch und prüft Queue
void send_eis(unsigned char eistyp, unsigned char objno, int sval);	// sendet ein EIS Telegramm

void write_value_req(void);
void read_value_req(void);
#endif
