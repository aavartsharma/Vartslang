#ifndef ASSERTS_H
#include<stdio.h>
#define ASSERTS_H
typedef enum {
  // Keywords
  FUNC,  // <-@->
  LOP, // <-?->
  ARG, // @  
  IF, // ?
  RET, // ^
  I32,
  
  // operator/assign
  ASSIGN, // <-
  // operator/arthimatic
  PLUS,
  MINUS,
  MUL,
  DIV,
  // operator/logical
  AND, // //
  OR,   // \/

  //puctation
  FLW_ARR, // ->
  SEMI, //;
  OCR, // {
  CCR, // }

  // liter 
  INTGER,
  FLOAT,
  CHAR,

  NULL_,

  COLLECTION,
  
  //identifer
  ID 
} TokenType;

typedef struct {
  char *src; 
  size_t len;
} src_code;

typedef struct {
  TokenType type;
  char *value;
  Token *n_token;
} Token;

// stack of char
typedef struct Str_chr {
  char c; 
  Str_chr *pre_char;
};

typedef struct {
  char m_buf[32]; // make this linked list
  size_t m_index;
  src_code src;
  Token *m_res;
} lexer;
#endif
