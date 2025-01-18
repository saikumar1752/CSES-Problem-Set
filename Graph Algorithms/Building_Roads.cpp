#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
 
using namespace std;
 
int main(){
	int n, m;
	cin>>n>>m;
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
		if(v==u)return;
		if(size[u]<size[v])swap(u, v);
		parent[v]=u;
		size[u]+=size[v];
	};
	for(int i=0;i<m;i++){
		int u, v;
		cin>>u>>v;
		unite(u, v);
	}
	set<int> store;
	for(int i=1;i<=n;i++){
		store.insert(find_parent(i));
	}
	vector<int> ano;
	for(auto x : store){
		ano.push_back(x);
	}
	cout<<ano.size()-1<<endl;
	for(int i=1;i<ano.size();i++){
		cout<<ano[0]<<" "<<ano[i]<<endl;
	}
}
