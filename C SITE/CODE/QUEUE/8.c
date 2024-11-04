// 8. IMPLEMENT THE OPERATIONS OF PRIORITY QUEUE IN AN STRING ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#include <string.h>
#define SIZE 5

// Insert a character into the priority queue
int insert(char queue[], int priority[], int *count, char value, int prio)
{
    if (*count == SIZE)
    {
        printf("Queue Full\n");
        return 0;
    }

    // Check if the priority already exists in the queue
    for (int j = 0; j < *count; j++)
    {
        if (priority[j] == prio)
        {
            printf("Priority %d already exists. Choose a different priority.\n", prio);
            return 0;
        }
    }

    // Find the position to insert the new element based on priority
    int i;
    for (i = *count - 1; i >= 0 && priority[i] < prio; i--)
    {
        queue[i + 1] = queue[i];
        priority[i + 1] = priority[i];
    }

    // Insert the new element at the found position
    queue[i + 1] = value;
    priority[i + 1] = prio;
    (*count)++;

    printf("Inserted: %c with priority %d\n", value, prio);
    return 1;
}

// Delete the element with the highest priority from the queue
void delete(char queue[], int priority[], int *count)
{
    if (*count == 0)
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("Deleted: %c with priority %d\n", queue[0], priority[0]);

        // Shift elements to the left after deletion
        for (int i = 0; i < *count - 1; i++)
        {
            queue[i] = queue[i + 1];
            priority[i] = priority[i + 1];
        }
        (*count)--;
    }
}

// Peek at the element with the highest priority
void peek(char queue[], int priority[], int count)
{
    if (count == 0)
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("Peek: %c with priority %d\n", queue[0], priority[0]);
    }
}

// Check if the queue is empty
void isEmpty(int count)
{
    printf(count == 0 ? "Queue is Empty\n" : "Queue is Not Empty\n");
}

// Check if the queue is full
void isFull(int count)
{
    printf(count == SIZE ? "Queue is Full\n" : "Queue is Not Full\n");
}

int main()
{
    char queue[SIZE];
    int priority[SIZE];
    int count = 0;

    int choice, prio;
    char value;

    while (1)
    {
        printf("\n1. INSERT\n2. DELETE\n3. PEEK\n4. ISEMPTY\n5. ISFULL\n6. EXIT\nENTER THE OPERATION: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (count == SIZE)
            {
                printf("Queue Full\n");
                break;
            }
            printf("Enter the character: ");
            scanf(" %c", &value);
            printf("Enter the priority: ");
            scanf("%d", &prio);
            insert(queue, priority, &count, value, prio);
            break;
        case 2:
            delete (queue, priority, &count);
            break;
        case 3:
            peek(queue, priority, count);
            break;
        case 4:
            isEmpty(count);
            break;
        case 5:
            isFull(count);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
}
