#include <stdio.h>

typedef struct {
  // TokenType type;
  char* value;
} Token;

void concat_strings(char *str1, const char *str2) {
  // ?
  char *end = str1;
  while(*end != '\0') {
    end++; 
  }
  while(*str2 != '\0') {
    *(end) = *(str2);
    str2++;
    end++;
  }
  *end = '\0';
  //*(str1) = '\0';
}

int main(void) {
  //printf("%zu\n", sizeof(c));
  //printf("%s\n",c);
  char *name = "matana";
  char *sur_name = " john";
  concat_strings(name, sur_name);
  printf("%s\n", name);

  return 0;
}
