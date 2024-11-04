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
    {
        return 1; // Memory allocation failed
    }
    temp->data = val;

    if (*start == NULL)
    {
        // List is empty, initialize the first node
        *start = temp;
        temp->next = *start;
    }
    else
    {
        // Insert at the beginning
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
    {
        return 1; // Memory allocation failed
    }
    temp->data = val;

    if (*start == NULL)
    {
        // List is empty, initialize the first node
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
    {
        return 1; // Memory allocation failed
    }
    temp->data = val;

    if (*start == NULL)
    {
        if (pos == 0)
        {
            *start = temp;
            temp->next = *start;
            return 0;
        }
        free(temp);
        return 1; // Invalid position for an empty list
    }

    struct node *curr = *start;
    for (int i = 0; i < pos - 1 && curr->next != *start; i++)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;

    if (pos == 0)
    {
        *start = temp;
    }
    return 0;
}

int deleteb(struct node **start)
{
    if (*start == NULL)
    {
        return 1; // List is empty
    }

    struct node *temp = *start;
    if (temp->next == *start)
    {
        *start = NULL;
    }
    else
    {
        struct node *last = *start;
        while (last->next != *start)
        {
            last = last->next;
        }
        *start = temp->next;
        last->next = *start;
    }
    free(temp);
    return 0;
}

int deletee(struct node **start)
{
    if (*start == NULL)
    {
        return 1; // List is empty
    }

    struct node *temp = *start;
    if (temp->next == *start)
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
    {
        return 1; // List is empty or invalid position
    }

    struct node *temp = *start;
    if (pos == 0)
    {
        return deleteb(start);
    }

    struct node *prev = NULL;
    for (int i = 0; i < pos && temp->next != *start; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == *start)
        return 1; // Position out of bounds

    prev->next = temp->next;
    free(temp);
    return 0;
}

int display(struct node *start)
{
    if (start == NULL)
    {
        return 1; // List is empty
    }

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
    {
        return -1; // List is empty
    }

    struct node *temp = start;
    int index = 0;
    do
    {
        if (temp->data == val)
        {
            return index;
        }
        temp = temp->next;
        index++;
    } while (temp != start);
    return -1; // Value not found
}

int isEmpty(struct node *start)
{
    return (start == NULL);
}

int isFull()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        return 1;
    }
    free(temp);
    return 0;
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
            (pos >= 0) ? printf("VALUE FOUND AT %d INDEX\n\n", pos) : printf("VALUE NOT FOUND\n\n");
            break;
        default:
            break;
        }
    } while (choice != 11);

    return 0;
}
