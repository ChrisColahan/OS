
//this needs to be here!
void main();

//boostrap kernel
void entry() {
    main();
}

//do normal C things

#include "../io.h"
#include "../util.h"
#include "../math.h"
#include "../graphics.h"


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
