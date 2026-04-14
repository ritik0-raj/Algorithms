#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define V 5

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}
int findParent(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = findParent(parent, parent[i]);
    return parent[i];
}
void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}
void kruskalMST(int graph[V][V]) {
    vector<Edge> edges;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    sort(edges.begin(), edges.end(), compare);

    int parent[V], rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    cout << "Edge \tWeight\n";

    int count = 0;
    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;

        int set_u = findParent(parent, u);
        int set_v = findParent(parent, v);

        if (set_u != set_v) {
            cout << u << " - " << v << "\t" << edge.weight << endl;
            unionSet(parent, rank, set_u, set_v);
            count++;
        }

        if (count == V - 1)
            break;
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    kruskalMST(graph);
    return 0;
}