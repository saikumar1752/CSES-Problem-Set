#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#define int long long
 
using namespace std;
int maxn=2000;
int arr[1001][1001];
int dp[2001][2001];
int n;
signed main(){
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c=='*'){
                arr[i][j]=1;
            }
        }
    }
    dp[0][0] = dp[1][0] = dp[0][1] = 0;
 
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            dp[i][j] = arr[i][j] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
    }
    while(q--){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        int val= dp[x2][y2] - 
                     dp[x2][y1-1] - 
                     dp[x1-1][y2] + 
                     dp[x1-1][y1-1] ;
        cout<<val<<endl;
    }
}
