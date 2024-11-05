/*
Rotten Oranges

Explanation -

Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning: 0 : Empty cell 1 : Cells have fresh oranges 2 : Cells have rotten oranges We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. Example 1: Input: grid = {{0,1,2},{0,1,2},{2,1,1}} Output: 1 Explanation: The grid is- 0 1 2 0 1 2 2 1 1 Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time. Example 2: Input: grid = {{2,2,0,1}} Output: -1 Explanation: The grid is- 2 2 0 1 Oranges at (0,0) and (0,1) can't rot orange at (0,3).
*/

#include <iostream>
#include <climits>

const int MAX = 100;
int grid[MAX][MAX];  // Fixed-size array for the grid

// Arrays to simulate a queue for BFS
int rowQueue[MAX * MAX];
int colQueue[MAX * MAX];
int front = 0, rear = 0; // Pointers to simulate queue operations

// Directions for adjacent cells (up, down, left, right)
int rowDir[] = {-1, 1, 0, 0};
int colDir[] = {0, 0, -1, 1};

void enqueue(int x, int y) {
    rowQueue[rear] = x;
    colQueue[rear] = y;
    rear++;
}

void dequeue(int &x, int &y) {
    x = rowQueue[front];
    y = colQueue[front];
    front++;
}

bool isQueueEmpty() {
    return front == rear;
}

int minTimeToRotOranges(int n, int m) {
    int freshOranges = 0;
    
    // Initialize the queue with all initially rotten oranges and count fresh oranges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                enqueue(i, j);
            } else if (grid[i][j] == 1) {
                freshOranges++;
            }
        }
    }

    // If there are no fresh oranges initially, return 0
    if (freshOranges == 0) return 0;

    int minutes = 0;

    // Perform BFS to rot adjacent fresh oranges
    while (!isQueueEmpty()) {
        int size = rear - front;
        bool anyRotten = false;

        for (int i = 0; i < size; i++) {
            int x, y;
            dequeue(x, y);

            // Process all 4 adjacent cells
            for (int d = 0; d < 4; d++) {
                int nx = x + rowDir[d];
                int ny = y + colDir[d];

                // Check if the adjacent cell is within bounds and is a fresh orange
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;   // Make the orange rotten
                    enqueue(nx, ny);    // Add the newly rotten orange to the queue
                    freshOranges--;     // Decrease count of fresh oranges
                    anyRotten = true;
                }
            }
        }

        // Increment time if at least one orange was rotten in this round
        if (anyRotten) minutes++;
    }

    // If there are still fresh oranges left, return -1 (not all oranges can rot)
    return (freshOranges == 0) ? minutes : -1;
}

int main() {
    int n, m;
    std::cout << "Enter the dimensions of the grid (n m): ";
    std::cin >> n >> m;

    std::cout << "Enter the grid values (0 for empty, 1 for fresh, 2 for rotten):" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
        }
    }

    int result = minTimeToRotOranges(n, m);
    if (result == -1) {
        std::cout << "Not all oranges can rot." << std::endl;
    } else {
        std::cout << "Minimum time to rot all oranges: " << result << std::endl;
    }

    return 0;
}
