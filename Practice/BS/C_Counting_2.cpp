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
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());

    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        int t = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        cout<<n-t<<endl;
    }
    
    return 0;
}