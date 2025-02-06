// 12. CREATE A PROGRAM TO EVALUATE THE POSTFIX EXPRESSION.
// TODO: VALIDATION
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
    int result;
    char curr;
    int ind = 0;
    int opr1, opr2;
    int i;
    printf("ENTER A POSTFIX EXPRESSION : ");
    gets(exp);
    for (i = 0; exp[i] != 0; i++)
    {
        if ((exp[i] == '^') || (exp[i] == '*') || (exp[i] == '/') || (exp[i] == '+') || (exp[i] == '-'))
        {
            opr2 = (int)(pop(stack, &top)); // ASCII 0 -> 48
            opr1 = (int)(pop(stack, &top)); // ASCII 0 -> 48
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
        else if ((exp[i] > 47) && (exp[i] < 58)) // ASCII 0 -> 48 9 -> 57
        {
            push(stack, &top, exp[i] - 48);
        }
    }
    result = pop(stack, &top);
    printf("RESULT : %d", result);
    return 0;
}