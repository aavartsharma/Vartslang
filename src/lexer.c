#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "asserts.h"

char peek(lexer *src, int offset) {
  // IMPORTANT - this function will have no safe grard
  // peek func returns the char m_index + offset 
  // without advencing the cursor
  if((src->m_index +offset) >= src->src.len) return '\0';
  return *(src->src.src + src->m_index + offset);
}

char consume(lexer *src) {
  // return the charater at m_index and increment
  // the index by one 
  if(src-> m_index >= src->src.len) return '\0'; 
  src->m_index++;
  return *(src->src.src +src->m_index -1); 
}

Token to_token(const char *token_src) {
  Token t;
    // Keyword
  if(strcmp(token_src, "<-@->") == 0) {
    t.type = FUNC;
    t.value = '\0';
  }
  else if(strcmp(token_src,"<-?->") == 0) {
    t.type = LOP;
    t.value = '\0';
  }

  else if (strcmp(token_src, "@") == 0) {
    t.type = ARG;
    t.value = '\0';
  }
  else if (strcmp(token_src, "?") == 0) {
    t.type = IF;
    t.value = '\0';
  }
  else if (strcmp(token_src, "^") == 0) {
    t.type = RET;
    t.value = '\0';
  }
  else if (strcmp(token_src, "i32") == 0) {
    t.type = I32;
    t.value = '\0';
  }
  else if (strcmp(token_src, "i64") == 0) {
    t.type = I64;
    t.value = '\0';
  }
  else if (strcmp(token_src, "f32") == 0) {
    t.type = F32;
    t.value = '\0';
  }
  else if (strcmp(token_src, "f64") == 0) {
    t.type = F64;
    t.value = '\0';
  }
  else if (strcmp(token_src, "u8") == 0) {
    t.type = U8;
    t.value = '\0';
  }

  // operator / assign
  else if (strcmp(token_src, "<-") == 0) {
    t.type = ASSIGN;
    t.value = '\0';
  }
  else if (strcmp(token_src, "+") == 0) {
    t.type = PLUS;
    t.value = '\0';
  }
  else if (strcmp(token_src, "-") == 0) {
    t.type = MINUS;
    t.value = '\0';
  }
  else if (strcmp(token_src, "*") == 0) {
    t.type = MUL;
    t.value = '\0';
  }
  else if (strcmp(token_src, "/") == 0) {
    t.type = DIV;
    t.value = '\0';
  }
  else if (strcmp(token_src, "&&") == 0) {
    t.type = AND;
    t.value = '\0';
  }
  else if (strcmp(token_src, "||") == 0) {
    t.type = OR;
    t.value = '\0';
  }
  else if (strcmp(token_src, "->") == 0) {
    t.type = FLW_ARR;
    t.value = '\0';
  }
  else if (strcmp(token_src, ";") == 0) {
    t.type = SEMI;
    t.value = '\0';
  }
  else if (strcmp(token_src, "{") == 0) {
    t.type = OCR;
    t.value = '\0';
  }
  else if (strcmp(token_src, "}") == 0) {
    t.type = CCR;
    t.value = '\0';
  }
  else {
    printf("lexer.c to_token function\n");
  }
  return t;
}

void tokenize(lexer *src) { // make this return list of tokens somehow
  for(int i=0; src->m_index < src->src.len; i++) {
    printf("src->Mindex = %ld\n",src->m_index);
    if(isalpha(peek(src,0))) {
      char a = consume(src);
      link_chr *ptr1 = (link_chr *) malloc(sizeof(link_chr));
      ptr1->c = a;
      ptr1->aft_chr = NULL;
      link_chr *ptr2= ptr1;
      for(int i= 1;isalpha(peek(src,0)) || isdigit(peek(src,0)) || peek(src,0) == '_'; i++) {
         
        if(i >17) break;
        ptr2->aft_chr = (link_chr *) malloc(sizeof(link_chr));
        ptr2->aft_chr->c = consume(src);
        printf("peeky: %c\n", peek(src,0));
        ptr2->aft_chr->aft_chr= NULL;
        ptr2 = ptr2->aft_chr;
      }
      printf("isspace %c\n", ptr2->c);

      link_chr *ptr3 = ptr1;
      for(int j =0;ptr3!=NULL; j++){
        printf("%c", ptr3->c);
        ptr3= ptr3->aft_chr; 
      }
      printf("\n");
      //src->m_buf[] = '\0';
      //to_token(src->m_buf);
    }
    else if (isdigit(peek(src,0))) {
      char a = consume(src);
      link_chr *ptr1 = (link_chr *) malloc(sizeof(link_chr));
      ptr1->c = a;
      ptr1->aft_chr = NULL;
      link_chr *ptr2= ptr1;
      for(int i= 1; isdigit(peek(src,0)) || peek(src,0) == '_'; i++) {
         
        if(i >17) break;
        ptr2->aft_chr = (link_chr *) malloc(sizeof(link_chr));
        ptr2->aft_chr->c = consume(src);
        printf("peeky: %c\n", peek(src,0));
        ptr2->aft_chr->aft_chr= NULL;
        ptr2 = ptr2->aft_chr;
      }
      link_chr *ptr3 = ptr1;
      for(int j =0;ptr3!=NULL; j++){
        printf("%c", ptr3->c);
        ptr3= ptr3->aft_chr; 
      }
      printf("\n");
    }
    else {
      src->m_index++;
    }
    
  }
}


