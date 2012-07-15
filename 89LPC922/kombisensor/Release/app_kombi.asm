;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
; This file was generated Sun Jul 15 18:49:21 2012
;--------------------------------------------------------
	.module app_kombi
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _ctrl_adr
	.globl _luxdelay
	.globl _hystable
	.globl _luxtable
	.globl _cycleval
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
	.globl _resend
	.globl _lockatt
	.globl _sequence
	.globl _dimmwert
	.globl _underrun
	.globl _overrun
	.globl _delrec
	.globl _global_object_value_3_to_10
	.globl _global_object_value_0_to_1
	.globl _schwelle
	.globl _read_obj_value
	.globl _write_obj_value
	.globl _read_value_req
	.globl _write_value_req
	.globl _delay_timer
	.globl _restart_app
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
_global_object_value_0_to_1::
	.ds 4
_global_object_value_3_to_10::
	.ds 1
_delrec::
	.ds 36
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area OSEG    (OVR,DATA)
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
_overrun::
	.ds 1
_underrun::
	.ds 1
_dimmwert::
	.ds 1
_sequence::
	.ds 1
_lockatt::
	.ds 1
_resend::
	.ds 1
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
;Allocation info for local variables in function 'schwelle'
;------------------------------------------------------------
;objno                     Allocated to registers r2 
;ctrl                      Allocated to stack - offset 1
;bitmask                   Allocated to registers r5 
;temp_compare              Allocated to registers r7 
;lux_compare               Allocated to registers r6 
;lastdimm                  Allocated to registers r2 
;step                      Allocated to registers r3 
;value                     Allocated to registers r6 
;offset                    Allocated to registers r5 
;over                      Allocated to registers b0 
;under                     Allocated to registers b1 
;valid                     Allocated to registers b2 
;active                    Allocated to stack - offset 2
;schwellwert               Allocated to stack - offset 3
;schwellwert_temp          Allocated to registers r6 r7 
;hysterese                 Allocated to stack - offset 5
;delay                     Allocated to registers r3 r4 
;sloc0                     Allocated to stack - offset 22
;------------------------------------------------------------
;	../app_kombi.c:52: void schwelle(unsigned char objno)		// Luxschwelle prüfen und reagieren
;	-----------------------------------------
;	 function schwelle
;	-----------------------------------------
_schwelle:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x06
	mov	sp,a
	mov	r2,dpl
;	../app_kombi.c:57: __bit over=0, under=0, valid;
	clr	b0
	clr	b1
;	../app_kombi.c:61: unsigned int hysterese=0, delay=0;
;	../app_kombi.c:64: offset=(objno-3)*5;
	clr	a
	mov	r3,a
	mov	r4,a
	mov	a,r2
	add	a,#0xfd
	mov	b,#0x05
	mul	ab
	mov	r5,a
;	../app_kombi.c:65: if (objno==9) offset++;        // da Verssatz in der Reihenfolge der Parameter
	cjne	r2,#0x09,00102$
	inc	r5
00102$:
;	../app_kombi.c:67: ctrl=eeprom[LUXCTRL-offset];
	mov	a,#0xF9
	clr	c
	subb	a,r5
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r6,a
	mov	r0,_bp
	inc	r0
	mov	@r0,ar6
;	../app_kombi.c:69: if ((eeprom[LUXPARAM]&0x80) && objno==3) {	// Helligkeitsregelung (nur Objekt1)
	mov	dptr,#(_eeprom + 0x00d3)
	clr	a
	movc	a,@a+dptr
	mov	r7,a
	jb	acc.7,00271$
	ljmp	00209$
00271$:
	cjne	r2,#0x03,00272$
	sjmp	00273$
00272$:
	ljmp	00209$
00273$:
;	../app_kombi.c:71: lastdimm=dimmwert;		// beim letzten Durchlauf errechneter Wert
	mov	r0,#_dimmwert
	mov	ar2,@r0
;	../app_kombi.c:72: schwellwert=eeprom[LUXSCHWELLWERT]*10;		// schwellwert ist hier der Sollwert
	mov	dptr,#(_eeprom + 0x00fb)
	clr	a
	movc	a,@a+dptr
	mov	r7,a
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	mov	a,r7
	mov	b,#0x0A
	mul	ab
	mov	@r0,a
	inc	r0
	mov	@r0,b
;	../app_kombi.c:74: hysterese=_divuint(schwellwert,hystable[ctrl&0x07]);
	mov	r0,_bp
	inc	r0
	mov	a,#0x07
	anl	a,@r0
	mov	dptr,#_hystable
	movc	a,@a+dptr
	mov	r6,a
	mov	r7,#0x00
	push	ar2
	push	ar6
	push	ar7
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	lcall	__divuint
	mov	r6,dpl
	mov	r7,dph
	dec	sp
	dec	sp
	pop	ar2
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,ar6
	inc	r0
	mov	@r0,ar7
;	../app_kombi.c:75: if (hysterese==0) hysterese=1;	// mindestens jedoch 1 Lux
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00104$
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,#0x01
	clr	a
	inc	r0
	mov	@r0,a
00104$:
;	../app_kombi.c:76: step=(((ctrl & 0xF0) >> 4) + 1) * 16;
	mov	r0,_bp
	inc	r0
	mov	a,#0xF0
	anl	a,@r0
	swap	a
	anl	a,#0x0f
	mov	r6,a
	inc	r6
	mov	a,r6
	swap	a
	anl	a,#0xf0
	mov	r3,a
;	../app_kombi.c:78: if (lux>schwellwert) {	// wenn überschritten
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	clr	c
	mov	a,@r0
	subb	a,_lux
	inc	r0
	mov	a,@r0
	subb	a,(_lux + 1)
	jnc	00113$
;	../app_kombi.c:79: if ((lux > (schwellwert*2)) && (dimmwert >= step)) dimmwert-=step;	// grosse Schritte wenn weit weg von Sollwert
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	a,@r0
	xch	a,r6
	add	a,acc
	xch	a,r6
	rlc	a
	mov	r7,a
	clr	c
	mov	a,r6
	subb	a,_lux
	mov	a,r7
	subb	a,(_lux + 1)
	jnc	00109$
	mov	r0,#_dimmwert
	clr	c
	mov	a,@r0
	subb	a,r3
	jc	00109$
	mov	r0,#_dimmwert
	mov	a,@r0
	clr	c
	subb	a,r3
	mov	@r0,a
	sjmp	00113$
00109$:
;	../app_kombi.c:81: if (dimmwert>3) dimmwert-=4;		// kleine Schritte
	mov	r0,#_dimmwert
	mov	a,@r0
	add	a,#0xff - 0x03
	jnc	00106$
	mov	r0,#_dimmwert
	dec	@r0
	dec	@r0
	dec	@r0
	dec	@r0
	sjmp	00113$
00106$:
;	../app_kombi.c:82: else dimmwert=0;
	mov	r0,#_dimmwert
	mov	@r0,#0x00
00113$:
;	../app_kombi.c:85: if (lux<(schwellwert-hysterese)) {		// wenn unterschritten
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	mov	a,_bp
	add	a,#0x05
	mov	r1,a
	mov	a,@r0
	clr	c
	subb	a,@r1
	mov	r6,a
	inc	r0
	mov	a,@r0
	inc	r1
	subb	a,@r1
	mov	r7,a
	clr	c
	mov	a,_lux
	subb	a,r6
	mov	a,(_lux + 1)
	subb	a,r7
	jnc	00122$
;	../app_kombi.c:86: if (((lux*2) < (schwellwert-hysterese)) && (dimmwert <= (255 - step))) dimmwert+=step;	// grosse Schritte wenn weit weg von Sollwert
	mov	a,_lux
	add	a,_lux
	mov	r4,a
	mov	a,(_lux + 1)
	rlc	a
	mov	r5,a
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	mov	a,_bp
	add	a,#0x05
	mov	r1,a
	mov	a,@r0
	clr	c
	subb	a,@r1
	mov	r6,a
	inc	r0
	mov	a,@r0
	inc	r1
	subb	a,@r1
	mov	r7,a
	clr	c
	mov	a,r4
	subb	a,r6
	mov	a,r5
	subb	a,r7
	jnc	00118$
	mov	ar6,r3
	mov	r7,#0x00
	mov	a,#0xFF
	clr	c
	subb	a,r6
	mov	r4,a
	clr	a
	subb	a,r7
	mov	r5,a
	mov	r0,#_dimmwert
	mov	ar6,@r0
	mov	r7,#0x00
	clr	c
	mov	a,r4
	subb	a,r6
	mov	a,r5
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jc	00118$
	mov	r0,#_dimmwert
	mov	a,r3
	add	a,@r0
	mov	@r0,a
	sjmp	00122$
00118$:
;	../app_kombi.c:88: if (dimmwert<252) dimmwert+=4;
	mov	r0,#_dimmwert
	cjne	@r0,#0xFC,00282$
00282$:
	jnc	00115$
	mov	r0,#_dimmwert
	mov	a,@r0
	add	a,#0x04
	mov	@r0,a
	sjmp	00122$
00115$:
;	../app_kombi.c:89: else dimmwert=255;
	mov	r0,#_dimmwert
	mov	@r0,#0xFF
00122$:
;	../app_kombi.c:92: if (lastdimm != dimmwert) {
	mov	r0,#_dimmwert
	mov	a,@r0
	cjne	a,ar2,00284$
	ljmp	00212$
00284$:
;	../app_kombi.c:93: WRITE_DELAY_RECORD(2,1,dimmwert,timer+1)
	mov	(_delrec + 0x0008),#0x01
	mov	r0,#_dimmwert
	mov	(_delrec + 0x0009),@r0
	mov	a,#0x01
	add	a,_timer
	mov	r6,a
	clr	a
	addc	a,(_timer + 1)
	mov	r7,a
	mov	(_delrec + 0x000a),r6
	mov	((_delrec + 0x000a) + 1),r7
	ljmp	00212$
00209$:
;	../app_kombi.c:99: if (objno<6) {	// Helligkeitsschwellen
	cjne	r2,#0x06,00285$
00285$:
	jc	00286$
	ljmp	00181$
00286$:
;	../app_kombi.c:100: schwellwert=luxtable[eeprom[LUXSCHWELLWERT-offset]-7];	// -7, weil luxtable erst ab 7 beginnt
	mov	a,#0xFB
	clr	c
	subb	a,r5
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	add	a,#0xf9
	add	a,acc
	mov	r6,a
	mov	dptr,#_luxtable
	movc	a,@a+dptr
	xch	a,r6
	inc	dptr
	movc	a,@a+dptr
	mov	r7,a
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	mov	@r0,ar6
	inc	r0
	mov	@r0,ar7
;	../app_kombi.c:102: hysterese=_divuint(schwellwert,hystable[ctrl&0x07]);
	mov	r0,_bp
	inc	r0
	mov	a,#0x07
	anl	a,@r0
	mov	dptr,#_hystable
	movc	a,@a+dptr
	mov	r6,a
	mov	r7,#0x00
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	bits
	push	ar6
	push	ar7
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	lcall	__divuint
	mov	r6,dpl
	mov	r7,dph
	dec	sp
	dec	sp
	pop	bits
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,ar6
	inc	r0
	mov	@r0,ar7
;	../app_kombi.c:104: if (hysterese==0) hysterese=1;	// mindestens jedoch 1 Lux
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00126$
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,#0x01
	clr	a
	inc	r0
	mov	@r0,a
00126$:
;	../app_kombi.c:105: if (lux>schwellwert) {
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	clr	c
	mov	a,@r0
	subb	a,_lux
	inc	r0
	mov	a,@r0
	subb	a,(_lux + 1)
	jnc	00128$
;	../app_kombi.c:106: over=1;
	setb	b0
;	../app_kombi.c:107: delay=luxdelay[(eeprom[LUXCYCLE1-offset] & 0xF0) >> 4];	// Verzögerung bei überschreiten
	mov	a,#0xFA
	clr	c
	subb	a,r5
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	anl	a,#0xF0
	swap	a
	anl	a,#0x0f
	add	a,acc
	mov	r6,a
	mov	dptr,#_luxdelay
	movc	a,@a+dptr
	xch	a,r6
	inc	dptr
	movc	a,@a+dptr
	mov	r7,a
	mov	ar3,r6
	mov	ar4,r7
00128$:
;	../app_kombi.c:109: if (lux<(schwellwert-hysterese)) under=1;
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	mov	a,_bp
	add	a,#0x05
	mov	r1,a
	mov	a,@r0
	clr	c
	subb	a,@r1
	mov	r6,a
	inc	r0
	mov	a,@r0
	inc	r1
	subb	a,@r1
	mov	r7,a
	clr	c
	mov	a,_lux
	subb	a,r6
	mov	a,(_lux + 1)
	subb	a,r7
	jnc	00130$
	setb	b1
00130$:
;	../app_kombi.c:110: switch (objno) {
	cjne	r2,#0x03,00290$
	sjmp	00131$
00290$:
	cjne	r2,#0x04,00291$
	sjmp	00137$
00291$:
	cjne	r2,#0x05,00292$
	sjmp	00140$
00292$:
	ljmp	00182$
;	../app_kombi.c:111: case 3:
00131$:
;	../app_kombi.c:112: if ((eeprom[LUXPARAM]&0x80) == 0) {
	mov	dptr,#(_eeprom + 0x00d3)
	clr	a
	movc	a,@a+dptr
	mov	r6,a
	jb	acc.7,00135$
;	../app_kombi.c:113: if (under) delay=luxdelay[(eeprom[0xCD] & 0xF0) >> 4];
	jb	b1,00294$
	ljmp	00182$
00294$:
	mov	dptr,#(_eeprom + 0x00cd)
	clr	a
	movc	a,@a+dptr
	anl	a,#0xF0
	swap	a
	anl	a,#0x0f
	add	a,acc
	mov	r6,a
	mov	dptr,#_luxdelay
	movc	a,@a+dptr
	xch	a,r6
	inc	dptr
	movc	a,@a+dptr
	mov	r7,a
	mov	ar3,r6
	mov	ar4,r7
	ljmp	00182$
00135$:
;	../app_kombi.c:115: else delay=0;	// bei Helligkeitsregelung keine Verzögerung
	mov	r3,#0x00
	mov	r4,#0x00
;	../app_kombi.c:116: break;
	ljmp	00182$
;	../app_kombi.c:117: case 4:
00137$:
;	../app_kombi.c:118: if (under) delay=luxdelay[eeprom[0xCD] & 0x0F];
	jb	b1,00295$
	ljmp	00182$
00295$:
	mov	dptr,#(_eeprom + 0x00cd)
	clr	a
	movc	a,@a+dptr
	anl	a,#0x0F
	add	a,acc
	mov	r6,a
	mov	dptr,#_luxdelay
	movc	a,@a+dptr
	xch	a,r6
	inc	dptr
	movc	a,@a+dptr
	mov	r7,a
	mov	ar3,r6
	mov	ar4,r7
;	../app_kombi.c:119: break;
	ljmp	00182$
;	../app_kombi.c:120: case 5:
00140$:
;	../app_kombi.c:121: if (under) delay=luxdelay[(eeprom[0xCC] & 0xF0) >> 4];
	jb	b1,00296$
	ljmp	00182$
00296$:
	mov	dptr,#(_eeprom + 0x00cc)
	clr	a
	movc	a,@a+dptr
	anl	a,#0xF0
	swap	a
	anl	a,#0x0f
	add	a,acc
	mov	r6,a
	mov	dptr,#_luxdelay
	movc	a,@a+dptr
	xch	a,r6
	inc	dptr
	movc	a,@a+dptr
	mov	r7,a
	mov	ar3,r6
	mov	ar4,r7
;	../app_kombi.c:123: }
	ljmp	00182$
00181$:
;	../app_kombi.c:127: if (objno<8) {	// Temperaturschwellen
	cjne	r2,#0x08,00297$
00297$:
	jc	00298$
	ljmp	00178$
00298$:
;	../app_kombi.c:128: schwellwert_temp=(signed char)eeprom[LUXSCHWELLWERT-offset];
	push	ar3
	push	ar4
	mov	a,#0xFB
	clr	c
	subb	a,r5
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r6,a
	rlc	a
	subb	a,acc
	mov	r7,a
;	../app_kombi.c:129: hysterese = ctrl & 0x07;
	mov	r0,_bp
	inc	r0
	mov	a,#0x07
	anl	a,@r0
	mov	r3,a
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,ar3
	inc	r0
	mov	@r0,#0x00
;	../app_kombi.c:131: if (schwellwert_temp<51) {	//>51 : Temperaturschwelle inaktiv
	clr	c
	mov	a,r6
	subb	a,#0x33
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	pop	ar4
	pop	ar3
	jc	00299$
	ljmp	00182$
00299$:
;	../app_kombi.c:132: if (temp > (schwellwert_temp* (signed int)100)) over=1;
	push	ar6
	push	ar7
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	bits
	push	ar6
	push	ar7
	mov	dptr,#0x0064
	lcall	__mulint
	mov	r6,dpl
	mov	r7,dph
	dec	sp
	dec	sp
	pop	bits
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
	clr	c
	mov	a,r6
	subb	a,_temp
	mov	a,r7
	xrl	a,#0x80
	mov	b,(_temp + 1)
	xrl	b,#0x80
	subb	a,b
	pop	ar7
	pop	ar6
	jnc	00145$
	setb	b0
00145$:
;	../app_kombi.c:133: if (temp < ((schwellwert_temp - (signed int)hysterese)*(signed int)100)) under=1;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,r6
	clr	c
	subb	a,@r0
	mov	r6,a
	mov	a,r7
	inc	r0
	subb	a,@r0
	mov	r7,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	bits
	push	ar6
	push	ar7
	mov	dptr,#0x0064
	lcall	__mulint
	mov	r6,dpl
	mov	r7,dph
	dec	sp
	dec	sp
	pop	bits
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
	clr	c
	mov	a,_temp
	subb	a,r6
	mov	a,(_temp + 1)
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jc	00301$
	ljmp	00182$
00301$:
	setb	b1
	ljmp	00182$
00178$:
;	../app_kombi.c:138: lux_compare = eeprom[0xF8-offset] & 0xF0;
	mov	a,#0xF8
	clr	c
	subb	a,r5
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r6,a
	anl	ar6,#0xF0
;	../app_kombi.c:139: temp_compare = eeprom[ctrl_adr[objno]+1] & 0x70;
	mov	a,r2
	mov	dptr,#_ctrl_adr
	movc	a,@a+dptr
	inc	a
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r7,a
	anl	ar7,#0x70
;	../app_kombi.c:142: over=1;
	setb	b0
;	../app_kombi.c:143: switch (temp_compare) {
	cjne	r7,#0x10,00302$
	sjmp	00150$
00302$:
	cjne	r7,#0x20,00303$
	sjmp	00151$
00303$:
	cjne	r7,#0x30,00304$
	sjmp	00152$
00304$:
;	../app_kombi.c:144: case 0x10:		// 1 = größer als Temperaturschwelle 1
	cjne	r7,#0x40,00154$
	sjmp	00153$
00150$:
;	../app_kombi.c:145: over = (overrun & 0x08);
	mov	r0,#_overrun
	mov	a,@r0
	mov	c,acc[3]
	mov	b0,c
;	../app_kombi.c:146: break;
;	../app_kombi.c:147: case 0x20:		// 2 = größer als Temperaturschwelle 2
	sjmp	00154$
00151$:
;	../app_kombi.c:148: over = (overrun & 0x10);
	mov	r0,#_overrun
	mov	a,@r0
	mov	c,acc[4]
	mov	b0,c
;	../app_kombi.c:149: break;
;	../app_kombi.c:150: case 0x30:		// 3 = kleiner als Temperaturschwelle 1
	sjmp	00154$
00152$:
;	../app_kombi.c:151: over = (underrun & 0x08);
	mov	r0,#_underrun
	mov	a,@r0
	mov	c,acc[3]
	mov	b0,c
;	../app_kombi.c:152: break;
;	../app_kombi.c:153: case 0x40:		// 4 = kleiner als Temperaturschwelle 2
	sjmp	00154$
00153$:
;	../app_kombi.c:154: over = (underrun & 0x10);
	mov	r0,#_underrun
	mov	a,@r0
	mov	c,acc[4]
	mov	b0,c
;	../app_kombi.c:156: }
00154$:
;	../app_kombi.c:158: valid=1;
	setb	b2
;	../app_kombi.c:159: switch (lux_compare) {
	cjne	r6,#0x10,00306$
	sjmp	00155$
00306$:
	cjne	r6,#0x20,00307$
	sjmp	00158$
00307$:
	cjne	r6,#0x30,00308$
	sjmp	00161$
00308$:
	cjne	r6,#0x40,00309$
	sjmp	00164$
00309$:
	cjne	r6,#0x50,00310$
	ljmp	00167$
00310$:
	cjne	r6,#0x60,00311$
	ljmp	00170$
00311$:
	ljmp	00173$
;	../app_kombi.c:160: case 0x10:		// 1 = größer als Helligkeitsschwelle 1
00155$:
;	../app_kombi.c:161: if(delrec[2].delayactive & 0x04) valid=0;	// wenn Verzögerung der Helligkeitsschwelle noch aktiv, dann noch nichts senden
	mov	a,(_delrec + 0x0008)
	jnb	acc.2,00157$
	clr	b2
00157$:
;	../app_kombi.c:162: over &= (overrun & 0x01);
	mov	r0,#_overrun
	mov	a,@r0
	anl	a,#0x01
	mov	r6,a
	mov	c,b0
	clr	a
	rlc	a
	mov	r7,a
	setb	c
	mov	a,r6
	anl	a,r7
	jnz	00313$
	clr	c
00313$:
	mov  b3,c
	mov	b0,c
;	../app_kombi.c:163: break;
	ljmp	00173$
;	../app_kombi.c:164: case 0x20:		// 2 = größer als Helligkeitsschwelle 2
00158$:
;	../app_kombi.c:165: if(delrec[3].delayactive & 0x04) valid=0;
	mov	a,(_delrec + 0x000c)
	jnb	acc.2,00160$
	clr	b2
00160$:
;	../app_kombi.c:166: over &= (overrun & 0x02);
	mov	r0,#_overrun
	mov	a,@r0
	rr	a
	anl	a,#0x01
	mov	r6,a
	mov	c,b0
	clr	a
	rlc	a
	mov	r7,a
	setb	c
	mov	a,r6
	anl	a,r7
	jnz	00315$
	clr	c
00315$:
	mov  b3,c
	mov	b0,c
;	../app_kombi.c:167: break;
;	../app_kombi.c:168: case 0x30:		// 3 = größer als Helligkeitsschwelle 3
	sjmp	00173$
00161$:
;	../app_kombi.c:169: if(delrec[4].delayactive & 0x04) valid=0;
	mov	a,(_delrec + 0x0010)
	jnb	acc.2,00163$
	clr	b2
00163$:
;	../app_kombi.c:170: over &= (overrun & 0x04);
	mov	r0,#_overrun
	mov	a,@r0
	rr	a
	rr	a
	anl	a,#0x01
	mov	r6,a
	mov	c,b0
	clr	a
	rlc	a
	mov	r7,a
	setb	c
	mov	a,r6
	anl	a,r7
	jnz	00317$
	clr	c
00317$:
	mov  b3,c
	mov	b0,c
;	../app_kombi.c:171: break;
;	../app_kombi.c:172: case 0x40:		// 4 = kleiner als Helligkeitsschwelle 1
	sjmp	00173$
00164$:
;	../app_kombi.c:173: if(delrec[2].delayactive & 0x04) valid=0;
	mov	a,(_delrec + 0x0008)
	jnb	acc.2,00166$
	clr	b2
00166$:
;	../app_kombi.c:174: over &= (underrun & 0x01);
	mov	r0,#_underrun
	mov	a,@r0
	anl	a,#0x01
	mov	r6,a
	mov	c,b0
	clr	a
	rlc	a
	mov	r7,a
	setb	c
	mov	a,r6
	anl	a,r7
	jnz	00319$
	clr	c
00319$:
	mov  b3,c
	mov	b0,c
;	../app_kombi.c:175: break;
;	../app_kombi.c:176: case 0x50:		// 5 = kleiner als Helligkeitsschwelle 2
	sjmp	00173$
00167$:
;	../app_kombi.c:177: if(delrec[3].delayactive & 0x04) valid=0;
	mov	a,(_delrec + 0x000c)
	jnb	acc.2,00169$
	clr	b2
00169$:
;	../app_kombi.c:178: over &= (underrun & 0x02);
	mov	r0,#_underrun
	mov	a,@r0
	rr	a
	anl	a,#0x01
	mov	r6,a
	mov	c,b0
	clr	a
	rlc	a
	mov	r7,a
	setb	c
	mov	a,r6
	anl	a,r7
	jnz	00321$
	clr	c
00321$:
	mov  b3,c
	mov	b0,c
;	../app_kombi.c:179: break;
;	../app_kombi.c:180: case 0x60:		// 6 = kleiner als Helligkeitsschwelle 3
	sjmp	00173$
00170$:
;	../app_kombi.c:181: if(delrec[4].delayactive & 0x04) valid=0;
	mov	a,(_delrec + 0x0010)
	jnb	acc.2,00172$
	clr	b2
00172$:
;	../app_kombi.c:182: over &= (underrun & 0x04);
	mov	r0,#_underrun
	mov	a,@r0
	rr	a
	rr	a
	anl	a,#0x01
	mov	r6,a
	mov	c,b0
	clr	a
	rlc	a
	mov	r7,a
	setb	c
	mov	a,r6
	anl	a,r7
	jnz	00323$
	clr	c
00323$:
	mov  b3,c
	mov	b0,c
;	../app_kombi.c:184: }
00173$:
;	../app_kombi.c:185: if(valid) under = !over;
	jnb	b2,00175$
	mov	c,b0
	cpl	c
	mov  b2,c
	mov	b1,c
	sjmp	00182$
00175$:
;	../app_kombi.c:187: over = 0;
	clr	b0
;	../app_kombi.c:188: under = 0;
	clr	b1
00182$:
;	../app_kombi.c:194: if (objno>=8) offset++;				// da Verssatz in der Reihenfolge der Parameter
	cjne	r2,#0x08,00325$
00325$:
	jc	00184$
	inc	r5
00184$:
;	../app_kombi.c:195: if (over) value = eeprom[LUX_OVER-offset];		// zu sendender Wert bei überschreiten
	jnb	b0,00186$
	mov	a,#0xF8
	clr	c
	subb	a,r5
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r6,a
	sjmp	00187$
00186$:
;	../app_kombi.c:196: else value = eeprom[LUX_UNDER-offset];		// zu sendender Wert bei unterschreiten
	mov	a,#0xF7
	clr	c
	subb	a,r5
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r5,a
	mov	r6,a
00187$:
;	../app_kombi.c:197: bitmask=1<<(objno-3);				// Bitmaske für underrun und overrun
	mov	a,r2
	add	a,#0xfd
	mov	r5,a
	mov	b,r5
	inc	b
	mov	a,#0x01
	sjmp	00330$
00328$:
	add	a,acc
00330$:
	djnz	b,00328$
	mov	r5,a
;	../app_kombi.c:198: active=0;
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,#0x00
;	../app_kombi.c:200: if (over) {					// wenn überschritten
	jnb	b0,00197$
;	../app_kombi.c:201: if (!(overrun&bitmask)) { 	// wenn neu überschritten
	mov	r0,#_overrun
	mov	a,r5
	anl	a,@r0
	jnz	00195$
;	../app_kombi.c:203: if (delay==0 || (resend&bitmask)) {		// // wenn keine Verzögerung oder Sperre aufgehoben wurde, sofort senden
	mov	a,r3
	orl	a,r4
	jz	00190$
	mov	r0,#_resend
	mov	a,r5
	anl	a,@r0
	jz	00191$
00190$:
;	../app_kombi.c:204: resend&=~bitmask;
	push	ar6
	mov	a,r5
	cpl	a
	mov	r0,#_resend
	anl	a,@r0
	mov	@r0,a
;	../app_kombi.c:205: active=3;	// Bit0=1=aktiv und Bit1=1=überschritten
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,#0x03
	pop	ar6
	sjmp	00192$
00191$:
;	../app_kombi.c:208: if(delrec[objno-1].delayactive!=5) {	// wenn bereits verzögertes unterschreiten läuft timer inaktiv setzen
	mov	a,r2
	dec	a
	add	a,acc
	add	a,acc
	add	a,#_delrec
	mov	r0,a
	mov	ar7,@r0
	cjne	r7,#0x05,00335$
	sjmp	00192$
00335$:
;	../app_kombi.c:209: active=7;	// Bit0=1=aktiv und Bit1=1=überschritten und Bit2=1=verzögert senden
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,#0x07
00192$:
;	../app_kombi.c:212: WRITE_DELAY_RECORD(objno-1,active,value,timer+delay+1);
	push	ar5
	mov	a,r2
	dec	a
	add	a,acc
	add	a,acc
	mov	r5,a
	add	a,#_delrec
	mov	r0,a
	mov	r1,_bp
	inc	r1
	inc	r1
	mov	a,@r1
	mov	@r0,a
	mov	a,r5
	add	a,#_delrec
	mov	r5,a
	inc	a
	mov	r0,a
	mov	@r0,ar6
	mov	a,#0x02
	add	a,r5
	mov	r0,a
	mov	a,r3
	add	a,_timer
	mov	r5,a
	mov	a,r4
	addc	a,(_timer + 1)
	mov	r7,a
	inc	r5
	cjne	r5,#0x00,00336$
	inc	r7
00336$:
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar7
;	../app_kombi.c:233: overrun&=~bitmask;	// Überschritten Bit löschen
	pop	ar5
;	../app_kombi.c:212: WRITE_DELAY_RECORD(objno-1,active,value,timer+delay+1);
00195$:
;	../app_kombi.c:214: overrun|=bitmask;		// Überschritten Bit setzen
	mov	r0,#_overrun
	mov	a,r5
	orl	a,@r0
	mov	@r0,a
;	../app_kombi.c:215: underrun&=~bitmask;		// Unterschritten Bit löschen
	mov	a,r5
	cpl	a
	mov	r7,a
	mov	r0,#_underrun
	anl	a,@r0
	mov	@r0,a
00197$:
;	../app_kombi.c:218: if (under) {										// wenn Wert unter Schwellwert
	jnb	b1,00212$
;	../app_kombi.c:219: if (!(underrun&bitmask)) { 						// wenn neu unterschritten
	mov	r0,#_underrun
	mov	a,r5
	anl	a,@r0
	jnz	00205$
;	../app_kombi.c:221: if (delay==0 || (resend&bitmask)) {	// wenn keine Verzögerung oder Sperre aufgehoben wurde, sofort senden
	mov	a,r3
	orl	a,r4
	jz	00200$
	mov	r0,#_resend
	mov	a,r5
	anl	a,@r0
	jz	00201$
00200$:
;	../app_kombi.c:222: resend&=~bitmask;
	mov	a,r5
	cpl	a
	mov	r7,a
	mov	r0,#_resend
	anl	a,@r0
	mov	@r0,a
;	../app_kombi.c:223: active=1;						// Bit0=1=aktiv und Bit1=0=unterschritten
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,#0x01
	sjmp	00202$
00201$:
;	../app_kombi.c:226: if(delrec[objno-1].delayactive!=7) {	// falls verzögertes überschritten Senden noch läuft stoppen
	mov	a,r2
	dec	a
	add	a,acc
	add	a,acc
	add	a,#_delrec
	mov	r0,a
	mov	ar7,@r0
	cjne	r7,#0x07,00341$
	sjmp	00202$
00341$:
;	../app_kombi.c:227: active=5;	// Bit0=1=aktiv und Bit1=0=unterschritten und Bit2=1=verzögert
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,#0x05
00202$:
;	../app_kombi.c:230: WRITE_DELAY_RECORD(objno-1,active,value,timer+delay+1);
	dec	r2
	mov	a,r2
	add	a,r2
	add	a,acc
	mov	r2,a
	add	a,#_delrec
	mov	r0,a
	mov	r1,_bp
	inc	r1
	inc	r1
	mov	a,@r1
	mov	@r0,a
	mov	a,r2
	add	a,#_delrec
	mov	r2,a
	inc	a
	mov	r0,a
	mov	@r0,ar6
	mov	a,#0x02
	add	a,r2
	mov	r0,a
	mov	a,r3
	add	a,_timer
	mov	r3,a
	mov	a,r4
	addc	a,(_timer + 1)
	mov	r4,a
	inc	r3
	cjne	r3,#0x00,00342$
	inc	r4
00342$:
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
00205$:
;	../app_kombi.c:232: underrun|=bitmask;	// Unterschritten Bit setzen
	mov	r0,#_underrun
	mov	a,r5
	orl	a,@r0
	mov	@r0,a
;	../app_kombi.c:233: overrun&=~bitmask;	// Überschritten Bit löschen
	mov	a,r5
	cpl	a
	mov	r5,a
	mov	r0,#_overrun
	anl	a,@r0
	mov	@r0,a
00212$:
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_obj_value'
;------------------------------------------------------------
;objno                     Allocated to registers r2 
;objvalue                  Allocated to registers r3 r4 
;------------------------------------------------------------
;	../app_kombi.c:241: unsigned long read_obj_value(unsigned char objno)
;	-----------------------------------------
;	 function read_obj_value
;	-----------------------------------------
_read_obj_value:
	mov	r2,dpl
;	../app_kombi.c:243: int objvalue=0;
	mov	r3,#0x00
	mov	r4,#0x00
;	../app_kombi.c:245: if (objno <= 1) {
	mov	a,r2
	add	a,#0xff - 0x01
	jc	00102$
;	../app_kombi.c:246: objvalue = global_object_value_0_to_1[objno];
	mov	a,r2
	add	a,r2
	add	a,#_global_object_value_0_to_1
	mov	r0,a
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	mov	ar3,r5
	mov	ar4,r6
00102$:
;	../app_kombi.c:248: if (objno >=3 && objno <= 10) {
	cjne	r2,#0x03,00116$
00116$:
	jc	00107$
	mov	a,r2
	add	a,#0xff - 0x0A
	jc	00107$
;	../app_kombi.c:249: if (global_object_value_3_to_10 & (1<<(objno-3))) objvalue=1; else objvalue=0;
	mov	r5,#0x00
	mov	a,r2
	add	a,#0xfd
	mov	r2,a
	mov	a,r5
	addc	a,#0xff
	mov	b,r2
	inc	b
	mov	r2,#0x01
	mov	r5,#0x00
	sjmp	00120$
00119$:
	mov	a,r2
	add	a,r2
	mov	r2,a
	mov	a,r5
	rlc	a
	mov	r5,a
00120$:
	djnz	b,00119$
	mov	r6,_global_object_value_3_to_10
	mov	r7,#0x00
	mov	a,r6
	anl	ar2,a
	mov	a,r7
	anl	ar5,a
	mov	a,r2
	orl	a,r5
	jz	00104$
	mov	r3,#0x01
	mov	r4,#0x00
	sjmp	00107$
00104$:
	mov	r3,#0x00
	mov	r4,#0x00
00107$:
;	../app_kombi.c:251: return(objvalue);
	mov	a,r4
	rlc	a
	subb	a,acc
	mov	r2,a
	mov	dpl,r3
	mov	dph,r4
	mov	b,r2
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'write_obj_value'
;------------------------------------------------------------
;objvalue                  Allocated to stack - offset -4
;objno                     Allocated to registers r2 
;bitpattern                Allocated to registers r3 
;------------------------------------------------------------
;	../app_kombi.c:255: void write_obj_value(unsigned char objno,int objvalue)
;	-----------------------------------------
;	 function write_obj_value
;	-----------------------------------------
_write_obj_value:
	push	_bp
	mov	_bp,sp
;	../app_kombi.c:259: bitpattern = 1<<(objno-3);
	mov	a,dpl
	mov	r2,a
	add	a,#0xfd
	mov	r3,a
	mov	b,r3
	inc	b
	mov	a,#0x01
	sjmp	00117$
00115$:
	add	a,acc
00117$:
	djnz	b,00115$
	mov	r3,a
;	../app_kombi.c:260: if (objno <= 1) {
	mov	a,r2
	add	a,#0xff - 0x01
	jc	00102$
;	../app_kombi.c:261: global_object_value_0_to_1[objno]=objvalue;
	mov	a,r2
	add	a,r2
	mov	r4,a
	add	a,#_global_object_value_0_to_1
	mov	r0,a
	mov	a,_bp
	add	a,#0xfc
	mov	r1,a
	mov	a,@r1
	mov	@r0,a
	inc	r0
	inc	r1
	mov	a,@r1
	mov	@r0,a
00102$:
;	../app_kombi.c:263: if (objno >=3 && objno <= 10) {
	cjne	r2,#0x03,00119$
00119$:
	jc	00109$
	mov	a,r2
	add	a,#0xff - 0x0A
	jc	00109$
;	../app_kombi.c:264: if (objvalue) global_object_value_3_to_10 |= bitpattern;
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00104$
	mov	a,r3
	orl	_global_object_value_3_to_10,a
	sjmp	00109$
00104$:
;	../app_kombi.c:265: else global_object_value_3_to_10 &= (0xFF - bitpattern);
	mov	a,#0xFF
	clr	c
	subb	a,r3
	anl	_global_object_value_3_to_10,a
00109$:
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_value_req'
;------------------------------------------------------------
;objno                     Allocated to registers r2 
;objflags                  Allocated to registers r3 
;------------------------------------------------------------
;	../app_kombi.c:272: void read_value_req(void)
;	-----------------------------------------
;	 function read_value_req
;	-----------------------------------------
_read_value_req:
;	../app_kombi.c:276: objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
	mov	dpl,(_telegramm + 0x0003)
	push	(_telegramm + 0x0004)
	lcall	_find_first_objno
	mov	r2,dpl
	dec	sp
;	../app_kombi.c:277: if(objno!=0xFF) {									// falls Gruppenadresse nicht gefunden
	cjne	r2,#0xFF,00109$
	ret
00109$:
;	../app_kombi.c:278: objflags=read_objflags(objno);					// Objekt Flags lesen
	mov	dpl,r2
	push	ar2
	lcall	_read_objflags
	mov	r3,dpl
	pop	ar2
;	../app_kombi.c:280: if((objflags&0x0C)==0x0C) send_obj_value(objno+0x40);
	anl	ar3,#0x0C
	cjne	r3,#0x0C,00105$
	mov	a,#0x40
	add	a,r2
	mov	dpl,a
	ljmp	_send_obj_value
00105$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'write_value_req'
;------------------------------------------------------------
;objno                     Allocated to registers r2 
;------------------------------------------------------------
;	../app_kombi.c:286: void write_value_req(void)
;	-----------------------------------------
;	 function write_value_req
;	-----------------------------------------
_write_value_req:
;	../app_kombi.c:290: objno=find_first_objno(telegramm[3],telegramm[4]);
	mov	dpl,(_telegramm + 0x0003)
	push	(_telegramm + 0x0004)
	lcall	_find_first_objno
	mov	r2,dpl
	dec	sp
;	../app_kombi.c:292: if (objno==10) {	// nur Sperrobjekt darf beschrieben werden
	cjne	r2,#0x0A,00108$
;	../app_kombi.c:294: if(telegramm[7]&0x01) global_object_value_3_to_10 |= 0x80;
	mov	a,(_telegramm + 0x0007)
	mov	r2,a
	jnb	acc.0,00102$
	orl	_global_object_value_3_to_10,#0x80
	sjmp	00103$
00102$:
;	../app_kombi.c:295: else global_object_value_3_to_10 &= 0x7F;
	anl	_global_object_value_3_to_10,#0x7F
00103$:
;	../app_kombi.c:298: if((telegramm[7]&0x01)==0) {
	mov	a,r2
	jb	acc.0,00108$
;	../app_kombi.c:299: overrun&=~lockatt;
	mov	r0,#_lockatt
	mov	a,@r0
	cpl	a
	mov	r2,a
	mov	r0,#_overrun
	anl	a,@r0
	mov	@r0,a
;	../app_kombi.c:300: underrun&=~lockatt;
	mov	r0,#_underrun
	mov	a,r2
	anl	a,@r0
	mov	@r0,a
;	../app_kombi.c:301: resend=lockatt;
	mov	r0,#_lockatt
	mov	ar2,@r0
	mov	r0,#_resend
	mov	@r0,ar2
00108$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay_timer'
;------------------------------------------------------------
;delrecno                  Allocated to registers 
;objno                     Allocated to stack - offset 1
;delay_state               Allocated to registers r6 
;cycle_param               Allocated to registers r3 
;ctrl                      Allocated to stack - offset 2
;sperre                    Allocated to registers r7 
;send                      Allocated to registers b0 
;cyclic                    Allocated to registers b1 
;over                      Allocated to registers b2 
;------------------------------------------------------------
;	../app_kombi.c:308: void delay_timer(void)	// zählt alle 130ms die Variable Timer hoch und prüft Einträge
;	-----------------------------------------
;	 function delay_timer
;	-----------------------------------------
_delay_timer:
	push	_bp
	mov	_bp,sp
	inc	sp
	inc	sp
;	../app_kombi.c:313: RTCCON=0x60;	// Real Time Clock stoppen
	mov	_RTCCON,#0x60
;	../app_kombi.c:315: timer++;
	inc	_timer
	clr	a
	cjne	a,_timer,00168$
	inc	(_timer + 1)
00168$:
;	../app_kombi.c:317: RTCH=0x1D;		// Real Time Clock auf 130ms laden (0,13s x 7372800 / 128)
	mov	_RTCH,#0x1D
;	../app_kombi.c:318: RTCL=0x40;		// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
	mov	_RTCL,#0x40
;	../app_kombi.c:319: RTCCON=0x61;	// ... und starten
	mov	_RTCCON,#0x61
;	../app_kombi.c:321: for(delrecno=0;delrecno<DELREC_CNT;delrecno++) {
	mov	r0,_bp
	inc	r0
	mov	@r0,#0x00
00141$:
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x09,00169$
00169$:
	jc	00170$
	ljmp	00145$
00170$:
;	../app_kombi.c:322: objno=delrecno;
	mov	r0,_bp
	inc	r0
	mov	ar3,@r0
;	../app_kombi.c:323: if (delrecno>1) objno++;	// da objno 2 im delay nicht benutzt wird
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	add	a,#0xff - 0x01
	jnc	00102$
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	a
	mov	r3,a
00102$:
;	../app_kombi.c:325: delay_state=delrec[delrecno].delaystate;
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	add	a,acc
	add	a,acc
	mov	r4,a
	add	a,#_delrec
	mov	r5,a
	inc	a
	mov	r0,a
	mov	ar6,@r0
;	../app_kombi.c:326: if (delrec[delrecno].delayvalue==timer && delrec[delrecno].delayactive) {
	mov	a,#0x02
	add	a,r5
	mov	r0,a
	mov	ar5,@r0
	inc	r0
	mov	ar7,@r0
	dec	r0
	mov	a,r5
	cjne	a,_timer,00172$
	mov	a,r7
	cjne	a,(_timer + 1),00172$
	sjmp	00173$
00172$:
	ljmp	00143$
00173$:
	mov	a,r4
	add	a,#_delrec
	mov	r0,a
	mov	a,@r0
	jnz	00174$
	ljmp	00143$
00174$:
;	../app_kombi.c:328: send=0;
	push	ar6
	clr	b0
;	../app_kombi.c:329: cyclic=0;
	clr	b1
;	../app_kombi.c:330: ctrl=eeprom[ctrl_adr[objno]];		// Control Parameter
	mov	a,r3
	mov	dptr,#_ctrl_adr
	movc	a,@a+dptr
	mov	dpl,a
	mov	dph,#(_eeprom >> 8)
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,ar5
;	../app_kombi.c:331: sperre=read_obj_value(10);
	mov	dpl,#0x0A
	push	ar3
	push	ar4
	push	bits
	lcall	_read_obj_value
	mov	r7,dpl
	mov	r6,dph
	mov	r5,b
	mov	r2,a
	pop	bits
	pop	ar4
	pop	ar3
;	../app_kombi.c:333: if (delrecno<2) {	//Helligkeits- und Temperaturwert
	mov	r0,_bp
	inc	r0
	cjne	@r0,#0x02,00175$
00175$:
	pop	ar6
	jnc	00129$
;	../app_kombi.c:335: if ((eeprom[0xD3-delrecno])!=0)send=1;		// ohne Prüfung auf Sperre etc. immer senden wenn mindset hysterese<>0 oder zykl.
	mov	r0,_bp
	inc	r0
	mov	a,#0xD3
	clr	c
	subb	a,@r0
	add	a,#_eeprom
	mov	r2,a
	clr	a
	addc	a,#(_eeprom >> 8)
	mov	r5,a
	mov	dpl,r2
	mov	dph,r5
	clr	a
	movc	a,@a+dptr
	jz	00104$
	setb	b0
00104$:
;	../app_kombi.c:337: if ((eeprom[0xD3-delrecno]&0x0F)!=0) cyclic=1;	// falls zyklisches Senden
	mov	r0,_bp
	inc	r0
	mov	a,#0xD3
	clr	c
	subb	a,@r0
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r2,a
	anl	a,#0x0F
	jz	00130$
	setb	b1
	sjmp	00130$
00129$:
;	../app_kombi.c:341: over=delrec[delrecno].delayactive & 0x02;	// überschritten
	mov	a,r4
	add	a,#_delrec
	mov	r0,a
	mov	a,@r0
	mov	r2,a
	mov	c,acc[1]
;	../app_kombi.c:342: if (over) {	// wenn überschritten
	mov	b2,c
	jnc	00112$
;	../app_kombi.c:343: if(ctrl & 0x20) cyclic=1;	// wenn überschritten und es soll zyklisch gesendet werden...
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	jnb	acc.5,00113$
	setb	b1
	sjmp	00113$
00112$:
;	../app_kombi.c:346: if(ctrl & 0x80) cyclic=1;	// ...oder wenn unterschritten und es soll zyklisch gesendet werden...
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	jnb	acc.7,00113$
	setb	b1
00113$:
;	../app_kombi.c:349: if ((over && (ctrl&0x30)) || (!over && (ctrl&0xC0))) {	// Senden bei über- oder unterschreiten...
	jnb	b2,00121$
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	anl	a,#0x30
	jnz	00117$
00121$:
	jb	b2,00118$
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	anl	a,#0xC0
	jz	00118$
00117$:
;	../app_kombi.c:350: if ((ctrl & 0x08)==0 || sperre==0) {	// ... nur wenn Sperre ignorieren oder Sperre=0
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	jnb	acc.3,00114$
	mov	a,r7
	jnz	00118$
00114$:
;	../app_kombi.c:351: send=1;
	setb	b0
00118$:
;	../app_kombi.c:355: if ((eeprom[LUXPARAM]&0x80) && (objno==3)) {	// bei Helligkeitsregelung immer zyklisch und immer senden
	mov	dptr,#(_eeprom + 0x00d3)
	clr	a
	movc	a,@a+dptr
	mov	r2,a
	jnb	acc.7,00130$
	cjne	r3,#0x03,00130$
;	../app_kombi.c:356: if ((ctrl & 0x08)==0 || sperre==0) {	// ... nur wenn Sperre ignorieren oder Sperre=0
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	jnb	acc.3,00122$
	mov	a,r7
	jnz	00130$
00122$:
;	../app_kombi.c:357: send=1;
	setb	b0
;	../app_kombi.c:358: cyclic=1;
	setb	b1
00130$:
;	../app_kombi.c:363: if (send) {
	jnb	b0,00134$
;	../app_kombi.c:364: if (objno>1) write_obj_value(objno,delay_state);		// Wert ins userram schreiben
	mov	a,r3
	add	a,#0xff - 0x01
	jnc	00132$
	mov	r2,#0x00
	push	ar3
	push	bits
	push	ar6
	push	ar2
	mov	dpl,r3
	lcall	_write_obj_value
	dec	sp
	dec	sp
	pop	bits
	pop	ar3
00132$:
;	../app_kombi.c:365: send_obj_value(objno);			// Telegramm senden
	mov	dpl,r3
	push	ar3
	push	bits
	lcall	_send_obj_value
	pop	bits
	pop	ar3
00134$:
;	../app_kombi.c:371: delrec[delrecno].delayactive &= 0xFB;
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	add	a,acc
	add	a,acc
	mov	r2,a
	add	a,#_delrec
	mov	r0,a
	mov	ar4,@r0
	mov	a,#0xFB
	anl	a,r4
	mov	@r0,a
;	../app_kombi.c:373: if (cyclic) {
	jnb	b1,00136$
;	../app_kombi.c:374: cycle_param=eeprom[ctrl_adr[objno]+1]&0x0F;	// Zyklus-Adresse jeweils ein Byte über ctrl_adr
	mov	a,r3
	mov	dptr,#_ctrl_adr
	movc	a,@a+dptr
	inc	a
	mov	dptr,#_eeprom
	movc	a,@a+dptr
	mov	r3,a
	anl	ar3,#0x0F
;	../app_kombi.c:375: delrec[delrecno].delayvalue=timer+cycleval[cycle_param];
	mov	a,r2
	add	a,#_delrec+0x02
	mov	r1,a
	mov	a,r3
	add	a,r3
	mov	r2,a
	mov	dptr,#_cycleval
	movc	a,@a+dptr
	xch	a,r2
	inc	dptr
	movc	a,@a+dptr
	mov	r3,a
	mov	a,r2
	add	a,_timer
	mov	r2,a
	mov	a,r3
	addc	a,(_timer + 1)
	mov	r3,a
	mov	@r1,ar2
	inc	r1
	mov	@r1,ar3
	dec	r1
	sjmp	00143$
00136$:
;	../app_kombi.c:378: else delrec[delrecno].delayactive=0;
	mov	@r0,#0x00
00143$:
;	../app_kombi.c:321: for(delrecno=0;delrecno<DELREC_CNT;delrecno++) {
	mov	r0,_bp
	inc	r0
	inc	@r0
	ljmp	00141$
00145$:
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'restart_app'
;------------------------------------------------------------
;objno                     Allocated to registers r2 
;bitmask                   Allocated to registers r2 
;ctrl                      Allocated to registers r4 
;------------------------------------------------------------
;	../app_kombi.c:385: void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
;	-----------------------------------------
;	 function restart_app
;	-----------------------------------------
_restart_app:
;	../app_kombi.c:390: PT0AD=0xF0; 		// disable digital inputs P0.1 ... P0.5
	mov	_PT0AD,#0xF0
;	../app_kombi.c:391: P0= 0xBF;			// P0.0 push-pull for charging the capacitor, P0.6 push-pull status-LED
	mov	_P0,#0xBF
;	../app_kombi.c:392: P0M1= 0x22;			// others bidirectional,
	mov	_P0M1,#0x22
;	../app_kombi.c:393: P0M2= 0x41;			// P0_5 & P0_1 high impedance for adc inputs
	mov	_P0M2,#0x41
;	../app_kombi.c:395: lux=65535;
	mov	_lux,#0xFF
	mov	(_lux + 1),#0xFF
;	../app_kombi.c:396: temp=-1000;
	mov	_temp,#0x18
	mov	(_temp + 1),#0xFC
;	../app_kombi.c:397: lastlux=lux;
	mov	_lastlux,#0xFF
	mov	(_lastlux + 1),#0xFF
;	../app_kombi.c:398: lasttemp=temp;
	mov	_lasttemp,#0x18
	mov	(_lasttemp + 1),#0xFC
;	../app_kombi.c:400: overrun=0;
	mov	r0,#_overrun
	mov	@r0,#0x00
;	../app_kombi.c:401: underrun=0;
	mov	r0,#_underrun
;	../app_kombi.c:403: timer=0;
	clr	a
	mov	@r0,a
	mov	_timer,a
	mov	(_timer + 1),a
;	../app_kombi.c:404: sequence=1;
	mov	r0,#_sequence
	mov	@r0,#0x01
;	../app_kombi.c:408: lockatt=0;
	mov	r0,#_lockatt
	mov	@r0,#0x00
;	../app_kombi.c:409: bitmask=1;
	mov	r2,#0x01
;	../app_kombi.c:410: for (objno=3; objno<=9; objno++) {
	mov	r3,#0x03
00107$:
	mov	a,r3
	add	a,#0xff - 0x09
	jc	00110$
;	../app_kombi.c:411: ctrl=eeprom[ctrl_adr[objno]];
	mov	a,r3
	mov	dptr,#_ctrl_adr
	movc	a,@a+dptr
	mov	dpl,a
	mov	dph,#(_eeprom >> 8)
	clr	a
	movc	a,@a+dptr
;	../app_kombi.c:412: if (ctrl & 0x08) lockatt|=bitmask;
	mov	r4,a
	jnb	acc.3,00102$
	mov	r0,#_lockatt
	mov	a,r2
	orl	a,@r0
	mov	@r0,a
00102$:
;	../app_kombi.c:413: bitmask=bitmask<<1;
	mov	a,r2
	add	a,r2
	mov	r2,a
;	../app_kombi.c:410: for (objno=3; objno<=9; objno++) {
	inc	r3
	sjmp	00107$
00110$:
;	../app_kombi.c:417: global_object_value_3_to_10 &= 0x7F;
	anl	_global_object_value_3_to_10,#0x7F
;	../app_kombi.c:419: for (objno=2;objno<9;objno++) WRITE_DELAY_RECORD(objno,0,0,0)			// erstmal alle delay-records auf inaktiv setzen
	mov	r2,#0x07
00113$:
	mov	a,r2
	dec	a
	mov	r3,a
	add	a,acc
	add	a,acc
	mov	r4,a
	add	a,#_delrec
	mov	r0,a
	mov	@r0,#0x00
	mov	ar2,r3
	mov	a,r2
	jnz	00113$
	mov	(_delrec + 0x0025),a
	mov	(_delrec + 0x0026),a
	mov	((_delrec + 0x0026) + 1),a
;	../app_kombi.c:420: if ((eeprom[0xD3]&0x0F)!=0) {
	mov	dptr,#(_eeprom + 0x00d3)
	clr	a
	movc	a,@a+dptr
	mov	r2,a
	anl	a,#0x0F
	jz	00104$
;	../app_kombi.c:421: WRITE_DELAY_RECORD(0,1,1,timer+50)
	mov	_delrec,#0x01
	mov	(_delrec + 0x0001),#0x01
	mov	(_delrec + 0x0002),#0x32
	mov	((_delrec + 0x0002) + 1),#0x00
00104$:
;	../app_kombi.c:423: if ((eeprom[0xD2]&0x0F)!=0) {
	mov	dptr,#(_eeprom + 0x00d2)
	clr	a
	movc	a,@a+dptr
	mov	r2,a
	anl	a,#0x0F
	jz	00106$
;	../app_kombi.c:424: WRITE_DELAY_RECORD(1,1,1,timer+55)
	mov	(_delrec + 0x0004),#0x01
	mov	(_delrec + 0x0005),#0x01
	mov	(_delrec + 0x0006),#0x37
	mov	((_delrec + 0x0006) + 1),#0x00
00106$:
;	../app_kombi.c:427: EA=0;
	clr	_IEN0_7
;	../app_kombi.c:428: START_WRITECYCLE			// Applikations-spezifische eeprom Eintraege schreiben
	mov	_FMCON,#0x00
;	../app_kombi.c:429: WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode: 0x0001 Siemens
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x03
	mov	_FMDATA,#0x00
;	../app_kombi.c:430: WRITE_BYTE(0x01,0x04,0x01)
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x04
	mov	_FMDATA,#0x01
;	../app_kombi.c:431: WRITE_BYTE(0x01,0x05,0x22)	// Gerätetyp: 0x221C AP254
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x05
	mov	_FMDATA,#0x22
;	../app_kombi.c:432: WRITE_BYTE(0x01,0x06,0x1C)
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x06
	mov	_FMDATA,#0x1C
;	../app_kombi.c:433: WRITE_BYTE(0x01,0x07,0x01)	// Software-Versionsnummer
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x07
	mov	_FMDATA,#0x01
;	../app_kombi.c:434: WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x0C
	mov	_FMDATA,#0x00
;	../app_kombi.c:435: WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x0D
	mov	_FMDATA,#0xFF
;	../app_kombi.c:436: WRITE_BYTE(0x01,0x12,0x56)	// COMMSTAB Pointer
	mov	_FMADRH,#0x1D
	mov	_FMADRL,#0x12
	mov	_FMDATA,#0x56
;	../app_kombi.c:437: STOP_WRITECYCLE
	mov	_FMCON,#0x68
;	../app_kombi.c:438: START_WRITECYCLE;
	mov	_FMCON,#0x00
;	../app_kombi.c:439: WRITE_BYTE(0x00,0x60,0x2E);	// system state: all layers active (run), not in prog mode
	mov	_FMADRH,#0x1C
	mov	_FMADRL,#0x60
	mov	_FMDATA,#0x2E
;	../app_kombi.c:440: STOP_WRITECYCLE;
	mov	_FMCON,#0x68
;	../app_kombi.c:441: EA=1;
	setb	_IEN0_7
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
_cycleval:
	.byte #0x5C,#0x67
	.byte #0xB9,#0x01
	.byte #0x2B,#0x05
	.byte #0x9D,#0x08
	.byte #0x3A,#0x11
	.byte #0x74,#0x22
	.byte #0xAE,#0x33
	.byte #0x85,#0x4D
	.byte #0x5C,#0x67
_luxtable:
	.byte #0x02,#0x00
	.byte #0x02,#0x00
	.byte #0x02,#0x00
	.byte #0x03,#0x00
	.byte #0x03,#0x00
	.byte #0x04,#0x00
	.byte #0x04,#0x00
	.byte #0x05,#0x00
	.byte #0x05,#0x00
	.byte #0x06,#0x00
	.byte #0x07,#0x00
	.byte #0x08,#0x00
	.byte #0x09,#0x00
	.byte #0x0A,#0x00
	.byte #0x0B,#0x00
	.byte #0x0C,#0x00
	.byte #0x0E,#0x00
	.byte #0x10,#0x00
	.byte #0x12,#0x00
	.byte #0x14,#0x00
	.byte #0x17,#0x00
	.byte #0x1A,#0x00
	.byte #0x1E,#0x00
	.byte #0x23,#0x00
	.byte #0x28,#0x00
	.byte #0x2D,#0x00
	.byte #0x32,#0x00
	.byte #0x37,#0x00
	.byte #0x3C,#0x00
	.byte #0x46,#0x00
	.byte #0x50,#0x00
	.byte #0x5A,#0x00
	.byte #0x64,#0x00
	.byte #0x6E,#0x00
	.byte #0x7D,#0x00
	.byte #0x8C,#0x00
	.byte #0xA0,#0x00
	.byte #0xB4,#0x00
	.byte #0xC8,#0x00
	.byte #0xE6,#0x00
	.byte #0x04,#0x01
	.byte #0x2C,#0x01
	.byte #0x5E,#0x01
	.byte #0x90,#0x01
	.byte #0xC2,#0x01
	.byte #0xF4,#0x01
	.byte #0x26,#0x02
	.byte #0x58,#0x02
	.byte #0xBC,#0x02
	.byte #0x20,#0x03
	.byte #0x84,#0x03
	.byte #0xE8,#0x03
	.byte #0x4C,#0x04
	.byte #0xE2,#0x04
	.byte #0x78,#0x05
	.byte #0x40,#0x06
	.byte #0x08,#0x07
	.byte #0xD0,#0x07
	.byte #0xFC,#0x08
	.byte #0x28,#0x0A
	.byte #0xB8,#0x0B
	.byte #0xAC,#0x0D
	.byte #0xA0,#0x0F
	.byte #0x94,#0x11
	.byte #0x88,#0x13
	.byte #0x7C,#0x15
	.byte #0x70,#0x17
	.byte #0x58,#0x1B
	.byte #0x40,#0x1F
	.byte #0x28,#0x23
	.byte #0x10,#0x27
	.byte #0xF8,#0x2A
	.byte #0xD4,#0x30
	.byte #0xB0,#0x36
	.byte #0x80,#0x3E
	.byte #0x50,#0x46
	.byte #0x20,#0x4E
	.byte #0xD8,#0x59
	.byte #0x90,#0x65
	.byte #0x30,#0x75
	.byte #0xB8,#0x88
	.byte #0x40,#0x9C
	.byte #0xC8,#0xAF
	.byte #0x50,#0xC3
	.byte #0xD8,#0xD6
	.byte #0x60,#0xEA
	.byte #0xFF,#0xFF
	.byte #0xFF,#0xFF
	.byte #0xFF,#0xFF
	.byte #0xFF,#0xFF
_hystable:
	.db #0x01
	.db #0x02
	.db #0x0A
	.db #0x05
	.db #0x03
_luxdelay:
	.byte #0x00,#0x00
	.byte #0x0F,#0x00
	.byte #0x26,#0x00
	.byte #0x4B,#0x00
	.byte #0x70,#0x00
	.byte #0x95,#0x00
	.byte #0xE1,#0x00
	.byte #0x51,#0x01
	.byte #0xC1,#0x01
	.byte #0xA2,#0x02
	.byte #0x81,#0x03
	.byte #0x42,#0x05
	.byte #0xC3,#0x08
	.byte #0x85,#0x11
	.byte #0x52,#0x1A
	.byte #0x8E,#0x34
_ctrl_adr:
	.db #0xD2
	.db #0xD1
	.db #0x00
	.db #0xF9
	.db #0xF4
	.db #0xEF
	.db #0xEA
	.db #0xE5
	.db #0xE0
	.db #0xDA
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
