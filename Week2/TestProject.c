#include <avr/io.h>

int main(void){
	DDRA = 0xFE;
	PORTA = 0xFE;

	return 0;
}
