#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    set<int> s;
    int left=0;
    int ans=0;
    for(int i=0;i<n;i++){
        while(s.find(arr[i])!=s.end()){
            s.erase(arr[left]);
            left++;
        }
        s.insert(arr[i]);
        ans=max(ans, (int)s.size());
    }
    cout<<ans<<endl;
}