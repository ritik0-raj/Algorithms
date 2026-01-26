#include <iostream>
using namespace std;

void permute( string str[], int l, int r){
    if (l==r){
        cout<<str<<endl;
        return;
    }
    for(int i=l; i<r; i++){
        swap (str[l], str[i]);
        permute(str,l+1,r);
        swap(str[l],str[i]);
    }
}
int main(){
    string arr[]={"S", "D" ,"F" };
    permute(arr,0, 3);
    return 0;
}