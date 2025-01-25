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
	int n, k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int &x : arr){
		cin>>x;
	}
	map<int, int> mp;
	int ans = 0;
	for(int i=0, j=0;i<n;i++){
		while(mp.size()<=k and j<n){
			if(mp.find(arr[j])==mp.end()){
				if(mp.size()==k)break;
				mp[arr[j]]=1;
			}
			else{
				mp[arr[j]]++;
			}
			j++;
		}
		ans += (j-i);
		mp[arr[i]]--;
		if(mp[arr[i]]==0){
			mp.erase(arr[i]);
		}
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