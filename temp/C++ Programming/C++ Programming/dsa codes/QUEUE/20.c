#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int x, y;
} Point;

int rottenOranges(int grid[MAX][MAX], int n, int m) {
    int time = 0;
    int freshCount = 0;
    Point queue[MAX * MAX];
    int front = 0, rear = 0;

    // Count fresh oranges and add rotten oranges to the queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                freshCount++;
            } else if (grid[i][j] == 2) {
                queue[rear++] = (Point){i, j}; // Store the position of rotten oranges
            }
        }
    }

    // Directions for up, down, left, right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (front < rear) {
        int currentSize = rear - front;
        for (int i = 0; i < currentSize; i++) {
            Point point = queue[front++];
            for (int j = 0; j < 4; j++) {
                int newX = point.x + directions[j][0];
                int newY = point.y + directions[j][1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; // Rotten the fresh orange
                    queue[rear++] = (Point){newX, newY}; // Add to queue
                    freshCount--;
                }
            }
        }
        if (freshCount > 0) {
            time++; // Increment time after processing one level of rotten oranges
        }
    }

    return freshCount == 0 ? time : -1; // If no fresh oranges left, return time, otherwise return -1
}

int main() {
    int n, m;
    printf("Enter dimensions of grid (n m): ");
    scanf("%d %d", &n, &m);
    
    int grid[MAX][MAX];
    printf("Enter the grid (%d x %d), use 0 for empty cell, 1 for fresh orange, 2 for rotten orange:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = rottenOranges(grid, n, m);
    printf("Time until all oranges are rotten: %d\n", result); // Output

    return 0;
}
