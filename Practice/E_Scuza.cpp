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
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];
    //sort(arr.begin(), arr.end());
    vector<int> presum(n+1,0);
    vector<int> maxh(n,0);
    maxh[0] = arr[0];
    fori(1,n){
        maxh[i] = max(maxh[i-1],arr[i]);
    }
    presum[0] = 0;
    for(int i=1;i<=n;i++){
        presum[i] = presum[i-1] + arr[i-1];
    }
    // for(auto it:presum){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    while(q--){
        int x;
        cin>>x;
        int ub = upper_bound(maxh.begin(),maxh.end(),x)-maxh.begin();
        
        cout<<presum[ub]<<" ";
    }
    cout<<endl;
    
    
    
}
    return 0;
}