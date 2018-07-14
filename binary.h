#ifndef BINARY_H_
#define BINARY_h_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

enum eCode{ NUMB, OPP, NUMB_FORMAT,OUT_FORMAT, SIZE, FOR_NUMB_FORMAT };
#define true 1
#define false 0


void printError(int err);
int notOpp(char* opp);
int isLength(int n , char * str);
void printArgs(int n, char** argv);
int goodNumForm(char* arg);
int goodOutFromat(char* arg);
int isNary(int n, char* str);
int overSize(char* input);


void flipStr(int l, char* str);
char** copyStrings(int n, char** argsN, char** argsO);
void freeStrings(int n, char ** v);
void setStrsToLower(int n,char ** strv);

long strToInt(char* str); 
int charToInt(char c);
int getBase(char c);
char* intToStr(long x, char c);


#endif
