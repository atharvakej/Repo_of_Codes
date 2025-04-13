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
    int n,m;
    cin>>n>>m; 
    vector<string> grid(n);
    fori(0,n){
        cin>>grid[i];
    }
    
    bool flag = 1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                bool f1 = 1;
                bool f2 =1;
                for(int k=0;k<i;k++){
                    if(grid[k][j]=='0'){
                        f1= 0;
                        break;
                    }
                }
                for(int k=0;k<j;k++){
                    if(grid[i][k]=='0'){
                        f2= 0;
                        break;
                    }
                }
                flag = f1 || f2;
            }
            if(flag==0)break;
        }
    }

    
    if(flag){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;


    
}
    return 0;
}