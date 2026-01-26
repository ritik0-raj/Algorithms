#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long power(long long a, int n) {
    if (n == 0)
        return 1;
    return a * power(a, n - 1);
}

int main() {
    cout<< power(2,5);
    const int repetitions = 100;
    cout << "InputSize\tAverageTime(ns)" << endl;
    for (int n = 1000; n <= 20000; n += 1000) {
        long long totalTime = 0;
        for (int i = 0; i < repetitions; i++) {
            auto start = high_resolution_clock::now();
            power(2, n);
            auto stop = high_resolution_clock::now();
            totalTime += duration_cast<nanoseconds>(stop - start).count();
        }
        long long averageTime = totalTime / repetitions;
        cout << n << "\t\t" << averageTime << endl;
    }

    return 0;
}
