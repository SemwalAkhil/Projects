// 3. CREATE A STACK IMPLEMENTING THE OPERATIONS ON AN INTEGER NODES (DYNAMICALLY) (PUSH, POP, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};
void push(struct node *start, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->data = val;
        temp->next = start->next;
        start->next = temp;
    }
    else
    {
        printf("MEMORY ALLOCATION FAILED !!!\n");
    }
}
void pop(struct node *start)
{
    if ((start->next) != NULL)
    {
        printf("%d\n", start->next->data);
        struct node *temp = start->next->next;
        free(start->next);
        start->next = temp;
    }
    else
    {
        printf("STACK EMPTY - OPERATION FAILED !!!\n");
    }
}
int peek(struct node *start)
{
    if ((start->next) != NULL)
    {
        return start->next->data;
    }
    else
    {
        printf("STACK EMPTY - OPERATION FAILED !!!\n");
        return -1;
    }
}
int isEmpty(struct node *start)
{
    if (start->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct node *start)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        free(temp);
        temp = NULL;
        return 1;
    }
    else
    {
        free(temp);
        temp = NULL;
        return 0;
    }
}
int main()
{
    struct node *start = (struct node *)malloc(sizeof(struct node));
    start->next = NULL;
    int input = 4;
    int val;
    while (1)
    {
        printf("\n1.PUSH\n2.POP\n3.PEEK\n4.ISEMPTY\n5.ISFULL\n6.EXIT\nENTER OPERATION:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("ENTER VALUE:");
            scanf("%d", &val);
            push(start, val);
            break;
        case 2:
            pop(start);
            break;
        case 3:
            printf("%d\n", peek(start));
            break;
        case 4:
            printf("%s\n", isEmpty(start) ? "STACK EMPTY" : "STACK NOT EMPTY");
            break;
        case 5:
            printf("%s\n", isFull(start) ? "STACK FULL" : "STACK NOT FULL");
            break;
        case 6:
            printf("EXITING...\n");
            return 0;
        default:
            break;
        }
    }
}