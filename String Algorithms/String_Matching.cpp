#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
 
#define int long long
 
using namespace std;
 
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
 
signed main(){
    string p, q;
    cin>>p>>q;
    string s=q;
    s+='$';
    s+=p;
    auto vec=z_function(s);
    int ans=0;
    for(auto x : vec){
        if(x==(int)q.length()){
            ans++;
        }
    }
    cout<<ans<<endl;
}