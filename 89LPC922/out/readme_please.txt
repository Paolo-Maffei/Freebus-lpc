Die Firmware out ersetzt die beiden Versionen out8 und out4.

Um das richtige hex-file f�r die entsprechende Anwendung zu erzeugen m�ssen in der fb_app_out.h folgende Parameter richtig gesetzt sein:

#define GS1   		f�r die alte Relaisplatine 8.1 ohne den 74HC573
#define GS2   		f�r die neue Relaisplatine ab 8.2 mit 74HC573

#define HAND		f�r die Handsteuerung, wenn nicht erforderlich einach auskommentieren

#define MAX_PORTS_8	f�r den 8-fach Aktor
#define MAX_PORTS_4	f�r den 4-fach Aktor

