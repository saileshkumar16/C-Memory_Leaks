#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(5 * sizeof(int));

    if (!p) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Memory allocated.\n");

    // Free memory without using free()
    p = realloc(p, 0);  // Acts like free()

    if (p == NULL)
        printf("Memory freed using realloc!\n");

    return 0;
}
