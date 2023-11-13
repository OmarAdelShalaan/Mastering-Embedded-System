/*
 * ATmega_USART_Driver.c
 *
 * Created: 11/11/2023 8:24:09 AM
 *  Author: Omar
 */ 


#include "ATmega_USART_Driver.h"
#include "REG_Macros.h"
#include <stdint.h>

void USART_Init( USART_Config_t * USARTCfg )
{
	// Enable receiver and transmitter 
	switch(USARTCfg->RX_TX_Enable)
	{
		case RX_and_TX_Enable:
			UCSRB = (1<<RXEN)|(1<<TXEN);
			break;
		case TX_only_Enable:
			UCSRB = (1<<TXEN);
			break;
		case RX_only_Enable:
			UCSRB = (1<<RXEN);
			break;
	}
	//• Bit 6 – UMSEL: USART Mode Select
	//This bit selects between Asynchronous and Synchronous mode of operation
	switch(USARTCfg->Asynch_Synch_Mode)
	{
		case USART_Synch_Rising_Mode:
		UCSRC = (1<<UMSEL) | (1<<URSEL);
		break;
		case USART_Synch_Falling_Mode:
		UCSRC = (1<<UMSEL) | (1<<URSEL) | (1<<UCPOL);
		break;
		case USART_Asynch_Mode:
		UCSRC = (0<<UMSEL) | (1<<URSEL);
		break;
		case USART_Asynch_UX2_Mode:
		UCSRC = (0<<UMSEL) | (1<<URSEL);
		UCSRA = (1<<U2X);
		break;
	}
	//----------------------------------------------------------
	// USART Frame

	// Set baud rate
	// UBRR =(fOSC/2or8or16BAUD) - 1
	UBRRH &= ~(1<<URSEL);
	UBRRH = (unsigned char)(USARTCfg->Frame.baud>>8);
	UBRRL = (unsigned char)USARTCfg->Frame.baud;
	// Num of Data Bits
	UCSRC |= (1<<URSEL) |(USARTCfg->Frame.numDataBits<<UCSZ0);
	//  Parity Mode
	UCSRC |= (1<<URSEL) |(USARTCfg->Frame.Parity<<UPM0);
	// Num of Stop Bit
	switch(USARTCfg->Frame.numStopBits)
	{
		case twoStopBit:
			UCSRC |= (1<<URSEL) |(1 <<USBS);
			break;
		case oneStopBit:
			UCSRC |= (1<<URSEL);
			UCSRC &= ~(1<<USBS);
			break;
	}
}

void USART_Transmit( USART_Config_t * USARTCfg, uint16_t data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	if(USARTCfg->Frame.numDataBits == SizeDataBits_9)
	{
		if(((data >> 8) & 0x01) == 1)
		{
			UCSRB |= (1 << TXB8);
		}
		else
		{
			UCSRB &= ~(1 << TXB8);
		}
	}
	/* Put data into buffer, sends the data */
	UDR = (uint8_t)data;
}
void USART_Transmit_String( USART_Config_t * USARTCfg, uint8_t * str )
{
	int i = 0;
	while(str[i] != '\0')
	{
		USART_Transmit(&USARTCfg, str[i]);
		i++;
	}
}
uint16_t USART_Receive( USART_Config_t * USARTCfg )
{
	/* Wait for data to be received */
	uint8_t temp = 0;
	while ( !(UCSRA & (1<<RXC)) )
	;
	if(USARTCfg->Frame.numDataBits == SizeDataBits_9)
	{
		temp = ((UCSRB >> RXB8) & 0x01) == 1?  1: 0;
	}
	/* Get and return received data from buffer */
	return ((temp << 8)| UDR);
}
void USART_Receive_String( USART_Config_t * USARTCfg, uint8_t * str )
{
	int i = 0;
	while(1)
	{
		str[i] = (uint8_t)USART_Receive(&USARTCfg);
		if(str[i] == '\r')break;
		i++;
	}
	str[i] = '\0';
}
// void USART_Flush( void )
// {
// 	unsigned char dummy;
// 	while ( UCSRA & (1<<RXC) ) dummy = UDR;
// }