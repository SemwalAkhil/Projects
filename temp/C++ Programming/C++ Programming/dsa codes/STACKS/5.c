// 5. ENTER THE STRING FROM THE USER AND REVERSE THE STRING USING STACKS.
#include <stdio.h>
#define size __INT16_MAX__
int push(char *stack, char val, int top)
{
    if (top < (size - 1))
        stack[++top] = val;
    else
        printf("Stack Overflow\n");
    return top;
}
int pop(char *stack, int top)
{
    if (top > -1)
    {
        printf("%c", stack[top]);
        top--;
    }
    else
        printf("Stack Underflow\n");
    return top;
}
int main()
{
    char stack[size];
    int temp, top = -1;
    char arr[size];
    printf("Enter string: ");
    gets(arr);
    for (int i = 0; arr[i] != 0; i++)
    {
        top = push(stack, arr[i], top);
    }
    for (; top > -1;)
    {
        top = pop(stack, top);
    }
}