#ifndef FB_PROT
#define FB_PROT

unsigned char telegramm[23];
unsigned char telpos;		// Zeiger auf nächste Position im Array Telegramm
unsigned char cs;		// checksum
unsigned char pal, pah;		// phys. Adresse
int gat[20];			// group address table
unsigned char gacount;		// Gruppenadresszähler

bit progmode, connected;	// Programmiermodus, Verbindung steht
unsigned char conh, conl;	// bei bestehender Verbindung phys. Adresse des Kommunikationspartners
unsigned char pcount;		// Paketzähler, Gruppenadresszähler


void timer1(void) interrupt 3;	// Interrupt von Timer 1, 370us keine Busaktivität seit letztem Byte, d.h. Telegramm wurde komplett übertragen
bit get_ack(void);		// wartet bis Byte empfangen wurde und prüft ob es ein ACK war  <- suboptimal, besser mit timeout !!!
void send_telegramm(void);	// sendet das Telegramm, das in telegramm[] vorher abgelegt wurde und berechnet die checksum
void send_ack(void);		// wartet auf Timer 1 wegen korrekter Positionierung und sendet ACK (0xCC)
void ucd_opr(void);		// UCD Verbindungsaufbau
void ucd_clr(void);		// UCD Verbindungsabbau
void get_gat(void);		// group address table aus EEPROM lesen und in array gat[] schreiben
void ncd_quit(void);		// NCD Quittierung zurück senden. Setzt telegramm Bytes 0 bis 6 !!!
void read_masq(void);		// Maskenversion senden
void read_memory(void);		// read_memory_request - Speicher auslesen und senden
void write_memory(void);	// write_memory_request - empfangene Daten in Speicher schreiben
void set_pa(void);		// neue phys. Adresse programmieren
void read_pa(void);		// phys. Adresse senden
unsigned char read_objflags(unsigned char objno);	// Objektflags lesen
void restart_prot(void);	// Protokoll-relevante Parameter zurücksetzen

#endif
