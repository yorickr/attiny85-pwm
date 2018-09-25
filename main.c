#include <avr/io.h>
#include <util/delay.h>

#define LED      PB0
#define BIT(x) (1 << (x))

int main () {
	// setup LED pin for output in port B's direction register
	DDRB |= BIT(LED);

	// set LED pin LOW
	PORTB &= ~(BIT(LED));


	// // Control behaviour of OC0A, so our pin.
	// TCCR0A |= BIT(COM0A1); // Clear OC0A on Compare Match, set OC0A at BOTTOM.
	

	// // Fast PWM from BOTTOM to OCRA
	// TCCR0A |= BIT(WGM00); // Control counting sequence of the cnt, source of TOP,
	// TCCR0A |= BIT(WGM01);
	// // TCCR0B |= BIT(WGM02);

	// // Select clock
	// TCCR0B |= BIT(CS02);
	// TCCR0B |= BIT(CS00);

	// // Set value for compare
	// OCR0A = 1;

	//make sure output happens on correct pin, albeit inverted
	TCCR1 |= BIT(COM1A0);
	
	// Enable comparator OCR1A
	TCCR1 |= BIT(PWM1A);

	// Set clock
	TCCR1 |= 0b1111 << CS10; // div 16k
	
	// freq = 8MHz / 16k / OCR1C+1

	unsigned char size = 80;
	OCR1A = size;
	OCR1C = size*2;


	while (1) {	
	}

	return 0;
}

