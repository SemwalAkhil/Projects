#include <stdio.h>
#include <string.h>

int findSecondWordStart(char *str) {
    int i = 0;
    while (str[i] != ' ' && str[i] != '\0') i++;
    while (str[i] == ' ') i++;
    return (str[i] != '\0') ? i : -1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    int index = findSecondWordStart(str);
    printf("Start index of the second word: %d", index);
    return 0;
}
