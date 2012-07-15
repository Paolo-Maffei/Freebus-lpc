                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
                              4 ; This file was generated Sun Jul 15 18:49:21 2012
                              5 ;--------------------------------------------------------
                              6 	.module app_kombi
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _ctrl_adr
                             13 	.globl _luxdelay
                             14 	.globl _hystable
                             15 	.globl _luxtable
                             16 	.globl _cycleval
                             17 	.globl _P3_1
                             18 	.globl _P3_0
                             19 	.globl _P1_7
                             20 	.globl _P1_6
                             21 	.globl _P1_5
                             22 	.globl _P1_4
                             23 	.globl _P1_3
                             24 	.globl _P1_2
                             25 	.globl _P1_1
                             26 	.globl _P1_0
                             27 	.globl _P0_7
                             28 	.globl _P0_6
                             29 	.globl _P0_5
                             30 	.globl _P0_4
                             31 	.globl _P0_3
                             32 	.globl _P0_2
                             33 	.globl _P0_1
                             34 	.globl _P0_0
                             35 	.globl _I2CON_0
                             36 	.globl _I2CON_2
                             37 	.globl _I2CON_3
                             38 	.globl _I2CON_4
                             39 	.globl _I2CON_5
                             40 	.globl _I2CON_6
                             41 	.globl _SCON_7
                             42 	.globl _SCON_6
                             43 	.globl _SCON_5
                             44 	.globl _SCON_4
                             45 	.globl _SCON_3
                             46 	.globl _SCON_2
                             47 	.globl _SCON_1
                             48 	.globl _SCON_0
                             49 	.globl _IP0_0
                             50 	.globl _IP0_1
                             51 	.globl _IP0_2
                             52 	.globl _IP0_3
                             53 	.globl _IP0_4
                             54 	.globl _IP0_5
                             55 	.globl _IP0_6
                             56 	.globl _IP1_0
                             57 	.globl _IP1_1
                             58 	.globl _IP1_2
                             59 	.globl _IP1_6
                             60 	.globl _IEN1_0
                             61 	.globl _IEN1_1
                             62 	.globl _IEN1_2
                             63 	.globl _IEN0_0
                             64 	.globl _IEN0_1
                             65 	.globl _IEN0_2
                             66 	.globl _IEN0_3
                             67 	.globl _IEN0_4
                             68 	.globl _IEN0_5
                             69 	.globl _IEN0_6
                             70 	.globl _IEN0_7
                             71 	.globl _TCON_0
                             72 	.globl _TCON_1
                             73 	.globl _TCON_2
                             74 	.globl _TCON_3
                             75 	.globl _TCON_4
                             76 	.globl _TCON_5
                             77 	.globl _TCON_6
                             78 	.globl _TCON_7
                             79 	.globl _PSW_7
                             80 	.globl _PSW_6
                             81 	.globl _PSW_5
                             82 	.globl _PSW_4
                             83 	.globl _PSW_3
                             84 	.globl _PSW_2
                             85 	.globl _PSW_1
                             86 	.globl _PSW_0
                             87 	.globl _IEN1
                             88 	.globl _IP0H
                             89 	.globl _WFEED2
                             90 	.globl _WFEED1
                             91 	.globl _WDL
                             92 	.globl _WDCON
                             93 	.globl _TRIM
                             94 	.globl _TAMOD
                             95 	.globl _SSTAT
                             96 	.globl _RTCL
                             97 	.globl _RTCH
                             98 	.globl _RTCCON
                             99 	.globl _RSTSRC
                            100 	.globl _PT0AD
                            101 	.globl _PCONA
                            102 	.globl _P3M2
                            103 	.globl _P3M1
                            104 	.globl _P1M2
                            105 	.globl _P1M1
                            106 	.globl _P0M2
                            107 	.globl _P0M1
                            108 	.globl _KBPATN
                            109 	.globl _KBMASK
                            110 	.globl _KBCON
                            111 	.globl _IP1H
                            112 	.globl _IP1
                            113 	.globl _I2STAT
                            114 	.globl _I2SCLL
                            115 	.globl _I2SCLH
                            116 	.globl _I2DAT
                            117 	.globl _I2CON
                            118 	.globl _I2ADR
                            119 	.globl _FMDATA
                            120 	.globl _FMCON
                            121 	.globl _FMADRL
                            122 	.globl _FMADRH
                            123 	.globl _DIVM
                            124 	.globl _CMP2
                            125 	.globl _CMP1
                            126 	.globl _BRGCON
                            127 	.globl _BRGR1
                            128 	.globl _BRGR0
                            129 	.globl _SADEN
                            130 	.globl _SADDR
                            131 	.globl _AUXR1
                            132 	.globl _SBUF
                            133 	.globl _SCON
                            134 	.globl _IP0
                            135 	.globl _IEN0
                            136 	.globl _TH1
                            137 	.globl _TH0
                            138 	.globl _TL1
                            139 	.globl _TL0
                            140 	.globl _TMOD
                            141 	.globl _TCON
                            142 	.globl _PCON
                            143 	.globl _DPH
                            144 	.globl _DPL
                            145 	.globl _SP
                            146 	.globl _B
                            147 	.globl _ACC
                            148 	.globl _PSW
                            149 	.globl _P3
                            150 	.globl _P1
                            151 	.globl _P0
                            152 	.globl _resend
                            153 	.globl _lockatt
                            154 	.globl _sequence
                            155 	.globl _dimmwert
                            156 	.globl _underrun
                            157 	.globl _overrun
                            158 	.globl _delrec
                            159 	.globl _global_object_value_3_to_10
                            160 	.globl _global_object_value_0_to_1
                            161 	.globl _schwelle
                            162 	.globl _read_obj_value
                            163 	.globl _write_obj_value
                            164 	.globl _read_value_req
                            165 	.globl _write_value_req
                            166 	.globl _delay_timer
                            167 	.globl _restart_app
                            168 ;--------------------------------------------------------
                            169 ; special function registers
                            170 ;--------------------------------------------------------
                            171 	.area RSEG    (DATA)
                    0080    172 _P0	=	0x0080
                    0090    173 _P1	=	0x0090
                    00B0    174 _P3	=	0x00b0
                    00D0    175 _PSW	=	0x00d0
                    00E0    176 _ACC	=	0x00e0
                    00F0    177 _B	=	0x00f0
                    0081    178 _SP	=	0x0081
                    0082    179 _DPL	=	0x0082
                    0083    180 _DPH	=	0x0083
                    0087    181 _PCON	=	0x0087
                    0088    182 _TCON	=	0x0088
                    0089    183 _TMOD	=	0x0089
                    008A    184 _TL0	=	0x008a
                    008B    185 _TL1	=	0x008b
                    008C    186 _TH0	=	0x008c
                    008D    187 _TH1	=	0x008d
                    00A8    188 _IEN0	=	0x00a8
                    00B8    189 _IP0	=	0x00b8
                    0098    190 _SCON	=	0x0098
                    0099    191 _SBUF	=	0x0099
                    00A2    192 _AUXR1	=	0x00a2
                    00A9    193 _SADDR	=	0x00a9
                    00B9    194 _SADEN	=	0x00b9
                    00BE    195 _BRGR0	=	0x00be
                    00BF    196 _BRGR1	=	0x00bf
                    00BD    197 _BRGCON	=	0x00bd
                    00AC    198 _CMP1	=	0x00ac
                    00AD    199 _CMP2	=	0x00ad
                    0095    200 _DIVM	=	0x0095
                    00E7    201 _FMADRH	=	0x00e7
                    00E6    202 _FMADRL	=	0x00e6
                    00E4    203 _FMCON	=	0x00e4
                    00E5    204 _FMDATA	=	0x00e5
                    00DB    205 _I2ADR	=	0x00db
                    00D8    206 _I2CON	=	0x00d8
                    00DA    207 _I2DAT	=	0x00da
                    00DD    208 _I2SCLH	=	0x00dd
                    00DC    209 _I2SCLL	=	0x00dc
                    00D9    210 _I2STAT	=	0x00d9
                    00F8    211 _IP1	=	0x00f8
                    00F7    212 _IP1H	=	0x00f7
                    0094    213 _KBCON	=	0x0094
                    0086    214 _KBMASK	=	0x0086
                    0093    215 _KBPATN	=	0x0093
                    0084    216 _P0M1	=	0x0084
                    0085    217 _P0M2	=	0x0085
                    0091    218 _P1M1	=	0x0091
                    0092    219 _P1M2	=	0x0092
                    00B1    220 _P3M1	=	0x00b1
                    00B2    221 _P3M2	=	0x00b2
                    00B5    222 _PCONA	=	0x00b5
                    00F6    223 _PT0AD	=	0x00f6
                    00DF    224 _RSTSRC	=	0x00df
                    00D1    225 _RTCCON	=	0x00d1
                    00D2    226 _RTCH	=	0x00d2
                    00D3    227 _RTCL	=	0x00d3
                    00BA    228 _SSTAT	=	0x00ba
                    008F    229 _TAMOD	=	0x008f
                    0096    230 _TRIM	=	0x0096
                    00A7    231 _WDCON	=	0x00a7
                    00C1    232 _WDL	=	0x00c1
                    00C2    233 _WFEED1	=	0x00c2
                    00C3    234 _WFEED2	=	0x00c3
                    00B7    235 _IP0H	=	0x00b7
                    00E8    236 _IEN1	=	0x00e8
                            237 ;--------------------------------------------------------
                            238 ; special function bits
                            239 ;--------------------------------------------------------
                            240 	.area RSEG    (DATA)
                    00D0    241 _PSW_0	=	0x00d0
                    00D1    242 _PSW_1	=	0x00d1
                    00D2    243 _PSW_2	=	0x00d2
                    00D3    244 _PSW_3	=	0x00d3
                    00D4    245 _PSW_4	=	0x00d4
                    00D5    246 _PSW_5	=	0x00d5
                    00D6    247 _PSW_6	=	0x00d6
                    00D7    248 _PSW_7	=	0x00d7
                    008F    249 _TCON_7	=	0x008f
                    008E    250 _TCON_6	=	0x008e
                    008D    251 _TCON_5	=	0x008d
                    008C    252 _TCON_4	=	0x008c
                    008B    253 _TCON_3	=	0x008b
                    008A    254 _TCON_2	=	0x008a
                    0089    255 _TCON_1	=	0x0089
                    0088    256 _TCON_0	=	0x0088
                    00AF    257 _IEN0_7	=	0x00af
                    00AE    258 _IEN0_6	=	0x00ae
                    00AD    259 _IEN0_5	=	0x00ad
                    00AC    260 _IEN0_4	=	0x00ac
                    00AB    261 _IEN0_3	=	0x00ab
                    00AA    262 _IEN0_2	=	0x00aa
                    00A9    263 _IEN0_1	=	0x00a9
                    00A8    264 _IEN0_0	=	0x00a8
                    00EA    265 _IEN1_2	=	0x00ea
                    00E9    266 _IEN1_1	=	0x00e9
                    00E8    267 _IEN1_0	=	0x00e8
                    00FE    268 _IP1_6	=	0x00fe
                    00FA    269 _IP1_2	=	0x00fa
                    00F9    270 _IP1_1	=	0x00f9
                    00F8    271 _IP1_0	=	0x00f8
                    00BE    272 _IP0_6	=	0x00be
                    00BD    273 _IP0_5	=	0x00bd
                    00BC    274 _IP0_4	=	0x00bc
                    00BB    275 _IP0_3	=	0x00bb
                    00BA    276 _IP0_2	=	0x00ba
                    00B9    277 _IP0_1	=	0x00b9
                    00B8    278 _IP0_0	=	0x00b8
                    0098    279 _SCON_0	=	0x0098
                    0099    280 _SCON_1	=	0x0099
                    009A    281 _SCON_2	=	0x009a
                    009B    282 _SCON_3	=	0x009b
                    009C    283 _SCON_4	=	0x009c
                    009D    284 _SCON_5	=	0x009d
                    009E    285 _SCON_6	=	0x009e
                    009F    286 _SCON_7	=	0x009f
                    00DE    287 _I2CON_6	=	0x00de
                    00DD    288 _I2CON_5	=	0x00dd
                    00DC    289 _I2CON_4	=	0x00dc
                    00DB    290 _I2CON_3	=	0x00db
                    00DA    291 _I2CON_2	=	0x00da
                    00D8    292 _I2CON_0	=	0x00d8
                    0080    293 _P0_0	=	0x0080
                    0081    294 _P0_1	=	0x0081
                    0082    295 _P0_2	=	0x0082
                    0083    296 _P0_3	=	0x0083
                    0084    297 _P0_4	=	0x0084
                    0085    298 _P0_5	=	0x0085
                    0086    299 _P0_6	=	0x0086
                    0087    300 _P0_7	=	0x0087
                    0090    301 _P1_0	=	0x0090
                    0091    302 _P1_1	=	0x0091
                    0092    303 _P1_2	=	0x0092
                    0093    304 _P1_3	=	0x0093
                    0094    305 _P1_4	=	0x0094
                    0095    306 _P1_5	=	0x0095
                    0096    307 _P1_6	=	0x0096
                    0097    308 _P1_7	=	0x0097
                    00B0    309 _P3_0	=	0x00b0
                    00B1    310 _P3_1	=	0x00b1
                            311 ;--------------------------------------------------------
                            312 ; overlayable register banks
                            313 ;--------------------------------------------------------
                            314 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     315 	.ds 8
                            316 ;--------------------------------------------------------
                            317 ; overlayable bit register bank
                            318 ;--------------------------------------------------------
                            319 	.area BIT_BANK	(REL,OVR,DATA)
   0023                     320 bits:
   0023                     321 	.ds 1
                    8000    322 	b0 = bits[0]
                    8100    323 	b1 = bits[1]
                    8200    324 	b2 = bits[2]
                    8300    325 	b3 = bits[3]
                    8400    326 	b4 = bits[4]
                    8500    327 	b5 = bits[5]
                    8600    328 	b6 = bits[6]
                    8700    329 	b7 = bits[7]
                            330 ;--------------------------------------------------------
                            331 ; internal ram data
                            332 ;--------------------------------------------------------
                            333 	.area DSEG    (DATA)
   0024                     334 _global_object_value_0_to_1::
   0024                     335 	.ds 4
   0028                     336 _global_object_value_3_to_10::
   0028                     337 	.ds 1
   0029                     338 _delrec::
   0029                     339 	.ds 36
                            340 ;--------------------------------------------------------
                            341 ; overlayable items in internal ram 
                            342 ;--------------------------------------------------------
                            343 	.area OSEG    (OVR,DATA)
                            344 ;--------------------------------------------------------
                            345 ; indirectly addressable internal ram data
                            346 ;--------------------------------------------------------
                            347 	.area ISEG    (DATA)
   007C                     348 _overrun::
   007C                     349 	.ds 1
   007D                     350 _underrun::
   007D                     351 	.ds 1
   007E                     352 _dimmwert::
   007E                     353 	.ds 1
   007F                     354 _sequence::
   007F                     355 	.ds 1
   0080                     356 _lockatt::
   0080                     357 	.ds 1
   0081                     358 _resend::
   0081                     359 	.ds 1
                            360 ;--------------------------------------------------------
                            361 ; absolute internal ram data
                            362 ;--------------------------------------------------------
                            363 	.area IABS    (ABS,DATA)
                            364 	.area IABS    (ABS,DATA)
                            365 ;--------------------------------------------------------
                            366 ; bit data
                            367 ;--------------------------------------------------------
                            368 	.area BSEG    (BIT)
                            369 ;--------------------------------------------------------
                            370 ; paged external ram data
                            371 ;--------------------------------------------------------
                            372 	.area PSEG    (PAG,XDATA)
                            373 ;--------------------------------------------------------
                            374 ; external ram data
                            375 ;--------------------------------------------------------
                            376 	.area XSEG    (XDATA)
                            377 ;--------------------------------------------------------
                            378 ; absolute external ram data
                            379 ;--------------------------------------------------------
                            380 	.area XABS    (ABS,XDATA)
                            381 ;--------------------------------------------------------
                            382 ; external initialized ram data
                            383 ;--------------------------------------------------------
                            384 	.area XISEG   (XDATA)
                            385 	.area HOME    (CODE)
                            386 	.area GSINIT0 (CODE)
                            387 	.area GSINIT1 (CODE)
                            388 	.area GSINIT2 (CODE)
                            389 	.area GSINIT3 (CODE)
                            390 	.area GSINIT4 (CODE)
                            391 	.area GSINIT5 (CODE)
                            392 	.area GSINIT  (CODE)
                            393 	.area GSFINAL (CODE)
                            394 	.area CSEG    (CODE)
                            395 ;--------------------------------------------------------
                            396 ; global & static initialisations
                            397 ;--------------------------------------------------------
                            398 	.area HOME    (CODE)
                            399 	.area GSINIT  (CODE)
                            400 	.area GSFINAL (CODE)
                            401 	.area GSINIT  (CODE)
                            402 ;--------------------------------------------------------
                            403 ; Home
                            404 ;--------------------------------------------------------
                            405 	.area HOME    (CODE)
                            406 	.area HOME    (CODE)
                            407 ;--------------------------------------------------------
                            408 ; code
                            409 ;--------------------------------------------------------
                            410 	.area CSEG    (CODE)
                            411 ;------------------------------------------------------------
                            412 ;Allocation info for local variables in function 'schwelle'
                            413 ;------------------------------------------------------------
                            414 ;objno                     Allocated to registers r2 
                            415 ;ctrl                      Allocated to stack - offset 1
                            416 ;bitmask                   Allocated to registers r5 
                            417 ;temp_compare              Allocated to registers r7 
                            418 ;lux_compare               Allocated to registers r6 
                            419 ;lastdimm                  Allocated to registers r2 
                            420 ;step                      Allocated to registers r3 
                            421 ;value                     Allocated to registers r6 
                            422 ;offset                    Allocated to registers r5 
                            423 ;over                      Allocated to registers b0 
                            424 ;under                     Allocated to registers b1 
                            425 ;valid                     Allocated to registers b2 
                            426 ;active                    Allocated to stack - offset 2
                            427 ;schwellwert               Allocated to stack - offset 3
                            428 ;schwellwert_temp          Allocated to registers r6 r7 
                            429 ;hysterese                 Allocated to stack - offset 5
                            430 ;delay                     Allocated to registers r3 r4 
                            431 ;sloc0                     Allocated to stack - offset 22
                            432 ;------------------------------------------------------------
                            433 ;	../app_kombi.c:52: void schwelle(unsigned char objno)		// Luxschwelle prüfen und reagieren
                            434 ;	-----------------------------------------
                            435 ;	 function schwelle
                            436 ;	-----------------------------------------
   0111                     437 _schwelle:
                    0002    438 	ar2 = 0x02
                    0003    439 	ar3 = 0x03
                    0004    440 	ar4 = 0x04
                    0005    441 	ar5 = 0x05
                    0006    442 	ar6 = 0x06
                    0007    443 	ar7 = 0x07
                    0000    444 	ar0 = 0x00
                    0001    445 	ar1 = 0x01
   0111 C0 1A               446 	push	_bp
   0113 E5 81               447 	mov	a,sp
   0115 F5 1A               448 	mov	_bp,a
   0117 24 06               449 	add	a,#0x06
   0119 F5 81               450 	mov	sp,a
   011B AA 82               451 	mov	r2,dpl
                            452 ;	../app_kombi.c:57: __bit over=0, under=0, valid;
   011D C2 18               453 	clr	b0
   011F C2 19               454 	clr	b1
                            455 ;	../app_kombi.c:61: unsigned int hysterese=0, delay=0;
                            456 ;	../app_kombi.c:64: offset=(objno-3)*5;
   0121 E4                  457 	clr	a
   0122 FB                  458 	mov	r3,a
   0123 FC                  459 	mov	r4,a
   0124 EA                  460 	mov	a,r2
   0125 24 FD               461 	add	a,#0xfd
   0127 75 F0 05            462 	mov	b,#0x05
   012A A4                  463 	mul	ab
   012B FD                  464 	mov	r5,a
                            465 ;	../app_kombi.c:65: if (objno==9) offset++;        // da Verssatz in der Reihenfolge der Parameter
   012C BA 09 01            466 	cjne	r2,#0x09,00102$
   012F 0D                  467 	inc	r5
   0130                     468 00102$:
                            469 ;	../app_kombi.c:67: ctrl=eeprom[LUXCTRL-offset];
   0130 74 F9               470 	mov	a,#0xF9
   0132 C3                  471 	clr	c
   0133 9D                  472 	subb	a,r5
   0134 90 1D 00            473 	mov	dptr,#_eeprom
   0137 93                  474 	movc	a,@a+dptr
   0138 FE                  475 	mov	r6,a
   0139 A8 1A               476 	mov	r0,_bp
   013B 08                  477 	inc	r0
   013C A6 06               478 	mov	@r0,ar6
                            479 ;	../app_kombi.c:69: if ((eeprom[LUXPARAM]&0x80) && objno==3) {	// Helligkeitsregelung (nur Objekt1)
   013E 90 1D D3            480 	mov	dptr,#(_eeprom + 0x00d3)
   0141 E4                  481 	clr	a
   0142 93                  482 	movc	a,@a+dptr
   0143 FF                  483 	mov	r7,a
   0144 20 E7 03            484 	jb	acc.7,00271$
   0147 02 02 A5            485 	ljmp	00209$
   014A                     486 00271$:
   014A BA 03 02            487 	cjne	r2,#0x03,00272$
   014D 80 03               488 	sjmp	00273$
   014F                     489 00272$:
   014F 02 02 A5            490 	ljmp	00209$
   0152                     491 00273$:
                            492 ;	../app_kombi.c:71: lastdimm=dimmwert;		// beim letzten Durchlauf errechneter Wert
   0152 78 7E               493 	mov	r0,#_dimmwert
   0154 86 02               494 	mov	ar2,@r0
                            495 ;	../app_kombi.c:72: schwellwert=eeprom[LUXSCHWELLWERT]*10;		// schwellwert ist hier der Sollwert
   0156 90 1D FB            496 	mov	dptr,#(_eeprom + 0x00fb)
   0159 E4                  497 	clr	a
   015A 93                  498 	movc	a,@a+dptr
   015B FF                  499 	mov	r7,a
   015C A8 1A               500 	mov	r0,_bp
   015E 08                  501 	inc	r0
   015F 08                  502 	inc	r0
   0160 08                  503 	inc	r0
   0161 EF                  504 	mov	a,r7
   0162 75 F0 0A            505 	mov	b,#0x0A
   0165 A4                  506 	mul	ab
   0166 F6                  507 	mov	@r0,a
   0167 08                  508 	inc	r0
   0168 A6 F0               509 	mov	@r0,b
                            510 ;	../app_kombi.c:74: hysterese=_divuint(schwellwert,hystable[ctrl&0x07]);
   016A A8 1A               511 	mov	r0,_bp
   016C 08                  512 	inc	r0
   016D 74 07               513 	mov	a,#0x07
   016F 56                  514 	anl	a,@r0
   0170 90 1B 4F            515 	mov	dptr,#_hystable
   0173 93                  516 	movc	a,@a+dptr
   0174 FE                  517 	mov	r6,a
   0175 7F 00               518 	mov	r7,#0x00
   0177 C0 02               519 	push	ar2
   0179 C0 06               520 	push	ar6
   017B C0 07               521 	push	ar7
   017D A8 1A               522 	mov	r0,_bp
   017F 08                  523 	inc	r0
   0180 08                  524 	inc	r0
   0181 08                  525 	inc	r0
   0182 86 82               526 	mov	dpl,@r0
   0184 08                  527 	inc	r0
   0185 86 83               528 	mov	dph,@r0
   0187 12 10 AC            529 	lcall	__divuint
   018A AE 82               530 	mov	r6,dpl
   018C AF 83               531 	mov	r7,dph
   018E 15 81               532 	dec	sp
   0190 15 81               533 	dec	sp
   0192 D0 02               534 	pop	ar2
   0194 E5 1A               535 	mov	a,_bp
   0196 24 05               536 	add	a,#0x05
   0198 F8                  537 	mov	r0,a
   0199 A6 06               538 	mov	@r0,ar6
   019B 08                  539 	inc	r0
   019C A6 07               540 	mov	@r0,ar7
                            541 ;	../app_kombi.c:75: if (hysterese==0) hysterese=1;	// mindestens jedoch 1 Lux
   019E E5 1A               542 	mov	a,_bp
   01A0 24 05               543 	add	a,#0x05
   01A2 F8                  544 	mov	r0,a
   01A3 E6                  545 	mov	a,@r0
   01A4 08                  546 	inc	r0
   01A5 46                  547 	orl	a,@r0
   01A6 70 0A               548 	jnz	00104$
   01A8 E5 1A               549 	mov	a,_bp
   01AA 24 05               550 	add	a,#0x05
   01AC F8                  551 	mov	r0,a
   01AD 76 01               552 	mov	@r0,#0x01
   01AF E4                  553 	clr	a
   01B0 08                  554 	inc	r0
   01B1 F6                  555 	mov	@r0,a
   01B2                     556 00104$:
                            557 ;	../app_kombi.c:76: step=(((ctrl & 0xF0) >> 4) + 1) * 16;
   01B2 A8 1A               558 	mov	r0,_bp
   01B4 08                  559 	inc	r0
   01B5 74 F0               560 	mov	a,#0xF0
   01B7 56                  561 	anl	a,@r0
   01B8 C4                  562 	swap	a
   01B9 54 0F               563 	anl	a,#0x0f
   01BB FE                  564 	mov	r6,a
   01BC 0E                  565 	inc	r6
   01BD EE                  566 	mov	a,r6
   01BE C4                  567 	swap	a
   01BF 54 F0               568 	anl	a,#0xf0
   01C1 FB                  569 	mov	r3,a
                            570 ;	../app_kombi.c:78: if (lux>schwellwert) {	// wenn überschritten
   01C2 A8 1A               571 	mov	r0,_bp
   01C4 08                  572 	inc	r0
   01C5 08                  573 	inc	r0
   01C6 08                  574 	inc	r0
   01C7 C3                  575 	clr	c
   01C8 E6                  576 	mov	a,@r0
   01C9 95 17               577 	subb	a,_lux
   01CB 08                  578 	inc	r0
   01CC E6                  579 	mov	a,@r0
   01CD 95 18               580 	subb	a,(_lux + 1)
   01CF 50 3A               581 	jnc	00113$
                            582 ;	../app_kombi.c:79: if ((lux > (schwellwert*2)) && (dimmwert >= step)) dimmwert-=step;	// grosse Schritte wenn weit weg von Sollwert
   01D1 A8 1A               583 	mov	r0,_bp
   01D3 08                  584 	inc	r0
   01D4 08                  585 	inc	r0
   01D5 08                  586 	inc	r0
   01D6 86 06               587 	mov	ar6,@r0
   01D8 08                  588 	inc	r0
   01D9 E6                  589 	mov	a,@r0
   01DA CE                  590 	xch	a,r6
   01DB 25 E0               591 	add	a,acc
   01DD CE                  592 	xch	a,r6
   01DE 33                  593 	rlc	a
   01DF FF                  594 	mov	r7,a
   01E0 C3                  595 	clr	c
   01E1 EE                  596 	mov	a,r6
   01E2 95 17               597 	subb	a,_lux
   01E4 EF                  598 	mov	a,r7
   01E5 95 18               599 	subb	a,(_lux + 1)
   01E7 50 0F               600 	jnc	00109$
   01E9 78 7E               601 	mov	r0,#_dimmwert
   01EB C3                  602 	clr	c
   01EC E6                  603 	mov	a,@r0
   01ED 9B                  604 	subb	a,r3
   01EE 40 08               605 	jc	00109$
   01F0 78 7E               606 	mov	r0,#_dimmwert
   01F2 E6                  607 	mov	a,@r0
   01F3 C3                  608 	clr	c
   01F4 9B                  609 	subb	a,r3
   01F5 F6                  610 	mov	@r0,a
   01F6 80 13               611 	sjmp	00113$
   01F8                     612 00109$:
                            613 ;	../app_kombi.c:81: if (dimmwert>3) dimmwert-=4;		// kleine Schritte
   01F8 78 7E               614 	mov	r0,#_dimmwert
   01FA E6                  615 	mov	a,@r0
   01FB 24 FC               616 	add	a,#0xff - 0x03
   01FD 50 08               617 	jnc	00106$
   01FF 78 7E               618 	mov	r0,#_dimmwert
   0201 16                  619 	dec	@r0
   0202 16                  620 	dec	@r0
   0203 16                  621 	dec	@r0
   0204 16                  622 	dec	@r0
   0205 80 04               623 	sjmp	00113$
   0207                     624 00106$:
                            625 ;	../app_kombi.c:82: else dimmwert=0;
   0207 78 7E               626 	mov	r0,#_dimmwert
   0209 76 00               627 	mov	@r0,#0x00
   020B                     628 00113$:
                            629 ;	../app_kombi.c:85: if (lux<(schwellwert-hysterese)) {		// wenn unterschritten
   020B A8 1A               630 	mov	r0,_bp
   020D 08                  631 	inc	r0
   020E 08                  632 	inc	r0
   020F 08                  633 	inc	r0
   0210 E5 1A               634 	mov	a,_bp
   0212 24 05               635 	add	a,#0x05
   0214 F9                  636 	mov	r1,a
   0215 E6                  637 	mov	a,@r0
   0216 C3                  638 	clr	c
   0217 97                  639 	subb	a,@r1
   0218 FE                  640 	mov	r6,a
   0219 08                  641 	inc	r0
   021A E6                  642 	mov	a,@r0
   021B 09                  643 	inc	r1
   021C 97                  644 	subb	a,@r1
   021D FF                  645 	mov	r7,a
   021E C3                  646 	clr	c
   021F E5 17               647 	mov	a,_lux
   0221 9E                  648 	subb	a,r6
   0222 E5 18               649 	mov	a,(_lux + 1)
   0224 9F                  650 	subb	a,r7
   0225 50 5E               651 	jnc	00122$
                            652 ;	../app_kombi.c:86: if (((lux*2) < (schwellwert-hysterese)) && (dimmwert <= (255 - step))) dimmwert+=step;	// grosse Schritte wenn weit weg von Sollwert
   0227 E5 17               653 	mov	a,_lux
   0229 25 17               654 	add	a,_lux
   022B FC                  655 	mov	r4,a
   022C E5 18               656 	mov	a,(_lux + 1)
   022E 33                  657 	rlc	a
   022F FD                  658 	mov	r5,a
   0230 A8 1A               659 	mov	r0,_bp
   0232 08                  660 	inc	r0
   0233 08                  661 	inc	r0
   0234 08                  662 	inc	r0
   0235 E5 1A               663 	mov	a,_bp
   0237 24 05               664 	add	a,#0x05
   0239 F9                  665 	mov	r1,a
   023A E6                  666 	mov	a,@r0
   023B C3                  667 	clr	c
   023C 97                  668 	subb	a,@r1
   023D FE                  669 	mov	r6,a
   023E 08                  670 	inc	r0
   023F E6                  671 	mov	a,@r0
   0240 09                  672 	inc	r1
   0241 97                  673 	subb	a,@r1
   0242 FF                  674 	mov	r7,a
   0243 C3                  675 	clr	c
   0244 EC                  676 	mov	a,r4
   0245 9E                  677 	subb	a,r6
   0246 ED                  678 	mov	a,r5
   0247 9F                  679 	subb	a,r7
   0248 50 28               680 	jnc	00118$
   024A 8B 06               681 	mov	ar6,r3
   024C 7F 00               682 	mov	r7,#0x00
   024E 74 FF               683 	mov	a,#0xFF
   0250 C3                  684 	clr	c
   0251 9E                  685 	subb	a,r6
   0252 FC                  686 	mov	r4,a
   0253 E4                  687 	clr	a
   0254 9F                  688 	subb	a,r7
   0255 FD                  689 	mov	r5,a
   0256 78 7E               690 	mov	r0,#_dimmwert
   0258 86 06               691 	mov	ar6,@r0
   025A 7F 00               692 	mov	r7,#0x00
   025C C3                  693 	clr	c
   025D EC                  694 	mov	a,r4
   025E 9E                  695 	subb	a,r6
   025F ED                  696 	mov	a,r5
   0260 64 80               697 	xrl	a,#0x80
   0262 8F F0               698 	mov	b,r7
   0264 63 F0 80            699 	xrl	b,#0x80
   0267 95 F0               700 	subb	a,b
   0269 40 07               701 	jc	00118$
   026B 78 7E               702 	mov	r0,#_dimmwert
   026D EB                  703 	mov	a,r3
   026E 26                  704 	add	a,@r0
   026F F6                  705 	mov	@r0,a
   0270 80 13               706 	sjmp	00122$
   0272                     707 00118$:
                            708 ;	../app_kombi.c:88: if (dimmwert<252) dimmwert+=4;
   0272 78 7E               709 	mov	r0,#_dimmwert
   0274 B6 FC 00            710 	cjne	@r0,#0xFC,00282$
   0277                     711 00282$:
   0277 50 08               712 	jnc	00115$
   0279 78 7E               713 	mov	r0,#_dimmwert
   027B E6                  714 	mov	a,@r0
   027C 24 04               715 	add	a,#0x04
   027E F6                  716 	mov	@r0,a
   027F 80 04               717 	sjmp	00122$
   0281                     718 00115$:
                            719 ;	../app_kombi.c:89: else dimmwert=255;
   0281 78 7E               720 	mov	r0,#_dimmwert
   0283 76 FF               721 	mov	@r0,#0xFF
   0285                     722 00122$:
                            723 ;	../app_kombi.c:92: if (lastdimm != dimmwert) {
   0285 78 7E               724 	mov	r0,#_dimmwert
   0287 E6                  725 	mov	a,@r0
   0288 B5 02 03            726 	cjne	a,ar2,00284$
   028B 02 07 1D            727 	ljmp	00212$
   028E                     728 00284$:
                            729 ;	../app_kombi.c:93: WRITE_DELAY_RECORD(2,1,dimmwert,timer+1)
   028E 75 31 01            730 	mov	(_delrec + 0x0008),#0x01
   0291 78 7E               731 	mov	r0,#_dimmwert
   0293 86 32               732 	mov	(_delrec + 0x0009),@r0
   0295 74 01               733 	mov	a,#0x01
   0297 25 0F               734 	add	a,_timer
   0299 FE                  735 	mov	r6,a
   029A E4                  736 	clr	a
   029B 35 10               737 	addc	a,(_timer + 1)
   029D FF                  738 	mov	r7,a
   029E 8E 33               739 	mov	(_delrec + 0x000a),r6
   02A0 8F 34               740 	mov	((_delrec + 0x000a) + 1),r7
   02A2 02 07 1D            741 	ljmp	00212$
   02A5                     742 00209$:
                            743 ;	../app_kombi.c:99: if (objno<6) {	// Helligkeitsschwellen
   02A5 BA 06 00            744 	cjne	r2,#0x06,00285$
   02A8                     745 00285$:
   02A8 40 03               746 	jc	00286$
   02AA 02 03 F4            747 	ljmp	00181$
   02AD                     748 00286$:
                            749 ;	../app_kombi.c:100: schwellwert=luxtable[eeprom[LUXSCHWELLWERT-offset]-7];	// -7, weil luxtable erst ab 7 beginnt
   02AD 74 FB               750 	mov	a,#0xFB
   02AF C3                  751 	clr	c
   02B0 9D                  752 	subb	a,r5
   02B1 90 1D 00            753 	mov	dptr,#_eeprom
   02B4 93                  754 	movc	a,@a+dptr
   02B5 24 F9               755 	add	a,#0xf9
   02B7 25 E0               756 	add	a,acc
   02B9 FE                  757 	mov	r6,a
   02BA 90 1A 9B            758 	mov	dptr,#_luxtable
   02BD 93                  759 	movc	a,@a+dptr
   02BE CE                  760 	xch	a,r6
   02BF A3                  761 	inc	dptr
   02C0 93                  762 	movc	a,@a+dptr
   02C1 FF                  763 	mov	r7,a
   02C2 A8 1A               764 	mov	r0,_bp
   02C4 08                  765 	inc	r0
   02C5 08                  766 	inc	r0
   02C6 08                  767 	inc	r0
   02C7 A6 06               768 	mov	@r0,ar6
   02C9 08                  769 	inc	r0
   02CA A6 07               770 	mov	@r0,ar7
                            771 ;	../app_kombi.c:102: hysterese=_divuint(schwellwert,hystable[ctrl&0x07]);
   02CC A8 1A               772 	mov	r0,_bp
   02CE 08                  773 	inc	r0
   02CF 74 07               774 	mov	a,#0x07
   02D1 56                  775 	anl	a,@r0
   02D2 90 1B 4F            776 	mov	dptr,#_hystable
   02D5 93                  777 	movc	a,@a+dptr
   02D6 FE                  778 	mov	r6,a
   02D7 7F 00               779 	mov	r7,#0x00
   02D9 C0 02               780 	push	ar2
   02DB C0 03               781 	push	ar3
   02DD C0 04               782 	push	ar4
   02DF C0 05               783 	push	ar5
   02E1 C0 23               784 	push	bits
   02E3 C0 06               785 	push	ar6
   02E5 C0 07               786 	push	ar7
   02E7 A8 1A               787 	mov	r0,_bp
   02E9 08                  788 	inc	r0
   02EA 08                  789 	inc	r0
   02EB 08                  790 	inc	r0
   02EC 86 82               791 	mov	dpl,@r0
   02EE 08                  792 	inc	r0
   02EF 86 83               793 	mov	dph,@r0
   02F1 12 10 AC            794 	lcall	__divuint
   02F4 AE 82               795 	mov	r6,dpl
   02F6 AF 83               796 	mov	r7,dph
   02F8 15 81               797 	dec	sp
   02FA 15 81               798 	dec	sp
   02FC D0 23               799 	pop	bits
   02FE D0 05               800 	pop	ar5
   0300 D0 04               801 	pop	ar4
   0302 D0 03               802 	pop	ar3
   0304 D0 02               803 	pop	ar2
   0306 E5 1A               804 	mov	a,_bp
   0308 24 05               805 	add	a,#0x05
   030A F8                  806 	mov	r0,a
   030B A6 06               807 	mov	@r0,ar6
   030D 08                  808 	inc	r0
   030E A6 07               809 	mov	@r0,ar7
                            810 ;	../app_kombi.c:104: if (hysterese==0) hysterese=1;	// mindestens jedoch 1 Lux
   0310 E5 1A               811 	mov	a,_bp
   0312 24 05               812 	add	a,#0x05
   0314 F8                  813 	mov	r0,a
   0315 E6                  814 	mov	a,@r0
   0316 08                  815 	inc	r0
   0317 46                  816 	orl	a,@r0
   0318 70 0A               817 	jnz	00126$
   031A E5 1A               818 	mov	a,_bp
   031C 24 05               819 	add	a,#0x05
   031E F8                  820 	mov	r0,a
   031F 76 01               821 	mov	@r0,#0x01
   0321 E4                  822 	clr	a
   0322 08                  823 	inc	r0
   0323 F6                  824 	mov	@r0,a
   0324                     825 00126$:
                            826 ;	../app_kombi.c:105: if (lux>schwellwert) {
   0324 A8 1A               827 	mov	r0,_bp
   0326 08                  828 	inc	r0
   0327 08                  829 	inc	r0
   0328 08                  830 	inc	r0
   0329 C3                  831 	clr	c
   032A E6                  832 	mov	a,@r0
   032B 95 17               833 	subb	a,_lux
   032D 08                  834 	inc	r0
   032E E6                  835 	mov	a,@r0
   032F 95 18               836 	subb	a,(_lux + 1)
   0331 50 1E               837 	jnc	00128$
                            838 ;	../app_kombi.c:106: over=1;
   0333 D2 18               839 	setb	b0
                            840 ;	../app_kombi.c:107: delay=luxdelay[(eeprom[LUXCYCLE1-offset] & 0xF0) >> 4];	// Verzögerung bei überschreiten
   0335 74 FA               841 	mov	a,#0xFA
   0337 C3                  842 	clr	c
   0338 9D                  843 	subb	a,r5
   0339 90 1D 00            844 	mov	dptr,#_eeprom
   033C 93                  845 	movc	a,@a+dptr
   033D 54 F0               846 	anl	a,#0xF0
   033F C4                  847 	swap	a
   0340 54 0F               848 	anl	a,#0x0f
   0342 25 E0               849 	add	a,acc
   0344 FE                  850 	mov	r6,a
   0345 90 1B 54            851 	mov	dptr,#_luxdelay
   0348 93                  852 	movc	a,@a+dptr
   0349 CE                  853 	xch	a,r6
   034A A3                  854 	inc	dptr
   034B 93                  855 	movc	a,@a+dptr
   034C FF                  856 	mov	r7,a
   034D 8E 03               857 	mov	ar3,r6
   034F 8F 04               858 	mov	ar4,r7
   0351                     859 00128$:
                            860 ;	../app_kombi.c:109: if (lux<(schwellwert-hysterese)) under=1;
   0351 A8 1A               861 	mov	r0,_bp
   0353 08                  862 	inc	r0
   0354 08                  863 	inc	r0
   0355 08                  864 	inc	r0
   0356 E5 1A               865 	mov	a,_bp
   0358 24 05               866 	add	a,#0x05
   035A F9                  867 	mov	r1,a
   035B E6                  868 	mov	a,@r0
   035C C3                  869 	clr	c
   035D 97                  870 	subb	a,@r1
   035E FE                  871 	mov	r6,a
   035F 08                  872 	inc	r0
   0360 E6                  873 	mov	a,@r0
   0361 09                  874 	inc	r1
   0362 97                  875 	subb	a,@r1
   0363 FF                  876 	mov	r7,a
   0364 C3                  877 	clr	c
   0365 E5 17               878 	mov	a,_lux
   0367 9E                  879 	subb	a,r6
   0368 E5 18               880 	mov	a,(_lux + 1)
   036A 9F                  881 	subb	a,r7
   036B 50 02               882 	jnc	00130$
   036D D2 19               883 	setb	b1
   036F                     884 00130$:
                            885 ;	../app_kombi.c:110: switch (objno) {
   036F BA 03 02            886 	cjne	r2,#0x03,00290$
   0372 80 0D               887 	sjmp	00131$
   0374                     888 00290$:
   0374 BA 04 02            889 	cjne	r2,#0x04,00291$
   0377 80 3A               890 	sjmp	00137$
   0379                     891 00291$:
   0379 BA 05 02            892 	cjne	r2,#0x05,00292$
   037C 80 54               893 	sjmp	00140$
   037E                     894 00292$:
   037E 02 05 FD            895 	ljmp	00182$
                            896 ;	../app_kombi.c:111: case 3:
   0381                     897 00131$:
                            898 ;	../app_kombi.c:112: if ((eeprom[LUXPARAM]&0x80) == 0) {
   0381 90 1D D3            899 	mov	dptr,#(_eeprom + 0x00d3)
   0384 E4                  900 	clr	a
   0385 93                  901 	movc	a,@a+dptr
   0386 FE                  902 	mov	r6,a
   0387 20 E7 22            903 	jb	acc.7,00135$
                            904 ;	../app_kombi.c:113: if (under) delay=luxdelay[(eeprom[0xCD] & 0xF0) >> 4];
   038A 20 19 03            905 	jb	b1,00294$
   038D 02 05 FD            906 	ljmp	00182$
   0390                     907 00294$:
   0390 90 1D CD            908 	mov	dptr,#(_eeprom + 0x00cd)
   0393 E4                  909 	clr	a
   0394 93                  910 	movc	a,@a+dptr
   0395 54 F0               911 	anl	a,#0xF0
   0397 C4                  912 	swap	a
   0398 54 0F               913 	anl	a,#0x0f
   039A 25 E0               914 	add	a,acc
   039C FE                  915 	mov	r6,a
   039D 90 1B 54            916 	mov	dptr,#_luxdelay
   03A0 93                  917 	movc	a,@a+dptr
   03A1 CE                  918 	xch	a,r6
   03A2 A3                  919 	inc	dptr
   03A3 93                  920 	movc	a,@a+dptr
   03A4 FF                  921 	mov	r7,a
   03A5 8E 03               922 	mov	ar3,r6
   03A7 8F 04               923 	mov	ar4,r7
   03A9 02 05 FD            924 	ljmp	00182$
   03AC                     925 00135$:
                            926 ;	../app_kombi.c:115: else delay=0;	// bei Helligkeitsregelung keine Verzögerung
   03AC 7B 00               927 	mov	r3,#0x00
   03AE 7C 00               928 	mov	r4,#0x00
                            929 ;	../app_kombi.c:116: break;
   03B0 02 05 FD            930 	ljmp	00182$
                            931 ;	../app_kombi.c:117: case 4:
   03B3                     932 00137$:
                            933 ;	../app_kombi.c:118: if (under) delay=luxdelay[eeprom[0xCD] & 0x0F];
   03B3 20 19 03            934 	jb	b1,00295$
   03B6 02 05 FD            935 	ljmp	00182$
   03B9                     936 00295$:
   03B9 90 1D CD            937 	mov	dptr,#(_eeprom + 0x00cd)
   03BC E4                  938 	clr	a
   03BD 93                  939 	movc	a,@a+dptr
   03BE 54 0F               940 	anl	a,#0x0F
   03C0 25 E0               941 	add	a,acc
   03C2 FE                  942 	mov	r6,a
   03C3 90 1B 54            943 	mov	dptr,#_luxdelay
   03C6 93                  944 	movc	a,@a+dptr
   03C7 CE                  945 	xch	a,r6
   03C8 A3                  946 	inc	dptr
   03C9 93                  947 	movc	a,@a+dptr
   03CA FF                  948 	mov	r7,a
   03CB 8E 03               949 	mov	ar3,r6
   03CD 8F 04               950 	mov	ar4,r7
                            951 ;	../app_kombi.c:119: break;
   03CF 02 05 FD            952 	ljmp	00182$
                            953 ;	../app_kombi.c:120: case 5:
   03D2                     954 00140$:
                            955 ;	../app_kombi.c:121: if (under) delay=luxdelay[(eeprom[0xCC] & 0xF0) >> 4];
   03D2 20 19 03            956 	jb	b1,00296$
   03D5 02 05 FD            957 	ljmp	00182$
   03D8                     958 00296$:
   03D8 90 1D CC            959 	mov	dptr,#(_eeprom + 0x00cc)
   03DB E4                  960 	clr	a
   03DC 93                  961 	movc	a,@a+dptr
   03DD 54 F0               962 	anl	a,#0xF0
   03DF C4                  963 	swap	a
   03E0 54 0F               964 	anl	a,#0x0f
   03E2 25 E0               965 	add	a,acc
   03E4 FE                  966 	mov	r6,a
   03E5 90 1B 54            967 	mov	dptr,#_luxdelay
   03E8 93                  968 	movc	a,@a+dptr
   03E9 CE                  969 	xch	a,r6
   03EA A3                  970 	inc	dptr
   03EB 93                  971 	movc	a,@a+dptr
   03EC FF                  972 	mov	r7,a
   03ED 8E 03               973 	mov	ar3,r6
   03EF 8F 04               974 	mov	ar4,r7
                            975 ;	../app_kombi.c:123: }
   03F1 02 05 FD            976 	ljmp	00182$
   03F4                     977 00181$:
                            978 ;	../app_kombi.c:127: if (objno<8) {	// Temperaturschwellen
   03F4 BA 08 00            979 	cjne	r2,#0x08,00297$
   03F7                     980 00297$:
   03F7 40 03               981 	jc	00298$
   03F9 02 04 BD            982 	ljmp	00178$
   03FC                     983 00298$:
                            984 ;	../app_kombi.c:128: schwellwert_temp=(signed char)eeprom[LUXSCHWELLWERT-offset];
   03FC C0 03               985 	push	ar3
   03FE C0 04               986 	push	ar4
   0400 74 FB               987 	mov	a,#0xFB
   0402 C3                  988 	clr	c
   0403 9D                  989 	subb	a,r5
   0404 90 1D 00            990 	mov	dptr,#_eeprom
   0407 93                  991 	movc	a,@a+dptr
   0408 FE                  992 	mov	r6,a
   0409 33                  993 	rlc	a
   040A 95 E0               994 	subb	a,acc
   040C FF                  995 	mov	r7,a
                            996 ;	../app_kombi.c:129: hysterese = ctrl & 0x07;
   040D A8 1A               997 	mov	r0,_bp
   040F 08                  998 	inc	r0
   0410 74 07               999 	mov	a,#0x07
   0412 56                 1000 	anl	a,@r0
   0413 FB                 1001 	mov	r3,a
   0414 E5 1A              1002 	mov	a,_bp
   0416 24 05              1003 	add	a,#0x05
   0418 F8                 1004 	mov	r0,a
   0419 A6 03              1005 	mov	@r0,ar3
   041B 08                 1006 	inc	r0
   041C 76 00              1007 	mov	@r0,#0x00
                           1008 ;	../app_kombi.c:131: if (schwellwert_temp<51) {	//>51 : Temperaturschwelle inaktiv
   041E C3                 1009 	clr	c
   041F EE                 1010 	mov	a,r6
   0420 94 33              1011 	subb	a,#0x33
   0422 EF                 1012 	mov	a,r7
   0423 64 80              1013 	xrl	a,#0x80
   0425 94 80              1014 	subb	a,#0x80
   0427 D0 04              1015 	pop	ar4
   0429 D0 03              1016 	pop	ar3
   042B 40 03              1017 	jc	00299$
   042D 02 05 FD           1018 	ljmp	00182$
   0430                    1019 00299$:
                           1020 ;	../app_kombi.c:132: if (temp > (schwellwert_temp* (signed int)100)) over=1;
   0430 C0 06              1021 	push	ar6
   0432 C0 07              1022 	push	ar7
   0434 C0 02              1023 	push	ar2
   0436 C0 03              1024 	push	ar3
   0438 C0 04              1025 	push	ar4
   043A C0 05              1026 	push	ar5
   043C C0 23              1027 	push	bits
   043E C0 06              1028 	push	ar6
   0440 C0 07              1029 	push	ar7
   0442 90 00 64           1030 	mov	dptr,#0x0064
   0445 12 1A 63           1031 	lcall	__mulint
   0448 AE 82              1032 	mov	r6,dpl
   044A AF 83              1033 	mov	r7,dph
   044C 15 81              1034 	dec	sp
   044E 15 81              1035 	dec	sp
   0450 D0 23              1036 	pop	bits
   0452 D0 05              1037 	pop	ar5
   0454 D0 04              1038 	pop	ar4
   0456 D0 03              1039 	pop	ar3
   0458 D0 02              1040 	pop	ar2
   045A C3                 1041 	clr	c
   045B EE                 1042 	mov	a,r6
   045C 95 15              1043 	subb	a,_temp
   045E EF                 1044 	mov	a,r7
   045F 64 80              1045 	xrl	a,#0x80
   0461 85 16 F0           1046 	mov	b,(_temp + 1)
   0464 63 F0 80           1047 	xrl	b,#0x80
   0467 95 F0              1048 	subb	a,b
   0469 D0 07              1049 	pop	ar7
   046B D0 06              1050 	pop	ar6
   046D 50 02              1051 	jnc	00145$
   046F D2 18              1052 	setb	b0
   0471                    1053 00145$:
                           1054 ;	../app_kombi.c:133: if (temp < ((schwellwert_temp - (signed int)hysterese)*(signed int)100)) under=1;
   0471 E5 1A              1055 	mov	a,_bp
   0473 24 05              1056 	add	a,#0x05
   0475 F8                 1057 	mov	r0,a
   0476 EE                 1058 	mov	a,r6
   0477 C3                 1059 	clr	c
   0478 96                 1060 	subb	a,@r0
   0479 FE                 1061 	mov	r6,a
   047A EF                 1062 	mov	a,r7
   047B 08                 1063 	inc	r0
   047C 96                 1064 	subb	a,@r0
   047D FF                 1065 	mov	r7,a
   047E C0 02              1066 	push	ar2
   0480 C0 03              1067 	push	ar3
   0482 C0 04              1068 	push	ar4
   0484 C0 05              1069 	push	ar5
   0486 C0 23              1070 	push	bits
   0488 C0 06              1071 	push	ar6
   048A C0 07              1072 	push	ar7
   048C 90 00 64           1073 	mov	dptr,#0x0064
   048F 12 1A 63           1074 	lcall	__mulint
   0492 AE 82              1075 	mov	r6,dpl
   0494 AF 83              1076 	mov	r7,dph
   0496 15 81              1077 	dec	sp
   0498 15 81              1078 	dec	sp
   049A D0 23              1079 	pop	bits
   049C D0 05              1080 	pop	ar5
   049E D0 04              1081 	pop	ar4
   04A0 D0 03              1082 	pop	ar3
   04A2 D0 02              1083 	pop	ar2
   04A4 C3                 1084 	clr	c
   04A5 E5 15              1085 	mov	a,_temp
   04A7 9E                 1086 	subb	a,r6
   04A8 E5 16              1087 	mov	a,(_temp + 1)
   04AA 64 80              1088 	xrl	a,#0x80
   04AC 8F F0              1089 	mov	b,r7
   04AE 63 F0 80           1090 	xrl	b,#0x80
   04B1 95 F0              1091 	subb	a,b
   04B3 40 03              1092 	jc	00301$
   04B5 02 05 FD           1093 	ljmp	00182$
   04B8                    1094 00301$:
   04B8 D2 19              1095 	setb	b1
   04BA 02 05 FD           1096 	ljmp	00182$
   04BD                    1097 00178$:
                           1098 ;	../app_kombi.c:138: lux_compare = eeprom[0xF8-offset] & 0xF0;
   04BD 74 F8              1099 	mov	a,#0xF8
   04BF C3                 1100 	clr	c
   04C0 9D                 1101 	subb	a,r5
   04C1 90 1D 00           1102 	mov	dptr,#_eeprom
   04C4 93                 1103 	movc	a,@a+dptr
   04C5 FE                 1104 	mov	r6,a
   04C6 53 06 F0           1105 	anl	ar6,#0xF0
                           1106 ;	../app_kombi.c:139: temp_compare = eeprom[ctrl_adr[objno]+1] & 0x70;
   04C9 EA                 1107 	mov	a,r2
   04CA 90 1B 74           1108 	mov	dptr,#_ctrl_adr
   04CD 93                 1109 	movc	a,@a+dptr
   04CE 04                 1110 	inc	a
   04CF 90 1D 00           1111 	mov	dptr,#_eeprom
   04D2 93                 1112 	movc	a,@a+dptr
   04D3 FF                 1113 	mov	r7,a
   04D4 53 07 70           1114 	anl	ar7,#0x70
                           1115 ;	../app_kombi.c:142: over=1;
   04D7 D2 18              1116 	setb	b0
                           1117 ;	../app_kombi.c:143: switch (temp_compare) {
   04D9 BF 10 02           1118 	cjne	r7,#0x10,00302$
   04DC 80 0F              1119 	sjmp	00150$
   04DE                    1120 00302$:
   04DE BF 20 02           1121 	cjne	r7,#0x20,00303$
   04E1 80 13              1122 	sjmp	00151$
   04E3                    1123 00303$:
   04E3 BF 30 02           1124 	cjne	r7,#0x30,00304$
   04E6 80 17              1125 	sjmp	00152$
   04E8                    1126 00304$:
                           1127 ;	../app_kombi.c:144: case 0x10:		// 1 = größer als Temperaturschwelle 1
   04E8 BF 40 24           1128 	cjne	r7,#0x40,00154$
   04EB 80 1B              1129 	sjmp	00153$
   04ED                    1130 00150$:
                           1131 ;	../app_kombi.c:145: over = (overrun & 0x08);
   04ED 78 7C              1132 	mov	r0,#_overrun
   04EF E6                 1133 	mov	a,@r0
   04F0 A2 E3              1134 	mov	c,acc[3]
   04F2 92 18              1135 	mov	b0,c
                           1136 ;	../app_kombi.c:146: break;
                           1137 ;	../app_kombi.c:147: case 0x20:		// 2 = größer als Temperaturschwelle 2
   04F4 80 19              1138 	sjmp	00154$
   04F6                    1139 00151$:
                           1140 ;	../app_kombi.c:148: over = (overrun & 0x10);
   04F6 78 7C              1141 	mov	r0,#_overrun
   04F8 E6                 1142 	mov	a,@r0
   04F9 A2 E4              1143 	mov	c,acc[4]
   04FB 92 18              1144 	mov	b0,c
                           1145 ;	../app_kombi.c:149: break;
                           1146 ;	../app_kombi.c:150: case 0x30:		// 3 = kleiner als Temperaturschwelle 1
   04FD 80 10              1147 	sjmp	00154$
   04FF                    1148 00152$:
                           1149 ;	../app_kombi.c:151: over = (underrun & 0x08);
   04FF 78 7D              1150 	mov	r0,#_underrun
   0501 E6                 1151 	mov	a,@r0
   0502 A2 E3              1152 	mov	c,acc[3]
   0504 92 18              1153 	mov	b0,c
                           1154 ;	../app_kombi.c:152: break;
                           1155 ;	../app_kombi.c:153: case 0x40:		// 4 = kleiner als Temperaturschwelle 2
   0506 80 07              1156 	sjmp	00154$
   0508                    1157 00153$:
                           1158 ;	../app_kombi.c:154: over = (underrun & 0x10);
   0508 78 7D              1159 	mov	r0,#_underrun
   050A E6                 1160 	mov	a,@r0
   050B A2 E4              1161 	mov	c,acc[4]
   050D 92 18              1162 	mov	b0,c
                           1163 ;	../app_kombi.c:156: }
   050F                    1164 00154$:
                           1165 ;	../app_kombi.c:158: valid=1;
   050F D2 1A              1166 	setb	b2
                           1167 ;	../app_kombi.c:159: switch (lux_compare) {
   0511 BE 10 02           1168 	cjne	r6,#0x10,00306$
   0514 80 1E              1169 	sjmp	00155$
   0516                    1170 00306$:
   0516 BE 20 02           1171 	cjne	r6,#0x20,00307$
   0519 80 38              1172 	sjmp	00158$
   051B                    1173 00307$:
   051B BE 30 02           1174 	cjne	r6,#0x30,00308$
   051E 80 52              1175 	sjmp	00161$
   0520                    1176 00308$:
   0520 BE 40 02           1177 	cjne	r6,#0x40,00309$
   0523 80 6D              1178 	sjmp	00164$
   0525                    1179 00309$:
   0525 BE 50 03           1180 	cjne	r6,#0x50,00310$
   0528 02 05 B0           1181 	ljmp	00167$
   052B                    1182 00310$:
   052B BE 60 03           1183 	cjne	r6,#0x60,00311$
   052E 02 05 CF           1184 	ljmp	00170$
   0531                    1185 00311$:
   0531 02 05 ED           1186 	ljmp	00173$
                           1187 ;	../app_kombi.c:160: case 0x10:		// 1 = größer als Helligkeitsschwelle 1
   0534                    1188 00155$:
                           1189 ;	../app_kombi.c:161: if(delrec[2].delayactive & 0x04) valid=0;	// wenn Verzögerung der Helligkeitsschwelle noch aktiv, dann noch nichts senden
   0534 E5 31              1190 	mov	a,(_delrec + 0x0008)
   0536 30 E2 02           1191 	jnb	acc.2,00157$
   0539 C2 1A              1192 	clr	b2
   053B                    1193 00157$:
                           1194 ;	../app_kombi.c:162: over &= (overrun & 0x01);
   053B 78 7C              1195 	mov	r0,#_overrun
   053D E6                 1196 	mov	a,@r0
   053E 54 01              1197 	anl	a,#0x01
   0540 FE                 1198 	mov	r6,a
   0541 A2 18              1199 	mov	c,b0
   0543 E4                 1200 	clr	a
   0544 33                 1201 	rlc	a
   0545 FF                 1202 	mov	r7,a
   0546 D3                 1203 	setb	c
   0547 EE                 1204 	mov	a,r6
   0548 5F                 1205 	anl	a,r7
   0549 70 01              1206 	jnz	00313$
   054B C3                 1207 	clr	c
   054C                    1208 00313$:
   054C 92 1B              1209 	mov  b3,c
   054E 92 18              1210 	mov	b0,c
                           1211 ;	../app_kombi.c:163: break;
   0550 02 05 ED           1212 	ljmp	00173$
                           1213 ;	../app_kombi.c:164: case 0x20:		// 2 = größer als Helligkeitsschwelle 2
   0553                    1214 00158$:
                           1215 ;	../app_kombi.c:165: if(delrec[3].delayactive & 0x04) valid=0;
   0553 E5 35              1216 	mov	a,(_delrec + 0x000c)
   0555 30 E2 02           1217 	jnb	acc.2,00160$
   0558 C2 1A              1218 	clr	b2
   055A                    1219 00160$:
                           1220 ;	../app_kombi.c:166: over &= (overrun & 0x02);
   055A 78 7C              1221 	mov	r0,#_overrun
   055C E6                 1222 	mov	a,@r0
   055D 03                 1223 	rr	a
   055E 54 01              1224 	anl	a,#0x01
   0560 FE                 1225 	mov	r6,a
   0561 A2 18              1226 	mov	c,b0
   0563 E4                 1227 	clr	a
   0564 33                 1228 	rlc	a
   0565 FF                 1229 	mov	r7,a
   0566 D3                 1230 	setb	c
   0567 EE                 1231 	mov	a,r6
   0568 5F                 1232 	anl	a,r7
   0569 70 01              1233 	jnz	00315$
   056B C3                 1234 	clr	c
   056C                    1235 00315$:
   056C 92 1B              1236 	mov  b3,c
   056E 92 18              1237 	mov	b0,c
                           1238 ;	../app_kombi.c:167: break;
                           1239 ;	../app_kombi.c:168: case 0x30:		// 3 = größer als Helligkeitsschwelle 3
   0570 80 7B              1240 	sjmp	00173$
   0572                    1241 00161$:
                           1242 ;	../app_kombi.c:169: if(delrec[4].delayactive & 0x04) valid=0;
   0572 E5 39              1243 	mov	a,(_delrec + 0x0010)
   0574 30 E2 02           1244 	jnb	acc.2,00163$
   0577 C2 1A              1245 	clr	b2
   0579                    1246 00163$:
                           1247 ;	../app_kombi.c:170: over &= (overrun & 0x04);
   0579 78 7C              1248 	mov	r0,#_overrun
   057B E6                 1249 	mov	a,@r0
   057C 03                 1250 	rr	a
   057D 03                 1251 	rr	a
   057E 54 01              1252 	anl	a,#0x01
   0580 FE                 1253 	mov	r6,a
   0581 A2 18              1254 	mov	c,b0
   0583 E4                 1255 	clr	a
   0584 33                 1256 	rlc	a
   0585 FF                 1257 	mov	r7,a
   0586 D3                 1258 	setb	c
   0587 EE                 1259 	mov	a,r6
   0588 5F                 1260 	anl	a,r7
   0589 70 01              1261 	jnz	00317$
   058B C3                 1262 	clr	c
   058C                    1263 00317$:
   058C 92 1B              1264 	mov  b3,c
   058E 92 18              1265 	mov	b0,c
                           1266 ;	../app_kombi.c:171: break;
                           1267 ;	../app_kombi.c:172: case 0x40:		// 4 = kleiner als Helligkeitsschwelle 1
   0590 80 5B              1268 	sjmp	00173$
   0592                    1269 00164$:
                           1270 ;	../app_kombi.c:173: if(delrec[2].delayactive & 0x04) valid=0;
   0592 E5 31              1271 	mov	a,(_delrec + 0x0008)
   0594 30 E2 02           1272 	jnb	acc.2,00166$
   0597 C2 1A              1273 	clr	b2
   0599                    1274 00166$:
                           1275 ;	../app_kombi.c:174: over &= (underrun & 0x01);
   0599 78 7D              1276 	mov	r0,#_underrun
   059B E6                 1277 	mov	a,@r0
   059C 54 01              1278 	anl	a,#0x01
   059E FE                 1279 	mov	r6,a
   059F A2 18              1280 	mov	c,b0
   05A1 E4                 1281 	clr	a
   05A2 33                 1282 	rlc	a
   05A3 FF                 1283 	mov	r7,a
   05A4 D3                 1284 	setb	c
   05A5 EE                 1285 	mov	a,r6
   05A6 5F                 1286 	anl	a,r7
   05A7 70 01              1287 	jnz	00319$
   05A9 C3                 1288 	clr	c
   05AA                    1289 00319$:
   05AA 92 1B              1290 	mov  b3,c
   05AC 92 18              1291 	mov	b0,c
                           1292 ;	../app_kombi.c:175: break;
                           1293 ;	../app_kombi.c:176: case 0x50:		// 5 = kleiner als Helligkeitsschwelle 2
   05AE 80 3D              1294 	sjmp	00173$
   05B0                    1295 00167$:
                           1296 ;	../app_kombi.c:177: if(delrec[3].delayactive & 0x04) valid=0;
   05B0 E5 35              1297 	mov	a,(_delrec + 0x000c)
   05B2 30 E2 02           1298 	jnb	acc.2,00169$
   05B5 C2 1A              1299 	clr	b2
   05B7                    1300 00169$:
                           1301 ;	../app_kombi.c:178: over &= (underrun & 0x02);
   05B7 78 7D              1302 	mov	r0,#_underrun
   05B9 E6                 1303 	mov	a,@r0
   05BA 03                 1304 	rr	a
   05BB 54 01              1305 	anl	a,#0x01
   05BD FE                 1306 	mov	r6,a
   05BE A2 18              1307 	mov	c,b0
   05C0 E4                 1308 	clr	a
   05C1 33                 1309 	rlc	a
   05C2 FF                 1310 	mov	r7,a
   05C3 D3                 1311 	setb	c
   05C4 EE                 1312 	mov	a,r6
   05C5 5F                 1313 	anl	a,r7
   05C6 70 01              1314 	jnz	00321$
   05C8 C3                 1315 	clr	c
   05C9                    1316 00321$:
   05C9 92 1B              1317 	mov  b3,c
   05CB 92 18              1318 	mov	b0,c
                           1319 ;	../app_kombi.c:179: break;
                           1320 ;	../app_kombi.c:180: case 0x60:		// 6 = kleiner als Helligkeitsschwelle 3
   05CD 80 1E              1321 	sjmp	00173$
   05CF                    1322 00170$:
                           1323 ;	../app_kombi.c:181: if(delrec[4].delayactive & 0x04) valid=0;
   05CF E5 39              1324 	mov	a,(_delrec + 0x0010)
   05D1 30 E2 02           1325 	jnb	acc.2,00172$
   05D4 C2 1A              1326 	clr	b2
   05D6                    1327 00172$:
                           1328 ;	../app_kombi.c:182: over &= (underrun & 0x04);
   05D6 78 7D              1329 	mov	r0,#_underrun
   05D8 E6                 1330 	mov	a,@r0
   05D9 03                 1331 	rr	a
   05DA 03                 1332 	rr	a
   05DB 54 01              1333 	anl	a,#0x01
   05DD FE                 1334 	mov	r6,a
   05DE A2 18              1335 	mov	c,b0
   05E0 E4                 1336 	clr	a
   05E1 33                 1337 	rlc	a
   05E2 FF                 1338 	mov	r7,a
   05E3 D3                 1339 	setb	c
   05E4 EE                 1340 	mov	a,r6
   05E5 5F                 1341 	anl	a,r7
   05E6 70 01              1342 	jnz	00323$
   05E8 C3                 1343 	clr	c
   05E9                    1344 00323$:
   05E9 92 1B              1345 	mov  b3,c
   05EB 92 18              1346 	mov	b0,c
                           1347 ;	../app_kombi.c:184: }
   05ED                    1348 00173$:
                           1349 ;	../app_kombi.c:185: if(valid) under = !over;
   05ED 30 1A 09           1350 	jnb	b2,00175$
   05F0 A2 18              1351 	mov	c,b0
   05F2 B3                 1352 	cpl	c
   05F3 92 1A              1353 	mov  b2,c
   05F5 92 19              1354 	mov	b1,c
   05F7 80 04              1355 	sjmp	00182$
   05F9                    1356 00175$:
                           1357 ;	../app_kombi.c:187: over = 0;
   05F9 C2 18              1358 	clr	b0
                           1359 ;	../app_kombi.c:188: under = 0;
   05FB C2 19              1360 	clr	b1
   05FD                    1361 00182$:
                           1362 ;	../app_kombi.c:194: if (objno>=8) offset++;				// da Verssatz in der Reihenfolge der Parameter
   05FD BA 08 00           1363 	cjne	r2,#0x08,00325$
   0600                    1364 00325$:
   0600 40 01              1365 	jc	00184$
   0602 0D                 1366 	inc	r5
   0603                    1367 00184$:
                           1368 ;	../app_kombi.c:195: if (over) value = eeprom[LUX_OVER-offset];		// zu sendender Wert bei überschreiten
   0603 30 18 0B           1369 	jnb	b0,00186$
   0606 74 F8              1370 	mov	a,#0xF8
   0608 C3                 1371 	clr	c
   0609 9D                 1372 	subb	a,r5
   060A 90 1D 00           1373 	mov	dptr,#_eeprom
   060D 93                 1374 	movc	a,@a+dptr
   060E FE                 1375 	mov	r6,a
   060F 80 0A              1376 	sjmp	00187$
   0611                    1377 00186$:
                           1378 ;	../app_kombi.c:196: else value = eeprom[LUX_UNDER-offset];		// zu sendender Wert bei unterschreiten
   0611 74 F7              1379 	mov	a,#0xF7
   0613 C3                 1380 	clr	c
   0614 9D                 1381 	subb	a,r5
   0615 90 1D 00           1382 	mov	dptr,#_eeprom
   0618 93                 1383 	movc	a,@a+dptr
   0619 FD                 1384 	mov	r5,a
   061A FE                 1385 	mov	r6,a
   061B                    1386 00187$:
                           1387 ;	../app_kombi.c:197: bitmask=1<<(objno-3);				// Bitmaske für underrun und overrun
   061B EA                 1388 	mov	a,r2
   061C 24 FD              1389 	add	a,#0xfd
   061E FD                 1390 	mov	r5,a
   061F 8D F0              1391 	mov	b,r5
   0621 05 F0              1392 	inc	b
   0623 74 01              1393 	mov	a,#0x01
   0625 80 02              1394 	sjmp	00330$
   0627                    1395 00328$:
   0627 25 E0              1396 	add	a,acc
   0629                    1397 00330$:
   0629 D5 F0 FB           1398 	djnz	b,00328$
   062C FD                 1399 	mov	r5,a
                           1400 ;	../app_kombi.c:198: active=0;
   062D A8 1A              1401 	mov	r0,_bp
   062F 08                 1402 	inc	r0
   0630 08                 1403 	inc	r0
   0631 76 00              1404 	mov	@r0,#0x00
                           1405 ;	../app_kombi.c:200: if (over) {					// wenn überschritten
   0633 30 18 76           1406 	jnb	b0,00197$
                           1407 ;	../app_kombi.c:201: if (!(overrun&bitmask)) { 	// wenn neu überschritten
   0636 78 7C              1408 	mov	r0,#_overrun
   0638 ED                 1409 	mov	a,r5
   0639 56                 1410 	anl	a,@r0
   063A 70 64              1411 	jnz	00195$
                           1412 ;	../app_kombi.c:203: if (delay==0 || (resend&bitmask)) {		// // wenn keine Verzögerung oder Sperre aufgehoben wurde, sofort senden
   063C EB                 1413 	mov	a,r3
   063D 4C                 1414 	orl	a,r4
   063E 60 06              1415 	jz	00190$
   0640 78 81              1416 	mov	r0,#_resend
   0642 ED                 1417 	mov	a,r5
   0643 56                 1418 	anl	a,@r0
   0644 60 12              1419 	jz	00191$
   0646                    1420 00190$:
                           1421 ;	../app_kombi.c:204: resend&=~bitmask;
   0646 C0 06              1422 	push	ar6
   0648 ED                 1423 	mov	a,r5
   0649 F4                 1424 	cpl	a
   064A 78 81              1425 	mov	r0,#_resend
   064C 56                 1426 	anl	a,@r0
   064D F6                 1427 	mov	@r0,a
                           1428 ;	../app_kombi.c:205: active=3;	// Bit0=1=aktiv und Bit1=1=überschritten
   064E A8 1A              1429 	mov	r0,_bp
   0650 08                 1430 	inc	r0
   0651 08                 1431 	inc	r0
   0652 76 03              1432 	mov	@r0,#0x03
   0654 D0 06              1433 	pop	ar6
   0656 80 16              1434 	sjmp	00192$
   0658                    1435 00191$:
                           1436 ;	../app_kombi.c:208: if(delrec[objno-1].delayactive!=5) {	// wenn bereits verzögertes unterschreiten läuft timer inaktiv setzen
   0658 EA                 1437 	mov	a,r2
   0659 14                 1438 	dec	a
   065A 25 E0              1439 	add	a,acc
   065C 25 E0              1440 	add	a,acc
   065E 24 29              1441 	add	a,#_delrec
   0660 F8                 1442 	mov	r0,a
   0661 86 07              1443 	mov	ar7,@r0
   0663 BF 05 02           1444 	cjne	r7,#0x05,00335$
   0666 80 06              1445 	sjmp	00192$
   0668                    1446 00335$:
                           1447 ;	../app_kombi.c:209: active=7;	// Bit0=1=aktiv und Bit1=1=überschritten und Bit2=1=verzögert senden
   0668 A8 1A              1448 	mov	r0,_bp
   066A 08                 1449 	inc	r0
   066B 08                 1450 	inc	r0
   066C 76 07              1451 	mov	@r0,#0x07
   066E                    1452 00192$:
                           1453 ;	../app_kombi.c:212: WRITE_DELAY_RECORD(objno-1,active,value,timer+delay+1);
   066E C0 05              1454 	push	ar5
   0670 EA                 1455 	mov	a,r2
   0671 14                 1456 	dec	a
   0672 25 E0              1457 	add	a,acc
   0674 25 E0              1458 	add	a,acc
   0676 FD                 1459 	mov	r5,a
   0677 24 29              1460 	add	a,#_delrec
   0679 F8                 1461 	mov	r0,a
   067A A9 1A              1462 	mov	r1,_bp
   067C 09                 1463 	inc	r1
   067D 09                 1464 	inc	r1
   067E E7                 1465 	mov	a,@r1
   067F F6                 1466 	mov	@r0,a
   0680 ED                 1467 	mov	a,r5
   0681 24 29              1468 	add	a,#_delrec
   0683 FD                 1469 	mov	r5,a
   0684 04                 1470 	inc	a
   0685 F8                 1471 	mov	r0,a
   0686 A6 06              1472 	mov	@r0,ar6
   0688 74 02              1473 	mov	a,#0x02
   068A 2D                 1474 	add	a,r5
   068B F8                 1475 	mov	r0,a
   068C EB                 1476 	mov	a,r3
   068D 25 0F              1477 	add	a,_timer
   068F FD                 1478 	mov	r5,a
   0690 EC                 1479 	mov	a,r4
   0691 35 10              1480 	addc	a,(_timer + 1)
   0693 FF                 1481 	mov	r7,a
   0694 0D                 1482 	inc	r5
   0695 BD 00 01           1483 	cjne	r5,#0x00,00336$
   0698 0F                 1484 	inc	r7
   0699                    1485 00336$:
   0699 A6 05              1486 	mov	@r0,ar5
   069B 08                 1487 	inc	r0
   069C A6 07              1488 	mov	@r0,ar7
                           1489 ;	../app_kombi.c:233: overrun&=~bitmask;	// Überschritten Bit löschen
   069E D0 05              1490 	pop	ar5
                           1491 ;	../app_kombi.c:212: WRITE_DELAY_RECORD(objno-1,active,value,timer+delay+1);
   06A0                    1492 00195$:
                           1493 ;	../app_kombi.c:214: overrun|=bitmask;		// Überschritten Bit setzen
   06A0 78 7C              1494 	mov	r0,#_overrun
   06A2 ED                 1495 	mov	a,r5
   06A3 46                 1496 	orl	a,@r0
   06A4 F6                 1497 	mov	@r0,a
                           1498 ;	../app_kombi.c:215: underrun&=~bitmask;		// Unterschritten Bit löschen
   06A5 ED                 1499 	mov	a,r5
   06A6 F4                 1500 	cpl	a
   06A7 FF                 1501 	mov	r7,a
   06A8 78 7D              1502 	mov	r0,#_underrun
   06AA 56                 1503 	anl	a,@r0
   06AB F6                 1504 	mov	@r0,a
   06AC                    1505 00197$:
                           1506 ;	../app_kombi.c:218: if (under) {										// wenn Wert unter Schwellwert
   06AC 30 19 6E           1507 	jnb	b1,00212$
                           1508 ;	../app_kombi.c:219: if (!(underrun&bitmask)) { 						// wenn neu unterschritten
   06AF 78 7D              1509 	mov	r0,#_underrun
   06B1 ED                 1510 	mov	a,r5
   06B2 56                 1511 	anl	a,@r0
   06B3 70 5C              1512 	jnz	00205$
                           1513 ;	../app_kombi.c:221: if (delay==0 || (resend&bitmask)) {	// wenn keine Verzögerung oder Sperre aufgehoben wurde, sofort senden
   06B5 EB                 1514 	mov	a,r3
   06B6 4C                 1515 	orl	a,r4
   06B7 60 06              1516 	jz	00200$
   06B9 78 81              1517 	mov	r0,#_resend
   06BB ED                 1518 	mov	a,r5
   06BC 56                 1519 	anl	a,@r0
   06BD 60 0F              1520 	jz	00201$
   06BF                    1521 00200$:
                           1522 ;	../app_kombi.c:222: resend&=~bitmask;
   06BF ED                 1523 	mov	a,r5
   06C0 F4                 1524 	cpl	a
   06C1 FF                 1525 	mov	r7,a
   06C2 78 81              1526 	mov	r0,#_resend
   06C4 56                 1527 	anl	a,@r0
   06C5 F6                 1528 	mov	@r0,a
                           1529 ;	../app_kombi.c:223: active=1;						// Bit0=1=aktiv und Bit1=0=unterschritten
   06C6 A8 1A              1530 	mov	r0,_bp
   06C8 08                 1531 	inc	r0
   06C9 08                 1532 	inc	r0
   06CA 76 01              1533 	mov	@r0,#0x01
   06CC 80 16              1534 	sjmp	00202$
   06CE                    1535 00201$:
                           1536 ;	../app_kombi.c:226: if(delrec[objno-1].delayactive!=7) {	// falls verzögertes überschritten Senden noch läuft stoppen
   06CE EA                 1537 	mov	a,r2
   06CF 14                 1538 	dec	a
   06D0 25 E0              1539 	add	a,acc
   06D2 25 E0              1540 	add	a,acc
   06D4 24 29              1541 	add	a,#_delrec
   06D6 F8                 1542 	mov	r0,a
   06D7 86 07              1543 	mov	ar7,@r0
   06D9 BF 07 02           1544 	cjne	r7,#0x07,00341$
   06DC 80 06              1545 	sjmp	00202$
   06DE                    1546 00341$:
                           1547 ;	../app_kombi.c:227: active=5;	// Bit0=1=aktiv und Bit1=0=unterschritten und Bit2=1=verzögert
   06DE A8 1A              1548 	mov	r0,_bp
   06E0 08                 1549 	inc	r0
   06E1 08                 1550 	inc	r0
   06E2 76 05              1551 	mov	@r0,#0x05
   06E4                    1552 00202$:
                           1553 ;	../app_kombi.c:230: WRITE_DELAY_RECORD(objno-1,active,value,timer+delay+1);
   06E4 1A                 1554 	dec	r2
   06E5 EA                 1555 	mov	a,r2
   06E6 2A                 1556 	add	a,r2
   06E7 25 E0              1557 	add	a,acc
   06E9 FA                 1558 	mov	r2,a
   06EA 24 29              1559 	add	a,#_delrec
   06EC F8                 1560 	mov	r0,a
   06ED A9 1A              1561 	mov	r1,_bp
   06EF 09                 1562 	inc	r1
   06F0 09                 1563 	inc	r1
   06F1 E7                 1564 	mov	a,@r1
   06F2 F6                 1565 	mov	@r0,a
   06F3 EA                 1566 	mov	a,r2
   06F4 24 29              1567 	add	a,#_delrec
   06F6 FA                 1568 	mov	r2,a
   06F7 04                 1569 	inc	a
   06F8 F8                 1570 	mov	r0,a
   06F9 A6 06              1571 	mov	@r0,ar6
   06FB 74 02              1572 	mov	a,#0x02
   06FD 2A                 1573 	add	a,r2
   06FE F8                 1574 	mov	r0,a
   06FF EB                 1575 	mov	a,r3
   0700 25 0F              1576 	add	a,_timer
   0702 FB                 1577 	mov	r3,a
   0703 EC                 1578 	mov	a,r4
   0704 35 10              1579 	addc	a,(_timer + 1)
   0706 FC                 1580 	mov	r4,a
   0707 0B                 1581 	inc	r3
   0708 BB 00 01           1582 	cjne	r3,#0x00,00342$
   070B 0C                 1583 	inc	r4
   070C                    1584 00342$:
   070C A6 03              1585 	mov	@r0,ar3
   070E 08                 1586 	inc	r0
   070F A6 04              1587 	mov	@r0,ar4
   0711                    1588 00205$:
                           1589 ;	../app_kombi.c:232: underrun|=bitmask;	// Unterschritten Bit setzen
   0711 78 7D              1590 	mov	r0,#_underrun
   0713 ED                 1591 	mov	a,r5
   0714 46                 1592 	orl	a,@r0
   0715 F6                 1593 	mov	@r0,a
                           1594 ;	../app_kombi.c:233: overrun&=~bitmask;	// Überschritten Bit löschen
   0716 ED                 1595 	mov	a,r5
   0717 F4                 1596 	cpl	a
   0718 FD                 1597 	mov	r5,a
   0719 78 7C              1598 	mov	r0,#_overrun
   071B 56                 1599 	anl	a,@r0
   071C F6                 1600 	mov	@r0,a
   071D                    1601 00212$:
   071D 85 1A 81           1602 	mov	sp,_bp
   0720 D0 1A              1603 	pop	_bp
   0722 22                 1604 	ret
                           1605 ;------------------------------------------------------------
                           1606 ;Allocation info for local variables in function 'read_obj_value'
                           1607 ;------------------------------------------------------------
                           1608 ;objno                     Allocated to registers r2 
                           1609 ;objvalue                  Allocated to registers r3 r4 
                           1610 ;------------------------------------------------------------
                           1611 ;	../app_kombi.c:241: unsigned long read_obj_value(unsigned char objno)
                           1612 ;	-----------------------------------------
                           1613 ;	 function read_obj_value
                           1614 ;	-----------------------------------------
   0723                    1615 _read_obj_value:
   0723 AA 82              1616 	mov	r2,dpl
                           1617 ;	../app_kombi.c:243: int objvalue=0;
   0725 7B 00              1618 	mov	r3,#0x00
   0727 7C 00              1619 	mov	r4,#0x00
                           1620 ;	../app_kombi.c:245: if (objno <= 1) {
   0729 EA                 1621 	mov	a,r2
   072A 24 FE              1622 	add	a,#0xff - 0x01
   072C 40 0E              1623 	jc	00102$
                           1624 ;	../app_kombi.c:246: objvalue = global_object_value_0_to_1[objno];
   072E EA                 1625 	mov	a,r2
   072F 2A                 1626 	add	a,r2
   0730 24 24              1627 	add	a,#_global_object_value_0_to_1
   0732 F8                 1628 	mov	r0,a
   0733 86 05              1629 	mov	ar5,@r0
   0735 08                 1630 	inc	r0
   0736 86 06              1631 	mov	ar6,@r0
   0738 8D 03              1632 	mov	ar3,r5
   073A 8E 04              1633 	mov	ar4,r6
   073C                    1634 00102$:
                           1635 ;	../app_kombi.c:248: if (objno >=3 && objno <= 10) {
   073C BA 03 00           1636 	cjne	r2,#0x03,00116$
   073F                    1637 00116$:
   073F 40 39              1638 	jc	00107$
   0741 EA                 1639 	mov	a,r2
   0742 24 F5              1640 	add	a,#0xff - 0x0A
   0744 40 34              1641 	jc	00107$
                           1642 ;	../app_kombi.c:249: if (global_object_value_3_to_10 & (1<<(objno-3))) objvalue=1; else objvalue=0;
   0746 7D 00              1643 	mov	r5,#0x00
   0748 EA                 1644 	mov	a,r2
   0749 24 FD              1645 	add	a,#0xfd
   074B FA                 1646 	mov	r2,a
   074C ED                 1647 	mov	a,r5
   074D 34 FF              1648 	addc	a,#0xff
   074F 8A F0              1649 	mov	b,r2
   0751 05 F0              1650 	inc	b
   0753 7A 01              1651 	mov	r2,#0x01
   0755 7D 00              1652 	mov	r5,#0x00
   0757 80 06              1653 	sjmp	00120$
   0759                    1654 00119$:
   0759 EA                 1655 	mov	a,r2
   075A 2A                 1656 	add	a,r2
   075B FA                 1657 	mov	r2,a
   075C ED                 1658 	mov	a,r5
   075D 33                 1659 	rlc	a
   075E FD                 1660 	mov	r5,a
   075F                    1661 00120$:
   075F D5 F0 F7           1662 	djnz	b,00119$
   0762 AE 28              1663 	mov	r6,_global_object_value_3_to_10
   0764 7F 00              1664 	mov	r7,#0x00
   0766 EE                 1665 	mov	a,r6
   0767 52 02              1666 	anl	ar2,a
   0769 EF                 1667 	mov	a,r7
   076A 52 05              1668 	anl	ar5,a
   076C EA                 1669 	mov	a,r2
   076D 4D                 1670 	orl	a,r5
   076E 60 06              1671 	jz	00104$
   0770 7B 01              1672 	mov	r3,#0x01
   0772 7C 00              1673 	mov	r4,#0x00
   0774 80 04              1674 	sjmp	00107$
   0776                    1675 00104$:
   0776 7B 00              1676 	mov	r3,#0x00
   0778 7C 00              1677 	mov	r4,#0x00
   077A                    1678 00107$:
                           1679 ;	../app_kombi.c:251: return(objvalue);
   077A EC                 1680 	mov	a,r4
   077B 33                 1681 	rlc	a
   077C 95 E0              1682 	subb	a,acc
   077E FA                 1683 	mov	r2,a
   077F 8B 82              1684 	mov	dpl,r3
   0781 8C 83              1685 	mov	dph,r4
   0783 8A F0              1686 	mov	b,r2
   0785 22                 1687 	ret
                           1688 ;------------------------------------------------------------
                           1689 ;Allocation info for local variables in function 'write_obj_value'
                           1690 ;------------------------------------------------------------
                           1691 ;objvalue                  Allocated to stack - offset -4
                           1692 ;objno                     Allocated to registers r2 
                           1693 ;bitpattern                Allocated to registers r3 
                           1694 ;------------------------------------------------------------
                           1695 ;	../app_kombi.c:255: void write_obj_value(unsigned char objno,int objvalue)
                           1696 ;	-----------------------------------------
                           1697 ;	 function write_obj_value
                           1698 ;	-----------------------------------------
   0786                    1699 _write_obj_value:
   0786 C0 1A              1700 	push	_bp
   0788 85 81 1A           1701 	mov	_bp,sp
                           1702 ;	../app_kombi.c:259: bitpattern = 1<<(objno-3);
   078B E5 82              1703 	mov	a,dpl
   078D FA                 1704 	mov	r2,a
   078E 24 FD              1705 	add	a,#0xfd
   0790 FB                 1706 	mov	r3,a
   0791 8B F0              1707 	mov	b,r3
   0793 05 F0              1708 	inc	b
   0795 74 01              1709 	mov	a,#0x01
   0797 80 02              1710 	sjmp	00117$
   0799                    1711 00115$:
   0799 25 E0              1712 	add	a,acc
   079B                    1713 00117$:
   079B D5 F0 FB           1714 	djnz	b,00115$
   079E FB                 1715 	mov	r3,a
                           1716 ;	../app_kombi.c:260: if (objno <= 1) {
   079F EA                 1717 	mov	a,r2
   07A0 24 FE              1718 	add	a,#0xff - 0x01
   07A2 40 11              1719 	jc	00102$
                           1720 ;	../app_kombi.c:261: global_object_value_0_to_1[objno]=objvalue;
   07A4 EA                 1721 	mov	a,r2
   07A5 2A                 1722 	add	a,r2
   07A6 FC                 1723 	mov	r4,a
   07A7 24 24              1724 	add	a,#_global_object_value_0_to_1
   07A9 F8                 1725 	mov	r0,a
   07AA E5 1A              1726 	mov	a,_bp
   07AC 24 FC              1727 	add	a,#0xfc
   07AE F9                 1728 	mov	r1,a
   07AF E7                 1729 	mov	a,@r1
   07B0 F6                 1730 	mov	@r0,a
   07B1 08                 1731 	inc	r0
   07B2 09                 1732 	inc	r1
   07B3 E7                 1733 	mov	a,@r1
   07B4 F6                 1734 	mov	@r0,a
   07B5                    1735 00102$:
                           1736 ;	../app_kombi.c:263: if (objno >=3 && objno <= 10) {
   07B5 BA 03 00           1737 	cjne	r2,#0x03,00119$
   07B8                    1738 00119$:
   07B8 40 1A              1739 	jc	00109$
   07BA EA                 1740 	mov	a,r2
   07BB 24 F5              1741 	add	a,#0xff - 0x0A
   07BD 40 15              1742 	jc	00109$
                           1743 ;	../app_kombi.c:264: if (objvalue) global_object_value_3_to_10 |= bitpattern;
   07BF E5 1A              1744 	mov	a,_bp
   07C1 24 FC              1745 	add	a,#0xfc
   07C3 F8                 1746 	mov	r0,a
   07C4 E6                 1747 	mov	a,@r0
   07C5 08                 1748 	inc	r0
   07C6 46                 1749 	orl	a,@r0
   07C7 60 05              1750 	jz	00104$
   07C9 EB                 1751 	mov	a,r3
   07CA 42 28              1752 	orl	_global_object_value_3_to_10,a
   07CC 80 06              1753 	sjmp	00109$
   07CE                    1754 00104$:
                           1755 ;	../app_kombi.c:265: else global_object_value_3_to_10 &= (0xFF - bitpattern);
   07CE 74 FF              1756 	mov	a,#0xFF
   07D0 C3                 1757 	clr	c
   07D1 9B                 1758 	subb	a,r3
   07D2 52 28              1759 	anl	_global_object_value_3_to_10,a
   07D4                    1760 00109$:
   07D4 D0 1A              1761 	pop	_bp
   07D6 22                 1762 	ret
                           1763 ;------------------------------------------------------------
                           1764 ;Allocation info for local variables in function 'read_value_req'
                           1765 ;------------------------------------------------------------
                           1766 ;objno                     Allocated to registers r2 
                           1767 ;objflags                  Allocated to registers r3 
                           1768 ;------------------------------------------------------------
                           1769 ;	../app_kombi.c:272: void read_value_req(void)
                           1770 ;	-----------------------------------------
                           1771 ;	 function read_value_req
                           1772 ;	-----------------------------------------
   07D7                    1773 _read_value_req:
                           1774 ;	../app_kombi.c:276: objno=find_first_objno(telegramm[3],telegramm[4]);	// erste Objektnummer zu empfangener GA finden
   07D7 85 57 82           1775 	mov	dpl,(_telegramm + 0x0003)
   07DA C0 58              1776 	push	(_telegramm + 0x0004)
   07DC 12 19 5F           1777 	lcall	_find_first_objno
   07DF AA 82              1778 	mov	r2,dpl
   07E1 15 81              1779 	dec	sp
                           1780 ;	../app_kombi.c:277: if(objno!=0xFF) {									// falls Gruppenadresse nicht gefunden
   07E3 BA FF 01           1781 	cjne	r2,#0xFF,00109$
   07E6 22                 1782 	ret
   07E7                    1783 00109$:
                           1784 ;	../app_kombi.c:278: objflags=read_objflags(objno);					// Objekt Flags lesen
   07E7 8A 82              1785 	mov	dpl,r2
   07E9 C0 02              1786 	push	ar2
   07EB 12 19 47           1787 	lcall	_read_objflags
   07EE AB 82              1788 	mov	r3,dpl
   07F0 D0 02              1789 	pop	ar2
                           1790 ;	../app_kombi.c:280: if((objflags&0x0C)==0x0C) send_obj_value(objno+0x40);
   07F2 53 03 0C           1791 	anl	ar3,#0x0C
   07F5 BB 0C 08           1792 	cjne	r3,#0x0C,00105$
   07F8 74 40              1793 	mov	a,#0x40
   07FA 2A                 1794 	add	a,r2
   07FB F5 82              1795 	mov	dpl,a
   07FD 02 17 1B           1796 	ljmp	_send_obj_value
   0800                    1797 00105$:
   0800 22                 1798 	ret
                           1799 ;------------------------------------------------------------
                           1800 ;Allocation info for local variables in function 'write_value_req'
                           1801 ;------------------------------------------------------------
                           1802 ;objno                     Allocated to registers r2 
                           1803 ;------------------------------------------------------------
                           1804 ;	../app_kombi.c:286: void write_value_req(void)
                           1805 ;	-----------------------------------------
                           1806 ;	 function write_value_req
                           1807 ;	-----------------------------------------
   0801                    1808 _write_value_req:
                           1809 ;	../app_kombi.c:290: objno=find_first_objno(telegramm[3],telegramm[4]);
   0801 85 57 82           1810 	mov	dpl,(_telegramm + 0x0003)
   0804 C0 58              1811 	push	(_telegramm + 0x0004)
   0806 12 19 5F           1812 	lcall	_find_first_objno
   0809 AA 82              1813 	mov	r2,dpl
   080B 15 81              1814 	dec	sp
                           1815 ;	../app_kombi.c:292: if (objno==10) {	// nur Sperrobjekt darf beschrieben werden
   080D BA 0A 28           1816 	cjne	r2,#0x0A,00108$
                           1817 ;	../app_kombi.c:294: if(telegramm[7]&0x01) global_object_value_3_to_10 |= 0x80;
   0810 E5 5B              1818 	mov	a,(_telegramm + 0x0007)
   0812 FA                 1819 	mov	r2,a
   0813 30 E0 05           1820 	jnb	acc.0,00102$
   0816 43 28 80           1821 	orl	_global_object_value_3_to_10,#0x80
   0819 80 03              1822 	sjmp	00103$
   081B                    1823 00102$:
                           1824 ;	../app_kombi.c:295: else global_object_value_3_to_10 &= 0x7F;
   081B 53 28 7F           1825 	anl	_global_object_value_3_to_10,#0x7F
   081E                    1826 00103$:
                           1827 ;	../app_kombi.c:298: if((telegramm[7]&0x01)==0) {
   081E EA                 1828 	mov	a,r2
   081F 20 E0 16           1829 	jb	acc.0,00108$
                           1830 ;	../app_kombi.c:299: overrun&=~lockatt;
   0822 78 80              1831 	mov	r0,#_lockatt
   0824 E6                 1832 	mov	a,@r0
   0825 F4                 1833 	cpl	a
   0826 FA                 1834 	mov	r2,a
   0827 78 7C              1835 	mov	r0,#_overrun
   0829 56                 1836 	anl	a,@r0
   082A F6                 1837 	mov	@r0,a
                           1838 ;	../app_kombi.c:300: underrun&=~lockatt;
   082B 78 7D              1839 	mov	r0,#_underrun
   082D EA                 1840 	mov	a,r2
   082E 56                 1841 	anl	a,@r0
   082F F6                 1842 	mov	@r0,a
                           1843 ;	../app_kombi.c:301: resend=lockatt;
   0830 78 80              1844 	mov	r0,#_lockatt
   0832 86 02              1845 	mov	ar2,@r0
   0834 78 81              1846 	mov	r0,#_resend
   0836 A6 02              1847 	mov	@r0,ar2
   0838                    1848 00108$:
   0838 22                 1849 	ret
                           1850 ;------------------------------------------------------------
                           1851 ;Allocation info for local variables in function 'delay_timer'
                           1852 ;------------------------------------------------------------
                           1853 ;delrecno                  Allocated to registers 
                           1854 ;objno                     Allocated to stack - offset 1
                           1855 ;delay_state               Allocated to registers r6 
                           1856 ;cycle_param               Allocated to registers r3 
                           1857 ;ctrl                      Allocated to stack - offset 2
                           1858 ;sperre                    Allocated to registers r7 
                           1859 ;send                      Allocated to registers b0 
                           1860 ;cyclic                    Allocated to registers b1 
                           1861 ;over                      Allocated to registers b2 
                           1862 ;------------------------------------------------------------
                           1863 ;	../app_kombi.c:308: void delay_timer(void)	// zählt alle 130ms die Variable Timer hoch und prüft Einträge
                           1864 ;	-----------------------------------------
                           1865 ;	 function delay_timer
                           1866 ;	-----------------------------------------
   0839                    1867 _delay_timer:
   0839 C0 1A              1868 	push	_bp
   083B 85 81 1A           1869 	mov	_bp,sp
   083E 05 81              1870 	inc	sp
   0840 05 81              1871 	inc	sp
                           1872 ;	../app_kombi.c:313: RTCCON=0x60;	// Real Time Clock stoppen
   0842 75 D1 60           1873 	mov	_RTCCON,#0x60
                           1874 ;	../app_kombi.c:315: timer++;
   0845 05 0F              1875 	inc	_timer
   0847 E4                 1876 	clr	a
   0848 B5 0F 02           1877 	cjne	a,_timer,00168$
   084B 05 10              1878 	inc	(_timer + 1)
   084D                    1879 00168$:
                           1880 ;	../app_kombi.c:317: RTCH=0x1D;		// Real Time Clock auf 130ms laden (0,13s x 7372800 / 128)
   084D 75 D2 1D           1881 	mov	_RTCH,#0x1D
                           1882 ;	../app_kombi.c:318: RTCL=0x40;		// (RTC ist ein down-counter mit 128 bit prescaler und osc-clock)
   0850 75 D3 40           1883 	mov	_RTCL,#0x40
                           1884 ;	../app_kombi.c:319: RTCCON=0x61;	// ... und starten
   0853 75 D1 61           1885 	mov	_RTCCON,#0x61
                           1886 ;	../app_kombi.c:321: for(delrecno=0;delrecno<DELREC_CNT;delrecno++) {
   0856 A8 1A              1887 	mov	r0,_bp
   0858 08                 1888 	inc	r0
   0859 76 00              1889 	mov	@r0,#0x00
   085B                    1890 00141$:
   085B A8 1A              1891 	mov	r0,_bp
   085D 08                 1892 	inc	r0
   085E B6 09 00           1893 	cjne	@r0,#0x09,00169$
   0861                    1894 00169$:
   0861 40 03              1895 	jc	00170$
   0863 02 09 EB           1896 	ljmp	00145$
   0866                    1897 00170$:
                           1898 ;	../app_kombi.c:322: objno=delrecno;
   0866 A8 1A              1899 	mov	r0,_bp
   0868 08                 1900 	inc	r0
   0869 86 03              1901 	mov	ar3,@r0
                           1902 ;	../app_kombi.c:323: if (delrecno>1) objno++;	// da objno 2 im delay nicht benutzt wird
   086B A8 1A              1903 	mov	r0,_bp
   086D 08                 1904 	inc	r0
   086E E6                 1905 	mov	a,@r0
   086F 24 FE              1906 	add	a,#0xff - 0x01
   0871 50 06              1907 	jnc	00102$
   0873 A8 1A              1908 	mov	r0,_bp
   0875 08                 1909 	inc	r0
   0876 E6                 1910 	mov	a,@r0
   0877 04                 1911 	inc	a
   0878 FB                 1912 	mov	r3,a
   0879                    1913 00102$:
                           1914 ;	../app_kombi.c:325: delay_state=delrec[delrecno].delaystate;
   0879 A8 1A              1915 	mov	r0,_bp
   087B 08                 1916 	inc	r0
   087C E6                 1917 	mov	a,@r0
   087D 25 E0              1918 	add	a,acc
   087F 25 E0              1919 	add	a,acc
   0881 FC                 1920 	mov	r4,a
   0882 24 29              1921 	add	a,#_delrec
   0884 FD                 1922 	mov	r5,a
   0885 04                 1923 	inc	a
   0886 F8                 1924 	mov	r0,a
   0887 86 06              1925 	mov	ar6,@r0
                           1926 ;	../app_kombi.c:326: if (delrec[delrecno].delayvalue==timer && delrec[delrecno].delayactive) {
   0889 74 02              1927 	mov	a,#0x02
   088B 2D                 1928 	add	a,r5
   088C F8                 1929 	mov	r0,a
   088D 86 05              1930 	mov	ar5,@r0
   088F 08                 1931 	inc	r0
   0890 86 07              1932 	mov	ar7,@r0
   0892 18                 1933 	dec	r0
   0893 ED                 1934 	mov	a,r5
   0894 B5 0F 06           1935 	cjne	a,_timer,00172$
   0897 EF                 1936 	mov	a,r7
   0898 B5 10 02           1937 	cjne	a,(_timer + 1),00172$
   089B 80 03              1938 	sjmp	00173$
   089D                    1939 00172$:
   089D 02 09 E4           1940 	ljmp	00143$
   08A0                    1941 00173$:
   08A0 EC                 1942 	mov	a,r4
   08A1 24 29              1943 	add	a,#_delrec
   08A3 F8                 1944 	mov	r0,a
   08A4 E6                 1945 	mov	a,@r0
   08A5 70 03              1946 	jnz	00174$
   08A7 02 09 E4           1947 	ljmp	00143$
   08AA                    1948 00174$:
                           1949 ;	../app_kombi.c:328: send=0;
   08AA C0 06              1950 	push	ar6
   08AC C2 18              1951 	clr	b0
                           1952 ;	../app_kombi.c:329: cyclic=0;
   08AE C2 19              1953 	clr	b1
                           1954 ;	../app_kombi.c:330: ctrl=eeprom[ctrl_adr[objno]];		// Control Parameter
   08B0 EB                 1955 	mov	a,r3
   08B1 90 1B 74           1956 	mov	dptr,#_ctrl_adr
   08B4 93                 1957 	movc	a,@a+dptr
   08B5 F5 82              1958 	mov	dpl,a
   08B7 75 83 1D           1959 	mov	dph,#(_eeprom >> 8)
   08BA E4                 1960 	clr	a
   08BB 93                 1961 	movc	a,@a+dptr
   08BC FD                 1962 	mov	r5,a
   08BD A8 1A              1963 	mov	r0,_bp
   08BF 08                 1964 	inc	r0
   08C0 08                 1965 	inc	r0
   08C1 A6 05              1966 	mov	@r0,ar5
                           1967 ;	../app_kombi.c:331: sperre=read_obj_value(10);
   08C3 75 82 0A           1968 	mov	dpl,#0x0A
   08C6 C0 03              1969 	push	ar3
   08C8 C0 04              1970 	push	ar4
   08CA C0 23              1971 	push	bits
   08CC 12 07 23           1972 	lcall	_read_obj_value
   08CF AF 82              1973 	mov	r7,dpl
   08D1 AE 83              1974 	mov	r6,dph
   08D3 AD F0              1975 	mov	r5,b
   08D5 FA                 1976 	mov	r2,a
   08D6 D0 23              1977 	pop	bits
   08D8 D0 04              1978 	pop	ar4
   08DA D0 03              1979 	pop	ar3
                           1980 ;	../app_kombi.c:333: if (delrecno<2) {	//Helligkeits- und Temperaturwert
   08DC A8 1A              1981 	mov	r0,_bp
   08DE 08                 1982 	inc	r0
   08DF B6 02 00           1983 	cjne	@r0,#0x02,00175$
   08E2                    1984 00175$:
   08E2 D0 06              1985 	pop	ar6
   08E4 50 2C              1986 	jnc	00129$
                           1987 ;	../app_kombi.c:335: if ((eeprom[0xD3-delrecno])!=0)send=1;		// ohne Prüfung auf Sperre etc. immer senden wenn mindset hysterese<>0 oder zykl.
   08E6 A8 1A              1988 	mov	r0,_bp
   08E8 08                 1989 	inc	r0
   08E9 74 D3              1990 	mov	a,#0xD3
   08EB C3                 1991 	clr	c
   08EC 96                 1992 	subb	a,@r0
   08ED 24 00              1993 	add	a,#_eeprom
   08EF FA                 1994 	mov	r2,a
   08F0 E4                 1995 	clr	a
   08F1 34 1D              1996 	addc	a,#(_eeprom >> 8)
   08F3 FD                 1997 	mov	r5,a
   08F4 8A 82              1998 	mov	dpl,r2
   08F6 8D 83              1999 	mov	dph,r5
   08F8 E4                 2000 	clr	a
   08F9 93                 2001 	movc	a,@a+dptr
   08FA 60 02              2002 	jz	00104$
   08FC D2 18              2003 	setb	b0
   08FE                    2004 00104$:
                           2005 ;	../app_kombi.c:337: if ((eeprom[0xD3-delrecno]&0x0F)!=0) cyclic=1;	// falls zyklisches Senden
   08FE A8 1A              2006 	mov	r0,_bp
   0900 08                 2007 	inc	r0
   0901 74 D3              2008 	mov	a,#0xD3
   0903 C3                 2009 	clr	c
   0904 96                 2010 	subb	a,@r0
   0905 90 1D 00           2011 	mov	dptr,#_eeprom
   0908 93                 2012 	movc	a,@a+dptr
   0909 FA                 2013 	mov	r2,a
   090A 54 0F              2014 	anl	a,#0x0F
   090C 60 66              2015 	jz	00130$
   090E D2 19              2016 	setb	b1
   0910 80 62              2017 	sjmp	00130$
   0912                    2018 00129$:
                           2019 ;	../app_kombi.c:341: over=delrec[delrecno].delayactive & 0x02;	// überschritten
   0912 EC                 2020 	mov	a,r4
   0913 24 29              2021 	add	a,#_delrec
   0915 F8                 2022 	mov	r0,a
   0916 E6                 2023 	mov	a,@r0
   0917 FA                 2024 	mov	r2,a
   0918 A2 E1              2025 	mov	c,acc[1]
                           2026 ;	../app_kombi.c:342: if (over) {	// wenn überschritten
   091A 92 1A              2027 	mov	b2,c
   091C 50 0C              2028 	jnc	00112$
                           2029 ;	../app_kombi.c:343: if(ctrl & 0x20) cyclic=1;	// wenn überschritten und es soll zyklisch gesendet werden...
   091E A8 1A              2030 	mov	r0,_bp
   0920 08                 2031 	inc	r0
   0921 08                 2032 	inc	r0
   0922 E6                 2033 	mov	a,@r0
   0923 30 E5 0E           2034 	jnb	acc.5,00113$
   0926 D2 19              2035 	setb	b1
   0928 80 0A              2036 	sjmp	00113$
   092A                    2037 00112$:
                           2038 ;	../app_kombi.c:346: if(ctrl & 0x80) cyclic=1;	// ...oder wenn unterschritten und es soll zyklisch gesendet werden...
   092A A8 1A              2039 	mov	r0,_bp
   092C 08                 2040 	inc	r0
   092D 08                 2041 	inc	r0
   092E E6                 2042 	mov	a,@r0
   092F 30 E7 02           2043 	jnb	acc.7,00113$
   0932 D2 19              2044 	setb	b1
   0934                    2045 00113$:
                           2046 ;	../app_kombi.c:349: if ((over && (ctrl&0x30)) || (!over && (ctrl&0xC0))) {	// Senden bei über- oder unterschreiten...
   0934 30 1A 09           2047 	jnb	b2,00121$
   0937 A8 1A              2048 	mov	r0,_bp
   0939 08                 2049 	inc	r0
   093A 08                 2050 	inc	r0
   093B E6                 2051 	mov	a,@r0
   093C 54 30              2052 	anl	a,#0x30
   093E 70 0C              2053 	jnz	00117$
   0940                    2054 00121$:
   0940 20 1A 16           2055 	jb	b2,00118$
   0943 A8 1A              2056 	mov	r0,_bp
   0945 08                 2057 	inc	r0
   0946 08                 2058 	inc	r0
   0947 E6                 2059 	mov	a,@r0
   0948 54 C0              2060 	anl	a,#0xC0
   094A 60 0D              2061 	jz	00118$
   094C                    2062 00117$:
                           2063 ;	../app_kombi.c:350: if ((ctrl & 0x08)==0 || sperre==0) {	// ... nur wenn Sperre ignorieren oder Sperre=0
   094C A8 1A              2064 	mov	r0,_bp
   094E 08                 2065 	inc	r0
   094F 08                 2066 	inc	r0
   0950 E6                 2067 	mov	a,@r0
   0951 30 E3 03           2068 	jnb	acc.3,00114$
   0954 EF                 2069 	mov	a,r7
   0955 70 02              2070 	jnz	00118$
   0957                    2071 00114$:
                           2072 ;	../app_kombi.c:351: send=1;
   0957 D2 18              2073 	setb	b0
   0959                    2074 00118$:
                           2075 ;	../app_kombi.c:355: if ((eeprom[LUXPARAM]&0x80) && (objno==3)) {	// bei Helligkeitsregelung immer zyklisch und immer senden
   0959 90 1D D3           2076 	mov	dptr,#(_eeprom + 0x00d3)
   095C E4                 2077 	clr	a
   095D 93                 2078 	movc	a,@a+dptr
   095E FA                 2079 	mov	r2,a
   095F 30 E7 12           2080 	jnb	acc.7,00130$
   0962 BB 03 0F           2081 	cjne	r3,#0x03,00130$
                           2082 ;	../app_kombi.c:356: if ((ctrl & 0x08)==0 || sperre==0) {	// ... nur wenn Sperre ignorieren oder Sperre=0
   0965 A8 1A              2083 	mov	r0,_bp
   0967 08                 2084 	inc	r0
   0968 08                 2085 	inc	r0
   0969 E6                 2086 	mov	a,@r0
   096A 30 E3 03           2087 	jnb	acc.3,00122$
   096D EF                 2088 	mov	a,r7
   096E 70 04              2089 	jnz	00130$
   0970                    2090 00122$:
                           2091 ;	../app_kombi.c:357: send=1;
   0970 D2 18              2092 	setb	b0
                           2093 ;	../app_kombi.c:358: cyclic=1;
   0972 D2 19              2094 	setb	b1
   0974                    2095 00130$:
                           2096 ;	../app_kombi.c:363: if (send) {
   0974 30 18 29           2097 	jnb	b0,00134$
                           2098 ;	../app_kombi.c:364: if (objno>1) write_obj_value(objno,delay_state);		// Wert ins userram schreiben
   0977 EB                 2099 	mov	a,r3
   0978 24 FE              2100 	add	a,#0xff - 0x01
   097A 50 17              2101 	jnc	00132$
   097C 7A 00              2102 	mov	r2,#0x00
   097E C0 03              2103 	push	ar3
   0980 C0 23              2104 	push	bits
   0982 C0 06              2105 	push	ar6
   0984 C0 02              2106 	push	ar2
   0986 8B 82              2107 	mov	dpl,r3
   0988 12 07 86           2108 	lcall	_write_obj_value
   098B 15 81              2109 	dec	sp
   098D 15 81              2110 	dec	sp
   098F D0 23              2111 	pop	bits
   0991 D0 03              2112 	pop	ar3
   0993                    2113 00132$:
                           2114 ;	../app_kombi.c:365: send_obj_value(objno);			// Telegramm senden
   0993 8B 82              2115 	mov	dpl,r3
   0995 C0 03              2116 	push	ar3
   0997 C0 23              2117 	push	bits
   0999 12 17 1B           2118 	lcall	_send_obj_value
   099C D0 23              2119 	pop	bits
   099E D0 03              2120 	pop	ar3
   09A0                    2121 00134$:
                           2122 ;	../app_kombi.c:371: delrec[delrecno].delayactive &= 0xFB;
   09A0 A8 1A              2123 	mov	r0,_bp
   09A2 08                 2124 	inc	r0
   09A3 E6                 2125 	mov	a,@r0
   09A4 25 E0              2126 	add	a,acc
   09A6 25 E0              2127 	add	a,acc
   09A8 FA                 2128 	mov	r2,a
   09A9 24 29              2129 	add	a,#_delrec
   09AB F8                 2130 	mov	r0,a
   09AC 86 04              2131 	mov	ar4,@r0
   09AE 74 FB              2132 	mov	a,#0xFB
   09B0 5C                 2133 	anl	a,r4
   09B1 F6                 2134 	mov	@r0,a
                           2135 ;	../app_kombi.c:373: if (cyclic) {
   09B2 30 19 2D           2136 	jnb	b1,00136$
                           2137 ;	../app_kombi.c:374: cycle_param=eeprom[ctrl_adr[objno]+1]&0x0F;	// Zyklus-Adresse jeweils ein Byte über ctrl_adr
   09B5 EB                 2138 	mov	a,r3
   09B6 90 1B 74           2139 	mov	dptr,#_ctrl_adr
   09B9 93                 2140 	movc	a,@a+dptr
   09BA 04                 2141 	inc	a
   09BB 90 1D 00           2142 	mov	dptr,#_eeprom
   09BE 93                 2143 	movc	a,@a+dptr
   09BF FB                 2144 	mov	r3,a
   09C0 53 03 0F           2145 	anl	ar3,#0x0F
                           2146 ;	../app_kombi.c:375: delrec[delrecno].delayvalue=timer+cycleval[cycle_param];
   09C3 EA                 2147 	mov	a,r2
   09C4 24 2B              2148 	add	a,#_delrec+0x02
   09C6 F9                 2149 	mov	r1,a
   09C7 EB                 2150 	mov	a,r3
   09C8 2B                 2151 	add	a,r3
   09C9 FA                 2152 	mov	r2,a
   09CA 90 1A 89           2153 	mov	dptr,#_cycleval
   09CD 93                 2154 	movc	a,@a+dptr
   09CE CA                 2155 	xch	a,r2
   09CF A3                 2156 	inc	dptr
   09D0 93                 2157 	movc	a,@a+dptr
   09D1 FB                 2158 	mov	r3,a
   09D2 EA                 2159 	mov	a,r2
   09D3 25 0F              2160 	add	a,_timer
   09D5 FA                 2161 	mov	r2,a
   09D6 EB                 2162 	mov	a,r3
   09D7 35 10              2163 	addc	a,(_timer + 1)
   09D9 FB                 2164 	mov	r3,a
   09DA A7 02              2165 	mov	@r1,ar2
   09DC 09                 2166 	inc	r1
   09DD A7 03              2167 	mov	@r1,ar3
   09DF 19                 2168 	dec	r1
   09E0 80 02              2169 	sjmp	00143$
   09E2                    2170 00136$:
                           2171 ;	../app_kombi.c:378: else delrec[delrecno].delayactive=0;
   09E2 76 00              2172 	mov	@r0,#0x00
   09E4                    2173 00143$:
                           2174 ;	../app_kombi.c:321: for(delrecno=0;delrecno<DELREC_CNT;delrecno++) {
   09E4 A8 1A              2175 	mov	r0,_bp
   09E6 08                 2176 	inc	r0
   09E7 06                 2177 	inc	@r0
   09E8 02 08 5B           2178 	ljmp	00141$
   09EB                    2179 00145$:
   09EB 85 1A 81           2180 	mov	sp,_bp
   09EE D0 1A              2181 	pop	_bp
   09F0 22                 2182 	ret
                           2183 ;------------------------------------------------------------
                           2184 ;Allocation info for local variables in function 'restart_app'
                           2185 ;------------------------------------------------------------
                           2186 ;objno                     Allocated to registers r2 
                           2187 ;bitmask                   Allocated to registers r2 
                           2188 ;ctrl                      Allocated to registers r4 
                           2189 ;------------------------------------------------------------
                           2190 ;	../app_kombi.c:385: void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
                           2191 ;	-----------------------------------------
                           2192 ;	 function restart_app
                           2193 ;	-----------------------------------------
   09F1                    2194 _restart_app:
                           2195 ;	../app_kombi.c:390: PT0AD=0xF0; 		// disable digital inputs P0.1 ... P0.5
   09F1 75 F6 F0           2196 	mov	_PT0AD,#0xF0
                           2197 ;	../app_kombi.c:391: P0= 0xBF;			// P0.0 push-pull for charging the capacitor, P0.6 push-pull status-LED
   09F4 75 80 BF           2198 	mov	_P0,#0xBF
                           2199 ;	../app_kombi.c:392: P0M1= 0x22;			// others bidirectional,
   09F7 75 84 22           2200 	mov	_P0M1,#0x22
                           2201 ;	../app_kombi.c:393: P0M2= 0x41;			// P0_5 & P0_1 high impedance for adc inputs
   09FA 75 85 41           2202 	mov	_P0M2,#0x41
                           2203 ;	../app_kombi.c:395: lux=65535;
   09FD 75 17 FF           2204 	mov	_lux,#0xFF
   0A00 75 18 FF           2205 	mov	(_lux + 1),#0xFF
                           2206 ;	../app_kombi.c:396: temp=-1000;
   0A03 75 15 18           2207 	mov	_temp,#0x18
   0A06 75 16 FC           2208 	mov	(_temp + 1),#0xFC
                           2209 ;	../app_kombi.c:397: lastlux=lux;
   0A09 75 11 FF           2210 	mov	_lastlux,#0xFF
   0A0C 75 12 FF           2211 	mov	(_lastlux + 1),#0xFF
                           2212 ;	../app_kombi.c:398: lasttemp=temp;
   0A0F 75 13 18           2213 	mov	_lasttemp,#0x18
   0A12 75 14 FC           2214 	mov	(_lasttemp + 1),#0xFC
                           2215 ;	../app_kombi.c:400: overrun=0;
   0A15 78 7C              2216 	mov	r0,#_overrun
   0A17 76 00              2217 	mov	@r0,#0x00
                           2218 ;	../app_kombi.c:401: underrun=0;
   0A19 78 7D              2219 	mov	r0,#_underrun
                           2220 ;	../app_kombi.c:403: timer=0;
   0A1B E4                 2221 	clr	a
   0A1C F6                 2222 	mov	@r0,a
   0A1D F5 0F              2223 	mov	_timer,a
   0A1F F5 10              2224 	mov	(_timer + 1),a
                           2225 ;	../app_kombi.c:404: sequence=1;
   0A21 78 7F              2226 	mov	r0,#_sequence
   0A23 76 01              2227 	mov	@r0,#0x01
                           2228 ;	../app_kombi.c:408: lockatt=0;
   0A25 78 80              2229 	mov	r0,#_lockatt
   0A27 76 00              2230 	mov	@r0,#0x00
                           2231 ;	../app_kombi.c:409: bitmask=1;
   0A29 7A 01              2232 	mov	r2,#0x01
                           2233 ;	../app_kombi.c:410: for (objno=3; objno<=9; objno++) {
   0A2B 7B 03              2234 	mov	r3,#0x03
   0A2D                    2235 00107$:
   0A2D EB                 2236 	mov	a,r3
   0A2E 24 F6              2237 	add	a,#0xff - 0x09
   0A30 40 1B              2238 	jc	00110$
                           2239 ;	../app_kombi.c:411: ctrl=eeprom[ctrl_adr[objno]];
   0A32 EB                 2240 	mov	a,r3
   0A33 90 1B 74           2241 	mov	dptr,#_ctrl_adr
   0A36 93                 2242 	movc	a,@a+dptr
   0A37 F5 82              2243 	mov	dpl,a
   0A39 75 83 1D           2244 	mov	dph,#(_eeprom >> 8)
   0A3C E4                 2245 	clr	a
   0A3D 93                 2246 	movc	a,@a+dptr
                           2247 ;	../app_kombi.c:412: if (ctrl & 0x08) lockatt|=bitmask;
   0A3E FC                 2248 	mov	r4,a
   0A3F 30 E3 05           2249 	jnb	acc.3,00102$
   0A42 78 80              2250 	mov	r0,#_lockatt
   0A44 EA                 2251 	mov	a,r2
   0A45 46                 2252 	orl	a,@r0
   0A46 F6                 2253 	mov	@r0,a
   0A47                    2254 00102$:
                           2255 ;	../app_kombi.c:413: bitmask=bitmask<<1;
   0A47 EA                 2256 	mov	a,r2
   0A48 2A                 2257 	add	a,r2
   0A49 FA                 2258 	mov	r2,a
                           2259 ;	../app_kombi.c:410: for (objno=3; objno<=9; objno++) {
   0A4A 0B                 2260 	inc	r3
   0A4B 80 E0              2261 	sjmp	00107$
   0A4D                    2262 00110$:
                           2263 ;	../app_kombi.c:417: global_object_value_3_to_10 &= 0x7F;
   0A4D 53 28 7F           2264 	anl	_global_object_value_3_to_10,#0x7F
                           2265 ;	../app_kombi.c:419: for (objno=2;objno<9;objno++) WRITE_DELAY_RECORD(objno,0,0,0)			// erstmal alle delay-records auf inaktiv setzen
   0A50 7A 07              2266 	mov	r2,#0x07
   0A52                    2267 00113$:
   0A52 EA                 2268 	mov	a,r2
   0A53 14                 2269 	dec	a
   0A54 FB                 2270 	mov	r3,a
   0A55 25 E0              2271 	add	a,acc
   0A57 25 E0              2272 	add	a,acc
   0A59 FC                 2273 	mov	r4,a
   0A5A 24 29              2274 	add	a,#_delrec
   0A5C F8                 2275 	mov	r0,a
   0A5D 76 00              2276 	mov	@r0,#0x00
   0A5F 8B 02              2277 	mov	ar2,r3
   0A61 EA                 2278 	mov	a,r2
   0A62 70 EE              2279 	jnz	00113$
   0A64 F5 4E              2280 	mov	(_delrec + 0x0025),a
   0A66 F5 4F              2281 	mov	(_delrec + 0x0026),a
   0A68 F5 50              2282 	mov	((_delrec + 0x0026) + 1),a
                           2283 ;	../app_kombi.c:420: if ((eeprom[0xD3]&0x0F)!=0) {
   0A6A 90 1D D3           2284 	mov	dptr,#(_eeprom + 0x00d3)
   0A6D E4                 2285 	clr	a
   0A6E 93                 2286 	movc	a,@a+dptr
   0A6F FA                 2287 	mov	r2,a
   0A70 54 0F              2288 	anl	a,#0x0F
   0A72 60 0C              2289 	jz	00104$
                           2290 ;	../app_kombi.c:421: WRITE_DELAY_RECORD(0,1,1,timer+50)
   0A74 75 29 01           2291 	mov	_delrec,#0x01
   0A77 75 2A 01           2292 	mov	(_delrec + 0x0001),#0x01
   0A7A 75 2B 32           2293 	mov	(_delrec + 0x0002),#0x32
   0A7D 75 2C 00           2294 	mov	((_delrec + 0x0002) + 1),#0x00
   0A80                    2295 00104$:
                           2296 ;	../app_kombi.c:423: if ((eeprom[0xD2]&0x0F)!=0) {
   0A80 90 1D D2           2297 	mov	dptr,#(_eeprom + 0x00d2)
   0A83 E4                 2298 	clr	a
   0A84 93                 2299 	movc	a,@a+dptr
   0A85 FA                 2300 	mov	r2,a
   0A86 54 0F              2301 	anl	a,#0x0F
   0A88 60 0C              2302 	jz	00106$
                           2303 ;	../app_kombi.c:424: WRITE_DELAY_RECORD(1,1,1,timer+55)
   0A8A 75 2D 01           2304 	mov	(_delrec + 0x0004),#0x01
   0A8D 75 2E 01           2305 	mov	(_delrec + 0x0005),#0x01
   0A90 75 2F 37           2306 	mov	(_delrec + 0x0006),#0x37
   0A93 75 30 00           2307 	mov	((_delrec + 0x0006) + 1),#0x00
   0A96                    2308 00106$:
                           2309 ;	../app_kombi.c:427: EA=0;
   0A96 C2 AF              2310 	clr	_IEN0_7
                           2311 ;	../app_kombi.c:428: START_WRITECYCLE			// Applikations-spezifische eeprom Eintraege schreiben
   0A98 75 E4 00           2312 	mov	_FMCON,#0x00
                           2313 ;	../app_kombi.c:429: WRITE_BYTE(0x01,0x03,0x00)	// Herstellercode: 0x0001 Siemens
   0A9B 75 E7 1D           2314 	mov	_FMADRH,#0x1D
   0A9E 75 E6 03           2315 	mov	_FMADRL,#0x03
   0AA1 75 E5 00           2316 	mov	_FMDATA,#0x00
                           2317 ;	../app_kombi.c:430: WRITE_BYTE(0x01,0x04,0x01)
   0AA4 75 E7 1D           2318 	mov	_FMADRH,#0x1D
   0AA7 75 E6 04           2319 	mov	_FMADRL,#0x04
   0AAA 75 E5 01           2320 	mov	_FMDATA,#0x01
                           2321 ;	../app_kombi.c:431: WRITE_BYTE(0x01,0x05,0x22)	// Gerätetyp: 0x221C AP254
   0AAD 75 E7 1D           2322 	mov	_FMADRH,#0x1D
   0AB0 75 E6 05           2323 	mov	_FMADRL,#0x05
   0AB3 75 E5 22           2324 	mov	_FMDATA,#0x22
                           2325 ;	../app_kombi.c:432: WRITE_BYTE(0x01,0x06,0x1C)
   0AB6 75 E7 1D           2326 	mov	_FMADRH,#0x1D
   0AB9 75 E6 06           2327 	mov	_FMADRL,#0x06
   0ABC 75 E5 1C           2328 	mov	_FMDATA,#0x1C
                           2329 ;	../app_kombi.c:433: WRITE_BYTE(0x01,0x07,0x01)	// Software-Versionsnummer
   0ABF 75 E7 1D           2330 	mov	_FMADRH,#0x1D
   0AC2 75 E6 07           2331 	mov	_FMADRL,#0x07
   0AC5 75 E5 01           2332 	mov	_FMDATA,#0x01
                           2333 ;	../app_kombi.c:434: WRITE_BYTE(0x01,0x0C,0x00)	// PORT A Direction Bit Setting
   0AC8 75 E7 1D           2334 	mov	_FMADRH,#0x1D
   0ACB 75 E6 0C           2335 	mov	_FMADRL,#0x0C
   0ACE 75 E5 00           2336 	mov	_FMDATA,#0x00
                           2337 ;	../app_kombi.c:435: WRITE_BYTE(0x01,0x0D,0xFF)	// Run-Status (00=stop FF=run)
   0AD1 75 E7 1D           2338 	mov	_FMADRH,#0x1D
   0AD4 75 E6 0D           2339 	mov	_FMADRL,#0x0D
   0AD7 75 E5 FF           2340 	mov	_FMDATA,#0xFF
                           2341 ;	../app_kombi.c:436: WRITE_BYTE(0x01,0x12,0x56)	// COMMSTAB Pointer
   0ADA 75 E7 1D           2342 	mov	_FMADRH,#0x1D
   0ADD 75 E6 12           2343 	mov	_FMADRL,#0x12
   0AE0 75 E5 56           2344 	mov	_FMDATA,#0x56
                           2345 ;	../app_kombi.c:437: STOP_WRITECYCLE
   0AE3 75 E4 68           2346 	mov	_FMCON,#0x68
                           2347 ;	../app_kombi.c:438: START_WRITECYCLE;
   0AE6 75 E4 00           2348 	mov	_FMCON,#0x00
                           2349 ;	../app_kombi.c:439: WRITE_BYTE(0x00,0x60,0x2E);	// system state: all layers active (run), not in prog mode
   0AE9 75 E7 1C           2350 	mov	_FMADRH,#0x1C
   0AEC 75 E6 60           2351 	mov	_FMADRL,#0x60
   0AEF 75 E5 2E           2352 	mov	_FMDATA,#0x2E
                           2353 ;	../app_kombi.c:440: STOP_WRITECYCLE;
   0AF2 75 E4 68           2354 	mov	_FMCON,#0x68
                           2355 ;	../app_kombi.c:441: EA=1;
   0AF5 D2 AF              2356 	setb	_IEN0_7
   0AF7 22                 2357 	ret
                           2358 	.area CSEG    (CODE)
                           2359 	.area CONST   (CODE)
   1A89                    2360 _cycleval:
   1A89 5C 67              2361 	.byte #0x5C,#0x67
   1A8B B9 01              2362 	.byte #0xB9,#0x01
   1A8D 2B 05              2363 	.byte #0x2B,#0x05
   1A8F 9D 08              2364 	.byte #0x9D,#0x08
   1A91 3A 11              2365 	.byte #0x3A,#0x11
   1A93 74 22              2366 	.byte #0x74,#0x22
   1A95 AE 33              2367 	.byte #0xAE,#0x33
   1A97 85 4D              2368 	.byte #0x85,#0x4D
   1A99 5C 67              2369 	.byte #0x5C,#0x67
   1A9B                    2370 _luxtable:
   1A9B 02 00              2371 	.byte #0x02,#0x00
   1A9D 02 00              2372 	.byte #0x02,#0x00
   1A9F 02 00              2373 	.byte #0x02,#0x00
   1AA1 03 00              2374 	.byte #0x03,#0x00
   1AA3 03 00              2375 	.byte #0x03,#0x00
   1AA5 04 00              2376 	.byte #0x04,#0x00
   1AA7 04 00              2377 	.byte #0x04,#0x00
   1AA9 05 00              2378 	.byte #0x05,#0x00
   1AAB 05 00              2379 	.byte #0x05,#0x00
   1AAD 06 00              2380 	.byte #0x06,#0x00
   1AAF 07 00              2381 	.byte #0x07,#0x00
   1AB1 08 00              2382 	.byte #0x08,#0x00
   1AB3 09 00              2383 	.byte #0x09,#0x00
   1AB5 0A 00              2384 	.byte #0x0A,#0x00
   1AB7 0B 00              2385 	.byte #0x0B,#0x00
   1AB9 0C 00              2386 	.byte #0x0C,#0x00
   1ABB 0E 00              2387 	.byte #0x0E,#0x00
   1ABD 10 00              2388 	.byte #0x10,#0x00
   1ABF 12 00              2389 	.byte #0x12,#0x00
   1AC1 14 00              2390 	.byte #0x14,#0x00
   1AC3 17 00              2391 	.byte #0x17,#0x00
   1AC5 1A 00              2392 	.byte #0x1A,#0x00
   1AC7 1E 00              2393 	.byte #0x1E,#0x00
   1AC9 23 00              2394 	.byte #0x23,#0x00
   1ACB 28 00              2395 	.byte #0x28,#0x00
   1ACD 2D 00              2396 	.byte #0x2D,#0x00
   1ACF 32 00              2397 	.byte #0x32,#0x00
   1AD1 37 00              2398 	.byte #0x37,#0x00
   1AD3 3C 00              2399 	.byte #0x3C,#0x00
   1AD5 46 00              2400 	.byte #0x46,#0x00
   1AD7 50 00              2401 	.byte #0x50,#0x00
   1AD9 5A 00              2402 	.byte #0x5A,#0x00
   1ADB 64 00              2403 	.byte #0x64,#0x00
   1ADD 6E 00              2404 	.byte #0x6E,#0x00
   1ADF 7D 00              2405 	.byte #0x7D,#0x00
   1AE1 8C 00              2406 	.byte #0x8C,#0x00
   1AE3 A0 00              2407 	.byte #0xA0,#0x00
   1AE5 B4 00              2408 	.byte #0xB4,#0x00
   1AE7 C8 00              2409 	.byte #0xC8,#0x00
   1AE9 E6 00              2410 	.byte #0xE6,#0x00
   1AEB 04 01              2411 	.byte #0x04,#0x01
   1AED 2C 01              2412 	.byte #0x2C,#0x01
   1AEF 5E 01              2413 	.byte #0x5E,#0x01
   1AF1 90 01              2414 	.byte #0x90,#0x01
   1AF3 C2 01              2415 	.byte #0xC2,#0x01
   1AF5 F4 01              2416 	.byte #0xF4,#0x01
   1AF7 26 02              2417 	.byte #0x26,#0x02
   1AF9 58 02              2418 	.byte #0x58,#0x02
   1AFB BC 02              2419 	.byte #0xBC,#0x02
   1AFD 20 03              2420 	.byte #0x20,#0x03
   1AFF 84 03              2421 	.byte #0x84,#0x03
   1B01 E8 03              2422 	.byte #0xE8,#0x03
   1B03 4C 04              2423 	.byte #0x4C,#0x04
   1B05 E2 04              2424 	.byte #0xE2,#0x04
   1B07 78 05              2425 	.byte #0x78,#0x05
   1B09 40 06              2426 	.byte #0x40,#0x06
   1B0B 08 07              2427 	.byte #0x08,#0x07
   1B0D D0 07              2428 	.byte #0xD0,#0x07
   1B0F FC 08              2429 	.byte #0xFC,#0x08
   1B11 28 0A              2430 	.byte #0x28,#0x0A
   1B13 B8 0B              2431 	.byte #0xB8,#0x0B
   1B15 AC 0D              2432 	.byte #0xAC,#0x0D
   1B17 A0 0F              2433 	.byte #0xA0,#0x0F
   1B19 94 11              2434 	.byte #0x94,#0x11
   1B1B 88 13              2435 	.byte #0x88,#0x13
   1B1D 7C 15              2436 	.byte #0x7C,#0x15
   1B1F 70 17              2437 	.byte #0x70,#0x17
   1B21 58 1B              2438 	.byte #0x58,#0x1B
   1B23 40 1F              2439 	.byte #0x40,#0x1F
   1B25 28 23              2440 	.byte #0x28,#0x23
   1B27 10 27              2441 	.byte #0x10,#0x27
   1B29 F8 2A              2442 	.byte #0xF8,#0x2A
   1B2B D4 30              2443 	.byte #0xD4,#0x30
   1B2D B0 36              2444 	.byte #0xB0,#0x36
   1B2F 80 3E              2445 	.byte #0x80,#0x3E
   1B31 50 46              2446 	.byte #0x50,#0x46
   1B33 20 4E              2447 	.byte #0x20,#0x4E
   1B35 D8 59              2448 	.byte #0xD8,#0x59
   1B37 90 65              2449 	.byte #0x90,#0x65
   1B39 30 75              2450 	.byte #0x30,#0x75
   1B3B B8 88              2451 	.byte #0xB8,#0x88
   1B3D 40 9C              2452 	.byte #0x40,#0x9C
   1B3F C8 AF              2453 	.byte #0xC8,#0xAF
   1B41 50 C3              2454 	.byte #0x50,#0xC3
   1B43 D8 D6              2455 	.byte #0xD8,#0xD6
   1B45 60 EA              2456 	.byte #0x60,#0xEA
   1B47 FF FF              2457 	.byte #0xFF,#0xFF
   1B49 FF FF              2458 	.byte #0xFF,#0xFF
   1B4B FF FF              2459 	.byte #0xFF,#0xFF
   1B4D FF FF              2460 	.byte #0xFF,#0xFF
   1B4F                    2461 _hystable:
   1B4F 01                 2462 	.db #0x01
   1B50 02                 2463 	.db #0x02
   1B51 0A                 2464 	.db #0x0A
   1B52 05                 2465 	.db #0x05
   1B53 03                 2466 	.db #0x03
   1B54                    2467 _luxdelay:
   1B54 00 00              2468 	.byte #0x00,#0x00
   1B56 0F 00              2469 	.byte #0x0F,#0x00
   1B58 26 00              2470 	.byte #0x26,#0x00
   1B5A 4B 00              2471 	.byte #0x4B,#0x00
   1B5C 70 00              2472 	.byte #0x70,#0x00
   1B5E 95 00              2473 	.byte #0x95,#0x00
   1B60 E1 00              2474 	.byte #0xE1,#0x00
   1B62 51 01              2475 	.byte #0x51,#0x01
   1B64 C1 01              2476 	.byte #0xC1,#0x01
   1B66 A2 02              2477 	.byte #0xA2,#0x02
   1B68 81 03              2478 	.byte #0x81,#0x03
   1B6A 42 05              2479 	.byte #0x42,#0x05
   1B6C C3 08              2480 	.byte #0xC3,#0x08
   1B6E 85 11              2481 	.byte #0x85,#0x11
   1B70 52 1A              2482 	.byte #0x52,#0x1A
   1B72 8E 34              2483 	.byte #0x8E,#0x34
   1B74                    2484 _ctrl_adr:
   1B74 D2                 2485 	.db #0xD2
   1B75 D1                 2486 	.db #0xD1
   1B76 00                 2487 	.db #0x00
   1B77 F9                 2488 	.db #0xF9
   1B78 F4                 2489 	.db #0xF4
   1B79 EF                 2490 	.db #0xEF
   1B7A EA                 2491 	.db #0xEA
   1B7B E5                 2492 	.db #0xE5
   1B7C E0                 2493 	.db #0xE0
   1B7D DA                 2494 	.db #0xDA
                           2495 	.area XINIT   (CODE)
                           2496 	.area CABS    (ABS,CODE)
