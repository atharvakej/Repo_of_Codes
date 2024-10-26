#include <iostream>
using namespace std;

bool enough(int mid, int N) {
    // Check how many elements are <= mid in the matrix
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        count += min(mid / i, N);  // Count elements <= mid in row i
    }
    return count >= (N * N + 1) / 2;  // Check if we have at least half the elements
}

string findMedian(int N) {
    int low = 1, high = N * N;
    int median = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (enough(mid, N)) {
            median = mid;  // Found a possible median, search left for smaller values
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return to_string(median);
}

int main() {
    int N;
    cin >> N;
    cout << findMedian(N) << endl;
    return 0;
}
