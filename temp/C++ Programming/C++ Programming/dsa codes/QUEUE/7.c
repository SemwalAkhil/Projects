// 7. IMPLEMENT THE OPERATIONS OF PRIORITY QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#define size 5
void insert(int queue[size][2], int *front, int *rear, int value, int priority)
{
    if ((*front <= *rear) && (*rear != size))
    {
        queue[(*rear)][0] = value;
        queue[(*rear)][1] = priority;
        int tempData, tempPriority;
        if ((*front < *rear) && (*front != size))
        {
            for (int i = (*rear) - 1; i >= 0; i--)
            {
                if (queue[i][1] > priority)
                {
                    tempData = queue[i + 1][0];
                    tempPriority = queue[i + 1][1];
                    queue[i + 1][0] = queue[(*rear)][0];
                    queue[i + 1][1] = queue[(*rear)][1];
                    queue[(*rear)][0] = tempData;
                    queue[(*rear)][1] = tempPriority;
                    break;
                }
                else if (i == 0)
                {
                }
            }
        }
        (*rear)++;
    }
    else
    {
        printf("Queue Full\n");
    }
}
void delete(int queue[size][2], int *front, int *rear)
{
    if ((*front < *rear) && (*front != size))
    {
        printf("%d\n", queue[(*front)++][0]);
    }
    else
    {
        printf("Queue Empty\n");
    }
}
void peek(int queue[size][2], int *front, int *rear)
{
    if ((*front < *rear) && (*front != size))
    {
        printf("%d\n", queue[*front][0]);
    }
    else
    {
        printf("Queue Empty\n");
    }
}
void isEmpty(int queue[size][2], int *front, int *rear)
{
    if ((*front < *rear) && (*front != size))
    {
        printf("Queue Not Empty\n");
    }
    else
    {
        printf("Queue Empty\n");
    }
}
void isFull(int queue[size][2], int *front, int *rear)
{
    if ((*front <= *rear) && (*rear != size))
    {
        printf("Queue Not Full\n");
    }
    else
    {
        printf("Queue Full\n");
    }
}
int main()
{
    int queue[size][2];
    int value, priority, front = 0, rear = 0, choice;
    while (1)
    {
        printf("\n1.INSERT\n2.DELETE\n3.PEEK\n4.ISEMPTY\n5.ISFULL\n6.EXIT\nENTER THE OPERATION: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER THE VALUE: ");
            scanf("%d", &value);
            printf("ENTER THE PRIORITY (HIGHEST 5 -> LOWEST 1): ");
            scanf("%d", &priority);
            insert(queue, &front, &rear, value, priority);
            break;
        case 2:
            delete (queue, &front, &rear);
            break;
        case 3:
            peek(queue, &front, &rear);
            break;
        case 4:
            isEmpty(queue, &front, &rear);
            break;
        case 5:
            isFull(queue, &front, &rear);
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
}