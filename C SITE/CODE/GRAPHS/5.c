// 5. TRAVERSE THE ADJACENT MATRIX WITH BREADTH FIRST SEARCH
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX]; // Adjacency matrix
int visited[MAX];        // Visited array to keep track of visited nodes
int queue[MAX];          // Queue for BFS traversal
int front = -1, rear = -1;
int vertices;

// Function to add an element to the queue
void enqueue(int vertex)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

// Function to remove an element from the queue
int dequeue()
{
    if (front == -1 || front > rear)
    {
        return -1;
    }
    else
    {
        return queue[front++];
    }
}

// Function to perform BFS traversal
void BFS(int startVertex)
{
    enqueue(startVertex);
    visited[startVertex] = 1;

    printf("BFS Traversal starting from vertex %d:\n", startVertex);

    while (front <= rear)
    {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        // Visit all adjacent vertices
        for (int i = 0; i < vertices; i++)
        {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Function to create the adjacency matrix
void createAdjMatrix(int edges)
{
    int src, dest;

    // Initialize the matrix to 0
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the edges (source and destination vertices) one by one:\n");
    for (int i = 0; i < edges; i++)
    {
        printf("Edge %d - Enter source and destination: ", i + 1);
        scanf("%d %d", &src, &dest);

        // For an undirected graph, mark both (src, dest) and (dest, src) as 1
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }
}

// Function to initialize the visited array
void initializeVisited()
{
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }
}

int main()
{
    int edges, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    createAdjMatrix(edges);

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    initializeVisited(); // Initialize all vertices as unvisited

    BFS(startVertex);

    return 0;
}
