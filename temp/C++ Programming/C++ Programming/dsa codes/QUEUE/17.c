#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct {
    char data[MAX];
    int front, rear;
} Queue;

void initialize(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue *q, char c) {
    q->data[q->rear++] = c;
}

char dequeue(Queue *q) {
    return q->data[q->front++];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

char front(Queue *q) {
    return q->data[q->front];
}

int main() {
    char stream[] = "geeksforgeeks";
    int charCount[MAX] = {0};
    Queue q;
    initialize(&q);

    for (int i = 0; i < strlen(stream); i++) {
        char current = stream[i];
        charCount[current]++;

        if (charCount[current] == 1) {
            enqueue(&q, current);
        }

        while (!isEmpty(&q) && charCount[front(&q)] > 1) {
            dequeue(&q);
        }

        if (isEmpty(&q)) {
            printf("-1 ");
        } else {
            printf("%c ", front(&q));
        }
    }
    printf("\n");
    return 0;
}
