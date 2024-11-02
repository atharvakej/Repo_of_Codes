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
    sort(arr.begin(),arr.end());
    priority_queue<int,vector<int>, greater<>> pq;
    pq.push(arr[0]);
    pq.push(arr[1]);
    int ans =0;
    int rep = arr[n-1];
    for(int i=2;i<n;i++){
        int one = pq.top();
        pq.pop();
        int two = pq.top();
        pq.pop();
        //cout<<one<<" "<<two<<" "<<arr[i]<<endl;
        if((one+two)<=arr[i]){
            pq.push(rep);
            pq.push(max(two,one));
            ans++;
        }
        else{
            pq.push(one);
            pq.push(two);
        }
        pq.push(arr[i]);
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<ans<<endl;
    
    
}
    return 0;
}