#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    srand(time(nullptr));
    int numbers[10000];
    for (int arraySize = 1000; arraySize <= 10000; arraySize += 1000) {
        long long totalTime = 0;
        for (int test = 0; test < 100; test++) {
            for (int i = 0; i < arraySize; i++) {
                numbers[i] = rand();
            }
            int target = rand();
            auto startTime = high_resolution_clock::now();

            for (int i = 0; i < arraySize; i++) {
                if (numbers[i] == target) {
                    break;
                }
            }
            auto endTime = high_resolution_clock::now();
            totalTime += duration_cast<nanoseconds>(endTime - startTime).count();
        }
        cout << "Average time for array size " << arraySize << " = " << totalTime / 100 << " nanoseconds" << endl;
    }

    return 0;
}
