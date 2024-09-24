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
#define fori(e,x) for(ll i=e; i<x; i++)
#define forj(x) for(ll j=0; j<x; j++)
#define sorta(x) sort(x.begin(),x.end())
#define fora(x) for(auto it : x)
#define int long long
vector<int> tree((100), 1e9);
void BuildTree(int i, int j, int idx, vector<int> &arr){
    int n = j+1;
    tree.resize(4*n);
    //cout<<idx<<" "<<i<<" "<<j<<endl;
    if(i==j){
        tree[idx]=arr[i];
        return;
    }
    int mid = (i+j)/2;
    BuildTree(i,mid,(2*idx)+1,arr);
    BuildTree(mid+1,j,(2*idx)+2,arr);
    tree[idx] = min(tree[(2*idx)+1],tree[(2*idx) +2]);
    return;
}
void Update(int ind, int val, int i, int j, int idx, 
vector<int> &arr){
    if(i==j){
        tree[idx] = val;
        return;
    }
    int mid = (i+j)/2;
    if(mid>=ind){
        Update(ind, val, i, mid, 2*idx +1, arr);
        
    }
    else{
        Update(ind, val, mid+1, j, 2*idx +2,arr);
    }
    tree[idx] = min(tree[(2*idx)+1],tree[(2*idx)+2]);
    return;

}
int query(int x, int y, int i, int j, int idx,
vector<int> &arr){

    if(j<x || i>y)return 1e9;
    if(x<=i && j<=y)return tree[idx];
    int mid = (i+j)/2;
    return min(query(x,y,i,mid,(2*idx)+1,arr), 
    query(x,y,mid+1,j,(2*idx)+2,arr)); 
}

int32_t main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];
    
    BuildTree(0,n-1,0,arr);
    cout<<query(2,4,0,n-1,0,arr);
    
    


    return 0;
}