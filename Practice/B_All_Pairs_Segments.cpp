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
    int n,q;
    cin>>n>>q;
    map<int,int> mp;
    fori(0,n){
        int x;
        cin>>x;
        mp[x]+=(n-i-1);
        if(i>0)
        mp[x+1] -= i;
    }
    int seg = 0;
    int lastseg = 0;
    int points = 0;
    vector<pair<int,int>> pairs;
    for(auto it:mp){
        seg += it.second;
        //cout<<seg<<" "<<it.first<<endl;
        pairs.push_back({seg,it.first});
        // pts[seg].push_back(it.first);
    }
    map<int,int> segments;
    int last = -1;
    int pts = 0;
    int prev = 0;
    for(auto it:pairs){
        if(last==-1 || it.first==last){
            //cout<<"and "<<it.first<<" "<<last<<endl;
            if(last==-1){
                pts +=1;
            }
            else
            pts += it.second - prev;

            last = it.first;
            prev = it.second;
        }
        else{
            segments[last] += pts;
            pts = 1;
            last = it.first;
            
        }
       // cout<<it.first<<" "<<it.second<<" "<<pts<<endl;
    }
    cout<<"Break"<<endl;
    for(auto it:segments){
        cout<<it.first<<" "<<it.second<<endl;
    }
    while(q--){
        int x;
        cin>>x;
        cout<<segments[x]<<" ";
    }
    cout<<endl;

    
    
    
}
    return 0;
}