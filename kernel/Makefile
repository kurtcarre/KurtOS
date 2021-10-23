TARGET = i686-elf

CC = $(TARGET)-gcc
LD = $(TARGET)-gcc
AS = nasm

CFLAGS = -ffreestanding -g
LDFLAGS = -T linker.ld -ffreestanding -nostdlib -lgcc

#SRCDIR := .
#OBJDIR := ~/Build/objs
BUILDDIR := ~/Build/bin

rwildcard = $(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,.,*.c)
ASMSRC = $(call rwildcard,.,*.asm)
OBJS = $(SRC:.c=.o)
OBJS += $(ASMSRC:.asm=.o)

.PHONY: default kernel link clean buildimg run
.SUFFIXES: .o .c .asm

default: kernel

kernel: $(OBJS) link

.c.o:
	@ echo !===== COMPILING $^ =====!
	$(CC) -c $^ -o $@ $(CFLAGS)

.asm.o:
	@ echo !===== ASSEMBLING $^ =====!
	$(AS) -felf32 -g $^ -o $@

link:
	@ echo !===== LINKING =====!
	$(LD) $(LDFLAGS) -o $(BUILDDIR)/kurtos.elf $(OBJS)

clean:
	find . -name '*.o' -delete	
	rm -rvf $(BUILDDIR)/*

buildimg: clean kernel
	mkdir -p $(BUILDDIR)/iso/boot/grub
	cp $(BUILDDIR)/kurtos.elf $(BUILDDIR)/iso/boot/kurtos.elf
	echo 'menuentry "kurtos" { multiboot /boot/kurtos.elf }' > $(BUILDDIR)/iso/boot/grub/grub.cfg
	grub-mkrescue -o $(BUILDDIR)/kurtos.iso $(BUILDDIR)/iso

run: buildimg
	qemu-system-i386 -cdrom $(BUILDDIR)/kurtos.iso -m 256 -s -S