#include<iostream> 
using namespace std;

int main(){
    int size = 5;
    int **arr = new int*[size];

    for(int i=0;i<size;i++){
        int x;
        cin>>x;
        arr[i] = new int[x];
    }
    for(int i=0;i<size;i++){
        
        cout<<arr[i][0]<<endl;
    }

    delete[] arr;
}