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
#define fori(e,x) for(ll i=e; i<x; i++)
#define forj(x) for(ll j=0; j<x; j++)
#define sorta(x) sort(x.begin(),x.end())
#define fora(x) for(auto it : x)
#define int long long
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t=1;
cin>>t;
while(t--){
    string s,t;
    cin>>s>>t;
    int i=0;
    int j=0;
    int n = s.size();
    int m = t.size();

    while(i<n && j<m){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        else if(s[i]=='?'){
            s[i]=t[j];
            i++;
            j++;
        }
        else
        i++;
    }
    if(j!=m)cout<<"NO"<<endl;
    else{
    for(auto &it:s){
        if(it=='?')it='a';
    }
    cout<<"YES"<<endl;
    cout<<s<<endl;
    }
    
    
}
    return 0;
}