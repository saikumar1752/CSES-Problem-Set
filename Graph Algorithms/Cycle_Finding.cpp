#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <queue>
 
#define int long long
#define endl '\n'
 
using namespace std;
struct Edge{
	int u, v, w;
};
signed main(){
	int n, m;
	cin>>n>>m;
	vector<Edge> edges;
	for(int i=0;i<m;i++){
		int a, b, c;
		cin>>a>>b>>c;
		edges.push_back({a, b, c});
	}
	vector<int> distance(n+1);
	vector<int> parent(n+1, -1);
	int x=-1;
	for(int i=0;i<n;i++){
		x=-1;
		for(int j=0;j<m;j++){
			if(distance[edges[j].u]+edges[j].w<distance[edges[j].v]){
				distance[edges[j].v]=distance[edges[j].u]+edges[j].w;
				parent[edges[j].v]=edges[j].u;
				x=edges[j].v;
			}
		}	
	}
	if(x==-1){
		cout<<"NO"<<endl;
	}
	else{
		for(int i=0;i<n;i++){
			if(parent[i]!=-1){
				x=parent[i];
			}
			else {
				break;
			}
		}
		vector<int> cycle;
		for(int v=x;;v=parent[v]){
			auto it=find(cycle.begin(), cycle.end(), v);
			if(it!=cycle.end() and cycle.size()>1){
				cycle.push_back(v);
				break;
			}
			cycle.push_back(v);
		}
		reverse(cycle.begin(), cycle.end());
		cout<<"YES"<<endl;
		for(auto v : cycle){
			cout<<v<<" ";
		}
		cout<<endl;
	}
}