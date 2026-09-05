#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "asserts.h"
#include "lexer.h"
#include "parser.h"
#include "grammer.h"

int main(int argc, char* argv[]) {
  if(argc != 2) {
    printf("No input file given\n");
    printE("NO INPUT FILE GIVEN");
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
    TokenType a = to_token(";");
    printf("%d\n----\n", a);
    Token_node aa = {
      .val = a,
      .next_el = NULL
    };
    //printf("%d\n", (src.m_res)->type);
    return 0;
  }
  tokenize(&src);
  Parser tokens = {
    .m_buf = src->m_res,
    .peek = &peek_token,
    .peekFor = &peekFor,
    .consume = &consume_token,
    .TryConsume = &TryConsume,
    .m_res = NULL,
  };
  Parsing(&tokens);
  free(src.src.src);
  return 0;
}
