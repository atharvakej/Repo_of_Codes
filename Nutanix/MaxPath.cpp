#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


    int maxPathSum(const vector<int>& parent, const vector<int>& values) {
        int n = parent.size();
        
        vector<vector<int>> tree(n);
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                root = i;
            } else {
                tree[parent[i]].push_back(i);
            }
        }

        int globalMax = INT_MIN;
        dfs(root, tree, values, globalMax);
        return globalMax;
    }

    int dfs(int node, const vector<vector<int>>& tree, const vector<int>& values, int& globalMax) {
        if (tree[node].empty()) {
            globalMax = max(globalMax, values[node]);
            return values[node];
        }

        
        int maxContribution = 0;
        int mxCsum1 = INT_MIN, mxCsum2 = INT_MIN;

        for (int child : tree[node]) {
            
            int  childcont = max(0, dfs(child, tree, values, globalMax));
            if ( childcont > mxCsum1) {
                mxCsum2 = mxCsum1;
                mxCsum1 =  childcont;
            } else if ( childcont > mxCsum2) {
                mxCsum2 =  childcont;
            }
        }

        
        int currentMaxPath = values[node] + mxCsum1 + mxCsum2;
        globalMax = max(globalMax, currentMaxPath); 

        
        return values[node] + mxCsum1;
    }
int main() {
    
    vector<int> parent = {-1, 0, 0, 1, 0};
    vector<int> values = {1, 2, 3, 4, 5};

    cout << maxPathSum(parent, values) << endl; 
    return 0;
}
