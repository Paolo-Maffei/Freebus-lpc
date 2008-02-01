;--------------------------------------------------------
; File Created by SDCC : FreeWare ANSI-C Compiler
; Version 2.6.1 #4376 (Sep 14 2006)
; This file generated Sat Dec 01 23:28:55 2007
;--------------------------------------------------------
	.module fb_in8
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _dataflash
	.globl _main
	.globl _pin_changed
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
	.globl _pdir
	.globl _timer
	.globl _objstate
	.globl _p0h
	.globl _portbuffer
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
	.globl _send_cyclic
	.globl _operation
	.globl _switch_dim
	.globl _schalten
	.globl _pin_function
	.globl _debounce
	.globl _eis1
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
_portbuffer::
	.ds 1
_p0h::
	.ds 1
_objstate::
	.ds 2
_timer::
	.ds 4
_pdir::
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:10: unsigned char get_byte(void)
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:15: EX1=0;				// Interrupt 1 sperren
;	genAssign
	clr	_IEN0_2
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:16: ET1=0;				// Interrupt von Timer 1 sperren
;	genAssign
	clr	_IEN0_3
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:18: set_timer1(380);			// Timer setzen um 1. Bit zu treffen (320-440)
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x017C
	lcall	_set_timer1
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:20: ph=0;					// Paritybit wird aus empfangenem Byte berechnet
;	genAssign
	clr	b0
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:21: parity_ok=0;
;	genAssign
	clr	_parity_ok
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:22: while(!TF1);				// warten auf Timer 1				
00101$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00101$
;	Peephole 300	removed redundant label 00152$
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:23: set_timer1(360);			// Timer 1 neu setzen für 2.Bit (300-420)
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x0168
	push	bits
	lcall	_set_timer1
	pop	bits
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:24: rbit=FBINC;				// 1.Bit einlesen
;	genAssign
	mov	c,_P1_4
	mov	b1,c
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:25: for(m=0;m<5;m++)
;	genAssign
	mov	r2,#0x05
00118$:
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:27: rbit&=FBINC;			// zur Steigerung der Fehlertoleranz mehrfach lesen
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:25: for(m=0;m<5;m++)
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:29: fbb=rbit;
;	genAssign
	clr	a
	mov	c,b1
	rlc	a
	mov	r2,a
;	genAssign
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:30: if(rbit) ph=!ph;			// Paritybit berechnen
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	b1,00142$
;	Peephole 300	removed redundant label 00155$
;	genNot
	cpl	b0
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:32: for(n=0;n<7;n++)			// 2. bis 8. Bit
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:34: fbb=fbb<<1;
;	genLeftShift
;	genLeftShiftLiteral
;	genlshOne
	mov	a,r2
;	Peephole 254	optimized left shift
	add	a,r2
	mov	r2,a
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:35: while(!TF1);
00106$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00106$
;	Peephole 300	removed redundant label 00158$
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:36: set_timer1(350);			// Timer 1 setzen für Position 2.-9.Bit (342-359)
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:37: rbit=FBINC;
;	genAssign
	mov	c,_P1_4
	mov	b1,c
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:38: for(m=0;m<5;m++)
;	genAssign
	mov	r4,#0x05
00121$:
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:40: rbit&=FBINC;			// zur Steigerung der Fehlertoleranz mehrfach lesen
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:38: for(m=0;m<5;m++)
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:42: fbb=fbb+rbit;
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:43: if(rbit) ph=!ph;			// Paritybit berechnen
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	b1,00124$
;	Peephole 300	removed redundant label 00161$
;	genNot
	cpl	b0
00124$:
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:32: for(n=0;n<7;n++)			// 2. bis 8. Bit
;	genPlus
;     genPlusIncr
	inc	r3
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:45: while(!TF1);				
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00122$
00111$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00111$
;	Peephole 300	removed redundant label 00162$
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:46: TR1=0;
;	genAssign
	clr	_TCON_6
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:47: parity=FBINC;				// Paritybit lesen
;	genAssign
	mov	c,_P1_4
	mov	b1,c
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:48: for(m=0;m<5;m++)
;	genAssign
	mov	r3,#0x05
00128$:
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:50: parity&=FBINC;
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:48: for(m=0;m<5;m++)
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:53: fbbh=(fbb&0x80)>>7;			// Byte bitweise vertauschen, da LSB zuerst übertragen wurde
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:54: fbbh=fbbh+((fbb&0x40)>>5);
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:55: fbbh=fbbh+((fbb&0x20)>>3);
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:56: fbbh=fbbh+((fbb&0x10)>>1);
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:57: fbbh=fbbh+((fbb&0x08)<<1);
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:58: fbbh=fbbh+((fbb&0x04)<<3);
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:59: fbbh=fbbh+((fbb&0x02)<<5);
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:60: fbbh=fbbh+((fbb&0x01)<<7);
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:62: if(parity==ph) parity_ok=1;
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:64: return fbbh;
;	genRet
	mov	dpl,r3
;	Peephole 300	removed redundant label 00129$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ext_int0'
;------------------------------------------------------------
;fbbh                      Allocated to registers r2 
;------------------------------------------------------------
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:70: void ext_int0(void) interrupt 2		// Byte vom Bus empfangen, wird durch negative Flanke am INT1 Eingang getriggert
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:76: TR1=0;
;	genAssign
	clr	_TCON_6
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:77: EX1=0;				// Interrupt 1 sperren
;	genAssign
	clr	_IEN0_2
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:78: ET1=0;				// Interrupt von Timer 1 sperren
;	genAssign
	clr	_IEN0_3
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:80: fbbh=get_byte();			// Byte vom Bus empfangen
;	genCall
	lcall	_get_byte
	mov	r2,dpl
;	genAssign
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:81: delay(200);
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x00C8
	push	ar2
	lcall	_delay
	pop	ar2
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:83: if(parity_ok)				// wenn Parity OK
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_parity_ok,00104$
;	Peephole 300	removed redundant label 00109$
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:85: telegramm[telpos]=fbbh; 
;	genPlus
	mov	a,_telpos
	add	a,#_telegramm
;	genPointerSet
;	genNearPointerSet
;	Peephole 239	used a instead of acc
	mov	r0,a
	mov	@r0,ar2
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:86: if(telpos==0) cs=0;
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:87: cs^=fbbh;				// Checksum durch EXOR der einzelnen Telegramm-Bytes bilden
;	genXor
	mov	a,r2
	xrl	_cs,a
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:88: telpos++;
;	genPlus
;     genPlusIncr
	inc	_telpos
00104$:
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:91: set_timer1(2700);			// Timer 1 starten für Timeout 370us -> signalisiert Telegrammende (1460)
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x0A8C
	lcall	_set_timer1
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:93: ET1=1;				// Interrupt für Timer 1 freigeben
;	genAssign
	setb	_IEN0_3
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:94: IE1=0;				// Interrupt 0 request zurücksetzen
;	genAssign
	clr	_TCON_3
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:95: EX1=1;				// Interrupt 0 wieder freigeben
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:99: bit sendbyte(unsigned char fbsb)
;	-----------------------------------------
;	 function sendbyte
;	-----------------------------------------
_sendbyte:
;	genReceive
	mov	r2,dpl
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:104: parity=1;
;	genAssign
	setb	b0
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:105: error=0;
;	genAssign
	clr	b1
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:107: FBOUTC=1;	// Startbit senden
;	genAssign
	setb	_P1_6
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:108: delay(95);	// 35us
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x005F
	push	ar2
	push	bits
	lcall	_delay
	pop	bits
	pop	ar2
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:109: FBOUTC=0;
;	genAssign
	clr	_P1_6
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:111: for(n=0;n<8;n++)		// 8 Datenbits senden
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:113: set_timer1(215);		// 69us Pause
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:114: if(((fbsb>>n)&0x01)==1) sendbit=0;
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:115: else sendbit=1;
;	genAssign
	setb	b2
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:116: while(!TF1);		// Warten bis 69us Pause fretig ist
00104$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00104$
;	Peephole 300	removed redundant label 00147$
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:118: FBOUTC=sendbit;		// Bit senden
;	genAssign
	mov	c,b2
	mov	_P1_6,c
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:120: set_timer1(100);		//35us Haltezeit für Bit 
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:122: if(!sendbit)		// wenn logische 1 gesendet wird, auf Kollision prüfen
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	b2,00110$
;	Peephole 300	removed redundant label 00148$
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:124: parity=!parity;
;	genNot
	cpl	b0
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:125: for(m=0;m<5;m++)
;	genAssign
	mov	r4,#0x05
00124$:
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:127: if(!FBINC) error=1;
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:125: for(m=0;m<5;m++)
00110$:
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:130: if(error) break;  
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	b1,00119$
;	Peephole 300	removed redundant label 00152$
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:132: while(!TF1);		// Warten bis 35us abgelaufen
00113$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00113$
;	Peephole 300	removed redundant label 00153$
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:133: FBOUTC=0;
;	genAssign
	clr	_P1_6
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:111: for(n=0;n<8;n++)		// 8 Datenbits senden
;	genPlus
;     genPlusIncr
	inc	r3
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00116$
00119$:
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:135: if(!error)
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	b1,00121$
;	Peephole 300	removed redundant label 00154$
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:137: delay(212);			// 69 us Pause vor Parity-Bit
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x00D4
	push	bits
	lcall	_delay
	pop	bits
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:138: FBOUTC=parity;
;	genAssign
	mov	c,b0
	mov	_P1_6,c
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:139: delay(95);			// 35us für Parity-Bit
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x005F
	push	bits
	lcall	_delay
	pop	bits
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:140: FBOUTC=0;
;	genAssign
	clr	_P1_6
00121$:
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:142: TR1=0;
;	genAssign
	clr	_TCON_6
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:144: return error;
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:148: void start_writecycle(void)
;	-----------------------------------------
;	 function start_writecycle
;	-----------------------------------------
_start_writecycle:
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:150: FMCON=0x00;			// load command, leert das pageregister
;	genAssign
	mov	_FMCON,#0x00
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'stop_writecycle'
;------------------------------------------------------------
;------------------------------------------------------------
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:154: void stop_writecycle(void)
;	-----------------------------------------
;	 function stop_writecycle
;	-----------------------------------------
_stop_writecycle:
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:156: FMCON=0x68;			// write command, schreibt pageregister ins flash und versetzt CPU in idle für 4ms
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:160: void write_byte(unsigned char addrh, unsigned char addrl, unsigned char zdata)	// schreibt byte ins pageregister zum flashen
;	-----------------------------------------
;	 function write_byte
;	-----------------------------------------
_write_byte:
	push	_bp
	mov	_bp,sp
;	genReceive
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:163: if (addrh<=0x01)		// sicherstellen, dass nicht versehentlich bootloader überschrieben wird
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:165: FMADRH=addrh+0x1C;
;	genPlus
;     genPlusIncr
	mov	a,#0x1C
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	_FMADRH,a
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:166: FMADRL=addrl;
;	genAssign
	mov	r0,_bp
	dec	r0
	dec	r0
	dec	r0
	mov	_FMADRL,@r0
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:167: FMDATA=zdata;
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:172: void delay(int deltime)			// Warten, deltime = Anzahl Takte
;	-----------------------------------------
;	 function delay
;	-----------------------------------------
_delay:
;	genReceive
	mov	r2,dpl
	mov	r3,dph
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:174: TR1=0;				// Timer 1 anhalten
;	genAssign
	clr	_TCON_6
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:175: deltime=0xFFFF-deltime;
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:176: TH1=deltime>>8;			// Timer 1 setzen 
;	genGetByte
	mov	_TH1,r3
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:177: TL1=deltime;	
;	genCast
	mov	_TL1,r2
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:178: TF1=0;
;	genAssign
	clr	_TCON_7
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:179: TR1=1;
;	genAssign
	setb	_TCON_6
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:180: while(!TF1);				// warten auf Timer 1
00101$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00101$
;	Peephole 300	removed redundant label 00108$
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:181: TR1=0;		
;	genAssign
	clr	_TCON_6
;	Peephole 300	removed redundant label 00104$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'set_timer1'
;------------------------------------------------------------
;deltime                   Allocated to registers r2 r3 
;------------------------------------------------------------
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:185: void set_timer1(int deltime)		// Warten, deltime = Anzahl Takte
;	-----------------------------------------
;	 function set_timer1
;	-----------------------------------------
_set_timer1:
;	genReceive
	mov	r2,dpl
	mov	r3,dph
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:187: TR1=0;				// Timer 1 anhalten
;	genAssign
	clr	_TCON_6
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:188: deltime=0xFFFF-deltime;
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:189: TH1=deltime>>8;			// Timer 1 setzen 
;	genGetByte
	mov	_TH1,r3
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:190: TL1=deltime;	
;	genCast
	mov	_TL1,r2
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:191: TF1=0;				// Überlauf-Flag zurücksetzen
;	genAssign
	clr	_TCON_7
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:192: TR1=1;				// Timer 1 starten
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:196: unsigned char read_byte(unsigned char addrh, unsigned char addrl)		// liest byte aus flash
;	-----------------------------------------
;	 function read_byte
;	-----------------------------------------
_read_byte:
	push	_bp
	mov	_bp,sp
;	genReceive
	mov	r2,dpl
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:200: zdata=dataflash[(addrh<<8)+addrl];
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
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:201: return (zdata);
;	genRet
;	Peephole 300	removed redundant label 00101$
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'restart_hw'
;------------------------------------------------------------
;------------------------------------------------------------
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:205: void restart_hw(void)	// Alle Hardware Einstellungen zurücksetzen
;	-----------------------------------------
;	 function restart_hw
;	-----------------------------------------
_restart_hw:
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:209: DIVM=0;		// Taktferquenz nicht teilen -> volles Tempo
;	genAssign
	mov	_DIVM,#0x00
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:211: P1M1=0x14;		// Port 1 auf quasi-bidirektional, außer P1.2(T0 als PWM Ausgang)=open-drain, P1.4(INT1)=Input only, P1.6(FBOUTC) push-pull
;	genAssign
	mov	_P1M1,#0x14
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:212: P1M2=0x44;
;	genAssign
	mov	_P1M2,#0x44
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:214: FBOUTC=0;		// Bus-Ausgang auf low
;	genAssign
	clr	_P1_6
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:216: TMOD=0x12;		// Timer 0 als PWM, Timer 1 als 16-Bit Timer
;	genAssign
	mov	_TMOD,#0x12
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:217: TAMOD=0x01;
;	genAssign
	mov	_TAMOD,#0x01
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:218: TH0=DUTY;		// Pulsverhältnis PWM
;	genAssign
	mov	_TH0,#0xC0
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:219: AUXR1|=0x10;		// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
;	genOr
	orl	_AUXR1,#0x10
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:221: ET0=0;		// Interrupt für Timer 0 sperren 
;	genAssign
	clr	_IEN0_1
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:222: TR0=1;		// Timer 0 starten (PWM)
;	genAssign
	setb	_TCON_4
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:223: TR1=0;		// Timer 1 (Empfangs-Timeout) zunächst stoppen
;	genAssign
	clr	_TCON_6
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:225: RTCH=0x1D;		// Real Time Clock
;	genAssign
	mov	_RTCH,#0x1D
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:226: RTCL=0x40;
;	genAssign
	mov	_RTCL,#0x40
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:227: RTCCON=0x61;
;	genAssign
	mov	_RTCCON,#0x61
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:229: IEN0=0x00;
;	genAssign
	mov	_IEN0,#0x00
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:230: IEN1=0x00;
;	genAssign
	mov	_IEN1,#0x00
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:231: EA=1;			// Interrupts prinzipiell freigeben
;	genAssign
	setb	_IEN0_7
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:232: EX0=0;		// Externen Interrupt 0 sperren
;	genAssign
	clr	_IEN0_0
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:233: EX1=1;		// Externen Interrupt 1 freigeben	
;	genAssign
	setb	_IEN0_2
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:235: IP0=0x0C;		// höchste Priorität für ext. Int. 1 und Timer 1 (Bit 0 und 3)
;	genAssign
	mov	_IP0,#0x0C
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:236: IP0H=0x0C;
;	genAssign
	mov	_IP0H,#0x0C
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:237: IP1=0x00;
;	genAssign
	mov	_IP1,#0x00
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:238: IP1H=0x00;
;	genAssign
	mov	_IP1H,#0x00
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:239: IT1=1;		// Int1 flankengetriggert=1 pegelgetriggert=0
;	genAssign
	setb	_TCON_2
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:241: SCON=0x50;		// Serielle auf Mode 1, receive enable
;	genAssign
	mov	_SCON,#0x50
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:242: SSTAT|=0x40;		// TI wird am Ende des Stopbits gesetzt
;	genOr
	orl	_SSTAT,#0x40
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:243: BRGCON|=0x02;		// Baudrate Generator verwenden aber noch gestoppt
;	genOr
	orl	_BRGCON,#0x02
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:244: BRGR1=0x00;		// Baudrate = cclk/((BRGR1,BRGR0)+16)
;	genAssign
	mov	_BRGR1,#0x00
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:245: BRGR0=0x30;
;	genAssign
	mov	_BRGR0,#0x30
;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:246: BRGCON|=0x01;		// Baudrate Generator starten
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:12: void timer1(void) interrupt 3	// Interrupt von Timer 1, 370us keine Busaktivität seit letztem Byte, d.h. Telegramm wurde komplett übertragen
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:16: EX1=0;					// ext. Interrupt stoppen 
;	genAssign
	clr	_IEN0_2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:17: ET1=0;					// Interrupt von Timer 1 sperren
;	genAssign
	clr	_IEN0_3
;	s:/elektronik/eib/c/fb_common/fb_prot.c:18: TR1=0;					// Timer 1 anhalten
;	genAssign
	clr	_TCON_6
;	s:/elektronik/eib/c/fb_common/fb_prot.c:19: TF1=0;
;	genAssign
	clr	_TCON_7
;	s:/elektronik/eib/c/fb_common/fb_prot.c:20: TH1=0xED;					// und neu starten für korrekte Positionierung des ACK Bytes
;	genAssign
	mov	_TH1,#0xED
;	s:/elektronik/eib/c/fb_common/fb_prot.c:21: TL1=0x80;				
;	genAssign
	mov	_TL1,#0x80
;	s:/elektronik/eib/c/fb_common/fb_prot.c:22: TR1=1;
;	genAssign
	setb	_TCON_6
;	s:/elektronik/eib/c/fb_common/fb_prot.c:25: if(cs==0xff)					// Checksum des Telegramms ist OK 
;	genCmpEq
;	gencjneshort
	mov	a,_cs
	cjne	a,#0xFF,00182$
	sjmp	00183$
00182$:
	ljmp	00150$
00183$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:27: data_laenge=(telegramm[5]&0x0F);		// Telegramm-Länge = Bit 0 bis 3 
;	genAssign
;	genAnd
	mov	a,#0x0F
	anl	a,0x0005 + _telegramm
	mov	r2,a
;	s:/elektronik/eib/c/fb_common/fb_prot.c:28: daf=(telegramm[5]&0x80);			// Destination Adress Flag = Bit 7, 0=phys. Adr., 1=Gruppenadr.
;	genAnd
	mov	a,#0x80
	anl	a,0x0005 + _telegramm
	mov	r3,a
;	s:/elektronik/eib/c/fb_common/fb_prot.c:30: if(telegramm[3]==0 && telegramm[4]==0)		// Broadcast, wenn Zieladresse = 0
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
;	genIfx
;	peephole 177.g	optimized mov sequence
	mov	a,(_telegramm + 0x0003)
	mov	r4,a
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00146$
;	Peephole 300	removed redundant label 00184$
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	a,(_telegramm + 0x0004)
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00146$
;	Peephole 300	removed redundant label 00185$
;	s:/elektronik/eib/c/fb_common/fb_prot.c:32: if(progmode)
;	genIfx
;	genIfxJump
	jb	_progmode,00186$
	ljmp	00150$
00186$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:34: if(data_laenge==3 && telegramm[6]==0x00 && telegramm[7]==0xC0) set_pa();	// set_pa_req
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r2,#0x03,00102$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00187$
;	Peephole 300	removed redundant label 00188$
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	a,(_telegramm + 0x0006)
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00102$
;	Peephole 300	removed redundant label 00189$
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0007 + _telegramm
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	a,#0xC0,00102$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00190$
;	Peephole 300	removed redundant label 00191$
;	genCall
	lcall	_set_pa
00102$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:35: if(telegramm[6]==0x01 && telegramm[7]==0x00) read_pa();				// read_pa_req
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0006 + _telegramm
	cjne	a,#0x01,00192$
	sjmp	00193$
00192$:
	ljmp	00150$
00193$:
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	a,(_telegramm + 0x0007)
;	genIfx
;	genIfxJump
	jz	00194$
	ljmp	00150$
00194$:
;	genCall
	lcall	_read_pa
	ljmp	00150$
00146$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:40: if(daf==0x00)					// Unicast, wenn Zieladresse physikalische Adresse ist
;	genIfx
	mov	a,r3
;	genIfxJump
	jz	00195$
	ljmp	00143$
00195$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:42: if(telegramm[3]==pah && telegramm[4]==pal)	// nur wenn es die eigene phys. Adr. ist
;	genCmpEq
;	gencjneshort
	mov	a,r4
	cjne	a,_pah,00196$
	sjmp	00197$
00196$:
	ljmp	00150$
00197$:
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0004 + _telegramm
	cjne	a,_pal,00198$
	sjmp	00199$
00198$:
	ljmp	00150$
00199$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:44: if((telegramm[6]&0xC3)==0x42 && (telegramm[7]&0xC0)==0x80) write_memory();	// write_memory_request beantworten
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
;	Peephole 300	removed redundant label 00200$
;	Peephole 300	removed redundant label 00201$
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
;	Peephole 300	removed redundant label 00202$
;	Peephole 300	removed redundant label 00203$
;	genCall
	push	ar2
	lcall	_write_memory
	pop	ar2
00111$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:45: if(data_laenge==0)
;	genIfx
	mov	a,r2
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00120$
;	Peephole 300	removed redundant label 00204$
;	s:/elektronik/eib/c/fb_common/fb_prot.c:47: if((telegramm[6]&0xC0)==0xC0) send_ack();				// auf NCD_Quittierung mit ACK antworten
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
;	Peephole 300	removed redundant label 00205$
;	Peephole 300	removed redundant label 00206$
;	genCall
	push	ar2
	lcall	_send_ack
	pop	ar2
00114$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:48: if(telegramm[6]==0x80) ucd_opr();					// UCD Verbindungsaufbau
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0006 + _telegramm
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	a,#0x80,00116$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00207$
;	Peephole 300	removed redundant label 00208$
;	genCall
	push	ar2
	lcall	_ucd_opr
	pop	ar2
00116$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:49: if(telegramm[6]==0x81) ucd_clr();					// UCD Verbindungsabbau
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0006 + _telegramm
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	a,#0x81,00120$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00209$
;	Peephole 300	removed redundant label 00210$
;	genCall
	push	ar2
	lcall	_ucd_clr
	pop	ar2
00120$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:51: if(data_laenge==1)
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r2,#0x01,00128$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00211$
;	Peephole 300	removed redundant label 00212$
;	s:/elektronik/eib/c/fb_common/fb_prot.c:53: if((telegramm[6]&0x03)==0x03 && telegramm[7]==0x80)		// restart request
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
;	Peephole 300	removed redundant label 00213$
;	Peephole 300	removed redundant label 00214$
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0007 + _telegramm
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	a,#0x80,00122$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00215$
;	Peephole 300	removed redundant label 00216$
;	s:/elektronik/eib/c/fb_common/fb_prot.c:55: restart_hw();	// Hardware zurücksetzen
;	genCall
	push	ar2
	lcall	_restart_hw
	pop	ar2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:56: restart_prot();	// Protokoll-relevante Parameter zurücksetzen
;	genCall
	push	ar2
	lcall	_restart_prot
	pop	ar2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:57: restart_app();	// Anwendungsspezifische Einstellungen zurücksetzen
;	genCall
	push	ar2
	lcall	_restart_app
	pop	ar2
00122$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:59: if(telegramm[6]==0x43 && telegramm[7]==0x00) read_masq();		// Maskenversion angefordert
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0006 + _telegramm
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	a,#0x43,00128$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00217$
;	Peephole 300	removed redundant label 00218$
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	a,(_telegramm + 0x0007)
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00128$
;	Peephole 300	removed redundant label 00219$
;	genCall
	push	ar2
	lcall	_read_masq
	pop	ar2
00128$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:61: if(data_laenge==3)
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r2,#0x03,00150$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00220$
;	Peephole 300	removed redundant label 00221$
;	s:/elektronik/eib/c/fb_common/fb_prot.c:63: if((telegramm[6]&0xC3)==0x42 && (telegramm[7]&0xC0)==0x00) read_memory();	// read_memory_request beantworten
;	genAssign
;	genAnd
	mov	a,#0xC3
	anl	a,0x0006 + _telegramm
	mov	r3,a
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x42,00150$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00222$
;	Peephole 300	removed redundant label 00223$
;	genAssign
;	genAnd
	mov	a,0x0007 + _telegramm
	anl	a,#0xC0
;	Peephole 160.c	removed sjmp by inverse jump logic
	jz	00225$
;	Peephole 300	removed redundant label 00224$
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00150$
00225$:
;	genCall
	lcall	_read_memory
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00150$
00143$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:70: if(data_laenge==1 && telegramm[6]==0x00 && ((telegramm[7]&0xFE)==0x80 || telegramm[7]==0x00)) eis1();	// Ausgänge schalten (EIS 1) oder lesen
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r2,#0x01,00150$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00226$
;	Peephole 300	removed redundant label 00227$
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	a,(_telegramm + 0x0006)
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00150$
;	Peephole 300	removed redundant label 00228$
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	r2,(_telegramm + 0x0007)
;	genAnd
	mov	a,#0xFE
	anl	a,r2
	mov	r3,a
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x80,00229$
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00137$
00229$:
;	genIfx
	mov	a,r2
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00150$
;	Peephole 300	removed redundant label 00230$
00137$:
;	genCall
	lcall	_eis1
00150$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:74: telpos=0;  
;	genAssign
	mov	_telpos,#0x00
;	s:/elektronik/eib/c/fb_common/fb_prot.c:75: IE1=0;		// IRQ zurücksetzen
;	genAssign
	clr	_TCON_3
;	s:/elektronik/eib/c/fb_common/fb_prot.c:76: EX1=1;		// externen Interrupt 0 wieder freigeben
;	genAssign
	setb	_IEN0_2
;	Peephole 300	removed redundant label 00151$
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:83: unsigned char get_ack(void)		// Byte empfangen und prüfen ob es ein ACK war
;	-----------------------------------------
;	 function get_ack
;	-----------------------------------------
_get_ack:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:89: ret=0;
;	genAssign
	mov	r2,#0x00
;	s:/elektronik/eib/c/fb_common/fb_prot.c:90: do 
;	genAssign
	mov	r3,#0x00
	mov	r4,#0x00
00107$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_P1_4,00105$
;	Peephole 300	removed redundant label 00118$
;	s:/elektronik/eib/c/fb_common/fb_prot.c:92: if(FBINC==1) n++;
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:95: if (get_byte()==0xCC && parity_ok) ret=1;
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:97: } while (n<3000);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:98: return(ret);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:103: void send_telegramm(void)		// sendet das Telegramm, das in telegramm[] vorher abgelegt wurde und berechnet die checksum
;	-----------------------------------------
;	 function send_telegramm
;	-----------------------------------------
_send_telegramm:
	push	_bp
	mov	_bp,sp
	inc	sp
;	s:/elektronik/eib/c/fb_common/fb_prot.c:107: r=0;
;	genAssign
	mov	r2,#0x00
;	s:/elektronik/eib/c/fb_common/fb_prot.c:108: do
00108$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:110: checksum=0;
;	genAssign
	mov	r3,#0x00
;	s:/elektronik/eib/c/fb_common/fb_prot.c:111: data_laenge=telegramm[5]&0x0F;	// Telegramm-Länge = Bit 0 bis 3
;	genAssign
;	genAnd
	mov	r0,_bp
	inc	r0
	mov	a,#0x0F
	anl	a,0x0005 + _telegramm
	mov	@r0,a
;	s:/elektronik/eib/c/fb_common/fb_prot.c:113: set_timer1(18780);			// Warten bis Bus frei ist
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x495C
	push	ar2
	push	ar3
	lcall	_set_timer1
	pop	ar3
	pop	ar2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:114: while(!TF1)
00103$:
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	_TCON_7,00105$
;	Peephole 300	removed redundant label 00125$
;	s:/elektronik/eib/c/fb_common/fb_prot.c:116: if(!FBINC) set_timer1(18780);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:118: TR1=0;
;	genAssign
	clr	_TCON_6
;	s:/elektronik/eib/c/fb_common/fb_prot.c:120: for(l=0;l<=data_laenge+6;l++)
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:122: sendbyte(telegramm[l]);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:123: checksum^=telegramm[l];
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:124: delay(1230);			// Interbyte-Abstand
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:120: for(l=0;l<=data_laenge+6;l++)
;	genPlus
;     genPlusIncr
	inc	r5
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00111$
00114$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:126: checksum=~checksum;
;	genCpl
	mov	a,r3
	cpl	a
;	s:/elektronik/eib/c/fb_common/fb_prot.c:127: sendbyte(checksum);
;	genCall
	mov	r3,a
;	Peephole 244.c	loading dpl from a instead of r3
	mov	dpl,a
	push	ar2
	lcall	_sendbyte
	pop	ar2
	clr	a
	rlc	a
;	s:/elektronik/eib/c/fb_common/fb_prot.c:128: if(get_ack()==1) r=3;		// wenn ACK empfangen, dann nicht nochmal senden
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:129: r++;
;	genPlus
;     genPlusIncr
	inc	r2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:130: telegramm[0]&=0xDF;			// Bit 5 löschen = Wiederholung
;	genAssign
;	genAnd
	mov	a,#0xDF
	anl	a,_telegramm
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,a
;	s:/elektronik/eib/c/fb_common/fb_prot.c:132: while(r<=3); 				// falls kein ACK max. 3 Mal wiederholen
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:136: void send_ack(void)			// wartet auf Timer 1 wegen korrekter Positionierung und sendet ACK (0xCC)
;	-----------------------------------------
;	 function send_ack
;	-----------------------------------------
_send_ack:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:138: while(!TF1) {}
00101$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00101$
;	Peephole 300	removed redundant label 00108$
;	s:/elektronik/eib/c/fb_common/fb_prot.c:139: sendbyte(0xCC);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:146: void ucd_opr(void)		// UCD Verbindungsaufbau
;	-----------------------------------------
;	 function ucd_opr
;	-----------------------------------------
_ucd_opr:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:148: if(!connected)		// wenn bereits verbunden: ignorieren
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	_connected,00103$
;	Peephole 300	removed redundant label 00106$
;	s:/elektronik/eib/c/fb_common/fb_prot.c:150: connected=1;
;	genAssign
	setb	_connected
;	s:/elektronik/eib/c/fb_common/fb_prot.c:151: conh=telegramm[1];		// phys. Adresse des Verbindungspartners
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	_conh,(_telegramm + 0x0001)
;	s:/elektronik/eib/c/fb_common/fb_prot.c:152: conl=telegramm[2];
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	_conl,(_telegramm + 0x0002)
;	s:/elektronik/eib/c/fb_common/fb_prot.c:153: send_ack();			// quittieren
;	genCall
	lcall	_send_ack
;	s:/elektronik/eib/c/fb_common/fb_prot.c:154: pcount=1;			// Paketzähler zurücksetzen
;	genAssign
	mov	_pcount,#0x01
00103$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ucd_clr'
;------------------------------------------------------------
;------------------------------------------------------------
;	s:/elektronik/eib/c/fb_common/fb_prot.c:159: void ucd_clr(void)		// UCD Verbindungsabbau
;	-----------------------------------------
;	 function ucd_clr
;	-----------------------------------------
_ucd_clr:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:161: if(conh==telegramm[1] && conl==telegramm[2] && connected)	// nur abbauen, wenn verbunden und Anforderung vom Verbindungspartner, kein ACK senden
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:163: connected=0;
;	genAssign
;	Peephole 250.a	using atomic test and clear
	jbc	_connected,00114$
;	Peephole 251.b	replaced sjmp to ret with ret
	ret
00114$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:164: pcount=1;			// Paketzähler zurücksetzen
;	genAssign
	mov	_pcount,#0x01
;	Peephole 300	removed redundant label 00105$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ncd_quit'
;------------------------------------------------------------
;------------------------------------------------------------
;	s:/elektronik/eib/c/fb_common/fb_prot.c:169: void ncd_quit(void)			// NCD Quittierung zurück senden. Setzt telegramm Bytes 0 bis 6 !!!
;	-----------------------------------------
;	 function ncd_quit
;	-----------------------------------------
_ncd_quit:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:171: telegramm[0]=0xB0;			// Control Byte			
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,#0xB0
;	s:/elektronik/eib/c/fb_common/fb_prot.c:172: telegramm[3]=telegramm[1];		// Zieladresse wird Quelladresse
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	r2,(_telegramm + 0x0001)
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0003),r2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:173: telegramm[4]=telegramm[2];
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	r2,(_telegramm + 0x0002)
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0004),r2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:174: telegramm[1]=pah;			// Quelladresse ist phys. Adresse
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0001),_pah
;	s:/elektronik/eib/c/fb_common/fb_prot.c:175: telegramm[2]=pal;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0002),_pal
;	s:/elektronik/eib/c/fb_common/fb_prot.c:176: telegramm[5]=0x60;			// DRL
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0005),#0x60
;	s:/elektronik/eib/c/fb_common/fb_prot.c:177: telegramm[6]|=0xC0;			// Bit 6 und 7 setzen (TCPI = 11 NCD Quittierung)
;	genAssign
;	genOr
	mov	a,#0xC0
	orl	a,0x0006 + _telegramm
	mov	r2,a
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),r2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:178: telegramm[6]&=0xFE;			// Bit 0 löschen 
;	genAnd
	mov	a,#0xFE
	anl	a,r2
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),a
;	s:/elektronik/eib/c/fb_common/fb_prot.c:179: send_telegramm();
;	genCall
;	Peephole 253.b	replaced lcall/ret with ljmp
	ljmp	_send_telegramm
;
;------------------------------------------------------------
;Allocation info for local variables in function 'read_masq'
;------------------------------------------------------------
;------------------------------------------------------------
;	s:/elektronik/eib/c/fb_common/fb_prot.c:183: void read_masq(void)			// Maskenversion senden
;	-----------------------------------------
;	 function read_masq
;	-----------------------------------------
_read_masq:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:187: send_ack();
;	genCall
	lcall	_send_ack
;	s:/elektronik/eib/c/fb_common/fb_prot.c:188: ncd_quit();				// NCD Quittierung senden
;	genCall
	lcall	_ncd_quit
;	s:/elektronik/eib/c/fb_common/fb_prot.c:190: telegramm[0]=0xB0;			// Control Byte
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,#0xB0
;	s:/elektronik/eib/c/fb_common/fb_prot.c:192: telegramm[5]=0x63;			// DRL
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0005),#0x63
;	s:/elektronik/eib/c/fb_common/fb_prot.c:193: telegramm[6]=0x43;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),#0x43
;	s:/elektronik/eib/c/fb_common/fb_prot.c:194: telegramm[7]=0x40;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),#0x40
;	s:/elektronik/eib/c/fb_common/fb_prot.c:195: telegramm[8]=0x00;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0008),#0x00
;	s:/elektronik/eib/c/fb_common/fb_prot.c:196: telegramm[9]=0x12;			// Maskenversion 1 = BCU1
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0009),#0x12
;	s:/elektronik/eib/c/fb_common/fb_prot.c:197: send_telegramm();
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:202: void read_memory(void)			// read_memory_request - Speicher auslesen und senden
;	-----------------------------------------
;	 function read_memory
;	-----------------------------------------
_read_memory:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:206: send_ack();				// erstmal quittieren
;	genCall
	lcall	_send_ack
;	s:/elektronik/eib/c/fb_common/fb_prot.c:207: ab=telegramm[7];			// Anzahl Bytes
;	genAssign
;	genAssign
	mov	r2,0x0007 + _telegramm
;	s:/elektronik/eib/c/fb_common/fb_prot.c:208: ncd_quit();
;	genCall
	push	ar2
	lcall	_ncd_quit
	pop	ar2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:210: for(n=0;n<ab;n++)
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:212: telegramm[n+10]=read_byte(telegramm[8],(telegramm[9]+n));    
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:210: for(n=0;n<ab;n++)
;	genPlus
;     genPlusIncr
	inc	r3
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00101$
00104$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:215: telegramm[0]=0xB0;			// read_memory_res senden
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,#0xB0
;	s:/elektronik/eib/c/fb_common/fb_prot.c:217: telegramm[5]=ab+0x63;		// DRL (Anzahl Bytes + 3)
;	genPlus
;     genPlusIncr
	mov	a,#0x63
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0005),a
;	s:/elektronik/eib/c/fb_common/fb_prot.c:218: telegramm[6]=(pcount<<2)|0x42;	// Paketzähler, TCPI und ersten beiden Befehlsbits
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:219: telegramm[7]=ab|0x40;		// letzten 2 Befehlsbits
;	genOr
	mov	a,#0x40
	orl	a,r2
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),a
;	s:/elektronik/eib/c/fb_common/fb_prot.c:220: send_telegramm();
;	genCall
	lcall	_send_telegramm
;	s:/elektronik/eib/c/fb_common/fb_prot.c:222: pcount++;				// Paketzähler erhöhen
;	genPlus
;     genPlusIncr
	inc	_pcount
;	s:/elektronik/eib/c/fb_common/fb_prot.c:223: pcount&=0x0F;				// max. 15
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:227: void write_memory(void)			// write_memory_request - empfangene Daten in Speicher schreiben
;	-----------------------------------------
;	 function write_memory
;	-----------------------------------------
_write_memory:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:231: send_ack();
;	genCall
	lcall	_send_ack
;	s:/elektronik/eib/c/fb_common/fb_prot.c:232: ab=telegramm[7]&0x0F;			// Anzahl Bytes
;	genAssign
;	genAnd
	mov	a,#0x0F
	anl	a,0x0007 + _telegramm
	mov	r2,a
;	s:/elektronik/eib/c/fb_common/fb_prot.c:233: ncd_quit();
;	genCall
	push	ar2
	lcall	_ncd_quit
	pop	ar2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:235: start_writecycle();
;	genCall
	push	ar2
	lcall	_start_writecycle
	pop	ar2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:236: for(n=0;n<ab;n++) 
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:238: write_byte(telegramm[8],telegramm[9]+n,telegramm[n+10]);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:239: if ((((telegramm[9]+n)&0x3F)==0x3F) && n!=(ab-1))		// Ende des 64-Byte Pageregisters, also zwischendurch flashen
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:241: stop_writecycle();
;	genCall
	push	ar2
	push	ar3
	lcall	_stop_writecycle
	pop	ar3
	pop	ar2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:242: start_writecycle();
;	genCall
	push	ar2
	push	ar3
	lcall	_start_writecycle
	pop	ar3
	pop	ar2
00106$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:236: for(n=0;n<ab;n++) 
;	genPlus
;     genPlusIncr
	inc	r3
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00104$
00107$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:245: stop_writecycle(); 
;	genCall
;	Peephole 253.b	replaced lcall/ret with ljmp
	ljmp	_stop_writecycle
;
;------------------------------------------------------------
;Allocation info for local variables in function 'set_pa'
;------------------------------------------------------------
;------------------------------------------------------------
;	s:/elektronik/eib/c/fb_common/fb_prot.c:249: void set_pa(void)			// neue phys. Adresse programmieren
;	-----------------------------------------
;	 function set_pa
;	-----------------------------------------
_set_pa:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:251: pah=telegramm[8];
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	_pah,(_telegramm + 0x0008)
;	s:/elektronik/eib/c/fb_common/fb_prot.c:252: pal=telegramm[9];
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	_pal,(_telegramm + 0x0009)
;	s:/elektronik/eib/c/fb_common/fb_prot.c:253: start_writecycle();
;	genCall
	lcall	_start_writecycle
;	s:/elektronik/eib/c/fb_common/fb_prot.c:254: write_byte(0x01,ADDRTAB+1,pah);		// in Flash schreiben
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:255: write_byte(0x01,ADDRTAB+2,pal);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:256: stop_writecycle();
;	genCall
;	Peephole 253.b	replaced lcall/ret with ljmp
	ljmp	_stop_writecycle
;
;------------------------------------------------------------
;Allocation info for local variables in function 'read_pa'
;------------------------------------------------------------
;------------------------------------------------------------
;	s:/elektronik/eib/c/fb_common/fb_prot.c:260: void read_pa(void)			// phys. Adresse senden
;	-----------------------------------------
;	 function read_pa
;	-----------------------------------------
_read_pa:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:264: send_ack();
;	genCall
	lcall	_send_ack
;	s:/elektronik/eib/c/fb_common/fb_prot.c:266: telegramm[0]=0xB0;			// read_memory_res senden
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,#0xB0
;	s:/elektronik/eib/c/fb_common/fb_prot.c:268: telegramm[1]=pah;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0001),_pah
;	s:/elektronik/eib/c/fb_common/fb_prot.c:269: telegramm[2]=pal;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0002),_pal
;	s:/elektronik/eib/c/fb_common/fb_prot.c:270: telegramm[3]=0x00;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0003),#0x00
;	s:/elektronik/eib/c/fb_common/fb_prot.c:271: telegramm[4]=0x00;			
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0004),#0x00
;	s:/elektronik/eib/c/fb_common/fb_prot.c:272: telegramm[5]=0xE1;			// DRL
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0005),#0xE1
;	s:/elektronik/eib/c/fb_common/fb_prot.c:273: telegramm[6]=0x01;		
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),#0x01
;	s:/elektronik/eib/c/fb_common/fb_prot.c:274: telegramm[7]=0x40;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),#0x40
;	s:/elektronik/eib/c/fb_common/fb_prot.c:275: send_telegramm();
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:280: unsigned char read_objflags(unsigned char objno)	// Objektflags lesen
;	-----------------------------------------
;	 function read_objflags
;	-----------------------------------------
_read_objflags:
;	genReceive
	mov	r2,dpl
;	s:/elektronik/eib/c/fb_common/fb_prot.c:284: ctp=read_byte(0x01,COMMSTABPTR);		// COMMSTAB Pointer
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:285: addr=ctp+3+3*objno;
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:286: flags=read_byte(0x01,addr);	// Objektflags
;	genIpush
	push	ar3
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r2,dpl
	dec	sp
;	genAssign
	mov	dpl,r2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:287: return(flags);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:291: int find_ga(unsigned char objno)		// Gruppenadresse über Assoziationstabelle finden (letzter Eintrag, falls mehrere)
;	-----------------------------------------
;	 function find_ga
;	-----------------------------------------
_find_ga:
	push	_bp
	mov	_bp,sp
	inc	sp
;	genReceive
	mov	r2,dpl
;	s:/elektronik/eib/c/fb_common/fb_prot.c:296: gapos=0;
;	genAssign
	mov	r3,#0x00
;	s:/elektronik/eib/c/fb_common/fb_prot.c:297: asstab=read_byte(0x01,ASSOCTABPTR);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:298: assno=read_byte(0x01,asstab);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:299: for(n=0;n<assno;n++)
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:301: if(read_byte(0x01,asstab+2+2*n)==objno)
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:303: gapos=read_byte(0x01,asstab+1+2*n);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:316: return(ga);
;	genIpop
	pop	ar4
;	s:/elektronik/eib/c/fb_common/fb_prot.c:303: gapos=read_byte(0x01,asstab+1+2*n);
00108$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:299: for(n=0;n<assno;n++)
;	genPlus
;     genPlusIncr
	inc	r7
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00106$
00109$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:306: if(gapos!=0)
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x00,00121$
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00104$
00121$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:308: gah=read_byte(0x01,ADDRTAB+1+gapos*2);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:309: gal=read_byte(0x01,ADDRTAB+2+gapos*2);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:310: ga=gal+256*gah;
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:314: ga=0;
;	genAssign
	mov	r3,#0x00
	mov	r2,#0x00
00105$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:316: return(ga);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:320: unsigned char gapos_in_gat(unsigned char gah, unsigned char gal)
;	-----------------------------------------
;	 function gapos_in_gat
;	-----------------------------------------
_gapos_in_gat:
	push	_bp
	mov	_bp,sp
;	genReceive
	mov	r2,dpl
;	s:/elektronik/eib/c/fb_common/fb_prot.c:324: ga_count=read_byte(0x01,ADDRTAB);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:325: ga_position=0xFF; 
;	genAssign
	mov	r4,#0xFF
;	s:/elektronik/eib/c/fb_common/fb_prot.c:326: if (ga_count>0)
;	genIfx
	mov	a,r3
;	genIfxJump
;	Peephole 108.c	removed ljmp by inverse jump logic
	jz	00105$
;	Peephole 300	removed redundant label 00118$
;	s:/elektronik/eib/c/fb_common/fb_prot.c:328: for (n=1;n<=ga_count;n++)
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:330: if (gah==read_byte(0x01,ADDRTAB+n*2+1) && gal==read_byte(0x01,ADDRTAB+n*2+2)) ga_position=n;
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:328: for (n=1;n<=ga_count;n++)
;	genPlus
;     genPlusIncr
	inc	r5
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00106$
00105$:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:333: return (ga_position);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:337: void write_delay_record(unsigned char objno, unsigned char delay_status, long delay_target)		// Schreibt die Schalt-Verzögerungswerte ins Flash
;	-----------------------------------------
;	 function write_delay_record
;	-----------------------------------------
_write_delay_record:
	push	_bp
	mov	_bp,sp
;	genReceive
	mov	r2,dpl
;	s:/elektronik/eib/c/fb_common/fb_prot.c:339: start_writecycle();
;	genCall
	push	ar2
	lcall	_start_writecycle
	pop	ar2
;	s:/elektronik/eib/c/fb_common/fb_prot.c:340: write_byte(0x00,objno*5,objno+delay_status);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:341: write_byte(0x00,1+objno*5,delay_target>>24);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:342: write_byte(0x00,2+objno*5,delay_target>>16);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:343: write_byte(0x00,3+objno*5,delay_target>>8);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:344: write_byte(0x00,4+objno*5,delay_target);
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
;	s:/elektronik/eib/c/fb_common/fb_prot.c:345: stop_writecycle();
;	genCall
	lcall	_stop_writecycle
;	Peephole 300	removed redundant label 00101$
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'restart_prot'
;------------------------------------------------------------
;------------------------------------------------------------
;	s:/elektronik/eib/c/fb_common/fb_prot.c:349: void restart_prot(void)		// Protokoll-relevante Parameter zurücksetzen
;	-----------------------------------------
;	 function restart_prot
;	-----------------------------------------
_restart_prot:
;	s:/elektronik/eib/c/fb_common/fb_prot.c:351: pah=read_byte(0x01,ADDRTAB+1);	// phys. Adresse einlesen
;	genIpush
	mov	a,#0x17
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	_pah,dpl
	dec	sp
;	s:/elektronik/eib/c/fb_common/fb_prot.c:352: pal=read_byte(0x01,ADDRTAB+2);
;	genIpush
	mov	a,#0x18
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	_pal,dpl
	dec	sp
;	s:/elektronik/eib/c/fb_common/fb_prot.c:354: progmode=0;			// kein Programmiermodus
;	genAssign
	clr	_progmode
;	s:/elektronik/eib/c/fb_common/fb_prot.c:355: pcount=1;			// Paketzähler initialisieren
;	genAssign
	mov	_pcount,#0x01
;	s:/elektronik/eib/c/fb_common/fb_prot.c:356: connected=0;			// keine Verbindung
;	genAssign
	clr	_connected
;	s:/elektronik/eib/c/fb_common/fb_prot.c:358: telpos=0;			// empfangene Bytes an dieser Position im Array telegramm[] ablegen
;	genAssign
	mov	_telpos,#0x00
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'pin_changed'
;------------------------------------------------------------
;pinno                     Allocated to registers r2 
;------------------------------------------------------------
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:13: void pin_changed(unsigned char pinno)
;	-----------------------------------------
;	 function pin_changed
;	-----------------------------------------
_pin_changed:
;	genReceive
	mov	r2,dpl
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:15: EX1=0;
;	genAssign
	clr	_IEN0_2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:17: if (debounce(pinno))			// Entprellzeit abwarten und prüfen
;	genCall
	mov	dpl,r2
	push	ar2
	lcall	_debounce
	mov	a,dpl
	pop	ar2
;	genIfx
;	genIfxJump
	jnz	00126$
	ljmp	00117$
00126$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:19: switch (pin_function(pinno))	// Funktion des Eingangs
;	genCall
	mov	dpl,r2
	push	ar2
	lcall	_pin_function
	mov	r3,dpl
	pop	ar2
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x00,00127$
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00101$
00127$:
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x01,00128$
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00106$
00128$:
	ljmp	00117$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:21: case 0x00:				// Funktion Schalten
00101$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:22: if(((portbuffer>>pinno)&0x01)==0 && ((p0h>>pinno)&0x01)==1)	
;	genRightShift
	mov	b,r2
	inc	b
	mov	a,_portbuffer
	sjmp	00130$
00129$:
	clr	c
	rrc	a
00130$:
	djnz	b,00129$
;	genAnd
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	acc.0,00103$
;	Peephole 300	removed redundant label 00131$
;	genRightShift
	mov	b,r2
	inc	b
	mov	a,_p0h
	sjmp	00133$
00132$:
	clr	c
	rrc	a
00133$:
	djnz	b,00132$
;	genAnd
	anl	a,#0x01
	mov	r3,a
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x01,00103$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00134$
;	Peephole 300	removed redundant label 00135$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:24: schalten(1,pinno);			// steigende Flanke Eingang x.1
;	genIpush
	push	ar2
	push	ar2
;	genCall
	mov	dpl,#0x01
	lcall	_schalten
	dec	sp
	pop	ar2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:25: schalten(1,pinno+8);			// steigende Flanke Eingang x.2
;	genPlus
;     genPlusIncr
	mov	a,#0x08
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	r3,a
;	genIpush
	push	ar2
	push	ar3
;	genCall
	mov	dpl,#0x01
	lcall	_schalten
	dec	sp
	pop	ar2
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00104$
00103$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:29: schalten(0,pinno);			// fallende Flanke Eingang x.1
;	genIpush
	push	ar2
	push	ar2
;	genCall
	mov	dpl,#0x00
	lcall	_schalten
	dec	sp
	pop	ar2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:30: schalten(0,pinno+8);			// fallende Flanke Eingang x.2
;	genPlus
;     genPlusIncr
	mov	a,#0x08
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	r3,a
;	genIpush
	push	ar2
	push	ar3
;	genCall
	mov	dpl,#0x00
	lcall	_schalten
	dec	sp
	pop	ar2
00104$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:32: send_cyclic(pinno);
;	genCall
	mov	dpl,r2
	push	ar2
	lcall	_send_cyclic
	pop	ar2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:33: case 0x01:				// Funktion Dimmen
00106$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:34: switch (operation(pinno))			// Bedienung
;	genCall
	mov	dpl,r2
	push	ar2
	lcall	_operation
	mov	r3,dpl
	pop	ar2
;	genCmpGt
;	genCmp
;	genIfxJump
;	Peephole 132.b	optimized genCmpGt by inverse logic (acc differs)
	mov	a,r3
	add	a,#0xff - 0x04
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 160.a	removed sjmp by inverse jump logic
	jc	00117$
;	Peephole 300	removed redundant label 00136$
;	genJumpTab
	mov	a,r3
;	Peephole 254	optimized left shift
	add	a,r3
	add	a,r3
	mov	dptr,#00137$
	jmp	@a+dptr
00137$:
	ljmp	00107$
	ljmp	00110$
	ljmp	00111$
	ljmp	00112$
	ljmp	00113$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:36: case 0x00:					// Einflächenbedienung heller/dunkler (UM)
00107$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:37: if (switch_dim(pinno)==0)			// prüfen, ob Taster länger gedrückt als Schalten/Dimmen-Zeit
;	genCall
	mov	dpl,r2
	lcall	_switch_dim
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:43: case 0x01:					// Zweiflächenbedienung heller (EIN)
00110$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:44: case 0x02:					// Zweiflächenbedienung dunkler (AUS)
00111$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:45: case 0x03:					// Zweiflächenbedienung heller (UM)
00112$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:46: case 0x04:					// Zweiflächenbedienung dunkler (UM)
00113$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:48: }
00117$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:50: EX1=1;
;	genAssign
	setb	_IEN0_2
;	Peephole 300	removed redundant label 00118$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'send_cyclic'
;------------------------------------------------------------
;pinno                     Allocated to registers 
;------------------------------------------------------------
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:54: void send_cyclic(unsigned char pinno)
;	-----------------------------------------
;	 function send_cyclic
;	-----------------------------------------
_send_cyclic:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:56: pinno;
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'operation'
;------------------------------------------------------------
;pinno                     Allocated to registers 
;------------------------------------------------------------
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:60: unsigned char operation(unsigned char pinno)
;	-----------------------------------------
;	 function operation
;	-----------------------------------------
_operation:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:63: return(1);
;	genRet
	mov	dpl,#0x01
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'switch_dim'
;------------------------------------------------------------
;pinno                     Allocated to registers 
;------------------------------------------------------------
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:67: unsigned char switch_dim(unsigned char pinno)
;	-----------------------------------------
;	 function switch_dim
;	-----------------------------------------
_switch_dim:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:70: return(1);
;	genRet
	mov	dpl,#0x01
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'schalten'
;------------------------------------------------------------
;pinno                     Allocated to stack - offset -3
;risefall                  Allocated to registers r2 
;func                      Allocated to registers r3 
;ga                        Allocated to registers r2 r4 
;------------------------------------------------------------
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:74: void schalten(unsigned char risefall, unsigned char pinno)	// Schaltbefehl senden
;	-----------------------------------------
;	 function schalten
;	-----------------------------------------
_schalten:
	push	_bp
	mov	_bp,sp
;	genReceive
	mov	r2,dpl
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:79: func=read_byte(0x01,0xD7+((pinno&0x07)*5));
;	genAnd
	mov	r0,_bp
	dec	r0
	dec	r0
	dec	r0
	mov	a,#0x07
	anl	a,@r0
;	genMult
;	genMultOneByte
	mov	b,#0x05
	mul	ab
;	genPlus
;     genPlusIncr
	add	a,#0xD7
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
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:80: if (risefall==1) func=(func>>2)&0x03;		// steigende Flanke
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r2,#0x01,00102$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00130$
;	Peephole 300	removed redundant label 00131$
;	genRightShift
;	genRightShiftLiteral
;	genrshOne
	mov	a,r3
	rr	a
	rr	a
	anl	a,#0x3f
	mov	r2,a
;	genAnd
	mov	a,#0x03
	anl	a,r2
	mov	r3,a
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00103$
00102$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:81: else func=func&0x03;				// fallende Flanke
;	genAnd
	anl	ar3,#0x03
00103$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:82: if (func!=0)
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x00,00132$
	ljmp	00120$
00132$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:84: ga=find_ga(pinno);
;	genCall
	mov	r0,_bp
	dec	r0
	dec	r0
	dec	r0
	mov	dpl,@r0
	push	ar3
	lcall	_find_ga
	mov	r2,dpl
	mov	r4,dph
	pop	ar3
;	genAssign
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:85: if (ga!=0)
;	genCmpEq
;	gencjneshort
	cjne	r2,#0x00,00133$
	cjne	r4,#0x00,00133$
	ljmp	00120$
00133$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:87: telegramm[0]=0xBC;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,#0xBC
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:88: telegramm[1]=pah;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0001),_pah
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:89: telegramm[2]=pal;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0002),_pal
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:90: telegramm[3]=ga>>8;
;	genGetByte
	mov	ar5,r4
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0003),r5
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:91: telegramm[4]=ga;
;	genCast
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0004),r2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:92: telegramm[5]=0xD1;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0005),#0xD1
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:93: telegramm[6]=0x00;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),#0x00
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:94: if (func==0x01) telegramm[7]=0x81;	// EIN
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x01,00105$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00134$
;	Peephole 300	removed redundant label 00135$
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),#0x81
00105$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:95: if (func==0x02) telegramm[7]=0x80;	// AUS
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x02,00107$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00136$
;	Peephole 300	removed redundant label 00137$
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),#0x80
00107$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:96: if (func==0x03)				// UM
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r3,#0x03,00112$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00138$
;	Peephole 300	removed redundant label 00139$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:98: if (((objstate>>pinno)&0x01)==0x01) telegramm[7]=0x80;	// AUS
;	genRightShift
;	genSignedRightShift
	mov	r0,_bp
	dec	r0
	dec	r0
	dec	r0
	mov	b,@r0
	inc	b
	mov	r2,_objstate
;	peephole 177.h	optimized mov sequence
	mov	a,(_objstate + 1)
	mov	r3,a
	rlc	a
	mov	ov,c
	sjmp	00141$
00140$:
	mov	c,ov
	mov	a,r3
	rrc	a
	mov	r3,a
	mov	a,r2
	rrc	a
	mov	r2,a
00141$:
	djnz	b,00140$
;	genAnd
	anl	ar2,#0x01
	mov	r3,#0x00
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.a	optimized misc jump sequence
	cjne	r2,#0x01,00109$
	cjne	r3,#0x00,00109$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00142$
;	Peephole 300	removed redundant label 00143$
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),#0x80
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00112$
00109$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:99: else telegramm[7]=0x81;					// EIN
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),#0x81
00112$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:101: if (telegramm[7]==0x80) objstate=objstate&(0xFFFF-(0x0001<<pinno));
;	genAssign
;	genCmpEq
;	gencjneshort
	mov	a,0x0007 + _telegramm
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	a,#0x80,00114$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00144$
;	Peephole 300	removed redundant label 00145$
;	genLeftShift
	mov	r0,_bp
	dec	r0
	dec	r0
	dec	r0
	mov	b,@r0
	inc	b
	mov	r2,#0x01
	mov	r3,#0x00
	sjmp	00147$
00146$:
	mov	a,r2
;	Peephole 254	optimized left shift
	add	a,r2
	mov	r2,a
	mov	a,r3
	rlc	a
	mov	r3,a
00147$:
	djnz	b,00146$
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
;	genAnd
	mov	a,r2
	anl	_objstate,a
	mov	a,r3
	anl	(_objstate + 1),a
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00115$
00114$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:102: else objstate=objstate|(0x0001<<pinno);
;	genLeftShift
	mov	r0,_bp
	dec	r0
	dec	r0
	dec	r0
	mov	b,@r0
	inc	b
	mov	r2,#0x01
	mov	r3,#0x00
	sjmp	00149$
00148$:
	mov	a,r2
;	Peephole 254	optimized left shift
	add	a,r2
	mov	r2,a
	mov	a,r3
	rlc	a
	mov	r3,a
00149$:
	djnz	b,00148$
;	genOr
	mov	a,r2
	orl	_objstate,a
	mov	a,r3
	orl	(_objstate + 1),a
00115$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:103: send_telegramm();
;	genCall
	lcall	_send_telegramm
00120$:
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'pin_function'
;------------------------------------------------------------
;pinno                     Allocated to registers 
;------------------------------------------------------------
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:111: unsigned char pin_function(unsigned char pinno)		// Funktion des Eingangs ermitteln
;	-----------------------------------------
;	 function pin_function
;	-----------------------------------------
_pin_function:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:114: return (0);
;	genRet
	mov	dpl,#0x00
;	Peephole 300	removed redundant label 00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'debounce'
;------------------------------------------------------------
;pinno                     Allocated to registers 
;debtime                   Allocated to registers r2 
;n                         Allocated to registers r3 
;------------------------------------------------------------
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:118: unsigned char debounce(unsigned char pinno)	// Entprellzeit abwarten und prüfen !! Prüfung fehlt noch !!
;	-----------------------------------------
;	 function debounce
;	-----------------------------------------
_debounce:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:122: debtime=read_byte(0x01,DEBTIME);			// Entprellzeit in 0,5ms Schritten
;	genIpush
	mov	a,#0xD2
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r2,dpl
	dec	sp
;	genAssign
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:123: if (debtime>0)
;	genIfx
	mov	a,r2
;	genIfxJump
;	Peephole 108.c	removed ljmp by inverse jump logic
	jz	00102$
;	Peephole 300	removed redundant label 00113$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:125: for(n=0;n<debtime;n++)
;	genAssign
	mov	r3,#0x00
00103$:
;	genCmpLt
;	genCmp
	clr	c
	mov	a,r3
	subb	a,r2
;	genIfxJump
;	Peephole 108.a	removed ljmp by inverse jump logic
	jnc	00102$
;	Peephole 300	removed redundant label 00114$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:127: delay(500);
;	genCall
;	Peephole 182.b	used 16 bit load of dptr
	mov	dptr,#0x01F4
	push	ar2
	push	ar3
	lcall	_delay
	pop	ar3
	pop	ar2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:125: for(n=0;n<debtime;n++)
;	genPlus
;     genPlusIncr
	inc	r3
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00103$
00102$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:131: return(1);
;	genRet
	mov	dpl,#0x01
;	Peephole 300	removed redundant label 00107$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'eis1'
;------------------------------------------------------------
;objno                     Allocated to registers r7 
;port_pattern              Allocated to stack - offset 1
;objflags                  Allocated to stack - offset 2
;gapos                     Allocated to stack - offset 3
;atp                       Allocated to registers r3 
;assno                     Allocated to stack - offset 4
;delay_base                Allocated to registers r4 
;n                         Allocated to stack - offset 5
;delay_onoff               Allocated to registers r2 
;delay_status              Allocated to registers r6 
;gaposh                    Allocated to registers r5 
;delay_zeit                Allocated to stack - offset 6
;delay_target              Allocated to stack - offset 7
;ga                        Allocated to registers r2 r4 
;sloc0                     Allocated to stack - offset 11
;------------------------------------------------------------
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:136: void eis1(void)				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
;	-----------------------------------------
;	 function eis1
;	-----------------------------------------
_eis1:
	push	_bp
;	peephole 177.h	optimized mov sequence
	mov	a,sp
	mov	_bp,a
	add	a,#0x0b
	mov	sp,a
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:143: ga=telegramm[3];
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	dpl,(_telegramm + 0x0003)
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:145: ga=ga+telegramm[4];
;	genAssign
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:149: gapos=gapos_in_gat(telegramm[3],telegramm[4]);
;	genIpush
	push	0x0004 + _telegramm
;	genCall
	lcall	_gapos_in_gat
	mov	r2,dpl
	dec	sp
;	genAssign
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	mov	@r0,ar2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:150: if (gapos!=0xFF)	
;	genCmpEq
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
;	gencjneshort
	cjne	@r0,#0xFF,00177$
	ljmp	00151$
00177$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:152: send_ack();
;	genCall
	lcall	_send_ack
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:153: atp=read_byte(0x01,0x11);			// Association Table Pointer
;	genIpush
	mov	a,#0x11
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r3,dpl
	dec	sp
;	genAssign
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:154: assno=read_byte(0x01,atp);		// Erster Eintrag = Anzahl Einträge
;	genIpush
	push	ar3
	push	ar3
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r4,dpl
	dec	sp
	pop	ar3
;	genAssign
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	@r0,ar4
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:156: for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
;	genPlus
;     genPlusIncr
	mov	a,#0x02
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r5,a
;	genPlus
;     genPlusIncr
	inc	r3
;	genAssign
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,#0x00
00147$:
;	genCmpLt
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,_bp
	add	a,#0x04
	mov	r1,a
;	genCmp
	clr	c
	mov	a,@r0
	subb	a,@r1
;	genIfxJump
	jc	00178$
	ljmp	00151$
00178$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:158: gaposh=read_byte(0x01,atp+1+(n*2));
;	genIpush
	push	ar5
;	genLeftShift
;	genLeftShiftLiteral
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
;	genlshOne
	mov	a,@r0
	add	a,acc
;	genPlus
	mov	r7,a
;	Peephole 177.b	removed redundant mov
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r5,a
;	genIpush
	push	ar3
	push	ar7
	push	ar5
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r5,dpl
	dec	sp
	pop	ar7
	pop	ar3
;	genAssign
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:159: if(gapos==gaposh)					// Wenn Positionsnummer übereinstimmt
;	genCmpEq
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
;	gencjne
;	gencjneshort
	mov	a,@r0
	cjne	a,ar5,00179$
	mov	a,#0x01
	sjmp	00180$
00179$:
	clr	a
00180$:
;	genIpop
	pop	ar5
;	genIfx
;	genIfxJump
	jnz	00181$
	ljmp	00149$
00181$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:161: objno=read_byte(0x01,atp+2+(n*2));			// Objektnummer
;	genIpush
	push	ar3
;	genPlus
;	Peephole 236.g	used r7 instead of ar7
	mov	a,r7
;	Peephole 236.a	used r5 instead of ar5
	add	a,r5
	mov	r7,a
;	genIpush
	push	ar3
	push	ar5
	push	ar7
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r7,dpl
	dec	sp
	pop	ar5
	pop	ar3
;	genAssign
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:162: objflags=read_objflags(objno);			// Objekt Flags lesen
;	genCall
	mov	dpl,r7
	push	ar5
	push	ar7
	lcall	_read_objflags
	mov	r3,dpl
	pop	ar7
	pop	ar5
;	genAssign
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,ar3
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:163: if((objflags&0x04)==0x04)				// Kommunikation zulässig (Bit 2 = communication enable) 
;	genAnd
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,#0x04
	anl	a,@r0
	mov	r3,a
;	genCmpEq
;	gencjne
;	gencjneshort
;	Peephole 241.d	optimized compare
	clr	a
	cjne	r3,#0x04,00182$
	inc	a
00182$:
;	Peephole 300	removed redundant label 00183$
;	genIpop
	pop	ar3
;	genIfx
;	genIfxJump
	jnz	00184$
	ljmp	00149$
00184$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:165: port_pattern=0x01<<objno;
;	genIpush
	push	ar5
;	genLeftShift
	mov	b,r7
	inc	b
	mov	r0,_bp
	inc	r0
	mov	a,#0x01
	sjmp	00187$
00185$:
	add	a,acc
00187$:
	djnz	b,00185$
	mov	@r0,a
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:166: if((port_pattern&pdir)==port_pattern)		// Portpin darf beschrieben werden
;	genAnd
	mov	r0,_bp
	inc	r0
	mov	a,_pdir
	anl	a,@r0
	mov	r5,a
;	genCmpEq
	mov	r0,_bp
	inc	r0
;	gencjne
;	gencjneshort
	mov	a,@r0
	cjne	a,ar5,00188$
	mov	a,#0x01
	sjmp	00189$
00188$:
	clr	a
00189$:
;	genIpop
	pop	ar5
;	genIfx
;	genIfxJump
	jnz	00190$
	ljmp	00134$
00190$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:168: if((objflags&0x10)==0x10)				// Schreiben zulässig (Bit 4 = write enable)
;	genIpush
	push	ar5
;	genAnd
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,#0x10
	anl	a,@r0
	mov	r5,a
;	genCmpEq
;	gencjne
;	gencjneshort
;	Peephole 241.d	optimized compare
	clr	a
	cjne	r5,#0x10,00191$
	inc	a
00191$:
;	Peephole 300	removed redundant label 00192$
;	genIpop
	pop	ar5
;	genIfx
;	genIfxJump
	jnz	00193$
	ljmp	00134$
00193$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:170: delay_base=read_byte(0x01,(((objno+1)>>1)+DELAYTAB));   
;	genIpush
	push	ar5
;	genCast
	mov	ar5,r7
	mov	r2,#0x00
;	genPlus
;     genPlusIncr
	inc	r5
	cjne	r5,#0x00,00194$
	inc	r2
00194$:
;	genRightShift
;	genSignedRightShift
;	genRightShiftLiteral
;	genrshTwo
	mov	a,r2
	mov	c,acc.7
	rrc	a
	xch	a,r5
	rrc	a
	xch	a,r5
	mov	r2,a
;	genCast
;	genPlus
;     genPlusIncr
	mov	a,#0xF9
;	Peephole 236.a	used r5 instead of ar5
	add	a,r5
	mov	r5,a
;	genIpush
	push	ar3
	push	ar5
	push	ar7
	push	ar5
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r2,dpl
	dec	sp
	pop	ar7
	pop	ar5
	pop	ar3
;	genAssign
	mov	ar4,r2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:171: if((objno&0x01)==0x01) delay_base&=0x0F;
;	genAnd
	mov	a,#0x01
	anl	a,r7
	mov	r2,a
;	genCmpEq
;	gencjne
;	gencjneshort
;	Peephole 241.d	optimized compare
	clr	a
	cjne	r2,#0x01,00195$
	inc	a
00195$:
;	Peephole 300	removed redundant label 00196$
;	genIpop
	pop	ar5
;	genIfx
;	genIfxJump
;	Peephole 108.c	removed ljmp by inverse jump logic
	jz	00102$
;	Peephole 300	removed redundant label 00197$
;	genAnd
	anl	ar4,#0x0F
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00103$
00102$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:172: else delay_base=(delay_base&0xF0)>>4;
;	genAnd
	mov	a,#0xF0
	anl	a,r4
;	genRightShift
;	genRightShiftLiteral
;	genrshOne
	mov	r2,a
;	Peephole 105	removed redundant mov
	swap	a
	anl	a,#0x0f
	mov	r4,a
00103$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:174: delay_onoff=0;
;	genIpush
	push	ar5
;	genAssign
	mov	r2,#0x00
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:175: delay_status=0;
;	genAssign
	mov	r6,#0x00
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:176: delay_zeit=read_byte(0x01,0xEA);
;	genIpush
	push	ar2
	push	ar3
	push	ar4
	push	ar6
	push	ar7
	mov	a,#0xEA
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r5,dpl
	dec	sp
	pop	ar7
	pop	ar6
	pop	ar4
	pop	ar3
	pop	ar2
;	genAssign
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	@r0,ar5
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:177: delay_zeit=((delay_zeit>>objno)&0x01);
;	genRightShift
	mov	b,r7
	inc	b
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,@r0
	sjmp	00199$
00198$:
	clr	c
	rrc	a
00199$:
	djnz	b,00198$
	mov	r5,a
;	genAnd
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,#0x01
	anl	a,r5
	mov	@r0,a
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:179: switch (telegramm[7])
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	@r0,(_telegramm + 0x0007)
;	genCmpEq
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
;	gencjne
;	gencjneshort
;	Peephole 241.h	optimized compare
	clr	a
	cjne	@r0,#0x80,00200$
	inc	a
00200$:
;	Peephole 300	removed redundant label 00201$
;	genIpop
	pop	ar5
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00104$
;	Peephole 300	removed redundant label 00202$
;	genCmpEq
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
;	gencjneshort
	cjne	@r0,#0x81,00203$
	ljmp	00112$
00203$:
	ljmp	00121$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:181: case 0x80:					// Ausschalten
00104$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:182: delay_onoff=read_byte(0x01,(objno+0xE2));
;	genIpush
	push	ar5
;	genPlus
;     genPlusIncr
	mov	a,#0xE2
;	Peephole 236.a	used r7 instead of ar7
	add	a,r7
	mov	r5,a
;	genIpush
	push	ar3
	push	ar4
	push	ar6
	push	ar7
	push	ar5
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r5,dpl
	dec	sp
	pop	ar7
	pop	ar6
	pop	ar4
	pop	ar3
;	genAssign
	mov	ar2,r5
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:183: if(delay_onoff==0x00 || delay_zeit==0x01)
;	genIpop
	pop	ar5
;	genIfx
	mov	a,r2
;	genIfxJump
;	Peephole 108.c	removed ljmp by inverse jump logic
	jz	00108$
;	Peephole 300	removed redundant label 00204$
;	genCmpEq
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	@r0,#0x01,00109$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00205$
;	Peephole 300	removed redundant label 00206$
00108$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:185: if (((read_byte(0x01,RELMODE)>>objno)&0x01)==0x00)
;	genIpush
	push	ar5
;	genIpush
	push	ar2
	push	ar3
	push	ar4
	push	ar6
	push	ar7
	mov	a,#0xF2
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r5,dpl
	dec	sp
	pop	ar7
	pop	ar6
	pop	ar4
	pop	ar3
	pop	ar2
;	genRightShift
	mov	b,r7
	inc	b
	mov	a,r5
	sjmp	00208$
00207$:
	clr	c
	rrc	a
00208$:
	djnz	b,00207$
;	genAnd
	anl	a,#0x01
;	genIpop
	pop	ar5
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00106$
;	Peephole 300	removed redundant label 00209$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:187: portbuffer=portbuffer&~port_pattern;		// sofort ausschalten (Schliesserbetrieb)
;	genIpush
	push	ar5
;	genCpl
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	cpl	a
;	genAnd
	mov	r5,a
;	Peephole 105	removed redundant mov
	anl	_portbuffer,a
;	genIpop
	pop	ar5
	ljmp	00121$
00106$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:191: portbuffer=portbuffer|port_pattern;		// sofort ausschalten (Öffnerbetrieb)
;	genOr
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	orl	_portbuffer,a
	ljmp	00121$
00109$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:196: delay_status=0x80;				// verzögert
;	genAssign
	mov	r6,#0x80
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:198: break;
	ljmp	00121$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:199: case 0x81:					// Einschalten
00112$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:200: delay_onoff=read_byte(0x01,(objno+0xDA));
;	genIpush
	push	ar5
;	genPlus
;     genPlusIncr
	mov	a,#0xDA
;	Peephole 236.a	used r7 instead of ar7
	add	a,r7
	mov	r5,a
;	genIpush
	push	ar3
	push	ar4
	push	ar6
	push	ar7
	push	ar5
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r5,dpl
	dec	sp
	pop	ar7
	pop	ar6
	pop	ar4
	pop	ar3
;	genAssign
	mov	ar2,r5
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:201: if(delay_onoff==0x00)
;	genIpop
	pop	ar5
;	genIfx
	mov	a,r2
;	genIfxJump
	jz	00210$
	ljmp	00119$
00210$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:203: if(delay_zeit==0x01) 			// Zeitschaltfunktion 
;	genCmpEq
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	@r0,#0x01,00114$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00211$
;	Peephole 300	removed redundant label 00212$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:205: delay_status=0x80;
;	genIpush
	push	ar5
;	genAssign
	mov	r6,#0x80
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:206: delay_onoff=read_byte(0x01,(objno+0xE2));
;	genPlus
;     genPlusIncr
	mov	a,#0xE2
;	Peephole 236.a	used r7 instead of ar7
	add	a,r7
	mov	r5,a
;	genIpush
	push	ar3
	push	ar4
	push	ar6
	push	ar7
	push	ar5
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r5,dpl
	dec	sp
	pop	ar7
	pop	ar6
	pop	ar4
	pop	ar3
;	genAssign
	mov	ar2,r5
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:156: for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
;	genIpop
	pop	ar5
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:206: delay_onoff=read_byte(0x01,(objno+0xE2));
00114$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:208: if (((read_byte(0x01,RELMODE)>>objno)&0x01)==0x00)
;	genIpush
	push	ar5
;	genIpush
	push	ar2
	push	ar3
	push	ar4
	push	ar6
	push	ar7
	mov	a,#0xF2
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r5,dpl
	dec	sp
	pop	ar7
	pop	ar6
	pop	ar4
	pop	ar3
	pop	ar2
;	genRightShift
	mov	b,r7
	inc	b
	mov	a,r5
	sjmp	00214$
00213$:
	clr	c
	rrc	a
00214$:
	djnz	b,00213$
;	genAnd
	anl	a,#0x01
;	genIpop
	pop	ar5
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00116$
;	Peephole 300	removed redundant label 00215$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:210: portbuffer=portbuffer|port_pattern;		// sofort einschalten (Schliesserbetrieb)
;	genOr
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	orl	_portbuffer,a
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00121$
00116$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:214: portbuffer=portbuffer&~port_pattern;		// sofort einschalten (Öffnerbetrieb)
;	genIpush
	push	ar5
;	genCpl
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	cpl	a
;	genAnd
	mov	r5,a
;	Peephole 105	removed redundant mov
	anl	_portbuffer,a
;	genIpop
	pop	ar5
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00121$
00119$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:219: delay_status=0x90;				// verzögert
;	genAssign
	mov	r6,#0x90
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:223: }
00121$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:224: if(delay_status!=0)								// wenn Verzögerung, dann timer-Wert schreiben
;	genCmpEq
;	gencjneshort
	cjne	r6,#0x00,00216$
	ljmp	00123$
00216$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:227: delay_target=delay_onoff;
;	genIpush
	push	ar5
;	genCast
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	@r0,ar2
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:228: delay_target=delay_target<<delay_base;
;	genLeftShift
	mov	b,r4
	inc	b
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	sjmp	00218$
00217$:
	mov	a,@r0
	add	a,acc
	mov	@r0,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	@r0,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	@r0,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	@r0,a
	dec	r0
	dec	r0
	dec	r0
00218$:
	djnz	b,00217$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:229: delay_target+=timer;
;	genPlus
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,_timer
	add	a,@r0
	mov	@r0,a
	mov	a,(_timer + 1)
	inc	r0
	addc	a,@r0
	mov	@r0,a
	mov	a,(_timer + 2)
	inc	r0
	addc	a,@r0
	mov	@r0,a
	mov	a,(_timer + 3)
	inc	r0
	addc	a,@r0
	mov	@r0,a
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:231: start_writecycle();
;	genCall
	push	ar3
	push	ar5
	push	ar6
	push	ar7
	lcall	_start_writecycle
	pop	ar7
	pop	ar6
	pop	ar5
	pop	ar3
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:232: write_byte(0x00,objno*5,objno+delay_status);
;	genPlus
;	Peephole 236.g	used r6 instead of ar6
	mov	a,r6
;	Peephole 236.a	used r7 instead of ar7
	add	a,r7
	mov	r2,a
;	genMult
;	genMultOneByte
	mov	a,r7
	mov	b,#0x05
	mul	ab
	mov	r4,a
;	genIpush
	push	ar3
	push	ar4
	push	ar5
	push	ar7
	push	ar2
;	genIpush
	push	ar4
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar7
	pop	ar5
	pop	ar4
	pop	ar3
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:233: write_byte(0x00,1+objno*5,delay_target>>24);
;	genGetByte
	mov	a,_bp
	add	a,#0x07
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
	mov	r0,a
	mov	ar2,@r0
;	genPlus
;     genPlusIncr
	mov	a,#0x01
;	Peephole 236.a	used r4 instead of ar4
	add	a,r4
	mov	r5,a
;	genIpush
	push	ar3
	push	ar4
	push	ar5
	push	ar7
	push	ar2
;	genIpush
	push	ar5
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar7
	pop	ar5
	pop	ar4
	pop	ar3
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:234: write_byte(0x00,2+objno*5,delay_target>>16);
;	genGetByte
	mov	a,_bp
	add	a,#0x07
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
	mov	r0,a
	mov	ar2,@r0
;	genPlus
;     genPlusIncr
	mov	a,#0x02
;	Peephole 236.a	used r4 instead of ar4
	add	a,r4
	mov	r5,a
;	genIpush
	push	ar3
	push	ar4
	push	ar5
	push	ar7
	push	ar2
;	genIpush
	push	ar5
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar7
	pop	ar5
	pop	ar4
	pop	ar3
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:235: write_byte(0x00,3+objno*5,delay_target>>8);
;	genGetByte
	mov	a,_bp
	add	a,#0x07
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
	mov	r0,a
	mov	ar2,@r0
;	genPlus
;     genPlusIncr
	mov	a,#0x03
;	Peephole 236.a	used r4 instead of ar4
	add	a,r4
	mov	r5,a
;	genIpush
	push	ar3
	push	ar4
	push	ar5
	push	ar7
	push	ar2
;	genIpush
	push	ar5
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar7
	pop	ar5
	pop	ar4
	pop	ar3
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:236: write_byte(0x00,4+objno*5,delay_target);
;	genCast
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	ar2,@r0
;	genPlus
;     genPlusIncr
	mov	a,r4
	add	a,#0x04
	mov	r4,a
;	genIpush
	push	ar3
	push	ar5
	push	ar7
	push	ar2
;	genIpush
	push	ar4
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar7
	pop	ar5
	pop	ar3
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:237: stop_writecycle();
;	genCall
	push	ar3
	push	ar5
	push	ar7
	lcall	_stop_writecycle
	pop	ar7
	pop	ar5
	pop	ar3
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:156: for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
;	genIpop
	pop	ar5
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:237: stop_writecycle();
00123$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:239: TH0=0;					// Port-Ausgabe
;	genAssign
	mov	_TH0,#0x00
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:240: P1_2=1;
;	genAssign
	setb	_P1_2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:241: P0=portbuffer;
;	genAssign
	mov	_P0,_portbuffer
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:242: start_writecycle();	
;	genCall
	push	ar3
	push	ar5
	push	ar7
	lcall	_start_writecycle
	pop	ar7
	pop	ar5
	pop	ar3
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:243: write_byte(0x00,0x29,portbuffer);
;	genIpush
	push	ar3
	push	ar5
	push	ar7
	push	_portbuffer
;	genIpush
	mov	a,#0x29
	push	acc
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar7
	pop	ar5
	pop	ar3
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:244: stop_writecycle();
;	genCall
	push	ar3
	push	ar5
	push	ar7
	lcall	_stop_writecycle
	pop	ar7
	pop	ar5
	pop	ar3
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:245: TR1=0;					
;	genAssign
	clr	_TCON_6
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:246: TF1=0;
;	genAssign
	clr	_TCON_7
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:247: TH1=0xA0;				// Relais zunächst mit vollem Strom einschalten...
;	genAssign
	mov	_TH1,#0xA0
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:248: TL1=0x00;				
;	genAssign
	mov	_TL1,#0x00
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:249: TR1=1;
;	genAssign
	setb	_TCON_6
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:250: while (!TF1);
00124$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00124$
;	Peephole 300	removed redundant label 00219$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:251: TR1=0;
;	genAssign
	clr	_TCON_6
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:252: TH0=DUTY;				// ...danach mit PWM halten (min5% von I nominal)
;	genAssign
	mov	_TH0,#0xC0
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:254: objno+=12;				// Rückmeldeobjekt verarbeiten
;	genPlus
;     genPlusIncr
	mov	a,#0x0C
;	Peephole 236.a	used r7 instead of ar7
	add	a,r7
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:255: objflags=read_objflags(objno);
;	genCall
	mov	r7,a
;	Peephole 244.c	loading dpl from a instead of r7
	mov	dpl,a
	push	ar3
	push	ar5
	push	ar7
	lcall	_read_objflags
	mov	r2,dpl
	pop	ar7
	pop	ar5
	pop	ar3
;	genAssign
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,ar2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:256: if ((objflags & 0x04) == 0x04)
;	genAnd
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,#0x04
	anl	a,@r0
	mov	r2,a
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r2,#0x04,00134$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00220$
;	Peephole 300	removed redundant label 00221$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:258: ga=find_ga(objno);
;	genCall
	mov	dpl,r7
	push	ar3
	push	ar5
	lcall	_find_ga
	mov	r2,dpl
	mov	r4,dph
	pop	ar5
	pop	ar3
;	genAssign
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:259: if (ga!=0)
;	genCmpEq
;	gencjneshort
	cjne	r2,#0x00,00222$
	cjne	r4,#0x00,00222$
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00134$
00222$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:261: telegramm[0]=0xBC;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,#0xBC
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:262: telegramm[1]=pah;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0001),_pah
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:263: telegramm[2]=pal;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0002),_pal
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:264: telegramm[3]=(ga>>8);
;	genGetByte
	mov	ar6,r4
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0003),r6
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:265: telegramm[4]=ga;
;	genCast
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0004),r2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:266: telegramm[5]=0xE1;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0005),#0xE1
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:267: telegramm[6]=0x00;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),#0x00
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:268: send_telegramm();
;	genCall
	push	ar3
	push	ar5
	lcall	_send_telegramm
	pop	ar5
	pop	ar3
00134$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:273: if(telegramm[7]==0x00 && (objflags&0x08)==0x08)	// Wert lesen, nur wenn read enable gesetzt (Bit3)
;	genPointerGet
;	genNearPointerGet
;	genDataPointerGet
	mov	a,(_telegramm + 0x0007)
;	genIfx
;	genIfxJump
;	Peephole 108.b	removed ljmp by inverse jump logic
	jnz	00149$
;	Peephole 300	removed redundant label 00223$
;	genAnd
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,#0x08
	anl	a,@r0
	mov	r2,a
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r2,#0x08,00149$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00224$
;	Peephole 300	removed redundant label 00225$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:275: telegramm[0]=0xBC;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	_telegramm,#0xBC
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:276: telegramm[1]=pah;			// Source Adresse
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0001),_pah
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:277: telegramm[2]=pal;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0002),_pal
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:278: telegramm[5]=0xE1;		// DRL
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0005),#0xE1
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:279: telegramm[6]=0x00;
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0006),#0x00
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:280: if((port_pattern&portbuffer)>0) telegramm[7]=0x41;	// An
;	genAnd
	mov	r0,_bp
	inc	r0
	mov	a,_portbuffer
	anl	a,@r0
;	genIfx
;	genIfxJump
;	Peephole 108.c	removed ljmp by inverse jump logic
	jz	00136$
;	Peephole 300	removed redundant label 00226$
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),#0x41
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00137$
00136$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:281: else telegramm[7]=0x40;					// Aus
;	genPointerSet
;	genNearPointerSet
;	genDataPointerSet
	mov	(_telegramm + 0x0007),#0x40
00137$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:282: send_telegramm();
;	genCall
	push	ar3
	push	ar5
	lcall	_send_telegramm
	pop	ar5
	pop	ar3
00149$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:156: for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
;	genPlus
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
;     genPlusIncr
	inc	@r0
	ljmp	00147$
00151$:
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay_timer'
;------------------------------------------------------------
;n                         Allocated to stack - offset 1
;b                         Allocated to registers r4 
;port_pattern              Allocated to registers r2 
;delay_zeit                Allocated to registers r5 
;delay_onoff               Allocated to registers r7 
;delay_base                Allocated to registers r3 
;delval                    Allocated to stack - offset 2
;delay_target              Allocated to stack - offset 6
;sloc0                     Allocated to stack - offset 10
;------------------------------------------------------------
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:296: void delay_timer(void)	// zählt alle 130ms die Variable Timer hoch und prüft Queue
;	-----------------------------------------
;	 function delay_timer
;	-----------------------------------------
_delay_timer:
	push	_bp
;	peephole 177.h	optimized mov sequence
	mov	a,sp
	mov	_bp,a
	add	a,#0x0d
	mov	sp,a
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:301: RTCCON=0x60;		// RTC anhalten und Flag löschen
;	genAssign
	mov	_RTCCON,#0x60
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:302: RTCH=0x1D;		// Real Time Clock
;	genAssign
	mov	_RTCH,#0x1D
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:303: RTCL=0x40;
;	genAssign
	mov	_RTCL,#0x40
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:305: timer++;
;	genPlus
;     genPlusIncr
	inc	_timer
	clr	a
	cjne	a,_timer,00145$
	inc	(_timer + 1)
	cjne	a,(_timer + 1),00145$
	inc	(_timer + 2)
	cjne	a,(_timer + 2),00145$
	inc	(_timer + 3)
00145$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:306: for(n=0;n<=7;n++)
;	genAssign
	mov	r0,_bp
	inc	r0
	mov	@r0,#0x00
00125$:
;	genCmpGt
	mov	r0,_bp
	inc	r0
;	genCmp
;	genIfxJump
;	Peephole 132.b	optimized genCmpGt by inverse logic (acc differs)
	mov	a,@r0
	add	a,#0xff - 0x07
	jnc	00146$
	ljmp	00128$
00146$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:308: b=read_byte(0x00,n*5);
;	genMult
	mov	r0,_bp
	inc	r0
;	genMultOneByte
	mov	a,@r0
	mov	b,#0x05
	mul	ab
	mov	r3,a
;	genIpush
	push	ar3
	push	ar3
;	genCall
	mov	dpl,#0x00
	lcall	_read_byte
	mov	r4,dpl
	dec	sp
	pop	ar3
;	genAssign
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:309: if(b!=0x00)							// 0x00 = queue Eintrag ist leer
;	genCmpEq
;	gencjneshort
	cjne	r4,#0x00,00147$
	ljmp	00127$
00147$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:311: delval=read_byte(0x00,n*5+1);
;	genIpush
	push	ar4
;	genPlus
;     genPlusIncr
	mov	a,#0x01
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r5,a
;	genIpush
	push	ar3
	push	ar4
	push	ar5
;	genCall
	mov	dpl,#0x00
	lcall	_read_byte
	mov	r5,dpl
	dec	sp
	pop	ar4
	pop	ar3
;	genCast
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:312: delval=(delval<<8)+read_byte(0x00,n*5+2);
;	genLeftShift
;	genLeftShiftLiteral
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,_bp
	add	a,#0x0a
	mov	r1,a
;	genlshFour
	inc	r0
	inc	r0
	mov	a,@r0
	inc	r1
	inc	r1
	inc	r1
	mov	@r1,a
	dec	r0
	mov	a,@r0
	dec	r1
	mov	@r1,a
	dec	r0
	mov	a,@r0
	dec	r1
	mov	@r1,a
	dec	r1
	mov	@r1,#0x00
;	genPlus
;     genPlusIncr
	mov	a,#0x02
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r2,a
;	genIpush
	push	ar3
	push	ar4
	push	ar2
;	genCall
	mov	dpl,#0x00
	lcall	_read_byte
	mov	r2,dpl
	dec	sp
	pop	ar4
	pop	ar3
;	genCast
;	genCast
;	peephole 177.g	optimized mov sequence
;	Peephole 181	changed mov to clr
	clr	a
	mov	r4,a
	rlc	a
	subb	a,acc
	mov	r5,a
	mov	r6,a
;	genPlus
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
;	Peephole 236.g	used r2 instead of ar2
	mov	a,r2
	add	a,@r0
	mov	r2,a
;	Peephole 236.g	used r4 instead of ar4
	mov	a,r4
	inc	r0
	addc	a,@r0
	mov	r4,a
;	Peephole 236.g	used r5 instead of ar5
	mov	a,r5
	inc	r0
	addc	a,@r0
	mov	r5,a
;	Peephole 236.g	used r6 instead of ar6
	mov	a,r6
	inc	r0
	addc	a,@r0
	mov	r6,a
;	genAssign
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar6
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:313: delval=(delval<<8)+read_byte(0x00,n*5+3);
;	genLeftShift
;	genLeftShiftLiteral
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,_bp
	add	a,#0x0a
	mov	r1,a
;	genlshFour
	inc	r0
	inc	r0
	mov	a,@r0
	inc	r1
	inc	r1
	inc	r1
	mov	@r1,a
	dec	r0
	mov	a,@r0
	dec	r1
	mov	@r1,a
	dec	r0
	mov	a,@r0
	dec	r1
	mov	@r1,a
	dec	r1
	mov	@r1,#0x00
;	genPlus
;     genPlusIncr
	mov	a,#0x03
;	Peephole 236.a	used r3 instead of ar3
	add	a,r3
	mov	r7,a
;	genIpush
	push	ar3
	push	ar4
	push	ar7
;	genCall
	mov	dpl,#0x00
	lcall	_read_byte
	mov	r7,dpl
	dec	sp
	pop	ar4
	pop	ar3
;	genCast
;	genCast
;	peephole 177.g	optimized mov sequence
;	Peephole 181	changed mov to clr
	clr	a
	mov	r2,a
	rlc	a
	subb	a,acc
	mov	r4,a
	mov	r5,a
;	genPlus
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
;	Peephole 236.g	used r7 instead of ar7
	mov	a,r7
	add	a,@r0
	mov	r7,a
;	Peephole 236.g	used r2 instead of ar2
	mov	a,r2
	inc	r0
	addc	a,@r0
	mov	r2,a
;	Peephole 236.g	used r4 instead of ar4
	mov	a,r4
	inc	r0
	addc	a,@r0
	mov	r4,a
;	Peephole 236.g	used r5 instead of ar5
	mov	a,r5
	inc	r0
	addc	a,@r0
	mov	r5,a
;	genAssign
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,ar7
	inc	r0
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:314: delval=(delval<<8)+read_byte(0x00,n*5+4);
;	genLeftShift
;	genLeftShiftLiteral
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,_bp
	add	a,#0x0a
	mov	r1,a
;	genlshFour
	inc	r0
	inc	r0
	mov	a,@r0
	inc	r1
	inc	r1
	inc	r1
	mov	@r1,a
	dec	r0
	mov	a,@r0
	dec	r1
	mov	@r1,a
	dec	r0
	mov	a,@r0
	dec	r1
	mov	@r1,a
	dec	r1
	mov	@r1,#0x00
;	genPlus
;     genPlusIncr
	mov	a,r3
	add	a,#0x04
	mov	r3,a
;	genIpush
	push	ar4
	push	ar3
;	genCall
	mov	dpl,#0x00
	lcall	_read_byte
	mov	r3,dpl
	dec	sp
	pop	ar4
;	genCast
;	genCast
;	peephole 177.g	optimized mov sequence
;	Peephole 181	changed mov to clr
	clr	a
	mov	r7,a
	rlc	a
	subb	a,acc
	mov	r2,a
	mov	r4,a
;	genPlus
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
;	Peephole 236.g	used r3 instead of ar3
	mov	a,r3
	add	a,@r0
	mov	r3,a
;	Peephole 236.g	used r7 instead of ar7
	mov	a,r7
	inc	r0
	addc	a,@r0
	mov	r7,a
;	Peephole 236.g	used r2 instead of ar2
	mov	a,r2
	inc	r0
	addc	a,@r0
	mov	r2,a
;	Peephole 236.g	used r4 instead of ar4
	mov	a,r4
	inc	r0
	addc	a,@r0
	mov	r4,a
;	genAssign
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar7
	inc	r0
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar4
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:315: if(delval==timer)
;	genCmpEq
	mov	r0,_bp
	inc	r0
	inc	r0
;	gencjne
;	gencjneshort
	mov	a,@r0
	cjne	a,_timer,00148$
	inc	r0
	mov	a,@r0
	cjne	a,(_timer + 1),00148$
	inc	r0
	mov	a,@r0
	cjne	a,(_timer + 2),00148$
	inc	r0
	mov	a,@r0
	cjne	a,(_timer + 3),00148$
	mov	a,#0x01
	sjmp	00149$
00148$:
	clr	a
00149$:
;	genIpop
	pop	ar4
;	genIfx
;	genIfxJump
	jnz	00150$
	ljmp	00127$
00150$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:317: port_pattern=0x01<<((b&0x0F));
;	genAnd
	mov	a,#0x0F
	anl	a,r4
	mov	r2,a
;	genLeftShift
	mov	b,r2
	inc	b
	mov	a,#0x01
	sjmp	00153$
00151$:
	add	a,acc
00153$:
	djnz	b,00151$
	mov	r2,a
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:318: if((b&0xF0)==0x90)
;	genAnd
	mov	a,#0xF0
	anl	a,r4
	mov	r3,a
;	genCmpEq
;	gencjneshort
	cjne	r3,#0x90,00154$
	sjmp	00155$
00154$:
	ljmp	00116$
00155$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:320: if (((read_byte(0x01,RELMODE)>>(b&0x0F))&0x01)==0x00)
;	genIpush
	push	ar2
	push	ar4
	mov	a,#0xF2
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r3,dpl
	dec	sp
	pop	ar4
	pop	ar2
;	genAnd
	mov	a,#0x0F
	anl	a,r4
;	genRightShift
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
	mov	b,a
	mov	a,r3
	sjmp	00157$
00156$:
	clr	c
	rrc	a
00157$:
	djnz	b,00156$
;	genAnd
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	acc.0,00102$
;	Peephole 300	removed redundant label 00158$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:322: portbuffer=portbuffer|port_pattern;		// Einschalten (Schliesserbetrieb)
;	genOr
	mov	a,r2
	orl	_portbuffer,a
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00103$
00102$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:326: portbuffer=portbuffer&~port_pattern;	// Einschalten (Öffnerbetrieb)
;	genCpl
	mov	a,r2
	cpl	a
;	genAnd
	mov	r3,a
;	Peephole 105	removed redundant mov
	anl	_portbuffer,a
00103$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:328: start_writecycle();
;	genCall
	lcall	_start_writecycle
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:329: write_byte(0x00,n*5,0x00);
;	genMult
	mov	r0,_bp
	inc	r0
;	genMultOneByte
	mov	a,@r0
	mov	b,#0x05
	mul	ab
	mov	r2,a
;	genIpush
	push	ar2
;	Peephole 181	changed mov to clr
	clr	a
	push	acc
;	genIpush
	push	ar2
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:330: stop_writecycle();
;	genCall
	push	ar2
	lcall	_stop_writecycle
	pop	ar2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:331: delay_zeit=read_byte(0x01,0xEA);
;	genIpush
	push	ar2
	mov	a,#0xEA
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r5,dpl
	dec	sp
	pop	ar2
;	genAssign
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:332: delay_zeit=((delay_zeit>>n)&0x01);
;	genRightShift
	mov	r0,_bp
	inc	r0
	mov	b,@r0
	inc	b
	mov	a,r5
	sjmp	00160$
00159$:
	clr	c
	rrc	a
00160$:
	djnz	b,00159$
	mov	r6,a
;	genAnd
	mov	a,#0x01
	anl	a,r6
	mov	r5,a
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:333: if(delay_zeit==0x01)
;	genCmpEq
;	gencjneshort
	cjne	r5,#0x01,00161$
	sjmp	00162$
00161$:
	ljmp	00117$
00162$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:335: delay_base=read_byte(0x01,(((n+1)>>1)+0xF9));   
;	genCast
	mov	r0,_bp
	inc	r0
	mov	ar6,@r0
	mov	r7,#0x00
;	genPlus
;     genPlusIncr
	inc	r6
	cjne	r6,#0x00,00163$
	inc	r7
00163$:
;	genRightShift
;	genSignedRightShift
;	genRightShiftLiteral
;	genrshTwo
	mov	a,r7
	mov	c,acc.7
	rrc	a
	xch	a,r6
	rrc	a
	xch	a,r6
	mov	r7,a
;	genCast
;	genPlus
;     genPlusIncr
	mov	a,#0xF9
;	Peephole 236.a	used r6 instead of ar6
	add	a,r6
	mov	r6,a
;	genIpush
	push	ar2
	push	ar5
	push	ar6
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r6,dpl
	dec	sp
	pop	ar5
	pop	ar2
;	genAssign
	mov	ar3,r6
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:336: if((n&0x01)==0x01) delay_base&=0x0F;
;	genAnd
	mov	r0,_bp
	inc	r0
	mov	a,#0x01
	anl	a,@r0
	mov	r7,a
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r7,#0x01,00105$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00164$
;	Peephole 300	removed redundant label 00165$
;	genAnd
	anl	ar3,#0x0F
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00106$
00105$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:337: else delay_base=(delay_base&0xF0)>>4;
;	genAnd
	mov	a,#0xF0
	anl	a,r3
;	genRightShift
;	genRightShiftLiteral
;	genrshOne
	mov	r7,a
;	Peephole 105	removed redundant mov
	swap	a
	anl	a,#0x0f
	mov	r3,a
00106$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:338: delay_onoff=read_byte(0x01,(n+0xE2));
;	genPlus
	mov	r0,_bp
	inc	r0
;     genPlusIncr
	mov	a,#0xE2
	add	a,@r0
	mov	r7,a
;	genIpush
	push	ar2
	push	ar3
	push	ar5
	push	ar7
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r7,dpl
	dec	sp
	pop	ar5
	pop	ar3
	pop	ar2
;	genAssign
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:339: if (delay_onoff!=0x00 && delay_zeit!=0x00)
;	genCmpEq
;	gencjneshort
	cjne	r7,#0x00,00166$
	ljmp	00117$
00166$:
;	genCmpEq
;	gencjneshort
	cjne	r5,#0x00,00167$
	ljmp	00117$
00167$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:341: delay_target=delay_onoff;
;	genCast
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	@r0,ar7
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:342: delay_target=delay_target<<delay_base;
;	genLeftShift
	mov	b,r3
	inc	b
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	sjmp	00169$
00168$:
	mov	a,@r0
	add	a,acc
	mov	@r0,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	@r0,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	@r0,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	@r0,a
	dec	r0
	dec	r0
	dec	r0
00169$:
	djnz	b,00168$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:343: delay_target+=timer;  
;	genPlus
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,_timer
	add	a,@r0
	mov	@r0,a
	mov	a,(_timer + 1)
	inc	r0
	addc	a,@r0
	mov	@r0,a
	mov	a,(_timer + 2)
	inc	r0
	addc	a,@r0
	mov	@r0,a
	mov	a,(_timer + 3)
	inc	r0
	addc	a,@r0
	mov	@r0,a
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:344: start_writecycle();   
;	genCall
	push	ar2
	lcall	_start_writecycle
	pop	ar2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:345: write_byte(0x00,n*5,n+0x80);
;	genPlus
	mov	r0,_bp
	inc	r0
;     genPlusIncr
	mov	a,#0x80
	add	a,@r0
	mov	r3,a
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
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:346: write_byte(0x00,1+n*5,delay_target>>24);
;	genGetByte
	mov	a,_bp
	add	a,#0x06
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
	mov	r5,a
;	genIpush
	push	ar2
	push	ar3
;	genIpush
	push	ar5
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:347: write_byte(0x00,2+n*5,delay_target>>16);
;	genGetByte
	mov	a,_bp
	add	a,#0x06
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
	mov	r5,a
;	genIpush
	push	ar2
	push	ar3
;	genIpush
	push	ar5
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:348: write_byte(0x00,3+n*5,delay_target>>8);
;	genGetByte
	mov	a,_bp
	add	a,#0x06
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
	mov	r0,a
	mov	ar3,@r0
;	genPlus
;     genPlusIncr
	mov	a,#0x03
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	r5,a
;	genIpush
	push	ar2
	push	ar3
;	genIpush
	push	ar5
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
	pop	ar2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:349: write_byte(0x00,4+n*5,delay_target);
;	genCast
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	ar7,@r0
;	genPlus
;     genPlusIncr
	mov	a,#0x04
;	Peephole 236.a	used r2 instead of ar2
	add	a,r2
	mov	r3,a
;	genIpush
	push	ar7
;	genIpush
	push	ar3
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:350: stop_writecycle();
;	genCall
	lcall	_stop_writecycle
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00117$
00116$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:356: if (((read_byte(0x01,RELMODE)>>(b&0x0F))&0x01)==0x00)
;	genIpush
	push	ar2
	push	ar4
	mov	a,#0xF2
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r3,dpl
	dec	sp
	pop	ar4
	pop	ar2
;	genAnd
	mov	a,#0x0F
	anl	a,r4
;	genRightShift
;	Peephole 185	changed order of increment (acc incremented also!)
	inc	a
	mov	b,a
	mov	a,r3
	sjmp	00171$
00170$:
	clr	c
	rrc	a
00171$:
	djnz	b,00170$
;	genAnd
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	acc.0,00113$
;	Peephole 300	removed redundant label 00172$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:358: portbuffer=portbuffer&~port_pattern;		// Ausschalten (Schliesserbetrieb)
;	genCpl
	mov	a,r2
	cpl	a
;	genAnd
	mov	r3,a
;	Peephole 105	removed redundant mov
	anl	_portbuffer,a
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00114$
00113$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:362: portbuffer=portbuffer|port_pattern;			// Ausschalten (Öffnerbetrieb)
;	genOr
	mov	a,r2
	orl	_portbuffer,a
00114$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:364: start_writecycle();
;	genCall
	lcall	_start_writecycle
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:365: write_byte(0x00,n*5,0x00);
;	genMult
	mov	r0,_bp
	inc	r0
;	genMultOneByte
	mov	a,@r0
	mov	b,#0x05
	mul	ab
	mov	r2,a
;	genIpush
;	Peephole 181	changed mov to clr
	clr	a
	push	acc
;	genIpush
	push	ar2
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:366: stop_writecycle();
;	genCall
	lcall	_stop_writecycle
00117$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:368: TH0=0;					// Port-Ausgabe
;	genAssign
	mov	_TH0,#0x00
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:369: P1_2=1;
;	genAssign
	setb	_P1_2
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:370: P0=portbuffer;	
;	genAssign
	mov	_P0,_portbuffer
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:371: start_writecycle();
;	genCall
	lcall	_start_writecycle
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:372: write_byte(0x00,0x29,portbuffer);
;	genIpush
	push	_portbuffer
;	genIpush
	mov	a,#0x29
	push	acc
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:373: stop_writecycle();
;	genCall
	lcall	_stop_writecycle
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:374: TR1=0;					
;	genAssign
	clr	_TCON_6
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:375: TF1=0;
;	genAssign
	clr	_TCON_7
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:376: TH1=0xA0;				// Relais zunächst mit vollem Strom einschalten...
;	genAssign
	mov	_TH1,#0xA0
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:377: TL1=0x00;				
;	genAssign
	mov	_TL1,#0x00
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:378: TR1=1;
;	genAssign
	setb	_TCON_6
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:379: while (!TF1);
00118$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_TCON_7,00118$
;	Peephole 300	removed redundant label 00173$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:380: TR1=0;
;	genAssign
	clr	_TCON_6
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:381: TH0=DUTY;				// ...danach mit PWM halten (min5% von I nominal)    
;	genAssign
	mov	_TH0,#0xC0
00127$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:306: for(n=0;n<=7;n++)
;	genPlus
	mov	r0,_bp
	inc	r0
;     genPlusIncr
	inc	@r0
	ljmp	00125$
00128$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:387: RTCCON=0x61;		// RTC starten
;	genAssign
	mov	_RTCCON,#0x61
;	Peephole 300	removed redundant label 00129$
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'restart_app'
;------------------------------------------------------------
;bw                        Allocated to registers r2 
;bwh                       Allocated to registers r4 
;n                         Allocated to registers r3 
;------------------------------------------------------------
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:391: void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
;	-----------------------------------------
;	 function restart_app
;	-----------------------------------------
_restart_app:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:396: portbuffer=read_byte(0x00,0x29);	// Verhalten nach Busspannungs-Wiederkehr
;	genIpush
	mov	a,#0x29
	push	acc
;	genCall
	mov	dpl,#0x00
	lcall	_read_byte
	mov	_portbuffer,dpl
	dec	sp
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:397: bw=read_byte(0x01,0xF6);
;	genIpush
	mov	a,#0xF6
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r2,dpl
	dec	sp
;	genAssign
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:398: for(n=0;n<=3;n++)			// Ausgänge 1-4
;	genAssign
	mov	r3,#0x00
00109$:
;	genCmpGt
;	genCmp
;	genIfxJump
;	Peephole 132.b	optimized genCmpGt by inverse logic (acc differs)
	mov	a,r3
	add	a,#0xff - 0x03
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 160.a	removed sjmp by inverse jump logic
	jc	00112$
;	Peephole 300	removed redundant label 00129$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:400: bwh=(bw>>(2*n))&0x03; 
;	genMult
;	genMultOneByte
	mov	a,r3
	mov	b,#0x02
	mul	ab
	mov	r4,a
	mov	r5,b
;	genRightShift
	mov	b,r4
	inc	b
	mov	a,r2
	sjmp	00131$
00130$:
	clr	c
	rrc	a
00131$:
	djnz	b,00130$
	mov	r4,a
;	genAnd
	anl	ar4,#0x03
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:401: if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<n));
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r4,#0x01,00102$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00132$
;	Peephole 300	removed redundant label 00133$
;	genLeftShift
	mov	b,r3
	inc	b
	mov	a,#0x01
	sjmp	00136$
00134$:
	add	a,acc
00136$:
	djnz	b,00134$
	mov	r5,a
;	genMinus
	mov	a,#0xFF
	clr	c
;	Peephole 236.l	used r5 instead of ar5
	subb	a,r5
;	genAnd
	anl	_portbuffer,a
00102$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:402: if(bwh==0x02)  portbuffer=portbuffer | (0x01<<n);
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r4,#0x02,00111$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00137$
;	Peephole 300	removed redundant label 00138$
;	genLeftShift
	mov	b,r3
	inc	b
	mov	a,#0x01
	sjmp	00141$
00139$:
	add	a,acc
00141$:
	djnz	b,00139$
;	genOr
	mov	r5,a
;	Peephole 105	removed redundant mov
	orl	_portbuffer,a
00111$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:398: for(n=0;n<=3;n++)			// Ausgänge 1-4
;	genPlus
;     genPlusIncr
	inc	r3
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00109$
00112$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:404: bw=read_byte(0x01,0xF7);
;	genIpush
	mov	a,#0xF7
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_read_byte
	mov	r3,dpl
	dec	sp
;	genAssign
	mov	ar2,r3
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:405: for(n=0;n<=3;n++)			// Ausgänge 5-8
;	genAssign
	mov	r3,#0x00
00113$:
;	genCmpGt
;	genCmp
;	genIfxJump
;	Peephole 132.b	optimized genCmpGt by inverse logic (acc differs)
	mov	a,r3
	add	a,#0xff - 0x03
	jnc	00142$
	ljmp	00116$
00142$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:407: bwh=(bw>>(2*n))&0x03; 
;	genMult
;	genMultOneByte
	mov	a,r3
	mov	b,#0x02
	mul	ab
	mov	r5,a
	mov	r6,b
;	genRightShift
	mov	b,r5
	inc	b
	mov	a,r2
	sjmp	00144$
00143$:
	clr	c
	rrc	a
00144$:
	djnz	b,00143$
	mov	r5,a
;	genAnd
	mov	a,#0x03
	anl	a,r5
	mov	r4,a
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:408: if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<(n+4)));
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r4,#0x01,00106$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00145$
;	Peephole 300	removed redundant label 00146$
;	genCast
	mov	ar5,r3
	mov	r6,#0x00
;	genPlus
;     genPlusIncr
	mov	a,#0x04
;	Peephole 236.a	used r5 instead of ar5
	add	a,r5
	mov	r5,a
;	Peephole 181	changed mov to clr
	clr	a
;	Peephole 236.b	used r6 instead of ar6
	addc	a,r6
	mov	r6,a
;	genLeftShift
	mov	b,r5
	inc	b
	mov	r5,#0x01
	mov	r6,#0x00
	sjmp	00148$
00147$:
	mov	a,r5
;	Peephole 254	optimized left shift
	add	a,r5
	mov	r5,a
	mov	a,r6
	rlc	a
	mov	r6,a
00148$:
	djnz	b,00147$
;	genMinus
	mov	a,#0xFF
	clr	c
;	Peephole 236.l	used r5 instead of ar5
	subb	a,r5
	mov	r5,a
;	Peephole 181	changed mov to clr
	clr	a
;	Peephole 236.l	used r6 instead of ar6
	subb	a,r6
	mov	r6,a
;	genCast
;	genAnd
	mov	a,r5
	anl	_portbuffer,a
00106$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:409: if(bwh==0x02)  portbuffer=portbuffer | (0x01<<(n+4));
;	genCmpEq
;	gencjneshort
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 198.b	optimized misc jump sequence
	cjne	r4,#0x02,00115$
;	Peephole 200.b	removed redundant sjmp
;	Peephole 300	removed redundant label 00149$
;	Peephole 300	removed redundant label 00150$
;	genCast
	mov	ar4,r3
	mov	r5,#0x00
;	genPlus
;     genPlusIncr
	mov	a,#0x04
;	Peephole 236.a	used r4 instead of ar4
	add	a,r4
	mov	r4,a
;	Peephole 181	changed mov to clr
	clr	a
;	Peephole 236.b	used r5 instead of ar5
	addc	a,r5
	mov	r5,a
;	genLeftShift
	mov	b,r4
	inc	b
	mov	r4,#0x01
	mov	r5,#0x00
	sjmp	00152$
00151$:
	mov	a,r4
;	Peephole 254	optimized left shift
	add	a,r4
	mov	r4,a
	mov	a,r5
	rlc	a
	mov	r5,a
00152$:
	djnz	b,00151$
;	genCast
;	genOr
	mov	a,r4
	orl	_portbuffer,a
00115$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:405: for(n=0;n<=3;n++)			// Ausgänge 5-8
;	genPlus
;     genPlusIncr
	inc	r3
	ljmp	00113$
00116$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:411: P0=portbuffer;
;	genAssign
	mov	_P0,_portbuffer
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:412: objstate=portbuffer<<8;
;	genCast
	mov	r2,_portbuffer
	mov	r3,#0x00
;	genLeftShift
;	genLeftShiftLiteral
;	genlshTwo
	mov	(_objstate + 1),r2
	mov	_objstate,#0x00
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:413: objstate+=portbuffer;
;	genPlus
;	Peephole 236.g	used r2 instead of ar2
	mov	a,r2
	add	a,_objstate
	mov	_objstate,a
;	Peephole 236.g	used r3 instead of ar3
	mov	a,r3
	addc	a,(_objstate + 1)
	mov	(_objstate + 1),a
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:414: start_writecycle();
;	genCall
	lcall	_start_writecycle
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:415: write_byte(0x00,0x29,portbuffer);
;	genIpush
	push	_portbuffer
;	genIpush
	mov	a,#0x29
	push	acc
;	genCall
	mov	dpl,#0x00
	lcall	_write_byte
	dec	sp
	dec	sp
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:416: stop_writecycle();
;	genCall
	lcall	_stop_writecycle
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:418: pdir=0xFF;		// Port-Direction - wenn Bit=1 darf entsprechender Portpin beschrieben werden (Ausgang), sonst nicht (Eingang)
;	genAssign
	mov	_pdir,#0xFF
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:420: timer=0;		// Timer-Variable, wird alle 135us inkrementiert
;	genAssign
	clr	a
	mov	_timer,a
	mov	(_timer + 1),a
	mov	(_timer + 2),a
	mov	(_timer + 3),a
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:422: start_writecycle();
;	genCall
	lcall	_start_writecycle
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:423: write_byte(0x01,0x04,0x04);	// Herstellercode 0x04 = Jung
;	genIpush
	mov	a,#0x04
	push	acc
;	genIpush
	mov	a,#0x04
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_write_byte
	dec	sp
	dec	sp
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:424: write_byte(0x01,0x05,0x70);	// Geräte Typ (2118) 7054h
;	genIpush
	mov	a,#0x70
	push	acc
;	genIpush
	mov	a,#0x05
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_write_byte
	dec	sp
	dec	sp
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:425: write_byte(0x01,0x06,0x54);  // 	"	"	"
;	genIpush
	mov	a,#0x54
	push	acc
;	genIpush
	mov	a,#0x06
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_write_byte
	dec	sp
	dec	sp
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:426: write_byte(0x01,0x07,0x02);	// Versionsnummer
;	genIpush
	mov	a,#0x02
	push	acc
;	genIpush
	mov	a,#0x07
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_write_byte
	dec	sp
	dec	sp
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:427: write_byte(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
;	genIpush
	mov	a,#0xFF
	push	acc
;	genIpush
	mov	a,#0x0D
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_write_byte
	dec	sp
	dec	sp
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:428: write_byte(0x01,0x12,0x84);	// COMMSTAB Pointer
;	genIpush
	mov	a,#0x84
	push	acc
;	genIpush
	mov	a,#0x12
	push	acc
;	genCall
	mov	dpl,#0x01
	lcall	_write_byte
	dec	sp
	dec	sp
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:429: stop_writecycle();
;	genCall
;	Peephole 253.b	replaced lcall/ret with ljmp
	ljmp	_stop_writecycle
;
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;n                         Allocated to registers r2 
;------------------------------------------------------------
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:16: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:21: restart_hw();				// Hardware zurücksetzen
;	genCall
	lcall	_restart_hw
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:22: restart_prot();			// Protokoll-relevante Parameter zurücksetzen
;	genCall
	lcall	_restart_prot
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:23: restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
;	genCall
	lcall	_restart_app
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:24: portbuffer=0xFF;
;	genAssign
	mov	_portbuffer,#0xFF
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:26: do  {
00112$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:28: if(RTCCON>=0x80) delay_timer();	// Verzögerungs-Timer alle 130ms hochzählen
;	genCmpLt
;	genCmp
;	genIfxJump
;	Peephole 132.e	optimized genCmpLt by inverse logic (carry differs)
	mov	a,#0x100 - 0x80
	add	a,_RTCCON
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 160.b	removed sjmp by inverse jump logic
	jnc	00102$
;	Peephole 300	removed redundant label 00143$
;	genCall
	lcall	_delay_timer
00102$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:30: p0h=P0;				// prüfen ob ein Eingang sich geändert hat
;	genAssign
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:31: if (p0h!=portbuffer) 
;	genCmpEq
;	gencjneshort
;	peephole 177.g	optimized mov sequence
	mov	a,_P0
	mov	_p0h,a
	cjne	a,_portbuffer,00144$
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00106$
00144$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:33: for(n=0;n<8;n++)					// jeden Eingangspin einzel prüfen
;	genAssign
	mov	r2,#0x00
00115$:
;	genCmpLt
;	genCmp
	cjne	r2,#0x08,00145$
00145$:
;	genIfxJump
;	Peephole 108.a	removed ljmp by inverse jump logic
	jnc	00118$
;	Peephole 300	removed redundant label 00146$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:35: if (((p0h>>n)&0x01) != ((portbuffer>>n)&0x01))
;	genRightShift
	mov	b,r2
	inc	b
	mov	a,_p0h
	sjmp	00148$
00147$:
	clr	c
	rrc	a
00148$:
	djnz	b,00147$
;	genAnd
	anl	a,#0x01
	mov	r3,a
;	genRightShift
	mov	b,r2
	inc	b
	mov	a,_portbuffer
	sjmp	00150$
00149$:
	clr	c
	rrc	a
00150$:
	djnz	b,00149$
;	genAnd
	anl	a,#0x01
	mov	r4,a
;	genCmpEq
;	gencjneshort
	mov	a,r3
	cjne	a,ar4,00151$
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00117$
00151$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:37: pin_changed(n);				// Änderung verarbeiten
;	genCall
	mov	dpl,r2
	push	ar2
	lcall	_pin_changed
	pop	ar2
00117$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:33: for(n=0;n<8;n++)					// jeden Eingangspin einzel prüfen
;	genPlus
;     genPlusIncr
	inc	r2
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00115$
00118$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:40: portbuffer=p0h;					// neuen Portzustand in buffer speichern
;	genAssign
	mov	_portbuffer,_p0h
00106$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:43: TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
;	genAssign
	setb	_P1_7
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:44: if(!TASTER) {				// Taster gedrückt
;	genIfx
;	genIfxJump
;	Peephole 108.e	removed ljmp by inverse jump logic
	jb	_P1_7,00111$
;	Peephole 300	removed redundant label 00152$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:45: for(n=0;n<100;n++) {}
;	genAssign
	mov	r2,#0x64
00121$:
;	genDjnz
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 205	optimized misc jump sequence
	djnz	r2,00121$
;	Peephole 300	removed redundant label 00153$
;	Peephole 300	removed redundant label 00154$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:46: while(!TASTER);
00107$:
;	genIfx
;	genIfxJump
;	Peephole 108.d	removed ljmp by inverse jump logic
	jnb	_P1_7,00107$
;	Peephole 300	removed redundant label 00155$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:47: progmode=!progmode;
;	genNot
	cpl	_progmode
00111$:
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:49: TASTER=!progmode;				// LED entsprechend schalten (low=LED an)
;	genNot
	mov	c,_progmode
	cpl	c
	mov	_P1_7,c
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:50: for(n=0;n<100;n++) {}
;	genAssign
	mov	r2,#0x64
00124$:
;	genDjnz
;	Peephole 112.b	changed ljmp to sjmp
;	Peephole 205	optimized misc jump sequence
	djnz	r2,00124$
;	Peephole 300	removed redundant label 00156$
;	Peephole 300	removed redundant label 00157$
;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:51: } while(1);
;	Peephole 112.b	changed ljmp to sjmp
	sjmp	00112$
;	Peephole 259.a	removed redundant label 00125$ and ret
;
	.area CSEG    (CODE)
	.area CONST   (CODE)
_dataflash	=	0x1c00
	.area XINIT   (CODE)
