#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;
 
int dp[501][501];
 
int solve(int a, int b){
    if(a==b){
        return dp[a][b]=0; 
    }
    if(dp[a][b]!=-1)return dp[a][b];
    int ans=INT_MAX;
    for(int i=1;i<a;i++){
        ans=min(ans, solve(i, b)+1+solve(a-i, b));
    }
    for(int j=1;j<b;j++){
        ans=min(ans, solve(a, j)+1+solve(a, b-j));
    }
    return dp[a][b]=ans;
}
 
int main(){
    int n, m;
    cin>>n>>m;
    memset(dp, -1, sizeof(dp));
    cout<<solve(n, m)<<endl;
}