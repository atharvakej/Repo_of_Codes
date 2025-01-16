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

void solve(){         
    ll n; cin>>n;
    vector<ll> a[n];
    map<ll,ll> freq;
    for(ll i=0;i<n;i++){
        ll k; cin>>k;
        while(k--){
            ll x; cin>>x;
            freq[x]++;
            a[i].push_back(x);  
        }
    }
    int i=0;
    for(auto it:a){
        ll valid=1;
        for(auto i:it){
            if(freq[i]==1){
                valid=0;
            }
        }
        if(valid){
            //cout<<i<<endl;
            cout<<"Yes\n";
            return;
        }
        i++;
    }
    cout<<"No\n";
    return;                                  
}             



int32_t main(){
IOS;
int t=1;
cin>>t;
while(t--){
    solve();
    
}
    return 0;
}