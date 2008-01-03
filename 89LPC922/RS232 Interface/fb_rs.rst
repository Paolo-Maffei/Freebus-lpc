                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : FreeWare ANSI-C Compiler
                              3 ; Version 2.6.1 #4376 (Sep 14 2006)
                              4 ; This file generated Wed Jan 02 12:56:17 2008
                              5 ;--------------------------------------------------------
                              6 	.module fb_rs
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _dataflash
                             13 	.globl _main
                             14 	.globl _find_ga
                             15 	.globl _get_ack
                             16 	.globl _P3_1
                             17 	.globl _P3_0
                             18 	.globl _P1_7
                             19 	.globl _P1_6
                             20 	.globl _P1_5
                             21 	.globl _P1_4
                             22 	.globl _P1_3
                             23 	.globl _P1_2
                             24 	.globl _P1_1
                             25 	.globl _P1_0
                             26 	.globl _P0_7
                             27 	.globl _P0_6
                             28 	.globl _P0_5
                             29 	.globl _P0_4
                             30 	.globl _P0_3
                             31 	.globl _P0_2
                             32 	.globl _P0_1
                             33 	.globl _P0_0
                             34 	.globl _I2CON_0
                             35 	.globl _I2CON_2
                             36 	.globl _I2CON_3
                             37 	.globl _I2CON_4
                             38 	.globl _I2CON_5
                             39 	.globl _I2CON_6
                             40 	.globl _SCON_7
                             41 	.globl _SCON_6
                             42 	.globl _SCON_5
                             43 	.globl _SCON_4
                             44 	.globl _SCON_3
                             45 	.globl _SCON_2
                             46 	.globl _SCON_1
                             47 	.globl _SCON_0
                             48 	.globl _IP0_0
                             49 	.globl _IP0_1
                             50 	.globl _IP0_2
                             51 	.globl _IP0_3
                             52 	.globl _IP0_4
                             53 	.globl _IP0_5
                             54 	.globl _IP0_6
                             55 	.globl _IP1_0
                             56 	.globl _IP1_1
                             57 	.globl _IP1_2
                             58 	.globl _IP1_6
                             59 	.globl _IEN1_0
                             60 	.globl _IEN1_1
                             61 	.globl _IEN1_2
                             62 	.globl _IEN0_0
                             63 	.globl _IEN0_1
                             64 	.globl _IEN0_2
                             65 	.globl _IEN0_3
                             66 	.globl _IEN0_4
                             67 	.globl _IEN0_5
                             68 	.globl _IEN0_6
                             69 	.globl _IEN0_7
                             70 	.globl _TCON_0
                             71 	.globl _TCON_1
                             72 	.globl _TCON_2
                             73 	.globl _TCON_3
                             74 	.globl _TCON_4
                             75 	.globl _TCON_5
                             76 	.globl _TCON_6
                             77 	.globl _TCON_7
                             78 	.globl _CY
                             79 	.globl _AC
                             80 	.globl _F0
                             81 	.globl _RS1
                             82 	.globl _RS0
                             83 	.globl _OV
                             84 	.globl _F1
                             85 	.globl _P
                             86 	.globl _PSW_7
                             87 	.globl _PSW_6
                             88 	.globl _PSW_5
                             89 	.globl _PSW_4
                             90 	.globl _PSW_3
                             91 	.globl _PSW_2
                             92 	.globl _PSW_1
                             93 	.globl _PSW_0
                             94 	.globl _IEN1
                             95 	.globl _IP0H
                             96 	.globl _WFEED2
                             97 	.globl _WFEED1
                             98 	.globl _WDL
                             99 	.globl _WDCON
                            100 	.globl _TRIM
                            101 	.globl _TAMOD
                            102 	.globl _SSTAT
                            103 	.globl _RTCL
                            104 	.globl _RTCH
                            105 	.globl _RTCCON
                            106 	.globl _RSTSRC
                            107 	.globl _PT0AD
                            108 	.globl _PCONA
                            109 	.globl _P3M2
                            110 	.globl _P3M1
                            111 	.globl _P1M2
                            112 	.globl _P1M1
                            113 	.globl _P0M2
                            114 	.globl _P0M1
                            115 	.globl _KBPATN
                            116 	.globl _KBMASK
                            117 	.globl _KBCON
                            118 	.globl _IP1H
                            119 	.globl _IP1
                            120 	.globl _I2STAT
                            121 	.globl _I2SCLL
                            122 	.globl _I2SCLH
                            123 	.globl _I2DAT
                            124 	.globl _I2CON
                            125 	.globl _I2ADR
                            126 	.globl _FMDATA
                            127 	.globl _FMCON
                            128 	.globl _FMADRL
                            129 	.globl _FMADRH
                            130 	.globl _DIVM
                            131 	.globl _CMP2
                            132 	.globl _CMP1
                            133 	.globl _BRGCON
                            134 	.globl _BRGR1
                            135 	.globl _BRGR0
                            136 	.globl _SADEN
                            137 	.globl _SADDR
                            138 	.globl _AUXR1
                            139 	.globl _SBUF
                            140 	.globl _SCON
                            141 	.globl _IP0
                            142 	.globl _IEN0
                            143 	.globl _TH1
                            144 	.globl _TH0
                            145 	.globl _TL1
                            146 	.globl _TL0
                            147 	.globl _TMOD
                            148 	.globl _TCON
                            149 	.globl _PCON
                            150 	.globl _DPH
                            151 	.globl _DPL
                            152 	.globl _SP
                            153 	.globl _B
                            154 	.globl _ACC
                            155 	.globl _PSW
                            156 	.globl _P3
                            157 	.globl _P1
                            158 	.globl _P0
                            159 	.globl _connected
                            160 	.globl _progmode
                            161 	.globl _parity_ok
                            162 	.globl _pcount
                            163 	.globl _conl
                            164 	.globl _conh
                            165 	.globl _gacount
                            166 	.globl _pah
                            167 	.globl _pal
                            168 	.globl _cs
                            169 	.globl _telpos
                            170 	.globl _telegramm
                            171 	.globl _get_byte
                            172 	.globl _ext_int0
                            173 	.globl _sendbyte
                            174 	.globl _start_writecycle
                            175 	.globl _stop_writecycle
                            176 	.globl _write_byte
                            177 	.globl _delay
                            178 	.globl _set_timer1
                            179 	.globl _read_byte
                            180 	.globl _restart_hw
                            181 	.globl _timer1
                            182 	.globl _send_telegramm
                            183 	.globl _send_ack
                            184 	.globl _ucd_opr
                            185 	.globl _ucd_clr
                            186 	.globl _ncd_quit
                            187 	.globl _read_masq
                            188 	.globl _read_memory
                            189 	.globl _write_memory
                            190 	.globl _set_pa
                            191 	.globl _read_pa
                            192 	.globl _read_objflags
                            193 	.globl _gapos_in_gat
                            194 	.globl _write_delay_record
                            195 	.globl _restart_prot
                            196 	.globl _rs_init
                            197 	.globl _rs_send_dec
                            198 	.globl _rs_send_ok
                            199 	.globl _eis1
                            200 	.globl _read_value_req
                            201 	.globl _restart_app
                            202 ;--------------------------------------------------------
                            203 ; special function registers
                            204 ;--------------------------------------------------------
                            205 	.area RSEG    (DATA)
                    0080    206 _P0	=	0x0080
                    0090    207 _P1	=	0x0090
                    00B0    208 _P3	=	0x00b0
                    00D0    209 _PSW	=	0x00d0
                    00E0    210 _ACC	=	0x00e0
                    00F0    211 _B	=	0x00f0
                    0081    212 _SP	=	0x0081
                    0082    213 _DPL	=	0x0082
                    0083    214 _DPH	=	0x0083
                    0087    215 _PCON	=	0x0087
                    0088    216 _TCON	=	0x0088
                    0089    217 _TMOD	=	0x0089
                    008A    218 _TL0	=	0x008a
                    008B    219 _TL1	=	0x008b
                    008C    220 _TH0	=	0x008c
                    008D    221 _TH1	=	0x008d
                    00A8    222 _IEN0	=	0x00a8
                    00B8    223 _IP0	=	0x00b8
                    0098    224 _SCON	=	0x0098
                    0099    225 _SBUF	=	0x0099
                    00A2    226 _AUXR1	=	0x00a2
                    00A9    227 _SADDR	=	0x00a9
                    00B9    228 _SADEN	=	0x00b9
                    00BE    229 _BRGR0	=	0x00be
                    00BF    230 _BRGR1	=	0x00bf
                    00BD    231 _BRGCON	=	0x00bd
                    00AC    232 _CMP1	=	0x00ac
                    00AD    233 _CMP2	=	0x00ad
                    0095    234 _DIVM	=	0x0095
                    00E7    235 _FMADRH	=	0x00e7
                    00E6    236 _FMADRL	=	0x00e6
                    00E4    237 _FMCON	=	0x00e4
                    00E5    238 _FMDATA	=	0x00e5
                    00DB    239 _I2ADR	=	0x00db
                    00D8    240 _I2CON	=	0x00d8
                    00DA    241 _I2DAT	=	0x00da
                    00DD    242 _I2SCLH	=	0x00dd
                    00DC    243 _I2SCLL	=	0x00dc
                    00D9    244 _I2STAT	=	0x00d9
                    00F8    245 _IP1	=	0x00f8
                    00F7    246 _IP1H	=	0x00f7
                    0094    247 _KBCON	=	0x0094
                    0086    248 _KBMASK	=	0x0086
                    0093    249 _KBPATN	=	0x0093
                    0084    250 _P0M1	=	0x0084
                    0085    251 _P0M2	=	0x0085
                    0091    252 _P1M1	=	0x0091
                    0092    253 _P1M2	=	0x0092
                    00B1    254 _P3M1	=	0x00b1
                    00B2    255 _P3M2	=	0x00b2
                    00B5    256 _PCONA	=	0x00b5
                    00F6    257 _PT0AD	=	0x00f6
                    00DF    258 _RSTSRC	=	0x00df
                    00D1    259 _RTCCON	=	0x00d1
                    00D2    260 _RTCH	=	0x00d2
                    00D3    261 _RTCL	=	0x00d3
                    00BA    262 _SSTAT	=	0x00ba
                    008F    263 _TAMOD	=	0x008f
                    0096    264 _TRIM	=	0x0096
                    00A7    265 _WDCON	=	0x00a7
                    00C1    266 _WDL	=	0x00c1
                    00C2    267 _WFEED1	=	0x00c2
                    00C3    268 _WFEED2	=	0x00c3
                    00B7    269 _IP0H	=	0x00b7
                    00E8    270 _IEN1	=	0x00e8
                            271 ;--------------------------------------------------------
                            272 ; special function bits
                            273 ;--------------------------------------------------------
                            274 	.area RSEG    (DATA)
                    00D0    275 _PSW_0	=	0x00d0
                    00D1    276 _PSW_1	=	0x00d1
                    00D2    277 _PSW_2	=	0x00d2
                    00D3    278 _PSW_3	=	0x00d3
                    00D4    279 _PSW_4	=	0x00d4
                    00D5    280 _PSW_5	=	0x00d5
                    00D6    281 _PSW_6	=	0x00d6
                    00D7    282 _PSW_7	=	0x00d7
                    00D0    283 _P	=	0x00d0
                    00D1    284 _F1	=	0x00d1
                    00D2    285 _OV	=	0x00d2
                    00D3    286 _RS0	=	0x00d3
                    00D4    287 _RS1	=	0x00d4
                    00D5    288 _F0	=	0x00d5
                    00D6    289 _AC	=	0x00d6
                    00D7    290 _CY	=	0x00d7
                    008F    291 _TCON_7	=	0x008f
                    008E    292 _TCON_6	=	0x008e
                    008D    293 _TCON_5	=	0x008d
                    008C    294 _TCON_4	=	0x008c
                    008B    295 _TCON_3	=	0x008b
                    008A    296 _TCON_2	=	0x008a
                    0089    297 _TCON_1	=	0x0089
                    0088    298 _TCON_0	=	0x0088
                    00AF    299 _IEN0_7	=	0x00af
                    00AE    300 _IEN0_6	=	0x00ae
                    00AD    301 _IEN0_5	=	0x00ad
                    00AC    302 _IEN0_4	=	0x00ac
                    00AB    303 _IEN0_3	=	0x00ab
                    00AA    304 _IEN0_2	=	0x00aa
                    00A9    305 _IEN0_1	=	0x00a9
                    00A8    306 _IEN0_0	=	0x00a8
                    00EA    307 _IEN1_2	=	0x00ea
                    00E9    308 _IEN1_1	=	0x00e9
                    00E8    309 _IEN1_0	=	0x00e8
                    00FE    310 _IP1_6	=	0x00fe
                    00FA    311 _IP1_2	=	0x00fa
                    00F9    312 _IP1_1	=	0x00f9
                    00F8    313 _IP1_0	=	0x00f8
                    00BE    314 _IP0_6	=	0x00be
                    00BD    315 _IP0_5	=	0x00bd
                    00BC    316 _IP0_4	=	0x00bc
                    00BB    317 _IP0_3	=	0x00bb
                    00BA    318 _IP0_2	=	0x00ba
                    00B9    319 _IP0_1	=	0x00b9
                    00B8    320 _IP0_0	=	0x00b8
                    0098    321 _SCON_0	=	0x0098
                    0099    322 _SCON_1	=	0x0099
                    009A    323 _SCON_2	=	0x009a
                    009B    324 _SCON_3	=	0x009b
                    009C    325 _SCON_4	=	0x009c
                    009D    326 _SCON_5	=	0x009d
                    009E    327 _SCON_6	=	0x009e
                    009F    328 _SCON_7	=	0x009f
                    00DE    329 _I2CON_6	=	0x00de
                    00DD    330 _I2CON_5	=	0x00dd
                    00DC    331 _I2CON_4	=	0x00dc
                    00DB    332 _I2CON_3	=	0x00db
                    00DA    333 _I2CON_2	=	0x00da
                    00D8    334 _I2CON_0	=	0x00d8
                    0080    335 _P0_0	=	0x0080
                    0081    336 _P0_1	=	0x0081
                    0082    337 _P0_2	=	0x0082
                    0083    338 _P0_3	=	0x0083
                    0084    339 _P0_4	=	0x0084
                    0085    340 _P0_5	=	0x0085
                    0086    341 _P0_6	=	0x0086
                    0087    342 _P0_7	=	0x0087
                    0090    343 _P1_0	=	0x0090
                    0091    344 _P1_1	=	0x0091
                    0092    345 _P1_2	=	0x0092
                    0093    346 _P1_3	=	0x0093
                    0094    347 _P1_4	=	0x0094
                    0095    348 _P1_5	=	0x0095
                    0096    349 _P1_6	=	0x0096
                    0097    350 _P1_7	=	0x0097
                    00B0    351 _P3_0	=	0x00b0
                    00B1    352 _P3_1	=	0x00b1
                            353 ;--------------------------------------------------------
                            354 ; overlayable register banks
                            355 ;--------------------------------------------------------
                            356 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     357 	.ds 8
                            358 ;--------------------------------------------------------
                            359 ; overlayable bit register bank
                            360 ;--------------------------------------------------------
                            361 	.area BIT_BANK	(REL,OVR,DATA)
   0021                     362 bits:
   0021                     363 	.ds 1
                    8000    364 	b0 = bits[0]
                    8100    365 	b1 = bits[1]
                    8200    366 	b2 = bits[2]
                    8300    367 	b3 = bits[3]
                    8400    368 	b4 = bits[4]
                    8500    369 	b5 = bits[5]
                    8600    370 	b6 = bits[6]
                    8700    371 	b7 = bits[7]
                            372 ;--------------------------------------------------------
                            373 ; internal ram data
                            374 ;--------------------------------------------------------
                            375 	.area DSEG    (DATA)
   0022                     376 _telegramm::
   0022                     377 	.ds 23
   0039                     378 _telpos::
   0039                     379 	.ds 1
   003A                     380 _cs::
   003A                     381 	.ds 1
   003B                     382 _pal::
   003B                     383 	.ds 1
   003C                     384 _pah::
   003C                     385 	.ds 1
   003D                     386 _gacount::
   003D                     387 	.ds 1
   003E                     388 _conh::
   003E                     389 	.ds 1
   003F                     390 _conl::
   003F                     391 	.ds 1
   0040                     392 _pcount::
   0040                     393 	.ds 1
                            394 ;--------------------------------------------------------
                            395 ; overlayable items in internal ram 
                            396 ;--------------------------------------------------------
                            397 	.area OSEG    (OVR,DATA)
                            398 ;--------------------------------------------------------
                            399 ; Stack segment in internal ram 
                            400 ;--------------------------------------------------------
                            401 	.area	SSEG	(DATA)
   0041                     402 __start__stack:
   0041                     403 	.ds	1
                            404 
                            405 ;--------------------------------------------------------
                            406 ; indirectly addressable internal ram data
                            407 ;--------------------------------------------------------
                            408 	.area ISEG    (DATA)
                            409 ;--------------------------------------------------------
                            410 ; bit data
                            411 ;--------------------------------------------------------
                            412 	.area BSEG    (BIT)
   0000                     413 _parity_ok::
   0000                     414 	.ds 1
   0001                     415 _progmode::
   0001                     416 	.ds 1
   0002                     417 _connected::
   0002                     418 	.ds 1
                            419 ;--------------------------------------------------------
                            420 ; paged external ram data
                            421 ;--------------------------------------------------------
                            422 	.area PSEG    (PAG,XDATA)
                            423 ;--------------------------------------------------------
                            424 ; external ram data
                            425 ;--------------------------------------------------------
                            426 	.area XSEG    (XDATA)
                            427 ;--------------------------------------------------------
                            428 ; external initialized ram data
                            429 ;--------------------------------------------------------
                            430 	.area XISEG   (XDATA)
                            431 	.area HOME    (CODE)
                            432 	.area GSINIT0 (CODE)
                            433 	.area GSINIT1 (CODE)
                            434 	.area GSINIT2 (CODE)
                            435 	.area GSINIT3 (CODE)
                            436 	.area GSINIT4 (CODE)
                            437 	.area GSINIT5 (CODE)
                            438 	.area GSINIT  (CODE)
                            439 	.area GSFINAL (CODE)
                            440 	.area CSEG    (CODE)
                            441 ;--------------------------------------------------------
                            442 ; interrupt vector 
                            443 ;--------------------------------------------------------
                            444 	.area HOME    (CODE)
   0000                     445 __interrupt_vect:
   0000 02 00 1E            446 	ljmp	__sdcc_gsinit_startup
   0003 32                  447 	reti
   0004                     448 	.ds	7
   000B 32                  449 	reti
   000C                     450 	.ds	7
   0013 02 01 5D            451 	ljmp	_ext_int0
   0016                     452 	.ds	5
   001B 02 03 4B            453 	ljmp	_timer1
                            454 ;--------------------------------------------------------
                            455 ; global & static initialisations
                            456 ;--------------------------------------------------------
                            457 	.area HOME    (CODE)
                            458 	.area GSINIT  (CODE)
                            459 	.area GSFINAL (CODE)
                            460 	.area GSINIT  (CODE)
                            461 	.globl __sdcc_gsinit_startup
                            462 	.globl __sdcc_program_startup
                            463 	.globl __start__stack
                            464 	.globl __mcs51_genXINIT
                            465 	.globl __mcs51_genXRAMCLEAR
                            466 	.globl __mcs51_genRAMCLEAR
                            467 	.area GSFINAL (CODE)
   0077 02 00 7A            468 	ljmp	__sdcc_program_startup
                            469 ;--------------------------------------------------------
                            470 ; Home
                            471 ;--------------------------------------------------------
                            472 	.area HOME    (CODE)
                            473 	.area CSEG    (CODE)
   007A                     474 __sdcc_program_startup:
   007A 12 0A 8B            475 	lcall	_main
                            476 ;	return from main will lock up
   007D 80 FE               477 	sjmp .
                            478 ;--------------------------------------------------------
                            479 ; code
                            480 ;--------------------------------------------------------
                            481 	.area CSEG    (CODE)
                            482 ;------------------------------------------------------------
                            483 ;Allocation info for local variables in function 'get_byte'
                            484 ;------------------------------------------------------------
                            485 ;rbit                      Allocated to registers b1 
                            486 ;parity                    Allocated to registers b1 
                            487 ;ph                        Allocated to registers b0 
                            488 ;n                         Allocated to registers r3 
                            489 ;m                         Allocated to registers r2 
                            490 ;fbb                       Allocated to registers r2 
                            491 ;fbbh                      Allocated to registers r3 
                            492 ;------------------------------------------------------------
                            493 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:10: unsigned char get_byte(void)
                            494 ;	-----------------------------------------
                            495 ;	 function get_byte
                            496 ;	-----------------------------------------
   007F                     497 _get_byte:
                    0002    498 	ar2 = 0x02
                    0003    499 	ar3 = 0x03
                    0004    500 	ar4 = 0x04
                    0005    501 	ar5 = 0x05
                    0006    502 	ar6 = 0x06
                    0007    503 	ar7 = 0x07
                    0000    504 	ar0 = 0x00
                    0001    505 	ar1 = 0x01
                            506 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:15: EX1=0;				// Interrupt 1 sperren
                            507 ;	genAssign
   007F C2 AA               508 	clr	_IEN0_2
                            509 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:16: ET1=0;				// Interrupt von Timer 1 sperren
                            510 ;	genAssign
   0081 C2 AB               511 	clr	_IEN0_3
                            512 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:18: set_timer1(380);			// Timer setzen um 1. Bit zu treffen (320-440)
                            513 ;	genCall
                            514 ;	Peephole 182.b	used 16 bit load of dptr
   0083 90 01 7C            515 	mov	dptr,#0x017C
   0086 12 02 B7            516 	lcall	_set_timer1
                            517 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:20: ph=0;					// Paritybit wird aus empfangenem Byte berechnet
                            518 ;	genAssign
   0089 C2 08               519 	clr	b0
                            520 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:21: parity_ok=0;
                            521 ;	genAssign
   008B C2 00               522 	clr	_parity_ok
                            523 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:22: while(!TF1);				// warten auf Timer 1				
   008D                     524 00101$:
                            525 ;	genIfx
                            526 ;	genIfxJump
                            527 ;	Peephole 108.d	removed ljmp by inverse jump logic
   008D 30 8F FD            528 	jnb	_TCON_7,00101$
                            529 ;	Peephole 300	removed redundant label 00152$
                            530 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:23: set_timer1(360);			// Timer 1 neu setzen für 2.Bit (300-420)
                            531 ;	genCall
                            532 ;	Peephole 182.b	used 16 bit load of dptr
   0090 90 01 68            533 	mov	dptr,#0x0168
   0093 C0 21               534 	push	bits
   0095 12 02 B7            535 	lcall	_set_timer1
   0098 D0 21               536 	pop	bits
                            537 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:24: rbit=FBINC;				// 1.Bit einlesen
                            538 ;	genAssign
   009A A2 94               539 	mov	c,_P1_4
   009C 92 09               540 	mov	b1,c
                            541 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:25: for(m=0;m<5;m++)
                            542 ;	genAssign
   009E 7A 05               543 	mov	r2,#0x05
   00A0                     544 00118$:
                            545 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:27: rbit&=FBINC;			// zur Steigerung der Fehlertoleranz mehrfach lesen
                            546 ;	genAnd
   00A0 A2 94               547 	mov	c,_P1_4
   00A2 82 09               548 	anl	c,b1
   00A4 92 09               549 	mov	b1,c
                            550 ;	genDjnz
                            551 ;	Peephole 112.b	changed ljmp to sjmp
                            552 ;	Peephole 205	optimized misc jump sequence
   00A6 DA F8               553 	djnz	r2,00118$
                            554 ;	Peephole 300	removed redundant label 00153$
                            555 ;	Peephole 300	removed redundant label 00154$
                            556 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:25: for(m=0;m<5;m++)
                            557 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:29: fbb=rbit;
                            558 ;	genAssign
   00A8 E4                  559 	clr	a
   00A9 A2 09               560 	mov	c,b1
   00AB 33                  561 	rlc	a
   00AC FA                  562 	mov	r2,a
                            563 ;	genAssign
                            564 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:30: if(rbit) ph=!ph;			// Paritybit berechnen
                            565 ;	genIfx
                            566 ;	genIfxJump
                            567 ;	Peephole 108.d	removed ljmp by inverse jump logic
   00AD 30 09 02            568 	jnb	b1,00142$
                            569 ;	Peephole 300	removed redundant label 00155$
                            570 ;	genNot
   00B0 B2 08               571 	cpl	b0
                            572 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:32: for(n=0;n<7;n++)			// 2. bis 8. Bit
   00B2                     573 00142$:
                            574 ;	genAssign
   00B2 7B 00               575 	mov	r3,#0x00
   00B4                     576 00122$:
                            577 ;	genCmpLt
                            578 ;	genCmp
   00B4 BB 07 00            579 	cjne	r3,#0x07,00156$
   00B7                     580 00156$:
                            581 ;	genIfxJump
                            582 ;	Peephole 108.a	removed ljmp by inverse jump logic
   00B7 50 35               583 	jnc	00111$
                            584 ;	Peephole 300	removed redundant label 00157$
                            585 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:34: fbb=fbb<<1;
                            586 ;	genLeftShift
                            587 ;	genLeftShiftLiteral
                            588 ;	genlshOne
   00B9 EA                  589 	mov	a,r2
                            590 ;	Peephole 254	optimized left shift
   00BA 2A                  591 	add	a,r2
   00BB FA                  592 	mov	r2,a
                            593 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:35: while(!TF1);
   00BC                     594 00106$:
                            595 ;	genIfx
                            596 ;	genIfxJump
                            597 ;	Peephole 108.d	removed ljmp by inverse jump logic
   00BC 30 8F FD            598 	jnb	_TCON_7,00106$
                            599 ;	Peephole 300	removed redundant label 00158$
                            600 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:36: set_timer1(350);			// Timer 1 setzen für Position 2.-9.Bit (342-359)
                            601 ;	genCall
                            602 ;	Peephole 182.b	used 16 bit load of dptr
   00BF 90 01 5E            603 	mov	dptr,#0x015E
   00C2 C0 02               604 	push	ar2
   00C4 C0 03               605 	push	ar3
   00C6 C0 21               606 	push	bits
   00C8 12 02 B7            607 	lcall	_set_timer1
   00CB D0 21               608 	pop	bits
   00CD D0 03               609 	pop	ar3
   00CF D0 02               610 	pop	ar2
                            611 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:37: rbit=FBINC;
                            612 ;	genAssign
   00D1 A2 94               613 	mov	c,_P1_4
   00D3 92 09               614 	mov	b1,c
                            615 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:38: for(m=0;m<5;m++)
                            616 ;	genAssign
   00D5 7C 05               617 	mov	r4,#0x05
   00D7                     618 00121$:
                            619 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:40: rbit&=FBINC;			// zur Steigerung der Fehlertoleranz mehrfach lesen
                            620 ;	genAnd
   00D7 A2 94               621 	mov	c,_P1_4
   00D9 82 09               622 	anl	c,b1
   00DB 92 09               623 	mov	b1,c
                            624 ;	genDjnz
                            625 ;	Peephole 112.b	changed ljmp to sjmp
                            626 ;	Peephole 205	optimized misc jump sequence
   00DD DC F8               627 	djnz	r4,00121$
                            628 ;	Peephole 300	removed redundant label 00159$
                            629 ;	Peephole 300	removed redundant label 00160$
                            630 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:38: for(m=0;m<5;m++)
                            631 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:42: fbb=fbb+rbit;
                            632 ;	genAssign
   00DF E4                  633 	clr	a
   00E0 A2 09               634 	mov	c,b1
   00E2 33                  635 	rlc	a
                            636 ;	genPlus
   00E3 FC                  637 	mov	r4,a
                            638 ;	Peephole 177.b	removed redundant mov
                            639 ;	Peephole 236.a	used r2 instead of ar2
   00E4 2A                  640 	add	a,r2
   00E5 FA                  641 	mov	r2,a
                            642 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:43: if(rbit) ph=!ph;			// Paritybit berechnen
                            643 ;	genIfx
                            644 ;	genIfxJump
                            645 ;	Peephole 108.d	removed ljmp by inverse jump logic
   00E6 30 09 02            646 	jnb	b1,00124$
                            647 ;	Peephole 300	removed redundant label 00161$
                            648 ;	genNot
   00E9 B2 08               649 	cpl	b0
   00EB                     650 00124$:
                            651 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:32: for(n=0;n<7;n++)			// 2. bis 8. Bit
                            652 ;	genPlus
                            653 ;     genPlusIncr
   00EB 0B                  654 	inc	r3
                            655 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:45: while(!TF1);				
                            656 ;	Peephole 112.b	changed ljmp to sjmp
   00EC 80 C6               657 	sjmp	00122$
   00EE                     658 00111$:
                            659 ;	genIfx
                            660 ;	genIfxJump
                            661 ;	Peephole 108.d	removed ljmp by inverse jump logic
   00EE 30 8F FD            662 	jnb	_TCON_7,00111$
                            663 ;	Peephole 300	removed redundant label 00162$
                            664 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:46: TR1=0;
                            665 ;	genAssign
   00F1 C2 8E               666 	clr	_TCON_6
                            667 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:47: parity=FBINC;				// Paritybit lesen
                            668 ;	genAssign
   00F3 A2 94               669 	mov	c,_P1_4
   00F5 92 09               670 	mov	b1,c
                            671 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:48: for(m=0;m<5;m++)
                            672 ;	genAssign
   00F7 7B 05               673 	mov	r3,#0x05
   00F9                     674 00128$:
                            675 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:50: parity&=FBINC;
                            676 ;	genAnd
   00F9 A2 94               677 	mov	c,_P1_4
   00FB 82 09               678 	anl	c,b1
   00FD 92 09               679 	mov	b1,c
                            680 ;	genDjnz
                            681 ;	Peephole 112.b	changed ljmp to sjmp
                            682 ;	Peephole 205	optimized misc jump sequence
   00FF DB F8               683 	djnz	r3,00128$
                            684 ;	Peephole 300	removed redundant label 00163$
                            685 ;	Peephole 300	removed redundant label 00164$
                            686 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:48: for(m=0;m<5;m++)
                            687 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:53: fbbh=(fbb&0x80)>>7;			// Byte bitweise vertauschen, da LSB zuerst übertragen wurde
                            688 ;	genAnd
   0101 74 80               689 	mov	a,#0x80
   0103 5A                  690 	anl	a,r2
                            691 ;	genRightShift
                            692 ;	genRightShiftLiteral
                            693 ;	genrshOne
   0104 FB                  694 	mov	r3,a
                            695 ;	Peephole 105	removed redundant mov
   0105 23                  696 	rl	a
   0106 54 01               697 	anl	a,#0x01
   0108 FB                  698 	mov	r3,a
                            699 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:54: fbbh=fbbh+((fbb&0x40)>>5);
                            700 ;	genAnd
   0109 74 40               701 	mov	a,#0x40
   010B 5A                  702 	anl	a,r2
                            703 ;	genRightShift
                            704 ;	genRightShiftLiteral
                            705 ;	genrshOne
   010C FC                  706 	mov	r4,a
                            707 ;	Peephole 105	removed redundant mov
   010D C4                  708 	swap	a
   010E 03                  709 	rr	a
   010F 54 07               710 	anl	a,#0x07
                            711 ;	genPlus
   0111 FC                  712 	mov	r4,a
                            713 ;	Peephole 177.b	removed redundant mov
                            714 ;	Peephole 236.a	used r3 instead of ar3
   0112 2B                  715 	add	a,r3
   0113 FB                  716 	mov	r3,a
                            717 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:55: fbbh=fbbh+((fbb&0x20)>>3);
                            718 ;	genAnd
   0114 74 20               719 	mov	a,#0x20
   0116 5A                  720 	anl	a,r2
                            721 ;	genRightShift
                            722 ;	genRightShiftLiteral
                            723 ;	genrshOne
   0117 FC                  724 	mov	r4,a
                            725 ;	Peephole 105	removed redundant mov
   0118 C4                  726 	swap	a
   0119 23                  727 	rl	a
   011A 54 1F               728 	anl	a,#0x1f
                            729 ;	genPlus
   011C FC                  730 	mov	r4,a
                            731 ;	Peephole 177.b	removed redundant mov
                            732 ;	Peephole 236.a	used r3 instead of ar3
   011D 2B                  733 	add	a,r3
   011E FB                  734 	mov	r3,a
                            735 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:56: fbbh=fbbh+((fbb&0x10)>>1);
                            736 ;	genAnd
   011F 74 10               737 	mov	a,#0x10
   0121 5A                  738 	anl	a,r2
                            739 ;	genRightShift
                            740 ;	genRightShiftLiteral
                            741 ;	genrshOne
   0122 FC                  742 	mov	r4,a
                            743 ;	Peephole 105	removed redundant mov
   0123 C3                  744 	clr	c
   0124 13                  745 	rrc	a
                            746 ;	genPlus
   0125 FC                  747 	mov	r4,a
                            748 ;	Peephole 177.b	removed redundant mov
                            749 ;	Peephole 236.a	used r3 instead of ar3
   0126 2B                  750 	add	a,r3
   0127 FB                  751 	mov	r3,a
                            752 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:57: fbbh=fbbh+((fbb&0x08)<<1);
                            753 ;	genAnd
   0128 74 08               754 	mov	a,#0x08
   012A 5A                  755 	anl	a,r2
                            756 ;	genLeftShift
                            757 ;	genLeftShiftLiteral
                            758 ;	genlshOne
                            759 ;	Peephole 105	removed redundant mov
                            760 ;	genPlus
                            761 ;	Peephole 204	removed redundant mov
   012B 25 E0               762 	add	a,acc
   012D FC                  763 	mov	r4,a
                            764 ;	Peephole 177.b	removed redundant mov
                            765 ;	Peephole 236.a	used r3 instead of ar3
   012E 2B                  766 	add	a,r3
   012F FB                  767 	mov	r3,a
                            768 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:58: fbbh=fbbh+((fbb&0x04)<<3);
                            769 ;	genAnd
   0130 74 04               770 	mov	a,#0x04
   0132 5A                  771 	anl	a,r2
                            772 ;	genLeftShift
                            773 ;	genLeftShiftLiteral
                            774 ;	genlshOne
   0133 FC                  775 	mov	r4,a
                            776 ;	Peephole 105	removed redundant mov
   0134 C4                  777 	swap	a
   0135 03                  778 	rr	a
   0136 54 F8               779 	anl	a,#0xf8
                            780 ;	genPlus
   0138 FC                  781 	mov	r4,a
                            782 ;	Peephole 177.b	removed redundant mov
                            783 ;	Peephole 236.a	used r3 instead of ar3
   0139 2B                  784 	add	a,r3
   013A FB                  785 	mov	r3,a
                            786 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:59: fbbh=fbbh+((fbb&0x02)<<5);
                            787 ;	genAnd
   013B 74 02               788 	mov	a,#0x02
   013D 5A                  789 	anl	a,r2
                            790 ;	genLeftShift
                            791 ;	genLeftShiftLiteral
                            792 ;	genlshOne
   013E FC                  793 	mov	r4,a
                            794 ;	Peephole 105	removed redundant mov
   013F C4                  795 	swap	a
   0140 23                  796 	rl	a
   0141 54 E0               797 	anl	a,#0xe0
                            798 ;	genPlus
   0143 FC                  799 	mov	r4,a
                            800 ;	Peephole 177.b	removed redundant mov
                            801 ;	Peephole 236.a	used r3 instead of ar3
   0144 2B                  802 	add	a,r3
   0145 FB                  803 	mov	r3,a
                            804 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:60: fbbh=fbbh+((fbb&0x01)<<7);
                            805 ;	genAnd
   0146 53 02 01            806 	anl	ar2,#0x01
                            807 ;	genLeftShift
                            808 ;	genLeftShiftLiteral
                            809 ;	genlshOne
   0149 EA                  810 	mov	a,r2
   014A 03                  811 	rr	a
   014B 54 80               812 	anl	a,#0x80
                            813 ;	genPlus
   014D FA                  814 	mov	r2,a
                            815 ;	Peephole 177.b	removed redundant mov
                            816 ;	Peephole 236.a	used r3 instead of ar3
   014E 2B                  817 	add	a,r3
   014F FB                  818 	mov	r3,a
                            819 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:62: if(parity==ph) parity_ok=1;
                            820 ;	genCmpEq
   0150 A2 09               821 	mov	c,b1
   0152 20 08 01            822 	jb	b0,00165$
   0155 B3                  823 	cpl	c
   0156                     824 00165$:
                            825 ;	Peephole 108.a	removed ljmp by inverse jump logic
   0156 50 02               826 	jnc	00115$
                            827 ;	Peephole 300	removed redundant label 00166$
                            828 ;	genAssign
   0158 D2 00               829 	setb	_parity_ok
   015A                     830 00115$:
                            831 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:64: return fbbh;
                            832 ;	genRet
   015A 8B 82               833 	mov	dpl,r3
                            834 ;	Peephole 300	removed redundant label 00129$
   015C 22                  835 	ret
                            836 ;------------------------------------------------------------
                            837 ;Allocation info for local variables in function 'ext_int0'
                            838 ;------------------------------------------------------------
                            839 ;fbbh                      Allocated to registers r2 
                            840 ;------------------------------------------------------------
                            841 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:70: void ext_int0(void) interrupt 2		// Byte vom Bus empfangen, wird durch negative Flanke am INT1 Eingang getriggert
                            842 ;	-----------------------------------------
                            843 ;	 function ext_int0
                            844 ;	-----------------------------------------
   015D                     845 _ext_int0:
   015D C0 E0               846 	push	acc
   015F C0 F0               847 	push	b
   0161 C0 82               848 	push	dpl
   0163 C0 83               849 	push	dph
   0165 C0 02               850 	push	(0+2)
   0167 C0 03               851 	push	(0+3)
   0169 C0 04               852 	push	(0+4)
   016B C0 05               853 	push	(0+5)
   016D C0 06               854 	push	(0+6)
   016F C0 07               855 	push	(0+7)
   0171 C0 00               856 	push	(0+0)
   0173 C0 01               857 	push	(0+1)
   0175 C0 21               858 	push	bits
   0177 C0 D0               859 	push	psw
   0179 75 D0 00            860 	mov	psw,#0x00
                            861 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:76: TR1=0;
                            862 ;	genAssign
   017C C2 8E               863 	clr	_TCON_6
                            864 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:77: EX1=0;				// Interrupt 1 sperren
                            865 ;	genAssign
   017E C2 AA               866 	clr	_IEN0_2
                            867 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:78: ET1=0;				// Interrupt von Timer 1 sperren
                            868 ;	genAssign
   0180 C2 AB               869 	clr	_IEN0_3
                            870 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:80: fbbh=get_byte();			// Byte vom Bus empfangen
                            871 ;	genCall
   0182 12 00 7F            872 	lcall	_get_byte
   0185 AA 82               873 	mov	r2,dpl
                            874 ;	genAssign
                            875 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:81: delay(200);
                            876 ;	genCall
                            877 ;	Peephole 182.b	used 16 bit load of dptr
   0187 90 00 C8            878 	mov	dptr,#0x00C8
   018A C0 02               879 	push	ar2
   018C 12 02 9A            880 	lcall	_delay
   018F D0 02               881 	pop	ar2
                            882 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:83: if(parity_ok)				// wenn Parity OK
                            883 ;	genIfx
                            884 ;	genIfxJump
                            885 ;	Peephole 108.d	removed ljmp by inverse jump logic
   0191 30 00 12            886 	jnb	_parity_ok,00104$
                            887 ;	Peephole 300	removed redundant label 00109$
                            888 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:85: telegramm[telpos]=fbbh; 
                            889 ;	genPlus
   0194 E5 39               890 	mov	a,_telpos
   0196 24 22               891 	add	a,#_telegramm
                            892 ;	genPointerSet
                            893 ;	genNearPointerSet
                            894 ;	Peephole 239	used a instead of acc
   0198 F8                  895 	mov	r0,a
   0199 A6 02               896 	mov	@r0,ar2
                            897 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:86: if(telpos==0) cs=0;
                            898 ;	genIfx
   019B E5 39               899 	mov	a,_telpos
                            900 ;	genIfxJump
                            901 ;	Peephole 108.b	removed ljmp by inverse jump logic
                            902 ;	genAssign
   019D 70 02               903 	jnz	00102$
                            904 ;	Peephole 300	removed redundant label 00110$
                            905 ;	Peephole 256.c	loading _cs with zero from a
   019F F5 3A               906 	mov	_cs,a
   01A1                     907 00102$:
                            908 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:87: cs^=fbbh;				// Checksum durch EXOR der einzelnen Telegramm-Bytes bilden
                            909 ;	genXor
   01A1 EA                  910 	mov	a,r2
   01A2 62 3A               911 	xrl	_cs,a
                            912 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:88: telpos++;
                            913 ;	genPlus
                            914 ;     genPlusIncr
   01A4 05 39               915 	inc	_telpos
   01A6                     916 00104$:
                            917 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:91: set_timer1(1350);			// Timer 1 starten für Timeout 370us -> signalisiert Telegrammende (1350)
                            918 ;	genCall
                            919 ;	Peephole 182.b	used 16 bit load of dptr
   01A6 90 05 46            920 	mov	dptr,#0x0546
   01A9 12 02 B7            921 	lcall	_set_timer1
                            922 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:93: ET1=1;				// Interrupt für Timer 1 freigeben
                            923 ;	genAssign
   01AC D2 AB               924 	setb	_IEN0_3
                            925 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:94: IE1=0;				// Interrupt 0 request zurücksetzen
                            926 ;	genAssign
   01AE C2 8B               927 	clr	_TCON_3
                            928 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:95: EX1=1;				// Interrupt 0 wieder freigeben
                            929 ;	genAssign
   01B0 D2 AA               930 	setb	_IEN0_2
                            931 ;	Peephole 300	removed redundant label 00105$
   01B2 D0 D0               932 	pop	psw
   01B4 D0 21               933 	pop	bits
   01B6 D0 01               934 	pop	(0+1)
   01B8 D0 00               935 	pop	(0+0)
   01BA D0 07               936 	pop	(0+7)
   01BC D0 06               937 	pop	(0+6)
   01BE D0 05               938 	pop	(0+5)
   01C0 D0 04               939 	pop	(0+4)
   01C2 D0 03               940 	pop	(0+3)
   01C4 D0 02               941 	pop	(0+2)
   01C6 D0 83               942 	pop	dph
   01C8 D0 82               943 	pop	dpl
   01CA D0 F0               944 	pop	b
   01CC D0 E0               945 	pop	acc
   01CE 32                  946 	reti
                            947 ;------------------------------------------------------------
                            948 ;Allocation info for local variables in function 'sendbyte'
                            949 ;------------------------------------------------------------
                            950 ;fbsb                      Allocated to registers r2 
                            951 ;n                         Allocated to registers r3 
                            952 ;m                         Allocated to registers r4 
                            953 ;sendbit                   Allocated to registers b2 
                            954 ;parity                    Allocated to registers b0 
                            955 ;error                     Allocated to registers b1 
                            956 ;------------------------------------------------------------
                            957 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:99: bit sendbyte(unsigned char fbsb)
                            958 ;	-----------------------------------------
                            959 ;	 function sendbyte
                            960 ;	-----------------------------------------
   01CF                     961 _sendbyte:
                            962 ;	genReceive
   01CF AA 82               963 	mov	r2,dpl
                            964 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:104: parity=1;
                            965 ;	genAssign
   01D1 D2 08               966 	setb	b0
                            967 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:105: error=0;
                            968 ;	genAssign
   01D3 C2 09               969 	clr	b1
                            970 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:107: FBOUTC=1;	// Startbit senden
                            971 ;	genAssign
   01D5 D2 96               972 	setb	_P1_6
                            973 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:108: delay(95);	// 35us
                            974 ;	genCall
                            975 ;	Peephole 182.b	used 16 bit load of dptr
   01D7 90 00 5F            976 	mov	dptr,#0x005F
   01DA C0 02               977 	push	ar2
   01DC C0 21               978 	push	bits
   01DE 12 02 9A            979 	lcall	_delay
   01E1 D0 21               980 	pop	bits
   01E3 D0 02               981 	pop	ar2
                            982 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:109: FBOUTC=0;
                            983 ;	genAssign
   01E5 C2 96               984 	clr	_P1_6
                            985 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:111: for(n=0;n<8;n++)		// 8 Datenbits senden
                            986 ;	genAssign
   01E7 7B 00               987 	mov	r3,#0x00
   01E9                     988 00116$:
                            989 ;	genCmpLt
                            990 ;	genCmp
   01E9 BB 08 00            991 	cjne	r3,#0x08,00141$
   01EC                     992 00141$:
                            993 ;	genIfxJump
                            994 ;	Peephole 112.b	changed ljmp to sjmp
                            995 ;	Peephole 160.b	removed sjmp by inverse jump logic
   01EC 50 5C               996 	jnc	00119$
                            997 ;	Peephole 300	removed redundant label 00142$
                            998 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:113: set_timer1(215);		// 69us Pause
                            999 ;	genCall
                           1000 ;	Peephole 182.b	used 16 bit load of dptr
   01EE 90 00 D7           1001 	mov	dptr,#0x00D7
   01F1 C0 02              1002 	push	ar2
   01F3 C0 03              1003 	push	ar3
   01F5 C0 21              1004 	push	bits
   01F7 12 02 B7           1005 	lcall	_set_timer1
   01FA D0 21              1006 	pop	bits
   01FC D0 03              1007 	pop	ar3
   01FE D0 02              1008 	pop	ar2
                           1009 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:114: if(((fbsb>>n)&0x01)==1) sendbit=0;
                           1010 ;	genRightShift
   0200 8B F0              1011 	mov	b,r3
   0202 05 F0              1012 	inc	b
   0204 EA                 1013 	mov	a,r2
   0205 80 02              1014 	sjmp	00144$
   0207                    1015 00143$:
   0207 C3                 1016 	clr	c
   0208 13                 1017 	rrc	a
   0209                    1018 00144$:
   0209 D5 F0 FB           1019 	djnz	b,00143$
                           1020 ;	genAnd
   020C 54 01              1021 	anl	a,#0x01
   020E FC                 1022 	mov	r4,a
                           1023 ;	genCmpEq
                           1024 ;	gencjneshort
                           1025 ;	Peephole 112.b	changed ljmp to sjmp
                           1026 ;	Peephole 198.b	optimized misc jump sequence
   020F BC 01 04           1027 	cjne	r4,#0x01,00102$
                           1028 ;	Peephole 200.b	removed redundant sjmp
                           1029 ;	Peephole 300	removed redundant label 00145$
                           1030 ;	Peephole 300	removed redundant label 00146$
                           1031 ;	genAssign
   0212 C2 0A              1032 	clr	b2
                           1033 ;	Peephole 112.b	changed ljmp to sjmp
   0214 80 02              1034 	sjmp	00104$
   0216                    1035 00102$:
                           1036 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:115: else sendbit=1;
                           1037 ;	genAssign
   0216 D2 0A              1038 	setb	b2
                           1039 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:116: while(!TF1);		// Warten bis 69us Pause fretig ist
   0218                    1040 00104$:
                           1041 ;	genIfx
                           1042 ;	genIfxJump
                           1043 ;	Peephole 108.d	removed ljmp by inverse jump logic
   0218 30 8F FD           1044 	jnb	_TCON_7,00104$
                           1045 ;	Peephole 300	removed redundant label 00147$
                           1046 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:118: FBOUTC=sendbit;		// Bit senden
                           1047 ;	genAssign
   021B A2 0A              1048 	mov	c,b2
   021D 92 96              1049 	mov	_P1_6,c
                           1050 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:120: set_timer1(100);		//35us Haltezeit für Bit 
                           1051 ;	genCall
                           1052 ;	Peephole 182.b	used 16 bit load of dptr
   021F 90 00 64           1053 	mov	dptr,#0x0064
   0222 C0 02              1054 	push	ar2
   0224 C0 03              1055 	push	ar3
   0226 C0 21              1056 	push	bits
   0228 12 02 B7           1057 	lcall	_set_timer1
   022B D0 21              1058 	pop	bits
   022D D0 03              1059 	pop	ar3
   022F D0 02              1060 	pop	ar2
                           1061 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:122: if(!sendbit)		// wenn logische 1 gesendet wird, auf Kollision prüfen
                           1062 ;	genIfx
                           1063 ;	genIfxJump
                           1064 ;	Peephole 108.e	removed ljmp by inverse jump logic
   0231 20 0A 0B           1065 	jb	b2,00110$
                           1066 ;	Peephole 300	removed redundant label 00148$
                           1067 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:124: parity=!parity;
                           1068 ;	genNot
   0234 B2 08              1069 	cpl	b0
                           1070 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:125: for(m=0;m<5;m++)
                           1071 ;	genAssign
   0236 7C 05              1072 	mov	r4,#0x05
   0238                    1073 00124$:
                           1074 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:127: if(!FBINC) error=1;
                           1075 ;	genIfx
                           1076 ;	genIfxJump
                           1077 ;	Peephole 108.e	removed ljmp by inverse jump logic
   0238 20 94 02           1078 	jb	_P1_4,00108$
                           1079 ;	Peephole 300	removed redundant label 00149$
                           1080 ;	genAssign
   023B D2 09              1081 	setb	b1
   023D                    1082 00108$:
                           1083 ;	genDjnz
                           1084 ;	Peephole 112.b	changed ljmp to sjmp
                           1085 ;	Peephole 205	optimized misc jump sequence
   023D DC F9              1086 	djnz	r4,00124$
                           1087 ;	Peephole 300	removed redundant label 00150$
                           1088 ;	Peephole 300	removed redundant label 00151$
                           1089 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:125: for(m=0;m<5;m++)
   023F                    1090 00110$:
                           1091 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:130: if(error) break;  
                           1092 ;	genIfx
                           1093 ;	genIfxJump
                           1094 ;	Peephole 108.e	removed ljmp by inverse jump logic
   023F 20 09 08           1095 	jb	b1,00119$
                           1096 ;	Peephole 300	removed redundant label 00152$
                           1097 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:132: while(!TF1);		// Warten bis 35us abgelaufen
   0242                    1098 00113$:
                           1099 ;	genIfx
                           1100 ;	genIfxJump
                           1101 ;	Peephole 108.d	removed ljmp by inverse jump logic
   0242 30 8F FD           1102 	jnb	_TCON_7,00113$
                           1103 ;	Peephole 300	removed redundant label 00153$
                           1104 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:133: FBOUTC=0;
                           1105 ;	genAssign
   0245 C2 96              1106 	clr	_P1_6
                           1107 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:111: for(n=0;n<8;n++)		// 8 Datenbits senden
                           1108 ;	genPlus
                           1109 ;     genPlusIncr
   0247 0B                 1110 	inc	r3
                           1111 ;	Peephole 112.b	changed ljmp to sjmp
   0248 80 9F              1112 	sjmp	00116$
   024A                    1113 00119$:
                           1114 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:135: if(!error)
                           1115 ;	genIfx
                           1116 ;	genIfxJump
                           1117 ;	Peephole 108.e	removed ljmp by inverse jump logic
   024A 20 09 1A           1118 	jb	b1,00121$
                           1119 ;	Peephole 300	removed redundant label 00154$
                           1120 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:137: delay(212);			// 69 us Pause vor Parity-Bit
                           1121 ;	genCall
                           1122 ;	Peephole 182.b	used 16 bit load of dptr
   024D 90 00 D4           1123 	mov	dptr,#0x00D4
   0250 C0 21              1124 	push	bits
   0252 12 02 9A           1125 	lcall	_delay
   0255 D0 21              1126 	pop	bits
                           1127 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:138: FBOUTC=parity;
                           1128 ;	genAssign
   0257 A2 08              1129 	mov	c,b0
   0259 92 96              1130 	mov	_P1_6,c
                           1131 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:139: delay(95);			// 35us für Parity-Bit
                           1132 ;	genCall
                           1133 ;	Peephole 182.b	used 16 bit load of dptr
   025B 90 00 5F           1134 	mov	dptr,#0x005F
   025E C0 21              1135 	push	bits
   0260 12 02 9A           1136 	lcall	_delay
   0263 D0 21              1137 	pop	bits
                           1138 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:140: FBOUTC=0;
                           1139 ;	genAssign
   0265 C2 96              1140 	clr	_P1_6
   0267                    1141 00121$:
                           1142 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:142: TR1=0;
                           1143 ;	genAssign
   0267 C2 8E              1144 	clr	_TCON_6
                           1145 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:144: return error;
                           1146 ;	genRet
   0269 E4                 1147 	clr	a
   026A A2 09              1148 	mov	c,b1
   026C 33                 1149 	rlc	a
   026D 24 FF              1150 	add	a,#0xff
                           1151 ;	Peephole 300	removed redundant label 00125$
   026F 22                 1152 	ret
                           1153 ;------------------------------------------------------------
                           1154 ;Allocation info for local variables in function 'start_writecycle'
                           1155 ;------------------------------------------------------------
                           1156 ;------------------------------------------------------------
                           1157 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:148: void start_writecycle(void)
                           1158 ;	-----------------------------------------
                           1159 ;	 function start_writecycle
                           1160 ;	-----------------------------------------
   0270                    1161 _start_writecycle:
                           1162 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:150: FMCON=0x00;			// load command, leert das pageregister
                           1163 ;	genAssign
   0270 75 E4 00           1164 	mov	_FMCON,#0x00
                           1165 ;	Peephole 300	removed redundant label 00101$
   0273 22                 1166 	ret
                           1167 ;------------------------------------------------------------
                           1168 ;Allocation info for local variables in function 'stop_writecycle'
                           1169 ;------------------------------------------------------------
                           1170 ;------------------------------------------------------------
                           1171 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:154: void stop_writecycle(void)
                           1172 ;	-----------------------------------------
                           1173 ;	 function stop_writecycle
                           1174 ;	-----------------------------------------
   0274                    1175 _stop_writecycle:
                           1176 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:156: FMCON=0x68;			// write command, schreibt pageregister ins flash und versetzt CPU in idle für 4ms
                           1177 ;	genAssign
   0274 75 E4 68           1178 	mov	_FMCON,#0x68
                           1179 ;	Peephole 300	removed redundant label 00101$
   0277 22                 1180 	ret
                           1181 ;------------------------------------------------------------
                           1182 ;Allocation info for local variables in function 'write_byte'
                           1183 ;------------------------------------------------------------
                           1184 ;addrl                     Allocated to stack - offset -3
                           1185 ;zdata                     Allocated to stack - offset -4
                           1186 ;addrh                     Allocated to registers r2 
                           1187 ;------------------------------------------------------------
                           1188 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:160: void write_byte(unsigned char addrh, unsigned char addrl, unsigned char zdata)	// schreibt byte ins pageregister zum flashen
                           1189 ;	-----------------------------------------
                           1190 ;	 function write_byte
                           1191 ;	-----------------------------------------
   0278                    1192 _write_byte:
   0278 C0 08              1193 	push	_bp
   027A 85 81 08           1194 	mov	_bp,sp
                           1195 ;	genReceive
                           1196 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:163: if (addrh<=0x01)		// sicherstellen, dass nicht versehentlich bootloader überschrieben wird
                           1197 ;	genCmpGt
                           1198 ;	genCmp
                           1199 ;	genIfxJump
                           1200 ;	Peephole 132.b	optimized genCmpGt by inverse logic (acc differs)
                           1201 ;	peephole 177.g	optimized mov sequence
   027D E5 82              1202 	mov	a,dpl
   027F FA                 1203 	mov	r2,a
   0280 24 FE              1204 	add	a,#0xff - 0x01
                           1205 ;	Peephole 112.b	changed ljmp to sjmp
                           1206 ;	Peephole 160.a	removed sjmp by inverse jump logic
   0282 40 13              1207 	jc	00103$
                           1208 ;	Peephole 300	removed redundant label 00106$
                           1209 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:165: FMADRH=addrh+0x1C;
                           1210 ;	genPlus
                           1211 ;     genPlusIncr
   0284 74 1C              1212 	mov	a,#0x1C
                           1213 ;	Peephole 236.a	used r2 instead of ar2
   0286 2A                 1214 	add	a,r2
   0287 F5 E7              1215 	mov	_FMADRH,a
                           1216 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:166: FMADRL=addrl;
                           1217 ;	genAssign
   0289 A8 08              1218 	mov	r0,_bp
   028B 18                 1219 	dec	r0
   028C 18                 1220 	dec	r0
   028D 18                 1221 	dec	r0
   028E 86 E6              1222 	mov	_FMADRL,@r0
                           1223 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:167: FMDATA=zdata;
                           1224 ;	genAssign
   0290 E5 08              1225 	mov	a,_bp
   0292 24 FC              1226 	add	a,#0xfffffffc
   0294 F8                 1227 	mov	r0,a
   0295 86 E5              1228 	mov	_FMDATA,@r0
   0297                    1229 00103$:
   0297 D0 08              1230 	pop	_bp
   0299 22                 1231 	ret
                           1232 ;------------------------------------------------------------
                           1233 ;Allocation info for local variables in function 'delay'
                           1234 ;------------------------------------------------------------
                           1235 ;deltime                   Allocated to registers r2 r3 
                           1236 ;------------------------------------------------------------
                           1237 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:172: void delay(int deltime)			// Warten, deltime = Anzahl Takte / 2 (Timer wird mit CCLK/2 betrieben)
                           1238 ;	-----------------------------------------
                           1239 ;	 function delay
                           1240 ;	-----------------------------------------
   029A                    1241 _delay:
                           1242 ;	genReceive
   029A AA 82              1243 	mov	r2,dpl
   029C AB 83              1244 	mov	r3,dph
                           1245 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:174: TR1=0;				// Timer 1 anhalten
                           1246 ;	genAssign
   029E C2 8E              1247 	clr	_TCON_6
                           1248 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:175: deltime=0xFFFF-deltime;
                           1249 ;	genMinus
   02A0 74 FF              1250 	mov	a,#0xFF
   02A2 C3                 1251 	clr	c
                           1252 ;	Peephole 236.l	used r2 instead of ar2
   02A3 9A                 1253 	subb	a,r2
   02A4 FA                 1254 	mov	r2,a
   02A5 74 FF              1255 	mov	a,#0xFF
                           1256 ;	Peephole 236.l	used r3 instead of ar3
   02A7 9B                 1257 	subb	a,r3
   02A8 FB                 1258 	mov	r3,a
                           1259 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:176: TH1=deltime>>8;			// Timer 1 setzen 
                           1260 ;	genGetByte
   02A9 8B 8D              1261 	mov	_TH1,r3
                           1262 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:177: TL1=deltime;	
                           1263 ;	genCast
   02AB 8A 8B              1264 	mov	_TL1,r2
                           1265 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:178: TF1=0;
                           1266 ;	genAssign
   02AD C2 8F              1267 	clr	_TCON_7
                           1268 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:179: TR1=1;
                           1269 ;	genAssign
   02AF D2 8E              1270 	setb	_TCON_6
                           1271 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:180: while(!TF1);				// warten auf Timer 1
   02B1                    1272 00101$:
                           1273 ;	genIfx
                           1274 ;	genIfxJump
                           1275 ;	Peephole 108.d	removed ljmp by inverse jump logic
   02B1 30 8F FD           1276 	jnb	_TCON_7,00101$
                           1277 ;	Peephole 300	removed redundant label 00108$
                           1278 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:181: TR1=0;		
                           1279 ;	genAssign
   02B4 C2 8E              1280 	clr	_TCON_6
                           1281 ;	Peephole 300	removed redundant label 00104$
   02B6 22                 1282 	ret
                           1283 ;------------------------------------------------------------
                           1284 ;Allocation info for local variables in function 'set_timer1'
                           1285 ;------------------------------------------------------------
                           1286 ;deltime                   Allocated to registers r2 r3 
                           1287 ;------------------------------------------------------------
                           1288 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:185: void set_timer1(int deltime)		// Timer 1 stoppen, setzen und starten (Timer wird mit CCLK/2 betrieben)
                           1289 ;	-----------------------------------------
                           1290 ;	 function set_timer1
                           1291 ;	-----------------------------------------
   02B7                    1292 _set_timer1:
                           1293 ;	genReceive
   02B7 AA 82              1294 	mov	r2,dpl
   02B9 AB 83              1295 	mov	r3,dph
                           1296 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:187: TR1=0;				// Timer 1 anhalten
                           1297 ;	genAssign
   02BB C2 8E              1298 	clr	_TCON_6
                           1299 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:188: deltime=0xFFFF-deltime;
                           1300 ;	genMinus
   02BD 74 FF              1301 	mov	a,#0xFF
   02BF C3                 1302 	clr	c
                           1303 ;	Peephole 236.l	used r2 instead of ar2
   02C0 9A                 1304 	subb	a,r2
   02C1 FA                 1305 	mov	r2,a
   02C2 74 FF              1306 	mov	a,#0xFF
                           1307 ;	Peephole 236.l	used r3 instead of ar3
   02C4 9B                 1308 	subb	a,r3
   02C5 FB                 1309 	mov	r3,a
                           1310 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:189: TH1=deltime>>8;			// Timer 1 setzen 
                           1311 ;	genGetByte
   02C6 8B 8D              1312 	mov	_TH1,r3
                           1313 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:190: TL1=deltime;	
                           1314 ;	genCast
   02C8 8A 8B              1315 	mov	_TL1,r2
                           1316 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:191: TF1=0;				// Überlauf-Flag zurücksetzen
                           1317 ;	genAssign
   02CA C2 8F              1318 	clr	_TCON_7
                           1319 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:192: TR1=1;				// Timer 1 starten
                           1320 ;	genAssign
   02CC D2 8E              1321 	setb	_TCON_6
                           1322 ;	Peephole 300	removed redundant label 00101$
   02CE 22                 1323 	ret
                           1324 ;------------------------------------------------------------
                           1325 ;Allocation info for local variables in function 'read_byte'
                           1326 ;------------------------------------------------------------
                           1327 ;addrl                     Allocated to stack - offset -3
                           1328 ;addrh                     Allocated to registers r2 
                           1329 ;zdata                     Allocated to registers 
                           1330 ;------------------------------------------------------------
                           1331 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:196: unsigned char read_byte(unsigned char addrh, unsigned char addrl)		// liest byte aus flash
                           1332 ;	-----------------------------------------
                           1333 ;	 function read_byte
                           1334 ;	-----------------------------------------
   02CF                    1335 _read_byte:
   02CF C0 08              1336 	push	_bp
   02D1 85 81 08           1337 	mov	_bp,sp
                           1338 ;	genReceive
   02D4 AA 82              1339 	mov	r2,dpl
                           1340 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:200: zdata=dataflash[(addrh<<8)+addrl];
                           1341 ;	genCast
                           1342 ;	genLeftShift
                           1343 ;	genLeftShiftLiteral
                           1344 ;	genlshTwo
                           1345 ;	peephole 177.e	removed redundant move
   02D6 8A 03              1346 	mov	ar3,r2
   02D8 7A 00              1347 	mov	r2,#0x00
                           1348 ;	genCast
   02DA A8 08              1349 	mov	r0,_bp
   02DC 18                 1350 	dec	r0
   02DD 18                 1351 	dec	r0
   02DE 18                 1352 	dec	r0
   02DF 86 04              1353 	mov	ar4,@r0
   02E1 7D 00              1354 	mov	r5,#0x00
                           1355 ;	genPlus
                           1356 ;	Peephole 236.g	used r4 instead of ar4
   02E3 EC                 1357 	mov	a,r4
                           1358 ;	Peephole 236.a	used r2 instead of ar2
   02E4 2A                 1359 	add	a,r2
   02E5 FA                 1360 	mov	r2,a
                           1361 ;	Peephole 236.g	used r5 instead of ar5
   02E6 ED                 1362 	mov	a,r5
                           1363 ;	Peephole 236.b	used r3 instead of ar3
   02E7 3B                 1364 	addc	a,r3
   02E8 FB                 1365 	mov	r3,a
                           1366 ;	genPlus
                           1367 ;     genPlus aligned array
   02E9 8A 82              1368 	mov	dpl,r2
   02EB 74 1C              1369 	mov	a,#(_dataflash >> 8)
   02ED 2B                 1370 	add	a,r3
   02EE F5 83              1371 	mov	dph,a
                           1372 ;	genPointerGet
                           1373 ;	genCodePointerGet
   02F0 E4                 1374 	clr	a
   02F1 93                 1375 	movc	a,@a+dptr
                           1376 ;	genAssign
   02F2 FA                 1377 	mov	r2,a
                           1378 ;	Peephole 244.c	loading dpl from a instead of r2
   02F3 F5 82              1379 	mov	dpl,a
                           1380 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:201: return (zdata);
                           1381 ;	genRet
                           1382 ;	Peephole 300	removed redundant label 00101$
   02F5 D0 08              1383 	pop	_bp
   02F7 22                 1384 	ret
                           1385 ;------------------------------------------------------------
                           1386 ;Allocation info for local variables in function 'restart_hw'
                           1387 ;------------------------------------------------------------
                           1388 ;------------------------------------------------------------
                           1389 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:205: void restart_hw(void)	// Alle Hardware Einstellungen zurücksetzen
                           1390 ;	-----------------------------------------
                           1391 ;	 function restart_hw
                           1392 ;	-----------------------------------------
   02F8                    1393 _restart_hw:
                           1394 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:209: DIVM=0;		// Taktferquenz nicht teilen -> volles Tempo
                           1395 ;	genAssign
   02F8 75 95 00           1396 	mov	_DIVM,#0x00
                           1397 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:211: P1M1=0x14;		// Port 1 auf quasi-bidirektional, außer P1.2(T0 als PWM Ausgang)=open-drain, P1.4(INT1)=Input only, P1.6(FBOUTC) push-pull
                           1398 ;	genAssign
   02FB 75 91 14           1399 	mov	_P1M1,#0x14
                           1400 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:212: P1M2=0x44;
                           1401 ;	genAssign
   02FE 75 92 44           1402 	mov	_P1M2,#0x44
                           1403 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:214: FBOUTC=0;		// Bus-Ausgang auf low
                           1404 ;	genAssign
   0301 C2 96              1405 	clr	_P1_6
                           1406 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:216: TMOD=0x12;		// Timer 0 als PWM, Timer 1 als 16-Bit Timer
                           1407 ;	genAssign
   0303 75 89 12           1408 	mov	_TMOD,#0x12
                           1409 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:217: TAMOD=0x01;
                           1410 ;	genAssign
   0306 75 8F 01           1411 	mov	_TAMOD,#0x01
                           1412 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:218: TH0=DUTY;		// Pulsverhältnis PWM
                           1413 ;	genAssign
   0309 75 8C C0           1414 	mov	_TH0,#0xC0
                           1415 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:219: AUXR1|=0x10;		// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
                           1416 ;	genOr
   030C 43 A2 10           1417 	orl	_AUXR1,#0x10
                           1418 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:221: ET0=0;		// Interrupt für Timer 0 sperren 
                           1419 ;	genAssign
   030F C2 A9              1420 	clr	_IEN0_1
                           1421 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:222: TR0=1;		// Timer 0 starten (PWM)
                           1422 ;	genAssign
   0311 D2 8C              1423 	setb	_TCON_4
                           1424 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:223: TR1=0;		// Timer 1 (Empfangs-Timeout) zunächst stoppen
                           1425 ;	genAssign
   0313 C2 8E              1426 	clr	_TCON_6
                           1427 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:225: RTCH=0x1D;		// Real Time Clock
                           1428 ;	genAssign
   0315 75 D2 1D           1429 	mov	_RTCH,#0x1D
                           1430 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:226: RTCL=0x40;
                           1431 ;	genAssign
   0318 75 D3 40           1432 	mov	_RTCL,#0x40
                           1433 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:227: RTCCON=0x61;
                           1434 ;	genAssign
   031B 75 D1 61           1435 	mov	_RTCCON,#0x61
                           1436 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:229: IEN0=0x00;
                           1437 ;	genAssign
   031E 75 A8 00           1438 	mov	_IEN0,#0x00
                           1439 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:230: IEN1=0x00;
                           1440 ;	genAssign
   0321 75 E8 00           1441 	mov	_IEN1,#0x00
                           1442 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:231: EA=1;			// Interrupts prinzipiell freigeben
                           1443 ;	genAssign
   0324 D2 AF              1444 	setb	_IEN0_7
                           1445 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:232: EX0=0;		// Externen Interrupt 0 sperren
                           1446 ;	genAssign
   0326 C2 A8              1447 	clr	_IEN0_0
                           1448 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:233: EX1=1;		// Externen Interrupt 1 freigeben	
                           1449 ;	genAssign
   0328 D2 AA              1450 	setb	_IEN0_2
                           1451 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:235: IP0=0x0C;		// höchste Priorität für ext. Int. 1 und Timer 1 (Bit 0 und 3)
                           1452 ;	genAssign
   032A 75 B8 0C           1453 	mov	_IP0,#0x0C
                           1454 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:236: IP0H=0x0C;
                           1455 ;	genAssign
   032D 75 B7 0C           1456 	mov	_IP0H,#0x0C
                           1457 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:237: IP1=0x00;
                           1458 ;	genAssign
   0330 75 F8 00           1459 	mov	_IP1,#0x00
                           1460 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:238: IP1H=0x00;
                           1461 ;	genAssign
   0333 75 F7 00           1462 	mov	_IP1H,#0x00
                           1463 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:239: IT1=1;		// Int1 flankengetriggert=1 pegelgetriggert=0
                           1464 ;	genAssign
   0336 D2 8A              1465 	setb	_TCON_2
                           1466 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:241: SCON=0x50;		// Serielle auf Mode 1, receive enable
                           1467 ;	genAssign
   0338 75 98 50           1468 	mov	_SCON,#0x50
                           1469 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:242: SSTAT|=0x40;		// TI wird am Ende des Stopbits gesetzt
                           1470 ;	genOr
   033B 43 BA 40           1471 	orl	_SSTAT,#0x40
                           1472 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:243: BRGCON|=0x02;		// Baudrate Generator verwenden aber noch gestoppt
                           1473 ;	genOr
   033E 43 BD 02           1474 	orl	_BRGCON,#0x02
                           1475 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:244: BRGR1=0x00;		// Baudrate = cclk/((BRGR1,BRGR0)+16)
                           1476 ;	genAssign
   0341 75 BF 00           1477 	mov	_BRGR1,#0x00
                           1478 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:245: BRGR0=0x30;
                           1479 ;	genAssign
   0344 75 BE 30           1480 	mov	_BRGR0,#0x30
                           1481 ;	d:/freebus/trunk/c51/89LPC922/common/fb_hal_lpc.c:246: BRGCON|=0x01;		// Baudrate Generator starten
                           1482 ;	genOr
   0347 43 BD 01           1483 	orl	_BRGCON,#0x01
                           1484 ;	Peephole 300	removed redundant label 00101$
   034A 22                 1485 	ret
                           1486 ;------------------------------------------------------------
                           1487 ;Allocation info for local variables in function 'timer1'
                           1488 ;------------------------------------------------------------
                           1489 ;data_laenge               Allocated to registers r2 
                           1490 ;daf                       Allocated to registers r3 
                           1491 ;------------------------------------------------------------
                           1492 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:12: void timer1(void) interrupt 3	// Interrupt von Timer 1, 370us keine Busaktivität seit letztem Byte, d.h. Telegramm wurde komplett übertragen
                           1493 ;	-----------------------------------------
                           1494 ;	 function timer1
                           1495 ;	-----------------------------------------
   034B                    1496 _timer1:
   034B C0 E0              1497 	push	acc
   034D C0 F0              1498 	push	b
   034F C0 82              1499 	push	dpl
   0351 C0 83              1500 	push	dph
   0353 C0 02              1501 	push	(0+2)
   0355 C0 03              1502 	push	(0+3)
   0357 C0 04              1503 	push	(0+4)
   0359 C0 05              1504 	push	(0+5)
   035B C0 06              1505 	push	(0+6)
   035D C0 07              1506 	push	(0+7)
   035F C0 00              1507 	push	(0+0)
   0361 C0 01              1508 	push	(0+1)
   0363 C0 21              1509 	push	bits
   0365 C0 D0              1510 	push	psw
   0367 75 D0 00           1511 	mov	psw,#0x00
                           1512 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:16: EX1=0;					// ext. Interrupt stoppen 
                           1513 ;	genAssign
   036A C2 AA              1514 	clr	_IEN0_2
                           1515 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:17: ET1=0;					// Interrupt von Timer 1 sperren
                           1516 ;	genAssign
   036C C2 AB              1517 	clr	_IEN0_3
                           1518 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:18: set_timer1(4720);				// und neu starten für korrekte Positionierung des ACK Bytes
                           1519 ;	genCall
                           1520 ;	Peephole 182.b	used 16 bit load of dptr
   036E 90 12 70           1521 	mov	dptr,#0x1270
   0371 12 02 B7           1522 	lcall	_set_timer1
                           1523 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:20: if(cs==0xff)					// Checksum des Telegramms ist OK 
                           1524 ;	genCmpEq
                           1525 ;	gencjneshort
   0374 E5 3A              1526 	mov	a,_cs
   0376 B4 FF 02           1527 	cjne	a,#0xFF,00185$
   0379 80 03              1528 	sjmp	00186$
   037B                    1529 00185$:
   037B 02 04 7D           1530 	ljmp	00152$
   037E                    1531 00186$:
                           1532 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:22: data_laenge=(telegramm[5]&0x0F);		// Telegramm-Länge = Bit 0 bis 3 
                           1533 ;	genAssign
                           1534 ;	genAnd
   037E 74 0F              1535 	mov	a,#0x0F
   0380 55 27              1536 	anl	a,0x0005 + _telegramm
   0382 FA                 1537 	mov	r2,a
                           1538 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:23: daf=(telegramm[5]&0x80);			// Destination Adress Flag = Bit 7, 0=phys. Adr., 1=Gruppenadr.
                           1539 ;	genAnd
   0383 74 80              1540 	mov	a,#0x80
   0385 55 27              1541 	anl	a,0x0005 + _telegramm
   0387 FB                 1542 	mov	r3,a
                           1543 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:25: if(telegramm[3]==0 && telegramm[4]==0)		// Broadcast, wenn Zieladresse = 0
                           1544 ;	genPointerGet
                           1545 ;	genNearPointerGet
                           1546 ;	genDataPointerGet
                           1547 ;	genIfx
                           1548 ;	peephole 177.g	optimized mov sequence
   0388 E5 25              1549 	mov	a,(_telegramm + 0x0003)
   038A FC                 1550 	mov	r4,a
                           1551 ;	genIfxJump
                           1552 ;	Peephole 108.b	removed ljmp by inverse jump logic
   038B 70 30              1553 	jnz	00148$
                           1554 ;	Peephole 300	removed redundant label 00187$
                           1555 ;	genPointerGet
                           1556 ;	genNearPointerGet
                           1557 ;	genDataPointerGet
   038D E5 26              1558 	mov	a,(_telegramm + 0x0004)
                           1559 ;	genIfx
                           1560 ;	genIfxJump
                           1561 ;	Peephole 108.b	removed ljmp by inverse jump logic
   038F 70 2C              1562 	jnz	00148$
                           1563 ;	Peephole 300	removed redundant label 00188$
                           1564 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:27: if(progmode)
                           1565 ;	genIfx
                           1566 ;	genIfxJump
   0391 20 01 03           1567 	jb	_progmode,00189$
   0394 02 04 7D           1568 	ljmp	00152$
   0397                    1569 00189$:
                           1570 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:29: if(data_laenge==3 && telegramm[6]==0x00 && telegramm[7]==0xC0) set_pa();	// set_pa_req
                           1571 ;	genCmpEq
                           1572 ;	gencjneshort
                           1573 ;	Peephole 112.b	changed ljmp to sjmp
                           1574 ;	Peephole 198.b	optimized misc jump sequence
   0397 BA 03 0C           1575 	cjne	r2,#0x03,00102$
                           1576 ;	Peephole 200.b	removed redundant sjmp
                           1577 ;	Peephole 300	removed redundant label 00190$
                           1578 ;	Peephole 300	removed redundant label 00191$
                           1579 ;	genPointerGet
                           1580 ;	genNearPointerGet
                           1581 ;	genDataPointerGet
   039A E5 28              1582 	mov	a,(_telegramm + 0x0006)
                           1583 ;	genIfx
                           1584 ;	genIfxJump
                           1585 ;	Peephole 108.b	removed ljmp by inverse jump logic
   039C 70 08              1586 	jnz	00102$
                           1587 ;	Peephole 300	removed redundant label 00192$
                           1588 ;	genAssign
                           1589 ;	genCmpEq
                           1590 ;	gencjneshort
   039E E5 29              1591 	mov	a,0x0007 + _telegramm
                           1592 ;	Peephole 112.b	changed ljmp to sjmp
                           1593 ;	Peephole 198.b	optimized misc jump sequence
   03A0 B4 C0 03           1594 	cjne	a,#0xC0,00102$
                           1595 ;	Peephole 200.b	removed redundant sjmp
                           1596 ;	Peephole 300	removed redundant label 00193$
                           1597 ;	Peephole 300	removed redundant label 00194$
                           1598 ;	genCall
   03A3 12 06 F5           1599 	lcall	_set_pa
   03A6                    1600 00102$:
                           1601 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:30: if(telegramm[6]==0x01 && telegramm[7]==0x00) read_pa();				// read_pa_req
                           1602 ;	genAssign
                           1603 ;	genCmpEq
                           1604 ;	gencjneshort
   03A6 E5 28              1605 	mov	a,0x0006 + _telegramm
   03A8 B4 01 02           1606 	cjne	a,#0x01,00195$
   03AB 80 03              1607 	sjmp	00196$
   03AD                    1608 00195$:
   03AD 02 04 7D           1609 	ljmp	00152$
   03B0                    1610 00196$:
                           1611 ;	genPointerGet
                           1612 ;	genNearPointerGet
                           1613 ;	genDataPointerGet
   03B0 E5 29              1614 	mov	a,(_telegramm + 0x0007)
                           1615 ;	genIfx
                           1616 ;	genIfxJump
   03B2 60 03              1617 	jz	00197$
   03B4 02 04 7D           1618 	ljmp	00152$
   03B7                    1619 00197$:
                           1620 ;	genCall
   03B7 12 07 21           1621 	lcall	_read_pa
   03BA 02 04 7D           1622 	ljmp	00152$
   03BD                    1623 00148$:
                           1624 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:35: if(daf==0x00)					// Unicast, wenn Zieladresse physikalische Adresse ist
                           1625 ;	genIfx
   03BD EB                 1626 	mov	a,r3
                           1627 ;	genIfxJump
   03BE 60 03              1628 	jz	00198$
   03C0 02 04 64           1629 	ljmp	00145$
   03C3                    1630 00198$:
                           1631 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:37: if(telegramm[3]==pah && telegramm[4]==pal)	// nur wenn es die eigene phys. Adr. ist
                           1632 ;	genCmpEq
                           1633 ;	gencjneshort
   03C3 EC                 1634 	mov	a,r4
   03C4 B5 3C 02           1635 	cjne	a,_pah,00199$
   03C7 80 03              1636 	sjmp	00200$
   03C9                    1637 00199$:
   03C9 02 04 7D           1638 	ljmp	00152$
   03CC                    1639 00200$:
                           1640 ;	genAssign
                           1641 ;	genCmpEq
                           1642 ;	gencjneshort
   03CC E5 26              1643 	mov	a,0x0004 + _telegramm
   03CE B5 3B 02           1644 	cjne	a,_pal,00201$
   03D1 80 03              1645 	sjmp	00202$
   03D3                    1646 00201$:
   03D3 02 04 7D           1647 	ljmp	00152$
   03D6                    1648 00202$:
                           1649 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:39: if((telegramm[6]&0xC3)==0x42 && (telegramm[7]&0xC0)==0x80) write_memory();	// write_memory_request beantworten
                           1650 ;	genAssign
                           1651 ;	genAnd
   03D6 74 C3              1652 	mov	a,#0xC3
   03D8 55 28              1653 	anl	a,0x0006 + _telegramm
   03DA FB                 1654 	mov	r3,a
                           1655 ;	genCmpEq
                           1656 ;	gencjneshort
                           1657 ;	Peephole 112.b	changed ljmp to sjmp
                           1658 ;	Peephole 198.b	optimized misc jump sequence
   03DB BB 42 0F           1659 	cjne	r3,#0x42,00111$
                           1660 ;	Peephole 200.b	removed redundant sjmp
                           1661 ;	Peephole 300	removed redundant label 00203$
                           1662 ;	Peephole 300	removed redundant label 00204$
                           1663 ;	genAssign
                           1664 ;	genAnd
   03DE 74 C0              1665 	mov	a,#0xC0
   03E0 55 29              1666 	anl	a,0x0007 + _telegramm
   03E2 FB                 1667 	mov	r3,a
                           1668 ;	genCmpEq
                           1669 ;	gencjneshort
                           1670 ;	Peephole 112.b	changed ljmp to sjmp
                           1671 ;	Peephole 198.b	optimized misc jump sequence
   03E3 BB 80 07           1672 	cjne	r3,#0x80,00111$
                           1673 ;	Peephole 200.b	removed redundant sjmp
                           1674 ;	Peephole 300	removed redundant label 00205$
                           1675 ;	Peephole 300	removed redundant label 00206$
                           1676 ;	genCall
   03E6 C0 02              1677 	push	ar2
   03E8 12 06 6E           1678 	lcall	_write_memory
   03EB D0 02              1679 	pop	ar2
   03ED                    1680 00111$:
                           1681 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:40: if(data_laenge==0)
                           1682 ;	genIfx
   03ED EA                 1683 	mov	a,r2
                           1684 ;	genIfxJump
                           1685 ;	Peephole 108.b	removed ljmp by inverse jump logic
   03EE 70 27              1686 	jnz	00120$
                           1687 ;	Peephole 300	removed redundant label 00207$
                           1688 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:42: if((telegramm[6]&0xC0)==0xC0) send_ack();				// auf NCD_Quittierung mit ACK antworten
                           1689 ;	genAssign
                           1690 ;	genAnd
   03F0 74 C0              1691 	mov	a,#0xC0
   03F2 55 28              1692 	anl	a,0x0006 + _telegramm
   03F4 FB                 1693 	mov	r3,a
                           1694 ;	genCmpEq
                           1695 ;	gencjneshort
                           1696 ;	Peephole 112.b	changed ljmp to sjmp
                           1697 ;	Peephole 198.b	optimized misc jump sequence
   03F5 BB C0 07           1698 	cjne	r3,#0xC0,00114$
                           1699 ;	Peephole 200.b	removed redundant sjmp
                           1700 ;	Peephole 300	removed redundant label 00208$
                           1701 ;	Peephole 300	removed redundant label 00209$
                           1702 ;	genCall
   03F8 C0 02              1703 	push	ar2
   03FA 12 05 9E           1704 	lcall	_send_ack
   03FD D0 02              1705 	pop	ar2
   03FF                    1706 00114$:
                           1707 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:43: if(telegramm[6]==0x80) ucd_opr();					// UCD Verbindungsaufbau
                           1708 ;	genAssign
                           1709 ;	genCmpEq
                           1710 ;	gencjneshort
   03FF E5 28              1711 	mov	a,0x0006 + _telegramm
                           1712 ;	Peephole 112.b	changed ljmp to sjmp
                           1713 ;	Peephole 198.b	optimized misc jump sequence
   0401 B4 80 07           1714 	cjne	a,#0x80,00116$
                           1715 ;	Peephole 200.b	removed redundant sjmp
                           1716 ;	Peephole 300	removed redundant label 00210$
                           1717 ;	Peephole 300	removed redundant label 00211$
                           1718 ;	genCall
   0404 C0 02              1719 	push	ar2
   0406 12 05 AA           1720 	lcall	_ucd_opr
   0409 D0 02              1721 	pop	ar2
   040B                    1722 00116$:
                           1723 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:44: if(telegramm[6]==0x81) ucd_clr();					// UCD Verbindungsabbau
                           1724 ;	genAssign
                           1725 ;	genCmpEq
                           1726 ;	gencjneshort
   040B E5 28              1727 	mov	a,0x0006 + _telegramm
                           1728 ;	Peephole 112.b	changed ljmp to sjmp
                           1729 ;	Peephole 198.b	optimized misc jump sequence
   040D B4 81 07           1730 	cjne	a,#0x81,00120$
                           1731 ;	Peephole 200.b	removed redundant sjmp
                           1732 ;	Peephole 300	removed redundant label 00212$
                           1733 ;	Peephole 300	removed redundant label 00213$
                           1734 ;	genCall
   0410 C0 02              1735 	push	ar2
   0412 12 05 BC           1736 	lcall	_ucd_clr
   0415 D0 02              1737 	pop	ar2
   0417                    1738 00120$:
                           1739 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:46: if(data_laenge==1)
                           1740 ;	genCmpEq
                           1741 ;	gencjneshort
                           1742 ;	Peephole 112.b	changed ljmp to sjmp
                           1743 ;	Peephole 198.b	optimized misc jump sequence
   0417 BA 01 32           1744 	cjne	r2,#0x01,00128$
                           1745 ;	Peephole 200.b	removed redundant sjmp
                           1746 ;	Peephole 300	removed redundant label 00214$
                           1747 ;	Peephole 300	removed redundant label 00215$
                           1748 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:48: if((telegramm[6]&0x03)==0x03 && telegramm[7]==0x80)		// restart request
                           1749 ;	genAssign
                           1750 ;	genAnd
   041A 74 03              1751 	mov	a,#0x03
   041C 55 28              1752 	anl	a,0x0006 + _telegramm
   041E FB                 1753 	mov	r3,a
                           1754 ;	genCmpEq
                           1755 ;	gencjneshort
                           1756 ;	Peephole 112.b	changed ljmp to sjmp
                           1757 ;	Peephole 198.b	optimized misc jump sequence
   041F BB 03 1A           1758 	cjne	r3,#0x03,00122$
                           1759 ;	Peephole 200.b	removed redundant sjmp
                           1760 ;	Peephole 300	removed redundant label 00216$
                           1761 ;	Peephole 300	removed redundant label 00217$
                           1762 ;	genAssign
                           1763 ;	genCmpEq
                           1764 ;	gencjneshort
   0422 E5 29              1765 	mov	a,0x0007 + _telegramm
                           1766 ;	Peephole 112.b	changed ljmp to sjmp
                           1767 ;	Peephole 198.b	optimized misc jump sequence
   0424 B4 80 15           1768 	cjne	a,#0x80,00122$
                           1769 ;	Peephole 200.b	removed redundant sjmp
                           1770 ;	Peephole 300	removed redundant label 00218$
                           1771 ;	Peephole 300	removed redundant label 00219$
                           1772 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:50: restart_hw();	// Hardware zurücksetzen
                           1773 ;	genCall
   0427 C0 02              1774 	push	ar2
   0429 12 02 F8           1775 	lcall	_restart_hw
   042C D0 02              1776 	pop	ar2
                           1777 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:51: restart_prot();	// Protokoll-relevante Parameter zurücksetzen
                           1778 ;	genCall
   042E C0 02              1779 	push	ar2
   0430 12 09 94           1780 	lcall	_restart_prot
   0433 D0 02              1781 	pop	ar2
                           1782 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:52: restart_app();	// Anwendungsspezifische Einstellungen zurücksetzen
                           1783 ;	genCall
   0435 C0 02              1784 	push	ar2
   0437 12 0A 81           1785 	lcall	_restart_app
   043A D0 02              1786 	pop	ar2
   043C                    1787 00122$:
                           1788 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:54: if(telegramm[6]==0x43 && telegramm[7]==0x00) read_masq();		// Maskenversion angefordert
                           1789 ;	genAssign
                           1790 ;	genCmpEq
                           1791 ;	gencjneshort
   043C E5 28              1792 	mov	a,0x0006 + _telegramm
                           1793 ;	Peephole 112.b	changed ljmp to sjmp
                           1794 ;	Peephole 198.b	optimized misc jump sequence
   043E B4 43 0B           1795 	cjne	a,#0x43,00128$
                           1796 ;	Peephole 200.b	removed redundant sjmp
                           1797 ;	Peephole 300	removed redundant label 00220$
                           1798 ;	Peephole 300	removed redundant label 00221$
                           1799 ;	genPointerGet
                           1800 ;	genNearPointerGet
                           1801 ;	genDataPointerGet
   0441 E5 29              1802 	mov	a,(_telegramm + 0x0007)
                           1803 ;	genIfx
                           1804 ;	genIfxJump
                           1805 ;	Peephole 108.b	removed ljmp by inverse jump logic
   0443 70 07              1806 	jnz	00128$
                           1807 ;	Peephole 300	removed redundant label 00222$
                           1808 ;	genCall
   0445 C0 02              1809 	push	ar2
   0447 12 05 F7           1810 	lcall	_read_masq
   044A D0 02              1811 	pop	ar2
   044C                    1812 00128$:
                           1813 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:56: if(data_laenge==3)
                           1814 ;	genCmpEq
                           1815 ;	gencjneshort
                           1816 ;	Peephole 112.b	changed ljmp to sjmp
                           1817 ;	Peephole 198.b	optimized misc jump sequence
   044C BA 03 2E           1818 	cjne	r2,#0x03,00152$
                           1819 ;	Peephole 200.b	removed redundant sjmp
                           1820 ;	Peephole 300	removed redundant label 00223$
                           1821 ;	Peephole 300	removed redundant label 00224$
                           1822 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:58: if((telegramm[6]&0xC3)==0x42 && (telegramm[7]&0xC0)==0x00) read_memory();	// read_memory_request beantworten
                           1823 ;	genAssign
                           1824 ;	genAnd
   044F 74 C3              1825 	mov	a,#0xC3
   0451 55 28              1826 	anl	a,0x0006 + _telegramm
   0453 FB                 1827 	mov	r3,a
                           1828 ;	genCmpEq
                           1829 ;	gencjneshort
                           1830 ;	Peephole 112.b	changed ljmp to sjmp
                           1831 ;	Peephole 198.b	optimized misc jump sequence
   0454 BB 42 26           1832 	cjne	r3,#0x42,00152$
                           1833 ;	Peephole 200.b	removed redundant sjmp
                           1834 ;	Peephole 300	removed redundant label 00225$
                           1835 ;	Peephole 300	removed redundant label 00226$
                           1836 ;	genAssign
                           1837 ;	genAnd
   0457 E5 29              1838 	mov	a,0x0007 + _telegramm
   0459 54 C0              1839 	anl	a,#0xC0
                           1840 ;	Peephole 160.c	removed sjmp by inverse jump logic
   045B 60 02              1841 	jz	00228$
                           1842 ;	Peephole 300	removed redundant label 00227$
                           1843 ;	Peephole 112.b	changed ljmp to sjmp
   045D 80 1E              1844 	sjmp	00152$
   045F                    1845 00228$:
                           1846 ;	genCall
   045F 12 06 12           1847 	lcall	_read_memory
                           1848 ;	Peephole 112.b	changed ljmp to sjmp
   0462 80 19              1849 	sjmp	00152$
   0464                    1850 00145$:
                           1851 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:65: if(data_laenge==1 && telegramm[6]==0x00)
                           1852 ;	genCmpEq
                           1853 ;	gencjneshort
                           1854 ;	Peephole 112.b	changed ljmp to sjmp
                           1855 ;	Peephole 198.b	optimized misc jump sequence
   0464 BA 01 16           1856 	cjne	r2,#0x01,00152$
                           1857 ;	Peephole 200.b	removed redundant sjmp
                           1858 ;	Peephole 300	removed redundant label 00229$
                           1859 ;	Peephole 300	removed redundant label 00230$
                           1860 ;	genPointerGet
                           1861 ;	genNearPointerGet
                           1862 ;	genDataPointerGet
   0467 E5 28              1863 	mov	a,(_telegramm + 0x0006)
                           1864 ;	genIfx
                           1865 ;	genIfxJump
                           1866 ;	Peephole 108.b	removed ljmp by inverse jump logic
   0469 70 12              1867 	jnz	00152$
                           1868 ;	Peephole 300	removed redundant label 00231$
                           1869 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:67: if ((telegramm[7]&0xFE)==0x80) eis1();		// Ausgänge schalten (EIS 1)
                           1870 ;	genAssign
                           1871 ;	genAnd
   046B 74 FE              1872 	mov	a,#0xFE
   046D 55 29              1873 	anl	a,0x0007 + _telegramm
   046F FA                 1874 	mov	r2,a
                           1875 ;	genCmpEq
                           1876 ;	gencjneshort
                           1877 ;	Peephole 112.b	changed ljmp to sjmp
                           1878 ;	Peephole 198.b	optimized misc jump sequence
   0470 BA 80 03           1879 	cjne	r2,#0x80,00138$
                           1880 ;	Peephole 200.b	removed redundant sjmp
                           1881 ;	Peephole 300	removed redundant label 00232$
                           1882 ;	Peephole 300	removed redundant label 00233$
                           1883 ;	genCall
   0473 12 0A 34           1884 	lcall	_eis1
   0476                    1885 00138$:
                           1886 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:68: if (telegramm[7]==0x00) read_value_req();		// Objektwert lesen und als read_value_res auf Bus senden
                           1887 ;	genPointerGet
                           1888 ;	genNearPointerGet
                           1889 ;	genDataPointerGet
   0476 E5 29              1890 	mov	a,(_telegramm + 0x0007)
                           1891 ;	genIfx
                           1892 ;	genIfxJump
                           1893 ;	Peephole 108.b	removed ljmp by inverse jump logic
   0478 70 03              1894 	jnz	00152$
                           1895 ;	Peephole 300	removed redundant label 00234$
                           1896 ;	genCall
   047A 12 0A 80           1897 	lcall	_read_value_req
   047D                    1898 00152$:
                           1899 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:73: telpos=0;  
                           1900 ;	genAssign
   047D 75 39 00           1901 	mov	_telpos,#0x00
                           1902 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:74: IE1=0;		// IRQ zurücksetzen
                           1903 ;	genAssign
   0480 C2 8B              1904 	clr	_TCON_3
                           1905 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:75: EX1=1;		// externen Interrupt 0 wieder freigeben
                           1906 ;	genAssign
   0482 D2 AA              1907 	setb	_IEN0_2
                           1908 ;	Peephole 300	removed redundant label 00153$
   0484 D0 D0              1909 	pop	psw
   0486 D0 21              1910 	pop	bits
   0488 D0 01              1911 	pop	(0+1)
   048A D0 00              1912 	pop	(0+0)
   048C D0 07              1913 	pop	(0+7)
   048E D0 06              1914 	pop	(0+6)
   0490 D0 05              1915 	pop	(0+5)
   0492 D0 04              1916 	pop	(0+4)
   0494 D0 03              1917 	pop	(0+3)
   0496 D0 02              1918 	pop	(0+2)
   0498 D0 83              1919 	pop	dph
   049A D0 82              1920 	pop	dpl
   049C D0 F0              1921 	pop	b
   049E D0 E0              1922 	pop	acc
   04A0 32                 1923 	reti
                           1924 ;------------------------------------------------------------
                           1925 ;Allocation info for local variables in function 'get_ack'
                           1926 ;------------------------------------------------------------
                           1927 ;ret                       Allocated to registers r2 
                           1928 ;n                         Allocated to registers r3 r4 
                           1929 ;------------------------------------------------------------
                           1930 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:82: unsigned char get_ack(void)		// Byte empfangen und prüfen ob es ein ACK war
                           1931 ;	-----------------------------------------
                           1932 ;	 function get_ack
                           1933 ;	-----------------------------------------
   04A1                    1934 _get_ack:
                           1935 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:88: ret=0;
                           1936 ;	genAssign
   04A1 7A 00              1937 	mov	r2,#0x00
                           1938 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:89: do 
                           1939 ;	genAssign
   04A3 7B 00              1940 	mov	r3,#0x00
   04A5 7C 00              1941 	mov	r4,#0x00
   04A7                    1942 00107$:
                           1943 ;	genIfx
                           1944 ;	genIfxJump
                           1945 ;	Peephole 108.d	removed ljmp by inverse jump logic
   04A7 30 94 07           1946 	jnb	_P1_4,00105$
                           1947 ;	Peephole 300	removed redundant label 00118$
                           1948 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:91: if(FBINC==1) n++;
                           1949 ;	genPlus
                           1950 ;     genPlusIncr
   04AA 0B                 1951 	inc	r3
                           1952 ;	Peephole 112.b	changed ljmp to sjmp
                           1953 ;	Peephole 243	avoided branch to sjmp
   04AB BB 00 1C           1954 	cjne	r3,#0x00,00108$
   04AE 0C                 1955 	inc	r4
                           1956 ;	Peephole 300	removed redundant label 00119$
   04AF 80 19              1957 	sjmp	00108$
   04B1                    1958 00105$:
                           1959 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:94: if (get_byte()==0xCC && parity_ok) ret=1;
                           1960 ;	genCall
   04B1 C0 02              1961 	push	ar2
   04B3 C0 03              1962 	push	ar3
   04B5 C0 04              1963 	push	ar4
   04B7 12 00 7F           1964 	lcall	_get_byte
   04BA AD 82              1965 	mov	r5,dpl
   04BC D0 04              1966 	pop	ar4
   04BE D0 03              1967 	pop	ar3
   04C0 D0 02              1968 	pop	ar2
                           1969 ;	genCmpEq
                           1970 ;	gencjneshort
                           1971 ;	Peephole 112.b	changed ljmp to sjmp
                           1972 ;	Peephole 198.b	optimized misc jump sequence
   04C2 BD CC 05           1973 	cjne	r5,#0xCC,00108$
                           1974 ;	Peephole 200.b	removed redundant sjmp
                           1975 ;	Peephole 300	removed redundant label 00120$
                           1976 ;	Peephole 300	removed redundant label 00121$
                           1977 ;	genIfx
                           1978 ;	genIfxJump
                           1979 ;	Peephole 108.d	removed ljmp by inverse jump logic
   04C5 30 00 02           1980 	jnb	_parity_ok,00108$
                           1981 ;	Peephole 300	removed redundant label 00122$
                           1982 ;	genAssign
   04C8 7A 01              1983 	mov	r2,#0x01
   04CA                    1984 00108$:
                           1985 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:96: } while (n<3000);
                           1986 ;	genCmpLt
                           1987 ;	genCmp
   04CA C3                 1988 	clr	c
   04CB EB                 1989 	mov	a,r3
   04CC 94 B8              1990 	subb	a,#0xB8
   04CE EC                 1991 	mov	a,r4
   04CF 64 80              1992 	xrl	a,#0x80
   04D1 94 8B              1993 	subb	a,#0x8b
                           1994 ;	genIfxJump
                           1995 ;	Peephole 112.b	changed ljmp to sjmp
                           1996 ;	Peephole 160.a	removed sjmp by inverse jump logic
   04D3 40 D2              1997 	jc	00107$
                           1998 ;	Peephole 300	removed redundant label 00123$
                           1999 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:97: return(ret);
                           2000 ;	genRet
   04D5 8A 82              2001 	mov	dpl,r2
                           2002 ;	Peephole 300	removed redundant label 00110$
   04D7 22                 2003 	ret
                           2004 ;------------------------------------------------------------
                           2005 ;Allocation info for local variables in function 'send_telegramm'
                           2006 ;------------------------------------------------------------
                           2007 ;data_laenge               Allocated to stack - offset 1
                           2008 ;l                         Allocated to registers r5 
                           2009 ;checksum                  Allocated to registers r3 
                           2010 ;r                         Allocated to registers r2 
                           2011 ;------------------------------------------------------------
                           2012 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:102: void send_telegramm(void)		// sendet das Telegramm, das in telegramm[] vorher abgelegt wurde und berechnet die checksum
                           2013 ;	-----------------------------------------
                           2014 ;	 function send_telegramm
                           2015 ;	-----------------------------------------
   04D8                    2016 _send_telegramm:
   04D8 C0 08              2017 	push	_bp
   04DA 85 81 08           2018 	mov	_bp,sp
   04DD 05 81              2019 	inc	sp
                           2020 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:106: r=0;
                           2021 ;	genAssign
   04DF 7A 00              2022 	mov	r2,#0x00
                           2023 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:107: do
   04E1                    2024 00108$:
                           2025 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:109: checksum=0;
                           2026 ;	genAssign
   04E1 7B 00              2027 	mov	r3,#0x00
                           2028 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:110: data_laenge=telegramm[5]&0x0F;	// Telegramm-Länge = Bit 0 bis 3
                           2029 ;	genAssign
                           2030 ;	genAnd
   04E3 A8 08              2031 	mov	r0,_bp
   04E5 08                 2032 	inc	r0
   04E6 74 0F              2033 	mov	a,#0x0F
   04E8 55 27              2034 	anl	a,0x0005 + _telegramm
   04EA F6                 2035 	mov	@r0,a
                           2036 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:112: set_timer1(18780);			// Warten bis Bus frei ist
                           2037 ;	genCall
                           2038 ;	Peephole 182.b	used 16 bit load of dptr
   04EB 90 49 5C           2039 	mov	dptr,#0x495C
   04EE C0 02              2040 	push	ar2
   04F0 C0 03              2041 	push	ar3
   04F2 12 02 B7           2042 	lcall	_set_timer1
   04F5 D0 03              2043 	pop	ar3
   04F7 D0 02              2044 	pop	ar2
                           2045 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:113: while(!TF1)
   04F9                    2046 00103$:
                           2047 ;	genIfx
                           2048 ;	genIfxJump
                           2049 ;	Peephole 108.e	removed ljmp by inverse jump logic
   04F9 20 8F 13           2050 	jb	_TCON_7,00105$
                           2051 ;	Peephole 300	removed redundant label 00125$
                           2052 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:115: if(!FBINC) set_timer1(18780);
                           2053 ;	genIfx
                           2054 ;	genIfxJump
                           2055 ;	Peephole 108.e	removed ljmp by inverse jump logic
   04FC 20 94 FA           2056 	jb	_P1_4,00103$
                           2057 ;	Peephole 300	removed redundant label 00126$
                           2058 ;	genCall
                           2059 ;	Peephole 182.b	used 16 bit load of dptr
   04FF 90 49 5C           2060 	mov	dptr,#0x495C
   0502 C0 02              2061 	push	ar2
   0504 C0 03              2062 	push	ar3
   0506 12 02 B7           2063 	lcall	_set_timer1
   0509 D0 03              2064 	pop	ar3
   050B D0 02              2065 	pop	ar2
                           2066 ;	Peephole 112.b	changed ljmp to sjmp
   050D 80 EA              2067 	sjmp	00103$
   050F                    2068 00105$:
                           2069 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:117: TR1=0;
                           2070 ;	genAssign
   050F C2 8E              2071 	clr	_TCON_6
                           2072 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:119: for(l=0;l<=data_laenge+6;l++)
                           2073 ;	genAssign
   0511 7D 00              2074 	mov	r5,#0x00
   0513                    2075 00111$:
                           2076 ;	genIpush
   0513 C0 02              2077 	push	ar2
                           2078 ;	genCast
   0515 A8 08              2079 	mov	r0,_bp
   0517 08                 2080 	inc	r0
   0518 86 06              2081 	mov	ar6,@r0
   051A 7F 00              2082 	mov	r7,#0x00
                           2083 ;	genPlus
                           2084 ;     genPlusIncr
   051C 74 06              2085 	mov	a,#0x06
                           2086 ;	Peephole 236.a	used r6 instead of ar6
   051E 2E                 2087 	add	a,r6
   051F FE                 2088 	mov	r6,a
                           2089 ;	Peephole 181	changed mov to clr
   0520 E4                 2090 	clr	a
                           2091 ;	Peephole 236.b	used r7 instead of ar7
   0521 3F                 2092 	addc	a,r7
   0522 FF                 2093 	mov	r7,a
                           2094 ;	genCast
   0523 8D 02              2095 	mov	ar2,r5
   0525 7C 00              2096 	mov	r4,#0x00
                           2097 ;	genCmpGt
                           2098 ;	genCmp
   0527 C3                 2099 	clr	c
   0528 EE                 2100 	mov	a,r6
   0529 9A                 2101 	subb	a,r2
   052A EF                 2102 	mov	a,r7
   052B 64 80              2103 	xrl	a,#0x80
   052D 8C F0              2104 	mov	b,r4
   052F 63 F0 80           2105 	xrl	b,#0x80
   0532 95 F0              2106 	subb	a,b
                           2107 ;	genIpop
                           2108 ;	genIfx
                           2109 ;	genIfxJump
                           2110 ;	Peephole 108.b	removed ljmp by inverse jump logic
                           2111 ;	Peephole 129.b	optimized condition
   0534 D0 02              2112 	pop	ar2
   0536 40 35              2113 	jc	00114$
                           2114 ;	Peephole 300	removed redundant label 00127$
                           2115 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:121: sendbyte(telegramm[l]);
                           2116 ;	genPlus
                           2117 ;	Peephole 236.g	used r5 instead of ar5
   0538 ED                 2118 	mov	a,r5
   0539 24 22              2119 	add	a,#_telegramm
   053B F8                 2120 	mov	r0,a
                           2121 ;	genPointerGet
                           2122 ;	genNearPointerGet
   053C 86 82              2123 	mov	dpl,@r0
                           2124 ;	genCall
   053E C0 02              2125 	push	ar2
   0540 C0 03              2126 	push	ar3
   0542 C0 05              2127 	push	ar5
   0544 12 01 CF           2128 	lcall	_sendbyte
   0547 D0 05              2129 	pop	ar5
   0549 D0 03              2130 	pop	ar3
   054B D0 02              2131 	pop	ar2
   054D E4                 2132 	clr	a
   054E 33                 2133 	rlc	a
                           2134 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:122: checksum^=telegramm[l];
                           2135 ;	genPlus
                           2136 ;	Peephole 236.g	used r5 instead of ar5
   054F ED                 2137 	mov	a,r5
   0550 24 22              2138 	add	a,#_telegramm
   0552 F8                 2139 	mov	r0,a
                           2140 ;	genPointerGet
                           2141 ;	genNearPointerGet
   0553 86 04              2142 	mov	ar4,@r0
                           2143 ;	genXor
   0555 EC                 2144 	mov	a,r4
   0556 62 03              2145 	xrl	ar3,a
                           2146 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:123: delay(1230);			// Interbyte-Abstand
                           2147 ;	genCall
                           2148 ;	Peephole 182.b	used 16 bit load of dptr
   0558 90 04 CE           2149 	mov	dptr,#0x04CE
   055B C0 02              2150 	push	ar2
   055D C0 03              2151 	push	ar3
   055F C0 05              2152 	push	ar5
   0561 12 02 9A           2153 	lcall	_delay
   0564 D0 05              2154 	pop	ar5
   0566 D0 03              2155 	pop	ar3
   0568 D0 02              2156 	pop	ar2
                           2157 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:119: for(l=0;l<=data_laenge+6;l++)
                           2158 ;	genPlus
                           2159 ;     genPlusIncr
   056A 0D                 2160 	inc	r5
                           2161 ;	Peephole 112.b	changed ljmp to sjmp
   056B 80 A6              2162 	sjmp	00111$
   056D                    2163 00114$:
                           2164 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:125: checksum=~checksum;
                           2165 ;	genCpl
   056D EB                 2166 	mov	a,r3
   056E F4                 2167 	cpl	a
                           2168 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:126: sendbyte(checksum);
                           2169 ;	genCall
   056F FB                 2170 	mov	r3,a
                           2171 ;	Peephole 244.c	loading dpl from a instead of r3
   0570 F5 82              2172 	mov	dpl,a
   0572 C0 02              2173 	push	ar2
   0574 12 01 CF           2174 	lcall	_sendbyte
   0577 D0 02              2175 	pop	ar2
   0579 E4                 2176 	clr	a
   057A 33                 2177 	rlc	a
                           2178 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:127: if(get_ack()==1) r=3;		// wenn ACK empfangen, dann nicht nochmal senden
                           2179 ;	genCall
   057B C0 02              2180 	push	ar2
   057D 12 04 A1           2181 	lcall	_get_ack
   0580 AB 82              2182 	mov	r3,dpl
   0582 D0 02              2183 	pop	ar2
                           2184 ;	genCmpEq
                           2185 ;	gencjneshort
                           2186 ;	Peephole 112.b	changed ljmp to sjmp
                           2187 ;	Peephole 198.b	optimized misc jump sequence
   0584 BB 01 02           2188 	cjne	r3,#0x01,00107$
                           2189 ;	Peephole 200.b	removed redundant sjmp
                           2190 ;	Peephole 300	removed redundant label 00128$
                           2191 ;	Peephole 300	removed redundant label 00129$
                           2192 ;	genAssign
   0587 7A 03              2193 	mov	r2,#0x03
   0589                    2194 00107$:
                           2195 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:128: r++;
                           2196 ;	genPlus
                           2197 ;     genPlusIncr
   0589 0A                 2198 	inc	r2
                           2199 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:129: telegramm[0]&=0xDF;			// Bit 5 löschen = Wiederholung
                           2200 ;	genAssign
                           2201 ;	genAnd
   058A 74 DF              2202 	mov	a,#0xDF
   058C 55 22              2203 	anl	a,_telegramm
                           2204 ;	genPointerSet
                           2205 ;	genNearPointerSet
                           2206 ;	genDataPointerSet
   058E F5 22              2207 	mov	_telegramm,a
                           2208 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:131: while(r<=3); 				// falls kein ACK max. 3 Mal wiederholen
                           2209 ;	genCmpGt
                           2210 ;	genCmp
                           2211 ;	genIfxJump
                           2212 ;	Peephole 132.c	optimized genCmpGt by inverse logic (acc differs)
   0590 EA                 2213 	mov	a,r2
   0591 24 FC              2214 	add	a,#0xff - 0x03
   0593 40 03              2215 	jc	00130$
   0595 02 04 E1           2216 	ljmp	00108$
   0598                    2217 00130$:
                           2218 ;	Peephole 300	removed redundant label 00115$
   0598 85 08 81           2219 	mov	sp,_bp
   059B D0 08              2220 	pop	_bp
   059D 22                 2221 	ret
                           2222 ;------------------------------------------------------------
                           2223 ;Allocation info for local variables in function 'send_ack'
                           2224 ;------------------------------------------------------------
                           2225 ;------------------------------------------------------------
                           2226 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:135: void send_ack(void)			// wartet auf Timer 1 wegen korrekter Positionierung und sendet ACK (0xCC)
                           2227 ;	-----------------------------------------
                           2228 ;	 function send_ack
                           2229 ;	-----------------------------------------
   059E                    2230 _send_ack:
                           2231 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:137: while(!TF1) {}
   059E                    2232 00101$:
                           2233 ;	genIfx
                           2234 ;	genIfxJump
                           2235 ;	Peephole 108.d	removed ljmp by inverse jump logic
   059E 30 8F FD           2236 	jnb	_TCON_7,00101$
                           2237 ;	Peephole 300	removed redundant label 00108$
                           2238 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:138: sendbyte(0xCC);
                           2239 ;	genCall
   05A1 75 82 CC           2240 	mov	dpl,#0xCC
   05A4 12 01 CF           2241 	lcall	_sendbyte
   05A7 E4                 2242 	clr	a
   05A8 33                 2243 	rlc	a
                           2244 ;	Peephole 300	removed redundant label 00104$
   05A9 22                 2245 	ret
                           2246 ;------------------------------------------------------------
                           2247 ;Allocation info for local variables in function 'ucd_opr'
                           2248 ;------------------------------------------------------------
                           2249 ;------------------------------------------------------------
                           2250 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:145: void ucd_opr(void)		// UCD Verbindungsaufbau
                           2251 ;	-----------------------------------------
                           2252 ;	 function ucd_opr
                           2253 ;	-----------------------------------------
   05AA                    2254 _ucd_opr:
                           2255 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:147: if(!connected)		// wenn bereits verbunden: ignorieren
                           2256 ;	genIfx
                           2257 ;	genIfxJump
                           2258 ;	Peephole 108.e	removed ljmp by inverse jump logic
   05AA 20 02 0E           2259 	jb	_connected,00103$
                           2260 ;	Peephole 300	removed redundant label 00106$
                           2261 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:149: connected=1;
                           2262 ;	genAssign
   05AD D2 02              2263 	setb	_connected
                           2264 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:150: conh=telegramm[1];		// phys. Adresse des Verbindungspartners
                           2265 ;	genPointerGet
                           2266 ;	genNearPointerGet
                           2267 ;	genDataPointerGet
   05AF 85 23 3E           2268 	mov	_conh,(_telegramm + 0x0001)
                           2269 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:151: conl=telegramm[2];
                           2270 ;	genPointerGet
                           2271 ;	genNearPointerGet
                           2272 ;	genDataPointerGet
   05B2 85 24 3F           2273 	mov	_conl,(_telegramm + 0x0002)
                           2274 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:152: send_ack();			// quittieren
                           2275 ;	genCall
   05B5 12 05 9E           2276 	lcall	_send_ack
                           2277 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:153: pcount=1;			// Paketzähler zurücksetzen
                           2278 ;	genAssign
   05B8 75 40 01           2279 	mov	_pcount,#0x01
   05BB                    2280 00103$:
   05BB 22                 2281 	ret
                           2282 ;------------------------------------------------------------
                           2283 ;Allocation info for local variables in function 'ucd_clr'
                           2284 ;------------------------------------------------------------
                           2285 ;------------------------------------------------------------
                           2286 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:158: void ucd_clr(void)		// UCD Verbindungsabbau
                           2287 ;	-----------------------------------------
                           2288 ;	 function ucd_clr
                           2289 ;	-----------------------------------------
   05BC                    2290 _ucd_clr:
                           2291 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:160: if(conh==telegramm[1] && conl==telegramm[2] && connected)	// nur abbauen, wenn verbunden und Anforderung vom Verbindungspartner, kein ACK senden
                           2292 ;	genAssign
                           2293 ;	genCmpEq
                           2294 ;	gencjneshort
   05BC E5 3E              2295 	mov	a,_conh
   05BE B5 23 02           2296 	cjne	a,0x0001 + _telegramm,00110$
   05C1 80 01              2297 	sjmp	00111$
   05C3                    2298 00110$:
                           2299 ;	Peephole 112.b	changed ljmp to sjmp
                           2300 ;	Peephole 251.b	replaced sjmp to ret with ret
   05C3 22                 2301 	ret
   05C4                    2302 00111$:
                           2303 ;	genAssign
                           2304 ;	genCmpEq
                           2305 ;	gencjneshort
   05C4 E5 3F              2306 	mov	a,_conl
   05C6 B5 24 02           2307 	cjne	a,0x0002 + _telegramm,00112$
   05C9 80 01              2308 	sjmp	00113$
   05CB                    2309 00112$:
                           2310 ;	Peephole 112.b	changed ljmp to sjmp
                           2311 ;	Peephole 251.b	replaced sjmp to ret with ret
   05CB 22                 2312 	ret
   05CC                    2313 00113$:
                           2314 ;	genIfx
                           2315 ;	genIfxJump
                           2316 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           2317 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:162: connected=0;
                           2318 ;	genAssign
                           2319 ;	Peephole 250.a	using atomic test and clear
   05CC 10 02 01           2320 	jbc	_connected,00114$
                           2321 ;	Peephole 251.b	replaced sjmp to ret with ret
   05CF 22                 2322 	ret
   05D0                    2323 00114$:
                           2324 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:163: pcount=1;			// Paketzähler zurücksetzen
                           2325 ;	genAssign
   05D0 75 40 01           2326 	mov	_pcount,#0x01
                           2327 ;	Peephole 300	removed redundant label 00105$
   05D3 22                 2328 	ret
                           2329 ;------------------------------------------------------------
                           2330 ;Allocation info for local variables in function 'ncd_quit'
                           2331 ;------------------------------------------------------------
                           2332 ;------------------------------------------------------------
                           2333 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:168: void ncd_quit(void)			// NCD Quittierung zurück senden. Setzt telegramm Bytes 0 bis 6 !!!
                           2334 ;	-----------------------------------------
                           2335 ;	 function ncd_quit
                           2336 ;	-----------------------------------------
   05D4                    2337 _ncd_quit:
                           2338 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:170: telegramm[0]=0xB0;			// Control Byte			
                           2339 ;	genPointerSet
                           2340 ;	genNearPointerSet
                           2341 ;	genDataPointerSet
   05D4 75 22 B0           2342 	mov	_telegramm,#0xB0
                           2343 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:171: telegramm[3]=telegramm[1];		// Zieladresse wird Quelladresse
                           2344 ;	genPointerGet
                           2345 ;	genNearPointerGet
                           2346 ;	genDataPointerGet
   05D7 AA 23              2347 	mov	r2,(_telegramm + 0x0001)
                           2348 ;	genPointerSet
                           2349 ;	genNearPointerSet
                           2350 ;	genDataPointerSet
   05D9 8A 25              2351 	mov	(_telegramm + 0x0003),r2
                           2352 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:172: telegramm[4]=telegramm[2];
                           2353 ;	genPointerGet
                           2354 ;	genNearPointerGet
                           2355 ;	genDataPointerGet
   05DB AA 24              2356 	mov	r2,(_telegramm + 0x0002)
                           2357 ;	genPointerSet
                           2358 ;	genNearPointerSet
                           2359 ;	genDataPointerSet
   05DD 8A 26              2360 	mov	(_telegramm + 0x0004),r2
                           2361 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:173: telegramm[1]=pah;			// Quelladresse ist phys. Adresse
                           2362 ;	genPointerSet
                           2363 ;	genNearPointerSet
                           2364 ;	genDataPointerSet
   05DF 85 3C 23           2365 	mov	(_telegramm + 0x0001),_pah
                           2366 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:174: telegramm[2]=pal;
                           2367 ;	genPointerSet
                           2368 ;	genNearPointerSet
                           2369 ;	genDataPointerSet
   05E2 85 3B 24           2370 	mov	(_telegramm + 0x0002),_pal
                           2371 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:175: telegramm[5]=0x60;			// DRL
                           2372 ;	genPointerSet
                           2373 ;	genNearPointerSet
                           2374 ;	genDataPointerSet
   05E5 75 27 60           2375 	mov	(_telegramm + 0x0005),#0x60
                           2376 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:176: telegramm[6]|=0xC0;			// Bit 6 und 7 setzen (TCPI = 11 NCD Quittierung)
                           2377 ;	genAssign
                           2378 ;	genOr
   05E8 74 C0              2379 	mov	a,#0xC0
   05EA 45 28              2380 	orl	a,0x0006 + _telegramm
   05EC FA                 2381 	mov	r2,a
                           2382 ;	genPointerSet
                           2383 ;	genNearPointerSet
                           2384 ;	genDataPointerSet
   05ED 8A 28              2385 	mov	(_telegramm + 0x0006),r2
                           2386 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:177: telegramm[6]&=0xFE;			// Bit 0 löschen 
                           2387 ;	genAnd
   05EF 74 FE              2388 	mov	a,#0xFE
   05F1 5A                 2389 	anl	a,r2
                           2390 ;	genPointerSet
                           2391 ;	genNearPointerSet
                           2392 ;	genDataPointerSet
   05F2 F5 28              2393 	mov	(_telegramm + 0x0006),a
                           2394 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:178: send_telegramm();
                           2395 ;	genCall
                           2396 ;	Peephole 253.b	replaced lcall/ret with ljmp
   05F4 02 04 D8           2397 	ljmp	_send_telegramm
                           2398 ;
                           2399 ;------------------------------------------------------------
                           2400 ;Allocation info for local variables in function 'read_masq'
                           2401 ;------------------------------------------------------------
                           2402 ;------------------------------------------------------------
                           2403 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:182: void read_masq(void)			// Maskenversion senden
                           2404 ;	-----------------------------------------
                           2405 ;	 function read_masq
                           2406 ;	-----------------------------------------
   05F7                    2407 _read_masq:
                           2408 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:186: send_ack();
                           2409 ;	genCall
   05F7 12 05 9E           2410 	lcall	_send_ack
                           2411 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:187: ncd_quit();				// NCD Quittierung senden
                           2412 ;	genCall
   05FA 12 05 D4           2413 	lcall	_ncd_quit
                           2414 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:189: telegramm[0]=0xB0;			// Control Byte
                           2415 ;	genPointerSet
                           2416 ;	genNearPointerSet
                           2417 ;	genDataPointerSet
   05FD 75 22 B0           2418 	mov	_telegramm,#0xB0
                           2419 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:191: telegramm[5]=0x63;			// DRL
                           2420 ;	genPointerSet
                           2421 ;	genNearPointerSet
                           2422 ;	genDataPointerSet
   0600 75 27 63           2423 	mov	(_telegramm + 0x0005),#0x63
                           2424 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:192: telegramm[6]=0x43;
                           2425 ;	genPointerSet
                           2426 ;	genNearPointerSet
                           2427 ;	genDataPointerSet
   0603 75 28 43           2428 	mov	(_telegramm + 0x0006),#0x43
                           2429 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:193: telegramm[7]=0x40;
                           2430 ;	genPointerSet
                           2431 ;	genNearPointerSet
                           2432 ;	genDataPointerSet
   0606 75 29 40           2433 	mov	(_telegramm + 0x0007),#0x40
                           2434 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:194: telegramm[8]=0x00;
                           2435 ;	genPointerSet
                           2436 ;	genNearPointerSet
                           2437 ;	genDataPointerSet
   0609 75 2A 00           2438 	mov	(_telegramm + 0x0008),#0x00
                           2439 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:195: telegramm[9]=0x12;			// Maskenversion 1 = BCU1
                           2440 ;	genPointerSet
                           2441 ;	genNearPointerSet
                           2442 ;	genDataPointerSet
   060C 75 2B 12           2443 	mov	(_telegramm + 0x0009),#0x12
                           2444 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:196: send_telegramm();
                           2445 ;	genCall
                           2446 ;	Peephole 253.b	replaced lcall/ret with ljmp
   060F 02 04 D8           2447 	ljmp	_send_telegramm
                           2448 ;
                           2449 ;------------------------------------------------------------
                           2450 ;Allocation info for local variables in function 'read_memory'
                           2451 ;------------------------------------------------------------
                           2452 ;ab                        Allocated to registers r2 
                           2453 ;n                         Allocated to registers r3 
                           2454 ;------------------------------------------------------------
                           2455 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:201: void read_memory(void)			// read_memory_request - Speicher auslesen und senden
                           2456 ;	-----------------------------------------
                           2457 ;	 function read_memory
                           2458 ;	-----------------------------------------
   0612                    2459 _read_memory:
                           2460 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:205: send_ack();				// erstmal quittieren
                           2461 ;	genCall
   0612 12 05 9E           2462 	lcall	_send_ack
                           2463 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:206: ab=telegramm[7];			// Anzahl Bytes
                           2464 ;	genAssign
                           2465 ;	genAssign
   0615 AA 29              2466 	mov	r2,0x0007 + _telegramm
                           2467 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:207: ncd_quit();
                           2468 ;	genCall
   0617 C0 02              2469 	push	ar2
   0619 12 05 D4           2470 	lcall	_ncd_quit
   061C D0 02              2471 	pop	ar2
                           2472 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:209: for(n=0;n<ab;n++)
                           2473 ;	genAssign
   061E 7B 00              2474 	mov	r3,#0x00
   0620                    2475 00101$:
                           2476 ;	genCmpLt
                           2477 ;	genCmp
   0620 C3                 2478 	clr	c
   0621 EB                 2479 	mov	a,r3
   0622 9A                 2480 	subb	a,r2
                           2481 ;	genIfxJump
                           2482 ;	Peephole 108.a	removed ljmp by inverse jump logic
   0623 50 27              2483 	jnc	00104$
                           2484 ;	Peephole 300	removed redundant label 00110$
                           2485 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:211: telegramm[n+10]=read_byte(telegramm[8],(telegramm[9]+n));    
                           2486 ;	genPlus
                           2487 ;     genPlusIncr
   0625 74 0A              2488 	mov	a,#0x0A
                           2489 ;	Peephole 236.a	used r3 instead of ar3
   0627 2B                 2490 	add	a,r3
                           2491 ;	genPlus
   0628 24 22              2492 	add	a,#_telegramm
   062A F8                 2493 	mov	r0,a
                           2494 ;	genAssign
                           2495 ;	genPlus
                           2496 ;	Peephole 236.g	used r3 instead of ar3
   062B EB                 2497 	mov	a,r3
   062C 25 2B              2498 	add	a,0x0009 + _telegramm
   062E FC                 2499 	mov	r4,a
                           2500 ;	genAssign
                           2501 ;	genIpush
   062F C0 02              2502 	push	ar2
   0631 C0 03              2503 	push	ar3
   0633 C0 00              2504 	push	ar0
   0635 C0 04              2505 	push	ar4
                           2506 ;	genCall
   0637 85 2A 82           2507 	mov	dpl,0x0008 + _telegramm
   063A 12 02 CF           2508 	lcall	_read_byte
   063D AC 82              2509 	mov	r4,dpl
   063F 15 81              2510 	dec	sp
   0641 D0 00              2511 	pop	ar0
   0643 D0 03              2512 	pop	ar3
   0645 D0 02              2513 	pop	ar2
                           2514 ;	genPointerSet
                           2515 ;	genNearPointerSet
   0647 A6 04              2516 	mov	@r0,ar4
                           2517 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:209: for(n=0;n<ab;n++)
                           2518 ;	genPlus
                           2519 ;     genPlusIncr
   0649 0B                 2520 	inc	r3
                           2521 ;	Peephole 112.b	changed ljmp to sjmp
   064A 80 D4              2522 	sjmp	00101$
   064C                    2523 00104$:
                           2524 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:214: telegramm[0]=0xB0;			// read_memory_res senden
                           2525 ;	genPointerSet
                           2526 ;	genNearPointerSet
                           2527 ;	genDataPointerSet
   064C 75 22 B0           2528 	mov	_telegramm,#0xB0
                           2529 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:216: telegramm[5]=ab+0x63;		// DRL (Anzahl Bytes + 3)
                           2530 ;	genPlus
                           2531 ;     genPlusIncr
   064F 74 63              2532 	mov	a,#0x63
                           2533 ;	Peephole 236.a	used r2 instead of ar2
   0651 2A                 2534 	add	a,r2
                           2535 ;	genPointerSet
                           2536 ;	genNearPointerSet
                           2537 ;	genDataPointerSet
   0652 F5 27              2538 	mov	(_telegramm + 0x0005),a
                           2539 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:217: telegramm[6]=(pcount<<2)|0x42;	// Paketzähler, TCPI und ersten beiden Befehlsbits
                           2540 ;	genLeftShift
                           2541 ;	genLeftShiftLiteral
                           2542 ;	genlshOne
   0654 E5 40              2543 	mov	a,_pcount
                           2544 ;	Peephole 254	optimized left shift
   0656 25 40              2545 	add	a,_pcount
   0658 25 E0              2546 	add	a,acc
   065A FB                 2547 	mov	r3,a
                           2548 ;	genOr
   065B 74 42              2549 	mov	a,#0x42
   065D 4B                 2550 	orl	a,r3
                           2551 ;	genPointerSet
                           2552 ;	genNearPointerSet
                           2553 ;	genDataPointerSet
   065E F5 28              2554 	mov	(_telegramm + 0x0006),a
                           2555 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:218: telegramm[7]=ab|0x40;		// letzten 2 Befehlsbits
                           2556 ;	genOr
   0660 74 40              2557 	mov	a,#0x40
   0662 4A                 2558 	orl	a,r2
                           2559 ;	genPointerSet
                           2560 ;	genNearPointerSet
                           2561 ;	genDataPointerSet
   0663 F5 29              2562 	mov	(_telegramm + 0x0007),a
                           2563 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:219: send_telegramm();
                           2564 ;	genCall
   0665 12 04 D8           2565 	lcall	_send_telegramm
                           2566 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:221: pcount++;				// Paketzähler erhöhen
                           2567 ;	genPlus
                           2568 ;     genPlusIncr
   0668 05 40              2569 	inc	_pcount
                           2570 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:222: pcount&=0x0F;				// max. 15
                           2571 ;	genAnd
   066A 53 40 0F           2572 	anl	_pcount,#0x0F
                           2573 ;	Peephole 300	removed redundant label 00105$
   066D 22                 2574 	ret
                           2575 ;------------------------------------------------------------
                           2576 ;Allocation info for local variables in function 'write_memory'
                           2577 ;------------------------------------------------------------
                           2578 ;ab                        Allocated to registers r2 
                           2579 ;n                         Allocated to registers r3 
                           2580 ;------------------------------------------------------------
                           2581 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:226: void write_memory(void)			// write_memory_request - empfangene Daten in Speicher schreiben
                           2582 ;	-----------------------------------------
                           2583 ;	 function write_memory
                           2584 ;	-----------------------------------------
   066E                    2585 _write_memory:
                           2586 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:230: send_ack();
                           2587 ;	genCall
   066E 12 05 9E           2588 	lcall	_send_ack
                           2589 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:231: ab=telegramm[7]&0x0F;			// Anzahl Bytes
                           2590 ;	genAssign
                           2591 ;	genAnd
   0671 74 0F              2592 	mov	a,#0x0F
   0673 55 29              2593 	anl	a,0x0007 + _telegramm
   0675 FA                 2594 	mov	r2,a
                           2595 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:232: ncd_quit();
                           2596 ;	genCall
   0676 C0 02              2597 	push	ar2
   0678 12 05 D4           2598 	lcall	_ncd_quit
   067B D0 02              2599 	pop	ar2
                           2600 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:234: start_writecycle();
                           2601 ;	genCall
   067D C0 02              2602 	push	ar2
   067F 12 02 70           2603 	lcall	_start_writecycle
   0682 D0 02              2604 	pop	ar2
                           2605 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:235: for(n=0;n<ab;n++) 
                           2606 ;	genAssign
   0684 7B 00              2607 	mov	r3,#0x00
   0686                    2608 00104$:
                           2609 ;	genCmpLt
                           2610 ;	genCmp
   0686 C3                 2611 	clr	c
   0687 EB                 2612 	mov	a,r3
   0688 9A                 2613 	subb	a,r2
                           2614 ;	genIfxJump
                           2615 ;	Peephole 108.a	removed ljmp by inverse jump logic
   0689 50 67              2616 	jnc	00107$
                           2617 ;	Peephole 300	removed redundant label 00115$
                           2618 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:237: write_byte(telegramm[8],telegramm[9]+n,telegramm[n+10]);
                           2619 ;	genPlus
                           2620 ;     genPlusIncr
   068B 74 0A              2621 	mov	a,#0x0A
                           2622 ;	Peephole 236.a	used r3 instead of ar3
   068D 2B                 2623 	add	a,r3
                           2624 ;	genPlus
   068E 24 22              2625 	add	a,#_telegramm
   0690 F8                 2626 	mov	r0,a
                           2627 ;	genPointerGet
                           2628 ;	genNearPointerGet
   0691 86 04              2629 	mov	ar4,@r0
                           2630 ;	genAssign
                           2631 ;	genPlus
                           2632 ;	Peephole 236.g	used r3 instead of ar3
   0693 EB                 2633 	mov	a,r3
   0694 25 2B              2634 	add	a,0x0009 + _telegramm
   0696 FD                 2635 	mov	r5,a
                           2636 ;	genAssign
                           2637 ;	genIpush
   0697 C0 02              2638 	push	ar2
   0699 C0 03              2639 	push	ar3
   069B C0 04              2640 	push	ar4
                           2641 ;	genIpush
   069D C0 05              2642 	push	ar5
                           2643 ;	genCall
   069F 85 2A 82           2644 	mov	dpl,0x0008 + _telegramm
   06A2 12 02 78           2645 	lcall	_write_byte
   06A5 15 81              2646 	dec	sp
   06A7 15 81              2647 	dec	sp
   06A9 D0 03              2648 	pop	ar3
   06AB D0 02              2649 	pop	ar2
                           2650 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:238: if ((((telegramm[9]+n)&0x3F)==0x3F) && n!=(ab-1))		// Ende des 64-Byte Pageregisters, also zwischendurch flashen
                           2651 ;	genAssign
                           2652 ;	genCast
   06AD AC 2B              2653 	mov	r4,0x0009 + _telegramm
   06AF 7D 00              2654 	mov	r5,#0x00
                           2655 ;	genCast
   06B1 8B 06              2656 	mov	ar6,r3
   06B3 7F 00              2657 	mov	r7,#0x00
                           2658 ;	genPlus
                           2659 ;	Peephole 236.g	used r6 instead of ar6
   06B5 EE                 2660 	mov	a,r6
                           2661 ;	Peephole 236.a	used r4 instead of ar4
   06B6 2C                 2662 	add	a,r4
   06B7 FC                 2663 	mov	r4,a
                           2664 ;	Peephole 236.g	used r7 instead of ar7
   06B8 EF                 2665 	mov	a,r7
                           2666 ;	Peephole 236.b	used r5 instead of ar5
   06B9 3D                 2667 	addc	a,r5
   06BA FD                 2668 	mov	r5,a
                           2669 ;	genAnd
   06BB 53 04 3F           2670 	anl	ar4,#0x3F
   06BE 7D 00              2671 	mov	r5,#0x00
                           2672 ;	genCmpEq
                           2673 ;	gencjneshort
                           2674 ;	Peephole 112.b	changed ljmp to sjmp
                           2675 ;	Peephole 198.a	optimized misc jump sequence
   06C0 BC 3F 2C           2676 	cjne	r4,#0x3F,00106$
   06C3 BD 00 29           2677 	cjne	r5,#0x00,00106$
                           2678 ;	Peephole 200.b	removed redundant sjmp
                           2679 ;	Peephole 300	removed redundant label 00116$
                           2680 ;	Peephole 300	removed redundant label 00117$
                           2681 ;	genCast
   06C6 8A 04              2682 	mov	ar4,r2
   06C8 7D 00              2683 	mov	r5,#0x00
                           2684 ;	genMinus
                           2685 ;	genMinusDec
   06CA 1C                 2686 	dec	r4
   06CB BC FF 01           2687 	cjne	r4,#0xff,00118$
   06CE 1D                 2688 	dec	r5
   06CF                    2689 00118$:
                           2690 ;	genCmpEq
                           2691 ;	gencjneshort
   06CF EE                 2692 	mov	a,r6
   06D0 B5 04 06           2693 	cjne	a,ar4,00119$
   06D3 EF                 2694 	mov	a,r7
   06D4 B5 05 02           2695 	cjne	a,ar5,00119$
                           2696 ;	Peephole 112.b	changed ljmp to sjmp
   06D7 80 16              2697 	sjmp	00106$
   06D9                    2698 00119$:
                           2699 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:240: stop_writecycle();
                           2700 ;	genCall
   06D9 C0 02              2701 	push	ar2
   06DB C0 03              2702 	push	ar3
   06DD 12 02 74           2703 	lcall	_stop_writecycle
   06E0 D0 03              2704 	pop	ar3
   06E2 D0 02              2705 	pop	ar2
                           2706 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:241: start_writecycle();
                           2707 ;	genCall
   06E4 C0 02              2708 	push	ar2
   06E6 C0 03              2709 	push	ar3
   06E8 12 02 70           2710 	lcall	_start_writecycle
   06EB D0 03              2711 	pop	ar3
   06ED D0 02              2712 	pop	ar2
   06EF                    2713 00106$:
                           2714 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:235: for(n=0;n<ab;n++) 
                           2715 ;	genPlus
                           2716 ;     genPlusIncr
   06EF 0B                 2717 	inc	r3
                           2718 ;	Peephole 112.b	changed ljmp to sjmp
   06F0 80 94              2719 	sjmp	00104$
   06F2                    2720 00107$:
                           2721 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:244: stop_writecycle(); 
                           2722 ;	genCall
                           2723 ;	Peephole 253.b	replaced lcall/ret with ljmp
   06F2 02 02 74           2724 	ljmp	_stop_writecycle
                           2725 ;
                           2726 ;------------------------------------------------------------
                           2727 ;Allocation info for local variables in function 'set_pa'
                           2728 ;------------------------------------------------------------
                           2729 ;------------------------------------------------------------
                           2730 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:248: void set_pa(void)			// neue phys. Adresse programmieren
                           2731 ;	-----------------------------------------
                           2732 ;	 function set_pa
                           2733 ;	-----------------------------------------
   06F5                    2734 _set_pa:
                           2735 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:250: pah=telegramm[8];
                           2736 ;	genPointerGet
                           2737 ;	genNearPointerGet
                           2738 ;	genDataPointerGet
   06F5 85 2A 3C           2739 	mov	_pah,(_telegramm + 0x0008)
                           2740 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:251: pal=telegramm[9];
                           2741 ;	genPointerGet
                           2742 ;	genNearPointerGet
                           2743 ;	genDataPointerGet
   06F8 85 2B 3B           2744 	mov	_pal,(_telegramm + 0x0009)
                           2745 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:252: start_writecycle();
                           2746 ;	genCall
   06FB 12 02 70           2747 	lcall	_start_writecycle
                           2748 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:253: write_byte(0x01,ADDRTAB+1,pah);		// in Flash schreiben
                           2749 ;	genIpush
   06FE C0 3C              2750 	push	_pah
                           2751 ;	genIpush
   0700 74 17              2752 	mov	a,#0x17
   0702 C0 E0              2753 	push	acc
                           2754 ;	genCall
   0704 75 82 01           2755 	mov	dpl,#0x01
   0707 12 02 78           2756 	lcall	_write_byte
   070A 15 81              2757 	dec	sp
   070C 15 81              2758 	dec	sp
                           2759 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:254: write_byte(0x01,ADDRTAB+2,pal);
                           2760 ;	genIpush
   070E C0 3B              2761 	push	_pal
                           2762 ;	genIpush
   0710 74 18              2763 	mov	a,#0x18
   0712 C0 E0              2764 	push	acc
                           2765 ;	genCall
   0714 75 82 01           2766 	mov	dpl,#0x01
   0717 12 02 78           2767 	lcall	_write_byte
   071A 15 81              2768 	dec	sp
   071C 15 81              2769 	dec	sp
                           2770 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:255: stop_writecycle();
                           2771 ;	genCall
                           2772 ;	Peephole 253.b	replaced lcall/ret with ljmp
   071E 02 02 74           2773 	ljmp	_stop_writecycle
                           2774 ;
                           2775 ;------------------------------------------------------------
                           2776 ;Allocation info for local variables in function 'read_pa'
                           2777 ;------------------------------------------------------------
                           2778 ;------------------------------------------------------------
                           2779 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:259: void read_pa(void)			// phys. Adresse senden
                           2780 ;	-----------------------------------------
                           2781 ;	 function read_pa
                           2782 ;	-----------------------------------------
   0721                    2783 _read_pa:
                           2784 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:263: send_ack();
                           2785 ;	genCall
   0721 12 05 9E           2786 	lcall	_send_ack
                           2787 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:265: telegramm[0]=0xB0;			// read_memory_res senden
                           2788 ;	genPointerSet
                           2789 ;	genNearPointerSet
                           2790 ;	genDataPointerSet
   0724 75 22 B0           2791 	mov	_telegramm,#0xB0
                           2792 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:267: telegramm[1]=pah;
                           2793 ;	genPointerSet
                           2794 ;	genNearPointerSet
                           2795 ;	genDataPointerSet
   0727 85 3C 23           2796 	mov	(_telegramm + 0x0001),_pah
                           2797 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:268: telegramm[2]=pal;
                           2798 ;	genPointerSet
                           2799 ;	genNearPointerSet
                           2800 ;	genDataPointerSet
   072A 85 3B 24           2801 	mov	(_telegramm + 0x0002),_pal
                           2802 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:269: telegramm[3]=0x00;
                           2803 ;	genPointerSet
                           2804 ;	genNearPointerSet
                           2805 ;	genDataPointerSet
   072D 75 25 00           2806 	mov	(_telegramm + 0x0003),#0x00
                           2807 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:270: telegramm[4]=0x00;			
                           2808 ;	genPointerSet
                           2809 ;	genNearPointerSet
                           2810 ;	genDataPointerSet
   0730 75 26 00           2811 	mov	(_telegramm + 0x0004),#0x00
                           2812 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:271: telegramm[5]=0xE1;			// DRL
                           2813 ;	genPointerSet
                           2814 ;	genNearPointerSet
                           2815 ;	genDataPointerSet
   0733 75 27 E1           2816 	mov	(_telegramm + 0x0005),#0xE1
                           2817 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:272: telegramm[6]=0x01;		
                           2818 ;	genPointerSet
                           2819 ;	genNearPointerSet
                           2820 ;	genDataPointerSet
   0736 75 28 01           2821 	mov	(_telegramm + 0x0006),#0x01
                           2822 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:273: telegramm[7]=0x40;
                           2823 ;	genPointerSet
                           2824 ;	genNearPointerSet
                           2825 ;	genDataPointerSet
   0739 75 29 40           2826 	mov	(_telegramm + 0x0007),#0x40
                           2827 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:274: send_telegramm();
                           2828 ;	genCall
                           2829 ;	Peephole 253.b	replaced lcall/ret with ljmp
   073C 02 04 D8           2830 	ljmp	_send_telegramm
                           2831 ;
                           2832 ;------------------------------------------------------------
                           2833 ;Allocation info for local variables in function 'read_objflags'
                           2834 ;------------------------------------------------------------
                           2835 ;objno                     Allocated to registers r2 
                           2836 ;ctp                       Allocated to registers 
                           2837 ;addr                      Allocated to registers 
                           2838 ;flags                     Allocated to registers 
                           2839 ;------------------------------------------------------------
                           2840 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:279: unsigned char read_objflags(unsigned char objno)	// Objektflags lesen
                           2841 ;	-----------------------------------------
                           2842 ;	 function read_objflags
                           2843 ;	-----------------------------------------
   073F                    2844 _read_objflags:
                           2845 ;	genReceive
   073F AA 82              2846 	mov	r2,dpl
                           2847 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:283: ctp=read_byte(0x01,COMMSTABPTR);		// COMMSTAB Pointer
                           2848 ;	genIpush
   0741 C0 02              2849 	push	ar2
   0743 74 12              2850 	mov	a,#0x12
   0745 C0 E0              2851 	push	acc
                           2852 ;	genCall
   0747 75 82 01           2853 	mov	dpl,#0x01
   074A 12 02 CF           2854 	lcall	_read_byte
   074D AB 82              2855 	mov	r3,dpl
   074F 15 81              2856 	dec	sp
   0751 D0 02              2857 	pop	ar2
                           2858 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:284: addr=ctp+3+3*objno;
                           2859 ;	genPlus
                           2860 ;     genPlusIncr
   0753 0B                 2861 	inc	r3
   0754 0B                 2862 	inc	r3
   0755 0B                 2863 	inc	r3
                           2864 ;	genMult
                           2865 ;	genMultOneByte
   0756 EA                 2866 	mov	a,r2
   0757 75 F0 03           2867 	mov	b,#0x03
   075A A4                 2868 	mul	ab
                           2869 ;	genPlus
   075B FA                 2870 	mov	r2,a
                           2871 ;	Peephole 177.b	removed redundant mov
                           2872 ;	Peephole 236.a	used r3 instead of ar3
   075C 2B                 2873 	add	a,r3
   075D FB                 2874 	mov	r3,a
                           2875 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:285: flags=read_byte(0x01,addr);	// Objektflags
                           2876 ;	genIpush
   075E C0 03              2877 	push	ar3
                           2878 ;	genCall
   0760 75 82 01           2879 	mov	dpl,#0x01
   0763 12 02 CF           2880 	lcall	_read_byte
   0766 AA 82              2881 	mov	r2,dpl
   0768 15 81              2882 	dec	sp
                           2883 ;	genAssign
   076A 8A 82              2884 	mov	dpl,r2
                           2885 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:286: return(flags);
                           2886 ;	genRet
                           2887 ;	Peephole 300	removed redundant label 00101$
   076C 22                 2888 	ret
                           2889 ;------------------------------------------------------------
                           2890 ;Allocation info for local variables in function 'find_ga'
                           2891 ;------------------------------------------------------------
                           2892 ;objno                     Allocated to registers r2 
                           2893 ;n                         Allocated to registers r7 
                           2894 ;assno                     Allocated to registers r5 
                           2895 ;asstab                    Allocated to registers r4 
                           2896 ;gapos                     Allocated to registers r3 
                           2897 ;gal                       Allocated to registers r3 
                           2898 ;gah                       Allocated to registers r2 
                           2899 ;ga                        Allocated to registers r3 r2 
                           2900 ;sloc0                     Allocated to stack - offset 1
                           2901 ;------------------------------------------------------------
                           2902 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:290: int find_ga(unsigned char objno)		// Gruppenadresse über Assoziationstabelle finden (letzter Eintrag, falls mehrere)
                           2903 ;	-----------------------------------------
                           2904 ;	 function find_ga
                           2905 ;	-----------------------------------------
   076D                    2906 _find_ga:
   076D C0 08              2907 	push	_bp
   076F 85 81 08           2908 	mov	_bp,sp
   0772 05 81              2909 	inc	sp
                           2910 ;	genReceive
   0774 AA 82              2911 	mov	r2,dpl
                           2912 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:295: gapos=0;
                           2913 ;	genAssign
   0776 7B 00              2914 	mov	r3,#0x00
                           2915 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:296: asstab=read_byte(0x01,ASSOCTABPTR);
                           2916 ;	genIpush
   0778 C0 02              2917 	push	ar2
   077A C0 03              2918 	push	ar3
   077C 74 11              2919 	mov	a,#0x11
   077E C0 E0              2920 	push	acc
                           2921 ;	genCall
   0780 75 82 01           2922 	mov	dpl,#0x01
   0783 12 02 CF           2923 	lcall	_read_byte
   0786 AC 82              2924 	mov	r4,dpl
   0788 15 81              2925 	dec	sp
   078A D0 03              2926 	pop	ar3
   078C D0 02              2927 	pop	ar2
                           2928 ;	genAssign
                           2929 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:297: assno=read_byte(0x01,asstab);
                           2930 ;	genIpush
   078E C0 02              2931 	push	ar2
   0790 C0 03              2932 	push	ar3
   0792 C0 04              2933 	push	ar4
   0794 C0 04              2934 	push	ar4
                           2935 ;	genCall
   0796 75 82 01           2936 	mov	dpl,#0x01
   0799 12 02 CF           2937 	lcall	_read_byte
   079C AD 82              2938 	mov	r5,dpl
   079E 15 81              2939 	dec	sp
   07A0 D0 04              2940 	pop	ar4
   07A2 D0 03              2941 	pop	ar3
   07A4 D0 02              2942 	pop	ar2
                           2943 ;	genAssign
                           2944 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:298: for(n=0;n<assno;n++)
                           2945 ;	genPlus
                           2946 ;     genPlusIncr
   07A6 74 01              2947 	mov	a,#0x01
                           2948 ;	Peephole 236.a	used r4 instead of ar4
   07A8 2C                 2949 	add	a,r4
   07A9 FE                 2950 	mov	r6,a
                           2951 ;	genPlus
                           2952 ;     genPlusIncr
   07AA 0C                 2953 	inc	r4
   07AB 0C                 2954 	inc	r4
                           2955 ;	genAssign
   07AC 7F 00              2956 	mov	r7,#0x00
   07AE                    2957 00106$:
                           2958 ;	genCmpLt
                           2959 ;	genCmp
   07AE C3                 2960 	clr	c
   07AF EF                 2961 	mov	a,r7
   07B0 9D                 2962 	subb	a,r5
                           2963 ;	genIfxJump
                           2964 ;	Peephole 108.a	removed ljmp by inverse jump logic
   07B1 50 66              2965 	jnc	00109$
                           2966 ;	Peephole 300	removed redundant label 00117$
                           2967 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:300: if(read_byte(0x01,asstab+2+2*n)==objno)
                           2968 ;	genIpush
   07B3 C0 03              2969 	push	ar3
                           2970 ;	genLeftShift
                           2971 ;	genLeftShiftLiteral
   07B5 A8 08              2972 	mov	r0,_bp
   07B7 08                 2973 	inc	r0
                           2974 ;	genlshOne
   07B8 EF                 2975 	mov	a,r7
                           2976 ;	Peephole 254	optimized left shift
   07B9 2F                 2977 	add	a,r7
   07BA F6                 2978 	mov	@r0,a
                           2979 ;	genPlus
   07BB A8 08              2980 	mov	r0,_bp
   07BD 08                 2981 	inc	r0
   07BE E6                 2982 	mov	a,@r0
                           2983 ;	Peephole 236.a	used r4 instead of ar4
   07BF 2C                 2984 	add	a,r4
   07C0 FB                 2985 	mov	r3,a
                           2986 ;	genIpush
   07C1 C0 02              2987 	push	ar2
   07C3 C0 04              2988 	push	ar4
   07C5 C0 05              2989 	push	ar5
   07C7 C0 06              2990 	push	ar6
   07C9 C0 07              2991 	push	ar7
   07CB C0 03              2992 	push	ar3
                           2993 ;	genCall
   07CD 75 82 01           2994 	mov	dpl,#0x01
   07D0 12 02 CF           2995 	lcall	_read_byte
   07D3 AB 82              2996 	mov	r3,dpl
   07D5 15 81              2997 	dec	sp
   07D7 D0 07              2998 	pop	ar7
   07D9 D0 06              2999 	pop	ar6
   07DB D0 05              3000 	pop	ar5
   07DD D0 04              3001 	pop	ar4
   07DF D0 02              3002 	pop	ar2
                           3003 ;	genCmpEq
                           3004 ;	gencjne
                           3005 ;	gencjneshort
   07E1 EB                 3006 	mov	a,r3
   07E2 B5 02 04           3007 	cjne	a,ar2,00118$
   07E5 74 01              3008 	mov	a,#0x01
   07E7 80 01              3009 	sjmp	00119$
   07E9                    3010 00118$:
   07E9 E4                 3011 	clr	a
   07EA                    3012 00119$:
                           3013 ;	genIpop
   07EA D0 03              3014 	pop	ar3
                           3015 ;	genIfx
                           3016 ;	genIfxJump
                           3017 ;	Peephole 108.c	removed ljmp by inverse jump logic
   07EC 60 28              3018 	jz	00108$
                           3019 ;	Peephole 300	removed redundant label 00120$
                           3020 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:302: gapos=read_byte(0x01,asstab+1+2*n);
                           3021 ;	genIpush
   07EE C0 04              3022 	push	ar4
                           3023 ;	genPlus
   07F0 A8 08              3024 	mov	r0,_bp
   07F2 08                 3025 	inc	r0
   07F3 E6                 3026 	mov	a,@r0
                           3027 ;	Peephole 236.a	used r6 instead of ar6
   07F4 2E                 3028 	add	a,r6
   07F5 FC                 3029 	mov	r4,a
                           3030 ;	genIpush
   07F6 C0 02              3031 	push	ar2
   07F8 C0 05              3032 	push	ar5
   07FA C0 06              3033 	push	ar6
   07FC C0 07              3034 	push	ar7
   07FE C0 04              3035 	push	ar4
                           3036 ;	genCall
   0800 75 82 01           3037 	mov	dpl,#0x01
   0803 12 02 CF           3038 	lcall	_read_byte
   0806 AC 82              3039 	mov	r4,dpl
   0808 15 81              3040 	dec	sp
   080A D0 07              3041 	pop	ar7
   080C D0 06              3042 	pop	ar6
   080E D0 05              3043 	pop	ar5
   0810 D0 02              3044 	pop	ar2
                           3045 ;	genAssign
   0812 8C 03              3046 	mov	ar3,r4
                           3047 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:315: return(ga);
                           3048 ;	genIpop
   0814 D0 04              3049 	pop	ar4
                           3050 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:302: gapos=read_byte(0x01,asstab+1+2*n);
   0816                    3051 00108$:
                           3052 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:298: for(n=0;n<assno;n++)
                           3053 ;	genPlus
                           3054 ;     genPlusIncr
   0816 0F                 3055 	inc	r7
                           3056 ;	Peephole 112.b	changed ljmp to sjmp
   0817 80 95              3057 	sjmp	00106$
   0819                    3058 00109$:
                           3059 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:305: if(gapos!=0)
                           3060 ;	genCmpEq
                           3061 ;	gencjneshort
   0819 BB 00 02           3062 	cjne	r3,#0x00,00121$
                           3063 ;	Peephole 112.b	changed ljmp to sjmp
   081C 80 3B              3064 	sjmp	00104$
   081E                    3065 00121$:
                           3066 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:307: gah=read_byte(0x01,ADDRTAB+1+gapos*2);
                           3067 ;	genLeftShift
                           3068 ;	genLeftShiftLiteral
                           3069 ;	genlshOne
   081E EB                 3070 	mov	a,r3
                           3071 ;	Peephole 254	optimized left shift
   081F 2B                 3072 	add	a,r3
   0820 FB                 3073 	mov	r3,a
                           3074 ;	genPlus
                           3075 ;     genPlusIncr
   0821 74 17              3076 	mov	a,#0x17
                           3077 ;	Peephole 236.a	used r3 instead of ar3
   0823 2B                 3078 	add	a,r3
   0824 FA                 3079 	mov	r2,a
                           3080 ;	genIpush
   0825 C0 03              3081 	push	ar3
   0827 C0 02              3082 	push	ar2
                           3083 ;	genCall
   0829 75 82 01           3084 	mov	dpl,#0x01
   082C 12 02 CF           3085 	lcall	_read_byte
   082F AA 82              3086 	mov	r2,dpl
   0831 15 81              3087 	dec	sp
   0833 D0 03              3088 	pop	ar3
                           3089 ;	genAssign
                           3090 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:308: gal=read_byte(0x01,ADDRTAB+2+gapos*2);
                           3091 ;	genPlus
                           3092 ;     genPlusIncr
   0835 74 18              3093 	mov	a,#0x18
                           3094 ;	Peephole 236.a	used r3 instead of ar3
   0837 2B                 3095 	add	a,r3
   0838 FB                 3096 	mov	r3,a
                           3097 ;	genIpush
   0839 C0 02              3098 	push	ar2
   083B C0 03              3099 	push	ar3
                           3100 ;	genCall
   083D 75 82 01           3101 	mov	dpl,#0x01
   0840 12 02 CF           3102 	lcall	_read_byte
   0843 AB 82              3103 	mov	r3,dpl
   0845 15 81              3104 	dec	sp
   0847 D0 02              3105 	pop	ar2
                           3106 ;	genAssign
                           3107 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:309: ga=gal+256*gah;
                           3108 ;	genCast
   0849 7C 00              3109 	mov	r4,#0x00
                           3110 ;	genCast
                           3111 ;	genLeftShift
                           3112 ;	genLeftShiftLiteral
                           3113 ;	genlshTwo
                           3114 ;	peephole 177.e	removed redundant move
   084B 8A 05              3115 	mov	ar5,r2
   084D 7A 00              3116 	mov	r2,#0x00
                           3117 ;	genPlus
                           3118 ;	Peephole 236.g	used r2 instead of ar2
   084F EA                 3119 	mov	a,r2
                           3120 ;	Peephole 236.a	used r3 instead of ar3
   0850 2B                 3121 	add	a,r3
   0851 FB                 3122 	mov	r3,a
                           3123 ;	Peephole 236.g	used r5 instead of ar5
   0852 ED                 3124 	mov	a,r5
                           3125 ;	Peephole 236.b	used r4 instead of ar4
   0853 3C                 3126 	addc	a,r4
   0854 FC                 3127 	mov	r4,a
                           3128 ;	genAssign
   0855 8C 02              3129 	mov	ar2,r4
                           3130 ;	Peephole 112.b	changed ljmp to sjmp
   0857 80 04              3131 	sjmp	00105$
   0859                    3132 00104$:
                           3133 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:313: ga=0;
                           3134 ;	genAssign
   0859 7B 00              3135 	mov	r3,#0x00
   085B 7A 00              3136 	mov	r2,#0x00
   085D                    3137 00105$:
                           3138 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:315: return(ga);
                           3139 ;	genRet
   085D 8B 82              3140 	mov	dpl,r3
   085F 8A 83              3141 	mov	dph,r2
                           3142 ;	Peephole 300	removed redundant label 00110$
   0861 85 08 81           3143 	mov	sp,_bp
   0864 D0 08              3144 	pop	_bp
   0866 22                 3145 	ret
                           3146 ;------------------------------------------------------------
                           3147 ;Allocation info for local variables in function 'gapos_in_gat'
                           3148 ;------------------------------------------------------------
                           3149 ;gal                       Allocated to stack - offset -3
                           3150 ;gah                       Allocated to registers r2 
                           3151 ;ga_position               Allocated to registers r4 
                           3152 ;ga_count                  Allocated to registers r3 
                           3153 ;n                         Allocated to registers 
                           3154 ;------------------------------------------------------------
                           3155 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:319: unsigned char gapos_in_gat(unsigned char gah, unsigned char gal)
                           3156 ;	-----------------------------------------
                           3157 ;	 function gapos_in_gat
                           3158 ;	-----------------------------------------
   0867                    3159 _gapos_in_gat:
   0867 C0 08              3160 	push	_bp
   0869 85 81 08           3161 	mov	_bp,sp
                           3162 ;	genReceive
   086C AA 82              3163 	mov	r2,dpl
                           3164 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:323: ga_count=read_byte(0x01,ADDRTAB);
                           3165 ;	genIpush
   086E C0 02              3166 	push	ar2
   0870 74 16              3167 	mov	a,#0x16
   0872 C0 E0              3168 	push	acc
                           3169 ;	genCall
   0874 75 82 01           3170 	mov	dpl,#0x01
   0877 12 02 CF           3171 	lcall	_read_byte
   087A AB 82              3172 	mov	r3,dpl
   087C 15 81              3173 	dec	sp
   087E D0 02              3174 	pop	ar2
                           3175 ;	genAssign
                           3176 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:324: ga_position=0xFF; 
                           3177 ;	genAssign
   0880 7C FF              3178 	mov	r4,#0xFF
                           3179 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:325: if (ga_count>0)
                           3180 ;	genIfx
   0882 EB                 3181 	mov	a,r3
                           3182 ;	genIfxJump
                           3183 ;	Peephole 108.c	removed ljmp by inverse jump logic
   0883 60 60              3184 	jz	00105$
                           3185 ;	Peephole 300	removed redundant label 00118$
                           3186 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:327: for (n=1;n<=ga_count;n++)
                           3187 ;	genAssign
   0885 7D 01              3188 	mov	r5,#0x01
   0887                    3189 00106$:
                           3190 ;	genCmpGt
                           3191 ;	genCmp
   0887 C3                 3192 	clr	c
   0888 EB                 3193 	mov	a,r3
   0889 9D                 3194 	subb	a,r5
                           3195 ;	genIfxJump
                           3196 ;	Peephole 112.b	changed ljmp to sjmp
                           3197 ;	Peephole 160.a	removed sjmp by inverse jump logic
   088A 40 59              3198 	jc	00105$
                           3199 ;	Peephole 300	removed redundant label 00119$
                           3200 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:329: if (gah==read_byte(0x01,ADDRTAB+n*2+1) && gal==read_byte(0x01,ADDRTAB+n*2+2)) ga_position=n;
                           3201 ;	genLeftShift
                           3202 ;	genLeftShiftLiteral
                           3203 ;	genlshOne
   088C ED                 3204 	mov	a,r5
                           3205 ;	Peephole 254	optimized left shift
   088D 2D                 3206 	add	a,r5
   088E FE                 3207 	mov	r6,a
                           3208 ;	genPlus
                           3209 ;     genPlusIncr
   088F 74 17              3210 	mov	a,#0x17
                           3211 ;	Peephole 236.a	used r6 instead of ar6
   0891 2E                 3212 	add	a,r6
   0892 FF                 3213 	mov	r7,a
                           3214 ;	genIpush
   0893 C0 02              3215 	push	ar2
   0895 C0 03              3216 	push	ar3
   0897 C0 04              3217 	push	ar4
   0899 C0 05              3218 	push	ar5
   089B C0 06              3219 	push	ar6
   089D C0 07              3220 	push	ar7
                           3221 ;	genCall
   089F 75 82 01           3222 	mov	dpl,#0x01
   08A2 12 02 CF           3223 	lcall	_read_byte
   08A5 AF 82              3224 	mov	r7,dpl
   08A7 15 81              3225 	dec	sp
   08A9 D0 06              3226 	pop	ar6
   08AB D0 05              3227 	pop	ar5
   08AD D0 04              3228 	pop	ar4
   08AF D0 03              3229 	pop	ar3
   08B1 D0 02              3230 	pop	ar2
                           3231 ;	genCmpEq
                           3232 ;	gencjneshort
   08B3 EA                 3233 	mov	a,r2
                           3234 ;	Peephole 112.b	changed ljmp to sjmp
                           3235 ;	Peephole 198.b	optimized misc jump sequence
   08B4 B5 07 2B           3236 	cjne	a,ar7,00108$
                           3237 ;	Peephole 200.b	removed redundant sjmp
                           3238 ;	Peephole 300	removed redundant label 00120$
                           3239 ;	Peephole 300	removed redundant label 00121$
                           3240 ;	genPlus
                           3241 ;     genPlusIncr
   08B7 74 18              3242 	mov	a,#0x18
                           3243 ;	Peephole 236.a	used r6 instead of ar6
   08B9 2E                 3244 	add	a,r6
   08BA FE                 3245 	mov	r6,a
                           3246 ;	genIpush
   08BB C0 02              3247 	push	ar2
   08BD C0 03              3248 	push	ar3
   08BF C0 04              3249 	push	ar4
   08C1 C0 05              3250 	push	ar5
   08C3 C0 06              3251 	push	ar6
                           3252 ;	genCall
   08C5 75 82 01           3253 	mov	dpl,#0x01
   08C8 12 02 CF           3254 	lcall	_read_byte
   08CB AE 82              3255 	mov	r6,dpl
   08CD 15 81              3256 	dec	sp
   08CF D0 05              3257 	pop	ar5
   08D1 D0 04              3258 	pop	ar4
   08D3 D0 03              3259 	pop	ar3
   08D5 D0 02              3260 	pop	ar2
                           3261 ;	genCmpEq
   08D7 A8 08              3262 	mov	r0,_bp
   08D9 18                 3263 	dec	r0
   08DA 18                 3264 	dec	r0
   08DB 18                 3265 	dec	r0
                           3266 ;	gencjneshort
   08DC E6                 3267 	mov	a,@r0
                           3268 ;	Peephole 112.b	changed ljmp to sjmp
                           3269 ;	Peephole 198.b	optimized misc jump sequence
   08DD B5 06 02           3270 	cjne	a,ar6,00108$
                           3271 ;	Peephole 200.b	removed redundant sjmp
                           3272 ;	Peephole 300	removed redundant label 00122$
                           3273 ;	Peephole 300	removed redundant label 00123$
                           3274 ;	genAssign
   08E0 8D 04              3275 	mov	ar4,r5
   08E2                    3276 00108$:
                           3277 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:327: for (n=1;n<=ga_count;n++)
                           3278 ;	genPlus
                           3279 ;     genPlusIncr
   08E2 0D                 3280 	inc	r5
                           3281 ;	Peephole 112.b	changed ljmp to sjmp
   08E3 80 A2              3282 	sjmp	00106$
   08E5                    3283 00105$:
                           3284 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:332: return (ga_position);
                           3285 ;	genRet
   08E5 8C 82              3286 	mov	dpl,r4
                           3287 ;	Peephole 300	removed redundant label 00110$
   08E7 D0 08              3288 	pop	_bp
   08E9 22                 3289 	ret
                           3290 ;------------------------------------------------------------
                           3291 ;Allocation info for local variables in function 'write_delay_record'
                           3292 ;------------------------------------------------------------
                           3293 ;delay_status              Allocated to stack - offset -3
                           3294 ;delay_target              Allocated to stack - offset -7
                           3295 ;objno                     Allocated to registers r2 
                           3296 ;------------------------------------------------------------
                           3297 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:336: void write_delay_record(unsigned char objno, unsigned char delay_status, long delay_target)		// Schreibt die Schalt-Verzögerungswerte ins Flash
                           3298 ;	-----------------------------------------
                           3299 ;	 function write_delay_record
                           3300 ;	-----------------------------------------
   08EA                    3301 _write_delay_record:
   08EA C0 08              3302 	push	_bp
   08EC 85 81 08           3303 	mov	_bp,sp
                           3304 ;	genReceive
   08EF AA 82              3305 	mov	r2,dpl
                           3306 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:338: start_writecycle();
                           3307 ;	genCall
   08F1 C0 02              3308 	push	ar2
   08F3 12 02 70           3309 	lcall	_start_writecycle
   08F6 D0 02              3310 	pop	ar2
                           3311 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:339: write_byte(0x00,objno*5,objno+delay_status);
                           3312 ;	genPlus
   08F8 A8 08              3313 	mov	r0,_bp
   08FA 18                 3314 	dec	r0
   08FB 18                 3315 	dec	r0
   08FC 18                 3316 	dec	r0
   08FD E6                 3317 	mov	a,@r0
                           3318 ;	Peephole 236.a	used r2 instead of ar2
   08FE 2A                 3319 	add	a,r2
   08FF FB                 3320 	mov	r3,a
                           3321 ;	genMult
                           3322 ;	genMultOneByte
   0900 EA                 3323 	mov	a,r2
   0901 75 F0 05           3324 	mov	b,#0x05
   0904 A4                 3325 	mul	ab
   0905 FA                 3326 	mov	r2,a
                           3327 ;	genIpush
   0906 C0 02              3328 	push	ar2
   0908 C0 03              3329 	push	ar3
                           3330 ;	genIpush
   090A C0 02              3331 	push	ar2
                           3332 ;	genCall
   090C 75 82 00           3333 	mov	dpl,#0x00
   090F 12 02 78           3334 	lcall	_write_byte
   0912 15 81              3335 	dec	sp
   0914 15 81              3336 	dec	sp
   0916 D0 02              3337 	pop	ar2
                           3338 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:340: write_byte(0x00,1+objno*5,delay_target>>24);
                           3339 ;	genGetByte
   0918 E5 08              3340 	mov	a,_bp
   091A 24 F9              3341 	add	a,#0xfffffff9
                           3342 ;	Peephole 185	changed order of increment (acc incremented also!)
   091C 04                 3343 	inc	a
                           3344 ;	Peephole 185	changed order of increment (acc incremented also!)
   091D 04                 3345 	inc	a
                           3346 ;	Peephole 185	changed order of increment (acc incremented also!)
   091E 04                 3347 	inc	a
   091F F8                 3348 	mov	r0,a
   0920 86 03              3349 	mov	ar3,@r0
                           3350 ;	genPlus
                           3351 ;     genPlusIncr
   0922 74 01              3352 	mov	a,#0x01
                           3353 ;	Peephole 236.a	used r2 instead of ar2
   0924 2A                 3354 	add	a,r2
   0925 FC                 3355 	mov	r4,a
                           3356 ;	genIpush
   0926 C0 02              3357 	push	ar2
   0928 C0 03              3358 	push	ar3
                           3359 ;	genIpush
   092A C0 04              3360 	push	ar4
                           3361 ;	genCall
   092C 75 82 00           3362 	mov	dpl,#0x00
   092F 12 02 78           3363 	lcall	_write_byte
   0932 15 81              3364 	dec	sp
   0934 15 81              3365 	dec	sp
   0936 D0 02              3366 	pop	ar2
                           3367 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:341: write_byte(0x00,2+objno*5,delay_target>>16);
                           3368 ;	genGetByte
   0938 E5 08              3369 	mov	a,_bp
   093A 24 F9              3370 	add	a,#0xfffffff9
                           3371 ;	Peephole 185	changed order of increment (acc incremented also!)
   093C 04                 3372 	inc	a
                           3373 ;	Peephole 185	changed order of increment (acc incremented also!)
   093D 04                 3374 	inc	a
   093E F8                 3375 	mov	r0,a
   093F 86 03              3376 	mov	ar3,@r0
                           3377 ;	genPlus
                           3378 ;     genPlusIncr
   0941 74 02              3379 	mov	a,#0x02
                           3380 ;	Peephole 236.a	used r2 instead of ar2
   0943 2A                 3381 	add	a,r2
   0944 FC                 3382 	mov	r4,a
                           3383 ;	genIpush
   0945 C0 02              3384 	push	ar2
   0947 C0 03              3385 	push	ar3
                           3386 ;	genIpush
   0949 C0 04              3387 	push	ar4
                           3388 ;	genCall
   094B 75 82 00           3389 	mov	dpl,#0x00
   094E 12 02 78           3390 	lcall	_write_byte
   0951 15 81              3391 	dec	sp
   0953 15 81              3392 	dec	sp
   0955 D0 02              3393 	pop	ar2
                           3394 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:342: write_byte(0x00,3+objno*5,delay_target>>8);
                           3395 ;	genGetByte
   0957 E5 08              3396 	mov	a,_bp
   0959 24 F9              3397 	add	a,#0xfffffff9
                           3398 ;	Peephole 185	changed order of increment (acc incremented also!)
   095B 04                 3399 	inc	a
   095C F8                 3400 	mov	r0,a
   095D 86 03              3401 	mov	ar3,@r0
                           3402 ;	genPlus
                           3403 ;     genPlusIncr
   095F 74 03              3404 	mov	a,#0x03
                           3405 ;	Peephole 236.a	used r2 instead of ar2
   0961 2A                 3406 	add	a,r2
   0962 FC                 3407 	mov	r4,a
                           3408 ;	genIpush
   0963 C0 02              3409 	push	ar2
   0965 C0 03              3410 	push	ar3
                           3411 ;	genIpush
   0967 C0 04              3412 	push	ar4
                           3413 ;	genCall
   0969 75 82 00           3414 	mov	dpl,#0x00
   096C 12 02 78           3415 	lcall	_write_byte
   096F 15 81              3416 	dec	sp
   0971 15 81              3417 	dec	sp
   0973 D0 02              3418 	pop	ar2
                           3419 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:343: write_byte(0x00,4+objno*5,delay_target);
                           3420 ;	genCast
   0975 E5 08              3421 	mov	a,_bp
   0977 24 F9              3422 	add	a,#0xfffffff9
   0979 F8                 3423 	mov	r0,a
   097A 86 03              3424 	mov	ar3,@r0
                           3425 ;	genPlus
                           3426 ;     genPlusIncr
   097C EA                 3427 	mov	a,r2
   097D 24 04              3428 	add	a,#0x04
   097F FA                 3429 	mov	r2,a
                           3430 ;	genIpush
   0980 C0 03              3431 	push	ar3
                           3432 ;	genIpush
   0982 C0 02              3433 	push	ar2
                           3434 ;	genCall
   0984 75 82 00           3435 	mov	dpl,#0x00
   0987 12 02 78           3436 	lcall	_write_byte
   098A 15 81              3437 	dec	sp
   098C 15 81              3438 	dec	sp
                           3439 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:344: stop_writecycle();
                           3440 ;	genCall
   098E 12 02 74           3441 	lcall	_stop_writecycle
                           3442 ;	Peephole 300	removed redundant label 00101$
   0991 D0 08              3443 	pop	_bp
   0993 22                 3444 	ret
                           3445 ;------------------------------------------------------------
                           3446 ;Allocation info for local variables in function 'restart_prot'
                           3447 ;------------------------------------------------------------
                           3448 ;------------------------------------------------------------
                           3449 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:348: void restart_prot(void)		// Protokoll-relevante Parameter zurücksetzen
                           3450 ;	-----------------------------------------
                           3451 ;	 function restart_prot
                           3452 ;	-----------------------------------------
   0994                    3453 _restart_prot:
                           3454 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:350: pah=read_byte(0x01,ADDRTAB+1);	// phys. Adresse einlesen
                           3455 ;	genIpush
   0994 74 17              3456 	mov	a,#0x17
   0996 C0 E0              3457 	push	acc
                           3458 ;	genCall
   0998 75 82 01           3459 	mov	dpl,#0x01
   099B 12 02 CF           3460 	lcall	_read_byte
   099E 85 82 3C           3461 	mov	_pah,dpl
   09A1 15 81              3462 	dec	sp
                           3463 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:351: pal=read_byte(0x01,ADDRTAB+2);
                           3464 ;	genIpush
   09A3 74 18              3465 	mov	a,#0x18
   09A5 C0 E0              3466 	push	acc
                           3467 ;	genCall
   09A7 75 82 01           3468 	mov	dpl,#0x01
   09AA 12 02 CF           3469 	lcall	_read_byte
   09AD 85 82 3B           3470 	mov	_pal,dpl
   09B0 15 81              3471 	dec	sp
                           3472 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:353: progmode=0;			// kein Programmiermodus
                           3473 ;	genAssign
   09B2 C2 01              3474 	clr	_progmode
                           3475 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:354: pcount=1;			// Paketzähler initialisieren
                           3476 ;	genAssign
   09B4 75 40 01           3477 	mov	_pcount,#0x01
                           3478 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:355: connected=0;			// keine Verbindung
                           3479 ;	genAssign
   09B7 C2 02              3480 	clr	_connected
                           3481 ;	d:/freebus/trunk/c51/89LPC922/common/fb_prot.c:357: telpos=0;			// empfangene Bytes an dieser Position im Array telegramm[] ablegen
                           3482 ;	genAssign
   09B9 75 39 00           3483 	mov	_telpos,#0x00
                           3484 ;	Peephole 300	removed redundant label 00101$
   09BC 22                 3485 	ret
                           3486 ;------------------------------------------------------------
                           3487 ;Allocation info for local variables in function 'rs_init'
                           3488 ;------------------------------------------------------------
                           3489 ;------------------------------------------------------------
                           3490 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:2: void rs_init(void)
                           3491 ;	-----------------------------------------
                           3492 ;	 function rs_init
                           3493 ;	-----------------------------------------
   09BD                    3494 _rs_init:
                           3495 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:4: SCON=0x50;	//Mode 1, receive enable
                           3496 ;	genAssign
   09BD 75 98 50           3497 	mov	_SCON,#0x50
                           3498 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:5: SSTAT|=0x40;	// TI wird am Ende des Stopbits gesetzt
                           3499 ;	genOr
   09C0 43 BA 40           3500 	orl	_SSTAT,#0x40
                           3501 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:6: BRGCON|=0x02;	// Baudrate Generator verwenden aber noch gestoppt
                           3502 ;	genOr
   09C3 43 BD 02           3503 	orl	_BRGCON,#0x02
                           3504 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:7: BRGR1=0x00;	// Baudrate = cclk/((BRGR1,BRGR0)+16)
                           3505 ;	genAssign
   09C6 75 BF 00           3506 	mov	_BRGR1,#0x00
                           3507 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:8: BRGR0=0x30;
                           3508 ;	genAssign
   09C9 75 BE 30           3509 	mov	_BRGR0,#0x30
                           3510 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:9: BRGCON|=0x01;	// Baudrate Generator starten
                           3511 ;	genOr
   09CC 43 BD 01           3512 	orl	_BRGCON,#0x01
                           3513 ;	Peephole 300	removed redundant label 00101$
   09CF 22                 3514 	ret
                           3515 ;------------------------------------------------------------
                           3516 ;Allocation info for local variables in function 'rs_send_dec'
                           3517 ;------------------------------------------------------------
                           3518 ;wert                      Allocated to registers r2 
                           3519 ;n                         Allocated to registers r3 
                           3520 ;------------------------------------------------------------
                           3521 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:12: void rs_send_dec(unsigned char wert)
                           3522 ;	-----------------------------------------
                           3523 ;	 function rs_send_dec
                           3524 ;	-----------------------------------------
   09D0                    3525 _rs_send_dec:
                           3526 ;	genReceive
   09D0 AA 82              3527 	mov	r2,dpl
                           3528 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:16: n=wert/100;
                           3529 ;	genDiv
                           3530 ;     genDivOneByte
   09D2 75 F0 64           3531 	mov	b,#0x64
   09D5 EA                 3532 	mov	a,r2
   09D6 84                 3533 	div	ab
                           3534 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:17: if(n>0)
                           3535 ;	genIfx
   09D7 FB                 3536 	mov	r3,a
                           3537 ;	Peephole 105	removed redundant mov
                           3538 ;	genIfxJump
                           3539 ;	Peephole 108.c	removed ljmp by inverse jump logic
   09D8 60 0A              3540 	jz	00105$
                           3541 ;	Peephole 300	removed redundant label 00124$
                           3542 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:19: SBUF=n+48;
                           3543 ;	genPlus
                           3544 ;     genPlusIncr
   09DA 74 30              3545 	mov	a,#0x30
                           3546 ;	Peephole 236.a	used r3 instead of ar3
   09DC 2B                 3547 	add	a,r3
   09DD F5 99              3548 	mov	_SBUF,a
                           3549 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:20: while(!TI);
   09DF                    3550 00101$:
                           3551 ;	genIfx
                           3552 ;	genIfxJump
                           3553 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           3554 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:21: TI=0;
                           3555 ;	genAssign
                           3556 ;	Peephole 250.a	using atomic test and clear
   09DF 10 99 02           3557 	jbc	_SCON_1,00125$
   09E2 80 FB              3558 	sjmp	00101$
   09E4                    3559 00125$:
   09E4                    3560 00105$:
                           3561 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:23: wert=wert-(n*100);
                           3562 ;	genMult
                           3563 ;	genMultOneByte
   09E4 EB                 3564 	mov	a,r3
   09E5 75 F0 64           3565 	mov	b,#0x64
   09E8 A4                 3566 	mul	ab
   09E9 FC                 3567 	mov	r4,a
                           3568 ;	genMinus
   09EA EA                 3569 	mov	a,r2
   09EB C3                 3570 	clr	c
                           3571 ;	Peephole 236.l	used r4 instead of ar4
   09EC 9C                 3572 	subb	a,r4
                           3573 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:24: n=wert/10;
                           3574 ;	genDiv
                           3575 ;     genDivOneByte
   09ED FA                 3576 	mov	r2,a
   09EE 75 F0 0A           3577 	mov	b,#0x0A
                           3578 ;	Peephole 177.d	removed redundant move
   09F1 84                 3579 	div	ab
                           3580 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:25: if(n>0)
                           3581 ;	genIfx
   09F2 FB                 3582 	mov	r3,a
                           3583 ;	Peephole 105	removed redundant mov
                           3584 ;	genIfxJump
                           3585 ;	Peephole 108.c	removed ljmp by inverse jump logic
   09F3 60 0A              3586 	jz	00110$
                           3587 ;	Peephole 300	removed redundant label 00126$
                           3588 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:27: SBUF=n+48;
                           3589 ;	genPlus
                           3590 ;     genPlusIncr
   09F5 74 30              3591 	mov	a,#0x30
                           3592 ;	Peephole 236.a	used r3 instead of ar3
   09F7 2B                 3593 	add	a,r3
   09F8 F5 99              3594 	mov	_SBUF,a
                           3595 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:28: while(!TI);
   09FA                    3596 00106$:
                           3597 ;	genIfx
                           3598 ;	genIfxJump
                           3599 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           3600 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:29: TI=0;
                           3601 ;	genAssign
                           3602 ;	Peephole 250.a	using atomic test and clear
   09FA 10 99 02           3603 	jbc	_SCON_1,00127$
   09FD 80 FB              3604 	sjmp	00106$
   09FF                    3605 00127$:
   09FF                    3606 00110$:
                           3607 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:31: wert=wert-(n*10);
                           3608 ;	genMult
                           3609 ;	genMultOneByte
   09FF EB                 3610 	mov	a,r3
   0A00 75 F0 0A           3611 	mov	b,#0x0A
   0A03 A4                 3612 	mul	ab
   0A04 FB                 3613 	mov	r3,a
                           3614 ;	genMinus
   0A05 EA                 3615 	mov	a,r2
   0A06 C3                 3616 	clr	c
                           3617 ;	Peephole 236.l	used r3 instead of ar3
   0A07 9B                 3618 	subb	a,r3
                           3619 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:32: SBUF=wert+48;
                           3620 ;	genPlus
                           3621 ;     genPlusIncr
                           3622 ;	Peephole 236.a	used r2 instead of ar2
   0A08 FA                 3623 	mov	r2,a
                           3624 ;	Peephole 214	reduced some extra moves
   0A09 24 30              3625 	add	a,#0x30
   0A0B F5 99              3626 	mov	_SBUF,a
                           3627 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:33: while(!TI);
   0A0D                    3628 00111$:
                           3629 ;	genIfx
                           3630 ;	genIfxJump
                           3631 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           3632 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:34: TI=0;
                           3633 ;	genAssign
                           3634 ;	Peephole 250.a	using atomic test and clear
   0A0D 10 99 02           3635 	jbc	_SCON_1,00128$
   0A10 80 FB              3636 	sjmp	00111$
   0A12                    3637 00128$:
                           3638 ;	Peephole 300	removed redundant label 00114$
   0A12 22                 3639 	ret
                           3640 ;------------------------------------------------------------
                           3641 ;Allocation info for local variables in function 'rs_send_ok'
                           3642 ;------------------------------------------------------------
                           3643 ;------------------------------------------------------------
                           3644 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:37: void rs_send_ok(void)
                           3645 ;	-----------------------------------------
                           3646 ;	 function rs_send_ok
                           3647 ;	-----------------------------------------
   0A13                    3648 _rs_send_ok:
                           3649 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:39: SBUF='O';
                           3650 ;	genAssign
   0A13 75 99 4F           3651 	mov	_SBUF,#0x4F
                           3652 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:40: while(!TI);
   0A16                    3653 00101$:
                           3654 ;	genIfx
                           3655 ;	genIfxJump
                           3656 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           3657 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:41: TI=0;
                           3658 ;	genAssign
                           3659 ;	Peephole 250.a	using atomic test and clear
   0A16 10 99 02           3660 	jbc	_SCON_1,00123$
   0A19 80 FB              3661 	sjmp	00101$
   0A1B                    3662 00123$:
                           3663 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:42: SBUF='K';
                           3664 ;	genAssign
   0A1B 75 99 4B           3665 	mov	_SBUF,#0x4B
                           3666 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:43: while(!TI);
   0A1E                    3667 00104$:
                           3668 ;	genIfx
                           3669 ;	genIfxJump
                           3670 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           3671 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:44: TI=0;
                           3672 ;	genAssign
                           3673 ;	Peephole 250.a	using atomic test and clear
   0A1E 10 99 02           3674 	jbc	_SCON_1,00124$
   0A21 80 FB              3675 	sjmp	00104$
   0A23                    3676 00124$:
                           3677 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:45: SBUF=0x0D;
                           3678 ;	genAssign
   0A23 75 99 0D           3679 	mov	_SBUF,#0x0D
                           3680 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:46: while(!TI);
   0A26                    3681 00107$:
                           3682 ;	genIfx
                           3683 ;	genIfxJump
                           3684 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           3685 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:47: TI=0;
                           3686 ;	genAssign
                           3687 ;	Peephole 250.a	using atomic test and clear
   0A26 10 99 02           3688 	jbc	_SCON_1,00125$
   0A29 80 FB              3689 	sjmp	00107$
   0A2B                    3690 00125$:
                           3691 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:48: SBUF=0x0A;
                           3692 ;	genAssign
   0A2B 75 99 0A           3693 	mov	_SBUF,#0x0A
                           3694 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:49: while(!TI);
   0A2E                    3695 00110$:
                           3696 ;	genIfx
                           3697 ;	genIfxJump
                           3698 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           3699 ;	d:/freebus/trunk/c51/89LPC922/common/fb_rs232.c:50: TI=0;
                           3700 ;	genAssign
                           3701 ;	Peephole 250.a	using atomic test and clear
   0A2E 10 99 02           3702 	jbc	_SCON_1,00126$
   0A31 80 FB              3703 	sjmp	00110$
   0A33                    3704 00126$:
                           3705 ;	Peephole 300	removed redundant label 00113$
   0A33 22                 3706 	ret
                           3707 ;------------------------------------------------------------
                           3708 ;Allocation info for local variables in function 'eis1'
                           3709 ;------------------------------------------------------------
                           3710 ;------------------------------------------------------------
                           3711 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:7: void eis1(void)
                           3712 ;	-----------------------------------------
                           3713 ;	 function eis1
                           3714 ;	-----------------------------------------
   0A34                    3715 _eis1:
                           3716 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:9: rs_send_dec(telegramm[3]>>3);
                           3717 ;	genAssign
                           3718 ;	genRightShift
                           3719 ;	genRightShiftLiteral
                           3720 ;	genrshOne
   0A34 E5 25              3721 	mov	a,0x0003 + _telegramm
   0A36 C4                 3722 	swap	a
   0A37 23                 3723 	rl	a
   0A38 54 1F              3724 	anl	a,#0x1f
   0A3A F5 82              3725 	mov	dpl,a
                           3726 ;	genCall
   0A3C 12 09 D0           3727 	lcall	_rs_send_dec
                           3728 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:10: SBUF='.';
                           3729 ;	genAssign
   0A3F 75 99 2E           3730 	mov	_SBUF,#0x2E
                           3731 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:11: while(!TI);
   0A42                    3732 00101$:
                           3733 ;	genIfx
                           3734 ;	genIfxJump
                           3735 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           3736 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:12: TI=0;
                           3737 ;	genAssign
                           3738 ;	Peephole 250.a	using atomic test and clear
   0A42 10 99 02           3739 	jbc	_SCON_1,00128$
   0A45 80 FB              3740 	sjmp	00101$
   0A47                    3741 00128$:
                           3742 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:13: rs_send_dec(telegramm[3] & 0x07);
                           3743 ;	genAssign
                           3744 ;	genAnd
   0A47 74 07              3745 	mov	a,#0x07
   0A49 55 25              3746 	anl	a,0x0003 + _telegramm
   0A4B F5 82              3747 	mov	dpl,a
                           3748 ;	genCall
   0A4D 12 09 D0           3749 	lcall	_rs_send_dec
                           3750 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:14: SBUF='.';
                           3751 ;	genAssign
   0A50 75 99 2E           3752 	mov	_SBUF,#0x2E
                           3753 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:15: while(!TI);
   0A53                    3754 00104$:
                           3755 ;	genIfx
                           3756 ;	genIfxJump
                           3757 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           3758 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:16: TI=0;
                           3759 ;	genAssign
                           3760 ;	Peephole 250.a	using atomic test and clear
   0A53 10 99 02           3761 	jbc	_SCON_1,00129$
   0A56 80 FB              3762 	sjmp	00104$
   0A58                    3763 00129$:
                           3764 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:17: rs_send_dec(telegramm[4]);
                           3765 ;	genPointerGet
                           3766 ;	genNearPointerGet
                           3767 ;	genDataPointerGet
   0A58 85 26 82           3768 	mov	dpl,(_telegramm + 0x0004)
                           3769 ;	genCall
   0A5B 12 09 D0           3770 	lcall	_rs_send_dec
                           3771 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:18: SBUF='=';
                           3772 ;	genAssign
   0A5E 75 99 3D           3773 	mov	_SBUF,#0x3D
                           3774 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:19: while(!TI);
   0A61                    3775 00107$:
                           3776 ;	genIfx
                           3777 ;	genIfxJump
                           3778 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           3779 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:20: TI=0;
                           3780 ;	genAssign
                           3781 ;	Peephole 250.a	using atomic test and clear
   0A61 10 99 02           3782 	jbc	_SCON_1,00130$
   0A64 80 FB              3783 	sjmp	00107$
   0A66                    3784 00130$:
                           3785 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:21: rs_send_dec(telegramm[7] & 0x01);
                           3786 ;	genAssign
                           3787 ;	genAnd
   0A66 74 01              3788 	mov	a,#0x01
   0A68 55 29              3789 	anl	a,0x0007 + _telegramm
   0A6A F5 82              3790 	mov	dpl,a
                           3791 ;	genCall
   0A6C 12 09 D0           3792 	lcall	_rs_send_dec
                           3793 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:22: SBUF=0x0D;
                           3794 ;	genAssign
   0A6F 75 99 0D           3795 	mov	_SBUF,#0x0D
                           3796 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:23: while(!TI);
   0A72                    3797 00110$:
                           3798 ;	genIfx
                           3799 ;	genIfxJump
                           3800 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           3801 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:24: TI=0;
                           3802 ;	genAssign
                           3803 ;	Peephole 250.a	using atomic test and clear
   0A72 10 99 02           3804 	jbc	_SCON_1,00131$
   0A75 80 FB              3805 	sjmp	00110$
   0A77                    3806 00131$:
                           3807 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:25: SBUF=0x0A;
                           3808 ;	genAssign
   0A77 75 99 0A           3809 	mov	_SBUF,#0x0A
                           3810 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:26: while(!TI);
   0A7A                    3811 00113$:
                           3812 ;	genIfx
                           3813 ;	genIfxJump
                           3814 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           3815 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:27: TI=0;
                           3816 ;	genAssign
                           3817 ;	Peephole 250.a	using atomic test and clear
   0A7A 10 99 02           3818 	jbc	_SCON_1,00132$
   0A7D 80 FB              3819 	sjmp	00113$
   0A7F                    3820 00132$:
                           3821 ;	Peephole 300	removed redundant label 00116$
   0A7F 22                 3822 	ret
                           3823 ;------------------------------------------------------------
                           3824 ;Allocation info for local variables in function 'read_value_req'
                           3825 ;------------------------------------------------------------
                           3826 ;------------------------------------------------------------
                           3827 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:30: void read_value_req(void)
                           3828 ;	-----------------------------------------
                           3829 ;	 function read_value_req
                           3830 ;	-----------------------------------------
   0A80                    3831 _read_value_req:
                           3832 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:32: }
                           3833 ;	Peephole 300	removed redundant label 00101$
   0A80 22                 3834 	ret
                           3835 ;------------------------------------------------------------
                           3836 ;Allocation info for local variables in function 'restart_app'
                           3837 ;------------------------------------------------------------
                           3838 ;------------------------------------------------------------
                           3839 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:37: void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
                           3840 ;	-----------------------------------------
                           3841 ;	 function restart_app
                           3842 ;	-----------------------------------------
   0A81                    3843 _restart_app:
                           3844 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:42: P0M1=0x00;				// Port 0 Modus push-pull für Ausgang
                           3845 ;	genAssign
   0A81 75 84 00           3846 	mov	_P0M1,#0x00
                           3847 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:43: P0M2=0xFF;
                           3848 ;	genAssign
   0A84 75 85 FF           3849 	mov	_P0M2,#0xFF
                           3850 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_app_rs.c:44: P0=0;
                           3851 ;	genAssign
   0A87 75 80 00           3852 	mov	_P0,#0x00
                           3853 ;	Peephole 300	removed redundant label 00101$
   0A8A 22                 3854 	ret
                           3855 ;------------------------------------------------------------
                           3856 ;Allocation info for local variables in function 'main'
                           3857 ;------------------------------------------------------------
                           3858 ;n                         Allocated to registers r2 
                           3859 ;rsinpos                   Allocated to stack - offset 1
                           3860 ;rsin                      Allocated to stack - offset 2
                           3861 ;cr_received               Allocated to registers b0 
                           3862 ;crlf_received             Allocated to registers b1 
                           3863 ;groupadr                  Allocated to registers r4 r5 
                           3864 ;sloc0                     Allocated to stack - offset 22
                           3865 ;------------------------------------------------------------
                           3866 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:18: void main(void)
                           3867 ;	-----------------------------------------
                           3868 ;	 function main
                           3869 ;	-----------------------------------------
   0A8B                    3870 _main:
   0A8B C0 08              3871 	push	_bp
                           3872 ;	peephole 177.h	optimized mov sequence
   0A8D E5 81              3873 	mov	a,sp
   0A8F F5 08              3874 	mov	_bp,a
   0A91 24 17              3875 	add	a,#0x17
   0A93 F5 81              3876 	mov	sp,a
                           3877 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:25: restart_hw();				// Hardware zurücksetzen
                           3878 ;	genCall
   0A95 12 02 F8           3879 	lcall	_restart_hw
                           3880 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:26: restart_prot();			// Protokoll-relevante Parameter zurücksetzen
                           3881 ;	genCall
   0A98 12 09 94           3882 	lcall	_restart_prot
                           3883 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:27: restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
                           3884 ;	genCall
   0A9B 12 0A 81           3885 	lcall	_restart_app
                           3886 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:29: rs_init();				// serielle Schnittstelle initialisieren
                           3887 ;	genCall
   0A9E 12 09 BD           3888 	lcall	_rs_init
                           3889 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:30: rsinpos=0;
                           3890 ;	genAssign
   0AA1 A8 08              3891 	mov	r0,_bp
   0AA3 08                 3892 	inc	r0
   0AA4 76 00              3893 	mov	@r0,#0x00
                           3894 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:31: cr_received=0;
                           3895 ;	genAssign
   0AA6 C2 08              3896 	clr	b0
                           3897 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:32: crlf_received=0;
                           3898 ;	genAssign
   0AA8 C2 09              3899 	clr	b1
                           3900 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:35: do  {
   0AAA                    3901 00156$:
                           3902 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:36: if (RI)
                           3903 ;	genIfx
                           3904 ;	genIfxJump
                           3905 ;	Peephole 108.d	removed ljmp by inverse jump logic
   0AAA 30 98 2C           3906 	jnb	_SCON_0,00108$
                           3907 ;	Peephole 300	removed redundant label 00218$
                           3908 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:38: switch (SBUF)
                           3909 ;	genAssign
   0AAD AB 99              3910 	mov	r3,_SBUF
                           3911 ;	genCmpEq
                           3912 ;	gencjneshort
   0AAF BB 0A 02           3913 	cjne	r3,#0x0A,00219$
                           3914 ;	Peephole 112.b	changed ljmp to sjmp
   0AB2 80 07              3915 	sjmp	00102$
   0AB4                    3916 00219$:
                           3917 ;	genCmpEq
                           3918 ;	gencjneshort
                           3919 ;	Peephole 112.b	changed ljmp to sjmp
                           3920 ;	Peephole 198.b	optimized misc jump sequence
   0AB4 BB 0D 0B           3921 	cjne	r3,#0x0D,00105$
                           3922 ;	Peephole 200.b	removed redundant sjmp
                           3923 ;	Peephole 300	removed redundant label 00220$
                           3924 ;	Peephole 300	removed redundant label 00221$
                           3925 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:41: cr_received=1;
                           3926 ;	genAssign
   0AB7 D2 08              3927 	setb	b0
                           3928 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:42: break;
                           3929 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:43: case 0x0A:
                           3930 ;	Peephole 112.b	changed ljmp to sjmp
   0AB9 80 1C              3931 	sjmp	00106$
   0ABB                    3932 00102$:
                           3933 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:44: if (cr_received) crlf_received=1;
                           3934 ;	genIfx
                           3935 ;	genIfxJump
                           3936 ;	Peephole 108.d	removed ljmp by inverse jump logic
   0ABB 30 08 19           3937 	jnb	b0,00106$
                           3938 ;	Peephole 300	removed redundant label 00222$
                           3939 ;	genAssign
   0ABE D2 09              3940 	setb	b1
                           3941 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:45: break;
                           3942 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:46: default:
                           3943 ;	Peephole 112.b	changed ljmp to sjmp
   0AC0 80 15              3944 	sjmp	00106$
   0AC2                    3945 00105$:
                           3946 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:47: rsin[rsinpos]=SBUF;
                           3947 ;	genAddrOf
   0AC2 E5 08              3948 	mov	a,_bp
   0AC4 24 02              3949 	add	a,#0x02
   0AC6 FB                 3950 	mov	r3,a
                           3951 ;	genPlus
   0AC7 A9 08              3952 	mov	r1,_bp
   0AC9 09                 3953 	inc	r1
   0ACA E7                 3954 	mov	a,@r1
                           3955 ;	Peephole 236.a	used r3 instead of ar3
   0ACB 2B                 3956 	add	a,r3
   0ACC F8                 3957 	mov	r0,a
                           3958 ;	genPointerSet
                           3959 ;	genNearPointerSet
   0ACD A6 99              3960 	mov	@r0,_SBUF
                           3961 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:48: rsinpos++;
                           3962 ;	genPlus
   0ACF A8 08              3963 	mov	r0,_bp
   0AD1 08                 3964 	inc	r0
                           3965 ;     genPlusIncr
   0AD2 06                 3966 	inc	@r0
                           3967 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:49: cr_received=0;
                           3968 ;	genAssign
   0AD3 C2 08              3969 	clr	b0
                           3970 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:50: crlf_received=0;
                           3971 ;	genAssign
   0AD5 C2 09              3972 	clr	b1
                           3973 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:51: }
   0AD7                    3974 00106$:
                           3975 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:52: RI=0;
                           3976 ;	genAssign
   0AD7 C2 98              3977 	clr	_SCON_0
   0AD9                    3978 00108$:
                           3979 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:55: if (crlf_received)			// Zeile vollständig empfangen
                           3980 ;	genIfx
                           3981 ;	genIfxJump
   0AD9 20 09 03           3982 	jb	b1,00223$
   0ADC 02 0E 8F           3983 	ljmp	00150$
   0ADF                    3984 00223$:
                           3985 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:57: if (rsin[0]=='f' && rsin[1]=='b')	// Magic-word 'fb' empfangen
                           3986 ;	genAddrOf
   0ADF E5 08              3987 	mov	a,_bp
   0AE1 24 02              3988 	add	a,#0x02
   0AE3 F8                 3989 	mov	r0,a
                           3990 ;	genPointerGet
                           3991 ;	genNearPointerGet
   0AE4 86 03              3992 	mov	ar3,@r0
                           3993 ;	genCmpEq
                           3994 ;	gencjneshort
   0AE6 BB 66 02           3995 	cjne	r3,#0x66,00224$
   0AE9 80 03              3996 	sjmp	00225$
   0AEB                    3997 00224$:
   0AEB 02 0E 77           3998 	ljmp	00206$
   0AEE                    3999 00225$:
                           4000 ;	genPlus
                           4001 ;     genPlusIncr
   0AEE 74 01              4002 	mov	a,#0x01
                           4003 ;	Peephole 236.a	used r0 instead of ar0
   0AF0 28                 4004 	add	a,r0
   0AF1 F9                 4005 	mov	r1,a
                           4006 ;	genPointerGet
                           4007 ;	genNearPointerGet
   0AF2 87 03              4008 	mov	ar3,@r1
                           4009 ;	genCmpEq
                           4010 ;	gencjneshort
   0AF4 BB 62 02           4011 	cjne	r3,#0x62,00226$
   0AF7 80 03              4012 	sjmp	00227$
   0AF9                    4013 00226$:
   0AF9 02 0E 77           4014 	ljmp	00206$
   0AFC                    4015 00227$:
                           4016 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:59: if(rsin[2]=='s' && rsin[3]=='0' && rsin[4]=='1' && rsin[5]=='/' && rsin[8]=='/' && rsin[10]=='/' && rsin[14]=='=' && (rsin[15]=='0' || rsin[15]=='1'))	// EIS 1 senden
                           4017 ;	genPlus
                           4018 ;     genPlusIncr
   0AFC 74 02              4019 	mov	a,#0x02
                           4020 ;	Peephole 236.a	used r0 instead of ar0
   0AFE 28                 4021 	add	a,r0
   0AFF F9                 4022 	mov	r1,a
                           4023 ;	genPointerGet
                           4024 ;	genNearPointerGet
   0B00 87 03              4025 	mov	ar3,@r1
                           4026 ;	genCmpEq
                           4027 ;	gencjneshort
   0B02 BB 73 02           4028 	cjne	r3,#0x73,00228$
   0B05 80 03              4029 	sjmp	00229$
   0B07                    4030 00228$:
   0B07 02 0D 16           4031 	ljmp	00114$
   0B0A                    4032 00229$:
                           4033 ;	genPlus
                           4034 ;     genPlusIncr
   0B0A 74 03              4035 	mov	a,#0x03
                           4036 ;	Peephole 236.a	used r0 instead of ar0
   0B0C 28                 4037 	add	a,r0
   0B0D FB                 4038 	mov	r3,a
                           4039 ;	genPointerGet
                           4040 ;	genNearPointerGet
   0B0E C0 00              4041 	push	ar0
   0B10 A8 03              4042 	mov	r0,ar3
   0B12 86 03              4043 	mov	ar3,@r0
   0B14 D0 00              4044 	pop	ar0
                           4045 ;	genCmpEq
                           4046 ;	gencjneshort
   0B16 BB 30 02           4047 	cjne	r3,#0x30,00230$
   0B19 80 03              4048 	sjmp	00231$
   0B1B                    4049 00230$:
   0B1B 02 0D 16           4050 	ljmp	00114$
   0B1E                    4051 00231$:
                           4052 ;	genPlus
                           4053 ;     genPlusIncr
   0B1E 74 04              4054 	mov	a,#0x04
                           4055 ;	Peephole 236.a	used r0 instead of ar0
   0B20 28                 4056 	add	a,r0
   0B21 FB                 4057 	mov	r3,a
                           4058 ;	genPointerGet
                           4059 ;	genNearPointerGet
   0B22 C0 00              4060 	push	ar0
   0B24 A8 03              4061 	mov	r0,ar3
   0B26 86 03              4062 	mov	ar3,@r0
   0B28 D0 00              4063 	pop	ar0
                           4064 ;	genCmpEq
                           4065 ;	gencjneshort
   0B2A BB 31 02           4066 	cjne	r3,#0x31,00232$
   0B2D 80 03              4067 	sjmp	00233$
   0B2F                    4068 00232$:
   0B2F 02 0D 16           4069 	ljmp	00114$
   0B32                    4070 00233$:
                           4071 ;	genPlus
                           4072 ;     genPlusIncr
   0B32 74 05              4073 	mov	a,#0x05
                           4074 ;	Peephole 236.a	used r0 instead of ar0
   0B34 28                 4075 	add	a,r0
   0B35 FB                 4076 	mov	r3,a
                           4077 ;	genPointerGet
                           4078 ;	genNearPointerGet
   0B36 C0 00              4079 	push	ar0
   0B38 A8 03              4080 	mov	r0,ar3
   0B3A 86 03              4081 	mov	ar3,@r0
   0B3C D0 00              4082 	pop	ar0
                           4083 ;	genCmpEq
                           4084 ;	gencjneshort
   0B3E BB 2F 02           4085 	cjne	r3,#0x2F,00234$
   0B41 80 03              4086 	sjmp	00235$
   0B43                    4087 00234$:
   0B43 02 0D 16           4088 	ljmp	00114$
   0B46                    4089 00235$:
                           4090 ;	genPlus
                           4091 ;     genPlusIncr
   0B46 74 08              4092 	mov	a,#0x08
                           4093 ;	Peephole 236.a	used r0 instead of ar0
   0B48 28                 4094 	add	a,r0
   0B49 FB                 4095 	mov	r3,a
                           4096 ;	genPointerGet
                           4097 ;	genNearPointerGet
   0B4A C0 00              4098 	push	ar0
   0B4C A8 03              4099 	mov	r0,ar3
   0B4E 86 03              4100 	mov	ar3,@r0
   0B50 D0 00              4101 	pop	ar0
                           4102 ;	genCmpEq
                           4103 ;	gencjneshort
   0B52 BB 2F 02           4104 	cjne	r3,#0x2F,00236$
   0B55 80 03              4105 	sjmp	00237$
   0B57                    4106 00236$:
   0B57 02 0D 16           4107 	ljmp	00114$
   0B5A                    4108 00237$:
                           4109 ;	genPlus
                           4110 ;     genPlusIncr
   0B5A 74 0A              4111 	mov	a,#0x0A
                           4112 ;	Peephole 236.a	used r0 instead of ar0
   0B5C 28                 4113 	add	a,r0
   0B5D FB                 4114 	mov	r3,a
                           4115 ;	genPointerGet
                           4116 ;	genNearPointerGet
   0B5E C0 00              4117 	push	ar0
   0B60 A8 03              4118 	mov	r0,ar3
   0B62 86 03              4119 	mov	ar3,@r0
   0B64 D0 00              4120 	pop	ar0
                           4121 ;	genCmpEq
                           4122 ;	gencjneshort
   0B66 BB 2F 02           4123 	cjne	r3,#0x2F,00238$
   0B69 80 03              4124 	sjmp	00239$
   0B6B                    4125 00238$:
   0B6B 02 0D 16           4126 	ljmp	00114$
   0B6E                    4127 00239$:
                           4128 ;	genPlus
                           4129 ;     genPlusIncr
   0B6E 74 0E              4130 	mov	a,#0x0E
                           4131 ;	Peephole 236.a	used r0 instead of ar0
   0B70 28                 4132 	add	a,r0
   0B71 FB                 4133 	mov	r3,a
                           4134 ;	genPointerGet
                           4135 ;	genNearPointerGet
   0B72 C0 00              4136 	push	ar0
   0B74 A8 03              4137 	mov	r0,ar3
   0B76 86 03              4138 	mov	ar3,@r0
   0B78 D0 00              4139 	pop	ar0
                           4140 ;	genCmpEq
                           4141 ;	gencjneshort
   0B7A BB 3D 02           4142 	cjne	r3,#0x3D,00240$
   0B7D 80 03              4143 	sjmp	00241$
   0B7F                    4144 00240$:
   0B7F 02 0D 16           4145 	ljmp	00114$
   0B82                    4146 00241$:
                           4147 ;	genPlus
                           4148 ;     genPlusIncr
   0B82 74 0F              4149 	mov	a,#0x0F
                           4150 ;	Peephole 236.a	used r0 instead of ar0
   0B84 28                 4151 	add	a,r0
   0B85 FB                 4152 	mov	r3,a
                           4153 ;	genPointerGet
                           4154 ;	genNearPointerGet
   0B86 C0 00              4155 	push	ar0
   0B88 A8 03              4156 	mov	r0,ar3
   0B8A 86 04              4157 	mov	ar4,@r0
   0B8C D0 00              4158 	pop	ar0
                           4159 ;	genCmpEq
                           4160 ;	gencjneshort
   0B8E BC 30 02           4161 	cjne	r4,#0x30,00242$
                           4162 ;	Peephole 112.b	changed ljmp to sjmp
   0B91 80 08              4163 	sjmp	00113$
   0B93                    4164 00242$:
                           4165 ;	genCmpEq
                           4166 ;	gencjneshort
   0B93 BC 31 02           4167 	cjne	r4,#0x31,00243$
   0B96 80 03              4168 	sjmp	00244$
   0B98                    4169 00243$:
   0B98 02 0D 16           4170 	ljmp	00114$
   0B9B                    4171 00244$:
   0B9B                    4172 00113$:
                           4173 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:61: groupadr=((rsin[6]-48)*10) + (rsin[7]-48);
                           4174 ;	genIpush
   0B9B C0 01              4175 	push	ar1
                           4176 ;	genPlus
                           4177 ;     genPlusIncr
   0B9D 74 06              4178 	mov	a,#0x06
                           4179 ;	Peephole 236.a	used r0 instead of ar0
   0B9F 28                 4180 	add	a,r0
   0BA0 FC                 4181 	mov	r4,a
                           4182 ;	genPointerGet
                           4183 ;	genNearPointerGet
   0BA1 C0 00              4184 	push	ar0
   0BA3 A8 04              4185 	mov	r0,ar4
   0BA5 86 04              4186 	mov	ar4,@r0
   0BA7 D0 00              4187 	pop	ar0
                           4188 ;	genCast
   0BA9 7D 00              4189 	mov	r5,#0x00
                           4190 ;	genMinus
   0BAB EC                 4191 	mov	a,r4
   0BAC 24 D0              4192 	add	a,#0xd0
   0BAE F5 82              4193 	mov	dpl,a
   0BB0 ED                 4194 	mov	a,r5
   0BB1 34 FF              4195 	addc	a,#0xff
   0BB3 F5 83              4196 	mov	dph,a
                           4197 ;	genIpush
   0BB5 C0 03              4198 	push	ar3
   0BB7 C0 00              4199 	push	ar0
   0BB9 C0 01              4200 	push	ar1
   0BBB 74 0A              4201 	mov	a,#0x0A
   0BBD C0 E0              4202 	push	acc
                           4203 ;	Peephole 181	changed mov to clr
   0BBF E4                 4204 	clr	a
   0BC0 C0 E0              4205 	push	acc
                           4206 ;	genCall
   0BC2 12 0E AF           4207 	lcall	__mulint
   0BC5 AC 82              4208 	mov	r4,dpl
   0BC7 AD 83              4209 	mov	r5,dph
   0BC9 15 81              4210 	dec	sp
   0BCB 15 81              4211 	dec	sp
   0BCD D0 01              4212 	pop	ar1
   0BCF D0 00              4213 	pop	ar0
   0BD1 D0 03              4214 	pop	ar3
                           4215 ;	genPlus
                           4216 ;     genPlusIncr
   0BD3 74 07              4217 	mov	a,#0x07
                           4218 ;	Peephole 236.a	used r0 instead of ar0
   0BD5 28                 4219 	add	a,r0
   0BD6 FE                 4220 	mov	r6,a
                           4221 ;	genPointerGet
                           4222 ;	genNearPointerGet
   0BD7 C0 00              4223 	push	ar0
   0BD9 A8 06              4224 	mov	r0,ar6
   0BDB 86 06              4225 	mov	ar6,@r0
   0BDD D0 00              4226 	pop	ar0
                           4227 ;	genCast
   0BDF 7F 00              4228 	mov	r7,#0x00
                           4229 ;	genMinus
   0BE1 EE                 4230 	mov	a,r6
   0BE2 24 D0              4231 	add	a,#0xd0
   0BE4 FE                 4232 	mov	r6,a
   0BE5 EF                 4233 	mov	a,r7
   0BE6 34 FF              4234 	addc	a,#0xff
   0BE8 FF                 4235 	mov	r7,a
                           4236 ;	genPlus
                           4237 ;	Peephole 236.g	used r6 instead of ar6
   0BE9 EE                 4238 	mov	a,r6
                           4239 ;	Peephole 236.a	used r4 instead of ar4
   0BEA 2C                 4240 	add	a,r4
   0BEB FC                 4241 	mov	r4,a
                           4242 ;	Peephole 236.g	used r7 instead of ar7
   0BEC EF                 4243 	mov	a,r7
                           4244 ;	Peephole 236.b	used r5 instead of ar5
   0BED 3D                 4245 	addc	a,r5
                           4246 ;	genAssign
                           4247 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:62: groupadr=groupadr*8;
                           4248 ;	genLeftShift
                           4249 ;	genLeftShiftLiteral
                           4250 ;	genlshTwo
   0BEE FD                 4251 	mov	r5,a
                           4252 ;	Peephole 105	removed redundant mov
   0BEF C4                 4253 	swap	a
   0BF0 03                 4254 	rr	a
   0BF1 54 F8              4255 	anl	a,#0xf8
   0BF3 CC                 4256 	xch	a,r4
   0BF4 C4                 4257 	swap	a
   0BF5 03                 4258 	rr	a
   0BF6 CC                 4259 	xch	a,r4
   0BF7 6C                 4260 	xrl	a,r4
   0BF8 CC                 4261 	xch	a,r4
   0BF9 54 F8              4262 	anl	a,#0xf8
   0BFB CC                 4263 	xch	a,r4
   0BFC 6C                 4264 	xrl	a,r4
   0BFD FD                 4265 	mov	r5,a
                           4266 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:63: groupadr=groupadr + (rsin[9]-48);
                           4267 ;	genPlus
                           4268 ;     genPlusIncr
   0BFE 74 09              4269 	mov	a,#0x09
                           4270 ;	Peephole 236.a	used r0 instead of ar0
   0C00 28                 4271 	add	a,r0
   0C01 FE                 4272 	mov	r6,a
                           4273 ;	genPointerGet
                           4274 ;	genNearPointerGet
   0C02 C0 00              4275 	push	ar0
   0C04 A8 06              4276 	mov	r0,ar6
   0C06 86 06              4277 	mov	ar6,@r0
   0C08 D0 00              4278 	pop	ar0
                           4279 ;	genCast
   0C0A 7F 00              4280 	mov	r7,#0x00
                           4281 ;	genMinus
   0C0C EE                 4282 	mov	a,r6
   0C0D 24 D0              4283 	add	a,#0xd0
   0C0F FE                 4284 	mov	r6,a
   0C10 EF                 4285 	mov	a,r7
   0C11 34 FF              4286 	addc	a,#0xff
   0C13 FF                 4287 	mov	r7,a
                           4288 ;	genPlus
                           4289 ;	Peephole 236.g	used r6 instead of ar6
   0C14 EE                 4290 	mov	a,r6
                           4291 ;	Peephole 236.a	used r4 instead of ar4
   0C15 2C                 4292 	add	a,r4
   0C16 FC                 4293 	mov	r4,a
                           4294 ;	Peephole 236.g	used r7 instead of ar7
   0C17 EF                 4295 	mov	a,r7
                           4296 ;	Peephole 236.b	used r5 instead of ar5
   0C18 3D                 4297 	addc	a,r5
                           4298 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:64: groupadr=groupadr*256;
                           4299 ;	genLeftShift
                           4300 ;	genLeftShiftLiteral
                           4301 ;	genlshTwo
                           4302 ;	peephole 177.e	removed redundant move
   0C19 8C 05              4303 	mov	ar5,r4
   0C1B 7C 00              4304 	mov	r4,#0x00
                           4305 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:65: groupadr=groupadr+((rsin[11]-48)*100) + ((rsin[12]-48)*10) + (rsin[13]-48);
                           4306 ;	genPlus
                           4307 ;     genPlusIncr
   0C1D 74 0B              4308 	mov	a,#0x0B
                           4309 ;	Peephole 236.a	used r0 instead of ar0
   0C1F 28                 4310 	add	a,r0
   0C20 FE                 4311 	mov	r6,a
                           4312 ;	genPointerGet
                           4313 ;	genNearPointerGet
   0C21 C0 00              4314 	push	ar0
   0C23 A8 06              4315 	mov	r0,ar6
   0C25 86 06              4316 	mov	ar6,@r0
   0C27 D0 00              4317 	pop	ar0
                           4318 ;	genCast
   0C29 7F 00              4319 	mov	r7,#0x00
                           4320 ;	genMinus
   0C2B EE                 4321 	mov	a,r6
   0C2C 24 D0              4322 	add	a,#0xd0
   0C2E F5 82              4323 	mov	dpl,a
   0C30 EF                 4324 	mov	a,r7
   0C31 34 FF              4325 	addc	a,#0xff
   0C33 F5 83              4326 	mov	dph,a
                           4327 ;	genIpush
   0C35 C0 03              4328 	push	ar3
   0C37 C0 04              4329 	push	ar4
   0C39 C0 05              4330 	push	ar5
   0C3B C0 00              4331 	push	ar0
   0C3D C0 01              4332 	push	ar1
   0C3F 74 64              4333 	mov	a,#0x64
   0C41 C0 E0              4334 	push	acc
                           4335 ;	Peephole 181	changed mov to clr
   0C43 E4                 4336 	clr	a
   0C44 C0 E0              4337 	push	acc
                           4338 ;	genCall
   0C46 12 0E AF           4339 	lcall	__mulint
   0C49 AE 82              4340 	mov	r6,dpl
   0C4B AF 83              4341 	mov	r7,dph
   0C4D 15 81              4342 	dec	sp
   0C4F 15 81              4343 	dec	sp
   0C51 D0 01              4344 	pop	ar1
   0C53 D0 00              4345 	pop	ar0
   0C55 D0 05              4346 	pop	ar5
   0C57 D0 04              4347 	pop	ar4
   0C59 D0 03              4348 	pop	ar3
                           4349 ;	genPlus
   0C5B C0 00              4350 	push	ar0
   0C5D E5 08              4351 	mov	a,_bp
   0C5F 24 16              4352 	add	a,#0x16
   0C61 F8                 4353 	mov	r0,a
                           4354 ;	Peephole 236.g	used r6 instead of ar6
   0C62 EE                 4355 	mov	a,r6
                           4356 ;	Peephole 236.a	used r4 instead of ar4
   0C63 2C                 4357 	add	a,r4
   0C64 F6                 4358 	mov	@r0,a
                           4359 ;	Peephole 236.g	used r7 instead of ar7
   0C65 EF                 4360 	mov	a,r7
                           4361 ;	Peephole 236.b	used r5 instead of ar5
   0C66 3D                 4362 	addc	a,r5
   0C67 08                 4363 	inc	r0
   0C68 F6                 4364 	mov	@r0,a
   0C69 D0 00              4365 	pop	ar0
                           4366 ;	genPlus
                           4367 ;     genPlusIncr
   0C6B 74 0C              4368 	mov	a,#0x0C
                           4369 ;	Peephole 236.a	used r0 instead of ar0
   0C6D 28                 4370 	add	a,r0
   0C6E F9                 4371 	mov	r1,a
                           4372 ;	genPointerGet
                           4373 ;	genNearPointerGet
   0C6F 87 02              4374 	mov	ar2,@r1
                           4375 ;	genCast
   0C71 7E 00              4376 	mov	r6,#0x00
                           4377 ;	genMinus
   0C73 EA                 4378 	mov	a,r2
   0C74 24 D0              4379 	add	a,#0xd0
   0C76 F5 82              4380 	mov	dpl,a
   0C78 EE                 4381 	mov	a,r6
   0C79 34 FF              4382 	addc	a,#0xff
   0C7B F5 83              4383 	mov	dph,a
                           4384 ;	genIpush
   0C7D C0 03              4385 	push	ar3
   0C7F C0 00              4386 	push	ar0
   0C81 C0 01              4387 	push	ar1
   0C83 74 0A              4388 	mov	a,#0x0A
   0C85 C0 E0              4389 	push	acc
                           4390 ;	Peephole 181	changed mov to clr
   0C87 E4                 4391 	clr	a
   0C88 C0 E0              4392 	push	acc
                           4393 ;	genCall
   0C8A 12 0E AF           4394 	lcall	__mulint
   0C8D AA 82              4395 	mov	r2,dpl
   0C8F AE 83              4396 	mov	r6,dph
   0C91 15 81              4397 	dec	sp
   0C93 15 81              4398 	dec	sp
   0C95 D0 01              4399 	pop	ar1
   0C97 D0 00              4400 	pop	ar0
   0C99 D0 03              4401 	pop	ar3
                           4402 ;	genPlus
   0C9B C0 00              4403 	push	ar0
   0C9D E5 08              4404 	mov	a,_bp
   0C9F 24 16              4405 	add	a,#0x16
   0CA1 F8                 4406 	mov	r0,a
                           4407 ;	Peephole 236.g	used r2 instead of ar2
   0CA2 EA                 4408 	mov	a,r2
   0CA3 26                 4409 	add	a,@r0
   0CA4 FC                 4410 	mov	r4,a
                           4411 ;	Peephole 236.g	used r6 instead of ar6
   0CA5 EE                 4412 	mov	a,r6
   0CA6 08                 4413 	inc	r0
   0CA7 36                 4414 	addc	a,@r0
   0CA8 FD                 4415 	mov	r5,a
   0CA9 D0 00              4416 	pop	ar0
                           4417 ;	genPlus
                           4418 ;     genPlusIncr
   0CAB 74 0D              4419 	mov	a,#0x0D
                           4420 ;	Peephole 236.a	used r0 instead of ar0
   0CAD 28                 4421 	add	a,r0
   0CAE F9                 4422 	mov	r1,a
                           4423 ;	genPointerGet
                           4424 ;	genNearPointerGet
   0CAF 87 07              4425 	mov	ar7,@r1
                           4426 ;	genCast
   0CB1 7A 00              4427 	mov	r2,#0x00
                           4428 ;	genMinus
   0CB3 EF                 4429 	mov	a,r7
   0CB4 24 D0              4430 	add	a,#0xd0
   0CB6 FF                 4431 	mov	r7,a
   0CB7 EA                 4432 	mov	a,r2
   0CB8 34 FF              4433 	addc	a,#0xff
   0CBA FA                 4434 	mov	r2,a
                           4435 ;	genPlus
                           4436 ;	Peephole 236.g	used r7 instead of ar7
   0CBB EF                 4437 	mov	a,r7
                           4438 ;	Peephole 236.a	used r4 instead of ar4
   0CBC 2C                 4439 	add	a,r4
   0CBD FF                 4440 	mov	r7,a
                           4441 ;	Peephole 236.g	used r2 instead of ar2
   0CBE EA                 4442 	mov	a,r2
                           4443 ;	Peephole 236.b	used r5 instead of ar5
   0CBF 3D                 4444 	addc	a,r5
   0CC0 FA                 4445 	mov	r2,a
                           4446 ;	genAssign
   0CC1 8F 04              4447 	mov	ar4,r7
   0CC3 8A 05              4448 	mov	ar5,r2
                           4449 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:66: telegramm[0]=0xBC;
                           4450 ;	genPointerSet
                           4451 ;	genNearPointerSet
                           4452 ;	genDataPointerSet
   0CC5 75 22 BC           4453 	mov	_telegramm,#0xBC
                           4454 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:67: telegramm[1]=pah;
                           4455 ;	genPointerSet
                           4456 ;	genNearPointerSet
                           4457 ;	genDataPointerSet
   0CC8 85 3C 23           4458 	mov	(_telegramm + 0x0001),_pah
                           4459 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:68: telegramm[2]=pal;
                           4460 ;	genPointerSet
                           4461 ;	genNearPointerSet
                           4462 ;	genDataPointerSet
   0CCB 85 3B 24           4463 	mov	(_telegramm + 0x0002),_pal
                           4464 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:69: telegramm[3]=groupadr>>8;
                           4465 ;	genGetByte
   0CCE 8D 02              4466 	mov	ar2,r5
                           4467 ;	genPointerSet
                           4468 ;	genNearPointerSet
                           4469 ;	genDataPointerSet
   0CD0 8A 25              4470 	mov	(_telegramm + 0x0003),r2
                           4471 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:70: telegramm[4]=groupadr;
                           4472 ;	genCast
                           4473 ;	genPointerSet
                           4474 ;	genNearPointerSet
                           4475 ;	genDataPointerSet
   0CD2 8C 26              4476 	mov	(_telegramm + 0x0004),r4
                           4477 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:71: telegramm[5]=0xE1;
                           4478 ;	genPointerSet
                           4479 ;	genNearPointerSet
                           4480 ;	genDataPointerSet
   0CD4 75 27 E1           4481 	mov	(_telegramm + 0x0005),#0xE1
                           4482 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:72: telegramm[6]=0x00;
                           4483 ;	genPointerSet
                           4484 ;	genNearPointerSet
                           4485 ;	genDataPointerSet
   0CD7 75 28 00           4486 	mov	(_telegramm + 0x0006),#0x00
                           4487 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:73: if (rsin[15]=='1') telegramm[7]=0x81;
                           4488 ;	genPointerGet
                           4489 ;	genNearPointerGet
   0CDA C0 00              4490 	push	ar0
   0CDC A8 03              4491 	mov	r0,ar3
   0CDE 86 02              4492 	mov	ar2,@r0
   0CE0 D0 00              4493 	pop	ar0
                           4494 ;	genCmpEq
                           4495 ;	gencjne
                           4496 ;	gencjneshort
                           4497 ;	Peephole 241.d	optimized compare
   0CE2 E4                 4498 	clr	a
   0CE3 BA 31 01           4499 	cjne	r2,#0x31,00245$
   0CE6 04                 4500 	inc	a
   0CE7                    4501 00245$:
                           4502 ;	Peephole 300	removed redundant label 00246$
                           4503 ;	genIpop
   0CE7 D0 01              4504 	pop	ar1
                           4505 ;	genIfx
                           4506 ;	genIfxJump
                           4507 ;	Peephole 108.c	removed ljmp by inverse jump logic
   0CE9 60 03              4508 	jz	00110$
                           4509 ;	Peephole 300	removed redundant label 00247$
                           4510 ;	genPointerSet
                           4511 ;	genNearPointerSet
                           4512 ;	genDataPointerSet
   0CEB 75 29 81           4513 	mov	(_telegramm + 0x0007),#0x81
   0CEE                    4514 00110$:
                           4515 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:74: if (rsin[15]=='0') telegramm[7]=0x80;
                           4516 ;	genPointerGet
                           4517 ;	genNearPointerGet
   0CEE C0 00              4518 	push	ar0
   0CF0 A8 03              4519 	mov	r0,ar3
   0CF2 86 02              4520 	mov	ar2,@r0
   0CF4 D0 00              4521 	pop	ar0
                           4522 ;	genCmpEq
                           4523 ;	gencjneshort
                           4524 ;	Peephole 112.b	changed ljmp to sjmp
                           4525 ;	Peephole 198.b	optimized misc jump sequence
   0CF6 BA 30 03           4526 	cjne	r2,#0x30,00112$
                           4527 ;	Peephole 200.b	removed redundant sjmp
                           4528 ;	Peephole 300	removed redundant label 00248$
                           4529 ;	Peephole 300	removed redundant label 00249$
                           4530 ;	genPointerSet
                           4531 ;	genNearPointerSet
                           4532 ;	genDataPointerSet
   0CF9 75 29 80           4533 	mov	(_telegramm + 0x0007),#0x80
   0CFC                    4534 00112$:
                           4535 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:75: EX1=0;
                           4536 ;	genAssign
   0CFC C2 AA              4537 	clr	_IEN0_2
                           4538 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:76: send_telegramm();
                           4539 ;	genCall
   0CFE C0 00              4540 	push	ar0
   0D00 C0 01              4541 	push	ar1
   0D02 12 04 D8           4542 	lcall	_send_telegramm
   0D05 D0 01              4543 	pop	ar1
   0D07 D0 00              4544 	pop	ar0
                           4545 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:77: EX1=1;
                           4546 ;	genAssign
   0D09 D2 AA              4547 	setb	_IEN0_2
                           4548 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:78: rs_send_ok();
                           4549 ;	genCall
   0D0B C0 00              4550 	push	ar0
   0D0D C0 01              4551 	push	ar1
   0D0F 12 0A 13           4552 	lcall	_rs_send_ok
   0D12 D0 01              4553 	pop	ar1
   0D14 D0 00              4554 	pop	ar0
   0D16                    4555 00114$:
                           4556 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:80: if(rsin[2]=='r' && rsin[3]=='p' && rsin[4]=='a')	// physikalische Adresse des Adaptrs lesen (fbrpa)
                           4557 ;	genPointerGet
                           4558 ;	genNearPointerGet
   0D16 87 02              4559 	mov	ar2,@r1
                           4560 ;	genCmpEq
                           4561 ;	gencjneshort
                           4562 ;	Peephole 112.b	changed ljmp to sjmp
                           4563 ;	Peephole 198.b	optimized misc jump sequence
   0D18 BA 72 6F           4564 	cjne	r2,#0x72,00136$
                           4565 ;	Peephole 200.b	removed redundant sjmp
                           4566 ;	Peephole 300	removed redundant label 00250$
                           4567 ;	Peephole 300	removed redundant label 00251$
                           4568 ;	genPlus
                           4569 ;     genPlusIncr
   0D1B 74 03              4570 	mov	a,#0x03
                           4571 ;	Peephole 236.a	used r0 instead of ar0
   0D1D 28                 4572 	add	a,r0
   0D1E FA                 4573 	mov	r2,a
                           4574 ;	genPointerGet
                           4575 ;	genNearPointerGet
   0D1F C0 00              4576 	push	ar0
   0D21 A8 02              4577 	mov	r0,ar2
   0D23 86 02              4578 	mov	ar2,@r0
   0D25 D0 00              4579 	pop	ar0
                           4580 ;	genCmpEq
                           4581 ;	gencjneshort
                           4582 ;	Peephole 112.b	changed ljmp to sjmp
                           4583 ;	Peephole 198.b	optimized misc jump sequence
   0D27 BA 70 60           4584 	cjne	r2,#0x70,00136$
                           4585 ;	Peephole 200.b	removed redundant sjmp
                           4586 ;	Peephole 300	removed redundant label 00252$
                           4587 ;	Peephole 300	removed redundant label 00253$
                           4588 ;	genPlus
                           4589 ;     genPlusIncr
   0D2A 74 04              4590 	mov	a,#0x04
                           4591 ;	Peephole 236.a	used r0 instead of ar0
   0D2C 28                 4592 	add	a,r0
   0D2D FA                 4593 	mov	r2,a
                           4594 ;	genPointerGet
                           4595 ;	genNearPointerGet
   0D2E C0 00              4596 	push	ar0
   0D30 A8 02              4597 	mov	r0,ar2
   0D32 86 02              4598 	mov	ar2,@r0
   0D34 D0 00              4599 	pop	ar0
                           4600 ;	genCmpEq
                           4601 ;	gencjneshort
                           4602 ;	Peephole 112.b	changed ljmp to sjmp
                           4603 ;	Peephole 198.b	optimized misc jump sequence
   0D36 BA 61 51           4604 	cjne	r2,#0x61,00136$
                           4605 ;	Peephole 200.b	removed redundant sjmp
                           4606 ;	Peephole 300	removed redundant label 00254$
                           4607 ;	Peephole 300	removed redundant label 00255$
                           4608 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:82: rs_send_dec(pah>>4);
                           4609 ;	genRightShift
                           4610 ;	genRightShiftLiteral
                           4611 ;	genrshOne
   0D39 E5 3C              4612 	mov	a,_pah
   0D3B C4                 4613 	swap	a
   0D3C 54 0F              4614 	anl	a,#0x0f
   0D3E F5 82              4615 	mov	dpl,a
                           4616 ;	genCall
   0D40 C0 00              4617 	push	ar0
   0D42 C0 01              4618 	push	ar1
   0D44 12 09 D0           4619 	lcall	_rs_send_dec
   0D47 D0 01              4620 	pop	ar1
   0D49 D0 00              4621 	pop	ar0
                           4622 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:83: SBUF='.';
                           4623 ;	genAssign
   0D4B 75 99 2E           4624 	mov	_SBUF,#0x2E
                           4625 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:84: while(!TI);
   0D4E                    4626 00123$:
                           4627 ;	genIfx
                           4628 ;	genIfxJump
                           4629 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           4630 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:85: TI=0;
                           4631 ;	genAssign
                           4632 ;	Peephole 250.a	using atomic test and clear
   0D4E 10 99 02           4633 	jbc	_SCON_1,00256$
   0D51 80 FB              4634 	sjmp	00123$
   0D53                    4635 00256$:
                           4636 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:86: rs_send_dec(pah&0x0F);
                           4637 ;	genAnd
   0D53 74 0F              4638 	mov	a,#0x0F
   0D55 55 3C              4639 	anl	a,_pah
   0D57 F5 82              4640 	mov	dpl,a
                           4641 ;	genCall
   0D59 C0 00              4642 	push	ar0
   0D5B C0 01              4643 	push	ar1
   0D5D 12 09 D0           4644 	lcall	_rs_send_dec
   0D60 D0 01              4645 	pop	ar1
   0D62 D0 00              4646 	pop	ar0
                           4647 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:87: SBUF='.';
                           4648 ;	genAssign
   0D64 75 99 2E           4649 	mov	_SBUF,#0x2E
                           4650 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:88: while(!TI);
   0D67                    4651 00126$:
                           4652 ;	genIfx
                           4653 ;	genIfxJump
                           4654 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           4655 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:89: TI=0;
                           4656 ;	genAssign
                           4657 ;	Peephole 250.a	using atomic test and clear
   0D67 10 99 02           4658 	jbc	_SCON_1,00257$
   0D6A 80 FB              4659 	sjmp	00126$
   0D6C                    4660 00257$:
                           4661 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:90: rs_send_dec(pal);
                           4662 ;	genCall
   0D6C 85 3B 82           4663 	mov	dpl,_pal
   0D6F C0 00              4664 	push	ar0
   0D71 C0 01              4665 	push	ar1
   0D73 12 09 D0           4666 	lcall	_rs_send_dec
   0D76 D0 01              4667 	pop	ar1
   0D78 D0 00              4668 	pop	ar0
                           4669 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:91: SBUF=0x0D;
                           4670 ;	genAssign
   0D7A 75 99 0D           4671 	mov	_SBUF,#0x0D
                           4672 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:92: while(!TI);
   0D7D                    4673 00129$:
                           4674 ;	genIfx
                           4675 ;	genIfxJump
                           4676 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           4677 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:93: TI=0;
                           4678 ;	genAssign
                           4679 ;	Peephole 250.a	using atomic test and clear
   0D7D 10 99 02           4680 	jbc	_SCON_1,00258$
   0D80 80 FB              4681 	sjmp	00129$
   0D82                    4682 00258$:
                           4683 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:94: SBUF=0x0A;
                           4684 ;	genAssign
   0D82 75 99 0A           4685 	mov	_SBUF,#0x0A
                           4686 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:95: while(!TI);
   0D85                    4687 00132$:
                           4688 ;	genIfx
                           4689 ;	genIfxJump
                           4690 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           4691 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:96: TI=0;
                           4692 ;	genAssign
                           4693 ;	Peephole 250.a	using atomic test and clear
   0D85 10 99 02           4694 	jbc	_SCON_1,00259$
   0D88 80 FB              4695 	sjmp	00132$
   0D8A                    4696 00259$:
   0D8A                    4697 00136$:
                           4698 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:98: if(rsin[2]=='s' && rsin[3]=='p' && rsin[4]=='a' && rsin[7]=='.' && rsin[10]=='.' && rsinpos==14)	// phys. Adresse des Adapters setzen (fbspaxx.xx.xxx)
                           4699 ;	genPointerGet
                           4700 ;	genNearPointerGet
   0D8A 87 02              4701 	mov	ar2,@r1
                           4702 ;	genCmpEq
                           4703 ;	gencjneshort
   0D8C BA 73 02           4704 	cjne	r2,#0x73,00260$
   0D8F 80 03              4705 	sjmp	00261$
   0D91                    4706 00260$:
   0D91 02 0E 77           4707 	ljmp	00206$
   0D94                    4708 00261$:
                           4709 ;	genPlus
                           4710 ;     genPlusIncr
   0D94 74 03              4711 	mov	a,#0x03
                           4712 ;	Peephole 236.a	used r0 instead of ar0
   0D96 28                 4713 	add	a,r0
   0D97 F9                 4714 	mov	r1,a
                           4715 ;	genPointerGet
                           4716 ;	genNearPointerGet
   0D98 87 02              4717 	mov	ar2,@r1
                           4718 ;	genCmpEq
                           4719 ;	gencjneshort
   0D9A BA 70 02           4720 	cjne	r2,#0x70,00262$
   0D9D 80 03              4721 	sjmp	00263$
   0D9F                    4722 00262$:
   0D9F 02 0E 77           4723 	ljmp	00206$
   0DA2                    4724 00263$:
                           4725 ;	genPlus
                           4726 ;     genPlusIncr
   0DA2 74 04              4727 	mov	a,#0x04
                           4728 ;	Peephole 236.a	used r0 instead of ar0
   0DA4 28                 4729 	add	a,r0
   0DA5 F9                 4730 	mov	r1,a
                           4731 ;	genPointerGet
                           4732 ;	genNearPointerGet
   0DA6 87 02              4733 	mov	ar2,@r1
                           4734 ;	genCmpEq
                           4735 ;	gencjneshort
   0DA8 BA 61 02           4736 	cjne	r2,#0x61,00264$
   0DAB 80 03              4737 	sjmp	00265$
   0DAD                    4738 00264$:
   0DAD 02 0E 77           4739 	ljmp	00206$
   0DB0                    4740 00265$:
                           4741 ;	genPlus
                           4742 ;     genPlusIncr
   0DB0 74 07              4743 	mov	a,#0x07
                           4744 ;	Peephole 236.a	used r0 instead of ar0
   0DB2 28                 4745 	add	a,r0
   0DB3 F9                 4746 	mov	r1,a
                           4747 ;	genPointerGet
                           4748 ;	genNearPointerGet
   0DB4 87 02              4749 	mov	ar2,@r1
                           4750 ;	genCmpEq
                           4751 ;	gencjneshort
   0DB6 BA 2E 02           4752 	cjne	r2,#0x2E,00266$
   0DB9 80 03              4753 	sjmp	00267$
   0DBB                    4754 00266$:
   0DBB 02 0E 77           4755 	ljmp	00206$
   0DBE                    4756 00267$:
                           4757 ;	genPlus
                           4758 ;     genPlusIncr
   0DBE 74 0A              4759 	mov	a,#0x0A
                           4760 ;	Peephole 236.a	used r0 instead of ar0
   0DC0 28                 4761 	add	a,r0
   0DC1 F9                 4762 	mov	r1,a
                           4763 ;	genPointerGet
                           4764 ;	genNearPointerGet
   0DC2 87 02              4765 	mov	ar2,@r1
                           4766 ;	genCmpEq
                           4767 ;	gencjneshort
   0DC4 BA 2E 02           4768 	cjne	r2,#0x2E,00268$
   0DC7 80 03              4769 	sjmp	00269$
   0DC9                    4770 00268$:
   0DC9 02 0E 77           4771 	ljmp	00206$
   0DCC                    4772 00269$:
                           4773 ;	genCmpEq
   0DCC A9 08              4774 	mov	r1,_bp
   0DCE 09                 4775 	inc	r1
                           4776 ;	gencjneshort
   0DCF B7 0E 02           4777 	cjne	@r1,#0x0E,00270$
   0DD2 80 03              4778 	sjmp	00271$
   0DD4                    4779 00270$:
   0DD4 02 0E 77           4780 	ljmp	00206$
   0DD7                    4781 00271$:
                           4782 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:100: pah=(((rsin[5]-48)*10) + (rsin[6]-48))*16;
                           4783 ;	genPlus
                           4784 ;     genPlusIncr
   0DD7 74 05              4785 	mov	a,#0x05
                           4786 ;	Peephole 236.a	used r0 instead of ar0
   0DD9 28                 4787 	add	a,r0
   0DDA F9                 4788 	mov	r1,a
                           4789 ;	genPointerGet
                           4790 ;	genNearPointerGet
   0DDB 87 02              4791 	mov	ar2,@r1
                           4792 ;	genMinus
   0DDD EA                 4793 	mov	a,r2
   0DDE 24 D0              4794 	add	a,#0xd0
                           4795 ;	genMult
                           4796 ;	genMultOneByte
   0DE0 75 F0 0A           4797 	mov	b,#0x0A
   0DE3 A4                 4798 	mul	ab
   0DE4 FA                 4799 	mov	r2,a
                           4800 ;	genPlus
                           4801 ;     genPlusIncr
   0DE5 74 06              4802 	mov	a,#0x06
                           4803 ;	Peephole 236.a	used r0 instead of ar0
   0DE7 28                 4804 	add	a,r0
   0DE8 F9                 4805 	mov	r1,a
                           4806 ;	genPointerGet
                           4807 ;	genNearPointerGet
   0DE9 87 03              4808 	mov	ar3,@r1
                           4809 ;	genMinus
   0DEB EB                 4810 	mov	a,r3
   0DEC 24 D0              4811 	add	a,#0xd0
                           4812 ;	genPlus
                           4813 ;	Peephole 236.a	used r2 instead of ar2
   0DEE 2A                 4814 	add	a,r2
                           4815 ;	genLeftShift
                           4816 ;	genLeftShiftLiteral
                           4817 ;	genlshOne
   0DEF FA                 4818 	mov	r2,a
                           4819 ;	Peephole 105	removed redundant mov
   0DF0 C4                 4820 	swap	a
   0DF1 54 F0              4821 	anl	a,#0xf0
   0DF3 F5 3C              4822 	mov	_pah,a
                           4823 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:101: pah=pah + (((rsin[8]-48)*10) + (rsin[9]-48));
                           4824 ;	genPlus
                           4825 ;     genPlusIncr
   0DF5 74 08              4826 	mov	a,#0x08
                           4827 ;	Peephole 236.a	used r0 instead of ar0
   0DF7 28                 4828 	add	a,r0
   0DF8 F9                 4829 	mov	r1,a
                           4830 ;	genPointerGet
                           4831 ;	genNearPointerGet
   0DF9 87 02              4832 	mov	ar2,@r1
                           4833 ;	genMinus
   0DFB EA                 4834 	mov	a,r2
   0DFC 24 D0              4835 	add	a,#0xd0
                           4836 ;	genMult
                           4837 ;	genMultOneByte
   0DFE 75 F0 0A           4838 	mov	b,#0x0A
   0E01 A4                 4839 	mul	ab
   0E02 FA                 4840 	mov	r2,a
                           4841 ;	genPlus
                           4842 ;     genPlusIncr
   0E03 74 09              4843 	mov	a,#0x09
                           4844 ;	Peephole 236.a	used r0 instead of ar0
   0E05 28                 4845 	add	a,r0
   0E06 F9                 4846 	mov	r1,a
                           4847 ;	genPointerGet
                           4848 ;	genNearPointerGet
   0E07 87 03              4849 	mov	ar3,@r1
                           4850 ;	genMinus
   0E09 EB                 4851 	mov	a,r3
   0E0A 24 D0              4852 	add	a,#0xd0
                           4853 ;	genPlus
                           4854 ;	Peephole 236.a	used r2 instead of ar2
   0E0C 2A                 4855 	add	a,r2
                           4856 ;	genPlus
   0E0D 25 3C              4857 	add	a,_pah
   0E0F F5 3C              4858 	mov	_pah,a
                           4859 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:102: pal=(((rsin[11]-48)*100) + ((rsin[12]-48)*10) + (rsin[13]-48));
                           4860 ;	genPlus
                           4861 ;     genPlusIncr
   0E11 74 0B              4862 	mov	a,#0x0B
                           4863 ;	Peephole 236.a	used r0 instead of ar0
   0E13 28                 4864 	add	a,r0
   0E14 F9                 4865 	mov	r1,a
                           4866 ;	genPointerGet
                           4867 ;	genNearPointerGet
   0E15 87 02              4868 	mov	ar2,@r1
                           4869 ;	genMinus
   0E17 EA                 4870 	mov	a,r2
   0E18 24 D0              4871 	add	a,#0xd0
                           4872 ;	genMult
                           4873 ;	genMultOneByte
   0E1A 75 F0 64           4874 	mov	b,#0x64
   0E1D A4                 4875 	mul	ab
   0E1E FA                 4876 	mov	r2,a
                           4877 ;	genPlus
                           4878 ;     genPlusIncr
   0E1F 74 0C              4879 	mov	a,#0x0C
                           4880 ;	Peephole 236.a	used r0 instead of ar0
   0E21 28                 4881 	add	a,r0
   0E22 F9                 4882 	mov	r1,a
                           4883 ;	genPointerGet
                           4884 ;	genNearPointerGet
   0E23 87 03              4885 	mov	ar3,@r1
                           4886 ;	genMinus
   0E25 EB                 4887 	mov	a,r3
   0E26 24 D0              4888 	add	a,#0xd0
                           4889 ;	genMult
                           4890 ;	genMultOneByte
   0E28 75 F0 0A           4891 	mov	b,#0x0A
   0E2B A4                 4892 	mul	ab
                           4893 ;	genPlus
                           4894 ;	Peephole 236.a	used r2 instead of ar2
   0E2C 2A                 4895 	add	a,r2
   0E2D FA                 4896 	mov	r2,a
                           4897 ;	genPlus
                           4898 ;     genPlusIncr
   0E2E 74 0D              4899 	mov	a,#0x0D
                           4900 ;	Peephole 236.a	used r0 instead of ar0
   0E30 28                 4901 	add	a,r0
   0E31 F9                 4902 	mov	r1,a
                           4903 ;	genPointerGet
                           4904 ;	genNearPointerGet
   0E32 87 03              4905 	mov	ar3,@r1
                           4906 ;	genMinus
   0E34 EB                 4907 	mov	a,r3
   0E35 24 D0              4908 	add	a,#0xd0
                           4909 ;	genPlus
                           4910 ;	Peephole 236.a	used r2 instead of ar2
   0E37 2A                 4911 	add	a,r2
   0E38 F5 3B              4912 	mov	_pal,a
                           4913 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:103: start_writecycle();
                           4914 ;	genCall
   0E3A C0 00              4915 	push	ar0
   0E3C 12 02 70           4916 	lcall	_start_writecycle
   0E3F D0 00              4917 	pop	ar0
                           4918 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:104: write_byte(0x01,ADDRTAB+1,pah);		// in Flash schreiben
                           4919 ;	genIpush
   0E41 C0 00              4920 	push	ar0
   0E43 C0 3C              4921 	push	_pah
                           4922 ;	genIpush
   0E45 74 17              4923 	mov	a,#0x17
   0E47 C0 E0              4924 	push	acc
                           4925 ;	genCall
   0E49 75 82 01           4926 	mov	dpl,#0x01
   0E4C 12 02 78           4927 	lcall	_write_byte
   0E4F 15 81              4928 	dec	sp
   0E51 15 81              4929 	dec	sp
   0E53 D0 00              4930 	pop	ar0
                           4931 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:105: write_byte(0x01,ADDRTAB+2,pal);
                           4932 ;	genIpush
   0E55 C0 00              4933 	push	ar0
   0E57 C0 3B              4934 	push	_pal
                           4935 ;	genIpush
   0E59 74 18              4936 	mov	a,#0x18
   0E5B C0 E0              4937 	push	acc
                           4938 ;	genCall
   0E5D 75 82 01           4939 	mov	dpl,#0x01
   0E60 12 02 78           4940 	lcall	_write_byte
   0E63 15 81              4941 	dec	sp
   0E65 15 81              4942 	dec	sp
   0E67 D0 00              4943 	pop	ar0
                           4944 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:106: stop_writecycle();
                           4945 ;	genCall
   0E69 C0 00              4946 	push	ar0
   0E6B 12 02 74           4947 	lcall	_stop_writecycle
   0E6E D0 00              4948 	pop	ar0
                           4949 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:107: rs_send_ok();
                           4950 ;	genCall
   0E70 C0 00              4951 	push	ar0
   0E72 12 0A 13           4952 	lcall	_rs_send_ok
   0E75 D0 00              4953 	pop	ar0
                           4954 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:110: for(n=0;n<20;n++) rsin[n]=0x00;
   0E77                    4955 00206$:
                           4956 ;	genAssign
   0E77 7A 00              4957 	mov	r2,#0x00
   0E79                    4958 00159$:
                           4959 ;	genCmpLt
                           4960 ;	genCmp
   0E79 BA 14 00           4961 	cjne	r2,#0x14,00272$
   0E7C                    4962 00272$:
                           4963 ;	genIfxJump
                           4964 ;	Peephole 108.a	removed ljmp by inverse jump logic
   0E7C 50 08              4965 	jnc	00162$
                           4966 ;	Peephole 300	removed redundant label 00273$
                           4967 ;	genPlus
                           4968 ;	Peephole 236.g	used r2 instead of ar2
   0E7E EA                 4969 	mov	a,r2
                           4970 ;	Peephole 236.a	used r0 instead of ar0
   0E7F 28                 4971 	add	a,r0
   0E80 F9                 4972 	mov	r1,a
                           4973 ;	genPointerSet
                           4974 ;	genNearPointerSet
   0E81 77 00              4975 	mov	@r1,#0x00
                           4976 ;	genPlus
                           4977 ;     genPlusIncr
   0E83 0A                 4978 	inc	r2
                           4979 ;	Peephole 112.b	changed ljmp to sjmp
   0E84 80 F3              4980 	sjmp	00159$
   0E86                    4981 00162$:
                           4982 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:111: rsinpos=0;
                           4983 ;	genAssign
   0E86 A8 08              4984 	mov	r0,_bp
   0E88 08                 4985 	inc	r0
   0E89 76 00              4986 	mov	@r0,#0x00
                           4987 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:112: cr_received=0;
                           4988 ;	genAssign
   0E8B C2 08              4989 	clr	b0
                           4990 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:113: crlf_received=0;
                           4991 ;	genAssign
   0E8D C2 09              4992 	clr	b1
   0E8F                    4993 00150$:
                           4994 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:117: TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
                           4995 ;	genAssign
   0E8F D2 97              4996 	setb	_P1_7
                           4997 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:118: if(!TASTER) {			// Taster gedrückt
                           4998 ;	genIfx
                           4999 ;	genIfxJump
                           5000 ;	Peephole 108.e	removed ljmp by inverse jump logic
   0E91 20 97 09           5001 	jb	_P1_7,00155$
                           5002 ;	Peephole 300	removed redundant label 00274$
                           5003 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:119: for(n=0;n<100;n++) {}
                           5004 ;	genAssign
   0E94 7A 64              5005 	mov	r2,#0x64
   0E96                    5006 00165$:
                           5007 ;	genDjnz
                           5008 ;	Peephole 112.b	changed ljmp to sjmp
                           5009 ;	Peephole 205	optimized misc jump sequence
   0E96 DA FE              5010 	djnz	r2,00165$
                           5011 ;	Peephole 300	removed redundant label 00275$
                           5012 ;	Peephole 300	removed redundant label 00276$
                           5013 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:120: while(!TASTER);			// warten bis Taster losgelassen
   0E98                    5014 00151$:
                           5015 ;	genIfx
                           5016 ;	genIfxJump
                           5017 ;	Peephole 108.d	removed ljmp by inverse jump logic
   0E98 30 97 FD           5018 	jnb	_P1_7,00151$
                           5019 ;	Peephole 300	removed redundant label 00277$
                           5020 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:121: progmode=!progmode;
                           5021 ;	genNot
   0E9B B2 01              5022 	cpl	_progmode
   0E9D                    5023 00155$:
                           5024 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:123: TASTER=!progmode;			// LED entsprechend schalten (low=LED an)
                           5025 ;	genNot
   0E9D A2 01              5026 	mov	c,_progmode
   0E9F B3                 5027 	cpl	c
   0EA0 92 97              5028 	mov	_P1_7,c
                           5029 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:124: for(n=0;n<100;n++) {}
                           5030 ;	genAssign
   0EA2 7A 64              5031 	mov	r2,#0x64
   0EA4                    5032 00168$:
                           5033 ;	genDjnz
                           5034 ;	Peephole 112.b	changed ljmp to sjmp
                           5035 ;	Peephole 205	optimized misc jump sequence
   0EA4 DA FE              5036 	djnz	r2,00168$
                           5037 ;	Peephole 300	removed redundant label 00278$
                           5038 ;	Peephole 300	removed redundant label 00279$
                           5039 ;	D:/freebus/trunk/c51/89LPC922/RS232I~1/fb_rs.c:125: } while(1);
   0EA6 02 0A AA           5040 	ljmp	00156$
                           5041 ;	Peephole 300	removed redundant label 00169$
   0EA9 85 08 81           5042 	mov	sp,_bp
   0EAC D0 08              5043 	pop	_bp
   0EAE 22                 5044 	ret
                           5045 	.area CSEG    (CODE)
                           5046 	.area CONST   (CODE)
                    1C00   5047 _dataflash	=	0x1c00
                           5048 	.area XINIT   (CODE)
