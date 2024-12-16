#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void sumgen(int idx, vector<int>& nums,int sum, vector<int>& store) {
        store.push_back(sum);
        if(idx>=nums.size())return;
        sumgen(idx+1,nums,sum+nums[idx],store) ;
        sumgen(idx+1,nums,sum,store);
        return;
}

int maximizeCPU(vector<int>& req, int capacity) {
    int n = req.size();
    vector<int> f,s;
    for(int i=0;i<(n/2);i++){
        f.push_back(req[i]);
    }
    for(int i=(n/2);i<(n);i++){
        s.push_back(req[i]);
    }
    vector<int> sumleft, sumright;
    sumgen(0,f,0, sumleft);
    sumgen(0,s,0, sumright);
    sort(sumright.begin(), sumright.end());
    int maxSum = 0;
    for (auto sum1:sumleft) {
        if (sum1 > capacity) continue;
        int remaining = capacity - sum1;
        auto it = upper_bound(sumright.begin(), sumright.end(), remaining);
        if(it != sumright.begin()){
            --it;
            maxSum = max(maxSum, sum1 + *it);
        }
    }
    return maxSum;
}

int main() {
    vector<int> req = {2,9,7};
    int capacity = 150;
    cout << maximizeCPU(req, capacity) << endl;
    return 0;
}