#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
 
signed main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(auto &x : arr){
		cin>>x;
	}
	int ans=0;
	for(int i=0;i<n-1;i++){
		if(arr[i+1]<arr[i]){
			ans+=arr[i]-arr[i+1];
			arr[i+1]=arr[i];
		}
	}
	cout<<ans<<endl;
}
