#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
 
#define int long long
#define endl '\n'
#define sz(a) a.size()
using namespace std;
 
signed main(){
	int n, m;
	cin>>n>>m;
	vector<string> grid(n);
	vector<vector<int>> distance(n+1, vector<int>(m, -1));
	vector<pair<int, int>> directions={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	queue<pair<int, int>> q;
	for(int i=0;i<n;i++){
		cin>>grid[i];
	}
	pair<int, int> source;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]=='A'){
				source={i, j};
			}
			else if(grid[i][j]=='M'){
				q.push({i, j});
				distance[i][j]=0;
			}
		}
	}
	if(source.first==0 or source.first==n-1 or source.second==0 or source.second==m-1){
		cout<<"YES"<<endl;
		cout<<0<<endl;
		return 0;	
	}
	function<bool(int, int)> safe=[&](int i, int j){
		if(i>=0 and i<n and j>=0 and j<m)return true;
		return false;
	};
	while(!q.empty()){
		auto [i, j]=q.front();
		q.pop();
		for(auto [dx, dy] : directions){
			int new_i=i+dx;
			int new_j=j+dy;
			if(safe(new_i, new_j) and grid[new_i][new_j]!='#' and distance[new_i][new_j]==-1){
				distance[new_i][new_j]=distance[i][j]+1;
				q.push({new_i, new_j});
			}
		}
	}
	while(!q.empty()){q.pop();}
	vector<char> ans;
	vector<vector<int>> distance1(n, vector<int>(m, -1));
	vector<vector<pair<int, int>>> from(n, vector<pair<int, int>>(m, pair<int, int>(-1, -1)));
	distance1[source.first][source.second]=0;
	from[source.first][source.second]={-1, -1};
	function<void(pair<int, int>)> retrace=[&](pair<int, int> node){
		auto origin = from[node.first][node.second];
		if(origin ==  pair<int, int>(-1,-1)) return;
		if(origin.first == node.first+1) ans.push_back('U');
		if(origin.first == node.first-1) ans.push_back('D');
		if(origin.second == node.second+1) ans.push_back('L');
		if(origin.second==node.second-1) ans.push_back('R');
		retrace(origin);
	};
	q.push(source);
	while(!q.empty()){
		auto [i, j]=q.front();
		q.pop();
		for(auto [dx, dy] : directions){
			int new_i=i+dx;
			int new_j=j+dy;
			if(safe(new_i, new_j) and grid[new_i][new_j]!='#' and distance1[new_i][new_j]==-1 and (distance[new_i][new_j]==-1 or (distance[new_i][new_j]>distance1[i][j]+1))){
				distance1[new_i][new_j]=distance1[i][j]+1;
				from[new_i][new_j]={i, j};
				if(new_i==0 or new_i==n-1 or new_j==0 or new_j==m-1){
					retrace({new_i, new_j});
					cout<<"YES"<<endl;
					cout<<ans.size()<<endl;
					reverse(ans.begin(), ans.end());
					for(auto x : ans){
						cout<<x;
					}
					cout<<endl;
					return 0;
				}
				q.push({new_i, new_j});
			}
		}
	}
	cout<<"NO"<<endl;
}