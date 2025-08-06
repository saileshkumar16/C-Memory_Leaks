#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = malloc(5 * sizeof(int));  // memory allocated 20 bytes

    if (ptr == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    // Use the memory
    for (int i = 0; i < 5; i++)
    {
        ptr[i] = i * 10;
        
        printf("%d ",*(ptr+i));
    }

    // Memory leak here: forgot to free(ptr)

    return 0;
}
