// 6. IMPLEMENT THE OPERATIONS OF SINGLE CIRCULAR LINKED LIST STORING STRING VALUES (INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END, DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

// Insert at the beginning
int insertb(struct node **last, char val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    if (*last == NULL)
    {
        temp->next = temp;
        *last = temp;
    }
    else
    {
        temp->next = (*last)->next;
        (*last)->next = temp;
    }
    return 0;
}

// Insert at the end
int inserte(struct node **last, char val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    if (*last == NULL)
    {
        temp->next = temp;
        *last = temp;
    }
    else
    {
        temp->next = (*last)->next;
        (*last)->next = temp;
        *last = temp;
    }
    return 0;
}

// Insert at a specific position
int insert(struct node **last, char val, int pos)
{
    if (pos < 0)
        return 1;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    if (*last == NULL)
    {
        if (pos == 0)
        {
            temp->next = temp;
            *last = temp;
            return 0;
        }
        else
        {
            free(temp);
            return 1;
        }
    }

    struct node *current = (*last)->next;
    for (int i = 0; i < pos && current != *last; i++)
    {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
    if (current == *last)
        *last = temp;
    return 0;
}

// Delete at the beginning
int deleteb(struct node **last)
{
    if (*last == NULL)
        return 1;

    struct node *temp = (*last)->next;
    if (*last == temp)
    {
        *last = NULL;
    }
    else
    {
        (*last)->next = temp->next;
    }
    free(temp);
    return 0;
}

// Delete at the end
int deletee(struct node **last)
{
    if (*last == NULL)
        return 1;

    struct node *temp = (*last)->next;
    if (*last == temp)
    {
        *last = NULL;
        free(temp);
    }
    else
    {
        while (temp->next != *last)
        {
            temp = temp->next;
        }
        temp->next = (*last)->next;
        free(*last);
        *last = temp;
    }
    return 0;
}

// Delete at a specific position
int delete(struct node **last, int pos)
{
    if (*last == NULL || pos < 0)
        return 1;

    struct node *temp = (*last)->next;
    if (pos == 0)
    {
        return deleteb(last);
    }

    for (int i = 0; i < pos - 1 && temp->next != (*last)->next; i++)
    {
        temp = temp->next;
    }
    if (temp->next == (*last)->next)
        return 1;

    struct node *temp2 = temp->next;
    temp->next = temp2->next;
    if (temp2 == *last)
        *last = temp;
    free(temp2);
    return 0;
}

// Display the list
int display(struct node *last)
{
    if (last == NULL)
        return 1;

    struct node *temp = last->next;
    do
    {
        printf("%c ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
    return 0;
}

// Search for a value in the list
int search(struct node *last, char val)
{
    if (last == NULL)
        return -1;

    struct node *temp = last->next;
    int pos = 0;
    do
    {
        if (temp->data == val)
            return pos;
        temp = temp->next;
        pos++;
    } while (temp != last->next);
    return -1;
}

// Check if the list is empty
int isEmpty(struct node *last)
{
    return (last == NULL);
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
    struct node *last = NULL;

    do
    {
        printf("1.INSERT BEGINNING\n2.INSERT END\n3.INSERT\n4.DELETE BEGINNING\n5.DELETE END\n6.DELETE\n7.IS EMPTY\n8.IS FULL\n9.DISPLAY\n10.SEARCH\n11.EXIT\nCHOOSE AN OPERATION: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER CHARACTER: ");
            scanf(" %c", &val);
            insertb(&last, val) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 2:
            printf("ENTER CHARACTER: ");
            scanf(" %c", &val);
            inserte(&last, val) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 3:
            printf("ENTER CHARACTER: ");
            scanf(" %c", &val);
            printf("ENTER POSITION: ");
            scanf("%d", &pos);
            insert(&last, val, pos) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 4:
            deleteb(&last) ? printf("FAILED TO DELETE\n\n") : printf("DELETED SUCCESSFULLY\n\n");
            break;
        case 5:
            deletee(&last) ? printf("FAILED TO DELETE\n\n") : printf("DELETED SUCCESSFULLY\n\n");
            break;
        case 6:
            printf("ENTER POSITION: ");
            scanf("%d", &pos);
            delete (&last, pos) ? printf("FAILED TO DELETE\n\n") : printf("DELETED SUCCESSFULLY\n\n");
            break;
        case 7:
            isEmpty(last) ? printf("EMPTY LIST\n\n") : printf("LIST NOT EMPTY\n\n");
            break;
        case 8:
            isFull() ? printf("LIST FULL\n\n") : printf("LIST NOT FULL\n\n");
            break;
        case 9:
            display(last) ? printf("EMPTY LIST\n\n") : printf("\n\n");
            break;
        case 10:
            printf("ENTER CHARACTER TO BE SEARCHED: ");
            scanf(" %c", &val);
            pos = search(last, val);
            (pos >= 0) ? printf("CHARACTER FOUND AT POSITION %d\n\n", pos) : printf("CHARACTER NOT FOUND\n\n");
            break;
        default:
            break;
        }
    } while (choice != 11);

    // Free all nodes in the list
    while (!isEmpty(last))
    {
        deleteb(&last);
    }

    return 0;
}
