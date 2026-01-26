#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void BS(int arr[], int n, int index) {
    if (index == n - 1)
        return;
    for (int i = 0; i < n - index - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    BS(arr, n, index + 1);
}

long long measureTime(int size) {
    long long total = 0;
    for (int t = 0; t < 100; t++) {
        int* arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 10000;
        }
        auto start = high_resolution_clock::now();
        BS(arr, size, 0);
        auto end = high_resolution_clock::now();
        long long duration = duration_cast<nanoseconds>(end - start).count();
        total += duration;
        delete[] arr;
    }
    return total / 100;
}

int main() {
    cout << "Array Size\tAverage Time (nanoseconds)\n";
    cout << "-----------------------------------------\n";
    for (int size = 1000; size <= 10000; size += 1000) {
        long long avgTime = measureTime(size);
        cout << size << "\t\t" << avgTime << " ns\n";
    }
    return 0;
}
