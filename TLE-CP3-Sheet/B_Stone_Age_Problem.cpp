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
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];
    int sum = 0;
    for(auto it:arr){
        sum += it;
    }
    vector<vector<int>> prr(n,vector<int>(2LL,-1LL));
    int slast = -1LL;
    int slastval = -1LL;
    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type==1){
            int idx,val;
            cin>>idx>>val;
            idx--;
            if(slast==-1){
                sum -= arr[idx];
                sum += val;
                arr[idx] = val;
                prr[idx][0] = i;
                prr[idx][1] = val;
            }
            else if(slast>prr[idx][0]){
                arr[idx] = slastval;
                sum -= arr[idx];
                sum += val;
                arr[idx] = val;
                prr[idx][0] = i;
                prr[idx][1] = val;
            }
            else{
                arr[idx] = prr[idx][1];
                sum -= arr[idx];
                sum += val;
                arr[idx] = val;
                prr[idx][0] = i;
                prr[idx][1] = val;
            }
        }
        else{
            int val;
            cin>>val;
            sum = n*val;
            slast = i;
            slastval = val;

        }
    cout<<sum<<endl;
    }
    
    
}
    return 0;
}