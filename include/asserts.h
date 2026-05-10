#ifndef ASSERTS_H
#include<stdio.h>
#define ASSERTS_H
typedef enum {
  // Keywords
  FUNC=0,  // <-@->
  LOP, // <-?->
  FEL, // <-:-> 
  LST,  // <-[]->
  ARG, // @  
  CAL, // <|
  IF, // ?
  RET, // ^
  LIT, //[]
  I32,
  I64,
  F32,
  F64,
  U8,
    
  // operator/assign
  ASSIGN, // <-
  // operator/arthimatic
  PLUS,
  MINUS,
  MUL,
  DIV,
  INC, // ++
  DEC, // -- 
  // operator/logical
  MT, // >
  LT, // <
  MTE, // >=
  LTE,  // <=
  NOT,      // !
  AND, //   /\   /
  OR,   // \/
  EQU,  // ==
  NEQU, // !=


  //puctation
  FLW_ARR, // ->
  SEMI, //;
  OCR, CCR, // { }
  COMMA, //,
  DOT,   // .
  NL, // \n

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

typedef struct token_raw {
  TokenType type;
  char *value;
  struct token_raw *n_token;
} Token;

// stack of char
typedef struct Node {
  void *val; 
  struct Node *next;
} node;

typedef struct {
  node *m_buf; 
  size_t m_index;
  src_code src;
  node *m_res; // linked list of tokens
} lexer;

node *new(void *val);

node *next(node *cur);

void push(node **cur, node *next_el);

void show_item(Token *t, int i);

#endif
