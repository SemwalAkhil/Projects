// 8. IMPLEMENT THE OPERATIONS OF DOUBLY CIRCULAR LINKED LIST STORING STRING VALUES (INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END, DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *prev;
    struct node *next;
};

// Insert at the beginning
int insertb(struct node **head, char val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    if (*head == NULL)
    {
        temp->next = temp->prev = temp;
        *head = temp;
    }
    else
    {
        struct node *last = (*head)->prev;
        temp->next = *head;
        temp->prev = last;
        last->next = temp;
        (*head)->prev = temp;
        *head = temp;
    }
    return 0;
}

// Insert at the end
int inserte(struct node **head, char val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    if (*head == NULL)
    {
        temp->next = temp->prev = temp;
        *head = temp;
    }
    else
    {
        struct node *last = (*head)->prev;
        temp->next = *head;
        temp->prev = last;
        last->next = temp;
        (*head)->prev = temp;
    }
    return 0;
}

// Insert at a specific position
int insert(struct node **head, char val, int pos)
{
    if (pos < 0)
        return 1;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    if (pos == 0)
    {
        return insertb(head, val);
    }

    struct node *current = *head;
    for (int i = 0; i < pos && current->next != *head; i++)
    {
        current = current->next;
    }
    if (current->next == *head)
        return inserte(head, val);

    temp->next = current;
    temp->prev = current->prev;
    current->prev->next = temp;
    current->prev = temp;
    return 0;
}

// Delete at the beginning
int deleteb(struct node **head)
{
    if (*head == NULL)
        return 1;

    struct node *temp = *head;
    if (temp->next == *head)
    {
        *head = NULL;
    }
    else
    {
        struct node *last = temp->prev;
        *head = temp->next;
        (*head)->prev = last;
        last->next = *head;
    }
    free(temp);
    return 0;
}

// Delete at the end
int deletee(struct node **head)
{
    if (*head == NULL)
        return 1;

    struct node *last = (*head)->prev;
    if (last == *head)
    {
        *head = NULL;
    }
    else
    {
        last->prev->next = *head;
        (*head)->prev = last->prev;
    }
    free(last);
    return 0;
}

// Delete at a specific position
int delete(struct node **head, int pos)
{
    if (*head == NULL || pos < 0)
        return 1;

    if (pos == 0)
        return deleteb(head);

    struct node *temp = *head;
    for (int i = 0; i < pos && temp->next != *head; i++)
    {
        temp = temp->next;
    }
    if (temp->next == *head)
        return 1;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return 0;
}

// Display the list
int display(struct node *head)
{
    if (head == NULL)
        return 1;

    struct node *temp = head;
    do
    {
        printf("%c ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
    return 0;
}

// Search for a value in the list
int search(struct node *head, char val)
{
    if (head == NULL)
        return -1;

    struct node *temp = head;
    int pos = 0;
    do
    {
        if (temp->data == val)
            return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);
    return -1;
}

// Check if the list is empty
int isEmpty(struct node *head)
{
    return (head == NULL);
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
    struct node *head = NULL;

    do
    {
        printf("1.INSERT BEGINNING\n2.INSERT END\n3.INSERT\n4.DELETE BEGINNING\n5.DELETE END\n6.DELETE\n7.IS EMPTY\n8.IS FULL\n9.DISPLAY\n10.SEARCH\n11.EXIT\nCHOOSE AN OPERATION: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER CHARACTER: ");
            scanf(" %c", &val);
            insertb(&head, val) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 2:
            printf("ENTER CHARACTER: ");
            scanf(" %c", &val);
            inserte(&head, val) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 3:
            printf("ENTER CHARACTER: ");
            scanf(" %c", &val);
            printf("ENTER POSITION: ");
            scanf("%d", &pos);
            insert(&head, val, pos) ? printf("FAILED TO INSERT\n\n") : printf("INSERTED SUCCESSFULLY\n\n");
            break;
        case 4:
            deleteb(&head) ? printf("FAILED TO DELETE\n\n") : printf("DELETED SUCCESSFULLY\n\n");
            break;
        case 5:
            deletee(&head) ? printf("FAILED TO DELETE\n\n") : printf("DELETED SUCCESSFULLY\n\n");
            break;
        case 6:
            printf("ENTER POSITION: ");
            scanf("%d", &pos);
            delete (&head, pos) ? printf("FAILED TO DELETE\n\n") : printf("DELETED SUCCESSFULLY\n\n");
            break;
        case 7:
            isEmpty(head) ? printf("EMPTY LIST\n\n") : printf("LIST NOT EMPTY\n\n");
            break;
        case 8:
            isFull() ? printf("LIST FULL\n\n") : printf("LIST NOT FULL\n\n");
            break;
        case 9:
            display(head) ? printf("EMPTY LIST\n\n") : printf("\n\n");
            break;
        case 10:
            printf("ENTER CHARACTER TO BE SEARCHED: ");
            scanf(" %c", &val);
            pos = search(head, val);
            (pos >= 0) ? printf("CHARACTER FOUND AT POSITION %d\n\n", pos) : printf("CHARACTER NOT FOUND\n\n");
            break;
        default:
            break;
        }
    } while (choice != 11);

    // Free all nodes in the list
    while (!isEmpty(head))
    {
        deleteb(&head);
    }

    return 0;
}
