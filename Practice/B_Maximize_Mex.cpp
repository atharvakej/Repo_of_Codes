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
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];

    map<int,int> mp;
    map<int,int> mape;
    fori(0,n)mp[arr[i]]++;
    int i=0;
    for(i=0;i<n;i++){
        if(mp[i]>0){
            if(mp[i]>1){
               mp[i+x] +=  mp[i]-1;
               mp[i] = 1;
            }
        }
        else{
            break;
        }
    }
    cout<<i<<endl;
    
    
}
    return 0;
}