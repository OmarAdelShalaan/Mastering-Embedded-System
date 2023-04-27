#@ Omar Adel Shalaan
#@ Pressure Controller Project
#@ STM32F103C6
Project_Name=Pressure_Controller

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 
INCS=-I .
SRC= $(wildcard *.c) 
OBJ= $(SRC:.c=.o)	
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)
ELF= $(wildcard *.elf)
BIN= $(ELF: .elf=.bin)
HEX= $(ELF: .elf=.hex)
LINKS= $(wildcard *.ld)
DEBUG=-g -gdwarf-2


all: $(Project_Name).bin $(Project_Name).hex
	@echo "(===========Done Build===========)"
	@echo "by: Omar Adel Shalaan"

%.o: %.c
	$(CC)gcc -c $(DEBUG)  $(CFLAGS) $(INCS)  $< -o $@		-lm -mthumb
%.o: %.s
	$(CC)as    $(DEBUG) $(CFLAGS) $(INCS)  $< -o $@		

%.hex: %.elf
	$(CC)objcopy -O ihex $<  $@		
	@echo "(===========Done hex file===========)"

%.bin: %.elf
	$(CC)objcopy -O binary  $<  $@
	@echo "(===========Done bin file===========)"


$(Project_Name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld -T $(LINKS) $(OBJ) $(ASOBJ) -o $@ -Map=output_map.map
	@echo "(===========Done elf file===========)"
	
#@ Symbol is Address but not carry any value
Symbols: $(Project_Name).elf					
	@echo "(===========Symbol===========)"
	$(CC)nm $<
	@echo "(============================)"

readelf: $(Project_Name).elf
	@echo "(===========readelf===========)"
	$(CC)readelf -h $< 
	@echo "(============================)"

Sections: $(Project_Name).elf
	@echo "(===========objdump===========)"
	$(CC)objdump  -h $<
	@echo "(============================)"
	

clean_all:
	@echo "(===========Clean .o && .elf && .hex file && .map===========)"
	rm -f $(wildcard *.o) $(wildcard *.elf) $(wildcard *.hex) $(wildcard *.bin) $(wildcard *.map)
	@echo "(===========Done Clean===========)"
	
	
clean:
	@echo "(===========Clean .o===========)"
	rm -f $(wildcard *.o) 
	@echo "(===========Done Clean===========)"
	

	
	
	
	
	