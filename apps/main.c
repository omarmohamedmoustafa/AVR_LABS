/*
* GccApplication2.c
*
* Created: 12/11/2024 2:09:10 PM
* Author : Omar_
*/
#define F_CPU 1000000UL

#define SET_BIT(reg,bit)        reg |= (1<<(bit))
#define CLR_BIT(reg,bit)        reg &=~(1<<(bit))
#define GET_BIT(reg,bit)        ((reg>>bit) & 1 )

typedef unsigned char        u8 ;
typedef unsigned short int    u16;
typedef unsigned long int     u32;

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Configure PORTB,0 as output for LED
	SET_BIT(DDRB, 0);
	// Configure PORTB,1 as input for button and enable internal pull-up
	CLR_BIT(DDRB, 1);
	SET_BIT(PORTB, 1);

	while (1)
	{
		// Check if the button is pressed (active low)
		if (!GET_BIT(PINB, 1))
		{
			// Turn on the LED
			SET_BIT(PORTB, 0);
		}
		else
		{
			// Turn off the LED
			CLR_BIT(PORTB, 0);
		}
	}
}
