#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(Byte, n) ((Byte) |= (1U << (n)))
#define CLR_BIT(Byte, n) ((Byte) &= ~(1U << (n)))
#define TOG_BIT(Byte, n) ((Byte) ^= (1U << (n)))
#define GET_BIT(Byte, n) (((Byte) >> (n)) & 1U)

#endif