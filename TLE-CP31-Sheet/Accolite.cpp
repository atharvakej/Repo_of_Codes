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

vector<int> func(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    for(int i=0;i<n;i++){
        if(arr[i]==0)continue;
        if(st.empty()){
            st.push(i);
        }
        else{
            int ele = arr[i];
            bool flag = 1;
            while(!st.empty()  && arr[st.top()]>0 && ele<0){
                int a = abs(arr[st.top()]);
                int b = abs(ele);
                if(a==b){
                    st.pop();
                    flag = 0;
                    break;
                }
                else if(b>a){
                    st.pop();
                }
                else{
                    flag = 0;
                    break;
                }
            }
            if(flag)
            st.push(i);
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(arr[i]==0)
        st.push(i);
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        ans[i] = arr[ans[i]];
    }
    return ans;

}

int32_t main(){
    vector<int> arr = {3,-2,0,4};
    vector<int> ans = func(arr);
    for(auto it:ans){
        cout<<it<<' ';
    }
    cout<<endl;

    
    return 0;
}