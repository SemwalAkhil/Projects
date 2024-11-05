// // 9. ENTER THE INFIX EXPRESSION FROM USER AND CONVERT INTO PREFIX EXPRESSION.

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
char reverse(char *exp, int strSize)
{
    if (strSize == -1)
    {
        char temp[size];
        int top = -1;
        for (int i = 0; exp[i] != 0; i++)
        {
            push(temp, &top, exp[i]);
        }
        for (int i = 0; top != -1; i++)
        {
            exp[i] = pop(temp, &top);
        }
    }
    else
    {
        int temp;
        for (int i = 0; i <= (strSize / 2); i++)
        {
            temp = exp[i];
            exp[i] = exp[strSize - i - 1];
            exp[strSize - i - 1] = temp;
        }
    }
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
    reverse(exp, -1);
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
            while (peek(stack, &top) == '^')
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
        else
        {
            result[ind++] = exp[i];
        }
    }
    while (top != -1)
    {
        result[ind++] = pop(stack, &top);
    }
    reverse(result, ind);
    printf("PREFIX EXPRESSION : ");
    for (int k = 0; k < ind; k++)
    {
        printf("%c", result[k]);
    }
}