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

int delx[] = {0,0,1,-1};
int dely[] = {1,-1,0,0};

void dfs(vector<string> &room, vector<vector<int>> &vis, int i , int j){
        int n = room.size();
        int m = room[0].size();
        vis[i][j] = 1;
        for(int p=0;p<4;p++){
            int nr = delx[p] + i;
            int nc = dely[p] + j;
            if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0
             && room[nr][nc]=='.'){
                dfs(room,vis,nr,nc);
            }

        }
        return;
}

int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<string> room(n);
    fori(0,n){
        cin>>room[i];
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && room[i][j]=='.'){
                count++;
                dfs(room,vis,i,j);
            }
        }
    }
    cout<<count<<endl;


    return 0;
}