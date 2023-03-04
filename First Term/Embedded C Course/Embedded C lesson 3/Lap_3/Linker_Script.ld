/*
* Omar Adel Shalaan
* Linker_Script
*/
MEMORY{
flash(RX): ORIGIN = 0x00000000, LENGTH = 512M
sram(RWX): ORIGIN = 0x20000000, LENGTH = 512M
}
SECTIONS
{
	.text : /* space after text */
	{
		*(.vectors*)
		*(.text*)
		_E_Text = .;
	}> flash
	.data :
	{
		_S_Data = .;
		*(.data)
		*(.rodata)
		_E_Data = .;
	}> sram AT> flash
	.bss :
	{
		_S_Bss = .;
		*(.bss)
		_E_Bss = .;
		. = . + 0x1000;
		_stack_top = .;
	}> sram

}



