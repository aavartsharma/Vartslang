#include <stdio.h>
#include <unistd.h>

int main(void) {
  int lengh = 5;
  char loading[] = {'|', '/', '-', '\\'};
  for (int j = 0; j<=lengh; j++) {
    printf("\r[");
    for(int i = 0; i <= lengh; i++) {
      if(i>j) {
        printf(" ");
      } else {
        printf("#");
      }
    }
    printf("]  %c", loading[j%4]);
    sleep(1);
    fflush(stdout);
  }
  printf("\r done\n");
  return 0;
}
