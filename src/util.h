
#ifndef UTIL_H
#define UTIL_H

//utility functions

// stop interrupts (cli)
void disable_interrupts();

// enable interrupts (sti)
void enable_interrupts();

//prevent further exectuion of code
void kill();

//convert unsigned integer to a string
char* itos(unsigned int i);

#endif
