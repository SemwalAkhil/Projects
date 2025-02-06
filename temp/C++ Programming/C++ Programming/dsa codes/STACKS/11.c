// 11. CREATE A PROGRAM TO EVALUATE THE PREFIX EXPRESSION.
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
void cpush(char *stack, int *top, char val)
{
    stack[++(*top)] = val;
}
char cpop(char *stack, int *top)
{
    return stack[(*top)--];
}
void reverse(char source[])
{
    char stack[size];
    int top = -1;
    int i;
    for (i = 0; source[i] != 0; i++)
    {
        cpush(stack, &top, source[i]);
    }
    i = 0;
    while (top != -1)
    {
        source[i] = cpop(stack, &top);
        i++;
    }
    source[i] = 0;
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
    printf("ENTER A PREFIX EXPRESSION : ");
    gets(exp);
    reverse(exp);
    for (i = 0; exp[i] != 0; i++)
    {
        if ((exp[i] == '^') || (exp[i] == '*') || (exp[i] == '/') || (exp[i] == '+') || (exp[i] == '-'))
        {
            opr1 = (int)(pop(stack, &top)); // ASCII 0 -> 48
            opr2 = (int)(pop(stack, &top)); // ASCII 0 -> 48
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