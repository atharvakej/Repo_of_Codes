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
    vector<pair<int,int>> pairs(n);
    for(int i=0;i<n;i++){
        cin>>pairs[i].first>>pairs[i].second;
    }

    set<int> st1;
    set<int> st2;
    bool flag = 0;
    for(auto it:pairs){
        int f = it.first;
        int s = it.second;
        if(f==s){
            flag =1;
            break;
        }
        if(st1.find(f)==st1.end() && st1.find(s)==st1.end()){
            st1.insert(f);
            st1.insert(s);
        }
        else if(st2.find(f)==st2.end() && st2.find(s)==st2.end()){
            st2.insert(f);
            st2.insert(s);
        }
        else{
            flag = 1;
            break;
        }
    }
    if(flag)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;


    
    
}
    return 0;
}