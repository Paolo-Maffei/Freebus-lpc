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

#ifndef FB_APP_CONFIG_H_
#define FB_APP_CONFIG_H_

/*
 * defines
 */
#define LOC_CONTROL_MODE            0xF8    // bit 2-0: 1=Heizen, 2=Kühlen, 3=Heizen&Kühlen
                                            //          5=2stufigesHeizen, 6=2stufigesKühlen
#define LOC_CONTROLLER_TYPE         0xF9    // bit 6,0: für Heizen - 0=PI-stetig,1=PI-schaltend
                                            //                       2=2P-stetig,3=2P-schaltend

#define LOC_CONTROLLER_PI_PROP      0xF2    // bit 7-0: Proportionalbereich in 0,1K
#define LOC_CONTROLLER_PI_INT       0xF3    // bit 7-0: Nachstellzeit in 1min

#define LOC_CONTROLLER_2P_HYST      0xF2    // bit 7-0: Hysterese in 0,1K

#define LOC_TEMP_SOLL_BASIS         0xE6    // bit 7-0: Basis Sollwert
#define LOC_REDUCT_STANDBY          0xE8    // bit 7-0: Absenkung Standbybetrieb
#define LOC_REDUCT_NIGHT            0xEA    // bit 7-0: Absenkung Nachtbetrieb
#define LOC_FROST_SOLL              0xEC    // bit 7-0: Sollwert Frostschutz

#define LOC_OBJ_STATUS              0xFA    // bit 7-4: 1=Standbybetrieb,     2=Nachtbetrieb,
                                            //          3=Frost-/Hitzeschutz, 4=Taupunktbetrieb,
                                            //          5=Heizbetrieb,        6=Regler inaktiv-Betrieb
                                            //          7=Frostalarm,         8=Regler Status

#define LOC_TEMP_THRESHOLD          0xEF    // bit 7-0:
#define LOC_TEMP_ADAPT_DIRECTION    0xF6    // bit   7:   0=anheben, 1=absenken
#define LOC_TEMP_ADAPT_VALUE        0xF6    // bit 6-0:

#define LOC_CONTROLLER_CYCLE        0xF1    // bit 0-7:   in 10s


//! Betriebsart
#define CFG_CONTROL_MODE                (eeprom[LOC_CONTROL_MODE] & 0x07)
//! Regelverhalten ...
#define CFG_CONTROLLER_TYPE             ((eeprom[LOC_CONTROLLER_TYPE] & 0x01) | ((eeprom[LOC_CONTROLLER_TYPE] & 0x40) >> 5))
//! Regelparameter PI Proportionalbereich
#define CFG_CONTROLLER_PI_PROP          (eeprom[LOC_CONTROLLER_PI_PROP])
//! Regelparameter PI Nachstellzeit
#define CFG_CONTROLLER_PI_INT           (eeprom[LOC_CONTROLLER_PI_INT])
//! Regelparameter 2P Hysterese
#define CFG_CONTROLLER_2P_HYST          (eeprom[LOC_CONTROLLER_2P_HYST])

//! Basis-Sollwert (Komfortbetrieb) in 1°C (7-40)
#define CFG_TEMP_SOLL_BASIS             (eeprom[LOC_TEMP_SOLL_BASIS])
//! Absenkung Standbybetrieb Heizen in 0,1K (0-200)
#define CFG_REDUCT_STANDBY              (eeprom[LOC_REDUCT_STANDBY])
//! Absenkung Nachtbetrieb Heizen in 0,1K (0-200)
#define CFG_REDUCT_NIGHT                (eeprom[LOC_REDUCT_NIGHT])
//! Sollwert Frostschutz (Heizen) in 1°C (7-40)
#define CFG_FROST_SOLL                  (eeprom[LOC_FROST_SOLL])

//! Funktion des Objektes -Status-
#define CFG_OBJ_STATUS                  (eeprom[LOC_OBJ_STATUS] >> 4)

//! Änderung für automatisches Senden in 0,1K (0-255)(0:inaktiv)
#define CFG_TEMP_THRESHOLD              (eeprom[LOC_TEMP_THRESHOLD])
//! Abgleichrichtung der Istwertmessung
#define CFG_TEMP_ADAP_DIRECTION         (eeprom[LOC_TEMP_ADAPT_DIRECTION] >> 7)
//! Offset zur Istwertmessung in 0,1K (0-127)
#define CFG_TEMP_ADAP_VALUE             (eeprom[LOC_TEMP_ADAPT_VALUE] & 0x7F)

//! Zykluszeit der schaltenden Stellgröße in 10 sek (1-255)
#define CFG_CONTROLLER_CYCLE            (eeprom[LOC_CONTROLLER_CYCLE])

#endif /* FB_APP_CONFIG_H_ */
