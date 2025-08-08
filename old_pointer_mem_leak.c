#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *str = (char *)malloc(20 * sizeof(char));

    if (str == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    strcpy(str, "First allocation");
    printf("String: %s\n", str);

    
    str = (char *)malloc(30 * sizeof(char));  // Leak previous 20 bytes and again we are assigning a new chunk of memory of 30 bytes

    if (str == NULL)
    {
        printf("Second allocation failed");
        return 1;
    }

    strcpy(str, "Second allocation");
    printf("String: %s\n", str);

    // Free only the second allocation
    free(str);

    return 0;
}
