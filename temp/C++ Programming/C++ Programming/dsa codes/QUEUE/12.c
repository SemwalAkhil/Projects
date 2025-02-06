#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
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

void insert(PriorityQueue *pq, char *str) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, str);
    newNode->next = NULL;

    if (isEmpty(pq) || strcmp(pq->front->data, str) > 0) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        Node *current = pq->front;
        while (current->next != NULL && strcmp(current->next->data, str) <= 0) {
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

char* peek(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        return NULL;
    }
    return pq->front->data;
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
