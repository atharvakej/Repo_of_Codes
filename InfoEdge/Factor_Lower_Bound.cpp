#include <bits/stdc++.h>
using namespace std;
int solve(const vector<int>& nums, int factor) {
  int low = -1;
 int high = nums.size() - 1;
 while (low < high) {
 int mid = (low + high + 1) / 2;
 if (nums[mid] < factor) {
 low = mid;
 } else {
 high = mid - 1; 
 }
 }
 return (low == -1) ? 0 : nums[low];
}

int main() {
 int N, m;
 cin >> N >> m;
 
 vector<int> nums(m);
 for (int i = 0; i < m; ++i) {
 cin >> nums[i];
 }
 
 sort(nums.begin(), nums.end());
 int s = 0;
 for (int i = 1; i <= sqrt(N); ++i) {
 if (N % i == 0) {
 s += solve(nums, i);
 if (i != N / i) {
 s += solve(nums, N / i);
 }
 }
 }
 
 cout << s << endl;
 
 return 0;
}