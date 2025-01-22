#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;
 
int dp[501][501 * 501];
int n, sum;
const int mod = (int)1e9 + 7;
int main()
{
    cin >> n;
    int target = (n * (n + 1)) / 2;
    if (target % 2)
    {
        cout << 0 << endl;
        return 0;
    }
    target /= 2;
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - i;
            if (left >= 0)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][left]) % mod;
            }
        }
    }
    cout << dp[n - 1][target] << endl;
}