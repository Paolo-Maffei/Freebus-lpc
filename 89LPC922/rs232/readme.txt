Dies ist ein EIB-RS232 Interface auf Basis des LPC-Controllerboards.

Die Schnittstelle ist auf 115.200 Baud,n,8,1 eingestellt. 

Vom Bus empfangene Multicast-Telegramme werden in der Form x/x/x=y[CR][LF] an der seriellen Schnittstelle ausgegeben. (z.B. 1/5/27=1)


Folgende Kommandos können an das Interface gesendet werden, jeweils durch ein CR abgeschlossen:


fbs01/BB/L/TTT=0 oder 1 : sendet ein EIS1 Telegramm auf den Bus

	BB/L/TTT ist die Gruppenadresse genau in dem Format 
	Beispiel: fbs01/1/4/7=1[CR] schaltet Gruppenadresse 1/4/7 ein


fbs06/BB/L/TTT=[0..255]	: sendet ein EIS6 Telegramm, z.b. für Dimmwerte


fbs05/BB/L/TTT=[-671 088.64 ... 0 ... 670 760.96]	: sendet ein EIS5 Telegramm, z.b. für Temperatur-, Helligkeitswerte


fbs15/BB/L/TTT=[A-Z,a-z,0-9]	: sendet ein EIS15 Telegramm, für Ascii Texte, max. 14 Zeichen


fbrpa 			: lesen der physikalischen Adresse des Adapters


fbspaXX.XX.XXX 		: Setzt die physikalische Adresse des Adapters 


fbrgaBB/L/TTT		: liest den gespeicherten Wert einer Gruppenadresse aus
	
	Das RS-Interface speichert kontinuierlich die Werte aller Gruppenadressen
	die sie empfängt oder selbst sendet. Und zwar bis zu 256 verschiedene GA, danach
	wird verworfen. (reicht aber dicke...) Man kann jederzeit den Wert auslesen, ohne 
	ein Telegramm auszulösen.

fbdump			: gibt die interne Tabelle der GA aus

fbsbr[115200,57600,19200,9600]: setzt die baudrate der schnittstelle, wird im flash gesichert.

weiteres folgt...