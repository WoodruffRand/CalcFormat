#include "binary.h"

long  strToInt(char* str){
  long rtnVal = 0;
  int mult = 1;
  
  int base=  getBase(str[0]);
  if(str[1]=='-'){
    mult = -1;
    str[1] ='d';
    str++;
  }
  
  str++;
  for( ; *str; str++){
    rtnVal = rtnVal*base+charToInt(*str);
  }
  return mult*rtnVal;

}


char* intToStr(long x, char c){
  int base = getBase(c);
  char* str = malloc(sizeof(char)*65);
  int i = 0;
  int neg =1;
  if(c == 'd' && x<0) {
    x*=-1;
    neg = -1;
  }

  
  if(x ==0 ){
    str[i++] ='0';
  }else{
    while((unsigned long)x > 0){
      int diff = x%((unsigned long)base); 
      if(diff <10) str[i] = diff+'0';
      else str[i] = diff-10+'a';
      x /= ((unsigned long)base);
      i++;
    }
  }
  if(c =='d' && neg <0) str[i++] = '-';
  str[i++] = c;
  str[i] = 0;
  flipStr(i, str);
  return str;
}





void printError(int err){
  fprintf(stderr,"ERROR ");

  switch (err){

  case NUMB:
    fprintf(stderr,"Wrong number of args, follow format <opp> <numb1> <nub2> <output format>\n");
    return;
  case OPP:
    fprintf(stderr,"unrecognized opp, please use + , - or *\n");
    return;
  case NUMB_FORMAT:
    fprintf(stderr,"Bad number format, check specifyer and digits, please use (b|o|d|x)-------\n");
    return;
  case OUT_FORMAT:
    fprintf(stderr,"BAD output format, please use (b|o|d|x)\n ");
    return;
  case SIZE:
    fprintf(stderr,"Provided input is too large to fit into a long int, sorry bud.");
    return;
  }
  //fall through
  printf("Unknow error code in print error function: %d\n", err);
}


int notOpp(char* opp){
  if(opp == 0) return true;
  if(!isLength(1, opp)) return true;
  if(opp[0]=='-') return false;
  if(opp[0]=='+') return false;
  if(opp[0]=='*') return false;
  
  return true;// fall through
}


int isLength(int n , char * str){
  int i = 0;
  for( ; str[i]; i++){
    if( i+1>n) return false ;
  }
  //printf("i is %d, n is %d\n",i,n);
  return i == n;
}


void printArgs(int n, char** argv){
  for(int i =0 ; i<n;i++){
    printf("%s\n",argv[i]);
  }


}



int goodNumForm(char* arg){
  if(arg == 0) return false; 
  //printf("%lu\n",strlen(arg));
  switch(arg[0]){

  case 'b':
    return isNary(2,arg+1);
  case 'o':
    //check octal
    return isNary(8, arg+1);
  case 'd':
    //check decmial format
    if(arg[1]== '-') return  isNary(10,arg+2);  //check for minus
    return isNary(10, arg+1);
  case 'x':
    //checl hexadecmial
    return isNary(16, arg+1);  
  }
  //fall through, did not find proper format specifier 
  return false;
}



int goodOutFromat(char* arg){
  if(arg == 0) return false;
  if(!isLength(1,arg)) return false;
  if(arg[0]== 'b') return true;
  if(arg[0] == 'd') return true;
  if( arg[0] == 'o') return true;
  if( arg[0] == 'x') return true; 
  return false; 
  
}

int charToInt(char c){
  if('0'<=c && c <= '9'){
    return c-'0';
  }
  if('a'<=c && c <= 'f'){
    return 10+c-'a';
  }

  return -1;// error 
}




int getBase(char c){
  switch(c){
  case 'b':
    return 2;
  case 'o':
    return 8;
  case 'd':
    return 10;
  case 'x':
    return 16;
  }
  //fallthrough
  return -1; 
  

}


int isNary(int n,char* str){
  if(str == 0) return false;

  for(;*str; str++){
    if(charToInt(*str)<0) return false;
    if(charToInt(*str)>=n) return false;
  }

  return true; //fall through no problems found
}



void flipStr( int l, char* str){
  int i = --l;

  for( ; i>l/2; i--){
    char temp = str[i];
    str[i] = str[l-i];
    str[l-i] = temp;
  }

}


void setStrsToLower(int n, char ** strv){
  for(int i = 0; i< n; i++){
    for(char* p = strv[i]; *p; p++){
      *p =tolower(*p);
      //printf("%c\n",*p);
    }
  }
}

char** copyStrings(int n, char** argsN, char** argsO){
  argsN = malloc(sizeof(char*)*n);
  for(int i = 0; i< n; i++){
   argsN[i]= malloc(sizeof(char)*(strlen(argsO[i]+1)));
    strcpy(argsN[i], argsO[i]);
    // printf("%s\n", argsN[i]);
  }
  return argsN;
}

void freeStrings(int n, char ** v){
  for(int i = 0; i <n; i++){
    free(v[i]);
  }
  free(v);
}



int overSize(char* input){
  char* decComp;
  switch(input[0]){
  case 'b':
    return (strlen(input)>64+1);//plus one for format char
  case 'o':
    if (strlen(input)<21+1) return false;
    if (strlen(input)>22+1) return true;
    return  !(input[1] =='1' || input[1] == '0');//need to check for sign bit at max len
  case 'd':
    decComp = input+1;
    if(input[1] =='-' && (strcmp(decComp+1, "9223372036854775808")>0) ) return true;
    if(strcmp(decComp, "9223372036854775807")>0) return true;
    return false;
  case 'x':
    return (strlen(input)>16+1);
  default:
    fprintf(stderr, "holly pancakes we got a problem in size limit detection");
    return false;
  }

}
