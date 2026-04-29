#include <iostream>
using namespace std;

#define V 5 

int findMin(int dist[], bool visited[]) {
    int min = INT_MAX, index;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[V][V], int source) {
    int dist[V];        // stores shortest distance
    bool visited[V];    // visited array

    // Initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    // Find shortest path
    for (int count = 0; count < V - 1; count++) {
        int u = findMin(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            // Update distance
            if (!visited[v] && graph[u][v] && 
                dist[u] != INT_MAX && 
                dist[u] + graph[u][v] < dist[v]) {
                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "        " << dist[i] << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {10, 0, 1, 0, 3},
        {0, 1, 0, 4, 9},
        {0, 0, 4, 0, 2},
        {5, 3, 9, 2, 0}
    };

    dijkstra(graph, 0);

    return 0;
}