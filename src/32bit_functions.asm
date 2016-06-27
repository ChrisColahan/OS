;
; functions in 32-bit protected mode
;
[bits 32]

VIDEO_MEMORY equ 0xB8000
WHITE_ON_BLACK equ 0x0F

;print a string using video memory
print_string_32:
  pusha
  mov edx, VIDEO_MEMORY ;set edx to the start of video memory

  print_string_pm_loop:
    mov al, [esi] ;store char at EBX in AL
    mov ah, WHITE_ON_BLACK  ;store attributes in AH

    cmp al, 0 ;check for end of string
    je print_string_pm_done

    mov [edx], ax ;store char and attributes at current character cell
    add esi, 1 ;increment EBX to next character in string
    add edx, 2 ;move to next character in video memory

    jmp print_string_pm_loop ; loop for next char

  print_string_pm_done:
    popa
    ret

[bits 16]
