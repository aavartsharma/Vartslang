#include <stdio.h>
#include <stdlib.h>

typedef enum {
  _return,
  int_lit,
  semi_c,
} TokenType;

typedef struct {
  TokenType type;
  char* value;
} Token;

char* tokenize(char *str, int length){
  for(int i=0; i < length; i++){
    // if it is End of file return 
    // 
  }
  return str;
}
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
  char *buffer;

  while(fgets(buffer, sizeof(buffer), file) != NULL){
    printf("%s", buffer);
  }
  tokenize(buffer, sizeof(buffer)/sizeof(buffer[0]));
  fclose(file);
  return 0;
}
