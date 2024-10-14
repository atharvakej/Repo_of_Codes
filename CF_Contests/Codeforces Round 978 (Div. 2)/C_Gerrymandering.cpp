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
int value(char a,char b,char c){
    int val=0;
    val+=(a=='A');
    val+=(b=='A');
    val+=(c=='A');
    return (val>=2)?1:0;
}
int ans(vector<vector<int>>& dp,int cat,int idx,string& up,string& down){
    int n=up.size();
    if(idx>=n)return 0;

    if(dp[idx][cat]!=-1)return dp[idx][cat];

    int res=0;
    if(cat==0){
       res=value(up[idx],up[idx+1],down[idx])+ans(dp,2,idx+1,up,down);
       res=max(res,value(up[idx],down[idx+1],down[idx])+ans(dp,1,idx+1,up,down));
       res=max(res,value(up[idx],up[idx+1],up[idx+2])+value(down[idx],down[idx+1],down[idx+2])+ans(dp,0,idx+3,up,down));
    }
    else if(cat==1){
       res=value(up[idx],up[idx+1],down[idx+1])+ans(dp,0,idx+2,up,down);
       if(idx+2<n)res=max(res,value(up[idx],up[idx+1],up[idx+2])+value(down[idx+1],down[idx+2],down[idx+3])+ans(dp,1,idx+3,up,down));
    }
    else {
       res=value(down[idx],down[idx+1],up[idx+1])+ans(dp,0,idx+2,up,down);
       if(idx+2<n)res=max(res,value(up[idx+1],up[idx+2],up[idx+3])+value(down[idx],down[idx+1],down[idx+2])+ans(dp,2,idx+3,up,down));
    }   
    return dp[idx][cat]=res;
}

int32_t main(){
IOS;
int t=1;
cin>>t;

while(t--){
    int n;
    cin>>n;
    string up,down;
    cin>>up>>down;

    vector<vector<int>> dp(n,vector<int>(3,-1));

     cout<<ans(dp,0,0,up,down)<<endl;   
}
    return 0;
}