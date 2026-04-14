#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void recursiveInsertionSort(int arr[],int n){
    if(n<=1)return;
    recursiveInsertionSort(arr,n-1);
    int last=arr[n-1];
    int j=n-2;
    while(j>=0&&arr[j]>last){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=last;
}

void fillArray(int arr[],int n){
    for(int i=0;i<n;i++)arr[i]=rand()%100000;
}

int main(){
    const int repetitions=100;
    cout<<"InputSize\tAverageTime(ns)"<<endl;
    for(int n=1000;n<=20000;n+=1000){
        long long totalTime=0;
        for(int i=0;i<repetitions;i++){
            int* arr=new int[n];
            fillArray(arr,n);
            auto start=high_resolution_clock::now();
            recursiveInsertionSort(arr,n);
            auto stop=high_resolution_clock::now();
            totalTime+=duration_cast<nanoseconds>(stop-start).count();
            delete[] arr;
        }
        cout<<n<<"\t\t"<<totalTime/repetitions<<endl;
    }
    return 0;
}
