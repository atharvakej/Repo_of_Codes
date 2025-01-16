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
        int k, x;
        cin >> k >> x;
        int low = 1;
        int high = 2* k-1;
        int ans = 2*k -1 ;
        while (low <=high)
        {
            int lines = low + (high - low) / 2;
            //cout<<low<<" "<<high<<endl;
            if (lines <= k)
            {
                if ((lines * (lines + 1)) >= 2 * x)
                {
                    ans = lines;
                    high = lines - 1;
                }
                else
                {
                    low = lines + 1;
                }
            }
            else
            {
                int tillk = (k * (k + 1)) / 2LL;
                int sum1 = ((k - 1) * (k)) / 2LL;
                int sum2 = (((2 * k) - 1 - lines) * (2 * k - lines)) / 2LL;
                int total = tillk + sum1 - sum2;
                //cout<<lines<<" "<<"t : "<<total<<endl;
                if (total >= x)
                {
                    ans = lines;
                    high = lines - 1;
                }
                else
                {
                    low = lines + 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}