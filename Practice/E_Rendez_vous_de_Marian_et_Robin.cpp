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

vector<int> func(int n,vector<bool> &horses,vector<pair<int,int>> adj[], int vertex, 
int ghoda , int iniwt){
    priority_queue<vector<int>, vector<vector<int>> , greater<>> pq;
    pq.push({iniwt,vertex,ghoda});
    vector<int> dist(n+1,1e15);
    dist[0] = 0;
    dist[vertex] = iniwt;
    while(!pq.empty()){
        int wt = pq.top()[0];
        int node = pq.top()[1];
        int ghoda = pq.top()[2];
        pq.pop();
        if(horses[node]==1)ghoda =1;

        for(auto it:adj[node]){
            if(ghoda){
                if((wt+(it.second/2))<dist[it.first]){
                    dist[it.first] = wt + (it.second/2);
                    pq.push({dist[it.first], it.first, ghoda});
                }
            }
            else{
                if((wt+(it.second))<dist[it.first]){
                    dist[it.first] = wt + (it.second);
                    pq.push({dist[it.first], it.first, ghoda});
                }
            }
        }
    }
    return dist;
}


int32_t main(){
IOS;
int t=1;
cin>>t;
while(t--){
    int n,m,h;
    cin>>n>>m>>h;
    vector<bool> horses(n+1,0);
    for(int i=0;i<h;i++){
        int x;
        cin>>x;
        horses[x] = 1 ;
    }
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> dist00 = func(n,horses,adj,1,0,0);
    int idx1 = -1;
    int distance = 1e15;
    for(int i=1;i<=n;i++){
        if(horses[i]==1){
            if(dist00[i]<distance){
                distance = dist00[i];
                idx1 = i;
            }
        }
    }
    vector<int> dist01;
    if(idx1==-1){
        dist01 = dist00;
    }
    else
     dist01 = func(n,horses,adj,idx1,1, distance );


    vector<int> dist10 = func(n,horses,adj,n,0,0);
    int idx2 = -1;
    int distance2 = 1e15;
    for(int i=1;i<=n;i++){
        if(horses[i]==1){
            if(dist10[i]<distance2){
                distance2 = dist10[i];
                idx2 = i;
            }
        }
    }
    vector<int> dist11;
    if(idx2==-1){
        dist11 = dist10;
    }
    else
    dist11 = func(n,horses,adj,idx2,1,distance2);

    int ans = 1e15;
    for(int i=1;i<=n;i++){  
        int leftmin = min(dist01[i],dist00[i]);
        int rightmin = min(dist10[i],dist11[i]);
        int t = max(leftmin,rightmin);
        ans = min(ans,t);
    }
     if(ans==1e15)ans=-1;
     cout<<ans<<endl;
    // for(auto it:dist00){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // for(auto it:dist01){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // for(auto it:dist10){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // for(auto it:dist11){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // cout<<endl;
    
    
}
    return 0;
}