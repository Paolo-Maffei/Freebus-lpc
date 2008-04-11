SNIFFER-TOOL

This is the soft for the LPC. In combination with the PC-Soft 'snifhelp' you can easily identify changes
in the eeprom area of a device. This LPC-soft waits for a single byte at the serial interface. This is
the address in the eeprom-area 0x100 through 0x1FF. It then returns as a single byte the content.

Usage:
This soft represents a prototype body of an eib-device. In the appliction layer 'fb_app_snif.c' you have
to set the devices parameters accordingly. They are located in the restart_app function. You then can program
this dummy-device via ets. Every changed byte is shown in red. So you can easily see what impact a changed parameter
in ets has in the eeprom-area.

much fun with this

kubi