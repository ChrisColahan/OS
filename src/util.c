
#include "util.h"

void kill() {
	while(1) {}
}

char* itos(unsigned int num) {
    char res[30]; // long enough for largest number
    unsigned int i, counter = 0;
	char* buf = &res[0];
    
	if (num == 0) {
        buf[counter++] = '0';
    }

    for ( ; num; num /= 10) {
        buf[counter++] = "0123456789"[num%10];
    }
    
    buf[counter] = '\0';

    for(i = 0; i < counter / 2; i ++) {
        char tmp = buf[i];
        buf[i] = buf[counter - i - 1];
        buf[counter - i - 1] = tmp;
    }

    return buf;
}
