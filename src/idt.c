
#include "idt.h"
#include "util.h"

void get_idt(struct idt_record *idt_r) {
    __asm("lidt %0" :: "m"(*idt_r));
}

void initialize_idt() {
    //first, retrieve the idt pointers
    struct idt_record idt;
    get_idt(&idt);
    
    //then load the data into the idt
    
    //finally, enable interrupts
    //enable_interrupts();
}
