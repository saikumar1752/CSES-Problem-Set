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
    vvi c(a.size(), vi(b[0].size()));
    for (int i = 0; i < a.size(); i++) 
        for (int j = 0; j < b[0].size(); j++)
            for ( int k = 0; k < a[0].size(); k++) 
                (c[i][j] += a[i][k]*b[k][j]%md)%=md;
    return c;
}
 
 
vvi exp( vvi x, int y) {
    vvi r(x.size(), vi(x.size()));
    for ( int i = 0; i < x.size(); i++) r[i][i] = 1;
    while (y>0){
        if (y&1) {
            r = mul(r,x);
        }
        y=y>>1;
        x = mul(x,x);
    }
    return r;
}
signed main(){
    //considering multiple edges
    int n,m, k; cin>>n>>m>>k;
    vvi adj(n,vi(n));
    for (int i = 0; i< m; i++) {
        int x,y; cin>>x>>y;
        x--; y--;
        adj[x][y]++;
    }
    adj = exp(adj,k);
    cout<<adj[0][n-1];
} 