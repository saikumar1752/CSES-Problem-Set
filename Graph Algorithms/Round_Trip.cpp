#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <queue>
 
#define int long long
#define endl '\n'
#define sz(a) a.size()
using namespace std;
 
signed main(){
	int n, m;
	cin>>n>>m;
	vector<vector<int>> graph(n+1);
	for(int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> path;
	vector<bool> visited(n+1, false);
	function<void(int, int)> dfs=[&](int u, int par){
		visited[u]=true;
		path.push_back(u);
		for(int v : graph[u]){
			if(v==par)continue;
			if(visited[v]){
				path.push_back(v);
				int i=find(path.begin(), path.end(), v)-path.begin();
				cout<<path.size()-i<<endl;
				while(i<path.size()){
					cout<<path[i++]<<" ";
				}
				cout<<endl;
				exit(0);
			}
			else{
				dfs(v, u);
			}
		}
		path.pop_back();
	};
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dfs(i, i);
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}