#include<stdio.h>
int main(void) {
  FILE *filePointer = NULL;

  // create the character array (aka string) to store the data that is read
  char savedString[61];

  filePointer = fopen("test.vart", "r");

  // check there is no error opening the file
  if (filePointer == NULL)
  {
    perror("Error: ");
    return(-1);
  }

  if(fgets(savedString, 60, filePointer) != NULL) {
    // print the return value (aka string read in) to terminal
    printf("%s", savedString);
  }

  fclose(filePointer);
  filePointer = NULL;

  return 0;
}
