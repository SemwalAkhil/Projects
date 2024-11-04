// 4. IMPLEMENT THE OPERATIONS OF QUEUE DYNAMICALLY OF STRING (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

// Function to check if the queue is empty
int isEmpty(struct node *front)
{
    return front == NULL;
}
int isFull()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    return (temp == NULL);
}
// Function to insert a new element into the queue
void insert(struct node **front, struct node **rear, char val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->data = val;
        temp->next = NULL;
        if (*rear == NULL)
        { // Queue is empty
            *front = *rear = temp;
        }
        else
        {
            (*rear)->next = temp;
            *rear = temp;
        }
    }
    else
    {
        printf("Memory allocation failed\n");
    }
}

// Function to delete an element from the queue
void delete(struct node **front)
{
    if (*front != NULL)
    {
        struct node *temp = *front;
        printf("Deleted: %c\n", temp->data);
        *front = (*front)->next;
        free(temp);
    }
    else
    {
        printf("Queue Empty\n");
    }
}

// Function to peek at the front element of the queue
void peek(struct node *front)
{
    if (front != NULL)
    {
        printf("Front: %c\n", front->data);
    }
    else
    {
        printf("Queue Empty\n");
    }
}

int main()
{
    struct node *front = NULL;
    struct node *rear = NULL;
    int choice;
    char val;

    while (1)
    {
        printf("\n1. INSERT\n2. DELETE\n3. PEEK\n4. ISEMPTY\n5. ISFULL\n6. EXIT\nENTER THE OPERATION: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("ENTER THE VALUE: ");
            fflush(stdin);
            scanf("%c", &val);
            insert(&front, &rear, val);
            break;
        case 2:
            delete (&front);
            if (front == NULL)
                rear = NULL; // Reset rear if queue is empty after deletion
            break;
        case 3:
            peek(front);
            break;
        case 4:
            printf(isEmpty(front) ? "QUEUE IS EMPTY\n" : "QUEUE IS NOT EMPTY\n");
            break;
        case 5:
            printf(isFull() ? "QUEUE IS FULL\n" : "QUEUE IS NOT FULL\n");
            break;
        case 6:
            // Free all remaining nodes before exiting
            while (!isEmpty(front))
            {
                delete (&front);
            }
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
}
