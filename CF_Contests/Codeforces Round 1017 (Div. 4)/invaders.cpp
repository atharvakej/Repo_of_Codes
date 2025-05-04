#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& group) {
    visited[node] = true;
    group.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, group);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, E;
    cin >> N >> E;

    vector<pair<int, int>> edges;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int P;
    cin >> P;
    set<int> invaders;
    for (int i = 0; i < P; ++i) {
        int x;
        cin >> x;
        invaders.insert(x);
    }

    // Build adjacency list after removing edges with invaders
    vector<vector<int>> adj(N);
    for (auto& edge : edges) {
        int u = edge.first, v = edge.second;
        if (invaders.count(u) || invaders.count(v)) continue; // Remove edge if u or v is an invader
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Find connected components (islands)
    vector<bool> visited(N, false);
    vector<vector<int>> groups;

    for (int i = 0; i < N; ++i) {
        if (!invaders.count(i) && !visited[i]) {
            vector<int> group;
            dfs(i, adj, visited, group);
            sort(group.begin(), group.end());
            groups.push_back(group);
        }
    }

    // Sort groups by the first element of each group
    sort(groups.begin(), groups.end());

    // Output
    for (auto& group : groups) {
        for (int node : group) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
