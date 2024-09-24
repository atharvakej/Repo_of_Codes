#include <bits/stdc++.h>
using namespace std;



int ETF(int n){    // O(sqrt(N)) time complexity
    int res = n;

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            res /= i;
            res *= (i-1);

            while(n%i==0)n/=i;

        }
    }
    if(n>1){
    res /=n; 
    res *= (n-1);
    }
        
    return res;
}



int main(){
    int n;
    cin>>n;
    cout<<"EFT("<<n<<") = "<<ETF(n)<<endl;    
    return 0;
}