#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#define int long long
 
using namespace std;
const int maxn=2e5+10;
vector<int> tree[maxn];
int  distances[maxn];
void dfs(int u, int p){
    distances[u]=distances[p]+1;
    for(auto v : tree[u]){
        if(v==p)continue;
        dfs(v, u);
    }
}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    int max_dist=0;
    int farthest=0;
    for(int i=1;i<=n;i++){
        if(max_dist<distances[i]){
            max_dist=distances[i];
            farthest=i;
        }
    }
    memset(distances, 0, sizeof(distances));
    dfs(farthest, 0);
    max_dist=0;
    for(int i=1;i<=n;i++){
        max_dist=max(max_dist, distances[i]);
    }
    cout<<max_dist-1<<endl;
}