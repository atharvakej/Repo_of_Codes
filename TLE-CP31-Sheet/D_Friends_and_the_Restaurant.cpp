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
    vector<int> x(n),y(n);
    fori(0,n)cin>>x[i];
    fori(0,n)cin>>y[i];

    vector<pair<int,int>> arr;
    fori(0,n){
        arr.push_back({y[i],x[i]});
    }
    sort(arr.begin(),arr.end(),[&](pair<int,int> &a, 
    pair<int,int> &b){
        
        // if(a.first==b.first){
        //     return a.second<b.second;
        // }
        // return a.first>b.first;
        return a.first-a.second > b.first-b.second;

    });

    // for(auto it:arr){
    //     cout<<it.first<<" ";
    // }
    // cout<<endl;
    // for(auto it:arr){
    //     cout<<it.second<<" ";
    // }
    // cout<<endl;

    int i= 0;
    int j = n-1;
    int count = 0;
    while(i<j){
        int money = arr[i].first + arr[j].first 
        - arr[i].second - arr[j].second;
        if(money>=0){
            i++;
            j--;
            count++;
        }
        else{
            j--;
        }
    }
    cout<<count<<endl;
    
    
}
    return 0;
}