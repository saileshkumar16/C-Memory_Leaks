#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(5 * sizeof(int));    // 20 bytes
    if (p == NULL) return -1;

    printf("Initial address: %p\n", (void *)p);

    int *tmp = realloc(p, 10 * sizeof(int));  // try to grow to 40 bytes
    if (tmp == NULL) {
        printf("Realloc failed! Old pointer still valid: %p\n", (void *)p);
        free(p);  // old pointer is still valid
        return -1;
    }

    printf("After realloc:   %p\n", (void *)tmp);

    // Check if same address or new one
    if (tmp == p)
        printf("Realloc expanded in place (same address)\n");
    else
        printf("Realloc moved memory to a new location\n");

    free(tmp);  // free final memory
    return 0;
}
