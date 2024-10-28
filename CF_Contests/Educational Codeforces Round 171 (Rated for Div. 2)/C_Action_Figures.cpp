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
int32_t main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> vis(n, 0);
        deque<int> pq;
        int cost = 0;
        pq.push_back(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                pq.push_back(i);
            }
            else
            {
                if (!pq.empty())
                {
                    vis[pq.front()] = 1;
                    vis[i] = 1;
                    cost += i + 1;
                    pq.pop_front();
                }
            }
        }
        // cout<<"cost : "<<cost<<endl;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0' && !vis[i])
            {
                cost += i + 1;
            }
        }
        // cout<<"cost : "<<cost<<endl;
        while (!pq.empty() && pq.size() > 1)
        {
            int top = pq.front();
            pq.pop_front();
            int stop = pq.back();
            pq.pop_back();
            cost += min(top, stop) + 1;
            // cout<<cost<<endl;
        }
        if (!pq.empty())
            cost += pq.front() + 1;
        cout << cost << endl;
    }
    return 0;
}