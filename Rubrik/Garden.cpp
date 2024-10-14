#include <iostream>
#include <vector>
using namespace std;

long long subarray_product(int a, int b, const vector<long long> &prefix)
{
    return prefix[b + 1] / prefix[a];
}

int main()
{
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> heights(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    vector<long long> prefix(n + 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        prefix[i] = (prefix[i - 1] * heights[i - 1]);
    }
    for(auto it:prefix){
        cout<<it<<" ";
    }
    cout<<endl;
    int ways = 0;
    for (int a = 0; a <=n; a++)
    {
        for (int b = 0; b <= n - a; b++)
        {
            long long product = subarray_product(a, n-1-b, prefix);
            if (product % k == 0)
            {
                ++ways;
            }
        }
    }

    cout << ways << endl;
    return 0;
}
