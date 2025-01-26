include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <climits>
 
#define endl "\n"
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;
 
int dp[1001][100001];
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	vector<int> prices(n), pages(n);
	for(int &x : prices) cin >> x;
	for(int &x : pages) cin >> x;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=x;j++){
			dp[i][j]=dp[i-1][j];
			int left = j-prices[i-1];
			if(left>=0){
				dp[i][j]=max(dp[i][j], dp[i-1][left]+pages[i-1]);
			}
		}
	}
	cout<<dp[n][x]<<endl;
}
