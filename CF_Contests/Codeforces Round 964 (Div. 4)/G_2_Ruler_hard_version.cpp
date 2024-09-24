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
    int low =1;
    int high = 999;
    int ans = -1;
    while(low<=high){
        int temp;
        int mid1 = low +  (high-low)/3;
        int mid2 = 2*(high-low)/3 + low;
        cout<<flush<<endl;
        cout<<'?'<<" "<<mid1<<" "<<mid2<<flush<<endl;
        cin>>temp;
        if(temp-(mid1*mid2)==0){
            
            low = mid2+1;
        }
        else if(temp-(mid1*mid2)==mid1){
            low = mid1+1;
            high = mid2-1;
            ans = mid2;
        }
        else{
            ans = mid1;
            high = mid1-1;
        }
    }
    cout<<flush<<endl;
    cout<<"! "<<ans<<flush<<endl;
    
    
}
    return 0;
}