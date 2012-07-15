;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
; This file was generated Sun Jul 15 18:51:27 2012
;--------------------------------------------------------
	.module onewire
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _P3_1
	.globl _P3_0
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _I2CON_0
	.globl _I2CON_2
	.globl _I2CON_3
	.globl _I2CON_4
	.globl _I2CON_5
	.globl _I2CON_6
	.globl _SCON_7
	.globl _SCON_6
	.globl _SCON_5
	.globl _SCON_4
	.globl _SCON_3
	.globl _SCON_2
	.globl _SCON_1
	.globl _SCON_0
	.globl _IP0_0
	.globl _IP0_1
	.globl _IP0_2
	.globl _IP0_3
	.globl _IP0_4
	.globl _IP0_5
	.globl _IP0_6
	.globl _IP1_0
	.globl _IP1_1
	.globl _IP1_2
	.globl _IP1_6
	.globl _IEN1_0
	.globl _IEN1_1
	.globl _IEN1_2
	.globl _IEN0_0
	.globl _IEN0_1
	.globl _IEN0_2
	.globl _IEN0_3
	.globl _IEN0_4
	.globl _IEN0_5
	.globl _IEN0_6
	.globl _IEN0_7
	.globl _TCON_0
	.globl _TCON_1
	.globl _TCON_2
	.globl _TCON_3
	.globl _TCON_4
	.globl _TCON_5
	.globl _TCON_6
	.globl _TCON_7
	.globl _PSW_7
	.globl _PSW_6
	.globl _PSW_5
	.globl _PSW_4
	.globl _PSW_3
	.globl _PSW_2
	.globl _PSW_1
	.globl _PSW_0
	.globl _IEN1
	.globl _IP0H
	.globl _WFEED2
	.globl _WFEED1
	.globl _WDL
	.globl _WDCON
	.globl _TRIM
	.globl _TAMOD
	.globl _SSTAT
	.globl _RTCL
	.globl _RTCH
	.globl _RTCCON
	.globl _RSTSRC
	.globl _PT0AD
	.globl _PCONA
	.globl _P3M2
	.globl _P3M1
	.globl _P1M2
	.globl _P1M1
	.globl _P0M2
	.globl _P0M1
	.globl _KBPATN
	.globl _KBMASK
	.globl _KBCON
	.globl _IP1H
	.globl _IP1
	.globl _I2STAT
	.globl _I2SCLL
	.globl _I2SCLH
	.globl _I2DAT
	.globl _I2CON
	.globl _I2ADR
	.globl _FMDATA
	.globl _FMCON
	.globl _FMADRL
	.globl _FMADRH
	.globl _DIVM
	.globl _CMP2
	.globl _CMP1
	.globl _BRGCON
	.globl _BRGR1
	.globl _BRGR0
	.globl _SADEN
	.globl _SADDR
	.globl _AUXR1
	.globl _SBUF
	.globl _SCON
	.globl _IP0
	.globl _IEN0
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _P3
	.globl _P1
	.globl _P0
	.globl _ow_init
	.globl _ow_write
	.globl _ow_read
	.globl _ow_read_bit
	.globl _start_tempconversion
	.globl _read_temp
	.globl _owdelay
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (DATA)
_P0	=	0x0080
_P1	=	0x0090
_P3	=	0x00b0
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_IEN0	=	0x00a8
_IP0	=	0x00b8
_SCON	=	0x0098
_SBUF	=	0x0099
_AUXR1	=	0x00a2
_SADDR	=	0x00a9
_SADEN	=	0x00b9
_BRGR0	=	0x00be
_BRGR1	=	0x00bf
_BRGCON	=	0x00bd
_CMP1	=	0x00ac
_CMP2	=	0x00ad
_DIVM	=	0x0095
_FMADRH	=	0x00e7
_FMADRL	=	0x00e6
_FMCON	=	0x00e4
_FMDATA	=	0x00e5
_I2ADR	=	0x00db
_I2CON	=	0x00d8
_I2DAT	=	0x00da
_I2SCLH	=	0x00dd
_I2SCLL	=	0x00dc
_I2STAT	=	0x00d9
_IP1	=	0x00f8
_IP1H	=	0x00f7
_KBCON	=	0x0094
_KBMASK	=	0x0086
_KBPATN	=	0x0093
_P0M1	=	0x0084
_P0M2	=	0x0085
_P1M1	=	0x0091
_P1M2	=	0x0092
_P3M1	=	0x00b1
_P3M2	=	0x00b2
_PCONA	=	0x00b5
_PT0AD	=	0x00f6
_RSTSRC	=	0x00df
_RTCCON	=	0x00d1
_RTCH	=	0x00d2
_RTCL	=	0x00d3
_SSTAT	=	0x00ba
_TAMOD	=	0x008f
_TRIM	=	0x0096
_WDCON	=	0x00a7
_WDL	=	0x00c1
_WFEED1	=	0x00c2
_WFEED2	=	0x00c3
_IP0H	=	0x00b7
_IEN1	=	0x00e8
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (DATA)
_PSW_0	=	0x00d0
_PSW_1	=	0x00d1
_PSW_2	=	0x00d2
_PSW_3	=	0x00d3
_PSW_4	=	0x00d4
_PSW_5	=	0x00d5
_PSW_6	=	0x00d6
_PSW_7	=	0x00d7
_TCON_7	=	0x008f
_TCON_6	=	0x008e
_TCON_5	=	0x008d
_TCON_4	=	0x008c
_TCON_3	=	0x008b
_TCON_2	=	0x008a
_TCON_1	=	0x0089
_TCON_0	=	0x0088
_IEN0_7	=	0x00af
_IEN0_6	=	0x00ae
_IEN0_5	=	0x00ad
_IEN0_4	=	0x00ac
_IEN0_3	=	0x00ab
_IEN0_2	=	0x00aa
_IEN0_1	=	0x00a9
_IEN0_0	=	0x00a8
_IEN1_2	=	0x00ea
_IEN1_1	=	0x00e9
_IEN1_0	=	0x00e8
_IP1_6	=	0x00fe
_IP1_2	=	0x00fa
_IP1_1	=	0x00f9
_IP1_0	=	0x00f8
_IP0_6	=	0x00be
_IP0_5	=	0x00bd
_IP0_4	=	0x00bc
_IP0_3	=	0x00bb
_IP0_2	=	0x00ba
_IP0_1	=	0x00b9
_IP0_0	=	0x00b8
_SCON_0	=	0x0098
_SCON_1	=	0x0099
_SCON_2	=	0x009a
_SCON_3	=	0x009b
_SCON_4	=	0x009c
_SCON_5	=	0x009d
_SCON_6	=	0x009e
_SCON_7	=	0x009f
_I2CON_6	=	0x00de
_I2CON_5	=	0x00dd
_I2CON_4	=	0x00dc
_I2CON_3	=	0x00db
_I2CON_2	=	0x00da
_I2CON_0	=	0x00d8
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_P3_0	=	0x00b0
_P3_1	=	0x00b1
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; overlayable bit register bank
;--------------------------------------------------------
	.area BIT_BANK	(REL,OVR,DATA)
bits:
	.ds 1
	b0 = bits[0]
	b1 = bits[1]
	b2 = bits[2]
	b3 = bits[3]
	b4 = bits[4]
	b5 = bits[5]
	b6 = bits[6]
	b7 = bits[7]
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area OSEG    (OVR,DATA)
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'ow_init'
;------------------------------------------------------------
;presence                  Allocated to registers b0 
;n                         Allocated to registers r2 
;------------------------------------------------------------
;	../../com/onewire.c:18: bit ow_init(void)		// one-wire Gerät initialisieren
;	-----------------------------------------
;	 function ow_init
;	-----------------------------------------
_ow_init:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
;	../../com/onewire.c:23: presence=1;
	setb	b0
;	../../com/onewire.c:24: OWDATA=0;
	clr	_P0_7
;	../../com/onewire.c:25: owdelay(2500);
	mov	dptr,#0x09C4
	push	bits
	lcall	_owdelay
	pop	bits
;	../../com/onewire.c:26: OWDATA=1;
	setb	_P0_7
;	../../com/onewire.c:27: for (n=0;n<255;n++) presence=presence & OWDATA;
	mov	r2,#0xFF
00103$:
	mov	c,_P0_7
	anl	c,b0
	mov	b0,c
	djnz	r2,00103$
;	../../com/onewire.c:28: presence=!presence;
	cpl	b0
;	../../com/onewire.c:29: return (presence);
	mov	c,b0
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ow_write'
;------------------------------------------------------------
;owbyte                    Allocated to registers r2 
;n                         Allocated to registers r3 
;m                         Allocated to registers r4 
;------------------------------------------------------------
;	../../com/onewire.c:32: void ow_write(unsigned char owbyte)	// Byte an one-wire Gerät senden
;	-----------------------------------------
;	 function ow_write
;	-----------------------------------------
_ow_write:
	mov	r2,dpl
;	../../com/onewire.c:37: for (n=1;n!=0;n=n<<1)		// LSB first
	mov	r3,#0x01
00108$:
	cjne	r3,#0x00,00120$
	ret
00120$:
;	../../com/onewire.c:40: if (owbyte & n)
	mov	a,r3
	anl	a,r2
	jz	00102$
;	../../com/onewire.c:42: for (m=0;m<2;m++) OWDATA=0;	// 1-Bit: 5µs auf low dann auf high und 85µs warten
	mov	r4,#0x00
00104$:
	cjne	r4,#0x02,00122$
00122$:
	jnc	00107$
	clr	_P0_7
	inc	r4
	sjmp	00104$
00107$:
;	../../com/onewire.c:43: OWDATA=1;
	setb	_P0_7
;	../../com/onewire.c:44: owdelay(260);
	mov	dptr,#0x0104
	push	ar2
	push	ar3
	lcall	_owdelay
	pop	ar3
	pop	ar2
	sjmp	00110$
00102$:
;	../../com/onewire.c:48: OWDATA=0;			// 0-Bit: 90µs auf low dann auf high
	clr	_P0_7
;	../../com/onewire.c:49: owdelay(275);
	mov	dptr,#0x0113
	push	ar2
	push	ar3
	lcall	_owdelay
	pop	ar3
	pop	ar2
;	../../com/onewire.c:50: OWDATA=1;
	setb	_P0_7
00110$:
;	../../com/onewire.c:37: for (n=1;n!=0;n=n<<1)		// LSB first
	mov	a,r3
	add	a,r3
	mov	r3,a
	sjmp	00108$
;------------------------------------------------------------
;Allocation info for local variables in function 'ow_read'
;------------------------------------------------------------
;n                         Allocated to registers r3 
;m                         Allocated to registers r4 
;d                         Allocated to registers r2 
;------------------------------------------------------------
;	../../com/onewire.c:56: unsigned char ow_read(void)			// Byte von one-wire Gerät lesen
;	-----------------------------------------
;	 function ow_read
;	-----------------------------------------
_ow_read:
;	../../com/onewire.c:60: d=0;
	mov	r2,#0x00
;	../../com/onewire.c:62: for (n=1;n!=0;n=n<<1)
	mov	r3,#0x01
00107$:
	cjne	r3,#0x00,00119$
	sjmp	00110$
00119$:
;	../../com/onewire.c:64: for (m=0;m<2;m++) OWDATA=0;
	mov	r4,#0x00
00103$:
	cjne	r4,#0x02,00120$
00120$:
	jnc	00106$
	clr	_P0_7
	inc	r4
	sjmp	00103$
00106$:
;	../../com/onewire.c:65: OWDATA=1;
	setb	_P0_7
;	../../com/onewire.c:66: owdelay(1);
	mov	dptr,#0x0001
	push	ar2
	push	ar3
	lcall	_owdelay
	pop	ar3
	pop	ar2
;	../../com/onewire.c:68: if (OWDATA) d|=n;
	jnb	_P0_7,00102$
	mov	a,r3
	orl	ar2,a
00102$:
;	../../com/onewire.c:69: owdelay(140);
	mov	dptr,#0x008C
	push	ar2
	push	ar3
	lcall	_owdelay
	pop	ar3
	pop	ar2
;	../../com/onewire.c:62: for (n=1;n!=0;n=n<<1)
	mov	a,r3
	add	a,r3
	mov	r3,a
	sjmp	00107$
00110$:
;	../../com/onewire.c:72: return(d);
	mov	dpl,r2
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ow_read_bit'
;------------------------------------------------------------
;m                         Allocated to registers r2 
;b                         Allocated to registers b0 
;------------------------------------------------------------
;	../../com/onewire.c:77: bit ow_read_bit(void)				// Bit von one-wire Datenleitung einlesen
;	-----------------------------------------
;	 function ow_read_bit
;	-----------------------------------------
_ow_read_bit:
;	../../com/onewire.c:82: for (m=0;m<2;m++) OWDATA=0;
	mov	r2,#0x00
00101$:
	cjne	r2,#0x02,00110$
00110$:
	jnc	00104$
	clr	_P0_7
	inc	r2
	sjmp	00101$
00104$:
;	../../com/onewire.c:83: OWDATA=1;
	setb	_P0_7
;	../../com/onewire.c:84: owdelay(1);
	mov	dptr,#0x0001
	lcall	_owdelay
;	../../com/onewire.c:85: b=OWDATA;
	mov	c,_P0_7
	mov	b0,c
;	../../com/onewire.c:86: owdelay (140);
	mov	dptr,#0x008C
	push	bits
	lcall	_owdelay
	pop	bits
;	../../com/onewire.c:87: return (b);
	mov	c,b0
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'start_tempconversion'
;------------------------------------------------------------
;------------------------------------------------------------
;	../../com/onewire.c:91: void start_tempconversion(void)		// Temperaturmessung starten
;	-----------------------------------------
;	 function start_tempconversion
;	-----------------------------------------
_start_tempconversion:
;	../../com/onewire.c:93: if (ow_init()) {
	lcall	_ow_init
	jnc	00103$
;	../../com/onewire.c:95: ow_write(0xCC);			// Skip-ROM command: alle parallel angeschlossenen Geräte werden angesprochen
	mov	dpl,#0xCC
	lcall	_ow_write
;	../../com/onewire.c:96: ow_write(0x44);			// start single temperature conversion command
	mov	dpl,#0x44
	ljmp	_ow_write
00103$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_temp'
;------------------------------------------------------------
;lsb                       Allocated to registers r2 
;msb                       Allocated to registers r3 
;t                         Allocated to registers r5 r6 
;t2                        Allocated to registers r3 r2 
;sign                      Allocated to registers r4 
;------------------------------------------------------------
;	../../com/onewire.c:100: signed int read_temp(void)					// Temperatur einlesen
;	-----------------------------------------
;	 function read_temp
;	-----------------------------------------
_read_temp:
;	../../com/onewire.c:112: if (ow_init()) {
	lcall	_ow_init
	jnc	00106$
;	../../com/onewire.c:113: ow_write(0xCC);			// Skip-ROM command: alle parallel angeschlossenen Geräte werden angesprochen
	mov	dpl,#0xCC
	lcall	_ow_write
;	../../com/onewire.c:114: ow_write(0xBE);			// read scratchpad command: Speicher einlesen
	mov	dpl,#0xBE
	lcall	_ow_write
;	../../com/onewire.c:115: lsb=ow_read();			// LSB von Temperaturwert
	lcall	_ow_read
	mov	r2,dpl
;	../../com/onewire.c:116: msb=ow_read();			// MSB von Temperaturwert
	push	ar2
	lcall	_ow_read
	mov	r3,dpl
	pop	ar2
;	../../com/onewire.c:134: sign=msb&0x80;
	mov	a,#0x80
	anl	a,r3
	mov	r4,a
;	../../com/onewire.c:135: t2=msb*256+lsb;
	mov	ar5,r3
	clr	a
	mov	r3,a
	mov	r6,a
	mov	a,r2
	add	a,r3
	mov	r3,a
	mov	a,r6
	addc	a,r5
	mov	r5,a
	mov	r2,a
;	../../com/onewire.c:136: if (sign) t2=(0xFFFF-t2)+1;
	mov	a,r4
	jz	00102$
	clr	c
	clr	a
	subb	a,r3
	mov	r3,a
	clr	a
	subb	a,r2
	mov	r2,a
00102$:
;	../../com/onewire.c:140: t=t2*6;
	push	ar2
	push	ar3
	push	ar4
	push	ar3
	push	ar2
	mov	dptr,#0x0006
	lcall	__mulint
	mov	r5,dpl
	mov	r6,dph
	dec	sp
	dec	sp
	pop	ar4
	pop	ar3
	pop	ar2
;	../../com/onewire.c:141: t2=t2>>2;
	mov	a,r2
	clr	c
	rrc	a
	xch	a,r3
	rrc	a
	xch	a,r3
	clr	c
	rrc	a
	xch	a,r3
	rrc	a
	xch	a,r3
	mov	r2,a
;	../../com/onewire.c:142: t=t+t2;					// hier ist t die Teperatur in 0,01°C
	mov	a,r3
	add	a,r5
	mov	r5,a
	mov	a,r2
	addc	a,r6
	mov	r6,a
;	../../com/onewire.c:149: if (sign) t=-t;		// Vorzeichen
	mov	a,r4
	jz	00107$
	clr	c
	clr	a
	subb	a,r5
	mov	r5,a
	clr	a
	subb	a,r6
	mov	r6,a
	sjmp	00107$
00106$:
;	../../com/onewire.c:152: else t=0xFFFF;				// im Fehlerfall 0xFFFF zurückmelden
	mov	r5,#0xFF
	mov	r6,#0xFF
00107$:
;	../../com/onewire.c:153: return (t);
	mov	dpl,r5
	mov	dph,r6
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'owdelay'
;------------------------------------------------------------
;deltime                   Allocated to registers r2 r3 
;------------------------------------------------------------
;	../../com/onewire.c:157: void owdelay(int deltime)			// Warten, deltime = Anzahl Takte / 2 (Timer wird mit CCLK/2 betrieben) 
;	-----------------------------------------
;	 function owdelay
;	-----------------------------------------
_owdelay:
	mov	r2,dpl
	mov	r3,dph
;	../../com/onewire.c:160: TR0=0;					// Timer 0 anhalten
	clr	_TCON_4
;	../../com/onewire.c:161: deltime=0xFFFF-deltime;
	mov	a,#0xFF
	clr	c
	subb	a,r2
	mov	r2,a
	mov	a,#0xFF
	subb	a,r3
	mov	r3,a
;	../../com/onewire.c:162: TH0=deltime>>8;			// Timer 0 setzen 
	mov	_TH0,r3
;	../../com/onewire.c:163: TL0=deltime;	
	mov	_TL0,r2
;	../../com/onewire.c:164: TF0=0;
	clr	_TCON_5
;	../../com/onewire.c:165: TR0=1;
	setb	_TCON_4
;	../../com/onewire.c:166: while(!TF0);				// warten auf Timer 0
00101$:
	jnb	_TCON_5,00101$
;	../../com/onewire.c:167: TR0=0;		
	clr	_TCON_4
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
