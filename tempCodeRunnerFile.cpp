#include <iostream>
#include <climits>
using namespace std;

#define V 7   // Number of vertices (A, B, C, D, E, F, G)

// Find vertex with minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Print MST and total cost
void printMST(int parent[], int graph[V][V]) {
    int totalCost = 0;

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << char(parent[i] + 'A') << " - " << char(i + 'A')
             << "\t" << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }

    cout << "\nTotal Minimum Cost = " << totalCost << endl;
}

// Prim’s Algorithm
void primMST(int graph[V][V]) {
    int parent[V];   // Stores MST
    int key[V];      // Minimum weights
    bool mstSet[V];  // Included in MST

    // Initialize
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;      // Start from vertex A
    parent[0] = -1;

    // Build MST
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

// Driver
int main() {
    // Example graph (you should adjust weights as per your image)
    int graph[V][V] = {
        //A  B  C  D  E  F  G
        {0, 0, 0, 4, 0, 0, 3}, // A
        {0, 0, 2, 0, 0, 0, 4}, // B
        {0, 2, 0, 0, 2, 5, 1}, // C
        {4, 0, 0, 0, 0, 2, 0}, // D
        {0, 0, 2, 0, 0, 4, 0}, // E
        {0, 0, 5, 2, 4, 0, 0}, // F
        {3, 4, 1, 0, 0, 0, 0}  // G
    };

    primMST(graph);

    return 0;
}