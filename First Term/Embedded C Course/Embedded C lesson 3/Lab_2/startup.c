/*
* Omar Adel Shalaan
* startup.c
*/

#include<stdint.h>

extern int main();
void Reset_handler();

void Default_Handler()
{
	Reset_handler();
}
extern uint32_t _stack_top;

void NMI_Handler(void) __attribute__(( weak, alias("Default_Handler")));
void H_fault_Handler(void) __attribute__(( weak, alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__(( weak, alias("Default_Handler")));
void Bus_handler(void) __attribute__(( weak, alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__(( weak, alias("Default_Handler")));

uint32_t vectors[] __attribute__((section(".vectors"))) = {
(uint32_t) &_stack_top,
(uint32_t) &Reset_handler,
(uint32_t) &NMI_Handler,
(uint32_t) &H_fault_Handler,
(uint32_t) &MM_Fault_Handler,
(uint32_t) &Bus_handler,
(uint32_t) &Usage_Fault_Handler
};

extern unsigned int _E_Text;
extern unsigned int _S_Data;
extern unsigned int _E_Data;
extern unsigned int _S_Bss;
extern unsigned int _E_Bss;

void Reset_handler()
{
	// Copy Data section from flash to SRAM
	unsigned int Data_size = (unsigned char*)&_E_Data - (unsigned char*)&_S_Data;
	unsigned char* P_src = (unsigned char*)&_E_Text;
	unsigned char* P_dst = (unsigned char*)&_S_Data;
	int i = 0;
	for( i = 0; i < Data_size; i++)
	{
		*((unsigned char*)P_dst++) =  *((unsigned char*)P_src++);
	}
	
	// init Bss section in SRAM
	unsigned int Bss_size = (unsigned char*)&_E_Bss - (unsigned char*)&_S_Bss;
	P_dst = (unsigned char*)&_S_Bss;
	for( i = 0; i < Bss_size; i++)
	{
		*((unsigned char*)P_dst++) =  (unsigned char)0;
	}
	
	// jump to main()
	main();
}





