/**
* @file   mcp3204.c
* @author Jan Wegner
* @author Rico Markus
* @date   2011
*
* @brief  Software SPI zur Anbindung des ADC
*
*
*/

#include <P89LPC922.h>
#include "mcp3204.h"


/*
 * Datenfeld für Lookup-Tabelle
 *
 * xs-Werte sind Werte des ADCs
 * ys-Werte sind bereits umgewandelte Werte für den enstsprechenden Druck
 * Intitalisieren ist wegen Speicherplatzzuweisung außerhalb der Funktion notwendig
 */
/* NOTE: xs MUST be sorted */
static const int xs[] = {0, 40, 80, 120, 160, 200, 240, 280, 320, 360, 400, 440, 480, 520, 560, 600, 640, 680, 720, 760, 800, 840, 880, 920, 960, 1000, 1040, 1080, 1120, 1160, 1200, 1240, 1280, 1320, 1360, 1400, 1440, 1480, 1520, 1560, 1600, 1640, 1680, 1720, 1760, 1800, 1840, 1880, 1920, 1960, 2000, 2040, 2080, 2120, 2160, 2200, 2240, 2280, 2320, 2360, 2400, 2440, 2480, 2520, 2560, 2600, 2640, 2680, 2720, 2760, 2800, 2840, 2880, 2920, 2960, 3000, 3040, 3080, 3120, 3160, 3200, 3240, 3280, 3320, 3360, 3400, 3440, 3480, 3520, 3560, 3600, 3640, 3680, 3720, 3760, 3800, 3840, 3880, 3920, 3960, 4000, 4040, 4080, 4120};
static const int ys[] = {0, 18, 19, 19, 21, 23, 26, 30, 35, 40, 47, 55, 64, 74, 85, 98, 112, 127, 144, 162, 182, 203, 226, 250, 276, 303, 333, 364, 396, 431, 467, 506, 546, 588, 632, 678, 726, 776, 828, 882, 938, 996, 1057, 1120, 1185, 1252, 1321, 1393, 1467, 1543, 1622, 1703, 1787, 1873, 1961, 2052, 2145, 2241, 2340, 2441, 2544, 2650, 2759, 2871, 2985, 3102, 3221, 3343, 3468, 3596, 3727, 3860, 3996, 4135, 4277, 4422, 4570, 4720, 4874, 5031, 5190, 5353, 5518, 5687, 5858, 6033, 6211, 6392, 6576, 6763, 6953, 7147, 7344, 7544, 7747, 7953, 8163, 8376, 8592, 8812, 9035, 9261, 9491, 9724};


/**
* Anpassen des ADC Wertes //Umrechnen in Druckwert
*
* \param kanal
*
* @return
*/

int read_strom(unsigned char kanal)
{
	int result=0;
	int help=0;

	help=read_adc(kanal); //Lesen vom ADC
	result=get_value(help); //Umrechnen des ADC-Wert in Gramm


	return(result);

}

/**
* Einlesen des ADC Wertes
*
* \param kanal
*
* @return
*/

int read_adc(unsigned char kanal)
{
	unsigned char n;
	int daten=0;
	unsigned char command;



	//command = 0x30 + kanal<1;
	command = 0x39; // 00111001 //Code zum Initialisieren des ADCs
	command+=kanal<<1;

	SPI_CLK=1;

	delay(32);

	SPI_CS =0;

	delay(32);

	for(n=0;n<=7;n++) //ADC wird initialisiert
	{
		SPI_CLK=0;

		delay(32);

		SPI_IN=(command&0x80)>>7;
		command<<=1;
		SPI_CLK=1;


	}

	delay(32);

	for(n=0;n<=13;n++) //Daten werden vom ADC gelesen
	{
		SPI_CLK=0;

		delay(32);

		daten<<=1;
		daten+=SPI_OUT;
		SPI_CLK=1;
	}

	delay(32);

	SPI_CS = 1;

	daten>>=1;

	return(daten);
}

/**
* Zeitverzögerung
*
* Wird für passendes CLK Signal benötigt
*
* \param w
*
* @return
*/


void delay(int w)	// delay ca. 4,5µs * w
{
	int n;
	for(n=w;n>0;n--) {}
}


/**
* Umrechnung der ADC-Werte
*
* ADC gibt 0-4096 aus, dies wird in Gramm umgerechnet.
*
* \param x
*
* @return
*/

int get_value(int x)
{

    static const int count = sizeof(xs)/sizeof(xs[0]); //Anzahl der Elemente im Feld

    int i;
    int dx, dy;

    if (x < xs[0]) //Mögliche Fehlerbehandlung wenn x kleiner als minimales Element ist
    {

        return ys[0]; //Minimales Element wird zurückgegeben
    }

    if (x > xs[count-1]) {
        return ys[count-1]; //Maximales Element wird zurückgegeben
    }

    for (i = 0; i < count-1; i++) //Passenden xs Wert finden (xs[i] <= x < xs[i+1])
    {
        if (xs[i+1] > x) {
            break;
        }
    }


    dx = xs[i+1] - xs[i]; //Interpolieren von dx
    dy = ys[i+1] - ys[i]; //Interpolieren von dy
    return ys[i] + (x - xs[i]) * dy / dx; //Rückgabe des Interpolieren ys Wertes entsprechend ADC
}




