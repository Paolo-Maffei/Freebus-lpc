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

// Versionen:	1.00	- erste Version
//              1.01    - Modi Komfort, Nacht, Frostschutz und Standby können abgefragt werden
//                      - Basis-Sollwert kann abgefragt werden
//              1.02    - bei Änderung des aktuellen Sollwertes diesen automatisch auf den Bus senden
//
// unterstützte Funktionen:
// [X] - Betriebsart Heizen
// [X] - Regelverhalten für Heizen: PI/2Punkt schaltend/stetig
// [X] - Typ des Heizsystems über Vorauswahl oder Eingabe der Reglerparameter
// [X] - Hystereseparameter
//
// [X] - Basis-Sollwert
// [X] - Absenkung im Standbybetrieb
// [X] - Absenkung im Nachtbetrieb
// [X] - Absenkung im Frostschutzbetrieb
//
// [X] - Funktion des Objektes -Status-
// [ ] - Regelung aktiv/inaktiv
//
// [X] - Änderung für automatisches Senden
// [X] - Abgleichrichtung der Istwertmessung
// [X] - Offset zur Istwertmessung
//
// [ ] - Wirksinn Heizen
// [X] - Änderung für automatisches Senden
// [X] - Zykluszeit der schaltenden Stellgröße
// [ ] - Zykluszeit für automatisches Senden
// [ ] - Stellgrößenausgabe
//
// nicht unterstützte Funktionen:
//     - Betriebsart Kühlen, Heizen & Kühlen, 2-stufiges Heizen, 2-stufies Khlen
//
//     - Maximale Sollwertverschiebung Drehknopf
//
//     - Tasterfunktion
//     - Verhalten des Tasterzustandes wenn Obj. Nachtbetrieb auf 0 gesetzt wird
//     - Verhalten des Tasterzustandes wenn Obj. Komfortbetrieb auf 0 gesetzt wird
//     - Dauer der Komfortverlängerung


#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_rtr.h"
#ifdef DEBUG
#include "fb_rs232.h"
#endif

/*
 * local functions
 */
void    main(void);
void    check_prog_button(void);

/*
 * implementation
 */


/**
 * main entry point
 */
void main(void)
{
    unsigned char   n;

    // hardware initialisieren
    restart_hw();

    // warten bis der BUS stabil ist
    for (n=0; n<50; n++)
    {
        set_timer0(0xFFFF);
        while(!TF0);
    }

    // Protokoll zurücksetzen
    restart_prot();

#ifdef DEBUG
    // serielle Schnittstelle für DEBUG Ausgaben initialisieren
    rs_init(576);
#endif

    // initialize/reset application
    restart_app();

    // main loop
    while (1)
    {
        if (!TR1) // check if TR1 is active -> send/receive finished
        {
            // applikation ausführen
            app_process();

            if (RTCCON>=0x80)
            {
                stop_rtc();
                rtc_process();  // Realtime clock Ueberlauf
                start_rtc(65);  // RTC mit 65ms neu starten
            }
        }

        // check program button
        check_prog_button();
    }
}

/**
 * check if the user presses the program button
 */
void check_prog_button(void)
{
    unsigned char n;

    // set button pin to input mode
    TASTER = 1;

    // check if button is pressed
    if (!TASTER)
    {
        for(n=0; n<100; n++) {}  // debounce time
        while (!TASTER);         // wait until the user releases the button

        START_WRITECYCLE;
        // toggle prog-bit and parity-bit in the system state
        WRITE_BYTE(0x00, 0x60, userram[0x60] ^ 0x81);
        STOP_WRITECYCLE;
    }

    // set LED according to prog-bit (low=LED on)
    TASTER=!(userram[0x060] & 0x01);

    // give the LED some time to light up
    for(n=0; n<100; n++) {}
}
