#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trimSpaces(char *str) {
    int start = 0, end = strlen(str) - 1;
    while (isspace(str[start])) start++;
    while (isspace(str[end])) end--;
    for (int i = start; i <= end; i++) str[i - start] = str[i];
    str[end - start + 1] = '\0';
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    trimSpaces(str);
    printf("Trimmed string: '%s'", str);
    return 0;
}
