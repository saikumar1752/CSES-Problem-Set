#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#define int long long
 
using namespace std;
const int maxn=2e5+10;
vector<int> children[maxn];
vector<int> sub(maxn);
void dfs(int u, int p){
    sub[u]=1;
    for(int v : children[u]){
        if(v==p)continue;
        dfs(v, u);
        sub[u]+=sub[v];
    }
}
 
signed main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int u;
        cin>>u;
        children[u].push_back(i);
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++){
        cout<<sub[i]-1<<" ";
    }
    cout<<endl;
}
