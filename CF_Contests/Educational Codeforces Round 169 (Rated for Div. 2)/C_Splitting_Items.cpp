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
    int n,k;
    cin>>n>>k;
    cout<<n<<k<<endl;
    vector<int> arr(n,0);
    fori(0,n)cin>>arr[i];   
    multiset<int> ms;
    fori(0,n)ms.insert(arr[i]);
    int diff = 0;
    bool flag = true;
    while(!ms.empty()){
        if(flag){
        auto it = ms.end();
        int a = *it;
        ms.erase(it);
        int b = 0;
        if(!ms.empty()){
            it--;
        b = (*it);
        ms.erase(it);
        }
        diff = abs(a-b);
        flag = !flag;
        }
        else{
        auto it = ms.begin();
        int a = *it;
        ms.erase(it);
        int b = 0;
        if(!ms.empty()){
            it++;
            b = (*it);
        }
        diff = abs(a-b);
        flag = !flag;
        }
    }
    cout<<diff<<endl;    
}
    return 0;
}