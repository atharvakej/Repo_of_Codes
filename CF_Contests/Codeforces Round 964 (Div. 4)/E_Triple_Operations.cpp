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
int mode = 2e5+100;
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

    vector<int> arr(mode,0);
    arr[1]=1;
    for(int i=1;i<=mode;i++){
         arr[i]= arr[i/3]+1;
    }
    vector<int> pre(mode,0);
    pre[0]=0;
    pre[1]=1;
    for(int i=1;i<mode;i++){
        pre[i] = pre[i-1]+arr[i];
    }




ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t=1;
cin>>t;
while(t--){
    int l,r;
    cin>>l>>r;
    int op=  pre[r]-pre[l-1]+arr[l];
    cout<<op<<endl;

    
    
}
    return 0;
}