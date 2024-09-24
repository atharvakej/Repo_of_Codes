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
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];
    sort(arr.begin(), arr.end());
    deque<int> dq;
    for(auto it:arr){
        dq.push_back(it);
    }
    bool turn = 0;
    while(dq.size()>1){
        if(turn==0){
            int one = dq.front();
            dq.pop_front();
            int two = dq.front();
            dq.pop_front();
            int maxi = max(one,two);
            dq.push_front(maxi);
            turn = 1;
        }
        else{
            int one = dq.back();
            dq.pop_back();
            int two = dq.back();
            dq.pop_back();
            int maxi = min(one,two);
            dq.push_back(maxi);
            turn =0;
        }
    }
    cout<<dq.front()<<endl;
    
    
}
    return 0;
}