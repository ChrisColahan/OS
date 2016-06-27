;
; FUNCTIONS for changing into 32-bit protected mode
;


[bits 16]

%include "src/gdt.asm"

switch_to_pm:
  cli ; switch off interrupts
  lgdt [gdt_descriptor] ;load global descriptor table

  mov eax, cr0 ;make switch to protected mode
  or eax, 0x1
  mov cr0, eax

  jmp CODE_SEG:init_pm

[bits 32]

init_pm:
  mov ax, DATA_SEG  ;now in pm, old segments meaningless,
  mov ds, ax        ;point segment registers to the data sector
  mov ss, ax        ;defined in GDT
  mov es, ax
  mov fs, ax
  mov gs, ax

  mov ebp, 0x90000  ;update stack position to the top of the free space
  mov esp, ebp

  call BEGIN_PM     ;call a well known label where 32-bit code may take
                    ;over the boot for 32-bit bootloader/kernel/OS

[bits 16]
