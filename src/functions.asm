;
; 16-BIT REAL MODE UTILITY FUNCTIONS
;

;infinite loop
kill:
  jmp $

print_string:
  mov ah, 0xE

  _loop:
    lodsb
    cmp al, 0
    je _end

    int 0x10
    jmp _loop

  _end:
    ret

; print the ASCII character in the al register onto the screen
print_char:
  mov ah, 0x0E ;BOIS scrolling teletype function
  int 0x10
  ret

;read from disk
;params: 
;  al: number of sectors to read
;  bx: where to load the sectors into
read_from_disk:
  mov ah, 0x02 ;read sectors from drive

  ;mov al, 1 ;read one sector
  mov ch, 0 ;read from track 0
  mov dh, 0 ;read from head 0
  mov cl, 2 ;boot sector is at 1, so read 2nd sector
  mov dx, 0x80; drive to boot from. 0x80 is the one with the bootloader

  push bx		;save bx
  mov bx, 0
  mov es, bx 	;es = 0
  pop bx		;get the saved bx

  ;mov bx, 0x7c00 + 512 ;end of boot sector, 
                       ;where to load the sector into memory

  int 0x13

  mov si, DISK_ERROR
  jc print_string ;display the disk error message if an error occurred

  ret

;
; ERROR MESSAGES
;

DISK_ERROR:
  db 'Error reading disk!',0

