#include "encoder_komplex.h"

uint8_t Encoder::encoder_value = 0;

void Encoder::encoder_init(){
	Encoder encoder;
	uint8_t position_init;
	DDRD &= ~((1<<PIN_A)|(1<<PIN_B));				//Set Inputs
	PORTD |= (1<<PIN_A)|(1<<PIN_B);					//Set pull-ups for Inputs

	PCICR |= (1<<PCIE2);							//Activate PinChange Interrupt PCINT16-23
	PCMSK2 |= (1<<PCINT18)|(1<<PCINT19);			//set mask for used input interrupt signals
	sei();
	
	position_init = encoder.get_position();
	if (position_init == 0){encoder.state = 0;}
	else if (position_init == 12){encoder.state = 1;}
}

uint8_t Encoder::get_position(){
	uint8_t _position_A = (PIND & (1<<PIN_A));		//read PIN A
	uint8_t _position_B = (PIND & (1<<PIN_B));		//read PIN B

	return _position_A + _position_B;				//0;4;8;12
}


ISR(PCINT2_vect){
	static Encoder encoder;												//Set class variable
	
	static uint8_t previouse_position;								//define last position variable
	
	uint8_t current_position = encoder.get_position();				//get current position 0,4,8,12
	

	if(current_position == 0 && previouse_position == 8){PORTB ^= (1<<PB0);}
	else if(current_position == 12 && previouse_position == 4){PORTB ^= (1<<PB0);}
	else if(current_position == 0 && previouse_position == 4){PORTB ^= (1<<PB0);}
	else if(current_position == 12 && previouse_position == 8){PORTB ^= (1<<PB0);}
		
		
	previouse_position = current_position;							//save current position as last
	
}


