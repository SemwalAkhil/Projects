#include <stdio.h>
#include <string.h>

int longestValidParentheses(char *s) {
    int maxLength = 0, lastInvalid = -1;
    int stack[strlen(s) + 1];
    int top = -1;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stack[++top] = i; // push index
        } else {
            if (top == -1) {
                lastInvalid = i; // update last invalid
            } else {
                top--; // pop
                if (top == -1) {
                    maxLength = (i - lastInvalid > maxLength) ? i - lastInvalid : maxLength;
                } else {
                    maxLength = (i - stack[top] > maxLength) ? i - stack[top] : maxLength;
                }
            }
        }
    }
    return maxLength;
}

int main() {
    char s[100];
    printf("Enter parentheses string: ");
    scanf("%s", s);
    
    int result = longestValidParentheses(s);
    printf("Length of longest valid substring: %d\n", result);
    
    return 0;
}
