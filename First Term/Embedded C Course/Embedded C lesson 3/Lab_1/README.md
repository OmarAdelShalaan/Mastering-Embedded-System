# Mastering-Embedded-System
# [www.learn-in-depth.com](https://www.learn-in-depth.com/online-diploma/omaradelshalaan%40gmail.com)

# Lab_1
### ==> Running
![Running](./Running.jpg)
## MAKEFILE
### ==> make
![make](./MAKE_FILE/make.jpg)
### ==> make objdump
![make](./MAKE_FILE/objdump.jpg)
### ==> make readelf
![make](./MAKE_FILE/readelf.jpg)
### ==> make clean
![make](./MAKE_FILE/clean.jpg)

## GDB
### Terminal 1:
qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel  learn-in-depth.bin
![run](./GDB/run.jpg)
### Terminal 2:
arm-none-eabi-gdb Learn-in-depth.elf
target remote localhost:1234
![](./GDB/done.jpg)


## ==> l
![l](GDB/l.jpg)
## ==> s
![]()
## ==> si
![]()
## ==> display
![](GDB/l.jpg)
## ==> display/10i $pc 
![](GDB/display.jpg)
## ==> watch
![]()
## ==> b
![](GDB/b.jpg)
## ==> info breakpoints
![info_breakpoint](./GDB/info_breakpoint.jpg)
## ==> c
![c](GDB/c.jpg)
## ==> set $pc=0x10000
![set_display](./GDB/set_display.jpg)