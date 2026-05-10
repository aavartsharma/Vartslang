#ifndef LEXER_H 
#define LEXER_H 
#include "asserts.h"
char peek(lexer *src, int offset);

char consume(lexer *src);

TokenType to_token(const char *token_src);

void tokenize(lexer *src);
#endif
