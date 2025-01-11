#include <bits/stdc++.h>
using namespace std;
#define POP pop_back
#define MOD 1e7+10
#define PI 3.1415926535897932
#define PB push_back
#define MP make_pair
#define pb     push_back
#define ppb    pop_back
#define int long long
int mod = 1e9+7;
int power(int a, int b){
int r=1; 
while(b){
if(b&1)r=(r%mod *a%mod)%mod;
a=(a%mod*a%mod)%mod; b/=2;
}
return r;
}

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fori(e,x) for(ll i=e; i<x; i++)
#define forj(x) for(ll j=0; j<x; j++)
#define sorta(x) sort(x.begin(),x.end())
#define fora(x) for(auto it : x)
int32_t main(){
IOS;
int t=1;
cin>>t;
while(t--){
    int n,k;
    cin>>n>>k;
    cout<<power(n,k)<<endl;
    
    
}
    return 0;
}