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
	int n, x;
	cin>>n>>x;
	vector<int> arr(n);
	for(int &x : arr){
		cin>>x;
	}
	sort(arr.begin(), arr.end());
	int i=0, j=n-1;
	int cnt=0;
	while(i<=j){
		if(arr[i]+arr[j]<=x){
			i++;
			j--;
		}
		else{
			j--;
 
		}
		cnt++;
	}
	cout<<cnt<<endl;
}
 
signed main(){
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}
