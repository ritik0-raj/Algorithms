#include <iostream>
using namespace std;

#define MAX 10
#define INF 99999

int graph[MAX][MAX];
bool visited[MAX];
int n;
int minCost = INF;

void tsp(int curr, int count, int cost) {

    if (count == n && graph[curr][0]) {
        if (cost + graph[curr][0] < minCost)
            minCost = cost + graph[curr][0];
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[curr][i]) {
            visited[i] = true;

            tsp(i, count + 1, cost + graph[curr][i]);

            visited[i] = false;
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = false;

    visited[0] = true; // start from city 0

    tsp(0, 1, 0);

    cout << "Minimum Travelling Cost = " << minCost;

    return 0;
}