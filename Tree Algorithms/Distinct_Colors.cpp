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
	vector<int> colors(n+1);
	for(int i=1;i<=n;i++){
		cin>>colors[i];
	}
	vector<vector<int>> tree(n+1);
	for(int i=0;i<n-1;i++){
		int a, b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	vector<set<int>> store(n+1);
	vector<int> ans(n+1);
	function<void(int, int)> dfs=[&](int u, int p){
		int idx=0, max=0;
		for(int v : tree[u]){
			if(v==p)continue;
			dfs(v, u);
			if(store[v].size()>max){
				max=store[v].size();
				idx=v;
			}
		}
		if(!idx){
			store[u].insert(colors[u]);
			ans[u]=store[u].size();
			return;
		}
		swap(store[idx], store[u]);
		for(int v : tree[u]){
			if(v==idx or v==p)continue;
			for(auto x : store[v]){
				store[u].insert(x);
			}
			store[v].clear();
		}
		store[u].insert(colors[u]);
		ans[u]=store[u].size();
	};
	dfs(1, 0);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
 
}
