#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "asserts.h"

char peek(lexer *src, int offset) {
  // IMPORTANT - this function will have no safe grard
  // peek func returns the char m_index + offset
  // without advencing the cursor
  if ((src->m_index + offset) >= src->src.len)
    return '\0';
  return *(src->src.src + src->m_index + offset);
}

char consume(lexer *src) {
  // return the charater at m_index and increment
  // the index by one
  if (src->m_index >= src->src.len)
    return '\0';
  src->m_index++;
  return *(src->src.src + src->m_index - 1);
}

TokenType to_token(const char *token_src) {
  // Keyword
  if (strcmp(token_src, "<-@->") == 0) {
    return FUNC;
  } else if (strcmp(token_src, "<-?->") == 0) {
    return LOP;
  } else if (strcmp(token_src, "<->") == 0) {
    return FEL;
  } else if (strcmp(token_src, "@") == 0) {
    return ARG;
  } else if (strcmp(token_src, "?") == 0) {
    return IF;
  } else if (strcmp(token_src, "^") == 0) {
    return RET;
  } else if (strcmp(token_src, "i32") == 0) {
    return I32;
  } else if (strcmp(token_src, "i64") == 0) {
    return I64;
  } else if (strcmp(token_src, "f32") == 0) {
    return F32;
  } else if (strcmp(token_src, "f64") == 0) {
    return F64;
  } else if (strcmp(token_src, "u8") == 0) {
    return U8;
  }

  // operator / assign
  else if (strcmp(token_src, "<-") == 0) {
    return ASSIGN;
  } 
  // operator/arthimatic
  else if (strcmp(token_src, "+") == 0) {
    return PLUS;
  } else if (strcmp(token_src, "-") == 0) {
    return MINUS;
  } else if (strcmp(token_src, "*") == 0) {
    return MUL;
  } else if (strcmp(token_src, "/") == 0) {
    return DIV;
  } else if (strcmp(token_src, "++") == 0){
    return INC; 
  } else if (strcmp(token_src, "--") == 0) {
    return DEC;
  }  

  // operator/logical
  else if (strcmp(token_src, ">") == 0) {
    return MT;
  } else if (strcmp(token_src, "<") == 0) {
    return LT;
  } else if (strcmp(token_src, ">=") == 0) {
    return MTE;
  } else if (strcmp(token_src, "<=") == 0) {
    return LTE;
  } else if (strcmp(token_src, "!") == 0) {
    return NOT;
  } else if (strcmp(token_src, "/\\") == 0) {
    return AND;
  } else if (strcmp(token_src, "\\/") == 0) {
    return OR;
  } else if (strcmp(token_src, "==") == 0) {
    return EQU;
  } else if (strcmp(token_src, "!=") == 0) {
    return NEQU;
  } 

  // puncutations
  else if (strcmp(token_src, "->") == 0) {
    return FLW_ARR;
  } else if (strcmp(token_src, ";") == 0) {
    return SEMI;
  } else if (strcmp(token_src, "{") == 0) {
    return OCR;
  } else if (strcmp(token_src, "}") == 0) {
    return CCR;
  } else if (strcmp(token_src, ",") == 0) {
    return COMMA;
  } else if (strcmp(token_src, "\n") == 0){
    return NL;
  }
  

  else if (isdigit(*token_src)) {
    return INTGER;
  } else if (isalpha(*token_src)) {
    return ID;
  } else {
    printf("lexer.c to_token function: unknown token %s\n", token_src);
    return 0; // make sure you define this
  }
}


// function for repeactig tokeniztion
//
int alpha(char chr){
  return isalpha(chr) || isdigit(chr) || chr == '_';
}
int numa(char chr) {
  return isdigit(chr) || chr == '_';
}
int extr(char chr) {
  int ispunc = 0;
  switch (chr) {
    case ';':
      ispunc = 1; 
    case '{':
      ispunc = 1;
    case '}':
      ispunc = 1;
    case ',':
      ispunc =1;
    case '.':
      ispunc =1;
    case '\n':
      ispunc =1;
  } 

  return (chr != ' ' && !isdigit(chr) && !isalpha(chr) && !(ispunc==1));
}
Token ret_token(lexer *src, int (*fun)(char)) {
  src->m_buf = (link_chr *)malloc(sizeof(link_chr));
  src->m_buf->c = consume(src);
  src->m_buf->aft_chr = NULL;
  link_chr *temp_ptr = src->m_buf;
  int lenght = 1;

  for (int i = 1;fun(peek(src,0));i++) {
    if (i > 17)
      break;
    temp_ptr->aft_chr = (link_chr *)malloc(sizeof(link_chr));
    temp_ptr->aft_chr->c = consume(src);
    //printf("peeky: %c\n", peek(src, 0));
    temp_ptr->aft_chr->aft_chr = NULL;
    temp_ptr = temp_ptr->aft_chr;
    lenght++;
  }
  char *str_buf = (char *)malloc((lenght * sizeof(char)) + 1);
  for (int i = 0; src->m_buf != NULL; i++) {
    //printf("%c(%d)", src->m_buf->c,src->m_buf->c);
    printf("%c", src->m_buf->c);
    *(str_buf + i) = src->m_buf->c; //
    src->m_buf = src->m_buf->aft_chr;
    if (i >= lenght) {
      printf("\ntonken lenght is e then buffer by %d\n", i - lenght);
      break;
    }
  }
  *(str_buf + lenght) = '\0';
  printf("\n");

  TokenType tok = to_token(str_buf);
  Token a = {
    .type = tok,
    .value = '\0',
    .n_token = NULL
  };
  free(str_buf);
  str_buf = NULL;
  return a;
}
void push(Token **src,Token tok) { // i don't know why it didn't work with single pointer
  if((*src) == NULL) {
    Token *ptr_tok = (Token *) malloc(sizeof(Token));
    *ptr_tok = tok;  
    *src = ptr_tok;
    return ;
  }
  push(&((*src)->n_token), tok);
}

void show_item(Token *t,int i) {
  if(t == NULL) {
    printf("----\n");
    return;
  }
  printf("%d -> %d\n",i, (int) t->type );
  show_item(t->n_token, i+1);
}

void tokenize(lexer *src) { // make this return list of tokens somehow
  for (int i = 0; src->m_index < src->src.len; i++) {
    if (isalpha(peek(src, 0))) {
      push(&(src->m_res),ret_token(src,alpha));
    } else if (isdigit(peek(src, 0))) {
      push(&(src->m_res),ret_token(src,numa));
    } else if (!(peek(src,0) == ' ' || peek(src,0) == '\n')) {
      push(&(src->m_res),ret_token(src,extr));
    } else {
      src->m_index++;
    }
  }
  printf("__________\n");
  show_item(src->m_res,0);
}
