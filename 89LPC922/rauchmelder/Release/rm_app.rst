                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
                              4 ; This file was generated Mon Jun 25 19:44:12 2012
                              5 ;--------------------------------------------------------
                              6 	.module rm_app
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _P3_1
                             13 	.globl _P3_0
                             14 	.globl _P1_7
                             15 	.globl _P1_6
                             16 	.globl _P1_5
                             17 	.globl _P1_4
                             18 	.globl _P1_3
                             19 	.globl _P1_2
                             20 	.globl _P1_1
                             21 	.globl _P1_0
                             22 	.globl _P0_7
                             23 	.globl _P0_6
                             24 	.globl _P0_5
                             25 	.globl _P0_4
                             26 	.globl _P0_3
                             27 	.globl _P0_2
                             28 	.globl _P0_1
                             29 	.globl _P0_0
                             30 	.globl _I2CON_0
                             31 	.globl _I2CON_2
                             32 	.globl _I2CON_3
                             33 	.globl _I2CON_4
                             34 	.globl _I2CON_5
                             35 	.globl _I2CON_6
                             36 	.globl _SCON_7
                             37 	.globl _SCON_6
                             38 	.globl _SCON_5
                             39 	.globl _SCON_4
                             40 	.globl _SCON_3
                             41 	.globl _SCON_2
                             42 	.globl _SCON_1
                             43 	.globl _SCON_0
                             44 	.globl _IP0_0
                             45 	.globl _IP0_1
                             46 	.globl _IP0_2
                             47 	.globl _IP0_3
                             48 	.globl _IP0_4
                             49 	.globl _IP0_5
                             50 	.globl _IP0_6
                             51 	.globl _IP1_0
                             52 	.globl _IP1_1
                             53 	.globl _IP1_2
                             54 	.globl _IP1_6
                             55 	.globl _IEN1_0
                             56 	.globl _IEN1_1
                             57 	.globl _IEN1_2
                             58 	.globl _IEN0_0
                             59 	.globl _IEN0_1
                             60 	.globl _IEN0_2
                             61 	.globl _IEN0_3
                             62 	.globl _IEN0_4
                             63 	.globl _IEN0_5
                             64 	.globl _IEN0_6
                             65 	.globl _IEN0_7
                             66 	.globl _TCON_0
                             67 	.globl _TCON_1
                             68 	.globl _TCON_2
                             69 	.globl _TCON_3
                             70 	.globl _TCON_4
                             71 	.globl _TCON_5
                             72 	.globl _TCON_6
                             73 	.globl _TCON_7
                             74 	.globl _PSW_7
                             75 	.globl _PSW_6
                             76 	.globl _PSW_5
                             77 	.globl _PSW_4
                             78 	.globl _PSW_3
                             79 	.globl _PSW_2
                             80 	.globl _PSW_1
                             81 	.globl _PSW_0
                             82 	.globl _IEN1
                             83 	.globl _IP0H
                             84 	.globl _WFEED2
                             85 	.globl _WFEED1
                             86 	.globl _WDL
                             87 	.globl _WDCON
                             88 	.globl _TRIM
                             89 	.globl _TAMOD
                             90 	.globl _SSTAT
                             91 	.globl _RTCL
                             92 	.globl _RTCH
                             93 	.globl _RTCCON
                             94 	.globl _RSTSRC
                             95 	.globl _PT0AD
                             96 	.globl _PCONA
                             97 	.globl _P3M2
                             98 	.globl _P3M1
                             99 	.globl _P1M2
                            100 	.globl _P1M1
                            101 	.globl _P0M2
                            102 	.globl _P0M1
                            103 	.globl _KBPATN
                            104 	.globl _KBMASK
                            105 	.globl _KBCON
                            106 	.globl _IP1H
                            107 	.globl _IP1
                            108 	.globl _I2STAT
                            109 	.globl _I2SCLL
                            110 	.globl _I2SCLH
                            111 	.globl _I2DAT
                            112 	.globl _I2CON
                            113 	.globl _I2ADR
                            114 	.globl _FMDATA
                            115 	.globl _FMCON
                            116 	.globl _FMADRL
                            117 	.globl _FMADRH
                            118 	.globl _DIVM
                            119 	.globl _CMP2
                            120 	.globl _CMP1
                            121 	.globl _BRGCON
                            122 	.globl _BRGR1
                            123 	.globl _BRGR0
                            124 	.globl _SADEN
                            125 	.globl _SADDR
                            126 	.globl _AUXR1
                            127 	.globl _SBUF
                            128 	.globl _SCON
                            129 	.globl _IP0
                            130 	.globl _IEN0
                            131 	.globl _TH1
                            132 	.globl _TH0
                            133 	.globl _TL1
                            134 	.globl _TL0
                            135 	.globl _TMOD
                            136 	.globl _TCON
                            137 	.globl _PCON
                            138 	.globl _DPH
                            139 	.globl _DPL
                            140 	.globl _SP
                            141 	.globl _B
                            142 	.globl _ACC
                            143 	.globl _PSW
                            144 	.globl _P3
                            145 	.globl _P1
                            146 	.globl _P0
                            147 	.globl _stoerung_obj
                            148 	.globl _alarm_obj
                            149 	.globl _stoerung
                            150 	.globl _alarm
                            151 	.globl _event
                            152 	.globl _timer_stoerung
                            153 	.globl _timer_alarm
                            154 	.globl _timer
                            155 	.globl _write_value_req
                            156 	.globl _read_value_req
                            157 	.globl _read_obj_value
                            158 	.globl _key
                            159 	.globl _delay_timer
                            160 	.globl _restart_app
                            161 ;--------------------------------------------------------
                            162 ; special function registers
                            163 ;--------------------------------------------------------
                            164 	.area RSEG    (DATA)
                    0080    165 _P0	=	0x0080
                    0090    166 _P1	=	0x0090
                    00B0    167 _P3	=	0x00b0
                    00D0    168 _PSW	=	0x00d0
                    00E0    169 _ACC	=	0x00e0
                    00F0    170 _B	=	0x00f0
                    0081    171 _SP	=	0x0081
                    0082    172 _DPL	=	0x0082
                    0083    173 _DPH	=	0x0083
                    0087    174 _PCON	=	0x0087
                    0088    175 _TCON	=	0x0088
                    0089    176 _TMOD	=	0x0089
                    008A    177 _TL0	=	0x008a
                    008B    178 _TL1	=	0x008b
                    008C    179 _TH0	=	0x008c
                    008D    180 _TH1	=	0x008d
                    00A8    181 _IEN0	=	0x00a8
                    00B8    182 _IP0	=	0x00b8
                    0098    183 _SCON	=	0x0098
                    0099    184 _SBUF	=	0x0099
                    00A2    185 _AUXR1	=	0x00a2
                    00A9    186 _SADDR	=	0x00a9
                    00B9    187 _SADEN	=	0x00b9
                    00BE    188 _BRGR0	=	0x00be
                    00BF    189 _BRGR1	=	0x00bf
                    00BD    190 _BRGCON	=	0x00bd
                    00AC    191 _CMP1	=	0x00ac
                    00AD    192 _CMP2	=	0x00ad
                    0095    193 _DIVM	=	0x0095
                    00E7    194 _FMADRH	=	0x00e7
                    00E6    195 _FMADRL	=	0x00e6
                    00E4    196 _FMCON	=	0x00e4
                    00E5    197 _FMDATA	=	0x00e5
                    00DB    198 _I2ADR	=	0x00db
                    00D8    199 _I2CON	=	0x00d8
                    00DA    200 _I2DAT	=	0x00da
                    00DD    201 _I2SCLH	=	0x00dd
                    00DC    202 _I2SCLL	=	0x00dc
                    00D9    203 _I2STAT	=	0x00d9
                    00F8    204 _IP1	=	0x00f8
                    00F7    205 _IP1H	=	0x00f7
                    0094    206 _KBCON	=	0x0094
                    0086    207 _KBMASK	=	0x0086
                    0093    208 _KBPATN	=	0x0093
                    0084    209 _P0M1	=	0x0084
                    0085    210 _P0M2	=	0x0085
                    0091    211 _P1M1	=	0x0091
                    0092    212 _P1M2	=	0x0092
                    00B1    213 _P3M1	=	0x00b1
                    00B2    214 _P3M2	=	0x00b2
                    00B5    215 _PCONA	=	0x00b5
                    00F6    216 _PT0AD	=	0x00f6
                    00DF    217 _RSTSRC	=	0x00df
                    00D1    218 _RTCCON	=	0x00d1
                    00D2    219 _RTCH	=	0x00d2
                    00D3    220 _RTCL	=	0x00d3
                    00BA    221 _SSTAT	=	0x00ba
                    008F    222 _TAMOD	=	0x008f
                    0096    223 _TRIM	=	0x0096
                    00A7    224 _WDCON	=	0x00a7
                    00C1    225 _WDL	=	0x00c1
                    00C2    226 _WFEED1	=	0x00c2
                    00C3    227 _WFEED2	=	0x00c3
                    00B7    228 _IP0H	=	0x00b7
                    00E8    229 _IEN1	=	0x00e8
                            230 ;--------------------------------------------------------
                            231 ; special function bits
                            232 ;--------------------------------------------------------
                            233 	.area RSEG    (DATA)
                    00D0    234 _PSW_0	=	0x00d0
                    00D1    235 _PSW_1	=	0x00d1
                    00D2    236 _PSW_2	=	0x00d2
                    00D3    237 _PSW_3	=	0x00d3
                    00D4    238 _PSW_4	=	0x00d4
                    00D5    239 _PSW_5	=	0x00d5
                    00D6    240 _PSW_6	=	0x00d6
                    00D7    241 _PSW_7	=	0x00d7
                    008F    242 _TCON_7	=	0x008f
                    008E    243 _TCON_6	=	0x008e
                    008D    244 _TCON_5	=	0x008d
                    008C    245 _TCON_4	=	0x008c
                    008B    246 _TCON_3	=	0x008b
                    008A    247 _TCON_2	=	0x008a
                    0089    248 _TCON_1	=	0x0089
                    0088    249 _TCON_0	=	0x0088
                    00AF    250 _IEN0_7	=	0x00af
                    00AE    251 _IEN0_6	=	0x00ae
                    00AD    252 _IEN0_5	=	0x00ad
                    00AC    253 _IEN0_4	=	0x00ac
                    00AB    254 _IEN0_3	=	0x00ab
                    00AA    255 _IEN0_2	=	0x00aa
                    00A9    256 _IEN0_1	=	0x00a9
                    00A8    257 _IEN0_0	=	0x00a8
                    00EA    258 _IEN1_2	=	0x00ea
                    00E9    259 _IEN1_1	=	0x00e9
                    00E8    260 _IEN1_0	=	0x00e8
                    00FE    261 _IP1_6	=	0x00fe
                    00FA    262 _IP1_2	=	0x00fa
                    00F9    263 _IP1_1	=	0x00f9
                    00F8    264 _IP1_0	=	0x00f8
                    00BE    265 _IP0_6	=	0x00be
                    00BD    266 _IP0_5	=	0x00bd
                    00BC    267 _IP0_4	=	0x00bc
                    00BB    268 _IP0_3	=	0x00bb
                    00BA    269 _IP0_2	=	0x00ba
                    00B9    270 _IP0_1	=	0x00b9
                    00B8    271 _IP0_0	=	0x00b8
                    0098    272 _SCON_0	=	0x0098
                    0099    273 _SCON_1	=	0x0099
                    009A    274 _SCON_2	=	0x009a
                    009B    275 _SCON_3	=	0x009b
                    009C    276 _SCON_4	=	0x009c
                    009D    277 _SCON_5	=	0x009d
                    009E    278 _SCON_6	=	0x009e
                    009F    279 _SCON_7	=	0x009f
                    00DE    280 _I2CON_6	=	0x00de
                    00DD    281 _I2CON_5	=	0x00dd
                    00DC    282 _I2CON_4	=	0x00dc
                    00DB    283 _I2CON_3	=	0x00db
                    00DA    284 _I2CON_2	=	0x00da
                    00D8    285 _I2CON_0	=	0x00d8
                    0080    286 _P0_0	=	0x0080
                    0081    287 _P0_1	=	0x0081
                    0082    288 _P0_2	=	0x0082
                    0083    289 _P0_3	=	0x0083
                    0084    290 _P0_4	=	0x0084
                    0085    291 _P0_5	=	0x0085
                    0086    292 _P0_6	=	0x0086
                    0087    293 _P0_7	=	0x0087
                    0090    294 _P1_0	=	0x0090
                    0091    295 _P1_1	=	0x0091
                    0092    296 _P1_2	=	0x0092
                    0093    297 _P1_3	=	0x0093
                    0094    298 _P1_4	=	0x0094
                    0095    299 _P1_5	=	0x0095
                    0096    300 _P1_6	=	0x0096
                    0097    301 _P1_7	=	0x0097
                    00B0    302 _P3_0	=	0x00b0
                    00B1    303 _P3_1	=	0x00b1
                            304 ;--------------------------------------------------------
                            305 ; overlayable register banks
                            306 ;--------------------------------------------------------
                            307 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     308 	.ds 8
                            309 ;--------------------------------------------------------
                            310 ; internal ram data
                            311 ;--------------------------------------------------------
                            312 	.area DSEG    (DATA)
   0008                     313 _timer::
   0008                     314 	.ds 2
   000A                     315 _timer_alarm::
   000A                     316 	.ds 2
   000C                     317 _timer_stoerung::
   000C                     318 	.ds 2
                            319 ;--------------------------------------------------------
                            320 ; overlayable items in internal ram 
                            321 ;--------------------------------------------------------
                            322 	.area OSEG    (OVR,DATA)
                            323 ;--------------------------------------------------------
                            324 ; indirectly addressable internal ram data
                            325 ;--------------------------------------------------------
                            326 	.area ISEG    (DATA)
                            327 ;--------------------------------------------------------
                            328 ; absolute internal ram data
                            329 ;--------------------------------------------------------
                            330 	.area IABS    (ABS,DATA)
                            331 	.area IABS    (ABS,DATA)
                            332 ;--------------------------------------------------------
                            333 ; bit data
                            334 ;--------------------------------------------------------
                            335 	.area BSEG    (BIT)
   0000                     336 _event::
   0000                     337 	.ds 1
   0001                     338 _alarm::
   0001                     339 	.ds 1
   0002                     340 _stoerung::
   0002                     341 	.ds 1
   0003                     342 _alarm_obj::
   0003                     343 	.ds 1
   0004                     344 _stoerung_obj::
   0004                     345 	.ds 1
                            346 ;--------------------------------------------------------
                            347 ; paged external ram data
                            348 ;--------------------------------------------------------
                            349 	.area PSEG    (PAG,XDATA)
                            350 ;--------------------------------------------------------
                            351 ; external ram data
                            352 ;--------------------------------------------------------
                            353 	.area XSEG    (XDATA)
                            354 ;--------------------------------------------------------
                            355 ; absolute external ram data
                            356 ;--------------------------------------------------------
                            357 	.area XABS    (ABS,XDATA)
                            358 ;--------------------------------------------------------
                            359 ; external initialized ram data
                            360 ;--------------------------------------------------------
                            361 	.area XISEG   (XDATA)
                            362 	.area HOME    (CODE)
                            363 	.area GSINIT0 (CODE)
                            364 	.area GSINIT1 (CODE)
                            365 	.area GSINIT2 (CODE)
                            366 	.area GSINIT3 (CODE)
                            367 	.area GSINIT4 (CODE)
                            368 	.area GSINIT5 (CODE)
                            369 	.area GSINIT  (CODE)
                            370 	.area GSFINAL (CODE)
                            371 	.area CSEG    (CODE)
                            372 ;--------------------------------------------------------
                            373 ; global & static initialisations
                            374 ;--------------------------------------------------------
                            375 	.area HOME    (CODE)
                            376 	.area GSINIT  (CODE)
                            377 	.area GSFINAL (CODE)
                            378 	.area GSINIT  (CODE)
                            379 ;--------------------------------------------------------
                            380 ; Home
                            381 ;--------------------------------------------------------
                            382 	.area HOME    (CODE)
                            383 	.area HOME    (CODE)
                            384 ;--------------------------------------------------------
                            385 ; code
                            386 ;--------------------------------------------------------
                            387 	.area CSEG    (CODE)
                            388 ;------------------------------------------------------------
                            389 ;Allocation info for local variables in function 'write_value_req'
                            390 ;------------------------------------------------------------
                            391 ;------------------------------------------------------------
                            392 ;	../rm_app.c:27: void write_value_req(void)	// Empfangenes write_value_request Telegramm verarbeiten
                            393 ;	-----------------------------------------
                            394 ;	 function write_value_req
                            395 ;	-----------------------------------------
   0129                     396 _write_value_req:
                    0002    397 	ar2 = 0x02
                    0003    398 	ar3 = 0x03
                    0004    399 	ar4 = 0x04
                    0005    400 	ar5 = 0x05
                    0006    401 	ar6 = 0x06
                    0007    402 	ar7 = 0x07
                    0000    403 	ar0 = 0x00
                    0001    404 	ar1 = 0x01
                            405 ;	../rm_app.c:32: }
   0129 22                  406 	ret
                            407 ;------------------------------------------------------------
                            408 ;Allocation info for local variables in function 'read_value_req'
                            409 ;------------------------------------------------------------
                            410 ;------------------------------------------------------------
                            411 ;	../rm_app.c:36: void read_value_req(void)	// Empfangenes read_value_request Telegramm verarbeiten
                            412 ;	-----------------------------------------
                            413 ;	 function read_value_req
                            414 ;	-----------------------------------------
   012A                     415 _read_value_req:
                            416 ;	../rm_app.c:41: }
   012A 22                  417 	ret
                            418 ;------------------------------------------------------------
                            419 ;Allocation info for local variables in function 'read_obj_value'
                            420 ;------------------------------------------------------------
                            421 ;objno                     Allocated to registers r2 
                            422 ;return_value              Allocated to registers r3 
                            423 ;------------------------------------------------------------
                            424 ;	../rm_app.c:44: unsigned long read_obj_value(unsigned char objno)
                            425 ;	-----------------------------------------
                            426 ;	 function read_obj_value
                            427 ;	-----------------------------------------
   012B                     428 _read_obj_value:
   012B AA 82               429 	mov	r2,dpl
                            430 ;	../rm_app.c:46: unsigned char return_value=0;
   012D 7B 00               431 	mov	r3,#0x00
                            432 ;	../rm_app.c:48: if(objno==0) return_value=alarm_obj;
   012F EA                  433 	mov	a,r2
   0130 70 06               434 	jnz	00102$
   0132 A2 03               435 	mov	c,_alarm_obj
   0134 E4                  436 	clr	a
   0135 33                  437 	rlc	a
   0136 FC                  438 	mov	r4,a
   0137 FB                  439 	mov	r3,a
   0138                     440 00102$:
                            441 ;	../rm_app.c:49: if(objno==1) return_value=stoerung_obj;
   0138 BA 01 06            442 	cjne	r2,#0x01,00104$
   013B A2 04               443 	mov	c,_stoerung_obj
   013D E4                  444 	clr	a
   013E 33                  445 	rlc	a
   013F FA                  446 	mov	r2,a
   0140 FB                  447 	mov	r3,a
   0141                     448 00104$:
                            449 ;	../rm_app.c:51: return(return_value);
   0141 7A 00               450 	mov	r2,#0x00
   0143 7C 00               451 	mov	r4,#0x00
   0145 7D 00               452 	mov	r5,#0x00
   0147 8B 82               453 	mov	dpl,r3
   0149 8A 83               454 	mov	dph,r2
   014B 8C F0               455 	mov	b,r4
   014D ED                  456 	mov	a,r5
   014E 22                  457 	ret
                            458 ;------------------------------------------------------------
                            459 ;Allocation info for local variables in function 'key'
                            460 ;------------------------------------------------------------
                            461 ;port                      Allocated to registers r2 
                            462 ;------------------------------------------------------------
                            463 ;	../rm_app.c:55: void key(void) __interrupt (7)
                            464 ;	-----------------------------------------
                            465 ;	 function key
                            466 ;	-----------------------------------------
   014F                     467 _key:
   014F C0 E0               468 	push	acc
   0151 C0 02               469 	push	ar2
   0153 C0 D0               470 	push	psw
   0155 75 D0 00            471 	mov	psw,#0x00
                            472 ;	../rm_app.c:59: EKBI=0;				// keyboard Interrupt sperren
   0158 C2 E9               473 	clr	_IEN1_1
                            474 ;	../rm_app.c:61: port=P0&0x03;
   015A 74 03               475 	mov	a,#0x03
   015C 55 80               476 	anl	a,_P0
   015E FA                  477 	mov	r2,a
                            478 ;	../rm_app.c:62: if(port==2) alarm=1;
   015F BA 02 02            479 	cjne	r2,#0x02,00102$
   0162 D2 01               480 	setb	_alarm
   0164                     481 00102$:
                            482 ;	../rm_app.c:63: if(port==1) stoerung=1;
   0164 BA 01 02            483 	cjne	r2,#0x01,00104$
   0167 D2 02               484 	setb	_stoerung
   0169                     485 00104$:
                            486 ;	../rm_app.c:64: if(port==0) {
   0169 EA                  487 	mov	a,r2
   016A 70 04               488 	jnz	00106$
                            489 ;	../rm_app.c:65: alarm=0;
   016C C2 01               490 	clr	_alarm
                            491 ;	../rm_app.c:66: stoerung=0;
   016E C2 02               492 	clr	_stoerung
   0170                     493 00106$:
                            494 ;	../rm_app.c:68: event=1;				// zeigt an, dass der Rauchmelder etwas gesendet hat
   0170 D2 00               495 	setb	_event
                            496 ;	../rm_app.c:69: interrupted=1;			// Flag setzen, dass unterbrochen wurde
   0172 D2 06               497 	setb	_interrupted
                            498 ;	../rm_app.c:71: KBCON=0;				// Interrupt-Flag löschen
   0174 75 94 00            499 	mov	_KBCON,#0x00
                            500 ;	../rm_app.c:72: KBPATN=port;
   0177 8A 93               501 	mov	_KBPATN,r2
                            502 ;	../rm_app.c:73: EKBI=1;					// Keyboard Interrupt wieder frei geben
   0179 D2 E9               503 	setb	_IEN1_1
   017B D0 D0               504 	pop	psw
   017D D0 02               505 	pop	ar2
   017F D0 E0               506 	pop	acc
   0181 32                  507 	reti
                            508 ;	eliminated unneeded push/pop ar0
                            509 ;	eliminated unneeded push/pop ar1
                            510 ;	eliminated unneeded push/pop dpl
                            511 ;	eliminated unneeded push/pop dph
                            512 ;	eliminated unneeded push/pop b
                            513 ;------------------------------------------------------------
                            514 ;Allocation info for local variables in function 'delay_timer'
                            515 ;------------------------------------------------------------
                            516 ;------------------------------------------------------------
                            517 ;	../rm_app.c:77: void delay_timer(void)	// zählt alle 65ms die Variable Timer hoch und prüft Queue
                            518 ;	-----------------------------------------
                            519 ;	 function delay_timer
                            520 ;	-----------------------------------------
   0182                     521 _delay_timer:
                            522 ;	../rm_app.c:81: RTCCON=0x60;		// RTC anhalten und Flag löschen
   0182 75 D1 60            523 	mov	_RTCCON,#0x60
                            524 ;	../rm_app.c:82: RTCH=0xE1;			// reload Real Time Clock
   0185 75 D2 E1            525 	mov	_RTCH,#0xE1
                            526 ;	../rm_app.c:83: RTCL=0x00;
   0188 75 D3 00            527 	mov	_RTCL,#0x00
                            528 ;	../rm_app.c:85: timer++;
   018B 05 08               529 	inc	_timer
   018D E4                  530 	clr	a
   018E B5 08 02            531 	cjne	a,_timer,00121$
   0191 05 09               532 	inc	(_timer + 1)
   0193                     533 00121$:
                            534 ;	../rm_app.c:87: if (timer_alarm==timer && eeprom[A_ZYKLISCH]) {
   0193 E5 08               535 	mov	a,_timer
   0195 B5 0A 41            536 	cjne	a,_timer_alarm,00105$
   0198 E5 09               537 	mov	a,(_timer + 1)
   019A B5 0B 3C            538 	cjne	a,(_timer_alarm + 1),00105$
   019D 90 1D F4            539 	mov	dptr,#(_eeprom + 0x00f4)
   01A0 E4                  540 	clr	a
   01A1 93                  541 	movc	a,@a+dptr
   01A2 60 35               542 	jz	00105$
                            543 ;	../rm_app.c:88: send_obj_value(0);
   01A4 75 82 00            544 	mov	dpl,#0x00
   01A7 12 08 F8            545 	lcall	_send_obj_value
                            546 ;	../rm_app.c:89: if (eeprom[A_BASIS]) timer_alarm=timer+eeprom[A_FAKTOR]*60;
   01AA 90 1D F6            547 	mov	dptr,#(_eeprom + 0x00f6)
   01AD E4                  548 	clr	a
   01AE 93                  549 	movc	a,@a+dptr
   01AF 60 16               550 	jz	00102$
   01B1 90 1D F5            551 	mov	dptr,#(_eeprom + 0x00f5)
   01B4 E4                  552 	clr	a
   01B5 93                  553 	movc	a,@a+dptr
   01B6 FA                  554 	mov	r2,a
   01B7 75 F0 3C            555 	mov	b,#0x3C
   01BA A4                  556 	mul	ab
   01BB 25 08               557 	add	a,_timer
   01BD F5 0A               558 	mov	_timer_alarm,a
   01BF E5 09               559 	mov	a,(_timer + 1)
   01C1 35 F0               560 	addc	a,b
   01C3 F5 0B               561 	mov	(_timer_alarm + 1),a
   01C5 80 12               562 	sjmp	00105$
   01C7                     563 00102$:
                            564 ;	../rm_app.c:90: else timer_alarm=timer+eeprom[A_FAKTOR];
   01C7 90 1D F5            565 	mov	dptr,#(_eeprom + 0x00f5)
   01CA E4                  566 	clr	a
   01CB 93                  567 	movc	a,@a+dptr
   01CC FA                  568 	mov	r2,a
   01CD 7B 00               569 	mov	r3,#0x00
   01CF EA                  570 	mov	a,r2
   01D0 25 08               571 	add	a,_timer
   01D2 F5 0A               572 	mov	_timer_alarm,a
   01D4 EB                  573 	mov	a,r3
   01D5 35 09               574 	addc	a,(_timer + 1)
   01D7 F5 0B               575 	mov	(_timer_alarm + 1),a
   01D9                     576 00105$:
                            577 ;	../rm_app.c:92: if (timer_stoerung==timer && eeprom[S_ZYKLISCH]) {
   01D9 E5 08               578 	mov	a,_timer
   01DB B5 0C 41            579 	cjne	a,_timer_stoerung,00111$
   01DE E5 09               580 	mov	a,(_timer + 1)
   01E0 B5 0D 3C            581 	cjne	a,(_timer_stoerung + 1),00111$
   01E3 90 1D F7            582 	mov	dptr,#(_eeprom + 0x00f7)
   01E6 E4                  583 	clr	a
   01E7 93                  584 	movc	a,@a+dptr
   01E8 60 35               585 	jz	00111$
                            586 ;	../rm_app.c:93: send_obj_value(1);
   01EA 75 82 01            587 	mov	dpl,#0x01
   01ED 12 08 F8            588 	lcall	_send_obj_value
                            589 ;	../rm_app.c:94: if (eeprom[S_BASIS]) timer_stoerung=timer+eeprom[S_FAKTOR]*60;
   01F0 90 1D F9            590 	mov	dptr,#(_eeprom + 0x00f9)
   01F3 E4                  591 	clr	a
   01F4 93                  592 	movc	a,@a+dptr
   01F5 60 16               593 	jz	00108$
   01F7 90 1D F8            594 	mov	dptr,#(_eeprom + 0x00f8)
   01FA E4                  595 	clr	a
   01FB 93                  596 	movc	a,@a+dptr
   01FC FA                  597 	mov	r2,a
   01FD 75 F0 3C            598 	mov	b,#0x3C
   0200 A4                  599 	mul	ab
   0201 25 08               600 	add	a,_timer
   0203 F5 0C               601 	mov	_timer_stoerung,a
   0205 E5 09               602 	mov	a,(_timer + 1)
   0207 35 F0               603 	addc	a,b
   0209 F5 0D               604 	mov	(_timer_stoerung + 1),a
   020B 80 12               605 	sjmp	00111$
   020D                     606 00108$:
                            607 ;	../rm_app.c:95: else timer_stoerung=timer+eeprom[S_FAKTOR];
   020D 90 1D F8            608 	mov	dptr,#(_eeprom + 0x00f8)
   0210 E4                  609 	clr	a
   0211 93                  610 	movc	a,@a+dptr
   0212 FA                  611 	mov	r2,a
   0213 7B 00               612 	mov	r3,#0x00
   0215 EA                  613 	mov	a,r2
   0216 25 08               614 	add	a,_timer
   0218 F5 0C               615 	mov	_timer_stoerung,a
   021A EB                  616 	mov	a,r3
   021B 35 09               617 	addc	a,(_timer + 1)
   021D F5 0D               618 	mov	(_timer_stoerung + 1),a
   021F                     619 00111$:
                            620 ;	../rm_app.c:98: RTCCON=0x61;		// RTC starten
   021F 75 D1 61            621 	mov	_RTCCON,#0x61
   0222 22                  622 	ret
                            623 ;------------------------------------------------------------
                            624 ;Allocation info for local variables in function 'restart_app'
                            625 ;------------------------------------------------------------
                            626 ;------------------------------------------------------------
                            627 ;	../rm_app.c:102: void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
                            628 ;	-----------------------------------------
                            629 ;	 function restart_app
                            630 ;	-----------------------------------------
   0223                     631 _restart_app:
                            632 ;	../rm_app.c:106: P0M1= 0x00;			// all bidirectional,
   0223 75 84 00            633 	mov	_P0M1,#0x00
                            634 ;	../rm_app.c:107: P0M2= 0x00;
   0226 75 85 00            635 	mov	_P0M2,#0x00
                            636 ;	../rm_app.c:108: P0= 0xFF;
   0229 75 80 FF            637 	mov	_P0,#0xFF
                            638 ;	../rm_app.c:110: alarm=0;
   022C C2 01               639 	clr	_alarm
                            640 ;	../rm_app.c:111: stoerung=0;
   022E C2 02               641 	clr	_stoerung
                            642 ;	../rm_app.c:112: alarm_obj=0;
   0230 C2 03               643 	clr	_alarm_obj
                            644 ;	../rm_app.c:113: stoerung_obj=0;
   0232 C2 04               645 	clr	_stoerung_obj
                            646 ;	../rm_app.c:116: KBMASK=0x03;		// P0.0 & P0.1 enabled for KB-Interrupt
   0234 75 86 03            647 	mov	_KBMASK,#0x03
                            648 ;	../rm_app.c:117: KBPATN=0x03;		// Pattern
   0237 75 93 03            649 	mov	_KBPATN,#0x03
                            650 ;	../rm_app.c:118: KBCON=0;			// Interrupt when port not equal to pattern
   023A 75 94 00            651 	mov	_KBCON,#0x00
                            652 ;	../rm_app.c:119: EKBI=1;
   023D D2 E9               653 	setb	_IEN1_1
                            654 ;	../rm_app.c:121: RTCH=0xE1;		// Real Time Clock auf 1s laden
   023F 75 D2 E1            655 	mov	_RTCH,#0xE1
                            656 ;	../rm_app.c:122: RTCL=0x00;		// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
   0242 75 D3 00            657 	mov	_RTCL,#0x00
                            658 ;	../rm_app.c:123: RTCCON=0x61;	// ... und starten
   0245 75 D1 61            659 	mov	_RTCCON,#0x61
                            660 ;	../rm_app.c:125: timer=0;
   0248 E4                  661 	clr	a
   0249 F5 08               662 	mov	_timer,a
   024B F5 09               663 	mov	(_timer + 1),a
                            664 ;	../rm_app.c:126: if (eeprom[A_ZYKLISCH]) timer_alarm=timer+2;
   024D 90 1D F4            665 	mov	dptr,#(_eeprom + 0x00f4)
   0250 E4                  666 	clr	a
   0251 93                  667 	movc	a,@a+dptr
   0252 60 06               668 	jz	00102$
   0254 75 0A 02            669 	mov	_timer_alarm,#0x02
   0257 E4                  670 	clr	a
   0258 F5 0B               671 	mov	(_timer_alarm + 1),a
   025A                     672 00102$:
                            673 ;	../rm_app.c:127: if (eeprom[S_ZYKLISCH]) timer_stoerung=timer+4;
   025A 90 1D F7            674 	mov	dptr,#(_eeprom + 0x00f7)
   025D E4                  675 	clr	a
   025E 93                  676 	movc	a,@a+dptr
   025F 60 06               677 	jz	00104$
   0261 75 0C 04            678 	mov	_timer_stoerung,#0x04
   0264 E4                  679 	clr	a
   0265 F5 0D               680 	mov	(_timer_stoerung + 1),a
   0267                     681 00104$:
                            682 ;	../rm_app.c:130: EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
   0267 C2 AF               683 	clr	_IEN0_7
                            684 ;	../rm_app.c:131: START_WRITECYCLE;
   0269 75 E4 00            685 	mov	_FMCON,#0x00
                            686 ;	../rm_app.c:132: WRITE_BYTE(0x01,0x03,0x00);	// Herstellercode 0x0000 = Freebus
   026C 75 E7 1D            687 	mov	_FMADRH,#0x1D
   026F 75 E6 03            688 	mov	_FMADRL,#0x03
   0272 75 E5 00            689 	mov	_FMDATA,#0x00
                            690 ;	../rm_app.c:133: WRITE_BYTE(0x01,0x04,0x00);
   0275 75 E7 1D            691 	mov	_FMADRH,#0x1D
   0278 75 E6 04            692 	mov	_FMADRL,#0x04
   027B 75 E5 00            693 	mov	_FMDATA,#0x00
                            694 ;	../rm_app.c:134: WRITE_BYTE(0x01,0x05,0x10);	// Devicetype 0x1003
   027E 75 E7 1D            695 	mov	_FMADRH,#0x1D
   0281 75 E6 05            696 	mov	_FMADRL,#0x05
   0284 75 E5 10            697 	mov	_FMDATA,#0x10
                            698 ;	../rm_app.c:135: WRITE_BYTE(0x01,0x06,0x03);
   0287 75 E7 1D            699 	mov	_FMADRH,#0x1D
   028A 75 E6 06            700 	mov	_FMADRL,#0x06
   028D 75 E5 03            701 	mov	_FMDATA,#0x03
                            702 ;	../rm_app.c:136: WRITE_BYTE(0x01,0x07,0x01);	// Versionnumber of application programm
   0290 75 E7 1D            703 	mov	_FMADRH,#0x1D
   0293 75 E6 07            704 	mov	_FMADRL,#0x07
   0296 75 E5 01            705 	mov	_FMDATA,#0x01
                            706 ;	../rm_app.c:137: WRITE_BYTE(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
   0299 75 E7 1D            707 	mov	_FMADRH,#0x1D
   029C 75 E6 0C            708 	mov	_FMADRL,#0x0C
   029F 75 E5 00            709 	mov	_FMDATA,#0x00
                            710 ;	../rm_app.c:138: WRITE_BYTE(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
   02A2 75 E7 1D            711 	mov	_FMADRH,#0x1D
   02A5 75 E6 0D            712 	mov	_FMADRL,#0x0D
   02A8 75 E5 FF            713 	mov	_FMDATA,#0xFF
                            714 ;	../rm_app.c:139: WRITE_BYTE(0x01,0x12,0xA0);	// COMMSTAB Pointer
   02AB 75 E7 1D            715 	mov	_FMADRH,#0x1D
   02AE 75 E6 12            716 	mov	_FMADRL,#0x12
   02B1 75 E5 A0            717 	mov	_FMDATA,#0xA0
                            718 ;	../rm_app.c:140: STOP_WRITECYCLE;
   02B4 75 E4 68            719 	mov	_FMCON,#0x68
                            720 ;	../rm_app.c:141: EA=1;						// Interrupts freigeben
   02B7 D2 AF               721 	setb	_IEN0_7
   02B9 22                  722 	ret
                            723 	.area CSEG    (CODE)
                            724 	.area CONST   (CODE)
                            725 	.area XINIT   (CODE)
                            726 	.area CABS    (ABS,CODE)
