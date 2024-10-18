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

int check2(int outlets, int k){
    int low = 0;
    int high = k;
    int ans = 1e9;
    while(low<=high){
        int mid = low + (high-low)/2;
        int value = (k*(k-1))/2 - ((k-mid)*(k-mid-1))/2 +1;
        if(value>=outlets){
            ans = min(ans,mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }

    }
    return ans;

}


bool check(int mid, int outlets, int k){
    if(check2(outlets,k)<=mid)return 1;
    return 0;

}

int32_t main(){
IOS;

    int n,k;
    cin>>n>>k;
    
    int low = 0;
    int high = k-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(check(mid,n,k)){
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