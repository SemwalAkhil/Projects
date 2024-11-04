// 11. IMPLEMENT THE OPERATIONS OF PRIORITY QUEUE DYNAMICALLY OF INTEGERS (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the priority queue
struct Node
{
    int data;          // The data (integer)
    int priority;      // The priority of the data
    struct Node *next; // Pointer to the next node
};

// Structure for the priority queue
struct PriorityQueue
{
    struct Node *head; // Head of the linked list
};

// Function to initialize the priority queue
void initQueue(struct PriorityQueue *pq)
{
    pq->head = NULL;
}

// Check if the priority queue is empty
int isEmpty(struct PriorityQueue *pq)
{
    return pq->head == NULL;
}

// Check if the priority queue is full (based on malloc)
int isFull()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        return 1; // Memory allocation failed
    }
    free(temp);
    return 0; // Memory available
}

// Insert an integer with a specified priority into the priority queue
void insert(struct PriorityQueue *pq, int value, int priority)
{
    if (isFull())
    {
        printf("Priority Queue is Full\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;

    // Insert in sorted order based on priority (lower priority value means higher priority)
    if (pq->head == NULL || pq->head->priority > priority)
    {
        // Insert at the beginning if queue is empty or new node has higher priority
        newNode->next = pq->head;
        pq->head = newNode;
    }
    else
    {
        // Find the right position to insert
        struct Node *current = pq->head;
        while (current->next != NULL && current->next->priority <= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Inserted %d with priority %d into the priority queue\n", value, priority);
}

// Delete the integer with the highest priority (lowest priority value)
void delete(struct PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    struct Node *temp = pq->head;
    pq->head = pq->head->next;
    printf("Deleted %d with priority %d from the priority queue\n", temp->data, temp->priority);
    free(temp);
}

// Peek at the integer with the highest priority
void peek(struct PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is Empty\n");
    }
    else
    {
        printf("Highest Priority Element: %d with priority %d\n", pq->head->data, pq->head->priority);
    }
}

int main()
{
    struct PriorityQueue pq;
    initQueue(&pq);

    int choice, value, priority;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Peek\n4. IsEmpty\n5. IsFull\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            printf("Enter the priority of the value: ");
            scanf("%d", &priority);
            insert(&pq, value, priority);
            break;
        case 2:
            delete (&pq);
            break;
        case 3:
            peek(&pq);
            break;
        case 4:
            printf(isEmpty(&pq) ? "Priority Queue is Empty\n" : "Priority Queue is Not Empty\n");
            break;
        case 5:
            printf(isFull() ? "Priority Queue is Full\n" : "Priority Queue is Not Full\n");
            break;
        case 6:
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }

    return 0;
}
