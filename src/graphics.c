
#include "graphics.h"

char makeAttr(char fgcolor, char bgcolor) {
    return (bgcolor<<4) | fgcolor;
}

void clear(char bg) {
    bg = makeAttr(bg, bg);
    char* p_video_mem = (char*) VIDEO_MEMORY_LOCATION;
    unsigned int offset = 0;
    
    while(offset < VIDEO_MEMORY_COLUMNS*VIDEO_MEMORY_LINES*2) {
        *p_video_mem = ' ';
        *p_video_mem = bg;
        p_video_mem ++;
        offset ++;
    }
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
