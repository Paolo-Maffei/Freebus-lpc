


#ifndef FB_HAL
#define FB_HAL

#define FBOUTC	P1_6	// Sendepin
#define TASTER	P1_7	// Pin für Programmiertaster
#define FBINC	P1_4	// Empfangspin
#define DUTY	0xC0	// war C0  0xFF=immer low 0x00=immer high


bit parity_ok;							// Parity Bit des letzten empfangenen Bytes OK

unsigned char get_byte(void);
void ext_int0(void) interrupt 2;
bit sendbyte(unsigned char fbsb);
void start_writecycle(void);
void stop_writecycle(void);
void write_byte(unsigned char addrh, unsigned char addrl, unsigned char zdata);
unsigned char read_byte(unsigned char addrh, unsigned char addrl);
void delay(int deltime);
void set_timer1(int deltime);
void restart_hw(void);

#endif
