Die Firmware out ersetzt die beiden Versionen out8 und out4.

Um das richtige hex-file für die entsprechende Anwendung zu erzeugen müssen in der fb_app_out.h folgende Parameter richtig gesetzt sein:

#define GS1   		für die alte Relaisplatine 8.1 ohne den 74HC573
#define GS2   		für die neue Relaisplatine ab 8.2 mit 74HC573

#define HAND		für die Handsteuerung, wenn nicht erforderlich einach auskommentieren

#define MAX_PORTS_8	für den 8-fach Aktor
#define MAX_PORTS_4	für den 4-fach Aktor

#define SPIBISTAB	Serielle Ausgabe für bistabile relaise aktivieren
