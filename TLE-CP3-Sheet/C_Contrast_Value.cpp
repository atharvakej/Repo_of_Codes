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
for(int p=1;p<=t;p++){
    int n;
    cin>>n;
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];
    bool flag = 1;
    for(int i=0;i<n;i++){
        if(arr[i]==arr[0]){

        }
        else{
            flag = 0;
            break;
        }
    }
    if(flag){
        cout<<1<<endl;
        continue;
    }


    vector<int> a;
    a.push_back(arr[0]);
    fori(1,n){
        if(arr[i]==a.back() || arr[i]==0){
            continue;
        }
        else a.push_back(arr[i]);
    }
    // for(auto it:a){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    int ans = 1;
    for(int i=1;i<a.size()-1;i++){
        if((a[i+1]-a[i])*(a[i]-a[i-1])<0){
           // cout<<i<<" ";
            ans +=2;
        }
    }
    //cout<<endl;
    // if(p==102){
    //     for(auto it:arr){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    if(ans==1 && flag==0){
        cout<<ans+1<<endl;
    }
    else
    cout<<ans<<endl;
    
}
    return 0;
}