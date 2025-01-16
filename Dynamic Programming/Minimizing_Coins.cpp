#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
int main(){
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for(int &x : coins){
		cin >> x;
	}
	vector<long long> dp(2*1000000+1, INT_MAX);
	dp[0]=0;
	for(int i=0;i<=x;i++){
		for(int j : coins){
			dp[i+j]=min(dp[i+j], dp[i]+1);
		}
	}
	cout << (dp[x]==INT_MAX?-1:dp[x]) << endl;
}
