#include <bits/stdc++.h>
using namespace std;


    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis,
    vector<int> adj[], int tin[], int low[],
    vector<vector<int>> &bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                // node --- it
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }


vector<vector<int>> criticalConnections(int n,
    vector<vector<int>>& connections){
        vector<int> adj[n];
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
    void funcdfs(int node, vector<int> adj[], int n, 
    vector<bool> &vis, unordered_set<int> &st, vector<int> &a){
        cout<<"yaha";
        vis[node]=1;
        st.insert(a[node]);
        for(auto it:adj[node]){
            if(!vis[it]){
                funcdfs(it,adj,n,vis,st,a);
            }
        }
    }
    int countSum(vector<int> adj[],vector<int> &a, int n){
        // n nodes 
        vector<bool> vis(n,0);
        vis[0]=1;
        int sum  =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int t = 0;
                cout<<"yaha peee";
                unordered_set<int> st;
                funcdfs(i,adj,n,vis,st,a);
                for(auto it:st){
                    cout<<"Hi"<<endl;
                    cout<<it<<endl;
                    t+= it;
                }
                cout<<t<<" ";
                sum +=t;
            }
            
        }
        // cout<<endl;
        return sum;

    }

    int helper(vector<vector<int>> &edges, vector<vector<int>> bridges,
     vector<int> &a, int n){
        int maxsum = 0;

        for(auto it:bridges){
            int x = it[0];
            int y = it[1];
        vector<int> adj[n];
        for (auto it : edges) {
            int u = it[0], v = it[1];
            if( (x==u && y==v) || (x==v && y==u) ){
                continue;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout<<"yaha to aae ";
         maxsum = max(maxsum,countSum(adj,a,n));
        }
        return maxsum;
    }



    int GetAnswer(int n, int m, int c, vector<vector<int>> &edges, 
    vector<int> &a){
        // All critical Edges is stored in bridges
       vector<vector<int>> bridges =  criticalConnections(n,edges);
       return helper(edges,bridges,a,n);

    }


int main() {
    int n = 5, m =4, c=2;
    vector<vector<int>> edges = {
        {0, 3}, {3, 2},
        {3,1}, {0, 4}
    };
    vector<int> A = {2,3,2,10,10};
    cout<<GetAnswer(n,m,c,edges, A)<<endl;
    
}