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
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++)
        {
            int size;
            cin >> size;
            int entry = 0;
            int exit = 0;
            int idx = 0;
            for (int j = 0; j < size; j++)
            {
                int x;
                cin >> x;
                if ((x - j) > entry)
                {
                    entry = x - j;
                    idx = j;
                }
            }
            exit = entry + idx + (size - idx);
            pairs[i] = {entry, exit};
            // cout<<entry<<" "<<exit<<endl;
        }
        sort(pairs.begin(), pairs.end(), [&](pair<int, int> &a, pair<int, int> &b)
             {
        if(a.first==b.first){
            return a.second> b.second;
        }
        return a.first < b.first; });
        // cout<<endl;
        //  for(auto it:pairs){
        //      cout<<it.first<<" "<<it.second<<endl;
        //  }
        int st = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            // cout<<st<<" "<<pairs[i].first<<endl;
            ans = max(ans, pairs[i].first - st + 1);
            st += (pairs[i].second - pairs[i].first);
            // cout<<ans<<" "<<st<<endl
        }
        cout << ans << endl;
    }
    return 0;
}