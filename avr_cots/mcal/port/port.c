
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

