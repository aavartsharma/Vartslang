#ifndef ASSERTS_H
#include<stdio.h>
#define ASSERTS_H
typedef enum {
  ident,
  exit_,
  func,  // <-@->
  lp, // <-?->
  i32,
  semi, //;
  open_cur, //{
  close_cur,
  assm_eq, // <-
  if_, // ?
  flow_arrow, // ->
  args_, // @ 
  ret, // ^
  plus,
  minus,
  mul,
  div_,
  and, // /\
  or   // \/
} TokenType;

typedef struct {
  char *src; 
  size_t len;
} src_code;

typedef struct {
  TokenType type;
  char* value;
  //struct Token *n_token;
} Token;

typedef struct {
  char *m_src;
  char m_buf[10];
  size_t m_index;
  size_t length;//
  Token *m_res;
} lexer;
#endif
