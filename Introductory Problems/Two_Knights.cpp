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
 
 
using namespace std;
 
 
 
void solve(){
    int k;
    cin>>k;
    cout << 0 <<endl;
    for(int i=2;i<=k;i++){
        cout<<(i*i*(i*i-1))/2 - 4*(i-1)*(i-2)<<endl;
    }
    
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
