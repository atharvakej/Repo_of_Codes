#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int>& arr, int l, int m, int r) {
    vector<int> tmp;
    int i = l, j = m + 1, cnt = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) tmp.push_back(arr[i++]);
        else {
            tmp.push_back(arr[j++]);
            cnt += (m - i + 1);
        }
    }

    while (i <= m) tmp.push_back(arr[i++]);
    while (j <= r) tmp.push_back(arr[j++]);

    for (int k = 0; k < tmp.size(); ++k) arr[l + k] = tmp[k];

    return cnt;
}

int mergeSortAndCount(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int m = l + (r - l) / 2;
    return mergeSortAndCount(arr, l, m) +
           mergeSortAndCount(arr, m + 1, r) +
           mergeAndCount(arr, l, m, r);
}

int howManySwaps(vector<int> arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {5, 1, 4, 2};
    cout << "Number of swaps: " << howManySwaps(arr) << endl;
    return 0;
}