#include<bits/stdc++.h>
using namespace std;


vector<int> tree(1000000+100);
void BuildTree(int l, int r, int i, vector<int> &arr){
    
    if(l==r){
        tree[i] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    BuildTree(l,mid,i*2 +1,arr);
    BuildTree(mid+1,r,2*i + 2,arr);
    int t =  abs(tree[2*i +1] - tree[2*i + 2]);
    tree[i] = t/2 + t%2;
    return;

}


void Update(int idx, int new_val, int l, int r, int i,
vector<int> &arr){
    if(l==r){
        tree[i] = new_val;
        return;
    }
    int mid = (l+r)/2;
    if(idx<=mid){
        Update(idx,new_val,l,mid,2*i+1,arr);
    }
    else Update(idx,new_val,mid+1,r,2*i + 2, arr);
    int t =  abs(tree[2*i +1] - tree[2*i + 2]);
    tree[i] = t/2 + t%2;
}

int query(int x,int y, int l, int r, int i, vector<int> &arr){
    if(r<x || l>y){
        return 0;
    }
    if(x<=l && y>=r){
        return tree[i];
    }
    int mid = (l+r)/2;
    return query(x,y,l,mid,2*i+1,arr) + query(x,y,mid+1,r,2*i+1,arr);
}


int main(){ 
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    BuildTree(0,n-1,0,arr);
    // for(int i=0;i<8;i++){
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<m;i++){
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1){
            Update(l-1,r,0,n-1,0,arr);
            // for(int i=0;i<8;i++){
            //     cout<<tree[i]<<" ";
            // }
            // cout<<endl;
        }
        else{
            int val = query(l-1,r-1,0,n-1,0,arr);
            cout<<min(val,(r-l+1)-val)<<endl;
        }
    }
    return 0;
}