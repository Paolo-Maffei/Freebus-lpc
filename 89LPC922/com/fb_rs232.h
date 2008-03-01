#ifndef FB_RS232
#define FB_RS232


void rs_init(void);
void rs_send_dec(unsigned char wert);
void rs_send_ok(void);
void rs_send(unsigned char z);

#endif
