#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#define int long long
int mod=1e9+7;
using namespace std;
int dp[1002][1002];
signed main(){
    int n;
    cin>>n;
    vector<string> arr(n);
    for(auto &x : arr){
        cin>>x;
    }
    if(arr[0][0]=='*'){
        cout<<0<<endl;
        return 0;
    }
    dp[0][0]=1;
    for(int i=1;i<n;i++){
        if(arr[i][0]=='.'){
            dp[i][0]=dp[i-1][0];
        }
    }
    for(int i=1;i<n;i++){
        if(arr[0][i]=='.'){
            dp[0][i]=dp[0][i-1];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(arr[i][j]=='.'){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
}