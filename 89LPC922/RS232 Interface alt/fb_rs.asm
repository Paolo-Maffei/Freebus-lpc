;--------------------------------------------------------
; File Created by SDCC : FreeWare ANSI-C Compiler
; Version 2.6.1 #4376 (Sep 14 2006)
; This file generated Thu Feb 21 19:45:02 2008
;--------------------------------------------------------
	.module fb_rs
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _dataflash
	.globl _main
	.globl _find_ga
	.globl _get_ack
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
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
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
	.globl _connected
	.globl _progmode
	.globl _parity_ok
	.globl _pcount
	.globl _conl
	.globl _conh
	.globl _gacount
	.globl _pah
	.globl _pal
	.globl _cs
	.globl _telpos
	.globl _telegramm
	.globl _get_byte
	.globl _ext_int0
	.globl _sendbyte
	.globl _start_writecycle
	.globl _stop_writecycle
	.globl _write_byte
	.globl _delay
	.globl _set_timer1
	.globl _read_byte
	.globl _restart_hw
	.globl _timer1
	.globl _send_telegramm
	.globl _send_ack
	.globl _ucd_opr
	.globl _ucd_clr
	.globl _ncd_quit
	.globl _read_masq
	.globl _read_memory
	.globl _write_memory
	.globl _set_pa
	.globl _read_pa
	.globl _read_objflags
	.globl _gapos_in_gat
	.globl _write_delay_record
	.globl _restart_prot
	.globl _rs_init
	.globl _rs_send_dec
	.globl _rs_send_ok
	.globl _eis1
	.globl _read_value_req
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
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
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
_telegramm::
	.ds 23
_telpos::
	.ds 1
_cs::
	.ds 1
_pal::
	.ds 1
_pah::
	.ds 1
_gacount::
	.ds 1
_conh::
	.ds 1
_conl::
	.ds 1
_pcount::
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
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
_parity_ok::
	.ds 1
_progmode::
	.ds 1
_connected::
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
	ljmp	_ext_int0
	.ds	5
	ljmp	_timer1
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
	.area CSEG    (CODE)
__sdcc_program_startup:
	lcall	_main
;	return from main will lock up
	sjmp .
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'get_byte'
;------------------------------------------------------------
;rbit                      Allocated to registers b1 
;parity                    Allocated to registers b1 
;ph                        Allocated to registers b0 
;n                         Allocated to registers r3 
;m                         Allocated to registers r2 
;fbb                       Allocated to registers r2 
;fbbh                      Allocated to registers r3 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:10: unsigned char get_byte(void)
;	-----------------------------------------
;	 function get_byte
;	-----------------------------------------
_get_byte:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:15: EX1=0;				// Interrupt 1 sperren
;	genAssign
	clr	_IEN0_2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:16: ET1=0;				// Interrupt von Timer 1 sperren
;	genAssign
	clr	_IEN0_3
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:18: set_timer1(380);			// Timer setzen um 1. Bit zu treffen (320-440)
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x017C
	lcall	_set_timer1
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:20: ph=0;					// Paritybit wird aus empfangenem Byte berechnet
;	genAssign
	clr	b0
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:21: parity_ok=0;
;	genAssign
	clr	_parity_ok
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:22: while(!TF1);				// warten auf Timer 1				
00101$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00101$
;	Peephole 300	removed redundant label 00152$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:23: set_timer1(360);			// Timer 1 neu setzen für 2.Bit (300-420)
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x0168
	push	bits
	lcall	_set_timer1
	pop	bits
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:24: rbit=FBINC;				// 1.Bit einlesen
;	genAssign
	mov	c,_P1_4
	mov	b1,c
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:25: for(m=0;m<5;m++)
;	genAssign
	mov	r2,#0x05
00118$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:27: rbit&=FBINC;			// zur Steigerung der Fehlertoleranz mehrfach lesen
;	genAnd
	mov	c,_P1_4
	anl	c,b1
	mov	b1,c
;	genDjnz
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 205	optimized misc jump sequence
	djnz	r2,00118$
;	Peephole 300	removed redundant label 00153$
;	Peephole 300	removed redundant label 00154$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:25: for(m=0;m<5;m++)
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:29: fbb=rbit;
;	genAssign
	clr	a
	mov	c,b1
	rlc	a
	mov	r2,a
;	genAssign
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:30: if(rbit) ph=!ph;			// Paritybit berechnen
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	b1,00142$
;	Peephole 300	removed redundant label 00155$
;	genNot
	cpl	b0
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:32: for(n=0;n<7;n++)			// 2. bis 8. Bit
00142$:
;	genAssign
	mov	r3,#0x00
00122$:
;	genCmpLt
;	genCmp
	cjne	r3,#0x07,00156$
00156$:
;	genIfxJump
;	Peephole 108.a	removed ljmp by inverse jump logic
	jnc	00111$
;	Peephole 300	removed redundant label 00157$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:34: fbb=fbb<<1;
;	genLeftShift
;	genLeftShiftLiteral
;	genlshOne
	mov	a,r2
;	Peephole 254	optimized left shift
	add	a,r2
	mov	r2,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:35: while(!TF1);
00106$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00106$
;	Peephole 300	removed redundant label 00158$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:36: set_timer1(350);			// Timer 1 setzen für Position 2.-9.Bit (342-359)
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x015E
	push	ar2
	push	ar3
	push	bits
	lcall	_set_timer1
	pop	bits
	pop	ar3
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:37: rbit=FBINC;
;	genAssign
	mov	c,_P1_4
	mov	b1,c
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:38: for(m=0;m<5;m++)
;	genAssign
	mov	r4,#0x05
00121$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:40: rbit&=FBINC;			// zur Steigerung der Fehlertoleranz mehrfach lesen
;	genAnd
	mov	c,_P1_4
	anl	c,b1
	mov	b1,c
;	genDjnz
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 205	optimized misc jump sequence
	djnz	r4,00121$
;	Peephole 300	removed redundant label 00159$
;	Peephole 300	removed redundant label 00160$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:38: for(m=0;m<5;m++)
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:42: fbb=fbb+rbit;
;	genAssign
	clr	a
	mov	c,b1
	rlc	a
;	genPlus
	mov	r4,a
;	Peephole 177.b	removed redundant mov
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	r2,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:43: if(rbit) ph=!ph;			// Paritybit berechnen
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	b1,00124$
;	Peephole 300	removed redundant label 00161$
;	genNot
	cpl	b0
00124$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:32: for(n=0;n<7;n++)			// 2. bis 8. Bit
;	genPlus
;     genPlusIncr
	inc	r3
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:45: while(!TF1);				
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00122$
00111$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00111$
;	Peephole 300	removed redundant label 00162$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:46: TR1=0;
;	genAssign
	clr	_TCON_6
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:47: parity=FBINC;				// Paritybit lesen
;	genAssign
	mov	c,_P1_4
	mov	b1,c
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:48: for(m=0;m<5;m++)
;	genAssign
	mov	r3,#0x05
00128$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:50: parity&=FBINC;
;	genAnd
	mov	c,_P1_4
	anl	c,b1
	mov	b1,c
;	genDjnz
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 205	optimized misc jump sequence
	djnz	r3,00128$
;	Peephole 300	removed redundant label 00163$
;	Peephole 300	removed redundant label 00164$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:48: for(m=0;m<5;m++)
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:53: fbbh=(fbb&0x80)>>7;			// Byte bitweise vertauschen, da LSB zuerst übertragen wurde
;	genAnd
	mov	a,#0x80
	anl	a,r2
;	genRightShift
;	genRightShiftLiteral
;	genrshOne
	mov	r3,a
;	Peephole 105	removed redundant mov
	rl	a
	anl	a,#0x01
	mov	r3,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:54: fbbh=fbbh+((fbb&0x40)>>5);
;	genAnd
	mov	a,#0x40
	anl	a,r2
;	genRightShift
;	genRightShiftLiteral
;	genrshOne
	mov	r4,a
;	Peephole 105	removed redundant mov
	swap	a
	rr	a
	anl	a,#0x07
;	genPlus
	mov	r4,a
;	Peephole 177.b	removed redundant mov
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r3,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:55: fbbh=fbbh+((fbb&0x20)>>3);
;	genAnd
	mov	a,#0x20
	anl	a,r2
;	genRightShift
;	genRightShiftLiteral
;	genrshOne
	mov	r4,a
;	Peephole 105	removed redundant mov
	swap	a
	rl	a
	anl	a,#0x1f
;	genPlus
	mov	r4,a
;	Peephole 177.b	removed redundant mov
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r3,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:56: fbbh=fbbh+((fbb&0x10)>>1);
;	genAnd
	mov	a,#0x10
	anl	a,r2
;	genRightShift
;	genRightShiftLiteral
;	genrshOne
	mov	r4,a
;	Peephole 105	removed redundant mov
	clr	c
	rrc	a
;	genPlus
	mov	r4,a
;	Peephole 177.b	removed redundant mov
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r3,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:57: fbbh=fbbh+((fbb&0x08)<<1);
;	genAnd
	mov	a,#0x08
	anl	a,r2
;	genLeftShift
;	genLeftShiftLiteral
;	genlshOne
;	Peephole 105	removed redundant mov
;	genPlus
;	Peephole 204	removed redundant mov
	add	a,acc
	mov	r4,a
;	Peephole 177.b	removed redundant mov
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r3,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:58: fbbh=fbbh+((fbb&0x04)<<3);
;	genAnd
	mov	a,#0x04
	anl	a,r2
;	genLeftShift
;	genLeftShiftLiteral
;	genlshOne
	mov	r4,a
;	Peephole 105	removed redundant mov
	swap	a
	rr	a
	anl	a,#0xf8
;	genPlus
	mov	r4,a
;	Peephole 177.b	removed redundant mov
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r3,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:59: fbbh=fbbh+((fbb&0x02)<<5);
;	genAnd
	mov	a,#0x02
	anl	a,r2
;	genLeftShift
;	genLeftShiftLiteral
;	genlshOne
	mov	r4,a
;	Peephole 105	removed redundant mov
	swap	a
	rl	a
	anl	a,#0xe0
;	genPlus
	mov	r4,a
;	Peephole 177.b	removed redundant mov
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r3,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:60: fbbh=fbbh+((fbb&0x01)<<7);
;	genAnd
	anl	ar2,#0x01
;	genLeftShift
;	genLeftShiftLiteral
;	genlshOne
	mov	a,r2
	rr	a
	anl	a,#0x80
;	genPlus
	mov	r2,a
;	Peephole 177.b	removed redundant mov
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r3,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:62: if(parity==ph) parity_ok=1;
;	genCmpEq
	mov	c,b1
	jb	b0,00165$
	cpl	c
00165$:
;	Peephole 108.a	removed ljmp by inverse jump logic
	jnc	00115$
;	Peephole 300	removed redundant label 00166$
;	genAssign
	setb	_parity_ok
00115$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:64: return fbbh;
;	genRet
	mov	dpl,r3
;	Peephole 300	removed redundant label 00129$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ext_int0'
;------------------------------------------------------------
;fbbh                      Allocated to registers r2 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:70: void ext_int0(void) interrupt 2		// Byte vom Bus empfangen, wird durch negative Flanke am INT1 Eingang getriggert
;	-----------------------------------------
;	 function ext_int0
;	-----------------------------------------
_ext_int0:
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+2)
	push	(0+3)
	push	(0+4)
	push	(0+5)
	push	(0+6)
	push	(0+7)
	push	(0+0)
	push	(0+1)
	push	bits
	push	psw
	mov	psw,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:76: TR1=0;
;	genAssign
	clr	_TCON_6
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:77: EX1=0;				// Interrupt 1 sperren
;	genAssign
	clr	_IEN0_2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:78: ET1=0;				// Interrupt von Timer 1 sperren
;	genAssign
	clr	_IEN0_3
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:80: fbbh=get_byte();			// Byte vom Bus empfangen
;	genCall
	lcall	_get_byte
	mov	r2,dpl
;	genAssign
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:81: delay(200);
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x00C8
	push	ar2
	lcall	_delay
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:83: if(parity_ok)				// wenn Parity OK
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_parity_ok,00104$
;	Peephole 300	removed redundant label 00109$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:85: telegramm[telpos]=fbbh; 
;	genPlus
	mov	a,_telpos
	add	a,#_telegramm
;	genPointerSet
;	genNearPointerSet
;	Peephole 239	used a instead of acc
	mov	r0,a
	mov	@r0,ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:86: if(telpos==0) cs=0;
;	genIfx
	mov	a,_telpos
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
;	genAssign
	jnz	00102$
;	Peephole 300	removed redundant label 00110$
;	Peephole 256.c	loading _cs with zero from a
	mov	_cs,a
00102$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:87: cs^=fbbh;				// Checksum durch EXOR der einzelnen Telegramm-Bytes bilden
;	genXor
	mov	a,r2
	xrl	_cs,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:88: telpos++;
;	genPlus
;     genPlusIncr
	inc	_telpos
00104$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:91: set_timer1(1350);			// Timer 1 starten für Timeout 370us -> signalisiert Telegrammende (1350)
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x0546
	lcall	_set_timer1
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:93: ET1=1;				// Interrupt für Timer 1 freigeben
;	genAssign
	setb	_IEN0_3
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:94: IE1=0;				// Interrupt 0 request zurücksetzen
;	genAssign
	clr	_TCON_3
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:95: EX1=1;				// Interrupt 0 wieder freigeben
;	genAssign
	setb	_IEN0_2
;	Peephole 300	removed redundant label 00105$
	pop	psw
	pop	bits
	pop	(0+1)
	pop	(0+0)
	pop	(0+7)
	pop	(0+6)
	pop	(0+5)
	pop	(0+4)
	pop	(0+3)
	pop	(0+2)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	reti
;------------------------------------------------------------
;Allocation info for local variables in function 'sendbyte'
;------------------------------------------------------------
;fbsb                      Allocated to registers r2 
;n                         Allocated to registers r3 
;m                         Allocated to registers r4 
;sendbit                   Allocated to registers b2 
;parity                    Allocated to registers b0 
;error                     Allocated to registers b1 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:99: bit sendbyte(unsigned char fbsb)
;	-----------------------------------------
;	 function sendbyte
;	-----------------------------------------
_sendbyte:
;	genReceive
	mov	r2,dpl
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:104: parity=1;
;	genAssign
	setb	b0
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:105: error=0;
;	genAssign
	clr	b1
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:107: FBOUTC=1;	// Startbit senden
;	genAssign
	setb	_P1_6
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:108: delay(95);	// 35us
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x005F
	push	ar2
	push	bits
	lcall	_delay
	pop	bits
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:109: FBOUTC=0;
;	genAssign
	clr	_P1_6
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:111: for(n=0;n<8;n++)		// 8 Datenbits senden
;	genAssign
	mov	r3,#0x00
00116$:
;	genCmpLt
;	genCmp
	cjne	r3,#0x08,00141$
00141$:
;	genIfxJump
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 160.b	removed sjmp by inverse jump logic
	jnc	00119$
;	Peephole 300	removed redundant label 00142$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:113: set_timer1(215);		// 69us Pause
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x00D7
	push	ar2
	push	ar3
	push	bits
	lcall	_set_timer1
	pop	bits
	pop	ar3
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:114: if(((fbsb>>n)&0x01)==1) sendbit=0;
;	genRightShift
	mov	b,r3
	inc	b
	mov	a,r2
	sjmp	00144$
00143$:
	clr	c
	rrc	a
00144$:
	djnz	b,00143$
;	genAnd
	anl	a,#0x01
	mov	r4,a
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r4,#0x01,00102$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00145$
;	Peephole 300	removed redundant label 00146$
;	genAssign
	clr	b2
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00104$
00102$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:115: else sendbit=1;
;	genAssign
	setb	b2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:116: while(!TF1);		// Warten bis 69us Pause fretig ist
00104$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00104$
;	Peephole 300	removed redundant label 00147$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:118: FBOUTC=sendbit;		// Bit senden
;	genAssign
	mov	c,b2
	mov	_P1_6,c
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:120: set_timer1(100);		//35us Haltezeit für Bit 
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x0064
	push	ar2
	push	ar3
	push	bits
	lcall	_set_timer1
	pop	bits
	pop	ar3
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:122: if(!sendbit)		// wenn logische 1 gesendet wird, auf Kollision prüfen
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	b2,00110$
;	Peephole 300	removed redundant label 00148$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:124: parity=!parity;
;	genNot
	cpl	b0
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:125: for(m=0;m<5;m++)
;	genAssign
	mov	r4,#0x05
00124$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:127: if(!FBINC) error=1;
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	_P1_4,00108$
;	Peephole 300	removed redundant label 00149$
;	genAssign
	setb	b1
00108$:
;	genDjnz
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 205	optimized misc jump sequence
	djnz	r4,00124$
;	Peephole 300	removed redundant label 00150$
;	Peephole 300	removed redundant label 00151$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:125: for(m=0;m<5;m++)
00110$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:130: if(error) break;  
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	b1,00119$
;	Peephole 300	removed redundant label 00152$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:132: while(!TF1);		// Warten bis 35us abgelaufen
00113$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00113$
;	Peephole 300	removed redundant label 00153$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:133: FBOUTC=0;
;	genAssign
	clr	_P1_6
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:111: for(n=0;n<8;n++)		// 8 Datenbits senden
;	genPlus
;     genPlusIncr
	inc	r3
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00116$
00119$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:135: if(!error)
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	b1,00121$
;	Peephole 300	removed redundant label 00154$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:137: delay(212);			// 69 us Pause vor Parity-Bit
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x00D4
	push	bits
	lcall	_delay
	pop	bits
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:138: FBOUTC=parity;
;	genAssign
	mov	c,b0
	mov	_P1_6,c
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:139: delay(95);			// 35us für Parity-Bit
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x005F
	push	bits
	lcall	_delay
	pop	bits
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:140: FBOUTC=0;
;	genAssign
	clr	_P1_6
00121$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:142: TR1=0;
;	genAssign
	clr	_TCON_6
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:144: return error;
;	genRet
	clr	a
	mov	c,b1
	rlc	a
	add	a,#0xff
;	Peephole 300	removed redundant label 00125$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'start_writecycle'
;------------------------------------------------------------
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:148: void start_writecycle(void)
;	-----------------------------------------
;	 function start_writecycle
;	-----------------------------------------
_start_writecycle:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:150: FMCON=0x00;			// load command, leert das pageregister
;	genAssign
	mov	_FMCON,#0x00
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'stop_writecycle'
;------------------------------------------------------------
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:154: void stop_writecycle(void)
;	-----------------------------------------
;	 function stop_writecycle
;	-----------------------------------------
_stop_writecycle:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:156: FMCON=0x68;			// write command, schreibt pageregister ins flash und versetzt CPU in idle für 4ms
;	genAssign
	mov	_FMCON,#0x68
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'write_byte'
;------------------------------------------------------------
;addrl                     Allocated to stack - offset -3
;zdata                     Allocated to stack - offset -4
;addrh                     Allocated to registers r2 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:160: void write_byte(unsigned char addrh, unsigned char addrl, unsigned char zdata)	// schreibt byte ins pageregister zum flashen
;	-----------------------------------------
;	 function write_byte
;	-----------------------------------------
_write_byte:
	push	_bp
	mov	_bp,sp
;	genReceive
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:163: if (addrh<=0x01)		// sicherstellen, dass nicht versehentlich bootloader überschrieben wird
;	genCmpGt
;	genCmp
;	genIfxJump
;	Peephole 132.b	optimized genCmpGt by inverse logic (acc differs)
;	peephole 177.g	optimized mov sequence
	mov	a,dpl
	mov	r2,a
	add	a,#0xff - 0x01
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 160.a	removed sjmp by inverse jump logic
	jc	00103$
;	Peephole 300	removed redundant label 00106$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:165: FMADRH=addrh+0x1C;
;	genPlus
;     genPlusIncr
	mov	a,#0x1C
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	_FMADRH,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:166: FMADRL=addrl;
;	genAssign
	mov	r0,_bp
	dec	r0
	dec	r0
	dec	r0
	mov	_FMADRL,@r0
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:167: FMDATA=zdata;
;	genAssign
	mov	a,_bp
	add	a,#0xfffffffc
	mov	r0,a
	mov	_FMDATA,@r0
00103$:
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay'
;------------------------------------------------------------
;deltime                   Allocated to registers r2 r3 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:172: void delay(int deltime)			// Warten, deltime = Anzahl Takte / 2 (Timer wird mit CCLK/2 betrieben)
;	-----------------------------------------
;	 function delay
;	-----------------------------------------
_delay:
;	genReceive
	mov	r2,dpl
	mov	r3,dph
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:174: TR1=0;				// Timer 1 anhalten
;	genAssign
	clr	_TCON_6
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:175: deltime=0xFFFF-deltime;
;	genMinus
	mov	a,#0xFF
	clr	c
;	Peephole 236.l	used r2 instead of ar2
	subb	a,r2
	mov	r2,a
	mov	a,#0xFF
;	Peephole 236.l	used r3 instead of ar3
	subb	a,r3
	mov	r3,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:176: TH1=deltime>>8;			// Timer 1 setzen 
;	genGetByte
	mov	_TH1,r3
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:177: TL1=deltime;	
;	genCast
	mov	_TL1,r2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:178: TF1=0;
;	genAssign
	clr	_TCON_7
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:179: TR1=1;
;	genAssign
	setb	_TCON_6
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:180: while(!TF1);				// warten auf Timer 1
00101$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00101$
;	Peephole 300	removed redundant label 00108$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:181: TR1=0;		
;	genAssign
	clr	_TCON_6
;	Peephole 300	removed redundant label 00104$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'set_timer1'
;------------------------------------------------------------
;deltime                   Allocated to registers r2 r3 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:185: void set_timer1(int deltime)		// Timer 1 stoppen, setzen und starten (Timer wird mit CCLK/2 betrieben)
;	-----------------------------------------
;	 function set_timer1
;	-----------------------------------------
_set_timer1:
;	genReceive
	mov	r2,dpl
	mov	r3,dph
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:187: TR1=0;				// Timer 1 anhalten
;	genAssign
	clr	_TCON_6
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:188: deltime=0xFFFF-deltime;
;	genMinus
	mov	a,#0xFF
	clr	c
;	Peephole 236.l	used r2 instead of ar2
	subb	a,r2
	mov	r2,a
	mov	a,#0xFF
;	Peephole 236.l	used r3 instead of ar3
	subb	a,r3
	mov	r3,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:189: TH1=deltime>>8;			// Timer 1 setzen 
;	genGetByte
	mov	_TH1,r3
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:190: TL1=deltime;	
;	genCast
	mov	_TL1,r2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:191: TF1=0;				// Überlauf-Flag zurücksetzen
;	genAssign
	clr	_TCON_7
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:192: TR1=1;				// Timer 1 starten
;	genAssign
	setb	_TCON_6
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_byte'
;------------------------------------------------------------
;addrl                     Allocated to stack - offset -3
;addrh                     Allocated to registers r2 
;zdata                     Allocated to registers 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:196: unsigned char read_byte(unsigned char addrh, unsigned char addrl)		// liest byte aus flash
;	-----------------------------------------
;	 function read_byte
;	-----------------------------------------
_read_byte:
	push	_bp
	mov	_bp,sp
;	genReceive
	mov	r2,dpl
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:200: zdata=dataflash[(addrh<<8)+addrl];
;	genCast
;	genLeftShift
;	genLeftShiftLiteral
;	genlshTwo
;	peephole 177.e	removed redundant move
	mov	ar3,r2
	mov	r2,#0x00
;	genCast
	mov	r0,_bp
	dec	r0
	dec	r0
	dec	r0
	mov	ar4,@r0
	mov	r5,#0x00
;	genPlus
;	Peephole 236.g	used r4 instead of ar4
	mov	a,r4
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	r2,a
;	Peephole 236.g	used r5 instead of ar5
	mov	a,r5
;	Peephole 236.b	used r3 instead of ar3
	addc	a,r3
	mov	r3,a
;	genPlus
;     genPlus aligned array
	mov	dpl,r2
	mov	a,#(_dataflash >> 8)
	add	a,r3
	mov	dph,a
;	genPointerGet
;	genCodePointerGet
	clr	a
	movc	a,@a+dptr
;	genAssign
	mov	r2,a
;	Peephole 244.c	loading dpl from a instead of r2
	mov	dpl,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:201: return (zdata);
;	genRet
;	Peephole 300	removed redundant label 00101$
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'restart_hw'
;------------------------------------------------------------
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:205: void restart_hw(void)	// Alle Hardware Einstellungen zurücksetzen
;	-----------------------------------------
;	 function restart_hw
;	-----------------------------------------
_restart_hw:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:209: DIVM=0;		// Taktferquenz nicht teilen -> volles Tempo
;	genAssign
	mov	_DIVM,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:211: P1M1=0x14;		// Port 1 auf quasi-bidirektional, außer P1.2(T0 als PWM Ausgang)=open-drain, P1.4(INT1)=Input only, P1.6(FBOUTC) push-pull
;	genAssign
	mov	_P1M1,#0x14
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:212: P1M2=0x44;
;	genAssign
	mov	_P1M2,#0x44
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:214: FBOUTC=0;		// Bus-Ausgang auf low
;	genAssign
	clr	_P1_6
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:216: TMOD=0x12;		// Timer 0 als PWM, Timer 1 als 16-Bit Timer
;	genAssign
	mov	_TMOD,#0x12
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:217: TAMOD=0x01;
;	genAssign
	mov	_TAMOD,#0x01
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:218: TH0=DUTY;		// Pulsverhältnis PWM
;	genAssign
	mov	_TH0,#0xC0
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:219: AUXR1|=0x10;		// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
;	genOr
	orl	_AUXR1,#0x10
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:221: ET0=0;		// Interrupt für Timer 0 sperren 
;	genAssign
	clr	_IEN0_1
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:222: TR0=1;		// Timer 0 starten (PWM)
;	genAssign
	setb	_TCON_4
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:223: TR1=0;		// Timer 1 (Empfangs-Timeout) zunächst stoppen
;	genAssign
	clr	_TCON_6
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:225: RTCH=0x1D;		// Real Time Clock
;	genAssign
	mov	_RTCH,#0x1D
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:226: RTCL=0x40;
;	genAssign
	mov	_RTCL,#0x40
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:227: RTCCON=0x61;
;	genAssign
	mov	_RTCCON,#0x61
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:229: IEN0=0x00;
;	genAssign
	mov	_IEN0,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:230: IEN1=0x00;
;	genAssign
	mov	_IEN1,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:231: EA=1;			// Interrupts prinzipiell freigeben
;	genAssign
	setb	_IEN0_7
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:232: EX0=0;		// Externen Interrupt 0 sperren
;	genAssign
	clr	_IEN0_0
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:233: EX1=1;		// Externen Interrupt 1 freigeben	
;	genAssign
	setb	_IEN0_2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:235: IP0=0x0C;		// höchste Priorität für ext. Int. 1 und Timer 1 (Bit 0 und 3)
;	genAssign
	mov	_IP0,#0x0C
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:236: IP0H=0x0C;
;	genAssign
	mov	_IP0H,#0x0C
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:237: IP1=0x00;
;	genAssign
	mov	_IP1,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:238: IP1H=0x00;
;	genAssign
	mov	_IP1H,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:239: IT1=1;		// Int1 flankengetriggert=1 pegelgetriggert=0
;	genAssign
	setb	_TCON_2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:241: SCON=0x50;		// Serielle auf Mode 1, receive enable
;	genAssign
	mov	_SCON,#0x50
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:242: SSTAT|=0x40;		// TI wird am Ende des Stopbits gesetzt
;	genOr
	orl	_SSTAT,#0x40
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:243: BRGCON|=0x02;		// Baudrate Generator verwenden aber noch gestoppt
;	genOr
	orl	_BRGCON,#0x02
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:244: BRGR1=0x00;		// Baudrate = cclk/((BRGR1,BRGR0)+16)
;	genAssign
	mov	_BRGR1,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:245: BRGR0=0x30;
;	genAssign
	mov	_BRGR0,#0x30
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_hal_lpc.c:246: BRGCON|=0x01;		// Baudrate Generator starten
;	genOr
	orl	_BRGCON,#0x01
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'timer1'
;------------------------------------------------------------
;data_laenge               Allocated to registers r2 
;daf                       Allocated to registers r3 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:12: void timer1(void) interrupt 3	// Interrupt von Timer 1, 370us keine Busaktivität seit letztem Byte, d.h. Telegramm wurde komplett übertragen
;	-----------------------------------------
;	 function timer1
;	-----------------------------------------
_timer1:
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+2)
	push	(0+3)
	push	(0+4)
	push	(0+5)
	push	(0+6)
	push	(0+7)
	push	(0+0)
	push	(0+1)
	push	bits
	push	psw
	mov	psw,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:16: EX1=0;					// ext. Interrupt stoppen 
;	genAssign
	clr	_IEN0_2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:17: ET1=0;					// Interrupt von Timer 1 sperren
;	genAssign
	clr	_IEN0_3
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:18: set_timer1(4720);				// und neu starten für korrekte Positionierung des ACK Bytes
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x1270
	lcall	_set_timer1
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:20: if(cs==0xff)					// Checksum des Telegramms ist OK 
;	genCmpEq
;	gencjneshort
	mov	a,_cs
	cjne	a,#0xFF,00185$
	sjmp	00186$
00185$:
	ljmp	00152$
00186$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:22: data_laenge=(telegramm[5]&0x0F);		// Telegramm-Länge = Bit 0 bis 3 
;	genAssign
;	genAnd
	mov	a,#0x0F
	anl	a,0x0005 + _telegramm
	mov	r2,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:23: daf=(telegramm[5]&0x80);			// Destination Adress Flag = Bit 7, 0=phys. Adr., 1=Gruppenadr.
;	genAnd
	mov	a,#0x80
	anl	a,0x0005 + _telegramm
	mov	r3,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:25: if(telegramm[3]==0 && telegramm[4]==0)		// Broadcast, wenn Zieladresse = 0
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
;	genIfx
;	peephole 177.g	optimized mov sequence
	mov	a,(_telegramm + 0x0003)
	mov	r4,a
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00148$
;	Peephole 300	removed redundant label 00187$
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	a,(_telegramm + 0x0004)
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00148$
;	Peephole 300	removed redundant label 00188$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:27: if(progmode)
;	genIfx
;	genIfxJump
	jb	_progmode,00189$
	ljmp	00152$
00189$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:29: if(data_laenge==3 && telegramm[6]==0x00 && telegramm[7]==0xC0) set_pa();	// set_pa_req
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r2,#0x03,00102$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00190$
;	Peephole 300	removed redundant label 00191$
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	a,(_telegramm + 0x0006)
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00102$
;	Peephole 300	removed redundant label 00192$
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0007 + _telegramm
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	a,#0xC0,00102$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00193$
;	Peephole 300	removed redundant label 00194$
;	genCall
	lcall	_set_pa
00102$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:30: if(telegramm[6]==0x01 && telegramm[7]==0x00) read_pa();				// read_pa_req
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0006 + _telegramm
	cjne	a,#0x01,00195$
	sjmp	00196$
00195$:
	ljmp	00152$
00196$:
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	a,(_telegramm + 0x0007)
;	genIfx
;	genIfxJump
	jz	00197$
	ljmp	00152$
00197$:
;	genCall
	lcall	_read_pa
	ljmp	00152$
00148$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:35: if(daf==0x00)					// Unicast, wenn Zieladresse physikalische Adresse ist
;	genIfx
	mov	a,r3
;	genIfxJump
	jz	00198$
	ljmp	00145$
00198$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:37: if(telegramm[3]==pah && telegramm[4]==pal)	// nur wenn es die eigene phys. Adr. ist
;	genCmpEq
;	gencjneshort
	mov	a,r4
	cjne	a,_pah,00199$
	sjmp	00200$
00199$:
	ljmp	00152$
00200$:
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0004 + _telegramm
	cjne	a,_pal,00201$
	sjmp	00202$
00201$:
	ljmp	00152$
00202$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:39: if((telegramm[6]&0xC3)==0x42 && (telegramm[7]&0xC0)==0x80) write_memory();	// write_memory_request beantworten
;	genAssign
;	genAnd
	mov	a,#0xC3
	anl	a,0x0006 + _telegramm
	mov	r3,a
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x42,00111$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00203$
;	Peephole 300	removed redundant label 00204$
;	genAssign
;	genAnd
	mov	a,#0xC0
	anl	a,0x0007 + _telegramm
	mov	r3,a
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x80,00111$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00205$
;	Peephole 300	removed redundant label 00206$
;	genCall
	push	ar2
	lcall	_write_memory
	pop	ar2
00111$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:40: if(data_laenge==0)
;	genIfx
	mov	a,r2
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00120$
;	Peephole 300	removed redundant label 00207$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:42: if((telegramm[6]&0xC0)==0xC0) send_ack();				// auf NCD_Quittierung mit ACK antworten
;	genAssign
;	genAnd
	mov	a,#0xC0
	anl	a,0x0006 + _telegramm
	mov	r3,a
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0xC0,00114$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00208$
;	Peephole 300	removed redundant label 00209$
;	genCall
	push	ar2
	lcall	_send_ack
	pop	ar2
00114$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:43: if(telegramm[6]==0x80) ucd_opr();					// UCD Verbindungsaufbau
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0006 + _telegramm
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	a,#0x80,00116$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00210$
;	Peephole 300	removed redundant label 00211$
;	genCall
	push	ar2
	lcall	_ucd_opr
	pop	ar2
00116$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:44: if(telegramm[6]==0x81) ucd_clr();					// UCD Verbindungsabbau
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0006 + _telegramm
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	a,#0x81,00120$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00212$
;	Peephole 300	removed redundant label 00213$
;	genCall
	push	ar2
	lcall	_ucd_clr
	pop	ar2
00120$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:46: if(data_laenge==1)
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r2,#0x01,00128$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00214$
;	Peephole 300	removed redundant label 00215$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:48: if((telegramm[6]&0x03)==0x03 && telegramm[7]==0x80)		// restart request
;	genAssign
;	genAnd
	mov	a,#0x03
	anl	a,0x0006 + _telegramm
	mov	r3,a
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x03,00122$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00216$
;	Peephole 300	removed redundant label 00217$
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0007 + _telegramm
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	a,#0x80,00122$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00218$
;	Peephole 300	removed redundant label 00219$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:50: restart_hw();	// Hardware zurücksetzen
;	genCall
	push	ar2
	lcall	_restart_hw
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:51: restart_prot();	// Protokoll-relevante Parameter zurücksetzen
;	genCall
	push	ar2
	lcall	_restart_prot
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:52: restart_app();	// Anwendungsspezifische Einstellungen zurücksetzen
;	genCall
	push	ar2
	lcall	_restart_app
	pop	ar2
00122$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:54: if(telegramm[6]==0x43 && telegramm[7]==0x00) read_masq();		// Maskenversion angefordert
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0006 + _telegramm
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	a,#0x43,00128$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00220$
;	Peephole 300	removed redundant label 00221$
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	a,(_telegramm + 0x0007)
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00128$
;	Peephole 300	removed redundant label 00222$
;	genCall
	push	ar2
	lcall	_read_masq
	pop	ar2
00128$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:56: if(data_laenge==3)
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r2,#0x03,00152$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00223$
;	Peephole 300	removed redundant label 00224$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:58: if((telegramm[6]&0xC3)==0x42 && (telegramm[7]&0xC0)==0x00) read_memory();	// read_memory_request beantworten
;	genAssign
;	genAnd
	mov	a,#0xC3
	anl	a,0x0006 + _telegramm
	mov	r3,a
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x42,00152$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00225$
;	Peephole 300	removed redundant label 00226$
;	genAssign
;	genAnd
	mov	a,0x0007 + _telegramm
	anl	a,#0xC0
;	Peephole 160.c	removed sjmp by inverse jump logic
	jz	00228$
;	Peephole 300	removed redundant label 00227$
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00152$
00228$:
;	genCall
	lcall	_read_memory
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00152$
00145$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:65: if(data_laenge==1 && telegramm[6]==0x00)
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r2,#0x01,00152$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00229$
;	Peephole 300	removed redundant label 00230$
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	a,(_telegramm + 0x0006)
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00152$
;	Peephole 300	removed redundant label 00231$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:67: if ((telegramm[7]&0xFE)==0x80) eis1();		// Ausgänge schalten (EIS 1)
;	genAssign
;	genAnd
	mov	a,#0xFE
	anl	a,0x0007 + _telegramm
	mov	r2,a
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r2,#0x80,00138$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00232$
;	Peephole 300	removed redundant label 00233$
;	genCall
	lcall	_eis1
00138$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:68: if (telegramm[7]==0x00) read_value_req();		// Objektwert lesen und als read_value_res auf Bus senden
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	a,(_telegramm + 0x0007)
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00152$
;	Peephole 300	removed redundant label 00234$
;	genCall
	lcall	_read_value_req
00152$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:73: telpos=0;  
;	genAssign
	mov	_telpos,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:74: IE1=0;		// IRQ zurücksetzen
;	genAssign
	clr	_TCON_3
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:75: EX1=1;		// externen Interrupt 0 wieder freigeben
;	genAssign
	setb	_IEN0_2
;	Peephole 300	removed redundant label 00153$
	pop	psw
	pop	bits
	pop	(0+1)
	pop	(0+0)
	pop	(0+7)
	pop	(0+6)
	pop	(0+5)
	pop	(0+4)
	pop	(0+3)
	pop	(0+2)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	reti
;------------------------------------------------------------
;Allocation info for local variables in function 'get_ack'
;------------------------------------------------------------
;ret                       Allocated to registers r2 
;n                         Allocated to registers r3 r4 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:82: unsigned char get_ack(void)		// Byte empfangen und prüfen ob es ein ACK war
;	-----------------------------------------
;	 function get_ack
;	-----------------------------------------
_get_ack:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:88: ret=0;
;	genAssign
	mov	r2,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:89: do 
;	genAssign
	mov	r3,#0x00
	mov	r4,#0x00
00107$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_P1_4,00105$
;	Peephole 300	removed redundant label 00118$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:91: if(FBINC==1) n++;
;	genPlus
;     genPlusIncr
	inc	r3
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 243	avoided branch to sjmp
	cjne	r3,#0x00,00108$
	inc	r4
;	Peephole 300	removed redundant label 00119$
	sjmp	00108$
00105$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:94: if (get_byte()==0xCC && parity_ok) ret=1;
;	genCall
	push	ar2
	push	ar3
	push	ar4
	lcall	_get_byte
	mov	r5,dpl
	pop	ar4
	pop	ar3
	pop	ar2
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r5,#0xCC,00108$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00120$
;	Peephole 300	removed redundant label 00121$
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_parity_ok,00108$
;	Peephole 300	removed redundant label 00122$
;	genAssign
	mov	r2,#0x01
00108$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:96: } while (n<3000);
;	genCmpLt
;	genCmp
	clr	c
	mov	a,r3
	subb	a,#0xB8
	mov	a,r4
	xrl	a,#0x80
	subb	a,#0x8b
;	genIfxJump
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 160.a	removed sjmp by inverse jump logic
	jc	00107$
;	Peephole 300	removed redundant label 00123$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:97: return(ret);
;	genRet
	mov	dpl,r2
;	Peephole 300	removed redundant label 00110$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'send_telegramm'
;------------------------------------------------------------
;data_laenge               Allocated to stack - offset 1
;l                         Allocated to registers r5 
;checksum                  Allocated to registers r3 
;r                         Allocated to registers r2 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:102: void send_telegramm(void)		// sendet das Telegramm, das in telegramm[] vorher abgelegt wurde und berechnet die checksum
;	-----------------------------------------
;	 function send_telegramm
;	-----------------------------------------
_send_telegramm:
	push	_bp
	mov	_bp,sp
	inc	sp
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:106: r=0;
;	genAssign
	mov	r2,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:107: do
00108$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:109: checksum=0;
;	genAssign
	mov	r3,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:110: data_laenge=telegramm[5]&0x0F;	// Telegramm-Länge = Bit 0 bis 3
;	genAssign
;	genAnd
	mov	r0,_bp
	inc	r0
	mov	a,#0x0F
	anl	a,0x0005 + _telegramm
	mov	@r0,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:112: set_timer1(18780);			// Warten bis Bus frei ist
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x495C
	push	ar2
	push	ar3
	lcall	_set_timer1
	pop	ar3
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:113: while(!TF1)
00103$:
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	_TCON_7,00105$
;	Peephole 300	removed redundant label 00125$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:115: if(!FBINC) set_timer1(18780);
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	_P1_4,00103$
;	Peephole 300	removed redundant label 00126$
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x495C
	push	ar2
	push	ar3
	lcall	_set_timer1
	pop	ar3
	pop	ar2
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00103$
00105$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:117: TR1=0;
;	genAssign
	clr	_TCON_6
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:119: for(l=0;l<=data_laenge+6;l++)
;	genAssign
	mov	r5,#0x00
00111$:
;	genIpush
	push	ar2
;	genCast
	mov	r0,_bp
	inc	r0
	mov	ar6,@r0
	mov	r7,#0x00
;	genPlus
;     genPlusIncr
	mov	a,#0x06
;	Peephole 236.a	used r6 instead of ar6
	add	a,r6
	mov	r6,a
;	Peephole 181	changed mov to clr
	clr	a
;	Peephole 236.b	used r7 instead of ar7
	addc	a,r7
	mov	r7,a
;	genCast
	mov	ar2,r5
	mov	r4,#0x00
;	genCmpGt
;	genCmp
	clr	c
	mov	a,r6
	subb	a,r2
	mov	a,r7
	xrl	a,#0x80
	mov	b,r4
	xrl	b,#0x80
	subb	a,b
;	genIpop
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
;	Peephole 129.b	optimized condition
	pop	ar2
	jc	00114$
;	Peephole 300	removed redundant label 00127$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:121: sendbyte(telegramm[l]);
;	genPlus
;	Peephole 236.g	used r5 instead of ar5
	mov	a,r5
	add	a,#_telegramm
	mov	r0,a
;	genPointerGet
;	genNearPointerGet
	mov	dpl,@r0
;	genCall
	push	ar2
	push	ar3
	push	ar5
	lcall	_sendbyte
	pop	ar5
	pop	ar3
	pop	ar2
	clr	a
	rlc	a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:122: checksum^=telegramm[l];
;	genPlus
;	Peephole 236.g	used r5 instead of ar5
	mov	a,r5
	add	a,#_telegramm
	mov	r0,a
;	genPointerGet
;	genNearPointerGet
	mov	ar4,@r0
;	genXor
	mov	a,r4
	xrl	ar3,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:123: delay(1230);			// Interbyte-Abstand
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x04CE
	push	ar2
	push	ar3
	push	ar5
	lcall	_delay
	pop	ar5
	pop	ar3
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:119: for(l=0;l<=data_laenge+6;l++)
;	genPlus
;     genPlusIncr
	inc	r5
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00111$
00114$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:125: checksum=~checksum;
;	genCpl
	mov	a,r3
	cpl	a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:126: sendbyte(checksum);
;	genCall
	mov	r3,a
;	Peephole 244.c	loading dpl from a instead of r3
	mov	dpl,a
	push	ar2
	lcall	_sendbyte
	pop	ar2
	clr	a
	rlc	a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:127: if(get_ack()==1) r=3;		// wenn ACK empfangen, dann nicht nochmal senden
;	genCall
	push	ar2
	lcall	_get_ack
	mov	r3,dpl
	pop	ar2
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x01,00107$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00128$
;	Peephole 300	removed redundant label 00129$
;	genAssign
	mov	r2,#0x03
00107$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:128: r++;
;	genPlus
;     genPlusIncr
	inc	r2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:129: telegramm[0]&=0xDF;			// Bit 5 löschen = Wiederholung
;	genAssign
;	genAnd
	mov	a,#0xDF
	anl	a,_telegramm
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:131: while(r<=3); 				// falls kein ACK max. 3 Mal wiederholen
;	genCmpGt
;	genCmp
;	genIfxJump
;	Peephole 132.c	optimized genCmpGt by inverse logic (acc differs)
	mov	a,r2
	add	a,#0xff - 0x03
	jc	00130$
	ljmp	00108$
00130$:
;	Peephole 300	removed redundant label 00115$
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'send_ack'
;------------------------------------------------------------
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:135: void send_ack(void)			// wartet auf Timer 1 wegen korrekter Positionierung und sendet ACK (0xCC)
;	-----------------------------------------
;	 function send_ack
;	-----------------------------------------
_send_ack:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:137: while(!TF1) {}
00101$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00101$
;	Peephole 300	removed redundant label 00108$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:138: sendbyte(0xCC);
;	genCall
	mov	dpl,#0xCC
	lcall	_sendbyte
	clr	a
	rlc	a
;	Peephole 300	removed redundant label 00104$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ucd_opr'
;------------------------------------------------------------
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:145: void ucd_opr(void)		// UCD Verbindungsaufbau
;	-----------------------------------------
;	 function ucd_opr
;	-----------------------------------------
_ucd_opr:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:147: if(!connected)		// wenn bereits verbunden: ignorieren
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	_connected,00103$
;	Peephole 300	removed redundant label 00106$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:149: connected=1;
;	genAssign
	setb	_connected
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:150: conh=telegramm[1];		// phys. Adresse des Verbindungspartners
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	_conh,(_telegramm + 0x0001)
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:151: conl=telegramm[2];
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	_conl,(_telegramm + 0x0002)
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:152: send_ack();			// quittieren
;	genCall
	lcall	_send_ack
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:153: pcount=1;			// Paketzähler zurücksetzen
;	genAssign
	mov	_pcount,#0x01
00103$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ucd_clr'
;------------------------------------------------------------
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:158: void ucd_clr(void)		// UCD Verbindungsabbau
;	-----------------------------------------
;	 function ucd_clr
;	-----------------------------------------
_ucd_clr:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:160: if(conh==telegramm[1] && conl==telegramm[2] && connected)	// nur abbauen, wenn verbunden und Anforderung vom Verbindungspartner, kein ACK senden
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,_conh
	cjne	a,0x0001 + _telegramm,00110$
	sjmp	00111$
00110$:
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 251.b	replaced sjmp to ret with ret
	ret
00111$:
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,_conl
	cjne	a,0x0002 + _telegramm,00112$
	sjmp	00113$
00112$:
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 251.b	replaced sjmp to ret with ret
	ret
00113$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:162: connected=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_connected,00114$
;	Peephole 251.b	replaced sjmp to ret with ret
	ret
00114$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:163: pcount=1;			// Paketzähler zurücksetzen
;	genAssign
	mov	_pcount,#0x01
;	Peephole 300	removed redundant label 00105$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ncd_quit'
;------------------------------------------------------------
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:168: void ncd_quit(void)			// NCD Quittierung zurück senden. Setzt telegramm Bytes 0 bis 6 !!!
;	-----------------------------------------
;	 function ncd_quit
;	-----------------------------------------
_ncd_quit:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:170: telegramm[0]=0xB0;			// Control Byte			
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,#0xB0
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:171: telegramm[3]=telegramm[1];		// Zieladresse wird Quelladresse
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	r2,(_telegramm + 0x0001)
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0003),r2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:172: telegramm[4]=telegramm[2];
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	r2,(_telegramm + 0x0002)
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0004),r2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:173: telegramm[1]=pah;			// Quelladresse ist phys. Adresse
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0001),_pah
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:174: telegramm[2]=pal;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0002),_pal
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:175: telegramm[5]=0x60;			// DRL
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0005),#0x60
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:176: telegramm[6]|=0xC0;			// Bit 6 und 7 setzen (TCPI = 11 NCD Quittierung)
;	genAssign
;	genOr
	mov	a,#0xC0
	orl	a,0x0006 + _telegramm
	mov	r2,a
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),r2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:177: telegramm[6]&=0xFE;			// Bit 0 löschen 
;	genAnd
	mov	a,#0xFE
	anl	a,r2
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:178: send_telegramm();
;	genCall
;	Peephole 253.b	replaced lcall/ret with ljmp
	ljmp	_send_telegramm
;
;------------------------------------------------------------
;Allocation info for local variables in function 'read_masq'
;------------------------------------------------------------
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:182: void read_masq(void)			// Maskenversion senden
;	-----------------------------------------
;	 function read_masq
;	-----------------------------------------
_read_masq:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:186: send_ack();
;	genCall
	lcall	_send_ack
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:187: ncd_quit();				// NCD Quittierung senden
;	genCall
	lcall	_ncd_quit
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:189: telegramm[0]=0xB0;			// Control Byte
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,#0xB0
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:191: telegramm[5]=0x63;			// DRL
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0005),#0x63
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:192: telegramm[6]=0x43;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),#0x43
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:193: telegramm[7]=0x40;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),#0x40
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:194: telegramm[8]=0x00;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0008),#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:195: telegramm[9]=0x12;			// Maskenversion 1 = BCU1
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0009),#0x12
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:196: send_telegramm();
;	genCall
;	Peephole 253.b	replaced lcall/ret with ljmp
	ljmp	_send_telegramm
;
;------------------------------------------------------------
;Allocation info for local variables in function 'read_memory'
;------------------------------------------------------------
;ab                        Allocated to registers r2 
;n                         Allocated to registers r3 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:201: void read_memory(void)			// read_memory_request - Speicher auslesen und senden
;	-----------------------------------------
;	 function read_memory
;	-----------------------------------------
_read_memory:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:205: send_ack();				// erstmal quittieren
;	genCall
	lcall	_send_ack
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:206: ab=telegramm[7];			// Anzahl Bytes
;	genAssign
;	genAssign
	mov	r2,0x0007 + _telegramm
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:207: ncd_quit();
;	genCall
	push	ar2
	lcall	_ncd_quit
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:209: for(n=0;n<ab;n++)
;	genAssign
	mov	r3,#0x00
00101$:
;	genCmpLt
;	genCmp
	clr	c
	mov	a,r3
	subb	a,r2
;	genIfxJump
;	Peephole 108.a	removed ljmp by inverse jump logic
	jnc	00104$
;	Peephole 300	removed redundant label 00110$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:211: telegramm[n+10]=read_byte(telegramm[8],(telegramm[9]+n));    
;	genPlus
;     genPlusIncr
	mov	a,#0x0A
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
;	genPlus
	add	a,#_telegramm
	mov	r0,a
;	genAssign
;	genPlus
;	Peephole 236.g	used r3 instead of ar3
	mov	a,r3
	add	a,0x0009 + _telegramm
	mov	r4,a
;	genAssign
;	genIpush
	push	ar2
	push	ar3
	push	ar0
	push	ar4
;	genCall
	mov	dpl,0x0008 + _telegramm
	lcall	_read_byte
	mov	r4,dpl
	dec	sp
	pop	ar0
	pop	ar3
	pop	ar2
;	genPointerSet
;	genNearPointerSet
	mov	@r0,ar4
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:209: for(n=0;n<ab;n++)
;	genPlus
;     genPlusIncr
	inc	r3
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00101$
00104$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:214: telegramm[0]=0xB0;			// read_memory_res senden
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,#0xB0
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:216: telegramm[5]=ab+0x63;		// DRL (Anzahl Bytes + 3)
;	genPlus
;     genPlusIncr
	mov	a,#0x63
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0005),a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:217: telegramm[6]=(pcount<<2)|0x42;	// Paketzähler, TCPI und ersten beiden Befehlsbits
;	genLeftShift
;	genLeftShiftLiteral
;	genlshOne
	mov	a,_pcount
;	Peephole 254	optimized left shift
	add	a,_pcount
	add	a,acc
	mov	r3,a
;	genOr
	mov	a,#0x42
	orl	a,r3
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:218: telegramm[7]=ab|0x40;		// letzten 2 Befehlsbits
;	genOr
	mov	a,#0x40
	orl	a,r2
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:219: send_telegramm();
;	genCall
	lcall	_send_telegramm
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:221: pcount++;				// Paketzähler erhöhen
;	genPlus
;     genPlusIncr
	inc	_pcount
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:222: pcount&=0x0F;				// max. 15
;	genAnd
	anl	_pcount,#0x0F
;	Peephole 300	removed redundant label 00105$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'write_memory'
;------------------------------------------------------------
;ab                        Allocated to registers r2 
;n                         Allocated to registers r3 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:226: void write_memory(void)			// write_memory_request - empfangene Daten in Speicher schreiben
;	-----------------------------------------
;	 function write_memory
;	-----------------------------------------
_write_memory:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:230: send_ack();
;	genCall
	lcall	_send_ack
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:231: ab=telegramm[7]&0x0F;			// Anzahl Bytes
;	genAssign
;	genAnd
	mov	a,#0x0F
	anl	a,0x0007 + _telegramm
	mov	r2,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:232: ncd_quit();
;	genCall
	push	ar2
	lcall	_ncd_quit
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:234: start_writecycle();
;	genCall
	push	ar2
	lcall	_start_writecycle
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:235: for(n=0;n<ab;n++) 
;	genAssign
	mov	r3,#0x00
00104$:
;	genCmpLt
;	genCmp
	clr	c
	mov	a,r3
	subb	a,r2
;	genIfxJump
;	Peephole 108.a	removed ljmp by inverse jump logic
	jnc	00107$
;	Peephole 300	removed redundant label 00115$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:237: write_byte(telegramm[8],telegramm[9]+n,telegramm[n+10]);
;	genPlus
;     genPlusIncr
	mov	a,#0x0A
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
;	genPlus
	add	a,#_telegramm
	mov	r0,a
;	genPointerGet
;	genNearPointerGet
	mov	ar4,@r0
;	genAssign
;	genPlus
;	Peephole 236.g	used r3 instead of ar3
	mov	a,r3
	add	a,0x0009 + _telegramm
	mov	r5,a
;	genAssign
;	genIpush
	push	ar2
	push	ar3
	push	ar4
;	genIpush
	push	ar5
;	genCall
	mov	dpl,0x0008 + _telegramm
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar3
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:238: if ((((telegramm[9]+n)&0x3F)==0x3F) && n!=(ab-1))		// Ende des 64-Byte Pageregisters, also zwischendurch flashen
;	genAssign
;	genCast
	mov	r4,0x0009 + _telegramm
	mov	r5,#0x00
;	genCast
	mov	ar6,r3
	mov	r7,#0x00
;	genPlus
;	Peephole 236.g	used r6 instead of ar6
	mov	a,r6
;	Peephole 236.a	used r4 instead of ar4
	add	a,r4
	mov	r4,a
;	Peephole 236.g	used r7 instead of ar7
	mov	a,r7
;	Peephole 236.b	used r5 instead of ar5
	addc	a,r5
	mov	r5,a
;	genAnd
	anl	ar4,#0x3F
	mov	r5,#0x00
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.a	optimized misc jump sequence
	cjne	r4,#0x3F,00106$
	cjne	r5,#0x00,00106$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00116$
;	Peephole 300	removed redundant label 00117$
;	genCast
	mov	ar4,r2
	mov	r5,#0x00
;	genMinus
;	genMinusDec
	dec	r4
	cjne	r4,#0xff,00118$
	dec	r5
00118$:
;	genCmpEq
;	gencjneshort
	mov	a,r6
	cjne	a,ar4,00119$
	mov	a,r7
	cjne	a,ar5,00119$
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00106$
00119$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:240: stop_writecycle();
;	genCall
	push	ar2
	push	ar3
	lcall	_stop_writecycle
	pop	ar3
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:241: start_writecycle();
;	genCall
	push	ar2
	push	ar3
	lcall	_start_writecycle
	pop	ar3
	pop	ar2
00106$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:235: for(n=0;n<ab;n++) 
;	genPlus
;     genPlusIncr
	inc	r3
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00104$
00107$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:244: stop_writecycle(); 
;	genCall
;	Peephole 253.b	replaced lcall/ret with ljmp
	ljmp	_stop_writecycle
;
;------------------------------------------------------------
;Allocation info for local variables in function 'set_pa'
;------------------------------------------------------------
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:248: void set_pa(void)			// neue phys. Adresse programmieren
;	-----------------------------------------
;	 function set_pa
;	-----------------------------------------
_set_pa:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:250: pah=telegramm[8];
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	_pah,(_telegramm + 0x0008)
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:251: pal=telegramm[9];
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	_pal,(_telegramm + 0x0009)
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:252: start_writecycle();
;	genCall
	lcall	_start_writecycle
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:253: write_byte(0x01,ADDRTAB+1,pah);		// in Flash schreiben
;	genIpush
	push	_pah
;	genIpush
	mov	a,#0x17
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_write_byte
	dec	sp
	dec	sp
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:254: write_byte(0x01,ADDRTAB+2,pal);
;	genIpush
	push	_pal
;	genIpush
	mov	a,#0x18
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_write_byte
	dec	sp
	dec	sp
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:255: stop_writecycle();
;	genCall
;	Peephole 253.b	replaced lcall/ret with ljmp
	ljmp	_stop_writecycle
;
;------------------------------------------------------------
;Allocation info for local variables in function 'read_pa'
;------------------------------------------------------------
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:259: void read_pa(void)			// phys. Adresse senden
;	-----------------------------------------
;	 function read_pa
;	-----------------------------------------
_read_pa:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:263: send_ack();
;	genCall
	lcall	_send_ack
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:265: telegramm[0]=0xB0;			// read_memory_res senden
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,#0xB0
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:267: telegramm[1]=pah;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0001),_pah
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:268: telegramm[2]=pal;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0002),_pal
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:269: telegramm[3]=0x00;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0003),#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:270: telegramm[4]=0x00;			
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0004),#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:271: telegramm[5]=0xE1;			// DRL
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0005),#0xE1
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:272: telegramm[6]=0x01;		
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),#0x01
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:273: telegramm[7]=0x40;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),#0x40
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:274: send_telegramm();
;	genCall
;	Peephole 253.b	replaced lcall/ret with ljmp
	ljmp	_send_telegramm
;
;------------------------------------------------------------
;Allocation info for local variables in function 'read_objflags'
;------------------------------------------------------------
;objno                     Allocated to registers r2 
;ctp                       Allocated to registers 
;addr                      Allocated to registers 
;flags                     Allocated to registers 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:279: unsigned char read_objflags(unsigned char objno)	// Objektflags lesen
;	-----------------------------------------
;	 function read_objflags
;	-----------------------------------------
_read_objflags:
;	genReceive
	mov	r2,dpl
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:283: ctp=read_byte(0x01,COMMSTABPTR);		// COMMSTAB Pointer
;	genIpush
	push	ar2
	mov	a,#0x12
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r3,dpl
	dec	sp
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:284: addr=ctp+3+3*objno;
;	genPlus
;     genPlusIncr
	inc	r3
	inc	r3
	inc	r3
;	genMult
;	genMultOneByte
	mov	a,r2
	mov	b,#0x03
	mul	ab
;	genPlus
	mov	r2,a
;	Peephole 177.b	removed redundant mov
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r3,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:285: flags=read_byte(0x01,addr);	// Objektflags
;	genIpush
	push	ar3
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r2,dpl
	dec	sp
;	genAssign
	mov	dpl,r2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:286: return(flags);
;	genRet
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'find_ga'
;------------------------------------------------------------
;objno                     Allocated to registers r2 
;n                         Allocated to registers r7 
;assno                     Allocated to registers r5 
;asstab                    Allocated to registers r4 
;gapos                     Allocated to registers r3 
;gal                       Allocated to registers r3 
;gah                       Allocated to registers r2 
;ga                        Allocated to registers r3 r2 
;sloc0                     Allocated to stack - offset 1
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:290: int find_ga(unsigned char objno)		// Gruppenadresse über Assoziationstabelle finden (letzter Eintrag, falls mehrere)
;	-----------------------------------------
;	 function find_ga
;	-----------------------------------------
_find_ga:
	push	_bp
	mov	_bp,sp
	inc	sp
;	genReceive
	mov	r2,dpl
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:295: gapos=0;
;	genAssign
	mov	r3,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:296: asstab=read_byte(0x01,ASSOCTABPTR);
;	genIpush
	push	ar2
	push	ar3
	mov	a,#0x11
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r4,dpl
	dec	sp
	pop	ar3
	pop	ar2
;	genAssign
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:297: assno=read_byte(0x01,asstab);
;	genIpush
	push	ar2
	push	ar3
	push	ar4
	push	ar4
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r5,dpl
	dec	sp
	pop	ar4
	pop	ar3
	pop	ar2
;	genAssign
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:298: for(n=0;n<assno;n++)
;	genPlus
;     genPlusIncr
	mov	a,#0x01
;	Peephole 236.a	used r4 instead of ar4
	add	a,r4
	mov	r6,a
;	genPlus
;     genPlusIncr
	inc	r4
	inc	r4
;	genAssign
	mov	r7,#0x00
00106$:
;	genCmpLt
;	genCmp
	clr	c
	mov	a,r7
	subb	a,r5
;	genIfxJump
;	Peephole 108.a	removed ljmp by inverse jump logic
	jnc	00109$
;	Peephole 300	removed redundant label 00117$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:300: if(read_byte(0x01,asstab+2+2*n)==objno)
;	genIpush
	push	ar3
;	genLeftShift
;	genLeftShiftLiteral
	mov	r0,_bp
	inc	r0
;	genlshOne
	mov	a,r7
;	Peephole 254	optimized left shift
	add	a,r7
	mov	@r0,a
;	genPlus
	mov	r0,_bp
	inc	r0
	mov	a,@r0
;	Peephole 236.a	used r4 instead of ar4
	add	a,r4
	mov	r3,a
;	genIpush
	push	ar2
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	ar3
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r3,dpl
	dec	sp
	pop	ar7
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar2
;	genCmpEq
;	gencjne
;	gencjneshort
	mov	a,r3
	cjne	a,ar2,00118$
	mov	a,#0x01
	sjmp	00119$
00118$:
	clr	a
00119$:
;	genIpop
	pop	ar3
;	genIfx
;	genIfxJump
;	Peephole 108.c	removed ljmp by inverse jump logic
	jz	00108$
;	Peephole 300	removed redundant label 00120$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:302: gapos=read_byte(0x01,asstab+1+2*n);
;	genIpush
	push	ar4
;	genPlus
	mov	r0,_bp
	inc	r0
	mov	a,@r0
;	Peephole 236.a	used r6 instead of ar6
	add	a,r6
	mov	r4,a
;	genIpush
	push	ar2
	push	ar5
	push	ar6
	push	ar7
	push	ar4
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r4,dpl
	dec	sp
	pop	ar7
	pop	ar6
	pop	ar5
	pop	ar2
;	genAssign
	mov	ar3,r4
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:315: return(ga);
;	genIpop
	pop	ar4
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:302: gapos=read_byte(0x01,asstab+1+2*n);
00108$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:298: for(n=0;n<assno;n++)
;	genPlus
;     genPlusIncr
	inc	r7
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00106$
00109$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:305: if(gapos!=0)
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x00,00121$
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00104$
00121$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:307: gah=read_byte(0x01,ADDRTAB+1+gapos*2);
;	genLeftShift
;	genLeftShiftLiteral
;	genlshOne
	mov	a,r3
;	Peephole 254	optimized left shift
	add	a,r3
	mov	r3,a
;	genPlus
;     genPlusIncr
	mov	a,#0x17
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r2,a
;	genIpush
	push	ar3
	push	ar2
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r2,dpl
	dec	sp
	pop	ar3
;	genAssign
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:308: gal=read_byte(0x01,ADDRTAB+2+gapos*2);
;	genPlus
;     genPlusIncr
	mov	a,#0x18
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r3,a
;	genIpush
	push	ar2
	push	ar3
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r3,dpl
	dec	sp
	pop	ar2
;	genAssign
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:309: ga=gal+256*gah;
;	genCast
	mov	r4,#0x00
;	genCast
;	genLeftShift
;	genLeftShiftLiteral
;	genlshTwo
;	peephole 177.e	removed redundant move
	mov	ar5,r2
	mov	r2,#0x00
;	genPlus
;	Peephole 236.g	used r2 instead of ar2
	mov	a,r2
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r3,a
;	Peephole 236.g	used r5 instead of ar5
	mov	a,r5
;	Peephole 236.b	used r4 instead of ar4
	addc	a,r4
	mov	r4,a
;	genAssign
	mov	ar2,r4
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00105$
00104$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:313: ga=0;
;	genAssign
	mov	r3,#0x00
	mov	r2,#0x00
00105$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:315: return(ga);
;	genRet
	mov	dpl,r3
	mov	dph,r2
;	Peephole 300	removed redundant label 00110$
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'gapos_in_gat'
;------------------------------------------------------------
;gal                       Allocated to stack - offset -3
;gah                       Allocated to registers r2 
;ga_position               Allocated to registers r4 
;ga_count                  Allocated to registers r3 
;n                         Allocated to registers 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:319: unsigned char gapos_in_gat(unsigned char gah, unsigned char gal)
;	-----------------------------------------
;	 function gapos_in_gat
;	-----------------------------------------
_gapos_in_gat:
	push	_bp
	mov	_bp,sp
;	genReceive
	mov	r2,dpl
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:323: ga_count=read_byte(0x01,ADDRTAB);
;	genIpush
	push	ar2
	mov	a,#0x16
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r3,dpl
	dec	sp
	pop	ar2
;	genAssign
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:324: ga_position=0xFF; 
;	genAssign
	mov	r4,#0xFF
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:325: if (ga_count>0)
;	genIfx
	mov	a,r3
;	genIfxJump
;	Peephole 108.c	removed ljmp by inverse jump logic
	jz	00105$
;	Peephole 300	removed redundant label 00118$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:327: for (n=1;n<=ga_count;n++)
;	genAssign
	mov	r5,#0x01
00106$:
;	genCmpGt
;	genCmp
	clr	c
	mov	a,r3
	subb	a,r5
;	genIfxJump
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 160.a	removed sjmp by inverse jump logic
	jc	00105$
;	Peephole 300	removed redundant label 00119$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:329: if (gah==read_byte(0x01,ADDRTAB+n*2+1) && gal==read_byte(0x01,ADDRTAB+n*2+2)) ga_position=n;
;	genLeftShift
;	genLeftShiftLiteral
;	genlshOne
	mov	a,r5
;	Peephole 254	optimized left shift
	add	a,r5
	mov	r6,a
;	genPlus
;     genPlusIncr
	mov	a,#0x17
;	Peephole 236.a	used r6 instead of ar6
	add	a,r6
	mov	r7,a
;	genIpush
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r7,dpl
	dec	sp
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	genCmpEq
;	gencjneshort
	mov	a,r2
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	a,ar7,00108$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00120$
;	Peephole 300	removed redundant label 00121$
;	genPlus
;     genPlusIncr
	mov	a,#0x18
;	Peephole 236.a	used r6 instead of ar6
	add	a,r6
	mov	r6,a
;	genIpush
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r6,dpl
	dec	sp
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	genCmpEq
	mov	r0,_bp
	dec	r0
	dec	r0
	dec	r0
;	gencjneshort
	mov	a,@r0
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	a,ar6,00108$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00122$
;	Peephole 300	removed redundant label 00123$
;	genAssign
	mov	ar4,r5
00108$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:327: for (n=1;n<=ga_count;n++)
;	genPlus
;     genPlusIncr
	inc	r5
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00106$
00105$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:332: return (ga_position);
;	genRet
	mov	dpl,r4
;	Peephole 300	removed redundant label 00110$
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'write_delay_record'
;------------------------------------------------------------
;delay_status              Allocated to stack - offset -3
;delay_target              Allocated to stack - offset -7
;objno                     Allocated to registers r2 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:336: void write_delay_record(unsigned char objno, unsigned char delay_status, long delay_target)		// Schreibt die Schalt-Verzögerungswerte ins Flash
;	-----------------------------------------
;	 function write_delay_record
;	-----------------------------------------
_write_delay_record:
	push	_bp
	mov	_bp,sp
;	genReceive
	mov	r2,dpl
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:338: start_writecycle();
;	genCall
	push	ar2
	lcall	_start_writecycle
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:339: write_byte(0x00,objno*5,objno+delay_status);
;	genPlus
	mov	r0,_bp
	dec	r0
	dec	r0
	dec	r0
	mov	a,@r0
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	r3,a
;	genMult
;	genMultOneByte
	mov	a,r2
	mov	b,#0x05
	mul	ab
	mov	r2,a
;	genIpush
	push	ar2
	push	ar3
;	genIpush
	push	ar2
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:340: write_byte(0x00,1+objno*5,delay_target>>24);
;	genGetByte
	mov	a,_bp
	add	a,#0xfffffff9
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
	mov	r0,a
	mov	ar3,@r0
;	genPlus
;     genPlusIncr
	mov	a,#0x01
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	r4,a
;	genIpush
	push	ar2
	push	ar3
;	genIpush
	push	ar4
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:341: write_byte(0x00,2+objno*5,delay_target>>16);
;	genGetByte
	mov	a,_bp
	add	a,#0xfffffff9
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
	mov	r0,a
	mov	ar3,@r0
;	genPlus
;     genPlusIncr
	mov	a,#0x02
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	r4,a
;	genIpush
	push	ar2
	push	ar3
;	genIpush
	push	ar4
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:342: write_byte(0x00,3+objno*5,delay_target>>8);
;	genGetByte
	mov	a,_bp
	add	a,#0xfffffff9
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
	mov	r0,a
	mov	ar3,@r0
;	genPlus
;     genPlusIncr
	mov	a,#0x03
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	r4,a
;	genIpush
	push	ar2
	push	ar3
;	genIpush
	push	ar4
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar2
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:343: write_byte(0x00,4+objno*5,delay_target);
;	genCast
	mov	a,_bp
	add	a,#0xfffffff9
	mov	r0,a
	mov	ar3,@r0
;	genPlus
;     genPlusIncr
	mov	a,r2
	add	a,#0x04
	mov	r2,a
;	genIpush
	push	ar3
;	genIpush
	push	ar2
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:344: stop_writecycle();
;	genCall
	lcall	_stop_writecycle
;	Peephole 300	removed redundant label 00101$
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'restart_prot'
;------------------------------------------------------------
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:348: void restart_prot(void)		// Protokoll-relevante Parameter zurücksetzen
;	-----------------------------------------
;	 function restart_prot
;	-----------------------------------------
_restart_prot:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:350: pah=read_byte(0x01,ADDRTAB+1);	// phys. Adresse einlesen
;	genIpush
	mov	a,#0x17
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	_pah,dpl
	dec	sp
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:351: pal=read_byte(0x01,ADDRTAB+2);
;	genIpush
	mov	a,#0x18
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	_pal,dpl
	dec	sp
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:353: progmode=0;			// kein Programmiermodus
;	genAssign
	clr	_progmode
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:354: pcount=1;			// Paketzähler initialisieren
;	genAssign
	mov	_pcount,#0x01
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:355: connected=0;			// keine Verbindung
;	genAssign
	clr	_connected
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_prot.c:357: telpos=0;			// empfangene Bytes an dieser Position im Array telegramm[] ablegen
;	genAssign
	mov	_telpos,#0x00
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'rs_init'
;------------------------------------------------------------
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:2: void rs_init(void)
;	-----------------------------------------
;	 function rs_init
;	-----------------------------------------
_rs_init:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:4: SCON=0x50;	//Mode 1, receive enable
;	genAssign
	mov	_SCON,#0x50
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:5: SSTAT|=0x40;	// TI wird am Ende des Stopbits gesetzt
;	genOr
	orl	_SSTAT,#0x40
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:6: BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
;	genOr
	orl	_BRGCON,#0x02
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:7: BRGR1=0x00;	// Baudrate = cclk/((BRGR1,BRGR0)+16)
;	genAssign
	mov	_BRGR1,#0x00
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:8: BRGR0=0x30;
;	genAssign
	mov	_BRGR0,#0x30
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:9: BRGCON|=0x01;	// Baudrate Generator starten
;	genOr
	orl	_BRGCON,#0x01
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'rs_send_dec'
;------------------------------------------------------------
;wert                      Allocated to registers r2 
;n                         Allocated to registers r3 
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:12: void rs_send_dec(unsigned char wert)
;	-----------------------------------------
;	 function rs_send_dec
;	-----------------------------------------
_rs_send_dec:
;	genReceive
	mov	r2,dpl
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:16: n=wert/100;
;	genDiv
;     genDivOneByte
	mov	b,#0x64
	mov	a,r2
	div	ab
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:17: if(n>0)
;	genIfx
	mov	r3,a
;	Peephole 105	removed redundant mov
;	genIfxJump
;	Peephole 108.c	removed ljmp by inverse jump logic
	jz	00105$
;	Peephole 300	removed redundant label 00124$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:19: SBUF=n+48;
;	genPlus
;     genPlusIncr
	mov	a,#0x30
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	_SBUF,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:20: while(!TI);
00101$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:21: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00125$
	sjmp	00101$
00125$:
00105$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:23: wert=wert-(n*100);
;	genMult
;	genMultOneByte
	mov	a,r3
	mov	b,#0x64
	mul	ab
	mov	r4,a
;	genMinus
	mov	a,r2
	clr	c
;	Peephole 236.l	used r4 instead of ar4
	subb	a,r4
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:24: n=wert/10;
;	genDiv
;     genDivOneByte
	mov	r2,a
	mov	b,#0x0A
;	Peephole 177.d	removed redundant move
	div	ab
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:25: if(n>0)
;	genIfx
	mov	r3,a
;	Peephole 105	removed redundant mov
;	genIfxJump
;	Peephole 108.c	removed ljmp by inverse jump logic
	jz	00110$
;	Peephole 300	removed redundant label 00126$
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:27: SBUF=n+48;
;	genPlus
;     genPlusIncr
	mov	a,#0x30
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	_SBUF,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:28: while(!TI);
00106$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:29: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00127$
	sjmp	00106$
00127$:
00110$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:31: wert=wert-(n*10);
;	genMult
;	genMultOneByte
	mov	a,r3
	mov	b,#0x0A
	mul	ab
	mov	r3,a
;	genMinus
	mov	a,r2
	clr	c
;	Peephole 236.l	used r3 instead of ar3
	subb	a,r3
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:32: SBUF=wert+48;
;	genPlus
;     genPlusIncr
;	Peephole 236.a	used r2 instead of ar2
	mov	r2,a
;	Peephole 214	reduced some extra moves
	add	a,#0x30
	mov	_SBUF,a
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:33: while(!TI);
00111$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:34: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00128$
	sjmp	00111$
00128$:
;	Peephole 300	removed redundant label 00114$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'rs_send_ok'
;------------------------------------------------------------
;------------------------------------------------------------
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:37: void rs_send_ok(void)
;	-----------------------------------------
;	 function rs_send_ok
;	-----------------------------------------
_rs_send_ok:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:39: SBUF='O';
;	genAssign
	mov	_SBUF,#0x4F
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:40: while(!TI);
00101$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:41: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00123$
	sjmp	00101$
00123$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:42: SBUF='K';
;	genAssign
	mov	_SBUF,#0x4B
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:43: while(!TI);
00104$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:44: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00124$
	sjmp	00104$
00124$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:45: SBUF=0x0D;
;	genAssign
	mov	_SBUF,#0x0D
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:46: while(!TI);
00107$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:47: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00125$
	sjmp	00107$
00125$:
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:48: SBUF=0x0A;
;	genAssign
	mov	_SBUF,#0x0A
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:49: while(!TI);
00110$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	d:/freebus/trunk/software/c51/89LPC922/common/fb_rs232.c:50: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00126$
	sjmp	00110$
00126$:
;	Peephole 300	removed redundant label 00113$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'eis1'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:7: void eis1(void)
;	-----------------------------------------
;	 function eis1
;	-----------------------------------------
_eis1:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:9: rs_send_dec(telegramm[3]>>3);
;	genAssign
;	genRightShift
;	genRightShiftLiteral
;	genrshOne
	mov	a,0x0003 + _telegramm
	swap	a
	rl	a
	anl	a,#0x1f
	mov	dpl,a
;	genCall
	lcall	_rs_send_dec
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:10: SBUF='.';
;	genAssign
	mov	_SBUF,#0x2E
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:11: while(!TI);
00101$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:12: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00128$
	sjmp	00101$
00128$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:13: rs_send_dec(telegramm[3] & 0x07);
;	genAssign
;	genAnd
	mov	a,#0x07
	anl	a,0x0003 + _telegramm
	mov	dpl,a
;	genCall
	lcall	_rs_send_dec
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:14: SBUF='.';
;	genAssign
	mov	_SBUF,#0x2E
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:15: while(!TI);
00104$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:16: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00129$
	sjmp	00104$
00129$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:17: rs_send_dec(telegramm[4]);
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	dpl,(_telegramm + 0x0004)
;	genCall
	lcall	_rs_send_dec
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:18: SBUF='=';
;	genAssign
	mov	_SBUF,#0x3D
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:19: while(!TI);
00107$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:20: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00130$
	sjmp	00107$
00130$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:21: rs_send_dec(telegramm[7] & 0x01);
;	genAssign
;	genAnd
	mov	a,#0x01
	anl	a,0x0007 + _telegramm
	mov	dpl,a
;	genCall
	lcall	_rs_send_dec
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:22: SBUF=0x0D;
;	genAssign
	mov	_SBUF,#0x0D
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:23: while(!TI);
00110$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:24: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00131$
	sjmp	00110$
00131$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:25: SBUF=0x0A;
;	genAssign
	mov	_SBUF,#0x0A
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:26: while(!TI);
00113$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:27: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00132$
	sjmp	00113$
00132$:
;	Peephole 300	removed redundant label 00116$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_value_req'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:30: void read_value_req(void)
;	-----------------------------------------
;	 function read_value_req
;	-----------------------------------------
_read_value_req:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:32: }
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'restart_app'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:37: void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
;	-----------------------------------------
;	 function restart_app
;	-----------------------------------------
_restart_app:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:42: P0M1=0x00;				// Port 0 Modus push-pull für Ausgang
;	genAssign
	mov	_P0M1,#0x00
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:43: P0M2=0xFF;
;	genAssign
	mov	_P0M2,#0xFF
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_app_rs.c:44: P0=0;
;	genAssign
	mov	_P0,#0x00
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;n                         Allocated to registers r3 
;rsinpos                   Allocated to registers r2 
;rsin                      Allocated to stack - offset 1
;cr_received               Allocated to registers b0 
;crlf_received             Allocated to registers b1 
;groupadr                  Allocated to registers r4 r5 
;sloc0                     Allocated to stack - offset 21
;------------------------------------------------------------
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:18: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	push	_bp
;	peephole 177.h	optimized mov sequence
	mov	a,sp
	mov	_bp,a
	add	a,#0x16
	mov	sp,a
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:25: restart_hw();				// Hardware zurücksetzen
;	genCall
	lcall	_restart_hw
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:26: restart_prot();			// Protokoll-relevante Parameter zurücksetzen
;	genCall
	lcall	_restart_prot
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:27: restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
;	genCall
	lcall	_restart_app
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:29: rs_init();				// serielle Schnittstelle initialisieren
;	genCall
	lcall	_rs_init
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:30: rsinpos=0;
;	genAssign
	mov	r2,#0x00
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:31: cr_received=0;
;	genAssign
	clr	b0
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:32: crlf_received=0;
;	genAssign
	clr	b1
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:35: do  {
00164$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:36: if (RI)
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_SCON_0,00108$
;	Peephole 300	removed redundant label 00233$
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:38: switch (SBUF)
;	genAssign
	mov	r3,_SBUF
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x0A,00234$
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00102$
00234$:
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x0D,00105$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00235$
;	Peephole 300	removed redundant label 00236$
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:41: cr_received=1;
;	genAssign
	setb	b0
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:42: break;
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:43: case 0x0A:
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00106$
00102$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:44: if (cr_received) crlf_received=1;
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	b0,00106$
;	Peephole 300	removed redundant label 00237$
;	genAssign
	setb	b1
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:45: break;
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:46: default:
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00106$
00105$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:47: rsin[rsinpos]=SBUF;
;	genAddrOf
;	Peephole 212	reduced add sequence to inc
	mov	r3,_bp
	inc	r3
;	genPlus
;	Peephole 236.g	used r2 instead of ar2
	mov	a,r2
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r0,a
;	genPointerSet
;	genNearPointerSet
	mov	@r0,_SBUF
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:48: rsinpos++;
;	genPlus
;     genPlusIncr
	inc	r2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:49: cr_received=0;
;	genAssign
	clr	b0
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:50: crlf_received=0;
;	genAssign
	clr	b1
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:51: }
00106$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:52: RI=0;
;	genAssign
	clr	_SCON_0
00108$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:55: if (crlf_received)			// Zeile vollständig empfangen
;	genIfx
;	genIfxJump
	jb	b1,00238$
	ljmp	00158$
00238$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:57: if (rsin[0]=='f' && rsin[1]=='b')	// Magic-word 'fb' empfangen
;	genAddrOf
;	Peephole 212	reduced add sequence to inc
	mov	r0,_bp
	inc	r0
;	genPointerGet
;	genNearPointerGet
	mov	ar3,@r0
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x66,00239$
	sjmp	00240$
00239$:
	ljmp	00221$
00240$:
;	genPlus
;     genPlusIncr
	mov	a,#0x01
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerGet
;	genNearPointerGet
	mov	ar3,@r1
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x62,00241$
	sjmp	00242$
00241$:
	ljmp	00221$
00242$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:59: if(rsin[2]=='s' && rsin[3]=='0' && rsin[4]=='1' && rsin[5]=='/' && rsin[8]=='/' && rsin[10]=='/' && rsin[14]=='=' && (rsin[15]=='0' || rsin[15]=='1'))	// EIS 1 senden
;	genPlus
;     genPlusIncr
	mov	a,#0x02
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerGet
;	genNearPointerGet
	mov	ar3,@r1
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x73,00243$
	sjmp	00244$
00243$:
	ljmp	00114$
00244$:
;	genPlus
;     genPlusIncr
	mov	a,#0x03
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x30,00245$
	sjmp	00246$
00245$:
	ljmp	00114$
00246$:
;	genPlus
;     genPlusIncr
	mov	a,#0x04
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x31,00247$
	sjmp	00248$
00247$:
	ljmp	00114$
00248$:
;	genPlus
;     genPlusIncr
	mov	a,#0x05
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x2F,00249$
	sjmp	00250$
00249$:
	ljmp	00114$
00250$:
;	genPlus
;     genPlusIncr
	mov	a,#0x08
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x2F,00251$
	sjmp	00252$
00251$:
	ljmp	00114$
00252$:
;	genPlus
;     genPlusIncr
	mov	a,#0x0A
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x2F,00253$
	sjmp	00254$
00253$:
	ljmp	00114$
00254$:
;	genPlus
;     genPlusIncr
	mov	a,#0x0E
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x3D,00255$
	sjmp	00256$
00255$:
	ljmp	00114$
00256$:
;	genPlus
;     genPlusIncr
	mov	a,#0x0F
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar4,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
	cjne	r4,#0x30,00257$
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00113$
00257$:
;	genCmpEq
;	gencjneshort
	cjne	r4,#0x31,00258$
	sjmp	00259$
00258$:
	ljmp	00114$
00259$:
00113$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:61: groupadr=((rsin[6]-48)*10) + (rsin[7]-48);
;	genIpush
	push	ar2
;	genPlus
;     genPlusIncr
	mov	a,#0x06
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r4,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar4
	mov	ar4,@r0
	pop	ar0
;	genCast
	mov	r5,#0x00
;	genMinus
	mov	a,r4
	add	a,#0xd0
	mov	dpl,a
	mov	a,r5
	addc	a,#0xff
	mov	dph,a
;	genIpush
	push	ar2
	push	ar3
	push	ar0
	push	ar1
	mov	a,#0x0A
	push	acc
;	Peephole 181	changed mov to clr
	clr	a
	push	acc
;	genCall
	lcall	__mulint
	mov	r4,dpl
	mov	r5,dph
	dec	sp
	dec	sp
	pop	ar1
	pop	ar0
	pop	ar3
	pop	ar2
;	genPlus
;     genPlusIncr
	mov	a,#0x07
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r6,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar6
	mov	ar6,@r0
	pop	ar0
;	genCast
	mov	r7,#0x00
;	genMinus
	mov	a,r6
	add	a,#0xd0
	mov	r6,a
	mov	a,r7
	addc	a,#0xff
	mov	r7,a
;	genPlus
;	Peephole 236.g	used r6 instead of ar6
	mov	a,r6
;	Peephole 236.a	used r4 instead of ar4
	add	a,r4
	mov	r4,a
;	Peephole 236.g	used r7 instead of ar7
	mov	a,r7
;	Peephole 236.b	used r5 instead of ar5
	addc	a,r5
;	genAssign
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:62: groupadr=groupadr*8;
;	genLeftShift
;	genLeftShiftLiteral
;	genlshTwo
	mov	r5,a
;	Peephole 105	removed redundant mov
	swap	a
	rr	a
	anl	a,#0xf8
	xch	a,r4
	swap	a
	rr	a
	xch	a,r4
	xrl	a,r4
	xch	a,r4
	anl	a,#0xf8
	xch	a,r4
	xrl	a,r4
	mov	r5,a
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:63: groupadr=groupadr + (rsin[9]-48);
;	genPlus
;     genPlusIncr
	mov	a,#0x09
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r6,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar6
	mov	ar6,@r0
	pop	ar0
;	genCast
	mov	r7,#0x00
;	genMinus
	mov	a,r6
	add	a,#0xd0
	mov	r6,a
	mov	a,r7
	addc	a,#0xff
	mov	r7,a
;	genPlus
;	Peephole 236.g	used r6 instead of ar6
	mov	a,r6
;	Peephole 236.a	used r4 instead of ar4
	add	a,r4
	mov	r4,a
;	Peephole 236.g	used r7 instead of ar7
	mov	a,r7
;	Peephole 236.b	used r5 instead of ar5
	addc	a,r5
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:64: groupadr=groupadr*256;
;	genLeftShift
;	genLeftShiftLiteral
;	genlshTwo
;	peephole 177.e	removed redundant move
	mov	ar5,r4
	mov	r4,#0x00
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:65: groupadr=groupadr+((rsin[11]-48)*100) + ((rsin[12]-48)*10) + (rsin[13]-48);
;	genPlus
;     genPlusIncr
	mov	a,#0x0B
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r6,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar6
	mov	ar6,@r0
	pop	ar0
;	genCast
	mov	r7,#0x00
;	genMinus
	mov	a,r6
	add	a,#0xd0
	mov	dpl,a
	mov	a,r7
	addc	a,#0xff
	mov	dph,a
;	genIpush
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar0
	push	ar1
	mov	a,#0x64
	push	acc
;	Peephole 181	changed mov to clr
	clr	a
	push	acc
;	genCall
	lcall	__mulint
	mov	r6,dpl
	mov	r7,dph
	dec	sp
	dec	sp
	pop	ar1
	pop	ar0
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	genPlus
	push	ar0
	mov	a,_bp
	add	a,#0x15
	mov	r0,a
;	Peephole 236.g	used r6 instead of ar6
	mov	a,r6
;	Peephole 236.a	used r4 instead of ar4
	add	a,r4
	mov	@r0,a
;	Peephole 236.g	used r7 instead of ar7
	mov	a,r7
;	Peephole 236.b	used r5 instead of ar5
	addc	a,r5
	inc	r0
	mov	@r0,a
	pop	ar0
;	genPlus
;     genPlusIncr
	mov	a,#0x0C
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r2,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar2
	mov	ar2,@r0
	pop	ar0
;	genCast
	mov	r6,#0x00
;	genMinus
	mov	a,r2
	add	a,#0xd0
	mov	dpl,a
	mov	a,r6
	addc	a,#0xff
	mov	dph,a
;	genIpush
	push	ar3
	push	ar0
	push	ar1
	mov	a,#0x0A
	push	acc
;	Peephole 181	changed mov to clr
	clr	a
	push	acc
;	genCall
	lcall	__mulint
	mov	r2,dpl
	mov	r6,dph
	dec	sp
	dec	sp
	pop	ar1
	pop	ar0
	pop	ar3
;	genPlus
	push	ar0
	mov	a,_bp
	add	a,#0x15
	mov	r0,a
;	Peephole 236.g	used r2 instead of ar2
	mov	a,r2
	add	a,@r0
	mov	r4,a
;	Peephole 236.g	used r6 instead of ar6
	mov	a,r6
	inc	r0
	addc	a,@r0
	mov	r5,a
	pop	ar0
;	genPlus
;     genPlusIncr
	mov	a,#0x0D
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r7,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar7
	mov	ar7,@r0
	pop	ar0
;	genCast
	mov	r2,#0x00
;	genMinus
	mov	a,r7
	add	a,#0xd0
	mov	r7,a
	mov	a,r2
	addc	a,#0xff
	mov	r2,a
;	genPlus
;	Peephole 236.g	used r7 instead of ar7
	mov	a,r7
;	Peephole 236.a	used r4 instead of ar4
	add	a,r4
	mov	r7,a
;	Peephole 236.g	used r2 instead of ar2
	mov	a,r2
;	Peephole 236.b	used r5 instead of ar5
	addc	a,r5
	mov	r2,a
;	genAssign
	mov	ar4,r7
	mov	ar5,r2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:66: telegramm[0]=0xBC;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,#0xBC
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:67: telegramm[1]=pah;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0001),_pah
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:68: telegramm[2]=pal;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0002),_pal
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:69: telegramm[3]=groupadr>>8;
;	genGetByte
	mov	ar2,r5
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0003),r2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:70: telegramm[4]=groupadr;
;	genCast
	mov	ar2,r4
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0004),r2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:71: telegramm[5]=0xE1;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0005),#0xE1
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:72: telegramm[6]=0x00;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),#0x00
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:73: if (rsin[15]=='1') telegramm[7]=0x81;
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar2,@r0
	pop	ar0
;	genCmpEq
;	gencjne
;	gencjneshort
;	Peephole 241.d	optimized compare
	clr	a
	cjne	r2,#0x31,00260$
	inc	a
00260$:
;	Peephole 300	removed redundant label 00261$
;	genIpop
	pop	ar2
;	genIfx
;	genIfxJump
;	Peephole 108.c	removed ljmp by inverse jump logic
	jz	00110$
;	Peephole 300	removed redundant label 00262$
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),#0x81
00110$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:74: if (rsin[15]=='0') telegramm[7]=0x80;
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x30,00112$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00263$
;	Peephole 300	removed redundant label 00264$
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),#0x80
00112$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:75: EX1=0;
;	genAssign
	clr	_IEN0_2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:76: send_telegramm();
;	genCall
	push	ar2
	push	ar0
	push	ar1
	lcall	_send_telegramm
	pop	ar1
	pop	ar0
	pop	ar2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:77: EX1=1;
;	genAssign
	setb	_IEN0_2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:78: rs_send_ok();
;	genCall
	push	ar2
	push	ar0
	push	ar1
	lcall	_rs_send_ok
	pop	ar1
	pop	ar0
	pop	ar2
00114$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:80: if(rsin[2]=='s' && rsin[3]=='0' && rsin[4]=='6' && rsin[5]=='/' && rsin[8]=='/' && rsin[10]=='/' && rsin[14]=='=')	// EIS 6 senden
;	genPointerGet
;	genNearPointerGet
	mov	ar3,@r1
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x73,00265$
	sjmp	00266$
00265$:
	ljmp	00124$
00266$:
;	genPlus
;     genPlusIncr
	mov	a,#0x03
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x30,00267$
	sjmp	00268$
00267$:
	ljmp	00124$
00268$:
;	genPlus
;     genPlusIncr
	mov	a,#0x04
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x36,00269$
	sjmp	00270$
00269$:
	ljmp	00124$
00270$:
;	genPlus
;     genPlusIncr
	mov	a,#0x05
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x2F,00271$
	sjmp	00272$
00271$:
	ljmp	00124$
00272$:
;	genPlus
;     genPlusIncr
	mov	a,#0x08
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x2F,00273$
	sjmp	00274$
00273$:
	ljmp	00124$
00274$:
;	genPlus
;     genPlusIncr
	mov	a,#0x0A
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x2F,00275$
	sjmp	00276$
00275$:
	ljmp	00124$
00276$:
;	genPlus
;     genPlusIncr
	mov	a,#0x0E
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x3D,00277$
	sjmp	00278$
00277$:
	ljmp	00124$
00278$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:82: groupadr=((rsin[6]-48)*10) + (rsin[7]-48);
;	genIpush
	push	ar2
;	genPlus
;     genPlusIncr
	mov	a,#0x06
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCast
	mov	r6,#0x00
;	genMinus
	mov	a,r3
	add	a,#0xd0
	mov	dpl,a
	mov	a,r6
	addc	a,#0xff
	mov	dph,a
;	genIpush
	push	ar2
	push	ar0
	push	ar1
	mov	a,#0x0A
	push	acc
;	Peephole 181	changed mov to clr
	clr	a
	push	acc
;	genCall
	lcall	__mulint
	mov	r3,dpl
	mov	r6,dph
	dec	sp
	dec	sp
	pop	ar1
	pop	ar0
	pop	ar2
;	genPlus
;     genPlusIncr
	mov	a,#0x07
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r7,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar7
	mov	ar7,@r0
	pop	ar0
;	genCast
	mov	r2,#0x00
;	genMinus
	mov	a,r7
	add	a,#0xd0
	mov	r7,a
	mov	a,r2
	addc	a,#0xff
	mov	r2,a
;	genPlus
;	Peephole 236.g	used r7 instead of ar7
	mov	a,r7
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r3,a
;	Peephole 236.g	used r2 instead of ar2
	mov	a,r2
;	Peephole 236.b	used r6 instead of ar6
	addc	a,r6
	mov	r6,a
;	genAssign
	mov	ar4,r3
	mov	ar5,r6
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:83: groupadr=groupadr*8;
;	genLeftShift
;	genLeftShiftLiteral
;	genlshTwo
	mov	a,r5
	swap	a
	rr	a
	anl	a,#0xf8
	xch	a,r4
	swap	a
	rr	a
	xch	a,r4
	xrl	a,r4
	xch	a,r4
	anl	a,#0xf8
	xch	a,r4
	xrl	a,r4
	mov	r5,a
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:84: groupadr=groupadr + (rsin[9]-48);
;	genPlus
;     genPlusIncr
	mov	a,#0x09
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r2,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar2
	mov	ar2,@r0
	pop	ar0
;	genCast
	mov	r3,#0x00
;	genMinus
	mov	a,r2
	add	a,#0xd0
	mov	r2,a
	mov	a,r3
	addc	a,#0xff
	mov	r3,a
;	genPlus
;	Peephole 236.g	used r2 instead of ar2
	mov	a,r2
;	Peephole 236.a	used r4 instead of ar4
	add	a,r4
	mov	r4,a
;	Peephole 236.g	used r3 instead of ar3
	mov	a,r3
;	Peephole 236.b	used r5 instead of ar5
	addc	a,r5
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:85: groupadr=groupadr*256;
;	genLeftShift
;	genLeftShiftLiteral
;	genlshTwo
;	peephole 177.e	removed redundant move
	mov	ar5,r4
	mov	r4,#0x00
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:86: groupadr=groupadr+((rsin[11]-48)*100) + ((rsin[12]-48)*10) + (rsin[13]-48);
;	genPlus
;     genPlusIncr
	mov	a,#0x0B
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r2,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar2
	mov	ar2,@r0
	pop	ar0
;	genCast
	mov	r3,#0x00
;	genMinus
	mov	a,r2
	add	a,#0xd0
	mov	dpl,a
	mov	a,r3
	addc	a,#0xff
	mov	dph,a
;	genIpush
	push	ar4
	push	ar5
	push	ar0
	push	ar1
	mov	a,#0x64
	push	acc
;	Peephole 181	changed mov to clr
	clr	a
	push	acc
;	genCall
	lcall	__mulint
	mov	r2,dpl
	mov	r3,dph
	dec	sp
	dec	sp
	pop	ar1
	pop	ar0
	pop	ar5
	pop	ar4
;	genPlus
;	Peephole 236.g	used r2 instead of ar2
	mov	a,r2
;	Peephole 236.a	used r4 instead of ar4
	add	a,r4
	mov	r2,a
;	Peephole 236.g	used r3 instead of ar3
	mov	a,r3
;	Peephole 236.b	used r5 instead of ar5
	addc	a,r5
	mov	r3,a
;	genPlus
;     genPlusIncr
	mov	a,#0x0C
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r6,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar6
	mov	ar6,@r0
	pop	ar0
;	genCast
	mov	r7,#0x00
;	genMinus
	mov	a,r6
	add	a,#0xd0
	mov	dpl,a
	mov	a,r7
	addc	a,#0xff
	mov	dph,a
;	genIpush
	push	ar2
	push	ar3
	push	ar0
	push	ar1
	mov	a,#0x0A
	push	acc
;	Peephole 181	changed mov to clr
	clr	a
	push	acc
;	genCall
	lcall	__mulint
	mov	r6,dpl
	mov	r7,dph
	dec	sp
	dec	sp
	pop	ar1
	pop	ar0
	pop	ar3
	pop	ar2
;	genPlus
;	Peephole 236.g	used r6 instead of ar6
	mov	a,r6
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	r2,a
;	Peephole 236.g	used r7 instead of ar7
	mov	a,r7
;	Peephole 236.b	used r3 instead of ar3
	addc	a,r3
	mov	r3,a
;	genPlus
;     genPlusIncr
	mov	a,#0x0D
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r6,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar6
	mov	ar6,@r0
	pop	ar0
;	genCast
	mov	r7,#0x00
;	genMinus
	mov	a,r6
	add	a,#0xd0
	mov	r6,a
	mov	a,r7
	addc	a,#0xff
	mov	r7,a
;	genPlus
;	Peephole 236.g	used r6 instead of ar6
	mov	a,r6
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	r2,a
;	Peephole 236.g	used r7 instead of ar7
	mov	a,r7
;	Peephole 236.b	used r3 instead of ar3
	addc	a,r3
	mov	r3,a
;	genAssign
	mov	ar4,r2
	mov	ar5,r3
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:87: telegramm[0]=0xBC;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,#0xBC
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:88: telegramm[1]=pah;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0001),_pah
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:89: telegramm[2]=pal;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0002),_pal
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:90: telegramm[3]=groupadr>>8;
;	genGetByte
	mov	ar2,r5
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0003),r2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:91: telegramm[4]=groupadr;
;	genCast
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0004),r4
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:92: telegramm[5]=0xE2;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0005),#0xE2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:93: telegramm[6]=0x00;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),#0x00
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:94: telegramm[7]=0x80;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),#0x80
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:95: telegramm[8]=((rsin[15]-48)*100) + ((rsin[16]-48)*10) + (rsin[17]-48);
;	genPlus
;     genPlusIncr
	mov	a,#0x0F
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r2,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar2
	mov	ar2,@r0
	pop	ar0
;	genMinus
	mov	a,r2
	add	a,#0xd0
;	genMult
;	genMultOneByte
	mov	b,#0x64
	mul	ab
	mov	r2,a
;	genPlus
;     genPlusIncr
	mov	a,#0x10
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genMinus
	mov	a,r3
	add	a,#0xd0
;	genMult
;	genMultOneByte
	mov	b,#0x0A
	mul	ab
;	genPlus
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	r2,a
;	genPlus
;     genPlusIncr
	mov	a,#0x11
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genMinus
	mov	a,r3
	add	a,#0xd0
;	genPlus
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0008),a
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:96: EX1=0;
;	genAssign
	clr	_IEN0_2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:97: send_telegramm();
;	genCall
	push	ar2
	push	ar0
	push	ar1
	lcall	_send_telegramm
	pop	ar1
	pop	ar0
	pop	ar2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:98: EX1=1;
;	genAssign
	setb	_IEN0_2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:99: rs_send_ok();
;	genCall
	push	ar2
	push	ar0
	push	ar1
	lcall	_rs_send_ok
	pop	ar1
	pop	ar0
	pop	ar2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:146: } while(1);
;	genIpop
	pop	ar2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:99: rs_send_ok();
00124$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:101: if(rsin[2]=='r' && rsin[3]=='p' && rsin[4]=='a')	// physikalische Adresse des Adaptrs lesen (fbrpa)
;	genPointerGet
;	genNearPointerGet
	mov	ar3,@r1
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x72,00279$
	sjmp	00280$
00279$:
	ljmp	00144$
00280$:
;	genPlus
;     genPlusIncr
	mov	a,#0x03
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x70,00144$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00281$
;	Peephole 300	removed redundant label 00282$
;	genPlus
;     genPlusIncr
	mov	a,#0x04
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r3,a
;	genPointerGet
;	genNearPointerGet
	push	ar0
	mov	r0,ar3
	mov	ar3,@r0
	pop	ar0
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x61,00144$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00283$
;	Peephole 300	removed redundant label 00284$
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:103: rs_send_dec(pah>>4);
;	genRightShift
;	genRightShiftLiteral
;	genrshOne
	mov	a,_pah
	swap	a
	anl	a,#0x0f
	mov	dpl,a
;	genCall
	push	ar2
	push	ar0
	push	ar1
	lcall	_rs_send_dec
	pop	ar1
	pop	ar0
	pop	ar2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:104: SBUF='.';
;	genAssign
	mov	_SBUF,#0x2E
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:105: while(!TI);
00131$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:106: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00285$
	sjmp	00131$
00285$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:107: rs_send_dec(pah&0x0F);
;	genAnd
	mov	a,#0x0F
	anl	a,_pah
	mov	dpl,a
;	genCall
	push	ar2
	push	ar0
	push	ar1
	lcall	_rs_send_dec
	pop	ar1
	pop	ar0
	pop	ar2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:108: SBUF='.';
;	genAssign
	mov	_SBUF,#0x2E
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:109: while(!TI);
00134$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:110: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00286$
	sjmp	00134$
00286$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:111: rs_send_dec(pal);
;	genCall
	mov	dpl,_pal
	push	ar2
	push	ar0
	push	ar1
	lcall	_rs_send_dec
	pop	ar1
	pop	ar0
	pop	ar2
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:112: SBUF=0x0D;
;	genAssign
	mov	_SBUF,#0x0D
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:113: while(!TI);
00137$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:114: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00287$
	sjmp	00137$
00287$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:115: SBUF=0x0A;
;	genAssign
	mov	_SBUF,#0x0A
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:116: while(!TI);
00140$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:117: TI=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_SCON_1,00288$
	sjmp	00140$
00288$:
00144$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:119: if(rsin[2]=='s' && rsin[3]=='p' && rsin[4]=='a' && rsin[7]=='.' && rsin[10]=='.' && rsinpos==14)	// phys. Adresse des Adapters setzen (fbspaxx.xx.xxx)
;	genPointerGet
;	genNearPointerGet
	mov	ar3,@r1
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x73,00289$
	sjmp	00290$
00289$:
	ljmp	00221$
00290$:
;	genPlus
;     genPlusIncr
	mov	a,#0x03
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerGet
;	genNearPointerGet
	mov	ar3,@r1
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x70,00291$
	sjmp	00292$
00291$:
	ljmp	00221$
00292$:
;	genPlus
;     genPlusIncr
	mov	a,#0x04
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerGet
;	genNearPointerGet
	mov	ar3,@r1
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x61,00293$
	sjmp	00294$
00293$:
	ljmp	00221$
00294$:
;	genPlus
;     genPlusIncr
	mov	a,#0x07
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerGet
;	genNearPointerGet
	mov	ar3,@r1
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x2E,00295$
	sjmp	00296$
00295$:
	ljmp	00221$
00296$:
;	genPlus
;     genPlusIncr
	mov	a,#0x0A
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerGet
;	genNearPointerGet
	mov	ar3,@r1
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x2E,00297$
	sjmp	00298$
00297$:
	ljmp	00221$
00298$:
;	genCmpEq
;	gencjneshort
	cjne	r2,#0x0E,00299$
	sjmp	00300$
00299$:
	ljmp	00221$
00300$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:121: pah=(((rsin[5]-48)*10) + (rsin[6]-48))*16;
;	genPlus
;     genPlusIncr
	mov	a,#0x05
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerGet
;	genNearPointerGet
	mov	ar3,@r1
;	genMinus
	mov	a,r3
	add	a,#0xd0
;	genMult
;	genMultOneByte
	mov	b,#0x0A
	mul	ab
	mov	r3,a
;	genPlus
;     genPlusIncr
	mov	a,#0x06
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerGet
;	genNearPointerGet
	mov	ar4,@r1
;	genMinus
	mov	a,r4
	add	a,#0xd0
;	genPlus
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
;	genLeftShift
;	genLeftShiftLiteral
;	genlshOne
	mov	r3,a
;	Peephole 105	removed redundant mov
	swap	a
	anl	a,#0xf0
	mov	_pah,a
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:122: pah=pah + (((rsin[8]-48)*10) + (rsin[9]-48));
;	genPlus
;     genPlusIncr
	mov	a,#0x08
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerGet
;	genNearPointerGet
	mov	ar3,@r1
;	genMinus
	mov	a,r3
	add	a,#0xd0
;	genMult
;	genMultOneByte
	mov	b,#0x0A
	mul	ab
	mov	r3,a
;	genPlus
;     genPlusIncr
	mov	a,#0x09
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerGet
;	genNearPointerGet
	mov	ar4,@r1
;	genMinus
	mov	a,r4
	add	a,#0xd0
;	genPlus
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
;	genPlus
	add	a,_pah
	mov	_pah,a
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:123: pal=(((rsin[11]-48)*100) + ((rsin[12]-48)*10) + (rsin[13]-48));
;	genPlus
;     genPlusIncr
	mov	a,#0x0B
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerGet
;	genNearPointerGet
	mov	ar3,@r1
;	genMinus
	mov	a,r3
	add	a,#0xd0
;	genMult
;	genMultOneByte
	mov	b,#0x64
	mul	ab
	mov	r3,a
;	genPlus
;     genPlusIncr
	mov	a,#0x0C
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerGet
;	genNearPointerGet
	mov	ar4,@r1
;	genMinus
	mov	a,r4
	add	a,#0xd0
;	genMult
;	genMultOneByte
	mov	b,#0x0A
	mul	ab
;	genPlus
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r3,a
;	genPlus
;     genPlusIncr
	mov	a,#0x0D
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerGet
;	genNearPointerGet
	mov	ar4,@r1
;	genMinus
	mov	a,r4
	add	a,#0xd0
;	genPlus
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	_pal,a
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:124: start_writecycle();
;	genCall
	push	ar0
	lcall	_start_writecycle
	pop	ar0
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:125: write_byte(0x01,ADDRTAB+1,pah);		// in Flash schreiben
;	genIpush
	push	ar0
	push	_pah
;	genIpush
	mov	a,#0x17
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar0
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:126: write_byte(0x01,ADDRTAB+2,pal);
;	genIpush
	push	ar0
	push	_pal
;	genIpush
	mov	a,#0x18
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar0
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:127: stop_writecycle();
;	genCall
	push	ar0
	lcall	_stop_writecycle
	pop	ar0
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:128: rs_send_ok();
;	genCall
	push	ar0
	lcall	_rs_send_ok
	pop	ar0
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:131: for(n=0;n<20;n++) rsin[n]=0x00;
00221$:
;	genAssign
	mov	r3,#0x00
00167$:
;	genCmpLt
;	genCmp
	cjne	r3,#0x14,00301$
00301$:
;	genIfxJump
;	Peephole 108.a	removed ljmp by inverse jump logic
	jnc	00170$
;	Peephole 300	removed redundant label 00302$
;	genPlus
;	Peephole 236.g	used r3 instead of ar3
	mov	a,r3
;	Peephole 236.a	used r0 instead of ar0
	add	a,r0
	mov	r1,a
;	genPointerSet
;	genNearPointerSet
	mov	@r1,#0x00
;	genPlus
;     genPlusIncr
	inc	r3
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00167$
00170$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:132: rsinpos=0;
;	genAssign
	mov	r2,#0x00
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:133: cr_received=0;
;	genAssign
	clr	b0
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:134: crlf_received=0;
;	genAssign
	clr	b1
00158$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:138: TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
;	genAssign
	setb	_P1_7
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:139: if(!TASTER) {			// Taster gedrückt
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	_P1_7,00163$
;	Peephole 300	removed redundant label 00303$
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:140: for(n=0;n<100;n++) {}
;	genAssign
	mov	r3,#0x64
00173$:
;	genDjnz
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 205	optimized misc jump sequence
	djnz	r3,00173$
;	Peephole 300	removed redundant label 00304$
;	Peephole 300	removed redundant label 00305$
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:141: while(!TASTER);			// warten bis Taster losgelassen
00159$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_P1_7,00159$
;	Peephole 300	removed redundant label 00306$
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:142: progmode=!progmode;
;	genNot
	cpl	_progmode
00163$:
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:144: TASTER=!progmode;			// LED entsprechend schalten (low=LED an)
;	genNot
	mov	c,_progmode
	cpl	c
	mov	_P1_7,c
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:145: for(n=0;n<100;n++) {}
;	genAssign
	mov	r3,#0x64
00176$:
;	genDjnz
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 205	optimized misc jump sequence
	djnz	r3,00176$
;	Peephole 300	removed redundant label 00307$
;	Peephole 300	removed redundant label 00308$
;	D:/freebus/trunk/software/c51/89LPC922/RS232I~1/fb_rs.c:146: } while(1);
	ljmp	00164$
;	Peephole 300	removed redundant label 00177$
	mov	sp,_bp
	pop	_bp
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
_dataflash	=	0x1c00
	.area XINIT   (CODE)
