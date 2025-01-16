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
    // cin>>t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int t = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                if (i < n - 2 && s[i + 1] == s[i + 2])
                {
                    if (s[i] == 'a')
                    {
                        s[i + 1] = 'b';
                    }
                    else if (s[i] == 'z')
                    {
                        s[i + 1] = 'y';
                    }
                    else
                    {
                        s[i + 1] = s[i + 1] - 'b' + 'a';
                    }
                }
                else
                {
                    if (i == 0)
                    {
                        s[i] = s[i] + 1;
                    }
                    else
                    {
                        char prev = s[i - 1];
                        s[i] = 'a' + (prev + s[i] + 26) % 26;
                    }
                }
            }
            // cout<<s<<endl;
        }
        cout << s << endl;
    }
    return 0;
}