/***********************************************************************
MODULE:    Watchdog
VERSION:   1.01
CONTAINS:  Routines for controlling the Watchdog on the
           P89LPC922
COPYRIGHT: Embedded Systems Academy, Inc. - www.esacademy.com
LICENSE:   May be freely used in commercial and non-commercial code
           without royalties provided this copyright notice remains
           in this file and unaltered
WARNING:   IF THIS FILE IS REGENERATED BY CODE ARCHITECT ANY CHANGES
           MADE WILL BE LOST. WHERE POSSIBLE USE ONLY CODE ARCHITECT
           TO CHANGE THE CONTENTS OF THIS FILE
GENERATED: On "May 17 2010" at "21:05:36" by Code Architect 2.06
***********************************************************************/

#ifndef _WATCHDOGH_
#define _WATCHDOGH_

/***********************************************************************
DESC:    Initializes the watchdog as a Watchdog Timer
         Uses Watchdog clock at 400kHz as a clock source
         Resets the device if not fed within 2.622 s
RETURNS: Nothing
************************************************************************/
extern void watchdog_init(void);



/***********************************************************************
DESC:    Feeds the Watchdog to stop the device from resetting
RETURNS: Nothing
CAUTION: watchdog_init must be called first
************************************************************************/
extern void watchdog_feed(void);


/***********************************************************************
DESC:    Starts the Watchdog
RETURNS: Nothing
CAUTION: watchdog_init must be called first
************************************************************************/
extern void watchdog_start(void);


/***********************************************************************
DESC:    Stops the Watchdog
RETURNS: Nothing
CAUTION: watchdog_init must be called first
************************************************************************/
extern void watchdog_stop(void);



extern void watchdog_count(void);

#endif // _WATCHDOGH_
