
#ifndef MATH_H
#define MATH_H

//constants. may need to increase/decrease their length later.

//eulers constant
#define M_E 2.718281828459045235360287471352662497757247093699959574966967627724076630353

//log base 2 of e
#define M_LOG2E 

//log base 10 of e
#define M_LOG10E

//log base e of 2
#define M_LN2

//log base e of 10
#define M_LN10

//pi constant
#define M_PI

//functions
#define abs(n) (n >= 0.0 ? n : -n)

#define floor(n) ((double)((long)n))

#define ceil(n) (n < 0.0 ? floor(n) - 1 : floor(n) + 1)

//return e to the nth power
double exp(double n);

//returns log base 2 of n
double log2(double n);

double log10(double n);

//returns a to b power
double pow(double a, double b);

//returns
#endif

