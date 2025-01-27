#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#define int long long
 
using namespace std;
 
const int maxn=2e5+10;
vector<int> tree[maxn];
int parent[maxn][20];
int height[maxn];
void dfs(int u, int p){
    parent[u][0]=p;
    height[u]=height[p]+1;
    for(int i=1;i<20;i++){
        int tmp=parent[u][i-1];
        parent[u][i]=parent[tmp][i-1];
    }
    for(auto v : tree[u]){
        if(v==p)continue;
        dfs(v, u);
    }
}
signed main(){
    int n, q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int u;
        cin>>u;
        tree[u].push_back(i);
        tree[i].push_back(u);
    }
    memset(parent, -1, sizeof(parent));
    dfs(1, 0);
    while(q--){
        int x, k;
        cin>>x>>k;    
        int ans=0;
        for(int i=20;i>=0;i--){
            if(k&(1<<i)){
                x=parent[x][i];
                if(x==-1)break;
            }
        }
        if(x==0){
            cout<<-1<<endl;
        }
        else{
            cout<<x<<endl;
        }
    }
}
