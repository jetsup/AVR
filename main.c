#define __AVR_ATmega32U4__
#include <avr/io.h>
#include <util/delay.h>

// MACROS
#define togglePin13() PORTB = PORTB ^ (1 << PB5) // PORTB ^= (1 << PB5);
#define togglePin13on() PORTB = PORTB | (1 << PB5)
#define togglePin13off() PORTB = PORTB & ~(1 << PB5)

int main(void)
{
	// DDRB = 0xff; // direction output of ALL the pins in PORTB
	DDRB = DDRB | (1 << PB5); // direction output for 'PB5'
	DDRB &= ~(1 << PB0);	  // input
	PORTB |= (1 << PB0);	  // pull PB0 HIGH

	while (1)
	{
		if ((PINB & (1 << PB0)) == (1 << PB0)) // if PB0 == HIGH
		{
			togglePin13off();
			continue;
		}
		else
		{
			togglePin13on();
		}
		// Blink Sketch
		// PORTB |= (1<<PB5);
		// _delay_ms(1000);
		// PORTB &= ~(1 << PB5);
		// _delay_ms(1000);
	}
}
