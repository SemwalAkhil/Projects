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
static inline int isEmpty(int *stack, int *top)
{
    return *top == -1;
}
static inline int isFull(int *stack, int *top)
{
    return *top == (size - 1);
}
int main()
{
    int choice, num, top = -1;
    int stack[size];
    while (1)
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.IsEmpty\n5.IsFull\n6.Exit\nChoose an operation: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to push: ");
            scanf("%d", &num);
            !isFull(stack, &top) ? push(stack, &top, num) : printf("Stack Full !!!\n");
            break;
        case 2:
            !isEmpty(stack, &top) ? printf("%d\n", pop(stack, &top)) : printf("Stack Empty !!!\n");
            break;
        case 3:
            !isEmpty(stack, &top) ? printf("%d\n", peek(stack, &top)) : printf("Stack Empty !!!\n");
            break;
        case 4:
            isEmpty(stack, &top) ? printf("Stack Empty !!!\n") : printf("Stack not Empty\n");
            break;
        case 5:
            isFull(stack, &top) ? printf("Stack Full !!!\n") : printf("Stack not Full\n");
            break;
        case 6:
            return 0;
        }
    }
}
