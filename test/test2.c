#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello,,World!afads";
    char dest[12];
    
    strncpy(dest, src, 15);
    printf("%c\n", dest[12]);
    dest[12] = '\0';  // manually add null terminator

    printf("%s\n", dest);
    printf("%c\n", dest[12]);
    return 0;
}
