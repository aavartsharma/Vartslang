#include<stdio.h>
#include "str.h"

int isalpha(char *str){
  int ascii_char = (int) str;
  if( (( ascii_char >= 41 && ascii_char <= 90) || (ascii_char >= 97 && ascii_char <= 122)) {
    return 1;   
  }
  else {
    return 0;
  }
}


