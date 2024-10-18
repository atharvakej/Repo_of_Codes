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
bool check(int mid, vector<int> &arr, int pages){
    //mid = 2;
    int i=0;
    int n = arr.size();
    int red = 0;
    int count = 0;
    while(i<n){
        int j =i;
        for(j=i;j<i+mid && j<n;j++){
            count += max(0LL,(arr[j]-red));
        }
        red++;
        i = j;
    }
    //cout<<mid<<" "<<count<<endl;
    if(count>=pages)return 1;
    return 0;
}

int32_t main(){
IOS;
int t=1;
//cin>>t;
while(t--){
    int n,pages;
    cin>>n>>pages;

    vector<int> arr(n);
    fori(0,n){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end(), greater<int>());


    int low = 1;
    int high = pages;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;

        if(check(mid,arr,pages)){
            ans = mid;
            high = mid-1;
        }
        else
        low = mid+1;

    }
    cout<<ans<<endl;
    
    
}
    return 0;
}