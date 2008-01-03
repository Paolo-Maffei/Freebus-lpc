                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : FreeWare ANSI-C Compiler
                              3 ; Version 2.6.1 #4376 (Sep 14 2006)
                              4 ; This file generated Sat Dec 01 23:28:55 2007
                              5 ;--------------------------------------------------------
                              6 	.module fb_in8
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _dataflash
                             13 	.globl _main
                             14 	.globl _pin_changed
                             15 	.globl _find_ga
                             16 	.globl _get_ack
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
                             79 	.globl _CY
                             80 	.globl _AC
                             81 	.globl _F0
                             82 	.globl _RS1
                             83 	.globl _RS0
                             84 	.globl _OV
                             85 	.globl _F1
                             86 	.globl _P
                             87 	.globl _PSW_7
                             88 	.globl _PSW_6
                             89 	.globl _PSW_5
                             90 	.globl _PSW_4
                             91 	.globl _PSW_3
                             92 	.globl _PSW_2
                             93 	.globl _PSW_1
                             94 	.globl _PSW_0
                             95 	.globl _IEN1
                             96 	.globl _IP0H
                             97 	.globl _WFEED2
                             98 	.globl _WFEED1
                             99 	.globl _WDL
                            100 	.globl _WDCON
                            101 	.globl _TRIM
                            102 	.globl _TAMOD
                            103 	.globl _SSTAT
                            104 	.globl _RTCL
                            105 	.globl _RTCH
                            106 	.globl _RTCCON
                            107 	.globl _RSTSRC
                            108 	.globl _PT0AD
                            109 	.globl _PCONA
                            110 	.globl _P3M2
                            111 	.globl _P3M1
                            112 	.globl _P1M2
                            113 	.globl _P1M1
                            114 	.globl _P0M2
                            115 	.globl _P0M1
                            116 	.globl _KBPATN
                            117 	.globl _KBMASK
                            118 	.globl _KBCON
                            119 	.globl _IP1H
                            120 	.globl _IP1
                            121 	.globl _I2STAT
                            122 	.globl _I2SCLL
                            123 	.globl _I2SCLH
                            124 	.globl _I2DAT
                            125 	.globl _I2CON
                            126 	.globl _I2ADR
                            127 	.globl _FMDATA
                            128 	.globl _FMCON
                            129 	.globl _FMADRL
                            130 	.globl _FMADRH
                            131 	.globl _DIVM
                            132 	.globl _CMP2
                            133 	.globl _CMP1
                            134 	.globl _BRGCON
                            135 	.globl _BRGR1
                            136 	.globl _BRGR0
                            137 	.globl _SADEN
                            138 	.globl _SADDR
                            139 	.globl _AUXR1
                            140 	.globl _SBUF
                            141 	.globl _SCON
                            142 	.globl _IP0
                            143 	.globl _IEN0
                            144 	.globl _TH1
                            145 	.globl _TH0
                            146 	.globl _TL1
                            147 	.globl _TL0
                            148 	.globl _TMOD
                            149 	.globl _TCON
                            150 	.globl _PCON
                            151 	.globl _DPH
                            152 	.globl _DPL
                            153 	.globl _SP
                            154 	.globl _B
                            155 	.globl _ACC
                            156 	.globl _PSW
                            157 	.globl _P3
                            158 	.globl _P1
                            159 	.globl _P0
                            160 	.globl _connected
                            161 	.globl _progmode
                            162 	.globl _parity_ok
                            163 	.globl _pdir
                            164 	.globl _timer
                            165 	.globl _objstate
                            166 	.globl _p0h
                            167 	.globl _portbuffer
                            168 	.globl _pcount
                            169 	.globl _conl
                            170 	.globl _conh
                            171 	.globl _gacount
                            172 	.globl _pah
                            173 	.globl _pal
                            174 	.globl _cs
                            175 	.globl _telpos
                            176 	.globl _telegramm
                            177 	.globl _get_byte
                            178 	.globl _ext_int0
                            179 	.globl _sendbyte
                            180 	.globl _start_writecycle
                            181 	.globl _stop_writecycle
                            182 	.globl _write_byte
                            183 	.globl _delay
                            184 	.globl _set_timer1
                            185 	.globl _read_byte
                            186 	.globl _restart_hw
                            187 	.globl _timer1
                            188 	.globl _send_telegramm
                            189 	.globl _send_ack
                            190 	.globl _ucd_opr
                            191 	.globl _ucd_clr
                            192 	.globl _ncd_quit
                            193 	.globl _read_masq
                            194 	.globl _read_memory
                            195 	.globl _write_memory
                            196 	.globl _set_pa
                            197 	.globl _read_pa
                            198 	.globl _read_objflags
                            199 	.globl _gapos_in_gat
                            200 	.globl _write_delay_record
                            201 	.globl _restart_prot
                            202 	.globl _send_cyclic
                            203 	.globl _operation
                            204 	.globl _switch_dim
                            205 	.globl _schalten
                            206 	.globl _pin_function
                            207 	.globl _debounce
                            208 	.globl _eis1
                            209 	.globl _delay_timer
                            210 	.globl _restart_app
                            211 ;--------------------------------------------------------
                            212 ; special function registers
                            213 ;--------------------------------------------------------
                            214 	.area RSEG    (DATA)
                    0080    215 _P0	=	0x0080
                    0090    216 _P1	=	0x0090
                    00B0    217 _P3	=	0x00b0
                    00D0    218 _PSW	=	0x00d0
                    00E0    219 _ACC	=	0x00e0
                    00F0    220 _B	=	0x00f0
                    0081    221 _SP	=	0x0081
                    0082    222 _DPL	=	0x0082
                    0083    223 _DPH	=	0x0083
                    0087    224 _PCON	=	0x0087
                    0088    225 _TCON	=	0x0088
                    0089    226 _TMOD	=	0x0089
                    008A    227 _TL0	=	0x008a
                    008B    228 _TL1	=	0x008b
                    008C    229 _TH0	=	0x008c
                    008D    230 _TH1	=	0x008d
                    00A8    231 _IEN0	=	0x00a8
                    00B8    232 _IP0	=	0x00b8
                    0098    233 _SCON	=	0x0098
                    0099    234 _SBUF	=	0x0099
                    00A2    235 _AUXR1	=	0x00a2
                    00A9    236 _SADDR	=	0x00a9
                    00B9    237 _SADEN	=	0x00b9
                    00BE    238 _BRGR0	=	0x00be
                    00BF    239 _BRGR1	=	0x00bf
                    00BD    240 _BRGCON	=	0x00bd
                    00AC    241 _CMP1	=	0x00ac
                    00AD    242 _CMP2	=	0x00ad
                    0095    243 _DIVM	=	0x0095
                    00E7    244 _FMADRH	=	0x00e7
                    00E6    245 _FMADRL	=	0x00e6
                    00E4    246 _FMCON	=	0x00e4
                    00E5    247 _FMDATA	=	0x00e5
                    00DB    248 _I2ADR	=	0x00db
                    00D8    249 _I2CON	=	0x00d8
                    00DA    250 _I2DAT	=	0x00da
                    00DD    251 _I2SCLH	=	0x00dd
                    00DC    252 _I2SCLL	=	0x00dc
                    00D9    253 _I2STAT	=	0x00d9
                    00F8    254 _IP1	=	0x00f8
                    00F7    255 _IP1H	=	0x00f7
                    0094    256 _KBCON	=	0x0094
                    0086    257 _KBMASK	=	0x0086
                    0093    258 _KBPATN	=	0x0093
                    0084    259 _P0M1	=	0x0084
                    0085    260 _P0M2	=	0x0085
                    0091    261 _P1M1	=	0x0091
                    0092    262 _P1M2	=	0x0092
                    00B1    263 _P3M1	=	0x00b1
                    00B2    264 _P3M2	=	0x00b2
                    00B5    265 _PCONA	=	0x00b5
                    00F6    266 _PT0AD	=	0x00f6
                    00DF    267 _RSTSRC	=	0x00df
                    00D1    268 _RTCCON	=	0x00d1
                    00D2    269 _RTCH	=	0x00d2
                    00D3    270 _RTCL	=	0x00d3
                    00BA    271 _SSTAT	=	0x00ba
                    008F    272 _TAMOD	=	0x008f
                    0096    273 _TRIM	=	0x0096
                    00A7    274 _WDCON	=	0x00a7
                    00C1    275 _WDL	=	0x00c1
                    00C2    276 _WFEED1	=	0x00c2
                    00C3    277 _WFEED2	=	0x00c3
                    00B7    278 _IP0H	=	0x00b7
                    00E8    279 _IEN1	=	0x00e8
                            280 ;--------------------------------------------------------
                            281 ; special function bits
                            282 ;--------------------------------------------------------
                            283 	.area RSEG    (DATA)
                    00D0    284 _PSW_0	=	0x00d0
                    00D1    285 _PSW_1	=	0x00d1
                    00D2    286 _PSW_2	=	0x00d2
                    00D3    287 _PSW_3	=	0x00d3
                    00D4    288 _PSW_4	=	0x00d4
                    00D5    289 _PSW_5	=	0x00d5
                    00D6    290 _PSW_6	=	0x00d6
                    00D7    291 _PSW_7	=	0x00d7
                    00D0    292 _P	=	0x00d0
                    00D1    293 _F1	=	0x00d1
                    00D2    294 _OV	=	0x00d2
                    00D3    295 _RS0	=	0x00d3
                    00D4    296 _RS1	=	0x00d4
                    00D5    297 _F0	=	0x00d5
                    00D6    298 _AC	=	0x00d6
                    00D7    299 _CY	=	0x00d7
                    008F    300 _TCON_7	=	0x008f
                    008E    301 _TCON_6	=	0x008e
                    008D    302 _TCON_5	=	0x008d
                    008C    303 _TCON_4	=	0x008c
                    008B    304 _TCON_3	=	0x008b
                    008A    305 _TCON_2	=	0x008a
                    0089    306 _TCON_1	=	0x0089
                    0088    307 _TCON_0	=	0x0088
                    00AF    308 _IEN0_7	=	0x00af
                    00AE    309 _IEN0_6	=	0x00ae
                    00AD    310 _IEN0_5	=	0x00ad
                    00AC    311 _IEN0_4	=	0x00ac
                    00AB    312 _IEN0_3	=	0x00ab
                    00AA    313 _IEN0_2	=	0x00aa
                    00A9    314 _IEN0_1	=	0x00a9
                    00A8    315 _IEN0_0	=	0x00a8
                    00EA    316 _IEN1_2	=	0x00ea
                    00E9    317 _IEN1_1	=	0x00e9
                    00E8    318 _IEN1_0	=	0x00e8
                    00FE    319 _IP1_6	=	0x00fe
                    00FA    320 _IP1_2	=	0x00fa
                    00F9    321 _IP1_1	=	0x00f9
                    00F8    322 _IP1_0	=	0x00f8
                    00BE    323 _IP0_6	=	0x00be
                    00BD    324 _IP0_5	=	0x00bd
                    00BC    325 _IP0_4	=	0x00bc
                    00BB    326 _IP0_3	=	0x00bb
                    00BA    327 _IP0_2	=	0x00ba
                    00B9    328 _IP0_1	=	0x00b9
                    00B8    329 _IP0_0	=	0x00b8
                    0098    330 _SCON_0	=	0x0098
                    0099    331 _SCON_1	=	0x0099
                    009A    332 _SCON_2	=	0x009a
                    009B    333 _SCON_3	=	0x009b
                    009C    334 _SCON_4	=	0x009c
                    009D    335 _SCON_5	=	0x009d
                    009E    336 _SCON_6	=	0x009e
                    009F    337 _SCON_7	=	0x009f
                    00DE    338 _I2CON_6	=	0x00de
                    00DD    339 _I2CON_5	=	0x00dd
                    00DC    340 _I2CON_4	=	0x00dc
                    00DB    341 _I2CON_3	=	0x00db
                    00DA    342 _I2CON_2	=	0x00da
                    00D8    343 _I2CON_0	=	0x00d8
                    0080    344 _P0_0	=	0x0080
                    0081    345 _P0_1	=	0x0081
                    0082    346 _P0_2	=	0x0082
                    0083    347 _P0_3	=	0x0083
                    0084    348 _P0_4	=	0x0084
                    0085    349 _P0_5	=	0x0085
                    0086    350 _P0_6	=	0x0086
                    0087    351 _P0_7	=	0x0087
                    0090    352 _P1_0	=	0x0090
                    0091    353 _P1_1	=	0x0091
                    0092    354 _P1_2	=	0x0092
                    0093    355 _P1_3	=	0x0093
                    0094    356 _P1_4	=	0x0094
                    0095    357 _P1_5	=	0x0095
                    0096    358 _P1_6	=	0x0096
                    0097    359 _P1_7	=	0x0097
                    00B0    360 _P3_0	=	0x00b0
                    00B1    361 _P3_1	=	0x00b1
                            362 ;--------------------------------------------------------
                            363 ; overlayable register banks
                            364 ;--------------------------------------------------------
                            365 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     366 	.ds 8
                            367 ;--------------------------------------------------------
                            368 ; overlayable bit register bank
                            369 ;--------------------------------------------------------
                            370 	.area BIT_BANK	(REL,OVR,DATA)
   0021                     371 bits:
   0021                     372 	.ds 1
                    8000    373 	b0 = bits[0]
                    8100    374 	b1 = bits[1]
                    8200    375 	b2 = bits[2]
                    8300    376 	b3 = bits[3]
                    8400    377 	b4 = bits[4]
                    8500    378 	b5 = bits[5]
                    8600    379 	b6 = bits[6]
                    8700    380 	b7 = bits[7]
                            381 ;--------------------------------------------------------
                            382 ; internal ram data
                            383 ;--------------------------------------------------------
                            384 	.area DSEG    (DATA)
   0022                     385 _telegramm::
   0022                     386 	.ds 23
   0039                     387 _telpos::
   0039                     388 	.ds 1
   003A                     389 _cs::
   003A                     390 	.ds 1
   003B                     391 _pal::
   003B                     392 	.ds 1
   003C                     393 _pah::
   003C                     394 	.ds 1
   003D                     395 _gacount::
   003D                     396 	.ds 1
   003E                     397 _conh::
   003E                     398 	.ds 1
   003F                     399 _conl::
   003F                     400 	.ds 1
   0040                     401 _pcount::
   0040                     402 	.ds 1
   0041                     403 _portbuffer::
   0041                     404 	.ds 1
   0042                     405 _p0h::
   0042                     406 	.ds 1
   0043                     407 _objstate::
   0043                     408 	.ds 2
   0045                     409 _timer::
   0045                     410 	.ds 4
   0049                     411 _pdir::
   0049                     412 	.ds 1
                            413 ;--------------------------------------------------------
                            414 ; overlayable items in internal ram 
                            415 ;--------------------------------------------------------
                            416 	.area OSEG    (OVR,DATA)
                            417 ;--------------------------------------------------------
                            418 ; Stack segment in internal ram 
                            419 ;--------------------------------------------------------
                            420 	.area	SSEG	(DATA)
   004A                     421 __start__stack:
   004A                     422 	.ds	1
                            423 
                            424 ;--------------------------------------------------------
                            425 ; indirectly addressable internal ram data
                            426 ;--------------------------------------------------------
                            427 	.area ISEG    (DATA)
                            428 ;--------------------------------------------------------
                            429 ; bit data
                            430 ;--------------------------------------------------------
                            431 	.area BSEG    (BIT)
   0000                     432 _parity_ok::
   0000                     433 	.ds 1
   0001                     434 _progmode::
   0001                     435 	.ds 1
   0002                     436 _connected::
   0002                     437 	.ds 1
                            438 ;--------------------------------------------------------
                            439 ; paged external ram data
                            440 ;--------------------------------------------------------
                            441 	.area PSEG    (PAG,XDATA)
                            442 ;--------------------------------------------------------
                            443 ; external ram data
                            444 ;--------------------------------------------------------
                            445 	.area XSEG    (XDATA)
                            446 ;--------------------------------------------------------
                            447 ; external initialized ram data
                            448 ;--------------------------------------------------------
                            449 	.area XISEG   (XDATA)
                            450 	.area HOME    (CODE)
                            451 	.area GSINIT0 (CODE)
                            452 	.area GSINIT1 (CODE)
                            453 	.area GSINIT2 (CODE)
                            454 	.area GSINIT3 (CODE)
                            455 	.area GSINIT4 (CODE)
                            456 	.area GSINIT5 (CODE)
                            457 	.area GSINIT  (CODE)
                            458 	.area GSFINAL (CODE)
                            459 	.area CSEG    (CODE)
                            460 ;--------------------------------------------------------
                            461 ; interrupt vector 
                            462 ;--------------------------------------------------------
                            463 	.area HOME    (CODE)
   0000                     464 __interrupt_vect:
   0000 02 00 1E            465 	ljmp	__sdcc_gsinit_startup
   0003 32                  466 	reti
   0004                     467 	.ds	7
   000B 32                  468 	reti
   000C                     469 	.ds	7
   0013 02 01 5D            470 	ljmp	_ext_int0
   0016                     471 	.ds	5
   001B 02 03 4B            472 	ljmp	_timer1
                            473 ;--------------------------------------------------------
                            474 ; global & static initialisations
                            475 ;--------------------------------------------------------
                            476 	.area HOME    (CODE)
                            477 	.area GSINIT  (CODE)
                            478 	.area GSFINAL (CODE)
                            479 	.area GSINIT  (CODE)
                            480 	.globl __sdcc_gsinit_startup
                            481 	.globl __sdcc_program_startup
                            482 	.globl __start__stack
                            483 	.globl __mcs51_genXINIT
                            484 	.globl __mcs51_genXRAMCLEAR
                            485 	.globl __mcs51_genRAMCLEAR
                            486 	.area GSFINAL (CODE)
   0077 02 00 7A            487 	ljmp	__sdcc_program_startup
                            488 ;--------------------------------------------------------
                            489 ; Home
                            490 ;--------------------------------------------------------
                            491 	.area HOME    (CODE)
                            492 	.area CSEG    (CODE)
   007A                     493 __sdcc_program_startup:
   007A 12 16 E9            494 	lcall	_main
                            495 ;	return from main will lock up
   007D 80 FE               496 	sjmp .
                            497 ;--------------------------------------------------------
                            498 ; code
                            499 ;--------------------------------------------------------
                            500 	.area CSEG    (CODE)
                            501 ;------------------------------------------------------------
                            502 ;Allocation info for local variables in function 'get_byte'
                            503 ;------------------------------------------------------------
                            504 ;rbit                      Allocated to registers b1 
                            505 ;parity                    Allocated to registers b1 
                            506 ;ph                        Allocated to registers b0 
                            507 ;n                         Allocated to registers r3 
                            508 ;m                         Allocated to registers r2 
                            509 ;fbb                       Allocated to registers r2 
                            510 ;fbbh                      Allocated to registers r3 
                            511 ;------------------------------------------------------------
                            512 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:10: unsigned char get_byte(void)
                            513 ;	-----------------------------------------
                            514 ;	 function get_byte
                            515 ;	-----------------------------------------
   007F                     516 _get_byte:
                    0002    517 	ar2 = 0x02
                    0003    518 	ar3 = 0x03
                    0004    519 	ar4 = 0x04
                    0005    520 	ar5 = 0x05
                    0006    521 	ar6 = 0x06
                    0007    522 	ar7 = 0x07
                    0000    523 	ar0 = 0x00
                    0001    524 	ar1 = 0x01
                            525 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:15: EX1=0;				// Interrupt 1 sperren
                            526 ;	genAssign
   007F C2 AA               527 	clr	_IEN0_2
                            528 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:16: ET1=0;				// Interrupt von Timer 1 sperren
                            529 ;	genAssign
   0081 C2 AB               530 	clr	_IEN0_3
                            531 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:18: set_timer1(380);			// Timer setzen um 1. Bit zu treffen (320-440)
                            532 ;	genCall
                            533 ;	Peephole 182.b	used 16 bit load of dptr
   0083 90 01 7C            534 	mov	dptr,#0x017C
   0086 12 02 B7            535 	lcall	_set_timer1
                            536 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:20: ph=0;					// Paritybit wird aus empfangenem Byte berechnet
                            537 ;	genAssign
   0089 C2 08               538 	clr	b0
                            539 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:21: parity_ok=0;
                            540 ;	genAssign
   008B C2 00               541 	clr	_parity_ok
                            542 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:22: while(!TF1);				// warten auf Timer 1				
   008D                     543 00101$:
                            544 ;	genIfx
                            545 ;	genIfxJump
                            546 ;	Peephole 108.d	removed ljmp by inverse jump logic
   008D 30 8F FD            547 	jnb	_TCON_7,00101$
                            548 ;	Peephole 300	removed redundant label 00152$
                            549 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:23: set_timer1(360);			// Timer 1 neu setzen für 2.Bit (300-420)
                            550 ;	genCall
                            551 ;	Peephole 182.b	used 16 bit load of dptr
   0090 90 01 68            552 	mov	dptr,#0x0168
   0093 C0 21               553 	push	bits
   0095 12 02 B7            554 	lcall	_set_timer1
   0098 D0 21               555 	pop	bits
                            556 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:24: rbit=FBINC;				// 1.Bit einlesen
                            557 ;	genAssign
   009A A2 94               558 	mov	c,_P1_4
   009C 92 09               559 	mov	b1,c
                            560 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:25: for(m=0;m<5;m++)
                            561 ;	genAssign
   009E 7A 05               562 	mov	r2,#0x05
   00A0                     563 00118$:
                            564 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:27: rbit&=FBINC;			// zur Steigerung der Fehlertoleranz mehrfach lesen
                            565 ;	genAnd
   00A0 A2 94               566 	mov	c,_P1_4
   00A2 82 09               567 	anl	c,b1
   00A4 92 09               568 	mov	b1,c
                            569 ;	genDjnz
                            570 ;	Peephole 112.b	changed ljmp to sjmp
                            571 ;	Peephole 205	optimized misc jump sequence
   00A6 DA F8               572 	djnz	r2,00118$
                            573 ;	Peephole 300	removed redundant label 00153$
                            574 ;	Peephole 300	removed redundant label 00154$
                            575 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:25: for(m=0;m<5;m++)
                            576 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:29: fbb=rbit;
                            577 ;	genAssign
   00A8 E4                  578 	clr	a
   00A9 A2 09               579 	mov	c,b1
   00AB 33                  580 	rlc	a
   00AC FA                  581 	mov	r2,a
                            582 ;	genAssign
                            583 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:30: if(rbit) ph=!ph;			// Paritybit berechnen
                            584 ;	genIfx
                            585 ;	genIfxJump
                            586 ;	Peephole 108.d	removed ljmp by inverse jump logic
   00AD 30 09 02            587 	jnb	b1,00142$
                            588 ;	Peephole 300	removed redundant label 00155$
                            589 ;	genNot
   00B0 B2 08               590 	cpl	b0
                            591 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:32: for(n=0;n<7;n++)			// 2. bis 8. Bit
   00B2                     592 00142$:
                            593 ;	genAssign
   00B2 7B 00               594 	mov	r3,#0x00
   00B4                     595 00122$:
                            596 ;	genCmpLt
                            597 ;	genCmp
   00B4 BB 07 00            598 	cjne	r3,#0x07,00156$
   00B7                     599 00156$:
                            600 ;	genIfxJump
                            601 ;	Peephole 108.a	removed ljmp by inverse jump logic
   00B7 50 35               602 	jnc	00111$
                            603 ;	Peephole 300	removed redundant label 00157$
                            604 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:34: fbb=fbb<<1;
                            605 ;	genLeftShift
                            606 ;	genLeftShiftLiteral
                            607 ;	genlshOne
   00B9 EA                  608 	mov	a,r2
                            609 ;	Peephole 254	optimized left shift
   00BA 2A                  610 	add	a,r2
   00BB FA                  611 	mov	r2,a
                            612 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:35: while(!TF1);
   00BC                     613 00106$:
                            614 ;	genIfx
                            615 ;	genIfxJump
                            616 ;	Peephole 108.d	removed ljmp by inverse jump logic
   00BC 30 8F FD            617 	jnb	_TCON_7,00106$
                            618 ;	Peephole 300	removed redundant label 00158$
                            619 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:36: set_timer1(350);			// Timer 1 setzen für Position 2.-9.Bit (342-359)
                            620 ;	genCall
                            621 ;	Peephole 182.b	used 16 bit load of dptr
   00BF 90 01 5E            622 	mov	dptr,#0x015E
   00C2 C0 02               623 	push	ar2
   00C4 C0 03               624 	push	ar3
   00C6 C0 21               625 	push	bits
   00C8 12 02 B7            626 	lcall	_set_timer1
   00CB D0 21               627 	pop	bits
   00CD D0 03               628 	pop	ar3
   00CF D0 02               629 	pop	ar2
                            630 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:37: rbit=FBINC;
                            631 ;	genAssign
   00D1 A2 94               632 	mov	c,_P1_4
   00D3 92 09               633 	mov	b1,c
                            634 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:38: for(m=0;m<5;m++)
                            635 ;	genAssign
   00D5 7C 05               636 	mov	r4,#0x05
   00D7                     637 00121$:
                            638 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:40: rbit&=FBINC;			// zur Steigerung der Fehlertoleranz mehrfach lesen
                            639 ;	genAnd
   00D7 A2 94               640 	mov	c,_P1_4
   00D9 82 09               641 	anl	c,b1
   00DB 92 09               642 	mov	b1,c
                            643 ;	genDjnz
                            644 ;	Peephole 112.b	changed ljmp to sjmp
                            645 ;	Peephole 205	optimized misc jump sequence
   00DD DC F8               646 	djnz	r4,00121$
                            647 ;	Peephole 300	removed redundant label 00159$
                            648 ;	Peephole 300	removed redundant label 00160$
                            649 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:38: for(m=0;m<5;m++)
                            650 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:42: fbb=fbb+rbit;
                            651 ;	genAssign
   00DF E4                  652 	clr	a
   00E0 A2 09               653 	mov	c,b1
   00E2 33                  654 	rlc	a
                            655 ;	genPlus
   00E3 FC                  656 	mov	r4,a
                            657 ;	Peephole 177.b	removed redundant mov
                            658 ;	Peephole 236.a	used r2 instead of ar2
   00E4 2A                  659 	add	a,r2
   00E5 FA                  660 	mov	r2,a
                            661 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:43: if(rbit) ph=!ph;			// Paritybit berechnen
                            662 ;	genIfx
                            663 ;	genIfxJump
                            664 ;	Peephole 108.d	removed ljmp by inverse jump logic
   00E6 30 09 02            665 	jnb	b1,00124$
                            666 ;	Peephole 300	removed redundant label 00161$
                            667 ;	genNot
   00E9 B2 08               668 	cpl	b0
   00EB                     669 00124$:
                            670 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:32: for(n=0;n<7;n++)			// 2. bis 8. Bit
                            671 ;	genPlus
                            672 ;     genPlusIncr
   00EB 0B                  673 	inc	r3
                            674 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:45: while(!TF1);				
                            675 ;	Peephole 112.b	changed ljmp to sjmp
   00EC 80 C6               676 	sjmp	00122$
   00EE                     677 00111$:
                            678 ;	genIfx
                            679 ;	genIfxJump
                            680 ;	Peephole 108.d	removed ljmp by inverse jump logic
   00EE 30 8F FD            681 	jnb	_TCON_7,00111$
                            682 ;	Peephole 300	removed redundant label 00162$
                            683 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:46: TR1=0;
                            684 ;	genAssign
   00F1 C2 8E               685 	clr	_TCON_6
                            686 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:47: parity=FBINC;				// Paritybit lesen
                            687 ;	genAssign
   00F3 A2 94               688 	mov	c,_P1_4
   00F5 92 09               689 	mov	b1,c
                            690 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:48: for(m=0;m<5;m++)
                            691 ;	genAssign
   00F7 7B 05               692 	mov	r3,#0x05
   00F9                     693 00128$:
                            694 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:50: parity&=FBINC;
                            695 ;	genAnd
   00F9 A2 94               696 	mov	c,_P1_4
   00FB 82 09               697 	anl	c,b1
   00FD 92 09               698 	mov	b1,c
                            699 ;	genDjnz
                            700 ;	Peephole 112.b	changed ljmp to sjmp
                            701 ;	Peephole 205	optimized misc jump sequence
   00FF DB F8               702 	djnz	r3,00128$
                            703 ;	Peephole 300	removed redundant label 00163$
                            704 ;	Peephole 300	removed redundant label 00164$
                            705 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:48: for(m=0;m<5;m++)
                            706 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:53: fbbh=(fbb&0x80)>>7;			// Byte bitweise vertauschen, da LSB zuerst übertragen wurde
                            707 ;	genAnd
   0101 74 80               708 	mov	a,#0x80
   0103 5A                  709 	anl	a,r2
                            710 ;	genRightShift
                            711 ;	genRightShiftLiteral
                            712 ;	genrshOne
   0104 FB                  713 	mov	r3,a
                            714 ;	Peephole 105	removed redundant mov
   0105 23                  715 	rl	a
   0106 54 01               716 	anl	a,#0x01
   0108 FB                  717 	mov	r3,a
                            718 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:54: fbbh=fbbh+((fbb&0x40)>>5);
                            719 ;	genAnd
   0109 74 40               720 	mov	a,#0x40
   010B 5A                  721 	anl	a,r2
                            722 ;	genRightShift
                            723 ;	genRightShiftLiteral
                            724 ;	genrshOne
   010C FC                  725 	mov	r4,a
                            726 ;	Peephole 105	removed redundant mov
   010D C4                  727 	swap	a
   010E 03                  728 	rr	a
   010F 54 07               729 	anl	a,#0x07
                            730 ;	genPlus
   0111 FC                  731 	mov	r4,a
                            732 ;	Peephole 177.b	removed redundant mov
                            733 ;	Peephole 236.a	used r3 instead of ar3
   0112 2B                  734 	add	a,r3
   0113 FB                  735 	mov	r3,a
                            736 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:55: fbbh=fbbh+((fbb&0x20)>>3);
                            737 ;	genAnd
   0114 74 20               738 	mov	a,#0x20
   0116 5A                  739 	anl	a,r2
                            740 ;	genRightShift
                            741 ;	genRightShiftLiteral
                            742 ;	genrshOne
   0117 FC                  743 	mov	r4,a
                            744 ;	Peephole 105	removed redundant mov
   0118 C4                  745 	swap	a
   0119 23                  746 	rl	a
   011A 54 1F               747 	anl	a,#0x1f
                            748 ;	genPlus
   011C FC                  749 	mov	r4,a
                            750 ;	Peephole 177.b	removed redundant mov
                            751 ;	Peephole 236.a	used r3 instead of ar3
   011D 2B                  752 	add	a,r3
   011E FB                  753 	mov	r3,a
                            754 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:56: fbbh=fbbh+((fbb&0x10)>>1);
                            755 ;	genAnd
   011F 74 10               756 	mov	a,#0x10
   0121 5A                  757 	anl	a,r2
                            758 ;	genRightShift
                            759 ;	genRightShiftLiteral
                            760 ;	genrshOne
   0122 FC                  761 	mov	r4,a
                            762 ;	Peephole 105	removed redundant mov
   0123 C3                  763 	clr	c
   0124 13                  764 	rrc	a
                            765 ;	genPlus
   0125 FC                  766 	mov	r4,a
                            767 ;	Peephole 177.b	removed redundant mov
                            768 ;	Peephole 236.a	used r3 instead of ar3
   0126 2B                  769 	add	a,r3
   0127 FB                  770 	mov	r3,a
                            771 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:57: fbbh=fbbh+((fbb&0x08)<<1);
                            772 ;	genAnd
   0128 74 08               773 	mov	a,#0x08
   012A 5A                  774 	anl	a,r2
                            775 ;	genLeftShift
                            776 ;	genLeftShiftLiteral
                            777 ;	genlshOne
                            778 ;	Peephole 105	removed redundant mov
                            779 ;	genPlus
                            780 ;	Peephole 204	removed redundant mov
   012B 25 E0               781 	add	a,acc
   012D FC                  782 	mov	r4,a
                            783 ;	Peephole 177.b	removed redundant mov
                            784 ;	Peephole 236.a	used r3 instead of ar3
   012E 2B                  785 	add	a,r3
   012F FB                  786 	mov	r3,a
                            787 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:58: fbbh=fbbh+((fbb&0x04)<<3);
                            788 ;	genAnd
   0130 74 04               789 	mov	a,#0x04
   0132 5A                  790 	anl	a,r2
                            791 ;	genLeftShift
                            792 ;	genLeftShiftLiteral
                            793 ;	genlshOne
   0133 FC                  794 	mov	r4,a
                            795 ;	Peephole 105	removed redundant mov
   0134 C4                  796 	swap	a
   0135 03                  797 	rr	a
   0136 54 F8               798 	anl	a,#0xf8
                            799 ;	genPlus
   0138 FC                  800 	mov	r4,a
                            801 ;	Peephole 177.b	removed redundant mov
                            802 ;	Peephole 236.a	used r3 instead of ar3
   0139 2B                  803 	add	a,r3
   013A FB                  804 	mov	r3,a
                            805 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:59: fbbh=fbbh+((fbb&0x02)<<5);
                            806 ;	genAnd
   013B 74 02               807 	mov	a,#0x02
   013D 5A                  808 	anl	a,r2
                            809 ;	genLeftShift
                            810 ;	genLeftShiftLiteral
                            811 ;	genlshOne
   013E FC                  812 	mov	r4,a
                            813 ;	Peephole 105	removed redundant mov
   013F C4                  814 	swap	a
   0140 23                  815 	rl	a
   0141 54 E0               816 	anl	a,#0xe0
                            817 ;	genPlus
   0143 FC                  818 	mov	r4,a
                            819 ;	Peephole 177.b	removed redundant mov
                            820 ;	Peephole 236.a	used r3 instead of ar3
   0144 2B                  821 	add	a,r3
   0145 FB                  822 	mov	r3,a
                            823 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:60: fbbh=fbbh+((fbb&0x01)<<7);
                            824 ;	genAnd
   0146 53 02 01            825 	anl	ar2,#0x01
                            826 ;	genLeftShift
                            827 ;	genLeftShiftLiteral
                            828 ;	genlshOne
   0149 EA                  829 	mov	a,r2
   014A 03                  830 	rr	a
   014B 54 80               831 	anl	a,#0x80
                            832 ;	genPlus
   014D FA                  833 	mov	r2,a
                            834 ;	Peephole 177.b	removed redundant mov
                            835 ;	Peephole 236.a	used r3 instead of ar3
   014E 2B                  836 	add	a,r3
   014F FB                  837 	mov	r3,a
                            838 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:62: if(parity==ph) parity_ok=1;
                            839 ;	genCmpEq
   0150 A2 09               840 	mov	c,b1
   0152 20 08 01            841 	jb	b0,00165$
   0155 B3                  842 	cpl	c
   0156                     843 00165$:
                            844 ;	Peephole 108.a	removed ljmp by inverse jump logic
   0156 50 02               845 	jnc	00115$
                            846 ;	Peephole 300	removed redundant label 00166$
                            847 ;	genAssign
   0158 D2 00               848 	setb	_parity_ok
   015A                     849 00115$:
                            850 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:64: return fbbh;
                            851 ;	genRet
   015A 8B 82               852 	mov	dpl,r3
                            853 ;	Peephole 300	removed redundant label 00129$
   015C 22                  854 	ret
                            855 ;------------------------------------------------------------
                            856 ;Allocation info for local variables in function 'ext_int0'
                            857 ;------------------------------------------------------------
                            858 ;fbbh                      Allocated to registers r2 
                            859 ;------------------------------------------------------------
                            860 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:70: void ext_int0(void) interrupt 2		// Byte vom Bus empfangen, wird durch negative Flanke am INT1 Eingang getriggert
                            861 ;	-----------------------------------------
                            862 ;	 function ext_int0
                            863 ;	-----------------------------------------
   015D                     864 _ext_int0:
   015D C0 E0               865 	push	acc
   015F C0 F0               866 	push	b
   0161 C0 82               867 	push	dpl
   0163 C0 83               868 	push	dph
   0165 C0 02               869 	push	(0+2)
   0167 C0 03               870 	push	(0+3)
   0169 C0 04               871 	push	(0+4)
   016B C0 05               872 	push	(0+5)
   016D C0 06               873 	push	(0+6)
   016F C0 07               874 	push	(0+7)
   0171 C0 00               875 	push	(0+0)
   0173 C0 01               876 	push	(0+1)
   0175 C0 21               877 	push	bits
   0177 C0 D0               878 	push	psw
   0179 75 D0 00            879 	mov	psw,#0x00
                            880 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:76: TR1=0;
                            881 ;	genAssign
   017C C2 8E               882 	clr	_TCON_6
                            883 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:77: EX1=0;				// Interrupt 1 sperren
                            884 ;	genAssign
   017E C2 AA               885 	clr	_IEN0_2
                            886 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:78: ET1=0;				// Interrupt von Timer 1 sperren
                            887 ;	genAssign
   0180 C2 AB               888 	clr	_IEN0_3
                            889 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:80: fbbh=get_byte();			// Byte vom Bus empfangen
                            890 ;	genCall
   0182 12 00 7F            891 	lcall	_get_byte
   0185 AA 82               892 	mov	r2,dpl
                            893 ;	genAssign
                            894 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:81: delay(200);
                            895 ;	genCall
                            896 ;	Peephole 182.b	used 16 bit load of dptr
   0187 90 00 C8            897 	mov	dptr,#0x00C8
   018A C0 02               898 	push	ar2
   018C 12 02 9A            899 	lcall	_delay
   018F D0 02               900 	pop	ar2
                            901 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:83: if(parity_ok)				// wenn Parity OK
                            902 ;	genIfx
                            903 ;	genIfxJump
                            904 ;	Peephole 108.d	removed ljmp by inverse jump logic
   0191 30 00 12            905 	jnb	_parity_ok,00104$
                            906 ;	Peephole 300	removed redundant label 00109$
                            907 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:85: telegramm[telpos]=fbbh; 
                            908 ;	genPlus
   0194 E5 39               909 	mov	a,_telpos
   0196 24 22               910 	add	a,#_telegramm
                            911 ;	genPointerSet
                            912 ;	genNearPointerSet
                            913 ;	Peephole 239	used a instead of acc
   0198 F8                  914 	mov	r0,a
   0199 A6 02               915 	mov	@r0,ar2
                            916 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:86: if(telpos==0) cs=0;
                            917 ;	genIfx
   019B E5 39               918 	mov	a,_telpos
                            919 ;	genIfxJump
                            920 ;	Peephole 108.b	removed ljmp by inverse jump logic
                            921 ;	genAssign
   019D 70 02               922 	jnz	00102$
                            923 ;	Peephole 300	removed redundant label 00110$
                            924 ;	Peephole 256.c	loading _cs with zero from a
   019F F5 3A               925 	mov	_cs,a
   01A1                     926 00102$:
                            927 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:87: cs^=fbbh;				// Checksum durch EXOR der einzelnen Telegramm-Bytes bilden
                            928 ;	genXor
   01A1 EA                  929 	mov	a,r2
   01A2 62 3A               930 	xrl	_cs,a
                            931 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:88: telpos++;
                            932 ;	genPlus
                            933 ;     genPlusIncr
   01A4 05 39               934 	inc	_telpos
   01A6                     935 00104$:
                            936 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:91: set_timer1(2700);			// Timer 1 starten für Timeout 370us -> signalisiert Telegrammende (1460)
                            937 ;	genCall
                            938 ;	Peephole 182.b	used 16 bit load of dptr
   01A6 90 0A 8C            939 	mov	dptr,#0x0A8C
   01A9 12 02 B7            940 	lcall	_set_timer1
                            941 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:93: ET1=1;				// Interrupt für Timer 1 freigeben
                            942 ;	genAssign
   01AC D2 AB               943 	setb	_IEN0_3
                            944 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:94: IE1=0;				// Interrupt 0 request zurücksetzen
                            945 ;	genAssign
   01AE C2 8B               946 	clr	_TCON_3
                            947 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:95: EX1=1;				// Interrupt 0 wieder freigeben
                            948 ;	genAssign
   01B0 D2 AA               949 	setb	_IEN0_2
                            950 ;	Peephole 300	removed redundant label 00105$
   01B2 D0 D0               951 	pop	psw
   01B4 D0 21               952 	pop	bits
   01B6 D0 01               953 	pop	(0+1)
   01B8 D0 00               954 	pop	(0+0)
   01BA D0 07               955 	pop	(0+7)
   01BC D0 06               956 	pop	(0+6)
   01BE D0 05               957 	pop	(0+5)
   01C0 D0 04               958 	pop	(0+4)
   01C2 D0 03               959 	pop	(0+3)
   01C4 D0 02               960 	pop	(0+2)
   01C6 D0 83               961 	pop	dph
   01C8 D0 82               962 	pop	dpl
   01CA D0 F0               963 	pop	b
   01CC D0 E0               964 	pop	acc
   01CE 32                  965 	reti
                            966 ;------------------------------------------------------------
                            967 ;Allocation info for local variables in function 'sendbyte'
                            968 ;------------------------------------------------------------
                            969 ;fbsb                      Allocated to registers r2 
                            970 ;n                         Allocated to registers r3 
                            971 ;m                         Allocated to registers r4 
                            972 ;sendbit                   Allocated to registers b2 
                            973 ;parity                    Allocated to registers b0 
                            974 ;error                     Allocated to registers b1 
                            975 ;------------------------------------------------------------
                            976 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:99: bit sendbyte(unsigned char fbsb)
                            977 ;	-----------------------------------------
                            978 ;	 function sendbyte
                            979 ;	-----------------------------------------
   01CF                     980 _sendbyte:
                            981 ;	genReceive
   01CF AA 82               982 	mov	r2,dpl
                            983 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:104: parity=1;
                            984 ;	genAssign
   01D1 D2 08               985 	setb	b0
                            986 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:105: error=0;
                            987 ;	genAssign
   01D3 C2 09               988 	clr	b1
                            989 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:107: FBOUTC=1;	// Startbit senden
                            990 ;	genAssign
   01D5 D2 96               991 	setb	_P1_6
                            992 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:108: delay(95);	// 35us
                            993 ;	genCall
                            994 ;	Peephole 182.b	used 16 bit load of dptr
   01D7 90 00 5F            995 	mov	dptr,#0x005F
   01DA C0 02               996 	push	ar2
   01DC C0 21               997 	push	bits
   01DE 12 02 9A            998 	lcall	_delay
   01E1 D0 21               999 	pop	bits
   01E3 D0 02              1000 	pop	ar2
                           1001 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:109: FBOUTC=0;
                           1002 ;	genAssign
   01E5 C2 96              1003 	clr	_P1_6
                           1004 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:111: for(n=0;n<8;n++)		// 8 Datenbits senden
                           1005 ;	genAssign
   01E7 7B 00              1006 	mov	r3,#0x00
   01E9                    1007 00116$:
                           1008 ;	genCmpLt
                           1009 ;	genCmp
   01E9 BB 08 00           1010 	cjne	r3,#0x08,00141$
   01EC                    1011 00141$:
                           1012 ;	genIfxJump
                           1013 ;	Peephole 112.b	changed ljmp to sjmp
                           1014 ;	Peephole 160.b	removed sjmp by inverse jump logic
   01EC 50 5C              1015 	jnc	00119$
                           1016 ;	Peephole 300	removed redundant label 00142$
                           1017 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:113: set_timer1(215);		// 69us Pause
                           1018 ;	genCall
                           1019 ;	Peephole 182.b	used 16 bit load of dptr
   01EE 90 00 D7           1020 	mov	dptr,#0x00D7
   01F1 C0 02              1021 	push	ar2
   01F3 C0 03              1022 	push	ar3
   01F5 C0 21              1023 	push	bits
   01F7 12 02 B7           1024 	lcall	_set_timer1
   01FA D0 21              1025 	pop	bits
   01FC D0 03              1026 	pop	ar3
   01FE D0 02              1027 	pop	ar2
                           1028 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:114: if(((fbsb>>n)&0x01)==1) sendbit=0;
                           1029 ;	genRightShift
   0200 8B F0              1030 	mov	b,r3
   0202 05 F0              1031 	inc	b
   0204 EA                 1032 	mov	a,r2
   0205 80 02              1033 	sjmp	00144$
   0207                    1034 00143$:
   0207 C3                 1035 	clr	c
   0208 13                 1036 	rrc	a
   0209                    1037 00144$:
   0209 D5 F0 FB           1038 	djnz	b,00143$
                           1039 ;	genAnd
   020C 54 01              1040 	anl	a,#0x01
   020E FC                 1041 	mov	r4,a
                           1042 ;	genCmpEq
                           1043 ;	gencjneshort
                           1044 ;	Peephole 112.b	changed ljmp to sjmp
                           1045 ;	Peephole 198.b	optimized misc jump sequence
   020F BC 01 04           1046 	cjne	r4,#0x01,00102$
                           1047 ;	Peephole 200.b	removed redundant sjmp
                           1048 ;	Peephole 300	removed redundant label 00145$
                           1049 ;	Peephole 300	removed redundant label 00146$
                           1050 ;	genAssign
   0212 C2 0A              1051 	clr	b2
                           1052 ;	Peephole 112.b	changed ljmp to sjmp
   0214 80 02              1053 	sjmp	00104$
   0216                    1054 00102$:
                           1055 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:115: else sendbit=1;
                           1056 ;	genAssign
   0216 D2 0A              1057 	setb	b2
                           1058 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:116: while(!TF1);		// Warten bis 69us Pause fretig ist
   0218                    1059 00104$:
                           1060 ;	genIfx
                           1061 ;	genIfxJump
                           1062 ;	Peephole 108.d	removed ljmp by inverse jump logic
   0218 30 8F FD           1063 	jnb	_TCON_7,00104$
                           1064 ;	Peephole 300	removed redundant label 00147$
                           1065 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:118: FBOUTC=sendbit;		// Bit senden
                           1066 ;	genAssign
   021B A2 0A              1067 	mov	c,b2
   021D 92 96              1068 	mov	_P1_6,c
                           1069 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:120: set_timer1(100);		//35us Haltezeit für Bit 
                           1070 ;	genCall
                           1071 ;	Peephole 182.b	used 16 bit load of dptr
   021F 90 00 64           1072 	mov	dptr,#0x0064
   0222 C0 02              1073 	push	ar2
   0224 C0 03              1074 	push	ar3
   0226 C0 21              1075 	push	bits
   0228 12 02 B7           1076 	lcall	_set_timer1
   022B D0 21              1077 	pop	bits
   022D D0 03              1078 	pop	ar3
   022F D0 02              1079 	pop	ar2
                           1080 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:122: if(!sendbit)		// wenn logische 1 gesendet wird, auf Kollision prüfen
                           1081 ;	genIfx
                           1082 ;	genIfxJump
                           1083 ;	Peephole 108.e	removed ljmp by inverse jump logic
   0231 20 0A 0B           1084 	jb	b2,00110$
                           1085 ;	Peephole 300	removed redundant label 00148$
                           1086 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:124: parity=!parity;
                           1087 ;	genNot
   0234 B2 08              1088 	cpl	b0
                           1089 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:125: for(m=0;m<5;m++)
                           1090 ;	genAssign
   0236 7C 05              1091 	mov	r4,#0x05
   0238                    1092 00124$:
                           1093 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:127: if(!FBINC) error=1;
                           1094 ;	genIfx
                           1095 ;	genIfxJump
                           1096 ;	Peephole 108.e	removed ljmp by inverse jump logic
   0238 20 94 02           1097 	jb	_P1_4,00108$
                           1098 ;	Peephole 300	removed redundant label 00149$
                           1099 ;	genAssign
   023B D2 09              1100 	setb	b1
   023D                    1101 00108$:
                           1102 ;	genDjnz
                           1103 ;	Peephole 112.b	changed ljmp to sjmp
                           1104 ;	Peephole 205	optimized misc jump sequence
   023D DC F9              1105 	djnz	r4,00124$
                           1106 ;	Peephole 300	removed redundant label 00150$
                           1107 ;	Peephole 300	removed redundant label 00151$
                           1108 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:125: for(m=0;m<5;m++)
   023F                    1109 00110$:
                           1110 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:130: if(error) break;  
                           1111 ;	genIfx
                           1112 ;	genIfxJump
                           1113 ;	Peephole 108.e	removed ljmp by inverse jump logic
   023F 20 09 08           1114 	jb	b1,00119$
                           1115 ;	Peephole 300	removed redundant label 00152$
                           1116 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:132: while(!TF1);		// Warten bis 35us abgelaufen
   0242                    1117 00113$:
                           1118 ;	genIfx
                           1119 ;	genIfxJump
                           1120 ;	Peephole 108.d	removed ljmp by inverse jump logic
   0242 30 8F FD           1121 	jnb	_TCON_7,00113$
                           1122 ;	Peephole 300	removed redundant label 00153$
                           1123 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:133: FBOUTC=0;
                           1124 ;	genAssign
   0245 C2 96              1125 	clr	_P1_6
                           1126 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:111: for(n=0;n<8;n++)		// 8 Datenbits senden
                           1127 ;	genPlus
                           1128 ;     genPlusIncr
   0247 0B                 1129 	inc	r3
                           1130 ;	Peephole 112.b	changed ljmp to sjmp
   0248 80 9F              1131 	sjmp	00116$
   024A                    1132 00119$:
                           1133 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:135: if(!error)
                           1134 ;	genIfx
                           1135 ;	genIfxJump
                           1136 ;	Peephole 108.e	removed ljmp by inverse jump logic
   024A 20 09 1A           1137 	jb	b1,00121$
                           1138 ;	Peephole 300	removed redundant label 00154$
                           1139 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:137: delay(212);			// 69 us Pause vor Parity-Bit
                           1140 ;	genCall
                           1141 ;	Peephole 182.b	used 16 bit load of dptr
   024D 90 00 D4           1142 	mov	dptr,#0x00D4
   0250 C0 21              1143 	push	bits
   0252 12 02 9A           1144 	lcall	_delay
   0255 D0 21              1145 	pop	bits
                           1146 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:138: FBOUTC=parity;
                           1147 ;	genAssign
   0257 A2 08              1148 	mov	c,b0
   0259 92 96              1149 	mov	_P1_6,c
                           1150 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:139: delay(95);			// 35us für Parity-Bit
                           1151 ;	genCall
                           1152 ;	Peephole 182.b	used 16 bit load of dptr
   025B 90 00 5F           1153 	mov	dptr,#0x005F
   025E C0 21              1154 	push	bits
   0260 12 02 9A           1155 	lcall	_delay
   0263 D0 21              1156 	pop	bits
                           1157 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:140: FBOUTC=0;
                           1158 ;	genAssign
   0265 C2 96              1159 	clr	_P1_6
   0267                    1160 00121$:
                           1161 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:142: TR1=0;
                           1162 ;	genAssign
   0267 C2 8E              1163 	clr	_TCON_6
                           1164 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:144: return error;
                           1165 ;	genRet
   0269 E4                 1166 	clr	a
   026A A2 09              1167 	mov	c,b1
   026C 33                 1168 	rlc	a
   026D 24 FF              1169 	add	a,#0xff
                           1170 ;	Peephole 300	removed redundant label 00125$
   026F 22                 1171 	ret
                           1172 ;------------------------------------------------------------
                           1173 ;Allocation info for local variables in function 'start_writecycle'
                           1174 ;------------------------------------------------------------
                           1175 ;------------------------------------------------------------
                           1176 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:148: void start_writecycle(void)
                           1177 ;	-----------------------------------------
                           1178 ;	 function start_writecycle
                           1179 ;	-----------------------------------------
   0270                    1180 _start_writecycle:
                           1181 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:150: FMCON=0x00;			// load command, leert das pageregister
                           1182 ;	genAssign
   0270 75 E4 00           1183 	mov	_FMCON,#0x00
                           1184 ;	Peephole 300	removed redundant label 00101$
   0273 22                 1185 	ret
                           1186 ;------------------------------------------------------------
                           1187 ;Allocation info for local variables in function 'stop_writecycle'
                           1188 ;------------------------------------------------------------
                           1189 ;------------------------------------------------------------
                           1190 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:154: void stop_writecycle(void)
                           1191 ;	-----------------------------------------
                           1192 ;	 function stop_writecycle
                           1193 ;	-----------------------------------------
   0274                    1194 _stop_writecycle:
                           1195 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:156: FMCON=0x68;			// write command, schreibt pageregister ins flash und versetzt CPU in idle für 4ms
                           1196 ;	genAssign
   0274 75 E4 68           1197 	mov	_FMCON,#0x68
                           1198 ;	Peephole 300	removed redundant label 00101$
   0277 22                 1199 	ret
                           1200 ;------------------------------------------------------------
                           1201 ;Allocation info for local variables in function 'write_byte'
                           1202 ;------------------------------------------------------------
                           1203 ;addrl                     Allocated to stack - offset -3
                           1204 ;zdata                     Allocated to stack - offset -4
                           1205 ;addrh                     Allocated to registers r2 
                           1206 ;------------------------------------------------------------
                           1207 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:160: void write_byte(unsigned char addrh, unsigned char addrl, unsigned char zdata)	// schreibt byte ins pageregister zum flashen
                           1208 ;	-----------------------------------------
                           1209 ;	 function write_byte
                           1210 ;	-----------------------------------------
   0278                    1211 _write_byte:
   0278 C0 08              1212 	push	_bp
   027A 85 81 08           1213 	mov	_bp,sp
                           1214 ;	genReceive
                           1215 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:163: if (addrh<=0x01)		// sicherstellen, dass nicht versehentlich bootloader überschrieben wird
                           1216 ;	genCmpGt
                           1217 ;	genCmp
                           1218 ;	genIfxJump
                           1219 ;	Peephole 132.b	optimized genCmpGt by inverse logic (acc differs)
                           1220 ;	peephole 177.g	optimized mov sequence
   027D E5 82              1221 	mov	a,dpl
   027F FA                 1222 	mov	r2,a
   0280 24 FE              1223 	add	a,#0xff - 0x01
                           1224 ;	Peephole 112.b	changed ljmp to sjmp
                           1225 ;	Peephole 160.a	removed sjmp by inverse jump logic
   0282 40 13              1226 	jc	00103$
                           1227 ;	Peephole 300	removed redundant label 00106$
                           1228 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:165: FMADRH=addrh+0x1C;
                           1229 ;	genPlus
                           1230 ;     genPlusIncr
   0284 74 1C              1231 	mov	a,#0x1C
                           1232 ;	Peephole 236.a	used r2 instead of ar2
   0286 2A                 1233 	add	a,r2
   0287 F5 E7              1234 	mov	_FMADRH,a
                           1235 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:166: FMADRL=addrl;
                           1236 ;	genAssign
   0289 A8 08              1237 	mov	r0,_bp
   028B 18                 1238 	dec	r0
   028C 18                 1239 	dec	r0
   028D 18                 1240 	dec	r0
   028E 86 E6              1241 	mov	_FMADRL,@r0
                           1242 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:167: FMDATA=zdata;
                           1243 ;	genAssign
   0290 E5 08              1244 	mov	a,_bp
   0292 24 FC              1245 	add	a,#0xfffffffc
   0294 F8                 1246 	mov	r0,a
   0295 86 E5              1247 	mov	_FMDATA,@r0
   0297                    1248 00103$:
   0297 D0 08              1249 	pop	_bp
   0299 22                 1250 	ret
                           1251 ;------------------------------------------------------------
                           1252 ;Allocation info for local variables in function 'delay'
                           1253 ;------------------------------------------------------------
                           1254 ;deltime                   Allocated to registers r2 r3 
                           1255 ;------------------------------------------------------------
                           1256 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:172: void delay(int deltime)			// Warten, deltime = Anzahl Takte
                           1257 ;	-----------------------------------------
                           1258 ;	 function delay
                           1259 ;	-----------------------------------------
   029A                    1260 _delay:
                           1261 ;	genReceive
   029A AA 82              1262 	mov	r2,dpl
   029C AB 83              1263 	mov	r3,dph
                           1264 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:174: TR1=0;				// Timer 1 anhalten
                           1265 ;	genAssign
   029E C2 8E              1266 	clr	_TCON_6
                           1267 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:175: deltime=0xFFFF-deltime;
                           1268 ;	genMinus
   02A0 74 FF              1269 	mov	a,#0xFF
   02A2 C3                 1270 	clr	c
                           1271 ;	Peephole 236.l	used r2 instead of ar2
   02A3 9A                 1272 	subb	a,r2
   02A4 FA                 1273 	mov	r2,a
   02A5 74 FF              1274 	mov	a,#0xFF
                           1275 ;	Peephole 236.l	used r3 instead of ar3
   02A7 9B                 1276 	subb	a,r3
   02A8 FB                 1277 	mov	r3,a
                           1278 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:176: TH1=deltime>>8;			// Timer 1 setzen 
                           1279 ;	genGetByte
   02A9 8B 8D              1280 	mov	_TH1,r3
                           1281 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:177: TL1=deltime;	
                           1282 ;	genCast
   02AB 8A 8B              1283 	mov	_TL1,r2
                           1284 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:178: TF1=0;
                           1285 ;	genAssign
   02AD C2 8F              1286 	clr	_TCON_7
                           1287 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:179: TR1=1;
                           1288 ;	genAssign
   02AF D2 8E              1289 	setb	_TCON_6
                           1290 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:180: while(!TF1);				// warten auf Timer 1
   02B1                    1291 00101$:
                           1292 ;	genIfx
                           1293 ;	genIfxJump
                           1294 ;	Peephole 108.d	removed ljmp by inverse jump logic
   02B1 30 8F FD           1295 	jnb	_TCON_7,00101$
                           1296 ;	Peephole 300	removed redundant label 00108$
                           1297 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:181: TR1=0;		
                           1298 ;	genAssign
   02B4 C2 8E              1299 	clr	_TCON_6
                           1300 ;	Peephole 300	removed redundant label 00104$
   02B6 22                 1301 	ret
                           1302 ;------------------------------------------------------------
                           1303 ;Allocation info for local variables in function 'set_timer1'
                           1304 ;------------------------------------------------------------
                           1305 ;deltime                   Allocated to registers r2 r3 
                           1306 ;------------------------------------------------------------
                           1307 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:185: void set_timer1(int deltime)		// Warten, deltime = Anzahl Takte
                           1308 ;	-----------------------------------------
                           1309 ;	 function set_timer1
                           1310 ;	-----------------------------------------
   02B7                    1311 _set_timer1:
                           1312 ;	genReceive
   02B7 AA 82              1313 	mov	r2,dpl
   02B9 AB 83              1314 	mov	r3,dph
                           1315 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:187: TR1=0;				// Timer 1 anhalten
                           1316 ;	genAssign
   02BB C2 8E              1317 	clr	_TCON_6
                           1318 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:188: deltime=0xFFFF-deltime;
                           1319 ;	genMinus
   02BD 74 FF              1320 	mov	a,#0xFF
   02BF C3                 1321 	clr	c
                           1322 ;	Peephole 236.l	used r2 instead of ar2
   02C0 9A                 1323 	subb	a,r2
   02C1 FA                 1324 	mov	r2,a
   02C2 74 FF              1325 	mov	a,#0xFF
                           1326 ;	Peephole 236.l	used r3 instead of ar3
   02C4 9B                 1327 	subb	a,r3
   02C5 FB                 1328 	mov	r3,a
                           1329 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:189: TH1=deltime>>8;			// Timer 1 setzen 
                           1330 ;	genGetByte
   02C6 8B 8D              1331 	mov	_TH1,r3
                           1332 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:190: TL1=deltime;	
                           1333 ;	genCast
   02C8 8A 8B              1334 	mov	_TL1,r2
                           1335 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:191: TF1=0;				// Überlauf-Flag zurücksetzen
                           1336 ;	genAssign
   02CA C2 8F              1337 	clr	_TCON_7
                           1338 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:192: TR1=1;				// Timer 1 starten
                           1339 ;	genAssign
   02CC D2 8E              1340 	setb	_TCON_6
                           1341 ;	Peephole 300	removed redundant label 00101$
   02CE 22                 1342 	ret
                           1343 ;------------------------------------------------------------
                           1344 ;Allocation info for local variables in function 'read_byte'
                           1345 ;------------------------------------------------------------
                           1346 ;addrl                     Allocated to stack - offset -3
                           1347 ;addrh                     Allocated to registers r2 
                           1348 ;zdata                     Allocated to registers 
                           1349 ;------------------------------------------------------------
                           1350 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:196: unsigned char read_byte(unsigned char addrh, unsigned char addrl)		// liest byte aus flash
                           1351 ;	-----------------------------------------
                           1352 ;	 function read_byte
                           1353 ;	-----------------------------------------
   02CF                    1354 _read_byte:
   02CF C0 08              1355 	push	_bp
   02D1 85 81 08           1356 	mov	_bp,sp
                           1357 ;	genReceive
   02D4 AA 82              1358 	mov	r2,dpl
                           1359 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:200: zdata=dataflash[(addrh<<8)+addrl];
                           1360 ;	genCast
                           1361 ;	genLeftShift
                           1362 ;	genLeftShiftLiteral
                           1363 ;	genlshTwo
                           1364 ;	peephole 177.e	removed redundant move
   02D6 8A 03              1365 	mov	ar3,r2
   02D8 7A 00              1366 	mov	r2,#0x00
                           1367 ;	genCast
   02DA A8 08              1368 	mov	r0,_bp
   02DC 18                 1369 	dec	r0
   02DD 18                 1370 	dec	r0
   02DE 18                 1371 	dec	r0
   02DF 86 04              1372 	mov	ar4,@r0
   02E1 7D 00              1373 	mov	r5,#0x00
                           1374 ;	genPlus
                           1375 ;	Peephole 236.g	used r4 instead of ar4
   02E3 EC                 1376 	mov	a,r4
                           1377 ;	Peephole 236.a	used r2 instead of ar2
   02E4 2A                 1378 	add	a,r2
   02E5 FA                 1379 	mov	r2,a
                           1380 ;	Peephole 236.g	used r5 instead of ar5
   02E6 ED                 1381 	mov	a,r5
                           1382 ;	Peephole 236.b	used r3 instead of ar3
   02E7 3B                 1383 	addc	a,r3
   02E8 FB                 1384 	mov	r3,a
                           1385 ;	genPlus
                           1386 ;     genPlus aligned array
   02E9 8A 82              1387 	mov	dpl,r2
   02EB 74 1C              1388 	mov	a,#(_dataflash >> 8)
   02ED 2B                 1389 	add	a,r3
   02EE F5 83              1390 	mov	dph,a
                           1391 ;	genPointerGet
                           1392 ;	genCodePointerGet
   02F0 E4                 1393 	clr	a
   02F1 93                 1394 	movc	a,@a+dptr
                           1395 ;	genAssign
   02F2 FA                 1396 	mov	r2,a
                           1397 ;	Peephole 244.c	loading dpl from a instead of r2
   02F3 F5 82              1398 	mov	dpl,a
                           1399 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:201: return (zdata);
                           1400 ;	genRet
                           1401 ;	Peephole 300	removed redundant label 00101$
   02F5 D0 08              1402 	pop	_bp
   02F7 22                 1403 	ret
                           1404 ;------------------------------------------------------------
                           1405 ;Allocation info for local variables in function 'restart_hw'
                           1406 ;------------------------------------------------------------
                           1407 ;------------------------------------------------------------
                           1408 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:205: void restart_hw(void)	// Alle Hardware Einstellungen zurücksetzen
                           1409 ;	-----------------------------------------
                           1410 ;	 function restart_hw
                           1411 ;	-----------------------------------------
   02F8                    1412 _restart_hw:
                           1413 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:209: DIVM=0;		// Taktferquenz nicht teilen -> volles Tempo
                           1414 ;	genAssign
   02F8 75 95 00           1415 	mov	_DIVM,#0x00
                           1416 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:211: P1M1=0x14;		// Port 1 auf quasi-bidirektional, außer P1.2(T0 als PWM Ausgang)=open-drain, P1.4(INT1)=Input only, P1.6(FBOUTC) push-pull
                           1417 ;	genAssign
   02FB 75 91 14           1418 	mov	_P1M1,#0x14
                           1419 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:212: P1M2=0x44;
                           1420 ;	genAssign
   02FE 75 92 44           1421 	mov	_P1M2,#0x44
                           1422 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:214: FBOUTC=0;		// Bus-Ausgang auf low
                           1423 ;	genAssign
   0301 C2 96              1424 	clr	_P1_6
                           1425 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:216: TMOD=0x12;		// Timer 0 als PWM, Timer 1 als 16-Bit Timer
                           1426 ;	genAssign
   0303 75 89 12           1427 	mov	_TMOD,#0x12
                           1428 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:217: TAMOD=0x01;
                           1429 ;	genAssign
   0306 75 8F 01           1430 	mov	_TAMOD,#0x01
                           1431 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:218: TH0=DUTY;		// Pulsverhältnis PWM
                           1432 ;	genAssign
   0309 75 8C C0           1433 	mov	_TH0,#0xC0
                           1434 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:219: AUXR1|=0x10;		// PWM von Timer 0 auf Pin ausgeben, gleichzeitig low-powermode ein (da <8MHz)
                           1435 ;	genOr
   030C 43 A2 10           1436 	orl	_AUXR1,#0x10
                           1437 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:221: ET0=0;		// Interrupt für Timer 0 sperren 
                           1438 ;	genAssign
   030F C2 A9              1439 	clr	_IEN0_1
                           1440 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:222: TR0=1;		// Timer 0 starten (PWM)
                           1441 ;	genAssign
   0311 D2 8C              1442 	setb	_TCON_4
                           1443 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:223: TR1=0;		// Timer 1 (Empfangs-Timeout) zunächst stoppen
                           1444 ;	genAssign
   0313 C2 8E              1445 	clr	_TCON_6
                           1446 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:225: RTCH=0x1D;		// Real Time Clock
                           1447 ;	genAssign
   0315 75 D2 1D           1448 	mov	_RTCH,#0x1D
                           1449 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:226: RTCL=0x40;
                           1450 ;	genAssign
   0318 75 D3 40           1451 	mov	_RTCL,#0x40
                           1452 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:227: RTCCON=0x61;
                           1453 ;	genAssign
   031B 75 D1 61           1454 	mov	_RTCCON,#0x61
                           1455 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:229: IEN0=0x00;
                           1456 ;	genAssign
   031E 75 A8 00           1457 	mov	_IEN0,#0x00
                           1458 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:230: IEN1=0x00;
                           1459 ;	genAssign
   0321 75 E8 00           1460 	mov	_IEN1,#0x00
                           1461 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:231: EA=1;			// Interrupts prinzipiell freigeben
                           1462 ;	genAssign
   0324 D2 AF              1463 	setb	_IEN0_7
                           1464 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:232: EX0=0;		// Externen Interrupt 0 sperren
                           1465 ;	genAssign
   0326 C2 A8              1466 	clr	_IEN0_0
                           1467 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:233: EX1=1;		// Externen Interrupt 1 freigeben	
                           1468 ;	genAssign
   0328 D2 AA              1469 	setb	_IEN0_2
                           1470 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:235: IP0=0x0C;		// höchste Priorität für ext. Int. 1 und Timer 1 (Bit 0 und 3)
                           1471 ;	genAssign
   032A 75 B8 0C           1472 	mov	_IP0,#0x0C
                           1473 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:236: IP0H=0x0C;
                           1474 ;	genAssign
   032D 75 B7 0C           1475 	mov	_IP0H,#0x0C
                           1476 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:237: IP1=0x00;
                           1477 ;	genAssign
   0330 75 F8 00           1478 	mov	_IP1,#0x00
                           1479 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:238: IP1H=0x00;
                           1480 ;	genAssign
   0333 75 F7 00           1481 	mov	_IP1H,#0x00
                           1482 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:239: IT1=1;		// Int1 flankengetriggert=1 pegelgetriggert=0
                           1483 ;	genAssign
   0336 D2 8A              1484 	setb	_TCON_2
                           1485 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:241: SCON=0x50;		// Serielle auf Mode 1, receive enable
                           1486 ;	genAssign
   0338 75 98 50           1487 	mov	_SCON,#0x50
                           1488 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:242: SSTAT|=0x40;		// TI wird am Ende des Stopbits gesetzt
                           1489 ;	genOr
   033B 43 BA 40           1490 	orl	_SSTAT,#0x40
                           1491 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:243: BRGCON|=0x02;		// Baudrate Generator verwenden aber noch gestoppt
                           1492 ;	genOr
   033E 43 BD 02           1493 	orl	_BRGCON,#0x02
                           1494 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:244: BRGR1=0x00;		// Baudrate = cclk/((BRGR1,BRGR0)+16)
                           1495 ;	genAssign
   0341 75 BF 00           1496 	mov	_BRGR1,#0x00
                           1497 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:245: BRGR0=0x30;
                           1498 ;	genAssign
   0344 75 BE 30           1499 	mov	_BRGR0,#0x30
                           1500 ;	s:/elektronik/eib/c/fb_common/fb_hal_lpc.c:246: BRGCON|=0x01;		// Baudrate Generator starten
                           1501 ;	genOr
   0347 43 BD 01           1502 	orl	_BRGCON,#0x01
                           1503 ;	Peephole 300	removed redundant label 00101$
   034A 22                 1504 	ret
                           1505 ;------------------------------------------------------------
                           1506 ;Allocation info for local variables in function 'timer1'
                           1507 ;------------------------------------------------------------
                           1508 ;data_laenge               Allocated to registers r2 
                           1509 ;daf                       Allocated to registers r3 
                           1510 ;------------------------------------------------------------
                           1511 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:12: void timer1(void) interrupt 3	// Interrupt von Timer 1, 370us keine Busaktivität seit letztem Byte, d.h. Telegramm wurde komplett übertragen
                           1512 ;	-----------------------------------------
                           1513 ;	 function timer1
                           1514 ;	-----------------------------------------
   034B                    1515 _timer1:
   034B C0 E0              1516 	push	acc
   034D C0 F0              1517 	push	b
   034F C0 82              1518 	push	dpl
   0351 C0 83              1519 	push	dph
   0353 C0 02              1520 	push	(0+2)
   0355 C0 03              1521 	push	(0+3)
   0357 C0 04              1522 	push	(0+4)
   0359 C0 05              1523 	push	(0+5)
   035B C0 06              1524 	push	(0+6)
   035D C0 07              1525 	push	(0+7)
   035F C0 00              1526 	push	(0+0)
   0361 C0 01              1527 	push	(0+1)
   0363 C0 21              1528 	push	bits
   0365 C0 D0              1529 	push	psw
   0367 75 D0 00           1530 	mov	psw,#0x00
                           1531 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:16: EX1=0;					// ext. Interrupt stoppen 
                           1532 ;	genAssign
   036A C2 AA              1533 	clr	_IEN0_2
                           1534 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:17: ET1=0;					// Interrupt von Timer 1 sperren
                           1535 ;	genAssign
   036C C2 AB              1536 	clr	_IEN0_3
                           1537 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:18: TR1=0;					// Timer 1 anhalten
                           1538 ;	genAssign
   036E C2 8E              1539 	clr	_TCON_6
                           1540 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:19: TF1=0;
                           1541 ;	genAssign
   0370 C2 8F              1542 	clr	_TCON_7
                           1543 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:20: TH1=0xED;					// und neu starten für korrekte Positionierung des ACK Bytes
                           1544 ;	genAssign
   0372 75 8D ED           1545 	mov	_TH1,#0xED
                           1546 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:21: TL1=0x80;				
                           1547 ;	genAssign
   0375 75 8B 80           1548 	mov	_TL1,#0x80
                           1549 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:22: TR1=1;
                           1550 ;	genAssign
   0378 D2 8E              1551 	setb	_TCON_6
                           1552 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:25: if(cs==0xff)					// Checksum des Telegramms ist OK 
                           1553 ;	genCmpEq
                           1554 ;	gencjneshort
   037A E5 3A              1555 	mov	a,_cs
   037C B4 FF 02           1556 	cjne	a,#0xFF,00182$
   037F 80 03              1557 	sjmp	00183$
   0381                    1558 00182$:
   0381 02 04 82           1559 	ljmp	00150$
   0384                    1560 00183$:
                           1561 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:27: data_laenge=(telegramm[5]&0x0F);		// Telegramm-Länge = Bit 0 bis 3 
                           1562 ;	genAssign
                           1563 ;	genAnd
   0384 74 0F              1564 	mov	a,#0x0F
   0386 55 27              1565 	anl	a,0x0005 + _telegramm
   0388 FA                 1566 	mov	r2,a
                           1567 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:28: daf=(telegramm[5]&0x80);			// Destination Adress Flag = Bit 7, 0=phys. Adr., 1=Gruppenadr.
                           1568 ;	genAnd
   0389 74 80              1569 	mov	a,#0x80
   038B 55 27              1570 	anl	a,0x0005 + _telegramm
   038D FB                 1571 	mov	r3,a
                           1572 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:30: if(telegramm[3]==0 && telegramm[4]==0)		// Broadcast, wenn Zieladresse = 0
                           1573 ;	genPointerGet
                           1574 ;	genNearPointerGet
                           1575 ;	genDataPointerGet
                           1576 ;	genIfx
                           1577 ;	peephole 177.g	optimized mov sequence
   038E E5 25              1578 	mov	a,(_telegramm + 0x0003)
   0390 FC                 1579 	mov	r4,a
                           1580 ;	genIfxJump
                           1581 ;	Peephole 108.b	removed ljmp by inverse jump logic
   0391 70 30              1582 	jnz	00146$
                           1583 ;	Peephole 300	removed redundant label 00184$
                           1584 ;	genPointerGet
                           1585 ;	genNearPointerGet
                           1586 ;	genDataPointerGet
   0393 E5 26              1587 	mov	a,(_telegramm + 0x0004)
                           1588 ;	genIfx
                           1589 ;	genIfxJump
                           1590 ;	Peephole 108.b	removed ljmp by inverse jump logic
   0395 70 2C              1591 	jnz	00146$
                           1592 ;	Peephole 300	removed redundant label 00185$
                           1593 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:32: if(progmode)
                           1594 ;	genIfx
                           1595 ;	genIfxJump
   0397 20 01 03           1596 	jb	_progmode,00186$
   039A 02 04 82           1597 	ljmp	00150$
   039D                    1598 00186$:
                           1599 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:34: if(data_laenge==3 && telegramm[6]==0x00 && telegramm[7]==0xC0) set_pa();	// set_pa_req
                           1600 ;	genCmpEq
                           1601 ;	gencjneshort
                           1602 ;	Peephole 112.b	changed ljmp to sjmp
                           1603 ;	Peephole 198.b	optimized misc jump sequence
   039D BA 03 0C           1604 	cjne	r2,#0x03,00102$
                           1605 ;	Peephole 200.b	removed redundant sjmp
                           1606 ;	Peephole 300	removed redundant label 00187$
                           1607 ;	Peephole 300	removed redundant label 00188$
                           1608 ;	genPointerGet
                           1609 ;	genNearPointerGet
                           1610 ;	genDataPointerGet
   03A0 E5 28              1611 	mov	a,(_telegramm + 0x0006)
                           1612 ;	genIfx
                           1613 ;	genIfxJump
                           1614 ;	Peephole 108.b	removed ljmp by inverse jump logic
   03A2 70 08              1615 	jnz	00102$
                           1616 ;	Peephole 300	removed redundant label 00189$
                           1617 ;	genAssign
                           1618 ;	genCmpEq
                           1619 ;	gencjneshort
   03A4 E5 29              1620 	mov	a,0x0007 + _telegramm
                           1621 ;	Peephole 112.b	changed ljmp to sjmp
                           1622 ;	Peephole 198.b	optimized misc jump sequence
   03A6 B4 C0 03           1623 	cjne	a,#0xC0,00102$
                           1624 ;	Peephole 200.b	removed redundant sjmp
                           1625 ;	Peephole 300	removed redundant label 00190$
                           1626 ;	Peephole 300	removed redundant label 00191$
                           1627 ;	genCall
   03A9 12 06 FA           1628 	lcall	_set_pa
   03AC                    1629 00102$:
                           1630 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:35: if(telegramm[6]==0x01 && telegramm[7]==0x00) read_pa();				// read_pa_req
                           1631 ;	genAssign
                           1632 ;	genCmpEq
                           1633 ;	gencjneshort
   03AC E5 28              1634 	mov	a,0x0006 + _telegramm
   03AE B4 01 02           1635 	cjne	a,#0x01,00192$
   03B1 80 03              1636 	sjmp	00193$
   03B3                    1637 00192$:
   03B3 02 04 82           1638 	ljmp	00150$
   03B6                    1639 00193$:
                           1640 ;	genPointerGet
                           1641 ;	genNearPointerGet
                           1642 ;	genDataPointerGet
   03B6 E5 29              1643 	mov	a,(_telegramm + 0x0007)
                           1644 ;	genIfx
                           1645 ;	genIfxJump
   03B8 60 03              1646 	jz	00194$
   03BA 02 04 82           1647 	ljmp	00150$
   03BD                    1648 00194$:
                           1649 ;	genCall
   03BD 12 07 26           1650 	lcall	_read_pa
   03C0 02 04 82           1651 	ljmp	00150$
   03C3                    1652 00146$:
                           1653 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:40: if(daf==0x00)					// Unicast, wenn Zieladresse physikalische Adresse ist
                           1654 ;	genIfx
   03C3 EB                 1655 	mov	a,r3
                           1656 ;	genIfxJump
   03C4 60 03              1657 	jz	00195$
   03C6 02 04 6A           1658 	ljmp	00143$
   03C9                    1659 00195$:
                           1660 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:42: if(telegramm[3]==pah && telegramm[4]==pal)	// nur wenn es die eigene phys. Adr. ist
                           1661 ;	genCmpEq
                           1662 ;	gencjneshort
   03C9 EC                 1663 	mov	a,r4
   03CA B5 3C 02           1664 	cjne	a,_pah,00196$
   03CD 80 03              1665 	sjmp	00197$
   03CF                    1666 00196$:
   03CF 02 04 82           1667 	ljmp	00150$
   03D2                    1668 00197$:
                           1669 ;	genAssign
                           1670 ;	genCmpEq
                           1671 ;	gencjneshort
   03D2 E5 26              1672 	mov	a,0x0004 + _telegramm
   03D4 B5 3B 02           1673 	cjne	a,_pal,00198$
   03D7 80 03              1674 	sjmp	00199$
   03D9                    1675 00198$:
   03D9 02 04 82           1676 	ljmp	00150$
   03DC                    1677 00199$:
                           1678 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:44: if((telegramm[6]&0xC3)==0x42 && (telegramm[7]&0xC0)==0x80) write_memory();	// write_memory_request beantworten
                           1679 ;	genAssign
                           1680 ;	genAnd
   03DC 74 C3              1681 	mov	a,#0xC3
   03DE 55 28              1682 	anl	a,0x0006 + _telegramm
   03E0 FB                 1683 	mov	r3,a
                           1684 ;	genCmpEq
                           1685 ;	gencjneshort
                           1686 ;	Peephole 112.b	changed ljmp to sjmp
                           1687 ;	Peephole 198.b	optimized misc jump sequence
   03E1 BB 42 0F           1688 	cjne	r3,#0x42,00111$
                           1689 ;	Peephole 200.b	removed redundant sjmp
                           1690 ;	Peephole 300	removed redundant label 00200$
                           1691 ;	Peephole 300	removed redundant label 00201$
                           1692 ;	genAssign
                           1693 ;	genAnd
   03E4 74 C0              1694 	mov	a,#0xC0
   03E6 55 29              1695 	anl	a,0x0007 + _telegramm
   03E8 FB                 1696 	mov	r3,a
                           1697 ;	genCmpEq
                           1698 ;	gencjneshort
                           1699 ;	Peephole 112.b	changed ljmp to sjmp
                           1700 ;	Peephole 198.b	optimized misc jump sequence
   03E9 BB 80 07           1701 	cjne	r3,#0x80,00111$
                           1702 ;	Peephole 200.b	removed redundant sjmp
                           1703 ;	Peephole 300	removed redundant label 00202$
                           1704 ;	Peephole 300	removed redundant label 00203$
                           1705 ;	genCall
   03EC C0 02              1706 	push	ar2
   03EE 12 06 73           1707 	lcall	_write_memory
   03F1 D0 02              1708 	pop	ar2
   03F3                    1709 00111$:
                           1710 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:45: if(data_laenge==0)
                           1711 ;	genIfx
   03F3 EA                 1712 	mov	a,r2
                           1713 ;	genIfxJump
                           1714 ;	Peephole 108.b	removed ljmp by inverse jump logic
   03F4 70 27              1715 	jnz	00120$
                           1716 ;	Peephole 300	removed redundant label 00204$
                           1717 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:47: if((telegramm[6]&0xC0)==0xC0) send_ack();				// auf NCD_Quittierung mit ACK antworten
                           1718 ;	genAssign
                           1719 ;	genAnd
   03F6 74 C0              1720 	mov	a,#0xC0
   03F8 55 28              1721 	anl	a,0x0006 + _telegramm
   03FA FB                 1722 	mov	r3,a
                           1723 ;	genCmpEq
                           1724 ;	gencjneshort
                           1725 ;	Peephole 112.b	changed ljmp to sjmp
                           1726 ;	Peephole 198.b	optimized misc jump sequence
   03FB BB C0 07           1727 	cjne	r3,#0xC0,00114$
                           1728 ;	Peephole 200.b	removed redundant sjmp
                           1729 ;	Peephole 300	removed redundant label 00205$
                           1730 ;	Peephole 300	removed redundant label 00206$
                           1731 ;	genCall
   03FE C0 02              1732 	push	ar2
   0400 12 05 A3           1733 	lcall	_send_ack
   0403 D0 02              1734 	pop	ar2
   0405                    1735 00114$:
                           1736 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:48: if(telegramm[6]==0x80) ucd_opr();					// UCD Verbindungsaufbau
                           1737 ;	genAssign
                           1738 ;	genCmpEq
                           1739 ;	gencjneshort
   0405 E5 28              1740 	mov	a,0x0006 + _telegramm
                           1741 ;	Peephole 112.b	changed ljmp to sjmp
                           1742 ;	Peephole 198.b	optimized misc jump sequence
   0407 B4 80 07           1743 	cjne	a,#0x80,00116$
                           1744 ;	Peephole 200.b	removed redundant sjmp
                           1745 ;	Peephole 300	removed redundant label 00207$
                           1746 ;	Peephole 300	removed redundant label 00208$
                           1747 ;	genCall
   040A C0 02              1748 	push	ar2
   040C 12 05 AF           1749 	lcall	_ucd_opr
   040F D0 02              1750 	pop	ar2
   0411                    1751 00116$:
                           1752 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:49: if(telegramm[6]==0x81) ucd_clr();					// UCD Verbindungsabbau
                           1753 ;	genAssign
                           1754 ;	genCmpEq
                           1755 ;	gencjneshort
   0411 E5 28              1756 	mov	a,0x0006 + _telegramm
                           1757 ;	Peephole 112.b	changed ljmp to sjmp
                           1758 ;	Peephole 198.b	optimized misc jump sequence
   0413 B4 81 07           1759 	cjne	a,#0x81,00120$
                           1760 ;	Peephole 200.b	removed redundant sjmp
                           1761 ;	Peephole 300	removed redundant label 00209$
                           1762 ;	Peephole 300	removed redundant label 00210$
                           1763 ;	genCall
   0416 C0 02              1764 	push	ar2
   0418 12 05 C1           1765 	lcall	_ucd_clr
   041B D0 02              1766 	pop	ar2
   041D                    1767 00120$:
                           1768 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:51: if(data_laenge==1)
                           1769 ;	genCmpEq
                           1770 ;	gencjneshort
                           1771 ;	Peephole 112.b	changed ljmp to sjmp
                           1772 ;	Peephole 198.b	optimized misc jump sequence
   041D BA 01 32           1773 	cjne	r2,#0x01,00128$
                           1774 ;	Peephole 200.b	removed redundant sjmp
                           1775 ;	Peephole 300	removed redundant label 00211$
                           1776 ;	Peephole 300	removed redundant label 00212$
                           1777 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:53: if((telegramm[6]&0x03)==0x03 && telegramm[7]==0x80)		// restart request
                           1778 ;	genAssign
                           1779 ;	genAnd
   0420 74 03              1780 	mov	a,#0x03
   0422 55 28              1781 	anl	a,0x0006 + _telegramm
   0424 FB                 1782 	mov	r3,a
                           1783 ;	genCmpEq
                           1784 ;	gencjneshort
                           1785 ;	Peephole 112.b	changed ljmp to sjmp
                           1786 ;	Peephole 198.b	optimized misc jump sequence
   0425 BB 03 1A           1787 	cjne	r3,#0x03,00122$
                           1788 ;	Peephole 200.b	removed redundant sjmp
                           1789 ;	Peephole 300	removed redundant label 00213$
                           1790 ;	Peephole 300	removed redundant label 00214$
                           1791 ;	genAssign
                           1792 ;	genCmpEq
                           1793 ;	gencjneshort
   0428 E5 29              1794 	mov	a,0x0007 + _telegramm
                           1795 ;	Peephole 112.b	changed ljmp to sjmp
                           1796 ;	Peephole 198.b	optimized misc jump sequence
   042A B4 80 15           1797 	cjne	a,#0x80,00122$
                           1798 ;	Peephole 200.b	removed redundant sjmp
                           1799 ;	Peephole 300	removed redundant label 00215$
                           1800 ;	Peephole 300	removed redundant label 00216$
                           1801 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:55: restart_hw();	// Hardware zurücksetzen
                           1802 ;	genCall
   042D C0 02              1803 	push	ar2
   042F 12 02 F8           1804 	lcall	_restart_hw
   0432 D0 02              1805 	pop	ar2
                           1806 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:56: restart_prot();	// Protokoll-relevante Parameter zurücksetzen
                           1807 ;	genCall
   0434 C0 02              1808 	push	ar2
   0436 12 09 99           1809 	lcall	_restart_prot
   0439 D0 02              1810 	pop	ar2
                           1811 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:57: restart_app();	// Anwendungsspezifische Einstellungen zurücksetzen
                           1812 ;	genCall
   043B C0 02              1813 	push	ar2
   043D 12 15 4F           1814 	lcall	_restart_app
   0440 D0 02              1815 	pop	ar2
   0442                    1816 00122$:
                           1817 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:59: if(telegramm[6]==0x43 && telegramm[7]==0x00) read_masq();		// Maskenversion angefordert
                           1818 ;	genAssign
                           1819 ;	genCmpEq
                           1820 ;	gencjneshort
   0442 E5 28              1821 	mov	a,0x0006 + _telegramm
                           1822 ;	Peephole 112.b	changed ljmp to sjmp
                           1823 ;	Peephole 198.b	optimized misc jump sequence
   0444 B4 43 0B           1824 	cjne	a,#0x43,00128$
                           1825 ;	Peephole 200.b	removed redundant sjmp
                           1826 ;	Peephole 300	removed redundant label 00217$
                           1827 ;	Peephole 300	removed redundant label 00218$
                           1828 ;	genPointerGet
                           1829 ;	genNearPointerGet
                           1830 ;	genDataPointerGet
   0447 E5 29              1831 	mov	a,(_telegramm + 0x0007)
                           1832 ;	genIfx
                           1833 ;	genIfxJump
                           1834 ;	Peephole 108.b	removed ljmp by inverse jump logic
   0449 70 07              1835 	jnz	00128$
                           1836 ;	Peephole 300	removed redundant label 00219$
                           1837 ;	genCall
   044B C0 02              1838 	push	ar2
   044D 12 05 FC           1839 	lcall	_read_masq
   0450 D0 02              1840 	pop	ar2
   0452                    1841 00128$:
                           1842 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:61: if(data_laenge==3)
                           1843 ;	genCmpEq
                           1844 ;	gencjneshort
                           1845 ;	Peephole 112.b	changed ljmp to sjmp
                           1846 ;	Peephole 198.b	optimized misc jump sequence
   0452 BA 03 2D           1847 	cjne	r2,#0x03,00150$
                           1848 ;	Peephole 200.b	removed redundant sjmp
                           1849 ;	Peephole 300	removed redundant label 00220$
                           1850 ;	Peephole 300	removed redundant label 00221$
                           1851 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:63: if((telegramm[6]&0xC3)==0x42 && (telegramm[7]&0xC0)==0x00) read_memory();	// read_memory_request beantworten
                           1852 ;	genAssign
                           1853 ;	genAnd
   0455 74 C3              1854 	mov	a,#0xC3
   0457 55 28              1855 	anl	a,0x0006 + _telegramm
   0459 FB                 1856 	mov	r3,a
                           1857 ;	genCmpEq
                           1858 ;	gencjneshort
                           1859 ;	Peephole 112.b	changed ljmp to sjmp
                           1860 ;	Peephole 198.b	optimized misc jump sequence
   045A BB 42 25           1861 	cjne	r3,#0x42,00150$
                           1862 ;	Peephole 200.b	removed redundant sjmp
                           1863 ;	Peephole 300	removed redundant label 00222$
                           1864 ;	Peephole 300	removed redundant label 00223$
                           1865 ;	genAssign
                           1866 ;	genAnd
   045D E5 29              1867 	mov	a,0x0007 + _telegramm
   045F 54 C0              1868 	anl	a,#0xC0
                           1869 ;	Peephole 160.c	removed sjmp by inverse jump logic
   0461 60 02              1870 	jz	00225$
                           1871 ;	Peephole 300	removed redundant label 00224$
                           1872 ;	Peephole 112.b	changed ljmp to sjmp
   0463 80 1D              1873 	sjmp	00150$
   0465                    1874 00225$:
                           1875 ;	genCall
   0465 12 06 17           1876 	lcall	_read_memory
                           1877 ;	Peephole 112.b	changed ljmp to sjmp
   0468 80 18              1878 	sjmp	00150$
   046A                    1879 00143$:
                           1880 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:70: if(data_laenge==1 && telegramm[6]==0x00 && ((telegramm[7]&0xFE)==0x80 || telegramm[7]==0x00)) eis1();	// Ausgänge schalten (EIS 1) oder lesen
                           1881 ;	genCmpEq
                           1882 ;	gencjneshort
                           1883 ;	Peephole 112.b	changed ljmp to sjmp
                           1884 ;	Peephole 198.b	optimized misc jump sequence
   046A BA 01 15           1885 	cjne	r2,#0x01,00150$
                           1886 ;	Peephole 200.b	removed redundant sjmp
                           1887 ;	Peephole 300	removed redundant label 00226$
                           1888 ;	Peephole 300	removed redundant label 00227$
                           1889 ;	genPointerGet
                           1890 ;	genNearPointerGet
                           1891 ;	genDataPointerGet
   046D E5 28              1892 	mov	a,(_telegramm + 0x0006)
                           1893 ;	genIfx
                           1894 ;	genIfxJump
                           1895 ;	Peephole 108.b	removed ljmp by inverse jump logic
   046F 70 11              1896 	jnz	00150$
                           1897 ;	Peephole 300	removed redundant label 00228$
                           1898 ;	genPointerGet
                           1899 ;	genNearPointerGet
                           1900 ;	genDataPointerGet
   0471 AA 29              1901 	mov	r2,(_telegramm + 0x0007)
                           1902 ;	genAnd
   0473 74 FE              1903 	mov	a,#0xFE
   0475 5A                 1904 	anl	a,r2
   0476 FB                 1905 	mov	r3,a
                           1906 ;	genCmpEq
                           1907 ;	gencjneshort
   0477 BB 80 02           1908 	cjne	r3,#0x80,00229$
                           1909 ;	Peephole 112.b	changed ljmp to sjmp
   047A 80 03              1910 	sjmp	00137$
   047C                    1911 00229$:
                           1912 ;	genIfx
   047C EA                 1913 	mov	a,r2
                           1914 ;	genIfxJump
                           1915 ;	Peephole 108.b	removed ljmp by inverse jump logic
   047D 70 03              1916 	jnz	00150$
                           1917 ;	Peephole 300	removed redundant label 00230$
   047F                    1918 00137$:
                           1919 ;	genCall
   047F 12 0B C4           1920 	lcall	_eis1
   0482                    1921 00150$:
                           1922 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:74: telpos=0;  
                           1923 ;	genAssign
   0482 75 39 00           1924 	mov	_telpos,#0x00
                           1925 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:75: IE1=0;		// IRQ zurücksetzen
                           1926 ;	genAssign
   0485 C2 8B              1927 	clr	_TCON_3
                           1928 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:76: EX1=1;		// externen Interrupt 0 wieder freigeben
                           1929 ;	genAssign
   0487 D2 AA              1930 	setb	_IEN0_2
                           1931 ;	Peephole 300	removed redundant label 00151$
   0489 D0 D0              1932 	pop	psw
   048B D0 21              1933 	pop	bits
   048D D0 01              1934 	pop	(0+1)
   048F D0 00              1935 	pop	(0+0)
   0491 D0 07              1936 	pop	(0+7)
   0493 D0 06              1937 	pop	(0+6)
   0495 D0 05              1938 	pop	(0+5)
   0497 D0 04              1939 	pop	(0+4)
   0499 D0 03              1940 	pop	(0+3)
   049B D0 02              1941 	pop	(0+2)
   049D D0 83              1942 	pop	dph
   049F D0 82              1943 	pop	dpl
   04A1 D0 F0              1944 	pop	b
   04A3 D0 E0              1945 	pop	acc
   04A5 32                 1946 	reti
                           1947 ;------------------------------------------------------------
                           1948 ;Allocation info for local variables in function 'get_ack'
                           1949 ;------------------------------------------------------------
                           1950 ;ret                       Allocated to registers r2 
                           1951 ;n                         Allocated to registers r3 r4 
                           1952 ;------------------------------------------------------------
                           1953 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:83: unsigned char get_ack(void)		// Byte empfangen und prüfen ob es ein ACK war
                           1954 ;	-----------------------------------------
                           1955 ;	 function get_ack
                           1956 ;	-----------------------------------------
   04A6                    1957 _get_ack:
                           1958 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:89: ret=0;
                           1959 ;	genAssign
   04A6 7A 00              1960 	mov	r2,#0x00
                           1961 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:90: do 
                           1962 ;	genAssign
   04A8 7B 00              1963 	mov	r3,#0x00
   04AA 7C 00              1964 	mov	r4,#0x00
   04AC                    1965 00107$:
                           1966 ;	genIfx
                           1967 ;	genIfxJump
                           1968 ;	Peephole 108.d	removed ljmp by inverse jump logic
   04AC 30 94 07           1969 	jnb	_P1_4,00105$
                           1970 ;	Peephole 300	removed redundant label 00118$
                           1971 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:92: if(FBINC==1) n++;
                           1972 ;	genPlus
                           1973 ;     genPlusIncr
   04AF 0B                 1974 	inc	r3
                           1975 ;	Peephole 112.b	changed ljmp to sjmp
                           1976 ;	Peephole 243	avoided branch to sjmp
   04B0 BB 00 1C           1977 	cjne	r3,#0x00,00108$
   04B3 0C                 1978 	inc	r4
                           1979 ;	Peephole 300	removed redundant label 00119$
   04B4 80 19              1980 	sjmp	00108$
   04B6                    1981 00105$:
                           1982 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:95: if (get_byte()==0xCC && parity_ok) ret=1;
                           1983 ;	genCall
   04B6 C0 02              1984 	push	ar2
   04B8 C0 03              1985 	push	ar3
   04BA C0 04              1986 	push	ar4
   04BC 12 00 7F           1987 	lcall	_get_byte
   04BF AD 82              1988 	mov	r5,dpl
   04C1 D0 04              1989 	pop	ar4
   04C3 D0 03              1990 	pop	ar3
   04C5 D0 02              1991 	pop	ar2
                           1992 ;	genCmpEq
                           1993 ;	gencjneshort
                           1994 ;	Peephole 112.b	changed ljmp to sjmp
                           1995 ;	Peephole 198.b	optimized misc jump sequence
   04C7 BD CC 05           1996 	cjne	r5,#0xCC,00108$
                           1997 ;	Peephole 200.b	removed redundant sjmp
                           1998 ;	Peephole 300	removed redundant label 00120$
                           1999 ;	Peephole 300	removed redundant label 00121$
                           2000 ;	genIfx
                           2001 ;	genIfxJump
                           2002 ;	Peephole 108.d	removed ljmp by inverse jump logic
   04CA 30 00 02           2003 	jnb	_parity_ok,00108$
                           2004 ;	Peephole 300	removed redundant label 00122$
                           2005 ;	genAssign
   04CD 7A 01              2006 	mov	r2,#0x01
   04CF                    2007 00108$:
                           2008 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:97: } while (n<3000);
                           2009 ;	genCmpLt
                           2010 ;	genCmp
   04CF C3                 2011 	clr	c
   04D0 EB                 2012 	mov	a,r3
   04D1 94 B8              2013 	subb	a,#0xB8
   04D3 EC                 2014 	mov	a,r4
   04D4 64 80              2015 	xrl	a,#0x80
   04D6 94 8B              2016 	subb	a,#0x8b
                           2017 ;	genIfxJump
                           2018 ;	Peephole 112.b	changed ljmp to sjmp
                           2019 ;	Peephole 160.a	removed sjmp by inverse jump logic
   04D8 40 D2              2020 	jc	00107$
                           2021 ;	Peephole 300	removed redundant label 00123$
                           2022 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:98: return(ret);
                           2023 ;	genRet
   04DA 8A 82              2024 	mov	dpl,r2
                           2025 ;	Peephole 300	removed redundant label 00110$
   04DC 22                 2026 	ret
                           2027 ;------------------------------------------------------------
                           2028 ;Allocation info for local variables in function 'send_telegramm'
                           2029 ;------------------------------------------------------------
                           2030 ;data_laenge               Allocated to stack - offset 1
                           2031 ;l                         Allocated to registers r5 
                           2032 ;checksum                  Allocated to registers r3 
                           2033 ;r                         Allocated to registers r2 
                           2034 ;------------------------------------------------------------
                           2035 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:103: void send_telegramm(void)		// sendet das Telegramm, das in telegramm[] vorher abgelegt wurde und berechnet die checksum
                           2036 ;	-----------------------------------------
                           2037 ;	 function send_telegramm
                           2038 ;	-----------------------------------------
   04DD                    2039 _send_telegramm:
   04DD C0 08              2040 	push	_bp
   04DF 85 81 08           2041 	mov	_bp,sp
   04E2 05 81              2042 	inc	sp
                           2043 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:107: r=0;
                           2044 ;	genAssign
   04E4 7A 00              2045 	mov	r2,#0x00
                           2046 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:108: do
   04E6                    2047 00108$:
                           2048 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:110: checksum=0;
                           2049 ;	genAssign
   04E6 7B 00              2050 	mov	r3,#0x00
                           2051 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:111: data_laenge=telegramm[5]&0x0F;	// Telegramm-Länge = Bit 0 bis 3
                           2052 ;	genAssign
                           2053 ;	genAnd
   04E8 A8 08              2054 	mov	r0,_bp
   04EA 08                 2055 	inc	r0
   04EB 74 0F              2056 	mov	a,#0x0F
   04ED 55 27              2057 	anl	a,0x0005 + _telegramm
   04EF F6                 2058 	mov	@r0,a
                           2059 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:113: set_timer1(18780);			// Warten bis Bus frei ist
                           2060 ;	genCall
                           2061 ;	Peephole 182.b	used 16 bit load of dptr
   04F0 90 49 5C           2062 	mov	dptr,#0x495C
   04F3 C0 02              2063 	push	ar2
   04F5 C0 03              2064 	push	ar3
   04F7 12 02 B7           2065 	lcall	_set_timer1
   04FA D0 03              2066 	pop	ar3
   04FC D0 02              2067 	pop	ar2
                           2068 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:114: while(!TF1)
   04FE                    2069 00103$:
                           2070 ;	genIfx
                           2071 ;	genIfxJump
                           2072 ;	Peephole 108.e	removed ljmp by inverse jump logic
   04FE 20 8F 13           2073 	jb	_TCON_7,00105$
                           2074 ;	Peephole 300	removed redundant label 00125$
                           2075 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:116: if(!FBINC) set_timer1(18780);
                           2076 ;	genIfx
                           2077 ;	genIfxJump
                           2078 ;	Peephole 108.e	removed ljmp by inverse jump logic
   0501 20 94 FA           2079 	jb	_P1_4,00103$
                           2080 ;	Peephole 300	removed redundant label 00126$
                           2081 ;	genCall
                           2082 ;	Peephole 182.b	used 16 bit load of dptr
   0504 90 49 5C           2083 	mov	dptr,#0x495C
   0507 C0 02              2084 	push	ar2
   0509 C0 03              2085 	push	ar3
   050B 12 02 B7           2086 	lcall	_set_timer1
   050E D0 03              2087 	pop	ar3
   0510 D0 02              2088 	pop	ar2
                           2089 ;	Peephole 112.b	changed ljmp to sjmp
   0512 80 EA              2090 	sjmp	00103$
   0514                    2091 00105$:
                           2092 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:118: TR1=0;
                           2093 ;	genAssign
   0514 C2 8E              2094 	clr	_TCON_6
                           2095 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:120: for(l=0;l<=data_laenge+6;l++)
                           2096 ;	genAssign
   0516 7D 00              2097 	mov	r5,#0x00
   0518                    2098 00111$:
                           2099 ;	genIpush
   0518 C0 02              2100 	push	ar2
                           2101 ;	genCast
   051A A8 08              2102 	mov	r0,_bp
   051C 08                 2103 	inc	r0
   051D 86 06              2104 	mov	ar6,@r0
   051F 7F 00              2105 	mov	r7,#0x00
                           2106 ;	genPlus
                           2107 ;     genPlusIncr
   0521 74 06              2108 	mov	a,#0x06
                           2109 ;	Peephole 236.a	used r6 instead of ar6
   0523 2E                 2110 	add	a,r6
   0524 FE                 2111 	mov	r6,a
                           2112 ;	Peephole 181	changed mov to clr
   0525 E4                 2113 	clr	a
                           2114 ;	Peephole 236.b	used r7 instead of ar7
   0526 3F                 2115 	addc	a,r7
   0527 FF                 2116 	mov	r7,a
                           2117 ;	genCast
   0528 8D 02              2118 	mov	ar2,r5
   052A 7C 00              2119 	mov	r4,#0x00
                           2120 ;	genCmpGt
                           2121 ;	genCmp
   052C C3                 2122 	clr	c
   052D EE                 2123 	mov	a,r6
   052E 9A                 2124 	subb	a,r2
   052F EF                 2125 	mov	a,r7
   0530 64 80              2126 	xrl	a,#0x80
   0532 8C F0              2127 	mov	b,r4
   0534 63 F0 80           2128 	xrl	b,#0x80
   0537 95 F0              2129 	subb	a,b
                           2130 ;	genIpop
                           2131 ;	genIfx
                           2132 ;	genIfxJump
                           2133 ;	Peephole 108.b	removed ljmp by inverse jump logic
                           2134 ;	Peephole 129.b	optimized condition
   0539 D0 02              2135 	pop	ar2
   053B 40 35              2136 	jc	00114$
                           2137 ;	Peephole 300	removed redundant label 00127$
                           2138 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:122: sendbyte(telegramm[l]);
                           2139 ;	genPlus
                           2140 ;	Peephole 236.g	used r5 instead of ar5
   053D ED                 2141 	mov	a,r5
   053E 24 22              2142 	add	a,#_telegramm
   0540 F8                 2143 	mov	r0,a
                           2144 ;	genPointerGet
                           2145 ;	genNearPointerGet
   0541 86 82              2146 	mov	dpl,@r0
                           2147 ;	genCall
   0543 C0 02              2148 	push	ar2
   0545 C0 03              2149 	push	ar3
   0547 C0 05              2150 	push	ar5
   0549 12 01 CF           2151 	lcall	_sendbyte
   054C D0 05              2152 	pop	ar5
   054E D0 03              2153 	pop	ar3
   0550 D0 02              2154 	pop	ar2
   0552 E4                 2155 	clr	a
   0553 33                 2156 	rlc	a
                           2157 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:123: checksum^=telegramm[l];
                           2158 ;	genPlus
                           2159 ;	Peephole 236.g	used r5 instead of ar5
   0554 ED                 2160 	mov	a,r5
   0555 24 22              2161 	add	a,#_telegramm
   0557 F8                 2162 	mov	r0,a
                           2163 ;	genPointerGet
                           2164 ;	genNearPointerGet
   0558 86 04              2165 	mov	ar4,@r0
                           2166 ;	genXor
   055A EC                 2167 	mov	a,r4
   055B 62 03              2168 	xrl	ar3,a
                           2169 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:124: delay(1230);			// Interbyte-Abstand
                           2170 ;	genCall
                           2171 ;	Peephole 182.b	used 16 bit load of dptr
   055D 90 04 CE           2172 	mov	dptr,#0x04CE
   0560 C0 02              2173 	push	ar2
   0562 C0 03              2174 	push	ar3
   0564 C0 05              2175 	push	ar5
   0566 12 02 9A           2176 	lcall	_delay
   0569 D0 05              2177 	pop	ar5
   056B D0 03              2178 	pop	ar3
   056D D0 02              2179 	pop	ar2
                           2180 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:120: for(l=0;l<=data_laenge+6;l++)
                           2181 ;	genPlus
                           2182 ;     genPlusIncr
   056F 0D                 2183 	inc	r5
                           2184 ;	Peephole 112.b	changed ljmp to sjmp
   0570 80 A6              2185 	sjmp	00111$
   0572                    2186 00114$:
                           2187 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:126: checksum=~checksum;
                           2188 ;	genCpl
   0572 EB                 2189 	mov	a,r3
   0573 F4                 2190 	cpl	a
                           2191 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:127: sendbyte(checksum);
                           2192 ;	genCall
   0574 FB                 2193 	mov	r3,a
                           2194 ;	Peephole 244.c	loading dpl from a instead of r3
   0575 F5 82              2195 	mov	dpl,a
   0577 C0 02              2196 	push	ar2
   0579 12 01 CF           2197 	lcall	_sendbyte
   057C D0 02              2198 	pop	ar2
   057E E4                 2199 	clr	a
   057F 33                 2200 	rlc	a
                           2201 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:128: if(get_ack()==1) r=3;		// wenn ACK empfangen, dann nicht nochmal senden
                           2202 ;	genCall
   0580 C0 02              2203 	push	ar2
   0582 12 04 A6           2204 	lcall	_get_ack
   0585 AB 82              2205 	mov	r3,dpl
   0587 D0 02              2206 	pop	ar2
                           2207 ;	genCmpEq
                           2208 ;	gencjneshort
                           2209 ;	Peephole 112.b	changed ljmp to sjmp
                           2210 ;	Peephole 198.b	optimized misc jump sequence
   0589 BB 01 02           2211 	cjne	r3,#0x01,00107$
                           2212 ;	Peephole 200.b	removed redundant sjmp
                           2213 ;	Peephole 300	removed redundant label 00128$
                           2214 ;	Peephole 300	removed redundant label 00129$
                           2215 ;	genAssign
   058C 7A 03              2216 	mov	r2,#0x03
   058E                    2217 00107$:
                           2218 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:129: r++;
                           2219 ;	genPlus
                           2220 ;     genPlusIncr
   058E 0A                 2221 	inc	r2
                           2222 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:130: telegramm[0]&=0xDF;			// Bit 5 löschen = Wiederholung
                           2223 ;	genAssign
                           2224 ;	genAnd
   058F 74 DF              2225 	mov	a,#0xDF
   0591 55 22              2226 	anl	a,_telegramm
                           2227 ;	genPointerSet
                           2228 ;	genNearPointerSet
                           2229 ;	genDataPointerSet
   0593 F5 22              2230 	mov	_telegramm,a
                           2231 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:132: while(r<=3); 				// falls kein ACK max. 3 Mal wiederholen
                           2232 ;	genCmpGt
                           2233 ;	genCmp
                           2234 ;	genIfxJump
                           2235 ;	Peephole 132.c	optimized genCmpGt by inverse logic (acc differs)
   0595 EA                 2236 	mov	a,r2
   0596 24 FC              2237 	add	a,#0xff - 0x03
   0598 40 03              2238 	jc	00130$
   059A 02 04 E6           2239 	ljmp	00108$
   059D                    2240 00130$:
                           2241 ;	Peephole 300	removed redundant label 00115$
   059D 85 08 81           2242 	mov	sp,_bp
   05A0 D0 08              2243 	pop	_bp
   05A2 22                 2244 	ret
                           2245 ;------------------------------------------------------------
                           2246 ;Allocation info for local variables in function 'send_ack'
                           2247 ;------------------------------------------------------------
                           2248 ;------------------------------------------------------------
                           2249 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:136: void send_ack(void)			// wartet auf Timer 1 wegen korrekter Positionierung und sendet ACK (0xCC)
                           2250 ;	-----------------------------------------
                           2251 ;	 function send_ack
                           2252 ;	-----------------------------------------
   05A3                    2253 _send_ack:
                           2254 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:138: while(!TF1) {}
   05A3                    2255 00101$:
                           2256 ;	genIfx
                           2257 ;	genIfxJump
                           2258 ;	Peephole 108.d	removed ljmp by inverse jump logic
   05A3 30 8F FD           2259 	jnb	_TCON_7,00101$
                           2260 ;	Peephole 300	removed redundant label 00108$
                           2261 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:139: sendbyte(0xCC);
                           2262 ;	genCall
   05A6 75 82 CC           2263 	mov	dpl,#0xCC
   05A9 12 01 CF           2264 	lcall	_sendbyte
   05AC E4                 2265 	clr	a
   05AD 33                 2266 	rlc	a
                           2267 ;	Peephole 300	removed redundant label 00104$
   05AE 22                 2268 	ret
                           2269 ;------------------------------------------------------------
                           2270 ;Allocation info for local variables in function 'ucd_opr'
                           2271 ;------------------------------------------------------------
                           2272 ;------------------------------------------------------------
                           2273 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:146: void ucd_opr(void)		// UCD Verbindungsaufbau
                           2274 ;	-----------------------------------------
                           2275 ;	 function ucd_opr
                           2276 ;	-----------------------------------------
   05AF                    2277 _ucd_opr:
                           2278 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:148: if(!connected)		// wenn bereits verbunden: ignorieren
                           2279 ;	genIfx
                           2280 ;	genIfxJump
                           2281 ;	Peephole 108.e	removed ljmp by inverse jump logic
   05AF 20 02 0E           2282 	jb	_connected,00103$
                           2283 ;	Peephole 300	removed redundant label 00106$
                           2284 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:150: connected=1;
                           2285 ;	genAssign
   05B2 D2 02              2286 	setb	_connected
                           2287 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:151: conh=telegramm[1];		// phys. Adresse des Verbindungspartners
                           2288 ;	genPointerGet
                           2289 ;	genNearPointerGet
                           2290 ;	genDataPointerGet
   05B4 85 23 3E           2291 	mov	_conh,(_telegramm + 0x0001)
                           2292 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:152: conl=telegramm[2];
                           2293 ;	genPointerGet
                           2294 ;	genNearPointerGet
                           2295 ;	genDataPointerGet
   05B7 85 24 3F           2296 	mov	_conl,(_telegramm + 0x0002)
                           2297 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:153: send_ack();			// quittieren
                           2298 ;	genCall
   05BA 12 05 A3           2299 	lcall	_send_ack
                           2300 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:154: pcount=1;			// Paketzähler zurücksetzen
                           2301 ;	genAssign
   05BD 75 40 01           2302 	mov	_pcount,#0x01
   05C0                    2303 00103$:
   05C0 22                 2304 	ret
                           2305 ;------------------------------------------------------------
                           2306 ;Allocation info for local variables in function 'ucd_clr'
                           2307 ;------------------------------------------------------------
                           2308 ;------------------------------------------------------------
                           2309 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:159: void ucd_clr(void)		// UCD Verbindungsabbau
                           2310 ;	-----------------------------------------
                           2311 ;	 function ucd_clr
                           2312 ;	-----------------------------------------
   05C1                    2313 _ucd_clr:
                           2314 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:161: if(conh==telegramm[1] && conl==telegramm[2] && connected)	// nur abbauen, wenn verbunden und Anforderung vom Verbindungspartner, kein ACK senden
                           2315 ;	genAssign
                           2316 ;	genCmpEq
                           2317 ;	gencjneshort
   05C1 E5 3E              2318 	mov	a,_conh
   05C3 B5 23 02           2319 	cjne	a,0x0001 + _telegramm,00110$
   05C6 80 01              2320 	sjmp	00111$
   05C8                    2321 00110$:
                           2322 ;	Peephole 112.b	changed ljmp to sjmp
                           2323 ;	Peephole 251.b	replaced sjmp to ret with ret
   05C8 22                 2324 	ret
   05C9                    2325 00111$:
                           2326 ;	genAssign
                           2327 ;	genCmpEq
                           2328 ;	gencjneshort
   05C9 E5 3F              2329 	mov	a,_conl
   05CB B5 24 02           2330 	cjne	a,0x0002 + _telegramm,00112$
   05CE 80 01              2331 	sjmp	00113$
   05D0                    2332 00112$:
                           2333 ;	Peephole 112.b	changed ljmp to sjmp
                           2334 ;	Peephole 251.b	replaced sjmp to ret with ret
   05D0 22                 2335 	ret
   05D1                    2336 00113$:
                           2337 ;	genIfx
                           2338 ;	genIfxJump
                           2339 ;	Peephole 108.d	removed ljmp by inverse jump logic
                           2340 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:163: connected=0;
                           2341 ;	genAssign
                           2342 ;	Peephole 250.a	using atomic test and clear
   05D1 10 02 01           2343 	jbc	_connected,00114$
                           2344 ;	Peephole 251.b	replaced sjmp to ret with ret
   05D4 22                 2345 	ret
   05D5                    2346 00114$:
                           2347 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:164: pcount=1;			// Paketzähler zurücksetzen
                           2348 ;	genAssign
   05D5 75 40 01           2349 	mov	_pcount,#0x01
                           2350 ;	Peephole 300	removed redundant label 00105$
   05D8 22                 2351 	ret
                           2352 ;------------------------------------------------------------
                           2353 ;Allocation info for local variables in function 'ncd_quit'
                           2354 ;------------------------------------------------------------
                           2355 ;------------------------------------------------------------
                           2356 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:169: void ncd_quit(void)			// NCD Quittierung zurück senden. Setzt telegramm Bytes 0 bis 6 !!!
                           2357 ;	-----------------------------------------
                           2358 ;	 function ncd_quit
                           2359 ;	-----------------------------------------
   05D9                    2360 _ncd_quit:
                           2361 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:171: telegramm[0]=0xB0;			// Control Byte			
                           2362 ;	genPointerSet
                           2363 ;	genNearPointerSet
                           2364 ;	genDataPointerSet
   05D9 75 22 B0           2365 	mov	_telegramm,#0xB0
                           2366 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:172: telegramm[3]=telegramm[1];		// Zieladresse wird Quelladresse
                           2367 ;	genPointerGet
                           2368 ;	genNearPointerGet
                           2369 ;	genDataPointerGet
   05DC AA 23              2370 	mov	r2,(_telegramm + 0x0001)
                           2371 ;	genPointerSet
                           2372 ;	genNearPointerSet
                           2373 ;	genDataPointerSet
   05DE 8A 25              2374 	mov	(_telegramm + 0x0003),r2
                           2375 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:173: telegramm[4]=telegramm[2];
                           2376 ;	genPointerGet
                           2377 ;	genNearPointerGet
                           2378 ;	genDataPointerGet
   05E0 AA 24              2379 	mov	r2,(_telegramm + 0x0002)
                           2380 ;	genPointerSet
                           2381 ;	genNearPointerSet
                           2382 ;	genDataPointerSet
   05E2 8A 26              2383 	mov	(_telegramm + 0x0004),r2
                           2384 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:174: telegramm[1]=pah;			// Quelladresse ist phys. Adresse
                           2385 ;	genPointerSet
                           2386 ;	genNearPointerSet
                           2387 ;	genDataPointerSet
   05E4 85 3C 23           2388 	mov	(_telegramm + 0x0001),_pah
                           2389 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:175: telegramm[2]=pal;
                           2390 ;	genPointerSet
                           2391 ;	genNearPointerSet
                           2392 ;	genDataPointerSet
   05E7 85 3B 24           2393 	mov	(_telegramm + 0x0002),_pal
                           2394 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:176: telegramm[5]=0x60;			// DRL
                           2395 ;	genPointerSet
                           2396 ;	genNearPointerSet
                           2397 ;	genDataPointerSet
   05EA 75 27 60           2398 	mov	(_telegramm + 0x0005),#0x60
                           2399 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:177: telegramm[6]|=0xC0;			// Bit 6 und 7 setzen (TCPI = 11 NCD Quittierung)
                           2400 ;	genAssign
                           2401 ;	genOr
   05ED 74 C0              2402 	mov	a,#0xC0
   05EF 45 28              2403 	orl	a,0x0006 + _telegramm
   05F1 FA                 2404 	mov	r2,a
                           2405 ;	genPointerSet
                           2406 ;	genNearPointerSet
                           2407 ;	genDataPointerSet
   05F2 8A 28              2408 	mov	(_telegramm + 0x0006),r2
                           2409 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:178: telegramm[6]&=0xFE;			// Bit 0 löschen 
                           2410 ;	genAnd
   05F4 74 FE              2411 	mov	a,#0xFE
   05F6 5A                 2412 	anl	a,r2
                           2413 ;	genPointerSet
                           2414 ;	genNearPointerSet
                           2415 ;	genDataPointerSet
   05F7 F5 28              2416 	mov	(_telegramm + 0x0006),a
                           2417 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:179: send_telegramm();
                           2418 ;	genCall
                           2419 ;	Peephole 253.b	replaced lcall/ret with ljmp
   05F9 02 04 DD           2420 	ljmp	_send_telegramm
                           2421 ;
                           2422 ;------------------------------------------------------------
                           2423 ;Allocation info for local variables in function 'read_masq'
                           2424 ;------------------------------------------------------------
                           2425 ;------------------------------------------------------------
                           2426 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:183: void read_masq(void)			// Maskenversion senden
                           2427 ;	-----------------------------------------
                           2428 ;	 function read_masq
                           2429 ;	-----------------------------------------
   05FC                    2430 _read_masq:
                           2431 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:187: send_ack();
                           2432 ;	genCall
   05FC 12 05 A3           2433 	lcall	_send_ack
                           2434 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:188: ncd_quit();				// NCD Quittierung senden
                           2435 ;	genCall
   05FF 12 05 D9           2436 	lcall	_ncd_quit
                           2437 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:190: telegramm[0]=0xB0;			// Control Byte
                           2438 ;	genPointerSet
                           2439 ;	genNearPointerSet
                           2440 ;	genDataPointerSet
   0602 75 22 B0           2441 	mov	_telegramm,#0xB0
                           2442 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:192: telegramm[5]=0x63;			// DRL
                           2443 ;	genPointerSet
                           2444 ;	genNearPointerSet
                           2445 ;	genDataPointerSet
   0605 75 27 63           2446 	mov	(_telegramm + 0x0005),#0x63
                           2447 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:193: telegramm[6]=0x43;
                           2448 ;	genPointerSet
                           2449 ;	genNearPointerSet
                           2450 ;	genDataPointerSet
   0608 75 28 43           2451 	mov	(_telegramm + 0x0006),#0x43
                           2452 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:194: telegramm[7]=0x40;
                           2453 ;	genPointerSet
                           2454 ;	genNearPointerSet
                           2455 ;	genDataPointerSet
   060B 75 29 40           2456 	mov	(_telegramm + 0x0007),#0x40
                           2457 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:195: telegramm[8]=0x00;
                           2458 ;	genPointerSet
                           2459 ;	genNearPointerSet
                           2460 ;	genDataPointerSet
   060E 75 2A 00           2461 	mov	(_telegramm + 0x0008),#0x00
                           2462 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:196: telegramm[9]=0x12;			// Maskenversion 1 = BCU1
                           2463 ;	genPointerSet
                           2464 ;	genNearPointerSet
                           2465 ;	genDataPointerSet
   0611 75 2B 12           2466 	mov	(_telegramm + 0x0009),#0x12
                           2467 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:197: send_telegramm();
                           2468 ;	genCall
                           2469 ;	Peephole 253.b	replaced lcall/ret with ljmp
   0614 02 04 DD           2470 	ljmp	_send_telegramm
                           2471 ;
                           2472 ;------------------------------------------------------------
                           2473 ;Allocation info for local variables in function 'read_memory'
                           2474 ;------------------------------------------------------------
                           2475 ;ab                        Allocated to registers r2 
                           2476 ;n                         Allocated to registers r3 
                           2477 ;------------------------------------------------------------
                           2478 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:202: void read_memory(void)			// read_memory_request - Speicher auslesen und senden
                           2479 ;	-----------------------------------------
                           2480 ;	 function read_memory
                           2481 ;	-----------------------------------------
   0617                    2482 _read_memory:
                           2483 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:206: send_ack();				// erstmal quittieren
                           2484 ;	genCall
   0617 12 05 A3           2485 	lcall	_send_ack
                           2486 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:207: ab=telegramm[7];			// Anzahl Bytes
                           2487 ;	genAssign
                           2488 ;	genAssign
   061A AA 29              2489 	mov	r2,0x0007 + _telegramm
                           2490 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:208: ncd_quit();
                           2491 ;	genCall
   061C C0 02              2492 	push	ar2
   061E 12 05 D9           2493 	lcall	_ncd_quit
   0621 D0 02              2494 	pop	ar2
                           2495 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:210: for(n=0;n<ab;n++)
                           2496 ;	genAssign
   0623 7B 00              2497 	mov	r3,#0x00
   0625                    2498 00101$:
                           2499 ;	genCmpLt
                           2500 ;	genCmp
   0625 C3                 2501 	clr	c
   0626 EB                 2502 	mov	a,r3
   0627 9A                 2503 	subb	a,r2
                           2504 ;	genIfxJump
                           2505 ;	Peephole 108.a	removed ljmp by inverse jump logic
   0628 50 27              2506 	jnc	00104$
                           2507 ;	Peephole 300	removed redundant label 00110$
                           2508 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:212: telegramm[n+10]=read_byte(telegramm[8],(telegramm[9]+n));    
                           2509 ;	genPlus
                           2510 ;     genPlusIncr
   062A 74 0A              2511 	mov	a,#0x0A
                           2512 ;	Peephole 236.a	used r3 instead of ar3
   062C 2B                 2513 	add	a,r3
                           2514 ;	genPlus
   062D 24 22              2515 	add	a,#_telegramm
   062F F8                 2516 	mov	r0,a
                           2517 ;	genAssign
                           2518 ;	genPlus
                           2519 ;	Peephole 236.g	used r3 instead of ar3
   0630 EB                 2520 	mov	a,r3
   0631 25 2B              2521 	add	a,0x0009 + _telegramm
   0633 FC                 2522 	mov	r4,a
                           2523 ;	genAssign
                           2524 ;	genIpush
   0634 C0 02              2525 	push	ar2
   0636 C0 03              2526 	push	ar3
   0638 C0 00              2527 	push	ar0
   063A C0 04              2528 	push	ar4
                           2529 ;	genCall
   063C 85 2A 82           2530 	mov	dpl,0x0008 + _telegramm
   063F 12 02 CF           2531 	lcall	_read_byte
   0642 AC 82              2532 	mov	r4,dpl
   0644 15 81              2533 	dec	sp
   0646 D0 00              2534 	pop	ar0
   0648 D0 03              2535 	pop	ar3
   064A D0 02              2536 	pop	ar2
                           2537 ;	genPointerSet
                           2538 ;	genNearPointerSet
   064C A6 04              2539 	mov	@r0,ar4
                           2540 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:210: for(n=0;n<ab;n++)
                           2541 ;	genPlus
                           2542 ;     genPlusIncr
   064E 0B                 2543 	inc	r3
                           2544 ;	Peephole 112.b	changed ljmp to sjmp
   064F 80 D4              2545 	sjmp	00101$
   0651                    2546 00104$:
                           2547 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:215: telegramm[0]=0xB0;			// read_memory_res senden
                           2548 ;	genPointerSet
                           2549 ;	genNearPointerSet
                           2550 ;	genDataPointerSet
   0651 75 22 B0           2551 	mov	_telegramm,#0xB0
                           2552 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:217: telegramm[5]=ab+0x63;		// DRL (Anzahl Bytes + 3)
                           2553 ;	genPlus
                           2554 ;     genPlusIncr
   0654 74 63              2555 	mov	a,#0x63
                           2556 ;	Peephole 236.a	used r2 instead of ar2
   0656 2A                 2557 	add	a,r2
                           2558 ;	genPointerSet
                           2559 ;	genNearPointerSet
                           2560 ;	genDataPointerSet
   0657 F5 27              2561 	mov	(_telegramm + 0x0005),a
                           2562 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:218: telegramm[6]=(pcount<<2)|0x42;	// Paketzähler, TCPI und ersten beiden Befehlsbits
                           2563 ;	genLeftShift
                           2564 ;	genLeftShiftLiteral
                           2565 ;	genlshOne
   0659 E5 40              2566 	mov	a,_pcount
                           2567 ;	Peephole 254	optimized left shift
   065B 25 40              2568 	add	a,_pcount
   065D 25 E0              2569 	add	a,acc
   065F FB                 2570 	mov	r3,a
                           2571 ;	genOr
   0660 74 42              2572 	mov	a,#0x42
   0662 4B                 2573 	orl	a,r3
                           2574 ;	genPointerSet
                           2575 ;	genNearPointerSet
                           2576 ;	genDataPointerSet
   0663 F5 28              2577 	mov	(_telegramm + 0x0006),a
                           2578 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:219: telegramm[7]=ab|0x40;		// letzten 2 Befehlsbits
                           2579 ;	genOr
   0665 74 40              2580 	mov	a,#0x40
   0667 4A                 2581 	orl	a,r2
                           2582 ;	genPointerSet
                           2583 ;	genNearPointerSet
                           2584 ;	genDataPointerSet
   0668 F5 29              2585 	mov	(_telegramm + 0x0007),a
                           2586 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:220: send_telegramm();
                           2587 ;	genCall
   066A 12 04 DD           2588 	lcall	_send_telegramm
                           2589 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:222: pcount++;				// Paketzähler erhöhen
                           2590 ;	genPlus
                           2591 ;     genPlusIncr
   066D 05 40              2592 	inc	_pcount
                           2593 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:223: pcount&=0x0F;				// max. 15
                           2594 ;	genAnd
   066F 53 40 0F           2595 	anl	_pcount,#0x0F
                           2596 ;	Peephole 300	removed redundant label 00105$
   0672 22                 2597 	ret
                           2598 ;------------------------------------------------------------
                           2599 ;Allocation info for local variables in function 'write_memory'
                           2600 ;------------------------------------------------------------
                           2601 ;ab                        Allocated to registers r2 
                           2602 ;n                         Allocated to registers r3 
                           2603 ;------------------------------------------------------------
                           2604 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:227: void write_memory(void)			// write_memory_request - empfangene Daten in Speicher schreiben
                           2605 ;	-----------------------------------------
                           2606 ;	 function write_memory
                           2607 ;	-----------------------------------------
   0673                    2608 _write_memory:
                           2609 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:231: send_ack();
                           2610 ;	genCall
   0673 12 05 A3           2611 	lcall	_send_ack
                           2612 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:232: ab=telegramm[7]&0x0F;			// Anzahl Bytes
                           2613 ;	genAssign
                           2614 ;	genAnd
   0676 74 0F              2615 	mov	a,#0x0F
   0678 55 29              2616 	anl	a,0x0007 + _telegramm
   067A FA                 2617 	mov	r2,a
                           2618 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:233: ncd_quit();
                           2619 ;	genCall
   067B C0 02              2620 	push	ar2
   067D 12 05 D9           2621 	lcall	_ncd_quit
   0680 D0 02              2622 	pop	ar2
                           2623 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:235: start_writecycle();
                           2624 ;	genCall
   0682 C0 02              2625 	push	ar2
   0684 12 02 70           2626 	lcall	_start_writecycle
   0687 D0 02              2627 	pop	ar2
                           2628 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:236: for(n=0;n<ab;n++) 
                           2629 ;	genAssign
   0689 7B 00              2630 	mov	r3,#0x00
   068B                    2631 00104$:
                           2632 ;	genCmpLt
                           2633 ;	genCmp
   068B C3                 2634 	clr	c
   068C EB                 2635 	mov	a,r3
   068D 9A                 2636 	subb	a,r2
                           2637 ;	genIfxJump
                           2638 ;	Peephole 108.a	removed ljmp by inverse jump logic
   068E 50 67              2639 	jnc	00107$
                           2640 ;	Peephole 300	removed redundant label 00115$
                           2641 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:238: write_byte(telegramm[8],telegramm[9]+n,telegramm[n+10]);
                           2642 ;	genPlus
                           2643 ;     genPlusIncr
   0690 74 0A              2644 	mov	a,#0x0A
                           2645 ;	Peephole 236.a	used r3 instead of ar3
   0692 2B                 2646 	add	a,r3
                           2647 ;	genPlus
   0693 24 22              2648 	add	a,#_telegramm
   0695 F8                 2649 	mov	r0,a
                           2650 ;	genPointerGet
                           2651 ;	genNearPointerGet
   0696 86 04              2652 	mov	ar4,@r0
                           2653 ;	genAssign
                           2654 ;	genPlus
                           2655 ;	Peephole 236.g	used r3 instead of ar3
   0698 EB                 2656 	mov	a,r3
   0699 25 2B              2657 	add	a,0x0009 + _telegramm
   069B FD                 2658 	mov	r5,a
                           2659 ;	genAssign
                           2660 ;	genIpush
   069C C0 02              2661 	push	ar2
   069E C0 03              2662 	push	ar3
   06A0 C0 04              2663 	push	ar4
                           2664 ;	genIpush
   06A2 C0 05              2665 	push	ar5
                           2666 ;	genCall
   06A4 85 2A 82           2667 	mov	dpl,0x0008 + _telegramm
   06A7 12 02 78           2668 	lcall	_write_byte
   06AA 15 81              2669 	dec	sp
   06AC 15 81              2670 	dec	sp
   06AE D0 03              2671 	pop	ar3
   06B0 D0 02              2672 	pop	ar2
                           2673 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:239: if ((((telegramm[9]+n)&0x3F)==0x3F) && n!=(ab-1))		// Ende des 64-Byte Pageregisters, also zwischendurch flashen
                           2674 ;	genAssign
                           2675 ;	genCast
   06B2 AC 2B              2676 	mov	r4,0x0009 + _telegramm
   06B4 7D 00              2677 	mov	r5,#0x00
                           2678 ;	genCast
   06B6 8B 06              2679 	mov	ar6,r3
   06B8 7F 00              2680 	mov	r7,#0x00
                           2681 ;	genPlus
                           2682 ;	Peephole 236.g	used r6 instead of ar6
   06BA EE                 2683 	mov	a,r6
                           2684 ;	Peephole 236.a	used r4 instead of ar4
   06BB 2C                 2685 	add	a,r4
   06BC FC                 2686 	mov	r4,a
                           2687 ;	Peephole 236.g	used r7 instead of ar7
   06BD EF                 2688 	mov	a,r7
                           2689 ;	Peephole 236.b	used r5 instead of ar5
   06BE 3D                 2690 	addc	a,r5
   06BF FD                 2691 	mov	r5,a
                           2692 ;	genAnd
   06C0 53 04 3F           2693 	anl	ar4,#0x3F
   06C3 7D 00              2694 	mov	r5,#0x00
                           2695 ;	genCmpEq
                           2696 ;	gencjneshort
                           2697 ;	Peephole 112.b	changed ljmp to sjmp
                           2698 ;	Peephole 198.a	optimized misc jump sequence
   06C5 BC 3F 2C           2699 	cjne	r4,#0x3F,00106$
   06C8 BD 00 29           2700 	cjne	r5,#0x00,00106$
                           2701 ;	Peephole 200.b	removed redundant sjmp
                           2702 ;	Peephole 300	removed redundant label 00116$
                           2703 ;	Peephole 300	removed redundant label 00117$
                           2704 ;	genCast
   06CB 8A 04              2705 	mov	ar4,r2
   06CD 7D 00              2706 	mov	r5,#0x00
                           2707 ;	genMinus
                           2708 ;	genMinusDec
   06CF 1C                 2709 	dec	r4
   06D0 BC FF 01           2710 	cjne	r4,#0xff,00118$
   06D3 1D                 2711 	dec	r5
   06D4                    2712 00118$:
                           2713 ;	genCmpEq
                           2714 ;	gencjneshort
   06D4 EE                 2715 	mov	a,r6
   06D5 B5 04 06           2716 	cjne	a,ar4,00119$
   06D8 EF                 2717 	mov	a,r7
   06D9 B5 05 02           2718 	cjne	a,ar5,00119$
                           2719 ;	Peephole 112.b	changed ljmp to sjmp
   06DC 80 16              2720 	sjmp	00106$
   06DE                    2721 00119$:
                           2722 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:241: stop_writecycle();
                           2723 ;	genCall
   06DE C0 02              2724 	push	ar2
   06E0 C0 03              2725 	push	ar3
   06E2 12 02 74           2726 	lcall	_stop_writecycle
   06E5 D0 03              2727 	pop	ar3
   06E7 D0 02              2728 	pop	ar2
                           2729 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:242: start_writecycle();
                           2730 ;	genCall
   06E9 C0 02              2731 	push	ar2
   06EB C0 03              2732 	push	ar3
   06ED 12 02 70           2733 	lcall	_start_writecycle
   06F0 D0 03              2734 	pop	ar3
   06F2 D0 02              2735 	pop	ar2
   06F4                    2736 00106$:
                           2737 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:236: for(n=0;n<ab;n++) 
                           2738 ;	genPlus
                           2739 ;     genPlusIncr
   06F4 0B                 2740 	inc	r3
                           2741 ;	Peephole 112.b	changed ljmp to sjmp
   06F5 80 94              2742 	sjmp	00104$
   06F7                    2743 00107$:
                           2744 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:245: stop_writecycle(); 
                           2745 ;	genCall
                           2746 ;	Peephole 253.b	replaced lcall/ret with ljmp
   06F7 02 02 74           2747 	ljmp	_stop_writecycle
                           2748 ;
                           2749 ;------------------------------------------------------------
                           2750 ;Allocation info for local variables in function 'set_pa'
                           2751 ;------------------------------------------------------------
                           2752 ;------------------------------------------------------------
                           2753 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:249: void set_pa(void)			// neue phys. Adresse programmieren
                           2754 ;	-----------------------------------------
                           2755 ;	 function set_pa
                           2756 ;	-----------------------------------------
   06FA                    2757 _set_pa:
                           2758 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:251: pah=telegramm[8];
                           2759 ;	genPointerGet
                           2760 ;	genNearPointerGet
                           2761 ;	genDataPointerGet
   06FA 85 2A 3C           2762 	mov	_pah,(_telegramm + 0x0008)
                           2763 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:252: pal=telegramm[9];
                           2764 ;	genPointerGet
                           2765 ;	genNearPointerGet
                           2766 ;	genDataPointerGet
   06FD 85 2B 3B           2767 	mov	_pal,(_telegramm + 0x0009)
                           2768 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:253: start_writecycle();
                           2769 ;	genCall
   0700 12 02 70           2770 	lcall	_start_writecycle
                           2771 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:254: write_byte(0x01,ADDRTAB+1,pah);		// in Flash schreiben
                           2772 ;	genIpush
   0703 C0 3C              2773 	push	_pah
                           2774 ;	genIpush
   0705 74 17              2775 	mov	a,#0x17
   0707 C0 E0              2776 	push	acc
                           2777 ;	genCall
   0709 75 82 01           2778 	mov	dpl,#0x01
   070C 12 02 78           2779 	lcall	_write_byte
   070F 15 81              2780 	dec	sp
   0711 15 81              2781 	dec	sp
                           2782 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:255: write_byte(0x01,ADDRTAB+2,pal);
                           2783 ;	genIpush
   0713 C0 3B              2784 	push	_pal
                           2785 ;	genIpush
   0715 74 18              2786 	mov	a,#0x18
   0717 C0 E0              2787 	push	acc
                           2788 ;	genCall
   0719 75 82 01           2789 	mov	dpl,#0x01
   071C 12 02 78           2790 	lcall	_write_byte
   071F 15 81              2791 	dec	sp
   0721 15 81              2792 	dec	sp
                           2793 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:256: stop_writecycle();
                           2794 ;	genCall
                           2795 ;	Peephole 253.b	replaced lcall/ret with ljmp
   0723 02 02 74           2796 	ljmp	_stop_writecycle
                           2797 ;
                           2798 ;------------------------------------------------------------
                           2799 ;Allocation info for local variables in function 'read_pa'
                           2800 ;------------------------------------------------------------
                           2801 ;------------------------------------------------------------
                           2802 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:260: void read_pa(void)			// phys. Adresse senden
                           2803 ;	-----------------------------------------
                           2804 ;	 function read_pa
                           2805 ;	-----------------------------------------
   0726                    2806 _read_pa:
                           2807 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:264: send_ack();
                           2808 ;	genCall
   0726 12 05 A3           2809 	lcall	_send_ack
                           2810 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:266: telegramm[0]=0xB0;			// read_memory_res senden
                           2811 ;	genPointerSet
                           2812 ;	genNearPointerSet
                           2813 ;	genDataPointerSet
   0729 75 22 B0           2814 	mov	_telegramm,#0xB0
                           2815 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:268: telegramm[1]=pah;
                           2816 ;	genPointerSet
                           2817 ;	genNearPointerSet
                           2818 ;	genDataPointerSet
   072C 85 3C 23           2819 	mov	(_telegramm + 0x0001),_pah
                           2820 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:269: telegramm[2]=pal;
                           2821 ;	genPointerSet
                           2822 ;	genNearPointerSet
                           2823 ;	genDataPointerSet
   072F 85 3B 24           2824 	mov	(_telegramm + 0x0002),_pal
                           2825 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:270: telegramm[3]=0x00;
                           2826 ;	genPointerSet
                           2827 ;	genNearPointerSet
                           2828 ;	genDataPointerSet
   0732 75 25 00           2829 	mov	(_telegramm + 0x0003),#0x00
                           2830 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:271: telegramm[4]=0x00;			
                           2831 ;	genPointerSet
                           2832 ;	genNearPointerSet
                           2833 ;	genDataPointerSet
   0735 75 26 00           2834 	mov	(_telegramm + 0x0004),#0x00
                           2835 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:272: telegramm[5]=0xE1;			// DRL
                           2836 ;	genPointerSet
                           2837 ;	genNearPointerSet
                           2838 ;	genDataPointerSet
   0738 75 27 E1           2839 	mov	(_telegramm + 0x0005),#0xE1
                           2840 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:273: telegramm[6]=0x01;		
                           2841 ;	genPointerSet
                           2842 ;	genNearPointerSet
                           2843 ;	genDataPointerSet
   073B 75 28 01           2844 	mov	(_telegramm + 0x0006),#0x01
                           2845 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:274: telegramm[7]=0x40;
                           2846 ;	genPointerSet
                           2847 ;	genNearPointerSet
                           2848 ;	genDataPointerSet
   073E 75 29 40           2849 	mov	(_telegramm + 0x0007),#0x40
                           2850 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:275: send_telegramm();
                           2851 ;	genCall
                           2852 ;	Peephole 253.b	replaced lcall/ret with ljmp
   0741 02 04 DD           2853 	ljmp	_send_telegramm
                           2854 ;
                           2855 ;------------------------------------------------------------
                           2856 ;Allocation info for local variables in function 'read_objflags'
                           2857 ;------------------------------------------------------------
                           2858 ;objno                     Allocated to registers r2 
                           2859 ;ctp                       Allocated to registers 
                           2860 ;addr                      Allocated to registers 
                           2861 ;flags                     Allocated to registers 
                           2862 ;------------------------------------------------------------
                           2863 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:280: unsigned char read_objflags(unsigned char objno)	// Objektflags lesen
                           2864 ;	-----------------------------------------
                           2865 ;	 function read_objflags
                           2866 ;	-----------------------------------------
   0744                    2867 _read_objflags:
                           2868 ;	genReceive
   0744 AA 82              2869 	mov	r2,dpl
                           2870 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:284: ctp=read_byte(0x01,COMMSTABPTR);		// COMMSTAB Pointer
                           2871 ;	genIpush
   0746 C0 02              2872 	push	ar2
   0748 74 12              2873 	mov	a,#0x12
   074A C0 E0              2874 	push	acc
                           2875 ;	genCall
   074C 75 82 01           2876 	mov	dpl,#0x01
   074F 12 02 CF           2877 	lcall	_read_byte
   0752 AB 82              2878 	mov	r3,dpl
   0754 15 81              2879 	dec	sp
   0756 D0 02              2880 	pop	ar2
                           2881 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:285: addr=ctp+3+3*objno;
                           2882 ;	genPlus
                           2883 ;     genPlusIncr
   0758 0B                 2884 	inc	r3
   0759 0B                 2885 	inc	r3
   075A 0B                 2886 	inc	r3
                           2887 ;	genMult
                           2888 ;	genMultOneByte
   075B EA                 2889 	mov	a,r2
   075C 75 F0 03           2890 	mov	b,#0x03
   075F A4                 2891 	mul	ab
                           2892 ;	genPlus
   0760 FA                 2893 	mov	r2,a
                           2894 ;	Peephole 177.b	removed redundant mov
                           2895 ;	Peephole 236.a	used r3 instead of ar3
   0761 2B                 2896 	add	a,r3
   0762 FB                 2897 	mov	r3,a
                           2898 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:286: flags=read_byte(0x01,addr);	// Objektflags
                           2899 ;	genIpush
   0763 C0 03              2900 	push	ar3
                           2901 ;	genCall
   0765 75 82 01           2902 	mov	dpl,#0x01
   0768 12 02 CF           2903 	lcall	_read_byte
   076B AA 82              2904 	mov	r2,dpl
   076D 15 81              2905 	dec	sp
                           2906 ;	genAssign
   076F 8A 82              2907 	mov	dpl,r2
                           2908 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:287: return(flags);
                           2909 ;	genRet
                           2910 ;	Peephole 300	removed redundant label 00101$
   0771 22                 2911 	ret
                           2912 ;------------------------------------------------------------
                           2913 ;Allocation info for local variables in function 'find_ga'
                           2914 ;------------------------------------------------------------
                           2915 ;objno                     Allocated to registers r2 
                           2916 ;n                         Allocated to registers r7 
                           2917 ;assno                     Allocated to registers r5 
                           2918 ;asstab                    Allocated to registers r4 
                           2919 ;gapos                     Allocated to registers r3 
                           2920 ;gal                       Allocated to registers r3 
                           2921 ;gah                       Allocated to registers r2 
                           2922 ;ga                        Allocated to registers r3 r2 
                           2923 ;sloc0                     Allocated to stack - offset 1
                           2924 ;------------------------------------------------------------
                           2925 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:291: int find_ga(unsigned char objno)		// Gruppenadresse über Assoziationstabelle finden (letzter Eintrag, falls mehrere)
                           2926 ;	-----------------------------------------
                           2927 ;	 function find_ga
                           2928 ;	-----------------------------------------
   0772                    2929 _find_ga:
   0772 C0 08              2930 	push	_bp
   0774 85 81 08           2931 	mov	_bp,sp
   0777 05 81              2932 	inc	sp
                           2933 ;	genReceive
   0779 AA 82              2934 	mov	r2,dpl
                           2935 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:296: gapos=0;
                           2936 ;	genAssign
   077B 7B 00              2937 	mov	r3,#0x00
                           2938 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:297: asstab=read_byte(0x01,ASSOCTABPTR);
                           2939 ;	genIpush
   077D C0 02              2940 	push	ar2
   077F C0 03              2941 	push	ar3
   0781 74 11              2942 	mov	a,#0x11
   0783 C0 E0              2943 	push	acc
                           2944 ;	genCall
   0785 75 82 01           2945 	mov	dpl,#0x01
   0788 12 02 CF           2946 	lcall	_read_byte
   078B AC 82              2947 	mov	r4,dpl
   078D 15 81              2948 	dec	sp
   078F D0 03              2949 	pop	ar3
   0791 D0 02              2950 	pop	ar2
                           2951 ;	genAssign
                           2952 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:298: assno=read_byte(0x01,asstab);
                           2953 ;	genIpush
   0793 C0 02              2954 	push	ar2
   0795 C0 03              2955 	push	ar3
   0797 C0 04              2956 	push	ar4
   0799 C0 04              2957 	push	ar4
                           2958 ;	genCall
   079B 75 82 01           2959 	mov	dpl,#0x01
   079E 12 02 CF           2960 	lcall	_read_byte
   07A1 AD 82              2961 	mov	r5,dpl
   07A3 15 81              2962 	dec	sp
   07A5 D0 04              2963 	pop	ar4
   07A7 D0 03              2964 	pop	ar3
   07A9 D0 02              2965 	pop	ar2
                           2966 ;	genAssign
                           2967 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:299: for(n=0;n<assno;n++)
                           2968 ;	genPlus
                           2969 ;     genPlusIncr
   07AB 74 01              2970 	mov	a,#0x01
                           2971 ;	Peephole 236.a	used r4 instead of ar4
   07AD 2C                 2972 	add	a,r4
   07AE FE                 2973 	mov	r6,a
                           2974 ;	genPlus
                           2975 ;     genPlusIncr
   07AF 0C                 2976 	inc	r4
   07B0 0C                 2977 	inc	r4
                           2978 ;	genAssign
   07B1 7F 00              2979 	mov	r7,#0x00
   07B3                    2980 00106$:
                           2981 ;	genCmpLt
                           2982 ;	genCmp
   07B3 C3                 2983 	clr	c
   07B4 EF                 2984 	mov	a,r7
   07B5 9D                 2985 	subb	a,r5
                           2986 ;	genIfxJump
                           2987 ;	Peephole 108.a	removed ljmp by inverse jump logic
   07B6 50 66              2988 	jnc	00109$
                           2989 ;	Peephole 300	removed redundant label 00117$
                           2990 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:301: if(read_byte(0x01,asstab+2+2*n)==objno)
                           2991 ;	genIpush
   07B8 C0 03              2992 	push	ar3
                           2993 ;	genLeftShift
                           2994 ;	genLeftShiftLiteral
   07BA A8 08              2995 	mov	r0,_bp
   07BC 08                 2996 	inc	r0
                           2997 ;	genlshOne
   07BD EF                 2998 	mov	a,r7
                           2999 ;	Peephole 254	optimized left shift
   07BE 2F                 3000 	add	a,r7
   07BF F6                 3001 	mov	@r0,a
                           3002 ;	genPlus
   07C0 A8 08              3003 	mov	r0,_bp
   07C2 08                 3004 	inc	r0
   07C3 E6                 3005 	mov	a,@r0
                           3006 ;	Peephole 236.a	used r4 instead of ar4
   07C4 2C                 3007 	add	a,r4
   07C5 FB                 3008 	mov	r3,a
                           3009 ;	genIpush
   07C6 C0 02              3010 	push	ar2
   07C8 C0 04              3011 	push	ar4
   07CA C0 05              3012 	push	ar5
   07CC C0 06              3013 	push	ar6
   07CE C0 07              3014 	push	ar7
   07D0 C0 03              3015 	push	ar3
                           3016 ;	genCall
   07D2 75 82 01           3017 	mov	dpl,#0x01
   07D5 12 02 CF           3018 	lcall	_read_byte
   07D8 AB 82              3019 	mov	r3,dpl
   07DA 15 81              3020 	dec	sp
   07DC D0 07              3021 	pop	ar7
   07DE D0 06              3022 	pop	ar6
   07E0 D0 05              3023 	pop	ar5
   07E2 D0 04              3024 	pop	ar4
   07E4 D0 02              3025 	pop	ar2
                           3026 ;	genCmpEq
                           3027 ;	gencjne
                           3028 ;	gencjneshort
   07E6 EB                 3029 	mov	a,r3
   07E7 B5 02 04           3030 	cjne	a,ar2,00118$
   07EA 74 01              3031 	mov	a,#0x01
   07EC 80 01              3032 	sjmp	00119$
   07EE                    3033 00118$:
   07EE E4                 3034 	clr	a
   07EF                    3035 00119$:
                           3036 ;	genIpop
   07EF D0 03              3037 	pop	ar3
                           3038 ;	genIfx
                           3039 ;	genIfxJump
                           3040 ;	Peephole 108.c	removed ljmp by inverse jump logic
   07F1 60 28              3041 	jz	00108$
                           3042 ;	Peephole 300	removed redundant label 00120$
                           3043 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:303: gapos=read_byte(0x01,asstab+1+2*n);
                           3044 ;	genIpush
   07F3 C0 04              3045 	push	ar4
                           3046 ;	genPlus
   07F5 A8 08              3047 	mov	r0,_bp
   07F7 08                 3048 	inc	r0
   07F8 E6                 3049 	mov	a,@r0
                           3050 ;	Peephole 236.a	used r6 instead of ar6
   07F9 2E                 3051 	add	a,r6
   07FA FC                 3052 	mov	r4,a
                           3053 ;	genIpush
   07FB C0 02              3054 	push	ar2
   07FD C0 05              3055 	push	ar5
   07FF C0 06              3056 	push	ar6
   0801 C0 07              3057 	push	ar7
   0803 C0 04              3058 	push	ar4
                           3059 ;	genCall
   0805 75 82 01           3060 	mov	dpl,#0x01
   0808 12 02 CF           3061 	lcall	_read_byte
   080B AC 82              3062 	mov	r4,dpl
   080D 15 81              3063 	dec	sp
   080F D0 07              3064 	pop	ar7
   0811 D0 06              3065 	pop	ar6
   0813 D0 05              3066 	pop	ar5
   0815 D0 02              3067 	pop	ar2
                           3068 ;	genAssign
   0817 8C 03              3069 	mov	ar3,r4
                           3070 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:316: return(ga);
                           3071 ;	genIpop
   0819 D0 04              3072 	pop	ar4
                           3073 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:303: gapos=read_byte(0x01,asstab+1+2*n);
   081B                    3074 00108$:
                           3075 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:299: for(n=0;n<assno;n++)
                           3076 ;	genPlus
                           3077 ;     genPlusIncr
   081B 0F                 3078 	inc	r7
                           3079 ;	Peephole 112.b	changed ljmp to sjmp
   081C 80 95              3080 	sjmp	00106$
   081E                    3081 00109$:
                           3082 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:306: if(gapos!=0)
                           3083 ;	genCmpEq
                           3084 ;	gencjneshort
   081E BB 00 02           3085 	cjne	r3,#0x00,00121$
                           3086 ;	Peephole 112.b	changed ljmp to sjmp
   0821 80 3B              3087 	sjmp	00104$
   0823                    3088 00121$:
                           3089 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:308: gah=read_byte(0x01,ADDRTAB+1+gapos*2);
                           3090 ;	genLeftShift
                           3091 ;	genLeftShiftLiteral
                           3092 ;	genlshOne
   0823 EB                 3093 	mov	a,r3
                           3094 ;	Peephole 254	optimized left shift
   0824 2B                 3095 	add	a,r3
   0825 FB                 3096 	mov	r3,a
                           3097 ;	genPlus
                           3098 ;     genPlusIncr
   0826 74 17              3099 	mov	a,#0x17
                           3100 ;	Peephole 236.a	used r3 instead of ar3
   0828 2B                 3101 	add	a,r3
   0829 FA                 3102 	mov	r2,a
                           3103 ;	genIpush
   082A C0 03              3104 	push	ar3
   082C C0 02              3105 	push	ar2
                           3106 ;	genCall
   082E 75 82 01           3107 	mov	dpl,#0x01
   0831 12 02 CF           3108 	lcall	_read_byte
   0834 AA 82              3109 	mov	r2,dpl
   0836 15 81              3110 	dec	sp
   0838 D0 03              3111 	pop	ar3
                           3112 ;	genAssign
                           3113 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:309: gal=read_byte(0x01,ADDRTAB+2+gapos*2);
                           3114 ;	genPlus
                           3115 ;     genPlusIncr
   083A 74 18              3116 	mov	a,#0x18
                           3117 ;	Peephole 236.a	used r3 instead of ar3
   083C 2B                 3118 	add	a,r3
   083D FB                 3119 	mov	r3,a
                           3120 ;	genIpush
   083E C0 02              3121 	push	ar2
   0840 C0 03              3122 	push	ar3
                           3123 ;	genCall
   0842 75 82 01           3124 	mov	dpl,#0x01
   0845 12 02 CF           3125 	lcall	_read_byte
   0848 AB 82              3126 	mov	r3,dpl
   084A 15 81              3127 	dec	sp
   084C D0 02              3128 	pop	ar2
                           3129 ;	genAssign
                           3130 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:310: ga=gal+256*gah;
                           3131 ;	genCast
   084E 7C 00              3132 	mov	r4,#0x00
                           3133 ;	genCast
                           3134 ;	genLeftShift
                           3135 ;	genLeftShiftLiteral
                           3136 ;	genlshTwo
                           3137 ;	peephole 177.e	removed redundant move
   0850 8A 05              3138 	mov	ar5,r2
   0852 7A 00              3139 	mov	r2,#0x00
                           3140 ;	genPlus
                           3141 ;	Peephole 236.g	used r2 instead of ar2
   0854 EA                 3142 	mov	a,r2
                           3143 ;	Peephole 236.a	used r3 instead of ar3
   0855 2B                 3144 	add	a,r3
   0856 FB                 3145 	mov	r3,a
                           3146 ;	Peephole 236.g	used r5 instead of ar5
   0857 ED                 3147 	mov	a,r5
                           3148 ;	Peephole 236.b	used r4 instead of ar4
   0858 3C                 3149 	addc	a,r4
   0859 FC                 3150 	mov	r4,a
                           3151 ;	genAssign
   085A 8C 02              3152 	mov	ar2,r4
                           3153 ;	Peephole 112.b	changed ljmp to sjmp
   085C 80 04              3154 	sjmp	00105$
   085E                    3155 00104$:
                           3156 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:314: ga=0;
                           3157 ;	genAssign
   085E 7B 00              3158 	mov	r3,#0x00
   0860 7A 00              3159 	mov	r2,#0x00
   0862                    3160 00105$:
                           3161 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:316: return(ga);
                           3162 ;	genRet
   0862 8B 82              3163 	mov	dpl,r3
   0864 8A 83              3164 	mov	dph,r2
                           3165 ;	Peephole 300	removed redundant label 00110$
   0866 85 08 81           3166 	mov	sp,_bp
   0869 D0 08              3167 	pop	_bp
   086B 22                 3168 	ret
                           3169 ;------------------------------------------------------------
                           3170 ;Allocation info for local variables in function 'gapos_in_gat'
                           3171 ;------------------------------------------------------------
                           3172 ;gal                       Allocated to stack - offset -3
                           3173 ;gah                       Allocated to registers r2 
                           3174 ;ga_position               Allocated to registers r4 
                           3175 ;ga_count                  Allocated to registers r3 
                           3176 ;n                         Allocated to registers 
                           3177 ;------------------------------------------------------------
                           3178 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:320: unsigned char gapos_in_gat(unsigned char gah, unsigned char gal)
                           3179 ;	-----------------------------------------
                           3180 ;	 function gapos_in_gat
                           3181 ;	-----------------------------------------
   086C                    3182 _gapos_in_gat:
   086C C0 08              3183 	push	_bp
   086E 85 81 08           3184 	mov	_bp,sp
                           3185 ;	genReceive
   0871 AA 82              3186 	mov	r2,dpl
                           3187 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:324: ga_count=read_byte(0x01,ADDRTAB);
                           3188 ;	genIpush
   0873 C0 02              3189 	push	ar2
   0875 74 16              3190 	mov	a,#0x16
   0877 C0 E0              3191 	push	acc
                           3192 ;	genCall
   0879 75 82 01           3193 	mov	dpl,#0x01
   087C 12 02 CF           3194 	lcall	_read_byte
   087F AB 82              3195 	mov	r3,dpl
   0881 15 81              3196 	dec	sp
   0883 D0 02              3197 	pop	ar2
                           3198 ;	genAssign
                           3199 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:325: ga_position=0xFF; 
                           3200 ;	genAssign
   0885 7C FF              3201 	mov	r4,#0xFF
                           3202 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:326: if (ga_count>0)
                           3203 ;	genIfx
   0887 EB                 3204 	mov	a,r3
                           3205 ;	genIfxJump
                           3206 ;	Peephole 108.c	removed ljmp by inverse jump logic
   0888 60 60              3207 	jz	00105$
                           3208 ;	Peephole 300	removed redundant label 00118$
                           3209 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:328: for (n=1;n<=ga_count;n++)
                           3210 ;	genAssign
   088A 7D 01              3211 	mov	r5,#0x01
   088C                    3212 00106$:
                           3213 ;	genCmpGt
                           3214 ;	genCmp
   088C C3                 3215 	clr	c
   088D EB                 3216 	mov	a,r3
   088E 9D                 3217 	subb	a,r5
                           3218 ;	genIfxJump
                           3219 ;	Peephole 112.b	changed ljmp to sjmp
                           3220 ;	Peephole 160.a	removed sjmp by inverse jump logic
   088F 40 59              3221 	jc	00105$
                           3222 ;	Peephole 300	removed redundant label 00119$
                           3223 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:330: if (gah==read_byte(0x01,ADDRTAB+n*2+1) && gal==read_byte(0x01,ADDRTAB+n*2+2)) ga_position=n;
                           3224 ;	genLeftShift
                           3225 ;	genLeftShiftLiteral
                           3226 ;	genlshOne
   0891 ED                 3227 	mov	a,r5
                           3228 ;	Peephole 254	optimized left shift
   0892 2D                 3229 	add	a,r5
   0893 FE                 3230 	mov	r6,a
                           3231 ;	genPlus
                           3232 ;     genPlusIncr
   0894 74 17              3233 	mov	a,#0x17
                           3234 ;	Peephole 236.a	used r6 instead of ar6
   0896 2E                 3235 	add	a,r6
   0897 FF                 3236 	mov	r7,a
                           3237 ;	genIpush
   0898 C0 02              3238 	push	ar2
   089A C0 03              3239 	push	ar3
   089C C0 04              3240 	push	ar4
   089E C0 05              3241 	push	ar5
   08A0 C0 06              3242 	push	ar6
   08A2 C0 07              3243 	push	ar7
                           3244 ;	genCall
   08A4 75 82 01           3245 	mov	dpl,#0x01
   08A7 12 02 CF           3246 	lcall	_read_byte
   08AA AF 82              3247 	mov	r7,dpl
   08AC 15 81              3248 	dec	sp
   08AE D0 06              3249 	pop	ar6
   08B0 D0 05              3250 	pop	ar5
   08B2 D0 04              3251 	pop	ar4
   08B4 D0 03              3252 	pop	ar3
   08B6 D0 02              3253 	pop	ar2
                           3254 ;	genCmpEq
                           3255 ;	gencjneshort
   08B8 EA                 3256 	mov	a,r2
                           3257 ;	Peephole 112.b	changed ljmp to sjmp
                           3258 ;	Peephole 198.b	optimized misc jump sequence
   08B9 B5 07 2B           3259 	cjne	a,ar7,00108$
                           3260 ;	Peephole 200.b	removed redundant sjmp
                           3261 ;	Peephole 300	removed redundant label 00120$
                           3262 ;	Peephole 300	removed redundant label 00121$
                           3263 ;	genPlus
                           3264 ;     genPlusIncr
   08BC 74 18              3265 	mov	a,#0x18
                           3266 ;	Peephole 236.a	used r6 instead of ar6
   08BE 2E                 3267 	add	a,r6
   08BF FE                 3268 	mov	r6,a
                           3269 ;	genIpush
   08C0 C0 02              3270 	push	ar2
   08C2 C0 03              3271 	push	ar3
   08C4 C0 04              3272 	push	ar4
   08C6 C0 05              3273 	push	ar5
   08C8 C0 06              3274 	push	ar6
                           3275 ;	genCall
   08CA 75 82 01           3276 	mov	dpl,#0x01
   08CD 12 02 CF           3277 	lcall	_read_byte
   08D0 AE 82              3278 	mov	r6,dpl
   08D2 15 81              3279 	dec	sp
   08D4 D0 05              3280 	pop	ar5
   08D6 D0 04              3281 	pop	ar4
   08D8 D0 03              3282 	pop	ar3
   08DA D0 02              3283 	pop	ar2
                           3284 ;	genCmpEq
   08DC A8 08              3285 	mov	r0,_bp
   08DE 18                 3286 	dec	r0
   08DF 18                 3287 	dec	r0
   08E0 18                 3288 	dec	r0
                           3289 ;	gencjneshort
   08E1 E6                 3290 	mov	a,@r0
                           3291 ;	Peephole 112.b	changed ljmp to sjmp
                           3292 ;	Peephole 198.b	optimized misc jump sequence
   08E2 B5 06 02           3293 	cjne	a,ar6,00108$
                           3294 ;	Peephole 200.b	removed redundant sjmp
                           3295 ;	Peephole 300	removed redundant label 00122$
                           3296 ;	Peephole 300	removed redundant label 00123$
                           3297 ;	genAssign
   08E5 8D 04              3298 	mov	ar4,r5
   08E7                    3299 00108$:
                           3300 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:328: for (n=1;n<=ga_count;n++)
                           3301 ;	genPlus
                           3302 ;     genPlusIncr
   08E7 0D                 3303 	inc	r5
                           3304 ;	Peephole 112.b	changed ljmp to sjmp
   08E8 80 A2              3305 	sjmp	00106$
   08EA                    3306 00105$:
                           3307 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:333: return (ga_position);
                           3308 ;	genRet
   08EA 8C 82              3309 	mov	dpl,r4
                           3310 ;	Peephole 300	removed redundant label 00110$
   08EC D0 08              3311 	pop	_bp
   08EE 22                 3312 	ret
                           3313 ;------------------------------------------------------------
                           3314 ;Allocation info for local variables in function 'write_delay_record'
                           3315 ;------------------------------------------------------------
                           3316 ;delay_status              Allocated to stack - offset -3
                           3317 ;delay_target              Allocated to stack - offset -7
                           3318 ;objno                     Allocated to registers r2 
                           3319 ;------------------------------------------------------------
                           3320 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:337: void write_delay_record(unsigned char objno, unsigned char delay_status, long delay_target)		// Schreibt die Schalt-Verzögerungswerte ins Flash
                           3321 ;	-----------------------------------------
                           3322 ;	 function write_delay_record
                           3323 ;	-----------------------------------------
   08EF                    3324 _write_delay_record:
   08EF C0 08              3325 	push	_bp
   08F1 85 81 08           3326 	mov	_bp,sp
                           3327 ;	genReceive
   08F4 AA 82              3328 	mov	r2,dpl
                           3329 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:339: start_writecycle();
                           3330 ;	genCall
   08F6 C0 02              3331 	push	ar2
   08F8 12 02 70           3332 	lcall	_start_writecycle
   08FB D0 02              3333 	pop	ar2
                           3334 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:340: write_byte(0x00,objno*5,objno+delay_status);
                           3335 ;	genPlus
   08FD A8 08              3336 	mov	r0,_bp
   08FF 18                 3337 	dec	r0
   0900 18                 3338 	dec	r0
   0901 18                 3339 	dec	r0
   0902 E6                 3340 	mov	a,@r0
                           3341 ;	Peephole 236.a	used r2 instead of ar2
   0903 2A                 3342 	add	a,r2
   0904 FB                 3343 	mov	r3,a
                           3344 ;	genMult
                           3345 ;	genMultOneByte
   0905 EA                 3346 	mov	a,r2
   0906 75 F0 05           3347 	mov	b,#0x05
   0909 A4                 3348 	mul	ab
   090A FA                 3349 	mov	r2,a
                           3350 ;	genIpush
   090B C0 02              3351 	push	ar2
   090D C0 03              3352 	push	ar3
                           3353 ;	genIpush
   090F C0 02              3354 	push	ar2
                           3355 ;	genCall
   0911 75 82 00           3356 	mov	dpl,#0x00
   0914 12 02 78           3357 	lcall	_write_byte
   0917 15 81              3358 	dec	sp
   0919 15 81              3359 	dec	sp
   091B D0 02              3360 	pop	ar2
                           3361 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:341: write_byte(0x00,1+objno*5,delay_target>>24);
                           3362 ;	genGetByte
   091D E5 08              3363 	mov	a,_bp
   091F 24 F9              3364 	add	a,#0xfffffff9
                           3365 ;	Peephole 185	changed order of increment (acc incremented also!)
   0921 04                 3366 	inc	a
                           3367 ;	Peephole 185	changed order of increment (acc incremented also!)
   0922 04                 3368 	inc	a
                           3369 ;	Peephole 185	changed order of increment (acc incremented also!)
   0923 04                 3370 	inc	a
   0924 F8                 3371 	mov	r0,a
   0925 86 03              3372 	mov	ar3,@r0
                           3373 ;	genPlus
                           3374 ;     genPlusIncr
   0927 74 01              3375 	mov	a,#0x01
                           3376 ;	Peephole 236.a	used r2 instead of ar2
   0929 2A                 3377 	add	a,r2
   092A FC                 3378 	mov	r4,a
                           3379 ;	genIpush
   092B C0 02              3380 	push	ar2
   092D C0 03              3381 	push	ar3
                           3382 ;	genIpush
   092F C0 04              3383 	push	ar4
                           3384 ;	genCall
   0931 75 82 00           3385 	mov	dpl,#0x00
   0934 12 02 78           3386 	lcall	_write_byte
   0937 15 81              3387 	dec	sp
   0939 15 81              3388 	dec	sp
   093B D0 02              3389 	pop	ar2
                           3390 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:342: write_byte(0x00,2+objno*5,delay_target>>16);
                           3391 ;	genGetByte
   093D E5 08              3392 	mov	a,_bp
   093F 24 F9              3393 	add	a,#0xfffffff9
                           3394 ;	Peephole 185	changed order of increment (acc incremented also!)
   0941 04                 3395 	inc	a
                           3396 ;	Peephole 185	changed order of increment (acc incremented also!)
   0942 04                 3397 	inc	a
   0943 F8                 3398 	mov	r0,a
   0944 86 03              3399 	mov	ar3,@r0
                           3400 ;	genPlus
                           3401 ;     genPlusIncr
   0946 74 02              3402 	mov	a,#0x02
                           3403 ;	Peephole 236.a	used r2 instead of ar2
   0948 2A                 3404 	add	a,r2
   0949 FC                 3405 	mov	r4,a
                           3406 ;	genIpush
   094A C0 02              3407 	push	ar2
   094C C0 03              3408 	push	ar3
                           3409 ;	genIpush
   094E C0 04              3410 	push	ar4
                           3411 ;	genCall
   0950 75 82 00           3412 	mov	dpl,#0x00
   0953 12 02 78           3413 	lcall	_write_byte
   0956 15 81              3414 	dec	sp
   0958 15 81              3415 	dec	sp
   095A D0 02              3416 	pop	ar2
                           3417 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:343: write_byte(0x00,3+objno*5,delay_target>>8);
                           3418 ;	genGetByte
   095C E5 08              3419 	mov	a,_bp
   095E 24 F9              3420 	add	a,#0xfffffff9
                           3421 ;	Peephole 185	changed order of increment (acc incremented also!)
   0960 04                 3422 	inc	a
   0961 F8                 3423 	mov	r0,a
   0962 86 03              3424 	mov	ar3,@r0
                           3425 ;	genPlus
                           3426 ;     genPlusIncr
   0964 74 03              3427 	mov	a,#0x03
                           3428 ;	Peephole 236.a	used r2 instead of ar2
   0966 2A                 3429 	add	a,r2
   0967 FC                 3430 	mov	r4,a
                           3431 ;	genIpush
   0968 C0 02              3432 	push	ar2
   096A C0 03              3433 	push	ar3
                           3434 ;	genIpush
   096C C0 04              3435 	push	ar4
                           3436 ;	genCall
   096E 75 82 00           3437 	mov	dpl,#0x00
   0971 12 02 78           3438 	lcall	_write_byte
   0974 15 81              3439 	dec	sp
   0976 15 81              3440 	dec	sp
   0978 D0 02              3441 	pop	ar2
                           3442 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:344: write_byte(0x00,4+objno*5,delay_target);
                           3443 ;	genCast
   097A E5 08              3444 	mov	a,_bp
   097C 24 F9              3445 	add	a,#0xfffffff9
   097E F8                 3446 	mov	r0,a
   097F 86 03              3447 	mov	ar3,@r0
                           3448 ;	genPlus
                           3449 ;     genPlusIncr
   0981 EA                 3450 	mov	a,r2
   0982 24 04              3451 	add	a,#0x04
   0984 FA                 3452 	mov	r2,a
                           3453 ;	genIpush
   0985 C0 03              3454 	push	ar3
                           3455 ;	genIpush
   0987 C0 02              3456 	push	ar2
                           3457 ;	genCall
   0989 75 82 00           3458 	mov	dpl,#0x00
   098C 12 02 78           3459 	lcall	_write_byte
   098F 15 81              3460 	dec	sp
   0991 15 81              3461 	dec	sp
                           3462 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:345: stop_writecycle();
                           3463 ;	genCall
   0993 12 02 74           3464 	lcall	_stop_writecycle
                           3465 ;	Peephole 300	removed redundant label 00101$
   0996 D0 08              3466 	pop	_bp
   0998 22                 3467 	ret
                           3468 ;------------------------------------------------------------
                           3469 ;Allocation info for local variables in function 'restart_prot'
                           3470 ;------------------------------------------------------------
                           3471 ;------------------------------------------------------------
                           3472 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:349: void restart_prot(void)		// Protokoll-relevante Parameter zurücksetzen
                           3473 ;	-----------------------------------------
                           3474 ;	 function restart_prot
                           3475 ;	-----------------------------------------
   0999                    3476 _restart_prot:
                           3477 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:351: pah=read_byte(0x01,ADDRTAB+1);	// phys. Adresse einlesen
                           3478 ;	genIpush
   0999 74 17              3479 	mov	a,#0x17
   099B C0 E0              3480 	push	acc
                           3481 ;	genCall
   099D 75 82 01           3482 	mov	dpl,#0x01
   09A0 12 02 CF           3483 	lcall	_read_byte
   09A3 85 82 3C           3484 	mov	_pah,dpl
   09A6 15 81              3485 	dec	sp
                           3486 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:352: pal=read_byte(0x01,ADDRTAB+2);
                           3487 ;	genIpush
   09A8 74 18              3488 	mov	a,#0x18
   09AA C0 E0              3489 	push	acc
                           3490 ;	genCall
   09AC 75 82 01           3491 	mov	dpl,#0x01
   09AF 12 02 CF           3492 	lcall	_read_byte
   09B2 85 82 3B           3493 	mov	_pal,dpl
   09B5 15 81              3494 	dec	sp
                           3495 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:354: progmode=0;			// kein Programmiermodus
                           3496 ;	genAssign
   09B7 C2 01              3497 	clr	_progmode
                           3498 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:355: pcount=1;			// Paketzähler initialisieren
                           3499 ;	genAssign
   09B9 75 40 01           3500 	mov	_pcount,#0x01
                           3501 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:356: connected=0;			// keine Verbindung
                           3502 ;	genAssign
   09BC C2 02              3503 	clr	_connected
                           3504 ;	s:/elektronik/eib/c/fb_common/fb_prot.c:358: telpos=0;			// empfangene Bytes an dieser Position im Array telegramm[] ablegen
                           3505 ;	genAssign
   09BE 75 39 00           3506 	mov	_telpos,#0x00
                           3507 ;	Peephole 300	removed redundant label 00101$
   09C1 22                 3508 	ret
                           3509 ;------------------------------------------------------------
                           3510 ;Allocation info for local variables in function 'pin_changed'
                           3511 ;------------------------------------------------------------
                           3512 ;pinno                     Allocated to registers r2 
                           3513 ;------------------------------------------------------------
                           3514 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:13: void pin_changed(unsigned char pinno)
                           3515 ;	-----------------------------------------
                           3516 ;	 function pin_changed
                           3517 ;	-----------------------------------------
   09C2                    3518 _pin_changed:
                           3519 ;	genReceive
   09C2 AA 82              3520 	mov	r2,dpl
                           3521 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:15: EX1=0;
                           3522 ;	genAssign
   09C4 C2 AA              3523 	clr	_IEN0_2
                           3524 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:17: if (debounce(pinno))			// Entprellzeit abwarten und prüfen
                           3525 ;	genCall
   09C6 8A 82              3526 	mov	dpl,r2
   09C8 C0 02              3527 	push	ar2
   09CA 12 0B 97           3528 	lcall	_debounce
   09CD E5 82              3529 	mov	a,dpl
   09CF D0 02              3530 	pop	ar2
                           3531 ;	genIfx
                           3532 ;	genIfxJump
   09D1 70 03              3533 	jnz	00126$
   09D3 02 0A 87           3534 	ljmp	00117$
   09D6                    3535 00126$:
                           3536 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:19: switch (pin_function(pinno))	// Funktion des Eingangs
                           3537 ;	genCall
   09D6 8A 82              3538 	mov	dpl,r2
   09D8 C0 02              3539 	push	ar2
   09DA 12 0B 93           3540 	lcall	_pin_function
   09DD AB 82              3541 	mov	r3,dpl
   09DF D0 02              3542 	pop	ar2
                           3543 ;	genCmpEq
                           3544 ;	gencjneshort
   09E1 BB 00 02           3545 	cjne	r3,#0x00,00127$
                           3546 ;	Peephole 112.b	changed ljmp to sjmp
   09E4 80 08              3547 	sjmp	00101$
   09E6                    3548 00127$:
                           3549 ;	genCmpEq
                           3550 ;	gencjneshort
   09E6 BB 01 02           3551 	cjne	r3,#0x01,00128$
                           3552 ;	Peephole 112.b	changed ljmp to sjmp
   09E9 80 71              3553 	sjmp	00106$
   09EB                    3554 00128$:
   09EB 02 0A 87           3555 	ljmp	00117$
                           3556 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:21: case 0x00:				// Funktion Schalten
   09EE                    3557 00101$:
                           3558 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:22: if(((portbuffer>>pinno)&0x01)==0 && ((p0h>>pinno)&0x01)==1)	
                           3559 ;	genRightShift
   09EE 8A F0              3560 	mov	b,r2
   09F0 05 F0              3561 	inc	b
   09F2 E5 41              3562 	mov	a,_portbuffer
   09F4 80 02              3563 	sjmp	00130$
   09F6                    3564 00129$:
   09F6 C3                 3565 	clr	c
   09F7 13                 3566 	rrc	a
   09F8                    3567 00130$:
   09F8 D5 F0 FB           3568 	djnz	b,00129$
                           3569 ;	genAnd
                           3570 ;	genIfxJump
                           3571 ;	Peephole 108.e	removed ljmp by inverse jump logic
   09FB 20 E0 35           3572 	jb	acc.0,00103$
                           3573 ;	Peephole 300	removed redundant label 00131$
                           3574 ;	genRightShift
   09FE 8A F0              3575 	mov	b,r2
   0A00 05 F0              3576 	inc	b
   0A02 E5 42              3577 	mov	a,_p0h
   0A04 80 02              3578 	sjmp	00133$
   0A06                    3579 00132$:
   0A06 C3                 3580 	clr	c
   0A07 13                 3581 	rrc	a
   0A08                    3582 00133$:
   0A08 D5 F0 FB           3583 	djnz	b,00132$
                           3584 ;	genAnd
   0A0B 54 01              3585 	anl	a,#0x01
   0A0D FB                 3586 	mov	r3,a
                           3587 ;	genCmpEq
                           3588 ;	gencjneshort
                           3589 ;	Peephole 112.b	changed ljmp to sjmp
                           3590 ;	Peephole 198.b	optimized misc jump sequence
   0A0E BB 01 22           3591 	cjne	r3,#0x01,00103$
                           3592 ;	Peephole 200.b	removed redundant sjmp
                           3593 ;	Peephole 300	removed redundant label 00134$
                           3594 ;	Peephole 300	removed redundant label 00135$
                           3595 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:24: schalten(1,pinno);			// steigende Flanke Eingang x.1
                           3596 ;	genIpush
   0A11 C0 02              3597 	push	ar2
   0A13 C0 02              3598 	push	ar2
                           3599 ;	genCall
   0A15 75 82 01           3600 	mov	dpl,#0x01
   0A18 12 0A 93           3601 	lcall	_schalten
   0A1B 15 81              3602 	dec	sp
   0A1D D0 02              3603 	pop	ar2
                           3604 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:25: schalten(1,pinno+8);			// steigende Flanke Eingang x.2
                           3605 ;	genPlus
                           3606 ;     genPlusIncr
   0A1F 74 08              3607 	mov	a,#0x08
                           3608 ;	Peephole 236.a	used r2 instead of ar2
   0A21 2A                 3609 	add	a,r2
   0A22 FB                 3610 	mov	r3,a
                           3611 ;	genIpush
   0A23 C0 02              3612 	push	ar2
   0A25 C0 03              3613 	push	ar3
                           3614 ;	genCall
   0A27 75 82 01           3615 	mov	dpl,#0x01
   0A2A 12 0A 93           3616 	lcall	_schalten
   0A2D 15 81              3617 	dec	sp
   0A2F D0 02              3618 	pop	ar2
                           3619 ;	Peephole 112.b	changed ljmp to sjmp
   0A31 80 20              3620 	sjmp	00104$
   0A33                    3621 00103$:
                           3622 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:29: schalten(0,pinno);			// fallende Flanke Eingang x.1
                           3623 ;	genIpush
   0A33 C0 02              3624 	push	ar2
   0A35 C0 02              3625 	push	ar2
                           3626 ;	genCall
   0A37 75 82 00           3627 	mov	dpl,#0x00
   0A3A 12 0A 93           3628 	lcall	_schalten
   0A3D 15 81              3629 	dec	sp
   0A3F D0 02              3630 	pop	ar2
                           3631 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:30: schalten(0,pinno+8);			// fallende Flanke Eingang x.2
                           3632 ;	genPlus
                           3633 ;     genPlusIncr
   0A41 74 08              3634 	mov	a,#0x08
                           3635 ;	Peephole 236.a	used r2 instead of ar2
   0A43 2A                 3636 	add	a,r2
   0A44 FB                 3637 	mov	r3,a
                           3638 ;	genIpush
   0A45 C0 02              3639 	push	ar2
   0A47 C0 03              3640 	push	ar3
                           3641 ;	genCall
   0A49 75 82 00           3642 	mov	dpl,#0x00
   0A4C 12 0A 93           3643 	lcall	_schalten
   0A4F 15 81              3644 	dec	sp
   0A51 D0 02              3645 	pop	ar2
   0A53                    3646 00104$:
                           3647 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:32: send_cyclic(pinno);
                           3648 ;	genCall
   0A53 8A 82              3649 	mov	dpl,r2
   0A55 C0 02              3650 	push	ar2
   0A57 12 0A 8A           3651 	lcall	_send_cyclic
   0A5A D0 02              3652 	pop	ar2
                           3653 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:33: case 0x01:				// Funktion Dimmen
   0A5C                    3654 00106$:
                           3655 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:34: switch (operation(pinno))			// Bedienung
                           3656 ;	genCall
   0A5C 8A 82              3657 	mov	dpl,r2
   0A5E C0 02              3658 	push	ar2
   0A60 12 0A 8B           3659 	lcall	_operation
   0A63 AB 82              3660 	mov	r3,dpl
   0A65 D0 02              3661 	pop	ar2
                           3662 ;	genCmpGt
                           3663 ;	genCmp
                           3664 ;	genIfxJump
                           3665 ;	Peephole 132.b	optimized genCmpGt by inverse logic (acc differs)
   0A67 EB                 3666 	mov	a,r3
   0A68 24 FB              3667 	add	a,#0xff - 0x04
                           3668 ;	Peephole 112.b	changed ljmp to sjmp
                           3669 ;	Peephole 160.a	removed sjmp by inverse jump logic
   0A6A 40 1B              3670 	jc	00117$
                           3671 ;	Peephole 300	removed redundant label 00136$
                           3672 ;	genJumpTab
   0A6C EB                 3673 	mov	a,r3
                           3674 ;	Peephole 254	optimized left shift
   0A6D 2B                 3675 	add	a,r3
   0A6E 2B                 3676 	add	a,r3
   0A6F 90 0A 73           3677 	mov	dptr,#00137$
   0A72 73                 3678 	jmp	@a+dptr
   0A73                    3679 00137$:
   0A73 02 0A 82           3680 	ljmp	00107$
   0A76 02 0A 87           3681 	ljmp	00110$
   0A79 02 0A 87           3682 	ljmp	00111$
   0A7C 02 0A 87           3683 	ljmp	00112$
   0A7F 02 0A 87           3684 	ljmp	00113$
                           3685 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:36: case 0x00:					// Einflächenbedienung heller/dunkler (UM)
   0A82                    3686 00107$:
                           3687 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:37: if (switch_dim(pinno)==0)			// prüfen, ob Taster länger gedrückt als Schalten/Dimmen-Zeit
                           3688 ;	genCall
   0A82 8A 82              3689 	mov	dpl,r2
   0A84 12 0A 8F           3690 	lcall	_switch_dim
                           3691 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:43: case 0x01:					// Zweiflächenbedienung heller (EIN)
   0A87                    3692 00110$:
                           3693 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:44: case 0x02:					// Zweiflächenbedienung dunkler (AUS)
   0A87                    3694 00111$:
                           3695 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:45: case 0x03:					// Zweiflächenbedienung heller (UM)
   0A87                    3696 00112$:
                           3697 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:46: case 0x04:					// Zweiflächenbedienung dunkler (UM)
   0A87                    3698 00113$:
                           3699 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:48: }
   0A87                    3700 00117$:
                           3701 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:50: EX1=1;
                           3702 ;	genAssign
   0A87 D2 AA              3703 	setb	_IEN0_2
                           3704 ;	Peephole 300	removed redundant label 00118$
   0A89 22                 3705 	ret
                           3706 ;------------------------------------------------------------
                           3707 ;Allocation info for local variables in function 'send_cyclic'
                           3708 ;------------------------------------------------------------
                           3709 ;pinno                     Allocated to registers 
                           3710 ;------------------------------------------------------------
                           3711 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:54: void send_cyclic(unsigned char pinno)
                           3712 ;	-----------------------------------------
                           3713 ;	 function send_cyclic
                           3714 ;	-----------------------------------------
   0A8A                    3715 _send_cyclic:
                           3716 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:56: pinno;
                           3717 ;	Peephole 300	removed redundant label 00101$
   0A8A 22                 3718 	ret
                           3719 ;------------------------------------------------------------
                           3720 ;Allocation info for local variables in function 'operation'
                           3721 ;------------------------------------------------------------
                           3722 ;pinno                     Allocated to registers 
                           3723 ;------------------------------------------------------------
                           3724 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:60: unsigned char operation(unsigned char pinno)
                           3725 ;	-----------------------------------------
                           3726 ;	 function operation
                           3727 ;	-----------------------------------------
   0A8B                    3728 _operation:
                           3729 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:63: return(1);
                           3730 ;	genRet
   0A8B 75 82 01           3731 	mov	dpl,#0x01
                           3732 ;	Peephole 300	removed redundant label 00101$
   0A8E 22                 3733 	ret
                           3734 ;------------------------------------------------------------
                           3735 ;Allocation info for local variables in function 'switch_dim'
                           3736 ;------------------------------------------------------------
                           3737 ;pinno                     Allocated to registers 
                           3738 ;------------------------------------------------------------
                           3739 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:67: unsigned char switch_dim(unsigned char pinno)
                           3740 ;	-----------------------------------------
                           3741 ;	 function switch_dim
                           3742 ;	-----------------------------------------
   0A8F                    3743 _switch_dim:
                           3744 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:70: return(1);
                           3745 ;	genRet
   0A8F 75 82 01           3746 	mov	dpl,#0x01
                           3747 ;	Peephole 300	removed redundant label 00101$
   0A92 22                 3748 	ret
                           3749 ;------------------------------------------------------------
                           3750 ;Allocation info for local variables in function 'schalten'
                           3751 ;------------------------------------------------------------
                           3752 ;pinno                     Allocated to stack - offset -3
                           3753 ;risefall                  Allocated to registers r2 
                           3754 ;func                      Allocated to registers r3 
                           3755 ;ga                        Allocated to registers r2 r4 
                           3756 ;------------------------------------------------------------
                           3757 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:74: void schalten(unsigned char risefall, unsigned char pinno)	// Schaltbefehl senden
                           3758 ;	-----------------------------------------
                           3759 ;	 function schalten
                           3760 ;	-----------------------------------------
   0A93                    3761 _schalten:
   0A93 C0 08              3762 	push	_bp
   0A95 85 81 08           3763 	mov	_bp,sp
                           3764 ;	genReceive
   0A98 AA 82              3765 	mov	r2,dpl
                           3766 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:79: func=read_byte(0x01,0xD7+((pinno&0x07)*5));
                           3767 ;	genAnd
   0A9A A8 08              3768 	mov	r0,_bp
   0A9C 18                 3769 	dec	r0
   0A9D 18                 3770 	dec	r0
   0A9E 18                 3771 	dec	r0
   0A9F 74 07              3772 	mov	a,#0x07
   0AA1 56                 3773 	anl	a,@r0
                           3774 ;	genMult
                           3775 ;	genMultOneByte
   0AA2 75 F0 05           3776 	mov	b,#0x05
   0AA5 A4                 3777 	mul	ab
                           3778 ;	genPlus
                           3779 ;     genPlusIncr
   0AA6 24 D7              3780 	add	a,#0xD7
   0AA8 FB                 3781 	mov	r3,a
                           3782 ;	genIpush
   0AA9 C0 02              3783 	push	ar2
   0AAB C0 03              3784 	push	ar3
                           3785 ;	genCall
   0AAD 75 82 01           3786 	mov	dpl,#0x01
   0AB0 12 02 CF           3787 	lcall	_read_byte
   0AB3 AB 82              3788 	mov	r3,dpl
   0AB5 15 81              3789 	dec	sp
   0AB7 D0 02              3790 	pop	ar2
                           3791 ;	genAssign
                           3792 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:80: if (risefall==1) func=(func>>2)&0x03;		// steigende Flanke
                           3793 ;	genCmpEq
                           3794 ;	gencjneshort
                           3795 ;	Peephole 112.b	changed ljmp to sjmp
                           3796 ;	Peephole 198.b	optimized misc jump sequence
   0AB9 BA 01 0C           3797 	cjne	r2,#0x01,00102$
                           3798 ;	Peephole 200.b	removed redundant sjmp
                           3799 ;	Peephole 300	removed redundant label 00130$
                           3800 ;	Peephole 300	removed redundant label 00131$
                           3801 ;	genRightShift
                           3802 ;	genRightShiftLiteral
                           3803 ;	genrshOne
   0ABC EB                 3804 	mov	a,r3
   0ABD 03                 3805 	rr	a
   0ABE 03                 3806 	rr	a
   0ABF 54 3F              3807 	anl	a,#0x3f
   0AC1 FA                 3808 	mov	r2,a
                           3809 ;	genAnd
   0AC2 74 03              3810 	mov	a,#0x03
   0AC4 5A                 3811 	anl	a,r2
   0AC5 FB                 3812 	mov	r3,a
                           3813 ;	Peephole 112.b	changed ljmp to sjmp
   0AC6 80 03              3814 	sjmp	00103$
   0AC8                    3815 00102$:
                           3816 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:81: else func=func&0x03;				// fallende Flanke
                           3817 ;	genAnd
   0AC8 53 03 03           3818 	anl	ar3,#0x03
   0ACB                    3819 00103$:
                           3820 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:82: if (func!=0)
                           3821 ;	genCmpEq
                           3822 ;	gencjneshort
   0ACB BB 00 03           3823 	cjne	r3,#0x00,00132$
   0ACE 02 0B 90           3824 	ljmp	00120$
   0AD1                    3825 00132$:
                           3826 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:84: ga=find_ga(pinno);
                           3827 ;	genCall
   0AD1 A8 08              3828 	mov	r0,_bp
   0AD3 18                 3829 	dec	r0
   0AD4 18                 3830 	dec	r0
   0AD5 18                 3831 	dec	r0
   0AD6 86 82              3832 	mov	dpl,@r0
   0AD8 C0 03              3833 	push	ar3
   0ADA 12 07 72           3834 	lcall	_find_ga
   0ADD AA 82              3835 	mov	r2,dpl
   0ADF AC 83              3836 	mov	r4,dph
   0AE1 D0 03              3837 	pop	ar3
                           3838 ;	genAssign
                           3839 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:85: if (ga!=0)
                           3840 ;	genCmpEq
                           3841 ;	gencjneshort
   0AE3 BA 00 06           3842 	cjne	r2,#0x00,00133$
   0AE6 BC 00 03           3843 	cjne	r4,#0x00,00133$
   0AE9 02 0B 90           3844 	ljmp	00120$
   0AEC                    3845 00133$:
                           3846 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:87: telegramm[0]=0xBC;
                           3847 ;	genPointerSet
                           3848 ;	genNearPointerSet
                           3849 ;	genDataPointerSet
   0AEC 75 22 BC           3850 	mov	_telegramm,#0xBC
                           3851 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:88: telegramm[1]=pah;
                           3852 ;	genPointerSet
                           3853 ;	genNearPointerSet
                           3854 ;	genDataPointerSet
   0AEF 85 3C 23           3855 	mov	(_telegramm + 0x0001),_pah
                           3856 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:89: telegramm[2]=pal;
                           3857 ;	genPointerSet
                           3858 ;	genNearPointerSet
                           3859 ;	genDataPointerSet
   0AF2 85 3B 24           3860 	mov	(_telegramm + 0x0002),_pal
                           3861 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:90: telegramm[3]=ga>>8;
                           3862 ;	genGetByte
   0AF5 8C 05              3863 	mov	ar5,r4
                           3864 ;	genPointerSet
                           3865 ;	genNearPointerSet
                           3866 ;	genDataPointerSet
   0AF7 8D 25              3867 	mov	(_telegramm + 0x0003),r5
                           3868 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:91: telegramm[4]=ga;
                           3869 ;	genCast
                           3870 ;	genPointerSet
                           3871 ;	genNearPointerSet
                           3872 ;	genDataPointerSet
   0AF9 8A 26              3873 	mov	(_telegramm + 0x0004),r2
                           3874 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:92: telegramm[5]=0xD1;
                           3875 ;	genPointerSet
                           3876 ;	genNearPointerSet
                           3877 ;	genDataPointerSet
   0AFB 75 27 D1           3878 	mov	(_telegramm + 0x0005),#0xD1
                           3879 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:93: telegramm[6]=0x00;
                           3880 ;	genPointerSet
                           3881 ;	genNearPointerSet
                           3882 ;	genDataPointerSet
   0AFE 75 28 00           3883 	mov	(_telegramm + 0x0006),#0x00
                           3884 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:94: if (func==0x01) telegramm[7]=0x81;	// EIN
                           3885 ;	genCmpEq
                           3886 ;	gencjneshort
                           3887 ;	Peephole 112.b	changed ljmp to sjmp
                           3888 ;	Peephole 198.b	optimized misc jump sequence
   0B01 BB 01 03           3889 	cjne	r3,#0x01,00105$
                           3890 ;	Peephole 200.b	removed redundant sjmp
                           3891 ;	Peephole 300	removed redundant label 00134$
                           3892 ;	Peephole 300	removed redundant label 00135$
                           3893 ;	genPointerSet
                           3894 ;	genNearPointerSet
                           3895 ;	genDataPointerSet
   0B04 75 29 81           3896 	mov	(_telegramm + 0x0007),#0x81
   0B07                    3897 00105$:
                           3898 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:95: if (func==0x02) telegramm[7]=0x80;	// AUS
                           3899 ;	genCmpEq
                           3900 ;	gencjneshort
                           3901 ;	Peephole 112.b	changed ljmp to sjmp
                           3902 ;	Peephole 198.b	optimized misc jump sequence
   0B07 BB 02 03           3903 	cjne	r3,#0x02,00107$
                           3904 ;	Peephole 200.b	removed redundant sjmp
                           3905 ;	Peephole 300	removed redundant label 00136$
                           3906 ;	Peephole 300	removed redundant label 00137$
                           3907 ;	genPointerSet
                           3908 ;	genNearPointerSet
                           3909 ;	genDataPointerSet
   0B0A 75 29 80           3910 	mov	(_telegramm + 0x0007),#0x80
   0B0D                    3911 00107$:
                           3912 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:96: if (func==0x03)				// UM
                           3913 ;	genCmpEq
                           3914 ;	gencjneshort
                           3915 ;	Peephole 112.b	changed ljmp to sjmp
                           3916 ;	Peephole 198.b	optimized misc jump sequence
   0B0D BB 03 31           3917 	cjne	r3,#0x03,00112$
                           3918 ;	Peephole 200.b	removed redundant sjmp
                           3919 ;	Peephole 300	removed redundant label 00138$
                           3920 ;	Peephole 300	removed redundant label 00139$
                           3921 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:98: if (((objstate>>pinno)&0x01)==0x01) telegramm[7]=0x80;	// AUS
                           3922 ;	genRightShift
                           3923 ;	genSignedRightShift
   0B10 A8 08              3924 	mov	r0,_bp
   0B12 18                 3925 	dec	r0
   0B13 18                 3926 	dec	r0
   0B14 18                 3927 	dec	r0
   0B15 86 F0              3928 	mov	b,@r0
   0B17 05 F0              3929 	inc	b
   0B19 AA 43              3930 	mov	r2,_objstate
                           3931 ;	peephole 177.h	optimized mov sequence
   0B1B E5 44              3932 	mov	a,(_objstate + 1)
   0B1D FB                 3933 	mov	r3,a
   0B1E 33                 3934 	rlc	a
   0B1F 92 D2              3935 	mov	ov,c
   0B21 80 08              3936 	sjmp	00141$
   0B23                    3937 00140$:
   0B23 A2 D2              3938 	mov	c,ov
   0B25 EB                 3939 	mov	a,r3
   0B26 13                 3940 	rrc	a
   0B27 FB                 3941 	mov	r3,a
   0B28 EA                 3942 	mov	a,r2
   0B29 13                 3943 	rrc	a
   0B2A FA                 3944 	mov	r2,a
   0B2B                    3945 00141$:
   0B2B D5 F0 F5           3946 	djnz	b,00140$
                           3947 ;	genAnd
   0B2E 53 02 01           3948 	anl	ar2,#0x01
   0B31 7B 00              3949 	mov	r3,#0x00
                           3950 ;	genCmpEq
                           3951 ;	gencjneshort
                           3952 ;	Peephole 112.b	changed ljmp to sjmp
                           3953 ;	Peephole 198.a	optimized misc jump sequence
   0B33 BA 01 08           3954 	cjne	r2,#0x01,00109$
   0B36 BB 00 05           3955 	cjne	r3,#0x00,00109$
                           3956 ;	Peephole 200.b	removed redundant sjmp
                           3957 ;	Peephole 300	removed redundant label 00142$
                           3958 ;	Peephole 300	removed redundant label 00143$
                           3959 ;	genPointerSet
                           3960 ;	genNearPointerSet
                           3961 ;	genDataPointerSet
   0B39 75 29 80           3962 	mov	(_telegramm + 0x0007),#0x80
                           3963 ;	Peephole 112.b	changed ljmp to sjmp
   0B3C 80 03              3964 	sjmp	00112$
   0B3E                    3965 00109$:
                           3966 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:99: else telegramm[7]=0x81;					// EIN
                           3967 ;	genPointerSet
                           3968 ;	genNearPointerSet
                           3969 ;	genDataPointerSet
   0B3E 75 29 81           3970 	mov	(_telegramm + 0x0007),#0x81
   0B41                    3971 00112$:
                           3972 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:101: if (telegramm[7]==0x80) objstate=objstate&(0xFFFF-(0x0001<<pinno));
                           3973 ;	genAssign
                           3974 ;	genCmpEq
                           3975 ;	gencjneshort
   0B41 E5 29              3976 	mov	a,0x0007 + _telegramm
                           3977 ;	Peephole 112.b	changed ljmp to sjmp
                           3978 ;	Peephole 198.b	optimized misc jump sequence
   0B43 B4 80 29           3979 	cjne	a,#0x80,00114$
                           3980 ;	Peephole 200.b	removed redundant sjmp
                           3981 ;	Peephole 300	removed redundant label 00144$
                           3982 ;	Peephole 300	removed redundant label 00145$
                           3983 ;	genLeftShift
   0B46 A8 08              3984 	mov	r0,_bp
   0B48 18                 3985 	dec	r0
   0B49 18                 3986 	dec	r0
   0B4A 18                 3987 	dec	r0
   0B4B 86 F0              3988 	mov	b,@r0
   0B4D 05 F0              3989 	inc	b
   0B4F 7A 01              3990 	mov	r2,#0x01
   0B51 7B 00              3991 	mov	r3,#0x00
   0B53 80 06              3992 	sjmp	00147$
   0B55                    3993 00146$:
   0B55 EA                 3994 	mov	a,r2
                           3995 ;	Peephole 254	optimized left shift
   0B56 2A                 3996 	add	a,r2
   0B57 FA                 3997 	mov	r2,a
   0B58 EB                 3998 	mov	a,r3
   0B59 33                 3999 	rlc	a
   0B5A FB                 4000 	mov	r3,a
   0B5B                    4001 00147$:
   0B5B D5 F0 F7           4002 	djnz	b,00146$
                           4003 ;	genMinus
   0B5E 74 FF              4004 	mov	a,#0xFF
   0B60 C3                 4005 	clr	c
                           4006 ;	Peephole 236.l	used r2 instead of ar2
   0B61 9A                 4007 	subb	a,r2
   0B62 FA                 4008 	mov	r2,a
   0B63 74 FF              4009 	mov	a,#0xFF
                           4010 ;	Peephole 236.l	used r3 instead of ar3
   0B65 9B                 4011 	subb	a,r3
   0B66 FB                 4012 	mov	r3,a
                           4013 ;	genAnd
   0B67 EA                 4014 	mov	a,r2
   0B68 52 43              4015 	anl	_objstate,a
   0B6A EB                 4016 	mov	a,r3
   0B6B 52 44              4017 	anl	(_objstate + 1),a
                           4018 ;	Peephole 112.b	changed ljmp to sjmp
   0B6D 80 1E              4019 	sjmp	00115$
   0B6F                    4020 00114$:
                           4021 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:102: else objstate=objstate|(0x0001<<pinno);
                           4022 ;	genLeftShift
   0B6F A8 08              4023 	mov	r0,_bp
   0B71 18                 4024 	dec	r0
   0B72 18                 4025 	dec	r0
   0B73 18                 4026 	dec	r0
   0B74 86 F0              4027 	mov	b,@r0
   0B76 05 F0              4028 	inc	b
   0B78 7A 01              4029 	mov	r2,#0x01
   0B7A 7B 00              4030 	mov	r3,#0x00
   0B7C 80 06              4031 	sjmp	00149$
   0B7E                    4032 00148$:
   0B7E EA                 4033 	mov	a,r2
                           4034 ;	Peephole 254	optimized left shift
   0B7F 2A                 4035 	add	a,r2
   0B80 FA                 4036 	mov	r2,a
   0B81 EB                 4037 	mov	a,r3
   0B82 33                 4038 	rlc	a
   0B83 FB                 4039 	mov	r3,a
   0B84                    4040 00149$:
   0B84 D5 F0 F7           4041 	djnz	b,00148$
                           4042 ;	genOr
   0B87 EA                 4043 	mov	a,r2
   0B88 42 43              4044 	orl	_objstate,a
   0B8A EB                 4045 	mov	a,r3
   0B8B 42 44              4046 	orl	(_objstate + 1),a
   0B8D                    4047 00115$:
                           4048 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:103: send_telegramm();
                           4049 ;	genCall
   0B8D 12 04 DD           4050 	lcall	_send_telegramm
   0B90                    4051 00120$:
   0B90 D0 08              4052 	pop	_bp
   0B92 22                 4053 	ret
                           4054 ;------------------------------------------------------------
                           4055 ;Allocation info for local variables in function 'pin_function'
                           4056 ;------------------------------------------------------------
                           4057 ;pinno                     Allocated to registers 
                           4058 ;------------------------------------------------------------
                           4059 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:111: unsigned char pin_function(unsigned char pinno)		// Funktion des Eingangs ermitteln
                           4060 ;	-----------------------------------------
                           4061 ;	 function pin_function
                           4062 ;	-----------------------------------------
   0B93                    4063 _pin_function:
                           4064 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:114: return (0);
                           4065 ;	genRet
   0B93 75 82 00           4066 	mov	dpl,#0x00
                           4067 ;	Peephole 300	removed redundant label 00101$
   0B96 22                 4068 	ret
                           4069 ;------------------------------------------------------------
                           4070 ;Allocation info for local variables in function 'debounce'
                           4071 ;------------------------------------------------------------
                           4072 ;pinno                     Allocated to registers 
                           4073 ;debtime                   Allocated to registers r2 
                           4074 ;n                         Allocated to registers r3 
                           4075 ;------------------------------------------------------------
                           4076 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:118: unsigned char debounce(unsigned char pinno)	// Entprellzeit abwarten und prüfen !! Prüfung fehlt noch !!
                           4077 ;	-----------------------------------------
                           4078 ;	 function debounce
                           4079 ;	-----------------------------------------
   0B97                    4080 _debounce:
                           4081 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:122: debtime=read_byte(0x01,DEBTIME);			// Entprellzeit in 0,5ms Schritten
                           4082 ;	genIpush
   0B97 74 D2              4083 	mov	a,#0xD2
   0B99 C0 E0              4084 	push	acc
                           4085 ;	genCall
   0B9B 75 82 01           4086 	mov	dpl,#0x01
   0B9E 12 02 CF           4087 	lcall	_read_byte
   0BA1 AA 82              4088 	mov	r2,dpl
   0BA3 15 81              4089 	dec	sp
                           4090 ;	genAssign
                           4091 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:123: if (debtime>0)
                           4092 ;	genIfx
   0BA5 EA                 4093 	mov	a,r2
                           4094 ;	genIfxJump
                           4095 ;	Peephole 108.c	removed ljmp by inverse jump logic
   0BA6 60 18              4096 	jz	00102$
                           4097 ;	Peephole 300	removed redundant label 00113$
                           4098 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:125: for(n=0;n<debtime;n++)
                           4099 ;	genAssign
   0BA8 7B 00              4100 	mov	r3,#0x00
   0BAA                    4101 00103$:
                           4102 ;	genCmpLt
                           4103 ;	genCmp
   0BAA C3                 4104 	clr	c
   0BAB EB                 4105 	mov	a,r3
   0BAC 9A                 4106 	subb	a,r2
                           4107 ;	genIfxJump
                           4108 ;	Peephole 108.a	removed ljmp by inverse jump logic
   0BAD 50 11              4109 	jnc	00102$
                           4110 ;	Peephole 300	removed redundant label 00114$
                           4111 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:127: delay(500);
                           4112 ;	genCall
                           4113 ;	Peephole 182.b	used 16 bit load of dptr
   0BAF 90 01 F4           4114 	mov	dptr,#0x01F4
   0BB2 C0 02              4115 	push	ar2
   0BB4 C0 03              4116 	push	ar3
   0BB6 12 02 9A           4117 	lcall	_delay
   0BB9 D0 03              4118 	pop	ar3
   0BBB D0 02              4119 	pop	ar2
                           4120 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:125: for(n=0;n<debtime;n++)
                           4121 ;	genPlus
                           4122 ;     genPlusIncr
   0BBD 0B                 4123 	inc	r3
                           4124 ;	Peephole 112.b	changed ljmp to sjmp
   0BBE 80 EA              4125 	sjmp	00103$
   0BC0                    4126 00102$:
                           4127 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:131: return(1);
                           4128 ;	genRet
   0BC0 75 82 01           4129 	mov	dpl,#0x01
                           4130 ;	Peephole 300	removed redundant label 00107$
   0BC3 22                 4131 	ret
                           4132 ;------------------------------------------------------------
                           4133 ;Allocation info for local variables in function 'eis1'
                           4134 ;------------------------------------------------------------
                           4135 ;objno                     Allocated to registers r7 
                           4136 ;port_pattern              Allocated to stack - offset 1
                           4137 ;objflags                  Allocated to stack - offset 2
                           4138 ;gapos                     Allocated to stack - offset 3
                           4139 ;atp                       Allocated to registers r3 
                           4140 ;assno                     Allocated to stack - offset 4
                           4141 ;delay_base                Allocated to registers r4 
                           4142 ;n                         Allocated to stack - offset 5
                           4143 ;delay_onoff               Allocated to registers r2 
                           4144 ;delay_status              Allocated to registers r6 
                           4145 ;gaposh                    Allocated to registers r5 
                           4146 ;delay_zeit                Allocated to stack - offset 6
                           4147 ;delay_target              Allocated to stack - offset 7
                           4148 ;ga                        Allocated to registers r2 r4 
                           4149 ;sloc0                     Allocated to stack - offset 11
                           4150 ;------------------------------------------------------------
                           4151 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:136: void eis1(void)				// Ausgänge schalten gemäß EIS 1 Protokoll (an/aus)
                           4152 ;	-----------------------------------------
                           4153 ;	 function eis1
                           4154 ;	-----------------------------------------
   0BC4                    4155 _eis1:
   0BC4 C0 08              4156 	push	_bp
                           4157 ;	peephole 177.h	optimized mov sequence
   0BC6 E5 81              4158 	mov	a,sp
   0BC8 F5 08              4159 	mov	_bp,a
   0BCA 24 0B              4160 	add	a,#0x0b
   0BCC F5 81              4161 	mov	sp,a
                           4162 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:143: ga=telegramm[3];
                           4163 ;	genPointerGet
                           4164 ;	genNearPointerGet
                           4165 ;	genDataPointerGet
   0BCE 85 25 82           4166 	mov	dpl,(_telegramm + 0x0003)
                           4167 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:145: ga=ga+telegramm[4];
                           4168 ;	genAssign
                           4169 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:149: gapos=gapos_in_gat(telegramm[3],telegramm[4]);
                           4170 ;	genIpush
   0BD1 C0 26              4171 	push	0x0004 + _telegramm
                           4172 ;	genCall
   0BD3 12 08 6C           4173 	lcall	_gapos_in_gat
   0BD6 AA 82              4174 	mov	r2,dpl
   0BD8 15 81              4175 	dec	sp
                           4176 ;	genAssign
   0BDA A8 08              4177 	mov	r0,_bp
   0BDC 08                 4178 	inc	r0
   0BDD 08                 4179 	inc	r0
   0BDE 08                 4180 	inc	r0
   0BDF A6 02              4181 	mov	@r0,ar2
                           4182 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:150: if (gapos!=0xFF)	
                           4183 ;	genCmpEq
   0BE1 A8 08              4184 	mov	r0,_bp
   0BE3 08                 4185 	inc	r0
   0BE4 08                 4186 	inc	r0
   0BE5 08                 4187 	inc	r0
                           4188 ;	gencjneshort
   0BE6 B6 FF 03           4189 	cjne	@r0,#0xFF,00177$
   0BE9 02 11 0E           4190 	ljmp	00151$
   0BEC                    4191 00177$:
                           4192 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:152: send_ack();
                           4193 ;	genCall
   0BEC 12 05 A3           4194 	lcall	_send_ack
                           4195 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:153: atp=read_byte(0x01,0x11);			// Association Table Pointer
                           4196 ;	genIpush
   0BEF 74 11              4197 	mov	a,#0x11
   0BF1 C0 E0              4198 	push	acc
                           4199 ;	genCall
   0BF3 75 82 01           4200 	mov	dpl,#0x01
   0BF6 12 02 CF           4201 	lcall	_read_byte
   0BF9 AB 82              4202 	mov	r3,dpl
   0BFB 15 81              4203 	dec	sp
                           4204 ;	genAssign
                           4205 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:154: assno=read_byte(0x01,atp);		// Erster Eintrag = Anzahl Einträge
                           4206 ;	genIpush
   0BFD C0 03              4207 	push	ar3
   0BFF C0 03              4208 	push	ar3
                           4209 ;	genCall
   0C01 75 82 01           4210 	mov	dpl,#0x01
   0C04 12 02 CF           4211 	lcall	_read_byte
   0C07 AC 82              4212 	mov	r4,dpl
   0C09 15 81              4213 	dec	sp
   0C0B D0 03              4214 	pop	ar3
                           4215 ;	genAssign
   0C0D E5 08              4216 	mov	a,_bp
   0C0F 24 04              4217 	add	a,#0x04
   0C11 F8                 4218 	mov	r0,a
   0C12 A6 04              4219 	mov	@r0,ar4
                           4220 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:156: for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
                           4221 ;	genPlus
                           4222 ;     genPlusIncr
   0C14 74 02              4223 	mov	a,#0x02
                           4224 ;	Peephole 236.a	used r3 instead of ar3
   0C16 2B                 4225 	add	a,r3
   0C17 FD                 4226 	mov	r5,a
                           4227 ;	genPlus
                           4228 ;     genPlusIncr
   0C18 0B                 4229 	inc	r3
                           4230 ;	genAssign
   0C19 E5 08              4231 	mov	a,_bp
   0C1B 24 05              4232 	add	a,#0x05
   0C1D F8                 4233 	mov	r0,a
   0C1E 76 00              4234 	mov	@r0,#0x00
   0C20                    4235 00147$:
                           4236 ;	genCmpLt
   0C20 E5 08              4237 	mov	a,_bp
   0C22 24 05              4238 	add	a,#0x05
   0C24 F8                 4239 	mov	r0,a
   0C25 E5 08              4240 	mov	a,_bp
   0C27 24 04              4241 	add	a,#0x04
   0C29 F9                 4242 	mov	r1,a
                           4243 ;	genCmp
   0C2A C3                 4244 	clr	c
   0C2B E6                 4245 	mov	a,@r0
   0C2C 97                 4246 	subb	a,@r1
                           4247 ;	genIfxJump
   0C2D 40 03              4248 	jc	00178$
   0C2F 02 11 0E           4249 	ljmp	00151$
   0C32                    4250 00178$:
                           4251 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:158: gaposh=read_byte(0x01,atp+1+(n*2));
                           4252 ;	genIpush
   0C32 C0 05              4253 	push	ar5
                           4254 ;	genLeftShift
                           4255 ;	genLeftShiftLiteral
   0C34 E5 08              4256 	mov	a,_bp
   0C36 24 05              4257 	add	a,#0x05
   0C38 F8                 4258 	mov	r0,a
                           4259 ;	genlshOne
   0C39 E6                 4260 	mov	a,@r0
   0C3A 25 E0              4261 	add	a,acc
                           4262 ;	genPlus
   0C3C FF                 4263 	mov	r7,a
                           4264 ;	Peephole 177.b	removed redundant mov
                           4265 ;	Peephole 236.a	used r3 instead of ar3
   0C3D 2B                 4266 	add	a,r3
   0C3E FD                 4267 	mov	r5,a
                           4268 ;	genIpush
   0C3F C0 03              4269 	push	ar3
   0C41 C0 07              4270 	push	ar7
   0C43 C0 05              4271 	push	ar5
                           4272 ;	genCall
   0C45 75 82 01           4273 	mov	dpl,#0x01
   0C48 12 02 CF           4274 	lcall	_read_byte
   0C4B AD 82              4275 	mov	r5,dpl
   0C4D 15 81              4276 	dec	sp
   0C4F D0 07              4277 	pop	ar7
   0C51 D0 03              4278 	pop	ar3
                           4279 ;	genAssign
                           4280 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:159: if(gapos==gaposh)					// Wenn Positionsnummer übereinstimmt
                           4281 ;	genCmpEq
   0C53 A8 08              4282 	mov	r0,_bp
   0C55 08                 4283 	inc	r0
   0C56 08                 4284 	inc	r0
   0C57 08                 4285 	inc	r0
                           4286 ;	gencjne
                           4287 ;	gencjneshort
   0C58 E6                 4288 	mov	a,@r0
   0C59 B5 05 04           4289 	cjne	a,ar5,00179$
   0C5C 74 01              4290 	mov	a,#0x01
   0C5E 80 01              4291 	sjmp	00180$
   0C60                    4292 00179$:
   0C60 E4                 4293 	clr	a
   0C61                    4294 00180$:
                           4295 ;	genIpop
   0C61 D0 05              4296 	pop	ar5
                           4297 ;	genIfx
                           4298 ;	genIfxJump
   0C63 70 03              4299 	jnz	00181$
   0C65 02 11 05           4300 	ljmp	00149$
   0C68                    4301 00181$:
                           4302 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:161: objno=read_byte(0x01,atp+2+(n*2));			// Objektnummer
                           4303 ;	genIpush
   0C68 C0 03              4304 	push	ar3
                           4305 ;	genPlus
                           4306 ;	Peephole 236.g	used r7 instead of ar7
   0C6A EF                 4307 	mov	a,r7
                           4308 ;	Peephole 236.a	used r5 instead of ar5
   0C6B 2D                 4309 	add	a,r5
   0C6C FF                 4310 	mov	r7,a
                           4311 ;	genIpush
   0C6D C0 03              4312 	push	ar3
   0C6F C0 05              4313 	push	ar5
   0C71 C0 07              4314 	push	ar7
                           4315 ;	genCall
   0C73 75 82 01           4316 	mov	dpl,#0x01
   0C76 12 02 CF           4317 	lcall	_read_byte
   0C79 AF 82              4318 	mov	r7,dpl
   0C7B 15 81              4319 	dec	sp
   0C7D D0 05              4320 	pop	ar5
   0C7F D0 03              4321 	pop	ar3
                           4322 ;	genAssign
                           4323 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:162: objflags=read_objflags(objno);			// Objekt Flags lesen
                           4324 ;	genCall
   0C81 8F 82              4325 	mov	dpl,r7
   0C83 C0 05              4326 	push	ar5
   0C85 C0 07              4327 	push	ar7
   0C87 12 07 44           4328 	lcall	_read_objflags
   0C8A AB 82              4329 	mov	r3,dpl
   0C8C D0 07              4330 	pop	ar7
   0C8E D0 05              4331 	pop	ar5
                           4332 ;	genAssign
   0C90 A8 08              4333 	mov	r0,_bp
   0C92 08                 4334 	inc	r0
   0C93 08                 4335 	inc	r0
   0C94 A6 03              4336 	mov	@r0,ar3
                           4337 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:163: if((objflags&0x04)==0x04)				// Kommunikation zulässig (Bit 2 = communication enable) 
                           4338 ;	genAnd
   0C96 A8 08              4339 	mov	r0,_bp
   0C98 08                 4340 	inc	r0
   0C99 08                 4341 	inc	r0
   0C9A 74 04              4342 	mov	a,#0x04
   0C9C 56                 4343 	anl	a,@r0
   0C9D FB                 4344 	mov	r3,a
                           4345 ;	genCmpEq
                           4346 ;	gencjne
                           4347 ;	gencjneshort
                           4348 ;	Peephole 241.d	optimized compare
   0C9E E4                 4349 	clr	a
   0C9F BB 04 01           4350 	cjne	r3,#0x04,00182$
   0CA2 04                 4351 	inc	a
   0CA3                    4352 00182$:
                           4353 ;	Peephole 300	removed redundant label 00183$
                           4354 ;	genIpop
   0CA3 D0 03              4355 	pop	ar3
                           4356 ;	genIfx
                           4357 ;	genIfxJump
   0CA5 70 03              4358 	jnz	00184$
   0CA7 02 11 05           4359 	ljmp	00149$
   0CAA                    4360 00184$:
                           4361 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:165: port_pattern=0x01<<objno;
                           4362 ;	genIpush
   0CAA C0 05              4363 	push	ar5
                           4364 ;	genLeftShift
   0CAC 8F F0              4365 	mov	b,r7
   0CAE 05 F0              4366 	inc	b
   0CB0 A8 08              4367 	mov	r0,_bp
   0CB2 08                 4368 	inc	r0
   0CB3 74 01              4369 	mov	a,#0x01
   0CB5 80 02              4370 	sjmp	00187$
   0CB7                    4371 00185$:
   0CB7 25 E0              4372 	add	a,acc
   0CB9                    4373 00187$:
   0CB9 D5 F0 FB           4374 	djnz	b,00185$
   0CBC F6                 4375 	mov	@r0,a
                           4376 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:166: if((port_pattern&pdir)==port_pattern)		// Portpin darf beschrieben werden
                           4377 ;	genAnd
   0CBD A8 08              4378 	mov	r0,_bp
   0CBF 08                 4379 	inc	r0
   0CC0 E5 49              4380 	mov	a,_pdir
   0CC2 56                 4381 	anl	a,@r0
   0CC3 FD                 4382 	mov	r5,a
                           4383 ;	genCmpEq
   0CC4 A8 08              4384 	mov	r0,_bp
   0CC6 08                 4385 	inc	r0
                           4386 ;	gencjne
                           4387 ;	gencjneshort
   0CC7 E6                 4388 	mov	a,@r0
   0CC8 B5 05 04           4389 	cjne	a,ar5,00188$
   0CCB 74 01              4390 	mov	a,#0x01
   0CCD 80 01              4391 	sjmp	00189$
   0CCF                    4392 00188$:
   0CCF E4                 4393 	clr	a
   0CD0                    4394 00189$:
                           4395 ;	genIpop
   0CD0 D0 05              4396 	pop	ar5
                           4397 ;	genIfx
                           4398 ;	genIfxJump
   0CD2 70 03              4399 	jnz	00190$
   0CD4 02 10 CC           4400 	ljmp	00134$
   0CD7                    4401 00190$:
                           4402 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:168: if((objflags&0x10)==0x10)				// Schreiben zulässig (Bit 4 = write enable)
                           4403 ;	genIpush
   0CD7 C0 05              4404 	push	ar5
                           4405 ;	genAnd
   0CD9 A8 08              4406 	mov	r0,_bp
   0CDB 08                 4407 	inc	r0
   0CDC 08                 4408 	inc	r0
   0CDD 74 10              4409 	mov	a,#0x10
   0CDF 56                 4410 	anl	a,@r0
   0CE0 FD                 4411 	mov	r5,a
                           4412 ;	genCmpEq
                           4413 ;	gencjne
                           4414 ;	gencjneshort
                           4415 ;	Peephole 241.d	optimized compare
   0CE1 E4                 4416 	clr	a
   0CE2 BD 10 01           4417 	cjne	r5,#0x10,00191$
   0CE5 04                 4418 	inc	a
   0CE6                    4419 00191$:
                           4420 ;	Peephole 300	removed redundant label 00192$
                           4421 ;	genIpop
   0CE6 D0 05              4422 	pop	ar5
                           4423 ;	genIfx
                           4424 ;	genIfxJump
   0CE8 70 03              4425 	jnz	00193$
   0CEA 02 10 CC           4426 	ljmp	00134$
   0CED                    4427 00193$:
                           4428 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:170: delay_base=read_byte(0x01,(((objno+1)>>1)+DELAYTAB));   
                           4429 ;	genIpush
   0CED C0 05              4430 	push	ar5
                           4431 ;	genCast
   0CEF 8F 05              4432 	mov	ar5,r7
   0CF1 7A 00              4433 	mov	r2,#0x00
                           4434 ;	genPlus
                           4435 ;     genPlusIncr
   0CF3 0D                 4436 	inc	r5
   0CF4 BD 00 01           4437 	cjne	r5,#0x00,00194$
   0CF7 0A                 4438 	inc	r2
   0CF8                    4439 00194$:
                           4440 ;	genRightShift
                           4441 ;	genSignedRightShift
                           4442 ;	genRightShiftLiteral
                           4443 ;	genrshTwo
   0CF8 EA                 4444 	mov	a,r2
   0CF9 A2 E7              4445 	mov	c,acc.7
   0CFB 13                 4446 	rrc	a
   0CFC CD                 4447 	xch	a,r5
   0CFD 13                 4448 	rrc	a
   0CFE CD                 4449 	xch	a,r5
   0CFF FA                 4450 	mov	r2,a
                           4451 ;	genCast
                           4452 ;	genPlus
                           4453 ;     genPlusIncr
   0D00 74 F9              4454 	mov	a,#0xF9
                           4455 ;	Peephole 236.a	used r5 instead of ar5
   0D02 2D                 4456 	add	a,r5
   0D03 FD                 4457 	mov	r5,a
                           4458 ;	genIpush
   0D04 C0 03              4459 	push	ar3
   0D06 C0 05              4460 	push	ar5
   0D08 C0 07              4461 	push	ar7
   0D0A C0 05              4462 	push	ar5
                           4463 ;	genCall
   0D0C 75 82 01           4464 	mov	dpl,#0x01
   0D0F 12 02 CF           4465 	lcall	_read_byte
   0D12 AA 82              4466 	mov	r2,dpl
   0D14 15 81              4467 	dec	sp
   0D16 D0 07              4468 	pop	ar7
   0D18 D0 05              4469 	pop	ar5
   0D1A D0 03              4470 	pop	ar3
                           4471 ;	genAssign
   0D1C 8A 04              4472 	mov	ar4,r2
                           4473 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:171: if((objno&0x01)==0x01) delay_base&=0x0F;
                           4474 ;	genAnd
   0D1E 74 01              4475 	mov	a,#0x01
   0D20 5F                 4476 	anl	a,r7
   0D21 FA                 4477 	mov	r2,a
                           4478 ;	genCmpEq
                           4479 ;	gencjne
                           4480 ;	gencjneshort
                           4481 ;	Peephole 241.d	optimized compare
   0D22 E4                 4482 	clr	a
   0D23 BA 01 01           4483 	cjne	r2,#0x01,00195$
   0D26 04                 4484 	inc	a
   0D27                    4485 00195$:
                           4486 ;	Peephole 300	removed redundant label 00196$
                           4487 ;	genIpop
   0D27 D0 05              4488 	pop	ar5
                           4489 ;	genIfx
                           4490 ;	genIfxJump
                           4491 ;	Peephole 108.c	removed ljmp by inverse jump logic
   0D29 60 05              4492 	jz	00102$
                           4493 ;	Peephole 300	removed redundant label 00197$
                           4494 ;	genAnd
   0D2B 53 04 0F           4495 	anl	ar4,#0x0F
                           4496 ;	Peephole 112.b	changed ljmp to sjmp
   0D2E 80 08              4497 	sjmp	00103$
   0D30                    4498 00102$:
                           4499 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:172: else delay_base=(delay_base&0xF0)>>4;
                           4500 ;	genAnd
   0D30 74 F0              4501 	mov	a,#0xF0
   0D32 5C                 4502 	anl	a,r4
                           4503 ;	genRightShift
                           4504 ;	genRightShiftLiteral
                           4505 ;	genrshOne
   0D33 FA                 4506 	mov	r2,a
                           4507 ;	Peephole 105	removed redundant mov
   0D34 C4                 4508 	swap	a
   0D35 54 0F              4509 	anl	a,#0x0f
   0D37 FC                 4510 	mov	r4,a
   0D38                    4511 00103$:
                           4512 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:174: delay_onoff=0;
                           4513 ;	genIpush
   0D38 C0 05              4514 	push	ar5
                           4515 ;	genAssign
   0D3A 7A 00              4516 	mov	r2,#0x00
                           4517 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:175: delay_status=0;
                           4518 ;	genAssign
   0D3C 7E 00              4519 	mov	r6,#0x00
                           4520 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:176: delay_zeit=read_byte(0x01,0xEA);
                           4521 ;	genIpush
   0D3E C0 02              4522 	push	ar2
   0D40 C0 03              4523 	push	ar3
   0D42 C0 04              4524 	push	ar4
   0D44 C0 06              4525 	push	ar6
   0D46 C0 07              4526 	push	ar7
   0D48 74 EA              4527 	mov	a,#0xEA
   0D4A C0 E0              4528 	push	acc
                           4529 ;	genCall
   0D4C 75 82 01           4530 	mov	dpl,#0x01
   0D4F 12 02 CF           4531 	lcall	_read_byte
   0D52 AD 82              4532 	mov	r5,dpl
   0D54 15 81              4533 	dec	sp
   0D56 D0 07              4534 	pop	ar7
   0D58 D0 06              4535 	pop	ar6
   0D5A D0 04              4536 	pop	ar4
   0D5C D0 03              4537 	pop	ar3
   0D5E D0 02              4538 	pop	ar2
                           4539 ;	genAssign
   0D60 E5 08              4540 	mov	a,_bp
   0D62 24 06              4541 	add	a,#0x06
   0D64 F8                 4542 	mov	r0,a
   0D65 A6 05              4543 	mov	@r0,ar5
                           4544 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:177: delay_zeit=((delay_zeit>>objno)&0x01);
                           4545 ;	genRightShift
   0D67 8F F0              4546 	mov	b,r7
   0D69 05 F0              4547 	inc	b
   0D6B E5 08              4548 	mov	a,_bp
   0D6D 24 06              4549 	add	a,#0x06
   0D6F F8                 4550 	mov	r0,a
   0D70 E6                 4551 	mov	a,@r0
   0D71 80 02              4552 	sjmp	00199$
   0D73                    4553 00198$:
   0D73 C3                 4554 	clr	c
   0D74 13                 4555 	rrc	a
   0D75                    4556 00199$:
   0D75 D5 F0 FB           4557 	djnz	b,00198$
   0D78 FD                 4558 	mov	r5,a
                           4559 ;	genAnd
   0D79 E5 08              4560 	mov	a,_bp
   0D7B 24 06              4561 	add	a,#0x06
   0D7D F8                 4562 	mov	r0,a
   0D7E 74 01              4563 	mov	a,#0x01
   0D80 5D                 4564 	anl	a,r5
   0D81 F6                 4565 	mov	@r0,a
                           4566 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:179: switch (telegramm[7])
                           4567 ;	genPointerGet
                           4568 ;	genNearPointerGet
                           4569 ;	genDataPointerGet
   0D82 E5 08              4570 	mov	a,_bp
   0D84 24 0B              4571 	add	a,#0x0b
   0D86 F8                 4572 	mov	r0,a
   0D87 A6 29              4573 	mov	@r0,(_telegramm + 0x0007)
                           4574 ;	genCmpEq
   0D89 E5 08              4575 	mov	a,_bp
   0D8B 24 0B              4576 	add	a,#0x0b
   0D8D F8                 4577 	mov	r0,a
                           4578 ;	gencjne
                           4579 ;	gencjneshort
                           4580 ;	Peephole 241.h	optimized compare
   0D8E E4                 4581 	clr	a
   0D8F B6 80 01           4582 	cjne	@r0,#0x80,00200$
   0D92 04                 4583 	inc	a
   0D93                    4584 00200$:
                           4585 ;	Peephole 300	removed redundant label 00201$
                           4586 ;	genIpop
   0D93 D0 05              4587 	pop	ar5
                           4588 ;	genIfx
                           4589 ;	genIfxJump
                           4590 ;	Peephole 108.b	removed ljmp by inverse jump logic
   0D95 70 0E              4591 	jnz	00104$
                           4592 ;	Peephole 300	removed redundant label 00202$
                           4593 ;	genCmpEq
   0D97 E5 08              4594 	mov	a,_bp
   0D99 24 0B              4595 	add	a,#0x0b
   0D9B F8                 4596 	mov	r0,a
                           4597 ;	gencjneshort
   0D9C B6 81 03           4598 	cjne	@r0,#0x81,00203$
   0D9F 02 0E 29           4599 	ljmp	00112$
   0DA2                    4600 00203$:
   0DA2 02 0E D3           4601 	ljmp	00121$
                           4602 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:181: case 0x80:					// Ausschalten
   0DA5                    4603 00104$:
                           4604 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:182: delay_onoff=read_byte(0x01,(objno+0xE2));
                           4605 ;	genIpush
   0DA5 C0 05              4606 	push	ar5
                           4607 ;	genPlus
                           4608 ;     genPlusIncr
   0DA7 74 E2              4609 	mov	a,#0xE2
                           4610 ;	Peephole 236.a	used r7 instead of ar7
   0DA9 2F                 4611 	add	a,r7
   0DAA FD                 4612 	mov	r5,a
                           4613 ;	genIpush
   0DAB C0 03              4614 	push	ar3
   0DAD C0 04              4615 	push	ar4
   0DAF C0 06              4616 	push	ar6
   0DB1 C0 07              4617 	push	ar7
   0DB3 C0 05              4618 	push	ar5
                           4619 ;	genCall
   0DB5 75 82 01           4620 	mov	dpl,#0x01
   0DB8 12 02 CF           4621 	lcall	_read_byte
   0DBB AD 82              4622 	mov	r5,dpl
   0DBD 15 81              4623 	dec	sp
   0DBF D0 07              4624 	pop	ar7
   0DC1 D0 06              4625 	pop	ar6
   0DC3 D0 04              4626 	pop	ar4
   0DC5 D0 03              4627 	pop	ar3
                           4628 ;	genAssign
   0DC7 8D 02              4629 	mov	ar2,r5
                           4630 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:183: if(delay_onoff==0x00 || delay_zeit==0x01)
                           4631 ;	genIpop
   0DC9 D0 05              4632 	pop	ar5
                           4633 ;	genIfx
   0DCB EA                 4634 	mov	a,r2
                           4635 ;	genIfxJump
                           4636 ;	Peephole 108.c	removed ljmp by inverse jump logic
   0DCC 60 08              4637 	jz	00108$
                           4638 ;	Peephole 300	removed redundant label 00204$
                           4639 ;	genCmpEq
   0DCE E5 08              4640 	mov	a,_bp
   0DD0 24 06              4641 	add	a,#0x06
   0DD2 F8                 4642 	mov	r0,a
                           4643 ;	gencjneshort
                           4644 ;	Peephole 112.b	changed ljmp to sjmp
                           4645 ;	Peephole 198.b	optimized misc jump sequence
   0DD3 B6 01 4E           4646 	cjne	@r0,#0x01,00109$
                           4647 ;	Peephole 200.b	removed redundant sjmp
                           4648 ;	Peephole 300	removed redundant label 00205$
                           4649 ;	Peephole 300	removed redundant label 00206$
   0DD6                    4650 00108$:
                           4651 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:185: if (((read_byte(0x01,RELMODE)>>objno)&0x01)==0x00)
                           4652 ;	genIpush
   0DD6 C0 05              4653 	push	ar5
                           4654 ;	genIpush
   0DD8 C0 02              4655 	push	ar2
   0DDA C0 03              4656 	push	ar3
   0DDC C0 04              4657 	push	ar4
   0DDE C0 06              4658 	push	ar6
   0DE0 C0 07              4659 	push	ar7
   0DE2 74 F2              4660 	mov	a,#0xF2
   0DE4 C0 E0              4661 	push	acc
                           4662 ;	genCall
   0DE6 75 82 01           4663 	mov	dpl,#0x01
   0DE9 12 02 CF           4664 	lcall	_read_byte
   0DEC AD 82              4665 	mov	r5,dpl
   0DEE 15 81              4666 	dec	sp
   0DF0 D0 07              4667 	pop	ar7
   0DF2 D0 06              4668 	pop	ar6
   0DF4 D0 04              4669 	pop	ar4
   0DF6 D0 03              4670 	pop	ar3
   0DF8 D0 02              4671 	pop	ar2
                           4672 ;	genRightShift
   0DFA 8F F0              4673 	mov	b,r7
   0DFC 05 F0              4674 	inc	b
   0DFE ED                 4675 	mov	a,r5
   0DFF 80 02              4676 	sjmp	00208$
   0E01                    4677 00207$:
   0E01 C3                 4678 	clr	c
   0E02 13                 4679 	rrc	a
   0E03                    4680 00208$:
   0E03 D5 F0 FB           4681 	djnz	b,00207$
                           4682 ;	genAnd
   0E06 54 01              4683 	anl	a,#0x01
                           4684 ;	genIpop
   0E08 D0 05              4685 	pop	ar5
                           4686 ;	genIfx
                           4687 ;	genIfxJump
                           4688 ;	Peephole 108.b	removed ljmp by inverse jump logic
   0E0A 70 0F              4689 	jnz	00106$
                           4690 ;	Peephole 300	removed redundant label 00209$
                           4691 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:187: portbuffer=portbuffer&~port_pattern;		// sofort ausschalten (Schliesserbetrieb)
                           4692 ;	genIpush
   0E0C C0 05              4693 	push	ar5
                           4694 ;	genCpl
   0E0E A8 08              4695 	mov	r0,_bp
   0E10 08                 4696 	inc	r0
   0E11 E6                 4697 	mov	a,@r0
   0E12 F4                 4698 	cpl	a
                           4699 ;	genAnd
   0E13 FD                 4700 	mov	r5,a
                           4701 ;	Peephole 105	removed redundant mov
   0E14 52 41              4702 	anl	_portbuffer,a
                           4703 ;	genIpop
   0E16 D0 05              4704 	pop	ar5
   0E18 02 0E D3           4705 	ljmp	00121$
   0E1B                    4706 00106$:
                           4707 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:191: portbuffer=portbuffer|port_pattern;		// sofort ausschalten (Öffnerbetrieb)
                           4708 ;	genOr
   0E1B A8 08              4709 	mov	r0,_bp
   0E1D 08                 4710 	inc	r0
   0E1E E6                 4711 	mov	a,@r0
   0E1F 42 41              4712 	orl	_portbuffer,a
   0E21 02 0E D3           4713 	ljmp	00121$
   0E24                    4714 00109$:
                           4715 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:196: delay_status=0x80;				// verzögert
                           4716 ;	genAssign
   0E24 7E 80              4717 	mov	r6,#0x80
                           4718 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:198: break;
   0E26 02 0E D3           4719 	ljmp	00121$
                           4720 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:199: case 0x81:					// Einschalten
   0E29                    4721 00112$:
                           4722 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:200: delay_onoff=read_byte(0x01,(objno+0xDA));
                           4723 ;	genIpush
   0E29 C0 05              4724 	push	ar5
                           4725 ;	genPlus
                           4726 ;     genPlusIncr
   0E2B 74 DA              4727 	mov	a,#0xDA
                           4728 ;	Peephole 236.a	used r7 instead of ar7
   0E2D 2F                 4729 	add	a,r7
   0E2E FD                 4730 	mov	r5,a
                           4731 ;	genIpush
   0E2F C0 03              4732 	push	ar3
   0E31 C0 04              4733 	push	ar4
   0E33 C0 06              4734 	push	ar6
   0E35 C0 07              4735 	push	ar7
   0E37 C0 05              4736 	push	ar5
                           4737 ;	genCall
   0E39 75 82 01           4738 	mov	dpl,#0x01
   0E3C 12 02 CF           4739 	lcall	_read_byte
   0E3F AD 82              4740 	mov	r5,dpl
   0E41 15 81              4741 	dec	sp
   0E43 D0 07              4742 	pop	ar7
   0E45 D0 06              4743 	pop	ar6
   0E47 D0 04              4744 	pop	ar4
   0E49 D0 03              4745 	pop	ar3
                           4746 ;	genAssign
   0E4B 8D 02              4747 	mov	ar2,r5
                           4748 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:201: if(delay_onoff==0x00)
                           4749 ;	genIpop
   0E4D D0 05              4750 	pop	ar5
                           4751 ;	genIfx
   0E4F EA                 4752 	mov	a,r2
                           4753 ;	genIfxJump
   0E50 60 03              4754 	jz	00210$
   0E52 02 0E D1           4755 	ljmp	00119$
   0E55                    4756 00210$:
                           4757 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:203: if(delay_zeit==0x01) 			// Zeitschaltfunktion 
                           4758 ;	genCmpEq
   0E55 E5 08              4759 	mov	a,_bp
   0E57 24 06              4760 	add	a,#0x06
   0E59 F8                 4761 	mov	r0,a
                           4762 ;	gencjneshort
                           4763 ;	Peephole 112.b	changed ljmp to sjmp
                           4764 ;	Peephole 198.b	optimized misc jump sequence
   0E5A B6 01 28           4765 	cjne	@r0,#0x01,00114$
                           4766 ;	Peephole 200.b	removed redundant sjmp
                           4767 ;	Peephole 300	removed redundant label 00211$
                           4768 ;	Peephole 300	removed redundant label 00212$
                           4769 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:205: delay_status=0x80;
                           4770 ;	genIpush
   0E5D C0 05              4771 	push	ar5
                           4772 ;	genAssign
   0E5F 7E 80              4773 	mov	r6,#0x80
                           4774 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:206: delay_onoff=read_byte(0x01,(objno+0xE2));
                           4775 ;	genPlus
                           4776 ;     genPlusIncr
   0E61 74 E2              4777 	mov	a,#0xE2
                           4778 ;	Peephole 236.a	used r7 instead of ar7
   0E63 2F                 4779 	add	a,r7
   0E64 FD                 4780 	mov	r5,a
                           4781 ;	genIpush
   0E65 C0 03              4782 	push	ar3
   0E67 C0 04              4783 	push	ar4
   0E69 C0 06              4784 	push	ar6
   0E6B C0 07              4785 	push	ar7
   0E6D C0 05              4786 	push	ar5
                           4787 ;	genCall
   0E6F 75 82 01           4788 	mov	dpl,#0x01
   0E72 12 02 CF           4789 	lcall	_read_byte
   0E75 AD 82              4790 	mov	r5,dpl
   0E77 15 81              4791 	dec	sp
   0E79 D0 07              4792 	pop	ar7
   0E7B D0 06              4793 	pop	ar6
   0E7D D0 04              4794 	pop	ar4
   0E7F D0 03              4795 	pop	ar3
                           4796 ;	genAssign
   0E81 8D 02              4797 	mov	ar2,r5
                           4798 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:156: for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
                           4799 ;	genIpop
   0E83 D0 05              4800 	pop	ar5
                           4801 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:206: delay_onoff=read_byte(0x01,(objno+0xE2));
   0E85                    4802 00114$:
                           4803 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:208: if (((read_byte(0x01,RELMODE)>>objno)&0x01)==0x00)
                           4804 ;	genIpush
   0E85 C0 05              4805 	push	ar5
                           4806 ;	genIpush
   0E87 C0 02              4807 	push	ar2
   0E89 C0 03              4808 	push	ar3
   0E8B C0 04              4809 	push	ar4
   0E8D C0 06              4810 	push	ar6
   0E8F C0 07              4811 	push	ar7
   0E91 74 F2              4812 	mov	a,#0xF2
   0E93 C0 E0              4813 	push	acc
                           4814 ;	genCall
   0E95 75 82 01           4815 	mov	dpl,#0x01
   0E98 12 02 CF           4816 	lcall	_read_byte
   0E9B AD 82              4817 	mov	r5,dpl
   0E9D 15 81              4818 	dec	sp
   0E9F D0 07              4819 	pop	ar7
   0EA1 D0 06              4820 	pop	ar6
   0EA3 D0 04              4821 	pop	ar4
   0EA5 D0 03              4822 	pop	ar3
   0EA7 D0 02              4823 	pop	ar2
                           4824 ;	genRightShift
   0EA9 8F F0              4825 	mov	b,r7
   0EAB 05 F0              4826 	inc	b
   0EAD ED                 4827 	mov	a,r5
   0EAE 80 02              4828 	sjmp	00214$
   0EB0                    4829 00213$:
   0EB0 C3                 4830 	clr	c
   0EB1 13                 4831 	rrc	a
   0EB2                    4832 00214$:
   0EB2 D5 F0 FB           4833 	djnz	b,00213$
                           4834 ;	genAnd
   0EB5 54 01              4835 	anl	a,#0x01
                           4836 ;	genIpop
   0EB7 D0 05              4837 	pop	ar5
                           4838 ;	genIfx
                           4839 ;	genIfxJump
                           4840 ;	Peephole 108.b	removed ljmp by inverse jump logic
   0EB9 70 08              4841 	jnz	00116$
                           4842 ;	Peephole 300	removed redundant label 00215$
                           4843 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:210: portbuffer=portbuffer|port_pattern;		// sofort einschalten (Schliesserbetrieb)
                           4844 ;	genOr
   0EBB A8 08              4845 	mov	r0,_bp
   0EBD 08                 4846 	inc	r0
   0EBE E6                 4847 	mov	a,@r0
   0EBF 42 41              4848 	orl	_portbuffer,a
                           4849 ;	Peephole 112.b	changed ljmp to sjmp
   0EC1 80 10              4850 	sjmp	00121$
   0EC3                    4851 00116$:
                           4852 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:214: portbuffer=portbuffer&~port_pattern;		// sofort einschalten (Öffnerbetrieb)
                           4853 ;	genIpush
   0EC3 C0 05              4854 	push	ar5
                           4855 ;	genCpl
   0EC5 A8 08              4856 	mov	r0,_bp
   0EC7 08                 4857 	inc	r0
   0EC8 E6                 4858 	mov	a,@r0
   0EC9 F4                 4859 	cpl	a
                           4860 ;	genAnd
   0ECA FD                 4861 	mov	r5,a
                           4862 ;	Peephole 105	removed redundant mov
   0ECB 52 41              4863 	anl	_portbuffer,a
                           4864 ;	genIpop
   0ECD D0 05              4865 	pop	ar5
                           4866 ;	Peephole 112.b	changed ljmp to sjmp
   0ECF 80 02              4867 	sjmp	00121$
   0ED1                    4868 00119$:
                           4869 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:219: delay_status=0x90;				// verzögert
                           4870 ;	genAssign
   0ED1 7E 90              4871 	mov	r6,#0x90
                           4872 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:223: }
   0ED3                    4873 00121$:
                           4874 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:224: if(delay_status!=0)								// wenn Verzögerung, dann timer-Wert schreiben
                           4875 ;	genCmpEq
                           4876 ;	gencjneshort
   0ED3 BE 00 03           4877 	cjne	r6,#0x00,00216$
   0ED6 02 10 15           4878 	ljmp	00123$
   0ED9                    4879 00216$:
                           4880 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:227: delay_target=delay_onoff;
                           4881 ;	genIpush
   0ED9 C0 05              4882 	push	ar5
                           4883 ;	genCast
   0EDB E5 08              4884 	mov	a,_bp
   0EDD 24 07              4885 	add	a,#0x07
   0EDF F8                 4886 	mov	r0,a
   0EE0 A6 02              4887 	mov	@r0,ar2
   0EE2 08                 4888 	inc	r0
   0EE3 76 00              4889 	mov	@r0,#0x00
   0EE5 08                 4890 	inc	r0
   0EE6 76 00              4891 	mov	@r0,#0x00
   0EE8 08                 4892 	inc	r0
   0EE9 76 00              4893 	mov	@r0,#0x00
                           4894 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:228: delay_target=delay_target<<delay_base;
                           4895 ;	genLeftShift
   0EEB 8C F0              4896 	mov	b,r4
   0EED 05 F0              4897 	inc	b
   0EEF E5 08              4898 	mov	a,_bp
   0EF1 24 07              4899 	add	a,#0x07
   0EF3 F8                 4900 	mov	r0,a
   0EF4 80 13              4901 	sjmp	00218$
   0EF6                    4902 00217$:
   0EF6 E6                 4903 	mov	a,@r0
   0EF7 25 E0              4904 	add	a,acc
   0EF9 F6                 4905 	mov	@r0,a
   0EFA 08                 4906 	inc	r0
   0EFB E6                 4907 	mov	a,@r0
   0EFC 33                 4908 	rlc	a
   0EFD F6                 4909 	mov	@r0,a
   0EFE 08                 4910 	inc	r0
   0EFF E6                 4911 	mov	a,@r0
   0F00 33                 4912 	rlc	a
   0F01 F6                 4913 	mov	@r0,a
   0F02 08                 4914 	inc	r0
   0F03 E6                 4915 	mov	a,@r0
   0F04 33                 4916 	rlc	a
   0F05 F6                 4917 	mov	@r0,a
   0F06 18                 4918 	dec	r0
   0F07 18                 4919 	dec	r0
   0F08 18                 4920 	dec	r0
   0F09                    4921 00218$:
   0F09 D5 F0 EA           4922 	djnz	b,00217$
                           4923 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:229: delay_target+=timer;
                           4924 ;	genPlus
   0F0C E5 08              4925 	mov	a,_bp
   0F0E 24 07              4926 	add	a,#0x07
   0F10 F8                 4927 	mov	r0,a
   0F11 E5 45              4928 	mov	a,_timer
   0F13 26                 4929 	add	a,@r0
   0F14 F6                 4930 	mov	@r0,a
   0F15 E5 46              4931 	mov	a,(_timer + 1)
   0F17 08                 4932 	inc	r0
   0F18 36                 4933 	addc	a,@r0
   0F19 F6                 4934 	mov	@r0,a
   0F1A E5 47              4935 	mov	a,(_timer + 2)
   0F1C 08                 4936 	inc	r0
   0F1D 36                 4937 	addc	a,@r0
   0F1E F6                 4938 	mov	@r0,a
   0F1F E5 48              4939 	mov	a,(_timer + 3)
   0F21 08                 4940 	inc	r0
   0F22 36                 4941 	addc	a,@r0
   0F23 F6                 4942 	mov	@r0,a
                           4943 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:231: start_writecycle();
                           4944 ;	genCall
   0F24 C0 03              4945 	push	ar3
   0F26 C0 05              4946 	push	ar5
   0F28 C0 06              4947 	push	ar6
   0F2A C0 07              4948 	push	ar7
   0F2C 12 02 70           4949 	lcall	_start_writecycle
   0F2F D0 07              4950 	pop	ar7
   0F31 D0 06              4951 	pop	ar6
   0F33 D0 05              4952 	pop	ar5
   0F35 D0 03              4953 	pop	ar3
                           4954 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:232: write_byte(0x00,objno*5,objno+delay_status);
                           4955 ;	genPlus
                           4956 ;	Peephole 236.g	used r6 instead of ar6
   0F37 EE                 4957 	mov	a,r6
                           4958 ;	Peephole 236.a	used r7 instead of ar7
   0F38 2F                 4959 	add	a,r7
   0F39 FA                 4960 	mov	r2,a
                           4961 ;	genMult
                           4962 ;	genMultOneByte
   0F3A EF                 4963 	mov	a,r7
   0F3B 75 F0 05           4964 	mov	b,#0x05
   0F3E A4                 4965 	mul	ab
   0F3F FC                 4966 	mov	r4,a
                           4967 ;	genIpush
   0F40 C0 03              4968 	push	ar3
   0F42 C0 04              4969 	push	ar4
   0F44 C0 05              4970 	push	ar5
   0F46 C0 07              4971 	push	ar7
   0F48 C0 02              4972 	push	ar2
                           4973 ;	genIpush
   0F4A C0 04              4974 	push	ar4
                           4975 ;	genCall
   0F4C 75 82 00           4976 	mov	dpl,#0x00
   0F4F 12 02 78           4977 	lcall	_write_byte
   0F52 15 81              4978 	dec	sp
   0F54 15 81              4979 	dec	sp
   0F56 D0 07              4980 	pop	ar7
   0F58 D0 05              4981 	pop	ar5
   0F5A D0 04              4982 	pop	ar4
   0F5C D0 03              4983 	pop	ar3
                           4984 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:233: write_byte(0x00,1+objno*5,delay_target>>24);
                           4985 ;	genGetByte
   0F5E E5 08              4986 	mov	a,_bp
   0F60 24 07              4987 	add	a,#0x07
                           4988 ;	Peephole 185	changed order of increment (acc incremented also!)
   0F62 04                 4989 	inc	a
                           4990 ;	Peephole 185	changed order of increment (acc incremented also!)
   0F63 04                 4991 	inc	a
                           4992 ;	Peephole 185	changed order of increment (acc incremented also!)
   0F64 04                 4993 	inc	a
   0F65 F8                 4994 	mov	r0,a
   0F66 86 02              4995 	mov	ar2,@r0
                           4996 ;	genPlus
                           4997 ;     genPlusIncr
   0F68 74 01              4998 	mov	a,#0x01
                           4999 ;	Peephole 236.a	used r4 instead of ar4
   0F6A 2C                 5000 	add	a,r4
   0F6B FD                 5001 	mov	r5,a
                           5002 ;	genIpush
   0F6C C0 03              5003 	push	ar3
   0F6E C0 04              5004 	push	ar4
   0F70 C0 05              5005 	push	ar5
   0F72 C0 07              5006 	push	ar7
   0F74 C0 02              5007 	push	ar2
                           5008 ;	genIpush
   0F76 C0 05              5009 	push	ar5
                           5010 ;	genCall
   0F78 75 82 00           5011 	mov	dpl,#0x00
   0F7B 12 02 78           5012 	lcall	_write_byte
   0F7E 15 81              5013 	dec	sp
   0F80 15 81              5014 	dec	sp
   0F82 D0 07              5015 	pop	ar7
   0F84 D0 05              5016 	pop	ar5
   0F86 D0 04              5017 	pop	ar4
   0F88 D0 03              5018 	pop	ar3
                           5019 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:234: write_byte(0x00,2+objno*5,delay_target>>16);
                           5020 ;	genGetByte
   0F8A E5 08              5021 	mov	a,_bp
   0F8C 24 07              5022 	add	a,#0x07
                           5023 ;	Peephole 185	changed order of increment (acc incremented also!)
   0F8E 04                 5024 	inc	a
                           5025 ;	Peephole 185	changed order of increment (acc incremented also!)
   0F8F 04                 5026 	inc	a
   0F90 F8                 5027 	mov	r0,a
   0F91 86 02              5028 	mov	ar2,@r0
                           5029 ;	genPlus
                           5030 ;     genPlusIncr
   0F93 74 02              5031 	mov	a,#0x02
                           5032 ;	Peephole 236.a	used r4 instead of ar4
   0F95 2C                 5033 	add	a,r4
   0F96 FD                 5034 	mov	r5,a
                           5035 ;	genIpush
   0F97 C0 03              5036 	push	ar3
   0F99 C0 04              5037 	push	ar4
   0F9B C0 05              5038 	push	ar5
   0F9D C0 07              5039 	push	ar7
   0F9F C0 02              5040 	push	ar2
                           5041 ;	genIpush
   0FA1 C0 05              5042 	push	ar5
                           5043 ;	genCall
   0FA3 75 82 00           5044 	mov	dpl,#0x00
   0FA6 12 02 78           5045 	lcall	_write_byte
   0FA9 15 81              5046 	dec	sp
   0FAB 15 81              5047 	dec	sp
   0FAD D0 07              5048 	pop	ar7
   0FAF D0 05              5049 	pop	ar5
   0FB1 D0 04              5050 	pop	ar4
   0FB3 D0 03              5051 	pop	ar3
                           5052 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:235: write_byte(0x00,3+objno*5,delay_target>>8);
                           5053 ;	genGetByte
   0FB5 E5 08              5054 	mov	a,_bp
   0FB7 24 07              5055 	add	a,#0x07
                           5056 ;	Peephole 185	changed order of increment (acc incremented also!)
   0FB9 04                 5057 	inc	a
   0FBA F8                 5058 	mov	r0,a
   0FBB 86 02              5059 	mov	ar2,@r0
                           5060 ;	genPlus
                           5061 ;     genPlusIncr
   0FBD 74 03              5062 	mov	a,#0x03
                           5063 ;	Peephole 236.a	used r4 instead of ar4
   0FBF 2C                 5064 	add	a,r4
   0FC0 FD                 5065 	mov	r5,a
                           5066 ;	genIpush
   0FC1 C0 03              5067 	push	ar3
   0FC3 C0 04              5068 	push	ar4
   0FC5 C0 05              5069 	push	ar5
   0FC7 C0 07              5070 	push	ar7
   0FC9 C0 02              5071 	push	ar2
                           5072 ;	genIpush
   0FCB C0 05              5073 	push	ar5
                           5074 ;	genCall
   0FCD 75 82 00           5075 	mov	dpl,#0x00
   0FD0 12 02 78           5076 	lcall	_write_byte
   0FD3 15 81              5077 	dec	sp
   0FD5 15 81              5078 	dec	sp
   0FD7 D0 07              5079 	pop	ar7
   0FD9 D0 05              5080 	pop	ar5
   0FDB D0 04              5081 	pop	ar4
   0FDD D0 03              5082 	pop	ar3
                           5083 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:236: write_byte(0x00,4+objno*5,delay_target);
                           5084 ;	genCast
   0FDF E5 08              5085 	mov	a,_bp
   0FE1 24 07              5086 	add	a,#0x07
   0FE3 F8                 5087 	mov	r0,a
   0FE4 86 02              5088 	mov	ar2,@r0
                           5089 ;	genPlus
                           5090 ;     genPlusIncr
   0FE6 EC                 5091 	mov	a,r4
   0FE7 24 04              5092 	add	a,#0x04
   0FE9 FC                 5093 	mov	r4,a
                           5094 ;	genIpush
   0FEA C0 03              5095 	push	ar3
   0FEC C0 05              5096 	push	ar5
   0FEE C0 07              5097 	push	ar7
   0FF0 C0 02              5098 	push	ar2
                           5099 ;	genIpush
   0FF2 C0 04              5100 	push	ar4
                           5101 ;	genCall
   0FF4 75 82 00           5102 	mov	dpl,#0x00
   0FF7 12 02 78           5103 	lcall	_write_byte
   0FFA 15 81              5104 	dec	sp
   0FFC 15 81              5105 	dec	sp
   0FFE D0 07              5106 	pop	ar7
   1000 D0 05              5107 	pop	ar5
   1002 D0 03              5108 	pop	ar3
                           5109 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:237: stop_writecycle();
                           5110 ;	genCall
   1004 C0 03              5111 	push	ar3
   1006 C0 05              5112 	push	ar5
   1008 C0 07              5113 	push	ar7
   100A 12 02 74           5114 	lcall	_stop_writecycle
   100D D0 07              5115 	pop	ar7
   100F D0 05              5116 	pop	ar5
   1011 D0 03              5117 	pop	ar3
                           5118 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:156: for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
                           5119 ;	genIpop
   1013 D0 05              5120 	pop	ar5
                           5121 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:237: stop_writecycle();
   1015                    5122 00123$:
                           5123 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:239: TH0=0;					// Port-Ausgabe
                           5124 ;	genAssign
   1015 75 8C 00           5125 	mov	_TH0,#0x00
                           5126 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:240: P1_2=1;
                           5127 ;	genAssign
   1018 D2 92              5128 	setb	_P1_2
                           5129 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:241: P0=portbuffer;
                           5130 ;	genAssign
   101A 85 41 80           5131 	mov	_P0,_portbuffer
                           5132 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:242: start_writecycle();	
                           5133 ;	genCall
   101D C0 03              5134 	push	ar3
   101F C0 05              5135 	push	ar5
   1021 C0 07              5136 	push	ar7
   1023 12 02 70           5137 	lcall	_start_writecycle
   1026 D0 07              5138 	pop	ar7
   1028 D0 05              5139 	pop	ar5
   102A D0 03              5140 	pop	ar3
                           5141 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:243: write_byte(0x00,0x29,portbuffer);
                           5142 ;	genIpush
   102C C0 03              5143 	push	ar3
   102E C0 05              5144 	push	ar5
   1030 C0 07              5145 	push	ar7
   1032 C0 41              5146 	push	_portbuffer
                           5147 ;	genIpush
   1034 74 29              5148 	mov	a,#0x29
   1036 C0 E0              5149 	push	acc
                           5150 ;	genCall
   1038 75 82 00           5151 	mov	dpl,#0x00
   103B 12 02 78           5152 	lcall	_write_byte
   103E 15 81              5153 	dec	sp
   1040 15 81              5154 	dec	sp
   1042 D0 07              5155 	pop	ar7
   1044 D0 05              5156 	pop	ar5
   1046 D0 03              5157 	pop	ar3
                           5158 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:244: stop_writecycle();
                           5159 ;	genCall
   1048 C0 03              5160 	push	ar3
   104A C0 05              5161 	push	ar5
   104C C0 07              5162 	push	ar7
   104E 12 02 74           5163 	lcall	_stop_writecycle
   1051 D0 07              5164 	pop	ar7
   1053 D0 05              5165 	pop	ar5
   1055 D0 03              5166 	pop	ar3
                           5167 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:245: TR1=0;					
                           5168 ;	genAssign
   1057 C2 8E              5169 	clr	_TCON_6
                           5170 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:246: TF1=0;
                           5171 ;	genAssign
   1059 C2 8F              5172 	clr	_TCON_7
                           5173 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:247: TH1=0xA0;				// Relais zunächst mit vollem Strom einschalten...
                           5174 ;	genAssign
   105B 75 8D A0           5175 	mov	_TH1,#0xA0
                           5176 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:248: TL1=0x00;				
                           5177 ;	genAssign
   105E 75 8B 00           5178 	mov	_TL1,#0x00
                           5179 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:249: TR1=1;
                           5180 ;	genAssign
   1061 D2 8E              5181 	setb	_TCON_6
                           5182 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:250: while (!TF1);
   1063                    5183 00124$:
                           5184 ;	genIfx
                           5185 ;	genIfxJump
                           5186 ;	Peephole 108.d	removed ljmp by inverse jump logic
   1063 30 8F FD           5187 	jnb	_TCON_7,00124$
                           5188 ;	Peephole 300	removed redundant label 00219$
                           5189 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:251: TR1=0;
                           5190 ;	genAssign
   1066 C2 8E              5191 	clr	_TCON_6
                           5192 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:252: TH0=DUTY;				// ...danach mit PWM halten (min5% von I nominal)
                           5193 ;	genAssign
   1068 75 8C C0           5194 	mov	_TH0,#0xC0
                           5195 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:254: objno+=12;				// Rückmeldeobjekt verarbeiten
                           5196 ;	genPlus
                           5197 ;     genPlusIncr
   106B 74 0C              5198 	mov	a,#0x0C
                           5199 ;	Peephole 236.a	used r7 instead of ar7
   106D 2F                 5200 	add	a,r7
                           5201 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:255: objflags=read_objflags(objno);
                           5202 ;	genCall
   106E FF                 5203 	mov	r7,a
                           5204 ;	Peephole 244.c	loading dpl from a instead of r7
   106F F5 82              5205 	mov	dpl,a
   1071 C0 03              5206 	push	ar3
   1073 C0 05              5207 	push	ar5
   1075 C0 07              5208 	push	ar7
   1077 12 07 44           5209 	lcall	_read_objflags
   107A AA 82              5210 	mov	r2,dpl
   107C D0 07              5211 	pop	ar7
   107E D0 05              5212 	pop	ar5
   1080 D0 03              5213 	pop	ar3
                           5214 ;	genAssign
   1082 A8 08              5215 	mov	r0,_bp
   1084 08                 5216 	inc	r0
   1085 08                 5217 	inc	r0
   1086 A6 02              5218 	mov	@r0,ar2
                           5219 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:256: if ((objflags & 0x04) == 0x04)
                           5220 ;	genAnd
   1088 A8 08              5221 	mov	r0,_bp
   108A 08                 5222 	inc	r0
   108B 08                 5223 	inc	r0
   108C 74 04              5224 	mov	a,#0x04
   108E 56                 5225 	anl	a,@r0
   108F FA                 5226 	mov	r2,a
                           5227 ;	genCmpEq
                           5228 ;	gencjneshort
                           5229 ;	Peephole 112.b	changed ljmp to sjmp
                           5230 ;	Peephole 198.b	optimized misc jump sequence
   1090 BA 04 39           5231 	cjne	r2,#0x04,00134$
                           5232 ;	Peephole 200.b	removed redundant sjmp
                           5233 ;	Peephole 300	removed redundant label 00220$
                           5234 ;	Peephole 300	removed redundant label 00221$
                           5235 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:258: ga=find_ga(objno);
                           5236 ;	genCall
   1093 8F 82              5237 	mov	dpl,r7
   1095 C0 03              5238 	push	ar3
   1097 C0 05              5239 	push	ar5
   1099 12 07 72           5240 	lcall	_find_ga
   109C AA 82              5241 	mov	r2,dpl
   109E AC 83              5242 	mov	r4,dph
   10A0 D0 05              5243 	pop	ar5
   10A2 D0 03              5244 	pop	ar3
                           5245 ;	genAssign
                           5246 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:259: if (ga!=0)
                           5247 ;	genCmpEq
                           5248 ;	gencjneshort
   10A4 BA 00 05           5249 	cjne	r2,#0x00,00222$
   10A7 BC 00 02           5250 	cjne	r4,#0x00,00222$
                           5251 ;	Peephole 112.b	changed ljmp to sjmp
   10AA 80 20              5252 	sjmp	00134$
   10AC                    5253 00222$:
                           5254 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:261: telegramm[0]=0xBC;
                           5255 ;	genPointerSet
                           5256 ;	genNearPointerSet
                           5257 ;	genDataPointerSet
   10AC 75 22 BC           5258 	mov	_telegramm,#0xBC
                           5259 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:262: telegramm[1]=pah;
                           5260 ;	genPointerSet
                           5261 ;	genNearPointerSet
                           5262 ;	genDataPointerSet
   10AF 85 3C 23           5263 	mov	(_telegramm + 0x0001),_pah
                           5264 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:263: telegramm[2]=pal;
                           5265 ;	genPointerSet
                           5266 ;	genNearPointerSet
                           5267 ;	genDataPointerSet
   10B2 85 3B 24           5268 	mov	(_telegramm + 0x0002),_pal
                           5269 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:264: telegramm[3]=(ga>>8);
                           5270 ;	genGetByte
   10B5 8C 06              5271 	mov	ar6,r4
                           5272 ;	genPointerSet
                           5273 ;	genNearPointerSet
                           5274 ;	genDataPointerSet
   10B7 8E 25              5275 	mov	(_telegramm + 0x0003),r6
                           5276 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:265: telegramm[4]=ga;
                           5277 ;	genCast
                           5278 ;	genPointerSet
                           5279 ;	genNearPointerSet
                           5280 ;	genDataPointerSet
   10B9 8A 26              5281 	mov	(_telegramm + 0x0004),r2
                           5282 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:266: telegramm[5]=0xE1;
                           5283 ;	genPointerSet
                           5284 ;	genNearPointerSet
                           5285 ;	genDataPointerSet
   10BB 75 27 E1           5286 	mov	(_telegramm + 0x0005),#0xE1
                           5287 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:267: telegramm[6]=0x00;
                           5288 ;	genPointerSet
                           5289 ;	genNearPointerSet
                           5290 ;	genDataPointerSet
   10BE 75 28 00           5291 	mov	(_telegramm + 0x0006),#0x00
                           5292 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:268: send_telegramm();
                           5293 ;	genCall
   10C1 C0 03              5294 	push	ar3
   10C3 C0 05              5295 	push	ar5
   10C5 12 04 DD           5296 	lcall	_send_telegramm
   10C8 D0 05              5297 	pop	ar5
   10CA D0 03              5298 	pop	ar3
   10CC                    5299 00134$:
                           5300 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:273: if(telegramm[7]==0x00 && (objflags&0x08)==0x08)	// Wert lesen, nur wenn read enable gesetzt (Bit3)
                           5301 ;	genPointerGet
                           5302 ;	genNearPointerGet
                           5303 ;	genDataPointerGet
   10CC E5 29              5304 	mov	a,(_telegramm + 0x0007)
                           5305 ;	genIfx
                           5306 ;	genIfxJump
                           5307 ;	Peephole 108.b	removed ljmp by inverse jump logic
   10CE 70 35              5308 	jnz	00149$
                           5309 ;	Peephole 300	removed redundant label 00223$
                           5310 ;	genAnd
   10D0 A8 08              5311 	mov	r0,_bp
   10D2 08                 5312 	inc	r0
   10D3 08                 5313 	inc	r0
   10D4 74 08              5314 	mov	a,#0x08
   10D6 56                 5315 	anl	a,@r0
   10D7 FA                 5316 	mov	r2,a
                           5317 ;	genCmpEq
                           5318 ;	gencjneshort
                           5319 ;	Peephole 112.b	changed ljmp to sjmp
                           5320 ;	Peephole 198.b	optimized misc jump sequence
   10D8 BA 08 2A           5321 	cjne	r2,#0x08,00149$
                           5322 ;	Peephole 200.b	removed redundant sjmp
                           5323 ;	Peephole 300	removed redundant label 00224$
                           5324 ;	Peephole 300	removed redundant label 00225$
                           5325 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:275: telegramm[0]=0xBC;
                           5326 ;	genPointerSet
                           5327 ;	genNearPointerSet
                           5328 ;	genDataPointerSet
   10DB 75 22 BC           5329 	mov	_telegramm,#0xBC
                           5330 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:276: telegramm[1]=pah;			// Source Adresse
                           5331 ;	genPointerSet
                           5332 ;	genNearPointerSet
                           5333 ;	genDataPointerSet
   10DE 85 3C 23           5334 	mov	(_telegramm + 0x0001),_pah
                           5335 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:277: telegramm[2]=pal;
                           5336 ;	genPointerSet
                           5337 ;	genNearPointerSet
                           5338 ;	genDataPointerSet
   10E1 85 3B 24           5339 	mov	(_telegramm + 0x0002),_pal
                           5340 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:278: telegramm[5]=0xE1;		// DRL
                           5341 ;	genPointerSet
                           5342 ;	genNearPointerSet
                           5343 ;	genDataPointerSet
   10E4 75 27 E1           5344 	mov	(_telegramm + 0x0005),#0xE1
                           5345 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:279: telegramm[6]=0x00;
                           5346 ;	genPointerSet
                           5347 ;	genNearPointerSet
                           5348 ;	genDataPointerSet
   10E7 75 28 00           5349 	mov	(_telegramm + 0x0006),#0x00
                           5350 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:280: if((port_pattern&portbuffer)>0) telegramm[7]=0x41;	// An
                           5351 ;	genAnd
   10EA A8 08              5352 	mov	r0,_bp
   10EC 08                 5353 	inc	r0
   10ED E5 41              5354 	mov	a,_portbuffer
   10EF 56                 5355 	anl	a,@r0
                           5356 ;	genIfx
                           5357 ;	genIfxJump
                           5358 ;	Peephole 108.c	removed ljmp by inverse jump logic
   10F0 60 05              5359 	jz	00136$
                           5360 ;	Peephole 300	removed redundant label 00226$
                           5361 ;	genPointerSet
                           5362 ;	genNearPointerSet
                           5363 ;	genDataPointerSet
   10F2 75 29 41           5364 	mov	(_telegramm + 0x0007),#0x41
                           5365 ;	Peephole 112.b	changed ljmp to sjmp
   10F5 80 03              5366 	sjmp	00137$
   10F7                    5367 00136$:
                           5368 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:281: else telegramm[7]=0x40;					// Aus
                           5369 ;	genPointerSet
                           5370 ;	genNearPointerSet
                           5371 ;	genDataPointerSet
   10F7 75 29 40           5372 	mov	(_telegramm + 0x0007),#0x40
   10FA                    5373 00137$:
                           5374 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:282: send_telegramm();
                           5375 ;	genCall
   10FA C0 03              5376 	push	ar3
   10FC C0 05              5377 	push	ar5
   10FE 12 04 DD           5378 	lcall	_send_telegramm
   1101 D0 05              5379 	pop	ar5
   1103 D0 03              5380 	pop	ar3
   1105                    5381 00149$:
                           5382 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:156: for(n=0;n<assno;n++)				// Schleife über alle Einträge in der Ass-Table, denn es könnten mehrere Objekte (Pins) der gleichen Gruppenadresse zugeordnet sein
                           5383 ;	genPlus
   1105 E5 08              5384 	mov	a,_bp
   1107 24 05              5385 	add	a,#0x05
   1109 F8                 5386 	mov	r0,a
                           5387 ;     genPlusIncr
   110A 06                 5388 	inc	@r0
   110B 02 0C 20           5389 	ljmp	00147$
   110E                    5390 00151$:
   110E 85 08 81           5391 	mov	sp,_bp
   1111 D0 08              5392 	pop	_bp
   1113 22                 5393 	ret
                           5394 ;------------------------------------------------------------
                           5395 ;Allocation info for local variables in function 'delay_timer'
                           5396 ;------------------------------------------------------------
                           5397 ;n                         Allocated to stack - offset 1
                           5398 ;b                         Allocated to registers r4 
                           5399 ;port_pattern              Allocated to registers r2 
                           5400 ;delay_zeit                Allocated to registers r5 
                           5401 ;delay_onoff               Allocated to registers r7 
                           5402 ;delay_base                Allocated to registers r3 
                           5403 ;delval                    Allocated to stack - offset 2
                           5404 ;delay_target              Allocated to stack - offset 6
                           5405 ;sloc0                     Allocated to stack - offset 10
                           5406 ;------------------------------------------------------------
                           5407 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:296: void delay_timer(void)	// zählt alle 130ms die Variable Timer hoch und prüft Queue
                           5408 ;	-----------------------------------------
                           5409 ;	 function delay_timer
                           5410 ;	-----------------------------------------
   1114                    5411 _delay_timer:
   1114 C0 08              5412 	push	_bp
                           5413 ;	peephole 177.h	optimized mov sequence
   1116 E5 81              5414 	mov	a,sp
   1118 F5 08              5415 	mov	_bp,a
   111A 24 0D              5416 	add	a,#0x0d
   111C F5 81              5417 	mov	sp,a
                           5418 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:301: RTCCON=0x60;		// RTC anhalten und Flag löschen
                           5419 ;	genAssign
   111E 75 D1 60           5420 	mov	_RTCCON,#0x60
                           5421 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:302: RTCH=0x1D;		// Real Time Clock
                           5422 ;	genAssign
   1121 75 D2 1D           5423 	mov	_RTCH,#0x1D
                           5424 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:303: RTCL=0x40;
                           5425 ;	genAssign
   1124 75 D3 40           5426 	mov	_RTCL,#0x40
                           5427 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:305: timer++;
                           5428 ;	genPlus
                           5429 ;     genPlusIncr
   1127 05 45              5430 	inc	_timer
   1129 E4                 5431 	clr	a
   112A B5 45 0C           5432 	cjne	a,_timer,00145$
   112D 05 46              5433 	inc	(_timer + 1)
   112F B5 46 07           5434 	cjne	a,(_timer + 1),00145$
   1132 05 47              5435 	inc	(_timer + 2)
   1134 B5 47 02           5436 	cjne	a,(_timer + 2),00145$
   1137 05 48              5437 	inc	(_timer + 3)
   1139                    5438 00145$:
                           5439 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:306: for(n=0;n<=7;n++)
                           5440 ;	genAssign
   1139 A8 08              5441 	mov	r0,_bp
   113B 08                 5442 	inc	r0
   113C 76 00              5443 	mov	@r0,#0x00
   113E                    5444 00125$:
                           5445 ;	genCmpGt
   113E A8 08              5446 	mov	r0,_bp
   1140 08                 5447 	inc	r0
                           5448 ;	genCmp
                           5449 ;	genIfxJump
                           5450 ;	Peephole 132.b	optimized genCmpGt by inverse logic (acc differs)
   1141 E6                 5451 	mov	a,@r0
   1142 24 F8              5452 	add	a,#0xff - 0x07
   1144 50 03              5453 	jnc	00146$
   1146 02 15 46           5454 	ljmp	00128$
   1149                    5455 00146$:
                           5456 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:308: b=read_byte(0x00,n*5);
                           5457 ;	genMult
   1149 A8 08              5458 	mov	r0,_bp
   114B 08                 5459 	inc	r0
                           5460 ;	genMultOneByte
   114C E6                 5461 	mov	a,@r0
   114D 75 F0 05           5462 	mov	b,#0x05
   1150 A4                 5463 	mul	ab
   1151 FB                 5464 	mov	r3,a
                           5465 ;	genIpush
   1152 C0 03              5466 	push	ar3
   1154 C0 03              5467 	push	ar3
                           5468 ;	genCall
   1156 75 82 00           5469 	mov	dpl,#0x00
   1159 12 02 CF           5470 	lcall	_read_byte
   115C AC 82              5471 	mov	r4,dpl
   115E 15 81              5472 	dec	sp
   1160 D0 03              5473 	pop	ar3
                           5474 ;	genAssign
                           5475 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:309: if(b!=0x00)							// 0x00 = queue Eintrag ist leer
                           5476 ;	genCmpEq
                           5477 ;	gencjneshort
   1162 BC 00 03           5478 	cjne	r4,#0x00,00147$
   1165 02 15 3F           5479 	ljmp	00127$
   1168                    5480 00147$:
                           5481 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:311: delval=read_byte(0x00,n*5+1);
                           5482 ;	genIpush
   1168 C0 04              5483 	push	ar4
                           5484 ;	genPlus
                           5485 ;     genPlusIncr
   116A 74 01              5486 	mov	a,#0x01
                           5487 ;	Peephole 236.a	used r3 instead of ar3
   116C 2B                 5488 	add	a,r3
   116D FD                 5489 	mov	r5,a
                           5490 ;	genIpush
   116E C0 03              5491 	push	ar3
   1170 C0 04              5492 	push	ar4
   1172 C0 05              5493 	push	ar5
                           5494 ;	genCall
   1174 75 82 00           5495 	mov	dpl,#0x00
   1177 12 02 CF           5496 	lcall	_read_byte
   117A AD 82              5497 	mov	r5,dpl
   117C 15 81              5498 	dec	sp
   117E D0 04              5499 	pop	ar4
   1180 D0 03              5500 	pop	ar3
                           5501 ;	genCast
   1182 A8 08              5502 	mov	r0,_bp
   1184 08                 5503 	inc	r0
   1185 08                 5504 	inc	r0
   1186 A6 05              5505 	mov	@r0,ar5
   1188 08                 5506 	inc	r0
   1189 76 00              5507 	mov	@r0,#0x00
   118B 08                 5508 	inc	r0
   118C 76 00              5509 	mov	@r0,#0x00
   118E 08                 5510 	inc	r0
   118F 76 00              5511 	mov	@r0,#0x00
                           5512 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:312: delval=(delval<<8)+read_byte(0x00,n*5+2);
                           5513 ;	genLeftShift
                           5514 ;	genLeftShiftLiteral
   1191 A8 08              5515 	mov	r0,_bp
   1193 08                 5516 	inc	r0
   1194 08                 5517 	inc	r0
   1195 E5 08              5518 	mov	a,_bp
   1197 24 0A              5519 	add	a,#0x0a
   1199 F9                 5520 	mov	r1,a
                           5521 ;	genlshFour
   119A 08                 5522 	inc	r0
   119B 08                 5523 	inc	r0
   119C E6                 5524 	mov	a,@r0
   119D 09                 5525 	inc	r1
   119E 09                 5526 	inc	r1
   119F 09                 5527 	inc	r1
   11A0 F7                 5528 	mov	@r1,a
   11A1 18                 5529 	dec	r0
   11A2 E6                 5530 	mov	a,@r0
   11A3 19                 5531 	dec	r1
   11A4 F7                 5532 	mov	@r1,a
   11A5 18                 5533 	dec	r0
   11A6 E6                 5534 	mov	a,@r0
   11A7 19                 5535 	dec	r1
   11A8 F7                 5536 	mov	@r1,a
   11A9 19                 5537 	dec	r1
   11AA 77 00              5538 	mov	@r1,#0x00
                           5539 ;	genPlus
                           5540 ;     genPlusIncr
   11AC 74 02              5541 	mov	a,#0x02
                           5542 ;	Peephole 236.a	used r3 instead of ar3
   11AE 2B                 5543 	add	a,r3
   11AF FA                 5544 	mov	r2,a
                           5545 ;	genIpush
   11B0 C0 03              5546 	push	ar3
   11B2 C0 04              5547 	push	ar4
   11B4 C0 02              5548 	push	ar2
                           5549 ;	genCall
   11B6 75 82 00           5550 	mov	dpl,#0x00
   11B9 12 02 CF           5551 	lcall	_read_byte
   11BC AA 82              5552 	mov	r2,dpl
   11BE 15 81              5553 	dec	sp
   11C0 D0 04              5554 	pop	ar4
   11C2 D0 03              5555 	pop	ar3
                           5556 ;	genCast
                           5557 ;	genCast
                           5558 ;	peephole 177.g	optimized mov sequence
                           5559 ;	Peephole 181	changed mov to clr
   11C4 E4                 5560 	clr	a
   11C5 FC                 5561 	mov	r4,a
   11C6 33                 5562 	rlc	a
   11C7 95 E0              5563 	subb	a,acc
   11C9 FD                 5564 	mov	r5,a
   11CA FE                 5565 	mov	r6,a
                           5566 ;	genPlus
   11CB E5 08              5567 	mov	a,_bp
   11CD 24 0A              5568 	add	a,#0x0a
   11CF F8                 5569 	mov	r0,a
                           5570 ;	Peephole 236.g	used r2 instead of ar2
   11D0 EA                 5571 	mov	a,r2
   11D1 26                 5572 	add	a,@r0
   11D2 FA                 5573 	mov	r2,a
                           5574 ;	Peephole 236.g	used r4 instead of ar4
   11D3 EC                 5575 	mov	a,r4
   11D4 08                 5576 	inc	r0
   11D5 36                 5577 	addc	a,@r0
   11D6 FC                 5578 	mov	r4,a
                           5579 ;	Peephole 236.g	used r5 instead of ar5
   11D7 ED                 5580 	mov	a,r5
   11D8 08                 5581 	inc	r0
   11D9 36                 5582 	addc	a,@r0
   11DA FD                 5583 	mov	r5,a
                           5584 ;	Peephole 236.g	used r6 instead of ar6
   11DB EE                 5585 	mov	a,r6
   11DC 08                 5586 	inc	r0
   11DD 36                 5587 	addc	a,@r0
   11DE FE                 5588 	mov	r6,a
                           5589 ;	genAssign
   11DF A8 08              5590 	mov	r0,_bp
   11E1 08                 5591 	inc	r0
   11E2 08                 5592 	inc	r0
   11E3 A6 02              5593 	mov	@r0,ar2
   11E5 08                 5594 	inc	r0
   11E6 A6 04              5595 	mov	@r0,ar4
   11E8 08                 5596 	inc	r0
   11E9 A6 05              5597 	mov	@r0,ar5
   11EB 08                 5598 	inc	r0
   11EC A6 06              5599 	mov	@r0,ar6
                           5600 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:313: delval=(delval<<8)+read_byte(0x00,n*5+3);
                           5601 ;	genLeftShift
                           5602 ;	genLeftShiftLiteral
   11EE A8 08              5603 	mov	r0,_bp
   11F0 08                 5604 	inc	r0
   11F1 08                 5605 	inc	r0
   11F2 E5 08              5606 	mov	a,_bp
   11F4 24 0A              5607 	add	a,#0x0a
   11F6 F9                 5608 	mov	r1,a
                           5609 ;	genlshFour
   11F7 08                 5610 	inc	r0
   11F8 08                 5611 	inc	r0
   11F9 E6                 5612 	mov	a,@r0
   11FA 09                 5613 	inc	r1
   11FB 09                 5614 	inc	r1
   11FC 09                 5615 	inc	r1
   11FD F7                 5616 	mov	@r1,a
   11FE 18                 5617 	dec	r0
   11FF E6                 5618 	mov	a,@r0
   1200 19                 5619 	dec	r1
   1201 F7                 5620 	mov	@r1,a
   1202 18                 5621 	dec	r0
   1203 E6                 5622 	mov	a,@r0
   1204 19                 5623 	dec	r1
   1205 F7                 5624 	mov	@r1,a
   1206 19                 5625 	dec	r1
   1207 77 00              5626 	mov	@r1,#0x00
                           5627 ;	genPlus
                           5628 ;     genPlusIncr
   1209 74 03              5629 	mov	a,#0x03
                           5630 ;	Peephole 236.a	used r3 instead of ar3
   120B 2B                 5631 	add	a,r3
   120C FF                 5632 	mov	r7,a
                           5633 ;	genIpush
   120D C0 03              5634 	push	ar3
   120F C0 04              5635 	push	ar4
   1211 C0 07              5636 	push	ar7
                           5637 ;	genCall
   1213 75 82 00           5638 	mov	dpl,#0x00
   1216 12 02 CF           5639 	lcall	_read_byte
   1219 AF 82              5640 	mov	r7,dpl
   121B 15 81              5641 	dec	sp
   121D D0 04              5642 	pop	ar4
   121F D0 03              5643 	pop	ar3
                           5644 ;	genCast
                           5645 ;	genCast
                           5646 ;	peephole 177.g	optimized mov sequence
                           5647 ;	Peephole 181	changed mov to clr
   1221 E4                 5648 	clr	a
   1222 FA                 5649 	mov	r2,a
   1223 33                 5650 	rlc	a
   1224 95 E0              5651 	subb	a,acc
   1226 FC                 5652 	mov	r4,a
   1227 FD                 5653 	mov	r5,a
                           5654 ;	genPlus
   1228 E5 08              5655 	mov	a,_bp
   122A 24 0A              5656 	add	a,#0x0a
   122C F8                 5657 	mov	r0,a
                           5658 ;	Peephole 236.g	used r7 instead of ar7
   122D EF                 5659 	mov	a,r7
   122E 26                 5660 	add	a,@r0
   122F FF                 5661 	mov	r7,a
                           5662 ;	Peephole 236.g	used r2 instead of ar2
   1230 EA                 5663 	mov	a,r2
   1231 08                 5664 	inc	r0
   1232 36                 5665 	addc	a,@r0
   1233 FA                 5666 	mov	r2,a
                           5667 ;	Peephole 236.g	used r4 instead of ar4
   1234 EC                 5668 	mov	a,r4
   1235 08                 5669 	inc	r0
   1236 36                 5670 	addc	a,@r0
   1237 FC                 5671 	mov	r4,a
                           5672 ;	Peephole 236.g	used r5 instead of ar5
   1238 ED                 5673 	mov	a,r5
   1239 08                 5674 	inc	r0
   123A 36                 5675 	addc	a,@r0
   123B FD                 5676 	mov	r5,a
                           5677 ;	genAssign
   123C A8 08              5678 	mov	r0,_bp
   123E 08                 5679 	inc	r0
   123F 08                 5680 	inc	r0
   1240 A6 07              5681 	mov	@r0,ar7
   1242 08                 5682 	inc	r0
   1243 A6 02              5683 	mov	@r0,ar2
   1245 08                 5684 	inc	r0
   1246 A6 04              5685 	mov	@r0,ar4
   1248 08                 5686 	inc	r0
   1249 A6 05              5687 	mov	@r0,ar5
                           5688 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:314: delval=(delval<<8)+read_byte(0x00,n*5+4);
                           5689 ;	genLeftShift
                           5690 ;	genLeftShiftLiteral
   124B A8 08              5691 	mov	r0,_bp
   124D 08                 5692 	inc	r0
   124E 08                 5693 	inc	r0
   124F E5 08              5694 	mov	a,_bp
   1251 24 0A              5695 	add	a,#0x0a
   1253 F9                 5696 	mov	r1,a
                           5697 ;	genlshFour
   1254 08                 5698 	inc	r0
   1255 08                 5699 	inc	r0
   1256 E6                 5700 	mov	a,@r0
   1257 09                 5701 	inc	r1
   1258 09                 5702 	inc	r1
   1259 09                 5703 	inc	r1
   125A F7                 5704 	mov	@r1,a
   125B 18                 5705 	dec	r0
   125C E6                 5706 	mov	a,@r0
   125D 19                 5707 	dec	r1
   125E F7                 5708 	mov	@r1,a
   125F 18                 5709 	dec	r0
   1260 E6                 5710 	mov	a,@r0
   1261 19                 5711 	dec	r1
   1262 F7                 5712 	mov	@r1,a
   1263 19                 5713 	dec	r1
   1264 77 00              5714 	mov	@r1,#0x00
                           5715 ;	genPlus
                           5716 ;     genPlusIncr
   1266 EB                 5717 	mov	a,r3
   1267 24 04              5718 	add	a,#0x04
   1269 FB                 5719 	mov	r3,a
                           5720 ;	genIpush
   126A C0 04              5721 	push	ar4
   126C C0 03              5722 	push	ar3
                           5723 ;	genCall
   126E 75 82 00           5724 	mov	dpl,#0x00
   1271 12 02 CF           5725 	lcall	_read_byte
   1274 AB 82              5726 	mov	r3,dpl
   1276 15 81              5727 	dec	sp
   1278 D0 04              5728 	pop	ar4
                           5729 ;	genCast
                           5730 ;	genCast
                           5731 ;	peephole 177.g	optimized mov sequence
                           5732 ;	Peephole 181	changed mov to clr
   127A E4                 5733 	clr	a
   127B FF                 5734 	mov	r7,a
   127C 33                 5735 	rlc	a
   127D 95 E0              5736 	subb	a,acc
   127F FA                 5737 	mov	r2,a
   1280 FC                 5738 	mov	r4,a
                           5739 ;	genPlus
   1281 E5 08              5740 	mov	a,_bp
   1283 24 0A              5741 	add	a,#0x0a
   1285 F8                 5742 	mov	r0,a
                           5743 ;	Peephole 236.g	used r3 instead of ar3
   1286 EB                 5744 	mov	a,r3
   1287 26                 5745 	add	a,@r0
   1288 FB                 5746 	mov	r3,a
                           5747 ;	Peephole 236.g	used r7 instead of ar7
   1289 EF                 5748 	mov	a,r7
   128A 08                 5749 	inc	r0
   128B 36                 5750 	addc	a,@r0
   128C FF                 5751 	mov	r7,a
                           5752 ;	Peephole 236.g	used r2 instead of ar2
   128D EA                 5753 	mov	a,r2
   128E 08                 5754 	inc	r0
   128F 36                 5755 	addc	a,@r0
   1290 FA                 5756 	mov	r2,a
                           5757 ;	Peephole 236.g	used r4 instead of ar4
   1291 EC                 5758 	mov	a,r4
   1292 08                 5759 	inc	r0
   1293 36                 5760 	addc	a,@r0
   1294 FC                 5761 	mov	r4,a
                           5762 ;	genAssign
   1295 A8 08              5763 	mov	r0,_bp
   1297 08                 5764 	inc	r0
   1298 08                 5765 	inc	r0
   1299 A6 03              5766 	mov	@r0,ar3
   129B 08                 5767 	inc	r0
   129C A6 07              5768 	mov	@r0,ar7
   129E 08                 5769 	inc	r0
   129F A6 02              5770 	mov	@r0,ar2
   12A1 08                 5771 	inc	r0
   12A2 A6 04              5772 	mov	@r0,ar4
                           5773 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:315: if(delval==timer)
                           5774 ;	genCmpEq
   12A4 A8 08              5775 	mov	r0,_bp
   12A6 08                 5776 	inc	r0
   12A7 08                 5777 	inc	r0
                           5778 ;	gencjne
                           5779 ;	gencjneshort
   12A8 E6                 5780 	mov	a,@r0
   12A9 B5 45 13           5781 	cjne	a,_timer,00148$
   12AC 08                 5782 	inc	r0
   12AD E6                 5783 	mov	a,@r0
   12AE B5 46 0E           5784 	cjne	a,(_timer + 1),00148$
   12B1 08                 5785 	inc	r0
   12B2 E6                 5786 	mov	a,@r0
   12B3 B5 47 09           5787 	cjne	a,(_timer + 2),00148$
   12B6 08                 5788 	inc	r0
   12B7 E6                 5789 	mov	a,@r0
   12B8 B5 48 04           5790 	cjne	a,(_timer + 3),00148$
   12BB 74 01              5791 	mov	a,#0x01
   12BD 80 01              5792 	sjmp	00149$
   12BF                    5793 00148$:
   12BF E4                 5794 	clr	a
   12C0                    5795 00149$:
                           5796 ;	genIpop
   12C0 D0 04              5797 	pop	ar4
                           5798 ;	genIfx
                           5799 ;	genIfxJump
   12C2 70 03              5800 	jnz	00150$
   12C4 02 15 3F           5801 	ljmp	00127$
   12C7                    5802 00150$:
                           5803 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:317: port_pattern=0x01<<((b&0x0F));
                           5804 ;	genAnd
   12C7 74 0F              5805 	mov	a,#0x0F
   12C9 5C                 5806 	anl	a,r4
   12CA FA                 5807 	mov	r2,a
                           5808 ;	genLeftShift
   12CB 8A F0              5809 	mov	b,r2
   12CD 05 F0              5810 	inc	b
   12CF 74 01              5811 	mov	a,#0x01
   12D1 80 02              5812 	sjmp	00153$
   12D3                    5813 00151$:
   12D3 25 E0              5814 	add	a,acc
   12D5                    5815 00153$:
   12D5 D5 F0 FB           5816 	djnz	b,00151$
   12D8 FA                 5817 	mov	r2,a
                           5818 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:318: if((b&0xF0)==0x90)
                           5819 ;	genAnd
   12D9 74 F0              5820 	mov	a,#0xF0
   12DB 5C                 5821 	anl	a,r4
   12DC FB                 5822 	mov	r3,a
                           5823 ;	genCmpEq
                           5824 ;	gencjneshort
   12DD BB 90 02           5825 	cjne	r3,#0x90,00154$
   12E0 80 03              5826 	sjmp	00155$
   12E2                    5827 00154$:
   12E2 02 14 BE           5828 	ljmp	00116$
   12E5                    5829 00155$:
                           5830 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:320: if (((read_byte(0x01,RELMODE)>>(b&0x0F))&0x01)==0x00)
                           5831 ;	genIpush
   12E5 C0 02              5832 	push	ar2
   12E7 C0 04              5833 	push	ar4
   12E9 74 F2              5834 	mov	a,#0xF2
   12EB C0 E0              5835 	push	acc
                           5836 ;	genCall
   12ED 75 82 01           5837 	mov	dpl,#0x01
   12F0 12 02 CF           5838 	lcall	_read_byte
   12F3 AB 82              5839 	mov	r3,dpl
   12F5 15 81              5840 	dec	sp
   12F7 D0 04              5841 	pop	ar4
   12F9 D0 02              5842 	pop	ar2
                           5843 ;	genAnd
   12FB 74 0F              5844 	mov	a,#0x0F
   12FD 5C                 5845 	anl	a,r4
                           5846 ;	genRightShift
                           5847 ;	Peephole 185	changed order of increment (acc incremented also!)
   12FE 04                 5848 	inc	a
   12FF F5 F0              5849 	mov	b,a
   1301 EB                 5850 	mov	a,r3
   1302 80 02              5851 	sjmp	00157$
   1304                    5852 00156$:
   1304 C3                 5853 	clr	c
   1305 13                 5854 	rrc	a
   1306                    5855 00157$:
   1306 D5 F0 FB           5856 	djnz	b,00156$
                           5857 ;	genAnd
                           5858 ;	genIfxJump
                           5859 ;	Peephole 108.e	removed ljmp by inverse jump logic
   1309 20 E0 05           5860 	jb	acc.0,00102$
                           5861 ;	Peephole 300	removed redundant label 00158$
                           5862 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:322: portbuffer=portbuffer|port_pattern;		// Einschalten (Schliesserbetrieb)
                           5863 ;	genOr
   130C EA                 5864 	mov	a,r2
   130D 42 41              5865 	orl	_portbuffer,a
                           5866 ;	Peephole 112.b	changed ljmp to sjmp
   130F 80 05              5867 	sjmp	00103$
   1311                    5868 00102$:
                           5869 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:326: portbuffer=portbuffer&~port_pattern;	// Einschalten (Öffnerbetrieb)
                           5870 ;	genCpl
   1311 EA                 5871 	mov	a,r2
   1312 F4                 5872 	cpl	a
                           5873 ;	genAnd
   1313 FB                 5874 	mov	r3,a
                           5875 ;	Peephole 105	removed redundant mov
   1314 52 41              5876 	anl	_portbuffer,a
   1316                    5877 00103$:
                           5878 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:328: start_writecycle();
                           5879 ;	genCall
   1316 12 02 70           5880 	lcall	_start_writecycle
                           5881 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:329: write_byte(0x00,n*5,0x00);
                           5882 ;	genMult
   1319 A8 08              5883 	mov	r0,_bp
   131B 08                 5884 	inc	r0
                           5885 ;	genMultOneByte
   131C E6                 5886 	mov	a,@r0
   131D 75 F0 05           5887 	mov	b,#0x05
   1320 A4                 5888 	mul	ab
   1321 FA                 5889 	mov	r2,a
                           5890 ;	genIpush
   1322 C0 02              5891 	push	ar2
                           5892 ;	Peephole 181	changed mov to clr
   1324 E4                 5893 	clr	a
   1325 C0 E0              5894 	push	acc
                           5895 ;	genIpush
   1327 C0 02              5896 	push	ar2
                           5897 ;	genCall
   1329 75 82 00           5898 	mov	dpl,#0x00
   132C 12 02 78           5899 	lcall	_write_byte
   132F 15 81              5900 	dec	sp
   1331 15 81              5901 	dec	sp
   1333 D0 02              5902 	pop	ar2
                           5903 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:330: stop_writecycle();
                           5904 ;	genCall
   1335 C0 02              5905 	push	ar2
   1337 12 02 74           5906 	lcall	_stop_writecycle
   133A D0 02              5907 	pop	ar2
                           5908 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:331: delay_zeit=read_byte(0x01,0xEA);
                           5909 ;	genIpush
   133C C0 02              5910 	push	ar2
   133E 74 EA              5911 	mov	a,#0xEA
   1340 C0 E0              5912 	push	acc
                           5913 ;	genCall
   1342 75 82 01           5914 	mov	dpl,#0x01
   1345 12 02 CF           5915 	lcall	_read_byte
   1348 AD 82              5916 	mov	r5,dpl
   134A 15 81              5917 	dec	sp
   134C D0 02              5918 	pop	ar2
                           5919 ;	genAssign
                           5920 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:332: delay_zeit=((delay_zeit>>n)&0x01);
                           5921 ;	genRightShift
   134E A8 08              5922 	mov	r0,_bp
   1350 08                 5923 	inc	r0
   1351 86 F0              5924 	mov	b,@r0
   1353 05 F0              5925 	inc	b
   1355 ED                 5926 	mov	a,r5
   1356 80 02              5927 	sjmp	00160$
   1358                    5928 00159$:
   1358 C3                 5929 	clr	c
   1359 13                 5930 	rrc	a
   135A                    5931 00160$:
   135A D5 F0 FB           5932 	djnz	b,00159$
   135D FE                 5933 	mov	r6,a
                           5934 ;	genAnd
   135E 74 01              5935 	mov	a,#0x01
   1360 5E                 5936 	anl	a,r6
   1361 FD                 5937 	mov	r5,a
                           5938 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:333: if(delay_zeit==0x01)
                           5939 ;	genCmpEq
                           5940 ;	gencjneshort
   1362 BD 01 02           5941 	cjne	r5,#0x01,00161$
   1365 80 03              5942 	sjmp	00162$
   1367                    5943 00161$:
   1367 02 15 0D           5944 	ljmp	00117$
   136A                    5945 00162$:
                           5946 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:335: delay_base=read_byte(0x01,(((n+1)>>1)+0xF9));   
                           5947 ;	genCast
   136A A8 08              5948 	mov	r0,_bp
   136C 08                 5949 	inc	r0
   136D 86 06              5950 	mov	ar6,@r0
   136F 7F 00              5951 	mov	r7,#0x00
                           5952 ;	genPlus
                           5953 ;     genPlusIncr
   1371 0E                 5954 	inc	r6
   1372 BE 00 01           5955 	cjne	r6,#0x00,00163$
   1375 0F                 5956 	inc	r7
   1376                    5957 00163$:
                           5958 ;	genRightShift
                           5959 ;	genSignedRightShift
                           5960 ;	genRightShiftLiteral
                           5961 ;	genrshTwo
   1376 EF                 5962 	mov	a,r7
   1377 A2 E7              5963 	mov	c,acc.7
   1379 13                 5964 	rrc	a
   137A CE                 5965 	xch	a,r6
   137B 13                 5966 	rrc	a
   137C CE                 5967 	xch	a,r6
   137D FF                 5968 	mov	r7,a
                           5969 ;	genCast
                           5970 ;	genPlus
                           5971 ;     genPlusIncr
   137E 74 F9              5972 	mov	a,#0xF9
                           5973 ;	Peephole 236.a	used r6 instead of ar6
   1380 2E                 5974 	add	a,r6
   1381 FE                 5975 	mov	r6,a
                           5976 ;	genIpush
   1382 C0 02              5977 	push	ar2
   1384 C0 05              5978 	push	ar5
   1386 C0 06              5979 	push	ar6
                           5980 ;	genCall
   1388 75 82 01           5981 	mov	dpl,#0x01
   138B 12 02 CF           5982 	lcall	_read_byte
   138E AE 82              5983 	mov	r6,dpl
   1390 15 81              5984 	dec	sp
   1392 D0 05              5985 	pop	ar5
   1394 D0 02              5986 	pop	ar2
                           5987 ;	genAssign
   1396 8E 03              5988 	mov	ar3,r6
                           5989 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:336: if((n&0x01)==0x01) delay_base&=0x0F;
                           5990 ;	genAnd
   1398 A8 08              5991 	mov	r0,_bp
   139A 08                 5992 	inc	r0
   139B 74 01              5993 	mov	a,#0x01
   139D 56                 5994 	anl	a,@r0
   139E FF                 5995 	mov	r7,a
                           5996 ;	genCmpEq
                           5997 ;	gencjneshort
                           5998 ;	Peephole 112.b	changed ljmp to sjmp
                           5999 ;	Peephole 198.b	optimized misc jump sequence
   139F BF 01 05           6000 	cjne	r7,#0x01,00105$
                           6001 ;	Peephole 200.b	removed redundant sjmp
                           6002 ;	Peephole 300	removed redundant label 00164$
                           6003 ;	Peephole 300	removed redundant label 00165$
                           6004 ;	genAnd
   13A2 53 03 0F           6005 	anl	ar3,#0x0F
                           6006 ;	Peephole 112.b	changed ljmp to sjmp
   13A5 80 08              6007 	sjmp	00106$
   13A7                    6008 00105$:
                           6009 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:337: else delay_base=(delay_base&0xF0)>>4;
                           6010 ;	genAnd
   13A7 74 F0              6011 	mov	a,#0xF0
   13A9 5B                 6012 	anl	a,r3
                           6013 ;	genRightShift
                           6014 ;	genRightShiftLiteral
                           6015 ;	genrshOne
   13AA FF                 6016 	mov	r7,a
                           6017 ;	Peephole 105	removed redundant mov
   13AB C4                 6018 	swap	a
   13AC 54 0F              6019 	anl	a,#0x0f
   13AE FB                 6020 	mov	r3,a
   13AF                    6021 00106$:
                           6022 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:338: delay_onoff=read_byte(0x01,(n+0xE2));
                           6023 ;	genPlus
   13AF A8 08              6024 	mov	r0,_bp
   13B1 08                 6025 	inc	r0
                           6026 ;     genPlusIncr
   13B2 74 E2              6027 	mov	a,#0xE2
   13B4 26                 6028 	add	a,@r0
   13B5 FF                 6029 	mov	r7,a
                           6030 ;	genIpush
   13B6 C0 02              6031 	push	ar2
   13B8 C0 03              6032 	push	ar3
   13BA C0 05              6033 	push	ar5
   13BC C0 07              6034 	push	ar7
                           6035 ;	genCall
   13BE 75 82 01           6036 	mov	dpl,#0x01
   13C1 12 02 CF           6037 	lcall	_read_byte
   13C4 AF 82              6038 	mov	r7,dpl
   13C6 15 81              6039 	dec	sp
   13C8 D0 05              6040 	pop	ar5
   13CA D0 03              6041 	pop	ar3
   13CC D0 02              6042 	pop	ar2
                           6043 ;	genAssign
                           6044 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:339: if (delay_onoff!=0x00 && delay_zeit!=0x00)
                           6045 ;	genCmpEq
                           6046 ;	gencjneshort
   13CE BF 00 03           6047 	cjne	r7,#0x00,00166$
   13D1 02 15 0D           6048 	ljmp	00117$
   13D4                    6049 00166$:
                           6050 ;	genCmpEq
                           6051 ;	gencjneshort
   13D4 BD 00 03           6052 	cjne	r5,#0x00,00167$
   13D7 02 15 0D           6053 	ljmp	00117$
   13DA                    6054 00167$:
                           6055 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:341: delay_target=delay_onoff;
                           6056 ;	genCast
   13DA E5 08              6057 	mov	a,_bp
   13DC 24 06              6058 	add	a,#0x06
   13DE F8                 6059 	mov	r0,a
   13DF A6 07              6060 	mov	@r0,ar7
   13E1 08                 6061 	inc	r0
   13E2 76 00              6062 	mov	@r0,#0x00
   13E4 08                 6063 	inc	r0
   13E5 76 00              6064 	mov	@r0,#0x00
   13E7 08                 6065 	inc	r0
   13E8 76 00              6066 	mov	@r0,#0x00
                           6067 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:342: delay_target=delay_target<<delay_base;
                           6068 ;	genLeftShift
   13EA 8B F0              6069 	mov	b,r3
   13EC 05 F0              6070 	inc	b
   13EE E5 08              6071 	mov	a,_bp
   13F0 24 06              6072 	add	a,#0x06
   13F2 F8                 6073 	mov	r0,a
   13F3 80 13              6074 	sjmp	00169$
   13F5                    6075 00168$:
   13F5 E6                 6076 	mov	a,@r0
   13F6 25 E0              6077 	add	a,acc
   13F8 F6                 6078 	mov	@r0,a
   13F9 08                 6079 	inc	r0
   13FA E6                 6080 	mov	a,@r0
   13FB 33                 6081 	rlc	a
   13FC F6                 6082 	mov	@r0,a
   13FD 08                 6083 	inc	r0
   13FE E6                 6084 	mov	a,@r0
   13FF 33                 6085 	rlc	a
   1400 F6                 6086 	mov	@r0,a
   1401 08                 6087 	inc	r0
   1402 E6                 6088 	mov	a,@r0
   1403 33                 6089 	rlc	a
   1404 F6                 6090 	mov	@r0,a
   1405 18                 6091 	dec	r0
   1406 18                 6092 	dec	r0
   1407 18                 6093 	dec	r0
   1408                    6094 00169$:
   1408 D5 F0 EA           6095 	djnz	b,00168$
                           6096 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:343: delay_target+=timer;  
                           6097 ;	genPlus
   140B E5 08              6098 	mov	a,_bp
   140D 24 06              6099 	add	a,#0x06
   140F F8                 6100 	mov	r0,a
   1410 E5 45              6101 	mov	a,_timer
   1412 26                 6102 	add	a,@r0
   1413 F6                 6103 	mov	@r0,a
   1414 E5 46              6104 	mov	a,(_timer + 1)
   1416 08                 6105 	inc	r0
   1417 36                 6106 	addc	a,@r0
   1418 F6                 6107 	mov	@r0,a
   1419 E5 47              6108 	mov	a,(_timer + 2)
   141B 08                 6109 	inc	r0
   141C 36                 6110 	addc	a,@r0
   141D F6                 6111 	mov	@r0,a
   141E E5 48              6112 	mov	a,(_timer + 3)
   1420 08                 6113 	inc	r0
   1421 36                 6114 	addc	a,@r0
   1422 F6                 6115 	mov	@r0,a
                           6116 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:344: start_writecycle();   
                           6117 ;	genCall
   1423 C0 02              6118 	push	ar2
   1425 12 02 70           6119 	lcall	_start_writecycle
   1428 D0 02              6120 	pop	ar2
                           6121 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:345: write_byte(0x00,n*5,n+0x80);
                           6122 ;	genPlus
   142A A8 08              6123 	mov	r0,_bp
   142C 08                 6124 	inc	r0
                           6125 ;     genPlusIncr
   142D 74 80              6126 	mov	a,#0x80
   142F 26                 6127 	add	a,@r0
   1430 FB                 6128 	mov	r3,a
                           6129 ;	genIpush
   1431 C0 02              6130 	push	ar2
   1433 C0 03              6131 	push	ar3
                           6132 ;	genIpush
   1435 C0 02              6133 	push	ar2
                           6134 ;	genCall
   1437 75 82 00           6135 	mov	dpl,#0x00
   143A 12 02 78           6136 	lcall	_write_byte
   143D 15 81              6137 	dec	sp
   143F 15 81              6138 	dec	sp
   1441 D0 02              6139 	pop	ar2
                           6140 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:346: write_byte(0x00,1+n*5,delay_target>>24);
                           6141 ;	genGetByte
   1443 E5 08              6142 	mov	a,_bp
   1445 24 06              6143 	add	a,#0x06
                           6144 ;	Peephole 185	changed order of increment (acc incremented also!)
   1447 04                 6145 	inc	a
                           6146 ;	Peephole 185	changed order of increment (acc incremented also!)
   1448 04                 6147 	inc	a
                           6148 ;	Peephole 185	changed order of increment (acc incremented also!)
   1449 04                 6149 	inc	a
   144A F8                 6150 	mov	r0,a
   144B 86 03              6151 	mov	ar3,@r0
                           6152 ;	genPlus
                           6153 ;     genPlusIncr
   144D 74 01              6154 	mov	a,#0x01
                           6155 ;	Peephole 236.a	used r2 instead of ar2
   144F 2A                 6156 	add	a,r2
   1450 FD                 6157 	mov	r5,a
                           6158 ;	genIpush
   1451 C0 02              6159 	push	ar2
   1453 C0 03              6160 	push	ar3
                           6161 ;	genIpush
   1455 C0 05              6162 	push	ar5
                           6163 ;	genCall
   1457 75 82 00           6164 	mov	dpl,#0x00
   145A 12 02 78           6165 	lcall	_write_byte
   145D 15 81              6166 	dec	sp
   145F 15 81              6167 	dec	sp
   1461 D0 02              6168 	pop	ar2
                           6169 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:347: write_byte(0x00,2+n*5,delay_target>>16);
                           6170 ;	genGetByte
   1463 E5 08              6171 	mov	a,_bp
   1465 24 06              6172 	add	a,#0x06
                           6173 ;	Peephole 185	changed order of increment (acc incremented also!)
   1467 04                 6174 	inc	a
                           6175 ;	Peephole 185	changed order of increment (acc incremented also!)
   1468 04                 6176 	inc	a
   1469 F8                 6177 	mov	r0,a
   146A 86 03              6178 	mov	ar3,@r0
                           6179 ;	genPlus
                           6180 ;     genPlusIncr
   146C 74 02              6181 	mov	a,#0x02
                           6182 ;	Peephole 236.a	used r2 instead of ar2
   146E 2A                 6183 	add	a,r2
   146F FD                 6184 	mov	r5,a
                           6185 ;	genIpush
   1470 C0 02              6186 	push	ar2
   1472 C0 03              6187 	push	ar3
                           6188 ;	genIpush
   1474 C0 05              6189 	push	ar5
                           6190 ;	genCall
   1476 75 82 00           6191 	mov	dpl,#0x00
   1479 12 02 78           6192 	lcall	_write_byte
   147C 15 81              6193 	dec	sp
   147E 15 81              6194 	dec	sp
   1480 D0 02              6195 	pop	ar2
                           6196 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:348: write_byte(0x00,3+n*5,delay_target>>8);
                           6197 ;	genGetByte
   1482 E5 08              6198 	mov	a,_bp
   1484 24 06              6199 	add	a,#0x06
                           6200 ;	Peephole 185	changed order of increment (acc incremented also!)
   1486 04                 6201 	inc	a
   1487 F8                 6202 	mov	r0,a
   1488 86 03              6203 	mov	ar3,@r0
                           6204 ;	genPlus
                           6205 ;     genPlusIncr
   148A 74 03              6206 	mov	a,#0x03
                           6207 ;	Peephole 236.a	used r2 instead of ar2
   148C 2A                 6208 	add	a,r2
   148D FD                 6209 	mov	r5,a
                           6210 ;	genIpush
   148E C0 02              6211 	push	ar2
   1490 C0 03              6212 	push	ar3
                           6213 ;	genIpush
   1492 C0 05              6214 	push	ar5
                           6215 ;	genCall
   1494 75 82 00           6216 	mov	dpl,#0x00
   1497 12 02 78           6217 	lcall	_write_byte
   149A 15 81              6218 	dec	sp
   149C 15 81              6219 	dec	sp
   149E D0 02              6220 	pop	ar2
                           6221 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:349: write_byte(0x00,4+n*5,delay_target);
                           6222 ;	genCast
   14A0 E5 08              6223 	mov	a,_bp
   14A2 24 06              6224 	add	a,#0x06
   14A4 F8                 6225 	mov	r0,a
   14A5 86 07              6226 	mov	ar7,@r0
                           6227 ;	genPlus
                           6228 ;     genPlusIncr
   14A7 74 04              6229 	mov	a,#0x04
                           6230 ;	Peephole 236.a	used r2 instead of ar2
   14A9 2A                 6231 	add	a,r2
   14AA FB                 6232 	mov	r3,a
                           6233 ;	genIpush
   14AB C0 07              6234 	push	ar7
                           6235 ;	genIpush
   14AD C0 03              6236 	push	ar3
                           6237 ;	genCall
   14AF 75 82 00           6238 	mov	dpl,#0x00
   14B2 12 02 78           6239 	lcall	_write_byte
   14B5 15 81              6240 	dec	sp
   14B7 15 81              6241 	dec	sp
                           6242 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:350: stop_writecycle();
                           6243 ;	genCall
   14B9 12 02 74           6244 	lcall	_stop_writecycle
                           6245 ;	Peephole 112.b	changed ljmp to sjmp
   14BC 80 4F              6246 	sjmp	00117$
   14BE                    6247 00116$:
                           6248 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:356: if (((read_byte(0x01,RELMODE)>>(b&0x0F))&0x01)==0x00)
                           6249 ;	genIpush
   14BE C0 02              6250 	push	ar2
   14C0 C0 04              6251 	push	ar4
   14C2 74 F2              6252 	mov	a,#0xF2
   14C4 C0 E0              6253 	push	acc
                           6254 ;	genCall
   14C6 75 82 01           6255 	mov	dpl,#0x01
   14C9 12 02 CF           6256 	lcall	_read_byte
   14CC AB 82              6257 	mov	r3,dpl
   14CE 15 81              6258 	dec	sp
   14D0 D0 04              6259 	pop	ar4
   14D2 D0 02              6260 	pop	ar2
                           6261 ;	genAnd
   14D4 74 0F              6262 	mov	a,#0x0F
   14D6 5C                 6263 	anl	a,r4
                           6264 ;	genRightShift
                           6265 ;	Peephole 185	changed order of increment (acc incremented also!)
   14D7 04                 6266 	inc	a
   14D8 F5 F0              6267 	mov	b,a
   14DA EB                 6268 	mov	a,r3
   14DB 80 02              6269 	sjmp	00171$
   14DD                    6270 00170$:
   14DD C3                 6271 	clr	c
   14DE 13                 6272 	rrc	a
   14DF                    6273 00171$:
   14DF D5 F0 FB           6274 	djnz	b,00170$
                           6275 ;	genAnd
                           6276 ;	genIfxJump
                           6277 ;	Peephole 108.e	removed ljmp by inverse jump logic
   14E2 20 E0 07           6278 	jb	acc.0,00113$
                           6279 ;	Peephole 300	removed redundant label 00172$
                           6280 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:358: portbuffer=portbuffer&~port_pattern;		// Ausschalten (Schliesserbetrieb)
                           6281 ;	genCpl
   14E5 EA                 6282 	mov	a,r2
   14E6 F4                 6283 	cpl	a
                           6284 ;	genAnd
   14E7 FB                 6285 	mov	r3,a
                           6286 ;	Peephole 105	removed redundant mov
   14E8 52 41              6287 	anl	_portbuffer,a
                           6288 ;	Peephole 112.b	changed ljmp to sjmp
   14EA 80 03              6289 	sjmp	00114$
   14EC                    6290 00113$:
                           6291 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:362: portbuffer=portbuffer|port_pattern;			// Ausschalten (Öffnerbetrieb)
                           6292 ;	genOr
   14EC EA                 6293 	mov	a,r2
   14ED 42 41              6294 	orl	_portbuffer,a
   14EF                    6295 00114$:
                           6296 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:364: start_writecycle();
                           6297 ;	genCall
   14EF 12 02 70           6298 	lcall	_start_writecycle
                           6299 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:365: write_byte(0x00,n*5,0x00);
                           6300 ;	genMult
   14F2 A8 08              6301 	mov	r0,_bp
   14F4 08                 6302 	inc	r0
                           6303 ;	genMultOneByte
   14F5 E6                 6304 	mov	a,@r0
   14F6 75 F0 05           6305 	mov	b,#0x05
   14F9 A4                 6306 	mul	ab
   14FA FA                 6307 	mov	r2,a
                           6308 ;	genIpush
                           6309 ;	Peephole 181	changed mov to clr
   14FB E4                 6310 	clr	a
   14FC C0 E0              6311 	push	acc
                           6312 ;	genIpush
   14FE C0 02              6313 	push	ar2
                           6314 ;	genCall
   1500 75 82 00           6315 	mov	dpl,#0x00
   1503 12 02 78           6316 	lcall	_write_byte
   1506 15 81              6317 	dec	sp
   1508 15 81              6318 	dec	sp
                           6319 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:366: stop_writecycle();
                           6320 ;	genCall
   150A 12 02 74           6321 	lcall	_stop_writecycle
   150D                    6322 00117$:
                           6323 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:368: TH0=0;					// Port-Ausgabe
                           6324 ;	genAssign
   150D 75 8C 00           6325 	mov	_TH0,#0x00
                           6326 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:369: P1_2=1;
                           6327 ;	genAssign
   1510 D2 92              6328 	setb	_P1_2
                           6329 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:370: P0=portbuffer;	
                           6330 ;	genAssign
   1512 85 41 80           6331 	mov	_P0,_portbuffer
                           6332 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:371: start_writecycle();
                           6333 ;	genCall
   1515 12 02 70           6334 	lcall	_start_writecycle
                           6335 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:372: write_byte(0x00,0x29,portbuffer);
                           6336 ;	genIpush
   1518 C0 41              6337 	push	_portbuffer
                           6338 ;	genIpush
   151A 74 29              6339 	mov	a,#0x29
   151C C0 E0              6340 	push	acc
                           6341 ;	genCall
   151E 75 82 00           6342 	mov	dpl,#0x00
   1521 12 02 78           6343 	lcall	_write_byte
   1524 15 81              6344 	dec	sp
   1526 15 81              6345 	dec	sp
                           6346 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:373: stop_writecycle();
                           6347 ;	genCall
   1528 12 02 74           6348 	lcall	_stop_writecycle
                           6349 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:374: TR1=0;					
                           6350 ;	genAssign
   152B C2 8E              6351 	clr	_TCON_6
                           6352 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:375: TF1=0;
                           6353 ;	genAssign
   152D C2 8F              6354 	clr	_TCON_7
                           6355 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:376: TH1=0xA0;				// Relais zunächst mit vollem Strom einschalten...
                           6356 ;	genAssign
   152F 75 8D A0           6357 	mov	_TH1,#0xA0
                           6358 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:377: TL1=0x00;				
                           6359 ;	genAssign
   1532 75 8B 00           6360 	mov	_TL1,#0x00
                           6361 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:378: TR1=1;
                           6362 ;	genAssign
   1535 D2 8E              6363 	setb	_TCON_6
                           6364 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:379: while (!TF1);
   1537                    6365 00118$:
                           6366 ;	genIfx
                           6367 ;	genIfxJump
                           6368 ;	Peephole 108.d	removed ljmp by inverse jump logic
   1537 30 8F FD           6369 	jnb	_TCON_7,00118$
                           6370 ;	Peephole 300	removed redundant label 00173$
                           6371 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:380: TR1=0;
                           6372 ;	genAssign
   153A C2 8E              6373 	clr	_TCON_6
                           6374 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:381: TH0=DUTY;				// ...danach mit PWM halten (min5% von I nominal)    
                           6375 ;	genAssign
   153C 75 8C C0           6376 	mov	_TH0,#0xC0
   153F                    6377 00127$:
                           6378 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:306: for(n=0;n<=7;n++)
                           6379 ;	genPlus
   153F A8 08              6380 	mov	r0,_bp
   1541 08                 6381 	inc	r0
                           6382 ;     genPlusIncr
   1542 06                 6383 	inc	@r0
   1543 02 11 3E           6384 	ljmp	00125$
   1546                    6385 00128$:
                           6386 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:387: RTCCON=0x61;		// RTC starten
                           6387 ;	genAssign
   1546 75 D1 61           6388 	mov	_RTCCON,#0x61
                           6389 ;	Peephole 300	removed redundant label 00129$
   1549 85 08 81           6390 	mov	sp,_bp
   154C D0 08              6391 	pop	_bp
   154E 22                 6392 	ret
                           6393 ;------------------------------------------------------------
                           6394 ;Allocation info for local variables in function 'restart_app'
                           6395 ;------------------------------------------------------------
                           6396 ;bw                        Allocated to registers r2 
                           6397 ;bwh                       Allocated to registers r4 
                           6398 ;n                         Allocated to registers r3 
                           6399 ;------------------------------------------------------------
                           6400 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:391: void restart_app(void)		// Alle Applikations-Parameter zurücksetzen
                           6401 ;	-----------------------------------------
                           6402 ;	 function restart_app
                           6403 ;	-----------------------------------------
   154F                    6404 _restart_app:
                           6405 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:396: portbuffer=read_byte(0x00,0x29);	// Verhalten nach Busspannungs-Wiederkehr
                           6406 ;	genIpush
   154F 74 29              6407 	mov	a,#0x29
   1551 C0 E0              6408 	push	acc
                           6409 ;	genCall
   1553 75 82 00           6410 	mov	dpl,#0x00
   1556 12 02 CF           6411 	lcall	_read_byte
   1559 85 82 41           6412 	mov	_portbuffer,dpl
   155C 15 81              6413 	dec	sp
                           6414 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:397: bw=read_byte(0x01,0xF6);
                           6415 ;	genIpush
   155E 74 F6              6416 	mov	a,#0xF6
   1560 C0 E0              6417 	push	acc
                           6418 ;	genCall
   1562 75 82 01           6419 	mov	dpl,#0x01
   1565 12 02 CF           6420 	lcall	_read_byte
   1568 AA 82              6421 	mov	r2,dpl
   156A 15 81              6422 	dec	sp
                           6423 ;	genAssign
                           6424 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:398: for(n=0;n<=3;n++)			// Ausgänge 1-4
                           6425 ;	genAssign
   156C 7B 00              6426 	mov	r3,#0x00
   156E                    6427 00109$:
                           6428 ;	genCmpGt
                           6429 ;	genCmp
                           6430 ;	genIfxJump
                           6431 ;	Peephole 132.b	optimized genCmpGt by inverse logic (acc differs)
   156E EB                 6432 	mov	a,r3
   156F 24 FC              6433 	add	a,#0xff - 0x03
                           6434 ;	Peephole 112.b	changed ljmp to sjmp
                           6435 ;	Peephole 160.a	removed sjmp by inverse jump logic
   1571 40 45              6436 	jc	00112$
                           6437 ;	Peephole 300	removed redundant label 00129$
                           6438 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:400: bwh=(bw>>(2*n))&0x03; 
                           6439 ;	genMult
                           6440 ;	genMultOneByte
   1573 EB                 6441 	mov	a,r3
   1574 75 F0 02           6442 	mov	b,#0x02
   1577 A4                 6443 	mul	ab
   1578 FC                 6444 	mov	r4,a
   1579 AD F0              6445 	mov	r5,b
                           6446 ;	genRightShift
   157B 8C F0              6447 	mov	b,r4
   157D 05 F0              6448 	inc	b
   157F EA                 6449 	mov	a,r2
   1580 80 02              6450 	sjmp	00131$
   1582                    6451 00130$:
   1582 C3                 6452 	clr	c
   1583 13                 6453 	rrc	a
   1584                    6454 00131$:
   1584 D5 F0 FB           6455 	djnz	b,00130$
   1587 FC                 6456 	mov	r4,a
                           6457 ;	genAnd
   1588 53 04 03           6458 	anl	ar4,#0x03
                           6459 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:401: if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<n));
                           6460 ;	genCmpEq
                           6461 ;	gencjneshort
                           6462 ;	Peephole 112.b	changed ljmp to sjmp
                           6463 ;	Peephole 198.b	optimized misc jump sequence
   158B BC 01 14           6464 	cjne	r4,#0x01,00102$
                           6465 ;	Peephole 200.b	removed redundant sjmp
                           6466 ;	Peephole 300	removed redundant label 00132$
                           6467 ;	Peephole 300	removed redundant label 00133$
                           6468 ;	genLeftShift
   158E 8B F0              6469 	mov	b,r3
   1590 05 F0              6470 	inc	b
   1592 74 01              6471 	mov	a,#0x01
   1594 80 02              6472 	sjmp	00136$
   1596                    6473 00134$:
   1596 25 E0              6474 	add	a,acc
   1598                    6475 00136$:
   1598 D5 F0 FB           6476 	djnz	b,00134$
   159B FD                 6477 	mov	r5,a
                           6478 ;	genMinus
   159C 74 FF              6479 	mov	a,#0xFF
   159E C3                 6480 	clr	c
                           6481 ;	Peephole 236.l	used r5 instead of ar5
   159F 9D                 6482 	subb	a,r5
                           6483 ;	genAnd
   15A0 52 41              6484 	anl	_portbuffer,a
   15A2                    6485 00102$:
                           6486 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:402: if(bwh==0x02)  portbuffer=portbuffer | (0x01<<n);
                           6487 ;	genCmpEq
                           6488 ;	gencjneshort
                           6489 ;	Peephole 112.b	changed ljmp to sjmp
                           6490 ;	Peephole 198.b	optimized misc jump sequence
   15A2 BC 02 10           6491 	cjne	r4,#0x02,00111$
                           6492 ;	Peephole 200.b	removed redundant sjmp
                           6493 ;	Peephole 300	removed redundant label 00137$
                           6494 ;	Peephole 300	removed redundant label 00138$
                           6495 ;	genLeftShift
   15A5 8B F0              6496 	mov	b,r3
   15A7 05 F0              6497 	inc	b
   15A9 74 01              6498 	mov	a,#0x01
   15AB 80 02              6499 	sjmp	00141$
   15AD                    6500 00139$:
   15AD 25 E0              6501 	add	a,acc
   15AF                    6502 00141$:
   15AF D5 F0 FB           6503 	djnz	b,00139$
                           6504 ;	genOr
   15B2 FD                 6505 	mov	r5,a
                           6506 ;	Peephole 105	removed redundant mov
   15B3 42 41              6507 	orl	_portbuffer,a
   15B5                    6508 00111$:
                           6509 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:398: for(n=0;n<=3;n++)			// Ausgänge 1-4
                           6510 ;	genPlus
                           6511 ;     genPlusIncr
   15B5 0B                 6512 	inc	r3
                           6513 ;	Peephole 112.b	changed ljmp to sjmp
   15B6 80 B6              6514 	sjmp	00109$
   15B8                    6515 00112$:
                           6516 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:404: bw=read_byte(0x01,0xF7);
                           6517 ;	genIpush
   15B8 74 F7              6518 	mov	a,#0xF7
   15BA C0 E0              6519 	push	acc
                           6520 ;	genCall
   15BC 75 82 01           6521 	mov	dpl,#0x01
   15BF 12 02 CF           6522 	lcall	_read_byte
   15C2 AB 82              6523 	mov	r3,dpl
   15C4 15 81              6524 	dec	sp
                           6525 ;	genAssign
   15C6 8B 02              6526 	mov	ar2,r3
                           6527 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:405: for(n=0;n<=3;n++)			// Ausgänge 5-8
                           6528 ;	genAssign
   15C8 7B 00              6529 	mov	r3,#0x00
   15CA                    6530 00113$:
                           6531 ;	genCmpGt
                           6532 ;	genCmp
                           6533 ;	genIfxJump
                           6534 ;	Peephole 132.b	optimized genCmpGt by inverse logic (acc differs)
   15CA EB                 6535 	mov	a,r3
   15CB 24 FC              6536 	add	a,#0xff - 0x03
   15CD 50 03              6537 	jnc	00142$
   15CF 02 16 3F           6538 	ljmp	00116$
   15D2                    6539 00142$:
                           6540 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:407: bwh=(bw>>(2*n))&0x03; 
                           6541 ;	genMult
                           6542 ;	genMultOneByte
   15D2 EB                 6543 	mov	a,r3
   15D3 75 F0 02           6544 	mov	b,#0x02
   15D6 A4                 6545 	mul	ab
   15D7 FD                 6546 	mov	r5,a
   15D8 AE F0              6547 	mov	r6,b
                           6548 ;	genRightShift
   15DA 8D F0              6549 	mov	b,r5
   15DC 05 F0              6550 	inc	b
   15DE EA                 6551 	mov	a,r2
   15DF 80 02              6552 	sjmp	00144$
   15E1                    6553 00143$:
   15E1 C3                 6554 	clr	c
   15E2 13                 6555 	rrc	a
   15E3                    6556 00144$:
   15E3 D5 F0 FB           6557 	djnz	b,00143$
   15E6 FD                 6558 	mov	r5,a
                           6559 ;	genAnd
   15E7 74 03              6560 	mov	a,#0x03
   15E9 5D                 6561 	anl	a,r5
   15EA FC                 6562 	mov	r4,a
                           6563 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:408: if(bwh==0x01)  portbuffer=portbuffer & (0xFF-(0x01<<(n+4)));
                           6564 ;	genCmpEq
                           6565 ;	gencjneshort
                           6566 ;	Peephole 112.b	changed ljmp to sjmp
                           6567 ;	Peephole 198.b	optimized misc jump sequence
   15EB BC 01 29           6568 	cjne	r4,#0x01,00106$
                           6569 ;	Peephole 200.b	removed redundant sjmp
                           6570 ;	Peephole 300	removed redundant label 00145$
                           6571 ;	Peephole 300	removed redundant label 00146$
                           6572 ;	genCast
   15EE 8B 05              6573 	mov	ar5,r3
   15F0 7E 00              6574 	mov	r6,#0x00
                           6575 ;	genPlus
                           6576 ;     genPlusIncr
   15F2 74 04              6577 	mov	a,#0x04
                           6578 ;	Peephole 236.a	used r5 instead of ar5
   15F4 2D                 6579 	add	a,r5
   15F5 FD                 6580 	mov	r5,a
                           6581 ;	Peephole 181	changed mov to clr
   15F6 E4                 6582 	clr	a
                           6583 ;	Peephole 236.b	used r6 instead of ar6
   15F7 3E                 6584 	addc	a,r6
   15F8 FE                 6585 	mov	r6,a
                           6586 ;	genLeftShift
   15F9 8D F0              6587 	mov	b,r5
   15FB 05 F0              6588 	inc	b
   15FD 7D 01              6589 	mov	r5,#0x01
   15FF 7E 00              6590 	mov	r6,#0x00
   1601 80 06              6591 	sjmp	00148$
   1603                    6592 00147$:
   1603 ED                 6593 	mov	a,r5
                           6594 ;	Peephole 254	optimized left shift
   1604 2D                 6595 	add	a,r5
   1605 FD                 6596 	mov	r5,a
   1606 EE                 6597 	mov	a,r6
   1607 33                 6598 	rlc	a
   1608 FE                 6599 	mov	r6,a
   1609                    6600 00148$:
   1609 D5 F0 F7           6601 	djnz	b,00147$
                           6602 ;	genMinus
   160C 74 FF              6603 	mov	a,#0xFF
   160E C3                 6604 	clr	c
                           6605 ;	Peephole 236.l	used r5 instead of ar5
   160F 9D                 6606 	subb	a,r5
   1610 FD                 6607 	mov	r5,a
                           6608 ;	Peephole 181	changed mov to clr
   1611 E4                 6609 	clr	a
                           6610 ;	Peephole 236.l	used r6 instead of ar6
   1612 9E                 6611 	subb	a,r6
   1613 FE                 6612 	mov	r6,a
                           6613 ;	genCast
                           6614 ;	genAnd
   1614 ED                 6615 	mov	a,r5
   1615 52 41              6616 	anl	_portbuffer,a
   1617                    6617 00106$:
                           6618 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:409: if(bwh==0x02)  portbuffer=portbuffer | (0x01<<(n+4));
                           6619 ;	genCmpEq
                           6620 ;	gencjneshort
                           6621 ;	Peephole 112.b	changed ljmp to sjmp
                           6622 ;	Peephole 198.b	optimized misc jump sequence
   1617 BC 02 21           6623 	cjne	r4,#0x02,00115$
                           6624 ;	Peephole 200.b	removed redundant sjmp
                           6625 ;	Peephole 300	removed redundant label 00149$
                           6626 ;	Peephole 300	removed redundant label 00150$
                           6627 ;	genCast
   161A 8B 04              6628 	mov	ar4,r3
   161C 7D 00              6629 	mov	r5,#0x00
                           6630 ;	genPlus
                           6631 ;     genPlusIncr
   161E 74 04              6632 	mov	a,#0x04
                           6633 ;	Peephole 236.a	used r4 instead of ar4
   1620 2C                 6634 	add	a,r4
   1621 FC                 6635 	mov	r4,a
                           6636 ;	Peephole 181	changed mov to clr
   1622 E4                 6637 	clr	a
                           6638 ;	Peephole 236.b	used r5 instead of ar5
   1623 3D                 6639 	addc	a,r5
   1624 FD                 6640 	mov	r5,a
                           6641 ;	genLeftShift
   1625 8C F0              6642 	mov	b,r4
   1627 05 F0              6643 	inc	b
   1629 7C 01              6644 	mov	r4,#0x01
   162B 7D 00              6645 	mov	r5,#0x00
   162D 80 06              6646 	sjmp	00152$
   162F                    6647 00151$:
   162F EC                 6648 	mov	a,r4
                           6649 ;	Peephole 254	optimized left shift
   1630 2C                 6650 	add	a,r4
   1631 FC                 6651 	mov	r4,a
   1632 ED                 6652 	mov	a,r5
   1633 33                 6653 	rlc	a
   1634 FD                 6654 	mov	r5,a
   1635                    6655 00152$:
   1635 D5 F0 F7           6656 	djnz	b,00151$
                           6657 ;	genCast
                           6658 ;	genOr
   1638 EC                 6659 	mov	a,r4
   1639 42 41              6660 	orl	_portbuffer,a
   163B                    6661 00115$:
                           6662 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:405: for(n=0;n<=3;n++)			// Ausgänge 5-8
                           6663 ;	genPlus
                           6664 ;     genPlusIncr
   163B 0B                 6665 	inc	r3
   163C 02 15 CA           6666 	ljmp	00113$
   163F                    6667 00116$:
                           6668 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:411: P0=portbuffer;
                           6669 ;	genAssign
   163F 85 41 80           6670 	mov	_P0,_portbuffer
                           6671 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:412: objstate=portbuffer<<8;
                           6672 ;	genCast
   1642 AA 41              6673 	mov	r2,_portbuffer
   1644 7B 00              6674 	mov	r3,#0x00
                           6675 ;	genLeftShift
                           6676 ;	genLeftShiftLiteral
                           6677 ;	genlshTwo
   1646 8A 44              6678 	mov	(_objstate + 1),r2
   1648 75 43 00           6679 	mov	_objstate,#0x00
                           6680 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:413: objstate+=portbuffer;
                           6681 ;	genPlus
                           6682 ;	Peephole 236.g	used r2 instead of ar2
   164B EA                 6683 	mov	a,r2
   164C 25 43              6684 	add	a,_objstate
   164E F5 43              6685 	mov	_objstate,a
                           6686 ;	Peephole 236.g	used r3 instead of ar3
   1650 EB                 6687 	mov	a,r3
   1651 35 44              6688 	addc	a,(_objstate + 1)
   1653 F5 44              6689 	mov	(_objstate + 1),a
                           6690 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:414: start_writecycle();
                           6691 ;	genCall
   1655 12 02 70           6692 	lcall	_start_writecycle
                           6693 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:415: write_byte(0x00,0x29,portbuffer);
                           6694 ;	genIpush
   1658 C0 41              6695 	push	_portbuffer
                           6696 ;	genIpush
   165A 74 29              6697 	mov	a,#0x29
   165C C0 E0              6698 	push	acc
                           6699 ;	genCall
   165E 75 82 00           6700 	mov	dpl,#0x00
   1661 12 02 78           6701 	lcall	_write_byte
   1664 15 81              6702 	dec	sp
   1666 15 81              6703 	dec	sp
                           6704 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:416: stop_writecycle();
                           6705 ;	genCall
   1668 12 02 74           6706 	lcall	_stop_writecycle
                           6707 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:418: pdir=0xFF;		// Port-Direction - wenn Bit=1 darf entsprechender Portpin beschrieben werden (Ausgang), sonst nicht (Eingang)
                           6708 ;	genAssign
   166B 75 49 FF           6709 	mov	_pdir,#0xFF
                           6710 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:420: timer=0;		// Timer-Variable, wird alle 135us inkrementiert
                           6711 ;	genAssign
   166E E4                 6712 	clr	a
   166F F5 45              6713 	mov	_timer,a
   1671 F5 46              6714 	mov	(_timer + 1),a
   1673 F5 47              6715 	mov	(_timer + 2),a
   1675 F5 48              6716 	mov	(_timer + 3),a
                           6717 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:422: start_writecycle();
                           6718 ;	genCall
   1677 12 02 70           6719 	lcall	_start_writecycle
                           6720 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:423: write_byte(0x01,0x04,0x04);	// Herstellercode 0x04 = Jung
                           6721 ;	genIpush
   167A 74 04              6722 	mov	a,#0x04
   167C C0 E0              6723 	push	acc
                           6724 ;	genIpush
   167E 74 04              6725 	mov	a,#0x04
   1680 C0 E0              6726 	push	acc
                           6727 ;	genCall
   1682 75 82 01           6728 	mov	dpl,#0x01
   1685 12 02 78           6729 	lcall	_write_byte
   1688 15 81              6730 	dec	sp
   168A 15 81              6731 	dec	sp
                           6732 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:424: write_byte(0x01,0x05,0x70);	// Geräte Typ (2118) 7054h
                           6733 ;	genIpush
   168C 74 70              6734 	mov	a,#0x70
   168E C0 E0              6735 	push	acc
                           6736 ;	genIpush
   1690 74 05              6737 	mov	a,#0x05
   1692 C0 E0              6738 	push	acc
                           6739 ;	genCall
   1694 75 82 01           6740 	mov	dpl,#0x01
   1697 12 02 78           6741 	lcall	_write_byte
   169A 15 81              6742 	dec	sp
   169C 15 81              6743 	dec	sp
                           6744 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:425: write_byte(0x01,0x06,0x54);  // 	"	"	"
                           6745 ;	genIpush
   169E 74 54              6746 	mov	a,#0x54
   16A0 C0 E0              6747 	push	acc
                           6748 ;	genIpush
   16A2 74 06              6749 	mov	a,#0x06
   16A4 C0 E0              6750 	push	acc
                           6751 ;	genCall
   16A6 75 82 01           6752 	mov	dpl,#0x01
   16A9 12 02 78           6753 	lcall	_write_byte
   16AC 15 81              6754 	dec	sp
   16AE 15 81              6755 	dec	sp
                           6756 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:426: write_byte(0x01,0x07,0x02);	// Versionsnummer
                           6757 ;	genIpush
   16B0 74 02              6758 	mov	a,#0x02
   16B2 C0 E0              6759 	push	acc
                           6760 ;	genIpush
   16B4 74 07              6761 	mov	a,#0x07
   16B6 C0 E0              6762 	push	acc
                           6763 ;	genCall
   16B8 75 82 01           6764 	mov	dpl,#0x01
   16BB 12 02 78           6765 	lcall	_write_byte
   16BE 15 81              6766 	dec	sp
   16C0 15 81              6767 	dec	sp
                           6768 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:427: write_byte(0x01,0x0D,0xFF);	// Run-Status (00=stop FF=run)
                           6769 ;	genIpush
   16C2 74 FF              6770 	mov	a,#0xFF
   16C4 C0 E0              6771 	push	acc
                           6772 ;	genIpush
   16C6 74 0D              6773 	mov	a,#0x0D
   16C8 C0 E0              6774 	push	acc
                           6775 ;	genCall
   16CA 75 82 01           6776 	mov	dpl,#0x01
   16CD 12 02 78           6777 	lcall	_write_byte
   16D0 15 81              6778 	dec	sp
   16D2 15 81              6779 	dec	sp
                           6780 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:428: write_byte(0x01,0x12,0x84);	// COMMSTAB Pointer
                           6781 ;	genIpush
   16D4 74 84              6782 	mov	a,#0x84
   16D6 C0 E0              6783 	push	acc
                           6784 ;	genIpush
   16D8 74 12              6785 	mov	a,#0x12
   16DA C0 E0              6786 	push	acc
                           6787 ;	genCall
   16DC 75 82 01           6788 	mov	dpl,#0x01
   16DF 12 02 78           6789 	lcall	_write_byte
   16E2 15 81              6790 	dec	sp
   16E4 15 81              6791 	dec	sp
                           6792 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_app_in8.c:429: stop_writecycle();
                           6793 ;	genCall
                           6794 ;	Peephole 253.b	replaced lcall/ret with ljmp
   16E6 02 02 74           6795 	ljmp	_stop_writecycle
                           6796 ;
                           6797 ;------------------------------------------------------------
                           6798 ;Allocation info for local variables in function 'main'
                           6799 ;------------------------------------------------------------
                           6800 ;n                         Allocated to registers r2 
                           6801 ;------------------------------------------------------------
                           6802 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:16: void main(void)
                           6803 ;	-----------------------------------------
                           6804 ;	 function main
                           6805 ;	-----------------------------------------
   16E9                    6806 _main:
                           6807 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:21: restart_hw();				// Hardware zurücksetzen
                           6808 ;	genCall
   16E9 12 02 F8           6809 	lcall	_restart_hw
                           6810 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:22: restart_prot();			// Protokoll-relevante Parameter zurücksetzen
                           6811 ;	genCall
   16EC 12 09 99           6812 	lcall	_restart_prot
                           6813 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:23: restart_app();			// Anwendungsspezifische Einstellungen zurücksetzen
                           6814 ;	genCall
   16EF 12 15 4F           6815 	lcall	_restart_app
                           6816 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:24: portbuffer=0xFF;
                           6817 ;	genAssign
   16F2 75 41 FF           6818 	mov	_portbuffer,#0xFF
                           6819 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:26: do  {
   16F5                    6820 00112$:
                           6821 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:28: if(RTCCON>=0x80) delay_timer();	// Verzögerungs-Timer alle 130ms hochzählen
                           6822 ;	genCmpLt
                           6823 ;	genCmp
                           6824 ;	genIfxJump
                           6825 ;	Peephole 132.e	optimized genCmpLt by inverse logic (carry differs)
   16F5 74 80              6826 	mov	a,#0x100 - 0x80
   16F7 25 D1              6827 	add	a,_RTCCON
                           6828 ;	Peephole 112.b	changed ljmp to sjmp
                           6829 ;	Peephole 160.b	removed sjmp by inverse jump logic
   16F9 50 03              6830 	jnc	00102$
                           6831 ;	Peephole 300	removed redundant label 00143$
                           6832 ;	genCall
   16FB 12 11 14           6833 	lcall	_delay_timer
   16FE                    6834 00102$:
                           6835 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:30: p0h=P0;				// prüfen ob ein Eingang sich geändert hat
                           6836 ;	genAssign
                           6837 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:31: if (p0h!=portbuffer) 
                           6838 ;	genCmpEq
                           6839 ;	gencjneshort
                           6840 ;	peephole 177.g	optimized mov sequence
   16FE E5 80              6841 	mov	a,_P0
   1700 F5 42              6842 	mov	_p0h,a
   1702 B5 41 02           6843 	cjne	a,_portbuffer,00144$
                           6844 ;	Peephole 112.b	changed ljmp to sjmp
   1705 80 3C              6845 	sjmp	00106$
   1707                    6846 00144$:
                           6847 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:33: for(n=0;n<8;n++)					// jeden Eingangspin einzel prüfen
                           6848 ;	genAssign
   1707 7A 00              6849 	mov	r2,#0x00
   1709                    6850 00115$:
                           6851 ;	genCmpLt
                           6852 ;	genCmp
   1709 BA 08 00           6853 	cjne	r2,#0x08,00145$
   170C                    6854 00145$:
                           6855 ;	genIfxJump
                           6856 ;	Peephole 108.a	removed ljmp by inverse jump logic
   170C 50 32              6857 	jnc	00118$
                           6858 ;	Peephole 300	removed redundant label 00146$
                           6859 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:35: if (((p0h>>n)&0x01) != ((portbuffer>>n)&0x01))
                           6860 ;	genRightShift
   170E 8A F0              6861 	mov	b,r2
   1710 05 F0              6862 	inc	b
   1712 E5 42              6863 	mov	a,_p0h
   1714 80 02              6864 	sjmp	00148$
   1716                    6865 00147$:
   1716 C3                 6866 	clr	c
   1717 13                 6867 	rrc	a
   1718                    6868 00148$:
   1718 D5 F0 FB           6869 	djnz	b,00147$
                           6870 ;	genAnd
   171B 54 01              6871 	anl	a,#0x01
   171D FB                 6872 	mov	r3,a
                           6873 ;	genRightShift
   171E 8A F0              6874 	mov	b,r2
   1720 05 F0              6875 	inc	b
   1722 E5 41              6876 	mov	a,_portbuffer
   1724 80 02              6877 	sjmp	00150$
   1726                    6878 00149$:
   1726 C3                 6879 	clr	c
   1727 13                 6880 	rrc	a
   1728                    6881 00150$:
   1728 D5 F0 FB           6882 	djnz	b,00149$
                           6883 ;	genAnd
   172B 54 01              6884 	anl	a,#0x01
   172D FC                 6885 	mov	r4,a
                           6886 ;	genCmpEq
                           6887 ;	gencjneshort
   172E EB                 6888 	mov	a,r3
   172F B5 04 02           6889 	cjne	a,ar4,00151$
                           6890 ;	Peephole 112.b	changed ljmp to sjmp
   1732 80 09              6891 	sjmp	00117$
   1734                    6892 00151$:
                           6893 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:37: pin_changed(n);				// Änderung verarbeiten
                           6894 ;	genCall
   1734 8A 82              6895 	mov	dpl,r2
   1736 C0 02              6896 	push	ar2
   1738 12 09 C2           6897 	lcall	_pin_changed
   173B D0 02              6898 	pop	ar2
   173D                    6899 00117$:
                           6900 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:33: for(n=0;n<8;n++)					// jeden Eingangspin einzel prüfen
                           6901 ;	genPlus
                           6902 ;     genPlusIncr
   173D 0A                 6903 	inc	r2
                           6904 ;	Peephole 112.b	changed ljmp to sjmp
   173E 80 C9              6905 	sjmp	00115$
   1740                    6906 00118$:
                           6907 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:40: portbuffer=p0h;					// neuen Portzustand in buffer speichern
                           6908 ;	genAssign
   1740 85 42 41           6909 	mov	_portbuffer,_p0h
   1743                    6910 00106$:
                           6911 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:43: TASTER=1;				// Pin als Eingang schalten um Taster abzufragen
                           6912 ;	genAssign
   1743 D2 97              6913 	setb	_P1_7
                           6914 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:44: if(!TASTER) {				// Taster gedrückt
                           6915 ;	genIfx
                           6916 ;	genIfxJump
                           6917 ;	Peephole 108.e	removed ljmp by inverse jump logic
   1745 20 97 09           6918 	jb	_P1_7,00111$
                           6919 ;	Peephole 300	removed redundant label 00152$
                           6920 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:45: for(n=0;n<100;n++) {}
                           6921 ;	genAssign
   1748 7A 64              6922 	mov	r2,#0x64
   174A                    6923 00121$:
                           6924 ;	genDjnz
                           6925 ;	Peephole 112.b	changed ljmp to sjmp
                           6926 ;	Peephole 205	optimized misc jump sequence
   174A DA FE              6927 	djnz	r2,00121$
                           6928 ;	Peephole 300	removed redundant label 00153$
                           6929 ;	Peephole 300	removed redundant label 00154$
                           6930 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:46: while(!TASTER);
   174C                    6931 00107$:
                           6932 ;	genIfx
                           6933 ;	genIfxJump
                           6934 ;	Peephole 108.d	removed ljmp by inverse jump logic
   174C 30 97 FD           6935 	jnb	_P1_7,00107$
                           6936 ;	Peephole 300	removed redundant label 00155$
                           6937 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:47: progmode=!progmode;
                           6938 ;	genNot
   174F B2 01              6939 	cpl	_progmode
   1751                    6940 00111$:
                           6941 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:49: TASTER=!progmode;				// LED entsprechend schalten (low=LED an)
                           6942 ;	genNot
   1751 A2 01              6943 	mov	c,_progmode
   1753 B3                 6944 	cpl	c
   1754 92 97              6945 	mov	_P1_7,c
                           6946 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:50: for(n=0;n<100;n++) {}
                           6947 ;	genAssign
   1756 7A 64              6948 	mov	r2,#0x64
   1758                    6949 00124$:
                           6950 ;	genDjnz
                           6951 ;	Peephole 112.b	changed ljmp to sjmp
                           6952 ;	Peephole 205	optimized misc jump sequence
   1758 DA FE              6953 	djnz	r2,00124$
                           6954 ;	Peephole 300	removed redundant label 00156$
                           6955 ;	Peephole 300	removed redundant label 00157$
                           6956 ;	S:/ELEKTR~1/EIB/C/fn_in8/fb_in8.c:51: } while(1);
                           6957 ;	Peephole 112.b	changed ljmp to sjmp
   175A 80 99              6958 	sjmp	00112$
                           6959 ;	Peephole 259.a	removed redundant label 00125$ and ret
                           6960 ;
                           6961 	.area CSEG    (CODE)
                           6962 	.area CONST   (CODE)
                    1C00   6963 _dataflash	=	0x1c00
                           6964 	.area XINIT   (CODE)
