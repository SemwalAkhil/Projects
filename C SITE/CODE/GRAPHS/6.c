// 6. TRAVERSE THE ADJACENT LIST WITH BREADTH FIRST SEARCH
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for an adjacency list node
struct Node
{
    int vertex;
    struct Node *next;
};

// Adjacency list
struct AdjList
{
    struct Node *head;
} *adjList[MAX];

int visited[MAX]; // Visited array for BFS
int queue[MAX];
int front = -1, rear = -1;
int vertices;

// Function to create a new node
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge
void addEdge(int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = adjList[src]->head;
    adjList[src]->head = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest]->head;
    adjList[dest]->head = newNode;
}

// Enqueue function for BFS
void enqueue(int vertex)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

// Dequeue function for BFS
int dequeue()
{
    return (front == -1 || front > rear) ? -1 : queue[front++];
}

// BFS traversal
void BFS(int startVertex)
{
    enqueue(startVertex);
    visited[startVertex] = 1;

    printf("BFS Traversal: ");
    while (front <= rear)
    {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        struct Node *temp = adjList[currentVertex]->head;
        while (temp)
        {
            if (!visited[temp->vertex])
            {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Initialize adjacency list and visited array
void initializeGraph()
{
    for (int i = 0; i < vertices; i++)
    {
        adjList[i] = (struct AdjList *)malloc(sizeof(struct AdjList));
        adjList[i]->head = NULL;
        visited[i] = 0;
    }
}

int main()
{
    int edges, src, dest, startVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    initializeGraph();

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Edge %d - Enter source and destination: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &startVertex);

    BFS(startVertex);

    return 0;
}
