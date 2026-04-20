#ifndef LEXER_H 
#define LEXER_H 
#include "asserts.h"
char peek(lexer *src, int offset);

char consume(lexer *src);

void tokenize(lexer *src);
#endif
