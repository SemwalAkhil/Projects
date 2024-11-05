// 2. IMPLEMENT THE OPERATIONS OF SINGLE CIRCULAR LINKED LIST STORING INTEGER VALUES (INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END, DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int insertb(struct node **start, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    if (*start == NULL)
    {
        *start = temp;
        temp->next = *start;
    }
    else
    {
        struct node *last = *start;
        while (last->next != *start)
        {
            last = last->next;
        }
        temp->next = *start;
        last->next = temp;
        *start = temp;
    }
    return 0;
}

int inserte(struct node **start, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    if (*start == NULL)
    {
        *start = temp;
        temp->next = *start;
    }
    else
    {
        struct node *last = *start;
        while (last->next != *start)
        {
            last = last->next;
        }
        last->next = temp;
        temp->next = *start;
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
            *start = temp;
            temp->next = *start;
            return 0;
        }
        else
        {
            free(temp);
            return 1;
        }
    }

    struct node *curr = *start;
    if (pos == 0)
    {
        return insertb(start, val);
    }

    for (int i = 1; i < pos; i++)
    {
        if (curr->next == *start)
            return 1;
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;
    return 0;
}

int deleteb(struct node **start)
{
    if (*start == NULL)
        return 1;

    struct node *temp = *start;
    if ((*start)->next == *start)
    {
        *start = NULL;
        free(temp);
        return 0;
    }

    struct node *last = *start;
    while (last->next != *start)
    {
        last = last->next;
    }

    *start = (*start)->next;
    last->next = *start;
    free(temp);
    return 0;
}

int deletee(struct node **start)
{
    if (*start == NULL)
        return 1;

    struct node *temp = *start;
    if ((*start)->next == *start)
    {
        *start = NULL;
        free(temp);
        return 0;
    }

    struct node *prev = NULL;
    while (temp->next != *start)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *start;
    free(temp);
    return 0;
}

int delete(struct node **start, int pos)
{
    if (*start == NULL || pos < 0)
        return 1;

    if (pos == 0)
        return deleteb(start);

    struct node *temp = *start;
    struct node *prev = NULL;

    for (int i = 0; i < pos; i++)
    {
        if (temp->next == *start)
            return 1;
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
    return 0;
}

int display(struct node *start)
{
    if (start == NULL)
        return 1;

    struct node *temp = start;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("\n");
    return 0;
}

int search(struct node *start, int val)
{
    if (start == NULL)
        return -1;

    struct node *temp = start;
    int pos = 0;
    do
    {
        if (temp->data == val)
            return pos;
        pos++;
        temp = temp->next;
    } while (temp != start);

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

    // Free all nodes in the circular list
    if (start != NULL)
    {
        struct node *temp = start->next;
        while (temp != start)
        {
            struct node *next = temp->next;
            free(temp);
            temp = next;
        }
        free(start);
    }

    return 0;
}
