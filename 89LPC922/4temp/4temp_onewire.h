





bit ow_init(void);						// one-wire Ger�t initialisieren
void ow_write(unsigned char owbyte);	// Byte an one-wire Ger�t senden
unsigned char ow_read(void);			// Byte von one-wire Ger�t lesen
bit ow_read_bit(void);					// Bit von one-wire Datenleitung einlesen
void start_tempconversion(void);		// Temperaturmessung starten
int read_temp(void);					// Temperatur einlesen und gem EIS6 umrechnen
void owdelay(int deltime);


