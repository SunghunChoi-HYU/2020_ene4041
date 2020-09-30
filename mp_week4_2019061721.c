#include<avr/io.h>

#define FND_C0 0x01
#define FND_C1 0x02
#define FND_C2 0x04
#define FND_C3 0x08

const char Font[17] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00};

void delay(unsigned long x){
	while(x--);
}

int main(void){
	unsigned int a, b, c, d;
	DDRB = 0xFF;
	DDRG = 0xFF;
	
	PORTB = 0x00;
	PORTG = 0xFF;
	
	for (a = 0; a < 10; a++){
		for(b = 0; b < 10; b++){
			for(c = 0; c < 10; c++){
				for(d = 0; d < 10; d++){
				 	PORTG |= 0x0F;
					PORTG &= ~FND_C3;
					PORTB = Font[a];
					delay(100);

					PORTG |= 0x0F;
					PORTG &= ~FND_C2;
					PORTB = Font[b];
					delay(100);

					PORTG |= 0x0F;
					PORTG &= ~FND_C1;
					PORTB = Font[c];
					delay(100);

					PORTG |= 0x0F;
					PORTG &= ~FND_C0;
					PORTB = Font[d];
					delay(100);

					delay(10000);
				}
			}
		}
	}

}
