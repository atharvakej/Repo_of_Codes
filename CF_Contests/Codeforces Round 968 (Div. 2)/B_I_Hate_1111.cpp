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
    if((n%11)==0 || (n%111)==0 || n>1099 )cout<<"YES"<<endl;
    else if( n<=1099){
        bool flag = false;
        for(int i=1;i<110;i++){
            for(int j=1;j<20;j++){
                if((i*11 + j*111)==n){
                    cout<<"YES"<<endl;
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
        if(!flag)cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;  
    }
}
    return 0;
}