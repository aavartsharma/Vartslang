#ifndef GRAMMER_H
#define GRAMMER_H
/*
typedef enum {
  // Keywords
  FUN=100,  // <-@->
  LOP,       // <-?->
  FEL,       // <-:-> 
  LST,       // <-[]->
  STC,       // <-<+>->
  ENM,       // <-<|>->
  CLS,       // <-<:>->
  ARG,       // @  
  CAL,       // <|
  IF,        // ?
  RET,       // ^^^
  LIT,       // []
  STA,       // <+>
  ENA,       // <|>
  ITA,       // <:>
  I32,
  I64,
  F32,
  F64,
  U8,
    
  // operator/assign
  ASG=200,   // <-
  // operator/arthimatic
  MNS = 220,
  PLS,
  MUL,
  DIV,
  INC,       // ++
  DEC,       // -- 
  // operator/relational
  MT = 240,  // >
  LT,        // <
  MTE,       // >=
  LTE,       // <=
  EQU,       // ==
  NEQ,       // !=
  // operator/logical
  NOT = 260, // !
  AND,       // /\ /
  OR,        // \/
  // operator/bitwise
  BNT = 280,       // ~
  BND,       // &
  BOR,       // | 
  XOR,       // ^ 
  SHL,       // <<
  SHR,       // >>
  // operator/membership
  IN = 290,  // <-:
  // operator/unary
  PMS, 
  // operator/member_access
  DOT,       // .
  // operator/type_cast
  TCO,       // (int), (float), (bool)

  //puctation
  ARW=300,   // ->
  SMI,       // ;
  OCR, CCR,  // { }
  CMA,       // ,
  NL,        // \n

  // liter 
  INT = 400,
  FLT,
  CHR,
  STR,
  TRU, 
  FLS,
  NULL_,

  COLLECTION,
  
  //identifer
  ID = 500 
} TokenType;
*/

typedef enum {
  FUN,       // <-@->
  LOP,       // <-?->
  FEL,       // <-:-> 
  LST,       // <-[]->
  STC,       // <-<+>->
  ENM,       // <-<|>->
  CLS,       // <-<:>->
  ARG,       // @  
  CAL,       // <|
  IF,        // ?
  RET,       // ^
  LIT,       // []
  STA,       // <+>
  ENA,       // <|>
  ITA,       // <:>
  I32,
  I64,
  F32,
  F64,
  U8
} keywords;

typedef enum {
  ASG=200   // <-
} op_assign;

typdef enum {
  MNS = 220,
  PLS,
  MUL,
  DIV,
  INC,       // ++
  DEC       // -- 
} op_arthimatic;

typedef enum {
  MT = 240,  // >
  LT,        // <
  MTE,       // >=
  LTE,       // <=
  EQU,       // ==
  NEQ       // !=
} op_relational;

typedef enum {
  NOT = 260, // !
  AND,       // /\ /
  OR        // \/
} op_logical;

typedef enum {
  BNT = 280,       // ~
  BND,       // &
  BOR,       // | 
  XOR,       // ^ 
  SHL,       // <<
  SHR       // >>
} op_bitwise;

typedef enum {
  IN = 290,  // <-:
} op_membership;

typedef enum {
  DOT       // .
} op_member_access;

typedef enum {
  PMS
} op_unary;

typedef enum {
  TCO
} op_type_cast;

typedef enum {
  ARW=300,   // ->
  SMI,       // ;
  OCR, CCR,  // { }
  CMA,       // ,
  NL        // \n
} puctation;

typedef enum {
  INT = 400,
  FLT,
  CHR,
  STR,
  TRU, 
  FLS,
  NULL_
} literal;

typedef enum {
  ID
} identifer; 



// grammer AST node Definitions
//
//
//
//
//

typedef struct {
  literal lit;  
  String s1;
} Literal;

typedef struct {
  identifer id;  
  Expr *expr_g;
  int count;
  
  identifer *id;
  Expr expr_g; 
  int count1;
} function_call;

typedef struct {
  Literal lit;  
  identifer id;
} primary_expr;

typedef struct {
  Expr oprand1;
  oprator op;
  Expr oprand2;
} binary_expr;

typedef struct {
  op_unary
}

typedef union {
  struct primary_expr; 
  struct unary_expr;
  struct binary_expr;
  struct grouping;
} Expr;

typedef struct {
  
} ;

#endif
