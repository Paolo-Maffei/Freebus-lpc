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

#include "fb_app_regler.h"
#ifdef DEBUG
#include "fb_rs232.h"
#endif

/*
 * variables
 */
static ctrlr_type   g_type;
static int    g_p1;
static int    g_p2;
static int    g_stell;
static int    g_esum;

/*
 * local functions
 */
static int _pi_step(int soll, int ist, int takt);
static int _2p_step(int soll, int ist);

/*
 * implementation
 */

/**
 * Regler initialisieren
 *
 * @param type      Reglertyp: PI oder 2Punkt
 * @param param1    abhängig vom Reglertyp: PI - Proportionalanteil, 2Punkt - Hysteresewert
 * @param param2    abhängig vom Reglertyp: PI - Nachstellzeit,      2Punkt - -
 */
void cntrlr_init(ctrlr_type type, int param1, int param2)
{
    g_type = type;

    g_p1     = param1;
    g_p2     = param2;
    g_stell = 0;
    g_esum  = 0;
}

/**
 * Regler Berechnung durchführen
 *
 * @param soll      der Sollwert
 * @param ist       der Istwert
 * @param takt      Zeit zwischen den Aufrufen der Funktion (in min)
 * @return          Stellwert 0 bis 100 Prozent, oder -1 für einen ungültigen Wert
 */
int cntrlr_step(int soll, int ist, int takt)
{
    switch(g_type)
    {
        case cntrlr_pi:
            return _pi_step(soll, ist, takt);

        case cntrlr_2p:
            return _2p_step(soll, ist);
    }

    return 0;
}

/**
 * PI-Regler Berechnung durchführen
 *
 * @param soll      der Sollwert
 * @param ist       der Istwert
 * @param takt      Zeit zwischen den Aufrufen der Funktion (in min)
 * @return          Stellwert 0 bis 100 Prozent
 */
static int _pi_step(int soll, int ist, int takt)
{
    int e, kp, stell_alt, v4;

    // Verstärkung berechnen
    kp = 200 / g_p1;
    // Fehler berechnen
    e = soll - ist;

#ifdef DEBUG
    rs_send_s("ps: e=");
    rs_send_dec(e);
    rs_send_s("\n");
#endif

    stell_alt = g_stell;
    if (stell_alt <= 100 && stell_alt >= 0)
        // Fehler aufsummieren
        g_esum += e;

    v4 = g_esum * kp * takt / g_p2;
    g_stell = e * kp + v4;

#ifdef DEBUG
    rs_send_s("ps: stell=");
    rs_send_dec(g_stell);
    rs_send_s("\n");
    rs_send_s("ps: esum=");
    rs_send_dec(g_esum);
    rs_send_s("\n");
#endif

    if (g_stell > 100)
    {
        g_stell = 100;
        g_esum = (stell_alt - e * kp) * g_p2 / kp / takt;
#ifdef DEBUG
        rs_send_s("ps: esum=");
        rs_send_dec(g_esum);
        rs_send_s("\n");
#endif
    }

    if (g_stell < 0 || g_esum < 0)
    {
#ifdef DEBUG
        rs_send_s("ps: llim\n");
#endif
        g_esum = 0;
        if (g_stell < 0)
            g_stell = 0;
    }

    return g_stell;
}

/**
 * @brief 2-Punkt-Regler Berechnung durchführen
 *
 * @param soll        der Sollwert
 * @param ist         der Istwert
 * @return            Stellwert 0 oder 100 Prozent oder -1 für ungültigen Wert
 */
static int _2p_step(int soll, int ist)
{
    if (ist < soll - g_p1/2)
        return 0;
    else if (ist > soll + g_p1/2)
        return 100;

    return -1;
}
