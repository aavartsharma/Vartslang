#ifndef PARSER_H
#define PARSER_H
#include "asserts.h"
typedef struct expression 
{
  void(*display)(struct expression*, int indent);
  int(*evaluate)(struct expression*);
} expression;

// Variable
typedef struct 
{
  expression base;
  Token var;
} variable_literal;

typedef struct 
{
  expression base;
  Token number;
} number_literal;

typedef struct 
{
  expression base;
  expression* body;
} sub_expression;

typedef struct 
{
  expression base;
  expression* lhs;
  Token operator;
  expression* rhs;
} infix_expression;

typedef struct {
  expression base;
  Token operator;
  expression* body;
} prefix_expression;
//  <body:expression> <opeartor>
typedef struct 
{
  expression base;
  Token operator;
  expression* body;
} postfix_expression;

typedef struct 
{
  int lp;
  int rp;
} binding_power;

Token peek_token(Parser *,int);
int peekFor_token(Parser *,int);
void consume_token(Parser *);
int TryConsume_token(Parser *, TokenName);
expression* create_expression(Parser *parser, int right_bp);

#endif // !PARSER_H
