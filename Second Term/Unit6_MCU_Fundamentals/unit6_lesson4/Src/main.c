/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define RCC_CR_BASE 0x40021000
#define RCC_CR   	*((volatile uint32_t *)(RCC_CR_BASE + 0x00))
#define RCC_CFGR 	*((volatile uint32_t *)(RCC_CR_BASE + 0x04))

#define RCC_APB2ENR *((volatile uint32_t *)(RCC_CR_BASE + 0x18))

#define GPIOA_BASE 0x40010800
#define GPIOA_CRL *((volatile uint32_t *)(GPIOA_BASE +  0x00))
#define GPIOA_CRH *((volatile uint32_t *)(GPIOA_BASE +  0x04))
#define GPIOA_ODR *((volatile uint32_t *)(GPIOA_BASE +  0x0C))

#define ICTR 0xE000E004

#define EXTI_BASE 0x40010400
#define EXTI_IMR *((volatile uint32_t *)( EXTI_BASE+  0x00))
#define EXTI_RTSR *((volatile uint32_t *)( EXTI_BASE+  0x08))
#define EXTI_PR *((volatile uint32_t *)( EXTI_BASE+  0x14))

#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1 *((volatile uint32_t *)( AFIO_BASE + 0x08))

#define NVIC_ISER0 *((volatile uint32_t *)0xE000E100)


void GPIOA_init()
{
	//Bit 2 IOPAEN: IO port A clock enable
	RCC_APB2ENR |= (1 << 2);
	//In output mode (MODE[1:0] > 00):
	//bit 13 output
	GPIOA_CRH |= (1<<20);

}

void clock_init()
{
	RCC_CFGR &= ~( 1 << 16 );
	RCC_CFGR |= ( 0b0110 << 18);
	RCC_CR |= (1 << 24);
	RCC_CFGR |= (0b10 << 0);
	RCC_CFGR |= ( 0b100 << 8);
	RCC_CFGR |= ( 0b101 << 11);
}

void EXTI_init()
{
	// open clock
	// defluat that is open


	// make ALF pinA
	//Bit 0 AFIOEN: Alternate function IO clock enable
	RCC_APB2ENR |= (1 << 0);

	// AFIO_EXTICR1
	// defluat that is pin0
	// 0000: PA[x] pin

	//rising
	//TRx: Rising trigger event configuration bit of line x
	//0: Rising trigger disabled (for Event and Interrupt) for input line
	//1: Rising trigger enabled (for Event and Interrupt) for input line.
	EXTI_RTSR |= (1<<0);

	// mask Interrupt
	//MRx: Interrupt Mask on line x
	//0: Interrupt request from Line x is masked
	//1: Interrupt request from Line x is not masked
	EXTI_IMR |= (1<<0);

	// Open NVIC
	NVIC_ISER0 |= (1<<6);

	//bit 0 input
	//In input mode (MODE[1:0]=00):
	//01: Floating input (reset state)
	GPIOA_CRL &= ~(1<<0);

	// Clear Pending
	//PRx: Pending bit
	//0: No trigger request occurred
	//1: selected trigger request occurred
	//This bit is set when the selected edge event arrives on the external interrupt line. This bit is
	//cleared by writing a ‘1’ into the bit.
	EXTI_PR |= (1<<0);
}

int main(void)
{
	clock_init();
	GPIOA_init();
	EXTI_init();
	while(1);
}

void EXTI0_IRQHandler()
{
	GPIOA_ODR ^= (1 << 13);
	EXTI_PR |= (1<<0); // to no make infinite interrupt
}


