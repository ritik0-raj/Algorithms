#include <iostream>
using namespace std;

#define MAX 10

int graph[MAX][MAX];
int color[MAX];
int n, m;

// Function to check if color can be assigned
bool isSafe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

// Function to solve graph coloring
bool solveColoring(int v) {
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (solveColoring(v + 1))
                return true;

            color[v] = 0; // backtrack
        }
    }
    return false;
}

// Function to print result
void printResult() {
    cout << "Vertex : Color\n";
    for (int i = 0; i < n; i++) {
        cout << i << " : " << color[i] << endl;
    }
}

int main() {

     cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of colors: ";
    cin >> m;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    // initialize colors
    for (int i = 0; i < n; i++)
        color[i] = 0;

    if (solveColoring(0)) {
        cout << "Solution exists!\n";
        printResult();
    } else {
        cout << "No solution exists.";
    }

    return 0;
}