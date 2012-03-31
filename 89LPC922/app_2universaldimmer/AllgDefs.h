#ifndef FB_ALLG_DEFS
#define FB_ALLG_DEFS

#define AnzahlKanaele 2
#define KANAL1 0
#define KANAL2 1

// die folgenden Variablen werden �ber Aufrufparameter gesetzt, so dass �ber verschiedene
// Build-Konfigurationen f�r verschiedene CPUs kompiliert werden kann
//#define LPC922
//#define LPC936

// ab V1.6.0 AN= 1  past f�r Hardware ab V1.4
//#define AlteAnsteuerung
#ifdef AlteAnsteuerung
	#define LAST_AN 0
	#define LAST_AUS 1
#else
	#define LAST_AN 1
	#define LAST_AUS 0
#endif

// Definition der Befehle der TimerWarteschlange
#define BEF_NOTHING 0
#define BEF_EIN	8
#define BEF_AUS	9

//#define BYTE unsigned char
#define false 0
#define true  1

#define ABSCHNITT 1
#define ANSCHNITT 0

#define SET_BIT(Byte,Bit) {Byte |= (1<<Bit);}
#define CLR_BIT(Byte,Bit) {Byte &= ~(1<<Bit);}

#define MSB(x) (x>>8)
#define LSB(x) (x)

#define MSN(x) (x>>4)
#define LSN(x) (x&0x0F)


typedef unsigned char byte;
typedef unsigned int  uint;
typedef unsigned long ulong;

#endif
