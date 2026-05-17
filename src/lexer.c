#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "asserts.h"

char peek_char(lexer *src, int offset) {
  // IMPORTANT - this function will have no safe grard
  // peek func returns the char m_index + offset
  // without advencing the cursor
  if ((src->m_index + offset) >= src->src.len)
    return '\0';
  return *(src->src.src + src->m_index + offset);
}

char consume_char(lexer *src) {
  // return the charater at m_index and increment
  // the index by one
  if (src->m_index >= src->src.len)
    return '\0';
  src->m_index++;
  return *(src->src.src + src->m_index - 1);
}

TokenType to_token(const String token_src) {
  // Keyword
  if (strcmp(token_src, "<-@->") == 0)       return FUNC;
  else if (strcmp(token_src, "<-?->") == 0)  return LOP;
  else if (strcmp(token_src, "<-:->") == 0)  return FEL;
  else if (strcmp(token_src, "<-[]->") == 0) return LST;
  else if (strcmp(token_src, "@") == 0)      return ARG;
  else if (strcmp(token_src, "<|") == 0)     return CAL;
  else if (strcmp(token_src, "?") == 0)      return IF;
  else if (strcmp(token_src, "^") == 0)      return RET;
  else if (strcmp(token_src,"[]")== 0 )      return LIT;
  else if (strcmp(token_src, "i32") == 0)    return I32;
  else if (strcmp(token_src, "i64") == 0)    return I64;
  else if (strcmp(token_src, "f32") == 0)    return F32;
  else if (strcmp(token_src, "f64") == 0)    return F64;
  else if (strcmp(token_src, "u8") == 0)     return U8;
 

  // operator / assign
  else if (strcmp(token_src, "<-") == 0)     return ASSIGN;

  // operator/arthimatic
  else if (strcmp(token_src, "+") == 0)      return PLUS;
  else if (strcmp(token_src, "-") == 0)      return MINUS;
  else if (strcmp(token_src, "*") == 0)      return MUL;
  else if (strcmp(token_src, "/") == 0)      return DIV;
  else if (strcmp(token_src, "++") == 0)     return INC; 
  else if (strcmp(token_src, "--") == 0)     return DEC;

  // operator/logical
  else if (strcmp(token_src, ">") == 0)      return MT;
  else if (strcmp(token_src, "<") == 0)      return LT;
  else if (strcmp(token_src, ">=") == 0)     return MTE;
  else if (strcmp(token_src, "<=") == 0)     return LTE;
  else if (strcmp(token_src, "!") == 0)      return NOT;
  else if (strcmp(token_src, "/\\") == 0)    return AND;
  else if (strcmp(token_src, "\\/") == 0)    return OR;
  else if (strcmp(token_src, "==") == 0)     return EQU;
  else if (strcmp(token_src, "!=") == 0)     return NEQU; 
  // operator/somthing
  else if (strcmp(token_src, "<-:")==0)      return IN;

  // puncutations
  else if (strcmp(token_src, "->") == 0)     return FLW_ARR;
  else if (strcmp(token_src, ";") == 0)      return SEMI;
  else if (strcmp(token_src, "{") == 0)      return OCR;
  else if (strcmp(token_src, "}") == 0)      return CCR;
  else if (strcmp(token_src, ",") == 0)      return COMMA;
  else if (strcmp(token_src, ".") == 0)      return DOT;
  else if (strcmp(token_src, "\n") == 0)     return NL;
  

  else if (isdigit(*token_src)) return INTGER;
  else if (isalpha(*token_src)) return ID;


  else {
    printf("lexer.c to_token function: unknown token %s, %d, %d\n", token_src,*token_src,*(token_src+1));
    exit(-1);
    return -1; // make sure you define this
  }
}

Token_node ret_token(lexer *src, int (*fun)(char), int offset) {
  int lenght = 0;
  chr_node **temp_ptr = &(src->m_buf); 
  for (int i = 0;fun(peek_char(src,offset));i++) {
    if (i > 17)
      break;
    printf("peeky: %c\n", peek_char(src, 0));
    char temp_char_var = consume_char(src);
    push_chr_node(temp_ptr,new_chr_node(temp_char_var));
    lenght++;
  }
  String str_buf = (char *)malloc((lenght * sizeof(char)) + 1);
  for (int i = 0; src->m_buf != NULL; i++) {
    *(str_buf + i) = src->m_buf->val; //
    src->m_buf = next_chr_node(src->m_buf);
    if (i > lenght) {
      printf("\n");
      printE("tonken lenght is e then buffer by %d", i - lenght);
      break;
    }
  }
  *(str_buf + lenght) = '\0';
  printf("str_buf : %s\n",str_buf);

  TokenType tok = to_token(str_buf);
  Token_node a = {
    .val = tok,
    .next_el = NULL
  };
  free(str_buf);
  str_buf = NULL;
  return a;
}

int alpha(char chr){
  return isalpha(chr) || isdigit(chr) || chr == '_';
}
int numa(char chr) {
  return isdigit(chr) || chr == '_';
}
int extr(char chr) {
  return (chr != ' ' && !isdigit(chr) && !isalpha(chr) && !is_pucuation(chr));
}

int is_pucuation(char chr){
  if(chr ==';' || chr == '{' || chr == '}' || chr == ',' || chr == '.' || chr == ';') {
    return 1;
  }
  return 0;
}

int reverse_puc(char chr) {
  return !is_pucuation(chr);
}

void tokenize(lexer *src) { // make this return list of tokens somehow
  printf("reading source code\n");
  for (int i = 0; src->m_index < src->src.len; i++) {
    if(i>500) break;
    if (isalpha(peek_char(src, 0))) {
      Token_node tok = ret_token(src,alpha,0);
      push_Token_node(&(src->m_res),&tok);
    } else if (isdigit(peek_char(src, 0))) {
      Token_node token_test = ret_token(src,numa,0);
       
      push_Token_node(&(src->m_res),&token_test);
    } else if (is_pucuation(peek_char(src,0))){
      Token_node token_test = ret_token(src,reverse_puc,-1);
      push_Token_node(&(src->m_res), &token_test);
    } else if (!(peek_char(src,0) == ' ' || peek_char(src,0) == '\n')) {
      Token_node tok = ret_token(src,extr,0);
      push_Token_node(&(src->m_res),&tok);
    } else {
      consume_char(src);
    }
  }
  printf("__________\n");
  
}
