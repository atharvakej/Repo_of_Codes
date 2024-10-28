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
    int n,k;
    cin>>n>>k;
    vector<int> cats(n);
    fori(0,n){
        cin>>cats[i];
    }
    vector<int> adj[n];

    fori(0,n-1){
        int x,y;
        cin>>x>>y;
        if(x>y){
            swap(x,y);
        }
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }

    queue<vector<int>> q;
    if(cats[0]){
        q.push({0,1,1});
    }
    else{
        q.push({0,0,0});
    }
    int count = 0;
    vector<int> vis(n,0);
    while(!q.empty()){
        int node = q.front()[0];
        int conscats = q.front()[1];
        int maxcats = q.front()[2];
        vis[node] = 1;
        q.pop();
        if(conscats>k)continue;
        //cout<<node<<" "<<conscats<<" "<<maxcats<<endl;
        // if(adj[node].size()==0 && conscats<=k){
        //     count++;
        // }
        bool flag = 0;
        for(auto it:adj[node]){
            //cout<<it<<endl;
            if(!vis[it]){
                flag =1;
                vis[it]=1;
                if(cats[it]){
                    int maxi = max(conscats+1,maxcats);
                    q.push({it,conscats+1,maxi});
                }
                else{
                    int maxi = max(conscats,maxcats);
                    q.push({it,0,maxi});
                }
            }
        }
        if(!flag && maxcats<=k){
            //cout<<"Node : "<<node+1<<endl;
            count++;
        }
    }
    cout<<count<<endl;

    
    
}
    return 0;
}