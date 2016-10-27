
//this needs to be here!
void main();

//boostrap kernel
void entry() {
    main();
}

//do normal C things

#include "io.h"
#include "util.h"
#include "math.h"
#include "graphics.h"


void main() {
    //unsigned char scancode = 0;
    //while(1) {
      //  if(scancode == 0)
	   //     scancode = getScancode();
        
        clear(ATTR_COLOR_MAGENTA);
        int offset = print("Hello from the C kernel!", 0, makeAttr(ATTR_COLOR_CYAN, ATTR_COLOR_RED));
	    offset = print("Some more text, but using fancy offsets so the first text isn't written over!", offset, makeAttr(ATTR_COLOR_LIGHT_GREEN, ATTR_COLOR_BLUE));
        offset = print("Some more text\nbut with\nline\nbreaks!", offset, makeAttr(ATTR_COLOR_RED, ATTR_COLOR_BLUE));
        offset = print("key press:", offset, makeAttr(ATTR_COLOR_WHITE, ATTR_COLOR_BLACK));
        offset = print(itos(12345678), offset, makeAttr(ATTR_COLOR_WHITE, ATTR_COLOR_BLACK));
    //}
    // just in case
    kill();
}

int print(char* text, unsigned int offset, char attr) {
	char* p_video_mem = (char*) VIDEO_MEMORY_LOCATION + offset;
	char* p_next_char = text;

	while(*p_next_char) {
        if(*p_next_char == '\n') {
            unsigned int currOffset = (int)p_video_mem - VIDEO_MEMORY_LOCATION;
            
            //go to beginning of line
            currOffset -= currOffset % (2*VIDEO_MEMORY_COLUMNS);
            //go down a line
            currOffset += 2*VIDEO_MEMORY_COLUMNS;
            //set location pointer
            p_video_mem = (char*)(VIDEO_MEMORY_LOCATION + currOffset);

            //go to next char
            p_next_char ++;
        }
        else {
		    *p_video_mem = *p_next_char;
            p_video_mem ++;
            p_next_char ++;
            *p_video_mem = attr;
            p_video_mem ++;
        }
	}

    return (int)p_video_mem - VIDEO_MEMORY_LOCATION - 2;
}

char makeAttr(char fgcolor, char bgcolor) {
    return (bgcolor<<4) | fgcolor;
}

void clear(char bg) {
    bg = makeAttr(bg, bg);
    char* p_video_mem = (char*) VIDEO_MEMORY_LOCATION;
    unsigned int offset = 0;
    
    while(offset < 80*25*2) {
        *p_video_mem = ' ';
        *p_video_mem = bg;
        p_video_mem ++;
        offset ++;
    }
}

inline void outb(unsigned short port, unsigned char val) {
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

inline unsigned char inb(unsigned short port) {
    unsigned char ret;
    asm volatile ("inb $1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

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


