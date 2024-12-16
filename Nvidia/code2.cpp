#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

string solve(vector<int>& a, vector<int>& m, string& s){
    int n = a.size();
    int i=0;
    if(s == "Odd") i += 1;

    int aa=0, mm=0;

    while(i < n){
        aa += a[i] - m[i];
        mm += m[i] - a[i];

        i+=2;
    }

    if( aa == mm) return "Tie";
    else{
        return aa > mm ? "Andria" : "Maria";
    }
}

int main() {
    int n ;  cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<int> m(n);
    for(int i=0; i<n; i++) cin>>m[i];
    string s; cin>>s;

    cout<<solve(a,m,s)<<endl;
    return 0;
}