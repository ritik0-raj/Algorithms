#include<iostream>
using namespace std;
void ToH(int n, char src, char aux, char dest){
    if (n==1){
        cout<<"move disk "<< "from "<< src<< "to "<< dest << endl;
        return;
    }
    ToH(n-1, src, dest, aux);
    cout<<"move disk "<< n << "from "<<src <<"to "<< dest<<endl;
    ToH(n-1, aux, src, dest);
}
int main(){
    ToH(3, 'A', 'B', 'C');
    return 0;
}