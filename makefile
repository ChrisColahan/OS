
all: build run

build: clean assemble_bootloader compile_kernel create_disk_image

clean:
	-rm bin/*

assemble_bootloader:
	nasm src/boot.asm -f bin -o bin/boot.bin

compile_kernel:
	#compile the C kernel
	gcc -ffreestanding -c src/kernel.c -o bin/kernel.o -m32
	#spit out the object dump for the kernel file (for dubugging)
	objdump -M intel -d bin/kernel.o > bin/kernel_objdump.txt
	#link the kernel into a 32-bit binary for x86 arch
	ld -o bin/kernel.bin -Ttext 0x7E00 bin/kernel.o -m elf_i386 --oformat binary
	#disassemble for analysis (if needed) and put it into a file
	ndisasm -b32 bin/kernel.bin > bin/kernel_dissembly.txt

create_disk_image:
	#create the raw binary image by concatentating the boot sector and kernel
	cat bin/boot.bin bin/kernel.bin > bin/os_image.bin
	#pad to ensure correct number of whole sectors
	truncate bin/os_image.bin -s 10240

run:
	qemu-system-x86_64 bin/os_image.bin



