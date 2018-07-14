#include "calc.h"
/*local functions*/


int main(int n, char** args ){
  /*if (!unitTest()){
    printf("Failed my crappy unit testing");
    return 1;
    }*/

  long a ,b, c;
  
  char** localArgs = NULL;//made local copy so they are editable
  localArgs = copyStrings(n , localArgs, args);
  setStrsToLower(n,localArgs);//told you i wanted to edit them!
  if(badFormat(N_ARGS, n, localArgs)) return 1;
  
  a = strToInt(localArgs[2]);
  b = strToInt(localArgs[3]);

  if(localArgs[1][0] == '+'){
    c = a+b;
  } else if(localArgs[1][0] == '-'){
    c = a-b;
  } else if(localArgs[1][0] == '*'){
    c = a*b;
  } 
  char * result = intToStr(c, localArgs[4][0]);
  printf("%ld %s %ld is %s\n",a, args[1], b,result);
  // printf("%ld %s %ld is %ld\n",a, args[1], b,c);
  free(result);  
  return 0;
}


int unitTest(){

  long x = 0x8000000000000001;
  printf("a:%ld\n",x);
  x *= -1;
  printf("b:%ld\n",x);
  for( long  i =  -1000000; i<=10000000; i++){
    char* str =intToStr (i,'o') ;
    if(i !=  strToInt(str)){
      printf("String: , %s\n",str  );
      printf("back to int, %ld\n", strToInt(str) );
      printf("input, %ld\n", i);
      return false;
    }
    free(str);

  }

  printf("passed unit testing\n");
  return true;

}

int badFormat(int N, int n, char** args){
  if(args == NULL ||n!= N){//wrong number of args
    printError(NUMB);
    return true;
  }
  if(notOpp(args[1])){// cannot recogize opperator
    printError(OPP);
    return true;
  }
  if(!(goodNumForm(args[2]) && goodNumForm(args[3]))){// bad number format 
    printError(NUMB_FORMAT);
    return true;
  }
  if(!goodOutFromat(args[4])){//check for supported output specifyer
    printError(OUT_FORMAT);
    return true;
  }
  if( overSize(args[2]) || overSize(args[3]) ){//detect size problems
    printError(SIZE);
    return true;
  }
     
  return false; //fall through, no problems dettected
}
