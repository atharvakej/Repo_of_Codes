#include <bits/stdc++.h>
using namespace std;
#define POP pop_back
#define MOD 1e7+10
#define PI 3.1415926535897932
#define PB push_back
#define MP make_pair
#define pb     push_back
#define ppb    pop_back
int power(int a, int b){
int r=1; 
while(b){
if(b&1)r=(r*a);
a=(a*a); b/=2;
}
return r;
}
    
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef map<ll , ll > mll;
typedef vector<ll> Vi;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fori(e,x) for(ll i=e; i<x; i++)
#define forj(x) for(ll j=0; j<x; j++)
#define sorta(x) sort(x.begin(),x.end())
#define fora(x) for(auto it : x)
#define int long long
int32_t main(){
IOS;
int t=1;
cin>>t;
while(t--){
    int n;
    cin>>n;
    // x*4 + y*6 == n
    // if n is div by 6 & 4 both -> (n/4, n/6)
    // if n = 4*x + 1 -> not possible
    // if n = 4*x +2 -> maxi = (x-1 + 1), mini = (2* (n/12) + (n%12)/4)
    // if n = 4*x + 3 -> not possible
    // if n = 4*x -> (x-3 + 2)
    if(n<4 || n%2){
        cout<<-1<<endl;
    }
    else{
        cout<<((n+5)/6)<<" "<<(n/4)<<endl;
    }

    
    
}
    return 0;
}