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

#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "../com/onewire.h"
#include "fb_app_temp.h"
#include "fb_app_rtr.h"
#include "fb_app_config.h"

/*
 * defines
 */
#define STATE_START     0
#define STATE_WAIT      1
#define STATE_FINISH    2

/*
 * variables
 */
int                     g_temp_value        = MAX_INT;
static unsigned char    g_temp_read_state   = STATE_START;

/*
 * local functions
 */
void set_temp(int value);
void check_temp_threshold(void);

/*
 * Implementation
 */

/**
 * diese Funktion startet die Temperaturmessung
 */
void temp_process(void)
{
    int     th;

    switch (g_temp_read_state)
    {
        case STATE_START:
            interrupted = 0;
            // starte messung
            start_tempconversion();
            if (!interrupted)
                g_temp_read_state = STATE_WAIT;
            break;

        case STATE_WAIT:
            if (ow_read_bit())
                g_temp_read_state = STATE_FINISH;      // conversion finished
            break;

        case STATE_FINISH:
            interrupted = 0;

            // read temperature
            th = read_temp();

            if (!interrupted)
            {
                // save temperature in global variable
                set_temp(th);

                // check temperature delta
                check_temp_threshold();

                // reset state machine
                g_temp_read_state = STATE_START;
            }
            break;
    }
}

/**
 * Temperaturwert in globaler Variable speichern; dabei Temperaturanpassung
 * berücksichtigen
 */
void set_temp(int value)
{
    unsigned char offset = CFG_TEMP_ADAP_VALUE;

    if (offset == 0x00)
    {
        // just set temperature
        g_temp_value = value;
        return;
    }

    if (CFG_TEMP_ADAP_DIRECTION == 0)
    {
        g_temp_value = value + offset * 10; // offset is 1/10 degree, temp is 1/100 degree
    }
    else
    {
        g_temp_value = value - offset * 10;
    }
}

/**
 * prüft, ob sich die Temperatur um einen vorgegebenen Wert geändert hat
 */
void check_temp_threshold(void)
{
    static int  last_temp_value;
    int         diff;
    int         eis5temp;
    unsigned    char threshold = CFG_TEMP_THRESHOLD;

    if (threshold == 0)
    {
        // deaktiviert
        return;
    }

    if (g_temp_value < last_temp_value)
    {
        diff = last_temp_value - g_temp_value;
    }
    else
    {
        diff = g_temp_value - last_temp_value;
    }

    // convert 1/100 degree to 1/10 degree
    diff /= 10;

    if (diff >= threshold)
    {
        // Temperatur umwandeln und senden
        eis5temp = temp_to_eis5(g_temp_value);
        send_value(0, OBJNR_ISTWERT, eis5temp);

        // aktuelle Temperatur zum zukünftigen Vergleich speichern
        last_temp_value = g_temp_value;
    }
}

/**
 * konvertiert einen EIS5 Typ in eine Temperatur mit 1/100 Grad Auflösung
 */
int eis5_to_temp(int eis5temp)
{
    unsigned char   exp;
    int             temp = 0;

    exp = (eis5temp >> 11) & 0x0F;
    temp = (eis5temp & 0x07FF) << exp;

    // Vorzeichen prüfen
    if (eis5temp >> 15 == 1)
        temp = -temp;

    return temp;
}

/**
 * konvertiert eine Temperatur mit 1/100 Grad Auflösung in einen EIS5 Type
 */
int temp_to_eis5(int temp)
{
    int eis5temp;

    // convert temperature to eis5 format
    eis5temp = (temp>>3) & 0x07FF;
    eis5temp = eis5temp + (0x18 << 8);            // exponent 3
    if (temp < 0)
    {
        eis5temp += 0x8000;       // sign
    }

    return eis5temp;
}
