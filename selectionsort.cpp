#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void SS(int arr[],int n,int index){
    if(index==n-1)return;
    int minIndex=index;
    for(int i=index+1;i<n;i++){
        if(arr[i]<arr[minIndex])minIndex=i;
    }
    swap(arr[index],arr[minIndex]);
    SS(arr,n,index+1);
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
            SS(arr,n,0);
            auto stop=high_resolution_clock::now();
            totalTime+=duration_cast<nanoseconds>(stop-start).count();
            delete[] arr;
        }
        cout<<n<<"\t\t"<<totalTime/repetitions<<endl;
    }
    return 0;
}
