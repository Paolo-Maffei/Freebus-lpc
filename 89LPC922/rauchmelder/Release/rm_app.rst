                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
                              4 ; This file was generated Thu Jun 28 18:23:15 2012
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
                            147 	.globl _fernalarm
                            148 	.globl _stoerung_obj
                            149 	.globl _alarm_obj
                            150 	.globl _stoerung
                            151 	.globl _alarm
                            152 	.globl _event
                            153 	.globl _timer_stoerung
                            154 	.globl _timer_alarm
                            155 	.globl _timer
                            156 	.globl _write_value_req
                            157 	.globl _read_value_req
                            158 	.globl _read_obj_value
                            159 	.globl _key
                            160 	.globl _delay_timer
                            161 	.globl _restart_app
                            162 ;--------------------------------------------------------
                            163 ; special function registers
                            164 ;--------------------------------------------------------
                            165 	.area RSEG    (DATA)
                    0080    166 _P0	=	0x0080
                    0090    167 _P1	=	0x0090
                    00B0    168 _P3	=	0x00b0
                    00D0    169 _PSW	=	0x00d0
                    00E0    170 _ACC	=	0x00e0
                    00F0    171 _B	=	0x00f0
                    0081    172 _SP	=	0x0081
                    0082    173 _DPL	=	0x0082
                    0083    174 _DPH	=	0x0083
                    0087    175 _PCON	=	0x0087
                    0088    176 _TCON	=	0x0088
                    0089    177 _TMOD	=	0x0089
                    008A    178 _TL0	=	0x008a
                    008B    179 _TL1	=	0x008b
                    008C    180 _TH0	=	0x008c
                    008D    181 _TH1	=	0x008d
                    00A8    182 _IEN0	=	0x00a8
                    00B8    183 _IP0	=	0x00b8
                    0098    184 _SCON	=	0x0098
                    0099    185 _SBUF	=	0x0099
                    00A2    186 _AUXR1	=	0x00a2
                    00A9    187 _SADDR	=	0x00a9
                    00B9    188 _SADEN	=	0x00b9
                    00BE    189 _BRGR0	=	0x00be
                    00BF    190 _BRGR1	=	0x00bf
                    00BD    191 _BRGCON	=	0x00bd
                    00AC    192 _CMP1	=	0x00ac
                    00AD    193 _CMP2	=	0x00ad
                    0095    194 _DIVM	=	0x0095
                    00E7    195 _FMADRH	=	0x00e7
                    00E6    196 _FMADRL	=	0x00e6
                    00E4    197 _FMCON	=	0x00e4
                    00E5    198 _FMDATA	=	0x00e5
                    00DB    199 _I2ADR	=	0x00db
                    00D8    200 _I2CON	=	0x00d8
                    00DA    201 _I2DAT	=	0x00da
                    00DD    202 _I2SCLH	=	0x00dd
                    00DC    203 _I2SCLL	=	0x00dc
                    00D9    204 _I2STAT	=	0x00d9
                    00F8    205 _IP1	=	0x00f8
                    00F7    206 _IP1H	=	0x00f7
                    0094    207 _KBCON	=	0x0094
                    0086    208 _KBMASK	=	0x0086
                    0093    209 _KBPATN	=	0x0093
                    0084    210 _P0M1	=	0x0084
                    0085    211 _P0M2	=	0x0085
                    0091    212 _P1M1	=	0x0091
                    0092    213 _P1M2	=	0x0092
                    00B1    214 _P3M1	=	0x00b1
                    00B2    215 _P3M2	=	0x00b2
                    00B5    216 _PCONA	=	0x00b5
                    00F6    217 _PT0AD	=	0x00f6
                    00DF    218 _RSTSRC	=	0x00df
                    00D1    219 _RTCCON	=	0x00d1
                    00D2    220 _RTCH	=	0x00d2
                    00D3    221 _RTCL	=	0x00d3
                    00BA    222 _SSTAT	=	0x00ba
                    008F    223 _TAMOD	=	0x008f
                    0096    224 _TRIM	=	0x0096
                    00A7    225 _WDCON	=	0x00a7
                    00C1    226 _WDL	=	0x00c1
                    00C2    227 _WFEED1	=	0x00c2
                    00C3    228 _WFEED2	=	0x00c3
                    00B7    229 _IP0H	=	0x00b7
                    00E8    230 _IEN1	=	0x00e8
                            231 ;--------------------------------------------------------
                            232 ; special function bits
                            233 ;--------------------------------------------------------
                            234 	.area RSEG    (DATA)
                    00D0    235 _PSW_0	=	0x00d0
                    00D1    236 _PSW_1	=	0x00d1
                    00D2    237 _PSW_2	=	0x00d2
                    00D3    238 _PSW_3	=	0x00d3
                    00D4    239 _PSW_4	=	0x00d4
                    00D5    240 _PSW_5	=	0x00d5
                    00D6    241 _PSW_6	=	0x00d6
                    00D7    242 _PSW_7	=	0x00d7
                    008F    243 _TCON_7	=	0x008f
                    008E    244 _TCON_6	=	0x008e
                    008D    245 _TCON_5	=	0x008d
                    008C    246 _TCON_4	=	0x008c
                    008B    247 _TCON_3	=	0x008b
                    008A    248 _TCON_2	=	0x008a
                    0089    249 _TCON_1	=	0x0089
                    0088    250 _TCON_0	=	0x0088
                    00AF    251 _IEN0_7	=	0x00af
                    00AE    252 _IEN0_6	=	0x00ae
                    00AD    253 _IEN0_5	=	0x00ad
                    00AC    254 _IEN0_4	=	0x00ac
                    00AB    255 _IEN0_3	=	0x00ab
                    00AA    256 _IEN0_2	=	0x00aa
                    00A9    257 _IEN0_1	=	0x00a9
                    00A8    258 _IEN0_0	=	0x00a8
                    00EA    259 _IEN1_2	=	0x00ea
                    00E9    260 _IEN1_1	=	0x00e9
                    00E8    261 _IEN1_0	=	0x00e8
                    00FE    262 _IP1_6	=	0x00fe
                    00FA    263 _IP1_2	=	0x00fa
                    00F9    264 _IP1_1	=	0x00f9
                    00F8    265 _IP1_0	=	0x00f8
                    00BE    266 _IP0_6	=	0x00be
                    00BD    267 _IP0_5	=	0x00bd
                    00BC    268 _IP0_4	=	0x00bc
                    00BB    269 _IP0_3	=	0x00bb
                    00BA    270 _IP0_2	=	0x00ba
                    00B9    271 _IP0_1	=	0x00b9
                    00B8    272 _IP0_0	=	0x00b8
                    0098    273 _SCON_0	=	0x0098
                    0099    274 _SCON_1	=	0x0099
                    009A    275 _SCON_2	=	0x009a
                    009B    276 _SCON_3	=	0x009b
                    009C    277 _SCON_4	=	0x009c
                    009D    278 _SCON_5	=	0x009d
                    009E    279 _SCON_6	=	0x009e
                    009F    280 _SCON_7	=	0x009f
                    00DE    281 _I2CON_6	=	0x00de
                    00DD    282 _I2CON_5	=	0x00dd
                    00DC    283 _I2CON_4	=	0x00dc
                    00DB    284 _I2CON_3	=	0x00db
                    00DA    285 _I2CON_2	=	0x00da
                    00D8    286 _I2CON_0	=	0x00d8
                    0080    287 _P0_0	=	0x0080
                    0081    288 _P0_1	=	0x0081
                    0082    289 _P0_2	=	0x0082
                    0083    290 _P0_3	=	0x0083
                    0084    291 _P0_4	=	0x0084
                    0085    292 _P0_5	=	0x0085
                    0086    293 _P0_6	=	0x0086
                    0087    294 _P0_7	=	0x0087
                    0090    295 _P1_0	=	0x0090
                    0091    296 _P1_1	=	0x0091
                    0092    297 _P1_2	=	0x0092
                    0093    298 _P1_3	=	0x0093
                    0094    299 _P1_4	=	0x0094
                    0095    300 _P1_5	=	0x0095
                    0096    301 _P1_6	=	0x0096
                    0097    302 _P1_7	=	0x0097
                    00B0    303 _P3_0	=	0x00b0
                    00B1    304 _P3_1	=	0x00b1
                            305 ;--------------------------------------------------------
                            306 ; overlayable register banks
                            307 ;--------------------------------------------------------
                            308 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     309 	.ds 8
                            310 ;--------------------------------------------------------
                            311 ; internal ram data
                            312 ;--------------------------------------------------------
                            313 	.area DSEG    (DATA)
   0008                     314 _timer::
   0008                     315 	.ds 2
   000A                     316 _timer_alarm::
   000A                     317 	.ds 2
   000C                     318 _timer_stoerung::
   000C                     319 	.ds 2
                            320 ;--------------------------------------------------------
                            321 ; overlayable items in internal ram 
                            322 ;--------------------------------------------------------
                            323 	.area OSEG    (OVR,DATA)
                            324 ;--------------------------------------------------------
                            325 ; indirectly addressable internal ram data
                            326 ;--------------------------------------------------------
                            327 	.area ISEG    (DATA)
                            328 ;--------------------------------------------------------
                            329 ; absolute internal ram data
                            330 ;--------------------------------------------------------
                            331 	.area IABS    (ABS,DATA)
                            332 	.area IABS    (ABS,DATA)
                            333 ;--------------------------------------------------------
                            334 ; bit data
                            335 ;--------------------------------------------------------
                            336 	.area BSEG    (BIT)
   0000                     337 _event::
   0000                     338 	.ds 1
   0001                     339 _alarm::
   0001                     340 	.ds 1
   0002                     341 _stoerung::
   0002                     342 	.ds 1
   0003                     343 _alarm_obj::
   0003                     344 	.ds 1
   0004                     345 _stoerung_obj::
   0004                     346 	.ds 1
   0005                     347 _fernalarm::
   0005                     348 	.ds 1
                            349 ;--------------------------------------------------------
                            350 ; paged external ram data
                            351 ;--------------------------------------------------------
                            352 	.area PSEG    (PAG,XDATA)
                            353 ;--------------------------------------------------------
                            354 ; external ram data
                            355 ;--------------------------------------------------------
                            356 	.area XSEG    (XDATA)
                            357 ;--------------------------------------------------------
                            358 ; absolute external ram data
                            359 ;--------------------------------------------------------
                            360 	.area XABS    (ABS,XDATA)
                            361 ;--------------------------------------------------------
                            362 ; external initialized ram data
                            363 ;--------------------------------------------------------
                            364 	.area XISEG   (XDATA)
                            365 	.area HOME    (CODE)
                            366 	.area GSINIT0 (CODE)
                            367 	.area GSINIT1 (CODE)
                            368 	.area GSINIT2 (CODE)
                            369 	.area GSINIT3 (CODE)
                            370 	.area GSINIT4 (CODE)
                            371 	.area GSINIT5 (CODE)
                            372 	.area GSINIT  (CODE)
                            373 	.area GSFINAL (CODE)
                            374 	.area CSEG    (CODE)
                            375 ;--------------------------------------------------------
                            376 ; global & static initialisations
                            377 ;--------------------------------------------------------
                            378 	.area HOME    (CODE)
                            379 	.area GSINIT  (CODE)
                            380 	.area GSFINAL (CODE)
                            381 	.area GSINIT  (CODE)
                            382 ;--------------------------------------------------------
                            383 ; Home
                            384 ;--------------------------------------------------------
                            385 	.area HOME    (CODE)
                            386 	.area HOME    (CODE)
                            387 ;--------------------------------------------------------
                            388 ; code
                            389 ;--------------------------------------------------------
                            390 	.area CSEG    (CODE)
                            391 ;------------------------------------------------------------
                            392 ;Allocation info for local variables in function 'write_value_req'
                            393 ;------------------------------------------------------------
                            394 ;objno                     Allocated to registers r2 
                            395 ;------------------------------------------------------------
                            396 ;	../rm_app.c:28: void write_value_req(void)	// Empfangenes write_value_request Telegramm verarbeiten
                            397 ;	-----------------------------------------
                            398 ;	 function write_value_req
                            399 ;	-----------------------------------------
   012C                     400 _write_value_req:
                    0002    401 	ar2 = 0x02
                    0003    402 	ar3 = 0x03
                    0004    403 	ar4 = 0x04
                    0005    404 	ar5 = 0x05
                    0006    405 	ar6 = 0x06
                    0007    406 	ar7 = 0x07
                    0000    407 	ar0 = 0x00
                    0001    408 	ar1 = 0x01
                            409 ;	../rm_app.c:32: objno=find_first_objno(telegramm[3],telegramm[4]);
   012C 85 2E 82            410 	mov	dpl,(_telegramm + 0x0003)
   012F C0 2F               411 	push	(_telegramm + 0x0004)
   0131 12 0B 62            412 	lcall	_find_first_objno
   0134 AA 82               413 	mov	r2,dpl
   0136 15 81               414 	dec	sp
                            415 ;	../rm_app.c:34: if (objno==2) {	// nur das Objekt für Alarm Fernauslösung darf beschrieben werden
   0138 BA 02 0E            416 	cjne	r2,#0x02,00106$
                            417 ;	../rm_app.c:35: if (telegramm[7]&0x01) {	// Alarm ein
   013B E5 32               418 	mov	a,(_telegramm + 0x0007)
   013D 30 E0 05            419 	jnb	acc.0,00102$
                            420 ;	../rm_app.c:36: PIN_DATA = 0;
   0140 C2 92               421 	clr	_P1_2
                            422 ;	../rm_app.c:37: fernalarm=1;
   0142 D2 05               423 	setb	_fernalarm
   0144 22                  424 	ret
   0145                     425 00102$:
                            426 ;	../rm_app.c:40: PIN_DATA = 1;
   0145 D2 92               427 	setb	_P1_2
                            428 ;	../rm_app.c:41: fernalarm=0;
   0147 C2 05               429 	clr	_fernalarm
   0149                     430 00106$:
   0149 22                  431 	ret
                            432 ;------------------------------------------------------------
                            433 ;Allocation info for local variables in function 'read_value_req'
                            434 ;------------------------------------------------------------
                            435 ;------------------------------------------------------------
                            436 ;	../rm_app.c:48: void read_value_req(void)	// Empfangenes read_value_request Telegramm verarbeiten
                            437 ;	-----------------------------------------
                            438 ;	 function read_value_req
                            439 ;	-----------------------------------------
   014A                     440 _read_value_req:
                            441 ;	../rm_app.c:53: }
   014A 22                  442 	ret
                            443 ;------------------------------------------------------------
                            444 ;Allocation info for local variables in function 'read_obj_value'
                            445 ;------------------------------------------------------------
                            446 ;objno                     Allocated to registers r2 
                            447 ;return_value              Allocated to registers r3 
                            448 ;------------------------------------------------------------
                            449 ;	../rm_app.c:56: unsigned long read_obj_value(unsigned char objno)
                            450 ;	-----------------------------------------
                            451 ;	 function read_obj_value
                            452 ;	-----------------------------------------
   014B                     453 _read_obj_value:
   014B AA 82               454 	mov	r2,dpl
                            455 ;	../rm_app.c:58: unsigned char return_value=0;
   014D 7B 00               456 	mov	r3,#0x00
                            457 ;	../rm_app.c:60: if(objno==0) return_value=alarm_obj;
   014F EA                  458 	mov	a,r2
   0150 70 06               459 	jnz	00102$
   0152 A2 03               460 	mov	c,_alarm_obj
   0154 E4                  461 	clr	a
   0155 33                  462 	rlc	a
   0156 FC                  463 	mov	r4,a
   0157 FB                  464 	mov	r3,a
   0158                     465 00102$:
                            466 ;	../rm_app.c:61: if(objno==1) return_value=stoerung_obj;
   0158 BA 01 06            467 	cjne	r2,#0x01,00104$
   015B A2 04               468 	mov	c,_stoerung_obj
   015D E4                  469 	clr	a
   015E 33                  470 	rlc	a
   015F FA                  471 	mov	r2,a
   0160 FB                  472 	mov	r3,a
   0161                     473 00104$:
                            474 ;	../rm_app.c:63: return(return_value);
   0161 7A 00               475 	mov	r2,#0x00
   0163 7C 00               476 	mov	r4,#0x00
   0165 7D 00               477 	mov	r5,#0x00
   0167 8B 82               478 	mov	dpl,r3
   0169 8A 83               479 	mov	dph,r2
   016B 8C F0               480 	mov	b,r4
   016D ED                  481 	mov	a,r5
   016E 22                  482 	ret
                            483 ;------------------------------------------------------------
                            484 ;Allocation info for local variables in function 'key'
                            485 ;------------------------------------------------------------
                            486 ;port                      Allocated to registers r2 
                            487 ;------------------------------------------------------------
                            488 ;	../rm_app.c:67: void key(void) __interrupt (7)		// Abfrage der beiden Statusleitungen
                            489 ;	-----------------------------------------
                            490 ;	 function key
                            491 ;	-----------------------------------------
   016F                     492 _key:
   016F C0 E0               493 	push	acc
   0171 C0 02               494 	push	ar2
   0173 C0 D0               495 	push	psw
   0175 75 D0 00            496 	mov	psw,#0x00
                            497 ;	../rm_app.c:71: EKBI=0;				// keyboard Interrupt sperren
   0178 C2 E9               498 	clr	_IEN1_1
                            499 ;	../rm_app.c:73: port=P0&0x03;
   017A 74 03               500 	mov	a,#0x03
   017C 55 80               501 	anl	a,_P0
   017E FA                  502 	mov	r2,a
                            503 ;	../rm_app.c:74: if(port==2) alarm=1;		// Alarm wenn P0.0 low
   017F BA 02 02            504 	cjne	r2,#0x02,00102$
   0182 D2 01               505 	setb	_alarm
   0184                     506 00102$:
                            507 ;	../rm_app.c:75: if(port==1) stoerung=1;		// Störung wenn P0.1 low
   0184 BA 01 02            508 	cjne	r2,#0x01,00104$
   0187 D2 02               509 	setb	_stoerung
   0189                     510 00104$:
                            511 ;	../rm_app.c:76: if(port==0) {				// Aufhebung der Meldung wenn beide low
   0189 EA                  512 	mov	a,r2
   018A 70 04               513 	jnz	00106$
                            514 ;	../rm_app.c:77: alarm=0;
   018C C2 01               515 	clr	_alarm
                            516 ;	../rm_app.c:78: stoerung=0;
   018E C2 02               517 	clr	_stoerung
   0190                     518 00106$:
                            519 ;	../rm_app.c:80: event=1;				// zeigt an, dass der Rauchmelder etwas gesendet hat
   0190 D2 00               520 	setb	_event
                            521 ;	../rm_app.c:81: interrupted=1;			// Flag setzen, dass unterbrochen wurde
   0192 D2 07               522 	setb	_interrupted
                            523 ;	../rm_app.c:82: KBCON=0;				// Interrupt-Flag löschen
   0194 75 94 00            524 	mov	_KBCON,#0x00
                            525 ;	../rm_app.c:83: KBPATN=port;			// aktuellen Portwert als neuen Ausgangspunkt für Änderung nehmen
   0197 8A 93               526 	mov	_KBPATN,r2
                            527 ;	../rm_app.c:84: EKBI=1;					// Keyboard Interrupt wieder frei geben
   0199 D2 E9               528 	setb	_IEN1_1
   019B D0 D0               529 	pop	psw
   019D D0 02               530 	pop	ar2
   019F D0 E0               531 	pop	acc
   01A1 32                  532 	reti
                            533 ;	eliminated unneeded push/pop ar0
                            534 ;	eliminated unneeded push/pop ar1
                            535 ;	eliminated unneeded push/pop dpl
                            536 ;	eliminated unneeded push/pop dph
                            537 ;	eliminated unneeded push/pop b
                            538 ;------------------------------------------------------------
                            539 ;Allocation info for local variables in function 'delay_timer'
                            540 ;------------------------------------------------------------
                            541 ;------------------------------------------------------------
                            542 ;	../rm_app.c:88: void delay_timer(void)	// zählt jede Sekunde die Variable Timer hoch und prüft ob zyklisch gesendet werden soll
                            543 ;	-----------------------------------------
                            544 ;	 function delay_timer
                            545 ;	-----------------------------------------
   01A2                     546 _delay_timer:
                            547 ;	../rm_app.c:92: RTCCON=0x60;		// RTC anhalten und Flag löschen
   01A2 75 D1 60            548 	mov	_RTCCON,#0x60
                            549 ;	../rm_app.c:93: RTCH=0xE1;			// reload Real Time Clock (1s=0xE100)
   01A5 75 D2 E1            550 	mov	_RTCH,#0xE1
                            551 ;	../rm_app.c:94: RTCL=0x00;
   01A8 75 D3 00            552 	mov	_RTCL,#0x00
                            553 ;	../rm_app.c:96: timer++;			// Zählervariable jede Sekunde hochzählen
   01AB 05 08               554 	inc	_timer
   01AD E4                  555 	clr	a
   01AE B5 08 02            556 	cjne	a,_timer,00121$
   01B1 05 09               557 	inc	(_timer + 1)
   01B3                     558 00121$:
                            559 ;	../rm_app.c:98: if (timer_alarm==timer && eeprom[A_ZYKLISCH]) {		// wenn Alarm zyklisch gesendet werden soll
   01B3 E5 08               560 	mov	a,_timer
   01B5 B5 0A 41            561 	cjne	a,_timer_alarm,00105$
   01B8 E5 09               562 	mov	a,(_timer + 1)
   01BA B5 0B 3C            563 	cjne	a,(_timer_alarm + 1),00105$
   01BD 90 1D F4            564 	mov	dptr,#(_eeprom + 0x00f4)
   01C0 E4                  565 	clr	a
   01C1 93                  566 	movc	a,@a+dptr
   01C2 60 35               567 	jz	00105$
                            568 ;	../rm_app.c:99: send_obj_value(0);
   01C4 75 82 00            569 	mov	dpl,#0x00
   01C7 12 09 1E            570 	lcall	_send_obj_value
                            571 ;	../rm_app.c:100: if (eeprom[A_BASIS]) timer_alarm=timer+eeprom[A_FAKTOR]*60;	// Minuten
   01CA 90 1D F6            572 	mov	dptr,#(_eeprom + 0x00f6)
   01CD E4                  573 	clr	a
   01CE 93                  574 	movc	a,@a+dptr
   01CF 60 16               575 	jz	00102$
   01D1 90 1D F5            576 	mov	dptr,#(_eeprom + 0x00f5)
   01D4 E4                  577 	clr	a
   01D5 93                  578 	movc	a,@a+dptr
   01D6 FA                  579 	mov	r2,a
   01D7 75 F0 3C            580 	mov	b,#0x3C
   01DA A4                  581 	mul	ab
   01DB 25 08               582 	add	a,_timer
   01DD F5 0A               583 	mov	_timer_alarm,a
   01DF E5 09               584 	mov	a,(_timer + 1)
   01E1 35 F0               585 	addc	a,b
   01E3 F5 0B               586 	mov	(_timer_alarm + 1),a
   01E5 80 12               587 	sjmp	00105$
   01E7                     588 00102$:
                            589 ;	../rm_app.c:101: else timer_alarm=timer+eeprom[A_FAKTOR];					// Sekunden
   01E7 90 1D F5            590 	mov	dptr,#(_eeprom + 0x00f5)
   01EA E4                  591 	clr	a
   01EB 93                  592 	movc	a,@a+dptr
   01EC FA                  593 	mov	r2,a
   01ED 7B 00               594 	mov	r3,#0x00
   01EF EA                  595 	mov	a,r2
   01F0 25 08               596 	add	a,_timer
   01F2 F5 0A               597 	mov	_timer_alarm,a
   01F4 EB                  598 	mov	a,r3
   01F5 35 09               599 	addc	a,(_timer + 1)
   01F7 F5 0B               600 	mov	(_timer_alarm + 1),a
   01F9                     601 00105$:
                            602 ;	../rm_app.c:103: if (timer_stoerung==timer && eeprom[S_ZYKLISCH]) {	// wenn Störung zyklisch gesendet werden soll
   01F9 E5 08               603 	mov	a,_timer
   01FB B5 0C 41            604 	cjne	a,_timer_stoerung,00111$
   01FE E5 09               605 	mov	a,(_timer + 1)
   0200 B5 0D 3C            606 	cjne	a,(_timer_stoerung + 1),00111$
   0203 90 1D F7            607 	mov	dptr,#(_eeprom + 0x00f7)
   0206 E4                  608 	clr	a
   0207 93                  609 	movc	a,@a+dptr
   0208 60 35               610 	jz	00111$
                            611 ;	../rm_app.c:104: send_obj_value(1);
   020A 75 82 01            612 	mov	dpl,#0x01
   020D 12 09 1E            613 	lcall	_send_obj_value
                            614 ;	../rm_app.c:105: if (eeprom[S_BASIS]) timer_stoerung=timer+eeprom[S_FAKTOR]*60;	// Minuten
   0210 90 1D F9            615 	mov	dptr,#(_eeprom + 0x00f9)
   0213 E4                  616 	clr	a
   0214 93                  617 	movc	a,@a+dptr
   0215 60 16               618 	jz	00108$
   0217 90 1D F8            619 	mov	dptr,#(_eeprom + 0x00f8)
   021A E4                  620 	clr	a
   021B 93                  621 	movc	a,@a+dptr
   021C FA                  622 	mov	r2,a
   021D 75 F0 3C            623 	mov	b,#0x3C
   0220 A4                  624 	mul	ab
   0221 25 08               625 	add	a,_timer
   0223 F5 0C               626 	mov	_timer_stoerung,a
   0225 E5 09               627 	mov	a,(_timer + 1)
   0227 35 F0               628 	addc	a,b
   0229 F5 0D               629 	mov	(_timer_stoerung + 1),a
   022B 80 12               630 	sjmp	00111$
   022D                     631 00108$:
                            632 ;	../rm_app.c:106: else timer_stoerung=timer+eeprom[S_FAKTOR];						// Sekunden
   022D 90 1D F8            633 	mov	dptr,#(_eeprom + 0x00f8)
   0230 E4                  634 	clr	a
   0231 93                  635 	movc	a,@a+dptr
   0232 FA                  636 	mov	r2,a
   0233 7B 00               637 	mov	r3,#0x00
   0235 EA                  638 	mov	a,r2
   0236 25 08               639 	add	a,_timer
   0238 F5 0C               640 	mov	_timer_stoerung,a
   023A EB                  641 	mov	a,r3
   023B 35 09               642 	addc	a,(_timer + 1)
   023D F5 0D               643 	mov	(_timer_stoerung + 1),a
   023F                     644 00111$:
                            645 ;	../rm_app.c:108: RTCCON=0x61;		// RTC starten
   023F 75 D1 61            646 	mov	_RTCCON,#0x61
   0242 22                  647 	ret
                            648 ;------------------------------------------------------------
                            649 ;Allocation info for local variables in function 'restart_app'
                            650 ;------------------------------------------------------------
                            651 ;------------------------------------------------------------
                            652 ;	../rm_app.c:112: void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
                            653 ;	-----------------------------------------
                            654 ;	 function restart_app
                            655 ;	-----------------------------------------
   0243                     656 _restart_app:
                            657 ;	../rm_app.c:114: P0M1= 0x00;			// alle Pins von Port0 als bidirectional definieren,
   0243 75 84 00            658 	mov	_P0M1,#0x00
                            659 ;	../rm_app.c:115: P0M2= 0x00;
   0246 75 85 00            660 	mov	_P0M2,#0x00
                            661 ;	../rm_app.c:116: P0= 0xFF;
   0249 75 80 FF            662 	mov	_P0,#0xFF
                            663 ;	../rm_app.c:120: alarm=0;
   024C C2 01               664 	clr	_alarm
                            665 ;	../rm_app.c:121: stoerung=0;
   024E C2 02               666 	clr	_stoerung
                            667 ;	../rm_app.c:122: alarm_obj=0;
   0250 C2 03               668 	clr	_alarm_obj
                            669 ;	../rm_app.c:123: stoerung_obj=0;
   0252 C2 04               670 	clr	_stoerung_obj
                            671 ;	../rm_app.c:124: event=0;
   0254 C2 00               672 	clr	_event
                            673 ;	../rm_app.c:125: fernalarm=0;
   0256 C2 05               674 	clr	_fernalarm
                            675 ;	../rm_app.c:126: PIN_DATA=1;		// Fernauslösung Alarm ausschalten
   0258 D2 92               676 	setb	_P1_2
                            677 ;	../rm_app.c:129: KBMASK=0x03;	// P0.0 & P0.1 enabled for KB-Interrupt
   025A 75 86 03            678 	mov	_KBMASK,#0x03
                            679 ;	../rm_app.c:130: KBPATN=0x03;	// Pattern
   025D 75 93 03            680 	mov	_KBPATN,#0x03
                            681 ;	../rm_app.c:131: KBCON=0;		// Interrupt when port not equal to pattern
   0260 75 94 00            682 	mov	_KBCON,#0x00
                            683 ;	../rm_app.c:132: EKBI=1;
   0263 D2 E9               684 	setb	_IEN1_1
                            685 ;	../rm_app.c:134: RTCH=0xE1;		// Real Time Clock auf 1s laden
   0265 75 D2 E1            686 	mov	_RTCH,#0xE1
                            687 ;	../rm_app.c:135: RTCL=0x00;		// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
   0268 75 D3 00            688 	mov	_RTCL,#0x00
                            689 ;	../rm_app.c:136: RTCCON=0x61;	// ... und starten
   026B 75 D1 61            690 	mov	_RTCCON,#0x61
                            691 ;	../rm_app.c:138: timer=0;
   026E E4                  692 	clr	a
   026F F5 08               693 	mov	_timer,a
   0271 F5 09               694 	mov	(_timer + 1),a
                            695 ;	../rm_app.c:139: if (eeprom[A_ZYKLISCH]) timer_alarm=timer+2;
   0273 90 1D F4            696 	mov	dptr,#(_eeprom + 0x00f4)
   0276 E4                  697 	clr	a
   0277 93                  698 	movc	a,@a+dptr
   0278 60 06               699 	jz	00102$
   027A 75 0A 02            700 	mov	_timer_alarm,#0x02
   027D E4                  701 	clr	a
   027E F5 0B               702 	mov	(_timer_alarm + 1),a
   0280                     703 00102$:
                            704 ;	../rm_app.c:140: if (eeprom[S_ZYKLISCH]) timer_stoerung=timer+4;
   0280 90 1D F7            705 	mov	dptr,#(_eeprom + 0x00f7)
   0283 E4                  706 	clr	a
   0284 93                  707 	movc	a,@a+dptr
   0285 60 06               708 	jz	00104$
   0287 75 0C 04            709 	mov	_timer_stoerung,#0x04
   028A E4                  710 	clr	a
   028B F5 0D               711 	mov	(_timer_stoerung + 1),a
   028D                     712 00104$:
                            713 ;	../rm_app.c:143: EA=0;						// Interrupts sperren, damit flashen nicht unterbrochen wird
   028D C2 AF               714 	clr	_IEN0_7
                            715 ;	../rm_app.c:144: START_WRITECYCLE;
   028F 75 E4 00            716 	mov	_FMCON,#0x00
                            717 ;	../rm_app.c:145: WRITE_BYTE(0x01,0x03,0x00);	// Herstellercode 0x0000 = Freebus
   0292 75 E7 1D            718 	mov	_FMADRH,#0x1D
   0295 75 E6 03            719 	mov	_FMADRL,#0x03
   0298 75 E5 00            720 	mov	_FMDATA,#0x00
                            721 ;	../rm_app.c:146: WRITE_BYTE(0x01,0x04,0x00);
   029B 75 E7 1D            722 	mov	_FMADRH,#0x1D
   029E 75 E6 04            723 	mov	_FMADRL,#0x04
   02A1 75 E5 00            724 	mov	_FMDATA,#0x00
                            725 ;	../rm_app.c:147: WRITE_BYTE(0x01,0x05,0x10);	// Devicetype 0x1003
   02A4 75 E7 1D            726 	mov	_FMADRH,#0x1D
   02A7 75 E6 05            727 	mov	_FMADRL,#0x05
   02AA 75 E5 10            728 	mov	_FMDATA,#0x10
                            729 ;	../rm_app.c:148: WRITE_BYTE(0x01,0x06,0x03);
   02AD 75 E7 1D            730 	mov	_FMADRH,#0x1D
   02B0 75 E6 06            731 	mov	_FMADRL,#0x06
   02B3 75 E5 03            732 	mov	_FMDATA,#0x03
                            733 ;	../rm_app.c:149: WRITE_BYTE(0x01,0x07,0x01);	// Versionnumber of application programm
   02B6 75 E7 1D            734 	mov	_FMADRH,#0x1D
   02B9 75 E6 07            735 	mov	_FMADRL,#0x07
   02BC 75 E5 01            736 	mov	_FMDATA,#0x01
                            737 ;	../rm_app.c:150: WRITE_BYTE(0x01,0x0C,0x00);	// PORT A Direction Bit Setting
   02BF 75 E7 1D            738 	mov	_FMADRH,#0x1D
   02C2 75 E6 0C            739 	mov	_FMADRL,#0x0C
   02C5 75 E5 00            740 	mov	_FMDATA,#0x00
                            741 ;	../rm_app.c:151: WRITE_BYTE(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
   02C8 75 E7 1D            742 	mov	_FMADRH,#0x1D
   02CB 75 E6 0D            743 	mov	_FMADRL,#0x0D
   02CE 75 E5 FF            744 	mov	_FMDATA,#0xFF
                            745 ;	../rm_app.c:152: WRITE_BYTE(0x01,0x12,0xA0);	// COMMSTAB Pointer
   02D1 75 E7 1D            746 	mov	_FMADRH,#0x1D
   02D4 75 E6 12            747 	mov	_FMADRL,#0x12
   02D7 75 E5 A0            748 	mov	_FMDATA,#0xA0
                            749 ;	../rm_app.c:153: STOP_WRITECYCLE;
   02DA 75 E4 68            750 	mov	_FMCON,#0x68
                            751 ;	../rm_app.c:154: EA=1;						// Interrupts freigeben
   02DD D2 AF               752 	setb	_IEN0_7
   02DF 22                  753 	ret
                            754 	.area CSEG    (CODE)
                            755 	.area CONST   (CODE)
                            756 	.area XINIT   (CODE)
                            757 	.area CABS    (ABS,CODE)
