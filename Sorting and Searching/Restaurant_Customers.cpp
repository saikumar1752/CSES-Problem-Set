#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
 
signed main(){
	int n;
	cin>>n;
	vector<pair<int, int>> arr;
	for(int i=0;i<n;i++){
		int a, b;
		cin>>a>>b;
		arr.push_back({a, 1});
		arr.push_back({b, -1});
	}
	sort(arr.begin(), arr.end());
	int ans=0;
	int cnt=0;
	for(int i=0;i<arr.size();i++){
		cnt+=arr[i].second;
		ans=max(ans, cnt);
	}
	cout<<ans<<endl;
 
