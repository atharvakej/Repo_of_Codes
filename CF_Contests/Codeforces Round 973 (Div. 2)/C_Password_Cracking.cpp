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
#define fori(e,x) for(ll i=e; i<x; i++)
#define forj(x) for(ll j=0; j<x; j++)
#define sorta(x) sort(x.begin(),x.end())
#define fora(x) for(auto it : x)
#define int long long
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t=1;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int temp;
    string str = "";
    bool flag = 0;
    for(int i=0;i<2*n;i++){
        string test1 = str + "0";
        string test2 = str + "1";
        if(flag==1){
            string test3 = '0' + str;
                string test4 = '1' + str;
                cout<<flush<<endl;
                cout<<'?'<<" "<<test3<<flush<<endl;
                cin>>temp;
                if(temp==1){
                    str = test3;
                }
                else{
                    str = test4;
                }
        }
        else{
        cout<<flush<<endl;
        cout<<'?'<<" "<<test1<<flush<<endl;
        cin>>temp;
        if(temp==1){
            str = test1;
        }
        else{
        cout<<flush<<endl;
        cout<<'?'<<" "<<test2<<flush<<endl;
        cin>>temp; 
            if(temp==1){
                str = test2;
            }
            else{
                flag = 1;
                string test3 = '0' + str;
                string test4 = '1' + str;
                cout<<flush<<endl;
                cout<<'?'<<" "<<test3<<flush<<endl;
                cin>>temp;
                if(temp==1){
                    str = test3;
                }
                else{
                    str = test4;
                }
            }
        }
        }
        if(str.size()==n)break;
        
    }
    cout<<flush<<endl;
    cout<<"! "<<str<<flush<<endl;
    
    
}
    return 0;
}