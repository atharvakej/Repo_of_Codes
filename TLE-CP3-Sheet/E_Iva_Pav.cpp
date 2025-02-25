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

bool func(int r, int l, vector<vector<int>> &bit, int k)
{

    int val = 0;
    for (int i = 0; i < 32; i++)
    {

        int diff = 0;
        if (l > 0)
            diff = bit[r][i] - bit[l - 1][i];
        else
            diff = bit[r][i];
        if (diff == (r - l + 1))
        {
            val = val | (1 << i);
        }
    }
    // cout<<"Val : "<<l<<" "<<r<<" "<<val<<endl;
    return val >= k;
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
        vector<int> arr(n);
        fori(0, n) cin >> arr[i];
        vector<vector<int>> bit(n, vector<int>(32, 0));
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
            {
                bit[i] = bit[i - 1];
            }
            for (int j = 0; j < 32; j++)
            {
                if ((arr[i] & (1 << j)))
                {
                    bit[i][j]++;
                }
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int l, k;
            cin >> l >> k;
            l--;
            int low = l;
            int high = n - 1;
            int ans = -1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                // cout<<mid<<endl;
                if (func(mid, l, bit, k))
                {
                    ans = mid+1;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}