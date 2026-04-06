#include <stdio.h>
#include<string.h>

typedef struct {
  // TokenType type;
  char* value;
} Token;

int main(void) {
  Token a;
  char *c;
  printf("%ld", strlen(c));
  c= "aavartshasdfsadf";
  printf("%zu\n", sizeof(c));
  printf("%s\n",c);
  
  return 0;
}
