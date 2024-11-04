// 20. Rotten Oranges
/*
Explanation -

    Given a grid of dimension nxm where each cell in the grid can have values 0,
    1 or 2 which has the following meaning : 0 : Empty cell 1 : Cells have fresh oranges 2 : Cells have rotten oranges We have to determine what is the earliest time after which all the oranges are rotten.A rotten orange at index[i, j] can rot other fresh orange at indexes[i - 1, j], [ i + 1, j ], [ i, j - 1 ], [ i, j + 1 ](up, down, left and right) in unit time.
    Example 1 :
    Input : grid = {{0, 1, 2}, {0, 1, 2}, {2, 1, 1}}
    Output : 1
    Explanation : The grid is - 0 1 2 0 1 2 2 1 1 Oranges at positions(0, 2), (1, 2), (2, 0)will rot oranges at(0, 1), (1, 1), (2, 2) and (2, 1) in unit time.
    Example 2 :
    Input : grid = {{2, 2, 0, 1}}
    Output : -1
    Explanation : The grid is - 2 2 0 1 Oranges at(0, 0) and (0, 1) can't rot orange at (0,3).
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct
{
    int x[MAX * MAX];
    int y[MAX * MAX];
    int front;
    int rear;
} Queue;

// Function to create a queue
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    return q;
}

// Function to enqueue
void enqueue(Queue *q, int x, int y)
{
    q->x[q->rear] = x;
    q->y[q->rear] = y;
    q->rear++;
}

// Function to dequeue
void dequeue(Queue *q, int *x, int *y)
{
    *x = q->x[q->front];
    *y = q->y[q->front];
    q->front++;
}

// Function to check if the queue is empty
int isEmpty(Queue *q)
{
    return q->front == q->rear;
}

// Function to find the earliest time after which all oranges are rotten
int orangesRotting(int grid[MAX][MAX], int n, int m)
{
    Queue *q = createQueue();
    int freshOranges = 0;
    int time = -1;

    // Initialize the queue with all rotten oranges and count fresh oranges
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                enqueue(q, i, j);
            }
            else if (grid[i][j] == 1)
            {
                freshOranges++;
            }
        }
    }

    // Directions for up, down, left, and right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Perform BFS
    while (!isEmpty(q))
    {
        int size = q->rear - q->front; // Number of elements at the current time unit
        time++;                        // Increase time for each level of BFS

        for (int i = 0; i < size; i++)
        {
            int x, y;
            dequeue(q, &x, &y);

            // Check all four directions
            for (int d = 0; d < 4; d++)
            {
                int newX = x + directions[d][0];
                int newY = y + directions[d][1];

                // Check boundaries and if the cell is a fresh orange
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;   // Rot the orange
                    freshOranges--;         // Decrease the count of fresh oranges
                    enqueue(q, newX, newY); // Enqueue the newly rotten orange
                }
            }
        }
    }

    // If there are still fresh oranges left, return -1
    return freshOranges == 0 ? time : -1;
}

int main()
{
    int grid[MAX][MAX];
    int n, m;

    printf("Enter dimensions of grid (n m): ");
    scanf("%d %d", &n, &m);

    printf("Enter the grid values (0 for empty, 1 for fresh orange, 2 for rotten orange):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, n, m);
    printf("The earliest time after which all oranges are rotten: %d\n", result);

    return 0;
}
