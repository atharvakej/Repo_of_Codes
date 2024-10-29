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
    string s;
    cin>>s;
    int n = s.size();
    bool flag = 1;
    for(int i=0;i<n;i++){
        if(s[i]=='1' || s[i]=='0'){

        }
        else{
            flag = 0;
        }
    }
    if(flag==1){
        cout<<"YES"<<endl;
        continue;
    }
    else{
        int t = stoi(s);
        map<int,int> mp;

        mp[11*11]++;
        mp[11*111]++;
        mp[11*111]++;
        mp[11*1111]++;
        mp[111*11]++;
        mp[111*1111]++;
        mp[11*101]++;
        mp[111*101]++;
        mp[111*101]++;
        mp[1111*101]++;
        mp[11*1010]++;
        mp[11*10100]++;
        mp[]
        


    }
    
    
}
    return 0;
}