#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
using namespace std;
 
vector<vector<int>> tree;
vector<bool> visited;
vector<int> parent;
vector<int> sz;
vector<int> store;
int find_size(int u, int p=-1){
    if(visited[u])return 0;
    sz[u]=1;
    for(int v : tree[u]){
        if(v!=p){
            sz[u]+=find_size(v, u);
        }
    }
    return sz[u];
}
 
int find_centroid(int u, int p, int n){
    for(int v : tree[u]){
        if(v!=p){
            if(!visited[v] and sz[v]>n/2){
                return find_centroid(v, u, n);
            }
        }
    }
    return u;
}
 
void init_centroid(int u, int p=-1){
    find_size(u);
 
    int c=find_centroid(u, -1, sz[u]);
    store.push_back(c);
    visited[c]=true;
    parent[c]=p;
 
    for(int v : tree[u]){
        if(!visited[v]){
            init_centroid(v);
        }
    }
}
 
int main(){
    int n;
    cin>>n;
    tree=vector<vector<int>>(n);
    visited=vector<bool>(n, false);
    parent=vector<int>(n);
    sz=vector<int>(n);
    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    init_centroid(0);
    cout<<store[0]+1<<endl;
}