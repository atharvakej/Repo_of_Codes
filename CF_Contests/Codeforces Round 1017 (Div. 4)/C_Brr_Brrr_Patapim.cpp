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
int32_t main(){
IOS;
int t=1;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    fori(0,n){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    unordered_map<int,int> mp;
    vector<int> ans((2*n) +1,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int idx = i+j+2;
            if(idx<ans.size()){
                mp[arr[i][j]]++;
            ans[idx] = arr[i][j];
            }
        }
    }
    stack<int> st;
    for(int i=1;i<=2*n;i++){
        if(ans[i]==0){
            st.push(i);
        }
    }
    for(int i=1;i<=(2*n);i++){
        if(mp.find(i)==mp.end()){
            if(st.empty()==false){
                int topidx = st.top();
                ans[topidx] = i;
                st.pop();
            }
        }
    }
    vector<int> final;
    for(int i=1;i<=(2*n);i++){
        final.push_back(ans[i]);
    }
    for(auto it:final){
        cout<<it<<' ';
    }
    cout<<endl;




    
    
}
    return 0;
}