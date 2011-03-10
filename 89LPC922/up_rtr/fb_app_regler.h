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

#ifndef FB_REGLER_H_
#define FB_REGLER_H_

/*
 * typedef
 */
typedef enum
{
    cntrlr_pi,
    cntrlr_2p
} ctrlr_type;

/*
 * global functions
 */
void cntrlr_init(ctrlr_type type, int param1, int param2);
int  cntrlr_step(int soll, int ist, int takt);

#endif /* FB_REGLER_H_ */
