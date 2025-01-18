#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
 
using namespace std;
 
int main(){
	int n, m;
	cin>>n>>m;
	vector<vector<int>> g(n+1);
	for(int i=0;i<m;i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<int> q;
	q.push(1);
	vector<int> distance(n+1);
	distance[1]=1;
	vector<int> parent(n+1, -1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v : g[u]){
			if(!distance[v]){
				distance[v]=distance[u]+1;
				q.push(v);
				parent[v]=u;
			}
		}
	}
	if(distance[n]){
		cout<<distance[n]<<endl;
		vector<int> sol;
		function<void(int)> recur=[&](int i){
			if(i==-1)return;
			sol.push_back(i);
			recur(parent[i]);
		};
		recur(n);
		reverse(sol.begin(), sol.end());
		for(auto x : sol){
			cout<<x<<" ";
		} 
		cout<<endl;
 
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
}
