// 3. IMPLEMENT THE OPERATIONS OF DOUBLY LINKED LIST STORING INTEGER VALUES (INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END, DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int insertb(struct node **start, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    temp->prev = NULL;
    temp->next = *start;

    if (*start != NULL)
    {
        (*start)->prev = temp;
    }
    *start = temp;
    return 0;
}

int inserte(struct node **start, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    temp->next = NULL;

    if (*start == NULL)
    {
        temp->prev = NULL;
        *start = temp;
    }
    else
    {
        struct node *last = *start;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = temp;
        temp->prev = last;
    }
    return 0;
}

int insert(struct node **start, int val, int pos)
{
    if (pos < 0)
        return 1;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;

    if (*start == NULL)
    {
        if (pos == 0)
        {
            temp->prev = NULL;
            temp->next = NULL;
            *start = temp;
            return 0;
        }
        else
        {
            free(temp);
            return 1;
        }
    }

    if (pos == 0)
    {
        return insertb(start, val);
    }

    struct node *curr = *start;
    for (int i = 0; i < pos - 1; i++)
    {
        if (curr->next == NULL)
        {
            free(temp);
            return 1;
        }
        curr = curr->next;
    }

    temp->next = curr->next;
    if (curr->next != NULL)
    {
        curr->next->prev = temp;
    }
    temp->prev = curr;
    curr->next = temp;

    return 0;
}

int deleteb(struct node **start)
{
    if (*start == NULL)
        return 1;

    struct node *temp = *start;
    *start = (*start)->next;

    if (*start != NULL)
    {
        (*start)->prev = NULL;
    }
    free(temp);
    return 0;
}

int deletee(struct node **start)
{
    if (*start == NULL)
        return 1;

    struct node *temp = *start;
    if (temp->next == NULL)
    {
        *start = NULL;
        free(temp);
        return 0;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    return 0;
}

int delete(struct node **start, int pos)
{
    if (*start == NULL || pos < 0)
        return 1;

    struct node *temp = *start;

    if (pos == 0)
    {
        return deleteb(start);
    }

    for (int i = 0; i < pos; i++)
    {
        if (temp->next == NULL)
            return 1;
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return 0;
}

int display(struct node *start)
{
    if (start == NULL)
        return 1;

    struct node *temp = start;
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
    struct node *temp = start;
    int pos = 0;
    while (temp != NULL)
    {
        if (temp->data == val)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

int isEmpty(struct node *start)
{
    return (start == NULL);
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
    struct node *start = NULL;

    do
    {
        printf("1.INSERT BEGINNING\n2.INSERT END\n3.INSERT\n4.DELETE BEGINNING\n5.DELETE END\n6.DELETE\n7.IS EMPTY\n8.IS FULL\n9.DISPLAY\n10.SEARCH\n11.EXIT\nCHOOSE AN OPERATION: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER ELEMENT : ");
            scanf("%d", &val);
            insertb(&start, val) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 2:
            printf("ENTER ELEMENT : ");
            scanf("%d", &val);
            inserte(&start, val) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 3:
            printf("ENTER ELEMENT : ");
            scanf("%d", &val);
            printf("ENTER POSITION : ");
            scanf("%d", &pos);
            insert(&start, val, pos) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 4:
            deleteb(&start) ? printf("FAILED TO DELETE\n\n") : printf("DELETED SUCCESSFULLY\n\n");
            break;
        case 5:
            deletee(&start) ? printf("FAILED TO DELETE\n\n") : printf("DELETED SUCCESSFULLY\n\n");
            break;
        case 6:
            printf("ENTER POSITION : ");
            scanf("%d", &pos);
            delete (&start, pos) ? printf("FAILED TO DELETE\n\n") : printf("DELETED SUCCESSFULLY\n\n");
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
            (pos >= 0) ? printf("VALUE FOUND AT POSITION %d\n\n", pos) : printf("VALUE NOT FOUND\n\n");
            break;
        default:
            break;
        }
    } while (choice != 11);

    // Free all nodes in the doubly linked list
    while (start != NULL)
    {
        struct node *temp = start;
        start = start->next;
        free(temp);
    }

    return 0;
}
