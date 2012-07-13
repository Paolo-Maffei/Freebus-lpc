                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
                              4 ; This file was generated Thu Jun 28 18:23:14 2012
                              5 ;--------------------------------------------------------
                              6 	.module rauchmelder
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _P3_1
                             14 	.globl _P3_0
                             15 	.globl _P1_7
                             16 	.globl _P1_6
                             17 	.globl _P1_5
                             18 	.globl _P1_4
                             19 	.globl _P1_3
                             20 	.globl _P1_2
                             21 	.globl _P1_1
                             22 	.globl _P1_0
                             23 	.globl _P0_7
                             24 	.globl _P0_6
                             25 	.globl _P0_5
                             26 	.globl _P0_4
                             27 	.globl _P0_3
                             28 	.globl _P0_2
                             29 	.globl _P0_1
                             30 	.globl _P0_0
                             31 	.globl _I2CON_0
                             32 	.globl _I2CON_2
                             33 	.globl _I2CON_3
                             34 	.globl _I2CON_4
                             35 	.globl _I2CON_5
                             36 	.globl _I2CON_6
                             37 	.globl _SCON_7
                             38 	.globl _SCON_6
                             39 	.globl _SCON_5
                             40 	.globl _SCON_4
                             41 	.globl _SCON_3
                             42 	.globl _SCON_2
                             43 	.globl _SCON_1
                             44 	.globl _SCON_0
                             45 	.globl _IP0_0
                             46 	.globl _IP0_1
                             47 	.globl _IP0_2
                             48 	.globl _IP0_3
                             49 	.globl _IP0_4
                             50 	.globl _IP0_5
                             51 	.globl _IP0_6
                             52 	.globl _IP1_0
                             53 	.globl _IP1_1
                             54 	.globl _IP1_2
                             55 	.globl _IP1_6
                             56 	.globl _IEN1_0
                             57 	.globl _IEN1_1
                             58 	.globl _IEN1_2
                             59 	.globl _IEN0_0
                             60 	.globl _IEN0_1
                             61 	.globl _IEN0_2
                             62 	.globl _IEN0_3
                             63 	.globl _IEN0_4
                             64 	.globl _IEN0_5
                             65 	.globl _IEN0_6
                             66 	.globl _IEN0_7
                             67 	.globl _TCON_0
                             68 	.globl _TCON_1
                             69 	.globl _TCON_2
                             70 	.globl _TCON_3
                             71 	.globl _TCON_4
                             72 	.globl _TCON_5
                             73 	.globl _TCON_6
                             74 	.globl _TCON_7
                             75 	.globl _PSW_7
                             76 	.globl _PSW_6
                             77 	.globl _PSW_5
                             78 	.globl _PSW_4
                             79 	.globl _PSW_3
                             80 	.globl _PSW_2
                             81 	.globl _PSW_1
                             82 	.globl _PSW_0
                             83 	.globl _IEN1
                             84 	.globl _IP0H
                             85 	.globl _WFEED2
                             86 	.globl _WFEED1
                             87 	.globl _WDL
                             88 	.globl _WDCON
                             89 	.globl _TRIM
                             90 	.globl _TAMOD
                             91 	.globl _SSTAT
                             92 	.globl _RTCL
                             93 	.globl _RTCH
                             94 	.globl _RTCCON
                             95 	.globl _RSTSRC
                             96 	.globl _PT0AD
                             97 	.globl _PCONA
                             98 	.globl _P3M2
                             99 	.globl _P3M1
                            100 	.globl _P1M2
                            101 	.globl _P1M1
                            102 	.globl _P0M2
                            103 	.globl _P0M1
                            104 	.globl _KBPATN
                            105 	.globl _KBMASK
                            106 	.globl _KBCON
                            107 	.globl _IP1H
                            108 	.globl _IP1
                            109 	.globl _I2STAT
                            110 	.globl _I2SCLL
                            111 	.globl _I2SCLH
                            112 	.globl _I2DAT
                            113 	.globl _I2CON
                            114 	.globl _I2ADR
                            115 	.globl _FMDATA
                            116 	.globl _FMCON
                            117 	.globl _FMADRL
                            118 	.globl _FMADRH
                            119 	.globl _DIVM
                            120 	.globl _CMP2
                            121 	.globl _CMP1
                            122 	.globl _BRGCON
                            123 	.globl _BRGR1
                            124 	.globl _BRGR0
                            125 	.globl _SADEN
                            126 	.globl _SADDR
                            127 	.globl _AUXR1
                            128 	.globl _SBUF
                            129 	.globl _SCON
                            130 	.globl _IP0
                            131 	.globl _IEN0
                            132 	.globl _TH1
                            133 	.globl _TH0
                            134 	.globl _TL1
                            135 	.globl _TL0
                            136 	.globl _TMOD
                            137 	.globl _TCON
                            138 	.globl _PCON
                            139 	.globl _DPH
                            140 	.globl _DPL
                            141 	.globl _SP
                            142 	.globl _B
                            143 	.globl _ACC
                            144 	.globl _PSW
                            145 	.globl _P3
                            146 	.globl _P1
                            147 	.globl _P0
                            148 ;--------------------------------------------------------
                            149 ; special function registers
                            150 ;--------------------------------------------------------
                            151 	.area RSEG    (DATA)
                    0080    152 _P0	=	0x0080
                    0090    153 _P1	=	0x0090
                    00B0    154 _P3	=	0x00b0
                    00D0    155 _PSW	=	0x00d0
                    00E0    156 _ACC	=	0x00e0
                    00F0    157 _B	=	0x00f0
                    0081    158 _SP	=	0x0081
                    0082    159 _DPL	=	0x0082
                    0083    160 _DPH	=	0x0083
                    0087    161 _PCON	=	0x0087
                    0088    162 _TCON	=	0x0088
                    0089    163 _TMOD	=	0x0089
                    008A    164 _TL0	=	0x008a
                    008B    165 _TL1	=	0x008b
                    008C    166 _TH0	=	0x008c
                    008D    167 _TH1	=	0x008d
                    00A8    168 _IEN0	=	0x00a8
                    00B8    169 _IP0	=	0x00b8
                    0098    170 _SCON	=	0x0098
                    0099    171 _SBUF	=	0x0099
                    00A2    172 _AUXR1	=	0x00a2
                    00A9    173 _SADDR	=	0x00a9
                    00B9    174 _SADEN	=	0x00b9
                    00BE    175 _BRGR0	=	0x00be
                    00BF    176 _BRGR1	=	0x00bf
                    00BD    177 _BRGCON	=	0x00bd
                    00AC    178 _CMP1	=	0x00ac
                    00AD    179 _CMP2	=	0x00ad
                    0095    180 _DIVM	=	0x0095
                    00E7    181 _FMADRH	=	0x00e7
                    00E6    182 _FMADRL	=	0x00e6
                    00E4    183 _FMCON	=	0x00e4
                    00E5    184 _FMDATA	=	0x00e5
                    00DB    185 _I2ADR	=	0x00db
                    00D8    186 _I2CON	=	0x00d8
                    00DA    187 _I2DAT	=	0x00da
                    00DD    188 _I2SCLH	=	0x00dd
                    00DC    189 _I2SCLL	=	0x00dc
                    00D9    190 _I2STAT	=	0x00d9
                    00F8    191 _IP1	=	0x00f8
                    00F7    192 _IP1H	=	0x00f7
                    0094    193 _KBCON	=	0x0094
                    0086    194 _KBMASK	=	0x0086
                    0093    195 _KBPATN	=	0x0093
                    0084    196 _P0M1	=	0x0084
                    0085    197 _P0M2	=	0x0085
                    0091    198 _P1M1	=	0x0091
                    0092    199 _P1M2	=	0x0092
                    00B1    200 _P3M1	=	0x00b1
                    00B2    201 _P3M2	=	0x00b2
                    00B5    202 _PCONA	=	0x00b5
                    00F6    203 _PT0AD	=	0x00f6
                    00DF    204 _RSTSRC	=	0x00df
                    00D1    205 _RTCCON	=	0x00d1
                    00D2    206 _RTCH	=	0x00d2
                    00D3    207 _RTCL	=	0x00d3
                    00BA    208 _SSTAT	=	0x00ba
                    008F    209 _TAMOD	=	0x008f
                    0096    210 _TRIM	=	0x0096
                    00A7    211 _WDCON	=	0x00a7
                    00C1    212 _WDL	=	0x00c1
                    00C2    213 _WFEED1	=	0x00c2
                    00C3    214 _WFEED2	=	0x00c3
                    00B7    215 _IP0H	=	0x00b7
                    00E8    216 _IEN1	=	0x00e8
                            217 ;--------------------------------------------------------
                            218 ; special function bits
                            219 ;--------------------------------------------------------
                            220 	.area RSEG    (DATA)
                    00D0    221 _PSW_0	=	0x00d0
                    00D1    222 _PSW_1	=	0x00d1
                    00D2    223 _PSW_2	=	0x00d2
                    00D3    224 _PSW_3	=	0x00d3
                    00D4    225 _PSW_4	=	0x00d4
                    00D5    226 _PSW_5	=	0x00d5
                    00D6    227 _PSW_6	=	0x00d6
                    00D7    228 _PSW_7	=	0x00d7
                    008F    229 _TCON_7	=	0x008f
                    008E    230 _TCON_6	=	0x008e
                    008D    231 _TCON_5	=	0x008d
                    008C    232 _TCON_4	=	0x008c
                    008B    233 _TCON_3	=	0x008b
                    008A    234 _TCON_2	=	0x008a
                    0089    235 _TCON_1	=	0x0089
                    0088    236 _TCON_0	=	0x0088
                    00AF    237 _IEN0_7	=	0x00af
                    00AE    238 _IEN0_6	=	0x00ae
                    00AD    239 _IEN0_5	=	0x00ad
                    00AC    240 _IEN0_4	=	0x00ac
                    00AB    241 _IEN0_3	=	0x00ab
                    00AA    242 _IEN0_2	=	0x00aa
                    00A9    243 _IEN0_1	=	0x00a9
                    00A8    244 _IEN0_0	=	0x00a8
                    00EA    245 _IEN1_2	=	0x00ea
                    00E9    246 _IEN1_1	=	0x00e9
                    00E8    247 _IEN1_0	=	0x00e8
                    00FE    248 _IP1_6	=	0x00fe
                    00FA    249 _IP1_2	=	0x00fa
                    00F9    250 _IP1_1	=	0x00f9
                    00F8    251 _IP1_0	=	0x00f8
                    00BE    252 _IP0_6	=	0x00be
                    00BD    253 _IP0_5	=	0x00bd
                    00BC    254 _IP0_4	=	0x00bc
                    00BB    255 _IP0_3	=	0x00bb
                    00BA    256 _IP0_2	=	0x00ba
                    00B9    257 _IP0_1	=	0x00b9
                    00B8    258 _IP0_0	=	0x00b8
                    0098    259 _SCON_0	=	0x0098
                    0099    260 _SCON_1	=	0x0099
                    009A    261 _SCON_2	=	0x009a
                    009B    262 _SCON_3	=	0x009b
                    009C    263 _SCON_4	=	0x009c
                    009D    264 _SCON_5	=	0x009d
                    009E    265 _SCON_6	=	0x009e
                    009F    266 _SCON_7	=	0x009f
                    00DE    267 _I2CON_6	=	0x00de
                    00DD    268 _I2CON_5	=	0x00dd
                    00DC    269 _I2CON_4	=	0x00dc
                    00DB    270 _I2CON_3	=	0x00db
                    00DA    271 _I2CON_2	=	0x00da
                    00D8    272 _I2CON_0	=	0x00d8
                    0080    273 _P0_0	=	0x0080
                    0081    274 _P0_1	=	0x0081
                    0082    275 _P0_2	=	0x0082
                    0083    276 _P0_3	=	0x0083
                    0084    277 _P0_4	=	0x0084
                    0085    278 _P0_5	=	0x0085
                    0086    279 _P0_6	=	0x0086
                    0087    280 _P0_7	=	0x0087
                    0090    281 _P1_0	=	0x0090
                    0091    282 _P1_1	=	0x0091
                    0092    283 _P1_2	=	0x0092
                    0093    284 _P1_3	=	0x0093
                    0094    285 _P1_4	=	0x0094
                    0095    286 _P1_5	=	0x0095
                    0096    287 _P1_6	=	0x0096
                    0097    288 _P1_7	=	0x0097
                    00B0    289 _P3_0	=	0x00b0
                    00B1    290 _P3_1	=	0x00b1
                            291 ;--------------------------------------------------------
                            292 ; overlayable register banks
                            293 ;--------------------------------------------------------
                            294 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     295 	.ds 8
                            296 ;--------------------------------------------------------
                            297 ; internal ram data
                            298 ;--------------------------------------------------------
                            299 	.area DSEG    (DATA)
                            300 ;--------------------------------------------------------
                            301 ; overlayable items in internal ram 
                            302 ;--------------------------------------------------------
                            303 	.area OSEG    (OVR,DATA)
                            304 ;--------------------------------------------------------
                            305 ; Stack segment in internal ram 
                            306 ;--------------------------------------------------------
                            307 	.area	SSEG	(DATA)
   0053                     308 __start__stack:
   0053                     309 	.ds	1
                            310 
                            311 ;--------------------------------------------------------
                            312 ; indirectly addressable internal ram data
                            313 ;--------------------------------------------------------
                            314 	.area ISEG    (DATA)
                            315 ;--------------------------------------------------------
                            316 ; absolute internal ram data
                            317 ;--------------------------------------------------------
                            318 	.area IABS    (ABS,DATA)
                            319 	.area IABS    (ABS,DATA)
                            320 ;--------------------------------------------------------
                            321 ; bit data
                            322 ;--------------------------------------------------------
                            323 	.area BSEG    (BIT)
                            324 ;--------------------------------------------------------
                            325 ; paged external ram data
                            326 ;--------------------------------------------------------
                            327 	.area PSEG    (PAG,XDATA)
                            328 ;--------------------------------------------------------
                            329 ; external ram data
                            330 ;--------------------------------------------------------
                            331 	.area XSEG    (XDATA)
                            332 ;--------------------------------------------------------
                            333 ; absolute external ram data
                            334 ;--------------------------------------------------------
                            335 	.area XABS    (ABS,XDATA)
                            336 ;--------------------------------------------------------
                            337 ; external initialized ram data
                            338 ;--------------------------------------------------------
                            339 	.area XISEG   (XDATA)
                            340 	.area HOME    (CODE)
                            341 	.area GSINIT0 (CODE)
                            342 	.area GSINIT1 (CODE)
                            343 	.area GSINIT2 (CODE)
                            344 	.area GSINIT3 (CODE)
                            345 	.area GSINIT4 (CODE)
                            346 	.area GSINIT5 (CODE)
                            347 	.area GSINIT  (CODE)
                            348 	.area GSFINAL (CODE)
                            349 	.area CSEG    (CODE)
                            350 ;--------------------------------------------------------
                            351 ; interrupt vector 
                            352 ;--------------------------------------------------------
                            353 	.area HOME    (CODE)
   0000                     354 __interrupt_vect:
   0000 02 00 43            355 	ljmp	__sdcc_gsinit_startup
   0003 32                  356 	reti
   0004                     357 	.ds	7
   000B 32                  358 	reti
   000C                     359 	.ds	7
   0013 02 02 E0            360 	ljmp	_X1_int
   0016                     361 	.ds	5
   001B 02 03 13            362 	ljmp	_T1_int
   001E                     363 	.ds	5
   0023 32                  364 	reti
   0024                     365 	.ds	7
   002B 32                  366 	reti
   002C                     367 	.ds	7
   0033 32                  368 	reti
   0034                     369 	.ds	7
   003B 02 01 6F            370 	ljmp	_key
                            371 ;--------------------------------------------------------
                            372 ; global & static initialisations
                            373 ;--------------------------------------------------------
                            374 	.area HOME    (CODE)
                            375 	.area GSINIT  (CODE)
                            376 	.area GSFINAL (CODE)
                            377 	.area GSINIT  (CODE)
                            378 	.globl __sdcc_gsinit_startup
                            379 	.globl __sdcc_program_startup
                            380 	.globl __start__stack
                            381 	.globl __mcs51_genXINIT
                            382 	.globl __mcs51_genXRAMCLEAR
                            383 	.globl __mcs51_genRAMCLEAR
                            384 	.area GSFINAL (CODE)
   009C 02 00 3E            385 	ljmp	__sdcc_program_startup
                            386 ;--------------------------------------------------------
                            387 ; Home
                            388 ;--------------------------------------------------------
                            389 	.area HOME    (CODE)
                            390 	.area HOME    (CODE)
   003E                     391 __sdcc_program_startup:
   003E 12 00 9F            392 	lcall	_main
                            393 ;	return from main will lock up
   0041 80 FE               394 	sjmp .
                            395 ;--------------------------------------------------------
                            396 ; code
                            397 ;--------------------------------------------------------
                            398 	.area CSEG    (CODE)
                            399 ;------------------------------------------------------------
                            400 ;Allocation info for local variables in function 'main'
                            401 ;------------------------------------------------------------
                            402 ;n                         Allocated to registers r2 
                            403 ;------------------------------------------------------------
                            404 ;	../rauchmelder.c:27: void main(void)
                            405 ;	-----------------------------------------
                            406 ;	 function main
                            407 ;	-----------------------------------------
   009F                     408 _main:
                    0002    409 	ar2 = 0x02
                    0003    410 	ar3 = 0x03
                    0004    411 	ar4 = 0x04
                    0005    412 	ar5 = 0x05
                    0006    413 	ar6 = 0x06
                    0007    414 	ar7 = 0x07
                    0000    415 	ar0 = 0x00
                    0001    416 	ar1 = 0x01
                            417 ;	../rauchmelder.c:32: restart_hw();				// Hardware zuruecksetzen
   009F 12 0C 07            418 	lcall	_restart_hw
                            419 ;	../rauchmelder.c:34: for (n=0;n<50;n++) {		// Warten bis Bus stabil, nach Busspannungswiederkehr
   00A2 7A 00               420 	mov	r2,#0x00
   00A4                     421 00126$:
   00A4 BA 32 00            422 	cjne	r2,#0x32,00161$
   00A7                     423 00161$:
   00A7 50 1A               424 	jnc	00129$
                            425 ;	../rauchmelder.c:35: TR0=0;					// Timer 0 anhalten
   00A9 C2 8C               426 	clr	_TCON_4
                            427 ;	../rauchmelder.c:36: TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
   00AB 90 1D 17            428 	mov	dptr,#(_eeprom + 0x0017)
   00AE E4                  429 	clr	a
   00AF 93                  430 	movc	a,@a+dptr
   00B0 F5 8C               431 	mov	_TH0,a
                            432 ;	../rauchmelder.c:37: TL0=eeprom[ADDRTAB+2];
   00B2 90 1D 18            433 	mov	dptr,#(_eeprom + 0x0018)
   00B5 E4                  434 	clr	a
   00B6 93                  435 	movc	a,@a+dptr
   00B7 F5 8A               436 	mov	_TL0,a
                            437 ;	../rauchmelder.c:38: TF0=0;					// Überlauf-Flag zurücksetzen
   00B9 C2 8D               438 	clr	_TCON_5
                            439 ;	../rauchmelder.c:39: TR0=1;					// Timer 0 starten
   00BB D2 8C               440 	setb	_TCON_4
                            441 ;	../rauchmelder.c:40: while(!TF0);
   00BD                     442 00101$:
   00BD 30 8D FD            443 	jnb	_TCON_5,00101$
                            444 ;	../rauchmelder.c:34: for (n=0;n<50;n++) {		// Warten bis Bus stabil, nach Busspannungswiederkehr
   00C0 0A                  445 	inc	r2
   00C1 80 E1               446 	sjmp	00126$
   00C3                     447 00129$:
                            448 ;	../rauchmelder.c:42: restart_app();				// Anwendungsspezifische Einstellungen zuruecksetzen
   00C3 12 02 43            449 	lcall	_restart_app
                            450 ;	../rauchmelder.c:45: do  {
   00C6                     451 00123$:
                            452 ;	../rauchmelder.c:46: if(APPLICATION_RUN) {	// nur wenn run-mode gesetzt
   00C6 90 1D 0D            453 	mov	dptr,#(_eeprom + 0x000d)
   00C9 E4                  454 	clr	a
   00CA 93                  455 	movc	a,@a+dptr
   00CB FA                  456 	mov	r2,a
   00CC BA FF 2F            457 	cjne	r2,#0xFF,00112$
   00CF 20 14 2C            458 	jb	_connected,00112$
                            459 ;	../rauchmelder.c:48: if (event) {				// wenn Rauchmelder etwas gesendet hat
   00D2 30 00 29            460 	jnb	_event,00112$
                            461 ;	../rauchmelder.c:49: if (alarm != alarm_obj && !fernalarm) {	// wenn Alarm aber keine Fernauslösung vorliegt
   00D5 A2 01               462 	mov	c,_alarm
   00D7 20 03 01            463 	jb	_alarm_obj,00168$
   00DA B3                  464 	cpl	c
   00DB                     465 00168$:
   00DB 40 0D               466 	jc	00105$
   00DD 20 05 0A            467 	jb	_fernalarm,00105$
                            468 ;	../rauchmelder.c:50: send_obj_value(0);					// Telegramm senden
   00E0 75 82 00            469 	mov	dpl,#0x00
   00E3 12 09 1E            470 	lcall	_send_obj_value
                            471 ;	../rauchmelder.c:51: alarm_obj = alarm;					// Objektwert setzen
   00E6 A2 01               472 	mov	c,_alarm
   00E8 92 03               473 	mov	_alarm_obj,c
   00EA                     474 00105$:
                            475 ;	../rauchmelder.c:53: if (stoerung != stoerung_obj) {			// bei Störung
   00EA A2 02               476 	mov	c,_stoerung
   00EC 20 04 01            477 	jb	_stoerung_obj,00171$
   00EF B3                  478 	cpl	c
   00F0                     479 00171$:
   00F0 40 0A               480 	jc	00108$
                            481 ;	../rauchmelder.c:54: send_obj_value(1);					// Telegramm senden
   00F2 75 82 01            482 	mov	dpl,#0x01
   00F5 12 09 1E            483 	lcall	_send_obj_value
                            484 ;	../rauchmelder.c:55: stoerung_obj = stoerung;			// Objektwert setzen
   00F8 A2 02               485 	mov	c,_stoerung
   00FA 92 04               486 	mov	_stoerung_obj,c
   00FC                     487 00108$:
                            488 ;	../rauchmelder.c:57: event=0;	// Ereignismelder zurücksetzen
   00FC C2 00               489 	clr	_event
   00FE                     490 00112$:
                            491 ;	../rauchmelder.c:61: if(tel_arrived) process_tel();		// empfangenes Telegramm abarbeiten
   00FE 30 0C 03            492 	jnb	_tel_arrived,00115$
   0101 12 09 51            493 	lcall	_process_tel
   0104                     494 00115$:
                            495 ;	../rauchmelder.c:63: if(RTCCON>=0x80) delay_timer();		// Realtime clock Ueberlauf
   0104 74 80               496 	mov	a,#0x100 - 0x80
   0106 25 D1               497 	add	a,_RTCCON
   0108 50 03               498 	jnc	00117$
   010A 12 01 A2            499 	lcall	_delay_timer
   010D                     500 00117$:
                            501 ;	../rauchmelder.c:67: TASTER=1;					// Pin als Eingang schalten um Taster abzufragen
   010D D2 97               502 	setb	_P1_7
                            503 ;	../rauchmelder.c:68: if(!TASTER) {				// Taster gedrückt
   010F 20 97 0A            504 	jb	_P1_7,00122$
                            505 ;	../rauchmelder.c:69: for(n=0;n<100;n++) {}	// Entprell-Zeit
   0112 7A 64               506 	mov	r2,#0x64
   0114                     507 00132$:
   0114 DA FE               508 	djnz	r2,00132$
                            509 ;	../rauchmelder.c:70: while(!TASTER);			// warten bis Taster losgelassen
   0116                     510 00118$:
   0116 30 97 FD            511 	jnb	_P1_7,00118$
                            512 ;	../rauchmelder.c:71: status60^=0x81;			// Prog-Bit und Parity-Bit im system_state toggeln
   0119 63 52 81            513 	xrl	_status60,#0x81
   011C                     514 00122$:
                            515 ;	../rauchmelder.c:73: TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
   011C E5 52               516 	mov	a,_status60
   011E 54 01               517 	anl	a,#0x01
   0120 FA                  518 	mov	r2,a
   0121 B4 01 00            519 	cjne	a,#0x01,00179$
   0124                     520 00179$:
   0124 92 97               521 	mov	_P1_7,c
                            522 ;	../rauchmelder.c:74: for(n=0;n<100;n++) {}		// falls Hauptroutine keine Zeit verbraucht, der LED etwas Zeit geben, damit sie auch leuchten kann
   0126 7A 64               523 	mov	r2,#0x64
   0128                     524 00135$:
   0128 DA FE               525 	djnz	r2,00135$
                            526 ;	../rauchmelder.c:75: } while(1);
   012A 80 9A               527 	sjmp	00123$
                            528 	.area CSEG    (CODE)
                            529 	.area CONST   (CODE)
                            530 	.area XINIT   (CODE)
                            531 	.area CABS    (ABS,CODE)
