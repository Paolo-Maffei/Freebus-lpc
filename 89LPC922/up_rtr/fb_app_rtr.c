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

#include <P89LPC922.h>
#include "../com/fb_hal_lpc.h"
#include "../com/fb_prot.h"
#include "fb_app_rtr.h"
#include "fb_app_temp.h"
#include "fb_app_config.h"
#include "fb_app_regler.h"
#ifdef DEBUG
#include "fb_rs232.h"
#endif

/*
 * defines
 */

// ein Macro was prüft, ob 10 Sekunden vergangen sind; wird all 65ms aufgerufen
#define CHECK_10S_COUNTER(cnt) {                              \
                                 if (++cnt < 153)             \
                                   return;                    \
                                 cnt = 0;                     \
                               }

// Hilfsmacro, wird in app_process verwendet, um zu überprüfen, ob bestimmte Aktionen
// ausgeführt werden müssen
#define CHECK_DO(do_val) if (do_val == 1 && do_val--)

// wandelt den operating mode in das passende Kommunikationsobjekt um
#define GET_OBJNR_FROM_MODE(mode) mode == om_komfort ? OBJNR_KOMFORTBETRIEB :    \
                                  mode == om_nacht   ? OBJNR_NACHTBETRIEB   :    \
                                  mode == om_frost   ? OBJNR_FROSTSCHUTZ    :    \
                                  mode == om_standby ? OBJNR_STANDBY        : OBJNR_KOMFORTBETRIEB

/*
 * typedefs
 */
typedef enum
{
    om_komfort  = 0x01,
    om_standby  = 0x02,
    om_nacht    = 0x04,
    om_frost    = 0x08,
} operating_mode;

/*
 * variables
 */
static __bit            g_do_controller;        // Regler Berechnung durchführen
static __bit            g_do_enable;            // Heizung anschalten
static __bit            g_do_disable;           // Heizung ausschalten
static unsigned char    g_controller_stell_counter;    // dieser counter wird alle 10 Sekunden um 1
                                                       // dekrementiert ... solange der Wert ungleich 0
                                                       // ist, wird geheizt ansonsten nicht

/*
 * local functions
 */
void            set_mode(operating_mode mode);
operating_mode  get_mode();
int             get_sollwert(void);
void            controller_process(void);
void            send_obj_status(void);
void            send_sollwert(void);
#ifdef DEBUG
static void     dump_telegramm(void);
#endif

/*
 * implementation
 */

/**
 * Diese Funktion wird aus der Programmschleife aufgerufen und führt die
 * Applikationsfunktionen aus.
 */
void app_process(void)
{
    // Temperaturmessung immer durchführen
    temp_process();

    // Regler Berechnung durchführen
    CHECK_DO(g_do_controller)
    {
        controller_process();
    }

    // Ausgang anschalten
    CHECK_DO(g_do_enable)
    {
        send_value(0, OBJNR_STELL_HEIZEN, 1);
    }

    // Ausgang ausschalten
    CHECK_DO(g_do_disable)
    {
        send_value(0, OBJNR_STELL_HEIZEN, 0);
    }
}

/**
 * wird aufgerufen wenn die Real-Time-Clock überläuft, alle 65ms
 */
void rtc_process(void)
{
    // wird von 0 bis 153 hochgezählt, danach sind ca. 10 Sekunden vergangen
    static int sec10_counter = 0;

    // prüft gemäß Konfiguration ob die Berechnung des Reglers durchgeführt werden muss;
    // zählt rückwärts, wenn der Wert 0 ist, wird die Berechnung durchgeführt
    static int controller_counter = 0;

    CHECK_10S_COUNTER(sec10_counter);

    //
    // der folgende Teil wird nur alle 10 Sekunden ausgeführt
    //

    // ///////////////////////////////////////////////////////////
    // prüfen ob eine Reglerberechnung durchgeführt werden muss;
    // nur wenn eine gültige Temperatur vorliegt
    if (g_temp_value != MAX_INT)
    {
        if (controller_counter == 0)
        {
            g_do_controller = 1;
            // counter zurücksetzen
            if (CFG_CONTROLLER_CYCLE != 0)
                controller_counter = CFG_CONTROLLER_CYCLE - 1; // es dauert 10 Sekunden zum ersten dekrementieren
            else
                controller_counter = 90 - 1; // wenn kein gültiger Wert vorliegt, Standardwert benutzen
            return;
        }
        else
        {
            controller_counter--;
        }
    }
    // ///////////////////////////////////////////////////////////

    // ///////////////////////////////////////////////////////////
    // bei schaltenden Reglern wird nach x Sekunden der Ausgang ausgeschaltet
    if (g_controller_stell_counter > 0)
    {
        g_controller_stell_counter--;

        if (g_controller_stell_counter == 0)
            g_do_disable = 1;
    }

    // ///////////////////////////////////////////////////////////
}

/**
 * führt die PI Berechnung aus und setzt Stellgröße
 */
void controller_process(void)
{
    int soll, stell, takt;

    // Sollwert und Preiodendauer des Reglers ermitteln
    soll = get_sollwert();
    takt = CFG_CONTROLLER_CYCLE;

    stell = cntrlr_step(soll, g_temp_value, takt);

#ifdef DEBUG
    rs_send_s("stell = ");
    rs_send_dec(stell);
    rs_send_s("\n");
#endif

    // stell sollte ein Wert zischen 0 und 100 sein

    if (CFG_CONTROLLER_TYPE == 0 || CFG_CONTROLLER_TYPE == 2)
    {
        // wenn der Reglertyp stetig ist, wird der Wert 'stell' einfach verschickt
        send_value(0, OBJNR_STELL_HEIZEN, stell * 255 / 100);
    }
    else
    {
        // bei schaltendem Reglertyp wird der Regler angeschaltet und dann nach einer Zeit, die
        // durch stell(Prozent) und die Schaltperiode definiert ist wieder ausgeschaltet

        // der Stellwert counter ist der absolute Anteil der Heizperiode zum PI-Berechnungszyklus
        // und berechnet sich aus dem Prozentwert der Stellgröße
        g_controller_stell_counter = takt * stell / 100;

#ifdef DEBUG
        rs_send_s("stell_cnt = ");
        rs_send_dec(g_controller_stell_counter);
        rs_send_s("\n");
#endif

        if (g_controller_stell_counter > 0)
        {
            // anschalten
            g_do_enable = 1;
        }
        else
        {
            // ausschalten
            g_do_disable = 1;
        }
    }
}

/**
* handle received write_value_request frame
*/
void write_value_req(void)
{
    unsigned char   objno;
    int             len, objvalue = 0;

#ifdef DEBUG
//    rs_send_s("write_value_req: ");
//    dump_telegramm();
//    rs_send_s("\n");
#endif

    // Nutzdatenlänge bestimmen
    len = (telegramm[5] & 0x0F) + 1;

    // get object value
    if (len == 1)
    {
        objvalue  = telegramm[5 + len];
    }
    else
    {
        objvalue  = telegramm[5 + len - 1] << 8;
        objvalue |= telegramm[5 + len - 0] << 0;
    }

    // find first object number to received group address
    objno = find_first_objno(telegramm[3], telegramm[4]);
    if (objno != 0xFF)
    {
        // send acknowledge
        send_ack();

        switch (objno)
        {
            case OBJNR_KOMFORTBETRIEB:  set_mode(om_komfort);   break;
            case OBJNR_NACHTBETRIEB:    set_mode(om_nacht);     break;
            case OBJNR_FROSTSCHUTZ:     set_mode(om_frost);     break;
            case OBJNR_STANDBY:         set_mode(om_standby);   break;

            case OBJNR_TASTER:
                // wird nicht unterstützt
                break;

            case OBJNR_SOLLWERT:
            case OBJNR_ISTWERT:
            case OBJNR_STELL_HEIZEN:
            case OBJNR_MELDUNG:
            case OBJNR_STATUS:
                // kann nicht geschrieben werden
                break;

            case OBJNR_BASIS_SOLLWERT:
                // EIS 5 Format in Temperatur konvertieren
                objvalue = eis5_to_temp(objvalue);

                // permanent speichern, der Basis-Sollwert wird mit einer Auflösung von 1 Grad gespeichert
                write_obj_value(OBJNR_BASIS_SOLLWERT, (objvalue + 50) / 100);

                // den durch die Änderung des Basis-Sollwert geänderten aktuellen Sollwert auf den Bus
                // senden
                send_sollwert();
                break;
        }
    }
}

/**
 * handle received read_value_request frame
*/
void read_value_req(void)
{
    unsigned char   objno, objflags;
    int             objvalue;
    operating_mode  mode;

#ifdef DEBUG
//    rs_send_s("read_value_req: ");
//    dump_telegramm();
//    rs_send_s("\n");
#endif

    // find first object number to received group address
    objno = find_first_objno(telegramm[3], telegramm[4]);
    if (objno != 0xFF)
    {
        // send an acknowledge
        send_ack();

        // read object flags
        objflags = read_objflags(objno);

        // objekt lesen, nur wenn read enable gesetzt (Bit3) und Kommunikation zulaessig (Bit2)
        if ((objflags & 0x0C) != 0x0C)
            return;

        switch (objno)
        {
            case OBJNR_KOMFORTBETRIEB:
                mode = get_mode();
                send_value(1, objno, mode == om_komfort);
                break;
            case OBJNR_NACHTBETRIEB:
                mode = get_mode();
                send_value(1, objno, mode == om_nacht);
                break;
            case OBJNR_FROSTSCHUTZ:
                mode = get_mode();
                send_value(1, objno, mode == om_frost);
                break;
            case OBJNR_STANDBY:
                mode = get_mode();
                send_value(1, objno, mode == om_standby);
                break;

            case OBJNR_TASTER:
                // wird nicht unterstützt
                break;

            case OBJNR_SOLLWERT:
                send_sollwert();
                break;

            case OBJNR_ISTWERT:
                // Temperatur in EIS5 umwandeln ...
                objvalue = temp_to_eis5(g_temp_value);
                // ... und senden
                send_value(1, OBJNR_ISTWERT, objvalue);
                break;

            case OBJNR_STELL_HEIZEN:
                // TODO: ...
                break;

            case OBJNR_MELDUNG:
                // TODO: ...
                break;

            case OBJNR_STATUS:
                send_obj_status();
                break;

            case OBJNR_BASIS_SOLLWERT:
                // der Basis-Sollwert wird mit einer Auflösung von 1 Grad gespeichert
                objvalue = read_obj_value(OBJNR_BASIS_SOLLWERT) * 100;
                // ... in EIS5 umwandeln ...
                objvalue = temp_to_eis5(objvalue);
                // ... und senden
                send_value(1, OBJNR_BASIS_SOLLWERT, objvalue);
                break;
        }
    }
}

/**
* reset application parameters
*/
void restart_app(void)
{
    int v;

    // Port Konfigurieren -> input mode
    P0M1= 0x00;
    P0M2= 0x00;

    // initialize variables
    g_do_controller             = 0;
    g_controller_stell_counter  = 0;
    g_do_disable                = 0;
    g_do_enable                 = 0;

    // Regler initialisieren
    if (CFG_CONTROLLER_TYPE <= 1) // 0=PI/stetig, 1=PI/schaltend
    {
        cntrlr_init(cntrlr_pi, CFG_CONTROLLER_PI_PROP, CFG_CONTROLLER_PI_INT);
    }
    else
    {
        cntrlr_init(cntrlr_2p, CFG_CONTROLLER_2P_HYST, 0);
    }

    // Temperatur Sollwert überprüfen/initialisieren
    v = read_obj_value(OBJNR_BASIS_SOLLWERT);
    if (v < 7 || v > 40)
        // der Sollwert ist ungültig, auf default-Wert setzen
        write_obj_value(OBJNR_BASIS_SOLLWERT, CFG_TEMP_SOLL_BASIS);

    EA=0;                       // disable interrupts during flashing
    START_WRITECYCLE;
    WRITE_BYTE(0x01,0x03,0x00)  // manufacturer code 0x0001 = Siemens
    WRITE_BYTE(0x01,0x04,0x01)
    WRITE_BYTE(0x01,0x05,0x21)  // devicetype 0x210B = Raumtemperaturregler UP 252/03 DELTA profil
    WRITE_BYTE(0x01,0x06,0x0B)
    WRITE_BYTE(0x01,0x07,0x04)  // version number of application program
    WRITE_BYTE(0x01,0x0C,0x00)  // PORT A Direction Bit Setting
    WRITE_BYTE(0x01,0x0D,0xFF)  // Run-Status (00=stop FF=run)
    WRITE_BYTE(0x01,0x12,0x62)  // COMMSTAB Pointer
    STOP_WRITECYCLE;

    // TODO: ???
    START_WRITECYCLE;
    WRITE_BYTE(0x00,0x60,0x2E); // system state: all layers active (run), not in prog mode
    STOP_WRITECYCLE;

    EA=1;                       // enable interrupts

#ifdef DEBUG
    rs_send_s("------------------------------------------------------\nUP RTR by semi\n\n");
    rs_send_s(CFG_CONTROLLER_TYPE == 0 ? "PI-stetig\n" :
                                                                                CFG_CONTROLLER_TYPE == 1 ? "PI-schaltend\n" :
                                                                                CFG_CONTROLLER_TYPE == 2 ? "2P-stetig\n" : "2P-schaltend\n");
#if 0
    rs_send_s("Betriebsart                           :");
    switch(CFG_CONTROL_MODE)
    {
        case 1:
            rs_send_s("Heizen\n");
            rs_send_s("Regelverhalten für Heizen             :"); rs_send_s(CFG_CONTROLLER_TYPE == 0 ? "PI-stetig\n" :
                                                                            CFG_CONTROLLER_TYPE == 1 ? "PI-schaltend\n" :
                                                                            CFG_CONTROLLER_TYPE == 2 ? "2P-stetig\n" : "2P-schaltend\n");
            break;
        case 2:
            rs_send_s("Kühlen\n");
            break;
        case 3:
            rs_send_s("Heizen & Kühlen\n");
            break;
        case 5:
            rs_send_s("2-stufiges Heizen\n");
            break;
        case 6:
            rs_send_s("2stufiges Kühlen\n");
            break;
        default:
            break;
    }
    rs_send_s("\n");

    rs_send_s("Basis-Sollwert in 1°C (7-40)          :"); rs_send_dec(CFG_TEMP_SOLL_BASIS); rs_send_s("\n");
    rs_send_s("\n");
    rs_send_s("Aenderung für automat. Senden in 0,1K :"); rs_send_dec(CFG_TEMP_THRESHOLD); rs_send_s("\n");
    rs_send_s("Abgleichrichtung der Istwertmessung   :"); if (CFG_TEMP_ADAP_DIRECTION == 0) rs_send_s("anheben\n"); else rs_send_s("absenken\n");
    rs_send_s("Offset zur Istwertmessung in 0,1K     :"); rs_send_dec(CFG_TEMP_ADAP_VALUE); rs_send_s("\n");
#endif
//    rs_send_s("FA = ");   rs_send_dec(eeprom[0xFA]);
//    rs_send_s("\n");
#endif
}

/**
* generic send function; determine group address for an object and send to the bus
*/
void send_value(unsigned char requested, unsigned char objno, unsigned int sval)
{
    unsigned int ga;
    unsigned char objtype;

    ga = find_ga(objno);
    if (ga != 0)
    {
        // there is a valid group address

        do
        {
            interrupted = 0;

            telegramm[0] = 0xBC;
            telegramm[1] = eeprom[ADDRTAB+1];
            telegramm[2] = eeprom[ADDRTAB+2];
            telegramm[3] = ga>>8;
            telegramm[4] = ga;
            telegramm[6] = 0x00;

            if (requested == 1)
                telegramm[7] = 0x40;       // read_value_response frame (requested)
            else
                telegramm[7] = 0x80;       // write_value_request frame (not requested)

            objtype = read_obj_type(objno);

            if (objtype <= 5)          // 1-6 Bit
            {
                telegramm[5]  = 0xE1;
                telegramm[7] += sval;
            }
            else if (objtype <=7)      // 7-8 Bit
            {
                telegramm[5] = 0xE2;
                telegramm[8] = sval;
            }
            else if (objtype <= 8)     // 16 Bit
            {
                telegramm[5] = 0xE3;
                telegramm[8] = sval>>8;
                telegramm[9] = sval;
            }

            EX1=0;
        } while (interrupted);

        send_telegramm();
        IE1=0;
        EX1=1;

    }
}

/**
 * Betriebsmodus setzen, speichert den Modus im eeprom
 */
void set_mode(operating_mode mode)
{
    operating_mode mode_old;

    // prüfen ob sich der Mode geändert hat
    mode_old = get_mode();
    if (mode_old == mode)
        return;

    // alten Mode deaktivierung ...
    write_obj_value(GET_OBJNR_FROM_MODE(mode_old), 0);
    // ... und neuen Mode aktivieren
    write_obj_value(GET_OBJNR_FROM_MODE(mode),     1);

    // den durch die Mode-Änderung geänderten aktuellen Sollwert auf den Bus senden
    send_sollwert();
}

/**
 * aktuellen Betriebmodus bestimmen
 */
operating_mode get_mode()
{
    int v;

    v = read_obj_value(OBJNR_KOMFORTBETRIEB);
    if (v == 1)
        return om_komfort;

    v = read_obj_value(OBJNR_NACHTBETRIEB);
    if (v == 1)
        return om_nacht;

    v = read_obj_value(OBJNR_FROSTSCHUTZ);
    if (v == 1)
        return om_frost;

    v = read_obj_value(OBJNR_STANDBY);
    if (v == 1)
        return om_standby;

    // default Wert
    return om_komfort;
}

/**
 * gibt den Sollwert abhängig von der Betriebsart und dem eingestellten Basiswert zurück
 *
 * @return   in 1/100 Grad
 */
int get_sollwert(void)
{
    operating_mode mode;
    int objvalue;

    mode = get_mode();
    if (mode == om_frost)
    {
        // aus der config holen (mit Auflösung von 1 Grad)
        objvalue = CFG_FROST_SOLL * 100;
    }
    else
    {
        // der Basis-Sollwert wird mit einer Auflösung von 1 Grad gespeichert
        objvalue = read_obj_value(OBJNR_BASIS_SOLLWERT) * 100;

        if (mode == om_standby)
            // Absenkung aus der config holen (mit Auflösung 0,1 K)
            objvalue -= CFG_REDUCT_STANDBY * 10;
        else if (mode == om_nacht)
            // Absenkung aus der config holen (mit Auflösung 0,1 K)
            objvalue -= CFG_REDUCT_NIGHT * 10;
    }

    return objvalue;
}

/**
 * das Status Objekt senden in Abhängigkeit der Objekt-Konfiguration
 */
void send_obj_status(void)
{
    unsigned char status;
    operating_mode mode;

    mode    = get_mode();

    switch (CFG_OBJ_STATUS)
    {
        case 0: // Komfortbetrieb EIS1
            send_value(1, OBJNR_STATUS, mode == om_komfort);
            break;

        case 1: // Standbybetrieb EIS1
            send_value(1, OBJNR_STATUS, mode == om_standby);
            break;

        case 2: // Nachtbetrieb EIS1
            send_value(1, OBJNR_STATUS, mode == om_nacht);
            break;

        case 3: // Frost-/Hitzeschutz EIS1
            send_value(1, OBJNR_STATUS, mode == om_frost);
            break;

        case 4: // Taupunktbetrieb EIS1
            // NIEMALS im Taupunktbetrieb
            send_value(1, OBJNR_STATUS, 0);
            break;

        case 5: // Heizbetrieb EIS1
            // IMMER im Heizbetrieb
            send_value(1, OBJNR_STATUS, 1);
            break;

        case 6: // Regler inaktiv-Betrieb EIS1
            // TODO: ...
            break;

        case 7: // Frostalarm EIS1
            // NIEMALS Frostalarm
            send_value(1, OBJNR_STATUS, 0);
            break;

        case 8: // Regler Status EIS6
            // bit 0 = Komfort-Betrieb Ein
            // bit 1 = Standby-Betrieb Ein
            // bit 2 = Nacht-Betrieb Ein
            // bit 3 = Frost-/Hitzeschutz-Betrieb Ein
            // bit 4 = Taupunktalarm
            // bit 5 = Heizbetrieb
            // bit 6 = Regler Ein
            // bit 7 = Frostalarm
            status = 0x20; // bit 5 ist immer Ein
            status |= mode;
            // TODO: bit 6
            send_value(1, OBJNR_STATUS, status);
            break;

        default: break;
    }
}

/**
 * den aktuellen Sollwert auf den Bus senden
 */
void send_sollwert(void)
{
    int sollwert;

    // Sollwert abfragen ...
    sollwert = get_sollwert();
    // ... in EIS5 umwandeln ...
    sollwert = temp_to_eis5(sollwert);
    // ... und senden
    send_value(1, OBJNR_SOLLWERT, sollwert);
}

#ifdef DEBUG
/**
 * Telegramm als Hex Werte auf der Konsole ausgeben
 */
static void dump_telegramm(void)
{
//    unsigned char i, len;
//
//    len = (telegramm[5] & 0x0F) + 1;
//
//    for (i = 0; i < 23; i++)
//    {
//        if (i <= 5)
//        {
//            rs_send_hex(telegramm[i]);
//        }
//        else if (len >= i-6)
//        {
//            rs_send_hex(telegramm[i]);
//        }
//
//        rs_send_s(" ");
//    }
}
#endif
