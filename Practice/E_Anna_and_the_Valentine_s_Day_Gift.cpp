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
    int n,m;
    cin>>n>>m;
    vector<string> arr(n);
    vector<pair<int,string>> temp;
    fori(0,n)cin>>arr[i];
    int zeros = 0;
    int len = 0;
    for(int i=0;i<n;i++){
        int t = stoi(arr[i]);
        len += arr[i].size();
        int ct = 0;
        for(int j=arr[i].size()-1;j>=0;j--){
            if(arr[i][j]=='0'){
                ct++;
            }
            else break;
        }
        if(ct){
            temp.push_back({ct,arr[i]});
        }
    }
    sort(temp.begin(),temp.end(), [&](pair<int,string> &a, pair<int,string> &b){
        return a.first>b.first;
    });
    for(int i=0;i<temp.size();i+=2){
        zeros += temp[i].first;
    }
    if((len-zeros)>m)cout<<"Sasha"<<endl;
    else cout<<"Anna"<<endl;
    
    
}
    return 0;
}