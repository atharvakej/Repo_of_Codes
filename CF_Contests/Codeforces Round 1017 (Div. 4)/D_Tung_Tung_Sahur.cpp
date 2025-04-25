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

vector<pair<char, int>> compress(string &s)
{
    if (s.empty())
        return {};

    vector<pair<char, int>> result;
    char curr = s[0];
    int count = 1;

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == curr)
        {
            ++count;
        }
        else
        {
            result.push_back({curr, count});
            curr = s[i];
            count = 1;
        }
    }
    result.push_back({curr, count});

    return result;
}

int32_t main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        string p, s;
        cin >> p >> s;
        bool flag = 1;
        vector<pair<char, int>> p1 = compress(p);
        vector<pair<char, int>> s1 = compress(s);
        // for (auto it : p1)
        // {
        //     cout << it.first << " " << it.second << endl;
        // }
        // cout << endl;
        // for (auto it : s1)
        // {
        //     cout << it.first << " " << it.second << endl;
        // }
        if (p1.size() != s1.size())
        {
            flag = 0;
        }

        for (int i = 0; i < p1.size() && i<s1.size(); i++)
        {
            if (p1[i].first == s1[i].first && 
            (2 * (p1[i].second)) >= ((s1[i].second)) 
            && ((p1[i].second)) <= ((s1[i].second)))
            {
                
            }
            else
            {
                // cout<<p1[i+1].second<<" "<<s1[i+1].second<<endl;
                // cout << i << endl;
                flag = 0;
                break;
            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}