#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <climits>
 
#define int long long
 
using namespace std;
 
signed main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int &x : arr){
		cin>>x;
	}
	int ans=LONG_MAX;
	function<void(int, vector<int>)> fun=[&](int i, vector<int> store){
		if(i>=n){
			int a=0, b=0;
			for(int i=0;i<store.size();i++){
				if(store[i]==0)a+=arr[i];
				else b+=arr[i];
			}
			ans=min(ans, abs(a-b));
			return;
		}
		store.push_back(0);
		fun(i+1, store);
		store.pop_back();
		store.push_back(1);
		fun(i+1, store);
	};
	fun(0, {});
	cout<<ans<<endl;
}
