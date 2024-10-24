#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long maxd(  vector<int>& a,   vector<int>& b,   vector<int>& c, 
                         vector<int>& d,   vector<int>& e) {
    int N = a.size();
    long long maxDiff = LLONG_MIN;

    for (int p1 : {-1, 1}) {
        for (int p2 : {-1, 1}) {
            for (int p3 : {-1, 1}) {
                for (int p4 : {-1, 1}) {
                    for (int p5 : {-1, 1}) {
                        for (int p6 : {-1, 1}) {
                            long long maxVal = LLONG_MIN;
                            long long minVal = LLONG_MAX;
                            for (int i = 0; i < N; ++i) {
                                long long value = p1 * a[i] + p2 * b[i] + p3 * c[i] +
                                                p4 * d[i] + p5 * e[i] + p6 * i;
                                maxVal = max(maxVal, value);
                                minVal = min(minVal, value);
                            }
                            maxDiff = max(maxDiff, maxVal - minVal);
                        }
                    }
                }
            }
        }
    }

    return maxDiff;
}

int main() {
    vector<int> a = {5, 7, 6, 3, 9};
    vector<int> b = {7, 9, 2, 7, 5};
    vector<int> c = {1, 9, 9, 3, 3};
    vector<int> d = {8,4,1, 10, 5};
    vector<int> e = {6,7,1,4,11};

    cout << maxd(a, b, c, d, e) << endl;
    return 0;
}
