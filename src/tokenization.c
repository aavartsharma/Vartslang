#include<stdlib.h>
#include "asserts.h"

void peek(Tokenizer *src, int offset = 0) {
  // IMPORTANT - this function will have no safe grard
  if(src->m_index >= src->length) return "";
  return *(src->m_src + m_index + offset);
}

void consume(Tokenizer *src,int offset=1) {
  return (src->m_src+offset); 
}

void tokenize(FILE *file){
  char ch;
  for(int len =0;(ch=fgetc(fptr)) != EOF;len++) {
    // if it is End of file return   
    if()
  }
  return str;
}

void to_string(const TokenType type) {
  switch (type) {
    case i32:
      return "i32";
    case semi:
      return ";";
  }
}
