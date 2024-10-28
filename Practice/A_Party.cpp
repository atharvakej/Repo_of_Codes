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
//cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int> adj[n+1];
    vector<int> heads;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        //cout<<x<<Endd
        if(x!=-1)
        adj[x].push_back(i);
        else
        heads.push_back(i);
    }

    int maxd = 0;
    // for(int i=1;i<=n;i++){
    //     for(auto it:adj[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<heads.size();i++){

    queue<pair<int,int>> q;
    q.push({heads[i],1});
    vector<bool> vis(n+1,0);
    vis[heads[i]] =1;
    while(!q.empty()){
        int node = q.front().first;
        int depth = q.front().second;
        //cout<<node<<" "<<depth<<endl;
        maxd = max(maxd,depth);
        q.pop();
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push({it,depth+1});
            }
        }
    }
    }
    cout<<maxd<<endl;
    
}
    return 0;
}