                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
                              4 ; This file was generated Sun Jul 15 18:49:18 2012
                              5 ;--------------------------------------------------------
                              6 	.module adc
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
                            147 	.globl _CMPbuf
                            148 	.globl _CMPbufaddr
                            149 	.globl _CMPModex
                            150 	.globl _CMPx
                            151 	.globl _HighByte
                            152 	.globl _LowByte
                            153 	.globl _Get_SD_ADC
                            154 	.globl _Get_ADC
                            155 ;--------------------------------------------------------
                            156 ; special function registers
                            157 ;--------------------------------------------------------
                            158 	.area RSEG    (DATA)
                    0080    159 _P0	=	0x0080
                    0090    160 _P1	=	0x0090
                    00B0    161 _P3	=	0x00b0
                    00D0    162 _PSW	=	0x00d0
                    00E0    163 _ACC	=	0x00e0
                    00F0    164 _B	=	0x00f0
                    0081    165 _SP	=	0x0081
                    0082    166 _DPL	=	0x0082
                    0083    167 _DPH	=	0x0083
                    0087    168 _PCON	=	0x0087
                    0088    169 _TCON	=	0x0088
                    0089    170 _TMOD	=	0x0089
                    008A    171 _TL0	=	0x008a
                    008B    172 _TL1	=	0x008b
                    008C    173 _TH0	=	0x008c
                    008D    174 _TH1	=	0x008d
                    00A8    175 _IEN0	=	0x00a8
                    00B8    176 _IP0	=	0x00b8
                    0098    177 _SCON	=	0x0098
                    0099    178 _SBUF	=	0x0099
                    00A2    179 _AUXR1	=	0x00a2
                    00A9    180 _SADDR	=	0x00a9
                    00B9    181 _SADEN	=	0x00b9
                    00BE    182 _BRGR0	=	0x00be
                    00BF    183 _BRGR1	=	0x00bf
                    00BD    184 _BRGCON	=	0x00bd
                    00AC    185 _CMP1	=	0x00ac
                    00AD    186 _CMP2	=	0x00ad
                    0095    187 _DIVM	=	0x0095
                    00E7    188 _FMADRH	=	0x00e7
                    00E6    189 _FMADRL	=	0x00e6
                    00E4    190 _FMCON	=	0x00e4
                    00E5    191 _FMDATA	=	0x00e5
                    00DB    192 _I2ADR	=	0x00db
                    00D8    193 _I2CON	=	0x00d8
                    00DA    194 _I2DAT	=	0x00da
                    00DD    195 _I2SCLH	=	0x00dd
                    00DC    196 _I2SCLL	=	0x00dc
                    00D9    197 _I2STAT	=	0x00d9
                    00F8    198 _IP1	=	0x00f8
                    00F7    199 _IP1H	=	0x00f7
                    0094    200 _KBCON	=	0x0094
                    0086    201 _KBMASK	=	0x0086
                    0093    202 _KBPATN	=	0x0093
                    0084    203 _P0M1	=	0x0084
                    0085    204 _P0M2	=	0x0085
                    0091    205 _P1M1	=	0x0091
                    0092    206 _P1M2	=	0x0092
                    00B1    207 _P3M1	=	0x00b1
                    00B2    208 _P3M2	=	0x00b2
                    00B5    209 _PCONA	=	0x00b5
                    00F6    210 _PT0AD	=	0x00f6
                    00DF    211 _RSTSRC	=	0x00df
                    00D1    212 _RTCCON	=	0x00d1
                    00D2    213 _RTCH	=	0x00d2
                    00D3    214 _RTCL	=	0x00d3
                    00BA    215 _SSTAT	=	0x00ba
                    008F    216 _TAMOD	=	0x008f
                    0096    217 _TRIM	=	0x0096
                    00A7    218 _WDCON	=	0x00a7
                    00C1    219 _WDL	=	0x00c1
                    00C2    220 _WFEED1	=	0x00c2
                    00C3    221 _WFEED2	=	0x00c3
                    00B7    222 _IP0H	=	0x00b7
                    00E8    223 _IEN1	=	0x00e8
                            224 ;--------------------------------------------------------
                            225 ; special function bits
                            226 ;--------------------------------------------------------
                            227 	.area RSEG    (DATA)
                    00D0    228 _PSW_0	=	0x00d0
                    00D1    229 _PSW_1	=	0x00d1
                    00D2    230 _PSW_2	=	0x00d2
                    00D3    231 _PSW_3	=	0x00d3
                    00D4    232 _PSW_4	=	0x00d4
                    00D5    233 _PSW_5	=	0x00d5
                    00D6    234 _PSW_6	=	0x00d6
                    00D7    235 _PSW_7	=	0x00d7
                    008F    236 _TCON_7	=	0x008f
                    008E    237 _TCON_6	=	0x008e
                    008D    238 _TCON_5	=	0x008d
                    008C    239 _TCON_4	=	0x008c
                    008B    240 _TCON_3	=	0x008b
                    008A    241 _TCON_2	=	0x008a
                    0089    242 _TCON_1	=	0x0089
                    0088    243 _TCON_0	=	0x0088
                    00AF    244 _IEN0_7	=	0x00af
                    00AE    245 _IEN0_6	=	0x00ae
                    00AD    246 _IEN0_5	=	0x00ad
                    00AC    247 _IEN0_4	=	0x00ac
                    00AB    248 _IEN0_3	=	0x00ab
                    00AA    249 _IEN0_2	=	0x00aa
                    00A9    250 _IEN0_1	=	0x00a9
                    00A8    251 _IEN0_0	=	0x00a8
                    00EA    252 _IEN1_2	=	0x00ea
                    00E9    253 _IEN1_1	=	0x00e9
                    00E8    254 _IEN1_0	=	0x00e8
                    00FE    255 _IP1_6	=	0x00fe
                    00FA    256 _IP1_2	=	0x00fa
                    00F9    257 _IP1_1	=	0x00f9
                    00F8    258 _IP1_0	=	0x00f8
                    00BE    259 _IP0_6	=	0x00be
                    00BD    260 _IP0_5	=	0x00bd
                    00BC    261 _IP0_4	=	0x00bc
                    00BB    262 _IP0_3	=	0x00bb
                    00BA    263 _IP0_2	=	0x00ba
                    00B9    264 _IP0_1	=	0x00b9
                    00B8    265 _IP0_0	=	0x00b8
                    0098    266 _SCON_0	=	0x0098
                    0099    267 _SCON_1	=	0x0099
                    009A    268 _SCON_2	=	0x009a
                    009B    269 _SCON_3	=	0x009b
                    009C    270 _SCON_4	=	0x009c
                    009D    271 _SCON_5	=	0x009d
                    009E    272 _SCON_6	=	0x009e
                    009F    273 _SCON_7	=	0x009f
                    00DE    274 _I2CON_6	=	0x00de
                    00DD    275 _I2CON_5	=	0x00dd
                    00DC    276 _I2CON_4	=	0x00dc
                    00DB    277 _I2CON_3	=	0x00db
                    00DA    278 _I2CON_2	=	0x00da
                    00D8    279 _I2CON_0	=	0x00d8
                    0080    280 _P0_0	=	0x0080
                    0081    281 _P0_1	=	0x0081
                    0082    282 _P0_2	=	0x0082
                    0083    283 _P0_3	=	0x0083
                    0084    284 _P0_4	=	0x0084
                    0085    285 _P0_5	=	0x0085
                    0086    286 _P0_6	=	0x0086
                    0087    287 _P0_7	=	0x0087
                    0090    288 _P1_0	=	0x0090
                    0091    289 _P1_1	=	0x0091
                    0092    290 _P1_2	=	0x0092
                    0093    291 _P1_3	=	0x0093
                    0094    292 _P1_4	=	0x0094
                    0095    293 _P1_5	=	0x0095
                    0096    294 _P1_6	=	0x0096
                    0097    295 _P1_7	=	0x0097
                    00B0    296 _P3_0	=	0x00b0
                    00B1    297 _P3_1	=	0x00b1
                            298 ;--------------------------------------------------------
                            299 ; overlayable register banks
                            300 ;--------------------------------------------------------
                            301 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     302 	.ds 8
                            303 ;--------------------------------------------------------
                            304 ; internal ram data
                            305 ;--------------------------------------------------------
                            306 	.area DSEG    (DATA)
   0008                     307 _LowByte::
   0008                     308 	.ds 1
   0009                     309 _HighByte::
   0009                     310 	.ds 1
   000A                     311 _CMPx::
   000A                     312 	.ds 1
   000B                     313 _CMPModex::
   000B                     314 	.ds 1
   000C                     315 _CMPbufaddr::
   000C                     316 	.ds 1
   000D                     317 _CMPbuf::
   000D                     318 	.ds 2
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
                            336 ;--------------------------------------------------------
                            337 ; paged external ram data
                            338 ;--------------------------------------------------------
                            339 	.area PSEG    (PAG,XDATA)
                            340 ;--------------------------------------------------------
                            341 ; external ram data
                            342 ;--------------------------------------------------------
                            343 	.area XSEG    (XDATA)
                            344 ;--------------------------------------------------------
                            345 ; absolute external ram data
                            346 ;--------------------------------------------------------
                            347 	.area XABS    (ABS,XDATA)
                            348 ;--------------------------------------------------------
                            349 ; external initialized ram data
                            350 ;--------------------------------------------------------
                            351 	.area XISEG   (XDATA)
                            352 	.area HOME    (CODE)
                            353 	.area GSINIT0 (CODE)
                            354 	.area GSINIT1 (CODE)
                            355 	.area GSINIT2 (CODE)
                            356 	.area GSINIT3 (CODE)
                            357 	.area GSINIT4 (CODE)
                            358 	.area GSINIT5 (CODE)
                            359 	.area GSINIT  (CODE)
                            360 	.area GSFINAL (CODE)
                            361 	.area CSEG    (CODE)
                            362 ;--------------------------------------------------------
                            363 ; global & static initialisations
                            364 ;--------------------------------------------------------
                            365 	.area HOME    (CODE)
                            366 	.area GSINIT  (CODE)
                            367 	.area GSFINAL (CODE)
                            368 	.area GSINIT  (CODE)
                            369 ;--------------------------------------------------------
                            370 ; Home
                            371 ;--------------------------------------------------------
                            372 	.area HOME    (CODE)
                            373 	.area HOME    (CODE)
                            374 ;--------------------------------------------------------
                            375 ; code
                            376 ;--------------------------------------------------------
                            377 	.area CSEG    (CODE)
                            378 ;------------------------------------------------------------
                            379 ;Allocation info for local variables in function 'Get_SD_ADC'
                            380 ;------------------------------------------------------------
                            381 ;------------------------------------------------------------
                            382 ;	../../com/adc_922.c:26: void Get_SD_ADC(void) __naked
                            383 ;	-----------------------------------------
                            384 ;	 function Get_SD_ADC
                            385 ;	-----------------------------------------
   0084                     386 _Get_SD_ADC:
                            387 ;	naked function: no prologue.
                            388 ;	../../com/adc_922.c:110: _endasm;
                            389 	
                            390 	
   0084                     391 	 00001$:
   0084 C0 E0               392 	 PUSH ACC
   0086 C0 D0               393 	 PUSH PSW
   0088 C0 00               394 	 push ar0
   008A C0 04               395 	 PUSH ar4
   008C C0 05               396 	 PUSH ar5
                            397 	
   008E A8 0C               398 	 MOV R0,_CMPbufaddr
   0090 85 0B AC            399 	 MOV _CMP1,_CMPModex ; load CMPModex into comparator control register P0_6
   0093 85 0B AD            400 	 MOV _CMP2,_CMPModex ; load CMPModex "" "" P0_0
   0096 7C 00               401 	 MOV R4,#0
   0098 7D 00               402 	 MOV R5,#0
                            403 	
   009A                     404 	 00002$:
                            405 ; Precharge (charges capacitor exactly to voltage of positive input)
   009A 85 AC 0D            406 	 MOV _CMPbuf,_CMP1 ; comparatur control registers into CMPbuf
   009D 85 AD 0E            407 	 MOV _CMPbuf+1,_CMP2
   00A0 E6                  408 	 MOV A,@R0 ; get CMPx indirectly, R0 is address of the variable CMPbuf
   00A1 54 02               409 	 ANL A,#0x02 ; only take the comparator output bit
   00A3 A2 E1               410 	 MOV C,0xE1 ; comparator output –> carry (0xE1 is second bit of ACC)
   00A5 E4                  411 	 CLR A
   00A6 92 80               412 	 MOV 0x80,C ; P0.0 = comparator output (charge capacitor when negative input is lower than positive)
                            413 	
   00A8 20 02 3E            414 	 JB _interrupted,00004$
                            415 	
                            416 	
                            417  ;Counter
   00AB C3                  418 	 CLR C ; increase 16-bit counter register R4/R5
   00AC EC                  419 	 MOV A,R4
   00AD 24 01               420 	 ADD A,#0x01
   00AF FC                  421 	 MOV R4,A
   00B0 ED                  422 	 MOV A,R5
   00B1 34 00               423 	 ADDC A,#0x00
   00B3 FD                  424 	 MOV R5,A
   00B4 B4 40 E3            425 	 CJNE A,#0x40,00002$ ; precharge loop (enough cycles, so that C could be fully charged to Vcc)
                            426 	
                            427 	
   00B7 7C 80               428 	 MOV R4,#0x80 ; R4/R5 are 16-bit counter for Measurecycles (should be 10.000 times Vcc, e.g. 5V=50.000 cycles)
   00B9 7D 00               429 	 MOV R5,#0x00 ; low byte is preset, so that at the end of loop only highbyte needs to be checked
   00BB 75 08 00            430 	 MOV _LowByte,#0x00;
   00BE 75 09 00            431 	 MOV _HighByte,#0x00;
                            432 	
   00C1                     433 	 00003$:
                            434  ;Sigma
                            435 	
   00C1 20 02 25            436 	 JB _interrupted,00004$
                            437 	
   00C4 C3                  438 	 CLR C
   00C5 85 AC 0D            439 	 MOV _CMPbuf,_CMP1 ; comparatur control registers into CMPbuf
   00C8 85 AD 0E            440 	 MOV _CMPbuf+1,_CMP2
   00CB E6                  441 	 MOV A,@R0 ; get CMPx indirectly, R0 is address of the variable CMPbuf
   00CC 54 02               442 	 ANL A,#0x02 ; only take the comparator output bit
   00CE A2 E1               443 	 MOV C,0xE1 ; comparator output –> carry (0xE1 is second bit of ACC)
   00D0 E4                  444 	 CLR A
   00D1 92 80               445 	 MOV 0x80,C ; comparator output (charge capacitor when negative input is lower than positive)
                            446 	
   00D3 35 08               447 	 ADDC A,_LowByte ; increase LowByte/HighByte counter if comparator output is high
   00D5 F5 08               448 	 MOV _LowByte,A
   00D7 E5 09               449 	 MOV A,_HighByte
   00D9 34 00               450 	 ADDC A,#0x00
   00DB F5 09               451 	 MOV _HighByte,A
                            452 	
                            453  ;Counter Measurementcycles
   00DD C3                  454 	 CLR C
   00DE EC                  455 	 MOV A,R4 ; increase R4/R5 counter
   00DF 24 01               456 	 ADD A,#0x01
   00E1 FC                  457 	 MOV R4,A
   00E2 ED                  458 	 MOV A,R5
   00E3 34 00               459 	 ADDC A,#0x00
   00E5 FD                  460 	 MOV R5,A
                            461 	
   00E6 B4 C4 D8            462 	 CJNE A,#0xC4,00003$ ; check only high byte of R4/R5 to get correct number of measure cycles
                            463 	
   00E9                     464 	 00004$:
   00E9 D0 05               465 	 POP ar5;
   00EB D0 04               466 	 POP ar4;
   00ED D0 00               467 	 pop ar0
   00EF D0 D0               468 	 POP PSW;
   00F1 D0 E0               469 	 POP ACC;
   00F3 22                  470 	 RET
                            471 	
                            472 	 
                            473 ;	naked function: no epilogue.
                            474 ;------------------------------------------------------------
                            475 ;Allocation info for local variables in function 'Get_ADC'
                            476 ;------------------------------------------------------------
                            477 ;channel                   Allocated to registers r2 
                            478 ;------------------------------------------------------------
                            479 ;	../../com/adc_922.c:116: void Get_ADC(char channel)	// Channel 0-3
                            480 ;	-----------------------------------------
                            481 ;	 function Get_ADC
                            482 ;	-----------------------------------------
   00F4                     483 _Get_ADC:
                    0002    484 	ar2 = 0x02
                    0003    485 	ar3 = 0x03
                    0004    486 	ar4 = 0x04
                    0005    487 	ar5 = 0x05
                    0006    488 	ar6 = 0x06
                    0007    489 	ar7 = 0x07
                    0000    490 	ar0 = 0x00
                    0001    491 	ar1 = 0x01
                            492 ;	../../com/adc_922.c:118: if (channel & 1)		// for channel 1 and 3
   00F4 E5 82               493 	mov	a,dpl
   00F6 FA                  494 	mov	r2,a
   00F7 30 E0 05            495 	jnb	acc.0,00102$
                            496 ;	../../com/adc_922.c:119: CMPModex = 0x030;		// comparator enabled, positive input pin CINnA, 
   00FA 75 0B 30            497 	mov	_CMPModex,#0x30
   00FD 80 03               498 	sjmp	00103$
   00FF                     499 00102$:
                            500 ;	../../com/adc_922.c:123: CMPModex = 0x020;		// same, but positive input pin is CINnB
   00FF 75 0B 20            501 	mov	_CMPModex,#0x20
   0102                     502 00103$:
                            503 ;	../../com/adc_922.c:125: if (channel & 2)
   0102 EA                  504 	mov	a,r2
   0103 30 E1 05            505 	jnb	acc.1,00105$
                            506 ;	../../com/adc_922.c:126: CMPbufaddr = (char) &CMPbuf[1];
   0106 75 0C 0E            507 	mov	_CMPbufaddr,#(_CMPbuf + 0x0001)
   0109 80 03               508 	sjmp	00106$
   010B                     509 00105$:
                            510 ;	../../com/adc_922.c:128: CMPbufaddr = (char) &CMPbuf[0];
   010B 75 0C 0D            511 	mov	_CMPbufaddr,#_CMPbuf
   010E                     512 00106$:
                            513 ;	../../com/adc_922.c:129: Get_SD_ADC();
   010E 02 00 84            514 	ljmp	_Get_SD_ADC
                            515 	.area CSEG    (CODE)
                            516 	.area CONST   (CODE)
                            517 	.area XINIT   (CODE)
                            518 	.area CABS    (ABS,CODE)
