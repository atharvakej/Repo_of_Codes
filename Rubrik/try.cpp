#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;  // Large prime to avoid overflow

// Function to compute (a^b) % mod using fast exponentiation
long long mod_pow(long long a, long long b, long long mod) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

// Function to compute modular inverse of a under modulo MOD
long long mod_inverse(long long a, long long mod) {
    return mod_pow(a, mod - 2, mod);  // Fermat's little theorem for prime mod
}

// Function to compute the product of a subarray [a, b]
long long subarray_product(int a, int b, const vector<long long>& prefix) {
    // Using prefix products and modular inverse for efficient calculation
    long long product = (prefix[b + 1] * mod_inverse(prefix[a], MOD)) % MOD;
    return product;
}

int main() {
    int n;
    cin >> n;
    vector<long long> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    // Compute prefix products
    vector<long long> prefix(n + 1, 1);  // Extra space for easier indexing
    for (int i = 1; i <= n; ++i) {
        prefix[i] = (prefix[i - 1] * heights[i - 1]) % MOD;
    }

    // Example usage of the subarray_product function
    int a, b;
    cout << "Enter range [a, b]: ";
    cin >> a >> b;

    cout << "Product of subarray [" << a << ", " << b << "] is: "
         << subarray_product(a, b, prefix) << endl;

    return 0;
}
