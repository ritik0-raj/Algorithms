#include <iostream>
using namespace std;

#define MAX 20

int setArr[MAX], n, target;

void printSubset(int sol[], int size) {
    cout << "Subset found: ";
    for (int i = 0; i < size; i++) {
        cout << sol[i] << " ";
    }
    cout << endl;
}

void subsetSum(int index, int sol[], int solSize, int sum) {
    if (sum == target) {
        printSubset(sol, solSize);
        return;
    }

    if (index == n || sum > target)
        return;

    sol[solSize] = setArr[index];
    subsetSum(index + 1, sol, solSize + 1, sum + setArr[index]);

    subsetSum(index + 1, sol, solSize, sum);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> setArr[i];

    cout << "Enter target sum: ";
    cin >> target;

    int sol[MAX];

    cout << "\nAll subsets with sum " << target << ":\n";
    subsetSum(0, sol, 0, 0);

    return 0;
}