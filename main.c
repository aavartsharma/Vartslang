#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
    .m_buf = NULL,
    .m_index= 0,
    .src = content,
    .m_res = NULL
  };
  if(0) {
    TokenType a = to_token("; ");
    printf("%d\n----\n", a);
    //new()
    Token aa = {
      .type = a,
      .value = '\0',
      .n_token = NULL
    };
    //push(&(src.m_res), *aa);
    //printf("%d\n", (src.m_res)->type);
    return 0;
  }
  TokenType aaa = OR;
  printf("%zu -> %zu \n", sizeof(TokenType),sizeof(aaa));
  tokenize(&src);
  //parser(&src);
  free(src.src.src);
  return 0;
}
