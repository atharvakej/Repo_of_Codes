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

void solve(){
    int b,c,d;
    cin>>b>>c>>d;
    int a = 0;
    for(int i=0;i<62;i++){
        int bset = b&(1LL<<i);
        int cset = c&(1LL<<i);
        if(d&(1LL<<i)){
            if(bset){

            }
            else if(cset==0){
                a = a|(1LL<<i);
            }
            else{
                cout<<-1<<endl;
                return;
            }
        }   
        else{
            if(bset==0){
                // a = a |(i<<i);
            }
            else if(cset){
                a = a|(1LL<<i);
            }
            else{
                cout<<-1<<endl;
                return;
            }
        } 
    }
    cout<<a<<endl;
    return;

}

int32_t main(){
IOS;
int t=1;
cin>>t;
while(t--){
    solve();
}
    return 0;
}