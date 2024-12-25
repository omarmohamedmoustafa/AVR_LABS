#ifndef DIO_H_
#define DIO_H_

/* Type Definitions */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;

/* Error Status Enum */
typedef enum
{
    MDIO_OK,
    MDIO_INVALID_PARAM,
    MDIO_NOK,
    MDIO_NULL_PTR
} MDIO_enuErrorStatus_t;

/* Port and Pin Enums */
typedef enum
{
    MDIO_PORTA,
    MDIO_PORTB,
    MDIO_PORTC,
    MDIO_PORTD
} MDIO_enuPortNum_t;

typedef enum
{
    MDIO_PIN0,
    MDIO_PIN1,
    MDIO_PIN2,
    MDIO_PIN3,
    MDIO_PIN4,
    MDIO_PIN5,
    MDIO_PIN6,
    MDIO_PIN7
} MDIO_enuPinNum_t;

/* Pin and Port Configuration Enums */
typedef enum
{
    MDIO_INPUT,
    MDIO_OUTPUT,
    MDIO_INPUT_PULLUP
} MDIO_enuPinConfiguration_t;

typedef enum
{
    MDIO_PORT_INPUT = 0x00,
    MDIO_PORT_OUTPUT = 0xFF
} MDIO_enuPortConfiguration_t;

/* Bit Manipulation Macros */
#define SET_BIT(Byte, n) ((Byte) |= (1U << (n)))
#define CLR_BIT(Byte, n) ((Byte) &= ~(1U << (n)))
#define TOG_BIT(Byte, n) ((Byte) ^= (1U << (n)))
#define GET_BIT(Byte, n) (((Byte) >> (n)) & 1U)

#define MDIO_HIGH 1
#define MDIO_LOW  0
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
/**
 * @brief Set the value of a specific pin (high, low, or pull-up).
 * 
 * @param Copy_enuPortNum      Port number (MDIO_PORTA, MDIO_PORTB, etc.).
 * @param Copy_enuPinNum       Pin number (MDIO_PIN0, MDIO_PIN1, etc.).
 * @param Copy_enuPinConfig    Pin configuration (MDIO_INPUT, MDIO_OUTPUT, MDIO_INPUT_PULLUP).
 * @return MDIO_enuErrorStatus_t Status of the operation (MDIO_OK, MDIO_INVALID_PARAM, etc.).
 */
MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPortNum_t Copy_enuPortNum, MDIO_enuPinNum_t Copy_enuPinNum, MDIO_enuPinConfiguration_t Copy_enuPinConfig);

/**
 * @brief Configure the direction of a specific pin (input, output).
 * 
 * @param Copy_enuPortNum      Port number (MDIO_PORTA, MDIO_PORTB, etc.).
 * @param Copy_enuPinNum       Pin number (MDIO_PIN0, MDIO_PIN1, etc.).
 * @param Copy_u8PinDir        Pin direction (MDIO_INPUT, MDIO_OUTPUT).
 * @return MDIO_enuErrorStatus_t Status of the operation (MDIO_OK, MDIO_INVALID_PARAM, etc.).
 */
MDIO_enuErrorStatus_t MDIO_enuSetPinConfiguration(MDIO_enuPortNum_t Copy_enuPortNum, MDIO_enuPinNum_t Copy_enuPinNum, MDIO_enuPinConfiguration_t Copy_u8PinDir);

/**
 * @brief Set the value of an entire port (high or low for all pins).
 * 
 * @param Copy_enuPortNum      Port number (MDIO_PORTA, MDIO_PORTB, etc.).
 * @param Copy_u8PortValue     Value to set the port (0x00 or 0xFF).
 * @return MDIO_enuErrorStatus_t Status of the operation (MDIO_OK, MDIO_INVALID_PARAM, etc.).
 */
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum_t Copy_enuPortNum, u8 Copy_u8PortValue);

/**
 * @brief Configure the direction of an entire port (input, output).
 * 
 * @param Copy_enuPortNum          Port number (MDIO_PORTA, MDIO_PORTB, etc.).
 * @param Copy_enuPortConfig       Port configuration (MDIO_PORT_INPUT, MDIO_PORT_OUTPUT).
 * @return MDIO_enuErrorStatus_t   Status of the operation (MDIO_OK, MDIO_INVALID_PARAM, etc.).
 */
MDIO_enuErrorStatus_t MDIO_enuSetPortDirection(MDIO_enuPortNum_t Copy_enuPortNum, MDIO_enuPortConfiguration_t Copy_enuPortConfig);

/**
 * @brief Get the value of a specific pin (high or low).
 * 
 * @param Copy_enuPortNum      Port number (MDIO_PORTA, MDIO_PORTB, etc.).
 * @param Copy_enuPinNum       Pin number (MDIO_PIN0, MDIO_PIN1, etc.).
 * @param Add_pu8PinValue      Pointer to store the pin value.
 * @return MDIO_enuErrorStatus_t Status of the operation (MDIO_OK, MDIO_NULL_PTR, etc.).
 */
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum_t Copy_enuPortNum, MDIO_enuPinNum_t Copy_enuPinNum, u8* Add_pu8PinValue);

#endif /* DIO_H_ */
