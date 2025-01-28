#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <climits>
 
#define int long long
#define m_k make_pair
 
using namespace std;
 
 
void solve(){
	string s;
	cin>>s;
	vector<int> z(s.length());
	for(int i=1, x=0, y=0;i<s.length();i++){
		z[i] = max(0ll,min(z[i-x], y-i+1));
        while (i+z[i] < s.length() && s[z[i]] == s[i+z[i]]) {
            x = i; y = i + z[i]; z[i]++;
        }
		if(z[i]+i==s.length()){
			cout<<i<<" ";
		}
	}
	cout<<s.length()<<" ";	 
	cout<<endl;
}
 
signed main(){
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
}