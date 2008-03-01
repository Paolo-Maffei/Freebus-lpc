#ifndef FB_PROT
#define FB_PROT

#define ASSOCTABPTR 	0x11	// Adresse des Pointers auf die Assoziations-Tabelle
#define COMMSTABPTR 	0x12	// Adresse des Pointers auf die Kommunikationsobjekt-Tabelle
#define ADDRTAB			0x16	// Startadresse der Adresstabelle

extern unsigned char telegramm[23];
extern unsigned char telpos;		// Zeiger auf n�chste Position im Array Telegramm
extern unsigned char cs;			// checksum
extern unsigned char pal, pah;		// phys. Adresse
//int gat[20];				// group address table
extern unsigned char gacount;		// Gruppenadressz�hler

extern bit progmode, connected;	// Programmiermodus, Verbindung steht
extern unsigned char conh, conl;	// bei bestehender Verbindung phys. Adresse des Kommunikationspartners
extern unsigned char pcount;		// Paketz�hler, Gruppenadressz�hler


void timer1(void) interrupt 3;	// Interrupt von Timer 1, 370us keine Busaktivit�t seit letztem Byte, d.h. Telegramm wurde komplett �bertragen
// bit get_ack(void);		// wartet bis Byte empfangen wurde und pr�ft ob es ein ACK war  <- suboptimal, besser mit timeout !!!
void send_telegramm(void);	// sendet das Telegramm, das in telegramm[] vorher abgelegt wurde und berechnet die checksum
void send_ack(void);		// wartet auf Timer 1 wegen korrekter Positionierung und sendet ACK (0xCC)
void ucd_opr(void);		// UCD Verbindungsaufbau
void ucd_clr(void);		// UCD Verbindungsabbau
void get_gat(void);		// group address table aus EEPROM lesen und in array gat[] schreiben
unsigned char gapos_in_gat(unsigned char gah, unsigned char gal);	// Gruppenadresse in Adresstabelle finden, R�ckgabe Positionsnr.
void ncd_quit(void);		// NCD Quittierung zur�ck senden. Setzt telegramm Bytes 0 bis 6 !!!
void read_masq(void);		// Maskenversion senden
void read_memory(void);		// read_memory_request - Speicher auslesen und senden
void write_memory(void);	// write_memory_request - empfangene Daten in Speicher schreiben
void set_pa(void);		// neue phys. Adresse programmieren
void read_pa(void);		// phys. Adresse senden
unsigned char read_objflags(unsigned char objno);	// Objektflags lesen
int find_ga(unsigned char objno);	// Gruppenadresse �ber Assoziationstabelle finden (letzter Eintrag, falls mehrere)
void write_delay_record(unsigned char objno, unsigned char delay_status, long delay_target);	// Schreibt die Schalt-Verz�gerungswerte ins Flash
void restart_prot(void);	// Protokoll-relevante Parameter zur�cksetzen

void eis1(void);			// Hauptroutine f�r Ausg�nge schalten gem�� EIS 1 Protokoll (an/aus)
void read_value_req(void);	// Objektwerte lesen angefordert
void restart_app(void);		// Alle Applikations-Parameter zur�cksetzen

#endif
