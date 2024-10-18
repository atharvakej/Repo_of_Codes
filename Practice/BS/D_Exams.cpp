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

bool check(int days, vector<int> &arr, vector<int> &time, int n, int m){
    map<int,int> mp;
    for(int i=days-1;i>=0;i--){
        if(arr[i]==0)continue;
        if(mp.find(arr[i])==mp.end()){
            mp[arr[i]] = i;
        }
    }
    map<int,int> m2;
    for(auto it:mp){
        m2[it.second] = it.first;
    }
    if(m2.size()<m)return 0;
    int extradays = 0;
    int prev = 0;
    for(auto it:m2){
        extradays += it.first-prev;
        prev = it.first;
        extradays -= time[it.second-1];
        if(extradays<0)return 0;
       // cout<<it.first<<" "<<it.second<<endl;
    }
    return 1;   

}


int32_t main(){
IOS;
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];

    vector<int> time(m);
    int low = 0;
    fori(0,m){
        cin>>time[i];
        low += time[i];
    }
    low += m;
    int high = n;
    int ans = -1;
    while(low<=high){   
        int mid = low + (high-low)/2;
        //cout<<"dasdas"<<mid<<" "<<check(mid,arr,time,n,m)<<endl;
        if(check(mid,arr,time,n,m)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<ans<<endl;

    


    return 0;
}