/*
 *      __________  ________________  __  _______
 *     / ____/ __ \/ ____/ ____/ __ )/ / / / ___/
 *    / /_  / /_/ / __/ / __/ / __  / / / /\__ \
 *   / __/ / _, _/ /___/ /___/ /_/ / /_/ /___/ /
 *  /_/   /_/ |_/_____/_____/_____/\____//____/
 *
 *  Copyright (c) 2010 Sebastian Michel
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */

#ifndef FB_APP_TEMP_H_
#define FB_APP_TEMP_H_

/*
 * defines
 */
#define MAX_INT 0x7FFF

/*
 * variables
 */
extern int      g_temp_value;

/*
 * globale Funktionen
 */
void    temp_process(void);
int     eis5_to_temp(int eis5temp);
int     temp_to_eis5(int temp);

#endif /* FB_APP_TEMP_H_ */
