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
    char light;
    cin>>n>>light;

    string s;
    cin>>s;
    vector<int> idx(n);
    int lastocc = n;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='g'){
            lastocc = i;
        }

        if(lastocc==n){
            idx[i] = n;
        }
        else idx[i] = lastocc-i;
    }
    // for(auto it:idx){
    //     cout<<it<<' ';
    // }
    // cout<<endl;
    int focc = n;
    for(int i=0;i<n;i++){
        if(s[i]=='g'){
            focc = i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(idx[i]==n){
            idx[i] = n - i + focc;
        }
    }

    int maxi = 0;
    for(int i=0;i<n;i++){
        if(s[i]==light){
            maxi = max(idx[i],maxi);
        }
    }
    cout<<maxi<<endl;

    
    
}
    return 0;
}