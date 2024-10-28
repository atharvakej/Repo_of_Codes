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
    int n,m,h;
    cin>>n>>m>>h;
    multimap<pair<int,int>,int> mp;
    for(int i=0;i<n;i++){
        int penalty = 0;
        int time = 0;
        int pts = 0;
        vector<int> t(m);
        for(int j=0;j<m;j++){
            cin>>t[j];
        }
        sort(t.begin(),t.end());
        for(int j=0;j<m;j++){
            int x = t[j];
            if((time+x)<=h){
                time += x;
                penalty += time;
                pts++;
                //cout<<time<<" "<<penalty<<endl;
            }
            else{
                break;
            }
        }
        mp.insert(pair<pair<int,int>, int>({-pts,penalty},i+1));
    }
    int order = 1;
    for(auto it:mp){    
       //cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
        if(it.second==1){
            cout<<order<<endl;
        }
        order++;
    }


    
    
}
    return 0;
}