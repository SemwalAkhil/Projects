// 10. ENTER THE INFIX EXPRESSION FROM USER AND CONVERT INTO POSTFIX EXPRESSION.
// TODO: VALIDATION
#include <stdio.h>
#define size __INT16_MAX__

void push(char *stack, int *top, char val)
{
    stack[++(*top)] = val;
}
char pop(char *stack, int *top)
{
    return stack[(*top)--];
}
char peek(char *stack, int *top)
{
    return stack[*top];
}
int main()
{
    int top = -1;
    char exp[size];
    char stack[size];
    char result[size];
    char curr;
    int ind = 0;
    int i;
    printf("ENTER A INFIX EXPRESSION : ");
    gets(exp);
    for (i = 0; exp[i] != 0; i++)
    {
        if (exp[i] == '^')
        {
            if (top < (size - 1))
            {
                push(stack, &top, exp[i]);
            }
            else
            {
                printf("OPERATION FAILED !!!\n");
                return 1;
            };
        }
        else if ((exp[i] == '*') || (exp[i] == '/'))
        {
            while ((peek(stack, &top) == '^') || (peek(stack, &top) == '*') || (peek(stack, &top) == '/'))
            {
                result[ind++] = pop(stack, &top);
            }
            if (top < (size - 1))
            {
                push(stack, &top, exp[i]);
            }
            else
            {
                printf("OPERATION FAILED !!!\n");
                return 1;
            };
        }
        else if ((exp[i] == '+') || (exp[i] == '-'))
        {
            while ((peek(stack, &top) == '^') || (peek(stack, &top) == '*') || (peek(stack, &top) == '/') || (peek(stack, &top) == '+') || (peek(stack, &top) == '-'))
            {
                result[ind++] = pop(stack, &top);
            }
            if (top < (size - 1))
            {
                push(stack, &top, exp[i]);
            }
            else
            {
                printf("OPERATION FAILED !!!\n");
                return 1;
            };
        }
        else
        {
            result[ind++] = exp[i];
        }
    }
    while (top != -1)
    {
        result[ind++] = pop(stack, &top);
    }

    printf("POSTFIX EXPRESSION : ");
    for (int k = 0; k < ind; k++)
    {
        printf("%c", result[k]);
    }
}