#include<stdio.h>

struct testing {
  char *x;
  int y;
};

struct testing *name(struct testing *st) {
  return st;
}
int main(void){
  struct testing sample={
    .x = 34,
    .y =35
  };
  struct testing *sample2 = name(&sample);
  printf("%d -> %d | %d -> %d\n", sample.x , sample.y, sample2->x, sample2->y);
  printf("%d\n", &sample  ==sample2);
  return 0;
} 
