// Application: Controlling 3 LEDs with 3 Buttons

// This application simulates a simple digital control system where three push-buttons are used to control the state of three LEDs independently. 
// Each button corresponds to a specific LED, allowing users to turn the LED on or off by pressing the associated button.

#include "Dio.h"

#define BUTTONS_PORT PORTA
#define LEDS_PORT PORTB

#define BUTTON1_PIN 0
#define BUTTON2_PIN 1
#define BUTTON3_PIN 2

#define LED1_PIN 0
#define LED2_PIN 1
#define LED3_PIN 2



