#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


bool isValid(int num, unordered_set<int>& bekar) {
    while (num > 0) {
        int digit = num % 10;
        if (bekar.count(digit)) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int solver(int N, int k, const vector<int>& dislike_digits) {
    unordered_set<int> bekar(dislike_digits.begin(), dislike_digits.end());
    
    while (true) {
        if (isValid(N, bekar)) {
            return N;
        }
        ++N;
    }
}

int main() {
    int N = 342;
    int k = 2;
    vector<int> dislike_digits = {0,1,2};
    
    cout << solver(N, k, dislike_digits) << endl;
    
    return 0;
}
