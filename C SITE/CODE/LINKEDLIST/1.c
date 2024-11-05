// 1. IMPLEMENT THE OPERATIONS OF SINGLE LINKED LIST STORING INTEGER VALUES (INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END, DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

int insertb(struct node *start, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->data = val;
        temp->next = start->next;
        start->next = temp;
        return 0;
    }
    return 1;
}

int inserte(struct node *start, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    struct node *end = start;
    while (end->next != NULL)
    {
        end = end->next;
    }
    end->next = temp;
    temp->data = val;
    temp->next = NULL;
    return 0;
}

int insert(struct node *start, int val, int pos)
{
    if (pos < 0)
        return 1;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    struct node *posNode = start;
    for (int i = 0; i < pos; i++)
    {
        posNode = posNode->next;
        if (posNode == NULL)
        {
            free(temp);
            return 1;
        }
    }
    temp->next = posNode->next;
    temp->data = val;
    posNode->next = temp;
    return 0;
}

int deleteb(struct node *start)
{
    struct node *temp = start->next;
    if (temp != NULL)
    {
        start->next = temp->next;
        free(temp);
        return 0;
    }
    return 1;
}

int deletee(struct node *start)
{
    if (start->next == NULL)
        return 1;

    struct node *temp = start;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return 0;
}

int delete(struct node *start, int pos)
{
    if (pos < 0)
        return 1;

    struct node *temp = start;
    for (int i = 0; i < pos; i++)
    {
        if (temp->next == NULL)
            return 1;
        temp = temp->next;
    }

    if (temp->next != NULL)
    {
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
        return 0;
    }
    return 1;
}

int display(struct node *start)
{
    if (start->next == NULL)
    {
        return 1;
    }
    struct node *temp = start->next;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

int search(struct node *start, int val)
{
    struct node *temp = start->next;
    int counter = 0;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return counter;
        }
        counter++;
        temp = temp->next;
    }
    return -1;
}

int isEmpty(struct node *start)
{
    return (start->next == NULL);
}

int isFull()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int full = (temp == NULL);
    free(temp);
    return full;
}

int main()
{
    int choice, val, pos;
    struct node *start = (struct node *)malloc(sizeof(struct node));
    start->next = NULL;

    do
    {
        printf("1.INSERT BEGINNING\n2.INSERT END\n3.INSERT\n4.DELETE BEGINNING\n5.DELETE END\n6.DELETE\n7.IS EMPTY\n8.IS FULL\n9.DISPLAY\n10.SEARCH\n11.EXIT\nCHOOSE AN OPERATION: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER ELEMENT : ");
            scanf("%d", &val);
            insertb(start, val) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 2:
            printf("ENTER ELEMENT : ");
            scanf("%d", &val);
            inserte(start, val) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 3:
            printf("ENTER ELEMENT : ");
            scanf("%d", &val);
            printf("ENTER INDEX : ");
            scanf("%d", &pos);
            insert(start, val, pos) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 4:
            deleteb(start) ? printf("FAILED TO DELETE\n\n") : printf("DELETED SUCCESSFULLY\n\n");
            break;
        case 5:
            deletee(start) ? printf("FAILED TO DELETE\n\n") : printf("DELETED SUCCESSFULLY\n\n");
            break;
        case 6:
            printf("ENTER INDEX : ");
            scanf("%d", &pos);
            delete (start, pos) ? printf("FAILED TO DELETE\n\n") : printf("DELETED SUCCESSFULLY\n\n");
            break;
        case 7:
            isEmpty(start) ? printf("EMPTY LIST\n\n") : printf("LIST NOT EMPTY\n\n");
            break;
        case 8:
            isFull() ? printf("LIST FULL\n\n") : printf("LIST NOT FULL\n\n");
            break;
        case 9:
            display(start) ? printf("EMPTY LIST\n\n") : printf("\n\n");
            break;
        case 10:
            printf("ENTER VALUE TO BE SEARCHED : ");
            scanf("%d", &val);
            pos = search(start, val);
            (pos >= 0) ? printf("VALUE FOUND AT %d INDEX\n\n", pos) : printf("VALUE NOT FOUND\n\n");
            break;
        default:
            break;
        }
    } while (choice != 11);

    free(start); // Free the start node to prevent memory leaks
    return 0;
}
