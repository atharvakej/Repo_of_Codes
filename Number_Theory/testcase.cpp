#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 1e4;
    cout<<'['<<"";
    for(int i=0;i<n;i++){
        cout<<'['<<i<<','<<i+1<<']'<<',';
    }
    cout<<']'<<endl;


    return 0;
}