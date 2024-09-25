// 3. IMPLEMENT THE OPERATIONS OF QUEUE DYNAMICALLY OF INTEGERS (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int isFull()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        free(temp);
        return 1;
    }
    free(temp);
    return 0;
}
int isEmpty(struct node *start)
{
    if (start->next == NULL)
        return 1;
    return 0;
}
void insert(struct node *start, struct node *end, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->next = end->next;
        temp->data = val;
        end->next = temp;
        if (start->next == NULL)
        {
            start->next = temp;
        }
        // printf("%d\n", end->next->data);
    }
}
void delete(struct node *start)
{
    if (!(isEmpty(start)))
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        printf("%d", start->next->data);
        temp = start->next;
        start->next = temp->next;
        free(temp);
    }
    else
    {
        printf("QUEUE EMPTY");
    }
}
void peek(struct node *start)
{
    if (!(isEmpty(start)))
    {
        printf("%d", start->next->data);
    }
    else
    {
        printf("QUEUE EMPTY");
    }
}
int main()
{
    struct node *start = (struct node *)malloc(sizeof(struct node));
    struct node *end = (struct node *)malloc(sizeof(struct node));
    start->next = NULL;
    end->next = NULL;
    int val, choice;
    while (1)
    {
        printf("\n1.INSERT\n2.DELETE\n3.PEEK\n4.ISEMPTY\n5.ISFULL\n6.EXIT\nENTER THE OPERATION: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER THE VALUE: ");
            scanf("%d", &val);
            insert(start, end, val);
            break;
        case 2:
            delete (start);
            break;
        case 3:
            peek(start);
            break;
        case 4:
            printf(isEmpty(start) ? "QUEUE IS EMPTY" : "QUEUE IS NOT EMPTY");
            break;
        case 5:
            printf(isFull(start) ? "QUEUE IS FULL" : "QUEUE IS NOT FULL");
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
    return 0;
}
/*
    f.next -> r -> null
    r -> temp , temp.next-> null
*/
// #include <stdio.h>
// #include <stdlib.h>
// struct que
// {
//     int val;
//     struct que *next;
// };
// struct que *front = NULL, *rear, *temp;
// void push(int val)
// {
//     if (front == NULL)
//     {
//         front = (struct que *)malloc(2 * sizeof(int));
//         front->val = val;
//         front->next = NULL;
//         rear = front;
//     }
//     else
//     {
//         temp = (struct que *)malloc(2 * sizeof(int));
//         if (temp != NULL)
//         {
//             temp->val = val;
//             temp->next = NULL;
//             rear->next = temp;
//             rear = temp;
//         }
//         else
//         {
//             printf("queue full");
//         }
//     }
// }
// void pop()
// {
//     struct que *tempo;
//     if (front == NULL)
//     {
//         printf("empty");
//     }
//     else
//     {
//         printf("%d", front->val);
//         if (front == rear)
//         {
//             front = NULL;
//             rear = NULL;
//             free(front);
//         }
//         else
//         {
//             tempo = front->next;
//             free(front);
//             front = tempo;
//         }
//     }
// }
// int main()
// {
//     while (1)
//     {
//         int c;
//         printf("choice  : ");
//         scanf("%d", &c);
//         if (c == 1)
//         {
//             scanf("%d", &c);
//             push(c);
//         }
//         else if (c == 2)
//         {
//             pop();
//         }
//         else if (c == 3)
//         {
//             break;
//         }
//     }
// }

/*
    s.next 20
    temp 30
*/