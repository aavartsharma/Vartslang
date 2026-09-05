#ifndef GRAMMER_H
#define GRAMMER_H

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
  IDENTIFER
} TokenType;



#define GEN_FUN(name, start_, end_)       \
    int name(TokenType tok)                             \
    {                                                   \
        return tok >= (int)(start_) && (tok < (int)(end_));         \
    } 

GEN_FUN(is_keyword,(int)FUN,(int)ASG)
GEN_FUN(is_type, (int)I32,(int)ASG)
GEN_FUN(is_operator_infix,(int) ASG,(int) IN)
GEN_FUN(is_operator_assign,(int) ASG,(int) MNS) 
GEN_FUN(is_operator_arthimatic,(int) MNS,(int) GT)
GEN_FUN(is_operator_relational, (int) GT, (int) NEQ)
GEN_FUN(is_operator_logical, (int) NOT, (int) BNT)
GEN_FUN(is_operator_bitwise, (int) BNT, (int) SHR)
GEN_FUN(is_operator_membership, (int) IN, (int) PMS)
GEN_FUN(is_operator_unary, (int) PMS, (int) DOT)
GEN_FUN(is_operator_member_access, (int) DOT, (int) TCO)
GEN_FUN(is_operator_type_cast, (int) TCO, (int) ARW)
GEN_FUN(is_puctation, (int) ARW,(int) INT)
GEN_FUN(is_liter,(int) INT,(int) COLLECTION)
GEN_FUN(is_identifer,(int) ID,(int) EOF_)

/*
typedef enum {
  KEY_FUN = FUN,       // <-@->
  KEY_LOP,       // <-?->
  KEY_FEL,       // <-:-> 
  KEY_LST,       // <-[]->
  KEY_STC,       // <-<+>->
  KEY_ENM,       // <-<|>->
  KEY_CLS,       // <-<:>->
  KEY_ARG,       // @  
  KEY_CAL,       // <|
  KEY_IF,        // ?
  KEY_RET,       // ^
  KEY_LIT,       // []
  KEY_STA,       // <+>
  KEY_ENA,       // <|>
  KEY_ITA,       // <:>
  KEY_I32,
  KEY_I64,
  KEY_F32,
  KEY_F64,
  KEY_U8
} keywords;

typedef enum {
  type_I32 = I32,
  type_I64 = I64,
  type_F32 = F32,
  type_F64 = F64,
  type_U8 = U8,
} type;

typedef enum {
  op_assign_ASG=ASG;   // <-
} op_assign;

typedef enum {
  op_arthimatic_MNS = MNS,
  op_arthimatic_PLS,
  op_arthimatic_MUL,
  op_arthimatic_DIV,
  op_arthimatic_INC,       // ++
  op_arthimatic_DEC       // -- 
} op_arthimatic;

typedef enum {
  op_relational_MT = MT,  // >
  op_relational_LT,        // <
  op_relational_MTE,       // >=
  op_relational_LTE,       // <=
  op_relational_EQU,       // ==
  op_relational_NEQ       // !=
} op_relational;

typedef enum {
  op_logical_NOT = NOT, // !
  op_logical_AND,       // /\ /
  op_logical_OR        // \/
} op_logical;

typedef enum {
  op_bitwise_BNT = BNT,       // ~
  op_bitwise_BND,       // &
  op_bitwise_BOR,       // | 
  op_bitwise_XOR,       // ^ 
  op_bitwise_SHL,       // <<
  op_bitwise_SHR       // >>
} op_bitwise;

typedef enum {
  op_membership_IN = IN,  // <-:
} op_membership;

typedef enum {
  op_member_access_DOT=DOT       // .
} op_member_access;

typedef enum {
  op_unary_PMS = PMS
} op_unary;

typedef enum {
  op_type_cast_TCO = TCD
} op_type_cast;

typedef enum {
  puctation_ARW=ARW,   // ->
  puctation_SMI,       // ;
  puctation_OCR, puctation_CCR,  // { }
  puctation_CMA,       // ,
  puctation_NL        // \n
} puctation;

typedef enum {
  literal_INT = INT,
  literal_FLT,
  literal_CHR,
  literal_STR,
  literal_TRU, 
  literal_FLS,
  literal_NULL_
} literal;

typedef enum {
  identifer_ID = ID
} identifer; 

*/

// grammer AST node Definitions

// typedef struct {
//    lit;  
//   String s1;
// } Literal;
//
// typedef struct {
//   Token id;  
//   Expr *expr_g;
//   int count;
//
//   Token *id;
//   Expr expr_g; 
//   int count1;
// } function_call;
//
// typedef struct {
//   Token lit;  
//   identifer id;
// } primary_expr;
//
// typedef struct {
//   Expr oprand1;
//   oprator op;
//   Expr oprand2;
// } binary_expr;
//
// typedef union unary_expr {
//   struct {
//     op_unary op; 
//     union {
//       primary_expr 
//       unary_expr 
//     } s;   
//   };
//   struct {
//     union {
//       unary_expr
//       primary_expr
//     } n; 
//     op_unary op;
//   };
//   struct {
//     op_unary 
//     grouping
//   };
// } ;
//
// typedef union grouping {
//   Expr
// } ;
//
// typedef union {
//   struct primary_expr; 
//   struct unary_expr;
//   struct binary_expr;
//   struct grouping;
// } Expr;
//

// typedef struct {
//   type
// } assign_variable;
//
typedef struct  {
   
} Program;

#endif
