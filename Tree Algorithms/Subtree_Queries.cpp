#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
 
#define int long long 
 
using namespace std;
 
struct segment_tree{
	vector<int> tree;
	int n;
	segment_tree(vector<int> &arr, vector<int> &val){
		n=arr.size();
		tree.resize(4*n);
		construct(arr, val, 1, 0, n-1);
	}
	void construct(vector<int> &arr, vector<int> &val, int i, int l, int r){
		if(l==r){
			tree[i]=val[arr[l]];
			return;
		}
		int mid=(l+r)/2;
		construct(arr, val, 2*i, l, mid);
		construct(arr, val, 2*i+1, mid+1, r);
		tree[i]=tree[2*i]+tree[2*i+1];
	}
	void update(int i, int l, int r, int idx, int val){
		if(l==r){
			tree[i]=val;
			return;
		}
		int mid=(l+r)/2;
		if(idx<=mid){
			update(2*i, l, mid, idx, val);
		}
		else{
			update(2*i+1, mid+1, r, idx, val);
		}
		tree[i]=tree[2*i]+tree[2*i+1];
	}
	int get(int i, int l, int r, int ql, int qr){
		if(l>qr or r<ql)return 0;
		if(l>=ql and r<=qr){
			return tree[i];
		}
		int mid=(l+r)/2;;
		return get(2*i, l, mid, ql, qr)+get(2*i+1, mid+1, r, ql, qr);
	}
};
 
signed main(){
	int n, q;
	cin>>n>>q;
	vector<int> arr(n+1);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	vector<vector<int>> tree(n+1);
	for(int i=0;i<n-1;i++){
		int a, b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	vector<int> euler, tout(n+1), tin(n+1);
	function<void(int, int)> dfs=[&](int u, int p){
		tin[u]=euler.size();
		euler.push_back(u);
		for(int v : tree[u]){
			if(v==p)continue;
			dfs(v, u);
		}
		tout[u]=euler.size()-1;
	};
	dfs(1, 0);
	segment_tree st(euler, arr);
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int u, x;
			cin>>u>>x;
			st.update(1, 0, n-1, tin[u], x);
		}
		else{
			int u;
			cin>>u;
			cout<<st.get(1, 0, n-1, tin[u], tout[u])<<endl;
		}
	}
}
