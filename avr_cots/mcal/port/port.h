#ifndef PORT_H_
#define PORT_H_
#include "platform_types.h"

/* Error Status Enum */
typedef enum {
	MPORT_OK,              // Operation successful
	MPORT_NOK,             // Operation failed
	MPORT_INVALID_PIN,     // Invalid pin number
	MPORT_INVALID_PORT,     // Invalid port number
	MPORT_INVALID_PIN_MODE, // invalid mode for pin
	MPORT_INVALID_PIN_CONFIG,
	MPORT_ERROR_INVALID_PIN,
	MPORT_ERROR_INVALID_DIRECTION,
	MPORT_ERROR_INVALID_MODE,
	MPORT_ERROR_UNCHANGEABLE_MODE,
    MPORT_INVALID_PARAM

} MPORT_enuErrorStatus_t;

// enum for pin modes
typedef enum {
	PORT_PIN_MODE_INPUT_PULLUP,
	PORT_PIN_MODE_INPUT_PULLDOWN,
	PORT_PIN_MODE_UART,
	PORT_PIN_MODE_SPI,
	// Add other modes as needed
} MPORT_enuPinMode_t;

#define MPORT_PINA0 0x00
#define MPORT_PINA1 0x01
#define MPORT_PINA2 0x02
#define MPORT_PINA3 0x03
#define MPORT_PINA4 0x04
#define MPORT_PINA5 0x05
#define MPORT_PINA6 0x06
#define MPORT_PINA7 0x07

#define MPORT_PINB0 0x10
#define MPORT_PINB1 0x11
#define MPORT_PINB2 0x12
#define MPORT_PINB3 0x13
#define MPORT_PINB4 0x14
#define MPORT_PINB5 0x15
#define MPORT_PINB6 0x16
#define MPORT_PINB7 0x17

#define MPORT_PINC0 0x20
#define MPORT_PINC1 0x21
#define MPORT_PINC2 0x22
#define MPORT_PINC3 0x23
#define MPORT_PINC4 0x24
#define MPORT_PINC5 0x25
#define MPORT_PINC6 0x26
#define MPORT_PINC7 0x27

#define MPORT_PIND0 0x30
#define MPORT_PIND1 0x31
#define MPORT_PIND2 0x32
#define MPORT_PIND3 0x33
#define MPORT_PIND4 0x34
#define MPORT_PIND5 0x35
#define MPORT_PIND6 0x36
#define MPORT_PIND7 0x37

#define MPORT_INPUT 0
#define MPORT_OUTPUT 1
#define MPORT_INPUT_PULLUP 2


/* Bit Manipulation Macros */


#define MPORT_HIGH 1
#define MPORT_LOW  0
#define MPORT_ENABLED 1
#define MPORT_DISABLED 0

/* AVR Register Mapping */
#define PORTA_REG (*((volatile u8 *)0x3B))
#define DDRA_REG  (*((volatile u8 *)0x3A))
#define PINA_REG  (*((volatile u8 *)0x39))

#define PORTB_REG (*((volatile u8 *)0x38))
#define DDRB_REG  (*((volatile u8 *)0x37))
#define PINB_REG  (*((volatile u8 *)0x36))

#define PORTC_REG (*((volatile u8 *)0x35))
#define DDRC_REG  (*((volatile u8 *)0x34))
#define PINC_REG  (*((volatile u8 *)0x33))

#define PORTD_REG (*((volatile u8 *)0x32))
#define DDRD_REG  (*((volatile u8 *)0x31))
#define PIND_REG  (*((volatile u8 *)0x30))

/* Public Functions */

/*********************************************************************/
//function name: MPORT_vINIT
//function arguments: void
//function return: void
//function functionality: initialize the port
/*********************************************************************/
void MPORT_vINIT();


/*********************************************************************/
//function name: MPORT_enuSetPinDirection
//function arguments: u8 Copy_enuPinNum, u8 Copy_enuPinDirection
//function return: MPORT_enuErrorStatus_t
//function functionality: set the direction of the pin
/*********************************************************************/
MPORT_enuErrorStatus_t MPORT_enuSetPinDirection(u8 Copy_enuPinNum, u8 Copy_enuPinDirection);

#endif //PORT_H_