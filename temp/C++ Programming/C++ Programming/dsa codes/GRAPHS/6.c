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

void BFS(Graph* graph, int vertices, int start) {
    bool visited[vertices];
    for (int i = 0; i < vertices; i++) visited[i] = false;

    int queue[vertices], front = 0, rear = -1;
    visited[start] = true;
    queue[++rear] = start;

    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (Node* temp = graph[current].head; temp != NULL; temp = temp->next) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = true;
                queue[++rear] = temp->vertex;
            }
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

    printf("BFS Traversal starting from vertex 0: ");
    BFS(graph, vertices, 0);
    
    return 0;
}
