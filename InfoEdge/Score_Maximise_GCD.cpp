#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    // Input the array elements
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Step 1: Compute prefix GCDs
    vector<int> prefix(N), suffix(N);
    prefix[0] = A[0];
    for (int i = 1; i < N; ++i) {
        prefix[i] = gcd(prefix[i - 1], A[i]);
    }

    // Step 2: Compute suffix GCDs
    suffix[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        suffix[i] = gcd(suffix[i + 1], A[i]);
    }

    // Step 3: Find the maximum possible GCD after removing one element
    int maxGCD = 0;
    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            // If the first element is removed
            maxGCD = max(maxGCD, suffix[1]);
        } else if (i == N - 1) {
            // If the last element is removed
            maxGCD = max(maxGCD, prefix[N - 2]);
        } else {
            // If a middle element is removed
            maxGCD = max(maxGCD, gcd(prefix[i - 1], suffix[i + 1]));
        }
    }

    // Output the maximum possible GCD
    cout << maxGCD << endl;

    return 0;
}
