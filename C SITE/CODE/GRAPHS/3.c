// 3. TRAVERSE THE ADJACENT MATRIX WITH DEPTH FIRST SEARCH
#include <stdio.h>

#define MAX 100

int adjMatrix[MAX][MAX]; // Adjacency matrix
int visited[MAX];        // Visited array to keep track of visited nodes
int vertices;

// Function to perform DFS traversal
void DFS(int v)
{
    printf("%d ", v); // Visit the current vertex
    visited[v] = 1;   // Mark the current vertex as visited

    for (int i = 0; i < vertices; i++)
    {
        // If there is an edge from v to i and i is not visited, do DFS on i
        if (adjMatrix[v][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
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

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    initializeVisited(); // Initialize all vertices as unvisited

    printf("DFS Traversal starting from vertex %d:\n", startVertex);
    DFS(startVertex);

    return 0;
}
