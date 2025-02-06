#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    int size;
} PriorityQueue;

void initialize(PriorityQueue *pq) {
    pq->front = NULL;
    pq->size = 0;
}

int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

void insert(PriorityQueue *pq, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(pq) || pq->front->data > value) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        Node *current = pq->front;
        while (current->next != NULL && current->next->data <= value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    pq->size++;
}

void delete(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = pq->front;
    pq->front = pq->front->next;
    free(temp);
    pq->size--;
}

int peek(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        return -1;
    }
    return pq->front->data;
}

int main() {
    PriorityQueue pq;
    initialize(&pq);
    
    int input;
    printf("Enter integers to insert (type -1 to stop):\n");
    while (1) {
        scanf("%d", &input);
        if (input == -1) break;
        insert(&pq, input);
    }

    printf("First element: %d\n", peek(&pq));
    delete(&pq);
    printf("First element after deletion: %d\n", peek(&pq));
    return 0;
}
