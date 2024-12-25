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
    vector<int> a(n), b(n);
    fori(0,n)cin>>a[i];
    fori(0,n)cin>>b[i];
    
    int maxi = 1;

    map<int,int> mp;
    map<int,int> mp2;
    int ct = 1;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            ct++;
        }
        else{
            if(mp.find(a[i])==mp.end())
            mp[a[i]] = ct;
            else{
                mp[a[i]] = max(mp[a[i]],ct);
            }
            ct = 1;
        }
    }
    if(mp.find(a.back())==mp.end())
    mp[a.back()] = ct;
    else mp[a.back()] = max(mp[a.back()], ct);



    int ct1 = 1;
    for(int i=0;i<n-1;i++){
        if(b[i]==b[i+1]){
            ct1++;
        }
        else{
            if(mp2.find(b[i])==mp2.end())
            mp2[b[i]] = ct1;
            else{
                mp2[b[i]] = max(mp2[b[i]],ct1);
            }
            ct1 = 1;
        }
    }
    if(mp2.find(b.back())==mp2.end())
    mp2[b.back()] = ct1;
    else mp2[b.back()] = max(mp2[b.back()], ct1);

    int ans = 1;

    for(auto it:mp){
        ans = max(ans, it.second + mp2[it.first]);
    }

    for(auto it:mp2){
        ans = max(ans,it.second + mp[it.first]);
    }

    cout<<ans<<endl;




    
    
}
    return 0;
}