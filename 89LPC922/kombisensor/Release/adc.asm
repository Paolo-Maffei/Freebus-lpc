;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
; This file was generated Sun Jul 15 18:49:18 2012
;--------------------------------------------------------
	.module adc
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
	.globl _CMPbuf
	.globl _CMPbufaddr
	.globl _CMPModex
	.globl _CMPx
	.globl _HighByte
	.globl _LowByte
	.globl _Get_SD_ADC
	.globl _Get_ADC
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
_LowByte::
	.ds 1
_HighByte::
	.ds 1
_CMPx::
	.ds 1
_CMPModex::
	.ds 1
_CMPbufaddr::
	.ds 1
_CMPbuf::
	.ds 2
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
;Allocation info for local variables in function 'Get_SD_ADC'
;------------------------------------------------------------
;------------------------------------------------------------
;	../../com/adc_922.c:26: void Get_SD_ADC(void) __naked
;	-----------------------------------------
;	 function Get_SD_ADC
;	-----------------------------------------
_Get_SD_ADC:
;	naked function: no prologue.
;	../../com/adc_922.c:110: _endasm;
	
	
	 00001$:
	 PUSH ACC
	 PUSH PSW
	 push ar0
	 PUSH ar4
	 PUSH ar5
	
	 MOV R0,_CMPbufaddr
	 MOV _CMP1,_CMPModex ; load CMPModex into comparator control register P0_6
	 MOV _CMP2,_CMPModex ; load CMPModex "" "" P0_0
	 MOV R4,#0
	 MOV R5,#0
	
	 00002$:
; Precharge (charges capacitor exactly to voltage of positive input)
	 MOV _CMPbuf,_CMP1 ; comparatur control registers into CMPbuf
	 MOV _CMPbuf+1,_CMP2
	 MOV A,@R0 ; get CMPx indirectly, R0 is address of the variable CMPbuf
	 ANL A,#0x02 ; only take the comparator output bit
	 MOV C,0xE1 ; comparator output –> carry (0xE1 is second bit of ACC)
	 CLR A
	 MOV 0x80,C ; P0.0 = comparator output (charge capacitor when negative input is lower than positive)
	
	 JB _interrupted,00004$
	
	
 ;Counter
	 CLR C ; increase 16-bit counter register R4/R5
	 MOV A,R4
	 ADD A,#0x01
	 MOV R4,A
	 MOV A,R5
	 ADDC A,#0x00
	 MOV R5,A
	 CJNE A,#0x40,00002$ ; precharge loop (enough cycles, so that C could be fully charged to Vcc)
	
	
	 MOV R4,#0x80 ; R4/R5 are 16-bit counter for Measurecycles (should be 10.000 times Vcc, e.g. 5V=50.000 cycles)
	 MOV R5,#0x00 ; low byte is preset, so that at the end of loop only highbyte needs to be checked
	 MOV _LowByte,#0x00;
	 MOV _HighByte,#0x00;
	
	 00003$:
 ;Sigma
	
	 JB _interrupted,00004$
	
	 CLR C
	 MOV _CMPbuf,_CMP1 ; comparatur control registers into CMPbuf
	 MOV _CMPbuf+1,_CMP2
	 MOV A,@R0 ; get CMPx indirectly, R0 is address of the variable CMPbuf
	 ANL A,#0x02 ; only take the comparator output bit
	 MOV C,0xE1 ; comparator output –> carry (0xE1 is second bit of ACC)
	 CLR A
	 MOV 0x80,C ; comparator output (charge capacitor when negative input is lower than positive)
	
	 ADDC A,_LowByte ; increase LowByte/HighByte counter if comparator output is high
	 MOV _LowByte,A
	 MOV A,_HighByte
	 ADDC A,#0x00
	 MOV _HighByte,A
	
 ;Counter Measurementcycles
	 CLR C
	 MOV A,R4 ; increase R4/R5 counter
	 ADD A,#0x01
	 MOV R4,A
	 MOV A,R5
	 ADDC A,#0x00
	 MOV R5,A
	
	 CJNE A,#0xC4,00003$ ; check only high byte of R4/R5 to get correct number of measure cycles
	
	 00004$:
	 POP ar5;
	 POP ar4;
	 pop ar0
	 POP PSW;
	 POP ACC;
	 RET
	
	 
;	naked function: no epilogue.
;------------------------------------------------------------
;Allocation info for local variables in function 'Get_ADC'
;------------------------------------------------------------
;channel                   Allocated to registers r2 
;------------------------------------------------------------
;	../../com/adc_922.c:116: void Get_ADC(char channel)	// Channel 0-3
;	-----------------------------------------
;	 function Get_ADC
;	-----------------------------------------
_Get_ADC:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
;	../../com/adc_922.c:118: if (channel & 1)		// for channel 1 and 3
	mov	a,dpl
	mov	r2,a
	jnb	acc.0,00102$
;	../../com/adc_922.c:119: CMPModex = 0x030;		// comparator enabled, positive input pin CINnA, 
	mov	_CMPModex,#0x30
	sjmp	00103$
00102$:
;	../../com/adc_922.c:123: CMPModex = 0x020;		// same, but positive input pin is CINnB
	mov	_CMPModex,#0x20
00103$:
;	../../com/adc_922.c:125: if (channel & 2)
	mov	a,r2
	jnb	acc.1,00105$
;	../../com/adc_922.c:126: CMPbufaddr = (char) &CMPbuf[1];
	mov	_CMPbufaddr,#(_CMPbuf + 0x0001)
	sjmp	00106$
00105$:
;	../../com/adc_922.c:128: CMPbufaddr = (char) &CMPbuf[0];
	mov	_CMPbufaddr,#_CMPbuf
00106$:
;	../../com/adc_922.c:129: Get_SD_ADC();
	ljmp	_Get_SD_ADC
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
