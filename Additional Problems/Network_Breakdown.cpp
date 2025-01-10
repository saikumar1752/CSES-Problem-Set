#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#define int long long
 
using namespace std;
 
signed main(){
    int n, m, q;
    cin>>n>>m>>q;
    vector<pair<int, int>> edges(m);
    set<pair<int, int>> left;
    for(auto &x : edges){
        cin>>x.first>>x.second;
        left.insert(x);
    }
    vector<pair<int, int>> query;
    for(int i=0;i<q;i++){
        int u, v;
        cin>>u>>v;
        query.push_back({u, v});
        if(left.find({u, v})!=left.end()){
            left.erase({u, v});
        }
        else if(left.find({v, u})!=left.end()){
            left.erase({v, u});
        }
    }
    vector<int> parent(n+1), size(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
    function<int(int)> find_parent=[&](int u){
        if(parent[u]!=u){
            parent[u]=find_parent(parent[u]);
        }
        return parent[u];
    };
    function<void(int, int)> unite=[&](int u, int v){
        u=find_parent(u);
        v=find_parent(v);
        if(size[u]<size[v])swap(u, v);
        parent[v]=u;
        size[u]+=size[v];
    };
    int components=n;
    for(auto x : left){
        int u=x.first;
        int v=x.second;
        if(find_parent(u)!=find_parent(v)){
            components--;
            unite(u, v);
        }
    }
    vector<int> answer;
    for(int i=query.size()-1;i>=0;i--){
        int u=query[i].first;
        int v=query[i].second;
        answer.push_back(components);
        if(find_parent(u)!=find_parent(v)){
            unite(u, v);
            components--;
        }
    }
    reverse(answer.begin(), answer.end());
    for(auto x : answer){
        cout<<x<<" ";
    }
    cout<<endl;
}