#include <iostream>
#include <cmath>
#include <algorithm>
using ll=long long;
using namespace std;
int main() {
    ll x2, y2, x3, y3, x1, k;
    cin >> x2 >> y2 >> x3 >> y3 >> x1 >> k;
    ll m = y2 + 1; 
    ll r = 2 * k;
    while (true) {
        ll c = abs(x1 * (y2 - y3) + x2 * (y3 - m) + x3 * (m - y2));
        if (c >= r) {
            cout << m << endl;
            break;
        }
        m++;
    }
    return 0;
}