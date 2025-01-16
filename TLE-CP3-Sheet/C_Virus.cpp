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
    int n,m;
    cin>>n>>m;
    vector<int> arr(m);
    fori(0,m)cin>>arr[i];
    sort(arr.begin(),arr.end());
    multiset<int> ms;
    int prev = arr[0];
    for(int i=1;i<m;i++){
        ms.insert(-(arr[i]-prev-1));
        prev = arr[i];
    }
    ms.insert(-(arr[0] + (n-arr.back()) - 1));
    int start = 0;
    int saved = 0;
    for(auto it:ms){
        //cout<<it<<endl;
        if((abs(it)-2*start)>0)
        saved += max(1LL,abs(it)-1-2*start);
        //cout<<saved<<endl;
        start +=2;
    }
    cout<<n-saved<<endl;


    
    
}
    return 0;
}