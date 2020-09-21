#include <avr/io.h>

void delay(){
	int time = 100000;
	while(time--);
}

int main(void){
	DDRB = 0xFF;

	while(1){
		PORTB = 0b00000001;
		delay();
		PORTB = 0b00000010;
		delay();
		PORTB = 0b00000100;
		delay();
		PORTB = 0b00001000;
		delay();
		PORTB = 0b00010000;
		delay();
		PORTB = 0b00100000;
		delay();
		PORTB = 0b01000000;
		delay();
		PORTB = 0b10000000;
		delay();
	}
}
