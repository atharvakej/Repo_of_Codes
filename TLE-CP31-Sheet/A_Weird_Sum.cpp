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
//cin>>t;
while(t--){
    int n,m;
    cin>>n>>m;

    map<int,vector<int>> x;
    map<int,vector<int>> y;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int color;
            cin>>color;
            x[color].push_back(i);
            y[color].push_back(j);
        }
    }

    int ans  = 0;
    for(auto it:x){
        int sum = 0;
        //cout<<it.first<<" :  "<<endl;
        for(auto i:it.second){
            //cout<<i<<" ";
            sum += i;
        }
        //cout<<endl;
        sort(it.second.begin(),it.second.end());
        int idx = 1;
        int psum = 0;
        int size = it.second.size();
        for(auto i:it.second){
            psum += i;
            ans += (sum-psum) - ((size-idx)*i);
            //cout<<sum<<" "<<psum<<" "<<idx<<' '<<i<<endl;
            //cout<<ans<<endl;
            idx++;
            if(idx==size)break;
        }
        
    }
    //cout<<"row : "<<ans<<endl;
    for(auto it:y){
        int sum = 0;
        //cout<<it.first<<" :  "<<endl;
        for(auto i:it.second){
            //cout<<i<<" ";
            sum += i;
        }
        //cout<<endl;
        sort(it.second.begin(),it.second.end());
        int idx = 1;
        int psum = 0;
        int size = it.second.size();
        for(auto i:it.second){
            psum += i;
            ans += (sum-psum) - ((size-idx)*i);
            
            idx++;
            if(idx==size)break;
        }
    }
    cout<<ans<<endl;

    
    
    
}
    return 0;
}