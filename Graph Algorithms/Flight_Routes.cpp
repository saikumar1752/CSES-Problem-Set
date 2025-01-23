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
	int n, m, k;
	cin>>n>>m>>k;
	vector<vector<pair<int, int>>> graph(n+1);
	for(int i=0;i<m;i++){
		int a, b, c;
		cin>>a>>b>>c;
		graph[a].push_back({b, c});
	}
	vector<priority_queue<int>> bes(n+1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 1});
	bes[1].push(0);
	while(!pq.empty()){
		auto a = pq.top(); pq.pop();
		if (a.first > bes[a.second].top()) continue;
		for (auto& i: graph[a.second]) {
			int tmp = a.first+i.second;
			if (bes[i.first].size() < k) {
				bes[i.first].push(tmp);
				pq.push({tmp,i.first});
			} else if (tmp < bes[i.first].top()) {
				bes[i.first].pop();
				bes[i.first].push(tmp);
				pq.push({tmp,i.first});
			}
		}
	}
	vector<int> ans;
	while(!bes[n].empty()){
		ans.push_back(bes[n].top());
		bes[n].pop();
	}
	reverse(ans.begin(), ans.end());
	for(auto x : ans){
		cout<<x<<" ";
	}
	cout<<endl;
}