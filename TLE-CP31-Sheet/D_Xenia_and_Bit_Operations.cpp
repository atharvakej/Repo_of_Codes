#include<bits/stdc++.h>
using namespace std;


vector<int> tree((1<<18)+100);
void BuildTree(int l, int r, int i, vector<int> &arr, int dis){
    
    if(l==r){
        tree[i] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    BuildTree(l,mid,i*2 +1,arr,dis-1);
    BuildTree(mid+1,r,2*i + 2,arr,dis-1);
    if(dis&1)
    tree[i] = tree[2*i+1]|tree[2*i+2];
    else tree[i] = tree[2*i+1] ^tree[2*i+2];
    return;

}


void Update(int idx, int new_val, int l, int r, int i,
vector<int> &arr, int dis){
        //cout<<"Update :"<<" "<<i<<" "<<l<<" "<<r<<" "<<new_val<<endl; 
    if(l==r){
        tree[i] = new_val;
        return;
    }
    int mid = (l+r)/2;
    if(idx<=mid){
        Update(idx,new_val,l,mid,2*i+1,arr,dis-1);
    }
    else Update(idx,new_val,mid+1,r,2*i + 2, arr,dis-1);
    if(dis&1)
    tree[i] = tree[2*i+1]|tree[2*i+2];
    else tree[i] = tree[2*i+1] ^tree[2*i+2];
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
    vector<int> arr(1<<n);
    for(int i=0;i<(1<<n);i++){
        cin>>arr[i];
    }
    BuildTree(0,(1<<n)-1,0,arr,n);
    // for(int i=0;i<8;i++){
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<m;i++){
        int idx,val;
        cin>>idx>>val;
        Update(idx-1,val,0,(1<<n)-1,0,arr,n);
    //     for(int i=0;i<8;i++){
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;
        cout<<tree[0]<<endl;
    }




    return 0;
}