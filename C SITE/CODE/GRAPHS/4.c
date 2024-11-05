// 4. TRAVERSE THE ADJACENT LIST WITH DEPTH FIRST SEARCH
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an adjacency list node
struct Node
{
    int vertex;
    struct Node *next;
};

// Structure to represent an adjacency list
struct AdjList
{
    struct Node *head;
};

struct AdjList *adjList[MAX];
int visited[MAX]; // Visited array to keep track of visited nodes
int vertices;

// Function to create a new adjacency list node
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to an undirected graph
void addEdge(int src, int dest)
{
    // Add edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = adjList[src]->head;
    adjList[src]->head = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = adjList[dest]->head;
    adjList[dest]->head = newNode;
}

// Function to perform DFS traversal
void DFS(int v)
{
    printf("%d ", v); // Visit the current vertex
    visited[v] = 1;   // Mark the current vertex as visited

    struct Node *temp = adjList[v]->head;
    while (temp != NULL)
    {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
        {
            DFS(adjVertex);
        }
        temp = temp->next;
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

// Function to create the adjacency list
void createAdjList(int edges)
{
    int src, dest;

    for (int i = 0; i < vertices; i++)
    {
        adjList[i] = (struct AdjList *)malloc(sizeof(struct AdjList));
        adjList[i]->head = NULL;
    }

    printf("Enter the edges (source and destination vertices) one by one:\n");
    for (int i = 0; i < edges; i++)
    {
        printf("Edge %d - Enter source and destination: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }
}

int main()
{
    int edges, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    createAdjList(edges);

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    initializeVisited(); // Initialize all vertices as unvisited

    printf("DFS Traversal starting from vertex %d:\n", startVertex);
    DFS(startVertex);

    return 0;
}
