// 2. CREATE THE GRAPH AS A ADJACENCY LIST WITH OPERATIONS SUCH AS INSERTION, DELETION
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for an adjacency list node
struct Node
{
    int dest;
    struct Node *next;
};

// Structure for an adjacency list
struct AdjList
{
    struct Node *head;
};

// Structure for the graph
struct Graph
{
    int vertices;
    struct AdjList *array;
};

// Function to create a new adjacency list node
struct Node *createNode(int dest)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct AdjList *)malloc(vertices * sizeof(struct AdjList));

    for (int i = 0; i < vertices; i++)
        graph->array[i].head = NULL;

    return graph;
}

// Function to insert an edge into the graph
void insertEdge(struct Graph *graph, int src, int dest)
{
    // Add an edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // For undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to delete an edge from the graph
void deleteEdge(struct Graph *graph, int src, int dest)
{
    struct Node *temp = graph->array[src].head, *prev = NULL;

    // If the head node itself holds the destination to delete
    if (temp != NULL && temp->dest == dest)
    {
        graph->array[src].head = temp->next;
        free(temp);
    }
    else
    {
        // Search for the node to be deleted
        while (temp != NULL && temp->dest != dest)
        {
            prev = temp;
            temp = temp->next;
        }
        // Unlink the node from the linked list
        if (temp != NULL)
        {
            prev->next = temp->next;
            free(temp);
        }
    }

    // Repeat for the undirected edge in the opposite direction
    temp = graph->array[dest].head;
    prev = NULL;
    if (temp != NULL && temp->dest == src)
    {
        graph->array[dest].head = temp->next;
        free(temp);
    }
    else
    {
        while (temp != NULL && temp->dest != src)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            prev->next = temp->next;
            free(temp);
        }
    }
}

// Function to print the adjacency list of the graph
void printGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->vertices; v++)
    {
        struct Node *temp = graph->array[v].head;
        printf("Vertex %d: ", v);
        while (temp)
        {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the memory allocated to the graph
void freeGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->vertices; v++)
    {
        struct Node *temp = graph->array[v].head;
        while (temp != NULL)
        {
            struct Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->array);
    free(graph);
}

int main()
{
    int vertices, edges, src, dest, choice;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph *graph = createGraph(vertices);

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Display Graph\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter source and destination of the edge to insert: ");
            scanf("%d %d", &src, &dest);
            insertEdge(graph, src, dest);
            printf("Edge inserted successfully.\n");
            break;
        case 2:
            printf("Enter source and destination of the edge to delete: ");
            scanf("%d %d", &src, &dest);
            deleteEdge(graph, src, dest);
            printf("Edge deleted successfully.\n");
            break;
        case 3:
            printf("Adjacency List Representation of the Graph:\n");
            printGraph(graph);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeGraph(graph);
    return 0;
}
