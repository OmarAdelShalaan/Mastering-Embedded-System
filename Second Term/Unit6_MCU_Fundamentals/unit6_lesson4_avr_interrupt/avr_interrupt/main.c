/*
 * avr_interrupt.c
 *
 * Created: 6/26/2023 1:35:25 AM
 * Author : Omar
 */ 

#include <stdint.h>

// Interrupt Reg
#define	GICR	(*(volatile uint8_t *)(0x5B))
#define	MCUCR	(*(volatile uint8_t *)(0x55))
#define	SREG	(*(volatile uint8_t *)(0x5F))
//GPIO Reg
#define	PORTA	(*(volatile uint8_t *)(0x3B))
#define	DDRA	(*(volatile uint8_t *)(0x3A))
#define	PINA	(*(volatile uint8_t *)(0x39))
#define	PORTD	(*(volatile uint8_t *)(0x32))
#define	DDRD	(*(volatile uint8_t *)(0x31))
#define	PIND	(*(volatile uint8_t *)(0x30))

#define EXT_INT_0  __vector_1
#define EXT_INT_1  __vector_2
#define EXT_INT_2  __vector_3

#define ISR(INT_VECT)  void INT_VECT(void) __attribute__ (( signal ));\
void INT_VECT(void)



void INT0_init()
{
	// enable INT0
	GICR |= (1<<6);
	//The rising edge of INT0 generates an interrupt request.
	MCUCR |= (3<<0);
}
void Sei()
{
	// enable global interrupt
	SREG |= (1<<7);//$5F
}

int main(void)
{
	DDRA |= ( 1 << 0);
	PORTA &= ~(1 << 0);
	
	DDRD &= ( 1 << 0);
	INT0_init();
	Sei();
	
	/* Replace with your application code */
    while (1) 
    {
    }
}

ISR(EXT_INT_0)
{
	PORTA ^= (1 << 0);
}