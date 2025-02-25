#include <bits/stdc++.h>
using namespace std;
#define POP pop_back
#define MOD 1e7 + 10
#define PI 3.1415926535897932
#define PB push_back
#define MP make_pair
#define pb push_back
#define ppb pop_back
int power(int a, int b)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
            r = (r * a);
        a = (a * a);
        b /= 2;
    }
    return r;
}

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
typedef vector<ll> Vi;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define fori(e, x) for (ll i = e; i < x; i++)
#define forj(x) for (ll j = 0; j < x; j++)
#define sorta(x) sort(x.begin(), x.end())
#define fora(x) for (auto it : x)
#define int long long
int ans;

void dfs(int node, vector<pair<int, int>> adj[], int par, int iterator, int idx)
{
    ans = max(ans, iterator);
    for (auto it : adj[node])
    {
        if (it.first==par)
        {
            continue;
        }
        dfs(it.first, adj, node, iterator + (it.second < idx), it.second);
    }
}

int32_t main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ans = 0;
        int count = 1;
        vector<pair<int, int>> edges(n - 1);
        fori(0, n - 1)
        {
            cin >> edges[i].first >> edges[i].second;
        }
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < n - 1; i++)
        {
            adj[edges[i].first].push_back({edges[i].second, i + 1});
            adj[edges[i].second].push_back({edges[i].first, i + 1});
        }
        dfs(1, adj, 0, 1, 1);
        cout << ans << endl;
    }
    return 0;
}