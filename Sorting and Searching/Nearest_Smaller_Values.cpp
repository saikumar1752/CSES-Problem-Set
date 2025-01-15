#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <climits>
 
#define int long long
#define m_k make_pair
 
using namespace std;
 
 
void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int &i : arr){
		cin>>i;
	}
	vector<pair<int, int>> store;
	cout<<0<<" ";
	store.push_back(m_k(arr[0], 0));
	for(int i=1;i<n;i++){
		while(store.size()>0 and store.back().first>=arr[i])store.pop_back();
		if(store.size()==0){
			cout<<0<<" ";
		}
		else{
			cout<<store.back().second+1<<" ";
		}
		store.push_back(m_k(arr[i], i));
	}
	cout<<endl;
}
 
signed main(){
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
}