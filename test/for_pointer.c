#include<stdio.h>
#include<stdlib.h>

typedef struct list_1 {
  char c;
  struct list_1 *pre;
} list;
int main(void) {
  list *ptr = NULL;
  for (int i = 0; i<10; i++){
    printf("%d - > %c\n", i+65, i+65);
    list *x = (list *) malloc(sizeof(list));
    
    x->c = (char) (i+65);
    x->pre = ptr;
    ptr = x;
  }
  list *ptr2 = ptr;
  for (int i = 0;ptr2 != NULL ; i++) {
    if(i >15) break;
    printf("char: %c\n", ptr2->c);
    ptr2 = ptr2->pre;
  }
  return 0;
}
