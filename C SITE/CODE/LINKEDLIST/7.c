// 7. IMPLEMENT THE OPERATIONS OF DOUBLY LINKED LIST STORING STRING VALUES (INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END, DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)
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
    temp->prev = NULL;
    temp->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = temp;
    }
    *head = temp;
    return 0;
}

// Insert at the end
int inserte(struct node **head, char val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;

    temp->data = val;
    temp->next = NULL;

    if (*head == NULL)
    {
        temp->prev = NULL;
        *head = temp;
        return 0;
    }

    struct node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
    temp->prev = last;
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
        temp->next = *head;
        temp->prev = NULL;
        if (*head != NULL)
            (*head)->prev = temp;
        *head = temp;
        return 0;
    }

    struct node *current = *head;
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
    temp->prev = current;
    if (current->next != NULL)
        current->next->prev = temp;
    current->next = temp;
    return 0;
}

// Delete at the beginning
int deleteb(struct node **head)
{
    if (*head == NULL)
        return 1;

    struct node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
    return 0;
}

// Delete at the end
int deletee(struct node **head)
{
    if (*head == NULL)
        return 1;

    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }
    free(temp);
    return 0;
}

// Delete at a specific position
int delete(struct node **head, int pos)
{
    if (*head == NULL || pos < 0)
        return 1;

    struct node *temp = *head;
    for (int i = 0; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
        return 1;

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return 0;
}

// Display the list
int display(struct node *head)
{
    if (head == NULL)
        return 1;

    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

// Search for a value in the list
int search(struct node *head, char val)
{
    struct node *temp = head;
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
