/*
#include "DIO.h"

// Define ports and pins for the LED and Button
#define LED_PORT    MDIO_PORTA
#define LED_PIN     MDIO_PIN0

#define BUTTON_PORT MDIO_PORTB
#define BUTTON_PIN  MDIO_PIN0

int main(void)
{
	int res;
    // Configure the LED pin as output
    MDIO_enuSetPinConfigration(LED_PORT, LED_PIN, MDIO_OUTPUT);

    // Configure the Button pin as input pull-up
    MDIO_enuSetPinConfigration(BUTTON_PORT, BUTTON_PIN, MDIO_INPUT_PULLUP);

    u8 buttonState = 0;

    while (1)
    {
        // Read Button state
        MDIO_enuGetPinValue(BUTTON_PORT, BUTTON_PIN, &buttonState);

        // Control the LED based on the Button state
        if (buttonState == 0) // Button pressed (assuming active low)
        {
            MDIO_enuSetPinValue(LED_PORT, LED_PIN, MDIO_HIGH); // Turn on the LED
        }
        else
        {
            MDIO_enuSetPinValue(LED_PORT, LED_PIN, MDIO_LOW); // Turn off the LED
        }
    }

    return 0;
}
*/

#define F_CPU 1000000UL
#include "DIO.h"
#include <util/delay.h>

#define LEDS_PORT   MDIO_PORTA
#define BUTTON_PORT MDIO_PORTB
#define BUTTON_PIN  MDIO_PIN0

int main(void)
{
	MDIO_enuErrorStatus_t result;

	// Initialization of PORT A as output for LEDs 
	result = MDIO_enuSetPortDir(MDIO_PORTA, MDIO_PORT_OUTPUT);

	// Initialization of Port B Pin 0 as input pull-up for the button 
	result = MDIO_enuSetPinConfigration(BUTTON_PORT, BUTTON_PIN, MDIO_INPUT_PULLUP);

	u8 pinVal = MDIO_HIGH;        // To store the current button state
	u8 prevPinVal = MDIO_HIGH;    // To store the previous button state
	u8 counterActive = 0;         // Flag to track whether the counter is active
	u8 counter = 0;               // Binary counter value

	while (1)
	{
		// Read the current state of the button 
		MDIO_enuGetPinValue(BUTTON_PORT, BUTTON_PIN, &pinVal);

		// Detect falling edge (button press, active-low) 
		if (pinVal == MDIO_LOW && prevPinVal == MDIO_HIGH)
		{
			counterActive = !counterActive; // Toggle the counter state
		}

		// Update the previous button state 
		prevPinVal = pinVal;

		if (counterActive)
		{
			// Display the counter value on LEDs 
			MDIO_enuSetPortValue(MDIO_PORTA, counter);

			// Increment the counter 
			counter++;

			// Add delay for visibility 
			_delay_ms(500);
		}
	}

	return 0;
}
