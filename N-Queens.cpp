#include <iostream>
using namespace std;

#define MAX 10

int board[MAX][MAX];
int n;

bool isSafe(int row, int col) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(int col) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solveNQueens(col + 1))
                return true;

            board[i][col] = 0; 
        }
    }
    return false;
}

void printBoard() {
    cout << "Solution:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter value of N: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    if (solveNQueens(0)) {
        printBoard();
    } else {
        cout << "No solution exists.";
    }

    return 0;
}