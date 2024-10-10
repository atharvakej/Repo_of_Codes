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

void dfs(int node,vector<int> adj[], vector<int> &vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
    return;
}

int32_t main(){
IOS;
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    vector<int> vis(n+1,0);
    vector<int> edges;
    int count = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            edges.push_back(i);
            count++;
            dfs(i,adj,vis);
        }
    }
    cout<<count-1<<endl;
    for(int i=1;i<(int)edges.size();i++){
        cout<<edges[0]<<" "<<edges[i]<<endl;
    }

    return 0;
}