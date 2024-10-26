#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minInsertionsToMakePretty(vector<int>& arr) {
    unordered_map<int, int> prefixMap; // Map to store the frequency of prefix sums
    int prefixSum = 0; // Running prefix sum
    int insertions = 0;

    prefixMap[0] = 1; // Handle case where prefixSum is 0 initially

    for (int num : arr) {
        prefixSum += num;

        if (prefixMap[prefixSum] > 0) {
            // We found a zero-sum subsegment, so we need to break it
            insertions++;

            // Reset prefix sum to break the segment
            prefixSum = num;

            // Clear the map and start fresh from the current element
            prefixMap.clear();
            prefixMap[0] = 1; // Add base case for new prefix sum
        }

        // Record the current prefix sum
        prefixMap[prefixSum]++;
    }

    return insertions;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << minInsertionsToMakePretty(arr) << endl;
    return 0;
}
