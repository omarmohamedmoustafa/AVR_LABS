/*
* GccApplication3.c
*
* Created: 12/11/2024 3:30:00 PM
* Author : Omar_
*/
#define F_CPU 1000000UL

#define SET_BIT(reg, bit)       reg |= (1 << (bit))
#define CLR_BIT(reg, bit)       reg &= ~(1 << (bit))
#define GET_BIT(reg, bit)       ((reg >> (bit)) & 1)

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Configure PORTB,0 to PORTB,3 as outputs for the LEDs
	SET_BIT(DDRB, 0);
	SET_BIT(DDRB, 1);
	SET_BIT(DDRB, 2);
	SET_BIT(DDRB, 3);

	// Configure PORTB,4 as input for the button with internal pull-up enabled
	CLR_BIT(DDRB, 4);
	SET_BIT(PORTB, 4);

	// Initialize LEDs to OFF
	PORTB &= 0xF0;

	uint8_t count = 0;

	while (1)
	{
		// Check if button is pressed (active low)
		if (!GET_BIT(PINB, 4))
		{
			_delay_ms(50); // Debounce delay
			if (!GET_BIT(PINB, 4)) // Check again after debounce
			{
				// Increment the counter and wrap around after 15
				count = (count + 1) % 16;

				// Update LEDs based on the counter value
				PORTB = (PORTB & 0xF0) | (count & 0x0F);

				// Wait until the button is released
				while (!GET_BIT(PINB, 4));

				_delay_ms(50); // Debounce delay after release
			}
		}
	}
}
