
#ifndef FB_APP_IN8
#define FB_APP_IN8

#define ASSOCTABPTR 	0x11	// Adresse des Pointers auf die Assoziations-Tabelle
#define COMMSTABPTR 	0x12	// Adresse des Pointers auf die Kommunikationsobjekt-Tabelle
#define ADDRTAB		0x16	// Startadresse der Adresstabelle
#define DEBTIME		0xD2	// Entprellzeit in 0,5ms
#define RELMODE		0xF2	// Relaisbetrieb
#define	DELAYTAB	0xF9	// Start der Tabelle f�r Verz�gerungswerte (Basis)

void schalten(unsigned char risefall, unsigned char pinno);	// Schaltbefehl senden
unsigned char pin_function(unsigned char pinno);	// Funktion des Eingangs ermitteln
unsigned char debounce(unsigned char pinno);		// Entprellzeit abwarten und pr�fen
void send_cyclic(unsigned char pinno);
unsigned char operation(unsigned char pinno);
unsigned char switch_dim(unsigned char pinno);

void eis1(void);		// Ausg�nge schalten gem�� EIS 1 Protokoll (an/aus)
void delay_timer(void);		// z�hlt alle 130ms die Variable Timer hoch und pr�ft Queue
void restart_app(void);		// Alle Applikations-Parameter zur�cksetzen

#endif
