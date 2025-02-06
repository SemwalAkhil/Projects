// 2. CREATE A STACK IMPLEMENTING THE OPERATIONS ON AN CHARACTERS ARRAY (PUSH, POP, PEEK, ISEMPTY, ISFULL)
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
static inline int isEmpty(char *stack, int *top)
{
    return *top == -1;
}
static inline int isFull(char *stack, int *top)
{
    return *top == (size - 1);
}
int main()
{
    int choice, top = -1;
    char val;
    char stack[size];
    while (1)
    {
        fflush(stdin);
        printf("1.Push\n2.Pop\n3.Peek\n4.IsEmpty\n5.IsFull\n6.Exit\nChoose an operation: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            fflush(stdin);
            printf("Enter character to push: ");
            scanf("%c", &val);
            !isFull(stack, &top) ? push(stack, &top, val) : printf("Stack Full !!!\n");
            break;
        case 2:
            !isEmpty(stack, &top) ? printf("%c\n", pop(stack, &top)) : printf("Stack Empty !!!\n");
            break;
        case 3:
            !isEmpty(stack, &top) ? printf("%c\n", peek(stack, &top)) : printf("Stack Empty !!!\n");
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
