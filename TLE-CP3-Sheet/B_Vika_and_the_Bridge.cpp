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
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];
    vector<vector<int>> color(k+1);
    int maxi = 1e9;
    for(int i=0;i<n;i++){
        color[arr[i]].push_back(i);
    }
    // for(auto it:color){
    //     for(auto i:it){
    //         cout<<i<<' ';
    //     }
    //     cout<<endl;
    // }
    for(auto it:color){
        if(it.size()==0)continue;
        int top = it[0];
        int second = n-it.back()-1;
        if(second>top){
            swap(second,top);
        }
        for(int i=0;i<it.size()-1;i++){
            int t = it[i+1]-it[i]-1;
            if(t>=top){
                second = top;
                top = t;
            }
            else if(t>=second){
                second = t;
            }
        }
        int one = (top)/2;
        int two = (top-1)/2;
        int mini = max({one,two,second});
       // cout<<one<<" "<<two<<" "<<second<<endl;
        maxi = min(mini,maxi);
        //cout<<mini<<endl;
    }
    cout<<maxi<<endl;
    
    
}
    return 0;
}