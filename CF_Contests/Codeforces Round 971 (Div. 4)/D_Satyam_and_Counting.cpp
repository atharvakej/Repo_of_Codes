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
    map<int,int> y1;
    map<int,int> y0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(b==0)y0[a]++;
        if(b==1)y1[a]++;
    }
    int count = 0;
    for(auto it:y1){
        if(y0.find(it.first+1)!=y0.end()
        && y0.find(it.first-1)!=y0.end()){
            count++;
        }
        if(y0.find(it.first)!=y0.end()){
            count+= y0.size()-1;
        }
    }
    for(auto it:y0){    
        if(y1.find(it.first+1)!=y1.end()
        && y1.find(it.first-1)!=y1.end()){
            count++;
        }
        if(y1.find(it.first)!=y1.end()){
            count+= y1.size()-1;
        }
    }
    cout<<count<<endl;
    
    
}
    return 0;
}