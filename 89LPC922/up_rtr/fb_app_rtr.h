/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2011 Sebastian Michel
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

#ifndef FB_APP_UP_RTR_H_
#define FB_APP_UP_RTR_H_

/*
 * defines
 */
#define OBJNR_KOMFORTBETRIEB    0
#define OBJNR_NACHTBETRIEB      1
#define OBJNR_FROSTSCHUTZ       2
//#define OBJNR_TAUPUNKTBETRIEB   3  // es gibt kein standby objekt, deswegen das Taupunktobjekt ...
#define OBJNR_STANDBY           3    // ... als Standby missbrauchen
#define OBJNR_TASTER            4
#define OBJNR_SOLLWERT          5
#define OBJNR_ISTWERT           6
#define OBJNR_STELL_HEIZEN      7
#define OBJNR_MELDUNG           8
#define OBJNR_STATUS            9
#define OBJNR_BASIS_SOLLWERT    10

/*
 * global functions
 */
void app_process(void);
void rtc_process(void);
void send_value(unsigned char type, unsigned char objno, unsigned int sval);

#endif /* FB_APP_UP_RTR_H_ */
