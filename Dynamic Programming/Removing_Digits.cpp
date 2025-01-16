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
 
ll dp[1000001];
 
vector<int> get_digits(int n){
	vector<int> digits;
	while(n){
		digits.push_back(n%10);
		n/=10;
	}
	return digits;
}
 
long long solve(int n){
	if(n==0)return 0;
	if(dp[n]!=-1)return dp[n];
	auto digits = get_digits(n);
	long long ans=INT_MAX;
	for(int digit : digits){
		if(digit!=0)
		ans = min(ans, solve(n-digit)+1);
	}
	return dp[n]=ans;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp, -1, sizeof(dp));
	int n;
	cin>>n;
	cout<<solve(n)<<endl;
}
