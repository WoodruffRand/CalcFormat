#include "format.h"


int main(int n, char** args){
  char ** localArgs = NULL;
  int x = 0;
  localArgs =  copyStrings(n,localArgs, args);
  setStrsToLower(n,localArgs);

  char* temp = localArgs[1];
  localArgs[1] =malloc(sizeof(char)*strlen(temp)+2);
  localArgs[1][0] = 'b';
  localArgs[1][1] = 0;
  strcat(localArgs[1],temp);  
  
  if(badFormat(N_ARGS,n, localArgs)) return 1;
  x = strToInt(localArgs[1]);
  if( strcmp(localArgs[2],"int") == 0) {
    printf("%d\n",x);
  }else{
    char f[20]; 
    floatToASCII( (float)x, f);
    printf("%s\n",f);
    
  }
     
  
  return 0;
}


int badFormat(int N, int n, char** args){
  if(args == NULL ||n!= N){//wrong number of args
    printError(NUMB);
    return true;
  }
  if(strlen(args[1])!= 33){
    fprintf(stderr,"ERROR ");
    fprintf(stderr, "you must enter 32 bits\n");
    return true;
  }

  if(args[1] == NULL ||  !goodNumForm(args[1])  ){// bad number format 
    fprintf(stderr,"ERROR ");
    fprintf(stderr, "invalid bit sequence, use only 1 or 0\n");
    return true;
  }
  if(args[2] !=NULL && strcmp(args[2], "int") != 0 && strcmp(args[2], "float") != 0 ){//check for supported output specifyer int or float
    fprintf(stderr,"ERROR ");
    fprintf(stderr, "unrecognized output specifiyer\n");
    return true;
  }
     
  return false; //fall through, no problems dettected
}
