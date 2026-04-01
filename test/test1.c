#include <stdio.h>

char* name(char* b){
  char a= 'a';
  return b;
}

int main(void){
  char b;
  b = '0';
  printf("%s", name(&b));
  return 0;
}
