#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
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
    string s;
    cin>>s;
    int n = s.length();
    int an = n+1;
    long long  kmp[an];
    int i=0, j=-1;
    kmp[0]=-1;
    while(i<n){
        while(i<n && j!=-1 && s[i]!=s[j]){
            j = kmp[j];
        }
        i++;
        j++;
        kmp[i] = j;
    }
    for(int i=0;i<n;i++)cout<<kmp[i]<<" ";
    cout<<endl;

    return 0;
}