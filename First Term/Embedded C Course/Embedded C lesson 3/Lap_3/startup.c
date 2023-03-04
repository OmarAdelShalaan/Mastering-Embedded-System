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


void NMI_Handler(void) __attribute__(( weak, alias("Default_Handler")));
void H_fault_Handler(void) __attribute__(( weak, alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__(( weak, alias("Default_Handler")));
void Bus_handler(void) __attribute__(( weak, alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__(( weak, alias("Default_Handler")));

// stack_top with arr

static unsigned long stack_top[256];

// vector with arr to p to fun return void

void (* const G_Arr_Ptr_fun_Vectors[])() __attribute__((section(".vectors"))) = {
(void (*)()) ((unsigned long)stack_top + sizeof(stack_top)),
&Reset_handler,
&NMI_Handler,
&H_fault_Handler,
&MM_Fault_Handler,
&Bus_handler,
&Usage_Fault_Handler
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





