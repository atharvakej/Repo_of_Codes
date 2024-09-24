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
    int l,r,L,R;
    cin>>l>>r>>L>>R;
    vector<int> gates(200,0);
    int count = 0;
    fori(l,r+1)gates[i]+=1;
    for(int i=L;i<=R;i++){
        gates[i]++;
    }
    for(int i=0;i<200;i++){
        if( i>0 && gates[i-1]==1 && gates[i]==2){
            count++;
        }
        else if(i>0 && gates[i-1]==2 && gates[i]==2){
            count++;
        }
        else if(i>0 && gates[i-1]==2 && gates[i]==1){
            count++;
        }
    }
    if(count ==0 )count=1;
    cout<<count<<endl;

    
    
}
    return 0;
}