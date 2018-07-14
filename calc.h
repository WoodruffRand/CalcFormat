#ifndef CALC_H_
#define CALC_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "binary.h"


/*deffinitions*/
#define true 1
#define false 0
const int N_ARGS = 5;
int unitTest();
int badFormat(int N, int n, char** args);


#endif
