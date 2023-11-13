/*
 * ATmega_USART_Driver.h
 *
 * Created: 11/11/2023 8:23:58 AM
 *  Author: Omar
 */ 


#ifndef ATMEGA_USART_DRIVER_H_
#define ATMEGA_USART_DRIVER_H_

#include "REG_Macros.h"
#include <stdint.h>

typedef struct{
	uint8_t		numDataBits;//@ref define num_Bits_TX&RX_data
	uint8_t		Parity;	// @ref define Parity_En_Even_Odd_OR_Disable
	uint8_t		numStopBits;//@ref define StopBitsNumber
	uint16_t	baud;
	
	}UART_Frame_t;
	
typedef struct{
	uint8_t			RX_TX_Enable;//@ref define RX_TX_Enable
	uint8_t			Asynch_Synch_Mode;//@ref define Asynch_OR_Synch_Mode
	UART_Frame_t	Frame;
	}USART_Config_t;
	
//@ref define RX_TX_Enable
#define RX_and_TX_Enable	0	
#define RX_only_Enable		1
#define TX_only_Enable		2

//@ref define num_Bits_TX&RX_data
#define SizeDataBits_5	0x00
#define SizeDataBits_6	0x01
#define SizeDataBits_7	0x02
#define SizeDataBits_8	0x03	
#define SizeDataBits_9	0x07

// @ref define Parity_En_Even_Odd_OR_Disable
#define Parity_Disable			0b00
#define Parity_odd_Enable		0b11
#define Parity_Even_Enable		0b10

//@ref define StopBitsNumber
#define oneStopBit		0
#define twoStopBit		1

//@ref define Asynch_OR_Synch_Mode
#define USART_Synch_Falling_Mode		0
#define USART_Synch_Rising_Mode			1
#define USART_Asynch_Mode				2
#define USART_Asynch_UX2_Mode			3

void USART_Init( USART_Config_t * USARTCfg );
void USART_Transmit( USART_Config_t * USARTCfg, uint16_t data );
void USART_Transmit_String( USART_Config_t * USARTCfg, uint8_t * str );
uint16_t USART_Receive( USART_Config_t * USARTCfg );
void USART_Receive_String( USART_Config_t * USARTCfg, uint8_t * str );

//void USART_Flush( void );

#endif /* ATMEGA_USART_DRIVER_H_ */