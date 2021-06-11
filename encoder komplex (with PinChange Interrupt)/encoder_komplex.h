/*
 * encoder_komplex.h
 *
 * Created: 09.06.2021 08:25:11
 * Author : mr_iks
 * Micrcontroller: Atmega328P 16Mhz
 */

/*
************Attantion************
Only for Encoder with this Grey Code!

			A	B
////////////first step///////////////
1.		|	0	0
2.			1	0
////////////second step//////////////
3.			1	1
4.			0	1	
-> return to beginning

*/
#ifndef encoder_komplex_h
#define encoder_komplex_h

#include <avr/interrupt.h>

#define PIN_A	PD2
#define PIN_B	PD3
#define Button	PC5

class Encoder{
	public:
		void encoder_init();
		uint8_t get_position();
		uint8_t get_button_position();
		static uint8_t encoder_value;													
	}; 
	
	#endif