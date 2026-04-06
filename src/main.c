#include <stdio.h>
#include <stdlib.h>
//#include <syslinkC.h>
#include "tokenization.h"


int main(int argc, char* argv[]) {
  if(argc != 2) {
    printf("No input file given\n");
    return EXIT_FAILURE;
  }
  FILE *file = fopen(argv[1], "r");
  if(file==NULL){
    printf("Error opening file. \n");
    return EXIT_FAILURE; 
  }
  char ch;
  while (fgetc(file)) {
    // 
    printf("%c\n",ch);
  }
  fclose(file);
  return 0;
}
