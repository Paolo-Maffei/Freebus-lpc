Dies ist ein EIB-RS232 Interface auf Basis des LPC-Controllerboards.

Die Schnittstelle ist auf 115.200 Baud,n,8,1 eingestellt.

Alle EIS1 Telegramme, die andere Teilnehmer auf den Bus senden, werden in der Form xx/x/xxx=x seriell
ausgegeben.

Folgende Kommandos können an das Interface gesendet werden, jeweils durch ein CR LF abgeschlossen:


fbs01/BB/L/TTT=0 oder 1 : sendet ein EIS1 Telegramm (an/aus) auf den Bus

	BB/L/TTT ist die Gruppenadresse genau in dem Format (ggf. mit Nullen auffüllen!)
	Beispiel: fbs01/01/4/007=1[CR][LF] schaltet Gruppenadresse 1/4/7 ein


fbs06/BB/L/TTT=000 bis 255 : sendet ein EIS6 Telegramm (0% bis 100%) auf den Bus

	BB/L/TTT ist die Gruppenadresse genau in dem Format (ggf. mit Nullen auffüllen!)
	Beispiel: fbs01/01/3/002=064[CR][LF] dimmt die Lampe an Gruppenadresse 1/3/2 auf 25%


fbrpa 			: lesen der physikalischen Adresse des Adapters


fbspaXX.XX.XXX 		: Setzt die physikalische Adresse des Adapters (ggf. mit Nullen auffüllen!)



weiteres folgt...