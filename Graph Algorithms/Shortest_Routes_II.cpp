#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cstring>
#include <vector>
#define int long long
int mod=1e9+7;
using namespace std;
#define int long long
int dp[1001][1001];
signed main(){
    int n, m, q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=1000000000000;
        }
        dp[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        dp[u][v]=min(dp[u][v],w), dp[v][u]=min(dp[u][v],w);
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
            }
        }
    }
    while(q--){
        int a, b;
        cin>>a>>b;
        if(dp[a][b]==1000000000000){
            cout<<-1<<endl;
        }
        else{
            cout<<dp[a][b]<<endl;
        }
    }
}