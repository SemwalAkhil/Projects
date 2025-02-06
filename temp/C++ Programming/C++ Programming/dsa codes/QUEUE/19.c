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

void reverseQueue(Queue *q) {
    if (isEmpty(q)) return;

    int item = dequeue(q);
    reverseQueue(q);
    enqueue(q, item);
}

void printQueue(Queue *q) {
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->arr[(q->front + i) % q->capacity]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements in queue: ");
    scanf("%d", &n);
    
    Queue *q = createQueue(n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        enqueue(q, value);
    }

    printf("Original Queue:\n");
    printQueue(q);

    reverseQueue(q);
    printf("Reversed Queue:\n");
    printQueue(q);

    return 0;
}
