#ifndef ASSERTS_H
#define ASSERTS_H 

typedef enum {
  ident,
  exit_,
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
  div_
} TokenType;

typedef struct {
  char *src;
  size_t length;
} source_code;

typedef struct {
  char *m_src;
  size_t m_index;
  size_t length;
} Tokenizer;

typedef struct {
  TokenType type;
  char* value;
  struct Token *n_token;
} Token;

#endif
