// 12. CREATE A PROGRAM TO EVALUATE THE POSTFIX EXPRESSION.
#include <stdio.h>
#include <math.h>
#define size __INT16_MAX__

void push(int *stack, int *top, int val)
{
    stack[++(*top)] = val;
}
int pop(int *stack, int *top)
{
    return stack[(*top)--];
}
int peek(int *stack, int *top)
{
    return stack[*top];
}
int main()
{
    int top = -1;
    char exp[size];
    int stack[size];
    char result[size];
    char curr;
    int ind = 0;
    int opr1, opr2;
    int i;
    printf("ENTER A INFIX EXPRESSION : ");
    gets(exp);
    for (i = 0; exp[i] != 0; i++)
    {
        if ((exp[i] == '^') || (exp[i] == '*') || (exp[i] == '/') || (exp[i] == '+') || (exp[i] == '-'))
        {
            opr2 = (int)(pop(stack, &top)) + 47; // ASCII 0 -> 47
            opr1 = (int)(pop(stack, &top)) + 47; // ASCII 0 -> 47
            if (exp[i] == '^')
            {
                push(stack, &top, pow(opr1, opr2));
            }
            if (exp[i] == '*')
            {
                push(stack, &top, opr1 * opr2);
            }
            if (exp[i] == '/')
            {
                push(stack, &top, opr1 / opr2);
            }
            if (exp[i] == '+')
            {
                push(stack, &top, opr1 + opr2);
            }
            if (exp[i] == '-')
            {
                push(stack, &top, opr1 - opr2);
            }
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