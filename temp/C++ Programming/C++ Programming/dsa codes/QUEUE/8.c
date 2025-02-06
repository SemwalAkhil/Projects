#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX][100];
    int size;
} PriorityQueue;

void initialize(PriorityQueue *pq) {
    pq->size = 0;
}

int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

int isFull(PriorityQueue *pq) {
    return pq->size == MAX;
}

void insert(PriorityQueue *pq, char *str) {
    if (isFull(pq)) {
        printf("Queue is full\n");
        return;
    }
    strcpy(pq->data[pq->size++], str);
}

void delete(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty\n");
        return;
    }
    // Simple deletion (FIFO)
    for (int i = 0; i < pq->size - 1; i++) {
        strcpy(pq->data[i], pq->data[i + 1]);
    }
    pq->size--;
}

char* peek(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        return NULL;
    }
    return pq->data[0]; // Return the first element
}

int main() {
    PriorityQueue pq;
    initialize(&pq);
    
    char input[100];
    printf("Enter strings to insert (type 'exit' to stop):\n");
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) break;
        insert(&pq, input);
    }

    printf("First element: %s\n", peek(&pq));
    delete(&pq);
    printf("First element after deletion: %s\n", peek(&pq));
    return 0;
}
