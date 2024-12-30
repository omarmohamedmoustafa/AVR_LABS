#ifndef PORT_CFG_H
#define PORT_CFG_H

#include "port.h"

// Define number of ports and pins
#define MPORT_NUM_PORTS 2  // Two ports: Port A and Port B
#define MPORT_PINS_PER_PORT 3  // One pin per port for button and LED
#define TOTAL_PINS (MPORT_NUM_PORTS * MPORT_PINS_PER_PORT)  // Total pins = 2 (Port A and Port B)


typedef struct {
	u8 port_pin;
	u8 dir;
} MPORT_PinCfg_t;

#endif
