#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
 
#define int long long
 
using namespace std;
 
signed main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int &x : arr){
        cin>>x;
    }
    vector<int> dp(n+1, 1e15);
    dp[0]=-1e10;
    for(int i=0;i<n;i++){
        int j=upper_bound(dp.begin(), dp.end(), arr[i])-dp.begin();
        if(dp[j-1]<arr[i] and arr[i]<dp[j]){
            dp[j]=arr[i];
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        if(dp[i]<(int)1e15){
            ans=i;
        }
    }
    cout<<ans<<endl;
}
