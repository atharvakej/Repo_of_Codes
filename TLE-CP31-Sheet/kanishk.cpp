
#include <bits/stdc++.h>
using namespace std;


int func(int i, int j, int n,int m, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    
    if (i< 0 || i>=n)
        return -1e9; 
    if (j == m-1)
        return dp[i][m-1] =  matrix[i][m-1]; 
    if (dp[i][j] != -1)
        return dp[i][j]; 
    int up = matrix[i][j] + func(i, j+1, n, m,matrix, dp);
    int leftDiagonal = matrix[i][j] + func(i + 1, j +1, n,m, matrix, dp);
    int rightDiagonal = matrix[i][j] + func(i - 1, j +1, n,m, matrix, dp);
    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}

vector<int>  getmax(vector<vector<int>> &matrix) {
    int n = matrix.size(); 
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = INT_MIN;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        int ans = func(i, 0, n,m, matrix, dp);
        if(ans>maxi){
            maxi = ans;
            idx = i+1;
        }
    }
    return {maxi,idx}; 
}

int main() {
    // Define the matrix as a 2D vector
    vector<vector<int>> matrix{{1, 2, 10, 4},
                                {100, 3, 2, 1},
                                {1, 1, 20, 2},
                                {1, 2, 2, 1}};
    
    // Call the getmax function and print the result
    
    cout << getmax(matrix);

    return 0;
}

