// TRAVERSE THE ADJACENT LIST WITH DEPTH FIRST SEARCH

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int vertices;           // Number of vertices
    list<int>* adjList;     // Pointer to an array containing adjacency lists

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

    // Utility function for DFS traversal
    void DFSUtil(int v, bool visited[]) {
        // Mark the current node as visited and print it
        visited[v] = true;
        cout << v << " ";

        // Recur for all vertices adjacent to this vertex
        for (int adjVertex : adjList[v]) {
            if (!visited[adjVertex]) {
                DFSUtil(adjVertex, visited);
            }
        }
    }

    // DFS traversal function
    void DFS(int startVertex) {
        // Mark all vertices as not visited
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }

        // Call the recursive helper function to print DFS traversal
        DFSUtil(startVertex, visited);

        // Clean up memory
        delete[] visited;
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
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "\nDFS Traversal starting from vertex " << startVertex << ": ";
    graph.DFS(startVertex);

    return 0;
}
