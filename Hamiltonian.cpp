#include <iostream>
using namespace std;

#define MAX 10

int graph[MAX][MAX];
int path[MAX];
int n;

// Check if vertex v can be added
bool isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }

    return true;
}

// Backtracking function
bool solveHamiltonian(int pos) {
    if (pos == n) {
        return (graph[path[pos - 1]][path[0]] == 1);
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;

            if (solveHamiltonian(pos + 1))
                return true;

            path[pos] = -1; // backtrack
        }
    }
    return false;
}

// Print cycle
void printCycle() {
    cout << "Hamiltonian Cycle:\n";
    for (int i = 0; i < n; i++) {
        cout << path[i] << " ";
    }
    cout << path[0];
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Initialize path
    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0; // start from vertex 0

    if (solveHamiltonian(1)) {
        printCycle();
    } else {
        cout << "No Hamiltonian Cycle exists.";
    }

    return 0;
}