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
#define int long long int
int32_t main(){
IOS;
int t=1;
cin>>t;
while(t--){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];
    sort(arr.begin(),arr.end());
    //cout<<arr[0]<<endl;
    if(k==1){
        
        int mini = arr[0];
        for(int i=1;i<n;i++){
            //cout<<abs(arr[i]-arr[i-1])<<endl;
            mini = min(mini,abs(arr[i]-arr[i-1]));
            mini = min(arr[i],mini);
        }
        cout<<mini<<endl;
    }
    else if(k==2){
        int  mini = 1e18+7;
        for(int i=0;i<n;i++){
        mini = min(arr[i],mini);
           for(int j=i+1;j<n;j++){
            int diff = abs(arr[i]-arr[j]);
            mini = min(diff,mini);
            int closest = upper_bound(arr.begin(), arr.end(), diff) - arr.begin();
            int closest2 = lower_bound(arr.begin(), arr.end(), diff) - arr.begin();
            if(closest<n){
                mini = min(mini,abs(arr[closest]-diff));
            }
            if(closest>0){
                mini = min(mini,abs(arr[closest-1]-diff));
            }
            if(closest2<n){
                mini = min(mini,abs(arr[closest2]-diff));
            }
            if(closest2>0){
                mini = min(mini,abs(arr[closest2-1]-diff));
            }

           }
        }
        cout<<mini<<endl;
    }
    else{
        cout<<0<<endl;
    }
    
    
}
    return 0;
}