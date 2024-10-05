#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define ll   long long int
const ll M=1e16;
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0)
#define mod  1e9+7
#define pb   push_back
#define vt   vector
#define f(i,a,b) for(ll(i)=a; (i)<(b); (i)++)
#define all(x) (x).begin(),(x).end()
/* ascii value
A=65,Z=90,a=97,z=122
*/
ll fastpow(ll a,ll b){
ll res=1;while(b){
if(b&1)  res=(res*a)%M;
a=(a*a)%M; b=b>>1;}
return res;}
int isPrime(long long int n){
 for(long long int i=2;i*i<=n;i++){
if(n%i==0){
return 0;}
}
return 1;}


void solve(){
/*ll n; cin>>n;
ll a[n]; 
f(i,0,n){cin>>a[i];}
*/

int n,k;
cin>>n>>k;
if(n<k){
    cout<<n<<endl;
    return;
}
int cnt=0;
while(n!=0){
int ut = log2(n)/log2(k);
int val = pow(k,ut);
n-= val;
cnt++;
if(n==0){
    break;
}

}
cout<<cnt<<endl;

return;


}
    
    
int32_t main(){
ll t; cin>>t;
while(t--){
solve();
}
return 0;
}