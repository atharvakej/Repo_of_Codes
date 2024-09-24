#include <bits/stdc++.h>
using namespace std;


int phi[1001001];
int ETFSieve(int n){    // O(NLog(LogN))) time complexity
    for(int i=1;i<=n;i++){
        phi[i] = i;
    }
    
    for(int i=2;i<=n;i++){
        if(phi[i]==i){
            for(int j=i;j<=n;j+=i){
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
}



int main(){
    ETFSieve(1001001);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<"EFT("<<n<<") = "<<phi[n]<<endl;
    }    
    return 0;
}