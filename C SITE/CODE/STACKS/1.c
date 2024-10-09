// 1. CREATE A STACK IMPLEMENTING THE OPERATIONS ON AN INTEGER ARRAY (PUSH, POP, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
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
    int choice, num, top = -1;
    int stack[size];
    while (1)
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Exit\nChoose an operation: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to push: ");
            scanf("%d", &num);
            (top < (size - 1)) ? push(stack, &top, num) : printf("Stack Full !!!\n");
            break;
        case 2:
            (top >= 0) ? printf("%d\n", pop(stack, &top)) : printf("Stack Empty !!!\n");
            break;
        case 3:
            (top >= 0) ? printf("%d\n", peek(stack, &top)) : printf("Stack Empty !!!\n");
            break;
        case 4:
            return 0;
        }
    }
}