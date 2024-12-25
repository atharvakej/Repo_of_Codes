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
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];


    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            mp[0].push_back(i);
        }
    }
    if(mp[0].size()==n)cout<<0<<endl;
    else{
        int st = 0, en = n-1;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                
            }
            else{
                st = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]==0){

            }
            else{
                en = i;
                break;
            }
        }
        int count  = 0;
        for(int i=st;i<=en;i++){
            if(arr[i]==0){
                count++;
                break;
            }
        }
        if(count==0)cout<<1<<endl;
        else cout<<2<<endl;



    }   
    
    
}
    return 0;
}