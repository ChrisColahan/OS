
#include "io.h"

unsigned char getScancode() {
    char c=0;
    do {
        if(inb(0x60)!=c)
        {
            c=inb(0x60);
            if(c>0)
                return c;
        }
    } while(1);
}

void outb(unsigned short port, unsigned char val) {
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

unsigned char inb(unsigned short port) {
    unsigned char ret;
    asm volatile ("inb $1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}
