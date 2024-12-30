#include "port.h"
#include "port_config.h"

// Configure pins for LED and button
MPORT_PinCfg_t PinCfg[TOTAL_PINS] = {
	{MPORT_PINA0, MPORT_OUTPUT},
	{MPORT_PINA1, MPORT_INPUT_PULLUP},
	{MPORT_PINA2, MPORT_OUTPUT},
	{MPORT_PINB0, MPORT_OUTPUT},
	{MPORT_PINB1, MPORT_INPUT_PULLUP},
	{MPORT_PINB2, MPORT_OUTPUT}
};