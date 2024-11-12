#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
// N can be max 10^18 and hence digitsum will be 162 maximum.
long long dp[18][2][162];

long long solve(int i, bool tight, int sum_so_far,
				int Sum, string number, int len)
{
	if (i == len) {

		// If sum_so_far equals to given sum then 
		// return 1 else 0
		if (sum_so_far == Sum)
			return 1;
		else
			return 0;
	}

	if (dp[i][tight][sum_so_far] != -1) {
		return dp[i][tight][sum_so_far];
	}

	int ans = 0;
	bool ntight;
	int nsum_so_far;
	for (char currdigit = '0'; currdigit <= '9'; currdigit++) {

		// Our constructed number should not become
		// greater than N.
		if (!tight && currdigit > number[i]) {
			break;
		}

		// If tight is true then it will also be true for (i+1) digit.
		ntight = tight || currdigit < number[i];
		nsum_so_far = sum_so_far + (currdigit - '0');
		ans = (ans%mod +  solve(i + 1, ntight, nsum_so_far, Sum, number, len)%mod)%mod;
	}

	return dp[i][tight][sum_so_far] = ans%mod;
}

// Driver code
int main()
{
	long long count = 0;
	long long sum = 70;
	string number = "1000000000000000";
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0, 0, sum, number, number.size());
	return 0;
}
