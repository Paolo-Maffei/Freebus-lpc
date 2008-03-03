
#ifndef FB_APP_RS
#define FB_APP_RS



#define FUNCASS		0xD8	// Startadresse der Zuordnung der Zusatzfunktionen (2 Byte)
#define FUNCTYP		0xED	// Typ der Zusatzfunktion
#define LOGICTYP	0xEE	// Verkn�pfungs Typ 0=keine 1=ODER 2=UND 3=UND mir R�ckf�hrung
#define BLOCKACT	0xEF	// Verhalten beim Sperren
#define RELMODE		0xF2	// Relaisbetrieb
#define	DELAYTAB	0xF9	// Start der Tabelle f�r Verz�gerungswerte (Basis)

#define OWDATA 		P3_1	// Data-Pin f�r one-wire Sensor


bit ow_init(void);						// one-wire Ger�t initialisieren
void ow_write(unsigned char owbyte);	// Byte an one-wire Ger�t senden
unsigned char ow_read(void);			// Byte von one-wire Ger�t lesen
bit ow_read_bit(void);					// Bit von one-wire Datenleitung einlesen
int read_temp(void);					// Temperatur einlesen und gem EIS6 umrechnen
void restart_app(void);					// Alle Applikations-Parameter zur�cksetzen
void eis1(void);
void read_value_req(void);
#endif
