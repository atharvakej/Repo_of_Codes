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
    int n,x;
    cin>>n>>x;
    int bits =  __builtin_popcount(x);
    
    if(bits>=n){
        cout<<x<<endl;
    }
    else if(x==0){
        if(n%2==0){
            cout<<n<<endl;
        }
        else{
            if(n==1){
                cout<<-1<<endl;
            }
            else{
                cout<<n+3<<endl;
            }
        }
    }
    else if(x==1){
        if(n%2){
            cout<<n<<endl;
        }
        else{
            cout<<5+(n-2)<<endl;
        }
    }
    else{
        // cout<<x<<" "<<n<<' '<<bits<<endl;
        cout<< x + n - bits +1 <<endl;
    }
    
    
}
    return 0;
}