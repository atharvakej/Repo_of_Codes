#include <stdio.h>
#include <limits.h>

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < c) {
        return b;
    } else {
        return c;
    }
}

int minopsHelper(long long n, int dp[]) {
    
    if (n == 2) {
        return 1;
    } else if (n == 1) {
        return 0;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int one = INT_MAX;
    int two = INT_MAX;

    if (n % 3 == 0) {
        one = 1 + minopsHelper(n / 3, dp);
    }
    if (n % 2 == 0) {
        two = 1 + minopsHelper(n / 2, dp);
    }
    int def = 1 + minopsHelper(n - 1, dp);
    dp[n] = min(one, two, def);
    return dp[n];
}

int minops(long long n, int dp[]) {
    return minopsHelper(n, dp);
}

// Driver code
int main() {
    long long n = 10;

    // Declare a dp array large enough to handle the given `n`
    int dp[100001]; // Assuming `n` will not exceed 100,000

    // Initialize the array with -1
    for (long long i = 0; i <= n; i++) {
        dp[i] = -1;
    }

    // Call the wrapper function and pass the dp array
    int ans = minops(n, dp);

    // Print the result
    printf("%d\n", ans);

    return 0;
}
