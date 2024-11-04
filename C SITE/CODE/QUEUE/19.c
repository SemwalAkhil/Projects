// 19. Queue Reversal
/*
Explanation -

    Given a Queue Q containing N elements.The task is to reverse the Queue.Your task is to complete the function rev(),
    that reverses the N elements of the queue.
    Example 1 :
    Input : 6 4 3 1 10 2 6
    Output : 6 2 10 1 3 4
    Explanation : After reversing the given elements of the queue, the resultant queue will be 6 2 10 1 3 4.
    Example 2 :
    Input : 4 4 3 2 1
    Output : 1 2 3 4
    Explanation : After reversing the given elements of the queue, the resultant queue will be 1 2 3 4.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct
{
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create an empty queue
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue *q)
{
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}

// Function to add an element to the queue
void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to remove an element from the queue
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1; // Return -1 if the queue is empty
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1; // Reset the queue when it becomes empty
    }
    return item;
}

// Function to reverse the queue using a stack
void reverseQueue(Queue *q)
{
    if (isEmpty(q))
    {
        return; // Do nothing if the queue is empty
    }

    // Create a stack to hold elements
    int stack[MAX];
    int top = -1;

    // Dequeue all elements and push them onto the stack
    while (!isEmpty(q))
    {
        stack[++top] = dequeue(q);
    }

    // Pop elements from the stack and enqueue them back to the queue
    while (top != -1)
    {
        enqueue(q, stack[top--]);
    }
}

// Function to print the queue
void printQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main()
{
    Queue *q = createQueue();
    int n, value;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(q, value);
    }

    printf("Queue before reversing: ");
    printQueue(q);

    reverseQueue(q);

    printf("Queue after reversing: ");
    printQueue(q);

    // Free the allocated memory
    free(q);

    return 0;
}
