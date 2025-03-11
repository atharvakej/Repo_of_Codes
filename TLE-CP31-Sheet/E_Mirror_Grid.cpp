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
    tree[i] = tree[2*i +1] + tree[2*i + 2];
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
    tree[i] = tree[2*i+1] + tree[2*i+2];
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
    vector<int> arr = {5,2,4,5,7};
    BuildTree(0,4,0,arr);
    for(int i=0;i<10;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    cout<<query(0,2,0,5,0,arr);



    return 0;
}