typedef enum {
  ident,
  exit,
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
  div,
  
  
} TokenType;

typedef struct {
  char *m_src;
  size_t m_index;
  int length;
} Tokenizer;

typedef struct {
  TokenType type;
  char* value;
} Token;


