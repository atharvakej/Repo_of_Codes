#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int func(string &dataset, int x, int y)
{

    unordered_map<char, int> freq;
    for (char ch : dataset)
    {
        freq[ch]++;
    }

    int idp = 0, singles = 0;

    for (auto it : freq)
    {
        idp += it.second / 2;
        singles += it.second % 2;
    }

    int sum = 0;

    if (y < x)
    {
        priority_queue<int> pq;
        for (auto it : freq)
        {
            pq.push(it.second);
        }
        while (pq.size() > 1)
        {
            int top = pq.top();
            pq.pop();
            int stop = pq.top();
            pq.pop();
            cout << top << " " << stop << endl;
            int mini = min(top, stop);
            int rem = max(top, stop) - mini;
            sum += y * mini;
            pq.push(rem);
        }
        if (!pq.empty())
        {
            sum += x * (pq.top() / 2);
        }
    }
    else
    {

        sum += idp * x;
        sum += (singles / 2) * y;
    }
    return sum;
}

int main()
{
    string dataset = "abbaaaaaff";
    int x = 3, y = 2;

    int result = func(dataset, x, y);
    cout << "Minimum cost to clean the dataset: " << result << endl;

    return 0;
}
