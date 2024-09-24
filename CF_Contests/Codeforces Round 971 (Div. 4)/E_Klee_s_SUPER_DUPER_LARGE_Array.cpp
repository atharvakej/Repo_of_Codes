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

int sum(int mididx, int st,int end){
    int sum = ((mididx+st)*(mididx+st+1))/2 - (st*(st-1))/2;
    sum = sum -( end*(end+1)/2 -  ((mididx+st-1)*(mididx+st))/2 );
    return sum;
}


int32_t main(){
IOS;
int t=1;
cin>>t;
while(t--){
    int st,k;
    cin>>st>>k;
    int end = st +k-1;

    int startidx = 0;
    int endidx = k-1;
    int ans = 1e9;
    while(startidx<=endidx){
        int mididx = startidx + (endidx-startidx)/2;
        if(sum(mididx,st,end)<0){
            ans = abs(sum(mididx,st,end));
            startidx = mididx+1;
        }
        else{
            endidx = mididx-1;
        }
    }
    cout<<ans<<endl;

    
    
}
    return 0;
}