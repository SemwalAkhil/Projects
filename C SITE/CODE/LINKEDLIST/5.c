// 5. IMPLEMENT THE OPERATIONS OF SINGLE LINKED LIST STORING STRING VALUES (INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END, DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

// Insert at the beginning
int insertb(struct node **start, char val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    temp->next = *start;
    *start = temp;
    return 0;
}

// Insert at the end
int inserte(struct node **start, char val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    temp->next = NULL;

    if (*start == NULL)
    {
        *start = temp;
    }
    else
    {
        struct node *end = *start;
        while (end->next != NULL)
        {
            end = end->next;
        }
        end->next = temp;
    }
    return 0;
}

// Insert at a specific position
int insert(struct node **start, char val, int pos)
{
    if (pos < 0)
        return 1;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    if (pos == 0)
    {
        temp->next = *start;
        *start = temp;
    }
    else
    {
        struct node *current = *start;
        for (int i = 0; i < pos - 1 && current != NULL; i++)
        {
            current = current->next;
        }
        if (current == NULL)
        {
            free(temp);
            return 1;
        }
        temp->next = current->next;
        current->next = temp;
    }
    return 0;
}

// Delete at the beginning
int deleteb(struct node **start)
{
    if (*start == NULL)
        return 1;

    struct node *temp = *start;
    *start = (*start)->next;
    free(temp);
    return 0;
}

// Delete at the end
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

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return 0;
}

// Delete at a specific position
int delete(struct node **start, int pos)
{
    if (*start == NULL || pos < 0)
        return 1;

    struct node *temp = *start;
    if (pos == 0)
    {
        *start = temp->next;
        free(temp);
        return 0;
    }

    for (int i = 0; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
        return 1;

    struct node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    return 0;
}

// Display the list
int display(struct node *start)
{
    if (start == NULL)
        return 1;

    struct node *temp = start;
    while (temp != NULL)
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

// Search for a value in the list
int search(struct node *start, char val)
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

// Check if the list is empty
int isEmpty(struct node *start)
{
    return (start == NULL);
}

// Check if the list is full
int isFull()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int full = (temp == NULL);
    free(temp);
    return full;
}

int main()
{
    int choice, pos;
    char val;
    struct node *start = NULL;

    do
    {
        printf("1.INSERT BEGINNING\n2.INSERT END\n3.INSERT\n4.DELETE BEGINNING\n5.DELETE END\n6.DELETE\n7.IS EMPTY\n8.IS FULL\n9.DISPLAY\n10.SEARCH\n11.EXIT\nCHOOSE AN OPERATION: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER CHARACTER: ");
            scanf(" %c", &val);
            insertb(&start, val) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 2:
            printf("ENTER CHARACTER: ");
            scanf(" %c", &val);
            inserte(&start, val) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 3:
            printf("ENTER CHARACTER: ");
            scanf(" %c", &val);
            printf("ENTER POSITION: ");
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
            printf("ENTER POSITION: ");
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
            printf("ENTER CHARACTER TO BE SEARCHED: ");
            scanf(" %c", &val);
            pos = search(start, val);
            (pos >= 0) ? printf("CHARACTER FOUND AT POSITION %d\n\n", pos) : printf("CHARACTER NOT FOUND\n\n");
            break;
        default:
            break;
        }
    } while (choice != 11);

    // Free all nodes in the list
    while (start != NULL)
    {
        deleteb(&start);
    }

    return 0;
}
