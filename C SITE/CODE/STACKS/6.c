// 6. CREATE THE PROGRAM TO MATCH THE SINGLE BRACKET USING STACKS.
#include <stdio.h>
#define size __INT16_MAX__
int push(int *stack, int val, int top)
{
    if (top < (size - 1))
        stack[++top] = val;
    else
        printf("Stack Overflow\n");
    return top;
}
int pop(int *stack, int top)
{
    if (top > -1)
        top--;
    else
        printf("Stack Underflow\n");
    return top;
}
int main()
{
    int stack[size], temp, top = -1;
    char arr[size];
    printf("Enter string: ");
    gets(arr);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == '(')
        {
            top = push(stack, 1, top);
        }
        else if (arr[i] == ')')
        {
            if (top > -1)
            {
                top = pop(stack, top);
            }
            else
            {
                printf("Non Matching Parenthesis");
                return 0;
            }
        }
    }
    if (top == -1)
    {
        printf("Matching Parenthesis");
    }
    else
    {
        printf("Non Matching Parenthesis");
    }
    return 0;
};