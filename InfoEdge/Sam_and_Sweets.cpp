#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<long> maximisingSweetness(vector<int> A,
                                 vector<int> B, vector<int> C)
{
    int n = A.size();
    vector<pair<int, int>> sweets;
    for (int i = 0; i < n; ++i)
    {
        sweets.push_back({A[i], B[i]});
    }
    sort(sweets.begin(), sweets.end());

    sort(C.begin(), C.end());
    priority_queue<int> q;

    int i = 0;
    int cnt = 0;
    long total = 0;
    for (int c : C)
    {
        while (i < n && sweets[i].first <= c)
        {
            q.push(sweets[i].second);
            ++i;
        }
        if (!q.empty())
        {
            ++cnt;
            total += q.top();
            q.pop();
        }
    }
    return {cnt, total};
}
