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
    fori(0,n){
        cin>>arr[i];
    }
    
    vector<pair<int,int>> idxs;
    for(int i=0;i<n;i++){
        int maxiconv = -1e9;
        int idx = 0;
        int conv = 0;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                conv++;
            }
            else if(arr[j]>arr[i]){
                conv--;
            }
            if(conv>maxiconv){
                maxiconv = conv;
                idx = j;
            }
        }
        idxs.push_back({maxiconv,idx});
    }
    // for(auto it:idxs){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    //cout<<endl;
    int iedx = -1;
    int maxi = 0;
    for(int i=0;i<idxs.size();i++){
        if(idxs[i].first>maxi){
            iedx = i;
            maxi = idxs[i].first;
        }
        //cout<<iedx<<" "<<maxi<<endl;
    }
    if(iedx==-1){
        cout<<1<<" "<<1<<endl;
    }
    else
    cout<<iedx+1<<" "<<idxs[iedx].second+1<<endl;
    //cout<<"---------------------"<<endl;
    
}
    return 0;
}