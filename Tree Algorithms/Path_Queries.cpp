#include <iostream>
#include <vector>
#include <algorithm>
#include <algorithm>
#include <functional>
using namespace std;
#define int long long 
 
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;
 
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
 
    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
 
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
 
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
 
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
 
signed main(){
    int n, q;
    cin>>n>>q;
    vector<int> values(n+1);
    for(int i=1;i<=n;i++){
        cin>>values[i];
    }
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;i++){
        int a, b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> euler, tin(n+1), tout(n+1);
    function<void(int, int)> dfs=[&](int u, int p){
        euler.push_back(u);
        tin[u]=euler.size()-1;
        for(int v : tree[u]){
            if(v==p)continue;
            dfs(v, u);
        }
        tout[u]=euler.size()-1;
    };
    euler.push_back(0);
    dfs(1, 0);
    FenwickTree ft(euler.size());
    for(int i=1;i<=n;i++){
        ft.add(tin[i], values[i]);
        ft.add(tout[i]+1, -values[i]);
    }
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int u, x;
            cin>>u>>x;
            ft.add(tin[u], x-values[u]);
            ft.add(tout[u]+1, -(x-values[u]));
            values[u]=x;
        }
        else{
            int u;
            cin>>u;
            cout<<ft.sum(tin[u])<<"\n";
        }
    }
}