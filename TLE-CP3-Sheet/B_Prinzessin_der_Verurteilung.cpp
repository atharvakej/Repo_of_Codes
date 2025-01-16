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
    string s;
    cin>>s;
    string t = "";
    for(char c='a';c<='z';c++){
        if(s.find(c)==string::npos){
            t.push_back(c);
            break;
        }
    }
    if(!t.empty()){
        cout<<t<<endl;
        continue;
    }
    for(char c='a';c<='z';c++){
        for(char a='a';a<='z';a++){
            t.push_back(c);
            t.push_back(a);
            if(s.find(t)==string::npos){
            break;
            }
            else t = "";
        }
        if(!t.empty()){
            break;
        }
    }
    if(!t.empty()){
        cout<<t<<endl;
        continue;
    }

    for(char c='a';c<='z';c++){
        for(char a='a';a<='z';a++){
            for(char b='a';b<='z';b++){
            t.push_back(c);
            t.push_back(a);
            t.push_back(b);
            if(s.find(t)==string::npos){
            break;
            }
            else t = "";
            }
            if(!t.empty()){
            break;
        }
        }
        if(!t.empty()){
            break;
        }
    }
    if(!t.empty()){
        cout<<t<<endl;
    }
    
    
    
}
    return 0;
}