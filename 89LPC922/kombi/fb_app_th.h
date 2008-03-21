
#ifndef FB_APP_RS
#define FB_APP_RS

#define	TEMPCORR			0xCA	// Abgleichwert für Temperatur in 0,1°C (-127 bis 128)
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

#define OWDATA 		P3_1	// Data-Pin für one-wire Sensor

extern long timer;			// Timer für Schaltverzögerungen, wird alle 130us hochgezählt
extern int temp,lasttemp;
extern bit templevel1, templevel2;

bit ow_init(void);						// one-wire Gerät initialisieren
void ow_write(unsigned char owbyte);	// Byte an one-wire Gerät senden
unsigned char ow_read(void);			// Byte von one-wire Gerät lesen
bit ow_read_bit(void);					// Bit von one-wire Datenleitung einlesen
void start_tempconversion(void);		// Temperaturmessung starten
int read_temp(void);					// Temperatur einlesen und gem EIS6 umrechnen
void restart_app(void);					// Alle Applikations-Parameter zurücksetzen
void temp_schwelle(bit schwelle);		// Temperaturschwelle prüfen und reagieren
void delay_timer(void);					// zählt alle 130ms die Variable Timer hoch und prüft Queue
void send_eis(unsigned char eistyp, unsigned char objno, int sval);	// sendet ein EIS Telegramm

void eis1(void);
void read_value_req(void);
#endif
