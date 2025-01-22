#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <cstring>
#include <array>
using namespace std;
 
signed main()
{
    long long n;
    cin >> n;
    vector<long long> a(n), b(n), p(n);
    map<long long, long long> compress;
    for(long long i=0;i<n;i++){
        cin>>a[i]>>b[i]>>p[i];
        b[i]++;
        compress[a[i]];
        compress[b[i]];
    }
    long long coords = 0;
    for (auto &v : compress)
    {
        v.second = coords++;
    }
    vector<vector<pair<long long, long long>>> projects(coords);
    for (long long i = 0; i < n; i++)
    {
        projects[compress[b[i]]].emplace_back(compress[a[i]], p[i]);
    }
    vector<long long> dp(coords, 0);
    for(long long i=0;i<coords;i++){
        dp[i]=i>0?dp[i-1]:dp[i];
        for(auto p : projects[i]){
            dp[i]=max(dp[i], dp[p.first]+p.second);
        }
    }
    cout << dp[coords - 1] << endl;
}
