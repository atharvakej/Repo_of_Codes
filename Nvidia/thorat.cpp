#include<bits/stdc++.h>
using namespace std;

int func(int idx, vector<int> &arr, vector<vector<int>> &dp, int prev, int k){
    if(idx>=arr.size() && k>=0){
        return 0;
    } 
    if(idx>=arr.size()){
        return -1e9;
    }
    int pick = 0;
    
    if(arr[idx]!=prev){
        if(prev==0){
            pick = 1 + func(idx+1,arr,dp,arr[idx],k);
        }
        else
        pick = 1 + func(idx+1,arr,dp,arr[idx],k-1);
    }
    else pick = 1 + func(idx+1,arr,dp,arr[idx],k);
    int npick = func(idx+1,arr,dp,prev,k);
    return max(pick,npick);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<func(0,arr,dp,0,k)<<endl;
    return 0;



}