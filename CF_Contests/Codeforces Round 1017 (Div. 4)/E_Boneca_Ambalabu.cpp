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
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];
    int maxi = *max_element(arr.begin(),arr.end());
    int val = 0;
    for(int i=0;i<31;i++){
        int onect = 0, zeroct = 0;
        for(int j=0;j<n;j++){
            if((arr[j]&(1<<i))){
                onect++;
            }
            else zeroct++;
        }
        // cout<<zeroct<<" "<<onect<<endl;
        if(zeroct>onect){
            // cout<<zeroct<<" "<<onect<<endl;
        // cout<<(1<<i)<<endl;
        if((1<<(i))<=maxi+10)
        val = val | (1<<(i));
        }
    }
    int mini = 1e9;
    int minimest = 1e9;
    for(int i=0;i<n;i++){
        int t = val^arr[i];
        if(t<minimest){
            minimest = t;
            mini = arr[i];
        }
    }
    int final = 0;
    for(int i=0;i<n;i++){
        final += mini^arr[i];
    }
    cout<<val<<" "<<mini<<" "<<final<<endl;

    

}
return 0;
}