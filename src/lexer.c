#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "asserts.h"

char peek(lexer *src, int offset) {
  // IMPORTANT - this function will have no safe grard
  // peek func returns the char m_index + offset 
  // without advencing the cursor
  if((src->m_index +offset) >= src->src.len) return '\0';
  return *(src->src.src + src->m_index + offset);
}

char consume(lexer *src) {
  // return the charater at m_index and increment
  // the index by one 
  if(src-> m_index >= src->src.len) return '\0'; 
  src->m_index++;
  return *(src->src.src +src->m_index -1); 
}

Token to_token(const char *token_src) {
  Token t;
    // Keyword
  if(strcmp(token_src, "<-@->") == 0) {
    t.type = FUNC;
    t.value = '\0';
  }
  else if(strcmp(token_src,"<-?->") == 0) {
    t.type = LOP;
    t.value = '\0';
  }

  else if (strcmp(token_src, "@") == 0) {
    t.type = ARG;
    t.value = '\0';
  }
  else if (strcmp(token_src, "?") == 0) {
    t.type = IF;
    t.value = '\0';
  }
  else if (strcmp(token_src, "^") == 0) {
    t.type = RET;
    t.value = '\0';
  }
  else if (strcmp(token_src, "i32") == 0) {
    t.type = I32;
    t.value = '\0';
  }

  // operator / assign
  else if (strcmp(token_src, "<-") == 0) {
    t.type = ASSIGN;
    t.value = '\0';
  }
  else if (strcmp(token_src, "+") == 0) {
    t.type = PLUS;
    t.value = '\0';
  }
  else if (strcmp(token_src, "-") == 0) {
    t.type = MINUS;
    t.value = '\0';
  }
  else if (strcmp(token_src, "*") == 0) {
    t.type = MUL;
    t.value = '\0';
  }
  else if (strcmp(token_src, "/") == 0) {
    t.type = DIV;
    t.value = '\0';
  }
  else if (strcmp(token_src, "&&") == 0) {
    t.type = AND;
    t.value = '\0';
  }
  else if (strcmp(token_src, "||") == 0) {
    t.type = OR;
    t.value = '\0';
  }
  else if (strcmp(token_src, "->") == 0) {
    t.type = FLW_ARR;
    t.value = '\0';
  }
  else if (strcmp(token_src, ";") == 0) {
    t.type = SEMI;
    t.value = '\0';
  }
  else if (strcmp(token_src, "{") == 0) {
    t.type = OCR;
    t.value = '\0';
  }
  else if (strcmp(token_src, "}") == 0) {
    t.type = CCR;
    t.value = '\0';
  }
  else {
    printf("lexer.c line 96\n");
  }
  return t;
}

void tokenize(lexer *src){
  for(int i=0; src->m_index < src->src.len; i++) {
    if(isalpha(peek(src,0))) {
      char a = consume(src);
      src->m_buf[0] = a;
      char n_char = peek(src,0);
      for(int i= 1;isalpha(n_char) || isdigit(n_char) || n_char == '_'; i++) {
        
        /*if(i>= 9) {
          printf("long idenitfer name\n");
        }
        char a = consume(src);
        strcat(src->m_buf, &a);
        //src->m_buf[i] = a;  */
      }
      //src->m_buf[] = '\0';
      to_token(src->m_buf);
    }
    else if (/*iis*/)
  }
}


