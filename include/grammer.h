#ifndef GRAMMER_H
#define GRAMMER_H

typedef enum {
  // Keywords
  IMP=100,    // <+$+>
  FUN,        // <-@->
  LOP,        // <-?->
  FEL,        // <-:-> 
  LST,        // <-[]->
  STC,        // <-<+>->
  ENM,        // <-<|>->
  CLS,        // <-<:>->
  ARG,        // @  
  CAL,        // <|
  IF,         // ?
  RET,        // ^^^
  LIT,        // []
  STA,        // <+>
  ENA,        // <|>
  ITA,        // <:>
  I32,
  I64,
  F32,
  F64,
  U8,
  B1,
    
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
  GT = 240,  // >
  LT,        // <
  GTE,       // >=
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
  ID = 500,

  // speical 
  EOF_
} TokenName;

typedef enum {
  KEYWORD= 1000,
  TYPE,
  OPRATOR,
  OP_ASSIGN,
  OP_ARTHIMATIC,
  OP_RELATIONAL,
  OP_LOGICAL,
  OP_BITWISE,
  OP_MEMBERSHIP,
  OP_MEMBER_ACCESS,
  OP_UNARY,
  OP_TYPE_CAST,
  PUNCTATION,
  LITERAL,
  IDENTIFER,
  SPEICAL
} TokenType;



#define GEN_FUN(name, start_, end_)       \
  int name(TokenType tok)                             \
  {                                                   \
    return tok >= (int)(start_) && (tok < (int)(end_));         \
  } 

typedef struct {
  Type type;
  ID id;
  expression expr;
} Assign_Var;

typedef struct {
  Type *type;
  ID id;
  expression expr;
} Assign_Arr;

typedef struct Assign_Func {
  Type type;
  ID id;
  union {
    Block b; 
    Assign_Func *func_ptr;
  } code;
} Assign_Func;

typedef struct {
  ID id; 
  Assign_Stm *assign_stm;
} Assign_Struct;

typedef struct {
  
} Assign_Enum;

typedef struct {
  
} Assign_Class;

typedef struct {
  Assign_Var Var;
  Assign_Arr Arr;
  Assign_Func Func;
  Assign_Struct Struct;
  Assign_Enum Enum;
  Assign_Class Class;
} Assign_Stm;

typedef struct If_Stm {
  expression *expr;
  Block b;
  struct If_Stm *next;
} If_Stm;

typedef struct  {
  Assign_Stm *assign_stm;
  expression condition;   
  expression *;
  Block b;
} Lp_Stm;

typedef struct {
  Assign_Stm *assign_stm;
  expression condition;   
  expression *;
  Block b;
} Do_Lp_Stm;

typedef struct {
   
} For_Each_Loop;

typedef struct {

} Func_Call_Stm;

typedef union {
  Assign_Stm assign_stm;
  If_Stm if_stm;
  Lp_Stm lp_stm;
  Do_Lp_Stm do_lp_stm;
  For_Each_Loop for_each_loop;
  Func_Call_Stm func_call_stm;
} Compound_Stm;

typedef struct  {
  Compound_Stm *statements;
} Program;

#endif
