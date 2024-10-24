#include <bits/stdc++.h>
using namespace std;
#define POP pop_back
#define MOD 1e7+10
#define PI 3.1415926535897932
#define PB push_back
#define MP make_pair
#define pb     push_back
#define ppb    pop_back
int power(int a, int b){
int r=1; 
while(b){
if(b&1)r=(r*a);
a=(a*a); b/=2;
}
return r;
}
    
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef map<ll , ll > mll;
typedef vector<ll> Vi;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fori(e,x) for(ll i=e; i<x; i++)
#define forj(x) for(ll j=0; j<x; j++)
#define sorta(x) sort(x.begin(),x.end())
#define fora(x) for(auto it : x)
#define int long long

int sumNegativeMinDiagonals(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int totalSum = 0;

    // Traverse diagonals starting from the first column (column 0)
    for (int r = 0; r < rows; ++r) {
        int i = r, j = 0;
        int minVal = INT_MAX;

        // Collect the minimum value along the diagonal
        while (i < rows && j < cols) {
            minVal = min(minVal, matrix[i][j]);
            ++i;
            ++j;
        }

        if (minVal < 0) {
            totalSum += abs(minVal);
        }
    }

    // Traverse diagonals starting from the first row (row 0), except (0,0)
    for (int c = 1; c < cols; ++c) {
        int i = 0, j = c;
        int minVal = INT_MAX;

        while (i < rows && j < cols) {
            minVal = min(minVal, matrix[i][j]);
            ++i;
            ++j;
        }

        if (minVal < 0) {
            totalSum += abs(minVal);
        }
    }

    return totalSum;
}



int32_t main(){
IOS;
int t=1;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    cout<<sumNegativeMinDiagonals(arr)<<endl;
    
    
}
    return 0;
}