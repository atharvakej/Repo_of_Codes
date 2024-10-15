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
const int p = 1e9+7;
int power(long long x, int y, int p) 
{ 
    int res = 1;     // Initialize result 
 
    x = x % p; // Update x if it is more than or 
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
 
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 


int32_t main(){
IOS;
    int N;
    cin>>N;
    vector<int> n(N);
    vector<int> k(N);
    fori(0,N)cin>>n[i];
    fori(0,N)cin>>k[i];

    for(int i=0;i<N;i++){
        int row = n[i];
        int col = k[i];
        if(row<col){
            cout<<0<<endl;
        }
        else if(row==col){
            cout<<1<<endl;
        }
        else{
            int value = power(2,col,p);
            cout<<value<<endl;
        }
    }


    return 0;
}