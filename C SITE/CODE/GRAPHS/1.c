// 1. ENTER THE VERTICES AND EDGES AND REPRESENT IN ADJACENCY MATRIX AND PRINT IT.
#include <stdio.h>

#define MAX 100

void createAdjMatrix(int adjMatrix[MAX][MAX], int vertices, int edges)
{
    int i, src, dest;

    // Initialize the matrix to 0
    for (i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the edges (source and destination vertices) one by one:\n");
    for (i = 0; i < edges; i++)
    {
        printf("Edge %d - Enter source and destination: ", i + 1);
        scanf("%d %d", &src, &dest);

        // For an undirected graph, mark both (src, dest) and (dest, src) as 1
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }
}

void printAdjMatrix(int adjMatrix[MAX][MAX], int vertices)
{
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int vertices, edges;
    int adjMatrix[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    createAdjMatrix(adjMatrix, vertices, edges);
    printAdjMatrix(adjMatrix, vertices);

    return 0;
}
