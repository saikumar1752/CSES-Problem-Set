#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
 
#define endl "\n"
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;
 
ll dp[1000001];
const int mod=(int)1e9+7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin>>n>>x;
	vector<int> coins(n);
	for(int &x : coins){
		cin>>x;
	}
	dp[0]=1;
	for(int coin : coins){
		for(int i=0;i<=x;i++){
			if(i-coin>=0){
				dp[i]+=dp[i-coin];
				dp[i]%=mod;
			}
		}
	}
	cout<<dp[x]<<endl;
}
