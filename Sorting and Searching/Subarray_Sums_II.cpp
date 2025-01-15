#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <map>
 
#define int long long
 
using namespace std;
 
 
signed main(){
    int n, x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int &x : arr){
        cin>>x;
    }
    map<int, int> mp;
    int sum=0;
    int answer=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        answer+=mp[sum-x]+(sum==x);
        mp[sum]++;
    }
    cout<<answer<<endl;
}