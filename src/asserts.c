#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include "asserts.h"

/*
node *new(void *val){
  node *temp = (node *) malloc(sizeof(node));
  temp->val = val;
  temp->next = NULL;
  return temp;
}

node *next(node *cur){
  return cur->next;  
}

void push(node **cur, node *next_el) {
  if(*cur == NULL){
    printf("node is null");
    return;
  }
  if((*cur)->next == NULL){
    (*cur)->next = next_el; 
    return;
  }
  push(&next(*cur),next_el);
}

void show_item(Token *t,int i) {
  if(t == NULL) {
    printf("----\n");
    return;
  }
  printf("%s, %d -> %d\n",t->value, i, (int) t->type );
  show_item(t->n_token, i+1);
}*/

void printE_impl(CString func, CString file,int line, CString message, ...) {

    va_list args;

    printf("ERROR: In function '%s' In file '%s' in line %d \n",func,file, line);

    va_start(args, message);
    printf("ERROR: ");
    vprintf(message, args);
    va_end(args);
    printf("\t\n");
}

void printL_impl(CString func, CString file,int line, CString message, ...) {

    va_list args;

    va_start(args, message);
    printf("LOG:Func['%s']:FILE['%s']:LINE[%d]: ",func,file,line);
    vprintf(message, args);
    va_end(args);
    printf("\t\n");
}
