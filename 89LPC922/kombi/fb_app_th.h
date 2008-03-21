
#ifndef FB_APP_RS
#define FB_APP_RS

#define	TEMPCORR			0xCA	// Abgleichwert f�r Temperatur in 0,1�C (-127 bis 128)
#define FUNKTION			0xCB	// schalten oder wert senden
#define TEMPPARAM			0xD2

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

#define OWDATA 		P3_1	// Data-Pin f�r one-wire Sensor

extern long timer;			// Timer f�r Schaltverz�gerungen, wird alle 130us hochgez�hlt
extern int temp,lasttemp;
extern bit templevel1, templevel2;

bit ow_init(void);						// one-wire Ger�t initialisieren
void ow_write(unsigned char owbyte);	// Byte an one-wire Ger�t senden
unsigned char ow_read(void);			// Byte von one-wire Ger�t lesen
bit ow_read_bit(void);					// Bit von one-wire Datenleitung einlesen
void start_tempconversion(void);		// Temperaturmessung starten
int read_temp(void);					// Temperatur einlesen und gem EIS6 umrechnen
void restart_app(void);					// Alle Applikations-Parameter zur�cksetzen
void temp_schwelle(bit schwelle);		// Temperaturschwelle pr�fen und reagieren
void delay_timer(void);					// z�hlt alle 130ms die Variable Timer hoch und pr�ft Queue
void send_eis(unsigned char eistyp, unsigned char objno, int sval);	// sendet ein EIS Telegramm

void eis1(void);
void read_value_req(void);
#endif
