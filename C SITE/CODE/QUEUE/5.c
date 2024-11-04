// 5. IMPLEMENT THE OPERATIONS OF CIRCULAR QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Check if the queue is full
int isFull()
{
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

// Check if the queue is empty
int isEmpty()
{
    return front == -1;
}

// Insert an element into the circular queue
void insert(int value)
{
    if (isFull())
    {
        printf("Queue Full\n");
    }
    else
    {
        if (front == -1) // First element being inserted
            front = 0;

        rear = (rear + 1) % SIZE; // Move rear to the next position
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Delete an element from the circular queue
void delete()
{
    if (isEmpty())
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("Deleted %d\n", queue[front]);

        if (front == rear)
        { // Queue becomes empty
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE; // Move front to the next position
        }
    }
}

// Peek at the front element in the circular queue
void peek()
{
    if (isEmpty())
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("Front: %d\n", queue[front]);
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1. INSERT\n2. DELETE\n3. PEEK\n4. ISEMPTY\n5. ISFULL\n6. EXIT\nENTER THE OPERATION: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            delete ();
            break;
        case 3:
            peek();
            break;
        case 4:
            printf(isEmpty() ? "Queue is Empty\n" : "Queue is Not Empty\n");
            break;
        case 5:
            printf(isFull() ? "Queue is Full\n" : "Queue is Not Full\n");
            break;
        case 6:
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
}
