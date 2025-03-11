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
    int n,x;
    cin>>n>>x;
    vector<int> arr;
    int st = 0;
    for(int i=0;i<n;i++){
        bool lega = 1;
        //cout<<i<<endl;
        for(int j=0;j<32;j++){
            if((x&(1<<j))==0  && (i&(1<<j))!=0 ){
                // cout<<"Kaha : "<<i<<endl;
                lega = 0;
                break;
            }
        }
        if(lega){
            st = i;
        }
        else{
            break;
        }
    }
    vector<int> ans;
    for(int i=0;i<=st;i++){
        ans.push_back(i);
    }
    for(int i=st+1;i<n;i++){
        ans.push_back(x);
    }
    int out = 0;
    for(auto it:ans){
        out = out | it;
    }
    if(out!=x){
        ans.pop_back();
        ans.push_back(x);
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    
    
}
    return 0;
}