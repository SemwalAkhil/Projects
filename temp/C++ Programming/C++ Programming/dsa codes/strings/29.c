#include <stdio.h>

void strToASCII(char *str, int ascii[], int len) {
    for (int i = 0; i < len; i++) {
        ascii[i] = str[i];
    }
}

int main() {
    char str[10];
    int ascii[10];
    printf("Enter a string (10 characters): ");
    gets(str);
    strToASCII(str, ascii, 10);

    printf("ASCII values: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", ascii[i]);
    }
    return 0;
}
