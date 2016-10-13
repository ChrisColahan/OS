

#define VIDEO_MEMORY_LOCATION 0xB8000

#define VIDEO_MEMORY_COLUMNS 80
#define VIDEO_MEMORY_LINES   25

#define COLOR_BLACK 0
#define COLOR_BLUE 1
#define COLOR_GREEN 2
#define COLOR_CYAN 3
#define COLOR_RED 4
#define COLOR_MAGENTA 5
#define COLOR_BROWN 6
#define COLOR_LIGHT_GRAY 7
#define COLOR_DARK_GREY 8
#define COLOR_LIGHT_BLUE 9
#define COLOR_LIGHT_GREEN 10
#define COLOR_LIGHT_CYAN 11
#define COLOR_LIGHT_RED 12
#define COLOR_LIGHT_MAGENTA 13
#define COLOR_LIGHT_BROWN 14
#define COLOR_WHITE 15

#define NEWLINE_CHAR 10

void main();
int print(char* text, int offset, char attr);
void kill();
char makeAttr(char fg, char bg);
void clear(char bg);
unsigned char getScancode();
static inline void outb(unsigned short port, unsigned char val);
static inline unsigned char inb(unsigned short port);

void entry() {
    main();
}

static inline void outb(unsigned short port, unsigned char val) {
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

static inline unsigned char inb(unsigned short port) {
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

char makeAttr(char fgcolor, char bgcolor) {
    return (bgcolor<<4) | fgcolor;
}

void main() {
	clear(COLOR_MAGENTA);
    int offset = print("Hello from the C kernel!", 0, makeAttr(COLOR_CYAN, COLOR_RED));
	offset = print("Some more text, but using fancy offsets so the first text isn't written over!", offset, makeAttr(COLOR_LIGHT_GREEN, COLOR_BLUE));
    offset = print("Some more text\nbut with\nline\nbreaks!", offset, makeAttr(COLOR_RED,COLOR_BLUE));
    kill();
}

void kill() {
	while(1) {}
}

int print(char* text, int offset, char attr) {
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
