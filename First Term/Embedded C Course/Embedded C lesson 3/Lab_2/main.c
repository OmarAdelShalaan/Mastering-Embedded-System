/**
 ******************************************************************************
 * Omar Adel Shalaan
 ******************************************************************************
 */

#include <stdint.h>
typedef volatile unsigned int vint32_t;
// register address
#define	RCC_BASE	0x40021000
#define	GPIOA_BASE	0x40010800
#define	RCC_APB2ENR	*(volatile uint32_t *)(RCC_BASE + 0x18)
#define	GPIOA_CRH	*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define	GPIOA_ODR	*(volatile uint32_t *)(GPIOA_BASE + 0x0C)
// BIT FIELDS
#define	RCC_IOPAEN	(1<<2)
#define GPIOA13	(1UL<<13)

typedef union{
	vint32_t all_fields;
	struct{
		vint32_t	reserved:13;
		vint32_t	P_13:1;
	}Pin;
}R_ODR_t;
volatile R_ODR_t * R_ODR = (volatile R_ODR_t *)(GPIOA_BASE + 0x0C);

int main(void)
{
	int i = 0;
	/* Loop forever */
	RCC_APB2ENR	|= RCC_IOPAEN;
	GPIOA_CRH	&= 0xFF0FFFFF;
	GPIOA_CRH	|= 0x00200000;
	while(1)
	{
		R_ODR->Pin.P_13 = 1;
		for(i = 0; i < 5000; i++);
		R_ODR->Pin.P_13 = 0;
		for( i = 0; i < 5000; i++);
	}
	return 0;
}

