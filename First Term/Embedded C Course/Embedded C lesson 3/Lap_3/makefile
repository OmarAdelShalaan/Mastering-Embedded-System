#@ Omar Adel Shalaan
Project_Name=Lab_3

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 
INCS=-I .
SRC= $(wildcard *.c) 
OBJ= $(SRC:.c=.o)	#@ No space after :
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)
ELF= $(wildcard *.elf)
BIN= $(ELF: .elf=.bin)
HEX= $(ELF: .elf=.hex)
LINKS= $(wildcard *.ld)
DEBUG=-gdwarf-2 -g


all: $(Project_Name).bin $(Project_Name).hex
	@echo "(===========Done Build===========)"
	@echo "by: Omar Adel Shalaan"

%.o: %.c
	$(CC)gcc -c $(DEBUG)  $(CFLAGS) $(INCS)  $< -o $@		 -mthumb
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
	cp $(Project_Name).elf $(Project_Name).axf
	@echo "(===========Done axf file===========)"

nm: $(Project_Name).elf
	@echo "(===========Symbol===========)"
	$(CC)nm $<
	@echo "(============================)"

readelf: $(Project_Name).elf
	@echo "(===========readelf===========)"
	$(CC)readelf -h $< 
	@echo "(============================)"

objdump: $(Project_Name).elf
	@echo "(===========objdump===========)"
	$(CC)objdump  -h $<
	@echo "(============================)"
	
simulation:
	@echo "(===========Simulation===========)"
	qemu-system-arm -M versatilepb -m 128M -nographic -kernel $(Project_Name).bin

clean:
	@echo "(===========Clean .o && .elf && .hex file && .map===========)"
	rm -f $(wildcard *.o) $(wildcard *.elf) $(wildcard *.axf) $(wildcard *.hex) $(wildcard *.bin) $(wildcard *.map)
	@echo "(===========Done Clean===========)"
	
	