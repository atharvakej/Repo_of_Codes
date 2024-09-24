#include <bits/stdc++.h>
using namespace std;

int phi[1001001];
void ETFSieve(int n){    // O(NLog(LogN))) time complexity
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

int getcount(int d1, int n){
    cout<<n<<" "<<d1<<" "<<phi[n/d1]<<endl;
    return phi[n/d1];
}

int countgcd(int n){
    int res = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            int d1 = i;
            int d2 = n/i;

            res += d1 * getcount(d1,n);
            if(d1!=d2)res += d2 * getcount(d2,n);
        }
    }
    return res;
}


int main(){
    ETFSieve(1001000);
    int q,n;
    cin>>q;
    while(q--){
        cin>>n;
        cout<<countgcd(n)<<endl;
    }    
    return 0;
}