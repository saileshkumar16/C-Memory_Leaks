#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ❌ FAULTY VERSION — memory leak
void sendData_Faulty(const char *msg) {
    char *txBuf = malloc(strlen(msg) + 1);  // allocates memory every call
    strcpy(txBuf, msg);                     // copies string into heap buffer

    printf("Sending (faulty): %s\n", txBuf);

    // ❌ Forgot to free(txBuf)
    // Memory keeps accumulating every time this function is called
}

// ✅ FIXED VERSION — proper memory management
void sendData_Fixed(const char *msg) {
    char *txBuf = malloc(strlen(msg) + 1);
    if (txBuf == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(txBuf, msg);
    printf("Sending (fixed): %s\n", txBuf);

    free(txBuf);  // ✅ releases allocated memory before returning
}

int main() {
    while (1) {
        sendData_Faulty("Hello world");  // memory leak version
        sendData_Fixed("Hello world");   // safe version
        break;  // remove break for testing continuous calls
    }
    return 0;
}
