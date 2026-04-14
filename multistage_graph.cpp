#include <iostream>
#include <climits>
using namespace std;

void shortestPathMultistage(int V, int graph[][101], int start, int end) {
    int cost[101], nextVertex[101];

    for (int i = 1; i <= V; i++) {
        cost[i] = INT_MAX;
        nextVertex[i] = -1;
    }
    cost[end] = 0;

    for (int i = V; i >= 1; i--) {
        int minCost = INT_MAX, next = -1;
        for (int j = i + 1; j <= V; j++) {
            if (graph[i][j] != 0 && cost[j] != INT_MAX && graph[i][j] + cost[j] < minCost) {
                minCost = graph[i][j] + cost[j];
                next = j;
            }
        }
        if (minCost != INT_MAX) { // Only update if a valid path exists
            cost[i] = minCost;
            nextVertex[i] = next;
        }
    }

    if (cost[start] == INT_MAX) {
        cout << "\nNo path from " << start << " to " << end << endl;
        return;
    }

    int v = start;
    cout << "\nShortest Path: ";
    while (v != -1) {
        cout << v;
        if (nextVertex[v] != -1) cout << " -> ";
        v = nextVertex[v];
    }
    cout << "\nMinimum Cost: " << cost[start] << endl;
}

int main() {
    int V, start, end, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter start vertex and end vertex: ";
    cin >> start >> end;
    cout << "Enter number of edges: ";
    cin >> E;

    int graph[101][101] = {0};
    cout << "Enter edges (from, to, weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    shortestPathMultistage(V, graph, start, end);
    return 0;
}