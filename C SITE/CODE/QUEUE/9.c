// 9. IMPLEMENT THE OPERATIONS OF DOUBLE ENDED QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#define SIZE 5

// Structure to represent the deque
struct Deque
{
    int arr[SIZE];
    int front;
    int rear;
    int count;
};

// Initialize the deque
void initDeque(struct Deque *deque)
{
    deque->front = -1;
    deque->rear = 0;
    deque->count = 0;
}

// Check if deque is full
int isFull(struct Deque *deque)
{
    return deque->count == SIZE;
}

// Check if deque is empty
int isEmpty(struct Deque *deque)
{
    return deque->count == 0;
}

// Insert an element at the front of the deque
void insertFront(struct Deque *deque, int value)
{
    if (isFull(deque))
    {
        printf("Deque is Full\n");
        return;
    }

    if (deque->front == -1)
    { // First insertion
        deque->front = deque->rear = 0;
    }
    else if (deque->front == 0)
    {
        deque->front = SIZE - 1;
    }
    else
    {
        deque->front--;
    }

    deque->arr[deque->front] = value;
    deque->count++;
    printf("Inserted %d at front\n", value);
}

// Insert an element at the rear of the deque
void insertRear(struct Deque *deque, int value)
{
    if (isFull(deque))
    {
        printf("Deque is Full\n");
        return;
    }

    if (deque->front == -1)
    { // First insertion
        deque->front = deque->rear = 0;
    }
    else if (deque->rear == SIZE - 1)
    {
        deque->rear = 0;
    }
    else
    {
        deque->rear++;
    }

    deque->arr[deque->rear] = value;
    deque->count++;
    printf("Inserted %d at rear\n", value);
}

// Delete an element from the front of the deque
void deleteFront(struct Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted %d from front\n", deque->arr[deque->front]);

    if (deque->front == deque->rear)
    { // Single element
        deque->front = deque->rear = -1;
    }
    else if (deque->front == SIZE - 1)
    {
        deque->front = 0;
    }
    else
    {
        deque->front++;
    }

    deque->count--;
}

// Delete an element from the rear of the deque
void deleteRear(struct Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted %d from rear\n", deque->arr[deque->rear]);

    if (deque->front == deque->rear)
    { // Single element
        deque->front = deque->rear = -1;
    }
    else if (deque->rear == 0)
    {
        deque->rear = SIZE - 1;
    }
    else
    {
        deque->rear--;
    }

    deque->count--;
}

// Peek at the front element of the deque
void peekFront(struct Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is Empty\n");
    }
    else
    {
        printf("Front Element: %d\n", deque->arr[deque->front]);
    }
}

// Peek at the rear element of the deque
void peekRear(struct Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is Empty\n");
    }
    else
    {
        printf("Rear Element: %d\n", deque->arr[deque->rear]);
    }
}

int main()
{
    struct Deque deque;
    initDeque(&deque);

    int choice, value;

    while (1)
    {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Peek Front\n6. Peek Rear\n7. IsEmpty\n8. IsFull\n9. Exit\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertFront(&deque, value);
            break;
        case 2:
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            insertRear(&deque, value);
            break;
        case 3:
            deleteFront(&deque);
            break;
        case 4:
            deleteRear(&deque);
            break;
        case 5:
            peekFront(&deque);
            break;
        case 6:
            peekRear(&deque);
            break;
        case 7:
            printf(isEmpty(&deque) ? "Deque is Empty\n" : "Deque is Not Empty\n");
            break;
        case 8:
            printf(isFull(&deque) ? "Deque is Full\n" : "Deque is Not Full\n");
            break;
        case 9:
            return 0;
        default:
            printf("Invalid option. Try again.\n");
            break;
        }
    }

    return 0;
}
