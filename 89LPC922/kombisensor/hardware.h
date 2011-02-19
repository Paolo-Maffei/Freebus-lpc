#ifndef HARDWARE_H_
#define HARDWARE_H_

#define LPC922

#define DS18S20			// für DS18B20 auskommentieren
#define OWDATA	P0_7	// Temp.Sensor an Port 0.7

#define CMPOUT	0x80	// Comparator output zum Laden des Kondensators (0x80=P0.0 in HEX, da in asm verwendet)

#endif /*HARDWARE_H_*/
