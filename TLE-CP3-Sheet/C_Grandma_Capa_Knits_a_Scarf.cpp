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
    string s;
    cin>>s;
    int mini = 1e9;
    for(char c ='a';c<='z';c++){
        int count = 0;
        bool flag = 1;
        int i= 0;
        int j= n-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else if(s[i]==c){
                count++;
                i++;
            }
            else if(s[j]==c){
                j--;
                count++;
            }
            else{
                flag = 0;
                break;
            }
        }
        if(flag)
        mini = min(mini,count);
    }
    if(mini==1e9){
        cout<<-1<<endl;
    }
    else
    cout<<mini<<endl;
    
    
}
    return 0;
}