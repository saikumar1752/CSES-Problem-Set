#include <iostream>
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
 
int dp[101][100001];
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> coins(n);
	for(int &x : coins){
		cin >> x;
	}
	for(int i=1;i<=n;i++){
		dp[i][coins[i-1]]=1;
		for(int j=0;j<=100000;j++){
			dp[i][j]=dp[i][j] | dp[i-1][j];
			if(dp[i-1][j]){
				dp[i][j+coins[i-1]]=1;
			}
		}
	}
	vector<int> solution;
	for(int i=0;i<=100000;i++){
		if(dp[n][i]){
			solution.push_back(i);
		}
	}
	cout<<solution.size()<<endl;
	for(auto x : solution){
		cout<<x<<" ";
	}
	cout<<endl;
}