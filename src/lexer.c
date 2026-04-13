#include<stdlib.h>
#include<ctype.h>
#include "asserts.h"

char peek(lexer *src, int offset) {
  // IMPORTANT - this function will have no safe grard
  // peek func returns the char m_index + offset 
  // without advencing the cursor
  if(src->m_index >= src->length) return '\0';
  return *(src->m_src + src->m_index + offset);
}

char consume(lexer *src) {
  // return the charater at m_index and increment
  // the index by one 
  if(src-> m_index >= src->length) return '\0'; 
  src->m_index++;
  return *(src->m_src +src->m_index -1); 
}

void tokenize(lexer *src){
  for(int i=0; src->m_index < src->length; i++) {
    if(isalpha(peek(src))) {
      char a = consume(src);
      src->m_buf[0] = a;
      for(int i= 1;isalpha(peek(src)) || peek(src) == '_'; i++) {
        if(i>= 9){
          printf("long idenitfer name\n");
        }
        char a = consume(src);
        src->m_buf[i] = a;  
      }
      src->m_buf[9] = '\0';
      to_string(src->m_buf);
    }
  }
}

char *to_token(const char *token_src) {
  Token t;
  switch (token_src) {
    case "i32" :
      t = {
        .type= i32,
        .value = '\0'
      };
    case ";":
      t = {
        .type= semi,
        .value = '\0'
      };
    case "{":
      t = {
        .type= open_cur,
        .value = '\0'
      };
    case "}":
      t = {
        .type= close_cur,  
        .value = '\0'
      };
    case "<-":
      t = {
        .type= assm_eq, 
        .value = '\0'
      };
    case "?":
      t = {
        .type= assm_eq, 
        .value = '\0'
      }; 
    case "->":
      t = {
        .type= flow_arrow, 
        .value = '\0'
      };
    case "@":
      t = {
        .type= args_, 
        .value = '\0'
      };
    case "^":
      t = {
        .type= args_, 
        .value = '\0'
      };
    case "^":
      t = {
        .type= args_, 
        .value = '\0'
      };
    case "^":
      t = {
        .type= args_, 
        .value = '\0'
      };
      
    //case
  }
  return t;
}
