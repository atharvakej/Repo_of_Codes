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
map<int,int> mp;
bool check(int n)
{
    for (int k = 2; k <= 1e6; k++)
    {
        int t = n;
        int siz = 0;
        while (t)
        {
            if (t % k != 1)
            {
                break;
            }
            siz++;
            t = t / k;
            if(siz>=3){
            }
            // cout<<k<<" "<<t<<endl;
        }
        if (t == 0 && siz >= 3)
        {
            // cout << k << endl;
            return 1;
        }
    }
    return false;
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
        if (check(n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}