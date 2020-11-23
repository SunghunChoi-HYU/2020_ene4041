#include <avr/io.h>
#include <avr/interrupt.h>

#define FND_C0 0x01
#define FND_C1 0x02
#define FND_C2 0x04
#define FND_C3 0x08
int i = 0;

const char Font[17] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00};

unsigned char digit0 = 0;
unsigned char digit1 = 0;
unsigned char digit2 = 0;
unsigned char digit3 = 0;

void delay(unsigned long x){
	while(x--);
}

void fnd_display(unsigned char digit0, unsigned char digit1, unsigned char digit2, unsigned char digit3){
	PORTG = 0x0F;
	PORTG &= ~FND_C0;
	PORTB = Font[digit0];
	delay(100);

	PORTG = 0x0F;
	PORTG &= ~FND_C0;
	PORTB = Font[digit1];
	delay(100);

	PORTG = 0x0F;
	PORTG &= ~FND_C0;
	PORTB = Font[digit2];
	delay(100);

	PORTG = 0x0F;
	PORTG &= ~FND_C0;
	PORTB = Font[digit3];
	delay(100);
}

SIGNAL(SIG_INTERRUP1){
	while(!SIGNAL(SIG_INTERRUP1){
		delay(100);
	}
	i = 0;
}

int main(void){
	DDRB = 0xFF;
	DDRG = 0xFF;
	PORTB = 0x00;
	PORTG = 0xFF;

	EIMSK = 0x02;
	EICRA = 0x02;
	EICRB = 0x00;

	sei();

	for(i = 0; i < 9999; i++){
		digit0 = i / 1000;
		digit1 = (i % 1000) / 100;
		digit2 = ((i % 1000) % 100) / 10;
		digit3 = ((i % 1000) % 100) % 10;

		fnd_display(digit0, digit1, digit2, digit3);
	}
}
