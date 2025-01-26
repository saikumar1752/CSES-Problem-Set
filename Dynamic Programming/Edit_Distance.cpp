#include <iostream>
#include <vector>
#include <string>
#include <functional>
 
using namespace std;
 
int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp){
	if(!i)return j;
	if(!j)return i;
	if(dp[i][j]!=-1)return dp[i][j];
	if(a[i-1]==b[j-1]){
		return dp[i][j]=solve(i-1, j-1, a, b, dp);
	}
	return dp[i][j]=1+min(solve(i-1, j, a, b, dp), min(solve(i, j-1, a, b, dp), solve(i-1, j-1, a, b, dp)));
}
 
int main(){
	string a, b;
	cin >> a >> b;
	int na = a.length();
	int nb = b.length();
	vector<vector<int>> dp(na+1, vector<int>(nb+1, -1));
	cout << solve(na, nb, a, b, dp) << endl;
}