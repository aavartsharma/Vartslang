#include<stdio.h>
#include<stdlib.h>
#include "asserts.h"

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
}
