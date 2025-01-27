#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
 
#define int long long 
 
using namespace std;
 
signed main(){
	int n;
	cin>>n;
	vector<vector<int>> tree(n+1);
	for(int i=0;i<n-1;i++){
		int a, b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	vector<int> sub(n+1);
	vector<int> dist(n+1);
	function<void(int, int)> dfs=[&](int u, int p){
		sub[u]=1;
		for(int v : tree[u]){
			if(v==p)continue;
			dfs(v, u);
			sub[u]+=sub[v];
			dist[u]+=dist[v]+sub[v];
		}
	};
	dfs(1, 0);
	vector<int> answer(n+1);
	answer[1]=dist[1];
	function<void(int, int)> dfs2=[&](int u, int p){
		for(int v : tree[u]){
			if(v==p)continue;
			int other=n-sub[v];
			int other_dist=answer[u]-dist[v]+other-sub[v];\
			answer[v]=dist[v]+other_dist;
			dfs2(v, u);
		}
	};
	dfs2(1, 0);
	for(int i=1;i<=n;i++){
		cout<<answer[i]<<" ";
	}
	cout<<endl;
}