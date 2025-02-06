#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->arr = (int *)malloc(capacity * sizeof(int));
    return q;
}

int isFull(Queue *q) {
    return (q->size == q->capacity);
}

int isEmpty(Queue *q) {
    return (q->size == 0);
}

void enqueue(Queue *q, int item) {
    if (isFull(q)) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = item;
    q->size++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    int item = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

void reverseFirstK(Queue *q, int k) {
    if (isEmpty(q) || k <= 0 || k > q->size) return;
    int *stack = (int *)malloc(k * sizeof(int));

    // Push first K elements to stack
    for (int i = 0; i < k; i++) {
        stack[i] = dequeue(q);
    }

    // Enqueue the stack elements back to queue
    for (int i = k - 1; i >= 0; i--) {
        enqueue(q, stack[i]);
    }

    // Move the remaining elements to the back of the queue
    for (int i = 0; i < q->size - k; i++) {
        enqueue(q, dequeue(q));
    }

    free(stack);
}

void printQueue(Queue *q) {
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->arr[(q->front + i) % q->capacity]);
    }
    printf("\n");
}

int main() {
    int n, k;
    printf("Enter number of elements in queue: ");
    scanf("%d", &n);
    printf("Enter value of K: ");
    scanf("%d", &k);
    
    Queue *q = createQueue(n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        enqueue(q, value);
    }

    printf("Original Queue:\n");
    printQueue(q);

    reverseFirstK(q, k);
    printf("Queue after reversing first %d elements:\n", k);
    printQueue(q);

    return 0;
}
