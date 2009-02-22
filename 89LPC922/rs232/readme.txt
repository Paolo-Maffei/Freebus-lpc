Dies ist ein EIB-RS232 Interface auf Basis des LPC-Controllerboards.

Die Schnittstelle ist auf 115.200 Baud,n,8,1 eingestellt. 

Vom Bus empfangene Multicast-Telegramme werden in der Form x/x/x=y[CR][LF] an der seriellen Schnittstelle ausgegeben. (z.B. 1/5/27=1)


Folgende Kommandos können an das Interface gesendet werden, jeweils durch ein CR LF abgeschlossen:


fbs01/BB/L/TTT=0 oder 1 : sendet ein EIS1 Telegramm auf den Bus

	BB/L/TTT ist die Gruppenadresse genau in dem Format (ggf. mit Nullen auffüllen!)
	Beispiel: fbs01/01/4/007=1[CR][LF] schaltet Gruppenadresse 1/4/7 ein


fbs06/BB/L/TTT=[0..255]	: sendet ein EIS6 Telegramm, z.b. für Dimmwerte


fbrpa 			: lesen der physikalischen Adresse des Adapters


fbspaXX.XX.XXX 		: Setzt die physikalische Adresse des Adapters (ggf. mit Nullen
			  auffüllen!)


fbrgaBB/L/TTT		: liest den gespeicherten Wert einer Gruppenadresse aus
	
	Das RS-Interface speichert kontinuierlich die Werte aller Gruppenadressen
	die sie empfängt oder selbst sendet. Und zwar bis zu 256 verschiedene GA, danach
	wird verworfen. (reicht aber dicke...) Man kann jederzeit den Wert auslesen, ohne 
	ein Telegramm auszulösen.

fbdump			: gibt die interne Tabelle der GA aus


weiteres folgt...