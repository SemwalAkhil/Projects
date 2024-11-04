// 18. Reverse First K elements of Queue
/*
Explanation -

    Given an integer K and a queue of integers,
    we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.Only following standard operations are allowed on queue.enqueue(x) : Add an item x to rear of queue dequeue() : Remove an item from front of queue size() : Returns number of elements in queue.front() : Finds front item.Note : The above operations represent the general processings.In - built functions of the respective languages can be used to solve the problem.
    Example 1 :
    Input : 5 3 1 2 3 4 5
    Output : 3 2 1 4 5
    Explanation : After reversing the given input from the 3rd position the resultant output will be 3 2 1 4 5.
    Example 2 :
    Input : 4 4 4 3 2 1
    Output : 1 2 3 4
    Explanation : After reversing the given input from the 4th position the resultant output will be 1 2 3 4.
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

// Function to reverse the first K elements of the queue
void reverseFirstK(Queue *q, int K)
{
    if (isEmpty(q) || K <= 0 || K > (q->rear - q->front + 1))
    {
        return; // Do nothing if the queue is empty or K is invalid
    }

    // Use a stack to reverse the first K elements
    int stack[MAX];
    int top = -1;

    // Dequeue first K elements and push them onto the stack
    for (int i = 0; i < K; i++)
    {
        stack[++top] = dequeue(q);
    }

    // Pop elements from the stack and enqueue them back to the queue
    for (int i = 0; i < K; i++)
    {
        enqueue(q, stack[top--]);
    }

    // Move the remaining elements to the back of the queue
    for (int i = 0; i < (q->rear - q->front + 1) - K; i++)
    {
        enqueue(q, dequeue(q));
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
    int n, k, value;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(q, value);
    }

    printf("Enter the value of K: ");
    scanf("%d", &k);

    reverseFirstK(q, k);

    printf("Queue after reversing first %d elements: ", k);
    printQueue(q);

    // Free the allocated memory
    free(q);

    return 0;
}
