// 3. CREATE A STACK IMPLEMENTING THE OPERATIONS ON AN INTEGER NODES (DYNAMICALLY) (PUSH, POP, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};
int push(struct node *top, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->next = top->next;
        temp->data = val;
        top->next = temp;
        return 0;
    }
    return 1;
}
int pop(struct node *top)
{
    int temp = top->next->data;
    struct node *ptr = top->next;
    top->next = top->next->next;
    free(ptr);
    return temp;
}
int peek(struct node *top)
{
    return top->next->data;
}
static inline int isEmpty(struct node *top)
{
    return top->next == NULL;
}
static inline int isFull(struct node *top)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    return temp == NULL;
}
int main()
{
    int choice, num;
    struct node *top;
    while (1)
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.IsEmpty\n5.IsFull\n6.Exit\nChoose an operation: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to push: ");
            scanf("%d", &num);
            !isFull(top) ? push(top, num) : printf("Stack Full !!!\n");
            break;
        case 2:
            !isEmpty(top) ? printf("%d\n", pop(top)) : printf("Stack Empty !!!\n");
            break;
        case 3:
            !isEmpty(top) ? printf("%d\n", peek(top)) : printf("Stack Empty !!!\n");
            break;
        case 4:
            isEmpty(top) ? printf("Stack Empty !!!\n") : printf("Stack not Empty\n");
            break;
        case 5:
            isFull(top) ? printf("Stack Full !!!\n") : printf("Stack not Full\n");
            break;
        case 6:
            return 0;
        }
    }
}