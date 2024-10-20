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
    vector<vector<int>> arr(n);
    fori(0,n){
        int x,y;
        cin>>x>>y;
        arr[i] = {x,y,i};
    }
    vector<vector<int>> arr2(n);
    fori(0,n){
        int x = arr[i][0];
        int y = arr[i][1];
        arr2[i] = {x,y};
    }
    fori(0,n){
        int mini = min(arr[i][0],arr[i][1]);
        int maxi = max(arr[i][0],arr[i][1]);
        arr[i] = {mini,maxi,i};
    }
    
    sort(arr.begin(),arr.end(),[&](vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    });
    for(auto it:arr){
        cout<<arr2[it[2]][0]<<" "<<arr2[it[2]][1]<<" ";
        //cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
    }
    cout<<endl;
    
}
    return 0;
}

