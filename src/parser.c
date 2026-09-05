#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "parser.h"
#include "grammer.h"
#include "asserts.h"

/*void peak_token(lexer *src, int offset)
  {

  }*/
/* 
   Token_node consume_token() 
   {
/*return m_token++;
}*/
/*void ret_tree(parser *tokens) {
  Token_node *j = NULL;
  Expr *k = parser->m_res;
  for(Token_node *i = tokens->lexer_list->m_res; i != NULL; i = next_Token_node(i)) {
  if()
  }
  }*/
/*void try_consume(parser *tokens, tokentype expected_token)
{
  return tokens->token == expected_token;   
}*/



/*typedef enum  token_id;

// A token - returned by the lexer
typedef struct {
    char* start_ptr;
    char* end_ptr;
    token_id type_id;
} token;
*/

// char *current_pos;
expression* create_expression(Parser *parser, int right_bp);
void display(expression* a , int indent){

}
Token peek_token(Parser *parser,int offset)  // front
{
  Token_node *temp = parser->m_buf;
  for (int i = offset; i < offset; i--){
    temp = next_Token_node(temp);
  }
  return temp->val;
}

int peekFor_token(Parser *parser,int lookingFor)
{
  Token temp = parser->peek(parser,0);
  return temp.tok == (TokenName) lookingFor || temp.type == (TokenType) lookingFor;
}

void consume_token(Parser *parser)    // advance
{
  if(parser->m_buf->val.tok == EOF_) {
    printE("end of tokens");
    return;
  }
  parser->m_buf = parser->m_buf->next_el;
}

int TryConsume_token(Parser *parser, TokenName o)
{
  if(parser->peekFor(parser,o)) {
    // consume_token();
    return 1;
  }
  return 0;
}

binding_power RightAssociative(int p) 
{
  return (binding_power){p + 1, p};
}

binding_power LeftAssociative(int p) 
{
  return (binding_power){p - 1, p};
}

int prefix_bp_lookup(TokenName type) 
{
  switch(type) 
  {
    case PLS: return 300;
    case MNS: return 300;
    case NOT: return 300; 
    case BNT: return 300;
    default: return 0;
  }
}

binding_power bp_lookup(TokenName type) 
{
  // Binding Power Table, Associativity can also be handled here by returning a second binding power
  // Larger for Left binding, lower for Right binding. E.g. (10, 11) - Left binding, (10, 9) - Right binding
  switch(type) 
  {
    // --- Infix ---
    case PLS:   return LeftAssociative(100);
    case MNS:   return LeftAssociative(100);
    case MUL:   return LeftAssociative(200);
    case DIV:   return LeftAssociative(200);

    case GT:    return LeftAssociative(50);
    case GTE:   return LeftAssociative(50);
    case LT:    return LeftAssociative(50);
    case LTE:   return LeftAssociative(50);
    case EQU:   return LeftAssociative(50);
    case NEQ:   return LeftAssociative(50);

                              // --- Postfix --- (Always Right Associative)
    case INC:   return RightAssociative(400);
    case DEC:   return RightAssociative(400);
    default:    return (binding_power){0,0};
  }
}

// evaluatint funcation with name of 
int variable_evaluate(expression* s) 
{
  variable_literal* self = (variable_literal*)s;
  // add logic 
  return 20;
}

int number_evaluate(expression* s) 
{
  number_literal* self = (number_literal*)s;
  // add logic 
  return 23;
}

int prefix_expression_evaluate(expression* s) 
{
  prefix_expression* self = (prefix_expression*)s;

  int body_res = self->body->evaluate(self->body);

  switch(self->operator.tok) {
    case PLS: return 0 + body_res;
    case MNS: return 0 - body_res;
    case NOT: return !body_res; 
    case BNT: return ~body_res; 
    default: printE("prefix_oprator is not recongized");
  }
} 

int sub_expression_evaluate(expression* s) 
{
  sub_expression* self = (sub_expression*)s;
  return self->body->evaluate(self->body);
}

int postfix_expression_evaluate(expression* s) 
{
  postfix_expression* self = (postfix_expression*)s;

  int body_res = self->body->evaluate(self->body);

  switch(self->operator.tok) 
  {
    case INC:   return body_res;  // increament body_res
    case DEC:   return body_res;
    default:    printE("Invaild posfix oprator");
  }
}
int infix_expression_evaluate(expression* s) 
{
  infix_expression* self = (infix_expression*)s;

  int lhs_res = self->lhs->evaluate(self->lhs);
  int rhs_res = self->rhs->evaluate(self->rhs);

  switch(self->operator.tok) 
  {
    case PLS:   return lhs_res + rhs_res;
    case MNS:   return lhs_res - rhs_res;
    case MUL:   return lhs_res * rhs_res;
    case DIV:   return lhs_res / rhs_res;

    case GT:    return (lhs_res > rhs_res);
    case LT:    return (lhs_res < rhs_res);
    case GTE:   return (lhs_res >= rhs_res);
    case LTE:   return (lhs_res <= rhs_res);
    case EQU:   return (lhs_res == rhs_res);
    case NEQ:   return (lhs_res != rhs_res);
    
    case AND:   return (lhs_res && rhs_res);
    case OR:    return (lhs_res || rhs_res);

    case BND:   return (lhs_res & rhs_res);
    case BOR:   return (lhs_res | rhs_res);
    case XOR:   return (lhs_res ^ rhs_res);
    case SHL:   return (lhs_res << rhs_res);
    case SHR:   return (lhs_res >> rhs_res);
    default:    printE("Operator doesn't recongized");
  }

}
/* 
 * AST creation fuctions
 */

expression* create_number_literal(Parser *parser) 
{
  number_literal* result = malloc(sizeof(number_literal));
  result->base.display = &number_display;
  result->base.evaluate = &number_evaluate;

  result->number = parser->consume(parser);
  //advance();

  return (expression*)result;
}

expression* create_variable_literal(Parser *parser) 
{
  variable_literal* result = malloc(sizeof(variable_literal));
  result->base.display = &variable_display;
  result->base.evaluate = &variable_evaluate;

  result->var = parser->consume(parser);
  // advance();

  return (expression*)result;
}

expression* create_sub_expression(Parser *parser) 
{
  sub_expression* result = malloc(sizeof(sub_expression));
  result->base.display = &sub_expression_display;
  result->base.evaluate = &sub_expression_evaluate;
  if (!parser->peekFor(parser,OCR)) {
    // Should do error handling!
    return (expression*)result;
  }
  parser->consume(parser);
  // advance();
  result->body = create_expression(parser,0);
  if (!parser->peekFor(parser,OCR)) {
    // Should do error handling!
    return (expression*)result;
  }
  parser->consume(parser);
//  advance();

  return (expression*)result;
}

expression* create_infix_expression(Parser *parser, expression* _lhs, int min_bp ) 
{
  infix_expression* result = malloc(sizeof(infix_expression));
  result->base.display = &infix_display;
  result->base.evaluate = &infix_expression_evaluate;

  result->lhs = _lhs;
  result->operator = parser->consume(parser);
  // advance();
  result->rhs = create_expression(parser, min_bp, SEM);    

  return(expression*)result;
}

expression* create_prefix_expression(Parser *parser, int min_bp ) 
{
  prefix_expression* result = malloc(sizeof(prefix_expression));
  result->base.display = &prefix_display;
  result->base.evaluate = &prefix_expression_evaluate;
  result->operator = parser->consume(parser);
  result->body = create_expression(parser,min_bp, stopAt);

  return(expression*)result;
}

expression* create_postfix_expression(Parser *parser, expression* _lhs, int min_bp ) 
{
  prefix_expression* result = malloc(sizeof(prefix_expression));
  result->base.display = &postfix_display;
  result->base.evaluate = &postfix_expression_evaluate;

  result->body = _lhs;
  // if (parser->peek(0) )
  result->operator = parser->consume(parser);

  return(expression*)result;
}

expression* create_expression(Parser *parser, int right_bp, TokenName stopAt) 
{
  expression* result = NULL;

  // Check to see if this is a prefix or a valid infix left-hand-side.
  if (parser->peekFor(parser,(int)INT)) {
    result = create_number_literal(parser);
  } else if (parser->peekFor(parser,ID)) {
    result = create_variable_literal(parser);
  } else if (parser->peekFor(parser,OCR)) {
    result = create_sub_expression(parser);

    // --- Prefix Operators ---
  } else if (parser->peekFor(parser,OP_UNARY)) {
    result = create_prefix_expression( parser, prefix_bp_lookup( parser->peek(parser,0).tok ) );
  }

  // Check the next token, if its a valid infix token. Plus the LHS we've just parsed down the AST
  // and into the infix AST node.
  while(!(parser->peekFor(parser,(int) stopAt) ) && right_bp < bp_lookup( parser->peek(parser,0).tok ).lp) {
    if(parser->peekFor(parser,INC) || parser->peekFor(parser,DEC)) {
      result = create_postfix_expression(parser, bp_lookup( parser->peek(parser,0).tok).rp);
    } 
    else {
      result = create_infix_expression(parser, result, bp_lookup( parser->peek(parser,0).tok).rp );
    } 
  }
  // Check we didn't mess up
  assert(result != NULL);
  return result;
}
//
// void prattParse(Parser *parser, TokenName stopAt) 
// {
//   expression* ast = create_expression(parser, 0, stopAt);       
// }
//
// void Parsering(Parser *parser) 
// {
//   prattParse();
// }
//


