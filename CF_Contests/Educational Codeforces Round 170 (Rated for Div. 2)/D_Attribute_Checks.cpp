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

    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];

    int freepts = 0;
    int s = 0;
    int intel = 0;
    int hurdle = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==0)freepts++;
        if(arr[i]>0){
            if((intel+freepts)>=arr[i]){
                hurdle++;
                freepts = freepts- (arr[i]-intel);
                intel = arr[i];
            }
            else break;
        }
        if(arr[i]<0){
            if((s+freepts)>=abs(arr[i])){
                hurdle++;
                freepts = freepts- (abs(arr[i])-s);
                s = arr[i];
            }
            else break;
        }
    }
    cout<<hurdle<<endl;


    return 0;
}