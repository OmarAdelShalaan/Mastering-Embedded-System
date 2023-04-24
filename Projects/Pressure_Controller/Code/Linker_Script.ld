/*
* Omar Adel Shalaan
* Linker_Script
*/
MEMORY{
flash(RX): ORIGIN = 0x08000000, LENGTH = 128K
sram(RWX): ORIGIN = 0x20000000, LENGTH = 20K
}
SECTIONS
{
	.text : /* space after text */
	{
		*(.vectors*)
		*(.text*)
		. = ALIGN(4);
		_E_Text = .;
	}> flash
	.data :
	{
		_S_Data = .;
		*(.data)
		*(.rodata)
		. = ALIGN(4);
		_E_Data = .;
	}> sram AT> flash
	.bss :
	{
		_S_Bss = .;
		*(.bss)
		. = ALIGN(4);
		_E_Bss = .;
		. = . + 0x1000;
		_stack_top = .;
	}> sram

}



