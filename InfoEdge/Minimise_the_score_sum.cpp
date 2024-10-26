#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

long long sumOfProductSubarrays(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    long long totalSum = 0;

    // Calculate contribution of each element in A and B
    for (int i = 0; i < n; ++i) {
        long long contributionA = (long long)(i + 1) * (n - i) % MOD;
        long long contributionB = (long long)(i + 1) * (n - i) % MOD;

       
        totalSum = (totalSum +  A[i] % MOD * contributionB % MOD * B[i] % MOD) % MOD;
    }

    return totalSum;
}


int main() {
    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }

    // Sort A in ascending order (for convenience)
    sort(A.begin(), A.end());

    // Sort B in descending order
    sort(B.begin(), B.end(), greater<long long>());

   long long sum = sumOfProductSubarrays(A,B);
   cout<<sum<<endl;
}
