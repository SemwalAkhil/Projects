#include <stdio.h>
#include <string.h>

void printAligned(char *str, int alignment) {
    int width = 30; // screen width example
    int len = strlen(str);
    int padding = (alignment == 2) ? (width - len) / 2 : (alignment == 3 ? width - len : 0);
    for (int i = 0; i < padding; i++) printf(" ");
    printf("%s\n", str);
}

int main() {
    char str[100];
    int alignment;
    printf("Enter text: ");
    gets(str);
    printf("Enter alignment (1=Left, 2=Center, 3=Right): ");
    scanf("%d", &alignment);
    printAligned(str, alignment);
    return 0;
}
