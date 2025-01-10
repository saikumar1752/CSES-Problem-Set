#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int dp[1000001];
int MOD=1e9+7;
signed main(){
    int n;
    cin>>n;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6 and i-j>=0;j++){
            dp[i]=(dp[i]+dp[i-j])%MOD;
        }
    }
    cout<<dp[n]<<endl;
}