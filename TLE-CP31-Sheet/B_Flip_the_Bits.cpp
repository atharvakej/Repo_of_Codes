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
    string s,t;
    cin>>s>>t;
    int one = 0;
    int zero = 0;
    bool flag = 1;
    vector<pair<int,int>> count(n);
    vector<int> idxs;
    for(int i=0;i<n-1;i++){
        if( (s[i]!=t[i] && s[i+1]==t[i+1])
        || (s[i]==t[i] && s[i+1]!=t[i+1])){
            idxs.push_back(i);
        }
        one += s[i]=='1';
        zero += s[i]=='0';
        count[i] = {zero,one};
    }
    one += s[n-1]=='1';
    zero += s[n-1]=='0';
    count[n-1] = {zero,one};
    if(s[n-1]!=t[n-1]){
        idxs.push_back(n-1);
    }
    //cout<<idxs[0]<<endl;
    for(auto it:idxs){
        if(count[it].first!=count[it].second){
            flag =0;
            break;
        }
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    

    
    
}
    return 0;
}