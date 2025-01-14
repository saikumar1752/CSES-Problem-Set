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
	int n, m, k;
	cin>>n>>m>>k;
	vector<int> arr(n), brr(m);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<m;i++){
		cin>>brr[i];
	}
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());
	int i=0, j=0, ans=0;
	while(i<arr.size() and j<brr.size()){
		if (abs(arr[i] - brr[j]) <= k){
			++i; ++j;
			++ans;
		}
		else{
			if (arr[i] - brr[j] > k){
				++j;
			}
			else{
				++i;
			}
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
