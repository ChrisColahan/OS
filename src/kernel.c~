

#define VIDEO_MEMORY_LOCATION 0xB8000

void main();
void print();
void kill();

void entry() {
	main();
}

void main() {
	print("hello from the C kernel!");
	kill();
}

void kill() {
	while(1) {}
}

void print(char* text) {
	char* p_video_mem = (char*) VIDEO_MEMORY_LOCATION;
	char* p_next_char = text;

	while(*p_next_char) {
		*p_video_mem = *p_next_char;
		p_next_char ++;
		p_video_mem += 2;
	}
}
