#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
vector<int> spf(MAXN + 1, 1);
void sieve()
{
    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { 
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1)
                spf[j] = i;
            }
        }
    }
}

int maxprime(int x)
{
    int maxi =  1;
    while (x != 1) {
        maxi = max(maxi,spf[x]);
        x = x / spf[x];
    }
    return maxi;
}



int main(){
int t=1;
cin>>t;
sieve();
while(t--){
    int l,r,p;
    cin>>l>>r>>p;
    int count = 0;
    for(int i=l;i<=r;i++){
        if(maxprime(i)<=p){
            count++;
        }
    }
    cout<<count<<endl;
    
    
}
    return 0;
}