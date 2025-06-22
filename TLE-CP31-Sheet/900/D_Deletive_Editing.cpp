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
    string st, fin;
    cin>>st>>fin;
    map<char,vector<int>> mp;
    for(int i=0;i<st.size();i++){
        mp[st[i]].push_back(i);
    }
    for(auto &it:mp){
        reverse(it.second.begin(), it.second.end());
    }
    map<char,int> count;
    for(int i=0;i<fin.size();i++){
        count[fin[i]]++;
    }
    bool flag =1;
    for(auto &it:mp){
        int ct = it.second.size();
        int finct = count[it.first];
        int toremove = ct-finct;
        for(int i=0;i<toremove;i++){
            if(mp[it.first].size()>0)
            mp[it.first].pop_back();
            else{
                flag = 0;
                break;
            }
        }

    }
    string finalize = "";
    for(int i=0;i<st.size();i++){
        finalize.push_back('#');
    }

    for(auto it:mp){
        for(auto i:it.second){
            finalize[i] = it.first;
        }
    }
    string che = "";
    for(auto it:finalize){
        if(it!='#'){
            che.push_back(it);
        }
    }
    cout << (che == fin ? "YES" : "NO") << endl;


    
    
}
    return 0;
}