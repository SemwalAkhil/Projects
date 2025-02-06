#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX][100];
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

void insertFront(Deque *dq, char *str) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    dq->front = (dq->front + 1) % MAX;
    strcpy(dq->data[dq->front], str);
    dq->size++;
}

void insertRear(Deque *dq, char *str) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    strcpy(dq->data[dq->rear], str);
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

char* peekFront(Deque *dq) {
    if (isEmpty(dq)) {
        return NULL;
    }
    return dq->data[dq->front];
}

char* peekRear(Deque *dq) {
    if (isEmpty(dq)) {
        return NULL;
    }
    return dq->data[(dq->rear + 1) % MAX];
}

int main() {
    Deque dq;
    initialize(&dq);
    
    char input[100];
    printf("Enter strings to insert at rear (type 'exit' to stop):\n");
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) break;
        insertRear(&dq, input);
    }

    printf("Front element: %s\n", peekFront(&dq));
    printf("Rear element: %s\n", peekRear(&dq));
    deleteFront(&dq);
    printf("Front element after deletion: %s\n", peekFront(&dq));
    return 0;
}
