// TRAVERSE THE ADJACENT MATRIX WITH BREADTH FIRST SEARCH

#include <iostream>
#include <queue>
using namespace std;

class Graph {
    int vertices;         // Number of vertices
    int** adjMatrix;      // Adjacency matrix

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int V) {
        vertices = V;
        adjMatrix = new int*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0; // Initialize all entries to 0
            }
        }
    }

    // Destructor to free dynamically allocated memory
    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    // Function to add an edge between source and destination
    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // For undirected graph
    }

    // BFS traversal function
    void BFS(int startVertex) {
        bool* visited = new bool[vertices]; // Array to keep track of visited vertices
        for (int i = 0; i < vertices; i++) {
            visited[i] = false; // Initialize all vertices as not visited
        }

        queue<int> q;          // Queue for BFS
        visited[startVertex] = true; // Mark the start vertex as visited
        q.push(startVertex);    // Enqueue the start vertex

        while (!q.empty()) {
            int v = q.front();  // Get the front vertex from the queue
            cout << v << " ";   // Process the vertex
            q.pop();            // Dequeue the front vertex

            // Get all adjacent vertices of the dequeued vertex
            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[v][i] == 1 && !visited[i]) { // If the vertex is connected and not visited
                    visited[i] = true; // Mark it as visited
                    q.push(i);         // Enqueue the vertex
                }
            }
        }

        delete[] visited; // Clean up memory
    }
};

int main() {
    int V, E;
    
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph graph(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter edges (source and destination):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "\nBFS Traversal starting from vertex " << startVertex << ": ";
    graph.BFS(startVertex);

    return 0;
}
