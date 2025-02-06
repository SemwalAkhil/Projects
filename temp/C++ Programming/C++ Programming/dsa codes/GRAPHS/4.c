#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* head;
} Graph;

void addEdge(Graph* graph, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = graph[u].head;
    graph[u].head = newNode;
}

void DFS(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (Node* temp = graph[vertex].head; temp != NULL; temp = temp->next) {
        if (!visited[temp->vertex]) {
            DFS(graph, temp->vertex, visited);
        }
    }
}

int main() {
    int vertices, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    Graph* graph = (Graph*)malloc(vertices * sizeof(Graph));
    for (int i = 0; i < vertices; i++) {
        graph[i].head = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
        addEdge(graph, v, u); // Uncomment for undirected graph
    }

    bool visited[vertices];
    for (int i = 0; i < vertices; i++) visited[i] = false;

    printf("DFS Traversal starting from vertex 0: ");
    DFS(graph, 0, visited);
    
    return 0;
}
