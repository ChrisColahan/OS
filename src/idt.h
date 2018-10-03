#ifndef IDT_H
#define IDT_H

/*
 * defines the IDT (Interrupt Descriptor Table) structure.
 * the bootloader has already allocated space, but nothing has been initilialized
 */


// A single IDT entry
struct idt_entry {

    unsigned short offset_low;  // low bits of offset
    unsigned short selector;    // code segment selector
    unsigned char zero;         // this is always 0
    unsigned char flags;        // type and attributes
    unsigned short offset_high; // high bits of offset
}__attribute__((packed));

struct idt_ptr {
    unsigned short limit;
    unsigned int base;
}__attribute__((packed));

struct idt_record {
    unsigned short limit;       // size of idt array - 1
    unsigned int base;          // pointer to idt array
}__attribute__((packed));

//retrieve IDT data
void get_idt(struct idt_record *idt_r);

//load data into IDT
void initialize_idt();

#endif
