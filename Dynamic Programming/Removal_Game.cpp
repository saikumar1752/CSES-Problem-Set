#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (long long &x : arr)
    {
        cin >> x;
    }
    vector<vector<long long>> dp(n, vector<long long>(n, -1));
    function<long long(int, int)> solve = [&](int i, int j)
    {
        if (i > j)
            return 0ll;
        if (dp[i][j] != -1)
            return dp[i][j];
        long long left = arr[i] + min(solve(i + 2, j), solve(i + 1, j - 1));
        long long right = arr[j] + min(solve(i + 1, j - 1), solve(i, j - 2));
        return dp[i][j] = max(left, right);
    };
    cout << solve(0, n - 1) << endl;
}