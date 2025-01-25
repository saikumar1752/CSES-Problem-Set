#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <climits>
 
#define int long long
#define m_k make_pair
 
using namespace std;
 
 
void solve(){
	int n, k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int &x : arr){
		cin>>x;
	}
	multiset<int> low, upp;
	function<void(int)> insert =[&](int val){
		int cur = *low.rbegin();
		if(cur<val){
			upp.insert(val);
			if(upp.size()>k/2){
				low.insert(*upp.begin());
				upp.erase(upp.find(*upp.begin()));
			}
		}
		else{
			low.insert(val);
			if(low.size()>(k+1)/2){
				upp.insert(*low.rbegin());
				low.erase(low.find(*low.rbegin()));
			}
 
		}
	};
	function<void(int)> erase = [&](int val){
		if (upp.find(val)!=upp.end()){
			upp.erase(upp.find(val));
		}
		else{
			low.erase(low.find(val));
		}
		if(low.empty()){
			low.insert(*upp.begin());
			upp.erase(upp.find(*upp.begin()));
		}
	};
	low.insert(arr[0]);
	for(int i=1;i<k;i++){
		insert(arr[i]);
	}
	cout<<*low.rbegin()<<" ";
	for(int i=k;i<n;i++){
		if(k==1){
			insert(arr[i]);
			erase(arr[i-k]);
		}
		else{
			erase(arr[i-k]);
			insert(arr[i]);
		}
		cout<<*low.rbegin()<<" ";
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