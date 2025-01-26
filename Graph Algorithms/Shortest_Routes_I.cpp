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
    vector<vector<pair<int, int>>> g(n+1);
    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        g[a].push_back({b, c});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, LONG_MAX);
    dist[1]=0;
    vector<bool> visited(n+1, false);
    pq.push({0, 1});
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        if (visited[u]) continue;
        visited[u]=1;
        for (auto [v,w] : g[u]){
            if (dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}