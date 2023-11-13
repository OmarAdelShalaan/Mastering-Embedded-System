/*
 * Atmega_USART_Driver.c
 *
 * Created: 11/11/2023 7:17:03 AM
 * Author : Omar
 */ 

//#include <avr/io.h>
#include "ATmega_USART_Driver.h"

int main(void)
{
	volatile uint16_t data;
	uint8_t str[20];
	USART_Config_t  USARTCfg;
	USARTCfg.RX_TX_Enable = RX_and_TX_Enable;
	USARTCfg.Asynch_Synch_Mode = USART_Asynch_Mode;	
	USARTCfg.Frame.numDataBits = SizeDataBits_9;	
	USARTCfg.Frame.baud = 51;	
	USARTCfg.Frame.numStopBits = oneStopBit;
	USARTCfg.Frame.Parity = Parity_Disable;

	USART_Init(&USARTCfg);	
	USART_Transmit_String(&USARTCfg,"Omar Adel Shalaan\r");
	USART_Receive_String(&USARTCfg,str);
	USART_Transmit_String(&USARTCfg,str);
    while (1) 
    ;
}

