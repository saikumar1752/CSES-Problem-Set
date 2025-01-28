#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <queue>
 using namespace std;
#define int long long
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define vvi vector<vi>
const int inf = 1LL<<62;
const int md = 1000000007;
 
vvi mul(vvi a, vvi b) {
    vvi c(a.size(), vi(b[0].size(), 2e18));
    for (int i = 0; i < a.size(); i++) 
        for (int j = 0; j < b[0].size(); j++)
            for ( int k = 0; k < a[0].size(); k++) 
            	c[i][j]=min(c[i][j], a[i][k]+b[k][j]);
    return c;
}
 
 
vector<vector<int>> binpow(vector<vector<int>> x, int pow){
	if(pow==1)return x;
	auto mid=binpow(x, pow/2);
	mid=mul(mid, mid);
	if(pow%2==1){
		mid=mul(mid, x);
	}
	return mid;
}
signed main(){
    int n,m, k; cin>>n>>m>>k;
    vvi adj(n,vi(n, 2e18));
    for (int i = 0; i< m; i++) {
        int x,y, w; cin>>x>>y>>w;
        x--; y--;
        adj[x][y]=min(adj[x][y], w);
    }
    adj = binpow(adj,k);
    if(adj[0][n-1]==(int)2e18){
    	cout<<-1<<endl;
    	return 0;
    }
    cout<<adj[0][n-1]<<endl;
} 