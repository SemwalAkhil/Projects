#include <stdio.h>
#include <string.h>

void sortString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    sortString(str);
    printf("Sorted string: %s", str);
    return 0;
}
