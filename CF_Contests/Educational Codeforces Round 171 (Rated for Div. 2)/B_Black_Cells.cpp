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

int check(int k, vector<int> &arr){
    int n = arr.size();
    int count = 0;
    int maxd = 0;
    for(int i=-1;i<n;i++){
        int last = -1;
        bool flag = 1;
        int ld = 0;
        for(int j=0;j<n;j++){
            if(j==i)continue;
            if(last ==-1){
                last = arr[j];
                continue;
            }
            if(last!=-1){
                if((arr[j]-last)<=k){
                    last = -1;
                }
                else{
                    ld = max(ld,(arr[i]-last));
                    flag = 0;
                    break;
                }
            }

        }
        //cout<<ld<<endl;
        if(i==-1 && flag)return 1;  
        if(flag && last==-1)return 1;
    }
    return 0;


}

int32_t main(){
IOS;
int t=1;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int> seg(n);
    fori(0,n)cin>>seg[i];

    sort(seg.begin(),seg.end());
    int low = 1;
    int high = *max_element(seg.begin(),seg.end()) - *min_element(seg.begin(), seg.end());
    int ans =  high;
    while(low<=high){

        int mid = low + (high-low)/2LL;
        if(check(mid,seg)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<max(1LL,ans)<<endl;

    
    
}
    return 0;
}