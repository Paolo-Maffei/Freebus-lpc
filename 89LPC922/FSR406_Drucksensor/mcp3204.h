/**
* @file   mcp3204.h
* @author Jan Wegner
* @author Rico Markus
* @date   2011
*
* @brief  Software SPI zur Anbindung des ADC
*
*
*/

#ifndef MCP3204_H_ ///Überprüfen ob dieser Header schon gelinkt wurde
#define MCP3204_H_


#define SPI_CS P0_3 ///Pin 0_3 ist Chip Select
#define SPI_IN P0_2 ///Pin 0_2 ist Serial Data In
#define SPI_OUT P0_1 ///Pin 0_1 ist Serial Data Out
#define SPI_CLK P0_0 ///Pin 0_0 ist Serial Clock

//hier muss noch IN und OUT getauscht werden falls was funktioniert

int read_strom(unsigned char kanal);
int read_adc(unsigned char kanal);
int get_value(int help); //Umrechnung in kg


void delay(int w);



#endif /* MCP3204_H_ */
