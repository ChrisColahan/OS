
#ifndef GRAPHICS_H
#define GRAPHICS_H

/*
* Details for how VGA memory works.
*
* Every character is 2 bytes:
* First byte is the character in ASCII.
* Second byte is the color attribute.
* First 4 bits (high bits) are the background color.
* Second 4 bits (low bits) are the foreground color (text color).
*
* VGA Memory starts at 0xB8000.
* VGA memory has 80 columns and 25 lines of characters (2 bytes each).
*/

// graphics constants for drawing on screen

#define VIDEO_MEMORY_LOCATION 0xB8000

#define VIDEO_MEMORY_COLUMNS 80
#define VIDEO_MEMORY_LINES   25

// base VGA attribute colors
#define ATTR_COLOR_BLACK 0
#define ATTR_COLOR_BLUE 1
#define ATTR_COLOR_GREEN 2
#define ATTR_COLOR_CYAN 3
#define ATTR_COLOR_RED 4
#define ATTR_COLOR_MAGENTA 5
#define ATTR_COLOR_BROWN 6
#define ATTR_COLOR_LIGHT_GRAY 7
#define ATTR_COLOR_DARK_GREY 8
#define ATTR_COLOR_LIGHT_BLUE 9
#define ATTR_COLOR_LIGHT_GREEN 10
#define ATTR_COLOR_LIGHT_CYAN 11
#define ATTR_COLOR_LIGHT_RED 12
#define ATTR_COLOR_LIGHT_MAGENTA 13
#define ATTR_COLOR_LIGHT_BROWN 14
#define ATTR_COLOR_WHITE 15

// make a full VGA color attribute
char makeAttr(char fg, char bg);

// clear screen, filling all characters with the background color
void clear(char bg);

// print text to screen
// text is the null ('\0') terminated string to print
// offset is the offset (in bytes) offset to start printing at
// attr is the color attribute that describes background and foreground color.
// returns new offset (offset + length(text) - 1).
int print(char* text, unsigned int offset, char attr);

#endif
