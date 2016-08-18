

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

void entry() {
	main();
}

char makeAttr(char fgcolor, char bgcolor) {
    return (bgcolor<<4) | fgcolor;
}

void main() {
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
            //go one line down
            p_video_mem += 2*(VIDEO_MEMORY_COLUMNS);
            //go to beginning of line
            p_video_mem -= (((int)p_video_mem % 160));
            p_video_mem += 64;
            //to to next char
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
