
#include "port.h"
#include "port_config.h"
extern MPORT_PinCfg_t PinCfg[];

void MPORT_portInit()
{
	for (u8 i = 0; i < TOTAL_PINS; i++)
	{
		MPORT_enuErrorStatus_t status =MPORT_enuSetPinDirection(PinCfg[i].port_pin, PinCfg[i].dir);
        if (status != MPORT_OK)
		{
                // Handle error (e.g., log it or halt execution)
		}
	}
}

MPORT_enuErrorStatus_t MPORT_enuSetPinDirection( u8 Copy_enuPinNum  ,  u8  Copy_enuPinDirection  )
{
    MPORT_enuErrorStatus_t status = MPORT_OK;
    u8 port = Copy_enuPinNum >> 4;
    u8 pin = Copy_enuPinNum & 0x0F;
    if (port < MPORT_NUM_PORTS && pin < MPORT_PINS_PER_PORT)
    {
        status = MPORT_enuSetPinConfigration(port, pin, Copy_enuPinDirection);
    }
    else
    {
        status = MPORT_INVALID_PARAM;
    }
    return status;
}

// Function: MPORT_enuSetPinMode
// Configures the mode of a specific pin.
MPORT_enuErrorStatus_t MPORT_enuSetPinMode(u8 Copy_enuPinNum, MPORT_enuPinMode_t Copy_enuPinMode)
{
	MPORT_enuErrorStatus_t Ret_enuError = MPORT_NOK;
	u8 port_Number = (Copy_enuPinNum >> 4) & 0x0F; // Extract port number
	u8 pin_Number = Copy_enuPinNum & 0x0F;        // Extract pin number

	// Validate mode
	if (Copy_enuPinMode < PORT_PIN_MODE_INPUT_PULLUP || Copy_enuPinMode > PORT_PIN_MODE_SPI)
	{
		return MPORT_ERROR_INVALID_MODE;
	}

	switch (port_Number)
	{
		case 0: // PORTA
		switch (Copy_enuPinMode)
		{
			case PORT_PIN_MODE_INPUT_PULLUP:
			CLEAR_BIT(DDRA_REG, pin_Number); // Configure as input
			SET_BIT(PORTA_REG, pin_Number);  // Enable pull-up
			break;

			case PORT_PIN_MODE_INPUT_PULLDOWN:
			CLEAR_BIT(DDRA_REG, pin_Number); // Configure as input
			CLEAR_BIT(PORTA_REG, pin_Number); // Disable pull-up (external pull-down required)
			break;

			case PORT_PIN_MODE_UART:
			case PORT_PIN_MODE_SPI:
			// Configure UART/SPI registers here as per the microcontroller's specifications
			Ret_enuError = MPORT_ERROR_UNCHANGEABLE_MODE; // Placeholder for now
			break;

			default:
			return MPORT_ERROR_INVALID_MODE;
		}
		Ret_enuError = MPORT_OK;
		break;

		case 1: // PORTB
		switch (Copy_enuPinMode)
		{
			case PORT_PIN_MODE_INPUT_PULLUP:
			CLEAR_BIT(DDRB_REG, pin_Number);
			SET_BIT(PORTB_REG, pin_Number);
			break;

			case PORT_PIN_MODE_INPUT_PULLDOWN:
			CLEAR_BIT(DDRB_REG, pin_Number);
			CLEAR_BIT(PORTB_REG, pin_Number);
			break;

			case PORT_PIN_MODE_UART:
			case PORT_PIN_MODE_SPI:
			// Add UART/SPI configuration here
			Ret_enuError = MPORT_ERROR_UNCHANGEABLE_MODE;
			break;

			default:
			return MPORT_ERROR_INVALID_MODE;
		}
		Ret_enuError = MPORT_OK;
		break;

		case 2: // PORTC
		switch (Copy_enuPinMode)
		{
			case PORT_PIN_MODE_INPUT_PULLUP:
			CLEAR_BIT(DDRC_REG, pin_Number);
			SET_BIT(PORTC_REG, pin_Number);
			break;

			case PORT_PIN_MODE_INPUT_PULLDOWN:
			CLEAR_BIT(DDRC_REG, pin_Number);
			CLEAR_BIT(PORTC_REG, pin_Number);
			break;

			case PORT_PIN_MODE_UART:
			case PORT_PIN_MODE_SPI:
			// Add UART/SPI configuration here
			Ret_enuError = MPORT_ERROR_UNCHANGEABLE_MODE;
			break;

			default:
			return MPORT_ERROR_INVALID_MODE;
		}
		Ret_enuError = MPORT_OK;
		break;

		case 3: // PORTD
		switch (Copy_enuPinMode)
		{
			case PORT_PIN_MODE_INPUT_PULLUP:
			CLEAR_BIT(DDRD_REG, pin_Number);
			SET_BIT(PORTD_REG, pin_Number);
			break;

			case PORT_PIN_MODE_INPUT_PULLDOWN:
			CLEAR_BIT(DDRD_REG, pin_Number);
			CLEAR_BIT(PORTD_REG, pin_Number);
			break;

			case PORT_PIN_MODE_UART:
			case PORT_PIN_MODE_SPI:
			// Add UART/SPI configuration here
			Ret_enuError = MPORT_ERROR_UNCHANGEABLE_MODE;
			break;

			default:
			return MPORT_ERROR_INVALID_MODE;
		}
		Ret_enuError = MPORT_OK;
		break;

		default:
		Ret_enuError = MPORT_ERROR_INVALID_PIN;
		break;
	}

	return Ret_enuError;
}