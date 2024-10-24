#include <bits/stdc++.h>
using namespace std;


vector<int> printNGE(vector<int>& arr, int n)
{
    vector<int> v(n,n);
    stack<int> s;
    stack<int> idx;
    s.push(arr[0]);
    idx.push(0);
    for (int i = 1; i < n; i++) {

        if (s.empty()) {
            s.push(arr[i]);
            idx.push(i);
            continue;
        }

        while (s.empty() == false && s.top() < arr[i]) {
            v[idx.top()]=i;
            idx.pop();
            s.pop();
        }
        s.push(arr[i]);
        idx.push(i);
    }

    while (s.empty() == false) {
        v[idx.top()]=n;
        idx.pop();
        s.pop();
    }
    return v;
}

vector<int> prevGreater(vector<int>& arr, int n)
{
    vector<int> v(n,-1);
    stack<int> idx;
    stack<int> s;
    s.push(arr[0]);
    idx.push(0);
     
     for (int i = 1; i < n; i++) {
 
        while (s.empty() == false && s.top() < arr[i]){
            s.pop();idx.pop();
        }
        if(!s.empty())v[i]=idx.top();
        s.push(arr[i]);
        idx.push(i);
    }
    return v;
}


void solve(vector<int>&arr){
    int n= arr.size();
    vector<int> a=printNGE(arr,n);
    vector<int> b=prevGreater(arr,n);
    for(auto it:a){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:b){
        cout<<it<<" ";
    }
    cout<<endl;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i]-b[i]-1;
    }
    cout<<sum<<endl;
    
}
int main() {
    vector<int> v={3,5,6};
	solve(v);

}