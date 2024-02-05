
QEMU=qemu-system-arm

TOOLCHAIN=arm-none-eabi

BOARD=versatile

ifeq ($(BOARD),versatile)
  CPU=cortex-a8
  # CPU=arm926ej-s
  VGA=-nographic
  SERIAL=-serial mon:stdio
  # memory size in kilo bytes.
  MEMSIZE=32
  MEMORY="$(MEMSIZE)K"  
  MACHINE=versatileab
  CFLAGS= -mcpu=$(CPU) -DCPU=$(CPU) -DMEMORY="($(MEMSIZE)*1024)"
  
  ASFLAGS= -mcpu=$(CPU) -g
  CFLAGS+= -c -g -nostdlib -ffreestanding
  LDFLAGS= -T kernel.ld -g -nostdlib -static
endif

ifndef MACHINE
  $(error Must choose a board (e.g. Versatile AB or PB)) 
endif

# Object files to build and link together
objs= startup.o main.o exception.o uart.o

OBJS = $(addprefix build/, $(objs)) 

# Compilation Rules
build/%.o: %.c
	$(TOOLCHAIN)-gcc $(CFLAGS) -o $@ $<

build/%.o: %.s
	$(TOOLCHAIN)-as $(ASFLAGS) -o $@ $<

# Build and link all
# Notice that we link with our own linker script: test.ld
all: build $(OBJS)
	$(TOOLCHAIN)-ld $(LDFLAGS) $(OBJS) -o kernel.elf
	$(TOOLCHAIN)-objcopy -O binary kernel.elf kernel.bin 

build:
	@mkdir build
	
clean: 
	rm -rf build/ kernel.elf kernel.bin

	
#-------------------------------------------------------------
ifeq ($(BOARD),versatile)
run: all
	@echo "\n\nBoard: Versatile Board...\n"
	$(QEMU) -M $(MACHINE) -cpu $(CPU) -m $(MEMORY) $(VGA) $(SERIAL) -device loader,file=kernel.elf

debug: all
	@echo "\n\nBoard: Versatile Board...\n"
	$(QEMU) -M $(MACHINE) -cpu $(CPU) -m $(MEMORY) $(VGA) $(SERIAL) -device loader,file=kernel.elf -gdb tcp::1234 -S
# -cpu $(CPU)

endif
