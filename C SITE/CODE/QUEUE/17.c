// 17. Queue based approach for first non-repeating character in a stream
/*
Explanation -

    Given a stream of characters and we have to find first non repeating character each time a character is inserted to the stream.
    Examples :
    Input : a a b c
    Output : a - 1 b b
    Input : a a c
    Output : a - 1 c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

// Queue structure
typedef struct
{
    char *data;
    int front;
    int rear;
    int capacity;
} Queue;

// Function to create a queue
Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->data = (char *)malloc(capacity * sizeof(char));
    return queue;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue *queue)
{
    return queue->front > queue->rear;
}

// Function to enqueue an element
void enqueue(Queue *queue, char value)
{
    queue->data[++queue->rear] = value;
}

// Function to dequeue an element
char dequeue(Queue *queue)
{
    return queue->data[queue->front++];
}

// Function to find the first non-repeating character in the stream
void firstNonRepeatingCharacter(char *stream)
{
    int frequency[MAX_CHAR] = {0}; // Array to store frequency of characters
    int i = 0;

    Queue *queue = createQueue(strlen(stream)); // Create a queue to store characters

    while (stream[i] != '\0')
    {
        char current = stream[i];
        frequency[current]++;    // Update frequency
        enqueue(queue, current); // Add character to queue

        // Check the front of the queue for non-repeating character
        while (!isQueueEmpty(queue) && frequency[queue->data[queue->front]] > 1)
        {
            dequeue(queue); // Remove non-repeating characters from the front
        }

        // Output the first non-repeating character
        if (isQueueEmpty(queue))
        {
            printf("-1 ");
        }
        else
        {
            printf("%c ", queue->data[queue->front]);
        }
        i++;
    }

    // Free allocated memory
    free(queue->data);
    free(queue);
}

int main()
{
    char stream[100];
    printf("Enter the character stream: ");
    scanf("%s", stream);

    firstNonRepeatingCharacter(stream);
    printf("\n");

    return 0;
}
