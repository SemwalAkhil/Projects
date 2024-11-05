// TRAVERSE THE ADJACENT LIST WITH BREADTH FIRST SEARCH

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int vertices;            // Number of vertices
    list<int>* adjList;      // Pointer to an array containing adjacency lists

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int V) {
        vertices = V;
        adjList = new list<int>[V];
    }

    // Destructor to free dynamically allocated memory
    ~Graph() {
        delete[] adjList;
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest); // Add dest to src's list
        adjList[dest].push_back(src); // Add src to dest's list (for undirected graph)
    }

    // BFS traversal function
    void BFS(int startVertex) {
        bool* visited = new bool[vertices]; // Array to keep track of visited vertices
        for (int i = 0; i < vertices; i++) {
            visited[i] = false; // Initialize all vertices as not visited
        }

        queue<int> q;             // Queue for BFS
        visited[startVertex] = true; // Mark the start vertex as visited
        q.push(startVertex);         // Enqueue the start vertex

        while (!q.empty()) {
            int v = q.front();       // Get the front vertex from the queue
            cout << v << " ";        // Process the vertex
            q.pop();                 // Dequeue the front vertex

            // Get all adjacent vertices of the dequeued vertex
            for (int adjVertex : adjList[v]) {
                if (!visited[adjVertex]) { // If the vertex has not been visited
                    visited[adjVertex] = true; // Mark it as visited
                    q.push(adjVertex);        // Enqueue the vertex
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
