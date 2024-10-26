#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 1000000007;

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> power(n);
    
    // Input power values
    for (int i = 0; i < n; i++) {
        cin >> power[i];
    }

    priority_queue<int> maxHeap; // Max-Heap to store powers

    // Populate the max heap
    for (int i = 0; i < n; i++) {
        int maxPower = power[i];
        for (int j = i; j < n; j++) {
            if (power[j] > maxPower) {
                maxPower = power[j];
            }
            maxHeap.push(maxPower);
        }
    }

    long long totalPower = 0;

    // Get the top k powers from the heap
    for (int i = 0; i < k && !maxHeap.empty(); i++) {
        totalPower = (totalPower + maxHeap.top()) % MOD;
        maxHeap.pop();
    }

    cout << totalPower << endl;
    return 0;
}
