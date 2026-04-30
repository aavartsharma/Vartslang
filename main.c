#include <stdio.h>
#include <stdlib.h>
#include "src/lexer.h"
#include "src/asserts.h"
#include "src/file.h"

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
    .m_buf = NULL,
    .m_index= 0,
    .src = content,
    .m_res = NULL
  };
  tokenize(&src);

  free(src.src.src);
  return 0;
}
