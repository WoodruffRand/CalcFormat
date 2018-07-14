#ifndef BINARY_H_
#define BINARY_h_

union Number {
	int	i;
	float	f;
};



void intToDecASCII(int pow10, char* exponent );
void floatToASCII( float x, char * output );
static void get_float_digit( float x, char * digit, int * pow10, float * remainder );
static void append( char * s, char c );

#endif
