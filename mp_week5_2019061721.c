#include <avr/io.h>

int main(void){
	unsigned char input;
	DDRD = 0x00;
	DDRB = 0xFF;

	while(1){
		unsigned char output = 0b00000001;
		input = PIND & 0x0f;

		while(input--){
			output = output * 2;
		}

		PORTB = output;
	}
}
