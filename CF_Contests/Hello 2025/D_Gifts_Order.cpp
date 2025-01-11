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
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    fori(0,n)cin>>arr[i];

    vector<int> a(n);
    vector<int> b(n);
    fori(0,n){
        a[i] = arr[i] - i;
        b[i] = arr[i] - i;
    }
    for(auto it:b){
        cout<<it<<" ";
    }
    cout<<endl;
    map<int,int> m1;
    map<int,int> m2;

    for(auto it:a){
        m1[it]++;
    }
    for(auto it:b){
        m2[it]++;
    }
    for(auto it:m1){
            cout<<it.first<<" ";
        }
        cout<<endl;
        for(auto it:m2){
            cout<<it.first<<" ";
        }
        cout<<endl;
    int maxi = (m2.rbegin()->first);
    int mini = (m1.begin()->first);
    cout<<maxi<<" "<<mini<<endl;

    for(int i=0;i<q;i++){
        int idx,val;
        cin>>idx>>val;
        idx--;
        cout<<"arr: "<<arr[idx]<<" "<<idx<<endl;
        int prev1 = arr[idx]-idx;
        int prev2 = arr[idx]-idx;
        m2[prev2]--;
        m1[prev1]--;
        if(m2[prev2]==0){
            m2.erase(prev2);
        } 
        if(m1[prev1]==0){
            m1.erase(prev1);
        }
        arr[idx] = val;
        m2[arr[idx]-idx]++;
        m1[arr[idx]-idx]++;
        cout<<"arr2: "<<arr[idx]<<" "<<idx<<endl;
        int maxi1 = (m2.rbegin()->first);
        int mini1 = (m1.begin()->first);
        for(auto it:m1){
            cout<<it.first<<" ";
        }
        cout<<endl;
        for(auto it:m2){
            cout<<it.first<<" ";
        }
        cout<<endl;
        cout<<"Ans : "<<maxi1<<" "<<mini1<<endl;
    }

    
    
}
    return 0;
}