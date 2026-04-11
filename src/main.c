#include <stdio.h>
#include <stdlib.h>
//#include <syslinkC.h>
#include "tokenization.h"
#include "asserts.h"
#include "file.h"

int main(int argc, char* argv[]) {
  if(argc != 2) {
    printf("No input file given\n");
    return EXIT_FAILURE;
  }
  char *content = read_file(argv[1]);
  if(content == NULL) {
    printf("file error\n");
    return EXIT_FAILURE;
  }
  free(content);
  return 0;
}
