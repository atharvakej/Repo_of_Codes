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

    int last1 = 1e9;
    int last2 = 1e9;
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>last1 && arr[i]>last2){
            count++;
            if(last1<last2){
                last1 = arr[i];
            }
            else{
                last2 = arr[i];
            }
        }
        else if(arr[i]>last1){
            last2 = arr[i];
        }
        else if(arr[i]>last2){
            last1 = arr[i];
        }
        else{
            if(last1<last2){
                last1 = arr[i];
            }
            else{
                last2 = arr[i];
            }
        }
    }
    cout<<count<<endl;
    
    
}
    return 0;
}