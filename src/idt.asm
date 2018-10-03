; Interrupt Descriptor Table

; Filled with nothing for now

idt:
    dw 2048  ; size of desciptor table, all 0 for now
    dd 0x0   ; linear address
