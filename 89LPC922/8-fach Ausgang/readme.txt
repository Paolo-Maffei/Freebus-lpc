Dies ist ein EIB-RS232 Interface auf Basis des LPC-Controllerboards.

Die Schnittstelle ist auf 115.200 Baud,n,8,1 eingestellt. 

Folgende Kommandos können an das Interface gesendet werden:


fbs01/BB/L/TTT=0 oder 1 gefolgt von CR LF: sendet ein EIS1 Telegramm auf den Bus

	BB/L/TTT ist die Gruppenadresse genau in dem Format
	Beispiel: fbs01/01/4/007=1[CR][LF] schaltet Gruppenadresse 1/4/7 ein

weiteres folgt...