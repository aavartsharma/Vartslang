# Vartslang's grammer

<program> ::= (<compound_stm>)*

<compound_stm> ::= <assign_stm> | <if_stm> | <lp_stm> | <do_lp_stm> | <for_each_loop> | <function_call_stm>  

<assign_stm> ::= <assign/variable> | <assign/array> | <assign/function> | <assign/struct> | <assign/enum> | <assign/class>

<if_stm> ::= 
    "?" "{" <expr> "}" <arrow> <block> 
    ( <arrow> "?" "{" <expr> "}" <arrow> <block> )* 
    ( (<arrow> <block>) | E )

<lp_stm> ::= 
    "<-?->" "{" ( <assign_stm> ("," <assign_stm>)* ) | E ";" 
    <expr> | E ";" 
     (<expr> | ( <expr> ",")) | E "}" 
    <arrow> <block>

<do_lp_stm> ::= <block> <arrow> "<-?->" "{" 
    E | ( <assign_stm> ("," <assign_stm>)* ) ";" 
    <expr> | E ";" 
    E | (<expr> | <expr> ( <expr> ",")* ) "}"

<for_each_loop> ::= "<-:->" "{" <type> <identifer> "<-:" <identifer> "}" <arrow> <block>

<function_call_stm> ::= <function_call> ";"

<block> ::= "{" (<compound_stm>)* "}"

<assign/variable> ::= <type> <identifer> (<op/assign> <expr> | E) ";"

<assign/array> ::= "<-[]->" "{" <type>  ( "," <type> )* "}" (<op/assign> ) ";"

<assign/function> ::= "<-@->" "{" <type> "}" <identifer> <op/assign> <block> ";"

<assign/struct> ::= "<-<+>->" "{" "}" <identifer> <op/assign> "<+>" "{" "}" <op/assign> "{" ( <assign_stm>* ) "}" ";"

<assign/enum> ::= "<-<|>->" "{" "}" <identifer> <arrow> "<|>" "{" "}" <op/assign> "{" ((<identifer> ((<op/assign>) | E)* "}" ";"

<assign/class> ::= "<-<:>->" "{" "}" <identifer> <arrow> "<:>" "{" ( <identifer> ("," <identifer> )* ) | E "}" <op/assign> <block> ";"

<type> ::= "i32" | "i64" | "f32" | "f64" | "u8"

<expr> ::= <primary_expr> | <unary_expr> | <binary_expr> | <grouping>

<prefix> ::= <literal> | <unary> | <identifer> | <grouping>

<grouping> ::= "(" <expr> ")"

<unary_expr> ::= <op/prefix> ( <primary_expr> | "(" <unary_expr> ")" ) | 
                ( <primary_expr> | "(" <unary_expr> ")" ) <op/suffix> |
                <op/other> <grouping>

<binary_expr> ::= <expr> <oprator> <expr>

<oprator> ::= <bin_op> | <prefix_op> | <postfix_op>

<bin_op> ::= <op/assign> | <op/arthimatic> | <op/logical> | <op/relation> | <op/membership> | <op/bitwise> 

<unary_op> ::= <prefix_op> | <postfix_op>

<prefix_op> ::= <prefix_op/> | "++" | "--"

<postfix_op> ::= "++" | "--" 

<prefix_op/> ::= "+" | "-" | "!" | "~"

<op/assign> ::= "<-"

<op/arthimatic> ::= "+" | "-" | "*" | "/" | "%" 

<op/logical> ::= "||" | "&&" | "!"

<op/relation> ::= "==" | "!=" | ">=" | "<=" | ">" | "<"

<op/membership> ::= "<-:"

<op/bitwise> ::= "~" | "&" | "^~^" | "|"

<function_call> ::= <identifer> "<|" "{" (<expr> ("," <expr>)* ("," <identifer> <op/assign> <expr>)* ) | E  "}" ";"

<primary_expr> ::= <literal> | <identifer> | <function_call>

<literal> ::= <numral> | <STRING> | "true" | "false" | "NULL"

<identifer> ::= ( "A" | "B" | ... | "Z" | "a" | "b" | ... | "z" | "_") 
                ( "A" | "B" | ... | "Z" | "a" | "b" | ... | "z" | "_" | <digit>)*

<numral> ::= <digit> (<digit>)*

<digit> ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"

<STRING> ::= """ (ascii_charaters)* """

<arrow> ::= "->"


## definitions

term = an peice of expr separted by operator
factor = literal that is
