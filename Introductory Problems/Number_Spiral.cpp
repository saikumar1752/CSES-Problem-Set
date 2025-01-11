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
using namespace std;
 
#define int long long
 
void solve(){
    int x, y;
    cin>>x>>y;
    int maxi = max(x, y);
    int numbers_contained = maxi*maxi;
    int ans;
    if(maxi%2){
        if(y == maxi){
            ans = numbers_contained - x + 1;
        }
        else{
            ans = numbers_contained - x - (maxi - y) + 1;
        }
    }
    else{
        if (x == maxi){
            ans = numbers_contained - y + 1;
        }
        else{
            ans = numbers_contained - y - (maxi-x)+1;
        }
    }
    cout<<ans<<endl;
}
 
signed main(){
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}
