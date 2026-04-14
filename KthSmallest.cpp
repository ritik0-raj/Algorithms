#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;           
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;  
}
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k)
            return arr[pivotIndex];
        else if (pivotIndex > k)
            return quickSelect(arr, low, pivotIndex - 1, k);
        else
            return quickSelect(arr, pivotIndex + 1, high, k);
    }
    return -1; 
}
int kSmallest(int arr[], int n, int k) {
    return quickSelect(arr, 0, n - 1, k - 1); 
}
int main() {
    int arr[] = {19, 11, 42, 34, 22, 72};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout << "K-th smallest element: " << kSmallest(arr, n, k) << endl;
    return 0;
}