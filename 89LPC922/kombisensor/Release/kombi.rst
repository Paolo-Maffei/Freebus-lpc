                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
                              4 ; This file was generated Sun Jul 15 18:49:22 2012
                              5 ;--------------------------------------------------------
                              6 	.module kombi
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _luxchange
                             13 	.globl _logtable
                             14 	.globl _main
                             15 	.globl _P3_1
                             16 	.globl _P3_0
                             17 	.globl _P1_7
                             18 	.globl _P1_6
                             19 	.globl _P1_5
                             20 	.globl _P1_4
                             21 	.globl _P1_3
                             22 	.globl _P1_2
                             23 	.globl _P1_1
                             24 	.globl _P1_0
                             25 	.globl _P0_7
                             26 	.globl _P0_6
                             27 	.globl _P0_5
                             28 	.globl _P0_4
                             29 	.globl _P0_3
                             30 	.globl _P0_2
                             31 	.globl _P0_1
                             32 	.globl _P0_0
                             33 	.globl _I2CON_0
                             34 	.globl _I2CON_2
                             35 	.globl _I2CON_3
                             36 	.globl _I2CON_4
                             37 	.globl _I2CON_5
                             38 	.globl _I2CON_6
                             39 	.globl _SCON_7
                             40 	.globl _SCON_6
                             41 	.globl _SCON_5
                             42 	.globl _SCON_4
                             43 	.globl _SCON_3
                             44 	.globl _SCON_2
                             45 	.globl _SCON_1
                             46 	.globl _SCON_0
                             47 	.globl _IP0_0
                             48 	.globl _IP0_1
                             49 	.globl _IP0_2
                             50 	.globl _IP0_3
                             51 	.globl _IP0_4
                             52 	.globl _IP0_5
                             53 	.globl _IP0_6
                             54 	.globl _IP1_0
                             55 	.globl _IP1_1
                             56 	.globl _IP1_2
                             57 	.globl _IP1_6
                             58 	.globl _IEN1_0
                             59 	.globl _IEN1_1
                             60 	.globl _IEN1_2
                             61 	.globl _IEN0_0
                             62 	.globl _IEN0_1
                             63 	.globl _IEN0_2
                             64 	.globl _IEN0_3
                             65 	.globl _IEN0_4
                             66 	.globl _IEN0_5
                             67 	.globl _IEN0_6
                             68 	.globl _IEN0_7
                             69 	.globl _TCON_0
                             70 	.globl _TCON_1
                             71 	.globl _TCON_2
                             72 	.globl _TCON_3
                             73 	.globl _TCON_4
                             74 	.globl _TCON_5
                             75 	.globl _TCON_6
                             76 	.globl _TCON_7
                             77 	.globl _PSW_7
                             78 	.globl _PSW_6
                             79 	.globl _PSW_5
                             80 	.globl _PSW_4
                             81 	.globl _PSW_3
                             82 	.globl _PSW_2
                             83 	.globl _PSW_1
                             84 	.globl _PSW_0
                             85 	.globl _IEN1
                             86 	.globl _IP0H
                             87 	.globl _WFEED2
                             88 	.globl _WFEED1
                             89 	.globl _WDL
                             90 	.globl _WDCON
                             91 	.globl _TRIM
                             92 	.globl _TAMOD
                             93 	.globl _SSTAT
                             94 	.globl _RTCL
                             95 	.globl _RTCH
                             96 	.globl _RTCCON
                             97 	.globl _RSTSRC
                             98 	.globl _PT0AD
                             99 	.globl _PCONA
                            100 	.globl _P3M2
                            101 	.globl _P3M1
                            102 	.globl _P1M2
                            103 	.globl _P1M1
                            104 	.globl _P0M2
                            105 	.globl _P0M1
                            106 	.globl _KBPATN
                            107 	.globl _KBMASK
                            108 	.globl _KBCON
                            109 	.globl _IP1H
                            110 	.globl _IP1
                            111 	.globl _I2STAT
                            112 	.globl _I2SCLL
                            113 	.globl _I2SCLH
                            114 	.globl _I2DAT
                            115 	.globl _I2CON
                            116 	.globl _I2ADR
                            117 	.globl _FMDATA
                            118 	.globl _FMCON
                            119 	.globl _FMADRL
                            120 	.globl _FMADRH
                            121 	.globl _DIVM
                            122 	.globl _CMP2
                            123 	.globl _CMP1
                            124 	.globl _BRGCON
                            125 	.globl _BRGR1
                            126 	.globl _BRGR0
                            127 	.globl _SADEN
                            128 	.globl _SADDR
                            129 	.globl _AUXR1
                            130 	.globl _SBUF
                            131 	.globl _SCON
                            132 	.globl _IP0
                            133 	.globl _IEN0
                            134 	.globl _TH1
                            135 	.globl _TH0
                            136 	.globl _TL1
                            137 	.globl _TL0
                            138 	.globl _TMOD
                            139 	.globl _TCON
                            140 	.globl _PCON
                            141 	.globl _DPH
                            142 	.globl _DPL
                            143 	.globl _SP
                            144 	.globl _B
                            145 	.globl _ACC
                            146 	.globl _PSW
                            147 	.globl _P3
                            148 	.globl _P1
                            149 	.globl _P0
                            150 	.globl _tastergetoggelt
                            151 	.globl _tasterpegel
                            152 	.globl _lux
                            153 	.globl _temp
                            154 	.globl _lasttemp
                            155 	.globl _lastlux
                            156 	.globl _timer
                            157 ;--------------------------------------------------------
                            158 ; special function registers
                            159 ;--------------------------------------------------------
                            160 	.area RSEG    (DATA)
                    0080    161 _P0	=	0x0080
                    0090    162 _P1	=	0x0090
                    00B0    163 _P3	=	0x00b0
                    00D0    164 _PSW	=	0x00d0
                    00E0    165 _ACC	=	0x00e0
                    00F0    166 _B	=	0x00f0
                    0081    167 _SP	=	0x0081
                    0082    168 _DPL	=	0x0082
                    0083    169 _DPH	=	0x0083
                    0087    170 _PCON	=	0x0087
                    0088    171 _TCON	=	0x0088
                    0089    172 _TMOD	=	0x0089
                    008A    173 _TL0	=	0x008a
                    008B    174 _TL1	=	0x008b
                    008C    175 _TH0	=	0x008c
                    008D    176 _TH1	=	0x008d
                    00A8    177 _IEN0	=	0x00a8
                    00B8    178 _IP0	=	0x00b8
                    0098    179 _SCON	=	0x0098
                    0099    180 _SBUF	=	0x0099
                    00A2    181 _AUXR1	=	0x00a2
                    00A9    182 _SADDR	=	0x00a9
                    00B9    183 _SADEN	=	0x00b9
                    00BE    184 _BRGR0	=	0x00be
                    00BF    185 _BRGR1	=	0x00bf
                    00BD    186 _BRGCON	=	0x00bd
                    00AC    187 _CMP1	=	0x00ac
                    00AD    188 _CMP2	=	0x00ad
                    0095    189 _DIVM	=	0x0095
                    00E7    190 _FMADRH	=	0x00e7
                    00E6    191 _FMADRL	=	0x00e6
                    00E4    192 _FMCON	=	0x00e4
                    00E5    193 _FMDATA	=	0x00e5
                    00DB    194 _I2ADR	=	0x00db
                    00D8    195 _I2CON	=	0x00d8
                    00DA    196 _I2DAT	=	0x00da
                    00DD    197 _I2SCLH	=	0x00dd
                    00DC    198 _I2SCLL	=	0x00dc
                    00D9    199 _I2STAT	=	0x00d9
                    00F8    200 _IP1	=	0x00f8
                    00F7    201 _IP1H	=	0x00f7
                    0094    202 _KBCON	=	0x0094
                    0086    203 _KBMASK	=	0x0086
                    0093    204 _KBPATN	=	0x0093
                    0084    205 _P0M1	=	0x0084
                    0085    206 _P0M2	=	0x0085
                    0091    207 _P1M1	=	0x0091
                    0092    208 _P1M2	=	0x0092
                    00B1    209 _P3M1	=	0x00b1
                    00B2    210 _P3M2	=	0x00b2
                    00B5    211 _PCONA	=	0x00b5
                    00F6    212 _PT0AD	=	0x00f6
                    00DF    213 _RSTSRC	=	0x00df
                    00D1    214 _RTCCON	=	0x00d1
                    00D2    215 _RTCH	=	0x00d2
                    00D3    216 _RTCL	=	0x00d3
                    00BA    217 _SSTAT	=	0x00ba
                    008F    218 _TAMOD	=	0x008f
                    0096    219 _TRIM	=	0x0096
                    00A7    220 _WDCON	=	0x00a7
                    00C1    221 _WDL	=	0x00c1
                    00C2    222 _WFEED1	=	0x00c2
                    00C3    223 _WFEED2	=	0x00c3
                    00B7    224 _IP0H	=	0x00b7
                    00E8    225 _IEN1	=	0x00e8
                            226 ;--------------------------------------------------------
                            227 ; special function bits
                            228 ;--------------------------------------------------------
                            229 	.area RSEG    (DATA)
                    00D0    230 _PSW_0	=	0x00d0
                    00D1    231 _PSW_1	=	0x00d1
                    00D2    232 _PSW_2	=	0x00d2
                    00D3    233 _PSW_3	=	0x00d3
                    00D4    234 _PSW_4	=	0x00d4
                    00D5    235 _PSW_5	=	0x00d5
                    00D6    236 _PSW_6	=	0x00d6
                    00D7    237 _PSW_7	=	0x00d7
                    008F    238 _TCON_7	=	0x008f
                    008E    239 _TCON_6	=	0x008e
                    008D    240 _TCON_5	=	0x008d
                    008C    241 _TCON_4	=	0x008c
                    008B    242 _TCON_3	=	0x008b
                    008A    243 _TCON_2	=	0x008a
                    0089    244 _TCON_1	=	0x0089
                    0088    245 _TCON_0	=	0x0088
                    00AF    246 _IEN0_7	=	0x00af
                    00AE    247 _IEN0_6	=	0x00ae
                    00AD    248 _IEN0_5	=	0x00ad
                    00AC    249 _IEN0_4	=	0x00ac
                    00AB    250 _IEN0_3	=	0x00ab
                    00AA    251 _IEN0_2	=	0x00aa
                    00A9    252 _IEN0_1	=	0x00a9
                    00A8    253 _IEN0_0	=	0x00a8
                    00EA    254 _IEN1_2	=	0x00ea
                    00E9    255 _IEN1_1	=	0x00e9
                    00E8    256 _IEN1_0	=	0x00e8
                    00FE    257 _IP1_6	=	0x00fe
                    00FA    258 _IP1_2	=	0x00fa
                    00F9    259 _IP1_1	=	0x00f9
                    00F8    260 _IP1_0	=	0x00f8
                    00BE    261 _IP0_6	=	0x00be
                    00BD    262 _IP0_5	=	0x00bd
                    00BC    263 _IP0_4	=	0x00bc
                    00BB    264 _IP0_3	=	0x00bb
                    00BA    265 _IP0_2	=	0x00ba
                    00B9    266 _IP0_1	=	0x00b9
                    00B8    267 _IP0_0	=	0x00b8
                    0098    268 _SCON_0	=	0x0098
                    0099    269 _SCON_1	=	0x0099
                    009A    270 _SCON_2	=	0x009a
                    009B    271 _SCON_3	=	0x009b
                    009C    272 _SCON_4	=	0x009c
                    009D    273 _SCON_5	=	0x009d
                    009E    274 _SCON_6	=	0x009e
                    009F    275 _SCON_7	=	0x009f
                    00DE    276 _I2CON_6	=	0x00de
                    00DD    277 _I2CON_5	=	0x00dd
                    00DC    278 _I2CON_4	=	0x00dc
                    00DB    279 _I2CON_3	=	0x00db
                    00DA    280 _I2CON_2	=	0x00da
                    00D8    281 _I2CON_0	=	0x00d8
                    0080    282 _P0_0	=	0x0080
                    0081    283 _P0_1	=	0x0081
                    0082    284 _P0_2	=	0x0082
                    0083    285 _P0_3	=	0x0083
                    0084    286 _P0_4	=	0x0084
                    0085    287 _P0_5	=	0x0085
                    0086    288 _P0_6	=	0x0086
                    0087    289 _P0_7	=	0x0087
                    0090    290 _P1_0	=	0x0090
                    0091    291 _P1_1	=	0x0091
                    0092    292 _P1_2	=	0x0092
                    0093    293 _P1_3	=	0x0093
                    0094    294 _P1_4	=	0x0094
                    0095    295 _P1_5	=	0x0095
                    0096    296 _P1_6	=	0x0096
                    0097    297 _P1_7	=	0x0097
                    00B0    298 _P3_0	=	0x00b0
                    00B1    299 _P3_1	=	0x00b1
                            300 ;--------------------------------------------------------
                            301 ; overlayable register banks
                            302 ;--------------------------------------------------------
                            303 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     304 	.ds 8
                            305 ;--------------------------------------------------------
                            306 ; internal ram data
                            307 ;--------------------------------------------------------
                            308 	.area DSEG    (DATA)
   000F                     309 _timer::
   000F                     310 	.ds 2
   0011                     311 _lastlux::
   0011                     312 	.ds 2
   0013                     313 _lasttemp::
   0013                     314 	.ds 2
   0015                     315 _temp::
   0015                     316 	.ds 2
   0017                     317 _lux::
   0017                     318 	.ds 2
   0019                     319 _tasterpegel::
   0019                     320 	.ds 1
                            321 ;--------------------------------------------------------
                            322 ; overlayable items in internal ram 
                            323 ;--------------------------------------------------------
                            324 	.area OSEG    (OVR,DATA)
                            325 ;--------------------------------------------------------
                            326 ; Stack segment in internal ram 
                            327 ;--------------------------------------------------------
                            328 	.area	SSEG	(DATA)
   0082                     329 __start__stack:
   0082                     330 	.ds	1
                            331 
                            332 ;--------------------------------------------------------
                            333 ; indirectly addressable internal ram data
                            334 ;--------------------------------------------------------
                            335 	.area ISEG    (DATA)
                            336 ;--------------------------------------------------------
                            337 ; absolute internal ram data
                            338 ;--------------------------------------------------------
                            339 	.area IABS    (ABS,DATA)
                            340 	.area IABS    (ABS,DATA)
                            341 ;--------------------------------------------------------
                            342 ; bit data
                            343 ;--------------------------------------------------------
                            344 	.area BSEG    (BIT)
   0000                     345 _tastergetoggelt::
   0000                     346 	.ds 1
                            347 ;--------------------------------------------------------
                            348 ; paged external ram data
                            349 ;--------------------------------------------------------
                            350 	.area PSEG    (PAG,XDATA)
                            351 ;--------------------------------------------------------
                            352 ; external ram data
                            353 ;--------------------------------------------------------
                            354 	.area XSEG    (XDATA)
                            355 ;--------------------------------------------------------
                            356 ; absolute external ram data
                            357 ;--------------------------------------------------------
                            358 	.area XABS    (ABS,XDATA)
                            359 ;--------------------------------------------------------
                            360 ; external initialized ram data
                            361 ;--------------------------------------------------------
                            362 	.area XISEG   (XDATA)
                            363 	.area HOME    (CODE)
                            364 	.area GSINIT0 (CODE)
                            365 	.area GSINIT1 (CODE)
                            366 	.area GSINIT2 (CODE)
                            367 	.area GSINIT3 (CODE)
                            368 	.area GSINIT4 (CODE)
                            369 	.area GSINIT5 (CODE)
                            370 	.area GSINIT  (CODE)
                            371 	.area GSFINAL (CODE)
                            372 	.area CSEG    (CODE)
                            373 ;--------------------------------------------------------
                            374 ; interrupt vector 
                            375 ;--------------------------------------------------------
                            376 	.area HOME    (CODE)
   0000                     377 __interrupt_vect:
   0000 02 00 23            378 	ljmp	__sdcc_gsinit_startup
   0003 32                  379 	reti
   0004                     380 	.ds	7
   000B 32                  381 	reti
   000C                     382 	.ds	7
   0013 02 10 DD            383 	ljmp	_X1_int
   0016                     384 	.ds	5
   001B 02 11 10            385 	ljmp	_T1_int
                            386 ;--------------------------------------------------------
                            387 ; global & static initialisations
                            388 ;--------------------------------------------------------
                            389 	.area HOME    (CODE)
                            390 	.area GSINIT  (CODE)
                            391 	.area GSFINAL (CODE)
                            392 	.area GSINIT  (CODE)
                            393 	.globl __sdcc_gsinit_startup
                            394 	.globl __sdcc_program_startup
                            395 	.globl __start__stack
                            396 	.globl __mcs51_genXINIT
                            397 	.globl __mcs51_genXRAMCLEAR
                            398 	.globl __mcs51_genRAMCLEAR
                            399 ;	../kombi.c:70: unsigned char tasterpegel=0;
   007C 75 19 00            400 	mov	_tasterpegel,#0x00
                            401 ;	../kombi.c:71: __bit tastergetoggelt=0;
   007F C2 00               402 	clr	_tastergetoggelt
                            403 	.area GSFINAL (CODE)
   0081 02 00 1E            404 	ljmp	__sdcc_program_startup
                            405 ;--------------------------------------------------------
                            406 ; Home
                            407 ;--------------------------------------------------------
                            408 	.area HOME    (CODE)
                            409 	.area HOME    (CODE)
   001E                     410 __sdcc_program_startup:
   001E 12 0A F8            411 	lcall	_main
                            412 ;	return from main will lock up
   0021 80 FE               413 	sjmp .
                            414 ;--------------------------------------------------------
                            415 ; code
                            416 ;--------------------------------------------------------
                            417 	.area CSEG    (CODE)
                            418 ;------------------------------------------------------------
                            419 ;Allocation info for local variables in function 'main'
                            420 ;------------------------------------------------------------
                            421 ;n                         Allocated to registers r3 
                            422 ;m                         Allocated to registers r7 
                            423 ;delta                     Allocated to registers r5 
                            424 ;th                        Allocated to registers r2 r3 
                            425 ;change                    Allocated to registers r2 r3 
                            426 ;eis5temp                  Allocated to registers r2 r3 
                            427 ;korrektur                 Allocated to registers r4 
                            428 ;exponent                  Allocated to registers r4 r5 
                            429 ;eis5lux                   Allocated to registers r2 r3 
                            430 ;rest                      Allocated to registers r2 r4 
                            431 ;sloc0                     Allocated to stack - offset 1
                            432 ;------------------------------------------------------------
                            433 ;	../kombi.c:83: void main(void)
                            434 ;	-----------------------------------------
                            435 ;	 function main
                            436 ;	-----------------------------------------
   0AF8                     437 _main:
                    0002    438 	ar2 = 0x02
                    0003    439 	ar3 = 0x03
                    0004    440 	ar4 = 0x04
                    0005    441 	ar5 = 0x05
                    0006    442 	ar6 = 0x06
                    0007    443 	ar7 = 0x07
                    0000    444 	ar0 = 0x00
                    0001    445 	ar1 = 0x01
   0AF8 C0 1A               446 	push	_bp
   0AFA 85 81 1A            447 	mov	_bp,sp
   0AFD 05 81               448 	inc	sp
                            449 ;	../kombi.c:91: WDL=0xFF;
   0AFF 75 C1 FF            450 	mov	_WDL,#0xFF
                            451 ;	../kombi.c:92: EA=0;
   0B02 C2 AF               452 	clr	_IEN0_7
                            453 ;	../kombi.c:93: WDCON=0xE5;
   0B04 75 A7 E5            454 	mov	_WDCON,#0xE5
                            455 ;	../kombi.c:94: WFEED1=0xA5;
   0B07 75 C2 A5            456 	mov	_WFEED1,#0xA5
                            457 ;	../kombi.c:95: WFEED2=0x5A;
   0B0A 75 C3 5A            458 	mov	_WFEED2,#0x5A
                            459 ;	../kombi.c:96: EA=1;
   0B0D D2 AF               460 	setb	_IEN0_7
                            461 ;	../kombi.c:99: restart_hw();				// Hardware zuruecksetzen
   0B0F 12 1A 04            462 	lcall	_restart_hw
                            463 ;	../kombi.c:101: for (n=0;n<50;n++) {		// Warten bis Bus stabil, nach Busspannungswiederkehr
   0B12 7A 00               464 	mov	r2,#0x00
   0B14                     465 00185$:
   0B14 BA 32 00            466 	cjne	r2,#0x32,00250$
   0B17                     467 00250$:
   0B17 50 1A               468 	jnc	00188$
                            469 ;	../kombi.c:102: TR0=0;					// Timer 0 anhalten
   0B19 C2 8C               470 	clr	_TCON_4
                            471 ;	../kombi.c:103: TH0=eeprom[ADDRTAB+1];	// Timer 0 setzen mit phys. Adr. damit Geräte unterschiedlich beginnen zu senden
   0B1B 90 1D 17            472 	mov	dptr,#(_eeprom + 0x0017)
   0B1E E4                  473 	clr	a
   0B1F 93                  474 	movc	a,@a+dptr
   0B20 F5 8C               475 	mov	_TH0,a
                            476 ;	../kombi.c:104: TL0=eeprom[ADDRTAB+2];
   0B22 90 1D 18            477 	mov	dptr,#(_eeprom + 0x0018)
   0B25 E4                  478 	clr	a
   0B26 93                  479 	movc	a,@a+dptr
   0B27 F5 8A               480 	mov	_TL0,a
                            481 ;	../kombi.c:105: TF0=0;					// Überlauf-Flag zurücksetzen
   0B29 C2 8D               482 	clr	_TCON_5
                            483 ;	../kombi.c:106: TR0=1;					// Timer 0 starten
   0B2B D2 8C               484 	setb	_TCON_4
                            485 ;	../kombi.c:107: while(!TF0);
   0B2D                     486 00101$:
   0B2D 30 8D FD            487 	jnb	_TCON_5,00101$
                            488 ;	../kombi.c:101: for (n=0;n<50;n++) {		// Warten bis Bus stabil, nach Busspannungswiederkehr
   0B30 0A                  489 	inc	r2
   0B31 80 E1               490 	sjmp	00185$
   0B33                     491 00188$:
                            492 ;	../kombi.c:109: restart_app();				// Anwendungsspezifische Einstellungen zuruecksetzen
   0B33 12 09 F1            493 	lcall	_restart_app
                            494 ;	../kombi.c:112: EA=0;
   0B36 C2 AF               495 	clr	_IEN0_7
                            496 ;	../kombi.c:113: WFEED1=0xA5;
   0B38 75 C2 A5            497 	mov	_WFEED1,#0xA5
                            498 ;	../kombi.c:114: WFEED2=0x5A;
   0B3B 75 C3 5A            499 	mov	_WFEED2,#0x5A
                            500 ;	../kombi.c:115: EA=1;
   0B3E D2 AF               501 	setb	_IEN0_7
                            502 ;	../kombi.c:117: do {
   0B40                     503 00182$:
                            504 ;	../kombi.c:118: if (eeprom[0x0D]==0xFF && fb_state==0 && !connected  ) {	// Nur wenn im run-mode und statemachine idle
   0B40 90 1D 0D            505 	mov	dptr,#(_eeprom + 0x000d)
   0B43 E4                  506 	clr	a
   0B44 93                  507 	movc	a,@a+dptr
   0B45 FA                  508 	mov	r2,a
   0B46 BA FF 02            509 	cjne	r2,#0xFF,00253$
   0B49 80 03               510 	sjmp	00254$
   0B4B                     511 00253$:
   0B4B 02 0E E8            512 	ljmp	00164$
   0B4E                     513 00254$:
   0B4E E5 77               514 	mov	a,_fb_state
   0B50 60 03               515 	jz	00255$
   0B52 02 0E E8            516 	ljmp	00164$
   0B55                     517 00255$:
   0B55 30 0F 03            518 	jnb	_connected,00256$
   0B58 02 0E E8            519 	ljmp	00164$
   0B5B                     520 00256$:
                            521 ;	../kombi.c:121: ET1=0;									// statemachine stoppen
   0B5B C2 AB               522 	clr	_IEN0_3
                            523 ;	../kombi.c:122: switch (sequence) {
   0B5D 78 7F               524 	mov	r0,#_sequence
   0B5F B6 01 02            525 	cjne	@r0,#0x01,00257$
   0B62 80 19               526 	sjmp	00104$
   0B64                     527 00257$:
   0B64 78 7F               528 	mov	r0,#_sequence
   0B66 B6 02 02            529 	cjne	@r0,#0x02,00258$
   0B69 80 30               530 	sjmp	00109$
   0B6B                     531 00258$:
   0B6B 78 7F               532 	mov	r0,#_sequence
   0B6D B6 03 02            533 	cjne	@r0,#0x03,00259$
   0B70 80 49               534 	sjmp	00115$
   0B72                     535 00259$:
   0B72 78 7F               536 	mov	r0,#_sequence
   0B74 B6 04 03            537 	cjne	@r0,#0x04,00260$
   0B77 02 0C 3B            538 	ljmp	00122$
   0B7A                     539 00260$:
   0B7A 02 0D E3            540 	ljmp	00146$
                            541 ;	../kombi.c:123: case 1:
   0B7D                     542 00104$:
                            543 ;	../kombi.c:124: if((timer&0x3F) == 0x30) {	// nur alle 10 Sekunden wandeln
   0B7D 74 3F               544 	mov	a,#0x3F
   0B7F 55 0F               545 	anl	a,_timer
   0B81 FA                  546 	mov	r2,a
   0B82 7B 00               547 	mov	r3,#0x00
   0B84 BA 30 0F            548 	cjne	r2,#0x30,00108$
   0B87 BB 00 0C            549 	cjne	r3,#0x00,00108$
                            550 ;	../kombi.c:125: interrupted=0;
   0B8A C2 02               551 	clr	_interrupted
                            552 ;	../kombi.c:126: start_tempconversion();				// Konvertierung starten
   0B8C 12 0F FF            553 	lcall	_start_tempconversion
                            554 ;	../kombi.c:127: if (!interrupted) sequence=2;
   0B8F 20 02 04            555 	jb	_interrupted,00108$
   0B92 78 7F               556 	mov	r0,#_sequence
   0B94 76 02               557 	mov	@r0,#0x02
   0B96                     558 00108$:
                            559 ;	../kombi.c:129: ET1=1;						// statemachine starten
   0B96 D2 AB               560 	setb	_IEN0_3
                            561 ;	../kombi.c:130: break;
   0B98 02 0D E3            562 	ljmp	00146$
                            563 ;	../kombi.c:131: case 2:
   0B9B                     564 00109$:
                            565 ;	../kombi.c:132: if((timer&0x07) == 0x07) {	// nur ein mal pro Sekunde pollen
   0B9B 74 07               566 	mov	a,#0x07
   0B9D 55 0F               567 	anl	a,_timer
   0B9F FA                  568 	mov	r2,a
   0BA0 7B 00               569 	mov	r3,#0x00
   0BA2 BA 07 11            570 	cjne	r2,#0x07,00114$
   0BA5 BB 00 0E            571 	cjne	r3,#0x00,00114$
                            572 ;	../kombi.c:133: interrupted=0;
   0BA8 C2 02               573 	clr	_interrupted
                            574 ;	../kombi.c:134: if (ow_read_bit() && !interrupted) sequence=3;	// Konvertierung abgeschlossen
   0BAA 12 0F DA            575 	lcall	_ow_read_bit
   0BAD 50 07               576 	jnc	00114$
   0BAF 20 02 04            577 	jb	_interrupted,00114$
   0BB2 78 7F               578 	mov	r0,#_sequence
   0BB4 76 03               579 	mov	@r0,#0x03
   0BB6                     580 00114$:
                            581 ;	../kombi.c:136: ET1=1;						// statemachine starten
   0BB6 D2 AB               582 	setb	_IEN0_3
                            583 ;	../kombi.c:137: break;
   0BB8 02 0D E3            584 	ljmp	00146$
                            585 ;	../kombi.c:138: case 3:
   0BBB                     586 00115$:
                            587 ;	../kombi.c:139: interrupted=0;
   0BBB C2 02               588 	clr	_interrupted
                            589 ;	../kombi.c:145: th=read_temp();					// Temperatur einlesen
   0BBD 12 10 11            590 	lcall	_read_temp
   0BC0 AA 82               591 	mov	r2,dpl
   0BC2 AB 83               592 	mov	r3,dph
                            593 ;	../kombi.c:147: ET1=1;						// statemachine starten
   0BC4 D2 AB               594 	setb	_IEN0_3
                            595 ;	../kombi.c:148: korrektur = (signed char)eeprom[TEMPCORR];			// Parameter Korrekturwert Temperatur
   0BC6 90 1D CA            596 	mov	dptr,#(_eeprom + 0x00ca)
   0BC9 E4                  597 	clr	a
   0BCA 93                  598 	movc	a,@a+dptr
   0BCB FC                  599 	mov	r4,a
                            600 ;	../kombi.c:149: for (n=0;n<10;n++)th+=korrektur;
   0BCC 7D 0A               601 	mov	r5,#0x0A
   0BCE                     602 00191$:
   0BCE EC                  603 	mov	a,r4
   0BCF FE                  604 	mov	r6,a
   0BD0 33                  605 	rlc	a
   0BD1 95 E0               606 	subb	a,acc
   0BD3 FF                  607 	mov	r7,a
   0BD4 EE                  608 	mov	a,r6
   0BD5 2A                  609 	add	a,r2
   0BD6 FA                  610 	mov	r2,a
   0BD7 EF                  611 	mov	a,r7
   0BD8 3B                  612 	addc	a,r3
   0BD9 FB                  613 	mov	r3,a
   0BDA DD F2               614 	djnz	r5,00191$
                            615 ;	../kombi.c:151: if (!interrupted) {
   0BDC 30 02 03            616 	jnb	_interrupted,00270$
   0BDF 02 0D E3            617 	ljmp	00146$
   0BE2                     618 00270$:
                            619 ;	../kombi.c:152: temp=th;
   0BE2 8A 15               620 	mov	_temp,r2
   0BE4 8B 16               621 	mov	(_temp + 1),r3
                            622 ;	../kombi.c:153: if (temp != lasttemp) {
   0BE6 E5 13               623 	mov	a,_lasttemp
   0BE8 B5 15 07            624 	cjne	a,_temp,00271$
   0BEB E5 14               625 	mov	a,(_lasttemp + 1)
   0BED B5 16 02            626 	cjne	a,(_temp + 1),00271$
   0BF0 80 42               627 	sjmp	00119$
   0BF2                     628 00271$:
                            629 ;	../kombi.c:154: eis5temp=(temp>>3)&0x07FF;	// durch 8 teilen, da später Exponent 3 dazukommt
   0BF2 AA 15               630 	mov	r2,_temp
   0BF4 E5 16               631 	mov	a,(_temp + 1)
   0BF6 C4                  632 	swap	a
   0BF7 23                  633 	rl	a
   0BF8 CA                  634 	xch	a,r2
   0BF9 C4                  635 	swap	a
   0BFA 23                  636 	rl	a
   0BFB 54 1F               637 	anl	a,#0x1f
   0BFD 6A                  638 	xrl	a,r2
   0BFE CA                  639 	xch	a,r2
   0BFF 54 1F               640 	anl	a,#0x1f
   0C01 CA                  641 	xch	a,r2
   0C02 6A                  642 	xrl	a,r2
   0C03 CA                  643 	xch	a,r2
   0C04 30 E4 02            644 	jnb	acc.4,00272$
   0C07 44 E0               645 	orl	a,#0xe0
   0C09                     646 00272$:
   0C09 FB                  647 	mov	r3,a
   0C0A 53 03 07            648 	anl	ar3,#0x07
                            649 ;	../kombi.c:155: eis5temp=eis5temp+(0x18 << 8);
   0C0D 74 18               650 	mov	a,#0x18
   0C0F 2B                  651 	add	a,r3
   0C10 FB                  652 	mov	r3,a
                            653 ;	../kombi.c:156: if (temp<0) eis5temp+=0x8000;	// Vorzeichen
   0C11 E5 16               654 	mov	a,(_temp + 1)
   0C13 30 E7 04            655 	jnb	acc.7,00117$
   0C16 74 80               656 	mov	a,#0x80
   0C18 2B                  657 	add	a,r3
   0C19 FB                  658 	mov	r3,a
   0C1A                     659 00117$:
                            660 ;	../kombi.c:157: write_obj_value(1,eis5temp);
   0C1A C0 02               661 	push	ar2
   0C1C C0 03               662 	push	ar3
   0C1E 75 82 01            663 	mov	dpl,#0x01
   0C21 12 07 86            664 	lcall	_write_obj_value
   0C24 15 81               665 	dec	sp
   0C26 15 81               666 	dec	sp
                            667 ;	../kombi.c:159: schwelle(6);             // Temperaturschwellen prüfen und ggf. reagieren
   0C28 75 82 06            668 	mov	dpl,#0x06
   0C2B 12 01 11            669 	lcall	_schwelle
                            670 ;	../kombi.c:160: schwelle(7);
   0C2E 75 82 07            671 	mov	dpl,#0x07
   0C31 12 01 11            672 	lcall	_schwelle
   0C34                     673 00119$:
                            674 ;	../kombi.c:162: sequence=4;
   0C34 78 7F               675 	mov	r0,#_sequence
   0C36 76 04               676 	mov	@r0,#0x04
                            677 ;	../kombi.c:164: break;
   0C38 02 0D E3            678 	ljmp	00146$
                            679 ;	../kombi.c:165: case 4:				// Helligkeitswert konvertieren
   0C3B                     680 00122$:
                            681 ;	../kombi.c:166: interrupted=0;
   0C3B C2 02               682 	clr	_interrupted
                            683 ;	../kombi.c:167: Get_ADC(3);		// ADC-Wert holen
   0C3D 75 82 03            684 	mov	dpl,#0x03
   0C40 12 00 F4            685 	lcall	_Get_ADC
                            686 ;	../kombi.c:168: ET1=1;			// statemachine starten
   0C43 D2 AB               687 	setb	_IEN0_3
                            688 ;	../kombi.c:169: if (!interrupted) {
   0C45 30 02 03            689 	jnb	_interrupted,00274$
   0C48 02 0D E3            690 	ljmp	00146$
   0C4B                     691 00274$:
                            692 ;	../kombi.c:171: if (HighByte>=112) {
   0C4B 74 90               693 	mov	a,#0x100 - 0x70
   0C4D 25 09               694 	add	a,_HighByte
   0C4F 50 09               695 	jnc	00137$
                            696 ;	../kombi.c:172: lux=65535;
   0C51 75 17 FF            697 	mov	_lux,#0xFF
   0C54 75 18 FF            698 	mov	(_lux + 1),#0xFF
   0C57 02 0D 5B            699 	ljmp	00138$
   0C5A                     700 00137$:
                            701 ;	../kombi.c:185: lux=2;
   0C5A 75 17 02            702 	mov	_lux,#0x02
   0C5D E4                  703 	clr	a
   0C5E F5 18               704 	mov	(_lux + 1),a
                            705 ;	../kombi.c:186: while (HighByte >= logtable[n]) {
   0C60 7A 00               706 	mov	r2,#0x00
   0C62                     707 00123$:
   0C62 EA                  708 	mov	a,r2
   0C63 90 1B 7E            709 	mov	dptr,#_logtable
   0C66 93                  710 	movc	a,@a+dptr
   0C67 FB                  711 	mov	r3,a
   0C68 C3                  712 	clr	c
   0C69 E5 09               713 	mov	a,_HighByte
   0C6B 9B                  714 	subb	a,r3
   0C6C 40 0E               715 	jc	00246$
                            716 ;	../kombi.c:187: n++;
   0C6E 0A                  717 	inc	r2
                            718 ;	../kombi.c:188: lux=lux*2;
   0C6F E5 18               719 	mov	a,(_lux + 1)
   0C71 C5 17               720 	xch	a,_lux
   0C73 25 E0               721 	add	a,acc
   0C75 C5 17               722 	xch	a,_lux
   0C77 33                  723 	rlc	a
   0C78 F5 18               724 	mov	(_lux + 1),a
   0C7A 80 E6               725 	sjmp	00123$
   0C7C                     726 00246$:
                            727 ;	../kombi.c:190: if (n<=1) lux=0;
   0C7C EA                  728 	mov	a,r2
   0C7D FB                  729 	mov	r3,a
   0C7E 24 FE               730 	add	a,#0xff - 0x01
   0C80 40 05               731 	jc	00127$
   0C82 E4                  732 	clr	a
   0C83 F5 17               733 	mov	_lux,a
   0C85 F5 18               734 	mov	(_lux + 1),a
   0C87                     735 00127$:
                            736 ;	../kombi.c:193: rest=HighByte-logtable[n-1];
   0C87 AA 09               737 	mov	r2,_HighByte
   0C89 7C 00               738 	mov	r4,#0x00
   0C8B EB                  739 	mov	a,r3
   0C8C 14                  740 	dec	a
   0C8D 90 1B 7E            741 	mov	dptr,#_logtable
   0C90 93                  742 	movc	a,@a+dptr
   0C91 FD                  743 	mov	r5,a
   0C92 FE                  744 	mov	r6,a
   0C93 7F 00               745 	mov	r7,#0x00
   0C95 EA                  746 	mov	a,r2
   0C96 C3                  747 	clr	c
   0C97 9E                  748 	subb	a,r6
   0C98 FA                  749 	mov	r2,a
   0C99 EC                  750 	mov	a,r4
   0C9A 9F                  751 	subb	a,r7
   0C9B FC                  752 	mov	r4,a
                            753 ;	../kombi.c:194: delta=logtable[n]-logtable[n-1];
   0C9C EB                  754 	mov	a,r3
   0C9D 90 1B 7E            755 	mov	dptr,#_logtable
   0CA0 93                  756 	movc	a,@a+dptr
   0CA1 FE                  757 	mov	r6,a
   0CA2 C3                  758 	clr	c
   0CA3 9D                  759 	subb	a,r5
   0CA4 FD                  760 	mov	r5,a
                            761 ;	../kombi.c:200: if (n<11) m=n+2; else m=n-2;
   0CA5 A8 1A               762 	mov	r0,_bp
   0CA7 08                  763 	inc	r0
   0CA8 BB 0B 00            764 	cjne	r3,#0x0B,00278$
   0CAB                     765 00278$:
   0CAB E4                  766 	clr	a
   0CAC 33                  767 	rlc	a
   0CAD F6                  768 	mov	@r0,a
   0CAE A8 1A               769 	mov	r0,_bp
   0CB0 08                  770 	inc	r0
   0CB1 E6                  771 	mov	a,@r0
   0CB2 60 06               772 	jz	00129$
   0CB4 74 02               773 	mov	a,#0x02
   0CB6 2B                  774 	add	a,r3
   0CB7 FF                  775 	mov	r7,a
   0CB8 80 04               776 	sjmp	00130$
   0CBA                     777 00129$:
   0CBA EB                  778 	mov	a,r3
   0CBB 24 FE               779 	add	a,#0xfe
   0CBD FF                  780 	mov	r7,a
   0CBE                     781 00130$:
                            782 ;	../kombi.c:201: rest=rest<<m;
   0CBE C0 03               783 	push	ar3
   0CC0 8F F0               784 	mov	b,r7
   0CC2 05 F0               785 	inc	b
   0CC4 80 06               786 	sjmp	00281$
   0CC6                     787 00280$:
   0CC6 EA                  788 	mov	a,r2
   0CC7 2A                  789 	add	a,r2
   0CC8 FA                  790 	mov	r2,a
   0CC9 EC                  791 	mov	a,r4
   0CCA 33                  792 	rlc	a
   0CCB FC                  793 	mov	r4,a
   0CCC                     794 00281$:
   0CCC D5 F0 F7            795 	djnz	b,00280$
                            796 ;	../kombi.c:202: rest=_divuint(rest,delta);
   0CCF 7F 00               797 	mov	r7,#0x00
   0CD1 C0 05               798 	push	ar5
   0CD3 C0 07               799 	push	ar7
   0CD5 C0 05               800 	push	ar5
   0CD7 C0 07               801 	push	ar7
   0CD9 8A 82               802 	mov	dpl,r2
   0CDB 8C 83               803 	mov	dph,r4
   0CDD 12 10 AC            804 	lcall	__divuint
   0CE0 AB 82               805 	mov	r3,dpl
   0CE2 AE 83               806 	mov	r6,dph
   0CE4 15 81               807 	dec	sp
   0CE6 15 81               808 	dec	sp
   0CE8 D0 07               809 	pop	ar7
   0CEA D0 05               810 	pop	ar5
   0CEC 8B 02               811 	mov	ar2,r3
   0CEE 8E 04               812 	mov	ar4,r6
                            813 ;	../kombi.c:203: if (n<11) lux+=rest; else lux+=rest<<4;
   0CF0 D0 03               814 	pop	ar3
   0CF2 A8 1A               815 	mov	r0,_bp
   0CF4 08                  816 	inc	r0
   0CF5 E6                  817 	mov	a,@r0
   0CF6 60 0C               818 	jz	00132$
   0CF8 EA                  819 	mov	a,r2
   0CF9 25 17               820 	add	a,_lux
   0CFB F5 17               821 	mov	_lux,a
   0CFD EC                  822 	mov	a,r4
   0CFE 35 18               823 	addc	a,(_lux + 1)
   0D00 F5 18               824 	mov	(_lux + 1),a
   0D02 80 18               825 	sjmp	00133$
   0D04                     826 00132$:
   0D04 EC                  827 	mov	a,r4
   0D05 C4                  828 	swap	a
   0D06 54 F0               829 	anl	a,#0xf0
   0D08 CA                  830 	xch	a,r2
   0D09 C4                  831 	swap	a
   0D0A CA                  832 	xch	a,r2
   0D0B 6A                  833 	xrl	a,r2
   0D0C CA                  834 	xch	a,r2
   0D0D 54 F0               835 	anl	a,#0xf0
   0D0F CA                  836 	xch	a,r2
   0D10 6A                  837 	xrl	a,r2
   0D11 FC                  838 	mov	r4,a
   0D12 EA                  839 	mov	a,r2
   0D13 25 17               840 	add	a,_lux
   0D15 F5 17               841 	mov	_lux,a
   0D17 EC                  842 	mov	a,r4
   0D18 35 18               843 	addc	a,(_lux + 1)
   0D1A F5 18               844 	mov	(_lux + 1),a
   0D1C                     845 00133$:
                            846 ;	../kombi.c:206: if (n<7) lux+=(_divuint(LowByte<<(n+2),delta)>>8);
   0D1C BB 07 00            847 	cjne	r3,#0x07,00283$
   0D1F                     848 00283$:
   0D1F 50 3A               849 	jnc	00138$
   0D21 AA 08               850 	mov	r2,_LowByte
   0D23 E4                  851 	clr	a
   0D24 FC                  852 	mov	r4,a
   0D25 FE                  853 	mov	r6,a
   0D26 74 02               854 	mov	a,#0x02
   0D28 2B                  855 	add	a,r3
   0D29 FB                  856 	mov	r3,a
   0D2A E4                  857 	clr	a
   0D2B 3E                  858 	addc	a,r6
   0D2C FE                  859 	mov	r6,a
   0D2D 8B F0               860 	mov	b,r3
   0D2F 05 F0               861 	inc	b
   0D31 80 06               862 	sjmp	00286$
   0D33                     863 00285$:
   0D33 EA                  864 	mov	a,r2
   0D34 2A                  865 	add	a,r2
   0D35 FA                  866 	mov	r2,a
   0D36 EC                  867 	mov	a,r4
   0D37 33                  868 	rlc	a
   0D38 FC                  869 	mov	r4,a
   0D39                     870 00286$:
   0D39 D5 F0 F7            871 	djnz	b,00285$
   0D3C C0 05               872 	push	ar5
   0D3E C0 07               873 	push	ar7
   0D40 8A 82               874 	mov	dpl,r2
   0D42 8C 83               875 	mov	dph,r4
   0D44 12 10 AC            876 	lcall	__divuint
   0D47 AB 83               877 	mov	r3,dph
   0D49 15 81               878 	dec	sp
   0D4B 15 81               879 	dec	sp
   0D4D 8B 02               880 	mov	ar2,r3
   0D4F 7B 00               881 	mov	r3,#0x00
   0D51 EA                  882 	mov	a,r2
   0D52 25 17               883 	add	a,_lux
   0D54 F5 17               884 	mov	_lux,a
   0D56 EB                  885 	mov	a,r3
   0D57 35 18               886 	addc	a,(_lux + 1)
   0D59 F5 18               887 	mov	(_lux + 1),a
   0D5B                     888 00138$:
                            889 ;	../kombi.c:209: if (lux!=lastlux) {
   0D5B E5 11               890 	mov	a,_lastlux
   0D5D B5 17 07            891 	cjne	a,_lux,00287$
   0D60 E5 12               892 	mov	a,(_lastlux + 1)
   0D62 B5 18 02            893 	cjne	a,(_lux + 1),00287$
   0D65 80 72               894 	sjmp	00143$
   0D67                     895 00287$:
                            896 ;	../kombi.c:212: eis5lux=lux>>1;
   0D67 AA 17               897 	mov	r2,_lux
   0D69 E5 18               898 	mov	a,(_lux + 1)
   0D6B C3                  899 	clr	c
   0D6C 13                  900 	rrc	a
   0D6D CA                  901 	xch	a,r2
   0D6E 13                  902 	rrc	a
   0D6F CA                  903 	xch	a,r2
   0D70 FB                  904 	mov	r3,a
                            905 ;	../kombi.c:213: eis5lux+=lux>>2;
   0D71 AC 17               906 	mov	r4,_lux
   0D73 E5 18               907 	mov	a,(_lux + 1)
   0D75 C3                  908 	clr	c
   0D76 13                  909 	rrc	a
   0D77 CC                  910 	xch	a,r4
   0D78 13                  911 	rrc	a
   0D79 CC                  912 	xch	a,r4
   0D7A C3                  913 	clr	c
   0D7B 13                  914 	rrc	a
   0D7C CC                  915 	xch	a,r4
   0D7D 13                  916 	rrc	a
   0D7E CC                  917 	xch	a,r4
   0D7F FD                  918 	mov	r5,a
   0D80 EC                  919 	mov	a,r4
   0D81 2A                  920 	add	a,r2
   0D82 FA                  921 	mov	r2,a
   0D83 ED                  922 	mov	a,r5
   0D84 3B                  923 	addc	a,r3
   0D85 FB                  924 	mov	r3,a
                            925 ;	../kombi.c:214: eis5lux+=lux>>5;
   0D86 AC 17               926 	mov	r4,_lux
   0D88 E5 18               927 	mov	a,(_lux + 1)
   0D8A C4                  928 	swap	a
   0D8B 03                  929 	rr	a
   0D8C CC                  930 	xch	a,r4
   0D8D C4                  931 	swap	a
   0D8E 03                  932 	rr	a
   0D8F 54 07               933 	anl	a,#0x07
   0D91 6C                  934 	xrl	a,r4
   0D92 CC                  935 	xch	a,r4
   0D93 54 07               936 	anl	a,#0x07
   0D95 CC                  937 	xch	a,r4
   0D96 6C                  938 	xrl	a,r4
   0D97 CC                  939 	xch	a,r4
   0D98 FD                  940 	mov	r5,a
   0D99 EC                  941 	mov	a,r4
   0D9A 2A                  942 	add	a,r2
   0D9B FA                  943 	mov	r2,a
   0D9C ED                  944 	mov	a,r5
   0D9D 3B                  945 	addc	a,r3
   0D9E FB                  946 	mov	r3,a
                            947 ;	../kombi.c:217: while (eis5lux > 0x07FF) {	// Exponent erhöhen falls Mantisse zu groß
   0D9F 7C 00               948 	mov	r4,#0x00
   0DA1 7D 38               949 	mov	r5,#0x38
   0DA3                     950 00139$:
   0DA3 C3                  951 	clr	c
   0DA4 74 FF               952 	mov	a,#0xFF
   0DA6 9A                  953 	subb	a,r2
   0DA7 74 07               954 	mov	a,#0x07
   0DA9 9B                  955 	subb	a,r3
   0DAA 50 0D               956 	jnc	00141$
                            957 ;	../kombi.c:218: eis5lux=eis5lux>>1;
   0DAC EB                  958 	mov	a,r3
   0DAD C3                  959 	clr	c
   0DAE 13                  960 	rrc	a
   0DAF CA                  961 	xch	a,r2
   0DB0 13                  962 	rrc	a
   0DB1 CA                  963 	xch	a,r2
   0DB2 FB                  964 	mov	r3,a
                            965 ;	../kombi.c:219: exponent+=0x0800;
   0DB3 74 08               966 	mov	a,#0x08
   0DB5 2D                  967 	add	a,r5
   0DB6 FD                  968 	mov	r5,a
   0DB7 80 EA               969 	sjmp	00139$
   0DB9                     970 00141$:
                            971 ;	../kombi.c:221: eis5lux+=exponent;
   0DB9 EC                  972 	mov	a,r4
   0DBA 2A                  973 	add	a,r2
   0DBB FA                  974 	mov	r2,a
   0DBC ED                  975 	mov	a,r5
   0DBD 3B                  976 	addc	a,r3
   0DBE FB                  977 	mov	r3,a
                            978 ;	../kombi.c:223: write_obj_value(0,eis5lux);		// Lux Wert im userram speichern
   0DBF C0 02               979 	push	ar2
   0DC1 C0 03               980 	push	ar3
   0DC3 75 82 00            981 	mov	dpl,#0x00
   0DC6 12 07 86            982 	lcall	_write_obj_value
   0DC9 15 81               983 	dec	sp
   0DCB 15 81               984 	dec	sp
                            985 ;	../kombi.c:224: schwelle(4);                           // Helligkeitsschwellen 2 und 3
   0DCD 75 82 04            986 	mov	dpl,#0x04
   0DD0 12 01 11            987 	lcall	_schwelle
                            988 ;	../kombi.c:225: schwelle(5);
   0DD3 75 82 05            989 	mov	dpl,#0x05
   0DD6 12 01 11            990 	lcall	_schwelle
   0DD9                     991 00143$:
                            992 ;	../kombi.c:227: schwelle(3);      // Helligkeitsschwelle 1 trotzdem jedes mal weil es auch Nachregelung sein könnte
   0DD9 75 82 03            993 	mov	dpl,#0x03
   0DDC 12 01 11            994 	lcall	_schwelle
                            995 ;	../kombi.c:228: sequence=1;
   0DDF 78 7F               996 	mov	r0,#_sequence
   0DE1 76 01               997 	mov	@r0,#0x01
                            998 ;	../kombi.c:231: }
   0DE3                     999 00146$:
                           1000 ;	../kombi.c:236: change=((eeprom[TEMPPARAM]&0x70)>>4)*100;	// wenn change=0 wird nicht gesendet
   0DE3 90 1D D2           1001 	mov	dptr,#(_eeprom + 0x00d2)
   0DE6 E4                 1002 	clr	a
   0DE7 93                 1003 	movc	a,@a+dptr
   0DE8 54 70              1004 	anl	a,#0x70
   0DEA C4                 1005 	swap	a
   0DEB 54 0F              1006 	anl	a,#0x0f
   0DED 75 F0 64           1007 	mov	b,#0x64
   0DF0 A4                 1008 	mul	ab
                           1009 ;	../kombi.c:237: if(change) {
   0DF1 FA                 1010 	mov	r2,a
   0DF2 AB F0              1011 	mov	r3,b
   0DF4 4B                 1012 	orl	a,r3
   0DF5 60 49              1013 	jz	00151$
                           1014 ;	../kombi.c:238: if (((temp + change)<= lasttemp) || ((lasttemp + change)<= temp)) {	// bei Änderung um 1-3K
   0DF7 EA                 1015 	mov	a,r2
   0DF8 25 15              1016 	add	a,_temp
   0DFA FC                 1017 	mov	r4,a
   0DFB EB                 1018 	mov	a,r3
   0DFC 35 16              1019 	addc	a,(_temp + 1)
   0DFE FD                 1020 	mov	r5,a
   0DFF C3                 1021 	clr	c
   0E00 E5 13              1022 	mov	a,_lasttemp
   0E02 9C                 1023 	subb	a,r4
   0E03 E5 14              1024 	mov	a,(_lasttemp + 1)
   0E05 64 80              1025 	xrl	a,#0x80
   0E07 8D F0              1026 	mov	b,r5
   0E09 63 F0 80           1027 	xrl	b,#0x80
   0E0C 95 F0              1028 	subb	a,b
   0E0E 50 19              1029 	jnc	00147$
   0E10 EA                 1030 	mov	a,r2
   0E11 25 13              1031 	add	a,_lasttemp
   0E13 FC                 1032 	mov	r4,a
   0E14 EB                 1033 	mov	a,r3
   0E15 35 14              1034 	addc	a,(_lasttemp + 1)
   0E17 FD                 1035 	mov	r5,a
   0E18 C3                 1036 	clr	c
   0E19 E5 15              1037 	mov	a,_temp
   0E1B 9C                 1038 	subb	a,r4
   0E1C E5 16              1039 	mov	a,(_temp + 1)
   0E1E 64 80              1040 	xrl	a,#0x80
   0E20 8D F0              1041 	mov	b,r5
   0E22 63 F0 80           1042 	xrl	b,#0x80
   0E25 95 F0              1043 	subb	a,b
   0E27 40 17              1044 	jc	00151$
   0E29                    1045 00147$:
                           1046 ;	../kombi.c:239: WRITE_DELAY_RECORD(1,1,1,timer+1)
   0E29 74 01              1047 	mov	a,#0x01
   0E2B F5 2D              1048 	mov	(_delrec + 0x0004),a
   0E2D F5 2E              1049 	mov	(_delrec + 0x0005),a
   0E2F 25 0F              1050 	add	a,_timer
   0E31 FC                 1051 	mov	r4,a
   0E32 E4                 1052 	clr	a
   0E33 35 10              1053 	addc	a,(_timer + 1)
   0E35 FD                 1054 	mov	r5,a
   0E36 8C 2F              1055 	mov	(_delrec + 0x0006),r4
   0E38 8D 30              1056 	mov	((_delrec + 0x0006) + 1),r5
                           1057 ;	../kombi.c:240: lasttemp=temp;
   0E3A 85 15 13           1058 	mov	_lasttemp,_temp
   0E3D 85 16 14           1059 	mov	(_lasttemp + 1),(_temp + 1)
   0E40                    1060 00151$:
                           1061 ;	../kombi.c:245: if (eeprom[LUXPARAM] & 0x70) {	// wenn Lux senden bei Änderung aktiv
   0E40 90 1D D3           1062 	mov	dptr,#(_eeprom + 0x00d3)
   0E43 E4                 1063 	clr	a
   0E44 93                 1064 	movc	a,@a+dptr
   0E45 FC                 1065 	mov	r4,a
   0E46 54 70              1066 	anl	a,#0x70
   0E48 70 03              1067 	jnz	00292$
   0E4A 02 0E D3           1068 	ljmp	00160$
   0E4D                    1069 00292$:
                           1070 ;	../kombi.c:246: change=_divuint(lastlux,luxchange[(eeprom[LUXPARAM]&0x70)>>4]);
   0E4D 90 1D D3           1071 	mov	dptr,#(_eeprom + 0x00d3)
   0E50 E4                 1072 	clr	a
   0E51 93                 1073 	movc	a,@a+dptr
   0E52 54 70              1074 	anl	a,#0x70
   0E54 C4                 1075 	swap	a
   0E55 54 0F              1076 	anl	a,#0x0f
   0E57 90 1B 8D           1077 	mov	dptr,#_luxchange
   0E5A 93                 1078 	movc	a,@a+dptr
   0E5B FC                 1079 	mov	r4,a
   0E5C 7D 00              1080 	mov	r5,#0x00
   0E5E C0 04              1081 	push	ar4
   0E60 C0 05              1082 	push	ar5
   0E62 85 11 82           1083 	mov	dpl,_lastlux
   0E65 85 12 83           1084 	mov	dph,(_lastlux + 1)
   0E68 12 10 AC           1085 	lcall	__divuint
   0E6B AC 82              1086 	mov	r4,dpl
   0E6D AD 83              1087 	mov	r5,dph
   0E6F 15 81              1088 	dec	sp
   0E71 15 81              1089 	dec	sp
   0E73 8C 02              1090 	mov	ar2,r4
   0E75 8D 03              1091 	mov	ar3,r5
                           1092 ;	../kombi.c:247: if (change==0) change=1;		// mindestens 1 Lux Änderung
   0E77 EA                 1093 	mov	a,r2
   0E78 4B                 1094 	orl	a,r3
   0E79 70 03              1095 	jnz	00153$
   0E7B 7A 01              1096 	mov	r2,#0x01
   0E7D FB                 1097 	mov	r3,a
   0E7E                    1098 00153$:
                           1099 ;	../kombi.c:248: if ((lux>lastlux && (lux-lastlux)>=change) || (lux<lastlux && (lastlux-lux)>=change)) {
   0E7E C3                 1100 	clr	c
   0E7F E5 11              1101 	mov	a,_lastlux
   0E81 95 17              1102 	subb	a,_lux
   0E83 E5 12              1103 	mov	a,(_lastlux + 1)
   0E85 95 18              1104 	subb	a,(_lux + 1)
   0E87 50 16              1105 	jnc	00158$
   0E89 E5 17              1106 	mov	a,_lux
   0E8B C3                 1107 	clr	c
   0E8C 95 11              1108 	subb	a,_lastlux
   0E8E FC                 1109 	mov	r4,a
   0E8F E5 18              1110 	mov	a,(_lux + 1)
   0E91 95 12              1111 	subb	a,(_lastlux + 1)
   0E93 FD                 1112 	mov	r5,a
   0E94 8A 06              1113 	mov	ar6,r2
   0E96 8B 07              1114 	mov	ar7,r3
   0E98 C3                 1115 	clr	c
   0E99 EC                 1116 	mov	a,r4
   0E9A 9E                 1117 	subb	a,r6
   0E9B ED                 1118 	mov	a,r5
   0E9C 9F                 1119 	subb	a,r7
   0E9D 50 1D              1120 	jnc	00154$
   0E9F                    1121 00158$:
   0E9F C3                 1122 	clr	c
   0EA0 E5 17              1123 	mov	a,_lux
   0EA2 95 11              1124 	subb	a,_lastlux
   0EA4 E5 18              1125 	mov	a,(_lux + 1)
   0EA6 95 12              1126 	subb	a,(_lastlux + 1)
   0EA8 50 29              1127 	jnc	00160$
   0EAA E5 11              1128 	mov	a,_lastlux
   0EAC C3                 1129 	clr	c
   0EAD 95 17              1130 	subb	a,_lux
   0EAF FC                 1131 	mov	r4,a
   0EB0 E5 12              1132 	mov	a,(_lastlux + 1)
   0EB2 95 18              1133 	subb	a,(_lux + 1)
   0EB4 FD                 1134 	mov	r5,a
   0EB5 C3                 1135 	clr	c
   0EB6 EC                 1136 	mov	a,r4
   0EB7 9A                 1137 	subb	a,r2
   0EB8 ED                 1138 	mov	a,r5
   0EB9 9B                 1139 	subb	a,r3
   0EBA 40 17              1140 	jc	00160$
   0EBC                    1141 00154$:
                           1142 ;	../kombi.c:249: WRITE_DELAY_RECORD(0,1,1,timer+1)
   0EBC 74 01              1143 	mov	a,#0x01
   0EBE F5 29              1144 	mov	_delrec,a
   0EC0 F5 2A              1145 	mov	(_delrec + 0x0001),a
   0EC2 25 0F              1146 	add	a,_timer
   0EC4 FA                 1147 	mov	r2,a
   0EC5 E4                 1148 	clr	a
   0EC6 35 10              1149 	addc	a,(_timer + 1)
   0EC8 FB                 1150 	mov	r3,a
   0EC9 8A 2B              1151 	mov	(_delrec + 0x0002),r2
   0ECB 8B 2C              1152 	mov	((_delrec + 0x0002) + 1),r3
                           1153 ;	../kombi.c:250: lastlux=lux;
   0ECD 85 17 11           1154 	mov	_lastlux,_lux
   0ED0 85 18 12           1155 	mov	(_lastlux + 1),(_lux + 1)
   0ED3                    1156 00160$:
                           1157 ;	../kombi.c:255: schwelle(8);     // Verknüpfungsobjekte
   0ED3 75 82 08           1158 	mov	dpl,#0x08
   0ED6 12 01 11           1159 	lcall	_schwelle
                           1160 ;	../kombi.c:256: schwelle(9);
   0ED9 75 82 09           1161 	mov	dpl,#0x09
   0EDC 12 01 11           1162 	lcall	_schwelle
                           1163 ;	../kombi.c:258: if(RTCCON>=0x80) delay_timer();	// Realtime clock Überlauf
   0EDF 74 80              1164 	mov	a,#0x100 - 0x80
   0EE1 25 D1              1165 	add	a,_RTCCON
   0EE3 50 03              1166 	jnc	00164$
   0EE5 12 08 39           1167 	lcall	_delay_timer
   0EE8                    1168 00164$:
                           1169 ;	../kombi.c:263: EA=0;
   0EE8 C2 AF              1170 	clr	_IEN0_7
                           1171 ;	../kombi.c:264: WFEED1=0xA5;
   0EEA 75 C2 A5           1172 	mov	_WFEED1,#0xA5
                           1173 ;	../kombi.c:265: WFEED2=0x5A;
   0EED 75 C3 5A           1174 	mov	_WFEED2,#0x5A
                           1175 ;	../kombi.c:266: EA=1;
   0EF0 D2 AF              1176 	setb	_IEN0_7
                           1177 ;	../kombi.c:268: if(tel_arrived) process_tel();			// empfangenes Telegramm abarbeiten
   0EF2 30 07 03           1178 	jnb	_tel_arrived,00168$
   0EF5 12 17 4E           1179 	lcall	_process_tel
   0EF8                    1180 00168$:
                           1181 ;	../kombi.c:272: TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
   0EF8 D2 97              1182 	setb	_P1_7
                           1183 ;	../kombi.c:273: if(!TASTER){ // Taster gedrückt
   0EFA 20 97 14           1184 	jb	_P1_7,00178$
                           1185 ;	../kombi.c:274: if(tasterpegel<255)	tasterpegel++;
   0EFD 74 01              1186 	mov	a,#0x100 - 0xFF
   0EFF 25 19              1187 	add	a,_tasterpegel
   0F01 40 04              1188 	jc	00172$
   0F03 05 19              1189 	inc	_tasterpegel
   0F05 80 14              1190 	sjmp	00179$
   0F07                    1191 00172$:
                           1192 ;	../kombi.c:276: if(!tastergetoggelt)status60^=0x81;	// Prog-Bit und Parity-Bit im system_state toggeln
   0F07 20 00 03           1193 	jb	_tastergetoggelt,00170$
   0F0A 63 7B 81           1194 	xrl	_status60,#0x81
   0F0D                    1195 00170$:
                           1196 ;	../kombi.c:277: tastergetoggelt=1;
   0F0D D2 00              1197 	setb	_tastergetoggelt
   0F0F 80 0A              1198 	sjmp	00179$
   0F11                    1199 00178$:
                           1200 ;	../kombi.c:281: if(tasterpegel>0) tasterpegel--;
   0F11 E5 19              1201 	mov	a,_tasterpegel
   0F13 60 04              1202 	jz	00175$
   0F15 15 19              1203 	dec	_tasterpegel
   0F17 80 02              1204 	sjmp	00179$
   0F19                    1205 00175$:
                           1206 ;	../kombi.c:282: else tastergetoggelt=0;
   0F19 C2 00              1207 	clr	_tastergetoggelt
   0F1B                    1208 00179$:
                           1209 ;	../kombi.c:284: TASTER=!(status60 & 0x01);	// LED entsprechend Prog-Bit schalten (low=LED an)
   0F1B E5 7B              1210 	mov	a,_status60
   0F1D 54 01              1211 	anl	a,#0x01
   0F1F FA                 1212 	mov	r2,a
   0F20 B4 01 00           1213 	cjne	a,#0x01,00304$
   0F23                    1214 00304$:
   0F23 92 97              1215 	mov	_P1_7,c
                           1216 ;	../kombi.c:285: if (fb_state==0) for(n=0;n<100;n++) {}	// etwas zeit zum leuchten, wenn Hauptschleife nicht aktiv
   0F25 E5 77              1217 	mov	a,_fb_state
   0F27 60 03              1218 	jz	00305$
   0F29 02 0B 40           1219 	ljmp	00182$
   0F2C                    1220 00305$:
   0F2C 7A 64              1221 	mov	r2,#0x64
   0F2E                    1222 00194$:
   0F2E DA FE              1223 	djnz	r2,00194$
                           1224 ;	../kombi.c:286: } while(1);
   0F30 02 0B 40           1225 	ljmp	00182$
   0F33 85 1A 81           1226 	mov	sp,_bp
   0F36 D0 1A              1227 	pop	_bp
   0F38 22                 1228 	ret
                           1229 	.area CSEG    (CODE)
                           1230 	.area CONST   (CODE)
   1B7E                    1231 _logtable:
   1B7E 00                 1232 	.db #0x00
   1B7F 09                 1233 	.db #0x09
   1B80 11                 1234 	.db #0x11
   1B81 1B                 1235 	.db #0x1B
   1B82 28                 1236 	.db #0x28
   1B83 35                 1237 	.db #0x35
   1B84 42                 1238 	.db #0x42
   1B85 4F                 1239 	.db #0x4F
   1B86 58                 1240 	.db #0x58
   1B87 60                 1241 	.db #0x60
   1B88 65                 1242 	.db #0x65
   1B89 6A                 1243 	.db #0x6A
   1B8A 6D                 1244 	.db #0x6D
   1B8B 70                 1245 	.db #0x70
   1B8C FF                 1246 	.db #0xFF
   1B8D                    1247 _luxchange:
   1B8D 64                 1248 	.db #0x64
   1B8E 14                 1249 	.db #0x14
   1B8F 0A                 1250 	.db #0x0A
   1B90 05                 1251 	.db #0x05
   1B91 03                 1252 	.db #0x03
                           1253 	.area XINIT   (CODE)
                           1254 	.area CABS    (ABS,CODE)
