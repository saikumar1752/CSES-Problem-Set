#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <functional>
 
#define int long long
 
using namespace std;
 
void solve(){
	int n, sum;
	cin>>n>>sum;
	vector<pair<int, int>> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;	
		arr.push_back({x, i});	
	}
	sort(arr.begin(), arr.end());
	for(int i=1;i<n-1;i++){
		int j=0, k=n-1;
		int s=sum-arr[i].first;
		while(j<i and i<k){
			if(arr[j].first+arr[k].first>s){
				k--;
			}
			else if(arr[j].first+arr[k].first<s){
				j++;
			}
			else if(arr[j].first+arr[k].first==s){
				cout<<arr[i].second+1<<" "<<arr[j].second+1<<" "<<arr[k].second+1<<endl;
				return;
			}
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}
 
signed main(){	
	ios::sync_with_stdio( NULL );
	cin.tie( NULL );
	cout.tie( NULL );
	int t=1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
