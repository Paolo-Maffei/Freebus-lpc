                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
                              4 ; This file was generated Sun Jul 15 18:51:27 2012
                              5 ;--------------------------------------------------------
                              6 	.module onewire
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
                            147 	.globl _ow_init
                            148 	.globl _ow_write
                            149 	.globl _ow_read
                            150 	.globl _ow_read_bit
                            151 	.globl _start_tempconversion
                            152 	.globl _read_temp
                            153 	.globl _owdelay
                            154 ;--------------------------------------------------------
                            155 ; special function registers
                            156 ;--------------------------------------------------------
                            157 	.area RSEG    (DATA)
                    0080    158 _P0	=	0x0080
                    0090    159 _P1	=	0x0090
                    00B0    160 _P3	=	0x00b0
                    00D0    161 _PSW	=	0x00d0
                    00E0    162 _ACC	=	0x00e0
                    00F0    163 _B	=	0x00f0
                    0081    164 _SP	=	0x0081
                    0082    165 _DPL	=	0x0082
                    0083    166 _DPH	=	0x0083
                    0087    167 _PCON	=	0x0087
                    0088    168 _TCON	=	0x0088
                    0089    169 _TMOD	=	0x0089
                    008A    170 _TL0	=	0x008a
                    008B    171 _TL1	=	0x008b
                    008C    172 _TH0	=	0x008c
                    008D    173 _TH1	=	0x008d
                    00A8    174 _IEN0	=	0x00a8
                    00B8    175 _IP0	=	0x00b8
                    0098    176 _SCON	=	0x0098
                    0099    177 _SBUF	=	0x0099
                    00A2    178 _AUXR1	=	0x00a2
                    00A9    179 _SADDR	=	0x00a9
                    00B9    180 _SADEN	=	0x00b9
                    00BE    181 _BRGR0	=	0x00be
                    00BF    182 _BRGR1	=	0x00bf
                    00BD    183 _BRGCON	=	0x00bd
                    00AC    184 _CMP1	=	0x00ac
                    00AD    185 _CMP2	=	0x00ad
                    0095    186 _DIVM	=	0x0095
                    00E7    187 _FMADRH	=	0x00e7
                    00E6    188 _FMADRL	=	0x00e6
                    00E4    189 _FMCON	=	0x00e4
                    00E5    190 _FMDATA	=	0x00e5
                    00DB    191 _I2ADR	=	0x00db
                    00D8    192 _I2CON	=	0x00d8
                    00DA    193 _I2DAT	=	0x00da
                    00DD    194 _I2SCLH	=	0x00dd
                    00DC    195 _I2SCLL	=	0x00dc
                    00D9    196 _I2STAT	=	0x00d9
                    00F8    197 _IP1	=	0x00f8
                    00F7    198 _IP1H	=	0x00f7
                    0094    199 _KBCON	=	0x0094
                    0086    200 _KBMASK	=	0x0086
                    0093    201 _KBPATN	=	0x0093
                    0084    202 _P0M1	=	0x0084
                    0085    203 _P0M2	=	0x0085
                    0091    204 _P1M1	=	0x0091
                    0092    205 _P1M2	=	0x0092
                    00B1    206 _P3M1	=	0x00b1
                    00B2    207 _P3M2	=	0x00b2
                    00B5    208 _PCONA	=	0x00b5
                    00F6    209 _PT0AD	=	0x00f6
                    00DF    210 _RSTSRC	=	0x00df
                    00D1    211 _RTCCON	=	0x00d1
                    00D2    212 _RTCH	=	0x00d2
                    00D3    213 _RTCL	=	0x00d3
                    00BA    214 _SSTAT	=	0x00ba
                    008F    215 _TAMOD	=	0x008f
                    0096    216 _TRIM	=	0x0096
                    00A7    217 _WDCON	=	0x00a7
                    00C1    218 _WDL	=	0x00c1
                    00C2    219 _WFEED1	=	0x00c2
                    00C3    220 _WFEED2	=	0x00c3
                    00B7    221 _IP0H	=	0x00b7
                    00E8    222 _IEN1	=	0x00e8
                            223 ;--------------------------------------------------------
                            224 ; special function bits
                            225 ;--------------------------------------------------------
                            226 	.area RSEG    (DATA)
                    00D0    227 _PSW_0	=	0x00d0
                    00D1    228 _PSW_1	=	0x00d1
                    00D2    229 _PSW_2	=	0x00d2
                    00D3    230 _PSW_3	=	0x00d3
                    00D4    231 _PSW_4	=	0x00d4
                    00D5    232 _PSW_5	=	0x00d5
                    00D6    233 _PSW_6	=	0x00d6
                    00D7    234 _PSW_7	=	0x00d7
                    008F    235 _TCON_7	=	0x008f
                    008E    236 _TCON_6	=	0x008e
                    008D    237 _TCON_5	=	0x008d
                    008C    238 _TCON_4	=	0x008c
                    008B    239 _TCON_3	=	0x008b
                    008A    240 _TCON_2	=	0x008a
                    0089    241 _TCON_1	=	0x0089
                    0088    242 _TCON_0	=	0x0088
                    00AF    243 _IEN0_7	=	0x00af
                    00AE    244 _IEN0_6	=	0x00ae
                    00AD    245 _IEN0_5	=	0x00ad
                    00AC    246 _IEN0_4	=	0x00ac
                    00AB    247 _IEN0_3	=	0x00ab
                    00AA    248 _IEN0_2	=	0x00aa
                    00A9    249 _IEN0_1	=	0x00a9
                    00A8    250 _IEN0_0	=	0x00a8
                    00EA    251 _IEN1_2	=	0x00ea
                    00E9    252 _IEN1_1	=	0x00e9
                    00E8    253 _IEN1_0	=	0x00e8
                    00FE    254 _IP1_6	=	0x00fe
                    00FA    255 _IP1_2	=	0x00fa
                    00F9    256 _IP1_1	=	0x00f9
                    00F8    257 _IP1_0	=	0x00f8
                    00BE    258 _IP0_6	=	0x00be
                    00BD    259 _IP0_5	=	0x00bd
                    00BC    260 _IP0_4	=	0x00bc
                    00BB    261 _IP0_3	=	0x00bb
                    00BA    262 _IP0_2	=	0x00ba
                    00B9    263 _IP0_1	=	0x00b9
                    00B8    264 _IP0_0	=	0x00b8
                    0098    265 _SCON_0	=	0x0098
                    0099    266 _SCON_1	=	0x0099
                    009A    267 _SCON_2	=	0x009a
                    009B    268 _SCON_3	=	0x009b
                    009C    269 _SCON_4	=	0x009c
                    009D    270 _SCON_5	=	0x009d
                    009E    271 _SCON_6	=	0x009e
                    009F    272 _SCON_7	=	0x009f
                    00DE    273 _I2CON_6	=	0x00de
                    00DD    274 _I2CON_5	=	0x00dd
                    00DC    275 _I2CON_4	=	0x00dc
                    00DB    276 _I2CON_3	=	0x00db
                    00DA    277 _I2CON_2	=	0x00da
                    00D8    278 _I2CON_0	=	0x00d8
                    0080    279 _P0_0	=	0x0080
                    0081    280 _P0_1	=	0x0081
                    0082    281 _P0_2	=	0x0082
                    0083    282 _P0_3	=	0x0083
                    0084    283 _P0_4	=	0x0084
                    0085    284 _P0_5	=	0x0085
                    0086    285 _P0_6	=	0x0086
                    0087    286 _P0_7	=	0x0087
                    0090    287 _P1_0	=	0x0090
                    0091    288 _P1_1	=	0x0091
                    0092    289 _P1_2	=	0x0092
                    0093    290 _P1_3	=	0x0093
                    0094    291 _P1_4	=	0x0094
                    0095    292 _P1_5	=	0x0095
                    0096    293 _P1_6	=	0x0096
                    0097    294 _P1_7	=	0x0097
                    00B0    295 _P3_0	=	0x00b0
                    00B1    296 _P3_1	=	0x00b1
                            297 ;--------------------------------------------------------
                            298 ; overlayable register banks
                            299 ;--------------------------------------------------------
                            300 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     301 	.ds 8
                            302 ;--------------------------------------------------------
                            303 ; overlayable bit register bank
                            304 ;--------------------------------------------------------
                            305 	.area BIT_BANK	(REL,OVR,DATA)
   0023                     306 bits:
   0023                     307 	.ds 1
                    8000    308 	b0 = bits[0]
                    8100    309 	b1 = bits[1]
                    8200    310 	b2 = bits[2]
                    8300    311 	b3 = bits[3]
                    8400    312 	b4 = bits[4]
                    8500    313 	b5 = bits[5]
                    8600    314 	b6 = bits[6]
                    8700    315 	b7 = bits[7]
                            316 ;--------------------------------------------------------
                            317 ; internal ram data
                            318 ;--------------------------------------------------------
                            319 	.area DSEG    (DATA)
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
                            337 ;--------------------------------------------------------
                            338 ; paged external ram data
                            339 ;--------------------------------------------------------
                            340 	.area PSEG    (PAG,XDATA)
                            341 ;--------------------------------------------------------
                            342 ; external ram data
                            343 ;--------------------------------------------------------
                            344 	.area XSEG    (XDATA)
                            345 ;--------------------------------------------------------
                            346 ; absolute external ram data
                            347 ;--------------------------------------------------------
                            348 	.area XABS    (ABS,XDATA)
                            349 ;--------------------------------------------------------
                            350 ; external initialized ram data
                            351 ;--------------------------------------------------------
                            352 	.area XISEG   (XDATA)
                            353 	.area HOME    (CODE)
                            354 	.area GSINIT0 (CODE)
                            355 	.area GSINIT1 (CODE)
                            356 	.area GSINIT2 (CODE)
                            357 	.area GSINIT3 (CODE)
                            358 	.area GSINIT4 (CODE)
                            359 	.area GSINIT5 (CODE)
                            360 	.area GSINIT  (CODE)
                            361 	.area GSFINAL (CODE)
                            362 	.area CSEG    (CODE)
                            363 ;--------------------------------------------------------
                            364 ; global & static initialisations
                            365 ;--------------------------------------------------------
                            366 	.area HOME    (CODE)
                            367 	.area GSINIT  (CODE)
                            368 	.area GSFINAL (CODE)
                            369 	.area GSINIT  (CODE)
                            370 ;--------------------------------------------------------
                            371 ; Home
                            372 ;--------------------------------------------------------
                            373 	.area HOME    (CODE)
                            374 	.area HOME    (CODE)
                            375 ;--------------------------------------------------------
                            376 ; code
                            377 ;--------------------------------------------------------
                            378 	.area CSEG    (CODE)
                            379 ;------------------------------------------------------------
                            380 ;Allocation info for local variables in function 'ow_init'
                            381 ;------------------------------------------------------------
                            382 ;presence                  Allocated to registers b0 
                            383 ;n                         Allocated to registers r2 
                            384 ;------------------------------------------------------------
                            385 ;	../../com/onewire.c:18: bit ow_init(void)		// one-wire Gerät initialisieren
                            386 ;	-----------------------------------------
                            387 ;	 function ow_init
                            388 ;	-----------------------------------------
   0F39                     389 _ow_init:
                    0002    390 	ar2 = 0x02
                    0003    391 	ar3 = 0x03
                    0004    392 	ar4 = 0x04
                    0005    393 	ar5 = 0x05
                    0006    394 	ar6 = 0x06
                    0007    395 	ar7 = 0x07
                    0000    396 	ar0 = 0x00
                    0001    397 	ar1 = 0x01
                            398 ;	../../com/onewire.c:23: presence=1;
   0F39 D2 18               399 	setb	b0
                            400 ;	../../com/onewire.c:24: OWDATA=0;
   0F3B C2 87               401 	clr	_P0_7
                            402 ;	../../com/onewire.c:25: owdelay(2500);
   0F3D 90 09 C4            403 	mov	dptr,#0x09C4
   0F40 C0 23               404 	push	bits
   0F42 12 10 8F            405 	lcall	_owdelay
   0F45 D0 23               406 	pop	bits
                            407 ;	../../com/onewire.c:26: OWDATA=1;
   0F47 D2 87               408 	setb	_P0_7
                            409 ;	../../com/onewire.c:27: for (n=0;n<255;n++) presence=presence & OWDATA;
   0F49 7A FF               410 	mov	r2,#0xFF
   0F4B                     411 00103$:
   0F4B A2 87               412 	mov	c,_P0_7
   0F4D 82 18               413 	anl	c,b0
   0F4F 92 18               414 	mov	b0,c
   0F51 DA F8               415 	djnz	r2,00103$
                            416 ;	../../com/onewire.c:28: presence=!presence;
   0F53 B2 18               417 	cpl	b0
                            418 ;	../../com/onewire.c:29: return (presence);
   0F55 A2 18               419 	mov	c,b0
   0F57 22                  420 	ret
                            421 ;------------------------------------------------------------
                            422 ;Allocation info for local variables in function 'ow_write'
                            423 ;------------------------------------------------------------
                            424 ;owbyte                    Allocated to registers r2 
                            425 ;n                         Allocated to registers r3 
                            426 ;m                         Allocated to registers r4 
                            427 ;------------------------------------------------------------
                            428 ;	../../com/onewire.c:32: void ow_write(unsigned char owbyte)	// Byte an one-wire Gerät senden
                            429 ;	-----------------------------------------
                            430 ;	 function ow_write
                            431 ;	-----------------------------------------
   0F58                     432 _ow_write:
   0F58 AA 82               433 	mov	r2,dpl
                            434 ;	../../com/onewire.c:37: for (n=1;n!=0;n=n<<1)		// LSB first
   0F5A 7B 01               435 	mov	r3,#0x01
   0F5C                     436 00108$:
   0F5C BB 00 01            437 	cjne	r3,#0x00,00120$
   0F5F 22                  438 	ret
   0F60                     439 00120$:
                            440 ;	../../com/onewire.c:40: if (owbyte & n)
   0F60 EB                  441 	mov	a,r3
   0F61 5A                  442 	anl	a,r2
   0F62 60 1E               443 	jz	00102$
                            444 ;	../../com/onewire.c:42: for (m=0;m<2;m++) OWDATA=0;	// 1-Bit: 5µs auf low dann auf high und 85µs warten
   0F64 7C 00               445 	mov	r4,#0x00
   0F66                     446 00104$:
   0F66 BC 02 00            447 	cjne	r4,#0x02,00122$
   0F69                     448 00122$:
   0F69 50 05               449 	jnc	00107$
   0F6B C2 87               450 	clr	_P0_7
   0F6D 0C                  451 	inc	r4
   0F6E 80 F6               452 	sjmp	00104$
   0F70                     453 00107$:
                            454 ;	../../com/onewire.c:43: OWDATA=1;
   0F70 D2 87               455 	setb	_P0_7
                            456 ;	../../com/onewire.c:44: owdelay(260);
   0F72 90 01 04            457 	mov	dptr,#0x0104
   0F75 C0 02               458 	push	ar2
   0F77 C0 03               459 	push	ar3
   0F79 12 10 8F            460 	lcall	_owdelay
   0F7C D0 03               461 	pop	ar3
   0F7E D0 02               462 	pop	ar2
   0F80 80 12               463 	sjmp	00110$
   0F82                     464 00102$:
                            465 ;	../../com/onewire.c:48: OWDATA=0;			// 0-Bit: 90µs auf low dann auf high
   0F82 C2 87               466 	clr	_P0_7
                            467 ;	../../com/onewire.c:49: owdelay(275);
   0F84 90 01 13            468 	mov	dptr,#0x0113
   0F87 C0 02               469 	push	ar2
   0F89 C0 03               470 	push	ar3
   0F8B 12 10 8F            471 	lcall	_owdelay
   0F8E D0 03               472 	pop	ar3
   0F90 D0 02               473 	pop	ar2
                            474 ;	../../com/onewire.c:50: OWDATA=1;
   0F92 D2 87               475 	setb	_P0_7
   0F94                     476 00110$:
                            477 ;	../../com/onewire.c:37: for (n=1;n!=0;n=n<<1)		// LSB first
   0F94 EB                  478 	mov	a,r3
   0F95 2B                  479 	add	a,r3
   0F96 FB                  480 	mov	r3,a
   0F97 80 C3               481 	sjmp	00108$
                            482 ;------------------------------------------------------------
                            483 ;Allocation info for local variables in function 'ow_read'
                            484 ;------------------------------------------------------------
                            485 ;n                         Allocated to registers r3 
                            486 ;m                         Allocated to registers r4 
                            487 ;d                         Allocated to registers r2 
                            488 ;------------------------------------------------------------
                            489 ;	../../com/onewire.c:56: unsigned char ow_read(void)			// Byte von one-wire Gerät lesen
                            490 ;	-----------------------------------------
                            491 ;	 function ow_read
                            492 ;	-----------------------------------------
   0F99                     493 _ow_read:
                            494 ;	../../com/onewire.c:60: d=0;
   0F99 7A 00               495 	mov	r2,#0x00
                            496 ;	../../com/onewire.c:62: for (n=1;n!=0;n=n<<1)
   0F9B 7B 01               497 	mov	r3,#0x01
   0F9D                     498 00107$:
   0F9D BB 00 02            499 	cjne	r3,#0x00,00119$
   0FA0 80 35               500 	sjmp	00110$
   0FA2                     501 00119$:
                            502 ;	../../com/onewire.c:64: for (m=0;m<2;m++) OWDATA=0;
   0FA2 7C 00               503 	mov	r4,#0x00
   0FA4                     504 00103$:
   0FA4 BC 02 00            505 	cjne	r4,#0x02,00120$
   0FA7                     506 00120$:
   0FA7 50 05               507 	jnc	00106$
   0FA9 C2 87               508 	clr	_P0_7
   0FAB 0C                  509 	inc	r4
   0FAC 80 F6               510 	sjmp	00103$
   0FAE                     511 00106$:
                            512 ;	../../com/onewire.c:65: OWDATA=1;
   0FAE D2 87               513 	setb	_P0_7
                            514 ;	../../com/onewire.c:66: owdelay(1);
   0FB0 90 00 01            515 	mov	dptr,#0x0001
   0FB3 C0 02               516 	push	ar2
   0FB5 C0 03               517 	push	ar3
   0FB7 12 10 8F            518 	lcall	_owdelay
   0FBA D0 03               519 	pop	ar3
   0FBC D0 02               520 	pop	ar2
                            521 ;	../../com/onewire.c:68: if (OWDATA) d|=n;
   0FBE 30 87 03            522 	jnb	_P0_7,00102$
   0FC1 EB                  523 	mov	a,r3
   0FC2 42 02               524 	orl	ar2,a
   0FC4                     525 00102$:
                            526 ;	../../com/onewire.c:69: owdelay(140);
   0FC4 90 00 8C            527 	mov	dptr,#0x008C
   0FC7 C0 02               528 	push	ar2
   0FC9 C0 03               529 	push	ar3
   0FCB 12 10 8F            530 	lcall	_owdelay
   0FCE D0 03               531 	pop	ar3
   0FD0 D0 02               532 	pop	ar2
                            533 ;	../../com/onewire.c:62: for (n=1;n!=0;n=n<<1)
   0FD2 EB                  534 	mov	a,r3
   0FD3 2B                  535 	add	a,r3
   0FD4 FB                  536 	mov	r3,a
   0FD5 80 C6               537 	sjmp	00107$
   0FD7                     538 00110$:
                            539 ;	../../com/onewire.c:72: return(d);
   0FD7 8A 82               540 	mov	dpl,r2
   0FD9 22                  541 	ret
                            542 ;------------------------------------------------------------
                            543 ;Allocation info for local variables in function 'ow_read_bit'
                            544 ;------------------------------------------------------------
                            545 ;m                         Allocated to registers r2 
                            546 ;b                         Allocated to registers b0 
                            547 ;------------------------------------------------------------
                            548 ;	../../com/onewire.c:77: bit ow_read_bit(void)				// Bit von one-wire Datenleitung einlesen
                            549 ;	-----------------------------------------
                            550 ;	 function ow_read_bit
                            551 ;	-----------------------------------------
   0FDA                     552 _ow_read_bit:
                            553 ;	../../com/onewire.c:82: for (m=0;m<2;m++) OWDATA=0;
   0FDA 7A 00               554 	mov	r2,#0x00
   0FDC                     555 00101$:
   0FDC BA 02 00            556 	cjne	r2,#0x02,00110$
   0FDF                     557 00110$:
   0FDF 50 05               558 	jnc	00104$
   0FE1 C2 87               559 	clr	_P0_7
   0FE3 0A                  560 	inc	r2
   0FE4 80 F6               561 	sjmp	00101$
   0FE6                     562 00104$:
                            563 ;	../../com/onewire.c:83: OWDATA=1;
   0FE6 D2 87               564 	setb	_P0_7
                            565 ;	../../com/onewire.c:84: owdelay(1);
   0FE8 90 00 01            566 	mov	dptr,#0x0001
   0FEB 12 10 8F            567 	lcall	_owdelay
                            568 ;	../../com/onewire.c:85: b=OWDATA;
   0FEE A2 87               569 	mov	c,_P0_7
   0FF0 92 18               570 	mov	b0,c
                            571 ;	../../com/onewire.c:86: owdelay (140);
   0FF2 90 00 8C            572 	mov	dptr,#0x008C
   0FF5 C0 23               573 	push	bits
   0FF7 12 10 8F            574 	lcall	_owdelay
   0FFA D0 23               575 	pop	bits
                            576 ;	../../com/onewire.c:87: return (b);
   0FFC A2 18               577 	mov	c,b0
   0FFE 22                  578 	ret
                            579 ;------------------------------------------------------------
                            580 ;Allocation info for local variables in function 'start_tempconversion'
                            581 ;------------------------------------------------------------
                            582 ;------------------------------------------------------------
                            583 ;	../../com/onewire.c:91: void start_tempconversion(void)		// Temperaturmessung starten
                            584 ;	-----------------------------------------
                            585 ;	 function start_tempconversion
                            586 ;	-----------------------------------------
   0FFF                     587 _start_tempconversion:
                            588 ;	../../com/onewire.c:93: if (ow_init()) {
   0FFF 12 0F 39            589 	lcall	_ow_init
   1002 50 0C               590 	jnc	00103$
                            591 ;	../../com/onewire.c:95: ow_write(0xCC);			// Skip-ROM command: alle parallel angeschlossenen Geräte werden angesprochen
   1004 75 82 CC            592 	mov	dpl,#0xCC
   1007 12 0F 58            593 	lcall	_ow_write
                            594 ;	../../com/onewire.c:96: ow_write(0x44);			// start single temperature conversion command
   100A 75 82 44            595 	mov	dpl,#0x44
   100D 02 0F 58            596 	ljmp	_ow_write
   1010                     597 00103$:
   1010 22                  598 	ret
                            599 ;------------------------------------------------------------
                            600 ;Allocation info for local variables in function 'read_temp'
                            601 ;------------------------------------------------------------
                            602 ;lsb                       Allocated to registers r2 
                            603 ;msb                       Allocated to registers r3 
                            604 ;t                         Allocated to registers r5 r6 
                            605 ;t2                        Allocated to registers r3 r2 
                            606 ;sign                      Allocated to registers r4 
                            607 ;------------------------------------------------------------
                            608 ;	../../com/onewire.c:100: signed int read_temp(void)					// Temperatur einlesen
                            609 ;	-----------------------------------------
                            610 ;	 function read_temp
                            611 ;	-----------------------------------------
   1011                     612 _read_temp:
                            613 ;	../../com/onewire.c:112: if (ow_init()) {
   1011 12 0F 39            614 	lcall	_ow_init
   1014 50 70               615 	jnc	00106$
                            616 ;	../../com/onewire.c:113: ow_write(0xCC);			// Skip-ROM command: alle parallel angeschlossenen Geräte werden angesprochen
   1016 75 82 CC            617 	mov	dpl,#0xCC
   1019 12 0F 58            618 	lcall	_ow_write
                            619 ;	../../com/onewire.c:114: ow_write(0xBE);			// read scratchpad command: Speicher einlesen
   101C 75 82 BE            620 	mov	dpl,#0xBE
   101F 12 0F 58            621 	lcall	_ow_write
                            622 ;	../../com/onewire.c:115: lsb=ow_read();			// LSB von Temperaturwert
   1022 12 0F 99            623 	lcall	_ow_read
   1025 AA 82               624 	mov	r2,dpl
                            625 ;	../../com/onewire.c:116: msb=ow_read();			// MSB von Temperaturwert
   1027 C0 02               626 	push	ar2
   1029 12 0F 99            627 	lcall	_ow_read
   102C AB 82               628 	mov	r3,dpl
   102E D0 02               629 	pop	ar2
                            630 ;	../../com/onewire.c:134: sign=msb&0x80;
   1030 74 80               631 	mov	a,#0x80
   1032 5B                  632 	anl	a,r3
   1033 FC                  633 	mov	r4,a
                            634 ;	../../com/onewire.c:135: t2=msb*256+lsb;
   1034 8B 05               635 	mov	ar5,r3
   1036 E4                  636 	clr	a
   1037 FB                  637 	mov	r3,a
   1038 FE                  638 	mov	r6,a
   1039 EA                  639 	mov	a,r2
   103A 2B                  640 	add	a,r3
   103B FB                  641 	mov	r3,a
   103C EE                  642 	mov	a,r6
   103D 3D                  643 	addc	a,r5
   103E FD                  644 	mov	r5,a
   103F FA                  645 	mov	r2,a
                            646 ;	../../com/onewire.c:136: if (sign) t2=(0xFFFF-t2)+1;
   1040 EC                  647 	mov	a,r4
   1041 60 07               648 	jz	00102$
   1043 C3                  649 	clr	c
   1044 E4                  650 	clr	a
   1045 9B                  651 	subb	a,r3
   1046 FB                  652 	mov	r3,a
   1047 E4                  653 	clr	a
   1048 9A                  654 	subb	a,r2
   1049 FA                  655 	mov	r2,a
   104A                     656 00102$:
                            657 ;	../../com/onewire.c:140: t=t2*6;
   104A C0 02               658 	push	ar2
   104C C0 03               659 	push	ar3
   104E C0 04               660 	push	ar4
   1050 C0 03               661 	push	ar3
   1052 C0 02               662 	push	ar2
   1054 90 00 06            663 	mov	dptr,#0x0006
   1057 12 1A 63            664 	lcall	__mulint
   105A AD 82               665 	mov	r5,dpl
   105C AE 83               666 	mov	r6,dph
   105E 15 81               667 	dec	sp
   1060 15 81               668 	dec	sp
   1062 D0 04               669 	pop	ar4
   1064 D0 03               670 	pop	ar3
   1066 D0 02               671 	pop	ar2
                            672 ;	../../com/onewire.c:141: t2=t2>>2;
   1068 EA                  673 	mov	a,r2
   1069 C3                  674 	clr	c
   106A 13                  675 	rrc	a
   106B CB                  676 	xch	a,r3
   106C 13                  677 	rrc	a
   106D CB                  678 	xch	a,r3
   106E C3                  679 	clr	c
   106F 13                  680 	rrc	a
   1070 CB                  681 	xch	a,r3
   1071 13                  682 	rrc	a
   1072 CB                  683 	xch	a,r3
   1073 FA                  684 	mov	r2,a
                            685 ;	../../com/onewire.c:142: t=t+t2;					// hier ist t die Teperatur in 0,01°C
   1074 EB                  686 	mov	a,r3
   1075 2D                  687 	add	a,r5
   1076 FD                  688 	mov	r5,a
   1077 EA                  689 	mov	a,r2
   1078 3E                  690 	addc	a,r6
   1079 FE                  691 	mov	r6,a
                            692 ;	../../com/onewire.c:149: if (sign) t=-t;		// Vorzeichen
   107A EC                  693 	mov	a,r4
   107B 60 0D               694 	jz	00107$
   107D C3                  695 	clr	c
   107E E4                  696 	clr	a
   107F 9D                  697 	subb	a,r5
   1080 FD                  698 	mov	r5,a
   1081 E4                  699 	clr	a
   1082 9E                  700 	subb	a,r6
   1083 FE                  701 	mov	r6,a
   1084 80 04               702 	sjmp	00107$
   1086                     703 00106$:
                            704 ;	../../com/onewire.c:152: else t=0xFFFF;				// im Fehlerfall 0xFFFF zurückmelden
   1086 7D FF               705 	mov	r5,#0xFF
   1088 7E FF               706 	mov	r6,#0xFF
   108A                     707 00107$:
                            708 ;	../../com/onewire.c:153: return (t);
   108A 8D 82               709 	mov	dpl,r5
   108C 8E 83               710 	mov	dph,r6
   108E 22                  711 	ret
                            712 ;------------------------------------------------------------
                            713 ;Allocation info for local variables in function 'owdelay'
                            714 ;------------------------------------------------------------
                            715 ;deltime                   Allocated to registers r2 r3 
                            716 ;------------------------------------------------------------
                            717 ;	../../com/onewire.c:157: void owdelay(int deltime)			// Warten, deltime = Anzahl Takte / 2 (Timer wird mit CCLK/2 betrieben) 
                            718 ;	-----------------------------------------
                            719 ;	 function owdelay
                            720 ;	-----------------------------------------
   108F                     721 _owdelay:
   108F AA 82               722 	mov	r2,dpl
   1091 AB 83               723 	mov	r3,dph
                            724 ;	../../com/onewire.c:160: TR0=0;					// Timer 0 anhalten
   1093 C2 8C               725 	clr	_TCON_4
                            726 ;	../../com/onewire.c:161: deltime=0xFFFF-deltime;
   1095 74 FF               727 	mov	a,#0xFF
   1097 C3                  728 	clr	c
   1098 9A                  729 	subb	a,r2
   1099 FA                  730 	mov	r2,a
   109A 74 FF               731 	mov	a,#0xFF
   109C 9B                  732 	subb	a,r3
   109D FB                  733 	mov	r3,a
                            734 ;	../../com/onewire.c:162: TH0=deltime>>8;			// Timer 0 setzen 
   109E 8B 8C               735 	mov	_TH0,r3
                            736 ;	../../com/onewire.c:163: TL0=deltime;	
   10A0 8A 8A               737 	mov	_TL0,r2
                            738 ;	../../com/onewire.c:164: TF0=0;
   10A2 C2 8D               739 	clr	_TCON_5
                            740 ;	../../com/onewire.c:165: TR0=1;
   10A4 D2 8C               741 	setb	_TCON_4
                            742 ;	../../com/onewire.c:166: while(!TF0);				// warten auf Timer 0
   10A6                     743 00101$:
   10A6 30 8D FD            744 	jnb	_TCON_5,00101$
                            745 ;	../../com/onewire.c:167: TR0=0;		
   10A9 C2 8C               746 	clr	_TCON_4
   10AB 22                  747 	ret
                            748 	.area CSEG    (CODE)
                            749 	.area CONST   (CODE)
                            750 	.area XINIT   (CODE)
                            751 	.area CABS    (ABS,CODE)
