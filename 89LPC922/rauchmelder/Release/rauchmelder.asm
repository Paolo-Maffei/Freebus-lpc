;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
; This file was generated Thu Jun 28 18:23:14 2012
;--------------------------------------------------------
	.module rauchmelder
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
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
	.ds	5
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	ljmp	_key
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
;n                         Allocated to registers r2 
;------------------------------------------------------------
;	../rauchmelder.c:27: void main(void)
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
;	../rauchmelder.c:32: restart_hw();				// Hardware zuruecksetzen
	lcall	_restart_hw
;	../rauchmelder.c:34: for (n=0;n<50;n++) {		// Warten bis Bus stabil, nach Busspannungswiederkehr
	mov	r2,#0x00
00126$:
	cjne	r2,#0x32,00161$
00161$:
	jnc	00129$
;	../rauchmelder.c:35: TR0=0;					// Timer 0 anhalten
	clr	_TCON_4
;	../rauchmelder.c:36: TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
	mov	dptr,#(_eeprom + 0x0017)
	clr	a
	movc	a,@a+dptr
	mov	_TH0,a
;	../rauchmelder.c:37: TL0=eeprom[ADDRTAB+2];
	mov	dptr,#(_eeprom + 0x0018)
	clr	a
	movc	a,@a+dptr
	mov	_TL0,a
;	../rauchmelder.c:38: TF0=0;					// Überlauf-Flag zurücksetzen
	clr	_TCON_5
;	../rauchmelder.c:39: TR0=1;					// Timer 0 starten
	setb	_TCON_4
;	../rauchmelder.c:40: while(!TF0);
00101$:
	jnb	_TCON_5,00101$
;	../rauchmelder.c:34: for (n=0;n<50;n++) {		// Warten bis Bus stabil, nach Busspannungswiederkehr
	inc	r2
	sjmp	00126$
00129$:
;	../rauchmelder.c:42: restart_app();				// Anwendungsspezifische Einstellungen zuruecksetzen
	lcall	_restart_app
;	../rauchmelder.c:45: do  {
00123$:
;	../rauchmelder.c:46: if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt
	mov	dptr,#(_eeprom + 0x000d)
	clr	a
	movc	a,@a+dptr
	mov	r2,a
	cjne	r2,#0xFF,00112$
	jb	_connected,00112$
;	../rauchmelder.c:48: if (event) {				// wenn Rauchmelder etwas gesendet hat
	jnb	_event,00112$
;	../rauchmelder.c:49: if (alarm != alarm_obj && !fernalarm) {	// wenn Alarm aber keine Fernauslösung vorliegt
	mov	c,_alarm
	jb	_alarm_obj,00168$
	cpl	c
00168$:
	jc	00105$
	jb	_fernalarm,00105$
;	../rauchmelder.c:50: send_obj_value(0);					// Telegramm senden
	mov	dpl,#0x00
	lcall	_send_obj_value
;	../rauchmelder.c:51: alarm_obj = alarm;					// Objektwert setzen
	mov	c,_alarm
	mov	_alarm_obj,c
00105$:
;	../rauchmelder.c:53: if (stoerung != stoerung_obj) {			// bei Störung
	mov	c,_stoerung
	jb	_stoerung_obj,00171$
	cpl	c
00171$:
	jc	00108$
;	../rauchmelder.c:54: send_obj_value(1);					// Telegramm senden
	mov	dpl,#0x01
	lcall	_send_obj_value
;	../rauchmelder.c:55: stoerung_obj = stoerung;			// Objektwert setzen
	mov	c,_stoerung
	mov	_stoerung_obj,c
00108$:
;	../rauchmelder.c:57: event=0;	// Ereignismelder zurücksetzen
	clr	_event
00112$:
;	../rauchmelder.c:61: if(tel_arrived) process_tel();		// empfangenes Telegramm abarbeiten
	jnb	_tel_arrived,00115$
	lcall	_process_tel
00115$:
;	../rauchmelder.c:63: if(RTCCON>=0x80) delay_timer();		// Realtime clock Ueberlauf
	mov	a,#0x100 - 0x80
	add	a,_RTCCON
	jnc	00117$
	lcall	_delay_timer
00117$:
;	../rauchmelder.c:67: TASTER=1;					// Pin als Eingang schalten um Taster abzufragen
	setb	_P1_7
;	../rauchmelder.c:68: if(!TASTER) {				// Taster gedrückt
	jb	_P1_7,00122$
;	../rauchmelder.c:69: for(n=0;n<100;n++) {}	// Entprell-Zeit
	mov	r2,#0x64
00132$:
	djnz	r2,00132$
;	../rauchmelder.c:70: while(!TASTER);			// warten bis Taster losgelassen
00118$:
	jnb	_P1_7,00118$
;	../rauchmelder.c:71: status60^=0x81;			// Prog-Bit und Parity-Bit im system_state toggeln
	xrl	_status60,#0x81
00122$:
;	../rauchmelder.c:73: TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
	mov	a,_status60
	anl	a,#0x01
	mov	r2,a
	cjne	a,#0x01,00179$
00179$:
	mov	_P1_7,c
;	../rauchmelder.c:74: for(n=0;n<100;n++) {}		// falls Hauptroutine keine Zeit verbraucht, der LED etwas Zeit geben, damit sie auch leuchten kann
	mov	r2,#0x64
00135$:
	djnz	r2,00135$
;	../rauchmelder.c:75: } while(1);
	sjmp	00123$
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
