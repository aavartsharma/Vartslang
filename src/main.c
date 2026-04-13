#include <stdio.h>
#include <stdlib.h>
//#include <syslinkC.h>
#include "lexer.h"
#include "asserts.h"
#include "file.h"

int main(int argc, char* argv[]) {
  if(argc != 2) {
    printf("No input file given\n");
    return EXIT_FAILURE;
  }
  src_code content = read_file(argv[1]);
  if(content.src == NULL) {
    printf("file error\n");
    return EXIT_FAILURE;
  }

  printf("%s\n", content.src);
  lexer src = {
    .m_src = content.src,
    .m_buf = "",
    .m_index= 0,
    .length = content.len,
    .m_res = NULL
  };
  printf("peek -> %c\n",peek(src,0));
  printf("cosome -> %c\n", consume(&src));
  printf("peek -> %c\n",peek(src,1));
  free(content.src);
  return 0;
}
