/*
 * REG_Macros.h
 *
 * Created: 11/12/2023 8:19:09 AM
 *  Author: Omar
 */ 


#ifndef REG_MACROS_H_
#define REG_MACROS_H_
#include <stdint.h>

#define RXC			7
#define TXC			6
#define UDRE		5
#define FE			4
#define DOR			3
#define PE			2
#define U2X			1
#define MPCM		0

#define RXCIE		7
#define TXCIE		6
#define UDRIE		5
#define RXEN		4
#define TXEN		3
#define UCSZ2		2
#define RXB8		1
#define TXB8		0

#define URSEL		7
#define UMSEL		6
#define UPM1		5
#define UPM0		4
#define USBS		3
#define UCSZ1		2
#define UCSZ0		1
#define UCPOL		0

#define UBRRL		(*((volatile uint8_t*)0x29))
#define UCSRB		(*((volatile uint8_t*)0x2A))
#define UCSRA		(*((volatile uint8_t*)0x2B))
#define UDR			(*((volatile uint8_t*)0x2C))
#define UCSRC		(*((volatile uint8_t*)0x40))
#define UBRRH		(*((volatile uint8_t*)0x40))

#endif /* REG_MACROS_H_ */