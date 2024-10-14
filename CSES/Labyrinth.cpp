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


int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<string> room(n);
    fori(0,n){
        cin>>room[i];
    }
string movem = "RLDU";
    set<pair<vector<int>,string>> q;
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(room[i][j]=='A'){
                q.insert({{i,j},""});
                dist[i][j] = 0;
                break;
            }
        }
    }
    bool flag = 0;
    while(!q.empty()){
        auto it = *(q.begin());
        int x = it.first[0];
        int y = it.first[1];
        string steps = it.second;
        int distance = dist[x][y];
        q.erase(it);
        // cout<<x<<" "<<y<<" "<<size<<" "<<steps<<endl;
        if(room[x][y]=='B'){
            flag = 1;
            cout<<"YES"<<endl;
            cout<<dist[x][y]<<endl;
            cout<<steps<<endl;
            break;  
        }
        for(int i=0;i<4;i++){
            int nx = delx[i] + x;
            int ny = dely[i] + y;
            if(nx>=0 && ny>=0 && nx<n && ny<m
            && (room[nx][ny]=='.' || room[nx][ny]=='B') ){
                if(distance+1 <dist[nx][ny]){

                    if(dist[nx][ny] != 1e9) 
                        q.erase({{nx,ny},}); 
                        
                    // If current distance is smaller,
                    // push it into the queue
                    dist[adjNode] = dis + edgW; 
                    st.insert({dist[adjNode], adjNode}); 


                }
            }
        }
    }
    if(!flag){
        cout<<"NO"<<endl;
    }
    return 0;
}