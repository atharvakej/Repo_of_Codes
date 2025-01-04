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
    int n,d;
    cin>>n>>d;
    int sum = n*d;
    vector<int> ans;
    ans.push_back(1);
    if(n>2 || d%3==0){
        ans.push_back(3);
    }
    if(d%2==0){
        ans.push_back(2);
    }
    int val = d*10 + d;
    if(n==1 && d%4==0 || (n>=2 && (val)%d==0)){
        ans.push_back(4);
    }
    if(d%5==0){
        ans.push_back(5);
    }
    if( (n>2 || d%3==0) && d%2==0){
        ans.push_back(6);
    }
    if(n>=3){
        ans.push_back(7);
    }
    int val2 = 100*d + d*10 + d;
    if((n>=3 && val2%8==0)|| (val%8==0) || (d%8==0)){
        ans.push_back(8);
    }
    if(n>=6 || (d%9==0)){
        ans.push_back(9);
    }
    for(auto it:ans){
        if(it%2)
        cout<<it<<" ";
    }
    cout<<endl;
    
    
}
    return 0;
}