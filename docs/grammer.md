# Vartslang's grammer

<program> ::= (<compound_stm>)*

<compound_stm> ::= <assign_stm> | <if_stm> | <if_else_statment | <lp_stm> | <block> 

<expr> ::= <literal>| <unary> | <binary> | <grouping> | <expr> "*" <factor> | <expr> "+" <factor> | <expr> "-" <factor>

<literal> ::= <NUMBER> | <STRING> | "true" | "false" | "NULL";

<grouping> ::= "(" <expr> ")"

<unary> ::= ( "-" | "!") <expr>;

<binary> ::= <expr> <oprator> <expr>

<oprator> ::= 

<term> ::= <term> "*" <factor> | <term> "+" <factor> | <term> "-" <factor>

<factor> ::= <digit> | ( <expr> )
