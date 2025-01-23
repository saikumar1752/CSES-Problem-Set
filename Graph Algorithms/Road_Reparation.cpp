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
 
signed main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int, pair<int, int>>> arr(m);
    for(int i=0;i<m;i++){
        cin>>arr[i].second.first>>arr[i].second.second>>arr[i].first;
    }
    sort(arr.begin(), arr.end());
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
        if(u==v)return;
        if(size[u]<size[v])swap(u, v);
        parent[v]=u;
        size[u]+=size[v];
    };
    int cnt=0;
    int answer=0;   
    for(auto x : arr){
        if(find_parent(x.second.first)!=find_parent(x.second.second)){
            cnt++;
            answer+=x.first;
            unite(x.second.first, x.second.second);
        }
    }
    if(cnt==n-1){
        cout<<answer<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}