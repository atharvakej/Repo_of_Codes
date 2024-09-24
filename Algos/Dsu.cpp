#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent,rank,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(node==parent[node])return node;

        return parent[node] = findUPar(parent[node]);

    }

    void ubr(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void ubs(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};


#define int long long
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    DisjointSet ds(9);
    ds.ubs(1,2);
    ds.ubs(2,3);
    ds.ubs(5,4);
    ds.ubs(3,4);
    if(ds.findUPar(2)==ds.findUPar(3)){
        cout<<"Hi there"<<endl;
    }
    if(ds.findUPar(4)==ds.findUPar(2)){
        cout<<"Hogya bhai"<<endl;
    }
    return 0;
}