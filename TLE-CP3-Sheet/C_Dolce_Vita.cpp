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
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];

    sort(arr.begin(), arr.end());
    for(int i=1;i<n;i++){
        arr[i] = arr[i-1] + arr[i];
    }
    int count = 0;
    int days = -1;
    for(int i=n-1;i>=0;i--){
        int today = (x-arr[i])/(i+1);
        if((x-arr[i])<0){
            today = -1;
        }
        cout<<today<<" "<<days<<endl;
        count += (i+1)*(today-days);
        days = today;
    }
    cout<<count<<endl;
    
    
}
    return 0;
}