// 14. Length of the longest valid substring
/*
Explanation -

    Given a string consisting of opening and closing parenthesis, find the length of the longest valid parenthesis substring.
    Examples:
    Input : ((()
    Output : 2
    Explanation : () Input: )()())
    Output : 4 Explanation: ()()
    Input: ()(()))))
    Output: 6
    Explanation: ()(())
*/
#include <stdio.h>
#include <string.h>

// STACK BASED APPROACH
int longestValidParentheses(char *s)
{
    int maxLength = 0;
    int stack[10000];  // Array to simulate stack (assuming string length won't exceed 10000)
    int top = -1;      // Stack pointer
    stack[++top] = -1; // Initialize stack with base index

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(')
        {
            stack[++top] = i; // Push the index of '(' onto the stack
        }
        else
        {          // s[i] == ')'
            top--; // Pop the top of the stack

            if (top == -1)
            {
                stack[++top] = i; // Push current index as a base
            }
            else
            {
                // Calculate the length of the valid substring
                maxLength = (maxLength > (i - stack[top])) ? maxLength : (i - stack[top]);
            }
        }
    }
    return maxLength;
}

int main()
{
    char str[10000]; // Array to store the input string
    printf("Enter the string of parentheses: ");
    scanf("%s", str);

    int result = longestValidParentheses(str);
    printf("Length of the longest valid substring: %d\n", result);

    return 0;
}
