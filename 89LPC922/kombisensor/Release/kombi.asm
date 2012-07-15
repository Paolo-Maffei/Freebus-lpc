;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
; This file was generated Sun Jul 15 18:49:22 2012
;--------------------------------------------------------
	.module kombi
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _luxchange
	.globl _logtable
	.globl _main
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
	.globl _tastergetoggelt
	.globl _tasterpegel
	.globl _lux
	.globl _temp
	.globl _lasttemp
	.globl _lastlux
	.globl _timer
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
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_timer::
	.ds 2
_lastlux::
	.ds 2
_lasttemp::
	.ds 2
_temp::
	.ds 2
_lux::
	.ds 2
_tasterpegel::
	.ds 1
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area OSEG    (OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG	(DATA)
__start__stack:
	.ds	1

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
_tastergetoggelt::
	.ds 1
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
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	reti
	.ds	7
	reti
	.ds	7
	ljmp	_X1_int
	.ds	5
	ljmp	_T1_int
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
;	../kombi.c:70: unsigned char tasterpegel=0;
	mov	_tasterpegel,#0x00
;	../kombi.c:71: __bit tastergetoggelt=0;
	clr	_tastergetoggelt
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	lcall	_main
;	return from main will lock up
	sjmp .
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;n                         Allocated to registers r3 
;m                         Allocated to registers r7 
;delta                     Allocated to registers r5 
;th                        Allocated to registers r2 r3 
;change                    Allocated to registers r2 r3 
;eis5temp                  Allocated to registers r2 r3 
;korrektur                 Allocated to registers r4 
;exponent                  Allocated to registers r4 r5 
;eis5lux                   Allocated to registers r2 r3 
;rest                      Allocated to registers r2 r4 
;sloc0                     Allocated to stack - offset 1
;------------------------------------------------------------
;	../kombi.c:83: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
	push	_bp
	mov	_bp,sp
	inc	sp
;	../kombi.c:91: WDL=0xFF;
	mov	_WDL,#0xFF
;	../kombi.c:92: EA=0;
	clr	_IEN0_7
;	../kombi.c:93: WDCON=0xE5;
	mov	_WDCON,#0xE5
;	../kombi.c:94: WFEED1=0xA5;
	mov	_WFEED1,#0xA5
;	../kombi.c:95: WFEED2=0x5A;
	mov	_WFEED2,#0x5A
;	../kombi.c:96: EA=1;
	setb	_IEN0_7
;	../kombi.c:99: restart_hw();				// Hardware zuruecksetzen
	lcall	_restart_hw
;	../kombi.c:101: for (n=0;n<50;n++) {		// Warten bis Bus stabil, nach Busspannungswiederkehr
	mov	r2,#0x00
00185$:
	cjne	r2,#0x32,00250$
00250$:
	jnc	00188$
;	../kombi.c:102: TR0=0;					// Timer 0 anhalten
	clr	_TCON_4
;	../kombi.c:103: TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
	mov	dptr,#(_eeprom + 0x0017)
	clr	a
	movc	a,@a+dptr
	mov	_TH0,a
;	../kombi.c:104: TL0=eeprom[ADDRTAB+2];
	mov	dptr,#(_eeprom + 0x0018)
	clr	a
	movc	a,@a+dptr
	mov	_TL0,a
;	../kombi.c:105: TF0=0;					// Überlauf-Flag zurücksetzen
	clr	_TCON_5
;	../kombi.c:106: TR0=1;					// Timer 0 starten
	setb	_TCON_4
;	../kombi.c:107: while(!TF0);
00101$:
	jnb	_TCON_5,00101$
;	../kombi.c:101: for (n=0;n<50;n++) {		// Warten bis Bus stabil, nach Busspannungswiederkehr
	inc	r2
	sjmp	00185$
00188$:
;	../kombi.c:109: restart_app();				// Anwendungsspezifische Einstellungen zuruecksetzen
	lcall	_restart_app
;	../kombi.c:112: EA=0;
	clr	_IEN0_7
;	../kombi.c:113: WFEED1=0xA5;
	mov	_WFEED1,#0xA5
;	../kombi.c:114: WFEED2=0x5A;
	mov	_WFEED2,#0x5A
;	../kombi.c:115: EA=1;
	setb	_IEN0_7
;	../kombi.c:117: do {
00182$:
;	../kombi.c:118: if (eeprom[0x0D]==0xFF && fb_state==0 && !connected  ) {	// Nur wenn im run-mode und statemachine idle
	mov	dptr,#(_eeprom + 0x000d)
	clr	a
	movc	a,@a+dptr
	mov	r2,a
	cjne	r2,#0xFF,00253$
	sjmp	00254$
00253$:
	ljmp	00164$
00254$:
	mov	a,_fb_state
	jz	00255$
	ljmp	00164$
00255$:
	jnb	_connected,00256$
	ljmp	00164$
00256$:
;	../kombi.c:121: ET1=0;									// statemachine stoppen
	clr	_IEN0_3
;	../kombi.c:122: switch (sequence) {
	mov	r0,#_sequence
	cjne	@r0,#0x01,00257$
	sjmp	00104$
00257$:
	mov	r0,#_sequence
	cjne	@r0,#0x02,00258$
	sjmp	00109$
00258$:
	mov	r0,#_sequence
	cjne	@r0,#0x03,00259$
	sjmp	00115$
00259$:
	mov	r0,#_sequence
	cjne	@r0,#0x04,00260$
	ljmp	00122$
00260$:
	ljmp	00146$
;	../kombi.c:123: case 1:
00104$:
;	../kombi.c:124: if((timer&0x3F) == 0x30) {	// nur alle 10 Sekunden wandeln
	mov	a,#0x3F
	anl	a,_timer
	mov	r2,a
	mov	r3,#0x00
	cjne	r2,#0x30,00108$
	cjne	r3,#0x00,00108$
;	../kombi.c:125: interrupted=0;
	clr	_interrupted
;	../kombi.c:126: start_tempconversion();				// Konvertierung starten
	lcall	_start_tempconversion
;	../kombi.c:127: if (!interrupted) sequence=2;
	jb	_interrupted,00108$
	mov	r0,#_sequence
	mov	@r0,#0x02
00108$:
;	../kombi.c:129: ET1=1;						// statemachine starten
	setb	_IEN0_3
;	../kombi.c:130: break;
	ljmp	00146$
;	../kombi.c:131: case 2:
00109$:
;	../kombi.c:132: if((timer&0x07) == 0x07) {	// nur ein mal pro Sekunde pollen
	mov	a,#0x07
	anl	a,_timer
	mov	r2,a
	mov	r3,#0x00
	cjne	r2,#0x07,00114$
	cjne	r3,#0x00,00114$
;	../kombi.c:133: interrupted=0;
	clr	_interrupted
;	../kombi.c:134: if (ow_read_bit() && !interrupted) sequence=3;	// Konvertierung abgeschlossen
	lcall	_ow_read_bit
	jnc	00114$
	jb	_interrupted,00114$
	mov	r0,#_sequence
	mov	@r0,#0x03
00114$:
;	../kombi.c:136: ET1=1;						// statemachine starten
	setb	_IEN0_3
;	../kombi.c:137: break;
	ljmp	00146$
;	../kombi.c:138: case 3:
00115$:
;	../kombi.c:139: interrupted=0;
	clr	_interrupted
;	../kombi.c:145: th=read_temp();					// Temperatur einlesen
	lcall	_read_temp
	mov	r2,dpl
	mov	r3,dph
;	../kombi.c:147: ET1=1;						// statemachine starten
	setb	_IEN0_3
;	../kombi.c:148: korrektur = (signed char)eeprom[TEMPCORR];			// Parameter Korrekturwert Temperatur
	mov	dptr,#(_eeprom + 0x00ca)
	clr	a
	movc	a,@a+dptr
	mov	r4,a
;	../kombi.c:149: for (n=0;n<10;n++)th+=korrektur;
	mov	r5,#0x0A
00191$:
	mov	a,r4
	mov	r6,a
	rlc	a
	subb	a,acc
	mov	r7,a
	mov	a,r6
	add	a,r2
	mov	r2,a
	mov	a,r7
	addc	a,r3
	mov	r3,a
	djnz	r5,00191$
;	../kombi.c:151: if (!interrupted) {
	jnb	_interrupted,00270$
	ljmp	00146$
00270$:
;	../kombi.c:152: temp=th;
	mov	_temp,r2
	mov	(_temp + 1),r3
;	../kombi.c:153: if (temp != lasttemp) {
	mov	a,_lasttemp
	cjne	a,_temp,00271$
	mov	a,(_lasttemp + 1)
	cjne	a,(_temp + 1),00271$
	sjmp	00119$
00271$:
;	../kombi.c:154: eis5temp=(temp>>3)&0x07FF;	// durch 8 teilen, da später Exponent 3 dazukommt
	mov	r2,_temp
	mov	a,(_temp + 1)
	swap	a
	rl	a
	xch	a,r2
	swap	a
	rl	a
	anl	a,#0x1f
	xrl	a,r2
	xch	a,r2
	anl	a,#0x1f
	xch	a,r2
	xrl	a,r2
	xch	a,r2
	jnb	acc.4,00272$
	orl	a,#0xe0
00272$:
	mov	r3,a
	anl	ar3,#0x07
;	../kombi.c:155: eis5temp=eis5temp+(0x18 << 8);
	mov	a,#0x18
	add	a,r3
	mov	r3,a
;	../kombi.c:156: if (temp<0) eis5temp+=0x8000;	// Vorzeichen
	mov	a,(_temp + 1)
	jnb	acc.7,00117$
	mov	a,#0x80
	add	a,r3
	mov	r3,a
00117$:
;	../kombi.c:157: write_obj_value(1,eis5temp);
	push	ar2
	push	ar3
	mov	dpl,#0x01
	lcall	_write_obj_value
	dec	sp
	dec	sp
;	../kombi.c:159: schwelle(6);             // Temperaturschwellen prüfen und ggf. reagieren
	mov	dpl,#0x06
	lcall	_schwelle
;	../kombi.c:160: schwelle(7);
	mov	dpl,#0x07
	lcall	_schwelle
00119$:
;	../kombi.c:162: sequence=4;
	mov	r0,#_sequence
	mov	@r0,#0x04
;	../kombi.c:164: break;
	ljmp	00146$
;	../kombi.c:165: case 4:				// Helligkeitswert konvertieren
00122$:
;	../kombi.c:166: interrupted=0;
	clr	_interrupted
;	../kombi.c:167: Get_ADC(3);		// ADC-Wert holen
	mov	dpl,#0x03
	lcall	_Get_ADC
;	../kombi.c:168: ET1=1;			// statemachine starten
	setb	_IEN0_3
;	../kombi.c:169: if (!interrupted) {
	jnb	_interrupted,00274$
	ljmp	00146$
00274$:
;	../kombi.c:171: if (HighByte>=112) {
	mov	a,#0x100 - 0x70
	add	a,_HighByte
	jnc	00137$
;	../kombi.c:172: lux=65535;
	mov	_lux,#0xFF
	mov	(_lux + 1),#0xFF
	ljmp	00138$
00137$:
;	../kombi.c:185: lux=2;
	mov	_lux,#0x02
	clr	a
	mov	(_lux + 1),a
;	../kombi.c:186: while (HighByte >= logtable[n]) {
	mov	r2,#0x00
00123$:
	mov	a,r2
	mov	dptr,#_logtable
	movc	a,@a+dptr
	mov	r3,a
	clr	c
	mov	a,_HighByte
	subb	a,r3
	jc	00246$
;	../kombi.c:187: n++;
	inc	r2
;	../kombi.c:188: lux=lux*2;
	mov	a,(_lux + 1)
	xch	a,_lux
	add	a,acc
	xch	a,_lux
	rlc	a
	mov	(_lux + 1),a
	sjmp	00123$
00246$:
;	../kombi.c:190: if (n<=1) lux=0;
	mov	a,r2
	mov	r3,a
	add	a,#0xff - 0x01
	jc	00127$
	clr	a
	mov	_lux,a
	mov	(_lux + 1),a
00127$:
;	../kombi.c:193: rest=HighByte-logtable[n-1];
	mov	r2,_HighByte
	mov	r4,#0x00
	mov	a,r3
	dec	a
	mov	dptr,#_logtable
	movc	a,@a+dptr
	mov	r5,a
	mov	r6,a
	mov	r7,#0x00
	mov	a,r2
	clr	c
	subb	a,r6
	mov	r2,a
	mov	a,r4
	subb	a,r7
	mov	r4,a
;	../kombi.c:194: delta=logtable[n]-logtable[n-1];
	mov	a,r3
	mov	dptr,#_logtable
	movc	a,@a+dptr
	mov	r6,a
	clr	c
	subb	a,r5
	mov	r5,a
;	../kombi.c:200: if (n<11) m=n+2; else m=n-2;
	mov	r0,_bp
	inc	r0
	cjne	r3,#0x0B,00278$
00278$:
	clr	a
	rlc	a
	mov	@r0,a
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	jz	00129$
	mov	a,#0x02
	add	a,r3
	mov	r7,a
	sjmp	00130$
00129$:
	mov	a,r3
	add	a,#0xfe
	mov	r7,a
00130$:
;	../kombi.c:201: rest=rest<<m;
	push	ar3
	mov	b,r7
	inc	b
	sjmp	00281$
00280$:
	mov	a,r2
	add	a,r2
	mov	r2,a
	mov	a,r4
	rlc	a
	mov	r4,a
00281$:
	djnz	b,00280$
;	../kombi.c:202: rest=_divuint(rest,delta);
	mov	r7,#0x00
	push	ar5
	push	ar7
	push	ar5
	push	ar7
	mov	dpl,r2
	mov	dph,r4
	lcall	__divuint
	mov	r3,dpl
	mov	r6,dph
	dec	sp
	dec	sp
	pop	ar7
	pop	ar5
	mov	ar2,r3
	mov	ar4,r6
;	../kombi.c:203: if (n<11) lux+=rest; else lux+=rest<<4;
	pop	ar3
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	jz	00132$
	mov	a,r2
	add	a,_lux
	mov	_lux,a
	mov	a,r4
	addc	a,(_lux + 1)
	mov	(_lux + 1),a
	sjmp	00133$
00132$:
	mov	a,r4
	swap	a
	anl	a,#0xf0
	xch	a,r2
	swap	a
	xch	a,r2
	xrl	a,r2
	xch	a,r2
	anl	a,#0xf0
	xch	a,r2
	xrl	a,r2
	mov	r4,a
	mov	a,r2
	add	a,_lux
	mov	_lux,a
	mov	a,r4
	addc	a,(_lux + 1)
	mov	(_lux + 1),a
00133$:
;	../kombi.c:206: if (n<7) lux+=(_divuint(LowByte<<(n+2),delta)>>8);
	cjne	r3,#0x07,00283$
00283$:
	jnc	00138$
	mov	r2,_LowByte
	clr	a
	mov	r4,a
	mov	r6,a
	mov	a,#0x02
	add	a,r3
	mov	r3,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	b,r3
	inc	b
	sjmp	00286$
00285$:
	mov	a,r2
	add	a,r2
	mov	r2,a
	mov	a,r4
	rlc	a
	mov	r4,a
00286$:
	djnz	b,00285$
	push	ar5
	push	ar7
	mov	dpl,r2
	mov	dph,r4
	lcall	__divuint
	mov	r3,dph
	dec	sp
	dec	sp
	mov	ar2,r3
	mov	r3,#0x00
	mov	a,r2
	add	a,_lux
	mov	_lux,a
	mov	a,r3
	addc	a,(_lux + 1)
	mov	(_lux + 1),a
00138$:
;	../kombi.c:209: if (lux!=lastlux) {
	mov	a,_lastlux
	cjne	a,_lux,00287$
	mov	a,(_lastlux + 1)
	cjne	a,(_lux + 1),00287$
	sjmp	00143$
00287$:
;	../kombi.c:212: eis5lux=lux>>1;
	mov	r2,_lux
	mov	a,(_lux + 1)
	clr	c
	rrc	a
	xch	a,r2
	rrc	a
	xch	a,r2
	mov	r3,a
;	../kombi.c:213: eis5lux+=lux>>2;
	mov	r4,_lux
	mov	a,(_lux + 1)
	clr	c
	rrc	a
	xch	a,r4
	rrc	a
	xch	a,r4
	clr	c
	rrc	a
	xch	a,r4
	rrc	a
	xch	a,r4
	mov	r5,a
	mov	a,r4
	add	a,r2
	mov	r2,a
	mov	a,r5
	addc	a,r3
	mov	r3,a
;	../kombi.c:214: eis5lux+=lux>>5;
	mov	r4,_lux
	mov	a,(_lux + 1)
	swap	a
	rr	a
	xch	a,r4
	swap	a
	rr	a
	anl	a,#0x07
	xrl	a,r4
	xch	a,r4
	anl	a,#0x07
	xch	a,r4
	xrl	a,r4
	xch	a,r4
	mov	r5,a
	mov	a,r4
	add	a,r2
	mov	r2,a
	mov	a,r5
	addc	a,r3
	mov	r3,a
;	../kombi.c:217: while (eis5lux > 0x07FF) {	// Exponent erhöhen falls Mantisse zu groß
	mov	r4,#0x00
	mov	r5,#0x38
00139$:
	clr	c
	mov	a,#0xFF
	subb	a,r2
	mov	a,#0x07
	subb	a,r3
	jnc	00141$
;	../kombi.c:218: eis5lux=eis5lux>>1;
	mov	a,r3
	clr	c
	rrc	a
	xch	a,r2
	rrc	a
	xch	a,r2
	mov	r3,a
;	../kombi.c:219: exponent+=0x0800;
	mov	a,#0x08
	add	a,r5
	mov	r5,a
	sjmp	00139$
00141$:
;	../kombi.c:221: eis5lux+=exponent;
	mov	a,r4
	add	a,r2
	mov	r2,a
	mov	a,r5
	addc	a,r3
	mov	r3,a
;	../kombi.c:223: write_obj_value(0,eis5lux);		// Lux Wert im userram speichern
	push	ar2
	push	ar3
	mov	dpl,#0x00
	lcall	_write_obj_value
	dec	sp
	dec	sp
;	../kombi.c:224: schwelle(4);                           // Helligkeitsschwellen 2 und 3
	mov	dpl,#0x04
	lcall	_schwelle
;	../kombi.c:225: schwelle(5);
	mov	dpl,#0x05
	lcall	_schwelle
00143$:
;	../kombi.c:227: schwelle(3);      // Helligkeitsschwelle 1 trotzdem jedes mal weil es auch Nachregelung sein könnte
	mov	dpl,#0x03
	lcall	_schwelle
;	../kombi.c:228: sequence=1;
	mov	r0,#_sequence
	mov	@r0,#0x01
;	../kombi.c:231: }
00146$:
;	../kombi.c:236: change=((eeprom[TEMPPARAM]&0x70)>>4)*100;	// wenn change=0 wird nicht gesendet
	mov	dptr,#(_eeprom + 0x00d2)
	clr	a
	movc	a,@a+dptr
	anl	a,#0x70
	swap	a
	anl	a,#0x0f
	mov	b,#0x64
	mul	ab
;	../kombi.c:237: if(change) {
	mov	r2,a
	mov	r3,b
	orl	a,r3
	jz	00151$
;	../kombi.c:238: if (((temp + change)<= lasttemp) || ((lasttemp + change)<= temp)) {	// bei Änderung um 1-3K
	mov	a,r2
	add	a,_temp
	mov	r4,a
	mov	a,r3
	addc	a,(_temp + 1)
	mov	r5,a
	clr	c
	mov	a,_lasttemp
	subb	a,r4
	mov	a,(_lasttemp + 1)
	xrl	a,#0x80
	mov	b,r5
	xrl	b,#0x80
	subb	a,b
	jnc	00147$
	mov	a,r2
	add	a,_lasttemp
	mov	r4,a
	mov	a,r3
	addc	a,(_lasttemp + 1)
	mov	r5,a
	clr	c
	mov	a,_temp
	subb	a,r4
	mov	a,(_temp + 1)
	xrl	a,#0x80
	mov	b,r5
	xrl	b,#0x80
	subb	a,b
	jc	00151$
00147$:
;	../kombi.c:239: WRITE_DELAY_RECORD(1,1,1,timer+1)
	mov	a,#0x01
	mov	(_delrec + 0x0004),a
	mov	(_delrec + 0x0005),a
	add	a,_timer
	mov	r4,a
	clr	a
	addc	a,(_timer + 1)
	mov	r5,a
	mov	(_delrec + 0x0006),r4
	mov	((_delrec + 0x0006) + 1),r5
;	../kombi.c:240: lasttemp=temp;
	mov	_lasttemp,_temp
	mov	(_lasttemp + 1),(_temp + 1)
00151$:
;	../kombi.c:245: if (eeprom[LUXPARAM] & 0x70) {	// wenn Lux senden bei Änderung aktiv
	mov	dptr,#(_eeprom + 0x00d3)
	clr	a
	movc	a,@a+dptr
	mov	r4,a
	anl	a,#0x70
	jnz	00292$
	ljmp	00160$
00292$:
;	../kombi.c:246: change=_divuint(lastlux,luxchange[(eeprom[LUXPARAM]&0x70)>>4]);
	mov	dptr,#(_eeprom + 0x00d3)
	clr	a
	movc	a,@a+dptr
	anl	a,#0x70
	swap	a
	anl	a,#0x0f
	mov	dptr,#_luxchange
	movc	a,@a+dptr
	mov	r4,a
	mov	r5,#0x00
	push	ar4
	push	ar5
	mov	dpl,_lastlux
	mov	dph,(_lastlux + 1)
	lcall	__divuint
	mov	r4,dpl
	mov	r5,dph
	dec	sp
	dec	sp
	mov	ar2,r4
	mov	ar3,r5
;	../kombi.c:247: if (change==0) change=1;		// mindestens 1 Lux Änderung
	mov	a,r2
	orl	a,r3
	jnz	00153$
	mov	r2,#0x01
	mov	r3,a
00153$:
;	../kombi.c:248: if ((lux>lastlux && (lux-lastlux)>=change) || (lux<lastlux && (lastlux-lux)>=change)) {
	clr	c
	mov	a,_lastlux
	subb	a,_lux
	mov	a,(_lastlux + 1)
	subb	a,(_lux + 1)
	jnc	00158$
	mov	a,_lux
	clr	c
	subb	a,_lastlux
	mov	r4,a
	mov	a,(_lux + 1)
	subb	a,(_lastlux + 1)
	mov	r5,a
	mov	ar6,r2
	mov	ar7,r3
	clr	c
	mov	a,r4
	subb	a,r6
	mov	a,r5
	subb	a,r7
	jnc	00154$
00158$:
	clr	c
	mov	a,_lux
	subb	a,_lastlux
	mov	a,(_lux + 1)
	subb	a,(_lastlux + 1)
	jnc	00160$
	mov	a,_lastlux
	clr	c
	subb	a,_lux
	mov	r4,a
	mov	a,(_lastlux + 1)
	subb	a,(_lux + 1)
	mov	r5,a
	clr	c
	mov	a,r4
	subb	a,r2
	mov	a,r5
	subb	a,r3
	jc	00160$
00154$:
;	../kombi.c:249: WRITE_DELAY_RECORD(0,1,1,timer+1)
	mov	a,#0x01
	mov	_delrec,a
	mov	(_delrec + 0x0001),a
	add	a,_timer
	mov	r2,a
	clr	a
	addc	a,(_timer + 1)
	mov	r3,a
	mov	(_delrec + 0x0002),r2
	mov	((_delrec + 0x0002) + 1),r3
;	../kombi.c:250: lastlux=lux;
	mov	_lastlux,_lux
	mov	(_lastlux + 1),(_lux + 1)
00160$:
;	../kombi.c:255: schwelle(8);     // Verknüpfungsobjekte
	mov	dpl,#0x08
	lcall	_schwelle
;	../kombi.c:256: schwelle(9);
	mov	dpl,#0x09
	lcall	_schwelle
;	../kombi.c:258: if(RTCCON>=0x80) delay_timer();	// Realtime clock Überlauf
	mov	a,#0x100 - 0x80
	add	a,_RTCCON
	jnc	00164$
	lcall	_delay_timer
00164$:
;	../kombi.c:263: EA=0;
	clr	_IEN0_7
;	../kombi.c:264: WFEED1=0xA5;
	mov	_WFEED1,#0xA5
;	../kombi.c:265: WFEED2=0x5A;
	mov	_WFEED2,#0x5A
;	../kombi.c:266: EA=1;
	setb	_IEN0_7
;	../kombi.c:268: if(tel_arrived) process_tel();			// empfangenes Telegramm abarbeiten
	jnb	_tel_arrived,00168$
	lcall	_process_tel
00168$:
;	../kombi.c:272: TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
	setb	_P1_7
;	../kombi.c:273: if(!TASTER){ // Taster gedrückt
	jb	_P1_7,00178$
;	../kombi.c:274: if(tasterpegel<255)	tasterpegel++;
	mov	a,#0x100 - 0xFF
	add	a,_tasterpegel
	jc	00172$
	inc	_tasterpegel
	sjmp	00179$
00172$:
;	../kombi.c:276: if(!tastergetoggelt)status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
	jb	_tastergetoggelt,00170$
	xrl	_status60,#0x81
00170$:
;	../kombi.c:277: tastergetoggelt=1;
	setb	_tastergetoggelt
	sjmp	00179$
00178$:
;	../kombi.c:281: if(tasterpegel>0) tasterpegel--;
	mov	a,_tasterpegel
	jz	00175$
	dec	_tasterpegel
	sjmp	00179$
00175$:
;	../kombi.c:282: else tastergetoggelt=0;
	clr	_tastergetoggelt
00179$:
;	../kombi.c:284: TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
	mov	a,_status60
	anl	a,#0x01
	mov	r2,a
	cjne	a,#0x01,00304$
00304$:
	mov	_P1_7,c
;	../kombi.c:285: if (fb_state==0) for(n=0;n<100;n++) {}	// etwas zeit zum leuchten, wenn Hauptschleife nicht aktiv
	mov	a,_fb_state
	jz	00305$
	ljmp	00182$
00305$:
	mov	r2,#0x64
00194$:
	djnz	r2,00194$
;	../kombi.c:286: } while(1);
	ljmp	00182$
	mov	sp,_bp
	pop	_bp
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
_logtable:
	.db #0x00
	.db #0x09
	.db #0x11
	.db #0x1B
	.db #0x28
	.db #0x35
	.db #0x42
	.db #0x4F
	.db #0x58
	.db #0x60
	.db #0x65
	.db #0x6A
	.db #0x6D
	.db #0x70
	.db #0xFF
_luxchange:
	.db #0x64
	.db #0x14
	.db #0x0A
	.db #0x05
	.db #0x03
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
