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
    string s;
    cin>>s;
    int n = s.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n-3;i++){
        if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0'){
            mp[i]++;
        }
    }
    int q;
    cin>>q;
    while(q--){
        int idx, val;
        cin>>idx>>val;
        idx--;
        s[idx] = val +'0';
        for(int i=max(0LL,idx-4);i<min(n,idx+4);i++){
            
            if(mp.find(i)!=mp.end()){
                mp.erase(i);
            }
            
        }
        for(int i=max(0LL,idx-4);i<min(n,idx+4);i++){
            
        if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0'){
            mp[i]++;
        }
            
        }
        if(!mp.empty()){
            cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
    


    
    
}
    return 0;
}