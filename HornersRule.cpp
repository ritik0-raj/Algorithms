#include <iostream>
using namespace std;

int HR(int a[], int n, int x, int index) {
    if (index == n - 1)
        return a[index];

    return a[index] + x * HR(a, n, x, index + 1);
}

int main() {
    int a[] = {2, 8, 4, -3};
    int n = 4;
    int x = 3;

    int result = HR(a, n, x, 0);

    cout << "Result: " << result;

    return 0;
}
