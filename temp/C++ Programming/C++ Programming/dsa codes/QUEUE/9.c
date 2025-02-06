#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear, size;
} Deque;

void initialize(Deque *dq) {
    dq->front = -1;
    dq->rear = 0;
    dq->size = 0;
}

int isEmpty(Deque *dq) {
    return dq->size == 0;
}

int isFull(Deque *dq) {
    return dq->size == MAX;
}

void insertFront(Deque *dq, int item) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    dq->front = (dq->front + 1) % MAX;
    dq->data[dq->front] = item;
    dq->size++;
}

void insertRear(Deque *dq, int item) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->data[dq->rear] = item;
    dq->size++;
}

void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->size--;
}

void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    dq->rear = (dq->rear + 1) % MAX;
    dq->size--;
}

int peekFront(Deque *dq) {
    if (isEmpty(dq)) {
        return -1;
    }
    return dq->data[dq->front];
}

int peekRear(Deque *dq) {
    if (isEmpty(dq)) {
        return -1;
    }
    return dq->data[(dq->rear + 1) % MAX];
}

int main() {
    Deque dq;
    initialize(&dq);
    
    int input;
    printf("Enter integers to insert at rear (type -1 to stop):\n");
    while (1) {
        scanf("%d", &input);
        if (input == -1) break;
        insertRear(&dq, input);
    }

    printf("Front element: %d\n", peekFront(&dq));
    printf("Rear element: %d\n", peekRear(&dq));
    deleteFront(&dq);
    printf("Front element after deletion: %d\n", peekFront(&dq));
    return 0;
}
