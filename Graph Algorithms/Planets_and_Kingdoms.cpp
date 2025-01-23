#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
#include <climits>
#include <cstring>
#include <vector>
#define int long long
 
using namespace std;
#define int long long
vector < vector<int> > g, gr;
vector<bool> used;
vector<int> order, component;
 
void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}
 
void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}
 
signed main() {
    int n, m;
    cin>>n>>m;
    g.resize(n+1);
    gr.resize(n+1);
    for (int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back (b);
        gr[b].push_back (a);
    }
 
    used.assign (n+1, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n+1, false);
    int cnt=1;
    vector<int> kingdom(n+1);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            for(auto x : component){
                kingdom[x]=cnt;
            }
            cnt++;
            component.clear();
        }
    }
    cout<<cnt-1<<endl;
    for(int i=0;i<n;i++){
        cout<<kingdom[i]<<" ";
    }
    cout<<endl;
}