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
	for(int &x : arr){
		cin>>x;
	}
	int ans = LONG_MIN;
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		ans=max(ans, sum);
		if(sum<0)sum=0;
	}
	cout<<ans<<endl;
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