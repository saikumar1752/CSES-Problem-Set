#include <iostream>
#include <vector>
 
#define endl "\n"
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;
 
const int mod = (int) 1e9 + 7;
int coins[300];
int dp[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x; cin >> n >> x;
	vi coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	dp[0] = 1;
	for (int weight = 0; weight <= x; weight++) {
		for (int i = 1; i <= n; i++) {
			if(weight - coins[i - 1] >= 0) {
				dp[weight] += dp[weight - coins[i - 1]];
				dp[weight] %= mod;
			}
		}
	}
	cout<<dp[x]<<endl;
}
